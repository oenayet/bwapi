#include <windows.h>
#include <BWAPI.h>

#include <list>
#include <deque>

using namespace BWAPI;

void UpdateScripts();
bool LoadAIBinary(const char *pszFileName);
int GetStandardUnitCount(BWAPI::UnitType type, bool bCompleted = true, Player *player = NULL);

int GetTerranRushScore(Player *player);
int GetZergGroundRushScore(Player *player);
int GetZergAirRushScore(Player *player);
int GetProtossAirRushScore(Player *player);

void AICreateThread(WORD wStartBlock, Position location, void *pTown = NULL);
void AICreateThread(char *pszScriptID, Position location);

#define AI_THREAD_BROODWAR        0x01
#define AI_THREAD_KILLABLE        0x02
#define AI_THREAD_WANT_KILLED     0x04
#define AI_THREAD_TARG_EXPANSION  0x08

class aithread
{
public:
  aithread();
  aithread(WORD wStartBlock, BWAPI::Position location, void *town = NULL);
  ~aithread();
  template <class _T>
  _T read()
  {
    _T rval = *(_T*)&pbAIScriptBinary[this->dwScriptOffset];
    this->dwScriptOffset += sizeof(_T);
    this->dwBytesRead    += sizeof(_T);
    return rval;
  }
  void  execute();
  DWORD getFlags();
  void  setFlags(DWORD dwFlags);
  void  clearFlags(DWORD dwFlags);
  DWORD sleep();
  void  killThread();
  void  showDebug(int x, int y);
  void  saveDebug(const char prefix, int iOpcode, const char *pszFormat = NULL, ...);
  void  retry();

private:
  DWORD             dwScriptOffset;   // the offset in the AIScript file
  DWORD             dwSleepTime;      // the number of frames remaining before the thread continues execution
  DWORD             dwPlayerID;       // the player index that owns the thread
  RECT              locationBounds;   // the location boundry of which the script is executed in
  //POINT             locationCenter;   // the center of the location of which the script is executed in
  BWAPI::Position   locationCenter;
  void              *pTown;           // town information
  DWORD             dwFlags;          // the flags for the thread behaviour
  BYTE              bTotBuildCount[228]; // not included

  int               threadId;
  DWORD             dwBytesRead;
  std::deque<char*> debugQueue;

  bool retryBlock;
};

extern BYTE *pbAIScriptBinary;
extern std::list<aithread> aiThreadList;

