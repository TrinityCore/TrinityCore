/*
 * Copyright (C) 2016-2019 AtieshCore <https://at-wow.org/>
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

#include "CreatureAI.h"
#include "Creature.h"
#include "Player.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "JumpMovementGenerator.h"
#include "World.h"

//---- JumpMovementGenerator
template<class T>
JumpMovementGenerator<T>::JumpMovementGenerator(uint32 id, float x, float y, float z, float o, float speedXY, float speedZ, bool hasOrientation, bool setorientationFixed) : _movementId(id), _x(x), _y(y), _z(z), _o(o), _speedXY(speedXY), _speedZ(speedZ), _hasOrientation(hasOrientation), _setorientationFixed(setorientationFixed)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_HIGHEST;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_JUMPING;
}

template<class T>
MovementGeneratorType JumpMovementGenerator<T>::GetMovementGeneratorType() const
{
    return JUMP_MOTION_TYPE;
}

template<class T>
void JumpMovementGenerator<T>::DoInitialize(T* owner)
{
    MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (!owner)
        return;

    // TODO: UNIT_FIELD_FLAGS should not be handled by generators
    //owner->AddUnitState(UNIT_STATE_JUMPING);

    Movement::MoveSplineInit init(owner);
    init.MoveTo(_x, _y, _z, false);
    init.SetParabolic(_speedZ, 0);
    if (_setorientationFixed)
        init.SetOrientationFixed(_setorientationFixed);
    init.SetVelocity(_speedXY);
    if (_hasOrientation)
        init.SetFacing(_o);
    
    owner->SetIsJumping(true);
    init.Launch();
}

template<class T>
void JumpMovementGenerator<T>::DoReset(T* owner)
{
    DoInitialize(owner);
}

template<class T>
bool JumpMovementGenerator<T>::DoUpdate(T* owner, uint32 /*diff*/)
{
    if (!owner || MovementGenerator::HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED))
        return false;

    if (owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
    else
        MovementGenerator::RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);

    if (owner->movespline->Finalized())
    {
        MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

template<class T>
void JumpMovementGenerator<T>::DoDeactivate(T* /*owner*/)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
}

template<class T>
void JumpMovementGenerator<T>::DoFinalize(T* owner, bool /*active*/, bool movementInform)
{
    MovementGenerator::AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (movementInform && MovementGenerator::HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        MovementInform(owner);

    owner->SetIsJumping(false);
}

template<class T>
void JumpMovementGenerator<T>::MovementInform(T*) { }

template <>
void JumpMovementGenerator<Creature>::MovementInform(Creature* owner)
{
    if (owner->AI())
        owner->AI()->MovementInform(JUMP_MOTION_TYPE, _movementId);
}

template JumpMovementGenerator<Player>::JumpMovementGenerator(uint32, float, float, float, float, float, float, bool, bool);
template JumpMovementGenerator<Creature>::JumpMovementGenerator(uint32, float, float, float, float, float, float, bool, bool);
template MovementGeneratorType JumpMovementGenerator<Player>::GetMovementGeneratorType() const;
template MovementGeneratorType JumpMovementGenerator<Creature>::GetMovementGeneratorType() const;
template void JumpMovementGenerator<Player>::DoInitialize(Player*);
template void JumpMovementGenerator<Creature>::DoInitialize(Creature*);
template void JumpMovementGenerator<Player>::DoReset(Player*);
template void JumpMovementGenerator<Creature>::DoReset(Creature*);
template bool JumpMovementGenerator<Player>::DoUpdate(Player*, uint32);
template bool JumpMovementGenerator<Creature>::DoUpdate(Creature*, uint32);
template void JumpMovementGenerator<Player>::DoDeactivate(Player*);
template void JumpMovementGenerator<Creature>::DoDeactivate(Creature*);
template void JumpMovementGenerator<Player>::DoFinalize(Player*, bool, bool);
template void JumpMovementGenerator<Creature>::DoFinalize(Creature*, bool, bool);
