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

#include "CyclicMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "Log.h"
#include "Map.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "ObjectMgr.h"
#include "Transport.h"
#include "WaypointManager.h"

CyclicMovementGenerator<Creature>::CyclicMovementGenerator() : _path(nullptr), _stalled(false), _moveTimer(0)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_NORMAL;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_ROAMING;
}

MovementGeneratorType CyclicMovementGenerator<Creature>::GetMovementGeneratorType() const
{
    return CYCLIC_SPLINE_MOTION_TYPE;
}

CyclicMovementGenerator<Creature>::CyclicMovementGenerator(WaypointPath const* path, Optional<bool> enforceFlight, Optional<bool> enforceWalk, Optional<float> velocity) : _path(path), _stalled(false), _moveTimer(0)
{
    if (enforceFlight.has_value())
        _enforceFlight = *enforceFlight;

    if (enforceWalk.has_value())
        _enforceWalk = *enforceWalk;

    if (velocity.has_value())
        _velocity = *velocity;
}

inline bool CanMove(Creature const* creature)
{
    return (!creature->HasUnitState(UNIT_STATE_NOT_MOVE) && !creature->IsMovementPreventedByCasting());
}

void CyclicMovementGenerator<Creature>::DoInitialize(Creature* creature)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    if (!_path)
        if (uint32 pathId = creature->GetCyclicSplinePathId())
            _path = sWaypointMgr->GetPath(pathId);

    if (_path)
        _moveTimer.Reset(1000);
}

void CyclicMovementGenerator<Creature>::DoReset(Creature* creature)
{
    if (_moveTimer.Passed() && CanMove(creature))
        StartMovement(creature);
}

bool CyclicMovementGenerator<Creature>::DoUpdate(Creature* creature, uint32 diff)
{
    if (!creature || !creature->IsAlive())
        return true;

    if (!_path || _path->nodes.empty())
        return true;

    if (_stalled || !CanMove(creature))
    {
        creature->StopMoving();
        return true;
    }

    // dont update wait timer while moving
    if (creature->movespline->Finalized())
    {
        _moveTimer.Update(diff);
        if (_moveTimer.Passed())
        {
            _moveTimer.Reset(0);
            StartMovement(creature); 
        }
    }

    return true;
}

void CyclicMovementGenerator<Creature>::DoFinalize(Creature* creature, bool active, bool /*movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (active)
        creature->StopMoving();
}

void CyclicMovementGenerator<Creature>::DoDeactivate(Creature* /*creature*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
}

void CyclicMovementGenerator<Creature>::StartMovement(Creature* creature)
{
    if (!creature || !creature->IsAlive() || !CanMove(creature) || !_path || _path->nodes.empty())
        return;

    if (!CanMove(creature) || (creature->IsFormationLeader() && !creature->IsFormationLeaderMoveAllowed())) // if cannot move OR cannot move because of formation
    {
        _moveTimer.Reset(1000); // delay 1s
        return;
    }

    // Cyclic splines get asynchronous if the serverside position is not being tracked constantly.
    creature->setActive(true);

    bool const flying = creature->CanFly() || creature->IsInWater(); // Swimming units also use flying and uncompressed splines
    Movement::MoveSplineInit init(creature);
    Movement::PointsArray path;

    path.reserve(_path->nodes.size() + 1);
    path.push_back(PositionToVector3(creature->GetPosition()));
    std::transform(_path->nodes.begin(), _path->nodes.end(), std::back_inserter(path), [](WaypointNode const& node)
    {
        return G3D::Vector3(node.x, node.y, node.z);
    });

    if (flying || (_enforceFlight.has_value() && *_enforceFlight))
    {
        init.SetFly();
        init.SetUncompressed();
    }

    if (_velocity.has_value())
        init.SetVelocity(*_velocity);
    else
    {
        float velocity = _path->nodes.front().velocity;
        if (velocity > 0.f)
            init.SetVelocity(velocity);
    }

    if (_enforceWalk.has_value())
        init.SetWalk(*_enforceWalk);

    init.MovebyPath(path);
    init.SetSmooth();
    init.SetCyclic();
    init.Launch();
}

void CyclicMovementGenerator<Creature>::Pause(uint32 timer/* = 0*/)
{
    _stalled = timer ? false : true;
    _moveTimer.Reset(timer ? timer : 1);
}

void CyclicMovementGenerator<Creature>::Resume(uint32 overrideTimer/* = 0*/)
{
    _stalled = false;
    if (overrideTimer)
        _moveTimer.Reset(overrideTimer);
}
