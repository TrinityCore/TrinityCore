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
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "Unit.h"

IdleMovementGenerator::IdleMovementGenerator()
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZED;
    BaseUnitState = 0;
}

/*
 *  TODO: "if (!owner->IsStopped())" is useless, each generator cleans their own STATE_MOVE, the result is that StopMoving is almost never called
 *  Old comment: "StopMoving is needed to make unit stop if its last movement generator expires but it should not be sent otherwise there are many redundent packets"
 */
void IdleMovementGenerator::Initialize(Unit* owner)
{
    owner->StopMoving();
}

void IdleMovementGenerator::Reset(Unit* owner)
{
    owner->StopMoving();
}

void IdleMovementGenerator::Deactivate(Unit* /*owner*/)
{
}

void IdleMovementGenerator::Finalize(Unit* /*owner*/, bool/* active*/, bool/* movementInform*/)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
}

MovementGeneratorType IdleMovementGenerator::GetMovementGeneratorType() const
{
    return IDLE_MOTION_TYPE;
}

MovementGenerator* IdleMovementFactory::Create(Unit* /*object*/) const
{
    static IdleMovementGenerator instance;
    return &instance;
}

//----------------------------------------------------//

RotateMovementGenerator::RotateMovementGenerator(uint32 id, RotateDirection direction, Optional<Milliseconds> duration,
    Optional<float> turnSpeed, Optional<float> totalTurnAngle,
    Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult) : _id(id), _duration(duration),
    _turnSpeed(turnSpeed), _totalTurnAngle(totalTurnAngle),
    _direction(direction), _diffSinceLastUpdate(0)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROTATING;
    ScriptResult = std::move(scriptResult);
}

void RotateMovementGenerator::Initialize(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    owner->StopMoving();

    /*
     *  TODO: This code should be handled somewhere else, like MovementInform
     *
     *  if (owner->GetVictim())
     *      owner->SetInFront(owner->GetVictim());
     *
     *  owner->AttackStop();
     */
}
void RotateMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    Initialize(owner);
}

bool RotateMovementGenerator::Update(Unit* owner, uint32 diff)
{
    _diffSinceLastUpdate += diff;

    float currentAngle = owner->GetOrientation();
    float angleDelta = _turnSpeed.value_or(owner->GetSpeed(MOVE_TURN_RATE)) * (float(_diffSinceLastUpdate) / float(IN_MILLISECONDS));

    if (_duration)
        _duration->Update(diff);

    if (_totalTurnAngle)
        _totalTurnAngle = *_totalTurnAngle - angleDelta;

    bool expired = (_duration && _duration->Passed()) || (_totalTurnAngle && _totalTurnAngle < 0.0f);

    if (angleDelta >= MIN_ANGLE_DELTA_FOR_FACING_UPDATE || expired)
    {
        float newAngle = Position::NormalizeOrientation(currentAngle + angleDelta * (_direction == ROTATE_DIRECTION_LEFT ? 1.0f : -1.0f));

        Movement::MoveSplineInit init(owner);
        init.MoveTo(PositionToVector3(owner->GetPosition()), false);
        if (!owner->GetTransGUID().IsEmpty())
            init.DisableTransportPathTransformations();
        init.SetFacing(newAngle);
        init.Launch();

        _diffSinceLastUpdate = 0;
    }

    if (expired)
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }

    return true;
}

void RotateMovementGenerator::Deactivate(Unit*)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
}

void RotateMovementGenerator::Finalize(Unit* owner, bool/* active*/, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (movementInform)
    {
        SetScriptResult(MovementStopReason::Finished);
        if (owner->IsCreature())
            owner->ToCreature()->AI()->MovementInform(ROTATE_MOTION_TYPE, _id);
    }
}

MovementGeneratorType RotateMovementGenerator::GetMovementGeneratorType() const
{
    return ROTATE_MOTION_TYPE;
}

//----------------------------------------------------//

DistractMovementGenerator::DistractMovementGenerator(uint32 timer, float orientation) : _timer(timer), _orientation(orientation)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_HIGHEST;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_DISTRACTED;
}

void DistractMovementGenerator::Initialize(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    // Distracted creatures stand up if not standing
    if (!owner->IsStandState())
        owner->SetStandState(UNIT_STAND_STATE_STAND);

    Movement::MoveSplineInit init(owner);
    init.MoveTo(PositionToVector3(*owner), false);
    if (!owner->GetTransGUID().IsEmpty())
        init.DisableTransportPathTransformations();
    init.SetFacing(_orientation);
    init.Launch();
}

void DistractMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    Initialize(owner);
}

bool DistractMovementGenerator::Update(Unit* owner, uint32 diff)
{
    if (!owner)
        return false;

    if (diff > _timer)
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }

    _timer -= diff;
    return true;
}

void DistractMovementGenerator::Deactivate(Unit*)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
}

void DistractMovementGenerator::Finalize(Unit* owner, bool/* active*/, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    // TODO: This code should be handled somewhere else
    // If this is a creature, then return orientation to original position (for idle movement creatures)
    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && owner->GetTypeId() == TYPEID_UNIT)
    {
        float angle = owner->ToCreature()->GetHomePosition().GetOrientation();
        owner->SetFacingTo(angle);
    }
}

MovementGeneratorType DistractMovementGenerator::GetMovementGeneratorType() const
{
    return DISTRACT_MOTION_TYPE;
}

//----------------------------------------------------//

AssistanceDistractMovementGenerator::AssistanceDistractMovementGenerator(uint32 timer, float orientation) : DistractMovementGenerator(timer, orientation)
{
    Priority = MOTION_PRIORITY_NORMAL;
}

void AssistanceDistractMovementGenerator::Finalize(Unit* owner, bool/* active*/, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && owner->GetTypeId() == TYPEID_UNIT)
        owner->ToCreature()->SetReactState(REACT_AGGRESSIVE);
}

MovementGeneratorType AssistanceDistractMovementGenerator::GetMovementGeneratorType() const
{
    return ASSISTANCE_DISTRACT_MOTION_TYPE;
}
