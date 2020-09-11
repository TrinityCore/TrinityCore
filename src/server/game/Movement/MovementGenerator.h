/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_MOVEMENTGENERATOR_H
#define TRINITY_MOVEMENTGENERATOR_H

#include "Define.h"
#include "ObjectRegistry.h"
#include "FactoryHolder.h"
#include "Common.h"
#include "MotionMaster.h"

class Unit;

class TC_GAME_API MovementGenerator
{
    public:
        virtual ~MovementGenerator();

        virtual void Initialize(Unit*) = 0;
        virtual void Finalize(Unit*) = 0;
        virtual void Reset(Unit*) = 0;
        virtual bool Update(Unit*, uint32 diff) = 0;
        virtual MovementGeneratorType GetMovementGeneratorType() const = 0;

        virtual void UnitSpeedChanged() { }
        virtual void Pause(uint32/* timer = 0*/) { } // timer in ms
        virtual void Resume(uint32/* overrideTimer = 0*/) { } // timer in ms

        // used by Evade code for select point to evade with expected restart default movement
        virtual bool GetResetPosition(Unit*, float& /*x*/, float& /*y*/, float& /*z*/) { return false; }

        virtual void NotifyAIOnFinalize(Unit*);
};

template<class T, class D>
class MovementGeneratorMedium : public MovementGenerator
{
    public:
        void Initialize(Unit* u) override
        {
            (static_cast<D*>(this))->DoInitialize(static_cast<T*>(u));
        }

        void Finalize(Unit* u) override
        {
            (static_cast<D*>(this))->DoFinalize(static_cast<T*>(u));
        }

        void Reset(Unit* u) override
        {
            (static_cast<D*>(this))->DoReset(static_cast<T*>(u));
        }

        bool Update(Unit* u, uint32 time_diff) override
        {
            return (static_cast<D*>(this))->DoUpdate(static_cast<T*>(u), time_diff);
        }
};

typedef FactoryHolder<MovementGenerator, Unit, MovementGeneratorType> MovementGeneratorCreator;

template<class Movement>
struct MovementGeneratorFactory : public MovementGeneratorCreator
{
    MovementGeneratorFactory(MovementGeneratorType movementGeneratorType) : MovementGeneratorCreator(movementGeneratorType) { }

    MovementGenerator* Create(Unit* /*object*/) const override
    {
        return new Movement();
    }
};

struct IdleMovementFactory : public MovementGeneratorCreator
{
    IdleMovementFactory() : MovementGeneratorCreator(IDLE_MOTION_TYPE) { }

    MovementGenerator* Create(Unit* object) const override;
};

typedef MovementGeneratorCreator::FactoryHolderRegistry MovementGeneratorRegistry;

#define sMovementGeneratorRegistry MovementGeneratorRegistry::instance()

#endif
