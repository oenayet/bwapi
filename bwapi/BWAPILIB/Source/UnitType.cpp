#include <string>
#include <map>

#include <Util/Foreach.h>

#include <BWAPI/UnitType.h>
#include <BWAPI/WeaponType.h>
#include <BWAPI/UnitSizeType.h>
#include <BWAPI/TechType.h>
#include <BWAPI/UpgradeType.h>
#include <BWAPI/Race.h>

#include "Common.h"

#include "../../Debug.h"

namespace BWAPI
{
  std::string unitLongNames[UnitTypes::Enum::MAX];
  std::string unitLocalNames[UnitTypes::Enum::MAX];

  static const std::string unitTypeNames[UnitTypes::Enum::MAX] = 
  {
    "Terran_Marine",
    "Terran_Ghost",
    "Terran_Vulture",
    "Terran_Goliath",
    "Terran_Goliath_Turret",
    "Terran_Siege_Tank_Tank_Mode",
    "Terran_Siege_Tank_Tank_Mode_Turret",
    "Terran_SCV",
    "Terran_Wraith",
    "Terran_Science_Vessel",
    "Hero_Gui_Montag",
    "Terran_Dropship",
    "Terran_Battlecruiser",
    "Terran_Vulture_Spider_Mine",
    "Terran_Nuclear_Missile",
    "Terran_Civilian",
    "Hero_Sarah_Kerrigan",
    "Hero_Alan_Schezar",
    "Hero_Alan_Schezar_Turret",
    "Hero_Jim_Raynor_Vulture",
    "Hero_Jim_Raynor_Marine",
    "Hero_Tom_Kazansky",
    "Hero_Magellan",
    "Hero_Edmund_Duke_Tank_Mode",
    "Hero_Edmund_Duke_Tank_Mode_Turret",
    "Hero_Edmund_Duke_Siege_Mode",
    "Hero_Edmund_Duke_Siege_Mode_Turret",
    "Hero_Arcturus_Mengsk",
    "Hero_Hyperion",
    "Hero_Norad_II",
    "Terran_Siege_Tank_Siege_Mode",
    "Terran_Siege_Tank_Siege_Mode_Turret",
    "Terran_Firebat",
    "Spell_Scanner_Sweep",
    "Terran_Medic",
    "Zerg_Larva",
    "Zerg_Egg",
    "Zerg_Zergling",
    "Zerg_Hydralisk",
    "Zerg_Ultralisk",
    "Zerg_Broodling",
    "Zerg_Drone",
    "Zerg_Overlord",
    "Zerg_Mutalisk",
    "Zerg_Guardian",
    "Zerg_Queen",
    "Zerg_Defiler",
    "Zerg_Scourge",
    "Hero_Torrasque",
    "Hero_Matriarch",
    "Zerg_Infested_Terran",
    "Hero_Infested_Kerrigan",
    "Hero_Unclean_One",
    "Hero_Hunter_Killer",
    "Hero_Devouring_One",
    "Hero_Kukulza_Mutalisk",
    "Hero_Kukulza_Guardian",
    "Hero_Yggdrasill",
    "Terran_Valkyrie",
    "Zerg_Cocoon",
    "Protoss_Corsair",
    "Protoss_Dark_Templar",
    "Zerg_Devourer",
    "Protoss_Dark_Archon",
    "Protoss_Probe",
    "Protoss_Zealot",
    "Protoss_Dragoon",
    "Protoss_High_Templar",
    "Protoss_Archon",
    "Protoss_Shuttle",
    "Protoss_Scout",
    "Protoss_Arbiter",
    "Protoss_Carrier",
    "Protoss_Interceptor",
    "Hero_Dark_Templar",
    "Hero_Zeratul",
    "Hero_Tassadar_Zeratul_Archon",
    "Hero_Fenix_Zealot",
    "Hero_Fenix_Dragoon",
    "Hero_Tassadar",
    "Hero_Mojo",
    "Hero_Warbringer",
    "Hero_Gantrithor",
    "Protoss_Reaver",
    "Protoss_Observer",
    "Protoss_Scarab",
    "Hero_Danimoth",
    "Hero_Aldaris",
    "Hero_Artanis",
    "Critter_Rhynadon",
    "Critter_Bengalaas",
    "Special_Cargo_Ship",
    "Special_Mercenary_Gunship",
    "Critter_Scantid",
    "Critter_Kakaru",
    "Critter_Ragnasaur",
    "Critter_Ursadon",
    "Zerg_Lurker_Egg",
    "Hero_Raszagal",
    "Hero_Samir_Duran",
    "Hero_Alexei_Stukov",
    "Special_Map_Revealer",
    "Hero_Gerard_DuGalle",
    "Zerg_Lurker",
    "Hero_Infested_Duran",
    "Spell_Disruption_Web",
    "Terran_Command_Center",
    "Terran_Comsat_Station",
    "Terran_Nuclear_Silo",
    "Terran_Supply_Depot",
    "Terran_Refinery",
    "Terran_Barracks",
    "Terran_Academy",
    "Terran_Factory",
    "Terran_Starport",
    "Terran_Control_Tower",
    "Terran_Science_Facility",
    "Terran_Covert_Ops",
    "Terran_Physics_Lab",
    "Unused_Terran1",
    "Terran_Machine_Shop",
    "Unused_Terran2",
    "Terran_Engineering_Bay",
    "Terran_Armory",
    "Terran_Missile_Turret",
    "Terran_Bunker",
    "Special_Crashed_Norad_II",
    "Special_Ion_Cannon",
    "Powerup_Uraj_Crystal",
    "Powerup_Khalis_Crystal",
    "Zerg_Infested_Command_Center",
    "Zerg_Hatchery",
    "Zerg_Lair",
    "Zerg_Hive",
    "Zerg_Nydus_Canal",
    "Zerg_Hydralisk_Den",
    "Zerg_Defiler_Mound",
    "Zerg_Greater_Spire",
    "Zerg_Queens_Nest",
    "Zerg_Evolution_Chamber",
    "Zerg_Ultralisk_Cavern",
    "Zerg_Spire",
    "Zerg_Spawning_Pool",
    "Zerg_Creep_Colony",
    "Zerg_Spore_Colony",
    "Unused_Zerg1",
    "Zerg_Sunken_Colony",
    "Special_Overmind_With_Shell",
    "Special_Overmind",
    "Zerg_Extractor",
    "Special_Mature_Chrysalis",
    "Special_Cerebrate",
    "Special_Cerebrate_Daggoth",
    "Unused_Zerg2",
    "Protoss_Nexus",
    "Protoss_Robotics_Facility",
    "Protoss_Pylon",
    "Protoss_Assimilator",
    "Unused_Protoss1",
    "Protoss_Observatory",
    "Protoss_Gateway",
    "Unused_Protoss2",
    "Protoss_Photon_Cannon",
    "Protoss_Citadel_of_Adun",
    "Protoss_Cybernetics_Core",
    "Protoss_Templar_Archives",
    "Protoss_Forge",
    "Protoss_Stargate",
    "Special_Stasis_Cell_Prison",
    "Protoss_Fleet_Beacon",
    "Protoss_Arbiter_Tribunal",
    "Protoss_Robotics_Support_Bay",
    "Protoss_Shield_Battery",
    "Special_Khaydarin_Crystal_Form",
    "Special_Protoss_Temple",
    "Special_XelNaga_Temple",
    "Resource_Mineral_Field",
    "Resource_Mineral_Field_Type_2",
    "Resource_Mineral_Field_Type_3",
    "Unused_Cave",
    "Unused_Cave_In",
    "Unused_Cantina",
    "Unused_Mining_Platform",
    "Unused_Independant_Command_Center",
    "Special_Independant_Starport",
    "Unused_Independant_Jump_Gate",
    "Unused_Ruins",
    "Unused_Khaydarin_Crystal_Formation",
    "Resource_Vespene_Geyser",
    "Special_Warp_Gate",
    "Special_Psi_Disrupter",
    "Unused_Zerg_Marker",
    "Unused_Terran_Marker",
    "Unused_Protoss_Marker",
    "Special_Zerg_Beacon",
    "Special_Terran_Beacon",
    "Special_Protoss_Beacon",
    "Special_Zerg_Flag_Beacon",
    "Special_Terran_Flag_Beacon",
    "Special_Protoss_Flag_Beacon",
    "Special_Power_Generator",
    "Special_Overmind_Cocoon",
    "Spell_Dark_Swarm",
    "Special_Floor_Missile_Trap",
    "Special_Floor_Hatch",
    "Special_Upper_Level_Door",
    "Special_Right_Upper_Level_Door",
    "Special_Pit_Door",
    "Special_Right_Pit_Door",
    "Special_Floor_Gun_Trap",
    "Special_Wall_Missile_Trap",
    "Special_Wall_Flame_Trap",
    "Special_Right_Wall_Missile_Trap",
    "Special_Right_Wall_Flame_Trap",
    "Special_Start_Location",
    "Powerup_Flag",
    "Powerup_Young_Chrysalis",
    "Powerup_Psi_Emitter",
    "Powerup_Data_Disk",
    "Powerup_Khaydarin_Crystal",
    "Powerup_Mineral_Cluster_Type_1",
    "Powerup_Mineral_Cluster_Type_2",
    "Powerup_Protoss_Gas_Orb_Type_1",
    "Powerup_Protoss_Gas_Orb_Type_2",
    "Powerup_Zerg_Gas_Sac_Type_1",
    "Powerup_Zerg_Gas_Sac_Type_2",
    "Powerup_Terran_Gas_Tank_Type_1",
    "Powerup_Terran_Gas_Tank_Type_2",

    "None",
    "AllUnits",
    "Men",
    "Buildings",
    "Factories",
    "Unknown"
  };
  
  static const std::string unitShortNames[UnitTypes::Enum::MAX] = 
  {
    "marine",
    "ghost",
    "vulture",
    "goliath",
    "",
    "siege_tank",
    "",
    "scv",
    "wraith",
    "science_vessel",
    "gui_montag",
    "dropship",
    "battlecruiser",
    "spider_mine",
    "nuke",
    "civilian",
    "sarah_kerrigan",
    "alan_schezar",
    "",
    "jim_raynor_vulture",
    "jim_raynor_marine",
    "tom_kazansky",
    "magellan",
    "edmund_duke",
    "",
    "edmund_duke_sieged",
    "",
    "arcturus_mengsk",
    "hyperion",
    "norad_2",
    "siege_tank_sieged",
    "",
    "firebat",
    "",
    "medic",
    "larva",
    "egg",
    "zergling",
    "hydralisk",
    "ultralisk",
    "broodling",
    "drone",
    "overlord",
    "mutalisk",
    "guardian",
    "queen",
    "defiler",
    "scourge",
    "torrasque",
    "matriarch",
    "infested_terran",
    "infested_kerrigan",
    "unclean_one",
    "hunter_killer",
    "devouring_one",
    "kukulza",
    "kukulza_guardian",
    "yggdrasill",
    "valkyrie",
    "cocoon",
    "corsair",
    "dark_templar",
    "devourer",
    "dark_archon",
    "probe",
    "zealot",
    "dragoon",
    "high_templar",
    "archon",
    "shuttle",
    "scout",
    "arbiter",
    "carrier",
    "interceptor",
    "dark_templar_hero",
    "zeratul",
    "tassadar_zeratul",
    "fenix_zealot",
    "fenix_dragoon",
    "tassadar",
    "mojo",
    "warbringer",
    "gantrithor",
    "reaver",
    "observer",
    "scarab",
    "danimoth",
    "aldaris",
    "artanis",
    "rhynadon",
    "bengalaas",
    "",
    "",
    "scantid",
    "kakaru",
    "ragnasaur",
    "ursadon",
    "lurker_egg",
    "raszagal",
    "samir_duran",
    "alexei_stukov",
    "",
    "gerard_dugalle",
    "lurker",
    "infested_duran",
    "",
    "command_center",
    "comsat_station",
    "nuke_silo",
    "supply_depot",
    "refinery",
    "barracks",
    "academy",
    "factory",
    "starport",
    "control_tower",
    "science_facility",
    "covert_ops",
    "physics_lab",
    "",
    "machine_shop",
    "",
    "engineering_bay",
    "armory",
    "missile_turret",
    "bunker",
    "",
    "",
    "",
    "",
    "infested_command_center",
    "hatchery",
    "lair",
    "hive",
    "nydus_canal",
    "hydralisk_den",
    "defiler_mound",
    "greater_spire",
    "queens_nest",
    "evolution_chamber",
    "ultralisk_cavern",
    "spire",
    "spawning_pool",
    "creep_colony",
    "spore_colony",
    "",
    "sunken_colony",
    "",
    "",
    "extractor",
    "",
    "",
    "",
    "",
    "nexus",
    "robotics_facility",
    "pylon",
    "assimilator",
    "",
    "observatory",
    "gateway",
    "",
    "photon_cannon",
    "citadel_of_adun",
    "cybernetics_core",
    "templar_archives",
    "forge",
    "stargate",
    "",
    "fleet_beacon",
    "arbiter_tribunal",
    "robotics_support",
    "shield_battery",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "none",
    "all",
    "men"
    "buildings",
    "factories",
    "unknown"
  };

  class UnitTypeInternal
  {
    public:
      UnitTypeInternal() {valid = false;}
      void set(const char* name, Race race, bool isHero, UnitType whatBuilds, int whatBuildsAmt, UnitType requiredUnit1, UnitType requiredUnit2, TechType requiredTech, TechType ability1, TechType ability2, TechType ability3, TechType ability4, UpgradeType armorUpgrade, int maxHitPoints, int maxShields, int maxEnergy, int armor,  int mineralPrice, int gasPrice, int buildTime, int supplyRequired, int supplyProvided, int spaceRequired, int spaceProvided, int buildScore, int destroyScore, UnitSizeType unitSizeType, int tileWidth, int tileHeight, int dimensionLeft, int dimensionUp, int dimensionRight, int dimensionDown,  int seekRange, int sightRange, WeaponType groundWeapon, int maxGroundHits, WeaponType airWeapon, int maxAirHits, double topSpeed, int acceleration, int haltDistance, int turnRadius, bool canProduce, bool canMove, bool isFlyer, bool regeneratesHP, bool hasPermanentCloak, bool isInvincible, bool isOrganic, bool isMechanical, bool isRobotic, bool isDetector, bool isResourceContainer, bool isResourceDepot, bool isWorker, bool requiresPsi, bool requiresCreep, bool isTwoUnitsInOneEgg, bool isBurrowable, bool isCloakable, bool isBuilding, bool isAddon, bool isFlyingBuilding, bool isNeutral, bool isRefinery)
      {
        this->name   = name;
        this->race   = race;
        this->isHero = isHero;

        this->whatBuilds = std::make_pair(whatBuilds, whatBuildsAmt);

        if ( whatBuilds != UnitTypes::None && whatBuildsAmt > 0 )
          this->requiredUnits.insert(this->whatBuilds);

        if ( requiredUnit1 != UnitTypes::None )
          this->requiredUnits.insert(std::make_pair(requiredUnit1, 1));

        if ( requiredUnit2 != UnitTypes::None )
          this->requiredUnits.insert(std::make_pair(requiredUnit2, 1));

        this->requiredTech = requiredTech;
        if (ability1 != TechTypes::None)
          this->abilities.insert(ability1);

        if (ability2 != TechTypes::None)
          this->abilities.insert(ability2);

        if (ability3 != TechTypes::None)
          this->abilities.insert(ability3);

        if (ability4 != TechTypes::None)
          this->abilities.insert(ability4);

        this->cloakingTech = TechTypes::None;

        if ( this->abilities.find(TechTypes::Cloaking_Field) != this->abilities.end() )
          cloakingTech = TechTypes::Cloaking_Field;
        if ( this->abilities.find(TechTypes::Personnel_Cloaking) != this->abilities.end() )
          cloakingTech = TechTypes::Personnel_Cloaking;

        this->armorUpgrade = armorUpgrade;
        this->maxHitPoints = maxHitPoints;
        this->maxShields   = maxShields;
        this->maxEnergy    = maxEnergy;
        this->armor        = armor;

        this->mineralPrice = mineralPrice;
        this->gasPrice     = gasPrice;
        this->buildTime    = buildTime;

        this->supplyRequired = supplyRequired;
        this->supplyProvided = supplyProvided;
        this->spaceRequired  = spaceRequired;
        this->spaceProvided  = spaceProvided;
        this->buildScore     = buildScore;
        this->destroyScore   = destroyScore;

        this->unitSizeType   = unitSizeType;
        this->tileWidth      = tileWidth;
        this->tileHeight     = tileHeight;
        this->dimensionLeft  = dimensionLeft;
        this->dimensionUp    = dimensionUp;
        this->dimensionRight = dimensionRight;
        this->dimensionDown  = dimensionDown;

        this->seekRange     = seekRange;
        this->sightRange    = sightRange;
        this->groundWeapon  = groundWeapon;
        this->maxGroundHits = maxGroundHits;
        this->airWeapon     = airWeapon;
        this->maxAirHits    = maxAirHits;

        this->topSpeed     = topSpeed;
        this->acceleration = acceleration;
        this->haltDistance = haltDistance;
        this->turnRadius   = turnRadius;

        this->canProduce = canProduce;
        this->canAttack  = groundWeapon != WeaponTypes::None || airWeapon != WeaponTypes::None;
        this->canMove    = canMove;

        this->isFlyer             = isFlyer;
        this->regeneratesHP       = regeneratesHP;
        this->isSpellcaster       = maxEnergy > 0;
        this->hasPermanentCloak   = hasPermanentCloak;
        this->isInvincible        = isInvincible;
        this->isOrganic           = isOrganic;
        this->isMechanical        = isMechanical;
        this->isRobotic           = isRobotic;
        this->isDetector          = isDetector;
        this->isResourceContainer = isResourceContainer;
        this->isResourceDepot     = isResourceDepot;
        this->isWorker            = isWorker;
        this->requiresPsi         = requiresPsi;
        this->requiresCreep       = requiresCreep;
        this->isTwoUnitsInOneEgg  = isTwoUnitsInOneEgg;
        this->isBurrowable        = isBurrowable;
        this->isCloakable         = isCloakable;
        this->isBuilding          = isBuilding;
        this->isAddon             = isAddon;
        this->isFlyingBuilding    = isFlyingBuilding;
        this->isNeutral           = isNeutral;
        this->isRefinery          = isRefinery;

        this->isSpecialBuilding = this->isBuilding && this->whatBuilds.second == 0;

        this->valid = true;
      }
      std::string name;
      Race        race;

      std::pair<UnitType, int> whatBuilds;
      std::map<UnitType, int>  requiredUnits;

      TechType      requiredTech;
      TechType      cloakingTech;
      TechType::set    abilities;
      UpgradeType::set  upgrades;
      UpgradeType      armorUpgrade;

      int maxHitPoints;
      int maxShields;
      int maxEnergy;
      int armor;

      int mineralPrice;
      int gasPrice;
      int buildTime;

      int supplyRequired;
      int supplyProvided;
      int spaceRequired;
      int spaceProvided;
      int buildScore;
      int destroyScore;

      UnitSizeType unitSizeType;
      int tileWidth;
      int tileHeight;
      int dimensionLeft;
      int dimensionUp;
      int dimensionRight;
      int dimensionDown;

      int seekRange;
      int sightRange;
      WeaponType groundWeapon;
      int maxGroundHits;
      WeaponType airWeapon;
      int maxAirHits;

      double topSpeed;
      int acceleration;
      int haltDistance;
      int turnRadius;

      bool canProduce;
      bool canAttack;
      bool canMove;
      bool isFlyer;
      bool regeneratesHP;
      bool isSpellcaster;
      bool hasPermanentCloak;
      bool isInvincible;
      bool isOrganic;
      bool isMechanical;
      bool isRobotic;
      bool isDetector;
      bool isResourceContainer;
      bool isResourceDepot;
      bool isWorker;
      bool requiresPsi;
      bool requiresCreep;
      bool isTwoUnitsInOneEgg;
      bool isBurrowable;
      bool isCloakable;
      bool isBuilding;
      bool isAddon;
      bool isFlyingBuilding;
      bool isNeutral;
      bool isRefinery;
      bool isHero;
      bool isSpecialBuilding;

      bool valid;
  };
  UnitTypeInternal unitTypeData[245];
  UnitType::set unitTypeSet;
  UnitType::set macroTypeSet;
  int maxWidth;
  int maxHeight;
  namespace UnitTypes
  {
    BWAPI_TYPEDEF(UnitType,Terran_Marine);
    BWAPI_TYPEDEF(UnitType,Terran_Ghost);
    BWAPI_TYPEDEF(UnitType,Terran_Vulture);
    BWAPI_TYPEDEF(UnitType,Terran_Goliath);
    // goliath turret (4)
    BWAPI_TYPEDEF(UnitType,Terran_Siege_Tank_Tank_Mode);
    // siege tank turret (6)
    BWAPI_TYPEDEF(UnitType,Terran_SCV);
    BWAPI_TYPEDEF(UnitType,Terran_Wraith);
    BWAPI_TYPEDEF(UnitType,Terran_Science_Vessel);
    BWAPI_TYPEDEF(UnitType,Hero_Gui_Montag);
    BWAPI_TYPEDEF(UnitType,Terran_Dropship);
    BWAPI_TYPEDEF(UnitType,Terran_Battlecruiser);
    BWAPI_TYPEDEF(UnitType,Terran_Vulture_Spider_Mine);
    BWAPI_TYPEDEF(UnitType,Terran_Nuclear_Missile);
    BWAPI_TYPEDEF(UnitType,Terran_Civilian);
    BWAPI_TYPEDEF(UnitType,Hero_Sarah_Kerrigan);
    BWAPI_TYPEDEF(UnitType,Hero_Alan_Schezar);
    // alan turret (18)
    BWAPI_TYPEDEF(UnitType,Hero_Jim_Raynor_Vulture);
    BWAPI_TYPEDEF(UnitType,Hero_Jim_Raynor_Marine);
    BWAPI_TYPEDEF(UnitType,Hero_Tom_Kazansky);
    BWAPI_TYPEDEF(UnitType,Hero_Magellan);
    BWAPI_TYPEDEF(UnitType,Hero_Edmund_Duke_Tank_Mode);
    // edmund duke turret (24)
    BWAPI_TYPEDEF(UnitType,Hero_Edmund_Duke_Siege_Mode);
    // edmund duke turret siege mode (26)
    BWAPI_TYPEDEF(UnitType,Hero_Arcturus_Mengsk);
    BWAPI_TYPEDEF(UnitType,Hero_Hyperion);
    BWAPI_TYPEDEF(UnitType,Hero_Norad_II);
    BWAPI_TYPEDEF(UnitType,Terran_Siege_Tank_Siege_Mode);
    // siege tank siege mode turret (31)
    BWAPI_TYPEDEF(UnitType,Terran_Firebat);
    BWAPI_TYPEDEF(UnitType,Spell_Scanner_Sweep);
    BWAPI_TYPEDEF(UnitType,Terran_Medic);
    BWAPI_TYPEDEF(UnitType,Zerg_Larva);
    BWAPI_TYPEDEF(UnitType,Zerg_Egg);
    BWAPI_TYPEDEF(UnitType,Zerg_Zergling);
    BWAPI_TYPEDEF(UnitType,Zerg_Hydralisk);
    BWAPI_TYPEDEF(UnitType,Zerg_Ultralisk);
    BWAPI_TYPEDEF(UnitType,Zerg_Broodling);
    BWAPI_TYPEDEF(UnitType,Zerg_Drone);
    BWAPI_TYPEDEF(UnitType,Zerg_Overlord);
    BWAPI_TYPEDEF(UnitType,Zerg_Mutalisk);
    BWAPI_TYPEDEF(UnitType,Zerg_Guardian);
    BWAPI_TYPEDEF(UnitType,Zerg_Queen);
    BWAPI_TYPEDEF(UnitType,Zerg_Defiler);
    BWAPI_TYPEDEF(UnitType,Zerg_Scourge);
    BWAPI_TYPEDEF(UnitType,Hero_Torrasque);
    BWAPI_TYPEDEF(UnitType,Hero_Matriarch);
    BWAPI_TYPEDEF(UnitType,Zerg_Infested_Terran);
    BWAPI_TYPEDEF(UnitType,Hero_Infested_Kerrigan);
    BWAPI_TYPEDEF(UnitType,Hero_Unclean_One);
    BWAPI_TYPEDEF(UnitType,Hero_Hunter_Killer);
    BWAPI_TYPEDEF(UnitType,Hero_Devouring_One);
    BWAPI_TYPEDEF(UnitType,Hero_Kukulza_Mutalisk);
    BWAPI_TYPEDEF(UnitType,Hero_Kukulza_Guardian);
    BWAPI_TYPEDEF(UnitType,Hero_Yggdrasill);
    BWAPI_TYPEDEF(UnitType,Terran_Valkyrie);
    BWAPI_TYPEDEF(UnitType,Zerg_Cocoon);
    BWAPI_TYPEDEF(UnitType,Protoss_Corsair);
    BWAPI_TYPEDEF(UnitType,Protoss_Dark_Templar);
    BWAPI_TYPEDEF(UnitType,Zerg_Devourer);
    BWAPI_TYPEDEF(UnitType,Protoss_Dark_Archon);
    BWAPI_TYPEDEF(UnitType,Protoss_Probe);
    BWAPI_TYPEDEF(UnitType,Protoss_Zealot);
    BWAPI_TYPEDEF(UnitType,Protoss_Dragoon);
    BWAPI_TYPEDEF(UnitType,Protoss_High_Templar);
    BWAPI_TYPEDEF(UnitType,Protoss_Archon);
    BWAPI_TYPEDEF(UnitType,Protoss_Shuttle);
    BWAPI_TYPEDEF(UnitType,Protoss_Scout);
    BWAPI_TYPEDEF(UnitType,Protoss_Arbiter);
    BWAPI_TYPEDEF(UnitType,Protoss_Carrier);
    BWAPI_TYPEDEF(UnitType,Protoss_Interceptor);
    BWAPI_TYPEDEF(UnitType,Hero_Dark_Templar);
    BWAPI_TYPEDEF(UnitType,Hero_Zeratul);
    BWAPI_TYPEDEF(UnitType,Hero_Tassadar_Zeratul_Archon);
    BWAPI_TYPEDEF(UnitType,Hero_Fenix_Zealot);
    BWAPI_TYPEDEF(UnitType,Hero_Fenix_Dragoon);
    BWAPI_TYPEDEF(UnitType,Hero_Tassadar);
    BWAPI_TYPEDEF(UnitType,Hero_Mojo);
    BWAPI_TYPEDEF(UnitType,Hero_Warbringer);
    BWAPI_TYPEDEF(UnitType,Hero_Gantrithor);
    BWAPI_TYPEDEF(UnitType,Protoss_Reaver);
    BWAPI_TYPEDEF(UnitType,Protoss_Observer);
    BWAPI_TYPEDEF(UnitType,Protoss_Scarab);
    BWAPI_TYPEDEF(UnitType,Hero_Danimoth);
    BWAPI_TYPEDEF(UnitType,Hero_Aldaris);
    BWAPI_TYPEDEF(UnitType,Hero_Artanis);
    BWAPI_TYPEDEF(UnitType,Critter_Rhynadon);
    BWAPI_TYPEDEF(UnitType,Critter_Bengalaas);
    BWAPI_TYPEDEF(UnitType,Special_Cargo_Ship);
    BWAPI_TYPEDEF(UnitType,Special_Mercenary_Gunship);
    BWAPI_TYPEDEF(UnitType,Critter_Scantid);
    BWAPI_TYPEDEF(UnitType,Critter_Kakaru);
    BWAPI_TYPEDEF(UnitType,Critter_Ragnasaur);
    BWAPI_TYPEDEF(UnitType,Critter_Ursadon);
    BWAPI_TYPEDEF(UnitType,Zerg_Lurker_Egg);
    BWAPI_TYPEDEF(UnitType,Hero_Raszagal);
    BWAPI_TYPEDEF(UnitType,Hero_Samir_Duran);
    BWAPI_TYPEDEF(UnitType,Hero_Alexei_Stukov);
    BWAPI_TYPEDEF(UnitType,Special_Map_Revealer);
    BWAPI_TYPEDEF(UnitType,Hero_Gerard_DuGalle);
    BWAPI_TYPEDEF(UnitType,Zerg_Lurker);
    BWAPI_TYPEDEF(UnitType,Hero_Infested_Duran);
    BWAPI_TYPEDEF(UnitType,Spell_Disruption_Web);
    BWAPI_TYPEDEF(UnitType,Terran_Command_Center);
    BWAPI_TYPEDEF(UnitType,Terran_Comsat_Station);
    BWAPI_TYPEDEF(UnitType,Terran_Nuclear_Silo);
    BWAPI_TYPEDEF(UnitType,Terran_Supply_Depot);
    BWAPI_TYPEDEF(UnitType,Terran_Refinery);
    BWAPI_TYPEDEF(UnitType,Terran_Barracks);
    BWAPI_TYPEDEF(UnitType,Terran_Academy);
    BWAPI_TYPEDEF(UnitType,Terran_Factory);
    BWAPI_TYPEDEF(UnitType,Terran_Starport);
    BWAPI_TYPEDEF(UnitType,Terran_Control_Tower);
    BWAPI_TYPEDEF(UnitType,Terran_Science_Facility);
    BWAPI_TYPEDEF(UnitType,Terran_Covert_Ops);
    BWAPI_TYPEDEF(UnitType,Terran_Physics_Lab);
    // starbase (119)
    BWAPI_TYPEDEF(UnitType,Terran_Machine_Shop);
    // repair bay (121)
    BWAPI_TYPEDEF(UnitType,Terran_Engineering_Bay);
    BWAPI_TYPEDEF(UnitType,Terran_Armory);
    BWAPI_TYPEDEF(UnitType,Terran_Missile_Turret);
    BWAPI_TYPEDEF(UnitType,Terran_Bunker);
    BWAPI_TYPEDEF(UnitType,Special_Crashed_Norad_II);
    BWAPI_TYPEDEF(UnitType,Special_Ion_Cannon);
    BWAPI_TYPEDEF(UnitType,Powerup_Uraj_Crystal);
    BWAPI_TYPEDEF(UnitType,Powerup_Khalis_Crystal);
    BWAPI_TYPEDEF(UnitType,Zerg_Infested_Command_Center);
    BWAPI_TYPEDEF(UnitType,Zerg_Hatchery);
    BWAPI_TYPEDEF(UnitType,Zerg_Lair);
    BWAPI_TYPEDEF(UnitType,Zerg_Hive);
    BWAPI_TYPEDEF(UnitType,Zerg_Nydus_Canal);
    BWAPI_TYPEDEF(UnitType,Zerg_Hydralisk_Den);
    BWAPI_TYPEDEF(UnitType,Zerg_Defiler_Mound);
    BWAPI_TYPEDEF(UnitType,Zerg_Greater_Spire);
    BWAPI_TYPEDEF(UnitType,Zerg_Queens_Nest);
    BWAPI_TYPEDEF(UnitType,Zerg_Evolution_Chamber);
    BWAPI_TYPEDEF(UnitType,Zerg_Ultralisk_Cavern);
    BWAPI_TYPEDEF(UnitType,Zerg_Spire);
    BWAPI_TYPEDEF(UnitType,Zerg_Spawning_Pool);
    BWAPI_TYPEDEF(UnitType,Zerg_Creep_Colony);
    BWAPI_TYPEDEF(UnitType,Zerg_Spore_Colony);
    // unused zerg 1 (145)
    BWAPI_TYPEDEF(UnitType,Zerg_Sunken_Colony);
    BWAPI_TYPEDEF(UnitType,Special_Overmind_With_Shell);
    BWAPI_TYPEDEF(UnitType,Special_Overmind);
    BWAPI_TYPEDEF(UnitType,Zerg_Extractor);
    BWAPI_TYPEDEF(UnitType,Special_Mature_Chrysalis);
    BWAPI_TYPEDEF(UnitType,Special_Cerebrate);
    BWAPI_TYPEDEF(UnitType,Special_Cerebrate_Daggoth);
    // unused zerg 2 (153)
    BWAPI_TYPEDEF(UnitType,Protoss_Nexus);
    BWAPI_TYPEDEF(UnitType,Protoss_Robotics_Facility);
    BWAPI_TYPEDEF(UnitType,Protoss_Pylon);
    BWAPI_TYPEDEF(UnitType,Protoss_Assimilator);
    // unused protoss 1 (158)
    BWAPI_TYPEDEF(UnitType,Protoss_Observatory);
    BWAPI_TYPEDEF(UnitType,Protoss_Gateway);
    // unused protoss 2 (161)
    BWAPI_TYPEDEF(UnitType,Protoss_Photon_Cannon);
    BWAPI_TYPEDEF(UnitType,Protoss_Citadel_of_Adun);
    BWAPI_TYPEDEF(UnitType,Protoss_Cybernetics_Core);
    BWAPI_TYPEDEF(UnitType,Protoss_Templar_Archives);
    BWAPI_TYPEDEF(UnitType,Protoss_Forge);
    BWAPI_TYPEDEF(UnitType,Protoss_Stargate);
    BWAPI_TYPEDEF(UnitType,Special_Stasis_Cell_Prison);
    BWAPI_TYPEDEF(UnitType,Protoss_Fleet_Beacon);
    BWAPI_TYPEDEF(UnitType,Protoss_Arbiter_Tribunal);
    BWAPI_TYPEDEF(UnitType,Protoss_Robotics_Support_Bay);
    BWAPI_TYPEDEF(UnitType,Protoss_Shield_Battery);
    BWAPI_TYPEDEF(UnitType,Special_Khaydarin_Crystal_Form);
    BWAPI_TYPEDEF(UnitType,Special_Protoss_Temple);
    BWAPI_TYPEDEF(UnitType,Special_XelNaga_Temple);
    BWAPI_TYPEDEF(UnitType,Resource_Mineral_Field);
    BWAPI_TYPEDEF(UnitType,Resource_Mineral_Field_Type_2);
    BWAPI_TYPEDEF(UnitType,Resource_Mineral_Field_Type_3);
    // cave (179)
    // cave-in (180)
    // cantina (181)
    // mining platform (182)
    // independant command center (183)
    BWAPI_TYPEDEF(UnitType,Special_Independant_Starport);
    // independant jump gate (185)
    // ruins (186)
    // unused khaydarin crystal formation (187)
    BWAPI_TYPEDEF(UnitType,Resource_Vespene_Geyser);
    BWAPI_TYPEDEF(UnitType,Special_Warp_Gate);
    BWAPI_TYPEDEF(UnitType,Special_Psi_Disrupter);
    // zerg marker (191)
    // terran marker (192)
    // protoss marker (193)
    BWAPI_TYPEDEF(UnitType,Special_Zerg_Beacon);
    BWAPI_TYPEDEF(UnitType,Special_Terran_Beacon);
    BWAPI_TYPEDEF(UnitType,Special_Protoss_Beacon);
    BWAPI_TYPEDEF(UnitType,Special_Zerg_Flag_Beacon);
    BWAPI_TYPEDEF(UnitType,Special_Terran_Flag_Beacon);
    BWAPI_TYPEDEF(UnitType,Special_Protoss_Flag_Beacon);
    BWAPI_TYPEDEF(UnitType,Special_Power_Generator);
    BWAPI_TYPEDEF(UnitType,Special_Overmind_Cocoon);
    BWAPI_TYPEDEF(UnitType,Spell_Dark_Swarm);
    BWAPI_TYPEDEF(UnitType,Special_Floor_Missile_Trap);
    BWAPI_TYPEDEF(UnitType,Special_Floor_Hatch);
    BWAPI_TYPEDEF(UnitType,Special_Upper_Level_Door);
    BWAPI_TYPEDEF(UnitType,Special_Right_Upper_Level_Door);
    BWAPI_TYPEDEF(UnitType,Special_Pit_Door);
    BWAPI_TYPEDEF(UnitType,Special_Right_Pit_Door);
    BWAPI_TYPEDEF(UnitType,Special_Floor_Gun_Trap);
    BWAPI_TYPEDEF(UnitType,Special_Wall_Missile_Trap);
    BWAPI_TYPEDEF(UnitType,Special_Wall_Flame_Trap);
    BWAPI_TYPEDEF(UnitType,Special_Right_Wall_Missile_Trap);
    BWAPI_TYPEDEF(UnitType,Special_Right_Wall_Flame_Trap);
    BWAPI_TYPEDEF(UnitType,Special_Start_Location);
    BWAPI_TYPEDEF(UnitType,Powerup_Flag);
    BWAPI_TYPEDEF(UnitType,Powerup_Young_Chrysalis);
    BWAPI_TYPEDEF(UnitType,Powerup_Psi_Emitter);
    BWAPI_TYPEDEF(UnitType,Powerup_Data_Disk);
    BWAPI_TYPEDEF(UnitType,Powerup_Khaydarin_Crystal);
    BWAPI_TYPEDEF(UnitType,Powerup_Mineral_Cluster_Type_1);
    BWAPI_TYPEDEF(UnitType,Powerup_Mineral_Cluster_Type_2);
    BWAPI_TYPEDEF(UnitType,Powerup_Protoss_Gas_Orb_Type_1);
    BWAPI_TYPEDEF(UnitType,Powerup_Protoss_Gas_Orb_Type_2);
    BWAPI_TYPEDEF(UnitType,Powerup_Zerg_Gas_Sac_Type_1);
    BWAPI_TYPEDEF(UnitType,Powerup_Zerg_Gas_Sac_Type_2);
    BWAPI_TYPEDEF(UnitType,Powerup_Terran_Gas_Tank_Type_1);
    BWAPI_TYPEDEF(UnitType,Powerup_Terran_Gas_Tank_Type_2);

    BWAPI_TYPEDEF(UnitType,None);
    BWAPI_TYPEDEF(UnitType,AllUnits);
    BWAPI_TYPEDEF(UnitType,Men);
    BWAPI_TYPEDEF(UnitType,Buildings);
    BWAPI_TYPEDEF(UnitType,Factories);
    BWAPI_TYPEDEF(UnitType,Unknown);

    void init()
    {
      unitTypeData[Terran_Marine].set("Terran Marine", Races::Terran, 0, Terran_Barracks, 1, None, None, TechTypes::None, TechTypes::Stim_Packs, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 40, 0, 0, 0, 50, 0, 360, 2, 0, 1, 0, 50, 100, UnitSizeTypes::Small, 1, 1, 8, 9, 8, 10, 128, 224, WeaponTypes::Gauss_Rifle, 1, WeaponTypes::Gauss_Rifle, 1, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Jim_Raynor_Marine].set("Hero Jim Raynor Marine", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Stim_Packs, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 200, 0, 0, 3, 50, 0, 1, 0, 0, 1, 0, 0, 200, UnitSizeTypes::Small, 1, 1, 8, 9, 8, 10, 128, 224, WeaponTypes::Gauss_Rifle_Jim_Raynor, 1, WeaponTypes::Gauss_Rifle_Jim_Raynor, 1, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Ghost].set("Terran Ghost", Races::Terran, 0, Terran_Barracks, 1, Terran_Academy, Terran_Covert_Ops, TechTypes::None, TechTypes::Lockdown, TechTypes::Personnel_Cloaking, TechTypes::Nuclear_Strike, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 45, 0, 200, 0, 25, 75, 750, 2, 0, 1, 0, 175, 350, UnitSizeTypes::Small, 1, 1, 7, 10, 7, 11, 224, 288, WeaponTypes::C_10_Canister_Rifle, 1, WeaponTypes::C_10_Canister_Rifle, 1, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Sarah_Kerrigan].set("Hero Sarah Kerrigan", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Lockdown, TechTypes::Personnel_Cloaking, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 250, 0, 250, 3, 50, 150, 1500, 0, 0, 1, 0, 0, 700, UnitSizeTypes::Small, 1, 1, 7, 10, 7, 11, 224, 352, WeaponTypes::C_10_Canister_Rifle_Sarah_Kerrigan, 1, WeaponTypes::C_10_Canister_Rifle_Sarah_Kerrigan, 1, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Samir_Duran].set("Hero Samir Duran", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Lockdown, TechTypes::Personnel_Cloaking, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 200, 0, 250, 2, 200, 75, 1500, 0, 0, 1, 0, 0, 700, UnitSizeTypes::Small, 1, 1, 7, 10, 7, 11, 224, 320, WeaponTypes::C_10_Canister_Rifle_Samir_Duran, 1, WeaponTypes::C_10_Canister_Rifle_Samir_Duran, 1, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Infested_Duran].set("Hero Infested Duran", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::Lockdown, TechTypes::Personnel_Cloaking, TechTypes::Consume, TechTypes::None, UpgradeTypes::Zerg_Carapace, 300, 0, 250, 3, 200, 75, 1500, 0, 0, 1, 0, 0, 700, UnitSizeTypes::Small, 1, 1, 7, 10, 7, 11, 224, 352, WeaponTypes::C_10_Canister_Rifle_Infested_Duran, 1, WeaponTypes::C_10_Canister_Rifle_Infested_Duran, 1, 4, 1, 1, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Alexei_Stukov].set("Hero Alexei Stukov", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Lockdown, TechTypes::Personnel_Cloaking, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 250, 0, 250, 3, 200, 75, 1500, 0, 0, 1, 0, 0, 700, UnitSizeTypes::Small, 1, 1, 7, 10, 7, 11, 224, 352, WeaponTypes::C_10_Canister_Rifle_Alexei_Stukov, 1, WeaponTypes::C_10_Canister_Rifle_Alexei_Stukov, 1, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Vulture].set("Terran Vulture", Races::Terran, 0, Terran_Factory, 1, None, None, TechTypes::None, TechTypes::Spider_Mines, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 80, 0, 0, 0, 75, 0, 450, 4, 0, 2, 0, 75, 150, UnitSizeTypes::Medium, 1, 1, 16, 16, 15, 15, 160, 256, WeaponTypes::Fragmentation_Grenade, 1, WeaponTypes::None, 0, 6.4, 100, 14569, 40, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Jim_Raynor_Vulture].set("Hero Jim Raynor Vulture", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Spider_Mines, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 300, 0, 0, 3, 150, 0, 900, 0, 0, 2, 0, 0, 300, UnitSizeTypes::Medium, 1, 1, 16, 16, 15, 15, 160, 256, WeaponTypes::Fragmentation_Grenade_Jim_Raynor, 1, WeaponTypes::None, 0, 6.4, 100, 14569, 40, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Goliath].set("Terran Goliath", Races::Terran, 0, Terran_Factory, 1, Terran_Armory, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 125, 0, 0, 1, 100, 50, 600, 4, 0, 2, 0, 200, 400, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 192, 256, WeaponTypes::Twin_Autocannons, 1, WeaponTypes::Hellfire_Missile_Pack, 1, 4.57, 1, 1, 17, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Alan_Schezar].set("Hero Alan Schezar", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 300, 0, 0, 3, 200, 100, 1200, 0, 0, 2, 0, 0, 800, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 192, 256, WeaponTypes::Twin_Autocannons_Alan_Schezar, 1, WeaponTypes::Hellfire_Missile_Pack_Alan_Schezar, 1, 4.57, 1, 1, 17, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Siege_Tank_Tank_Mode].set("Terran Siege Tank Tank Mode", Races::Terran, 0, Terran_Factory, 1, Terran_Machine_Shop, None, TechTypes::None, TechTypes::Tank_Siege_Mode, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 150, 0, 0, 1, 150, 100, 750, 4, 0, 4, 0, 350, 700, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 256, 320, WeaponTypes::Arclite_Cannon, 1, WeaponTypes::None, 0, 4, 1, 1, 13, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Edmund_Duke_Tank_Mode].set("Hero Edmund Duke Tank Mode", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Tank_Siege_Mode, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 400, 0, 0, 3, 300, 200, 1500, 0, 0, 4, 0, 0, 1400, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 256, 320, WeaponTypes::Arclite_Cannon_Edmund_Duke, 1, WeaponTypes::None, 0, 4, 1, 1, 13, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_SCV].set("Terran SCV", Races::Terran, 0, Terran_Command_Center, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 60, 0, 0, 0, 50, 0, 300, 2, 0, 1, 0, 50, 100, UnitSizeTypes::Small, 1, 1, 11, 11, 11, 11, 32, 224, WeaponTypes::Fusion_Cutter, 1, WeaponTypes::None, 0, 4.92, 67, 12227, 40, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Wraith].set("Terran Wraith", Races::Terran, 0, Terran_Starport, 1, None, None, TechTypes::None, TechTypes::Cloaking_Field, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 120, 0, 200, 0, 150, 100, 900, 4, 0, 255, 0, 400, 800, UnitSizeTypes::Large, 1, 1, 19, 15, 18, 14, 160, 224, WeaponTypes::Burst_Lasers, 1, WeaponTypes::Gemini_Missiles, 1, 6.67, 67, 21745, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Tom_Kazansky].set("Hero Tom Kazansky", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Cloaking_Field, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 500, 0, 250, 4, 400, 200, 1800, 0, 0, 255, 0, 0, 1600, UnitSizeTypes::Large, 1, 1, 19, 15, 18, 14, 160, 224, WeaponTypes::Burst_Lasers_Tom_Kazansky, 1, WeaponTypes::Gemini_Missiles_Tom_Kazansky, 1, 6.67, 67, 21745, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Science_Vessel].set("Terran Science Vessel", Races::Terran, 0, Terran_Starport, 1, Terran_Control_Tower, Terran_Science_Facility, TechTypes::None, TechTypes::EMP_Shockwave, TechTypes::Defensive_Matrix, TechTypes::Irradiate, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 200, 0, 200, 1, 100, 225, 1200, 4, 0, 255, 0, 625, 1250, UnitSizeTypes::Large, 2, 2, 32, 33, 32, 16, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 5, 50, 5120, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Magellan].set("Hero Magellan", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::EMP_Shockwave, TechTypes::Defensive_Matrix, TechTypes::Irradiate, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 800, 0, 250, 4, 50, 600, 2400, 0, 0, 255, 0, 0, 2500, UnitSizeTypes::Large, 2, 2, 32, 33, 32, 16, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 5, 50, 5120, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Dropship].set("Terran Dropship", Races::Terran, 0, Terran_Starport, 1, Terran_Control_Tower, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 150, 0, 0, 1, 100, 100, 750, 4, 0, 255, 8, 300, 600, UnitSizeTypes::Large, 2, 2, 24, 16, 24, 20, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 5.47, 17, 37756, 20, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Battlecruiser].set("Terran Battlecruiser", Races::Terran, 0, Terran_Starport, 1, Terran_Control_Tower, Terran_Physics_Lab, TechTypes::None, TechTypes::Yamato_Gun, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 500, 0, 200, 3, 400, 300, 2000, 12, 0, 255, 0, 1200, 2400, UnitSizeTypes::Large, 2, 2, 37, 29, 37, 29, 192, 352, WeaponTypes::ATS_Laser_Battery, 1, WeaponTypes::ATA_Laser_Battery, 1, 2.5, 27, 7585, 20, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Arcturus_Mengsk].set("Hero Arcturus Mengsk", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 1000, 0, 250, 4, 800, 600, 4800, 0, 0, 255, 0, 0, 4800, UnitSizeTypes::Large, 2, 2, 37, 29, 37, 29, 192, 256, WeaponTypes::ATS_Laser_Battery_Hero, 1, WeaponTypes::ATA_Laser_Battery_Hero, 1, 2.5, 27, 7585, 20, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Hyperion].set("Hero Hyperion", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Yamato_Gun, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 850, 0, 250, 4, 800, 600, 2400, 0, 0, 255, 0, 0, 4800, UnitSizeTypes::Large, 2, 2, 37, 29, 37, 29, 192, 352, WeaponTypes::ATS_Laser_Battery_Hyperion, 1, WeaponTypes::ATA_Laser_Battery_Hyperion, 1, 2.5, 27, 7585, 20, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Norad_II].set("Hero Norad II", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Yamato_Gun, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 700, 0, 250, 4, 800, 600, 4800, 0, 0, 255, 0, 0, 4800, UnitSizeTypes::Large, 2, 2, 37, 29, 37, 29, 192, 352, WeaponTypes::ATS_Laser_Battery_Hero, 1, WeaponTypes::ATA_Laser_Battery_Hero, 1, 2.5, 27, 7585, 20, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Gerard_DuGalle].set("Hero Gerard DuGalle", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Yamato_Gun, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 700, 0, 250, 4, 800, 600, 4800, 0, 0, 255, 0, 0, 4800, UnitSizeTypes::Large, 2, 2, 37, 29, 37, 29, 192, 352, WeaponTypes::ATS_Laser_Battery_Hero, 1, WeaponTypes::ATA_Laser_Battery_Hero, 1, 2.5, 27, 7585, 20, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Vulture_Spider_Mine].set("Terran Vulture Spider Mine", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 20, 0, 0, 0, 1, 0, 1, 0, 0, 255, 0, 0, 25, UnitSizeTypes::Small, 1, 1, 7, 7, 7, 7, 96, 96, WeaponTypes::Spider_Mines, 1, WeaponTypes::None, 0, 16, 1, 1, 127, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Nuclear_Missile].set("Terran Nuclear Missile", Races::Terran, 0, Terran_Nuclear_Silo, 1, Terran_Command_Center, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100, 0, 0, 0, 200, 200, 1500, 16, 0, 255, 0, 800, 0, UnitSizeTypes::Independent, 1, 1, 7, 14, 7, 14, 0, 96, WeaponTypes::None, 0, WeaponTypes::None, 0, 33.33, 33, 1103213, 127, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Siege_Tank_Siege_Mode].set("Terran Siege Tank Siege Mode", Races::Terran, 0, Terran_Factory, 1, Terran_Machine_Shop, None, TechTypes::None, TechTypes::Tank_Siege_Mode, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 150, 0, 0, 1, 150, 100, 750, 4, 0, 255, 0, 0, 700, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 384, 320, WeaponTypes::Arclite_Shock_Cannon, 1, WeaponTypes::None, 0, 0, 1, 1, 40, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Edmund_Duke_Siege_Mode].set("Hero Edmund Duke Siege Mode", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Tank_Siege_Mode, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Vehicle_Plating, 400, 0, 0, 3, 300, 200, 1500, 0, 0, 255, 0, 0, 1400, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 384, 320, WeaponTypes::Arclite_Shock_Cannon_Edmund_Duke, 1, WeaponTypes::None, 0, 0, 1, 1, 40, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Firebat].set("Terran Firebat", Races::Terran, 0, Terran_Barracks, 1, Terran_Academy, None, TechTypes::None, TechTypes::Stim_Packs, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 50, 0, 0, 1, 50, 25, 360, 2, 0, 1, 0, 100, 200, UnitSizeTypes::Small, 1, 1, 11, 7, 11, 14, 96, 224, WeaponTypes::Flame_Thrower, 3, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Gui_Montag].set("Hero Gui Montag", Races::Terran, 1, None, 0, None, None, TechTypes::None, TechTypes::Stim_Packs, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 160, 0, 0, 3, 100, 50, 720, 0, 0, 1, 0, 0, 400, UnitSizeTypes::Small, 1, 1, 11, 7, 11, 14, 96, 224, WeaponTypes::Flame_Thrower_Gui_Montag, 3, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Spell_Scanner_Sweep].set("Spell Scanner Sweep", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 13, 13, 13, 17, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Medic].set("Terran Medic", Races::Terran, 0, Terran_Barracks, 1, Terran_Academy, None, TechTypes::None, TechTypes::Restoration, TechTypes::Optical_Flare, TechTypes::Healing, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 60, 0, 200, 1, 50, 25, 450, 2, 0, 1, 0, 125, 250, UnitSizeTypes::Small, 1, 1, 8, 9, 8, 10, 288, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Civilian].set("Terran Civilian", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Infantry_Armor, 40, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 8, 9, 8, 10, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Larva].set("Zerg Larva", Races::Zerg, 0, Zerg_Hatchery, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 25, 0, 0, 10, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 8, 8, 7, 7, 0, 128, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 1, 1, 20, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Egg].set("Zerg Egg", Races::Zerg, 0, Zerg_Larva, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 200, 0, 0, 10, 1, 1, 1, 0, 0, 255, 0, 0, 25, UnitSizeTypes::Medium, 1, 1, 16, 16, 15, 15, 0, 128, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Zergling].set("Zerg Zergling", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Spawning_Pool, None, TechTypes::None, TechTypes::Burrowing, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 35, 0, 0, 0, 50, 0, 420, 1, 0, 1, 0, 25, 50, UnitSizeTypes::Small, 1, 1, 8, 4, 7, 11, 96, 160, WeaponTypes::Claws, 1, WeaponTypes::None, 0, 5.49, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Devouring_One].set("Hero Devouring One", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::Burrowing, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 120, 0, 0, 3, 100, 0, 840, 0, 0, 1, 0, 0, 100, UnitSizeTypes::Small, 1, 1, 8, 4, 7, 11, 96, 160, WeaponTypes::Claws_Devouring_One, 1, WeaponTypes::None, 0, 5.49, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Infested_Kerrigan].set("Hero Infested Kerrigan", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::Personnel_Cloaking, TechTypes::Ensnare, TechTypes::Psionic_Storm, TechTypes::Consume, UpgradeTypes::Zerg_Carapace, 400, 0, 250, 2, 200, 300, 1500, 0, 0, 1, 0, 0, 4000, UnitSizeTypes::Small, 1, 1, 7, 10, 7, 11, 96, 288, WeaponTypes::Claws_Infested_Kerrigan, 1, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Hydralisk].set("Zerg Hydralisk", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Hydralisk_Den, None, TechTypes::None, TechTypes::Burrowing, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 80, 0, 0, 0, 75, 25, 420, 2, 0, 2, 0, 125, 350, UnitSizeTypes::Medium, 1, 1, 10, 10, 10, 12, 128, 192, WeaponTypes::Needle_Spines, 1, WeaponTypes::Needle_Spines, 1, 3.66, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Hunter_Killer].set("Hero Hunter Killer", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::Burrowing, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 160, 0, 0, 2, 150, 50, 780, 0, 0, 2, 0, 0, 500, UnitSizeTypes::Medium, 1, 1, 10, 10, 10, 12, 128, 256, WeaponTypes::Needle_Spines_Hunter_Killer, 1, WeaponTypes::Needle_Spines_Hunter_Killer, 1, 3.66, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Ultralisk].set("Zerg Ultralisk", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Ultralisk_Cavern, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 400, 0, 0, 1, 200, 200, 900, 8, 0, 4, 0, 650, 1300, UnitSizeTypes::Large, 2, 2, 19, 16, 18, 15, 96, 224, WeaponTypes::Kaiser_Blades, 1, WeaponTypes::None, 0, 5.12, 1, 1, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Torrasque].set("Hero Torrasque", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 800, 0, 0, 4, 400, 400, 1800, 0, 0, 4, 0, 0, 2600, UnitSizeTypes::Large, 2, 2, 19, 16, 18, 15, 96, 224, WeaponTypes::Kaiser_Blades_Torrasque, 1, WeaponTypes::None, 0, 5.12, 1, 1, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Broodling].set("Zerg Broodling", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 30, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 25, UnitSizeTypes::Small, 1, 1, 9, 9, 9, 9, 96, 160, WeaponTypes::Toxic_Spores, 1, WeaponTypes::None, 0, 6, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Drone].set("Zerg Drone", Races::Zerg, 0, Zerg_Larva, 1, None, None, TechTypes::None, TechTypes::Burrowing, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 40, 0, 0, 0, 50, 0, 300, 2, 0, 1, 0, 50, 100, UnitSizeTypes::Small, 1, 1, 11, 11, 11, 11, 32, 224, WeaponTypes::Spines, 1, WeaponTypes::None, 0, 4.92, 67, 12227, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Overlord].set("Zerg Overlord", Races::Zerg, 0, Zerg_Larva, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 200, 0, 0, 0, 100, 0, 600, 0, 16, 255, 8, 100, 200, UnitSizeTypes::Large, 2, 2, 25, 25, 24, 24, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 0.83, 27, 840, 20, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Yggdrasill].set("Hero Yggdrasill", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 1000, 0, 0, 4, 200, 0, 1200, 0, 60, 255, 8, 0, 400, UnitSizeTypes::Large, 2, 2, 25, 25, 24, 24, 0, 352, WeaponTypes::None, 0, WeaponTypes::None, 0, 0.83, 27, 840, 20, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Mutalisk].set("Zerg Mutalisk", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Spire, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 120, 0, 0, 0, 100, 100, 600, 4, 0, 255, 0, 300, 600, UnitSizeTypes::Small, 2, 2, 22, 22, 21, 21, 96, 224, WeaponTypes::Glave_Wurm, 1, WeaponTypes::Glave_Wurm, 1, 6.67, 67, 21745, 40, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Kukulza_Mutalisk].set("Hero Kukulza Mutalisk", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 300, 0, 0, 3, 200, 200, 1200, 0, 0, 255, 0, 0, 1200, UnitSizeTypes::Small, 2, 2, 22, 22, 21, 21, 96, 224, WeaponTypes::Glave_Wurm_Kukulza, 1, WeaponTypes::Glave_Wurm_Kukulza, 1, 6.67, 67, 21745, 40, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Guardian].set("Zerg Guardian", Races::Zerg, 0, Zerg_Mutalisk, 1, Zerg_Greater_Spire, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 150, 0, 0, 2, 50, 100, 600, 4, 0, 255, 0, 550, 1100, UnitSizeTypes::Large, 2, 2, 22, 22, 21, 21, 256, 352, WeaponTypes::Acid_Spore, 1, WeaponTypes::None, 0, 2.5, 27, 7585, 20, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Kukulza_Guardian].set("Hero Kukulza Guardian", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 400, 0, 0, 4, 100, 200, 1200, 0, 0, 255, 0, 0, 2200, UnitSizeTypes::Large, 2, 2, 22, 22, 21, 21, 256, 352, WeaponTypes::Acid_Spore_Kukulza, 1, WeaponTypes::None, 0, 2.5, 27, 7585, 20, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Queen].set("Zerg Queen", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Queens_Nest, None, TechTypes::None, TechTypes::Infestation, TechTypes::Spawn_Broodlings, TechTypes::Ensnare, TechTypes::Parasite, UpgradeTypes::Zerg_Flyer_Carapace, 120, 0, 200, 0, 100, 100, 750, 4, 0, 255, 0, 400, 800, UnitSizeTypes::Medium, 2, 2, 24, 24, 23, 23, 256, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 6.67, 67, 21745, 40, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Matriarch].set("Hero Matriarch", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::Infestation, TechTypes::Spawn_Broodlings, TechTypes::Ensnare, TechTypes::Parasite, UpgradeTypes::Zerg_Flyer_Carapace, 300, 0, 250, 3, 200, 300, 1500, 0, 0, 255, 0, 0, 1600, UnitSizeTypes::Medium, 2, 2, 24, 24, 23, 23, 256, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 6.67, 67, 21745, 40, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Defiler].set("Zerg Defiler", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Defiler_Mound, None, TechTypes::None, TechTypes::Burrowing, TechTypes::Dark_Swarm, TechTypes::Plague, TechTypes::Consume, UpgradeTypes::Zerg_Carapace, 80, 0, 200, 1, 50, 150, 750, 4, 0, 2, 0, 225, 450, UnitSizeTypes::Medium, 1, 1, 13, 12, 13, 12, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Unclean_One].set("Hero Unclean One", Races::Zerg, 1, None, 0, None, None, TechTypes::None, TechTypes::Burrowing, TechTypes::Dark_Swarm, TechTypes::Plague, TechTypes::Consume, UpgradeTypes::Zerg_Carapace, 250, 0, 250, 3, 50, 200, 1500, 0, 0, 2, 0, 0, 900, UnitSizeTypes::Medium, 1, 1, 13, 12, 13, 12, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Scourge].set("Zerg Scourge", Races::Zerg, 0, Zerg_Larva, 1, Zerg_Spire, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 25, 0, 0, 0, 25, 75, 450, 1, 0, 255, 0, 100, 200, UnitSizeTypes::Small, 1, 1, 12, 12, 11, 11, 96, 160, WeaponTypes::None, 0, WeaponTypes::Suicide_Scourge, 1, 6.67, 107, 13616, 40, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Infested_Terran].set("Zerg Infested Terran", Races::Zerg, 0, Zerg_Infested_Command_Center, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 60, 0, 0, 0, 100, 50, 600, 2, 0, 1, 0, 200, 400, UnitSizeTypes::Small, 1, 1, 8, 9, 8, 10, 96, 160, WeaponTypes::Suicide_Infested_Terran, 1, WeaponTypes::None, 0, 5.82, 1, 1, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Terran_Valkyrie].set("Terran Valkyrie", Races::Terran, 0, Terran_Starport, 1, Terran_Control_Tower, Terran_Armory, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Terran_Ship_Plating, 200, 0, 0, 2, 250, 125, 750, 6, 0, 255, 0, 400, 800, UnitSizeTypes::Large, 2, 2, 24, 16, 24, 20, 192, 256, WeaponTypes::None, 0, WeaponTypes::Halo_Rockets, 4, 6.6, 65, 21901, 30, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Cocoon].set("Zerg Cocoon", Races::Zerg, 0, Zerg_Mutalisk, 1, Zerg_Greater_Spire, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 200, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 1100, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 0, 128, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Corsair].set("Protoss Corsair", Races::Protoss, 0, Protoss_Stargate, 1, None, None, TechTypes::None, TechTypes::Disruption_Web, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 100, 80, 200, 1, 150, 100, 600, 4, 0, 255, 0, 350, 700, UnitSizeTypes::Medium, 1, 1, 18, 16, 17, 15, 288, 288, WeaponTypes::None, 0, WeaponTypes::Neutron_Flare, 1, 6.67, 67, 17067, 30, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Raszagal].set("Hero Raszagal", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::Disruption_Web, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 100, 60, 250, 0, 150, 100, 750, 0, 0, 255, 0, 0, 1300, UnitSizeTypes::Medium, 1, 1, 18, 16, 17, 15, 288, 288, WeaponTypes::None, 0, WeaponTypes::Neutron_Flare, 1, 6.67, 67, 17067, 30, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Dark_Templar].set("Protoss Dark Templar", Races::Protoss, 0, Protoss_Gateway, 1, Protoss_Templar_Archives, None, TechTypes::None, TechTypes::Dark_Archon_Meld, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 80, 40, 0, 1, 125, 100, 750, 4, 0, 2, 0, 325, 650, UnitSizeTypes::Small, 1, 1, 12, 6, 11, 19, 96, 224, WeaponTypes::Warp_Blades, 1, WeaponTypes::None, 0, 4.92, 27, 13474, 40, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Dark_Templar].set("Hero Dark Templar", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 40, 80, 0, 0, 150, 150, 750, 1, 0, 2, 0, 0, 400, UnitSizeTypes::Small, 1, 1, 12, 6, 11, 19, 96, 224, WeaponTypes::Warp_Blades_Hero, 1, WeaponTypes::None, 0, 4.92, 27, 13474, 40, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Zeratul].set("Hero Zeratul", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 60, 400, 0, 0, 100, 300, 1500, 0, 0, 2, 0, 0, 800, UnitSizeTypes::Small, 1, 1, 12, 6, 11, 19, 96, 224, WeaponTypes::Warp_Blades_Zeratul, 1, WeaponTypes::None, 0, 4.92, 27, 13474, 40, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Devourer].set("Zerg Devourer", Races::Zerg, 0, Zerg_Mutalisk, 1, Zerg_Greater_Spire, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Flyer_Carapace, 250, 0, 0, 2, 150, 50, 600, 4, 0, 255, 0, 550, 1100, UnitSizeTypes::Large, 2, 2, 22, 22, 21, 21, 224, 320, WeaponTypes::None, 0, WeaponTypes::Corrosive_Acid, 1, 5, 48, 17067, 30, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Dark_Archon].set("Protoss Dark Archon", Races::Protoss, 0, Protoss_Dark_Templar, 2, None, None, TechTypes::None, TechTypes::Mind_Control, TechTypes::Feedback, TechTypes::Maelstrom, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 25, 200, 200, 1, 0, 0, 300, 8, 0, 4, 0, 650, 1300, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 224, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 4.92, 160, 5120, 40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Probe].set("Protoss Probe", Races::Protoss, 0, Protoss_Nexus, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 20, 20, 0, 0, 50, 0, 300, 2, 0, 1, 0, 50, 100, UnitSizeTypes::Small, 1, 1, 11, 11, 11, 11, 32, 256, WeaponTypes::Particle_Beam, 1, WeaponTypes::None, 0, 4.92, 67, 12227, 40, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Zealot].set("Protoss Zealot", Races::Protoss, 0, Protoss_Gateway, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 100, 60, 0, 1, 100, 0, 600, 4, 0, 2, 0, 100, 200, UnitSizeTypes::Small, 1, 1, 11, 5, 11, 13, 96, 224, WeaponTypes::Psi_Blades, 2, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Fenix_Zealot].set("Hero Fenix Zealot", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 240, 240, 0, 2, 200, 0, 1200, 0, 0, 2, 0, 0, 400, UnitSizeTypes::Small, 1, 1, 11, 5, 11, 13, 96, 224, WeaponTypes::Psi_Blades_Fenix, 2, WeaponTypes::None, 0, 4, 1, 1, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Dragoon].set("Protoss Dragoon", Races::Protoss, 0, Protoss_Gateway, 1, Protoss_Cybernetics_Core, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 100, 80, 0, 1, 125, 50, 750, 4, 0, 4, 0, 250, 500, UnitSizeTypes::Large, 1, 1, 15, 15, 16, 16, 128, 256, WeaponTypes::Phase_Disruptor, 1, WeaponTypes::Phase_Disruptor, 1, 5, 1, 1, 40, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Fenix_Dragoon].set("Hero Fenix Dragoon", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 240, 240, 0, 3, 300, 100, 1500, 0, 0, 4, 0, 0, 1000, UnitSizeTypes::Large, 1, 1, 15, 15, 16, 16, 128, 256, WeaponTypes::Phase_Disruptor_Fenix, 1, WeaponTypes::Phase_Disruptor_Fenix, 1, 5, 1, 1, 40, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_High_Templar].set("Protoss High Templar", Races::Protoss, 0, Protoss_Gateway, 1, Protoss_Templar_Archives, None, TechTypes::None, TechTypes::Psionic_Storm, TechTypes::Hallucination, TechTypes::Archon_Warp, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 40, 40, 200, 0, 50, 150, 750, 4, 0, 2, 0, 350, 700, UnitSizeTypes::Small, 1, 1, 12, 10, 11, 13, 96, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 3.2, 27, 13474, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Tassadar].set("Hero Tassadar", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::Psionic_Storm, TechTypes::Hallucination, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 80, 300, 250, 2, 100, 300, 1500, 0, 0, 2, 0, 0, 1400, UnitSizeTypes::Small, 1, 1, 12, 10, 11, 13, 96, 224, WeaponTypes::Psi_Assault, 1, WeaponTypes::None, 0, 3.2, 27, 13474, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Aldaris].set("Hero Aldaris", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 80, 300, 250, 2, 100, 300, 1500, 0, 0, 2, 0, 0, 1400, UnitSizeTypes::Small, 1, 1, 12, 10, 11, 13, 96, 224, WeaponTypes::Psi_Assault, 1, WeaponTypes::None, 0, 3.2, 27, 13474, 40, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Archon].set("Protoss Archon", Races::Protoss, 0, Protoss_High_Templar, 2, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 10, 350, 0, 0, 0, 0, 300, 8, 0, 4, 0, 700, 1400, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 96, 256, WeaponTypes::Psionic_Shockwave, 1, WeaponTypes::Psionic_Shockwave, 1, 4.92, 160, 5120, 40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Tassadar_Zeratul_Archon].set("Hero Tassadar Zeratul Archon", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 100, 800, 0, 3, 0, 0, 600, 0, 0, 4, 0, 0, 2800, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 96, 256, WeaponTypes::Psionic_Shockwave_TZ_Archon, 1, WeaponTypes::Psionic_Shockwave_TZ_Archon, 1, 4.92, 160, 5120, 40, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Shuttle].set("Protoss Shuttle", Races::Protoss, 0, Protoss_Robotics_Facility, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 80, 60, 0, 1, 200, 0, 900, 4, 0, 255, 8, 200, 400, UnitSizeTypes::Large, 2, 1, 20, 16, 19, 15, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 4.43, 17, 37756, 20, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Scout].set("Protoss Scout", Races::Protoss, 0, Protoss_Stargate, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 150, 100, 0, 0, 275, 125, 1200, 6, 0, 255, 0, 650, 1300, UnitSizeTypes::Large, 2, 1, 18, 16, 17, 15, 128, 256, WeaponTypes::Dual_Photon_Blasters, 1, WeaponTypes::Anti_Matter_Missiles, 1, 5, 48, 17067, 30, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Mojo].set("Hero Mojo", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 400, 400, 0, 3, 600, 300, 2400, 0, 0, 255, 0, 0, 2600, UnitSizeTypes::Large, 2, 1, 18, 16, 17, 15, 128, 320, WeaponTypes::Dual_Photon_Blasters_Mojo, 1, WeaponTypes::Anti_Matter_Missiles_Mojo, 1, 5, 48, 17067, 30, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Artanis].set("Hero Artanis", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 250, 250, 0, 3, 600, 300, 2400, 0, 0, 255, 0, 0, 2400, UnitSizeTypes::Large, 2, 1, 18, 16, 17, 15, 128, 320, WeaponTypes::Dual_Photon_Blasters_Artanis, 1, WeaponTypes::Anti_Matter_Missiles_Artanis, 1, 5, 48, 17067, 30, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Arbiter].set("Protoss Arbiter", Races::Protoss, 0, Protoss_Stargate, 1, Protoss_Arbiter_Tribunal, None, TechTypes::None, TechTypes::Recall, TechTypes::Stasis_Field, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 200, 150, 200, 1, 100, 350, 2400, 8, 0, 255, 0, 1025, 2050, UnitSizeTypes::Large, 2, 2, 22, 22, 21, 21, 160, 288, WeaponTypes::Phase_Disruptor_Cannon, 1, WeaponTypes::Phase_Disruptor_Cannon, 1, 5, 33, 24824, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Danimoth].set("Hero Danimoth", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::Recall, TechTypes::Stasis_Field, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 600, 500, 250, 3, 50, 1000, 4800, 0, 0, 255, 0, 0, 4100, UnitSizeTypes::Large, 2, 2, 22, 22, 21, 21, 160, 288, WeaponTypes::Phase_Disruptor_Cannon_Danimoth, 1, WeaponTypes::Phase_Disruptor_Cannon_Danimoth, 1, 5, 33, 24824, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Carrier].set("Protoss Carrier", Races::Protoss, 0, Protoss_Stargate, 1, Protoss_Fleet_Beacon, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 300, 150, 0, 4, 350, 250, 2100, 12, 0, 255, 0, 950, 1900, UnitSizeTypes::Large, 2, 2, 32, 32, 31, 31, 256, 352, WeaponTypes::None, 0, WeaponTypes::None, 0, 3.33, 27, 13474, 20, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Gantrithor].set("Hero Gantrithor", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 800, 500, 0, 4, 700, 600, 4200, 0, 0, 255, 0, 0, 3800, UnitSizeTypes::Large, 2, 2, 32, 32, 31, 31, 256, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 3.33, 27, 13474, 20, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Interceptor].set("Protoss Interceptor", Races::Protoss, 0, Protoss_Carrier, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 40, 40, 0, 0, 25, 0, 300, 0, 0, 255, 0, 30, 60, UnitSizeTypes::Small, 1, 1, 8, 8, 7, 7, 128, 192, WeaponTypes::Pulse_Cannon, 1, WeaponTypes::Pulse_Cannon, 1, 13.33, 427, 13640, 40, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Reaver].set("Protoss Reaver", Races::Protoss, 0, Protoss_Robotics_Facility, 1, Protoss_Robotics_Support_Bay, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 100, 80, 0, 0, 200, 100, 1050, 8, 0, 4, 0, 400, 800, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 256, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 1.78, 1, 1, 20, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Hero_Warbringer].set("Hero Warbringer", Races::Protoss, 1, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 200, 400, 0, 3, 400, 200, 1800, 0, 0, 4, 0, 0, 1600, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 256, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 1.78, 1, 1, 20, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Observer].set("Protoss Observer", Races::Protoss, 0, Protoss_Robotics_Facility, 1, Protoss_Observatory, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Air_Armor, 40, 20, 0, 0, 25, 75, 600, 2, 0, 255, 0, 225, 450, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 3.33, 27, 13474, 20, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Protoss_Scarab].set("Protoss Scarab", Races::Protoss, 0, Protoss_Reaver, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Protoss_Ground_Armor, 20, 10, 0, 0, 15, 0, 105, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Small, 1, 1, 2, 2, 2, 2, 128, 160, WeaponTypes::Scarab, 1, WeaponTypes::None, 0, 16, 1, 1, 27, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Critter_Rhynadon].set("Critter Rhynadon", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 60, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Critter_Bengalaas].set("Critter Bengalaas", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 60, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Special_Cargo_Ship].set("Special Cargo Ship", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,125,0,0,1,100,100,600,0,0,255,0,0,0, UnitSizeTypes::Medium,1,1,15,15,16,16,256,256, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Special_Mercenary_Gunship].set("Special Mercenary Gunship", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,125,0,0,1,100,100,600,0,0,255,0,0,0, UnitSizeTypes::Medium,1,1,15,15,16,16,128,224, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Critter_Scantid].set("Critter Scantid", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 60, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Critter_Kakaru].set("Critter Kakaru", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 60, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 5, 16, 51200, 14, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Critter_Ragnasaur].set("Critter Ragnasaur", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 60, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Critter_Ursadon].set("Critter Ursadon", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 60, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Small, 1, 1, 16, 16, 15, 15, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 4, 1, 1, 27, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Zerg_Lurker_Egg].set("Zerg Lurker Egg", Races::Zerg, 0, Zerg_Hydralisk, 1, None, None, TechTypes::Lurker_Aspect, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 200, 0, 0, 10, 1, 1, 1, 0, 0, 255, 0, 0, 500, UnitSizeTypes::Medium, 1, 1, 16, 16, 15, 15, 0, 128, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Zerg_Lurker].set("Zerg Lurker", Races::Zerg, 0, Zerg_Hydralisk, 1, None, None, TechTypes::Lurker_Aspect, TechTypes::Lurker_Aspect, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::Zerg_Carapace, 125, 0, 0, 1, 50, 100, 600, 4, 0, 4, 0, 250, 500, UnitSizeTypes::Medium, 1, 1, 15, 15, 16, 16, 192, 256, WeaponTypes::Subterranean_Spines, 1, WeaponTypes::None, 0, 5.82, 1, 1, 40, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0);
      unitTypeData[Spell_Disruption_Web].set("Spell Disruption Web", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 250, 250, 2400, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 4, 3, 60, 40, 59, 39, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Terran_Command_Center].set("Terran Command Center", Races::Terran, 0, Terran_SCV, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1500, 0, 0, 1, 400, 0, 1800, 0, 20, 255, 0, 400, 1200, UnitSizeTypes::Large, 4, 3, 58, 41, 58, 41, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Terran_Comsat_Station].set("Terran Comsat Station", Races::Terran, 0, Terran_Command_Center, 1, Terran_Academy, None, TechTypes::None, TechTypes::Scanner_Sweep, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 0, 200, 1, 50, 50, 600, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 2, 2, 37, 16, 31, 25, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
      unitTypeData[Terran_Nuclear_Silo].set("Terran Nuclear Silo", Races::Terran, 0, Terran_Command_Center, 1, Terran_Science_Facility, Terran_Covert_Ops, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 600, 0, 0, 1, 100, 100, 1200, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 2, 2, 37, 16, 31, 25, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
      unitTypeData[Terran_Supply_Depot].set("Terran Supply Depot", Races::Terran, 0, Terran_SCV, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 0, 0, 1, 100, 0, 600, 0, 16, 255, 0, 50, 150, UnitSizeTypes::Large, 3, 2, 38, 22, 38, 26, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Terran_Refinery].set("Terran Refinery", Races::Terran, 0, Terran_SCV, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 100, 0, 600, 0, 0, 255, 0, 50, 150, UnitSizeTypes::Large, 4, 2, 56, 32, 56, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 33, 2763, 27, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);
      unitTypeData[Terran_Barracks].set("Terran Barracks", Races::Terran, 0, Terran_SCV, 1, Terran_Command_Center, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1000, 0, 0, 1, 150, 0, 1200, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 4, 3, 48, 40, 56, 32, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Terran_Academy].set("Terran Academy", Races::Terran, 0, Terran_SCV, 1, Terran_Barracks, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 600, 0, 0, 1, 150, 0, 1200, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 3, 2, 40, 32, 44, 24, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Terran_Factory].set("Terran Factory", Races::Terran, 0, Terran_SCV, 1, Terran_Barracks, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1250, 0, 0, 1, 200, 100, 1200, 0, 0, 255, 0, 200, 600, UnitSizeTypes::Large, 4, 3, 56, 40, 56, 40, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Terran_Starport].set("Terran Starport", Races::Terran, 0, Terran_SCV, 1, Terran_Factory, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1300, 0, 0, 1, 150, 100, 1050, 0, 0, 255, 0, 200, 600, UnitSizeTypes::Large, 4, 3, 48, 40, 48, 38, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Terran_Control_Tower].set("Terran Control Tower", Races::Terran, 0, Terran_Starport, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 0, 0, 1, 50, 50, 600, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 2, 2, 47, 24, 28, 22, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
      unitTypeData[Terran_Science_Facility].set("Terran Science Facility", Races::Terran, 0, Terran_SCV, 1, Terran_Starport, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 850, 0, 0, 1, 100, 150, 900, 0, 0, 255, 0, 275, 825, UnitSizeTypes::Large, 4, 3, 48, 38, 48, 38, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Terran_Covert_Ops].set("Terran Covert Ops", Races::Terran, 0, Terran_Science_Facility, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 50, 50, 600, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 2, 2, 47, 24, 28, 22, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
      unitTypeData[Terran_Physics_Lab].set("Terran Physics Lab", Races::Terran, 0, Terran_Science_Facility, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 600, 0, 0, 1, 50, 50, 600, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 2, 2, 47, 24, 28, 22, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
      unitTypeData[Terran_Machine_Shop].set("Terran Machine Shop", Races::Terran, 0, Terran_Factory, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 50, 50, 600, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 2, 2, 39, 24, 31, 24, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0);
      unitTypeData[Terran_Engineering_Bay].set("Terran Engineering Bay", Races::Terran, 0, Terran_SCV, 1, Terran_Command_Center, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 850, 0, 0, 1, 125, 0, 900, 0, 0, 255, 0, 65, 195, UnitSizeTypes::Large, 4, 3, 48, 32, 48, 28, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Terran_Armory].set("Terran Armory", Races::Terran, 0, Terran_SCV, 1, Terran_Factory, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 100, 50, 1200, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 3, 2, 48, 32, 47, 22, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Terran_Missile_Turret].set("Terran Missile Turret", Races::Terran, 0, Terran_SCV, 1, Terran_Engineering_Bay, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 200, 0, 0, 0, 75, 0, 450, 0, 0, 255, 0, 50, 150, UnitSizeTypes::Large, 2, 2, 16, 32, 16, 16, 224, 352, WeaponTypes::None, 0, WeaponTypes::Longbolt_Missile, 1, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Terran_Bunker].set("Terran Bunker", Races::Terran, 0, Terran_SCV, 1, Terran_Barracks, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 350, 0, 0, 1, 100, 0, 450, 0, 0, 255, 4, 50, 150, UnitSizeTypes::Large, 3, 2, 32, 24, 32, 16, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 33, 2763, 27, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Crashed_Norad_II].set("Special Crashed Norad II", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 700, 0, 0, 1, 800, 600, 4800, 0, 0, 255, 0, 0, 5000, UnitSizeTypes::Large, 3, 2, 48, 32, 47, 31, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Ion_Cannon].set("Special Ion Cannon", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 2000, 0, 0, 1, 200, 0, 900, 0, 0, 255, 0, 0, 5000, UnitSizeTypes::Large, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Infested_Command_Center].set("Zerg Infested Command Center", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1500, 0, 0, 1, 1, 1, 1800, 0, 0, 255, 0, 300, 900, UnitSizeTypes::Large, 4, 3, 58, 41, 58, 41, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 1, 33, 2763, 27, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0);
      unitTypeData[Zerg_Hatchery].set("Zerg Hatchery", Races::Zerg, 0, Zerg_Drone, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1250, 0, 0, 1, 300, 0, 1800, 0, 2, 255, 0, 300, 900, UnitSizeTypes::Large, 4, 3, 49, 32, 49, 32, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Lair].set("Zerg Lair", Races::Zerg, 0, Zerg_Hatchery, 1, Zerg_Spawning_Pool, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1800, 0, 0, 1, 150, 100, 1500, 0, 2, 255, 0, 100, 1200, UnitSizeTypes::Large, 4, 3, 49, 32, 49, 32, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Hive].set("Zerg Hive", Races::Zerg, 0, Zerg_Lair, 1, Zerg_Queens_Nest, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 2500, 0, 0, 1, 200, 150, 1800, 0, 2, 255, 0, 100, 1500, UnitSizeTypes::Large, 4, 3, 49, 32, 49, 32, 0, 352, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Nydus_Canal].set("Zerg Nydus Canal", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Hive, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 250, 0, 0, 1, 150, 0, 600, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 2, 2, 32, 32, 31, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Hydralisk_Den].set("Zerg Hydralisk Den", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Spawning_Pool, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 850, 0, 0, 1, 100, 50, 600, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 3, 2, 40, 32, 40, 24, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Defiler_Mound].set("Zerg Defiler Mound", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Hive, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 850, 0, 0, 1, 100, 100, 900, 0, 0, 255, 0, 150, 450, UnitSizeTypes::Large, 4, 2, 48, 32, 48, 4, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Greater_Spire].set("Zerg Greater Spire", Races::Zerg, 0, Zerg_Spire, 1, Zerg_Spire, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1000, 0, 0, 1, 100, 150, 1800, 0, 0, 255, 0, 200, 1350, UnitSizeTypes::Large, 2, 2, 28, 32, 28, 24, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Queens_Nest].set("Zerg Queens Nest", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Lair, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 850, 0, 0, 1, 150, 100, 900, 0, 0, 255, 0, 175, 525, UnitSizeTypes::Large, 3, 2, 38, 28, 32, 28, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Evolution_Chamber].set("Zerg Evolution Chamber", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Hatchery, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 75, 0, 600, 0, 0, 255, 0, 40, 120, UnitSizeTypes::Large, 3, 2, 44, 32, 32, 20, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Ultralisk_Cavern].set("Zerg Ultralisk Cavern", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Hive, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 600, 0, 0, 1, 150, 200, 1200, 0, 0, 255, 0, 275, 825, UnitSizeTypes::Large, 3, 2, 40, 32, 32, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Spire].set("Zerg Spire", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Lair, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 600, 0, 0, 1, 200, 150, 1800, 0, 0, 255, 0, 250, 750, UnitSizeTypes::Large, 2, 2, 28, 32, 28, 24, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Spawning_Pool].set("Zerg Spawning Pool", Races::Zerg, 0, Zerg_Drone, 1, Zerg_Hatchery, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 200, 0, 1200, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 3, 2, 36, 28, 40, 18, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Creep_Colony].set("Zerg Creep Colony", Races::Zerg, 0, Zerg_Drone, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 400, 0, 0, 0, 75, 0, 300, 0, 0, 255, 0, 40, 120, UnitSizeTypes::Large, 2, 2, 24, 24, 23, 23, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Spore_Colony].set("Zerg Spore Colony", Races::Zerg, 0, Zerg_Creep_Colony, 1, Zerg_Creep_Colony, Zerg_Evolution_Chamber, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 400, 0, 0, 0, 50, 0, 300, 0, 0, 255, 0, 25, 195, UnitSizeTypes::Large, 2, 2, 24, 24, 23, 23, 224, 320, WeaponTypes::None, 0, WeaponTypes::Seeker_Spores, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Sunken_Colony].set("Zerg Sunken Colony", Races::Zerg, 0, Zerg_Creep_Colony, 1, Zerg_Creep_Colony, Zerg_Spawning_Pool, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 300, 0, 0, 2, 50, 0, 300, 0, 0, 255, 0, 40, 240, UnitSizeTypes::Large, 2, 2, 24, 24, 23, 23, 224, 320, WeaponTypes::Subterranean_Tentacle, 1, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Overmind_With_Shell].set("Special Overmind With Shell", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 5000, 0, 0, 1, 1, 1, 1, 0, 0, 255, 0, 0, 10000, UnitSizeTypes::Large, 5, 3, 80, 32, 79, 40, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Overmind].set("Special Overmind", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 2500, 0, 0, 1, 1, 1, 1, 0, 0, 255, 0, 0, 10000, UnitSizeTypes::Large, 5, 3, 80, 32, 79, 40, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Zerg_Extractor].set("Zerg Extractor", Races::Zerg, 0, Zerg_Drone, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 0, 0, 1, 50, 0, 600, 0, 0, 255, 0, 25, 75, UnitSizeTypes::Large, 4, 2, 64, 32, 63, 31, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);
      unitTypeData[Special_Mature_Chrysalis].set("Special Mature Chrysalis", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 250, 0, 0, 1, 0, 0, 0, 0, 0, 255, 0, 0, 5000, UnitSizeTypes::Large, 2, 2, 32, 32, 31, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Cerebrate].set("Special Cerebrate", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1500, 0, 0, 1, 0, 0, 0, 0, 0, 255, 0, 0, 2500, UnitSizeTypes::Large, 3, 2, 40, 32, 32, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Cerebrate_Daggoth].set("Special Cerebrate Daggoth", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1500, 0, 0, 1, 0, 0, 0, 0, 0, 255, 0, 0, 2500, UnitSizeTypes::Large, 3, 2, 40, 32, 32, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Nexus].set("Protoss Nexus", Races::Protoss, 0, Protoss_Probe, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 750, 750, 0, 1, 400, 0, 1800, 0, 18, 255, 0, 400, 1200, UnitSizeTypes::Large, 4, 3, 56, 39, 56, 39, 0, 352, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Robotics_Facility].set("Protoss Robotics Facility", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Cybernetics_Core, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 500, 0, 1, 200, 200, 1200, 0, 0, 255, 0, 300, 900, UnitSizeTypes::Large, 3, 2, 36, 16, 40, 20, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Pylon].set("Protoss Pylon", Races::Protoss, 0, Protoss_Probe, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 300, 300, 0, 0, 100, 0, 450, 0, 16, 255, 0, 50, 150, UnitSizeTypes::Large, 2, 2, 16, 12, 16, 20, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Assimilator].set("Protoss Assimilator", Races::Protoss, 0, Protoss_Probe, 1, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 450, 450, 0, 1, 100, 0, 600, 0, 0, 255, 0, 50, 150, UnitSizeTypes::Large, 4, 2, 48, 32, 48, 24, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1);
      unitTypeData[Protoss_Observatory].set("Protoss Observatory", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Robotics_Facility, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 250, 250, 0, 1, 50, 100, 450, 0, 0, 255, 0, 175, 525, UnitSizeTypes::Large, 3, 2, 44, 16, 44, 28, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Gateway].set("Protoss Gateway", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Nexus, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 500, 0, 1, 150, 0, 900, 0, 0, 255, 0, 75, 225, UnitSizeTypes::Large, 4, 3, 48, 32, 48, 40, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Photon_Cannon].set("Protoss Photon Cannon", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Forge, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100, 100, 0, 0, 150, 0, 750, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 2, 2, 20, 16, 20, 16, 224, 352, WeaponTypes::STS_Photon_Cannon, 1, WeaponTypes::STA_Photon_Cannon, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Citadel_of_Adun].set("Protoss Citadel of Adun", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Cybernetics_Core, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 450, 450, 0, 1, 150, 100, 900, 0, 0, 255, 0, 200, 600, UnitSizeTypes::Large, 3, 2, 24, 24, 40, 24, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Cybernetics_Core].set("Protoss Cybernetics Core", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Gateway, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 500, 0, 1, 200, 0, 900, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 3, 2, 40, 24, 40, 24, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Templar_Archives].set("Protoss Templar Archives", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Citadel_of_Adun, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 500, 0, 1, 150, 200, 900, 0, 0, 255, 0, 250, 750, UnitSizeTypes::Large, 3, 2, 32, 24, 32, 24, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Forge].set("Protoss Forge", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Nexus, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 550, 550, 0, 1, 150, 0, 600, 0, 0, 255, 0, 100, 300, UnitSizeTypes::Large, 3, 2, 36, 24, 36, 20, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Stargate].set("Protoss Stargate", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Cybernetics_Core, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 600, 600, 0, 1, 150, 150, 1050, 0, 0, 255, 0, 300, 900, UnitSizeTypes::Large, 4, 3, 48, 40, 48, 32, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Stasis_Cell_Prison].set("Special Stasis Cell Prison", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 2000, 0, 0, 1, 150, 0, 1, 0, 0, 255, 0, 0, 5000, UnitSizeTypes::Large, 4, 3, 64, 48, 63, 47, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Fleet_Beacon].set("Protoss Fleet Beacon", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Stargate, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 500, 0, 1, 300, 200, 900, 0, 0, 255, 0, 350, 1050, UnitSizeTypes::Large, 3, 2, 40, 32, 47, 24, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Arbiter_Tribunal].set("Protoss Arbiter Tribunal", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Templar_Archives, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 500, 500, 0, 1, 200, 150, 900, 0, 0, 255, 0, 450, 1350, UnitSizeTypes::Large, 3, 2, 44, 28, 44, 28, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Robotics_Support_Bay].set("Protoss Robotics Support Bay", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Robotics_Facility, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 450, 450, 0, 1, 150, 100, 450, 0, 0, 255, 0, 125, 375, UnitSizeTypes::Large, 3, 2, 32, 32, 32, 20, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Protoss_Shield_Battery].set("Protoss Shield Battery", Races::Protoss, 0, Protoss_Probe, 1, Protoss_Gateway, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 200, 200, 200, 1, 100, 0, 450, 0, 0, 255, 0, 50, 150, UnitSizeTypes::Large, 3, 2, 32, 16, 32, 16, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Khaydarin_Crystal_Form].set("Special Khaydarin Crystal Form", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 1, 250, 0, 1, 0, 0, 255, 0, 0, 2500, UnitSizeTypes::Large, 4, 3, 64, 48, 63, 47, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Protoss_Temple].set("Special Protoss Temple", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1500, 0, 0, 1, 250, 0, 1, 0, 0, 255, 0, 0, 5000, UnitSizeTypes::Large, 7, 3, 112, 48, 111, 47, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_XelNaga_Temple].set("Special XelNaga Temple", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 5000, 0, 0, 1, 1500, 500, 4800, 0, 0, 255, 0, 0, 5000, UnitSizeTypes::Large, 5, 4, 80, 34, 79, 63, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Resource_Mineral_Field].set("Resource Mineral Field", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 10, 10, UnitSizeTypes::Independent, 2, 1, 32, 16, 31, 15, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
      unitTypeData[Resource_Mineral_Field_Type_2].set("Resource Mineral Field Type 2", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 10, 10, UnitSizeTypes::Independent, 2, 1, 32, 16, 31, 15, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
      unitTypeData[Resource_Mineral_Field_Type_3].set("Resource Mineral Field Type 3", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 10, 10, UnitSizeTypes::Independent, 2, 1, 32, 16, 31, 15, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
      unitTypeData[Special_Independant_Starport].set("Special Independant Starport", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,10,10, UnitSizeTypes::Independent,2,2,32,32,31,31,0,288, WeaponTypes::Independant_Laser_Battery,1, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0);
      unitTypeData[Resource_Vespene_Geyser].set("Resource Vespene Geyser", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 10, 10, UnitSizeTypes::Independent, 4, 2, 64, 32, 63, 31, 0, 288, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0);
      unitTypeData[Special_Warp_Gate].set("Special Warp Gate", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 700, 0, 0, 1, 600, 200, 2400, 0, 0, 255, 0, 0, 2000, UnitSizeTypes::Large, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Psi_Disrupter].set("Special Psi Disrupter", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 2000, 0, 0, 1, 1000, 400, 4800, 0, 0, 255, 0, 0, 3600, UnitSizeTypes::Large, 5, 3, 80, 38, 69, 47, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Power_Generator].set("Special Power Generator", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 1, 200, 50, 2400, 0, 0, 255, 0, 0, 600, UnitSizeTypes::Large, 4, 3, 56, 28, 63, 43, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Overmind_Cocoon].set("Special Overmind Cocoon", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 2500, 0, 0, 1, 1000, 500, 2400, 0, 0, 255, 0, 0, 4000, UnitSizeTypes::Large, 3, 2, 48, 32, 47, 31, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Zerg_Beacon].set("Special Zerg Beacon", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 250, 0, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Terran_Beacon].set("Special Terran Beacon", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 50, 50, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Protoss_Beacon].set("Special Protoss Beacon", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 100, 100, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Zerg_Flag_Beacon].set("Special Zerg Flag Beacon", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 250, 0, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Terran_Flag_Beacon].set("Special Terran Flag Beacon", Races::Terran, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 50, 50, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Special_Protoss_Flag_Beacon].set("Special Protoss Flag Beacon", Races::Protoss, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 100, 100, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 3, 2, 48, 32, 47, 31, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);
      unitTypeData[Spell_Dark_Swarm].set("Spell Dark Swarm", Races::Zerg, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 250, 200, 2400, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 5, 5, 80, 80, 79, 79, 0, 256, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0);
      unitTypeData[Powerup_Uraj_Crystal].set("Powerup Uraj Crystal", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 10000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Khalis_Crystal].set("Powerup Khalis Crystal", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 10000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Flag].set("Powerup Flag", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 10000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Young_Chrysalis].set("Powerup Young Chrysalis", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Psi_Emitter].set("Powerup Psi Emitter", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Data_Disk].set("Powerup Data Disk", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Khaydarin_Crystal].set("Powerup Khaydarin Crystal", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 16, 16, 15, 15, 0, 160, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Powerup_Mineral_Cluster_Type_1].set("Powerup Mineral Cluster Type 1", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Mineral_Cluster_Type_2].set("Powerup Mineral Cluster Type 2", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Protoss_Gas_Orb_Type_1].set("Powerup Protoss Gas Orb Type 1", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Protoss_Gas_Orb_Type_2].set("Powerup Protoss Gas Orb Type 2", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Zerg_Gas_Sac_Type_1].set("Powerup Zerg Gas Sac Type 1", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Zerg_Gas_Sac_Type_2].set("Powerup Zerg Gas Sac Type 2", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Terran_Gas_Tank_Type_1].set("Powerup Terran Gas Tank Type 1", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Powerup_Terran_Gas_Tank_Type_2].set("Powerup Terran Gas Tank Type 2", Races::None,0, None,0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None,800,0,0,0,1,1,1,0,0,255,0,0,0, UnitSizeTypes::Independent,1,1,16,16,15,15,0,160, WeaponTypes::None,0, WeaponTypes::None,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
      unitTypeData[Special_Map_Revealer].set("Special Map Revealer", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 1, 0, 0, 0, 0, 0, 1, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 1, 1, 13, 13, 13, 17, 0, 320, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Floor_Missile_Trap].set("Special Floor Missile Trap", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 50, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 100, UnitSizeTypes::Large, 2, 2, 32, 32, 31, 31, 160, 192, WeaponTypes::Hellfire_Missile_Pack_Floor_Trap, 1, WeaponTypes::None, 0, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Floor_Gun_Trap].set("Special Floor Gun Trap", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 50, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 100, UnitSizeTypes::Large, 2, 2, 32, 32, 31, 31, 160, 192, WeaponTypes::Twin_Autocannons_Floor_Trap, 1, WeaponTypes::None, 0, 0, 0, 0, 127, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Wall_Missile_Trap].set("Special Wall Missile Trap", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 50, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 100, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 160, 192, WeaponTypes::Hellfire_Missile_Pack_Wall_Trap, 1, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Right_Wall_Missile_Trap].set("Special Right Wall Missile Trap", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 50, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 100, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 160, 192, WeaponTypes::Hellfire_Missile_Pack_Wall_Trap, 1, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Wall_Flame_Trap].set("Special Wall Flame Trap", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 50, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 100, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 64, 96, WeaponTypes::Flame_Thrower_Wall_Trap, 1, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Right_Wall_Flame_Trap].set("Special Right Wall Flame Trap", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 50, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 100, UnitSizeTypes::Large, 1, 1, 16, 16, 15, 15, 64, 96, WeaponTypes::Flame_Thrower_Wall_Trap, 1, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Upper_Level_Door].set("Special Upper Level Door", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Independent, 3, 2, 25, 17, 44, 20, 0, 32, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Right_Upper_Level_Door].set("Special Right Upper Level Door", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Independent, 3, 2, 44, 17, 25, 20, 0, 32, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Pit_Door].set("Special Pit Door", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Independent, 3, 2, 41, 17, 28, 20, 0, 32, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Right_Pit_Door].set("Special Right Pit Door", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Independent, 3, 2, 28, 17, 41, 20, 0, 32, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Floor_Hatch].set("Special Floor Hatch", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 100000, 0, 0, 0, 1, 1, 1, 0, 0, 255, 0, 0, 10, UnitSizeTypes::Independent, 8, 4, 128, 64, 127, 63, 0, 224, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Special_Start_Location].set("Special Start Location", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 800, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::Independent, 4, 3, 48, 32, 48, 32, 0, 32, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0);

      unitTypeData[None].set("None", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[AllUnits].set("All Units", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Men].set("Men", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Buildings].set("Buildings", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Factories].set("Factories", Races::None, 0, None, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      unitTypeData[Unknown].set("Unknown", Races::Unknown, 0, Unknown, 0, None, None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, TechTypes::None, UpgradeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 255, 0, 0, 0, UnitSizeTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, WeaponTypes::None, 0, WeaponTypes::None, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

      unitTypeData[Protoss_Reaver].canAttack         = true;
      unitTypeData[Protoss_Carrier].canAttack        = true;
      unitTypeData[Hero_Gantrithor].canAttack        = true;
      unitTypeData[Hero_Warbringer].canAttack        = true;
      unitTypeData[Terran_Nuclear_Missile].canAttack = true;
      unitTypeData[Special_Independant_Starport].canAttack = false;

      foreach(UpgradeType i, UpgradeTypes::allUpgradeTypes())
      {
        foreach (UnitType ut, i.whatUses())
          unitTypeData[ut].upgrades.insert(i);
      }

      unitTypeSet.insert(Terran_Marine);
      unitTypeSet.insert(Hero_Jim_Raynor_Marine);
      unitTypeSet.insert(Terran_Ghost);
      unitTypeSet.insert(Hero_Sarah_Kerrigan);
      unitTypeSet.insert(Hero_Samir_Duran);
      unitTypeSet.insert(Hero_Infested_Duran);
      unitTypeSet.insert(Hero_Alexei_Stukov);
      unitTypeSet.insert(Terran_Vulture);
      unitTypeSet.insert(Hero_Jim_Raynor_Vulture);
      unitTypeSet.insert(Terran_Goliath);
      unitTypeSet.insert(Hero_Alan_Schezar);
      unitTypeSet.insert(Terran_Siege_Tank_Tank_Mode);
      unitTypeSet.insert(Hero_Edmund_Duke_Tank_Mode);
      unitTypeSet.insert(Terran_SCV);
      unitTypeSet.insert(Terran_Wraith);
      unitTypeSet.insert(Hero_Tom_Kazansky);
      unitTypeSet.insert(Terran_Science_Vessel);
      unitTypeSet.insert(Hero_Magellan);
      unitTypeSet.insert(Terran_Dropship);
      unitTypeSet.insert(Terran_Battlecruiser);
      unitTypeSet.insert(Hero_Arcturus_Mengsk);
      unitTypeSet.insert(Hero_Hyperion);
      unitTypeSet.insert(Hero_Norad_II);
      unitTypeSet.insert(Hero_Gerard_DuGalle);
      unitTypeSet.insert(Terran_Vulture_Spider_Mine);
      unitTypeSet.insert(Terran_Nuclear_Missile);
      unitTypeSet.insert(Terran_Siege_Tank_Siege_Mode);
      unitTypeSet.insert(Hero_Edmund_Duke_Siege_Mode);
      unitTypeSet.insert(Terran_Firebat);
      unitTypeSet.insert(Hero_Gui_Montag);
      unitTypeSet.insert(Spell_Scanner_Sweep);
      unitTypeSet.insert(Terran_Medic);
      unitTypeSet.insert(Terran_Civilian);
      unitTypeSet.insert(Zerg_Larva);
      unitTypeSet.insert(Zerg_Egg);
      unitTypeSet.insert(Zerg_Zergling);
      unitTypeSet.insert(Hero_Devouring_One);
      unitTypeSet.insert(Hero_Infested_Kerrigan);
      unitTypeSet.insert(Zerg_Hydralisk);
      unitTypeSet.insert(Hero_Hunter_Killer);
      unitTypeSet.insert(Zerg_Ultralisk);
      unitTypeSet.insert(Hero_Torrasque);
      unitTypeSet.insert(Zerg_Broodling);
      unitTypeSet.insert(Zerg_Drone);
      unitTypeSet.insert(Zerg_Overlord);
      unitTypeSet.insert(Hero_Yggdrasill);
      unitTypeSet.insert(Zerg_Mutalisk);
      unitTypeSet.insert(Hero_Kukulza_Mutalisk);
      unitTypeSet.insert(Zerg_Guardian);
      unitTypeSet.insert(Hero_Kukulza_Guardian);
      unitTypeSet.insert(Zerg_Queen);
      unitTypeSet.insert(Hero_Matriarch);
      unitTypeSet.insert(Zerg_Defiler);
      unitTypeSet.insert(Hero_Unclean_One);
      unitTypeSet.insert(Zerg_Scourge);
      unitTypeSet.insert(Zerg_Infested_Terran);
      unitTypeSet.insert(Terran_Valkyrie);
      unitTypeSet.insert(Zerg_Cocoon);
      unitTypeSet.insert(Protoss_Corsair);
      unitTypeSet.insert(Hero_Raszagal);
      unitTypeSet.insert(Protoss_Dark_Templar);
      unitTypeSet.insert(Hero_Dark_Templar);
      unitTypeSet.insert(Hero_Zeratul);
      unitTypeSet.insert(Zerg_Devourer);
      unitTypeSet.insert(Protoss_Dark_Archon);
      unitTypeSet.insert(Protoss_Probe);
      unitTypeSet.insert(Protoss_Zealot);
      unitTypeSet.insert(Hero_Fenix_Zealot);
      unitTypeSet.insert(Protoss_Dragoon);
      unitTypeSet.insert(Hero_Fenix_Dragoon);
      unitTypeSet.insert(Protoss_High_Templar);
      unitTypeSet.insert(Hero_Tassadar);
      unitTypeSet.insert(Hero_Aldaris);
      unitTypeSet.insert(Protoss_Archon);
      unitTypeSet.insert(Hero_Tassadar_Zeratul_Archon);
      unitTypeSet.insert(Protoss_Shuttle);
      unitTypeSet.insert(Protoss_Scout);
      unitTypeSet.insert(Hero_Mojo);
      unitTypeSet.insert(Hero_Artanis);
      unitTypeSet.insert(Protoss_Arbiter);
      unitTypeSet.insert(Hero_Danimoth);
      unitTypeSet.insert(Protoss_Carrier);
      unitTypeSet.insert(Hero_Gantrithor);
      unitTypeSet.insert(Protoss_Interceptor);
      unitTypeSet.insert(Protoss_Reaver);
      unitTypeSet.insert(Hero_Warbringer);
      unitTypeSet.insert(Protoss_Observer);
      unitTypeSet.insert(Protoss_Scarab);
      unitTypeSet.insert(Critter_Rhynadon);
      unitTypeSet.insert(Critter_Bengalaas);
      unitTypeSet.insert(Special_Cargo_Ship);
      unitTypeSet.insert(Special_Mercenary_Gunship);
      unitTypeSet.insert(Critter_Scantid);
      unitTypeSet.insert(Critter_Kakaru);
      unitTypeSet.insert(Critter_Ragnasaur);
      unitTypeSet.insert(Critter_Ursadon);
      unitTypeSet.insert(Zerg_Lurker_Egg);
      unitTypeSet.insert(Zerg_Lurker);
      unitTypeSet.insert(Spell_Disruption_Web);
      unitTypeSet.insert(Terran_Command_Center);
      unitTypeSet.insert(Terran_Comsat_Station);
      unitTypeSet.insert(Terran_Nuclear_Silo);
      unitTypeSet.insert(Terran_Supply_Depot);
      unitTypeSet.insert(Terran_Refinery);
      unitTypeSet.insert(Terran_Barracks);
      unitTypeSet.insert(Terran_Academy);
      unitTypeSet.insert(Terran_Factory);
      unitTypeSet.insert(Terran_Starport);
      unitTypeSet.insert(Terran_Control_Tower);
      unitTypeSet.insert(Terran_Science_Facility);
      unitTypeSet.insert(Terran_Covert_Ops);
      unitTypeSet.insert(Terran_Physics_Lab);
      unitTypeSet.insert(Terran_Machine_Shop);
      unitTypeSet.insert(Terran_Engineering_Bay);
      unitTypeSet.insert(Terran_Armory);
      unitTypeSet.insert(Terran_Missile_Turret);
      unitTypeSet.insert(Terran_Bunker);
      unitTypeSet.insert(Special_Crashed_Norad_II);
      unitTypeSet.insert(Special_Ion_Cannon);
      unitTypeSet.insert(Zerg_Infested_Command_Center);
      unitTypeSet.insert(Zerg_Hatchery);
      unitTypeSet.insert(Zerg_Lair);
      unitTypeSet.insert(Zerg_Hive);
      unitTypeSet.insert(Zerg_Nydus_Canal);
      unitTypeSet.insert(Zerg_Hydralisk_Den);
      unitTypeSet.insert(Zerg_Defiler_Mound);
      unitTypeSet.insert(Zerg_Greater_Spire);
      unitTypeSet.insert(Zerg_Queens_Nest);
      unitTypeSet.insert(Zerg_Evolution_Chamber);
      unitTypeSet.insert(Zerg_Ultralisk_Cavern);
      unitTypeSet.insert(Zerg_Spire);
      unitTypeSet.insert(Zerg_Spawning_Pool);
      unitTypeSet.insert(Zerg_Creep_Colony);
      unitTypeSet.insert(Zerg_Spore_Colony);
      unitTypeSet.insert(Zerg_Sunken_Colony);
      unitTypeSet.insert(Special_Overmind_With_Shell);
      unitTypeSet.insert(Special_Overmind);
      unitTypeSet.insert(Zerg_Extractor);
      unitTypeSet.insert(Special_Mature_Chrysalis);
      unitTypeSet.insert(Special_Cerebrate);
      unitTypeSet.insert(Special_Cerebrate_Daggoth);
      unitTypeSet.insert(Protoss_Nexus);
      unitTypeSet.insert(Protoss_Robotics_Facility);
      unitTypeSet.insert(Protoss_Pylon);
      unitTypeSet.insert(Protoss_Assimilator);
      unitTypeSet.insert(Protoss_Observatory);
      unitTypeSet.insert(Protoss_Gateway);
      unitTypeSet.insert(Protoss_Photon_Cannon);
      unitTypeSet.insert(Protoss_Citadel_of_Adun);
      unitTypeSet.insert(Protoss_Cybernetics_Core);
      unitTypeSet.insert(Protoss_Templar_Archives);
      unitTypeSet.insert(Protoss_Forge);
      unitTypeSet.insert(Protoss_Stargate);
      unitTypeSet.insert(Special_Stasis_Cell_Prison);
      unitTypeSet.insert(Protoss_Fleet_Beacon);
      unitTypeSet.insert(Protoss_Arbiter_Tribunal);
      unitTypeSet.insert(Protoss_Robotics_Support_Bay);
      unitTypeSet.insert(Protoss_Shield_Battery);
      unitTypeSet.insert(Special_Khaydarin_Crystal_Form);
      unitTypeSet.insert(Special_Protoss_Temple);
      unitTypeSet.insert(Special_XelNaga_Temple);
      unitTypeSet.insert(Resource_Mineral_Field);
      unitTypeSet.insert(Resource_Mineral_Field_Type_2);
      unitTypeSet.insert(Resource_Mineral_Field_Type_3);
      unitTypeSet.insert(Special_Independant_Starport);
      unitTypeSet.insert(Resource_Vespene_Geyser);
      unitTypeSet.insert(Special_Warp_Gate);
      unitTypeSet.insert(Special_Psi_Disrupter);
      unitTypeSet.insert(Special_Power_Generator);
      unitTypeSet.insert(Special_Overmind_Cocoon);
      unitTypeSet.insert(Special_Zerg_Beacon);
      unitTypeSet.insert(Special_Terran_Beacon);
      unitTypeSet.insert(Special_Protoss_Beacon);
      unitTypeSet.insert(Special_Zerg_Flag_Beacon);
      unitTypeSet.insert(Special_Terran_Flag_Beacon);
      unitTypeSet.insert(Special_Protoss_Flag_Beacon);
      unitTypeSet.insert(Spell_Dark_Swarm);
      unitTypeSet.insert(Powerup_Uraj_Crystal);
      unitTypeSet.insert(Powerup_Khalis_Crystal);
      unitTypeSet.insert(Powerup_Flag);
      unitTypeSet.insert(Powerup_Young_Chrysalis);
      unitTypeSet.insert(Powerup_Psi_Emitter);
      unitTypeSet.insert(Powerup_Data_Disk);
      unitTypeSet.insert(Powerup_Khaydarin_Crystal);
      unitTypeSet.insert(Powerup_Mineral_Cluster_Type_1);
      unitTypeSet.insert(Powerup_Mineral_Cluster_Type_2);
      unitTypeSet.insert(Powerup_Protoss_Gas_Orb_Type_1);
      unitTypeSet.insert(Powerup_Protoss_Gas_Orb_Type_2);
      unitTypeSet.insert(Powerup_Zerg_Gas_Sac_Type_1);
      unitTypeSet.insert(Powerup_Zerg_Gas_Sac_Type_2);
      unitTypeSet.insert(Powerup_Terran_Gas_Tank_Type_1);
      unitTypeSet.insert(Powerup_Terran_Gas_Tank_Type_2);
      unitTypeSet.insert(Special_Map_Revealer);
      unitTypeSet.insert(Special_Floor_Missile_Trap);
      unitTypeSet.insert(Special_Floor_Gun_Trap);
      unitTypeSet.insert(Special_Wall_Missile_Trap);
      unitTypeSet.insert(Special_Right_Wall_Missile_Trap);
      unitTypeSet.insert(Special_Wall_Flame_Trap);
      unitTypeSet.insert(Special_Right_Wall_Flame_Trap);
      unitTypeSet.insert(Special_Upper_Level_Door);
      unitTypeSet.insert(Special_Right_Upper_Level_Door);
      unitTypeSet.insert(Special_Pit_Door);
      unitTypeSet.insert(Special_Right_Pit_Door);
      unitTypeSet.insert(Special_Floor_Hatch);
      unitTypeSet.insert(Special_Start_Location);

      unitTypeSet.insert(None);
      unitTypeSet.insert(Unknown);

      macroTypeSet.insert(AllUnits);
      macroTypeSet.insert(Men);
      macroTypeSet.insert(Buildings);
      macroTypeSet.insert(Factories);

      foreach(UnitType i, unitTypeSet)
      {
        int wid = i.dimensionLeft() + i.dimensionRight()  + 1;
        int hgt = i.dimensionUp()   + i.dimensionDown()   + 1;
        if ( wid > maxWidth )
          maxWidth = wid;
        if ( hgt > maxHeight )
          maxHeight = hgt;
      }
    }
  }
  UnitType::UnitType(int id) : Type( id )
  {
  }
  const std::string &UnitType::getName() const
  {
    return unitTypeData[this->getID()].name;
  }
  const char *UnitType::c_str() const
  {
    return unitTypeData[this->getID()].name.c_str();
  }
  Race UnitType::getRace() const
  {
    return unitTypeData[this->getID()].race;
  }
  const std::pair<  UnitType, int> UnitType::whatBuilds() const
  {
    return unitTypeData[this->getID()].whatBuilds;
  }
  const std::map<  UnitType, int >& UnitType::requiredUnits() const
  {
    return unitTypeData[this->getID()].requiredUnits;
  }
  TechType UnitType::requiredTech() const
  {
    return unitTypeData[this->getID()].requiredTech;
  }
  TechType UnitType::cloakingTech() const
  {
    return unitTypeData[this->getID()].cloakingTech;
  }
  const TechType::set& UnitType::abilities() const
  {
    return unitTypeData[this->getID()].abilities;
  }
  const UpgradeType::set& UnitType::upgrades() const
  {
    return unitTypeData[this->getID()].upgrades;
  }
  UpgradeType UnitType::armorUpgrade() const
  {
    return unitTypeData[this->getID()].armorUpgrade;
  }
  int UnitType::maxHitPoints() const
  {
    return unitTypeData[this->getID()].maxHitPoints;
  }
  int UnitType::maxShields() const
  {
    return unitTypeData[this->getID()].maxShields;
  }
  int UnitType::maxEnergy() const
  {
    return unitTypeData[this->getID()].maxEnergy;
  }
  int UnitType::armor() const
  {
    return unitTypeData[this->getID()].armor;
  }
  int UnitType::mineralPrice() const
  {
    return unitTypeData[this->getID()].mineralPrice;
  }
  int UnitType::gasPrice() const
  {
    return unitTypeData[this->getID()].gasPrice;
  }
  int UnitType::buildTime() const
  {
    return unitTypeData[this->getID()].buildTime;
  }
  int UnitType::supplyRequired() const
  {
    return unitTypeData[this->getID()].supplyRequired;
  }
  int UnitType::supplyProvided() const
  {
    return unitTypeData[this->getID()].supplyProvided;
  }
  int UnitType::spaceRequired() const
  {
    return unitTypeData[this->getID()].spaceRequired;
  }
  int UnitType::spaceProvided() const
  {
    return unitTypeData[this->getID()].spaceProvided;
  }
  int UnitType::buildScore() const
  {
    return unitTypeData[this->getID()].buildScore;
  }
  int UnitType::destroyScore() const
  {
    return unitTypeData[this->getID()].destroyScore;
  }
  UnitSizeType UnitType::size() const
  {
    return unitTypeData[this->getID()].unitSizeType;
  }
  int UnitType::tileWidth() const
  {
    return unitTypeData[this->getID()].tileWidth;
  }
  int UnitType::tileHeight() const
  {
    return unitTypeData[this->getID()].tileHeight;
  }
  TilePosition UnitType::tileSize() const
  {
    return TilePosition(tileWidth(), tileHeight());
  }
  int UnitType::dimensionLeft() const
  {
    return unitTypeData[this->getID()].dimensionLeft;
  }
  int UnitType::dimensionUp() const
  {
    return unitTypeData[this->getID()].dimensionUp;
  }
  int UnitType::dimensionRight() const
  {
    return unitTypeData[this->getID()].dimensionRight;
  }
  int UnitType::dimensionDown() const
  {
    return unitTypeData[this->getID()].dimensionDown;
  }
  int UnitType::seekRange() const
  {
    return unitTypeData[this->getID()].seekRange;
  }
  int UnitType::sightRange() const
  {
    return unitTypeData[this->getID()].sightRange;
  }
  WeaponType UnitType::groundWeapon() const
  {
    return unitTypeData[this->getID()].groundWeapon;
  }
  int UnitType::maxGroundHits() const
  {
    return unitTypeData[this->getID()].maxGroundHits;
  }
  WeaponType UnitType::airWeapon() const
  {
    return unitTypeData[this->getID()].airWeapon;
  }
  int UnitType::maxAirHits() const
  {
    return unitTypeData[this->getID()].maxAirHits;
  }
  double UnitType::topSpeed() const
  {
    return unitTypeData[this->getID()].topSpeed;
  }
  int UnitType::acceleration() const
  {
    return unitTypeData[this->getID()].acceleration;
  }
  int UnitType::haltDistance() const
  {
    return unitTypeData[this->getID()].haltDistance;
  }
  int UnitType::turnRadius() const
  {
    return unitTypeData[this->getID()].turnRadius;
  }
  bool UnitType::canProduce() const
  {
    return unitTypeData[this->getID()].canProduce;
  }
  bool UnitType::canAttack() const
  {
    return unitTypeData[this->getID()].canAttack;
  }
  bool UnitType::canMove() const
  {
    return unitTypeData[this->getID()].canMove;
  }
  bool UnitType::isFlyer() const
  {
    return unitTypeData[this->getID()].isFlyer;
  }
  bool UnitType::regeneratesHP() const
  {
    return unitTypeData[this->getID()].regeneratesHP;
  }
  bool UnitType::isSpellcaster() const
  {
    return unitTypeData[this->getID()].isSpellcaster;
  }
  bool UnitType::hasPermanentCloak() const
  {
    return unitTypeData[this->getID()].hasPermanentCloak;
  }
  bool UnitType::isInvincible() const
  {
    return unitTypeData[this->getID()].isInvincible;
  }
  bool UnitType::isOrganic() const
  {
    return unitTypeData[this->getID()].isOrganic;
  }
  bool UnitType::isMechanical() const
  {
    return unitTypeData[this->getID()].isMechanical;
  }
  bool UnitType::isRobotic() const
  {
    return unitTypeData[this->getID()].isRobotic;
  }
  bool UnitType::isDetector() const
  {
    return unitTypeData[this->getID()].isDetector;
  }
  bool UnitType::isResourceContainer() const
  {
    return unitTypeData[this->getID()].isResourceContainer;
  }
  bool UnitType::isResourceDepot() const
  {
    return unitTypeData[this->getID()].isResourceDepot;
  }
  bool UnitType::isRefinery() const
  {
    return unitTypeData[this->getID()].isRefinery;
  }
  bool UnitType::isWorker() const
  {
    return unitTypeData[this->getID()].isWorker;
  }
  bool UnitType::requiresPsi() const
  {
    return unitTypeData[this->getID()].requiresPsi;
  }
  bool UnitType::requiresCreep() const
  {
    return unitTypeData[this->getID()].requiresCreep;
  }
  bool UnitType::isTwoUnitsInOneEgg() const
  {
    return unitTypeData[this->getID()].isTwoUnitsInOneEgg;
  }
  bool UnitType::isBurrowable() const
  {
    return unitTypeData[this->getID()].isBurrowable;
  }
  bool UnitType::isCloakable() const
  {
    return unitTypeData[this->getID()].isCloakable;
  }
  bool UnitType::isBuilding() const
  {
    return unitTypeData[this->getID()].isBuilding;
  }
  bool UnitType::isAddon() const
  {
    return unitTypeData[this->getID()].isAddon;
  }
  bool UnitType::isFlyingBuilding() const
  {
    return unitTypeData[this->getID()].isFlyingBuilding;
  }
  bool UnitType::isNeutral() const
  {
    return unitTypeData[this->getID()].isNeutral;
  }
  bool UnitType::isHero() const
  {
    return unitTypeData[this->getID()].isHero ||
           this->getID() == UnitTypes::Hero_Dark_Templar ||
           this->getID() == UnitTypes::Terran_Civilian;
  }
  bool UnitType::isPowerup() const
  {
    return this->getID() == UnitTypes::Powerup_Uraj_Crystal ||
           this->getID() == UnitTypes::Powerup_Khalis_Crystal ||
           (this->getID() >= UnitTypes::Powerup_Flag && this->getID() < UnitTypes::None);
  }
  bool UnitType::isBeacon() const
  {
    return this->getID() == UnitTypes::Special_Zerg_Beacon ||
           this->getID() == UnitTypes::Special_Terran_Beacon ||
           this->getID() == UnitTypes::Special_Protoss_Beacon;
  }
  bool UnitType::isFlagBeacon() const
  {
    return this->getID() == UnitTypes::Special_Zerg_Flag_Beacon ||
           this->getID() == UnitTypes::Special_Terran_Flag_Beacon ||
           this->getID() == UnitTypes::Special_Protoss_Flag_Beacon;
  }
  bool UnitType::isSpecialBuilding() const
  {
    return unitTypeData[this->getID()].isSpecialBuilding && this->getID() != UnitTypes::Zerg_Infested_Command_Center;
  }
  bool UnitType::isSpell() const
  {
    return this->getID() == UnitTypes::Spell_Dark_Swarm ||
           this->getID() == UnitTypes::Spell_Disruption_Web ||
           this->getID() == UnitTypes::Spell_Scanner_Sweep;
  }
  bool UnitType::producesLarva() const
  {
    return this->getID() == UnitTypes::Zerg_Hatchery ||
           this->getID() == UnitTypes::Zerg_Lair     ||
           this->getID() == UnitTypes::Zerg_Hive;
  }
  bool UnitType::isMineralField() const
  {
    return this->getID() == UnitTypes::Resource_Mineral_Field        ||
           this->getID() == UnitTypes::Resource_Mineral_Field_Type_2 ||
           this->getID() == UnitTypes::Resource_Mineral_Field_Type_3;
  }
  bool UnitType::canBuildAddon() const
  {
    return this->getID() == UnitTypes::Terran_Command_Center  ||
           this->getID() == UnitTypes::Terran_Factory         ||
           this->getID() == UnitTypes::Terran_Starport        ||
           this->getID() == UnitTypes::Terran_Science_Facility;
  }
  UnitType UnitTypes::getUnitType(std::string name)
  {
    for ( int i = 0; i < UnitTypes::Enum::MAX; ++i )
    {
      if ( name == unitTypeNames[i] )
        return UnitType(i);
    }
    return UnitTypes::Unknown;
  }
  const UnitType::set& UnitTypes::allUnitTypes()
  {
    return unitTypeSet;
  }
  const UnitType::set& UnitTypes::allMacroTypes()
  {
    return macroTypeSet;
  }
  int UnitTypes::maxUnitWidth()
  {
    return maxWidth;
  }
  int UnitTypes::maxUnitHeight()
  {
    return maxHeight;
  }

}
