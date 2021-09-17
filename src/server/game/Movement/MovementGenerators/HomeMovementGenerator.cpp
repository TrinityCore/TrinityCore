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

#include "HomeMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "Vehicle.h"

template<class T>
HomeMovementGenerator<T>::HomeMovementGenerator()
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_NORMAL;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_ROAMING;
}

template HomeMovementGenerator<Creature>::HomeMovementGenerator();

template<class T>
MovementGeneratorType HomeMovementGenerator<T>::GetMovementGeneratorType() const
{
    return HOME_MOTION_TYPE;
}

template MovementGeneratorType HomeMovementGenerator<Creature>::GetMovementGeneratorType() const;

template<class T>
void HomeMovementGenerator<T>::SetTargetLocation(T*) { }

template<>
void HomeMovementGenerator<Creature>::SetTargetLocation(Creature* owner)
{
    // if we are ROOT/STUNNED/DISTRACTED even after aura clear, finalize on next update - otherwise we would get stuck in evade
    if (owner->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED | UNIT_STATE_DISTRACTED))
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        return;
    }

    owner->ClearUnitState(UNIT_STATE_ALL_ERASABLE & ~UNIT_STATE_EVADE);
    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Position destination = owner->GetHomePosition();
    Movement::MoveSplineInit init(owner);

    /*
     * TODO: maybe this never worked, who knows, top is always this generator, so this code calls GetResetPosition on itself
     *
     * if (owner->GetMotionMaster()->empty() || !owner->GetMotionMaster()->top()->GetResetPosition(owner, x, y, z))
     * {
     *     owner->GetHomePosition(x, y, z, o);
     *     init.SetFacing(o);
     * }
     */

    owner->UpdateAllowedPositionZ(destination.m_positionX, destination.m_positionY, destination.m_positionZ);
    init.MoveTo(PositionToVector3(destination));
    init.SetFacing(destination.GetOrientation());
    init.SetWalk(false);
    init.Launch();
}

template<class T>
void HomeMovementGenerator<T>::DoInitialize(T*) { }

template<>
void HomeMovementGenerator<Creature>::DoInitialize(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    owner->SetNoSearchAssistance(false);

    SetTargetLocation(owner);
}

template<class T>
void HomeMovementGenerator<T>::DoReset(T*) { }

template<>
void HomeMovementGenerator<Creature>::DoReset(Creature* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    DoInitialize(owner);
}

template<class T>
bool HomeMovementGenerator<T>::DoUpdate(T*, uint32)
{
    return false;
}

template<>
bool HomeMovementGenerator<Creature>::DoUpdate(Creature* owner, uint32 /*diff*/)
{
    if (HasFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED) || owner->movespline->Finalized())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

template<class T>
void HomeMovementGenerator<T>::DoDeactivate(T*) { }

template<>
void HomeMovementGenerator<Creature>::DoDeactivate(Creature* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

template<class T>
void HomeMovementGenerator<T>::DoFinalize(T*, bool, bool) { }

template<>
void HomeMovementGenerator<Creature>::DoFinalize(Creature* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE | UNIT_STATE_EVADE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
    {
        if (!owner->HasCanSwimFlagOutOfCombat())
            owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_CAN_SWIM);

        owner->SetSpawnHealth();
        owner->LoadCreaturesAddon();
        if (owner->IsVehicle())
            owner->GetVehicleKit()->Reset(true);
        owner->AI()->JustReachedHome();
    }
}
