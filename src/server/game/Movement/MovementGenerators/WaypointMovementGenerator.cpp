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
#include "Player.h"
#include "Transport.h"
#include "WaypointManager.h"
#include <span>

namespace
{
constexpr Milliseconds SEND_NEXT_POINT_EARLY_DELTA = 1500ms;
}

template <typename T>
WaypointMovementGenerator<T>::WaypointMovementGenerator(uint32 pathId, bool repeating, Optional<Milliseconds> duration, Optional<float> speed,
    MovementWalkRunSpeedSelectionMode speedSelectionMode, Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd,
    Optional<float> wanderDistanceAtPathEnds, Optional<bool> followPathBackwardsFromEndToStart, Optional<bool> exactSplinePath, bool generatePath,
    Scripting::v2::ActionResultSetter<MovementStopReason>&& scriptResult /*= {}*/)
    : PathMovementBase(sWaypointMgr->GetPath(pathId)), _speed(speed), _speedSelectionMode(speedSelectionMode),
    _waitTimeRangeAtPathEnd(std::move(waitTimeRangeAtPathEnd)), _wanderDistanceAtPathEnds(wanderDistanceAtPathEnds),
    _followPathBackwardsFromEndToStart(followPathBackwardsFromEndToStart), _exactSplinePath(exactSplinePath), _repeating(repeating), _generatePath(generatePath),
    _moveTimer(0), _nextMoveTime(0), _waypointTransitionSplinePointsIndex(0), _isReturningToStart(false)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_NORMAL;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_ROAMING;
    this->ScriptResult = std::move(scriptResult);
    if (duration)
        _duration.emplace(*duration);
}

template <typename T>
WaypointMovementGenerator<T>::WaypointMovementGenerator(WaypointPath const& path, bool repeating, Optional<Milliseconds> duration, Optional<float> speed,
    MovementWalkRunSpeedSelectionMode speedSelectionMode, Optional<std::pair<Milliseconds, Milliseconds>> waitTimeRangeAtPathEnd,
    Optional<float> wanderDistanceAtPathEnds, Optional<bool> followPathBackwardsFromEndToStart, Optional<bool> exactSplinePath, bool generatePath,
    Scripting::v2::ActionResultSetter<MovementStopReason>&& scriptResult /*= {}*/)
    : PathMovementBase(std::make_unique<WaypointPath>(path)), _speed(speed), _speedSelectionMode(speedSelectionMode),
    _waitTimeRangeAtPathEnd(std::move(waitTimeRangeAtPathEnd)), _wanderDistanceAtPathEnds(wanderDistanceAtPathEnds),
    _followPathBackwardsFromEndToStart(followPathBackwardsFromEndToStart), _exactSplinePath(exactSplinePath), _repeating(repeating), _generatePath(generatePath),
    _moveTimer(0), _nextMoveTime(0), _waypointTransitionSplinePointsIndex(0), _isReturningToStart(false)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_NORMAL;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_ROAMING;
    this->ScriptResult = std::move(scriptResult);
    if (duration)
        _duration.emplace(*duration);

    std::get<std::unique_ptr<WaypointPath>>(this->_path)->BuildSegments();
}

template <typename T>
WaypointMovementGenerator<T>::~WaypointMovementGenerator() = default;

template <typename T>
MovementGeneratorType WaypointMovementGenerator<T>::GetMovementGeneratorType() const
{
    return WAYPOINT_MOTION_TYPE;
}

template <typename T>
void WaypointMovementGenerator<T>::Pause(uint32 timer)
{
    if (timer)
    {
        // Don't try to paused an already paused generator
        if (this->HasFlag(MOVEMENTGENERATOR_FLAG_PAUSED))
            return;

        this->AddFlag(MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);
        _nextMoveTime.Reset(timer);
        this->RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
    }
    else
    {
        this->AddFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached
        this->RemoveFlag(MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);
    }
}

template <typename T>
void WaypointMovementGenerator<T>::Resume(uint32 overrideTimer)
{
    if (overrideTimer)
        _nextMoveTime.Reset(overrideTimer);

    if (_nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached

    this->RemoveFlag(MOVEMENTGENERATOR_FLAG_PAUSED);
}

template <typename T>
bool WaypointMovementGenerator<T>::GetResetPosition(Unit* /*owner*/, float& x, float& y, float& z)
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

template <typename T>
void WaypointMovementGenerator<T>::DoInitialize(T* owner)
{
    this->RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    WaypointPath const* path = GetPath();
    if (!path)
    {
        TC_LOG_ERROR("sql.sql", "WaypointMovementGenerator::DoInitialize: couldn't load path for {}", owner->GetGUID());
        return;
    }

    if (path->Nodes.size() == 1)
        _repeating = false;

    owner->StopMoving();

    _nextMoveTime.Reset(1000);
}

template <typename T>
void WaypointMovementGenerator<T>::DoReset(T* owner)
{
    this->RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    owner->StopMoving();

    if (!this->HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED) && _nextMoveTime.Passed())
        _nextMoveTime.Reset(1); // Needed so that Update does not behave as if node was reached
}

template <typename T>
bool WaypointMovementGenerator<T>::DoUpdate(T* owner, uint32 diff)
{
    if (!owner->IsAlive())
        return true;

    if (this->HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED | MOVEMENTGENERATOR_FLAG_PAUSED))
        return true;

    WaypointPath const* path = GetPath();
    if (!path || path->Nodes.empty())
        return true;

    if (_duration)
    {
        _duration->Update(diff);
        if (_duration->Passed())
        {
            if constexpr (std::is_base_of_v<Creature, T>)
                owner->UpdateCurrentWaypointInfo(0, 0);

            this->RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
            this->AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
            this->AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
            this->SetScriptResult(MovementStopReason::Finished);
            return false;
        }
    }

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE | UNIT_STATE_LOST_CONTROL) || owner->IsMovementPreventedByCasting())
    {
        this->AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if (this->HasFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED))
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
        if (this->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED) && (_nextMoveTime.Passed() || !this->HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)))
        {
            StartMove(owner, true);
            return true;
        }

        this->RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
    }

    // if it's moving
    if (!UpdateMoveTimer(diff) && !owner->movespline->Finalized())
    {
        // set home position at place (every MotionMaster::UpdateMotion)
        if constexpr (std::is_base_of_v<Creature, T>)
            if (owner->GetTransGUID().IsEmpty())
                owner->SetHomePosition(owner->GetPosition());

        // handle switching points in continuous segments
        if (IsExactSplinePath())
        {
            if (_waypointTransitionSplinePointsIndex < _waypointTransitionSplinePoints.size()
                && owner->movespline->currentPathIdx() >= _waypointTransitionSplinePoints[_waypointTransitionSplinePointsIndex])
            {
                OnArrived(owner);
                ++_waypointTransitionSplinePointsIndex;
                if (ComputeNextNode())
                {
                    if constexpr (std::is_base_of_v<Creature, T>)
                        if (CreatureAI* ai = owner->AI())
                            ai->WaypointStarted(path->Nodes[_currentNode].Id, path->Id);
                }
            }
        }

        // relaunch movement if its speed has changed
        if (this->HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING))
            StartMove(owner, true);
    }
    else if (!_nextMoveTime.Passed()) // it's not moving, is there a timer?
    {
        if (UpdateWaitTimer(diff))
        {
            if (!this->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED)) // initial movement call
            {
                StartMove(owner);
                return true;
            }
            else if (!this->HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED)) // timer set before node was reached, resume now
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
        if (this->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED) && !this->HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        {
            OnArrived(owner); // hooks and wait timer reset (if necessary)
            this->AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED); // signals to future StartMove that it reached a node
        }

        if (_nextMoveTime.Passed()) // OnArrived might have set a timer
            StartMove(owner); // check path status, get next point and move if necessary & can
    }

    return true;
}

template <typename T>
void WaypointMovementGenerator<T>::DoDeactivate(T* owner)
{
    this->AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

template <typename T>
void WaypointMovementGenerator<T>::DoFinalize(T* owner, bool active, bool movementInform)
{
    this->AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
    {
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

        // TODO: Research if this modification is needed, which most likely isnt
        if constexpr (std::is_base_of_v<Creature, T>)
            owner->SetWalk(false);
    }

    if (movementInform)
        this->SetScriptResult(MovementStopReason::Finished);
}

template <typename T>
void WaypointMovementGenerator<T>::MovementInform(T const* /*owner*/) const
{
}

template <>
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

template <typename T>
void WaypointMovementGenerator<T>::OnArrived(T* owner)
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
            owner->GetMotionMaster()->MoveRandom(*_wanderDistanceAtPathEnds, waitTime, _speed, _speedSelectionMode, MOTION_SLOT_ACTIVE);
        else
            _nextMoveTime.Reset(waitTime);
    }

    MovementInform(owner);

    if constexpr (std::is_base_of_v<Creature, T>)
        owner->UpdateCurrentWaypointInfo(waypoint.Id, path->Id);
}

namespace
{
void CreateSingularPointPath(Unit const* owner, WaypointPath const* path, uint32 currentNode, bool generatePath,
    Movement::PointsArray* points, std::vector<int32>* waypointTransitionSplinePoints)
{
    WaypointNode const& waypoint = path->Nodes[currentNode];
    points->emplace_back(owner->GetPositionX(), owner->GetPositionY(), owner->GetPositionZ());

    if (generatePath)
    {
        PathGenerator generator(owner);
        bool result = generator.CalculatePath(waypoint.X, waypoint.Y, waypoint.Z);
        if (result && !(generator.GetPathType() & PATHFIND_NOPATH))
            points->insert(points->end(), generator.GetPath().begin() + 1, generator.GetPath().end());
        else
            points->emplace_back(waypoint.X, waypoint.Y, waypoint.Z);
    }
    else
        points->emplace_back(waypoint.X, waypoint.Y, waypoint.Z);

    waypointTransitionSplinePoints->push_back(points->size() - 1);
}

void CreateMergedPath(Unit const* owner, WaypointPath const* path, uint32 previousNode, uint32 currentNode,
    bool isReturningToStart, bool generatePath, bool isCyclic,
    Movement::PointsArray* points, std::vector<int32>* waypointTransitionSplinePoints, WaypointNode const** lastWaypointOnPath)
{
    std::span<WaypointNode const> segment = [&]
    {
        // find the continuous segment that our destination waypoint is on
        auto segmentItr = std::ranges::find_if(path->ContinuousSegments, [&](std::pair<std::size_t, std::size_t> const& segmentRange)
        {
            auto isInSegmentRange = [&](uint32 node) { return node >= segmentRange.first && node < segmentRange.first + segmentRange.second; };
            return isInSegmentRange(currentNode) && isInSegmentRange(previousNode);
        });

        // handle path returning directly from last point to first
        if (segmentItr == path->ContinuousSegments.end())
        {
            if (currentNode != 0 || previousNode != path->Nodes.size() - 1)
                return std::span(&path->Nodes[currentNode], 1);

            segmentItr = path->ContinuousSegments.begin();
        }

        if (!isReturningToStart)
            return std::span(&path->Nodes[currentNode], segmentItr->second - (currentNode - segmentItr->first));

        return std::span(&path->Nodes[segmentItr->first], currentNode - segmentItr->first + 1);
    }();

    *lastWaypointOnPath = !isReturningToStart ? &segment.back() : &segment.front();

    waypointTransitionSplinePoints->clear();
    auto fillPath = [&]<typename iterator>(iterator itr, iterator end)
    {
        Optional<PathGenerator> generator;
        if (generatePath)
            generator.emplace(owner);

        Position source = owner->GetPosition();
        points->emplace_back(source.GetPositionX(), source.GetPositionY(), source.GetPositionZ());

        while (itr != end)
        {
            if (generator)
            {
                bool result = generator->CalculatePath(source.GetPositionX(), source.GetPositionY(), source.GetPositionZ(), itr->X, itr->Y, itr->Z);
                if (result && !(generator->GetPathType() & PATHFIND_NOPATH))
                    points->insert(points->end(), generator->GetPath().begin() + 1, generator->GetPath().end());
                else
                    generator.reset(); // when path generation to a waypoint fails, add all remaining points without pathfinding (preserve legacy behavior of MoveSplineInit::MoveTo)
            }

            if (!generator)
                points->emplace_back(itr->X, itr->Y, itr->Z);

            waypointTransitionSplinePoints->push_back(points->size() - 1);

            source.Relocate(itr->X, itr->Y, itr->Z);
            ++itr;
        }
    };

    if (isCyclic)
    {
        // create new cyclic path starting at current node
        std::vector<WaypointNode> cyclicPath = path->Nodes;
        std::rotate(cyclicPath.begin(), cyclicPath.begin() + currentNode, cyclicPath.end());
        fillPath(cyclicPath.begin(), cyclicPath.end());
        return;
    }

    if (!isReturningToStart)
        fillPath(segment.begin(), segment.end());
    else
        fillPath(segment.rbegin(), segment.rend());
}
}

template <typename T>
void WaypointMovementGenerator<T>::StartMove(T* owner, bool relaunch/* = false*/)
{
    // sanity checks
    if (!owner->IsAlive() || this->HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED)
        || (relaunch && (this->HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) || !this->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))))
        return;

    WaypointPath const* path = GetPath();
    if (!path || path->Nodes.empty())
        return;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting()) // if cannot move
    {
        _nextMoveTime.Reset(1000); // delay 1s
        return;
    }

    if constexpr (std::is_base_of_v<Creature, T>)
    {
        if (owner->IsFormationLeader() && !owner->IsFormationLeaderMoveAllowed()) // if cannot move because of formation
        {
            _nextMoveTime.Reset(1000); // delay 1s
            return;
        }
    }

    bool const transportPath = !owner->GetTransGUID().IsEmpty();

    uint32 previousNode = _currentNode;
    if (this->HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && this->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))
    {
        if (ComputeNextNode())
        {
            ASSERT(_currentNode < path->Nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, path->Id);

            // inform AI
            if constexpr (std::is_base_of_v<Creature, T>)
                if (CreatureAI* AI = owner->AI())
                    AI->WaypointStarted(path->Nodes[_currentNode].Id, path->Id);
        }
        else
        {
            this->AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

            if constexpr (std::is_base_of_v<Creature, T>)
            {
                owner->UpdateCurrentWaypointInfo(0, 0);

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
                        owner->SetHomePosition(trans->GetPositionWithOffset(owner->GetTransportHomePosition()));
                    }
                    // else if (vehicle) - this should never happen, vehicle offsets are const
                }

                // inform AI
                if (CreatureAI* AI = owner->AI())
                    AI->WaypointPathEnded(waypoint.Id, path->Id);
            }

            this->SetScriptResult(MovementStopReason::Finished);
            return;
        }
    }
    else if (!this->HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED))
    {
        this->AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

        // inform AI
        if constexpr (std::is_base_of_v<Creature, T>)
            if (CreatureAI* AI = owner->AI())
                AI->WaypointStarted(path->Nodes[_currentNode].Id, path->Id);
    }

    ASSERT(_currentNode < path->Nodes.size(), "WaypointMovementGenerator::StartMove: tried to reference a node id (%u) which is not included in path (%u)", _currentNode, path->Id);
    WaypointNode const* lastWaypointForSegment = &path->Nodes[_currentNode];

    bool isCyclic = IsCyclic();
    Movement::PointsArray points;

    if (IsExactSplinePath())
        CreateMergedPath(owner, path, previousNode, _currentNode, _isReturningToStart, false, isCyclic,
            &points, &_waypointTransitionSplinePoints, &lastWaypointForSegment);
    else
        CreateSingularPointPath(owner, path, _currentNode, _generatePath, &points, &_waypointTransitionSplinePoints);

    _waypointTransitionSplinePointsIndex = 0;

    this->RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_INFORM_ENABLED | MOVEMENTGENERATOR_FLAG_TIMED_PAUSED);

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    if (isCyclic)
    {
        bool isFirstCycle = relaunch || owner->movespline->Finalized() || !owner->movespline->isCyclic();
        if (!isFirstCycle)
        {
            for (int32& point : _waypointTransitionSplinePoints)
                --point;

            // cyclic paths are using identical duration to first cycle with EnterCycle
            _moveTimer.Reset(Milliseconds(owner->movespline->Duration()));
            return;
        }
    }

    Movement::MoveSplineInit init(owner);

    //! If creature is on transport, we assume waypoints set in DB are already transport offsets
    if (transportPath)
        init.DisableTransportPathTransformations();

    init.MovebyPath(points);

    if (lastWaypointForSegment->Orientation.has_value()
        && (lastWaypointForSegment->Delay || (_isReturningToStart ? _currentNode == 0 : _currentNode == path->Nodes.size() - 1)))
        init.SetFacing(*lastWaypointForSegment->Orientation);

    switch (lastWaypointForSegment->MoveType.value_or(path->MoveType))
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

    if (isCyclic)
        init.SetCyclic();

    if (IsExactSplinePath() && (points.size() > 2 && owner->CanFly()))
        init.SetSmooth();

    Milliseconds duration(init.Launch());

    if (!IsExactSplinePath()
        && duration > 2 * SEND_NEXT_POINT_EARLY_DELTA
        && !lastWaypointForSegment->Delay
        && path->Nodes.size() > 2
        // don't cut movement short at ends of path if its not a looping path or if it can be traversed backwards
        && ((_currentNode != 0 && _currentNode != path->Nodes.size() - 1) || (!IsFollowingPathBackwardsFromEndToStart() && _repeating)))
        duration -= SEND_NEXT_POINT_EARLY_DELTA;

    _moveTimer.Reset(duration);

    // inform formation
    if constexpr (std::is_base_of_v<Creature, T>)
        owner->SignalFormationMovement();
}

template <typename T>
bool WaypointMovementGenerator<T>::ComputeNextNode()
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

template <typename T>
bool WaypointMovementGenerator<T>::IsFollowingPathBackwardsFromEndToStart() const
{
    if (_followPathBackwardsFromEndToStart)
        return *_followPathBackwardsFromEndToStart;

    return GetPath()->Flags.HasFlag(WaypointPathFlags::FollowPathBackwardsFromEndToStart);
}

template <typename T>
bool WaypointMovementGenerator<T>::IsExactSplinePath() const
{
    if (_exactSplinePath)
        return *_exactSplinePath;

    return GetPath()->Flags.HasFlag(WaypointPathFlags::ExactSplinePath);
}

template <typename T>
bool WaypointMovementGenerator<T>::IsCyclic() const
{
    return !IsFollowingPathBackwardsFromEndToStart()
        && IsExactSplinePath()
        && _repeating
        && GetPath()->ContinuousSegments.size() == 1;
}

template <typename T>
std::string WaypointMovementGenerator<T>::GetDebugInfo() const
{
    return Trinity::StringFormat("{}\n{}",
        PathMovementBase::GetDebugInfo(),
        MovementGeneratorMedium<T, WaypointMovementGenerator>::GetDebugInfo());
}

MovementGenerator* WaypointMovementFactory::Create(Unit* object) const
{
    return new WaypointMovementGenerator<Creature>(object->ToCreature()->GetWaypointPathId(), true);
}

template class WaypointMovementGenerator<Creature>;
template class WaypointMovementGenerator<Player>;
