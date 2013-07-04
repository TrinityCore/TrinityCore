/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include <G3D/g3dmath.h>

IdleMovementGenerator si_idleMovement;

// StopMoving is needed to make unit stop if its last movement generator expires
// But it should not be sent otherwise there are many redundent packets
void IdleMovementGenerator::Initialize(Unit* owner)
{
    Reset(owner);
}

void IdleMovementGenerator::Reset(Unit* owner)
{
    if (!owner->IsStopped())
        owner->StopMoving();
}

void RotateMovementGenerator::Initialize(Unit* owner)
{
    if (!owner->IsStopped())
        owner->StopMoving();

    if (owner->GetVictim())
        owner->SetInFront(owner->GetVictim());

    owner->AddUnitState(UNIT_STATE_ROTATING);
    owner->AttackStop();
}

bool RotateMovementGenerator::Update(Unit* owner, uint32 diff)
{
    float angle = owner->GetOrientation();
    angle += (float(diff) * static_cast<float>(M_PI * 2) / m_maxDuration) * (m_direction == ROTATE_DIRECTION_LEFT ? 1.0f : -1.0f);
    angle = G3D::wrap(angle, 0.0f, float(G3D::twoPi()));

    owner->SetOrientation(angle);   // UpdateSplinePosition does not set orientation with UNIT_STATE_ROTATING
    owner->SetFacingTo(angle);      // Send spline movement to clients

    if (m_duration > diff)
        m_duration -= diff;
    else
        return false;

    return true;
}

void RotateMovementGenerator::Finalize(Unit* unit)
{
    unit->ClearUnitState(UNIT_STATE_ROTATING);
    if (unit->GetTypeId() == TYPEID_UNIT)
      unit->ToCreature()->AI()->MovementInform(ROTATE_MOTION_TYPE, 0);
}

void DistractMovementGenerator::Initialize(Unit* owner)
{
    owner->AddUnitState(UNIT_STATE_DISTRACTED);
}

void DistractMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_DISTRACTED);
}

bool DistractMovementGenerator::Update(Unit* /*owner*/, uint32 time_diff)
{
    if (time_diff > m_timer)
        return false;

    m_timer -= time_diff;
    return true;
}

void AssistanceDistractMovementGenerator::Finalize(Unit* unit)
{
    unit->ClearUnitState(UNIT_STATE_DISTRACTED);
    unit->ToCreature()->SetReactState(REACT_AGGRESSIVE);
}
