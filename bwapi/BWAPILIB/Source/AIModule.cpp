#include <BWAPI/AIModule.h>

#include "../../Debug.h"

namespace BWAPI
{
  AIModule::AIModule()
  { }
  AIModule::~AIModule()
  { }
  void AIModule::onStart()
  { }
  void AIModule::onEnd(bool isWinner)
  { }
  void AIModule::onFrame()
  { }
  void AIModule::onSendText(std::string text)
  { }
  void AIModule::onReceiveText(Player* player, std::string text)
  { }
  void AIModule::onPlayerLeft(Player *player)
  { }
  void AIModule::onNukeDetect(Position target)
  { }
  void AIModule::onUnitDiscover(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitEvade(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitShow(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitHide(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitCreate(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitDestroy(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitMorph(BWAPI::Unit* unit)
  { }
  void AIModule::onUnitRenegade(BWAPI::Unit* unit)
  { }
  void AIModule::onSaveGame(std::string gameName)
  { }
  void AIModule::onUnitComplete(BWAPI::Unit *unit)
  { }

  TournamentModule::TournamentModule()
  { }
  TournamentModule::~TournamentModule()
  { }
  bool TournamentModule::onAction(int actionType, void *parameter)
  {
    return true;
  }
  void TournamentModule::onFirstAdvertisement()
  { }
}
