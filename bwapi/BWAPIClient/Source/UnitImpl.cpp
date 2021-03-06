#include <BWAPI.h>
#include <BWAPI/Client/GameImpl.h>
#include <BWAPI/Client/ForceImpl.h>
#include <BWAPI/Client/PlayerImpl.h>
#include <BWAPI/Client/UnitImpl.h>

#include "TemplatesImpl.h"
#include "Command.h"
#include <Util/Foreach.h>

#include <limits>
#include <string>
namespace BWAPI
{
  UnitImpl::UnitImpl(int id)
    : clientInfo(nullptr)
  {
    this->self = &(BWAPI::BWAPIClient.data->units[id]);
    this->id   = id;
    clear();
  }
  //--------------------------------------------- ISSUE COMMAND ----------------------------------------------
  bool UnitImpl::issueCommand(UnitCommand command)
  {
    if ( !canIssueCommand(command) )
      return false;

    command.unit = this;

    if (command.type == UnitCommandTypes::Train ||
        command.type == UnitCommandTypes::Morph)
      if (getType().producesLarva() && command.getUnitType().whatBuilds().first == UnitTypes::Zerg_Larva )
        command.unit = *getLarva().begin();

    BWAPIC::UnitCommand c;
    c.type      = command.type;
    c.unitIndex = command.unit->getID();
    if ( command.target )
      c.targetIndex = command.target->getID();
    else
      c.targetIndex = -1;
    c.x     = command.x;
    c.y     = command.y;
    c.extra = command.extra;
    Command(command).execute(0);
    ((GameImpl*)Broodwar)->addUnitCommand(c);
    lastCommandFrame = Broodwar->getFrameCount();
    lastCommand      = command;
    return true;
  }
}
