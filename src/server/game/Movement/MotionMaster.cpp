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

#include "MotionMaster.h"
#include "AbstractFollower.h"
#include "Creature.h"
#include "CreatureAISelector.h"
#include "Containers.h"
#include "DB2Stores.h"
#include "Errors.h"
#include "G3DPosition.hpp"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "PetDefines.h"
#include "Player.h"
#include "ScriptSystem.h"
#include "Unit.h"
#include "WaypointDefines.h"
#include <algorithm>
#include <iterator>

#include "ChaseMovementGenerator.h"
#include "ConfusedMovementGenerator.h"
#include "FleeingMovementGenerator.h"
#include "FlightPathMovementGenerator.h"
#include "FollowMovementGenerator.h"
#include "FormationMovementGenerator.h"
#include "GenericMovementGenerator.h"
#include "HomeMovementGenerator.h"
#include "IdleMovementGenerator.h"
#include "Memory.h"
#include "PointMovementGenerator.h"
#include "RandomMovementGenerator.h"
#include "SplineChainMovementGenerator.h"
#include "WaypointMovementGenerator.h"

inline MovementGenerator* GetIdleMovementGenerator()
{
    return sMovementGeneratorRegistry->GetRegistryItem(IDLE_MOTION_TYPE)->Create();
}

inline bool IsStatic(MovementGenerator* movement)
{
    return (movement == GetIdleMovementGenerator());
}

inline void MovementGeneratorPointerDeleter(MovementGenerator* a)
{
    if (a != nullptr && !IsStatic(a))
        delete a;
}

void MovementGeneratorDeleter::operator()(MovementGenerator* a)
{
    MovementGeneratorPointerDeleter(a);
}

bool MovementGeneratorComparator::operator()(MovementGenerator const* a, MovementGenerator const* b) const
{
    if (a->Mode > b->Mode)
        return true;
    else if (a->Mode == b->Mode)
        return a->Priority > b->Priority;

    return false;
}

MovementGeneratorInformation::MovementGeneratorInformation(MovementGeneratorType type, ObjectGuid targetGUID, std::string const& targetName) : Type(type), TargetGUID(targetGUID), TargetName(targetName) { }

MotionMaster::MotionMaster(Unit* unit) : _owner(unit), _defaultGenerator(nullptr), _flags(MOTIONMASTER_FLAG_INITIALIZATION_PENDING) { }

MotionMaster::~MotionMaster()
{
    _delayedActions.clear();

    for (auto itr = _generators.begin(); itr != _generators.end(); itr = _generators.erase(itr))
        MovementGeneratorPointerDeleter(*itr);
}

void MotionMaster::Initialize()
{
    if (HasFlag(MOTIONMASTER_FLAG_INITIALIZATION_PENDING))
        return;

    if (HasFlag(MOTIONMASTER_FLAG_UPDATE))
    {
        DelayedActionDefine action = [this]()
        {
            Initialize();
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_INITIALIZE);
        return;
    }

    DirectInitialize();
}

void MotionMaster::InitializeDefault()
{
    Add(FactorySelector::SelectMovementGenerator(_owner), MOTION_SLOT_DEFAULT);
}

void MotionMaster::AddToWorld()
{
    if (!HasFlag(MOTIONMASTER_FLAG_INITIALIZATION_PENDING))
        return;

    AddFlag(MOTIONMASTER_FLAG_INITIALIZING);
    RemoveFlag(MOTIONMASTER_FLAG_INITIALIZATION_PENDING);

    DirectInitialize();
    ResolveDelayedActions();

    RemoveFlag(MOTIONMASTER_FLAG_INITIALIZING);
}

bool MotionMaster::Empty() const
{
    return !_defaultGenerator && _generators.empty();
}

uint32 MotionMaster::Size() const
{
    return (_defaultGenerator ? 1 : 0) + uint32(_generators.size());
}

std::vector<MovementGeneratorInformation> MotionMaster::GetMovementGeneratorsInformation() const
{
    std::vector<MovementGeneratorInformation> list;

    if (_defaultGenerator)
        list.emplace_back(_defaultGenerator->GetMovementGeneratorType(), ObjectGuid::Empty, std::string());

    for (auto itr = _generators.begin(); itr != _generators.end(); ++itr)
    {
        MovementGenerator* movement = *itr;
        MovementGeneratorType const type = movement->GetMovementGeneratorType();
        switch (type)
        {
            case CHASE_MOTION_TYPE:
            case FOLLOW_MOTION_TYPE:
                if (AbstractFollower* followInformation = dynamic_cast<AbstractFollower*>(movement))
                {
                    if (Unit* target = followInformation->GetTarget())
                        list.emplace_back(type, target->GetGUID(), target->GetName());
                    else
                        list.emplace_back(type, ObjectGuid::Empty, std::string());
                }
                else
                    list.emplace_back(type, ObjectGuid::Empty, std::string());
                break;
            default:
                list.emplace_back(type, ObjectGuid::Empty, std::string());
                break;
        }
    }

    return list;
}

MovementSlot MotionMaster::GetCurrentSlot() const
{
    if (!_generators.empty())
        return MOTION_SLOT_ACTIVE;

    if (_defaultGenerator)
        return MOTION_SLOT_DEFAULT;

    return MAX_MOTION_SLOT;
}

MovementGenerator* MotionMaster::GetCurrentMovementGenerator() const
{
    if (!_generators.empty())
        return *_generators.begin();

    if (_defaultGenerator)
        return _defaultGenerator.get();

    return nullptr;
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType() const
{
    if (Empty())
        return MAX_MOTION_TYPE;

    MovementGenerator const* movement = GetCurrentMovementGenerator();
    if (!movement)
        return MAX_MOTION_TYPE;

    return movement->GetMovementGeneratorType();
}

MovementGeneratorType MotionMaster::GetCurrentMovementGeneratorType(MovementSlot slot) const
{
    if (Empty() || IsInvalidMovementSlot(slot))
        return MAX_MOTION_TYPE;

    if (slot == MOTION_SLOT_ACTIVE && !_generators.empty())
        return (*_generators.begin())->GetMovementGeneratorType();

    if (slot == MOTION_SLOT_DEFAULT && _defaultGenerator)
        return _defaultGenerator->GetMovementGeneratorType();

    return MAX_MOTION_TYPE;
}

MovementGenerator* MotionMaster::GetCurrentMovementGenerator(MovementSlot slot) const
{
    if (Empty() || IsInvalidMovementSlot(slot))
        return nullptr;

    if (slot == MOTION_SLOT_ACTIVE && !_generators.empty())
        return *_generators.begin();

    if (slot == MOTION_SLOT_DEFAULT && _defaultGenerator)
        return _defaultGenerator.get();

    return nullptr;
}

MovementGenerator* MotionMaster::GetMovementGenerator(std::function<bool(MovementGenerator const*)> const& filter, MovementSlot slot) const
{
    if (Empty() || IsInvalidMovementSlot(slot))
        return nullptr;

    MovementGenerator* movement = nullptr;
    switch (slot)
    {
        case MOTION_SLOT_DEFAULT:
            if (_defaultGenerator && filter(_defaultGenerator.get()))
                movement = _defaultGenerator.get();
            break;
        case MOTION_SLOT_ACTIVE:
            if (!_generators.empty())
            {
                auto itr = std::find_if(_generators.begin(), _generators.end(), std::ref(filter));
                if (itr != _generators.end())
                    movement = *itr;
            }
            break;
        default:
            break;
    }

    return movement;
}

bool MotionMaster::HasMovementGenerator(std::function<bool(MovementGenerator const*)> const& filter, MovementSlot slot) const
{
    if (Empty() || IsInvalidMovementSlot(slot))
        return false;

    bool value = false;
    switch (slot)
    {
        case MOTION_SLOT_DEFAULT:
            if (_defaultGenerator && filter(_defaultGenerator.get()))
                value = true;
            break;
        case MOTION_SLOT_ACTIVE:
            if (!_generators.empty())
            {
                auto itr = std::find_if(_generators.begin(), _generators.end(), std::ref(filter));
                value = itr != _generators.end();
            }
            break;
        default:
            break;
    }

    return value;
}

void MotionMaster::Update(uint32 diff)
{
    if (!_owner)
        return;

    if (HasFlag(MOTIONMASTER_FLAG_INITIALIZATION_PENDING | MOTIONMASTER_FLAG_INITIALIZING))
        return;

    ASSERT(!Empty(), "MotionMaster:Update: update called without Initializing! (%s)", _owner->GetGUID().ToString().c_str());

    AddFlag(MOTIONMASTER_FLAG_UPDATE);

    MovementGenerator* top = GetCurrentMovementGenerator();
    if (HasFlag(MOTIONMASTER_FLAG_STATIC_INITIALIZATION_PENDING) && IsStatic(top))
    {
        RemoveFlag(MOTIONMASTER_FLAG_STATIC_INITIALIZATION_PENDING);
        top->Initialize(_owner);
    }
    if (top->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING))
        top->Initialize(_owner);
    if (top->HasFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED))
        top->Reset(_owner);

    ASSERT(!top->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED), "MotionMaster:Update: update called on an uninitialized top! (%s) (type: %u, flags: %u)", _owner->GetGUID().ToString().c_str(), top->GetMovementGeneratorType(), top->Flags);

    if (!top->Update(_owner, diff))
    {
        ASSERT(top == GetCurrentMovementGenerator(), "MotionMaster::Update: top was modified while updating! (%s)", _owner->GetGUID().ToString().c_str());

        // Since all the actions that modify any slot are delayed, this movement is guaranteed to be top
        Pop(true, true); // Natural, and only, call to MovementInform
    }

    RemoveFlag(MOTIONMASTER_FLAG_UPDATE);

    ResolveDelayedActions();
}

void MotionMaster::Add(MovementGenerator* movement, MovementSlot slot/* = MOTION_SLOT_ACTIVE*/)
{
    if (!movement)
        return;

    if (IsInvalidMovementSlot(slot))
    {
        delete movement;
        return;
    }

    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this, movement, slot]()
        {
            Add(movement, slot);
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_ADD);
    }
    else
        DirectAdd(movement, slot);
}

void MotionMaster::Remove(MovementGenerator* movement, MovementSlot slot/* = MOTION_SLOT_ACTIVE*/)
{
    if (!movement || IsInvalidMovementSlot(slot))
        return;

    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this, movement, slot]()
        {
            Remove(movement, slot);
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_REMOVE);
        return;
    }

    if (Empty())
        return;

    switch (slot)
    {
        case MOTION_SLOT_DEFAULT:
            if (_defaultGenerator && _defaultGenerator.get() == movement)
                DirectClearDefault();
            break;
        case MOTION_SLOT_ACTIVE:
            if (!_generators.empty())
            {
                auto bounds = _generators.equal_range(movement);
                auto itr = std::find(bounds.first, bounds.second, movement);
                if (itr != _generators.end())
                    Remove(itr, GetCurrentMovementGenerator() == *itr, false);
            }
            break;
        default:
            break;
    }
}

void MotionMaster::Remove(MovementGeneratorType type, MovementSlot slot/* = MOTION_SLOT_ACTIVE*/)
{
    if (IsInvalidMovementGeneratorType(type) || IsInvalidMovementSlot(slot))
        return;

    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this, type, slot]()
        {
            Remove(type, slot);
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_REMOVE_TYPE);
        return;
    }

    if (Empty())
        return;

    switch (slot)
    {
        case MOTION_SLOT_DEFAULT:
            if (_defaultGenerator && _defaultGenerator->GetMovementGeneratorType() == type)
                DirectClearDefault();
            break;
        case MOTION_SLOT_ACTIVE:
            if (!_generators.empty())
            {
                auto itr = std::find_if(_generators.begin(), _generators.end(), [type](MovementGenerator const* a) -> bool
                {
                    return a->GetMovementGeneratorType() == type;
                });

                if (itr != _generators.end())
                    Remove(itr, GetCurrentMovementGenerator() == *itr, false);
            }
            break;
        default:
            break;
    }
}

void MotionMaster::Clear()
{
    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this]()
        {
            Clear();
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_CLEAR);
        return;
    }

    if (!Empty())
        DirectClear();
}

void MotionMaster::Clear(MovementSlot slot)
{
    if (IsInvalidMovementSlot(slot))
        return;

    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this, slot]()
        {
            Clear(slot);
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_CLEAR_SLOT);
        return;
    }

    if (Empty())
        return;

    switch (slot)
    {
        case MOTION_SLOT_DEFAULT:
            DirectClearDefault();
            break;
        case MOTION_SLOT_ACTIVE:
            DirectClear();
            break;
        default:
            break;
    }
}

void MotionMaster::Clear(MovementGeneratorMode mode)
{
    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this, mode]()
        {
            Clear(mode);
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_CLEAR_MODE);
        return;
    }

    if (Empty())
        return;

    std::function<bool(MovementGenerator*)> criteria = [mode](MovementGenerator* a) -> bool
    {
        return a->Mode == mode;
    };
    DirectClear(criteria);
}

void MotionMaster::Clear(MovementGeneratorPriority priority)
{
    if (HasFlag(MOTIONMASTER_FLAG_DELAYED))
    {
        DelayedActionDefine action = [this, priority]()
        {
            Clear(priority);
        };
        _delayedActions.emplace_back(std::move(action), MOTIONMASTER_DELAYED_CLEAR_PRIORITY);
        return;
    }

    if (Empty())
        return;

    std::function<bool(MovementGenerator*)> criteria = [priority](MovementGenerator* a) -> bool
    {
        return a->Priority == priority;
    };
    DirectClear(criteria);
}

void MotionMaster::PropagateSpeedChange()
{
    if (Empty())
        return;

    MovementGenerator* movement = GetCurrentMovementGenerator();
    if (!movement)
        return;

    movement->UnitSpeedChanged();
}

bool MotionMaster::GetDestination(float &x, float &y, float &z)
{
    if (_owner->movespline->Finalized())
        return false;

    G3D::Vector3 const& dest = _owner->movespline->FinalDestination();
    x = dest.x;
    y = dest.y;
    z = dest.z;
    return true;
}

bool MotionMaster::StopOnDeath()
{
    if (MovementGenerator* movementGenerator = GetCurrentMovementGenerator())
        if (movementGenerator->HasFlag(MOVEMENTGENERATOR_FLAG_PERSIST_ON_DEATH))
            return false;

    if (_owner->IsInWorld())
    {
        // Only clear MotionMaster for entities that exists in world
        // Avoids crashes in the following conditions :
        //  * Using 'call pet' on dead pets
        //  * Using 'call stabled pet'
        //  * Logging in with dead pets
        Clear();
        MoveIdle();
    }

    _owner->StopMoving();

    return true;
}

void MotionMaster::MoveIdle()
{
    Add(GetIdleMovementGenerator(), MOTION_SLOT_DEFAULT);
}

void MotionMaster::MoveTargetedHome()
{
    Creature* owner = _owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTargetedHome: '{}', attempted to move towards target home.", _owner->GetGUID());
        return;
    }

    Clear();

    Unit* target = owner->GetCharmerOrOwner();
    if (!target)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTargetedHome: '{}', targeted home.", _owner->GetGUID());
        Add(new HomeMovementGenerator<Creature>());
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTargetedHome: '{}', starts following '{}'", _owner->GetGUID(), target->GetGUID());
        Add(new FollowMovementGenerator(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE, {}));
    }
}

void MotionMaster::MoveRandom(float wanderDistance /*= 0.0f*/, Optional<Milliseconds> duration /*= {}*/, MovementSlot slot /*= MOTION_SLOT_DEFAULT*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveRandom: '{}', started random movement (spawnDist: {})", _owner->GetGUID(), wanderDistance);
        Add(new RandomMovementGenerator<Creature>(wanderDistance, duration, std::move(scriptResult)), slot);
    }
    else if (scriptResult)
        scriptResult->SetResult(MovementStopReason::Interrupted);
}

void MotionMaster::MoveFollow(Unit* target, float dist, Optional<ChaseAngle> angle /*= {}*/, Optional<Milliseconds> duration /*= {}*/, bool ignoreTargetWalk /*= false*/, MovementSlot slot/* = MOTION_SLOT_ACTIVE*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    // Ignore movement request if target not exist
    if (!target || target == _owner)
    {
        if (scriptResult)
            scriptResult->SetResult(MovementStopReason::Interrupted);
        return;
    }

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFollow: '{}', starts following '{}'", _owner->GetGUID(), target->GetGUID());
    Add(new FollowMovementGenerator(target, dist, angle, duration, ignoreTargetWalk, std::move(scriptResult)), slot);
}

void MotionMaster::MoveChase(Unit* target, Optional<ChaseRange> dist, Optional<ChaseAngle> angle)
{
    // Ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveChase: '{}', starts chasing '{}'", _owner->GetGUID(), target->GetGUID());
    Add(new ChaseMovementGenerator(target, dist, angle));
}

void MotionMaster::MoveConfused()
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveConfused: '{}', started confused movement.", _owner->GetGUID());
        Add(new ConfusedMovementGenerator<Player>());
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveConfused: '{}', started confused movement.", _owner->GetGUID());
        Add(new ConfusedMovementGenerator<Creature>());
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, Milliseconds time /*= 0ms*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    if (!enemy)
    {
        if (scriptResult)
            scriptResult->SetResult(MovementStopReason::Interrupted);
        return;
    }

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFleeing: '{}', flees from '{}' (time: {}ms)", _owner->GetGUID(), enemy->GetGUID(), time.count());
    if (_owner->GetTypeId() == TYPEID_UNIT && time > 0ms)
        Add(new TimedFleeingMovementGenerator(enemy->GetGUID(), time, std::move(scriptResult)));
    else
        Add(new FleeingMovementGenerator(enemy->GetGUID(), std::move(scriptResult)));
}

void MotionMaster::MovePoint(uint32 id, Position const& pos, bool generatePath/* = true*/, Optional<float> finalOrient/* = {}*/, Optional<float> speed /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/, Optional<float> closeEnoughDistance /*= {}*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    MovePoint(id, pos.m_positionX, pos.m_positionY, pos.m_positionZ, generatePath, finalOrient, speed, speedSelectionMode, closeEnoughDistance, std::move(scriptResult));
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z, bool generatePath /*= true*/, Optional<float> finalOrient /*= {}*/, Optional<float> speed /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/, Optional<float> closeEnoughDistance /*= {}*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePoint: '{}', targeted point Id: {} (X: {}, Y: {}, Z: {})", _owner->GetGUID(), id, x, y, z);
    Add(new PointMovementGenerator(id, x, y, z, generatePath, speed, finalOrient, nullptr, nullptr, speedSelectionMode, closeEnoughDistance, std::move(scriptResult)));
}

void MotionMaster::MoveCloserAndStop(uint32 id, Unit* target, float distance)
{
    float distanceToTravel = _owner->GetExactDist2d(target) - distance;
    if (distanceToTravel > 0.0f)
    {
        float angle = _owner->GetAbsoluteAngle(target);
        float destx = _owner->GetPositionX() + distanceToTravel * std::cos(angle);
        float desty = _owner->GetPositionY() + distanceToTravel * std::sin(angle);
        MovePoint(id, destx, desty, target->GetPositionZ());
    }
    else
    {
        // We are already close enough. We just need to turn toward the target without changing position.
        std::function<void(Movement::MoveSplineInit&)> initializer = [=, this, target = target->GetGUID()](Movement::MoveSplineInit& init)
        {
            init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
            if (Unit const* refreshedTarget = ObjectAccessor::GetUnit(*_owner, target))
                init.SetFacing(refreshedTarget);
        };
        Add(new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, id));
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos, Optional<int32> tierTransitionId /*= {}*/, Optional<float> velocity /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveLand: '{}', landing point Id: {} (X: {}, Y: {}, Z: {})", _owner->GetGUID(), id, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

    std::function<void(Movement::MoveSplineInit&)> initializer = [=](Movement::MoveSplineInit& init)
    {
        init.MoveTo(PositionToVector3(pos), false);
        init.SetAnimation(AnimTier::Ground, tierTransitionId.value_or(1));
        init.SetFly(); // ensure smooth animation even if gravity is enabled before calling this function
        init.SetSmooth();
        switch (speedSelectionMode)
        {
            case MovementWalkRunSpeedSelectionMode::ForceRun:
                init.SetWalk(false);
                break;
            case MovementWalkRunSpeedSelectionMode::ForceWalk:
                init.SetWalk(true);
                break;
            case MovementWalkRunSpeedSelectionMode::Default:
            default:
                break;
        }
        if (velocity)
            init.SetVelocity(*velocity);
    };
    Add(new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, id, { .ScriptResult = std::move(scriptResult) }));
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos, Optional<int32> tierTransitionId /*= {}*/, Optional<float> velocity /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTakeoff: '{}', landing point Id: {} (X: {}, Y: {}, Z: {})", _owner->GetGUID(), id, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

    std::function<void(Movement::MoveSplineInit&)> initializer = [=](Movement::MoveSplineInit& init)
    {
        init.MoveTo(PositionToVector3(pos), false);
        init.SetAnimation(AnimTier::Fly, tierTransitionId.value_or(2));
        init.SetFly(); // ensure smooth animation even if gravity is disabled after calling this function
        switch (speedSelectionMode)
        {
            case MovementWalkRunSpeedSelectionMode::ForceRun:
                init.SetWalk(false);
                break;
            case MovementWalkRunSpeedSelectionMode::ForceWalk:
                init.SetWalk(true);
                break;
            case MovementWalkRunSpeedSelectionMode::Default:
            default:
                break;
        }
        if (velocity)
            init.SetVelocity(*velocity);
    };
    Add(new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, id, { .ScriptResult = std::move(scriptResult) }));
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed /*= SPEED_CHARGE*/, uint32 id /*= EVENT_CHARGE*/, bool generatePath /*= false*/,
    Unit const* target /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
/*
    if (_slot[MOTION_SLOT_CONTROLLED] && _slot[MOTION_SLOT_CONTROLLED]->GetMovementGeneratorType() != DISTRACT_MOTION_TYPE)
        return;
*/
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveCharge: '{}', charging point Id: {} (X: {}, Y: {}, Z: {})", _owner->GetGUID(), id, x, y, z);
    PointMovementGenerator* movement = new PointMovementGenerator(id, x, y, z, generatePath, speed, {}, target, spellEffectExtraData);
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    movement->BaseUnitState = UNIT_STATE_CHARGING;
    Add(movement);
}

void MotionMaster::MoveCharge(PathGenerator const& path, float speed /*= SPEED_CHARGE*/, Unit const* target /*= nullptr*/,
    Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    G3D::Vector3 dest = path.GetActualEndPosition();

    MoveCharge(dest.x, dest.y, dest.z, speed, EVENT_CHARGE_PREPATH);

    // If this is ever changed to not happen immediately then all spell effect handlers that use this must be updated

    // Charge movement is not started when using EVENT_CHARGE_PREPATH
    Movement::MoveSplineInit init(_owner);
    init.MovebyPath(path.GetPath());
    init.SetVelocity(speed);
    if (target)
        init.SetFacing(target);
    if (spellEffectExtraData)
        init.SetSpellEffectExtraData(*spellEffectExtraData);
    init.Launch();
}

void MotionMaster::MoveKnockbackFrom(Position const& origin, float speedXY, float speedZ, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/)
{
    // This function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    if (speedXY < 0.01f)
        return;

    Position dest = _owner->GetPosition();
    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    // Use a mmap raycast to get a valid destination.
    _owner->MovePositionToFirstCollision(dest, dist, _owner->GetRelativeAngle(origin) + float(M_PI));

    std::function<void(Movement::MoveSplineInit&)> initializer = [=, effect = (spellEffectExtraData ? Optional<Movement::SpellEffectExtraData>(*spellEffectExtraData) : Optional<Movement::SpellEffectExtraData>())](Movement::MoveSplineInit& init)
    {
        init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), false);
        init.SetParabolic(max_height, 0);
        init.SetOrientationFixed(true);
        init.SetVelocity(speedXY);
        if (effect)
            init.SetSpellEffectExtraData(*effect);
    };

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, 0);
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    movement->AddFlag(MOVEMENTGENERATOR_FLAG_PERSIST_ON_DEATH);
    Add(movement);
}

void MotionMaster::MoveJumpTo(float angle, float speedXY, float speedZ)
{
    // This function may make players fall below map
    if (_owner->GetTypeId() == TYPEID_PLAYER)
        return;

    float x, y, z = _owner->GetPositionZ();

    float moveTimeHalf = speedZ / Movement::gravity;
    float dist = 2 * moveTimeHalf * speedXY;

    _owner->GetNearPoint2D(nullptr, x, y, dist, _owner->GetOrientation() + angle);
    _owner->UpdateAllowedPositionZ(x, y, z);

    MoveJump(x, y, z, speedXY, speedZ);
}

void MotionMaster::MoveJump(Position const& pos, float speedXY, float speedZ, uint32 id /*= EVENT_JUMP*/, MovementFacingTarget const& facing /*= {}*/,
    bool orientationFixed /*= false*/, JumpArrivalCastArgs const* arrivalCast /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    MoveJump(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), speedXY, speedZ, id, facing, orientationFixed, arrivalCast,
        spellEffectExtraData, std::move(scriptResult));
}

void MotionMaster::MoveJump(float x, float y, float z, float speedXY, float speedZ, uint32 id /*= EVENT_JUMP*/, MovementFacingTarget const& facing /* = {}*/,
    bool orientationFixed /*= false*/, JumpArrivalCastArgs const* arrivalCast /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveJump: '{}', jumps to point Id: {} (X: {}, Y: {}, Z: {})", _owner->GetGUID(), id, x, y, z);
    if (speedXY < 0.01f)
    {
        if (scriptResult)
            scriptResult->SetResult(MovementStopReason::Interrupted);
        return;
    }

    float moveTimeHalf = speedZ / Movement::gravity;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    std::function<void(Movement::MoveSplineInit&)> initializer = [=, effect = (spellEffectExtraData ? Optional<Movement::SpellEffectExtraData>(*spellEffectExtraData) : Optional<Movement::SpellEffectExtraData>())](Movement::MoveSplineInit& init)
    {
        init.MoveTo(x, y, z, false);
        init.SetParabolic(max_height, 0);
        init.SetVelocity(speedXY);
        std::visit(Movement::MoveSplineInitFacingVisitor(init), facing);
        init.SetJumpOrientationFixed(orientationFixed);
        if (effect)
            init.SetSpellEffectExtraData(*effect);
    };

    uint32 arrivalSpellId = 0;
    ObjectGuid arrivalSpellTargetGuid;
    if (arrivalCast)
    {
        arrivalSpellId = arrivalCast->SpellId;
        arrivalSpellTargetGuid = arrivalCast->Target;
    }

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, id,
        { .ArrivalSpellId = arrivalSpellId, .ArrivalSpellTarget = arrivalSpellTargetGuid, .ScriptResult = std::move(scriptResult) });
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    movement->BaseUnitState = UNIT_STATE_JUMPING;
    Add(movement);
}

void MotionMaster::MoveJumpWithGravity(Position const& pos, float speedXY, float gravity, uint32 id/* = EVENT_JUMP*/, MovementFacingTarget const& facing/* = {}*/,
    bool orientationFixed /*= false*/, JumpArrivalCastArgs const* arrivalCast /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveJumpWithGravity: '{}', jumps to point Id: {} ({})", _owner->GetGUID(), id, pos.ToString());
    if (speedXY < 0.01f)
    {
        if (scriptResult)
            scriptResult->SetResult(MovementStopReason::Interrupted);
        return;
    }

    std::function<void(Movement::MoveSplineInit&)> initializer = [=, effect = (spellEffectExtraData ? Optional<Movement::SpellEffectExtraData>(*spellEffectExtraData) : Optional<Movement::SpellEffectExtraData>())](Movement::MoveSplineInit& init)
    {
        init.MoveTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), false);
        init.SetParabolicVerticalAcceleration(gravity, 0);
        init.SetUncompressed();
        init.SetVelocity(speedXY);
        init.SetUnlimitedSpeed();
        std::visit(Movement::MoveSplineInitFacingVisitor(init), facing);
        init.SetJumpOrientationFixed(orientationFixed);
        if (effect)
            init.SetSpellEffectExtraData(*effect);
    };

    uint32 arrivalSpellId = 0;
    ObjectGuid arrivalSpellTargetGuid;
    if (arrivalCast)
    {
        arrivalSpellId = arrivalCast->SpellId;
        arrivalSpellTargetGuid = arrivalCast->Target;
    }

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, id,
        { .ArrivalSpellId = arrivalSpellId, .ArrivalSpellTarget = arrivalSpellTargetGuid, .ScriptResult = std::move(scriptResult) });
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    movement->BaseUnitState = UNIT_STATE_JUMPING;
    movement->AddFlag(MOVEMENTGENERATOR_FLAG_PERSIST_ON_DEATH);
    Add(movement);
}

void MotionMaster::MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount,
    Optional<Milliseconds> duration /*= {}*/, Optional<float> speed /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    std::function<void(Movement::MoveSplineInit&)> initializer = [=, this](Movement::MoveSplineInit& init)
    {
        float step = 2 * float(M_PI) / stepCount * (clockwise ? -1.0f : 1.0f);
        Position const& pos = { x, y, z, 0.0f };
        float angle = pos.GetAbsoluteAngle(_owner->GetPositionX(), _owner->GetPositionY());

        // add the owner's current position as starting point as it gets removed after entering the cycle
        init.Path().emplace_back(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());

        for (uint8 i = 0; i < stepCount; angle += step, ++i)
        {
            G3D::Vector3& point = init.Path().emplace_back();
            point.x = x + radius * cosf(angle);
            point.y = y + radius * sinf(angle);

            if (_owner->IsFlying())
                point.z = z;
            else
                point.z = _owner->GetMapHeight(point.x, point.y, z) + _owner->GetHoverOffset();
        }

        init.SetCyclic();
        if (_owner->IsFlying())
        {
            init.SetFly();
            init.SetAnimation(AnimTier::Hover);
        }
        else
            init.SetWalk(true);

        switch (speedSelectionMode)
        {
            case MovementWalkRunSpeedSelectionMode::ForceRun:
                init.SetWalk(false);
                break;
            case MovementWalkRunSpeedSelectionMode::ForceWalk:
                init.SetWalk(true);
                break;
            case MovementWalkRunSpeedSelectionMode::Default:
            default:
                break;
        }
        if (speed)
            init.SetVelocity(*speed);
    };

    Add(new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, 0, { .Duration = duration, .ScriptResult = std::move(scriptResult) }));
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, uint16 dbChainId, bool walk)
{
    Creature* owner = _owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveAlongSplineChain: '{}', tried to walk along DB spline chain. Ignoring.", _owner->GetGUID());
        return;
    }
    std::vector<SplineChainLink> const* chain = sScriptSystemMgr->GetSplineChain(owner, dbChainId);
    if (!chain)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveAlongSplineChain: '{}', tried to walk along non-existing spline chain with DB Id: {}.", _owner->GetGUID(), dbChainId);
        return;
    }
    MoveAlongSplineChain(pointId, *chain, walk);
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, std::vector<SplineChainLink> const& chain, bool walk)
{
    Add(new SplineChainMovementGenerator(pointId, chain, walk));
}

void MotionMaster::ResumeSplineChain(SplineChainResumeInfo const& info)
{
    if (info.Empty())
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::ResumeSplineChain: '{}', tried to resume a spline chain from empty info.", _owner->GetGUID());
        return;
    }
    Add(new SplineChainMovementGenerator(info));
}

void MotionMaster::MoveFall(uint32 id /*= 0*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    auto setterScopeExit = Trinity::make_unique_ptr_with_deleter(&scriptResult, [](Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>* opt)
    {
        if (opt->has_value())
            (*opt)->SetResult(MovementStopReason::Interrupted);
    });

    // Use larger distance for vmap height search than in most other cases
    float tz = _owner->GetMapHeight(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ(), true, MAX_FALL_DISTANCE);
    if (tz <= INVALID_HEIGHT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFall: '{}', unable to retrieve a proper height at map Id: {} (X: {}, Y: {}, Z: {})",
            _owner->GetGUID(), _owner->GetMap()->GetId(), _owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
        return;
    }

    // Abort too if the ground is very near
    if (std::fabs(_owner->GetPositionZ() - tz) < 0.1f)
        return;

    // rooted units don't move (also setting falling+root flag causes client freezes)
    if (_owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
        return;

    _owner->SetFall(true);

    // Don't run spline movement for players
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        _owner->ToPlayer()->SetFallInformation(0, _owner->GetPositionZ());
        return;
    }

    std::function<void(Movement::MoveSplineInit&)> initializer = [this, tz](Movement::MoveSplineInit& init)
    {
        init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), tz + _owner->GetHoverOffset(), false);
        init.SetFall();
    };

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(initializer), EFFECT_MOTION_TYPE, id, { .ScriptResult = std::move(*setterScopeExit.release()) });
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    Add(movement);
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (Creature* creature = _owner->ToCreature())
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveSeekAssistance: '{}', seeks assistance (X: {}, Y: {}, Z: {})", creature->GetGUID(), x, y, z);
        creature->AttackStop();
        creature->CastStop();
        creature->DoNotReacquireSpellFocusTarget();
        creature->SetReactState(REACT_PASSIVE);
        Add(new AssistanceMovementGenerator(EVENT_ASSIST_MOVE, x, y, z));
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveSeekAssistance: '{}', attempted to seek assistance.", _owner->GetGUID());
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveSeekAssistanceDistract: '{}', is distracted after assistance call (Time: {})", _owner->GetGUID(), time);
        Add(new AssistanceDistractMovementGenerator(time, _owner->GetOrientation()));
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveSeekAssistanceDistract: '{}', attempted to call distract assistance.", _owner->GetGUID());
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode, Optional<float> speed /*= {}*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '{}', taxi to path Id: {} (node {})", _owner->GetGUID(), path, pathnode);

            // Only one FLIGHT_MOTION_TYPE is allowed
            bool hasExisting = HasMovementGenerator([](MovementGenerator const* gen) { return gen->GetMovementGeneratorType() == FLIGHT_MOTION_TYPE; });
            ASSERT(!hasExisting, "Duplicate flight path movement generator");

            FlightPathMovementGenerator* movement = new FlightPathMovementGenerator(speed, std::move(scriptResult));
            movement->LoadPath(_owner->ToPlayer(), pathnode);
            Add(movement);
        }
        else
            TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '{}', attempted taxi to non-existing path Id: {} (node: {})", _owner->GetGUID(), path, pathnode);
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '{}', attempted taxi to path Id: {} (node: {})", _owner->GetGUID(), path, pathnode);
}

void MotionMaster::MoveDistract(uint32 timer, float orientation)
{
/*
    if (_slot[MOTION_SLOT_CONTROLLED])
        return;
*/
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveDistract: '{}', distracted (timer: {}, orientation: {})", _owner->GetGUID(), timer, orientation);
    Add(new DistractMovementGenerator(timer, orientation));
}

void MotionMaster::MovePath(uint32 pathId, bool repeatable, Optional<Milliseconds> duration /*= {}*/, Optional<float> speed /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd /*= {}*/,
    Optional<float> wanderDistanceAtPathEnds /*= {}*/, Optional<bool> followPathBackwardsFromEndToStart /*= {}*/,
    Optional<bool> exactSplinePath /*= {}*/, bool generatePath /*= true*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    if (!pathId)
    {
        if (scriptResult)
            scriptResult->SetResult(MovementStopReason::Interrupted);
        return;
    }

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePath: '{}', starts moving over path Id: {} (repeatable: {})",
        _owner->GetGUID(), pathId, repeatable ? "YES" : "NO");
    Add(new WaypointMovementGenerator<Creature>(pathId, repeatable, duration, speed, speedSelectionMode, waitTimeRangeAtPathEnd,
        wanderDistanceAtPathEnds, followPathBackwardsFromEndToStart, exactSplinePath, generatePath, std::move(scriptResult)), MOTION_SLOT_DEFAULT);
}

void MotionMaster::MovePath(WaypointPath const& path, bool repeatable, Optional<Milliseconds> duration /*= {}*/, Optional<float> speed /*= {}*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd /*= {}*/,
    Optional<float> wanderDistanceAtPathEnds /*= {}*/, Optional<bool> followPathBackwardsFromEndToStart /*= {}*/,
    Optional<bool> exactSplinePath /*= {}*/, bool generatePath /*= true*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePath: '{}', starts moving over path Id: {} (repeatable: {})",
        _owner->GetGUID(), path.Id, repeatable ? "YES" : "NO");
    Add(new WaypointMovementGenerator<Creature>(path, repeatable, duration, speed, speedSelectionMode, waitTimeRangeAtPathEnd,
        wanderDistanceAtPathEnds, followPathBackwardsFromEndToStart, exactSplinePath, generatePath, std::move(scriptResult)), MOTION_SLOT_DEFAULT);
}

void MotionMaster::MoveRotate(uint32 id, RotateDirection direction, Optional<Milliseconds> time /*= {}*/,
    Optional<float> turnSpeed /*= {}*/, Optional<float> totalTurnAngle /*= {}*/,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveRotate: '{}', starts rotate (time: {}ms, turnSpeed: {}, totalTurnAngle: {}, direction: {})",
        _owner->GetGUID(), time.value_or(0ms).count(), turnSpeed, totalTurnAngle, direction);

    Add(new RotateMovementGenerator(id, direction, time, turnSpeed, totalTurnAngle, std::move(scriptResult)));
}

void MotionMaster::MoveFormation(Unit* leader, float range, float angle, uint32 point1, uint32 point2)
{
    if (_owner->GetTypeId() == TYPEID_UNIT && leader)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFormation: '{}', started to move in a formation with leader {}", _owner->GetGUID(), leader->GetGUID());
        Add(new FormationMovementGenerator(leader, range, angle, point1, point2), MOTION_SLOT_DEFAULT);
    }
}

void MotionMaster::LaunchMoveSpline(std::function<void(Movement::MoveSplineInit& init)>&& initializer, uint32 id/*= 0*/, MovementGeneratorPriority priority/* = MOTION_PRIORITY_NORMAL*/, MovementGeneratorType type/*= EFFECT_MOTION_TYPE*/)
{
    if (IsInvalidMovementGeneratorType(type))
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::LaunchMoveSpline: '{}', tried to launch a spline with an invalid MovementGeneratorType: {} (Id: {}, Priority: {})", _owner->GetGUID(), type, id, priority);
        return;
    }

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::LaunchMoveSpline: '{}', initiates spline Id: {} (Type: {}, Priority: {})", _owner->GetGUID(), id, type, priority);

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(initializer), type, id);
    movement->Priority = priority;
    Add(movement);
}

void MotionMaster::CalculateJumpSpeeds(float dist, UnitMoveType moveType, float speedMultiplier, float minHeight, float maxHeight, float& speedXY, float& speedZ) const
{
    float baseSpeed = _owner->IsControlledByPlayer() ? playerBaseMoveSpeed[moveType] : baseMoveSpeed[moveType];
    if (Creature* creature = _owner->ToCreature())
        baseSpeed *= creature->GetCreatureTemplate()->speed_run;

    speedXY = std::min(baseSpeed * 3.0f * speedMultiplier, std::max(28.0f, _owner->GetSpeed(moveType) * 4.0f));

    float duration = dist / speedXY;
    float durationSqr = duration * duration;
    float height;
    if (durationSqr < minHeight * 8 / Movement::gravity)
        height = minHeight;
    else if (durationSqr > maxHeight * 8 / Movement::gravity)
        height = maxHeight;
    else
        height = Movement::gravity * durationSqr / 8;

    speedZ = std::sqrt(2 * Movement::gravity * height);
}

/******************** Private methods ********************/

void MotionMaster::ResolveDelayedActions()
{
    while (!_delayedActions.empty())
    {
        _delayedActions.front().Resolve();
        _delayedActions.pop_front();
    }
}

void MotionMaster::Remove(MotionMasterContainer::iterator iterator, bool active, bool movementInform)
{
    MovementGenerator* pointer = *iterator;
    _generators.erase(iterator);
    Delete(pointer, active, movementInform);
}

void MotionMaster::Pop(bool active, bool movementInform)
{
    if (!_generators.empty())
        Remove(_generators.begin(), active, movementInform);
}

void MotionMaster::DirectInitialize()
{
    // Clear ALL movement generators (including default)
    DirectClearDefault();
    DirectClear();

    InitializeDefault();
}

void MotionMaster::DirectClear()
{
    // First delete Top
    if (!_generators.empty())
        Pop(true, false);

    // Then the rest
    while (!_generators.empty())
        Pop(false, false);

    // Make sure the storage is empty
    ClearBaseUnitStates();
}

void MotionMaster::DirectClearDefault()
{
    if (_defaultGenerator)
        DeleteDefault(_generators.empty(), false);
}

void MotionMaster::DirectClear(std::function<bool(MovementGenerator*)> const& filter)
{
    if (_generators.empty())
        return;

    MovementGenerator const* top = GetCurrentMovementGenerator();
    for (auto itr = _generators.begin(); itr != _generators.end();)
    {
        if (filter(*itr))
        {
            MovementGenerator* movement = *itr;
            itr = _generators.erase(itr);
            Delete(movement, movement == top, false);
        }
        else
            ++itr;
    }
}

void MotionMaster::DirectAdd(MovementGenerator* movement, MovementSlot slot/* = MOTION_SLOT_ACTIVE*/)
{
/*
    if (MovementGenerator* curr = _slot[slot])
    {
        _slot[slot] = nullptr; // in case a new one is generated in this slot during directdelete
        if (_top == slot && (_cleanFlag & MOTIONMMASTER_CLEANFLAG_UPDATE))
            DelayedDelete(curr);
        else
            DirectDelete(curr);
    }
    else if (_top < slot)
    {
        _top = slot;
    }

    _slot[slot] = m;
    if (_top > slot)
        _initialize[slot] = true;
    else
    {
        _initialize[slot] = false;
        m->Initialize(_owner);
    }
*/

    /*
     * NOTE: This mimics old behaviour: only one MOTION_SLOT_IDLE, MOTION_SLOT_ACTIVE, MOTION_SLOT_CONTROLLED
     * On future changes support for multiple will be added
     */

    switch (slot)
    {
        case MOTION_SLOT_DEFAULT:
            if (_defaultGenerator)
                _defaultGenerator->Finalize(_owner, _generators.empty(), false);

            _defaultGenerator = MovementGeneratorPointer(movement);
            if (IsStatic(movement))
                AddFlag(MOTIONMASTER_FLAG_STATIC_INITIALIZATION_PENDING);
            break;
        case MOTION_SLOT_ACTIVE:
            if (!_generators.empty())
            {
                if (movement->Priority >= (*_generators.begin())->Priority)
                {
                    auto itr = _generators.begin();
                    if (movement->Priority == (*itr)->Priority)
                        Remove(itr, true, false);
                    else
                        (*itr)->Deactivate(_owner);
                }
                else
                {
                    auto itr = std::find_if(_generators.begin(), _generators.end(), [movement](MovementGenerator const* a) -> bool
                    {
                        return a->Priority == movement->Priority;
                    });

                    if (itr != _generators.end())
                        Remove(itr, false, false);
                }
            }
            else
                _defaultGenerator->Deactivate(_owner);

            _generators.emplace(movement);
            AddBaseUnitState(movement);
            break;
        default:
            break;
    }
}

void MotionMaster::Delete(MovementGenerator* movement, bool active, bool movementInform)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::Delete: deleting generator (Priority: {}, Flags: {}, BaseUnitState: {}, Type: {}), owner: '{}'",
        movement->Priority, movement->Flags, movement->BaseUnitState, movement->GetMovementGeneratorType(), _owner->GetGUID());

    movement->Finalize(_owner, active, movementInform);
    ClearBaseUnitState(movement);
    MovementGeneratorPointerDeleter(movement);
}

void MotionMaster::DeleteDefault(bool active, bool movementInform)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::DeleteDefault: deleting generator (Priority: {}, Flags: {}, BaseUnitState: {}, Type: {}), owner: '{}'",
        _defaultGenerator->Priority, _defaultGenerator->Flags, _defaultGenerator->BaseUnitState, _defaultGenerator->GetMovementGeneratorType(), _owner->GetGUID());

    _defaultGenerator->Finalize(_owner, active, movementInform);
    _defaultGenerator = MovementGeneratorPointer(GetIdleMovementGenerator());
    AddFlag(MOTIONMASTER_FLAG_STATIC_INITIALIZATION_PENDING);
}

void MotionMaster::AddBaseUnitState(MovementGenerator const* movement)
{
    if (!movement || !movement->BaseUnitState)
        return;

    _baseUnitStatesMap.emplace(movement->BaseUnitState, movement);
    _owner->AddUnitState(movement->BaseUnitState);
}

void MotionMaster::ClearBaseUnitState(MovementGenerator const* movement)
{
    if (!movement || !movement->BaseUnitState)
        return;

    Trinity::Containers::MultimapErasePair(_baseUnitStatesMap, movement->BaseUnitState, movement);
    if (_baseUnitStatesMap.count(movement->BaseUnitState) == 0)
        _owner->ClearUnitState(movement->BaseUnitState);
}

void MotionMaster::ClearBaseUnitStates()
{
    uint32 unitState = 0;
    for (auto itr = _baseUnitStatesMap.begin(); itr != _baseUnitStatesMap.end(); ++itr)
        unitState |= itr->first;

    _owner->ClearUnitState(unitState);
    _baseUnitStatesMap.clear();
}
