#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>

#include <Util/Gnu.h>
#include <Util/Foreach.h>
#include <Util/clamp.h>

#include <BWAPI.h>

#include "../../svnrev.h"

#include "BW/Offsets.h"
#include "BWAPI/GameImpl.h"
#include "DLLMain.h"
#include "ExceptionFilter.h"

#include "Detours.h"
#include "CodePatch.h"
#include "Config.h"
#include "WMode.h"

#include "../../Debug.h"

//---------------------------------------------- QUEUE COMMAND -----------------------------------------------
void __fastcall QueueGameCommand(void *pBuffer, DWORD dwLength)
{
  if ( !pBuffer || !dwLength || !isCorrectVersion )
    return;

  CAPS caps;
  caps.dwSize = sizeof(CAPS);
  SNetGetProviderCaps(&caps);

  DWORD dwMaxBuffer = clamp<DWORD>(caps.maxmessagesize, 0, 512);
  if ( dwLength + *BW::BWDATA_sgdwBytesInCmdQueue <= dwMaxBuffer )
  {
    // Copy data to primary turn buffer
    memcpy(&BW::BWDATA_TurnBuffer[*BW::BWDATA_sgdwBytesInCmdQueue], pBuffer, dwLength);
    *BW::BWDATA_sgdwBytesInCmdQueue += dwLength;
    return;
  }
  
  // Verify game mode
  if ( *BW::BWDATA_gwGameMode == 4 )
    return;

  int turns;
  if ( SNetGetTurnsInTransit(&turns) ) // Buffer is full
  {
    int callDelay = 1;
    if ( *BW::BWDATA_NetMode )
      callDelay = clamp<DWORD>(caps.dwCallDelay, 2, 8);

    // This statement will probably never be hit, but just in case
    if ( turns >= 16 - callDelay )
      return;

    // Send the turn and fill the new buffer
    BW::BWFXN_sendTurn();
    memcpy(&BW::BWDATA_TurnBuffer[*BW::BWDATA_sgdwBytesInCmdQueue], pBuffer, dwLength);
    *BW::BWDATA_sgdwBytesInCmdQueue += dwLength;
  }
  // assume no error, would be fatal in Starcraft anyway
}

int getFileType(const char *szFileName)
{
  if ( !szFileName )
    return 0;

  int rVal = 0;
  HANDLE hMPQ;
  HANDLE hFile;
  // Open archive for map checking
  if ( SFileOpenArchive(szFileName, 0, 0, &hMPQ) && hMPQ )
  {
    // Open scenario.chk file
    if ( SFileOpenFileEx(hMPQ, "staredit\\scenario.chk", SFILE_FROM_MPQ, &hFile) && hFile )
    {
      rVal = 1;
      SFileCloseFile(hFile);
    }
    // Close archive
    SFileCloseArchive(hMPQ);
  }
  else if ( SFileOpenFileEx(NULL, szFileName, SFILE_FROM_ABSOLUTE, &hFile) && hFile )
  {
    DWORD dwRead = 0;
    char tbuff[16];
    DWORD dwSize = SFileGetFileSize(hFile, 0);
    // Read file data to check if it's a replay
    if ( dwSize > 16 && SFileReadFile(hFile, &tbuff, 16, &dwRead, 0) && dwRead == 16 && *(DWORD*)&tbuff[12] == 'SRer' )
      rVal = 2;
    // Close file
    SFileCloseFile(hFile);
  }
  return rVal;
}
//------------------------------------------------ BWAPI ERROR -----------------------------------------------
void BWAPIError(const char *format, ...)
{
  char *buffer;
  vstretchyprintf(buffer, format);

  BWAPI::BroodwarImpl.printf( "\x06" "ERROR: %s", buffer);

  SYSTEMTIME time;
  GetSystemTime(&time);
  char szLogFile[MAX_PATH];
  sprintf_s(szLogFile, MAX_PATH, "%s\\bwapi-error.txt", szLogPath);
  FILE* f = fopen(szLogFile, "a+");
  if ( f )
  {
    fprintf(f, "[%u/%02u/%02u - %02u:%02u:%02u] %s\n", time.wYear, time.wMonth, time.wDay, time.wHour, time.wMinute, time.wSecond, buffer);
    fclose(f);
  }
  free(buffer);
}

void BWAPIError(DWORD dwErrCode, const char *format, ...)
{
  char *buffer;
  vstretchyprintf(buffer, format);

  char szErrString[256];
  SErrGetErrorStr(dwErrCode, szErrString, 256);
  BWAPIError("%s    %s", szErrString, buffer);
  free(buffer);
}

void CheckVersion()
{
  WORD w1, w2, w3, w4;
  GetCurrentProductVersion(w1, w2, w3, w4);
  if (  w1 != SC_VER_1 ||
      w2 != SC_VER_2 ||
      w3 != SC_VER_3 )
  {
    isCorrectVersion = false;
    MessageBox(NULL, "The version of Starcraft that you are using is not compatible with BWAPI. BWAPI is intended to run on Starcraft version " STARCRAFT_VER ". However, BWAPI will attempt to continue to run in a reduced functionality mode.", NULL, MB_ICONERROR | MB_OK);
  }
}

DWORD WINAPI PersistentPatch(LPVOID)
{
  for ever
  {
    Sleep(300);

    // If version is correct
    if ( isCorrectVersion )
    {
      // dialog/menu layer
      if ( BW::BWDATA_ScreenLayers[2].pUpdate != DrawDialogHook && 
           BW::BWDATA_ScreenLayers[2].pUpdate != nullptr )
      {
        BW::pOldDrawDialogProc = BW::BWDATA_ScreenLayers[2].pUpdate;
        BW::BWDATA_ScreenLayers[2].pUpdate = DrawDialogHook;
      }

      // game layer
      if ( BW::BWDATA_ScreenLayers[5].pUpdate != DrawHook && BW::BWDATA_ScreenLayers[5].pUpdate != nullptr )
      {
        BW::pOldDrawGameProc = BW::BWDATA_ScreenLayers[5].pUpdate;
        BW::BWDATA_ScreenLayers[5].pUpdate = DrawHook;
      }
    }

    // Only grab this info if we are not currently detouring the CreateWindowEx procedure
    if ( !detourCreateWindow )
    {
      if ( !ghMainWnd )
        ghMainWnd = SDrawGetFrameWindow();

      if ( ghMainWnd )
      {
        WNDPROC thisProc = (WNDPROC)GetWindowLong(ghMainWnd, GWLP_WNDPROC);
        if ( thisProc != &WindowProc )
        {
          wOriginalProc = thisProc;
          SetWindowLong(ghMainWnd, GWLP_WNDPROC, (LONG)&WindowProc);
        }
      }
    }
  } //loop
}

//------------------------------------------------- DLL MAIN -------------------------------------------------
BOOL APIENTRY DllMain(HMODULE, DWORD ul_reason_for_call, LPVOID)
{
  switch (ul_reason_for_call)
  {
    case DLL_PROCESS_ATTACH:
      {
#ifdef _DEBUG
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
        // Retrieve the initial configuration stuff if not already
        InitPrimaryConfig();

        // Do version checking
        CheckVersion();

        // Load the auto-menu config
        BWAPI::BroodwarImpl.loadAutoMenuData();

        // Apply all hacks and patches to the game
        ApplyCodePatches();

        // Initialize BWAPI
        BWAPI::BWAPI_init();

        // Create our thread that persistently applies hacks
        CreateThread(NULL, 0, &PersistentPatch, NULL, 0, NULL);

        return TRUE;
      }
  }
  return TRUE;
}
