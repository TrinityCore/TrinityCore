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
#include "DBCStores.h"
#include "Errors.h"
#include "G3DPosition.hpp"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
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
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTargetedHome: '%s', attempted to move towards target home.", _owner->GetGUID().ToString().c_str());
        return;
    }

    Clear();

    Unit* target = owner->GetCharmerOrOwner();
    if (!target)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTargetedHome: '%s', targeted home.", _owner->GetGUID().ToString().c_str());
        Add(new HomeMovementGenerator<Creature>());
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTargetedHome: '%s', starts following '%s'", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
        Add(new FollowMovementGenerator(target, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE));
    }
}

void MotionMaster::MoveRandom(float wanderDistance)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveRandom: '%s', started random movement (spawnDist: %f)", _owner->GetGUID().ToString().c_str(), wanderDistance);
        Add(new RandomMovementGenerator<Creature>(wanderDistance), MOTION_SLOT_DEFAULT);
    }
}

void MotionMaster::MoveFollow(Unit* target, float dist, ChaseAngle angle, MovementSlot slot/* = MOTION_SLOT_ACTIVE*/)
{
    // Ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFollow: '%s', starts following '%s'", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
    Add(new FollowMovementGenerator(target, dist, angle), slot);
}

void MotionMaster::MoveChase(Unit* target, Optional<ChaseRange> dist, Optional<ChaseAngle> angle)
{
    // Ignore movement request if target not exist
    if (!target || target == _owner)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveChase: '%s', starts chasing '%s'", _owner->GetGUID().ToString().c_str(), target->GetGUID().ToString().c_str());
    Add(new ChaseMovementGenerator(target, dist, angle));
}

void MotionMaster::MoveConfused()
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveConfused: '%s', started confused movement.", _owner->GetGUID().ToString().c_str());
        Add(new ConfusedMovementGenerator<Player>());
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveConfused: '%s', started confused movement.", _owner->GetGUID().ToString().c_str());
        Add(new ConfusedMovementGenerator<Creature>());
    }
}

void MotionMaster::MoveFleeing(Unit* enemy, uint32 time)
{
    if (!enemy)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFleeing: '%s', flees from '%s' (time: %u)", _owner->GetGUID().ToString().c_str(), enemy->GetGUID().ToString().c_str(), time);
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        if (time)
            Add(new TimedFleeingMovementGenerator(enemy->GetGUID(), time));
        else
            Add(new FleeingMovementGenerator<Creature>(enemy->GetGUID()));
    }
    else
        Add(new FleeingMovementGenerator<Player>(enemy->GetGUID()));
}

void MotionMaster::MovePoint(uint32 id, Position const& pos, bool generatePath/* = true*/, Optional<float> finalOrient/* = {}*/)
{
    MovePoint(id, pos.m_positionX, pos.m_positionY, pos.m_positionZ, generatePath, finalOrient);
}

void MotionMaster::MovePoint(uint32 id, float x, float y, float z, bool generatePath, Optional<float> finalOrient)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePoint: '%s', targeted point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Add(new PointMovementGenerator<Player>(id, x, y, z, generatePath, 0.0f, finalOrient));
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePoint: '%s', targeted point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        Add(new PointMovementGenerator<Creature>(id, x, y, z, generatePath, 0.0f, finalOrient));
    }
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
        Movement::MoveSplineInit init(_owner);
        init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
        init.SetFacing(target);
        Add(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id));
    }
}

void MotionMaster::MoveLand(uint32 id, Position const& pos, Optional<float> velocity /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveLand: '%s', landing point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(PositionToVector3(pos), false);
    init.SetAnimation(AnimationTier::Ground);
    if (velocity)
        init.SetVelocity(*velocity);
    Add(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id));
}

void MotionMaster::MoveTakeoff(uint32 id, Position const& pos, Optional<float> velocity /*= {}*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTakeoff: '%s', landing point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(PositionToVector3(pos), false);
    init.SetAnimation(AnimationTier::Hover);
    if (velocity)
        init.SetVelocity(*velocity);
    Add(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id));
}

void MotionMaster::MoveCharge(float x, float y, float z, float speed /*= SPEED_CHARGE*/, uint32 id /*= EVENT_CHARGE*/, bool generatePath /*= false*/)
{
/*
    if (_slot[MOTION_SLOT_CONTROLLED] && _slot[MOTION_SLOT_CONTROLLED]->GetMovementGeneratorType() != DISTRACT_MOTION_TYPE)
        return;
*/
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveCharge: '%s', charging point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        PointMovementGenerator<Player>* movement = new PointMovementGenerator<Player>(id, x, y, z, generatePath, speed);
        movement->Priority = MOTION_PRIORITY_HIGHEST;
        movement->BaseUnitState = UNIT_STATE_CHARGING;
        Add(movement);
    }
    else
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveCharge: '%s', charging point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
        PointMovementGenerator<Creature>* movement = new PointMovementGenerator<Creature>(id, x, y, z, generatePath, speed);
        movement->Priority = MOTION_PRIORITY_HIGHEST;
        movement->BaseUnitState = UNIT_STATE_CHARGING;
        Add(movement);
    }
}

void MotionMaster::MoveCharge(PathGenerator const& path, float speed /*= SPEED_CHARGE*/)
{
    G3D::Vector3 dest = path.GetActualEndPosition();

    MoveCharge(dest.x, dest.y, dest.z, speed, EVENT_CHARGE_PREPATH);

    // Charge movement is not started when using EVENT_CHARGE_PREPATH
    Movement::MoveSplineInit init(_owner);
    init.MovebyPath(path.GetPath());
    init.SetVelocity(speed);
    init.Launch();
}

void MotionMaster::MoveKnockbackFrom(float srcX, float srcY, float speedXY, float speedZ)
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
    _owner->MovePositionToFirstCollision(dest, dist, _owner->GetRelativeAngle(srcX, srcY) + float(M_PI));

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), false);
    init.SetParabolic(max_height, 0);
    init.SetOrientationFixed(true);
    init.SetVelocity(speedXY);

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, 0);
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

    MoveJump(x, y, z, 0.0f, speedXY, speedZ);
}

void MotionMaster::MoveJump(Position const& pos, float speedXY, float speedZ, uint32 id/* = EVENT_JUMP*/, bool hasOrientation/* = false*/)
{
    MoveJump(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), speedXY, speedZ, id, hasOrientation);
}

void MotionMaster::MoveJump(float x, float y, float z, float o, float speedXY, float speedZ, uint32 id, bool hasOrientation /* = false*/)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveJump: '%s', jumps to point Id: %u (X: %f, Y: %f, Z: %f)", _owner->GetGUID().ToString().c_str(), id, x, y, z);
    if (speedXY < 0.01f)
        return;

    float moveTimeHalf = speedZ / Movement::gravity;
    float max_height = -Movement::computeFallElevation(moveTimeHalf, false, -speedZ);

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(x, y, z, false);
    init.SetParabolic(max_height, 0);
    init.SetVelocity(speedXY);
    if (hasOrientation)
        init.SetFacing(o);

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id);
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    movement->BaseUnitState = UNIT_STATE_JUMPING;
    movement->AddFlag(MOVEMENTGENERATOR_FLAG_PERSIST_ON_DEATH);
    Add(movement);
}

void MotionMaster::MoveCirclePath(float x, float y, float z, float radius, bool clockwise, uint8 stepCount)
{
    float step = 2 * float(M_PI) / stepCount * (clockwise ? -1.0f : 1.0f);
    Position const& pos = { x, y, z, 0.0f };
    float angle = pos.GetAbsoluteAngle(_owner->GetPositionX(), _owner->GetPositionY());

    Movement::MoveSplineInit init(_owner);

    // add the owner's current position as starting point as it gets removed after entering the cycle
    init.Path().push_back(G3D::Vector3(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ()));

    for (uint8 i = 0; i < stepCount; angle += step, ++i)
    {
        G3D::Vector3 point;
        point.x = x + radius * cosf(angle);
        point.y = y + radius * sinf(angle);

        if (_owner->IsFlying())
            point.z = z;
        else
            point.z = _owner->GetMapHeight(point.x, point.y, z) + _owner->GetHoverOffset();

        init.Path().push_back(point);
    }

    if (_owner->IsFlying())
    {
        init.SetFly();
        init.SetCyclic();
        init.SetAnimation(AnimationTier::Hover);
    }
    else
    {
        init.SetWalk(true);
        init.SetCyclic();
    }

    Add(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, 0));
}

void MotionMaster::MoveSmoothPath(uint32 pointId, Position const* pathPoints, size_t pathSize, bool walk)
{
    Movement::MoveSplineInit init(_owner);
    Movement::PointsArray path;
    path.reserve(pathSize);
    std::transform(pathPoints, pathPoints + pathSize, std::back_inserter(path), [](Position const& point)
    {
        return G3D::Vector3(point.GetPositionX(), point.GetPositionY(), point.GetPositionZ());
    });

    init.MovebyPath(path);
    init.SetSmooth();
    init.SetWalk(walk);

    // This code is not correct
    // GenericMovementGenerator does not affect UNIT_STATE_ROAMING_MOVE
    // need to call PointMovementGenerator with various pointIds
    Add(new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, pointId));
}

void MotionMaster::MoveAlongSplineChain(uint32 pointId, uint16 dbChainId, bool walk)
{
    Creature* owner = _owner->ToCreature();
    if (!owner)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveAlongSplineChain: '%s', tried to walk along DB spline chain. Ignoring.", _owner->GetGUID().ToString().c_str());
        return;
    }
    std::vector<SplineChainLink> const* chain = sScriptSystemMgr->GetSplineChain(owner, dbChainId);
    if (!chain)
    {
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveAlongSplineChain: '%s', tried to walk along non-existing spline chain with DB Id: %u.", _owner->GetGUID().ToString().c_str(), dbChainId);
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
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::ResumeSplineChain: '%s', tried to resume a spline chain from empty info.", _owner->GetGUID().ToString().c_str());
        return;
    }
    Add(new SplineChainMovementGenerator(info));
}

void MotionMaster::MoveFall(uint32 id/* = 0*/)
{
    // Use larger distance for vmap height search than in most other cases
    float tz = _owner->GetMapHeight(_owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ(), true, MAX_FALL_DISTANCE);
    if (tz <= INVALID_HEIGHT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFall: '%s', unable to retrieve a proper height at map Id: %u (X: %f, Y: %f, Z: %f)",
            _owner->GetGUID().ToString().c_str(), _owner->GetMap()->GetId(), _owner->GetPositionX(), _owner->GetPositionY(), _owner->GetPositionZ());
        return;
    }

    // Abort too if the ground is very near
    if (std::fabs(_owner->GetPositionZ() - tz) < 0.1f)
        return;

    // rooted units don't move (also setting falling+root flag causes client freezes)
    if (_owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
        return;

    _owner->AddUnitMovementFlag(MOVEMENTFLAG_FALLING);
    _owner->m_movementInfo.SetFallTime(0);

    // Don't run spline movement for players
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        _owner->ToPlayer()->SetFallInformation(0, _owner->GetPositionZ());
        return;
    }

    Movement::MoveSplineInit init(_owner);
    init.MoveTo(_owner->GetPositionX(), _owner->GetPositionY(), tz + _owner->GetHoverOffset(), false);
    init.SetFall();

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(init), EFFECT_MOTION_TYPE, id);
    movement->Priority = MOTION_PRIORITY_HIGHEST;
    Add(movement);
}

void MotionMaster::MoveSeekAssistance(float x, float y, float z)
{
    if (Creature* creature = _owner->ToCreature())
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveSeekAssistance: '%s', seeks assistance (X: %f, Y: %f, Z: %f)", creature->GetGUID().ToString().c_str(), x, y, z);
        creature->AttackStop();
        creature->CastStop();
        creature->DoNotReacquireSpellFocusTarget();
        creature->SetReactState(REACT_PASSIVE);
        Add(new AssistanceMovementGenerator(EVENT_ASSIST_MOVE, x, y, z));
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveSeekAssistance: '%s', attempted to seek assistance.", _owner->GetGUID().ToString().c_str());
}

void MotionMaster::MoveSeekAssistanceDistract(uint32 time)
{
    if (_owner->GetTypeId() == TYPEID_UNIT)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveSeekAssistanceDistract: '%s', is distracted after assistance call (Time: %u)", _owner->GetGUID().ToString().c_str(), time);
        Add(new AssistanceDistractMovementGenerator(time, _owner->GetOrientation()));
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveSeekAssistanceDistract: '%s', attempted to call distract assistance.", _owner->GetGUID().ToString().c_str());
}

void MotionMaster::MoveTaxiFlight(uint32 path, uint32 pathnode)
{
    if (_owner->GetTypeId() == TYPEID_PLAYER)
    {
        if (path < sTaxiPathNodesByPath.size())
        {
            TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '%s', taxi to path Id: %u (node %u)", _owner->GetGUID().ToString().c_str(), path, pathnode);

            // Only one FLIGHT_MOTION_TYPE is allowed
            bool hasExisting = HasMovementGenerator([](MovementGenerator const* gen) { return gen->GetMovementGeneratorType() == FLIGHT_MOTION_TYPE; });
            ASSERT(!hasExisting, "Duplicate flight path movement generator");

            FlightPathMovementGenerator* movement = new FlightPathMovementGenerator(pathnode);
            movement->LoadPath(_owner->ToPlayer());
            Add(movement);
        }
        else
            TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '%s', attempted taxi to non-existing path Id: %u (node: %u)", _owner->GetGUID().ToString().c_str(), path, pathnode);
    }
    else
        TC_LOG_ERROR("movement.motionmaster", "MotionMaster::MoveTaxiFlight: '%s', attempted taxi to path Id: %u (node: %u)", _owner->GetGUID().ToString().c_str(), path, pathnode);
}

void MotionMaster::MoveDistract(uint32 timer, float orientation)
{
/*
    if (_slot[MOTION_SLOT_CONTROLLED])
        return;
*/
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveDistract: '%s', distracted (timer: %u, orientation: %f)", _owner->GetGUID().ToString().c_str(), timer, orientation);
    Add(new DistractMovementGenerator(timer, orientation));
}

void MotionMaster::MovePath(uint32 pathId, bool repeatable)
{
    if (!pathId)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePath: '%s', starts moving over path Id: %u (repeatable: %s)", _owner->GetGUID().ToString().c_str(), pathId, repeatable ? "YES" : "NO");
    Add(new WaypointMovementGenerator<Creature>(pathId, repeatable), MOTION_SLOT_DEFAULT);
}

void MotionMaster::MovePath(WaypointPath& path, bool repeatable)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MovePath: '%s', starts moving over path Id: %u (repeatable: %s)", _owner->GetGUID().ToString().c_str(), path.id, repeatable ? "YES" : "NO");
    Add(new WaypointMovementGenerator<Creature>(path, repeatable), MOTION_SLOT_DEFAULT);
}

void MotionMaster::MoveRotate(uint32 id, uint32 time, RotateDirection direction)
{
    if (!time)
        return;

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveRotate: '%s', starts rotate (time: %u, direction: %u)", _owner->GetGUID().ToString().c_str(), time, direction);
    Add(new RotateMovementGenerator(id, time, direction));
}

void MotionMaster::MoveFormation(Unit* leader, float range, float angle, uint32 point1, uint32 point2)
{
    if (_owner->GetTypeId() == TYPEID_UNIT && leader)
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::MoveFormation: '%s', started to move in a formation with leader %s", _owner->GetGUID().ToString().c_str(), leader->GetGUID().ToString().c_str());
        Add(new FormationMovementGenerator(leader, range, angle, point1, point2), MOTION_SLOT_DEFAULT);
    }
}

void MotionMaster::LaunchMoveSpline(Movement::MoveSplineInit&& init, uint32 id/*= 0*/, MovementGeneratorPriority priority/* = MOTION_PRIORITY_NORMAL*/, MovementGeneratorType type/*= EFFECT_MOTION_TYPE*/)
{
    if (IsInvalidMovementGeneratorType(type))
    {
        TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::LaunchMoveSpline: '%s', tried to launch a spline with an invalid MovementGeneratorType: %u (Id: %u, Priority: %u)", _owner->GetGUID().ToString().c_str(), type, id, priority);
        return;
    }

    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::LaunchMoveSpline: '%s', initiates spline Id: %u (Type: %u, Priority: %u)", _owner->GetGUID().ToString().c_str(), id, type, priority);

    GenericMovementGenerator* movement = new GenericMovementGenerator(std::move(init), type, id);
    movement->Priority = priority;
    Add(movement);
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
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::Delete: deleting generator (Priority: %u, Flags: %u, BaseUnitState: %u, Type: %u), owner: '%s'",
        movement->Priority, movement->Flags, movement->BaseUnitState, movement->GetMovementGeneratorType(), _owner->GetGUID().ToString().c_str());

    movement->Finalize(_owner, active, movementInform);
    ClearBaseUnitState(movement);
    MovementGeneratorPointerDeleter(movement);
}

void MotionMaster::DeleteDefault(bool active, bool movementInform)
{
    TC_LOG_DEBUG("movement.motionmaster", "MotionMaster::DeleteDefault: deleting generator (Priority: %u, Flags: %u, BaseUnitState: %u, Type: %u), owner: '%s'",
        _defaultGenerator->Priority, _defaultGenerator->Flags, _defaultGenerator->BaseUnitState, _defaultGenerator->GetMovementGeneratorType(), _owner->GetGUID().ToString().c_str());

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
