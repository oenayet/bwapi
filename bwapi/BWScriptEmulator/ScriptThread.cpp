#include "ScriptThread.h"
#include "ScriptEnum.h"
#include "BWScriptEmulator.h"

#include "Controller.h"

#include <BWAPI.h>

using namespace BWAPI;

#define MACRO_BUILD   0
#define MACRO_UPGRADE 1
#define MACRO_TECH    2

std::list<aithread> aiThreadList;

BYTE *pbAIScriptBinary;

#define AIS_ENTRY_REQUIRES_LOCATION   0x01
#define AIS_ENTRY_STAREDIT_INVISIBLE  0x02
#define AIS_ENTRY_REQUIRES_BROODWAR   0x04

struct ais_entry
{
  DWORD dwScriptID;
  DWORD dwOffset;
  DWORD dwStringIndex;
  DWORD dwFlags;
};

int threadCount = 0;
void UpdateScripts()
{
  std::list<aithread>::iterator i = aiThreadList.begin();
  while ( i != aiThreadList.end() )
  {
    i->showDebug(0, 0);
    if ( !i->sleep() )    // wait/sleep
    {
      if ( i->getFlags() & AI_THREAD_WANT_KILLED )
      {
        i = aiThreadList.erase(i);
        --threadCount;
        continue;
      }      

      // execute thread
      i->execute();
    }
    ++i;
  }
}

bool LoadAIBinary(const char *pszFileName)
{
  HANDLE hFile = CreateFile(pszFileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
  if ( hFile == INVALID_HANDLE_VALUE )
    return false;

  DWORD dwFileSize = GetFileSize(hFile, NULL);
  if ( dwFileSize <= 10 )
  {
    CloseHandle(hFile);
    return false;
  }
  pbAIScriptBinary = (BYTE*)malloc(dwFileSize);
  if ( !pbAIScriptBinary )
  {
    CloseHandle(hFile);
    return false;
  }
  memset(pbAIScriptBinary, 0, dwFileSize);

  DWORD dwBytesRead = 0;
  ReadFile(hFile, pbAIScriptBinary, dwFileSize, &dwBytesRead, NULL);
  CloseHandle(hFile);
  return true;
}

void AICreateThread(WORD wStartBlock, Position location, void *pTown)
{
  aiThreadList.push_front(aithread(wStartBlock, location, pTown));
  ++threadCount;
}

void AICreateThread(char *pszScriptID, Position location)
{
  DWORD dwScriptID = *(DWORD*)pszScriptID;
  if ( !pbAIScriptBinary )
    return;

  ais_entry *entryList = (ais_entry*)(pbAIScriptBinary + *(DWORD*)pbAIScriptBinary);
  DWORD dwScriptOffset = 0;
  for ( int i = 0; entryList[i].dwScriptID != 0 && dwScriptOffset == 0; ++i )
  {
    if ( dwScriptID == entryList[i].dwScriptID )
    {
      dwScriptOffset = entryList[i].dwOffset;
      break;
    }
  }

  if ( dwScriptOffset )
  {
    AICreateThread((WORD)dwScriptOffset, location);
    Broodwar->sendText("Beginning AI script execution: %s", pszScriptID);
  }
  else
    Broodwar->sendText("Unable to find script: %s", pszScriptID);
}

aithread::aithread()
:dwScriptOffset(0)
,dwSleepTime(0)
,dwPlayerID( (Broodwar->self()->getID()) )
,locationCenter(BWAPI::Positions::None)
,pTown(NULL)
,dwFlags(0)
,threadId(threadCount)
,dwBytesRead(0)
,retryBlock(false)
{
  this->locationBounds.left   = 0;
  this->locationBounds.right  = 0;
  this->locationBounds.top    = 0;
  this->locationBounds.bottom = 0;
  memset(this->bTotBuildCount, 0, sizeof(this->bTotBuildCount));
  this->debugQueue.clear();
}

aithread::aithread(WORD wStartBlock, BWAPI::Position location, void *town)
:dwScriptOffset(wStartBlock)
,dwSleepTime(0)
,dwPlayerID(Broodwar->self()->getID())
,locationCenter(location)
,pTown(town)
,dwFlags(0)
,threadId(threadCount)
,dwBytesRead(0)
,retryBlock(false)
{
  this->locationBounds.left   = location.x - 128;
  this->locationBounds.right  = location.x + 128;
  this->locationBounds.top    = location.y - 128;
  this->locationBounds.bottom = location.y + 128;
  memset(this->bTotBuildCount, 0, sizeof(this->bTotBuildCount));
  this->debugQueue.clear();
}

aithread::~aithread()
{
  for ( std::deque<char*>::iterator c = this->debugQueue.begin(); c != this->debugQueue.end(); ++c )
    free(*c);
  this->debugQueue.clear();
}

int GetTerranRushScore(Player *player)
{
  int bunkerScore = 4 * player->completedUnitCount(UnitTypes::Terran_Bunker);
  int marineScore = player->completedUnitCount(UnitTypes::Terran_Marine);
  if ( bunkerScore <= marineScore )
    return marineScore + bunkerScore;
  else
    return 2 * marineScore;
}

int GetZergGroundRushScore(Player *player)
{
  return player->completedUnitCount(UnitTypes::Zerg_Hydralisk) + 
     2 * player->completedUnitCount(UnitTypes::Zerg_Sunken_Colony);
}

int GetZergAirRushScore(Player *player)
{
  return player->completedUnitCount(UnitTypes::Zerg_Hydralisk) + 
    player->completedUnitCount(UnitTypes::Zerg_Mutalisk) + 
     2 * player->completedUnitCount(UnitTypes::Zerg_Spore_Colony);
}

int GetProtossAirRushScore(Player *player)
{
  return player->completedUnitCount(UnitTypes::Protoss_Dragoon) + 
         player->completedUnitCount(UnitTypes::Protoss_Scout);
}

int GetStandardUnitCount(UnitType type, bool bCompleted, Player *player)
{
  int count = 0;
  Player *pl = (player ? player : self);
  if ( !pl )
    return 0;
  if ( bCompleted )
  {
    count = pl->completedUnitCount(type);
    if ( type == UnitTypes::Terran_Siege_Tank_Siege_Mode )
      count += pl->completedUnitCount(UnitTypes::Terran_Siege_Tank_Tank_Mode);
    else if ( type == UnitTypes::Terran_Siege_Tank_Tank_Mode )
      count += pl->completedUnitCount(UnitTypes::Terran_Siege_Tank_Siege_Mode);
  }
  else
  {
    count = pl->allUnitCount(type);
    if ( type == UnitTypes::Terran_Siege_Tank_Siege_Mode )
      count += pl->allUnitCount(UnitTypes::Terran_Siege_Tank_Tank_Mode);
    else if ( type == UnitTypes::Terran_Siege_Tank_Tank_Mode )
      count += pl->allUnitCount(UnitTypes::Terran_Siege_Tank_Siege_Mode);
  }
  return count;
}

DWORD aithread::getFlags()
{
  return this->dwFlags;
}

void aithread::setFlags(DWORD dwFlags)
{
  this->dwFlags |= dwFlags;
}

void aithread::clearFlags(DWORD dwFlags)
{
  this->dwFlags &= ~dwFlags;
}

DWORD aithread::sleep()
{
  DWORD rval = this->dwSleepTime;
  if ( rval )
    this->dwSleepTime = rval - 1;
  return rval;
}

void aithread::killThread()
{
  this->setFlags(AI_THREAD_WANT_KILLED);
}

void aithread::showDebug(int x, int y)
{
  int _y = y;
  int _x = x + this->threadId*200 + 4;
  bw->setTextSize(0);
  for each ( char *s in this->debugQueue )
  {
    char n[512];
    strcpy(n, s);
    
    char *mid = strchr(n, ' ');
    if ( mid )
    {
      *mid = 0;
      ++mid;
    }
    
    bw->drawTextScreen(_x, _y, "%s", n);
    if ( mid )
      bw->drawTextScreen(_x+100, _y, "%s", mid);
    _y += 9;
  }
  bw->setTextSize();
}

void aithread::saveDebug(const char prefix, int iOpcode, const char *pszFormat, ...)
{
  if ( retryBlock )
    return;

  char szFinalBuffer[512];
  char szBuffer[256];

  szFinalBuffer[0] = 0;
  szBuffer[0]      = 0;

  if ( pszFormat )
  {
    va_list ap;
    va_start(ap, pszFormat);
    vsnprintf_s(szBuffer, 256, 256, pszFormat, ap);
    va_end(ap);
  }
  sprintf_s(szFinalBuffer, 512, "%c%s %s", prefix, AISCRIPT::getOpcodeName(iOpcode), szBuffer);

  char *tmp = (char*)malloc(strlen(szFinalBuffer)+1);
  strcpy(tmp, szFinalBuffer);

  if ( this->debugQueue.size() > 32 )
  {
    char *front = this->debugQueue.front();
    free(front);
    this->debugQueue.pop_front();
  }
  this->debugQueue.push_back(tmp);
}
void aithread::retry()
{
  this->dwScriptOffset -= this->dwBytesRead;
  this->dwSleepTime     = 30;
  this->dwBytesRead     = 0;
  retryBlock            = true;
}
