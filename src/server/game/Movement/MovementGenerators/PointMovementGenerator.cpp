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

#include "PointMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "G3DPosition.hpp"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "MoveSpline.h"
#include "MoveSplineInit.h"
#include "PathGenerator.h"
#include "World.h"

//----- Point Movement Generator

PointMovementGenerator::PointMovementGenerator(uint32 id, float x, float y, float z, bool generatePath, Optional<float> speed /*= {}*/, Optional<float> finalOrient /*= {}*/,
    Unit const* faceTarget /*= nullptr*/, Movement::SpellEffectExtraData const* spellEffectExtraData /*= nullptr*/,
    MovementWalkRunSpeedSelectionMode speedSelectionMode /*= MovementWalkRunSpeedSelectionMode::Default*/,
    Optional<float> closeEnoughDistance /*= {}*/, Optional<Scripting::v2::ActionResultSetter<MovementStopReason>>&& scriptResult /*= {}*/)
    : _movementId(id), _destination(x, y, z), _speed(speed), _generatePath(generatePath), _finalOrient(finalOrient),
    i_faceTarget(faceTarget), _speedSelectionMode(speedSelectionMode), _closeEnoughDistance(closeEnoughDistance)
{
    this->Mode = MOTION_MODE_DEFAULT;
    this->Priority = MOTION_PRIORITY_NORMAL;
    this->Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    this->BaseUnitState = UNIT_STATE_ROAMING;
    this->ScriptResult = std::move(scriptResult);

    if (spellEffectExtraData)
        this->i_spellEffectExtra = std::make_unique<Movement::SpellEffectExtraData>(*spellEffectExtraData);
}

MovementGeneratorType PointMovementGenerator::GetMovementGeneratorType() const
{
    return POINT_MOTION_TYPE;
}

void PointMovementGenerator::Initialize(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    if (_movementId == EVENT_CHARGE_PREPATH)
    {
        owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);
        return;
    }

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return;
    }

    owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

    Movement::MoveSplineInit init(owner);
    [&]()
    {
        if (_generatePath)
        {
            PathGenerator path(owner);
            G3D::Vector3 dest = PositionToVector3(_destination);
            bool result = path.CalculatePath(dest.x, dest.y, dest.z, false);
            if (result && !(path.GetPathType() & PATHFIND_NOPATH))
            {
                if (_closeEnoughDistance)
                    path.ShortenPathUntilDist(dest, *_closeEnoughDistance);

                init.MovebyPath(path.GetPath());
                return;
            }
        }

        Position dest = _destination;
        if (_closeEnoughDistance)
            owner->MovePosition(dest, std::min(*_closeEnoughDistance, dest.GetExactDist(owner)), float(M_PI) + owner->GetRelativeAngle(dest));

        init.MoveTo(dest.GetPositionX(), dest.GetPositionY(), dest.GetPositionZ(), false);
    }();
    if (_speed)
        init.SetVelocity(*_speed);
    if (i_faceTarget)
        init.SetFacing(i_faceTarget);
    if (i_spellEffectExtra)
        init.SetSpellEffectExtraData(*i_spellEffectExtra);
    if (_finalOrient)
        init.SetFacing(*_finalOrient);
    switch (_speedSelectionMode)
    {
        case MovementWalkRunSpeedSelectionMode::Default:
            break;
        case MovementWalkRunSpeedSelectionMode::ForceRun:
            init.SetWalk(false);
            break;
        case MovementWalkRunSpeedSelectionMode::ForceWalk:
            init.SetWalk(true);
            break;
        default:
            break;
    }

    init.Launch();

    // Call for creature group update
    if (Creature* creature = owner->ToCreature())
        creature->SignalFormationMovement();
}

void PointMovementGenerator::Reset(Unit* owner)
{
    RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY | MOVEMENTGENERATOR_FLAG_DEACTIVATED);

    Initialize(owner);
}

bool PointMovementGenerator::Update(Unit* owner, uint32 /*diff*/)
{
    if (!owner)
        return false;

    if (_movementId == EVENT_CHARGE_PREPATH)
    {
        if (owner->movespline->Finalized())
        {
            AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
            return false;
        }
        return true;
    }

    if (owner->HasUnitState(UNIT_STATE_NOT_MOVE) || owner->IsMovementPreventedByCasting())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED);
        owner->StopMoving();
        return true;
    }

    if ((HasFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED) && owner->movespline->Finalized()) || (HasFlag(MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING) && !owner->movespline->Finalized()))
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_INTERRUPTED | MOVEMENTGENERATOR_FLAG_SPEED_UPDATE_PENDING);

        owner->AddUnitState(UNIT_STATE_ROAMING_MOVE);

        Movement::MoveSplineInit init(owner);
        init.MoveTo(_destination.GetPositionX(), _destination.GetPositionY(), _destination.GetPositionZ(), _generatePath);
        if (_speed) // Default value for point motion type is 0.0, if 0.0 spline will use GetSpeed on unit
            init.SetVelocity(*_speed);
        init.Launch();

        // Call for creature group update
        if (Creature* creature = owner->ToCreature())
            creature->SignalFormationMovement();
    }

    if (owner->movespline->Finalized())
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_TRANSITORY);
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

void PointMovementGenerator::Deactivate(Unit* owner)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);
}

void PointMovementGenerator::Finalize(Unit* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        MovementInform(owner);
}

void PointMovementGenerator::MovementInform(Unit* owner)
{
    SetScriptResult(MovementStopReason::Finished);

    // deliver EVENT_CHARGE to scripts, EVENT_CHARGE_PREPATH is just internal implementation detail of this movement generator
    uint32 movementId = _movementId == EVENT_CHARGE_PREPATH ? uint32(EVENT_CHARGE) : _movementId;

    if (Creature* creature = owner->ToCreature())
        if (creature->AI())
            creature->AI()->MovementInform(POINT_MOTION_TYPE, movementId);
}

//---- AssistanceMovementGenerator

void AssistanceMovementGenerator::Finalize(Unit* owner, bool active, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
    if (active)
        owner->ClearUnitState(UNIT_STATE_ROAMING_MOVE);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED) && owner->IsCreature())
    {
        Creature* ownerCreature = owner->ToCreature();
        ownerCreature->SetNoCallAssistance(false);
        ownerCreature->CallAssistance();
        if (ownerCreature->IsAlive())
            ownerCreature->GetMotionMaster()->MoveSeekAssistanceDistract(sWorld->getIntConfig(CONFIG_CREATURE_FAMILY_ASSISTANCE_DELAY));
    }
}

MovementGeneratorType AssistanceMovementGenerator::GetMovementGeneratorType() const
{
    return ASSISTANCE_MOTION_TYPE;
}
