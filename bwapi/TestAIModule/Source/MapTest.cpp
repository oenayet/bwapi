#include "MapTest.h"
using namespace std;
using namespace BWAPI;
void MapTest::onStart()
{
  BWAssert(Broodwar->isReplay()==false);
  Broodwar->enableFlag(Flag::CompleteMapInformation);
  Broodwar->setLocalSpeed(0);
  BWAssert(Broodwar->mapWidth()==192);
  BWAssert(Broodwar->mapHeight()==128);
  BWAssert(Broodwar->mapFileName()=="MapTest.scx");
  //Don't assert this since path is allowed to differ
  Broodwar->printf("%s",Broodwar->mapPathName().c_str());
  BWAssert(Broodwar->mapName()=="Test Map");

  //Update this whenever the map is modified
  BWAssert(Broodwar->mapHash()=="b1458acae03d6bbacd223ba8c96830b28a6035fb");

  for ( TilePosition::iterator p(10,10); p; ++p )
  {
    BWAssert(Broodwar->isWalkable( WalkPosition(p) ));
    BWAssert(Broodwar->getGroundHeight(p)==2);
    BWAssert(Broodwar->isBuildable(p));
    BWAssert(Broodwar->isVisible(p));
    BWAssert(Broodwar->isExplored(p));
  }

  for(int x=5;x<14;x++)
  {
    BWAssertF(Broodwar->hasCreep(x,0), { log("  hasCreep(%u,0)", x); });
  }
  for(int x=14;x<40;x++)
  {
    BWAssert(Broodwar->hasCreep(x,0)==false);
  }
  for(int x=13;x<20;x++)
  {
    for(int y=10;y<15;y++)
    {
      BWAssert(Broodwar->hasPower(x,y,2,2));
    }
  }
  for(int x=50;x<60;x++)
  {
    for(int y=50;y<60;y++)
    {
      BWAssert(Broodwar->getGroundHeight(x,y)==0);
      BWAssert(Broodwar->isBuildable(x,y));
      BWAssert(Broodwar->isVisible(x,y)==false);
      BWAssert(Broodwar->isExplored(x,y)==false);
      BWAssert(Broodwar->hasPower(x,y,2,2)==false);
    }
  }

  //briefly check some of these functions. Can add more test cases later if needed
  BWAssert(Broodwar->canBuildHere(TilePosition(18,12),UnitTypes::Protoss_Pylon));
  BWAssert(Broodwar->canBuildHere(TilePosition(18,12),UnitTypes::Protoss_Gateway));
  BWAssert(Broodwar->canMake(UnitTypes::Protoss_Gateway)==false);
  BWAssert(Broodwar->canResearch(TechTypes::Psionic_Storm)==false);
  BWAssert(Broodwar->canUpgrade(UpgradeTypes::Gravitic_Thrusters)==false);

  //check start locations
  TilePosition::set startLocations = Broodwar->getStartLocations();
  BWAssert(startLocations.size()==4);
  BWAssert((*startLocations.begin()).x==0);
  BWAssert((*startLocations.begin()).y==0);
  startLocations.erase(startLocations.begin());
  BWAssert(startLocations.size()==3);
  BWAssert((*startLocations.begin()).x==4);
  BWAssert((*startLocations.begin()).y==3);
  startLocations.erase(startLocations.begin());
  BWAssert(startLocations.size()==2);
  BWAssert((*startLocations.begin()).x==8);
  BWAssert((*startLocations.begin()).y==6);
  startLocations.erase(startLocations.begin());
  BWAssert(startLocations.size()==1);
  BWAssert((*startLocations.begin()).x==12);
  BWAssert((*startLocations.begin()).y==9);
  startLocations.erase(startLocations.begin());
  BWAssert(startLocations.empty());
  Broodwar->printf("Completed all asserts");
}