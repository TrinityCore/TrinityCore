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

#ifndef AIWORLD_AGENTRECORD_H
#define AIWORLD_AGENTRECORD_H

#include "Action/ActiveAction.h"
#include "Action/PendingEatContinuation.h"
#include "AgentEconomyState.h"
#include "AgentId.h"
#include "AgentLocation.h"
#include "AgentType.h"
#include "Define.h"
#include "Faction/WorldFactionId.h"
#include "Goal/ActiveGoal.h"
#include "Goal/CoordinationStopEvent.h"
#include "Goal/GroupCoordinationGoal.h"
#include "Goal/RoutineActivity.h"
#include "Goal/RoutineGoal.h"
#include "Needs/NeedsState.h"
#include "Needs/NeedsThresholdState.h"
#include "ObjectGuid.h"
#include <optional>

// One persistent agent's registry-owned state. SpawnId/MapId is the stable
// binding to a TrinityCore creature spawn; RuntimeGuid is only the current
// Creature this agent happens to be bound to right now (meaningful only
// while WorldState == Materialized) - never the agent's identity, and never
// a substitute for AgentId. Deliberately holds no Creature*/Map*.
//
// Milestone 2.12D P2 fix (STATIC review): every AgentRecord now names a
// real, individually-bindable TrinityCore creature spawn - there is no
// AgentType whose SpawnId means something else any more. An AgentGroup
// (formerly modeled as a fake AgentRecord with an opaque, reserved-range
// SpawnId - see GroupId.h for why that was wrong) is a completely separate
// identity, owned by AgentGroupRegistry, never by this struct/AgentRegistry.
struct AgentRecord
{
    AgentId Id;
    AgentType Type = AgentType::Civilian;

    // Milestone 2.12F4A: fail-closed default - ObserveOnly, never
    // AIWorldControlled. Every new/default-constructed AgentRecord must
    // start as a TrinityCore/scripted-AI-owned agent AIWorld only
    // observes/state-tracks; nothing may implicitly grant AIWorld control
    // over a Creature just because an AgentRecord now exists for it. See
    // AgentControlMode's own comment (AgentType.h) for the full semantics
    // and AIWorldMgr::OwnsSpawn()/ActionSystem::Validate() for where this
    // is actually enforced. Persistent (ai_agents.control_mode) - loaded
    // by AgentPersistence::LoadAgents(), never mutated per-tick in this
    // milestone (no runtime transition command yet).
    AgentControlMode ControlMode = AgentControlMode::ObserveOnly;

    uint32 MapId = 0;
    uint64 SpawnId = 0;

    // AI WorldFactionId (data/elwynn/factions/README.md) - social/political
    // affiliation, separate from Faction.dbc/FactionTemplate.dbc. Defaults
    // to Unaffiliated, the same fail-closed shape ControlMode above uses:
    // an agent this catalog never classifies (or one loaded before the
    // catalog existed) stays NEUTRAL_UNAFFILIATED, never an arbitrary/
    // guessed affiliation. For a Creature agent, resolved from
    // CreatureSpawnIdentity::Entry via WorldFactionCatalog - see
    // AIWorldMgr::RunSpawnReconciliation()'s own WorldFactionCatalog
    // refresh pass and AgentPersistence::LoadAgents() for where this is
    // set. Persistent (ai_agents.world_faction_id), appended at the end of
    // CHAR_SEL_AI_AGENTS' own column list the same way ControlMode's own
    // control_mode column was (2.12F4A) - see that statement's comment.
    WorldFactionId WorldFaction = WorldFactions::Unaffiliated;

    // Milestone 2.11A: persistent, optional - most agents (e.g. GUARD) have
    // neither. Behavior/capability layer (profession, daily cycle, ...) is
    // deliberately not modeled as its own AgentType - "has a home and a
    // workplace" is expressed purely by both being set here, regardless of
    // AgentType. Pa Maclure happens to be a CIVILIAN, but that is only his
    // identity, not what makes RoutineSystem (2.11B) treat him as routine-
    // eligible; nothing gates on AgentType::Civilian anywhere in that path.
    std::optional<AgentLocation> HomeLocation;
    std::optional<AgentLocation> WorkLocation;

    // Milestone 2.11E2: persistent, not optional - every agent has one
    // (defaulting to zero), unlike HomeLocation/WorkLocation. Only ever
    // mutated by AIWorldMgr::UpdateNeeds() on a WORK ActionCompletion
    // reaching Succeeded/Performed (see ActionCompletion.h) - never on
    // Started alone, and never for REST. Written back to ai_agents via
    // AgentPersistence::SaveEconomyState() (fire-and-forget async, the
    // same pattern MemoryPersistence uses) immediately after the in-memory
    // mutation, so it survives a restart without the world thread ever
    // blocking on the DB.
    AgentEconomyState EconomyState;

    ObjectGuid RuntimeGuid;
    AgentWorldState WorldState = AgentWorldState::Abstract;

    uint64 SnapshotSequence = 0;

    // Milestone 2.6A: owned here, not by NeedsSystem - AgentRecord is
    // already the registry-owned home for an agent's runtime state, and
    // Needs must survive Creature unload/reload the same way everything
    // else here does. Frozen (not updated) while WorldState == Abstract.
    NeedsState Needs;

    // Milestone 2.6C: edge-trigger latch for NeedsThresholdEvent, owned
    // alongside Needs for the same reason - must survive Creature
    // unload/reload so a threshold doesn't spuriously re-fire on the next
    // materialize.
    NeedsThresholdState NeedsThresholds;

    // Milestone 2.7B1: the agent's single currently-selected goal, or
    // empty if none is active. Owned here for the same reason as Needs -
    // must survive Creature unload/reload within this process. Not
    // persisted across restart yet.
    std::optional<ActiveGoal> ActiveGoalState;

    // Milestone 2.11B/2.11C: the agent's current routine destination
    // (GoalType::GoToWork/GoHome), or empty if it has neither HomeLocation/
    // WorkLocation set or ActiveGoalState is currently Emergency (see
    // RoutineSystem::DeriveGoal()). Unlike ActiveGoalState this has no
    // hysteresis of its own - it is a pure function of current time,
    // recomputed fresh every Needs-cadence tick, not persisted across
    // restart. Stored here (rather than only ever a local in UpdateNeeds())
    // so it can be compared tick-over-tick before being reconciled into a
    // MOVE_TO ActionRequest - see AIWorldMgr::UpdateNeeds()'s 2.11C
    // arbitration comment for when that reconciliation is (and is not)
    // allowed to happen. This field only ever holds what routine currently
    // wants; whether that is actually safe to act on right now is decided
    // there, never here.
    std::optional<RoutineGoal> RoutineGoalState;

    // Milestone 2.12F2: the agent's own in-flight group-coordination MOVE_TO
    // attempt (GoalType::Regroup), or empty - the third and LOWEST-priority
    // tier under ActiveGoalState/RoutineGoalState (see AIWorldMgr::
    // UpdateNeeds()'s own arbitration comments). Set only by AIWorldMgr::
    // DispatchGroupMemberActionProposal(), never re-derived every Needs
    // tick the way RoutineGoalState is - see GroupCoordinationGoal.h for
    // why this is ephemeral (cleared on the attempt's own terminal
    // outcome) rather than persistent like RoutineGoalState. Not persisted
    // across restart, the same as ActiveGoalState/RoutineGoalState/
    // ActiveActionState.
    std::optional<GroupCoordinationGoal> GroupCoordinationGoalState;

    // Milestone 2.12G2R P2 fix, round 2 (STATIC review): a historical
    // record of the most recent time THIS agent's own GroupCoordinationGoalState
    // was stopped by a genuine production stop path (UpdateNeeds()'s own
    // COORDINATION_PREEMPTED_BY_GOAL block, or
    // StopInFlightGroupCoordination()'s own COORDINATION_STOPPED_BY_LIFECYCLE
    // path) - see CoordinationStopEvent.h for why this exists and why a
    // natural ARRIVED completion never writes it. Written synchronously by
    // those two call sites only, at the exact moment they stop an
    // in-flight attempt - never by anything else, and never read by any
    // production code path itself (this is pure observability). Runtime-
    // only, not persisted across restart, the same as ActiveActionState/
    // GroupCoordinationGoalState. Deliberately never cleared/reset once
    // written (the 2.12G2R lifecycle test hooks that read this always
    // compare its own StartedAtMs against a specific attempt identity
    // they themselves captured, so a stale event from an older, different
    // attempt can never be mistaken for a current one - there is nothing
    // for clearing it early to protect against).
    std::optional<CoordinationStopEvent> LastCoordinationStop;

    // Milestone 2.11D: what the agent is actually doing right now at its
    // routine destination (Work/Rest), or empty - see
    // RoutineActivitySystem::DeriveActivity() for the reality checks this
    // requires (materialized, alive, no ActiveGoalState/ActiveActionState,
    // actually standing at RoutineGoalState's own target). Unlike
    // RoutineGoalState, StartedAtMs here is stable across ticks while the
    // same activity holds - only set fresh on an actual transition, not
    // recomputed from scratch every tick. Runtime-only, not persisted
    // across restart, the same as RoutineGoalState/ActiveActionState.
    std::optional<RoutineActivity> RoutineActivityState;

    // Milestone 2.8F: the Action currently actually running in TrinityCore
    // for this agent's ActiveGoalState, if any. Set only after
    // ActionExecutor::ExecuteX() has actually returned Started - every
    // path that ends the underlying engine movement (interrupt, goal
    // completion, dematerialization, natural arrival) must also clear
    // this. Not persisted across restart.
    std::optional<ActiveAction> ActiveActionState;

    // Milestone 2.8G P2 fix: a MOVE_TO's arrival at a GET_FOOD target,
    // set by HandleActionCompletion() but deliberately not acted on until
    // UpdateNeeds()'s own goal-selection pass has run this same tick - see
    // PendingEatContinuation.h for why. One-shot; consumed (whether or not
    // it actually produces an Eat) the same tick it is first seen set. Not
    // persisted across restart.
    std::optional<PendingEatContinuation> PendingEat;
};

#endif // AIWORLD_AGENTRECORD_H
