/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Creature.h"
#include "CreatureAI.h"
#include "MapManager.h"
#include "FleeingMovementGenerator.h"
#include "PathGenerator.h"
#include "ObjectAccessor.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"

#define MIN_QUIET_DISTANCE 28.0f
#define MAX_QUIET_DISTANCE 43.0f

template<class T>
void FleeingMovementGenerator<T>::_setTargetLocation(T* owner)
{
    if (!owner)
        return;

    if (owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
        return;

    float x, y, z;
    if (!_getPoint(owner, x, y, z))
        return;

    owner->AddUnitState(UNIT_STATE_FLEEING_MOVE);

    PathGenerator path(owner);
    path.SetPathLengthLimit(30.0f);
    bool result = path.CalculatePath(x, y, z);
    if (!result || path.GetPathType() & PATHFIND_NOPATH)
    {
        i_nextCheckTime.Reset(urand(1000, 1500));
        return;
    }

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(path.GetPath());
    init.SetWalk(false);
    int32 traveltime = init.Launch();
    i_nextCheckTime.Reset(traveltime + urand(800, 1500));
}

template<class T>
bool FleeingMovementGenerator<T>::_getPoint(T* owner, float &x, float &y, float &z)
{
    if (!owner)
        return false;

    float dist_from_caster, angle_to_caster;
    if (Unit* fright = ObjectAccessor::GetUnit(*owner, i_frightGUID))
    {
        dist_from_caster = fright->GetDistance(owner);
        if (dist_from_caster > 0.2f)
            angle_to_caster = fright->GetAngle(owner);
        else
            angle_to_caster = frand(0, 2 * static_cast<float>(M_PI));
    }
    else
    {
        dist_from_caster = 0.0f;
        angle_to_caster = frand(0, 2 * static_cast<float>(M_PI));
    }

    float dist, angle;
    if (dist_from_caster < MIN_QUIET_DISTANCE)
    {
        dist = frand(0.4f, 1.3f)*(MIN_QUIET_DISTANCE - dist_from_caster);
        angle = angle_to_caster + frand(-static_cast<float>(M_PI)/8, static_cast<float>(M_PI)/8);
    }
    else if(dist_from_caster > MAX_QUIET_DISTANCE)
    {
        dist = frand(0.4f, 1.0f)*(MAX_QUIET_DISTANCE - MIN_QUIET_DISTANCE);
        angle = -angle_to_caster + frand(-static_cast<float>(M_PI)/4, static_cast<float>(M_PI)/4);
    }
    else    // we are inside quiet range
    {
        dist = frand(0.6f, 1.2f)*(MAX_QUIET_DISTANCE - MIN_QUIET_DISTANCE);
        angle = frand(0, 2*static_cast<float>(M_PI));
    }

    float curr_x, curr_y, curr_z;
    owner->GetPosition(curr_x, curr_y, curr_z);

    x = curr_x + dist * std::cos(angle);
    y = curr_y + dist * std::sin(angle);
    z = curr_z;

    owner->UpdateAllowedPositionZ(x, y, z);

    return true;
}

template<class T>
void FleeingMovementGenerator<T>::Initialize(T* owner)
{
    if (!owner)
        return;

    owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner->AddUnitState(UNIT_STATE_FLEEING|UNIT_STATE_FLEEING_MOVE);

    if (owner->GetTypeId() == TYPEID_UNIT)
        return;

    _setTargetLocation(owner);
}

template<>
void FleeingMovementGenerator<Player>::Finalize(Player* owner)
{
    owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner->ClearUnitState(UNIT_STATE_FLEEING | UNIT_STATE_FLEEING_MOVE);
    owner->StopMoving();
}

template<>
void FleeingMovementGenerator<Creature>::Finalize(Creature* owner)
{
    owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner->ClearUnitState(UNIT_STATE_FLEEING|UNIT_STATE_FLEEING_MOVE);
    if (owner->getVictim())
        owner->SetTarget(owner->getVictim()->GetGUID());
}

template<class T>
void FleeingMovementGenerator<T>::Reset(T* owner)
{
    Initialize(owner);
}

template<class T>
bool FleeingMovementGenerator<T>::Update(T* owner, const uint32& time_diff)
{
    if (!owner || !owner->isAlive())
        return false;
    if (owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
    {
        owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);
        return true;
    }

    i_nextCheckTime.Update(time_diff);
    if (i_nextCheckTime.Passed() && owner->movespline->Finalized())
        _setTargetLocation(owner);

    return true;
}

template void FleeingMovementGenerator<Player>::Initialize(Player*);
template void FleeingMovementGenerator<Creature>::Initialize(Creature*);
template bool FleeingMovementGenerator<Player>::_getPoint(Player*, float&, float&, float&);
template bool FleeingMovementGenerator<Creature>::_getPoint(Creature*, float&, float&, float&);
template void FleeingMovementGenerator<Player>::_setTargetLocation(Player*);
template void FleeingMovementGenerator<Creature>::_setTargetLocation(Creature*);
template void FleeingMovementGenerator<Player>::Reset(Player*);
template void FleeingMovementGenerator<Creature>::Reset(Creature*);
template bool FleeingMovementGenerator<Player>::Update(Player*, const uint32&);
template bool FleeingMovementGenerator<Creature>::Update(Creature*, const uint32&);

void TimedFleeingMovementGenerator::Finalize(Unit* owner)
{
    owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_FLEEING);
    owner->ClearUnitState(UNIT_STATE_FLEEING|UNIT_STATE_FLEEING_MOVE);
    if (Unit* victim = owner->getVictim())
    {
        if (owner->isAlive())
        {
            owner->AttackStop();
            owner->ToCreature()->AI()->AttackStart(victim);
        }
    }
}

bool TimedFleeingMovementGenerator::Update(Unit* owner, const uint32& time_diff)
{
    if (!owner->isAlive())
        return false;

    if (owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
    {
        owner->ClearUnitState(UNIT_STATE_FLEEING_MOVE);
        return true;
    }

    i_totalFleeTime.Update(time_diff);
    if (i_totalFleeTime.Passed())
        return false;

    // This calls grant-parent Update method hiden by FleeingMovementGenerator::Update(Creature &, const uint32 &) version
    // This is done instead of casting Unit& to Creature& and call parent method, then we can use Unit directly
    return MovementGeneratorMedium< Creature, FleeingMovementGenerator<Creature> >::Update(owner, time_diff);
}

