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

#include "AgentPersistence.h"
#include "Agent/AgentLocation.h"
#include "Agent/AgentRegistry.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include <string>
#include <unordered_map>
#include <unordered_set>

uint32 AgentPersistence::LoadAgents(AgentRegistry& registry)
{
    uint32 loaded = 0;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENTS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI persistence loaded 0 agents");
        return 0;
    }

    do
    {
        Field* fields = result->Fetch();

        AgentRecord record;
        record.Id = AgentId{ fields[0].GetUInt64() };
        record.Type = AgentType(fields[1].GetUInt8());
        record.MapId = fields[2].GetUInt32();
        record.SpawnId = fields[3].GetUInt64();
        record.RuntimeGuid = ObjectGuid::Empty;
        record.WorldState = AgentWorldState::Abstract;
        record.SnapshotSequence = 0;

        // Milestone 2.11A: home_map_id/work_map_id are the presence check
        // for the whole pair - always NULL or set together, never partial
        // (see ai_agents' own migration comment).
        if (!fields[4].IsNull())
        {
            AgentLocation home;
            home.MapId = fields[4].GetUInt32();
            home.X = fields[5].GetFloat();
            home.Y = fields[6].GetFloat();
            home.Z = fields[7].GetFloat();
            home.Orientation = fields[8].GetFloat();
            record.HomeLocation = home;
        }

        if (!fields[9].IsNull())
        {
            AgentLocation work;
            work.MapId = fields[9].GetUInt32();
            work.X = fields[10].GetFloat();
            work.Y = fields[11].GetFloat();
            work.Z = fields[12].GetFloat();
            work.Orientation = fields[13].GetFloat();
            record.WorkLocation = work;
        }

        // Milestone 2.11E2/2.11E2 P2/P3 fix: NOT NULL columns (default 0) -
        // no presence check needed, unlike home_*/work_* above. money is
        // BIGINT UNSIGNED (GetUInt64), not INT UNSIGNED like food/resource
        // - see AgentEconomyState::Money.
        record.EconomyState.Money = fields[14].GetUInt64();
        record.EconomyState.Food = fields[15].GetUInt32();
        record.EconomyState.Resource = fields[16].GetUInt32();
        record.EconomyState.LastRewardedWorkWindowId = fields[17].GetUInt64();
        record.EconomyState.Version = fields[18].GetUInt64();

        // Milestone 2.12F4A: appended at the end of CHAR_SEL_AI_AGENTS' own
        // column list (see its own comment) - fields[19], not reindexed
        // among the identity columns above. Any value other than the two
        // AgentControlMode enumerators reads as ObserveOnly, never as
        // AIWorldControlled - a corrupted/out-of-range stored value must
        // fail closed, the same discipline AgentGroupKind's own load
        // already applies.
        record.ControlMode = fields[19].GetUInt8() == uint8(AgentControlMode::AIWorldControlled)
            ? AgentControlMode::AIWorldControlled
            : AgentControlMode::ObserveOnly;

        // AI WorldFactionId: appended at the end of CHAR_SEL_AI_AGENTS' own
        // column list one place after control_mode (fields[20]) - see
        // AgentRecord::WorldFaction's own comment. No fail-closed range
        // check needed the way ControlMode's own uint8 does: every uint32
        // value is a structurally valid WorldFactionId (an unrecognized one
        // just resolves to nothing meaningful yet, the same way an unknown
        // CreatureEntry resolves to Unaffiliated in WorldFactionCatalog::
        // Resolve()).
        record.WorldFaction = WorldFactionId{ fields[20].GetUInt32() };

        // Milestone 2.12F4A2 P2 fix (STATIC review): AgentId == SpawnId is
        // a hard identity invariant for a persistent non-instance
        // Creature agent, not an advisory one - a row violating it (e.g.
        // one this migration didn't reach) must not silently keep
        // functioning as a normal agent. Quarantined here: logged and
        // skipped, never reaching AgentRegistry::Add() - no ownership, no
        // actions, the same "don't add anything the identity contract
        // can't vouch for" discipline CreateCreatureAgent() below now
        // also applies. Not a hard ASSERT/crash: a bad row must not take
        // the whole world thread down with it.
        if (record.Id.Value != record.SpawnId)
        {
            TC_LOG_ERROR("ai.world", "AI agent id={} map={} spawn={} violates the AgentId == SpawnId invariant (2.12F4A2), quarantined - not added to the registry",
                record.Id.Value, record.MapId, record.SpawnId);
            continue;
        }

        if (!registry.Add(record))
            continue;

        TC_LOG_INFO("ai.world", "AI agent loaded id={} type={} map={} spawn={} state=ABSTRACT controlMode={} worldFactionId={} home={} work={} money={} food={} resource={} lastRewardedWorkWindowId={} economyVersion={}",
            record.Id.Value, ToString(record.Type), record.MapId, record.SpawnId, ToString(record.ControlMode), record.WorldFaction.Value,
            record.HomeLocation.has_value(), record.WorkLocation.has_value(),
            record.EconomyState.Money, record.EconomyState.Food, record.EconomyState.Resource,
            record.EconomyState.LastRewardedWorkWindowId, record.EconomyState.Version);

        ++loaded;
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI persistence loaded {} agents", loaded);
    return loaded;
}

AgentId AgentPersistence::FindBinding(uint32 mapId, uint64 spawnId)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_BY_BINDING);
    stmt->setUInt32(0, mapId);
    stmt->setUInt64(1, spawnId);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return AgentId{};

    Field* fields = result->Fetch();
    return AgentId{ fields[0].GetUInt64() };
}

AgentId AgentPersistence::CreateCreatureAgent(AgentType type, uint32 mapId, uint64 spawnId)
{
    if (AgentId existingId = FindBinding(mapId, spawnId))
    {
        // Milestone 2.12F4A2 P2 fix (STATIC review): a pre-existing row
        // whose stored agent_id doesn't match this spawnId violates the
        // AgentId == SpawnId invariant (e.g. an unmigrated historical
        // row) - refuse to reuse it rather than silently handing the
        // caller an identity that doesn't describe this spawn, the same
        // fail-closed contract LoadAgents() now applies to a row like
        // this at startup.
        if (existingId.Value != spawnId)
        {
            TC_LOG_ERROR("ai.world", "AgentPersistence: map={} spawn={} already exists in ai_agents as agent id={}, which violates the AgentId == SpawnId invariant (2.12F4A2) - refusing to reuse it",
                mapId, spawnId, existingId.Value);
            return AgentId{};
        }

        TC_LOG_WARN("ai.world", "AgentPersistence: map={} spawn={} already exists in ai_agents as agent id={}, reusing it instead of inserting a duplicate",
            mapId, spawnId, existingId.Value);
        return existingId;
    }

    // Milestone 2.12F4A2: for a persistent non-instance Creature agent,
    // AgentId must equal the TrinityCore Creature SpawnId it is bound to
    // (see AIWorld_Current_Roadmap.md's own "2.12F4A2" section) - agent_id
    // is bound explicitly here instead of being left to the column's own
    // AUTO_INCREMENT default.
    CharacterDatabasePreparedStatement* insertStmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AI_AGENT);
    insertStmt->setUInt64(0, spawnId);
    insertStmt->setUInt8(1, uint8(type));
    insertStmt->setUInt32(2, mapId);
    insertStmt->setUInt64(3, spawnId);
    CharacterDatabase.DirectExecute(insertStmt);

    // DirectExecute() doesn't report success/failure, so the only way to
    // know whether the row actually got stored is to read it back by the
    // unique (map_id, spawn_id) binding - this no longer discovers a
    // MySQL-assigned id (the caller already knows it: spawnId), only
    // confirms the write landed.
    AgentId newId = FindBinding(mapId, spawnId);
    if (!newId)
    {
        TC_LOG_ERROR("ai.world", "AgentPersistence: INSERT for map={} spawn={} did not produce a readable row, agent was not created", mapId, spawnId);
        return newId;
    }

    // Milestone 2.12F4A2 P2 fix (STATIC review): this should be
    // unreachable (the INSERT above always binds agent_id=spawnId), but
    // if it ever isn't true, the caller must not receive an id that
    // violates the very invariant this method exists to establish - fail
    // closed instead of returning a mismatched id.
    if (newId.Value != spawnId)
    {
        TC_LOG_ERROR("ai.world", "AgentPersistence: INSERT for map={} spawn={} produced agent id={}, expected id={} (AgentId == SpawnId invariant violated) - refusing to return it",
            mapId, spawnId, newId.Value, spawnId);
        return AgentId{};
    }

    return newId;
}

namespace
{
    // Milestone 2.12F4B P2 fix (STATIC review): rows/ids per batched raw
    // SQL statement (multi-row INSERT, or an UPDATE ... WHERE id IN (...)
    // - see CreateCreatureAgentsBatch()/PromoteControlModeBatch()) -
    // bounded well under MySQL's default max_allowed_packet (4MB+) even
    // for the widest realistic row ("(18446744073709551615,255,
    // 4294967295,18446744073709551615)," is ~50 bytes; 1000 rows is
    // ~50KB), while still turning a bulk operation over thousands of
    // agents into a small, bounded number of statements instead of one
    // per row/id.
    constexpr std::size_t AgentPersistenceBatchChunkSize = 1000;
}

std::vector<PendingCreatureAgent> AgentPersistence::CreateCreatureAgentsBatch(std::vector<PendingCreatureAgent> const& pending)
{
    std::vector<PendingCreatureAgent> confirmed;
    if (pending.empty())
        return confirmed;

    // Milestone 2.12F4B P2 fix (STATIC review): a genuine multi-row INSERT
    // ... VALUES (...),(...),... , chunked to AgentPersistenceBatchChunkSize
    // rows per statement - see this method's own header comment for why a
    // CharacterDatabaseTransaction of N single-row PreparedStatements
    // (the previous shape here) does NOT avoid N separate statement
    // executions server-side, only N DirectExecute() round trips. Every
    // interpolated value is a plain unsigned integer (SpawnId/AgentType/
    // MapId), never a string/identifier from an untrusted source - see
    // the header comment for why building raw SQL text is safe here.
    // agent_id is bound explicitly to spawnId, the same as
    // CreateCreatureAgent()'s own single-row INSERT above.
    for (std::size_t offset = 0; offset < pending.size(); offset += AgentPersistenceBatchChunkSize)
    {
        std::size_t chunkEnd = offset + AgentPersistenceBatchChunkSize;
        if (chunkEnd > pending.size())
            chunkEnd = pending.size();

        // AI WorldFactionId: agent.WorldFaction is resolved once already,
        // by BuildReconciliationPlan() against WorldFactionCatalog when this
        // PendingCreatureAgent was built - inserted here, not looked up
        // again, the same "resolve once, carry the value" shape SpawnId/
        // Type already have.
        std::string sql = "INSERT INTO ai_agents (agent_id, agent_type, map_id, spawn_id, world_faction_id) VALUES ";
        for (std::size_t i = offset; i < chunkEnd; ++i)
        {
            PendingCreatureAgent const& agent = pending[i];
            if (i != offset)
                sql += ',';

            sql += '(';
            sql += std::to_string(agent.SpawnId);
            sql += ',';
            sql += std::to_string(uint32(uint8(agent.Type)));
            sql += ',';
            sql += std::to_string(agent.MapId);
            sql += ',';
            sql += std::to_string(agent.SpawnId);
            sql += ',';
            sql += std::to_string(agent.WorldFaction.Value);
            sql += ')';
        }

        CharacterDatabase.DirectExecute(sql.c_str());
    }

    // DirectExecute() reports no success/failure (like every
    // DirectExecute()/DirectCommitTransaction() call in this file) -
    // confirm with exactly one bulk read (not one per row, not one per
    // chunk), then only report back the subset that actually landed with
    // agent_id == spawnId. Fail closed per-row, same as CreateCreatureAgent():
    // anything not confirmed is simply not in the returned list, so the
    // caller never adds it to AgentRegistry.
    std::vector<AgentSpawnBinding> bindings = LoadAllBindings();
    std::unordered_set<uint64> confirmedSpawnIds;
    confirmedSpawnIds.reserve(bindings.size());
    for (AgentSpawnBinding const& binding : bindings)
        if (binding.Id.Value == binding.SpawnId)
            confirmedSpawnIds.insert(binding.SpawnId);

    confirmed.reserve(pending.size());
    for (PendingCreatureAgent const& agent : pending)
    {
        if (confirmedSpawnIds.find(agent.SpawnId) != confirmedSpawnIds.end())
            confirmed.push_back(agent);
        else
            TC_LOG_ERROR("ai.world", "AgentPersistence: batch INSERT for map={} spawn={} was not confirmed by read-back, skipped - will be retried by the next reconciliation",
                agent.MapId, agent.SpawnId);
    }

    return confirmed;
}

std::vector<AgentSpawnBinding> AgentPersistence::LoadAllBindings()
{
    std::vector<AgentSpawnBinding> bindings;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_BINDINGS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return bindings;

    bindings.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();

        AgentSpawnBinding binding;
        binding.Id = AgentId{ fields[0].GetUInt64() };
        binding.MapId = fields[1].GetUInt32();
        binding.SpawnId = fields[2].GetUInt64();
        bindings.push_back(binding);
    } while (result->NextRow());

    return bindings;
}

std::vector<AgentId> AgentPersistence::PromoteControlModeBatch(std::vector<AgentId> const& ids)
{
    std::vector<AgentId> promoted;
    if (ids.empty())
        return promoted;

    // Milestone 2.12F4B3 P2 fix (STATIC review): chunked "UPDATE ai_agents
    // SET control_mode = 1 WHERE agent_id IN (...)" raw SQL, but every
    // chunk is Append()ed to ONE CharacterDatabaseTransaction and
    // committed together via a single DirectCommitTransaction() - never N
    // independent DirectExecute() calls. AIWorldMgr::
    // RunZoneControlActivation()'s own caller-side check (all-or-nothing
    // at the "is every scoped spawn reconciled" level) does not by itself
    // guarantee the DB WRITE is all-or-nothing too - if chunk 3 of N
    // failed independently after chunks 1-2 already committed, the result
    // is exactly the partially-Controlled zone this milestone's target
    // state rules out. A CharacterDatabaseTransaction genuinely provides
    // that here: MySQLConnection::ExecuteTransaction() wraps every
    // appended element (raw SQL included - Transaction<T>::Append(char
    // const*) is a real, already-used API, see e.g. PlayerDump.cpp) in
    // one START TRANSACTION/COMMIT, rolling back the whole transaction if
    // any element fails. This is a different requirement than
    // CreateCreatureAgentsBatch()'s own multi-row INSERT deliberately NOT
    // using a transaction of N statements (that decision was about round-
    // trip count, not atomicity - a single Missing row failing to insert
    // is self-healing on the next reconciliation regardless of the other
    // rows; a half-promoted zone is not equivalently safe to leave as-is).
    // Every interpolated id is a plain unsigned integer from
    // AgentId::Value, never an untrusted string.
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (std::size_t offset = 0; offset < ids.size(); offset += AgentPersistenceBatchChunkSize)
    {
        std::size_t chunkEnd = offset + AgentPersistenceBatchChunkSize;
        if (chunkEnd > ids.size())
            chunkEnd = ids.size();

        std::string sql = "UPDATE ai_agents SET control_mode = ";
        sql += std::to_string(uint32(uint8(AgentControlMode::AIWorldControlled)));
        sql += " WHERE agent_id IN (";
        for (std::size_t i = offset; i < chunkEnd; ++i)
        {
            if (i != offset)
                sql += ',';
            sql += std::to_string(ids[i].Value);
        }
        sql += ')';

        trans->Append(sql.c_str());
    }
    CharacterDatabase.DirectCommitTransaction(trans);

    // DirectCommitTransaction() reports no success/failure either - even
    // though the write is now atomic, still confirm with exactly one bulk
    // read (LoadAllControlModes(), the whole table, not one per id/chunk),
    // then only report back the subset actually confirmed AIWorldControlled.
    // Fail closed: anything not confirmed is simply not in the returned
    // list, so the caller must not mark it promoted in memory - it keeps
    // whatever ControlMode it already had.
    std::unordered_map<uint64, AgentControlMode> controlModes = LoadAllControlModes();
    promoted.reserve(ids.size());
    for (AgentId const& id : ids)
    {
        auto it = controlModes.find(id.Value);
        if (it != controlModes.end() && it->second == AgentControlMode::AIWorldControlled)
            promoted.push_back(id);
        else
            TC_LOG_ERROR("ai.world", "AgentPersistence: batch ControlMode promotion for agent id={} was not confirmed by read-back", id.Value);
    }

    return promoted;
}

std::unordered_map<uint64, AgentControlMode> AgentPersistence::LoadAllControlModes()
{
    std::unordered_map<uint64, AgentControlMode> controlModes;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_CONTROL_MODES);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return controlModes;

    controlModes.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();

        uint64 agentId = fields[0].GetUInt64();
        AgentControlMode mode = fields[1].GetUInt8() == uint8(AgentControlMode::AIWorldControlled)
            ? AgentControlMode::AIWorldControlled
            : AgentControlMode::ObserveOnly;
        controlModes.emplace(agentId, mode);
    } while (result->NextRow());

    return controlModes;
}

bool AgentPersistence::SetControlMode(AgentId id, AgentControlMode mode)
{
    // Startup-only, synchronous (CONNECTION_SYNCH/DirectExecute()), the
    // same pattern CreateCreatureAgent() above already uses - never called
    // from the world update loop.
    CharacterDatabasePreparedStatement* updateStmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AI_AGENT_CONTROL_MODE);
    updateStmt->setUInt8(0, uint8(mode));
    updateStmt->setUInt64(1, id.Value);
    CharacterDatabase.DirectExecute(updateStmt);

    // Milestone 2.12F4A P2 fix (STATIC review, round 2): DirectExecute()
    // doesn't report success/failure, and "the caller already knows id and
    // mode" (this method's own original reasoning) is not the same as the
    // write having actually landed - the exact gap the review caught. Read
    // the row back and compare, the same discipline CreateCreatureAgent()
    // already applies to its own INSERT via FindBinding().
    CharacterDatabasePreparedStatement* selectStmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_CONTROL_MODE);
    selectStmt->setUInt64(0, id.Value);
    PreparedQueryResult result = CharacterDatabase.Query(selectStmt);
    if (!result)
    {
        TC_LOG_ERROR("ai.world", "AgentPersistence: ControlMode UPDATE for agent id={} could not be confirmed, no such row on read-back", id.Value);
        return false;
    }

    Field* fields = result->Fetch();
    bool confirmed = fields[0].GetUInt8() == uint8(mode);
    if (!confirmed)
        TC_LOG_ERROR("ai.world", "AgentPersistence: ControlMode UPDATE for agent id={} to {} was not confirmed by read-back", id.Value, ToString(mode));

    return confirmed;
}

std::vector<std::pair<AgentId, WorldFactionId>> AgentPersistence::ReconcileWorldFactionsBatch(std::vector<std::pair<AgentId, WorldFactionId>> const& mismatches)
{
    std::vector<std::pair<AgentId, WorldFactionId>> confirmed;
    if (mismatches.empty())
        return confirmed;

    // Unlike PromoteControlModeBatch()'s single target value
    // (AIWorldControlled), a WorldFactionCatalog refresh pass can produce
    // several different target WorldFactionId values in one pass (e.g. one
    // zone's census resolves to a mix of DEFIAS_BROTHERHOOD/ELWYNN_WOLVES/
    // Unaffiliated) - grouped here so each distinct target value becomes
    // its own chunked `UPDATE ... WHERE agent_id IN (...)`, all still
    // appended to ONE CharacterDatabaseTransaction/DirectCommitTransaction()
    // for the same atomicity reason PromoteControlModeBatch() already
    // documents. Every interpolated value is a plain unsigned integer
    // (AgentId::Value/WorldFactionId::Value), never an untrusted string.
    std::unordered_map<uint32, std::vector<uint64>> idsByTargetFaction;
    for (auto const& mismatch : mismatches)
        idsByTargetFaction[mismatch.second.Value].push_back(mismatch.first.Value);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    for (auto const& targetGroup : idsByTargetFaction)
    {
        std::vector<uint64> const& ids = targetGroup.second;
        for (std::size_t offset = 0; offset < ids.size(); offset += AgentPersistenceBatchChunkSize)
        {
            std::size_t chunkEnd = offset + AgentPersistenceBatchChunkSize;
            if (chunkEnd > ids.size())
                chunkEnd = ids.size();

            std::string sql = "UPDATE ai_agents SET world_faction_id = ";
            sql += std::to_string(targetGroup.first);
            sql += " WHERE agent_id IN (";
            for (std::size_t i = offset; i < chunkEnd; ++i)
            {
                if (i != offset)
                    sql += ',';
                sql += std::to_string(ids[i]);
            }
            sql += ')';

            trans->Append(sql.c_str());
        }
    }
    CharacterDatabase.DirectCommitTransaction(trans);

    // DirectCommitTransaction() reports no success/failure - confirm with
    // exactly one bulk LoadAllWorldFactions() read (not one per id/chunk/
    // target group), then only report back the subset actually confirmed
    // at its own intended target value. Fail closed: anything not
    // confirmed is simply not in the returned list, so the caller must not
    // update AgentRecord::WorldFaction in memory for it - it keeps
    // whatever WorldFaction it already had, the same discipline
    // PromoteControlModeBatch() already applies to ControlMode.
    std::unordered_map<uint64, WorldFactionId> current = LoadAllWorldFactions();
    confirmed.reserve(mismatches.size());
    for (auto const& mismatch : mismatches)
    {
        auto it = current.find(mismatch.first.Value);
        if (it != current.end() && it->second == mismatch.second)
            confirmed.push_back(mismatch);
        else
            TC_LOG_ERROR("ai.world", "AgentPersistence: batch WorldFaction reconcile for agent id={} to worldFactionId={} was not confirmed by read-back",
                mismatch.first.Value, mismatch.second.Value);
    }

    return confirmed;
}

std::unordered_map<uint64, WorldFactionId> AgentPersistence::LoadAllWorldFactions()
{
    std::unordered_map<uint64, WorldFactionId> factions;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_AGENT_WORLD_FACTIONS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return factions;

    factions.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        factions.emplace(fields[0].GetUInt64(), WorldFactionId{ fields[1].GetUInt32() });
    } while (result->NextRow());

    return factions;
}

void AgentPersistence::SaveEconomyState(AgentId id, AgentEconomyState& state)
{
    // 2.11E2 P3 fix: unconditional, first thing, regardless of what the
    // caller already did - see this method's own header comment for why
    // the bump lives here rather than being trusted to every caller.
    ++state.Version;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_AI_AGENT_ECONOMY);
    stmt->setUInt64(0, state.Money);
    stmt->setUInt32(1, state.Food);
    stmt->setUInt32(2, state.Resource);
    stmt->setUInt64(3, state.LastRewardedWorkWindowId);
    stmt->setUInt64(4, state.Version);
    stmt->setUInt64(5, id.Value);

    // Milestone 2.11E2 P3 fix: bound again for the statement's own
    // "AND economy_version < ?" guard - see AgentEconomyState::Version and
    // CHAR_UPD_AI_AGENT_ECONOMY's own comment for why.
    stmt->setUInt64(6, state.Version);

    // Fire-and-forget by design - see the class comment. The world update
    // thread must never wait on this.
    CharacterDatabase.Execute(stmt);
}
