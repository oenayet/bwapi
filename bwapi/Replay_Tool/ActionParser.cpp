#include "ActionParser.h"


ActionParser::ActionParser(ReplayReader * p_replayReader)
{
	rr = p_replayReader;

	
}

void ActionParser::InitializeMappings()
{
	mapping[Actions::Load_Game] = &ActionParser::Save;
	mapping[Actions::Save_Game] = &ActionParser::Save;

	mapping[Actions::Chat_Replay] = &ActionParser::Chat_Replay;

	mapping[Actions::Select_Delta_Add] = &ActionParser::Select_Units;
	mapping[Actions::Select_Delta_Del] = &ActionParser::Select_Units;
	mapping[Actions::Select_Units] = &ActionParser::Select_Units;

	mapping[Actions::Placebox] = &ActionParser::PlaceBox;

	mapping[Actions::Set_Fog] = &ActionParser::Set_Fog;

	mapping[Actions::Group_Units] = &ActionParser::Group_Units;

	mapping[Actions::Building_Morph] = &ActionParser::Building_Morph;
	mapping[Actions::Unit_Morph] = &ActionParser::Building_Morph;
	mapping[Actions::Train] = &ActionParser::Building_Morph;
	
	mapping[Actions::Cancel_Train] = &ActionParser::Exit_Transport;
	mapping[Actions::Exit_Transport] = &ActionParser::Exit_Transport;

	mapping[Actions::Set_Allies] = &ActionParser::Set_Allies;
	
	mapping[Actions::Cheat] = &ActionParser::Cheat;

	mapping[Actions::Ping_Minimap] = &ActionParser::Ping_Minimap;
	mapping[Actions::Lift_Off] = &ActionParser::Ping_Minimap;

	mapping[Actions::Set_Speed] = &ActionParser::Set_Speed;

	mapping[Actions::Stop] = &ActionParser::Burrow;
	mapping[Actions::Return] = &ActionParser::Burrow;
	mapping[Actions::Cloak_Off] = &ActionParser::Burrow;
	mapping[Actions::Cloak_On] = &ActionParser::Burrow;
	mapping[Actions::Tank_Siege] = &ActionParser::Burrow;
	mapping[Actions::Tank_Unsiege] = &ActionParser::Burrow;
	mapping[Actions::Unload_All] = &ActionParser::Burrow;
	mapping[Actions::Hold_Position] = &ActionParser::Burrow;
	mapping[Actions::Burrow_Down] = &ActionParser::Burrow;
	mapping[Actions::Burrow_Up] = &ActionParser::Burrow;

	mapping[Actions::Research] = &ActionParser::Research;

	mapping[Actions::Upgrade] = &ActionParser::Upgrade;

	mapping[Actions::Voice_Enable] = &ActionParser::Voice;
	mapping[Actions::Voice_Squelch] = &ActionParser::Voice;

	mapping[Actions::Set_Latency] = &ActionParser::Set_Latency;

	mapping[Actions::Leave_Game] = &ActionParser::Leave_Game;

	mapping[Actions::Right_Click] = &ActionParser::Right_Click;

	mapping[Actions::Set_Replay_Speed] = &ActionParser::Set_Replay_Speed;

	mapping[Actions::Target_Click] = &ActionParser::Target_Click;
}

void ActionParser::Save()
{
	DWORD dwSaveInfo = rr->read<DWORD>();
	rr->log("0x%08X, %s", dwSaveInfo, rr->ReadCString().c_str());
}

void ActionParser::PlaceBox()
{
	BWAPI::Order orderType( rr->readOrder() );
    short x = rr->read<short>();
    short y = rr->read<short>();
    BWAPI::UnitType unitType( rr->readUnitType() );
    rr->log("%s, (%d, %d), %s", orderType.c_str(), x, y, unitType.c_str());
}

void ActionParser::Chat_Replay()
{
        BYTE bChatID = rr->read<BYTE>();
        char szMessage[80];
        for ( int i = 0; i < sizeof(szMessage); ++i )
        szMessage[i] = rr->read<char>();
        rr->log("%u, %s", bChatID, szMessage);
}

void ActionParser::Select_Units()
{
			WORD wUnits[12] = { 0 };
		BYTE bUnitCount = rr->read<BYTE>();

		if ( bUnitCount > 12 )
		bUnitCount = 12;
		rr->log("%u", bUnitCount);
		for ( BYTE i = 0; i < bUnitCount; ++i )
		{
		wUnits[i] = rr->read<WORD>();
		rr->log(", %u:%02X", wUnits[i] & 0x7FF, wUnits[i] >> 12);
		}
	

}

void ActionParser::Set_Fog()
{
	rr->log("%04X", rr->read<WORD>() );
}

void ActionParser::Group_Units()
{
	BYTE bGroupType = rr->read<BYTE>();
    BYTE bGroupNum  = rr->read<BYTE>();

    rr->log("%s, %u", bGroupType < 3 ? Actions::pszGroupType[bGroupType] : "INVALID", bGroupNum );
}

void ActionParser::Building_Morph()
{
	rr->log("%s", rr->readUnitType().c_str());

}

void ActionParser::Exit_Transport()
{
	WORD wUnitID = rr->read<WORD>();
    rr->log("(%u, 0x%02X)", wUnitID & 0x7FF, wUnitID >> 12);
}

void ActionParser::Set_Allies()
{
	rr->log("0x%08X", rr->read<DWORD>() );
}

void ActionParser::Cheat()
{
	          DWORD dwCheatFlags = rr->read<DWORD>();
          rr->log("0x%08X", dwCheatFlags);
}

void ActionParser::Ping_Minimap()
{
	          short x = rr->read<short>();
          short y = rr->read<short>();
          rr->log("(%d, %d)", x, y);
}

void ActionParser::Set_Speed()
{
	          BYTE bSpeed = rr->read<BYTE>();
          rr->log("%s", bSpeed < 7 ? Actions::pszGameSpeed[bSpeed] : "INVALID");
}

void  ActionParser::Burrow()
{
rr->log("%s", rr->read<BYTE>() ? "Queued" : "");
}

void ActionParser::Research()
{
	rr->log("%s", rr->readTechType().c_str());
}

void ActionParser::Upgrade()
{
	rr->log("%s", rr->readUpgradeType().c_str());
}

void ActionParser::Voice()
{
	rr->log("%u", rr->read<BYTE>());
}

void ActionParser::Set_Latency()
{
	          BYTE bLatency = rr->read<BYTE>();
          rr->log("%s", bLatency < 3 ? Actions::pszLatency[bLatency] : "INVALID");
}

void ActionParser::Leave_Game()
{
	          BYTE bLeaveType = rr->read<BYTE>();
          rr->log("%s", bLeaveType < 6 ? Actions::pszLeaveType[bLeaveType] : "UNKNOWN");
}

void ActionParser::Right_Click()
{
	short x = rr->read<short>();
          short y = rr->read<short>();
          WORD wTargetID = rr->read<WORD>();
          BWAPI::UnitType unitType( rr->readUnitType() );
          BYTE bHow = rr->read<BYTE>();
          rr->log("(%d, %d), %u:%02X, %s%s", x, y, wTargetID & 0x7FF, wTargetID >> 12, unitType.c_str(), bHow ? ", Queued" : "");
}

void ActionParser::Target_Click()
{
	short x = rr->read<short>();
          short y = rr->read<short>();
          WORD wTargetID = rr->read<WORD>();
          BWAPI::UnitType unitType( rr->readUnitType() );
          BWAPI::Order orderType( rr->readOrder() );
          BYTE bHow = rr->read<BYTE>();
          rr->log("(%d, %d), %u:%02X, %s, %s%s", x, y, wTargetID & 0x7FF, wTargetID >> 12, unitType.c_str(), orderType.c_str(), bHow ? ", Queued" : "");
}
void ActionParser::Set_Replay_Speed()
{
	bool paused = rr->read<bool>();
          DWORD dwSpeed = rr->read<DWORD>();
          DWORD dwMultiplier = rr->read<DWORD>();
          rr->log("%s%s, ×%u", paused ? "PAUSED, " : "", dwSpeed < 7 ? Actions::pszGameSpeed[dwSpeed] : "INVALID", dwMultiplier);
}

void ActionParser::Parse(Actions::Enum action)
{
	if (mapping[action] != NULL)
		(this->*(this->mapping[action]))();
}

