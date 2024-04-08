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

#include "GenericMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "MoveSpline.h"
#include "MovementDefines.h"
#include "ObjectAccessor.h"
#include "Unit.h"

GenericMovementGenerator::GenericMovementGenerator(std::function<void(Movement::MoveSplineInit& init)>&& initializer, MovementGeneratorType type, uint32 id,
    GenericMovementGeneratorArgs&& args)
    : _splineInit(std::move(initializer)), _type(type), _pointId(id), _durationTracksSpline(true), _arrivalSpellId(0)
{
    Mode = MOTION_MODE_DEFAULT;
    Priority = MOTION_PRIORITY_NORMAL;
    Flags = MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING;
    BaseUnitState = UNIT_STATE_ROAMING;
    if (args.ArrivalSpellId)
        _arrivalSpellId = *args.ArrivalSpellId;
    if (args.ArrivalSpellTarget)
        _arrivalSpellTargetGuid = *args.ArrivalSpellTarget;
    if (args.Duration)
    {
        _duration.emplace(*args.Duration);
        _durationTracksSpline = false;
    }
    ScriptResult = std::move(args.ScriptResult);
}

void GenericMovementGenerator::Initialize(Unit* owner)
{
    if (HasFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED) && !HasFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING)) // Resume spline is not supported
    {
        RemoveFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
        AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);
        return;
    }

    RemoveFlag(MOVEMENTGENERATOR_FLAG_INITIALIZATION_PENDING | MOVEMENTGENERATOR_FLAG_DEACTIVATED);
    AddFlag(MOVEMENTGENERATOR_FLAG_INITIALIZED);

    Movement::MoveSplineInit init(owner);
    _splineInit(init);
    int32 duration = init.Launch();
    if (_durationTracksSpline)
        _duration.emplace(duration);
}

void GenericMovementGenerator::Reset(Unit* owner)
{
    Initialize(owner);
}

bool GenericMovementGenerator::Update(Unit* owner, uint32 diff)
{
    if (!owner || HasFlag(MOVEMENTGENERATOR_FLAG_FINALIZED))
        return false;

    // Cyclic splines never expire, so update the duration only if it's not cyclic
    if (_duration)
        _duration->Update(diff);

    if ((_duration && _duration->Passed()) || owner->movespline->Finalized())
    {
        AddFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED);
        return false;
    }
    return true;
}

void GenericMovementGenerator::Deactivate(Unit*)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_DEACTIVATED);
}

void GenericMovementGenerator::Finalize(Unit* owner, bool/* active*/, bool movementInform)
{
    AddFlag(MOVEMENTGENERATOR_FLAG_FINALIZED);

    if (movementInform && HasFlag(MOVEMENTGENERATOR_FLAG_INFORM_ENABLED))
        MovementInform(owner);
}

void GenericMovementGenerator::MovementInform(Unit* owner)
{
    if (_arrivalSpellId)
        owner->CastSpell(ObjectAccessor::GetUnit(*owner, _arrivalSpellTargetGuid), _arrivalSpellId, true);

    SetScriptResult(MovementStopReason::Finished);

    if (Creature* creature = owner->ToCreature())
    {
        if (creature->AI())
            creature->AI()->MovementInform(_type, _pointId);
    }
}
