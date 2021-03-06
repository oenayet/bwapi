#pragma once

#include <BWAPI/Unit.h>
#include <BWAPI/Unitset.h>
#include <Util/Types.h>

#include <BWAPI/UnitCommand.h>
#include <BWAPI/Client/UnitData.h>

#define checkOwnership()\
{\
  if (_getPlayer != Broodwar->self())\
    return BroodwarImpl.setLastError(Errors::Unit_Not_Owned);\
}

namespace BW
{ 
  class Unit;
};
namespace BWAPI
{
  // Forwards
  class Player;

  /**
   * Interface for broodwar unit, can be used to obtain any information and
   * issue commands.
   */
  class UnitImpl : public Unit
  {
    public:
      virtual int           getID() const;
      virtual int           getReplayID() const;
      virtual Player*       getPlayer() const;
      virtual UnitType      getType() const;
      virtual Position      getPosition() const;
      virtual TilePosition  getTilePosition() const;
      virtual double        getAngle() const;
      virtual double        getVelocityX() const;
      virtual double        getVelocityY() const;
      virtual BWAPI::Region *getRegion() const;
      virtual int           getLeft() const;
      virtual int           getTop() const;
      virtual int           getRight() const;
      virtual int           getBottom() const;
      virtual int           getHitPoints() const;
      virtual int           getShields() const;
      virtual int           getEnergy() const;
      virtual int           getResources() const;
      virtual int           getResourceGroup() const;

      virtual int           getDistance(PositionOrUnit target) const;
      virtual bool          hasPath(PositionOrUnit target) const;
      virtual int           getLastCommandFrame() const;
      virtual UnitCommand   getLastCommand() const;
      virtual BWAPI::Player *getLastAttackingPlayer() const;
      virtual int           getUpgradeLevel(UpgradeType upgrade) const;

      virtual UnitType      getInitialType() const;
      virtual Position      getInitialPosition() const;
      virtual TilePosition  getInitialTilePosition() const;
      virtual int           getInitialHitPoints() const;
      virtual int           getInitialResources() const;

      virtual int getKillCount() const;
      virtual int getAcidSporeCount() const;
      virtual int getInterceptorCount() const;
      virtual int getScarabCount() const;
      virtual int getSpiderMineCount() const;
      virtual int getGroundWeaponCooldown() const;
      virtual int getAirWeaponCooldown() const;
      virtual int getSpellCooldown() const;
      virtual int getDefenseMatrixPoints() const;

      virtual int getDefenseMatrixTimer() const;
      virtual int getEnsnareTimer() const;
      virtual int getIrradiateTimer() const;
      virtual int getLockdownTimer() const;
      virtual int getMaelstromTimer() const;
      virtual int getOrderTimer() const;
      virtual int getPlagueTimer() const;
      virtual int getRemoveTimer() const;
      virtual int getStasisTimer() const;
      virtual int getStimTimer() const;

      virtual UnitType      getBuildType() const;
      virtual UnitType::set getTrainingQueue() const;
      virtual TechType      getTech() const;
      virtual UpgradeType   getUpgrade() const;
      virtual int           getRemainingBuildTime() const;
      virtual int           getRemainingTrainTime() const;
      virtual int           getRemainingResearchTime() const;
      virtual int           getRemainingUpgradeTime() const;
      virtual Unit*         getBuildUnit() const;

      virtual Unit*    getTarget() const;
      virtual Position getTargetPosition() const;
      virtual Order    getOrder() const;
      virtual Unit*    getOrderTarget() const;
      virtual Position getOrderTargetPosition() const;
      virtual Order    getSecondaryOrder() const;
      virtual Position getRallyPosition() const;
      virtual Unit*    getRallyUnit() const;
      virtual Unit*    getAddon() const;
      virtual Unit*    getNydusExit() const;
      virtual Unit*    getPowerUp() const;

      virtual Unit*    getTransport() const;
      virtual Unitset  getLoadedUnits() const;
      virtual Unit*    getCarrier() const;
      virtual Unitset  getInterceptors() const;
      virtual Unit*    getHatchery() const;
      virtual Unitset  getLarva() const;

      virtual void *getClientInfo() const;
      virtual void setClientInfo(void* clientinfo = nullptr);

      virtual bool exists() const;
      virtual bool hasNuke() const;
      virtual bool isAccelerating() const;
      virtual bool isAttackFrame() const;
      virtual bool isAttacking() const;
      virtual bool isBeingConstructed() const;
      virtual bool isBeingGathered() const;
      virtual bool isBeingHealed() const;
      virtual bool isBlind() const;
      virtual bool isBraking() const;
      virtual bool isBurrowed() const;
      virtual bool isCarryingGas() const;
      virtual bool isCarryingMinerals() const;
      virtual bool isCloaked() const;
      virtual bool isCompleted() const;
      virtual bool isConstructing() const;
      virtual bool isDetected() const;
      virtual bool isGatheringGas() const;
      virtual bool isGatheringMinerals() const;
      virtual bool isHallucination() const;
      virtual bool isInWeaponRange(Unit *target) const;
      virtual bool isIdle() const;
      virtual bool isInterruptible() const;
      virtual bool isInvincible() const;
      virtual bool isLifted() const;
      virtual bool isMorphing() const;
      virtual bool isMoving() const;
      virtual bool isParasited() const;
      virtual bool isSelected() const;
      virtual bool isStartingAttack() const;
      virtual bool isStuck() const;
      virtual bool isTraining() const;
      virtual bool isUnderAttack() const;
      virtual bool isUnderDarkSwarm() const;
      virtual bool isUnderDisruptionWeb() const;
      virtual bool isUnderStorm() const;
      virtual bool isUnpowered() const;
      virtual bool isVisible(Player* player = nullptr) const;

      virtual bool canIssueCommand(UnitCommand c) const;
      virtual bool issueCommand(UnitCommand command);

      //Internal BWAPI commands:
      UnitImpl(BW::Unit* originalUnit,
               u16 index);
      ~UnitImpl();
      static UnitImpl* BWUnitToBWAPIUnit(BW::Unit* unit);
      void die();
      void setID(int newID);
      bool canAccess() const;
      bool canAccessDetected() const;
      bool canAccessInside() const;
      Player* _getPlayer;
      UnitType _getType;
      Position _getPosition;
      int _getResources;
      int _getHitPoints;
      bool _isCompleted;
      bool wasCompleted;
      Unit* _getTransport;

      /**
       * Gets index of the unit in the unit array. Note that the index is same
       * for the original unit array, BWAPI::Unit array and BWAI::Unit array, so
       * it is good way to compare units of different types and for conversion.
       * @return 0-based index of the unit in the unit array.
       */
      u16 getIndex() const;
      void setSelected(bool selectedState);
      void setLoaded(bool loadedState);
      UnitImpl* getNext() const;
      /** Gets #bwOriginalUnit */
      BW::Unit* getOriginalRawData;
      /** Gets #bwUnitLocal */
      u8 getBuildQueueSlot;
      /** Gets #bwUnit->BW#Unit#buildQueue */
      BWAPI::UnitType getBuildQueue[5];
      /** Returns if the unit has empty building queue */
      bool hasEmptyBuildQueue;

      void saveInitialState();
      void updateInternalData();
      void updateData();
      UnitData data;
      UnitData *self;

      bool userSelected;
      bool staticInformation;
      bool nukeDetected;
      Position nukePosition;
      int lastGroundWeaponCooldown;
      int lastAirWeaponCooldown;
      int lastFrameSet;
      bool startingAttack;
      UnitType lastType;
      Player* lastPlayer;
      int id;
      bool isAlive;
      bool wasAlive;
      bool wasAccessible;
      bool wasVisible;

      Unitset connectedUnits;
      Unitset loadedUnits;

      int lastCommandFrame;
      UnitCommand lastCommand;

      void *clientInfo;
    private:
      /** Orders to select this unit (previous selection will be lost. */
      void orderSelect();
      void clear();

      u16 index; /**< Index of the unit in the array (can be computed, it's just optimisation) */
      UnitType initialType;
      BWAPI::Position initialPosition;
      int initialResources;
      int initialHitPoints;
  };
};

