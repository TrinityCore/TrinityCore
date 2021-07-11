/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOS_MOVEMENTGENERATOR_H
#define MANGOS_MOVEMENTGENERATOR_H

#include "Common.h"
#include "Platform/Define.h"
#include "Policies/Singleton.h"
#include "Dynamic/ObjectRegistry.h"
#include "Dynamic/FactoryHolder.h"
#include "MotionMaster.h"

class Unit;

class MovementGenerator
{
    public:
        virtual ~MovementGenerator();

        // called before adding movement generator to motion stack
        virtual void Initialize(Unit &) = 0;
        // called aftre remove movement generator from motion stack
        virtual void Finalize(Unit &) = 0;

        // called before lost top position (before push new movement generator above)
        virtual void Interrupt(Unit &) = 0;
        // called after return movement generator to top position (after remove above movement generator)
        virtual void Reset(Unit &) = 0;

        virtual bool Update(Unit &, uint32 const& time_diff) = 0;
        // Should be trade-safe! No AI call, no other unit modification, etc ...
        // Can use pathfinding things (use to compute paths)
        virtual void UpdateAsync(Unit&, uint32) {}

        virtual MovementGeneratorType GetMovementGeneratorType() const = 0;

        virtual void UnitSpeedChanged() { }

        virtual void UpdateFinalDistance(float /*fDistance*/) { }

        // given destination unreachable? due to pathfinding or other
        virtual bool IsReachable() const { return true; }

        // used by Evade code for select point to evade with expected restart default movement
        virtual bool GetResetPosition(Unit &, float& /*x*/, float& /*y*/, float& /*z*/) { return false; }

        // used for check from Update call is movegen still be active (top movement generator)
        // after some not safe for this calls
        bool IsActive(Unit& u);
};

template<class T, class D>
class MovementGeneratorMedium : public MovementGenerator
{
    public:
        void Initialize(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->Initialize(*((T*)&u));
        }
        void Finalize(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->Finalize(*((T*)&u));
        }
        void Interrupt(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->Interrupt(*((T*)&u));
        }
        void Reset(Unit &u) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->Reset(*((T*)&u));
        }
        bool Update(Unit &u, uint32 const& time_diff) override
        {
            //u->AssertIsType<T>();
            return (static_cast<D*>(this))->Update(*((T*)&u), time_diff);
        }
        void UpdateAsync(Unit &u, uint32 time_diff) override
        {
            //u->AssertIsType<T>();
            (static_cast<D*>(this))->UpdateAsync(*((T*)&u), time_diff);
        }
        bool GetResetPosition(Unit& u, float& x, float& y, float& z) override
        {
            //u->AssertIsType<T>();
            return (static_cast<D*>(this))->GetResetPosition(*((T*)&u), x, y, z);
        }

        // will not link if not overridden in the generators
        void Initialize(T &u);
        void Finalize(T &u);
        void Interrupt(T &u);
        void Reset(T &u);
        bool Update(T &u, uint32 const& time_diff);
        void UpdateAsync(T &/*u*/, uint32 /*time_diff*/) {}

        // not need always overwrites
        bool GetResetPosition(T& /*u*/, float& /*x*/, float& /*y*/, float& /*z*/) { return false; }
};

struct SelectableMovement : FactoryHolder<MovementGenerator,MovementGeneratorType>
{
    explicit SelectableMovement(MovementGeneratorType mgt) : FactoryHolder<MovementGenerator,MovementGeneratorType>(mgt) {}
};

template<class REAL_MOVEMENT>
struct MovementGeneratorFactory : SelectableMovement
{
    explicit MovementGeneratorFactory(MovementGeneratorType mgt) : SelectableMovement(mgt) {}

    MovementGenerator* Create(void *) const override;
};

typedef FactoryHolder<MovementGenerator,MovementGeneratorType> MovementGeneratorCreator;
typedef FactoryHolder<MovementGenerator,MovementGeneratorType>::FactoryHolderRegistry MovementGeneratorRegistry;
typedef FactoryHolder<MovementGenerator,MovementGeneratorType>::FactoryHolderRepository MovementGeneratorRepository;

#endif
