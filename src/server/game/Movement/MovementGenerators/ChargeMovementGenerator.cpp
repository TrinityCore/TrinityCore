/*
 * Copyright (C) 2019 AtieshCore <https://at-wow.org/>
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

#include "ChargeMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "PathGenerator.h"
#include "Player.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "Unit.h"
#include "Util.h"
#include "World.h"

//----- Charge Movement Generator - Normal
template<class T>
ChargeMovementGenerator<T>::ChargeMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, float speed, Optional<float> finalOrient) : _movementId(id), _x(x), _y(y), _z(z), _speed(speed), _generatePath(generatePath), _finalOrient(finalOrient)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_HIGHEST;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_CHARGING;
}

template<class T>
MovementGeneratorType ChargeMovementGenerator<T>::GetMovementGeneratorType() const
{
    return CHARGE_MOTION_TYPE;
}

template<class T>
void ChargeMovementGenerator<T>::DoInitialize(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);
    _path = nullptr;

    Movement::MoveSplineInit init(owner);
    if (_generatePath)
    {
        _path = std::make_unique<PathGenerator>(owner);
        _path->CalculatePath(_x, _y, _z);
        init.MovebyPath(_path->GetPath());
    }
    else
        init.MoveTo(_x, _y, _z, _generatePath);
    if (_speed > 0.0f)
        init.SetVelocity(_speed);
    init.Launch();
    if (_finalOrient)
        init.SetFacing(*_finalOrient);

    owner->SetIsCharging(true);
    // Call for creature group update
    if (Creature* creature = owner->ToCreature())
        creature->SignalFormationMovement(Position(_x, _y, _z), _movementId);
}

template<class T>
void ChargeMovementGenerator<T>::DoReset(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

template<class T>
bool ChargeMovementGenerator<T>::DoUpdate(T* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if (owner->movespline->Finalized())
    {
        MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

template<class T>
void ChargeMovementGenerator<T>::DoDeactivate(T* owner)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

template<class T>
void ChargeMovementGenerator<T>::DoFinalize(T* owner, bool active, bool /*movementInform*/)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
    owner->SetIsCharging(false);
}

template ChargeMovementGenerator<Player>::ChargeMovementGenerator(uint32, float, float, float, bool, float, Optional<float>);
template ChargeMovementGenerator<Creature>::ChargeMovementGenerator(uint32, float, float, float, bool, float, Optional<float>);
template MovementGeneratorType ChargeMovementGenerator<Player>::GetMovementGeneratorType() const;
template MovementGeneratorType ChargeMovementGenerator<Creature>::GetMovementGeneratorType() const;
template void ChargeMovementGenerator<Player>::DoInitialize(Player*);
template void ChargeMovementGenerator<Creature>::DoInitialize(Creature*);
template void ChargeMovementGenerator<Player>::DoReset(Player*);
template void ChargeMovementGenerator<Creature>::DoReset(Creature*);
template bool ChargeMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool ChargeMovementGenerator<Creature>::DoUpdate(Creature*, uint32);
template void ChargeMovementGenerator<Player>::DoDeactivate(Player*);
template void ChargeMovementGenerator<Creature>::DoDeactivate(Creature*);
template void ChargeMovementGenerator<Player>::DoFinalize(Player*, bool, bool);
template void ChargeMovementGenerator<Creature>::DoFinalize(Creature*, bool, bool);


//----- Charge Movement Generator - By Prepared Path
template<class T>
ChargePathMovementGenerator<T>::ChargePathMovementGenerator(uint32 id, float x, float y, float z, PathGenerator const& path, float speed, Optional<float> finalOrient) : _movementId(id), _x(x), _y(y), _z(z), _path(path), _speed(speed),  _finalOrient(finalOrient)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_HIGHEST;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_CHARGING;
}

template<class T>
MovementGeneratorType ChargePathMovementGenerator<T>::GetMovementGeneratorType() const
{
    return CHARGE_MOTION_TYPE;
}

template<class T>
void ChargePathMovementGenerator<T>::DoInitialize(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE))
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);
    init.MovebyPath(_path.GetPath());
    init.SetVelocity(_speed);
    init.Launch();

    owner->SetIsCharging(true);
    // Call for creature group update
    if (Creature* creature = owner->ToCreature())
        creature->SignalFormationMovement(Position(_x, _y, _z), _movementId);
}

template<class T>
void ChargePathMovementGenerator<T>::DoReset(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

template<class T>
bool ChargePathMovementGenerator<T>::DoUpdate(T* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if (owner->movespline->Finalized())
    {
        MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

template<class T>
void ChargePathMovementGenerator<T>::DoDeactivate(T* owner)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

template<class T>
void ChargePathMovementGenerator<T>::DoFinalize(T* owner, bool active, bool /*movementInform*/)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
    owner->SetIsCharging(false);
}

template ChargePathMovementGenerator<Player>::ChargePathMovementGenerator(uint32, float, float, float, PathGenerator const&, float, Optional<float>);
template ChargePathMovementGenerator<Creature>::ChargePathMovementGenerator(uint32, float, float, float, PathGenerator const&, float, Optional<float>);
template MovementGeneratorType ChargePathMovementGenerator<Player>::GetMovementGeneratorType() const;
template MovementGeneratorType ChargePathMovementGenerator<Creature>::GetMovementGeneratorType() const;
template void ChargePathMovementGenerator<Player>::DoInitialize(Player*);
template void ChargePathMovementGenerator<Creature>::DoInitialize(Creature*);
template void ChargePathMovementGenerator<Player>::DoReset(Player*);
template void ChargePathMovementGenerator<Creature>::DoReset(Creature*);
template bool ChargePathMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool ChargePathMovementGenerator<Creature>::DoUpdate(Creature*, uint32);
template void ChargePathMovementGenerator<Player>::DoDeactivate(Player*);
template void ChargePathMovementGenerator<Creature>::DoDeactivate(Creature*);
template void ChargePathMovementGenerator<Player>::DoFinalize(Player*, bool, bool);
template void ChargePathMovementGenerator<Creature>::DoFinalize(Creature*, bool, bool);
