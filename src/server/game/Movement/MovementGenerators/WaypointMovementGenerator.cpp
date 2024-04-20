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

#include "WaypointMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Errors.h"
#include "Log.h"
#include "MotionMaster.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "MovementDefines.h"
#include "PathGenerator.h"
#include "Transport.h"
#include "WaypointManager.h"
#include <span>

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(uint32 pathId, bool repeating, Optional<Milliseconds> duration, Optional<float> speed,
    MovementWalkRunSpeedSelectionMode speedSelectionMode, Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd,
    Optional<float> wanderDistanceAtPathEnds, Optional<bool> followPathBackwardsFromEndToStart, bool generatePath,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
    : PathMovementBase(PathType(std::in_place_type<WaypointPath const*>)), _nextMoveTime(0), _pathId(pathId), _repeating(repeating),
    _speed(speed), _speedSelectionMode(speedSelectionMode), _waitTimeRangeAtPathEnd(std::move(waitTimeRangeAtPathEnd)),
    _wanderDistanceAtPathEnds(wanderDistanceAtPathEnds), _followPathBackwardsFromEndToStart(followPathBackwardsFromEndToStart), _isReturningToStart(false),
    _generatePath(generatePath)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
    ScriptResult = std::move(scriptResult);
    if (duration)
        _duration.emplace(*duration);
}

WaypointMovementGenerator<Creature>::WaypointMovementGenerator(WaypointPath const& path, bool repeating, Optional<Milliseconds> duration, Optional<float> speed,
    MovementWalkRunSpeedSelectionMode speedSelectionMode, Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd,
    Optional<float> wanderDistanceAtPathEnds, Optional<bool> followPathBackwardsFromEndToStart, bool generatePath,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
    : PathMovementBase(std::make_unique<WaypointPath>(path)), _nextMoveTime(0), _pathId(0), _repeating(repeating),
    _speed(speed), _speedSelectionMode(speedSelectionMode), _waitTimeRangeAtPathEnd(std::move(waitTimeRangeAtPathEnd)),
    _wanderDistanceAtPathEnds(wanderDistanceAtPathEnds), _followPathBackwardsFromEndToStart(followPathBackwardsFromEndToStart), _isReturningToStart(false),
    _generatePath(generatePath)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
    ScriptResult = std::move(scriptResult);
    if (duration)
        _duration.emplace(*duration);

    std::get<std::unique_ptr<WaypointPath>>(_path)->BuildSegments();
}

WaypointMovementGenerator<Creature>::~WaypointMovementGenerator() = default;

MovementGeneratorType WaypointMovementGenerator<Creature>::GetMovementGeneratorType() const
{
    return WAYPOINT_MOTION_TYPE;
}

void WaypointMovementGenerator<Creature>::Pause(uint32 timer)
{
    if (timer)
    {
        // Don't try to paused an already paused generator
        if (HasFlag(MOVEMENTGENERATOR_FLAG_PAUSED))
            return;

        AddFlag(MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);
        _nextMoveTime.Reset(timer);
        RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
    }
    else
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached
        RemoveFlag(MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);
    }
}

void WaypointMovementGenerator<Creature>::Resume(uint32 overrideTimer)
{
    if (overrideTimer)
        _nextMoveTime.Reset(overrideTimer);

    if (_nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached

    RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
}

bool WaypointMovementGenerator<Creature>::GetResetPosition(Unit* /*owner*/, float& x, float& y, float& z)
{
    // prevent a crash at empty waypoint path.
    WaypointPath const* path = GetPath();
    if (!path || path->Nodes.empty())
        return false;

    ASSERT(_currentNode < path->Nodes.size(), "WaypointMovementGenerator::GetResetPosition: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, path->Id);
    WaypointNode const& waypoint = path->Nodes[_currentNode];

    x = waypoint.X;
    y = waypoint.Y;
    z = waypoint.Z;
    return true;
}

void WaypointMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    if (IsLoadedFromDB())
    {
        if (!_pathId)
            _pathId = owner->GetWaypointPathId();

        _path = sWaypointMgr->GetPath(_pathId);
    }

    WaypointPath const* path = GetPath();
    if (!path)
    {
        TC_LOG_ERROR("sql.sql", "WaypointMovementGenerator::DoInitialize: couldn't load path for creature ({}) (_pathId: {})", owner->GetGUID(), _pathId);
        return;
    }

    if (path->Nodes.size() == 1)
        _repeating = false;

    owner->StopMoving();

    _nextMoveTime.Reset(1000);
}

void WaypointMovementGenerator<Creature>::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    owner->StopMoving();

    if (!HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED) && _nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached
}

bool WaypointMovementGenerator<Creature>::DoUpdate(Creature* owner, uint32 diff)
{
    if (!owner || !owner->IsAlive())
        return true;

    if (HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED | MOVEMENTGENERATOR_FLAG_PAUSED))
        return true;

    WaypointPath const* path = GetPath();
    if (!path || path->Nodes.empty())
        return true;

    if (_duration)
    {
        _duration->Update(diff);
        if (_duration->Passed())
        {
            RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
            AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
            owner->UpdateCurrentWaypointInfo(0, 0);
            SetScriptResult(MovementStopReason::Finished);
            return false;
        }
    }

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE | UNIT_STATE_LOST_CONTROL) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if (HasFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED))
    {
        /*
         *  relaunch only if
         *  - has a tiner? -> was it interrupted while not waiting aka moving? need to check both:
         *      -> has a timer - is it because its waiting to start next node?
         *      -> has a timer - is it because something set it while moving (like timed pause)?
         *
         *  - doesnt have a timer? -> is movement valid?
         *
         *  TODO: ((_nextMoveTime.Passed() && VALID_MOVEMENT) || (!_nextMoveTime.Passed() && !HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)))
         */
        if (HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED) && (_nextMoveTime.Passed() || !HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)))
        {
            StartMove(owner, true);
            return true;
        }

        RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
    }

    // if it's moving
    if (!owner->movespline->Finalized())
    {
        // set home position at place (every MotionMaster::UpdateMotion)
        if (owner->GetTransGUID().IsEmpty())
            owner->SetHomePosition(owner->GetPosition());

        // handle switching points in continuous segments
        if (_waypointTransitionSplinePoints.size() > 1 && owner->movespline->currentPathIdx() >= _waypointTransitionSplinePoints.front())
        {
            OnArrived(owner);
            _waypointTransitionSplinePoints.erase(_waypointTransitionSplinePoints.begin());
            if (ComputeNextNode())
                if (CreatureAI* ai = owner->AI())
                    ai->WaypointStarted(path->Nodes[_currentNode].Id, path->Id);
        }

        // relaunch movement if its speed has changed
        if (HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING))
            StartMove(owner, true);
    }
    else if (!_nextMoveTime.Passed()) // it's not moving, is there a timer?
    {
        if (UpdateTimer(diff))
        {
            if (!HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED)) // initial movement call
            {
                StartMove(owner);
                return true;
            }
            else if (!HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)) // timer set before node was reached, resume now
            {
                StartMove(owner, true);
                return true;
            }
        }
        else
            return true; // keep waiting
    }
    else // not moving, no timer
    {
        if (HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED) && !HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        {
            OnArrived(owner); // hooks and wait timer reset (if necessary)
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED); // signals to future StartMove that it reached a node
        }

        if (_nextMoveTime.Passed()) // OnArrived might have set a timer
            StartMove(owner); // check path status, get next point and move if necessary & can
    }

    return true;
}

void WaypointMovementGenerator<Creature>::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void WaypointMovementGenerator<Creature>::DoFinalize(Creature* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

        // TODO: Research if this modification is needed, which most likely isnt
        owner->SetWalk(false);
    }

    if (movementInform)
        SetScriptResult(MovementStopReason::Finished);
}

void WaypointMovementGenerator<Creature>::MovementInform(Creature const* owner) const
{
    WaypointPath const* path = GetPath();
    WaypointNode const& waypoint = path->Nodes[_currentNode];
    if (CreatureAI* AI = owner->AI())
    {
        AI->MovementInform(WAYPOINT_MOTION_TYPE, waypoint.Id);
        AI->WaypointReached(waypoint.Id, path->Id);
    }
}

void WaypointMovementGenerator<Creature>::OnArrived(Creature* owner)
{
    WaypointPath const* path = GetPath();
    if (!path || path->Nodes.empty())
        return;

    ASSERT(_currentNode < path->Nodes.size(), "WaypointMovementGenerator::OnArrived: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, path->Id);
    WaypointNode const& waypoint = path->Nodes[_currentNode];

    if (waypoint.Delay)
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        _nextMoveTime.Reset(*waypoint.Delay);
    }

    if (_waitTimeRangeAtPathEnd && IsFollowingPathBackwardsFromEndToStart()
        && ((_isReturningToStart && _currentNode == 0) || (!_isReturningToStart && _currentNode == path->Nodes.size() - 1)))
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
        Milliseconds waitTime = randtime(_waitTimeRangeAtPathEnd->first, _waitTimeRangeAtPathEnd->second);
        if (_duration)
            _duration->Update(waitTime); // count the random movement time as part of waypoing movement action

        if (_wanderDistanceAtPathEnds)
            owner->GetMotionMaster()->MoveRandom(*_wanderDistanceAtPathEnds, waitTime, MOTION_SLOT_ACTIVE);
        else
            _nextMoveTime.Reset(waitTime);
    }

    MovementInform(owner);

    owner->UpdateCurrentWaypointInfo(waypoint.Id, path->Id);
}

void WaypointMovementGenerator<Creature>::StartMove(Creature* owner, bool relaunch/* = false*/)
{
    // sanity checks
    if (!owner || !owner->IsAlive() || HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED) || (relaunch && (HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) || !HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))))
        return;

    WaypointPath const* path = GetPath();
    if (!path || path->Nodes.empty())
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting() || (owner->IsFormationLeader() && !owner->IsFormationLeaderMoveAllowed())) // if cannot move OR cannot move because of formation
    {
        _nextMoveTime.Reset(1000); // delay 1s
        return;
    }

    bool const transportPath = !owner->GetTransGUID().IsEmpty();

    uint32 previousNode = _currentNode;
    if (HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))
    {
        if (ComputeNextNode())
        {
            ASSERT(_currentNode < path->Nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, path->Id);

            // inform AI
            if (CreatureAI* AI = owner->AI())
                AI->WaypointStarted(path->Nodes[_currentNode].Id, path->Id);
        }
        else
        {
            WaypointNode const& waypoint = path->Nodes[_currentNode];
            float x = waypoint.X;
            float y = waypoint.Y;
            float z = waypoint.Z;
            float o = owner->GetOrientation();

            if (!transportPath)
                owner->SetHomePosition(x, y, z, o);
            else
            {
                if (TransportBase* trans = owner->GetTransport())
                {
                    o -= trans->GetTransportOrientation();
                    owner->SetTransportHomePosition(x, y, z, o);
                    trans->CalculatePassengerPosition(x, y, z, &o);
                    owner->SetHomePosition(x, y, z, o);
                }
                // else if (vehicle) - this should never happen, vehicle offsets are const
            }
            AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
            owner->UpdateCurrentWaypointInfo(0, 0);

            // inform AI
            if (CreatureAI* AI = owner->AI())
                AI->WaypointPathEnded(waypoint.Id, path->Id);

            SetScriptResult(MovementStopReason::Finished);
            return;
        }
    }
    else if (!HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

        // inform AI
        if (CreatureAI* AI = owner->AI())
            AI->WaypointStarted(path->Nodes[_currentNode].Id, path->Id);
    }

    ASSERT(_currentNode < path->Nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, path->Id);

    std::span<WaypointNode const> segment = [&]
    {
        // find the continuous segment that our destination waypoint is on
        auto segmentItr = std::ranges::find_if(path->ContinuousSegments, [&](std::pair<std::size_t, std::size_t> segmentRange)
        {
            auto isInSegmentRange = [&](uint32 node) { return node >= segmentRange.first && node < segmentRange.first + segmentRange.second; };
            return isInSegmentRange(_currentNode) && isInSegmentRange(previousNode);
        });

        // handle path returning directly from last point to first
        if (segmentItr == path->ContinuousSegments.end())
        {
            if (_currentNode != 0 || previousNode != path->Nodes.size() - 1)
                return std::span(&path->Nodes[_currentNode], 1);

            segmentItr = path->ContinuousSegments.begin();
        }

        if (!_isReturningToStart)
            return std::span(&path->Nodes[_currentNode], segmentItr->second - (_currentNode - segmentItr->first));

        return std::span(&path->Nodes[segmentItr->first], _currentNode - segmentItr->first + 1);
    }();

    WaypointNode const& lastWaypointForSegment = !_isReturningToStart ? segment.back() : segment.front();

    _waypointTransitionSplinePoints.clear();
    Movement::PointsArray points;
    auto fillPath = [this, owner, &points]<typename iterator>(iterator itr, iterator end)
    {
        Optional<PathGenerator> generator;
        if (_generatePath)
            generator.emplace(owner);

        Position source = owner->GetPosition();
        points.emplace_back(source.GetPositionX(), source.GetPositionY(), source.GetPositionZ());

        while (itr != end)
        {
            if (generator)
            {
                bool result = generator->CalculatePath(source.GetPositionX(), source.GetPositionY(), source.GetPositionZ(), itr->X, itr->Y, itr->Z);
                if (result && !(generator->GetPathType() & PATHFIND_NOPATH))
                    points.insert(points.end(), generator->GetPath().begin() + 1, generator->GetPath().end());
                else
                    generator.reset(); // when path generation to a waypoint fails, add all remaining points without pathfinding (preserve legacy behavior of MoveSplineInit::MoveTo)
            }

            if (!generator)
                points.emplace_back(itr->X, itr->Y, itr->Z);

            _waypointTransitionSplinePoints.push_back(points.size() - 1);

            source.Relocate(itr->X, itr->Y, itr->Z);
            ++itr;
        }
    };

    if (!_isReturningToStart)
        fillPath(segment.begin(), segment.end());
    else
        fillPath(segment.rbegin(), segment.rend());

    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_INFORM_ENABLED | MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);

    // because steering flag can cause position on client to not be perfectly accurate, dont do it in combat
    if (!owner->IsInCombat())
        init.SetSteering();

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
        init.DisableTransportPathTransformations();

    init.MovebyPath(points);

    if (lastWaypointForSegment.Orientation.has_value() && (lastWaypointForSegment.Delay || _currentNode == path->Nodes.size() - 1))
        init.SetFacing(*lastWaypointForSegment.Orientation);

    switch (path->MoveType)
    {
        case WaypointMoveType::Land:
            init.SetAnimation(AnimTier::Ground);
            init.SetFly();
            break;
        case WaypointMoveType::TakeOff:
            init.SetAnimation(AnimTier::Fly);
            init.SetFly();
            break;
        case WaypointMoveType::Run:
            init.SetWalk(false);
            break;
        case WaypointMoveType::Walk:
            init.SetWalk(true);
            break;
        default:
            break;
    }

    switch (_speedSelectionMode) // overrides move type from each waypoint if set
    {
        case MovementWalkRunSpeedSelectionMode::Default:
            break;
        case MovementWalkRunSpeedSelectionMode::ForceRun:
            init.SetWalk(false);
            break;
        case MovementWalkRunSpeedSelectionMode::ForceWalk:
            init.SetWalk(true);
            break;
        default:
            break;
    }

    if (path->Velocity && !_speed)
        _speed = path->Velocity;

    if (_speed)
        init.SetVelocity(*_speed);

    if (init.Path().size() > 2)
    {
        G3D::Vector3 mid = (init.Path().front() + init.Path().back()) / 2.0f;
        auto itr = init.Path().begin() + 1;
        auto end = itr + (init.Path().size() - 2);
        while (itr != end)
        {
            G3D::Vector3 offset = *itr - mid;
            if (std::fabs(offset.x) >= 128.0f || std::fabs(offset.y) >= 128.0f || std::fabs(offset.z) >= 64.0f)
            {
                // when distance is too great, send path in uncompressed state otherwise too much precision is lost on each point
                init.SetUncompressed();
                break;
            }

            ++itr;
        }
    }

    init.Launch();

    // inform formation
    owner->SignalFormationMovement();
}

bool WaypointMovementGenerator<Creature>::ComputeNextNode()
{
    WaypointPath const* path = GetPath();
    if ((_currentNode == path->Nodes.size() - 1) && !_repeating)
        return false;

    if (!IsFollowingPathBackwardsFromEndToStart() || path->Nodes.size() < WAYPOINT_PATH_FLAG_FOLLOW_PATH_BACKWARDS_MINIMUM_NODES)
        _currentNode = (_currentNode + 1) % path->Nodes.size();
    else
    {
        if (!_isReturningToStart)
        {
            if (++_currentNode >= path->Nodes.size())
            {
                _currentNode -= WAYPOINT_PATH_FLAG_FOLLOW_PATH_BACKWARDS_MINIMUM_NODES;
                _isReturningToStart = true;
            }
        }
        else
        {
            if (_currentNode-- == 0)
            {
                _currentNode = 1;
                _isReturningToStart = false;
            }
        }
    }

    return true;
}

bool WaypointMovementGenerator<Creature>::IsFollowingPathBackwardsFromEndToStart() const
{
    if (_followPathBackwardsFromEndToStart)
        return *_followPathBackwardsFromEndToStart;

    return GetPath()->Flags.HasFlag(WaypointPathFlags::FollowPathBackwardsFromEndToStart);
}

std::string WaypointMovementGenerator<Creature>::GetDebugInfo() const
{
    return Trinity::StringFormat("{}\n{}",
        PathMovementBase::GetDebugInfo(),
        MovementGeneratorMedium::GetDebugInfo());
}

MovementGenerator* WaypointMovementFactory::Create(Unit* /*object*/) const
{
    return new WaypointMovementGenerator<Creature>(0, true);
}
