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
#include "FactoryHolder.h"
#include "MovementDefines.h"
#include "ObjectRegistry.h"
#include "Optional.h"
#include "ScriptActionResult.h"

class Creature;
class Unit;

enum MovementGeneratorType : uint8;

enum MovementGeneratorFlags : uint16
{
    MOVEMENTGENERATOR_FLAG_NONE                   = 0x000,
    MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING = 0x001,
    MOVEMENTGENERATOR_FLAG_INITIALIZED            = 0x002,
    MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING   = 0x004,
    MOVEMENTGENERATOR_FLAG_INTERRUPTED            = 0x008,
    MOVEMENTGENERATOR_FLAG_PAUSED                 = 0x010,
    MOVEMENTGENERATOR_FLAG_TIMED_PAUSED           = 0x020,
    MOVEMENTGENERATOR_FLAG_DEACTIVATED            = 0x040,
    MOVEMENTGENERATOR_FLAG_INFORM_ENABLED         = 0x080,
    MOVEMENTGENERATOR_FLAG_FINALIZED              = 0x100,
    MOVEMENTGENERATOR_FLAG_PERSIST_ON_DEATH       = 0x200,

    MOVEMENTGENERATOR_FLAG_TRANSITORY = MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING | MOVEMENTGENERATOR_FLAG_INTERRUPTED
};

class TC_GAME_API MovementGenerator
{
    public:
        explicit MovementGenerator() : Mode(0), Priority(0), Flags(MOVEMENTGENERATOR_FLAG_NONE), BaseUnitState(0) { }
        MovementGenerator(MovementGenerator const&) = delete;
        MovementGenerator(MovementGenerator&&) = delete;
        MovementGenerator& operator=(MovementGenerator const&) = delete;
        MovementGenerator& operator=(MovementGenerator&&) = delete;
        virtual ~MovementGenerator();

        // on top first update
        virtual void Initialize(Unit* owner) = 0;
        // on top reassign
        virtual void Reset(Unit* owner) = 0;
        // on top on MotionMaster::Update
        virtual bool Update(Unit* owner, uint32 diff) = 0;
        // on current top if another movement replaces
        virtual void Deactivate(Unit* owner) = 0;
        // on movement delete
        virtual void Finalize(Unit* owner, bool active, bool movementInform) = 0;
        virtual MovementGeneratorType GetMovementGeneratorType() const = 0;

        virtual void UnitSpeedChanged() { }
        // timer in ms
        virtual void Pause(uint32/* timer*/) { }
        // timer in ms
        virtual void Resume(uint32/* overrideTimer*/) { }
        // used by Evade code for select point to evade with expected restart default movement
        virtual bool GetResetPosition(Unit*, float&/* x*/, float&/* y*/, float&/* z*/) { return false; }

        void AddFlag(uint16 const flag) { Flags |= flag; }
        bool HasFlag(uint16 const flag) const { return (Flags & flag) != 0; }
        void RemoveFlag(uint16 const flag) { Flags &= ~flag; }

        virtual std::string GetDebugInfo() const;

        uint8 Mode;
        uint8 Priority;
        uint16 Flags;
        uint32 BaseUnitState;
        Optional<Scripting::v2::ActionResultSetter<MovementStopReason>> ScriptResult;

    protected:
        void SetScriptResult(MovementStopReason reason);
};

template<class T, class D>
class MovementGeneratorMedium : public MovementGenerator
{
    public:
        void Initialize(Unit* owner) override
        {
            (static_cast<D*>(this))->DoInitialize(static_cast<T*>(owner));
        }

        void Reset(Unit* owner) override
        {
            (static_cast<D*>(this))->DoReset(static_cast<T*>(owner));
        }

        bool Update(Unit* owner, uint32 diff) override
        {
            return (static_cast<D*>(this))->DoUpdate(static_cast<T*>(owner), diff);
        }

        void Deactivate(Unit* owner) override
        {
            (static_cast<D*>(this))->DoDeactivate(static_cast<T*>(owner));
        }

        void Finalize(Unit* owner, bool active, bool movementInform) override
        {
            (static_cast<D*>(this))->DoFinalize(static_cast<T*>(owner), active, movementInform);
        }
};

typedef FactoryHolder<MovementGenerator, Unit, MovementGeneratorType> MovementGeneratorCreator;

struct IdleMovementFactory : public MovementGeneratorCreator
{
    IdleMovementFactory() : MovementGeneratorCreator(IDLE_MOTION_TYPE) { }

    MovementGenerator* Create(Unit* object) const override;
};

struct RandomMovementFactory : public MovementGeneratorCreator
{
    RandomMovementFactory() : MovementGeneratorCreator(RANDOM_MOTION_TYPE) { }

    MovementGenerator* Create(Unit* object) const override;
};

struct WaypointMovementFactory : public MovementGeneratorCreator
{
    WaypointMovementFactory() : MovementGeneratorCreator(WAYPOINT_MOTION_TYPE) { }

    MovementGenerator* Create(Unit* object) const override;
};

typedef MovementGeneratorCreator::FactoryHolderRegistry MovementGeneratorRegistry;

#define sMovementGeneratorRegistry MovementGeneratorRegistry::instance()

#endif
