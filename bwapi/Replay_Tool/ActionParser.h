#pragma once
//#include <windows.h>
//#include <string>
#include "Actions.h"

#include <map>
using namespace std;

class ActionParser
{
public:
	ActionParser(ReplayReader * );
	void Parse(Actions::Enum action);	

private:
	map<Actions::Enum, void (ActionParser::*)()> mapping;
	void InitializeMappings();

	void Save();
	void PlaceBox();
	void Chat_Replay();
	void Select_Units();
	void Set_Fog();
	void Group_Units();
	void Building_Morph();
	void Exit_Transport();
	void Set_Allies();
	void Cheat();
	void Ping_Minimap();
	void Set_Speed();
	void Burrow();
	void Research();
	void Upgrade();
	void Voice();
	void Set_Latency();
	void Leave_Game();
	void Right_Click();
	void Set_Replay_Speed();
	void Target_Click();



	ReplayReader * rr;
	
};

