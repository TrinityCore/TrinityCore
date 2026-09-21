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

#include "ActionExecutor.h"
#include "ChaseMovementGenerator.h"
#include "CombatManager.h"
#include "Creature.h"
#include "MotionMaster.h"
#include "MovementDefines.h"
#include "PointMovementGenerator.h"
#include "SharedDefines.h"
#include "Unit.h"

ActionResult ActionExecutor::ExecuteFlee(ActionRequest const& request, Creature& actor, Unit& fleeSource) const
{
    ActionResult result;
    result.Actor = request.Actor;
    result.Type = request.Type;
    result.SourceGoal = request.SourceGoal;
    result.GoalStartedAtMs = request.GoalStartedAtMs;

    if (request.Type != ActionType::Flee)
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::UnsupportedAction;
        return result;
    }

    // Untimed (time=0): the flee ends when AIWorld's own goal lifecycle
    // (SafetyPressure dropping below retention, or the goal timing out)
    // says it should, via StopFlee() - not on a TrinityCore-owned timer
    // this class would then have to coordinate with.
    actor.GetMotionMaster()->MoveFleeing(&fleeSource);

    result.Status = ActionExecutionStatus::Started;
    result.Reason = ActionExecutionReason::None;
    return result;
}

void ActionExecutor::StopFlee(Creature& actor) const
{
    MotionMaster* motion = actor.GetMotionMaster();

    // StopMoving() halts whatever spline is currently running, unscoped by
    // generator type - if something else (knockback, a charge effect, ...)
    // has since taken over as the active movement generator, FLEE is no
    // longer running and StopMoving() must not touch that unrelated
    // movement. Only call it when FLEE was actually the one still active.
    bool wasActiveFlee = motion->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE;

    motion->Remove(FLEEING_MOTION_TYPE);

    if (wasActiveFlee)
        actor.StopMoving();
}

ActionResult ActionExecutor::ExecuteMoveTo(ActionRequest const& request, Creature& actor) const
{
    ActionResult result;
    result.Actor = request.Actor;
    result.Type = request.Type;
    result.SourceGoal = request.SourceGoal;
    result.GoalStartedAtMs = request.GoalStartedAtMs;

    if (request.Type != ActionType::MoveTo || !request.Destination)
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::UnsupportedAction;
        return result;
    }

    // Defensive mirror of ValidateMoveTo()'s HasActiveMovement check (2.8D
    // P2 fix): the world-thread caller should already have rejected this
    // request via ActionSystem::Validate() before ever reaching here, but
    // MOTION_SLOT_ACTIVE could in principle have changed between that
    // check and this call. MoveTo may only start from an idle actor -
    // adding into an already-occupied active slot could either replace a
    // movement this class doesn't own or queue silently behind it.
    if (actor.GetMotionMaster()->GetCurrentMovementGenerator(MOTION_SLOT_ACTIVE))
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::EngineRejected;
        return result;
    }

    actor.GetMotionMaster()->MovePoint(MovePointId,
        request.Destination->X, request.Destination->Y, request.Destination->Z);

    result.Status = ActionExecutionStatus::Started;
    result.Reason = ActionExecutionReason::None;
    return result;
}

void ActionExecutor::StopMoveTo(Creature& actor) const
{
    MotionMaster* motion = actor.GetMotionMaster();

    // POINT_MOTION_TYPE alone isn't a safe removal key the way
    // FLEEING_MOTION_TYPE is for StopFlee() - scripts/escorts/formations
    // all use it too. Find the specific generator instance this class
    // created, identified by MovePointId, and remove only that one.
    MovementGenerator* ours = motion->GetMovementGenerator([](MovementGenerator const* gen)
    {
        if (gen->GetMovementGeneratorType() != POINT_MOTION_TYPE)
            return false;

        auto const* point = dynamic_cast<PointMovementGenerator<Creature> const*>(gen);
        return point && point->GetId() == MovePointId;
    });

    if (!ours)
        return;

    // Same reasoning as StopFlee(): PointMovementGenerator::DoFinalize()
    // only clears UNIT_STATE_ROAMING_MOVE, it does not itself stop the
    // in-progress spline, and StopMoving() is unscoped by generator
    // instance - only call it when our point movement was actually the
    // active one.
    bool wasActive = motion->GetCurrentMovementGenerator() == ours;

    motion->Remove(ours);

    if (wasActive)
        actor.StopMoving();
}

ActionResult ActionExecutor::ExecuteEat(ActionRequest const& request, Creature& actor) const
{
    ActionResult result;
    result.Actor = request.Actor;
    result.Type = request.Type;
    result.SourceGoal = request.SourceGoal;
    result.GoalStartedAtMs = request.GoalStartedAtMs;

    if (request.Type != ActionType::Eat)
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::UnsupportedAction;
        return result;
    }

    // One-shot animation broadcast only - no UpdateField, no server-side
    // state, no combat/threat/movement side effect, nothing to undo later.
    actor.HandleEmoteCommand(EMOTE_ONESHOT_EAT);

    result.Status = ActionExecutionStatus::Started;
    result.Reason = ActionExecutionReason::None;
    return result;
}

ActionResult ActionExecutor::ExecuteWork(ActionRequest const& request, Creature& actor) const
{
    ActionResult result;
    result.Actor = request.Actor;
    result.Type = request.Type;
    result.SourceGoal = request.SourceGoal;
    result.GoalStartedAtMs = request.GoalStartedAtMs;

    if (request.Type != ActionType::Work)
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::UnsupportedAction;
        return result;
    }

    // One-shot animation broadcast only, same as ExecuteEat() - nothing to
    // undo later. EMOTE_ONESHOT_WORK_CHOPWOOD is a generic manual-labor
    // gesture, a reasonable first pick for any GoToWork destination; a
    // later milestone could vary it per workplace/profession.
    actor.HandleEmoteCommand(EMOTE_ONESHOT_WORK_CHOPWOOD);

    result.Status = ActionExecutionStatus::Started;
    result.Reason = ActionExecutionReason::None;
    return result;
}

ActionResult ActionExecutor::ExecuteRest(ActionRequest const& request, Creature& actor) const
{
    ActionResult result;
    result.Actor = request.Actor;
    result.Type = request.Type;
    result.SourceGoal = request.SourceGoal;
    result.GoalStartedAtMs = request.GoalStartedAtMs;

    if (request.Type != ActionType::Rest)
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::UnsupportedAction;
        return result;
    }

    // Civilian routine rest remains a one-shot gesture. Wildlife sleep
    // owns a persistent posture, released by StopWildlifeRest on completion
    // or interruption (only if that posture is still present).
    if (request.SourceGoal == GoalType::WildlifeRest)
        actor.SetStandState(UNIT_STAND_STATE_SLEEP);
    else
        actor.HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);

    result.Status = ActionExecutionStatus::Started;
    result.Reason = ActionExecutionReason::None;
    return result;
}

void ActionExecutor::StopWildlifeRest(Creature& actor) const
{
    if (actor.GetStandState() == UNIT_STAND_STATE_SLEEP)
        actor.SetStandState(UNIT_STAND_STATE_STAND);
}

ActionResult ActionExecutor::ExecuteAttack(ActionRequest const& request, Creature& actor, Unit& target) const
{
    ActionResult result;
    result.Actor = request.Actor;
    result.Type = request.Type;
    result.SourceGoal = request.SourceGoal;
    result.GoalStartedAtMs = request.GoalStartedAtMs;

    if (request.Type != ActionType::Attack)
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::UnsupportedAction;
        return result;
    }

    if (request.SourceGoal == GoalType::Defend &&
        actor.GetMotionMaster()->GetCurrentMovementGenerator(MOTION_SLOT_ACTIVE))
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::EngineRejected;
        return result;
    }

    // Unit::Attack() itself already handles "switch to melee from an
    // existing non-melee attack on the same victim" / "already this exact
    // victim, nothing to change" - the caller (AIWorldMgr::DispatchHuntAttack())
    // only calls this at all when it is NOT the idempotent "already
    // engaged with this exact target" case, so a Failed return here means
    // Unit::Attack() genuinely refused (dead/evading/GM-mode/etc, see its
    // own rules), not that nothing needed to change.
    if (!actor.Attack(&target, true))
    {
        result.Status = ActionExecutionStatus::Failed;
        result.Reason = ActionExecutionReason::EngineRejected;
        return result;
    }

    actor.GetMotionMaster()->MoveChase(&target);

    result.Status = ActionExecutionStatus::Started;
    result.Reason = ActionExecutionReason::None;
    return result;
}

void ActionExecutor::StopAttack(Creature& actor, ObjectGuid ownedTargetGuid) const
{
    // Milestone 2.12G3D P2 fix (STATIC review): only touches the melee-
    // attack relationship if the actor's own CURRENT victim still IS
    // ownedTargetGuid - never RemoveAllAttackers()/CombatStop(), which
    // would also affect an unrelated victim or unrelated attackers. A
    // no-op here (not the whole method - see below) if the actor is not
    // currently attacking ownedTargetGuid at all.
    Unit* victim = actor.GetVictim();
    if (victim && victim->GetGUID() == ownedTargetGuid)
    {
        // Targeted only - never Unit::CombatStop(), which also calls
        // RemoveAllAttackers() and would silently force every OTHER unit
        // currently attacking this actor to stop fighting it too, an
        // effect entirely unrelated to ending THIS HUNT attempt's own
        // attack on ownedTargetGuid.
        actor.AttackStop();
    }

    // Milestone 2.12G3D P2 fix, round 2 (STATIC review): independent of
    // the block above - AttackStop() never ends the underlying PvE
    // combat/threat reference at all (CombatManager.h's own dev doc: "To
    // end combat between two units, find their CombatReference and call
    // EndCombat"). Looked up directly by ownedTargetGuid regardless of
    // whatever the actor's CURRENT victim happens to be, since a combat
    // reference with THIS HUNT attempt's own target can still exist even
    // when GetVictim() no longer names it (or never did). EndCombat()
    // itself removes the reference from both units' own CombatManager -
    // the iterator from find() is not used again afterward.
    auto const& pveCombatRefs = actor.GetCombatManager().GetPvECombatRefs();
    auto combatRefIt = pveCombatRefs.find(ownedTargetGuid);
    if (combatRefIt != pveCombatRefs.end())
        combatRefIt->second->EndCombat();

    // Milestone 2.12G3D P2 fix, round 3 (STATIC review, confirmed in a
    // real fight): the CHASE_MOTION_TYPE generator MoveChase() started is
    // found and removed by its OWN stored target (AbstractFollower::
    // GetTarget(), which ChaseMovementGenerator publicly inherits) -
    // deliberately NOT gated on the victim check above. TrinityCore
    // already clears Unit::GetVictim() as part of its own death teardown
    // well before this HUNT stop path ever runs for a defeated target, so
    // an earlier version's victim-gated chase removal was never reached -
    // the chase generator stayed fully present in MOTION_SLOT_ACTIVE, and
    // the actor's NEXT HUNT attempt's own MOVE_TO was then rejected
    // (ActorMovementBusy) against a chase toward a corpse. Same "find and
    // remove only the specific instance we can prove is ours" discipline
    // StopMoveTo() already applies to its own POINT_MOTION_TYPE generator
    // - a chase toward a genuinely different target (this actor has
    // already moved on to something else entirely) is left completely
    // untouched.
    MotionMaster* motion = actor.GetMotionMaster();
    MovementGenerator* ownedChase = motion->GetMovementGenerator([ownedTargetGuid](MovementGenerator const* gen)
    {
        if (gen->GetMovementGeneratorType() != CHASE_MOTION_TYPE)
            return false;

        auto const* chase = dynamic_cast<ChaseMovementGenerator const*>(gen);
        Unit const* chaseTarget = chase ? chase->GetTarget() : nullptr;
        return chaseTarget && chaseTarget->GetGUID() == ownedTargetGuid;
    });

    if (!ownedChase)
        return;

    // Same "only halt the active spline if our own generator was actually
    // the one running" discipline StopMoveTo()/StopFlee() already apply.
    bool wasActiveChase = motion->GetCurrentMovementGenerator() == ownedChase;

    motion->Remove(ownedChase);

    if (wasActiveChase)
        actor.StopMoving();
}
