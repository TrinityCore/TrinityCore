/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "CreatureAI.h"
#include "MovementDefines.h"

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

MovementGeneratorType IdleMovementGenerator::GetMovementGeneratorType() const
{
    return IDLE_MOTION_TYPE;
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
    if (_direction == ROTATE_DIRECTION_LEFT)
    {
        angle += float(diff) * float(M_PI) * 2.f / float(_maxDuration);
        while (angle >= float(M_PI) * 2.f)
            angle -= float(M_PI) * 2.f;
    }
    else
    {
        angle -= float(diff) * float(M_PI) * 2.f / float(_maxDuration);
        while (angle < 0.f)
            angle += float(M_PI) * 2.f;
    }

    owner->SetFacingTo(angle);

    if (_duration > diff)
        _duration -= diff;
    else
        return false;

    return true;
}

MovementGeneratorType RotateMovementGenerator::GetMovementGeneratorType() const
{
    return ROTATE_MOTION_TYPE;
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

MovementGeneratorType DistractMovementGenerator::GetMovementGeneratorType() const
{
    return DISTRACT_MOTION_TYPE;
}

//----------------------------------------------------//

MovementGeneratorType AssistanceDistractMovementGenerator::GetMovementGeneratorType() const
{
    return ASSISTANCE_DISTRACT_MOTION_TYPE;
}

void AssistanceDistractMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_DISTRACTED);
    owner->ToCreature()->SetReactState(REACT_AGGRESSIVE);
}
