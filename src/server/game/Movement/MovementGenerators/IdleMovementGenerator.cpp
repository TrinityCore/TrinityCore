/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "IdleMovementGenerator.h"
#include "CreatureAI.h"
#include "Creature.h"

IdleMovementGenerator si_idleMovement;

// StopMoving is needed to make unit stop if its last movement generator expires
// But it should not be sent otherwise there are many redundent packets
void IdleMovementGenerator::Initialize(WorldObject* owner)
{
    Reset(owner);
}

void IdleMovementGenerator::Reset(WorldObject* owner)
{
	if (!((Unit *)owner)->IsStopped())
		((Unit *)owner)->StopMoving();
}

void RotateMovementGenerator::Initialize(WorldObject* owner)
{
	if (!((Unit *)owner)->IsStopped())
		((Unit *)owner)->StopMoving();

	if (((Unit *)owner)->GetVictim())
		((Unit *)owner)->SetInFront(((Unit *)owner)->GetVictim());

	((Unit *)owner)->AddUnitState(UNIT_STATE_ROTATING);

	((Unit *)owner)->AttackStop();
}

bool RotateMovementGenerator::Update(WorldObject* owner, uint32 diff)
{
    float angle = owner->GetOrientation();
    if (m_direction == ROTATE_DIRECTION_LEFT)
    {
        angle += (float)diff * static_cast<float>(M_PI * 2) / m_maxDuration;
        while (angle >= static_cast<float>(M_PI * 2)) angle -= static_cast<float>(M_PI * 2);
    }
    else
    {
        angle -= (float)diff * static_cast<float>(M_PI * 2) / m_maxDuration;
        while (angle < 0) angle += static_cast<float>(M_PI * 2);
    }

	((Unit *)owner)->SetFacingTo(angle);

    if (m_duration > diff)
        m_duration -= diff;
    else
        return false;

    return true;
}

void RotateMovementGenerator::Finalize(WorldObject* unit)
{
	((Unit *)unit)->ClearUnitState(UNIT_STATE_ROTATING);
    if (unit->GetTypeId() == TYPEID_UNIT)
      unit->ToCreature()->AI()->MovementInform(ROTATE_MOTION_TYPE, 0);
}

void DistractMovementGenerator::Initialize(WorldObject* owner)
{
    // Distracted creatures stand up if not standing
	if (!((Unit *)owner)->IsStandState())
		((Unit *)owner)->SetStandState(UNIT_STAND_STATE_STAND);

    ((Unit *)owner)->AddUnitState(UNIT_STATE_DISTRACTED);
}

void DistractMovementGenerator::Finalize(WorldObject* owner)
{
	((Unit *)owner)->ClearUnitState(UNIT_STATE_DISTRACTED);

    // If this is a creature, then return orientation to original position (for idle movement creatures)
    if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature())
    {
        float angle = owner->ToCreature()->GetHomePosition().GetOrientation();
		((Unit *)owner)->SetFacingTo(angle);
    }
}

bool DistractMovementGenerator::Update(WorldObject* /*owner*/, uint32 time_diff)
{
    if (time_diff > m_timer)
        return false;

    m_timer -= time_diff;
    return true;
}

void AssistanceDistractMovementGenerator::Finalize(WorldObject* unit)
{
    ((Unit *)unit)->ClearUnitState(UNIT_STATE_DISTRACTED);
    unit->ToCreature()->SetReactState(REACT_AGGRESSIVE);
}
