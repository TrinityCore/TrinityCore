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

#include "PointMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "Player.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "World.h"

//----- Point Movement Generator

template<class T>
MovementGeneratorType PointMovementGenerator<T>::GetMovementGeneratorType() const
{
    return POINT_MOTION_TYPE;
}

template<class T>
void PointMovementGenerator<T>::DoInitialize(T* owner)
{
    if (_movementId == EVENT_CHARGE_PREPATH)
    {
        owner->AddUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING);

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        _interrupt = true;
        owner->StopMoving();
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);
    init.MoveTo(_x, _y, _z , _generatePath);
    if (_speed > 0.0f)
        init.SetVelocity(_speed);

    if (_finalOrient)
        init.SetFacing(*_finalOrient);

    init.Launch();

    // Call for creature group update
    if (Creature* creature = owner->ToCreature())
        creature->SignalFormationMovement(Position(_x, _y, _z), _movementId);
}

template<class T>
bool PointMovementGenerator<T>::DoUpdate(T* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (_movementId == EVENT_CHARGE_PREPATH)
        return !owner->movespline->Finalized();

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        _interrupt = true;
        owner->StopMoving();
        return true;
    }

    if ((_interrupt && owner->movespline->Finalized()) || (_recalculateSpeed && !owner->movespline->Finalized()))
    {
        _recalculateSpeed = false;
        _interrupt = false;

        owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

        Movement::MoveSplineInit init(owner);
        init.MoveTo(_x, _y, _z, _generatePath);
        if (_speed > 0.0f) // Default value for point motion type is 0.0, if 0.0 spline will use GetSpeed on unit
            init.SetVelocity(_speed);
        init.Launch();

        // Call for creature group update
        if (Creature* creature = owner->ToCreature())
            creature->SignalFormationMovement(Position(_x, _y, _z), _movementId);
    }

    return !owner->movespline->Finalized();
}

template<class T>
void PointMovementGenerator<T>::DoFinalize(T* owner)
{
    owner->ClearUnitState(UNIT_STATE_ROAMING | UNIT_STATE_ROAMING_MOVE);

    if (owner->movespline->Finalized())
        MovementInform(owner);
}

template<class T>
void PointMovementGenerator<T>::DoReset(T* owner)
{
    owner->StopMoving();
    DoInitialize(owner);
}

template<class T>
void PointMovementGenerator<T>::MovementInform(T*) { }

template <>
void PointMovementGenerator<Creature>::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(POINT_MOTION_TYPE, _movementId);
}

template MovementGeneratorType PointMovementGenerator<Player>::GetMovementGeneratorType() const;
template MovementGeneratorType PointMovementGenerator<Creature>::GetMovementGeneratorType() const;
template void PointMovementGenerator<Player>::DoInitialize(Player*);
template void PointMovementGenerator<Creature>::DoInitialize(Creature*);
template void PointMovementGenerator<Player>::DoFinalize(Player*);
template void PointMovementGenerator<Creature>::DoFinalize(Creature*);
template void PointMovementGenerator<Player>::DoReset(Player*);
template void PointMovementGenerator<Creature>::DoReset(Creature*);
template bool PointMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool PointMovementGenerator<Creature>::DoUpdate(Creature*, uint32);

//---- AssistanceMovementGenerator

MovementGeneratorType AssistanceMovementGenerator::GetMovementGeneratorType() const
{
    return ASSISTANCE_MOTION_TYPE;
}

void AssistanceMovementGenerator::Finalize(Unit* owner)
{
    owner->ClearUnitState(UNIT_STATE_ROAMING);
    owner->StopMoving();
    owner->ToCreature()->SetNoCallAssistance(false);
    owner->ToCreature()->CallAssistance();
    if (owner->IsAlive())
        owner->GetMotionMaster()->MoveSeekAssistanceDistract(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY));
}
