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

#include "AIWorldMgr.h"
#include "Agent/WolfBehaviorPolicy.h"
#include "Creature.h"
#include "ChaseMovementGenerator.h"
#include "PointMovementGenerator.h"
#include "Log.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ThreatManager.h"

bool AIWorldMgr::IsLivingWolf(AgentRecord const& record) const
{
    return _livingWolvesEnabled && record.ControlMode == AgentControlMode::AIWorldControlled &&
        record.RuntimeGuid.IsCreature() && record.RuntimeGuid.GetEntry() == _wolfLooseFormationProfile.CreatureEntry &&
        record.WorldFaction == _wolfLooseFormationProfile.RequiredWorldFaction;
}

void AIWorldMgr::StopLivingWolfAction(AgentRecord& record, Creature& creature)
{
    if (record.GroupCoordinationGoalState)
        StopInFlightGroupCoordination(record, "WOLF_INDIVIDUAL_PRIORITY", CoordinationStopReason::PreemptedByGoal);

    if (record.ActiveActionState)
    {
        ActiveAction const& action = *record.ActiveActionState;
        if (action.Type == ActionType::Attack && action.Target)
            _actionExecutor.StopAttack(creature, action.Target->Guid);
        else if (action.Type == ActionType::Flee)
            _actionExecutor.StopFlee(creature);
        else if (action.Type == ActionType::MoveTo)
            _actionExecutor.StopMoveTo(creature);
        else if (action.SourceGoal == GoalType::WildlifeRest)
            _actionExecutor.StopWildlifeRest(creature);
        record.ActiveActionState.reset();
    }
    record.ActiveGoalState.reset();
    record.WolfMealTarget.Clear();
    record.WolfActionRuntimeGuid.Clear();
}

// Runs at needs cadence on the world thread. The normal group pipeline still
// owns roaming and hunting; this only arbitrates individual survival and meals.
void AIWorldMgr::UpdateLivingWolf(AgentRecord& record, Creature& creature, uint64 nowMs)
{
    Unit* threat = creature.GetThreatManager().GetCurrentVictim();
    if (threat && (!threat->IsAlive() || !creature.IsValidAttackTarget(threat)))
        threat = nullptr;

    bool fleeing = record.ActiveGoalState && record.ActiveGoalState->Type == GoalType::FleeDanger;
    // Ending our attack also ends its combat reference. Keep a short escape
    // from that same live source instead of cancelling flee on the next tick.
    if (!threat && fleeing && record.ActiveActionState && record.ActiveActionState->Target &&
        !WolfBehaviorPolicy::Elapsed(nowMs, record.ActiveActionState->StartedAtMs, 8000))
    {
        Unit* source = ObjectAccessor::GetUnit(creature, record.ActiveActionState->Target->Guid);
        if (source && source->IsAlive() && creature.IsWithinDistInMap(source, 30.0f))
            threat = source;
    }
    bool minimumEscape = fleeing && record.ActiveActionState &&
        !WolfBehaviorPolicy::Elapsed(nowMs, record.ActiveActionState->StartedAtMs, 8000);
    bool defenseLimit = false;
    if (record.ActiveActionState && record.ActiveActionState->SourceGoal == GoalType::Defend)
    {
        ActiveAction const& action = *record.ActiveActionState;
        defenseLimit = WolfBehaviorPolicy::Elapsed(nowMs, action.StartedAtMs, 30000);
        if (action.Destination)
            defenseLimit = defenseLimit || creature.GetDistance(action.Destination->X,
                action.Destination->Y, action.Destination->Z) > 30.0f;
    }
    bool retreat = threat && (minimumEscape || defenseLimit ||
        WolfBehaviorPolicy::ShouldFlee(record.Needs.HealthPressure, fleeing));
    bool hunting = record.GroupCoordinationGoalState && record.GroupCoordinationGoalState->Type == GoalType::Hunt;

    // Retain the original attempt and its timer while the same action is valid.
    if (record.ActiveActionState && record.ActiveGoalState)
    {
        ActiveAction const& action = *record.ActiveActionState;
        if (action.SourceGoal == GoalType::FleeDanger && retreat &&
            creature.GetMotionMaster()->GetMovementGenerator([](MovementGenerator const* movement)
            { return movement->GetMovementGeneratorType() == FLEEING_MOTION_TYPE; }))
            return;
        if (action.SourceGoal == GoalType::Defend && !retreat && threat && action.Target &&
            action.Target->Guid == threat->GetGUID() && creature.GetVictim() == threat &&
            creature.IsWithinDistInMap(threat, 30.0f) &&
            creature.GetMotionMaster()->GetMovementGenerator([threat](MovementGenerator const* movement)
            {
                auto const* chase = dynamic_cast<ChaseMovementGenerator const*>(movement);
                return chase && chase->GetTarget() == threat;
            }))
            return;
        if (action.SourceGoal == GoalType::WildlifeRest && !threat && !creature.IsInCombat() &&
            creature.IsStopped() && creature.GetStandState() == UNIT_STAND_STATE_SLEEP &&
            !WolfBehaviorPolicy::Elapsed(nowMs, action.StartedAtMs, WolfBehaviorPolicy::RestDurationMs))
            return;
    }

    // A healthy hunter keeps its validated hunt even when its prey fights back.
    if (hunting && !retreat && (!threat || threat->GetGUID() == record.GroupCoordinationGoalState->TargetGuid))
        return;

    GoalType goalType = GoalType::WildlifeRest;
    ActionType actionType = ActionType::Rest;
    Unit* target = nullptr;
    if (retreat)
    {
        goalType = GoalType::FleeDanger;
        actionType = ActionType::Flee;
        target = threat;
    }
    else if (threat)
    {
        goalType = GoalType::Defend;
        actionType = ActionType::Attack;
        target = threat;
    }
    else if (!record.WolfMealTarget.IsEmpty())
    {
        target = ObjectAccessor::GetCreature(creature, record.WolfMealTarget);
        goalType = GoalType::Feed;
        actionType = ActionType::Eat;
    }
    else if (record.ActiveGoalState && record.ActiveGoalState->Type == GoalType::WildlifeRest)
    {
        // A complete sleep lowers fatigue, never health or hunger.
        if (record.ActiveActionState && !creature.IsInCombat() && creature.IsStopped() &&
            creature.GetStandState() == UNIT_STAND_STATE_SLEEP && WolfBehaviorPolicy::Elapsed(nowMs,
                record.ActiveActionState->StartedAtMs, WolfBehaviorPolicy::RestDurationMs))
            record.Needs.Fatigue = 0.0f;
        StopLivingWolfAction(record, creature);
        return;
    }
    else
    {
        // No individual reason to act: let the group roam or acquire prey.
        if (record.ActiveGoalState)
            StopLivingWolfAction(record, creature);
        return;
    }

    ActionValidationContext context;
    context.Materialized = record.WorldState == AgentWorldState::Materialized;
    context.Alive = creature.IsAlive();
    context.ControlMode = record.ControlMode;
    context.MapId = creature.GetMapId();
    context.InCombat = creature.IsInCombat();
    context.HasActiveMovement = creature.GetMotionMaster()->GetCurrentMovementGenerator(MOTION_SLOT_ACTIVE) != nullptr;
    context.DefenseThreatGuid = threat ? threat->GetGUID() : ObjectGuid::Empty;
    context.FleeSourceGuid = context.DefenseThreatGuid;
    context.MealTargetGuid = record.WolfMealTarget;
    if (target)
    {
        context.TargetResolved = true;
        context.TargetAlive = target->IsAlive();
        context.TargetAttackable = creature.IsValidAttackTarget(target);
        context.TargetGuid = target->GetGUID();
        context.TargetEntry = target->GetEntry();
        context.TargetMapId = target->GetMapId();
        context.TargetWithinAttackRange = creature.IsWithinDistInMap(target, goalType == GoalType::Feed ? 5.0f : 30.0f);
        context.TargetInLineOfSight = creature.IsWithinLOSInMap(target);
    }
    if (creature.GetVictim())
        context.ActorCurrentVictimGuid = creature.GetVictim()->GetGUID();

    // Feeding is revalidated throughout its duration. An interruption never
    // awards nutrition, and an unresolved/despawned corpse is not a meal.
    if (goalType == GoalType::Feed && record.ActiveGoalState && record.ActiveActionState &&
        record.ActiveActionState->SourceGoal == GoalType::Feed)
    {
        context.ActiveGoalType = record.ActiveGoalState->Type;
        context.ActiveGoalStartedAtMs = record.ActiveGoalState->StartedAtMs;
        ActionRequest feed;
        feed.Actor = record.Id;
        feed.Type = ActionType::Eat;
        feed.SourceGoal = GoalType::Feed;
        feed.GoalStartedAtMs = context.ActiveGoalStartedAtMs;
        feed.Target = record.ActiveActionState->Target;
        if (!_actionSystem.Validate(feed, context).Allowed)
        {
            StopLivingWolfAction(record, creature);
            return;
        }
        if (!WolfBehaviorPolicy::Elapsed(nowMs, record.ActiveActionState->StartedAtMs, WolfBehaviorPolicy::FeedDurationMs))
            return;
        ActionCompletion meal;
        meal.Actor = record.Id;
        meal.Type = ActionType::Eat;
        meal.SourceGoal = GoalType::Feed;
        meal.GoalStartedAtMs = record.ActiveGoalState->StartedAtMs;
        meal.Status = ActionCompletionStatus::Succeeded;
        meal.Reason = ActionCompletionReason::Consumed;
        meal.CompletedAtMs = nowMs;
        HandleActionCompletion(record, meal);
        _needsSystem.SatisfyHunger(record.Needs);
        StopLivingWolfAction(record, creature);
        TC_LOG_DEBUG("ai.world", "AI living wolf agent={} meal=CONSUMED", record.Id.Value);
        goalType = GoalType::WildlifeRest;
        actionType = ActionType::Rest;
        target = nullptr;
        context.WildlifeRestAllowed = creature.GetStandState() == UNIT_STAND_STATE_STAND;
    }

    // Validate before preempting group movement/combat. A different current
    // victim is cleared only if it belongs to our own recorded attack.
    if (record.ActiveActionState && record.ActiveActionState->Type == ActionType::Attack &&
        record.ActiveActionState->Target && context.ActorCurrentVictimGuid == record.ActiveActionState->Target->Guid)
        context.ActorCurrentVictimGuid.Clear();
    if (goalType == GoalType::Defend && record.ActiveActionState)
    {
        // Only discount the exact movement that StopLivingWolfAction owns.
        // An unrelated charge/knockback must not be replaced by a new chase.
        MovementGenerator* movement = creature.GetMotionMaster()->GetCurrentMovementGenerator(MOTION_SLOT_ACTIVE);
        if (auto* point = dynamic_cast<PointMovementGenerator<Creature>*>(movement))
            if (record.ActiveActionState->Type == ActionType::MoveTo && point->GetId() == ActionExecutor::MovePointId)
                context.HasActiveMovement = false;
        if (auto* chase = dynamic_cast<ChaseMovementGenerator*>(movement))
            if (record.ActiveActionState->Type == ActionType::Attack && record.ActiveActionState->Target &&
                chase->GetTarget() && chase->GetTarget()->GetGUID() == record.ActiveActionState->Target->Guid)
                context.HasActiveMovement = false;
    }
    context.ActiveGoalType = goalType;
    context.ActiveGoalStartedAtMs = nowMs;
    ActionRequest request;
    request.Actor = record.Id;
    request.Type = actionType;
    request.SourceGoal = goalType;
    request.GoalStartedAtMs = nowMs;
    request.FleeFromGuid = context.FleeSourceGuid;
    if (target)
        request.Target = ActionTargetRef{ target->GetGUID(), target->GetEntry() };
    if (!_actionSystem.Validate(request, context).Allowed)
    {
        if (goalType == GoalType::Feed || record.ActiveGoalState)
            StopLivingWolfAction(record, creature);
        return;
    }

    StopLivingWolfAction(record, creature);
    // StopAttack can remove the threat reference; the synchronously captured
    // target is the same one validated above (no asynchronous pointer storage).
    ActionResult result;
    if (actionType == ActionType::Flee)
        result = _actionExecutor.ExecuteFlee(request, creature, *target);
    else if (actionType == ActionType::Attack)
        result = _actionExecutor.ExecuteAttack(request, creature, *target);
    else if (actionType == ActionType::Eat)
        result = _actionExecutor.ExecuteEat(request, creature);
    else
        result = _actionExecutor.ExecuteRest(request, creature);
    if (result.Status != ActionExecutionStatus::Started)
        return;

    ActiveGoal goal;
    goal.Type = goalType;
    goal.Priority = threat ? GoalPriority::Emergency : GoalPriority::Normal;
    goal.StartedAtMs = nowMs;
    record.ActiveGoalState = goal;
    ActiveAction action;
    action.Type = actionType;
    action.SourceGoal = goalType;
    action.GoalStartedAtMs = nowMs;
    action.StartedAtMs = nowMs;
    action.Target = request.Target;
    if (goalType == GoalType::Defend)
        action.Destination = ActionPosition{ creature.GetMapId(), creature.GetPositionX(),
            creature.GetPositionY(), creature.GetPositionZ() };
    record.ActiveActionState = action;
    record.WolfActionRuntimeGuid = creature.GetGUID();
    if (goalType == GoalType::Feed)
        record.WolfMealTarget = target->GetGUID();
    TC_LOG_DEBUG("ai.world", "AI living wolf agent={} action={}", record.Id.Value, ToString(goalType));
}
