#pragma once

#include "ReplayReader.h"
#include <windows.h>


void ParseActions(ReplayReader &fr, const char *pszFilename);

namespace Actions
{
  static const char *pszGroupType[] =
  {
    "Save",
    "Recall",
    "Add"
  };

  static const char *pszGameSpeed[] =
  {
    "Slowest",
    "Slower",
    "Slow",
    "Normal",
    "Fast",
    "Faster",
    "Fastest"
  };

  static const char *pszLatency[] =
  {
    "Low",
    "High",
    "Extra High"
  };

  static const char *pszLeaveType[] =
  {
    "Quit",
    "Defeat",
    "Victory",
    "Finished",
    "Draw",
    "Dropped"
  };

  static const char *pszActionNames[] =
  {
    "Public Chat",
    "Private Chat",
    "Null Chat",
    "0x03",
    "0x04",
    "Keep Alive",
    "Save Game",
    "Load Game",
    "Restart Game",
    "Select",
    "Shift Select",
    "Shift Deselect",
    "Placebox",
    "Set Fog",
    "Set Allies",
    "Set Speed",
    "Pause",
    "Unpause",
    "Use Cheat",
    "Group Units",
    "Right Click",
    "Target Click",
    "0x16",
    "0x17",
    "Cancel Construction",
    "Cancel Morph",
    "Stop",
    "Carrier Stop",
    "Reaver Stop",
    "Nothing",
    "Return Cargo",
    "Train",
    "Cancel Train",
    "Cloak",
    "Decloak",
    "Morph Unit",
    "0x24",
    "Unsiege",
    "Siege",
    "Build Fighter",
    "Unload All",
    "Exit Transport",
    "Merge Archon",
    "Hold Position",
    "Burrow",
    "Unburrow",
    "Cancel Nuke",
    "Lift Off",
    "Research",
    "Cancel Research",
    "Upgrade",
    "Cancel Upgrade",
    "Cancel Addon",
    "Morph Building",
    "Use Stimpack",
    "Game Synchronization",
    "Voice On",
    "Voice Off",
    "Voice Squelch",
    "Voice Unsquelch",
    "[Lobby]Start Game",
    "[Lobby]Set Download Progress",
    "[Lobby]Set Slot Data (Host)",
    "[Lobby]Ask Version",
    "[Lobby]Confirm Version",
    "[Lobby]Set Race",
    "[Lobby]Set Force (Melee)",
    "[Lobby]Set Force (UMS)",
    "[Lobby]Set Slot",
    "[Lobby]Swap Players",
    "[Lobby]0x46",
    "[Lobby]0x47",
    "[Lobby]Set Game Seed",
    "[Lobby]Request Info",
    "[Lobby]Set Force Data",
    "[Lobby]Set Force Names",
    "[Lobby]Chat",
    "[Lobby]Chat2",
    "[Lobby]Boot Player",
    "[Lobby]File Transfer",
    "[Result]OK",
    "[Result]Network Error",
    "[Result]Unknown",
    "[Result]Briefing Started",
    "Skip Briefing",
    "Set Latency",
    "Set Replay Speed",
    "Leave Game",
    "Minimap Ping",
    "0x59",
    "Dark Archon Meld",
    "Make Game Public",
    "Chat"
  };

  enum Enum
  {
    Chat_Public,
    Chat_Private,
    Chat_Null,
    z__0x03,
    z__0x04,
    Keep_Alive,
    Save_Game,
    Load_Game,
    Restart_Game,
    Select_Units,
    Select_Delta_Add,
    Select_Delta_Del,
    Placebox,
    Set_Fog,
    Set_Allies,
    Set_Speed,
    Pause_On,
    Pause_Off,
    Cheat,
    Group_Units,
    Right_Click,
    Target_Click,
    z__0x16,
    z__0x17,
    Cancel_Construction,
    Cancel_Morph,
    Stop,
    Stop_Carrier,
    Stop_Reaver,
    Order_Nothing,
    Return,
    Train,
    Cancel_Train,
    Cloak_On,
    Cloak_Off,
    Unit_Morph,
    z__0x24,
    Tank_Unsiege,
    Tank_Siege,
    Build_Fighter,
    Unload_All,
    Exit_Transport,
    Summon_Archon,
    Hold_Position,
    Burrow_Down,
    Burrow_Up,
    Cancel_Nuke,
    Lift_Off,
    Research,
    Cancel_Research,
    Upgrade,
    Cancel_Upgrade,
    Cancel_Addon,
    Building_Morph,
    Stim_Pack,
    Synchro_Check,
    Voice_Off,
    Voice_On,
    Voice_Squelch,
    Voice_Enable,
    Start_Game,
    Set_Download_Progress,
    Set_Slot_Data,
    Version_Ask,
    Version_Confirm,
    Set_Race,
    Set_Force_Melee,
    Set_Force,
    Set_Slot,
    Swap_Player,
    z__0x46,
    z__0x47,
    Set_Seed,
    Request_Info,
    Set_Force_Data,
    Set_Force_Names,
    Chat_Lobby,
    Chat_Lobby_2,
    Kick_Player,
    Transfer_File,
    Response_Nothing,
    Response_Error,
    Response_Unknown,
    Response_Entered_Briefing,
    Briefing_Start,
    Set_Latency,
    Set_Replay_Speed,
    Leave_Game,
    Ping_Minimap,
    z__0x59,
    Summon_Dark_Archon,
    Set_Public_Game,
    Chat_Replay,
    Max
  };
  
};
