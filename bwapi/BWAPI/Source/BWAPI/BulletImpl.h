#pragma once

#include "BWAPI/Bullet.h"

#include <Util/Types.h>
#include <BWAPI/Position.h>
#include <BWAPI/Client/BulletData.h>
namespace BW    { struct Bullet; };

namespace BWAPI
{
  // forwards
  class UnitImpl;
  class BulletType;

  /**
   * Interface for broodwar bullets, can be used to obtain any information
   * about bullets and spells
   */
  class BulletImpl : public Bullet
  {
    public:
      virtual int        getID() const;
      virtual Player*    getPlayer() const;
      virtual BulletType getType() const;
      virtual Unit*      getSource() const;
      virtual Position   getPosition() const;
      virtual double     getAngle() const;
      virtual double     getVelocityX() const;
      virtual double     getVelocityY() const;
      virtual Unit*      getTarget() const;
      virtual Position   getTargetPosition() const;
      virtual int        getRemoveTimer() const;
      virtual bool       exists() const;
      virtual bool       isVisible(Player* player = nullptr) const;

      BulletImpl(BW::Bullet* originalBullet, u16 index);
      ~BulletImpl();

      void        setExists(bool exists);
      BW::Bullet* getRawData() const;
      void        saveExists();

      BulletData* self;
      BulletData  data;
      void        updateData();

      static BulletImpl* BWBulletToBWAPIBullet(BW::Bullet* bullet);
    private:
      BW::Bullet* bwOriginalBullet; /**< Pointer to broodwar unit data table. */
      u16 index;
      int id;
      bool __exists;
      bool lastExists;
  };
};