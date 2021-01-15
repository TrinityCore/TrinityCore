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

#include "IdleMovementGenerator.h"
#include "CreatureAI.h"
#include "Creature.h"
#include <G3D/g3dmath.h>

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

//----------------------------------------------------//

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
    angle += (float(diff) * static_cast<float>(M_PI * 2) / _maxDuration) * (_direction == ROTATE_DIRECTION_LEFT ? 1.0f : -1.0f);
    angle = G3D::wrap(angle, 0.0f, float(G3D::twoPi()));

    owner->SetOrientation(angle);   // UpdateSplinePosition does not set orientation with UNIT_STATE_ROTATING
    owner->SetFacingTo(angle);      // Send spline movement to clients

    if (_duration > diff)
        _duration -= diff;
    else
        return false;

    return true;
}

void RotateMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_ROTATING);
    if (owner->GetTypeId() == TYPEID_UNIT)
        owner->ToCreature()->AI()->MovementInform(ROTATE_MOTION_TYPE, 0);
}

//----------------------------------------------------//

void DistractMovementGenerator::Initialize(Unit* owner)
{
    // Distracted creatures stand up if not standing
    if (!owner->IsStandState())
        owner->SetStandState(UNIT_STAND_STATE_STAND);

    owner->AddUnitState(UNIT_STATE_DISTRACTED);
}

void DistractMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_DISTRACTED);

    // If this is a creature, then return orientation to original position (for idle movement creatures)
    if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature())
    {
        float angle = owner->ToCreature()->GetHomePosition().GetOrientation();
        owner->SetFacingTo(angle);
    }
}

bool DistractMovementGenerator::Update(Unit* /*owner*/, uint32 diff)
{
    if (diff > _timer)
        return false;

    _timer -= diff;
    return true;
}

//----------------------------------------------------//

void AssistanceDistractMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_DISTRACTED);
    owner->ToCreature()->SetReactState(REACT_AGGRESSIVE);
}
