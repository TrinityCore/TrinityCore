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

#ifndef AIWORLD_AGENTPERSISTENCE_H
#define AIWORLD_AGENTPERSISTENCE_H

#include "Agent/AgentEconomyState.h"
#include "Agent/AgentId.h"
#include "Agent/AgentSpawnBinding.h"
#include "Agent/AgentType.h"
#include "Agent/PendingCreatureAgent.h"
#include "Define.h"
#include "Faction/WorldFactionId.h"
#include <unordered_map>
#include <utility>
#include <vector>

class AgentRegistry;

// Characters-DB-backed persistence for agent identity (the ai_agents
// table). Deliberately narrow for Milestone 2.2A: only AgentId/AgentType/
// MapId/SpawnId survive a restart. RuntimeGuid and WorldState are never
// written here - every agent LoadAgents() produces starts Abstract with an
// empty RuntimeGuid, regardless of what it was before shutdown, and
// SnapshotSequence is not persisted either. It only protects requests
// within one process's lifetime; no request from a previous run can
// legitimately still be in flight after a restart.
//
// characters DB was picked over world DB (static content, not realm
// runtime state) and over a fourth AI-specific database (not justified
// yet for one table).
//
// Milestone 2.12F4A2 (P2 fix, STATIC review round 2: namespace policy
// locked, not deferred to 2.12F4B): for a persistent non-instance
// Creature agent, AgentId.Value equals the TrinityCore Creature SpawnId
// it is bound to, and that is the ONLY namespace agent_id ever comes
// from - CreateCreatureAgent() binds it explicitly (=spawnId), and
// ai_agents.agent_id is no longer AUTO_INCREMENT at all (see
// AIWorld_Current_Roadmap.md's own "2.12F4A2" section and the
// 2026_08_30_01 migration's own comment) - no auto-generated id can ever
// collide with a real spawn_id-derived one. A future non-creature
// AgentType must get its own disjoint namespace or its own table, never
// a value silently auto-assigned into this one. This database layer has
// no last-insert-id support, so CreateCreatureAgent() still reads the row
// back by the unique (map_id, spawn_id) binding - not to discover an
// assigned id (the caller already knows it), only to confirm the write
// actually landed. Both CreateCreatureAgent() and LoadAgents() fail
// closed - refuse to reuse/quarantine, never silently return/load a
// mismatched AgentId - if a stored row's agent_id doesn't actually equal
// its spawn_id.
//
// Synchronous by design: LoadAgents(), CreateCreatureAgent(),
// CreateCreatureAgentsBatch()/LoadAllBindings() (2.12F4B),
// PromoteControlModeBatch()/LoadAllControlModes() (2.12F4B3) are only
// ever meant to be called during AIWorldMgr::Initialize(), never from the
// world update loop. SaveEconomyState() (2.11E2) is the one exception -
// see its own comment for why it is safe from there.
//
// Milestone 2.12D: AgentGroup persistence (ai_agent_groups/
// ai_agent_group_members) is no longer this class's job - see
// AgentGroupPersistence, its own dedicated class, now that a group is not
// an ai_agents row at all (see GroupId.h).
class TC_GAME_API AgentPersistence
{
    public:
        // Loads every row from ai_agents into registry (WorldState =
        // Abstract, RuntimeGuid = Empty, SnapshotSequence = 0). Returns the
        // number of agents loaded.
        uint32 LoadAgents(AgentRegistry& registry);

        // Idempotent against ai_agents itself (not just against what
        // LoadAgents() already saw): if a row for (mapId, spawnId) already
        // exists, its AgentId is reused instead of inserting a duplicate.
        // Otherwise inserts a new row with agent_id bound explicitly to
        // spawnId (Milestone 2.12F4A2 - AgentId == SpawnId for a
        // persistent non-instance Creature agent) and reads it back by
        // that same binding to confirm the write landed. Returns AgentId{}
        // (Value == 0, never a valid id) - the caller must not add
        // anything to an AgentRegistry in that case - if the read-back
        // doesn't find a row (insert didn't land), OR (2.12F4A2 P2 fix,
        // STATIC review) if an existing/just-inserted row's own agent_id
        // does not actually equal spawnId: fail closed rather than hand
        // the caller an identity that violates AgentId == SpawnId.
        AgentId CreateCreatureAgent(AgentType type, uint32 mapId, uint64 spawnId);

        // Milestone 2.12F4B: bulk creation for RunSpawnReconciliation()'s
        // own MISSING set - potentially thousands of rows at once, so
        // unlike CreateCreatureAgent() above this deliberately does NOT do
        // one FindBinding()/read-back round trip per entry (that would be
        // exactly the N+1 bootstrap pattern 2.12F4B must avoid).
        //
        // Milestone 2.12F4B P2 fix (STATIC review): an earlier version
        // batched every row into ONE CharacterDatabaseTransaction and
        // called DirectCommitTransaction() once - reviewed and rejected,
        // because TrinityCore's own transaction execution still runs each
        // queued statement as its own separate execution internally; one
        // CharacterDatabaseTransaction is one COMMIT, not one round trip.
        // This now builds a genuine multi-row `INSERT ... VALUES
        // (...),(...),...` (see AgentPersistenceBatchChunkSize in
        // the .cpp for the per-statement row cap, chosen to stay well
        // under max_allowed_packet) and issues it via DirectExecute() -
        // the one place in this codebase's AIWorld subsystem that builds
        // raw SQL text instead of a fixed-arity PreparedStatement, and
        // deliberately so: every interpolated value is a plain unsigned
        // integer sourced from world.creature/this process's own
        // AgentType enum, never a string/identifier from an untrusted
        // source, so there is no injection surface to guard against here.
        //
        // Confirmed afterward with exactly one bulk LoadAllBindings()
        // read (not one per row, and not one per chunk either). Returns
        // only the subset of `pending` that read-back actually confirms
        // landed with agent_id == spawnId - the caller (AIWorldMgr::
        // RunSpawnReconciliation()) must only add these to AgentRegistry;
        // anything not confirmed is logged and simply reappears as MISSING
        // on the next reconciliation (idempotent, self-healing - never a
        // ghost AgentRecord in the meantime, since it was never added).
        // No-op (empty result, no DB access at all) if pending is empty.
        std::vector<PendingCreatureAgent> CreateCreatureAgentsBatch(std::vector<PendingCreatureAgent> const& pending);

        // Milestone 2.12F4B: lightweight bulk read of every (AgentId,
        // MapId, SpawnId) binding currently in ai_agents - none of
        // LoadAgents()'s other columns. Used both by RunSpawnReconciliation()
        // itself as the diff's "what does ai_agents PHYSICALLY hold"
        // input (2.12F4B P2 fix, STATIC review: NOT built from
        // AgentRegistry - see SpawnReconciliationPlan.h's own comment for
        // why a quarantined row must still be visible here) and
        // internally by CreateCreatureAgentsBatch() above to confirm its
        // own batch write, each with exactly one query regardless of
        // table/batch size.
        std::vector<AgentSpawnBinding> LoadAllBindings();

        // Milestone 2.12F4B3: bulk promotion to AIWorldControlled for
        // AIWorldMgr::RunZoneControlActivation()'s own scoped promotion
        // set - potentially thousands of ids at once, so unlike
        // SetControlMode() below this deliberately does NOT do one UPDATE
        // + one read-back round trip per id (that would be exactly the
        // per-id loop this method exists to avoid). Builds a chunked
        // `UPDATE ai_agents SET control_mode = 1 WHERE agent_id IN
        // (...)` (raw SQL text, same "every interpolated value is a plain
        // trusted integer" reasoning as CreateCreatureAgentsBatch()'s own
        // multi-row INSERT).
        //
        // Milestone 2.12F4B3 P2 fix (STATIC review): all chunks are
        // Append()ed to ONE CharacterDatabaseTransaction and committed
        // together via a single DirectCommitTransaction() - not N
        // independent DirectExecute() calls. This is about atomicity, not
        // round-trip count (a different requirement than
        // CreateCreatureAgentsBatch()'s own multi-row INSERT, which
        // deliberately avoids a transaction of N statements for the
        // opposite reason): RunZoneControlActivation()'s own caller-side
        // "is every scoped spawn already reconciled" check guarantees
        // this only ever runs against a complete candidate set, but
        // without a transaction, one chunk failing independently after an
        // earlier chunk already committed would still leave the exact
        // partially-Controlled zone that check exists to rule out.
        //
        // Confirms with exactly one bulk LoadAllControlModes() read (not
        // one per id/chunk) regardless. Returns only the subset of `ids`
        // confirmed AIWorldControlled by that read-back - the caller must
        // only mark those promoted in memory (AgentRecord::ControlMode);
        // anything not confirmed keeps whatever ControlMode it already
        // had, fail closed, the same discipline CreateCreatureAgentsBatch()
        // already applies. No-op (empty result, no DB access) if ids is
        // empty.
        std::vector<AgentId> PromoteControlModeBatch(std::vector<AgentId> const& ids);

        // Milestone 2.12F4B3: lightweight bulk read of every agent_id's
        // current control_mode - none of LoadAgents()'s other columns.
        // Used internally by PromoteControlModeBatch() above to confirm
        // its own batch UPDATE with exactly one query, regardless of
        // batch size.
        std::unordered_map<uint64, AgentControlMode> LoadAllControlModes();

        // AI WorldFactionId: bulk reconcile-mismatch update for AIWorldMgr::
        // RunSpawnReconciliation()'s own WorldFactionCatalog refresh pass -
        // mirrors PromoteControlModeBatch()'s own chunked-transaction/bulk-
        // readback shape, generalized to more than one target value (see
        // the .cpp for why). Confirmed afterward with exactly one bulk
        // LoadAllWorldFactions() read; returns only the subset of
        // `mismatches` whose read-back world_faction_id actually matches
        // the intended target - the caller must only update
        // AgentRecord::WorldFaction in memory for those, fail closed like
        // every other batch method here. No-op if mismatches is empty.
        std::vector<std::pair<AgentId, WorldFactionId>> ReconcileWorldFactionsBatch(std::vector<std::pair<AgentId, WorldFactionId>> const& mismatches);

        // AI WorldFactionId: lightweight bulk read of every agent_id's
        // current world_faction_id - none of LoadAgents()'s other columns.
        // Used internally by ReconcileWorldFactionsBatch() above to confirm
        // its own batch UPDATE with exactly one query, regardless of batch
        // size.
        std::unordered_map<uint64, WorldFactionId> LoadAllWorldFactions();

        // Milestone 2.12F4A P2 fix (STATIC review): explicit, synchronous
        // ControlMode upgrade for a single already-created agent - startup-
        // only, like CreateCreatureAgent()/LoadAgents() above, never called
        // from the world update loop. CreateCreatureAgent() itself
        // deliberately never sets control_mode, always taking the schema's
        // own ObserveOnly (0) DEFAULT (see CHAR_INS_AI_AGENT's own
        // comment) - correct for every general caller, but wrong for
        // AIWorld.TestSpawnId's own "explicitly chosen AIWorld test agent"
        // fixture, which must become AIWorldControlled the moment it is
        // freshly created, not silently stay at the generic default. A
        // caller that legitimately needs a just-created agent to start
        // AIWorldControlled calls this as its own explicit follow-up step
        // - never something CreateCreatureAgent() infers from a hint or a
        // default parameter.
        //
        // Milestone 2.12F4A P2 fix (STATIC review, round 2): returns
        // whether the UPDATE was actually confirmed by a read-back, not
        // just issued. DirectExecute() itself never reports success/
        // failure (see CreateCreatureAgent()'s own comment on why its
        // INSERT needs a read-back) - the same is true for an UPDATE, so a
        // caller must not set an in-memory AgentRecord::ControlMode to
        // AIWorldControlled, nor treat ownership as granted, until this
        // returns true. On false (row missing, or the DB write silently
        // didn't land) the caller must fail closed and leave the agent at
        // whatever ControlMode it already had in memory.
        bool SetControlMode(AgentId id, AgentControlMode mode);

        // Milestone 2.11E2: fire-and-forget async UPDATE (CONNECTION_ASYNC/
        // Execute(), never CONNECTION_SYNCH/DirectExecute()) - unlike
        // LoadAgents()/CreateCreatureAgent(), this is meant to be called
        // from the world update loop (right after AIWorldMgr mutates
        // AgentRecord::EconomyState in memory) and must never block it on
        // the DB. No read-back/result to report: the in-memory
        // AgentRecord::EconomyState the caller already updated is
        // authoritative for this process's remaining lifetime regardless
        // of whether/when the write actually lands.
        //
        // Milestone 2.11E2 P3 fix: state is a mutable reference, not const
        // - this function increments state.Version itself, unconditionally,
        // as its first step, before persisting. That used to be the
        // caller's job (AIWorldMgr::MutateEconomyAndPersist()), but a
        // convention only holds for callers that go through it; anyone
        // calling SaveEconomyState() directly could still forget the bump
        // and the UPDATE's own "AND economy_version < ?" guard would then
        // silently reject the write. Bumping here instead means every
        // caller that actually persists gets it for free - there is no
        // path to a real DB write that skips it.
        void SaveEconomyState(AgentId id, AgentEconomyState& state);

    private:
        AgentId FindBinding(uint32 mapId, uint64 spawnId);
};

#endif // AIWORLD_AGENTPERSISTENCE_H
