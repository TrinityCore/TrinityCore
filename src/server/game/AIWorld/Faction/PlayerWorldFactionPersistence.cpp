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

#include "PlayerWorldFactionPersistence.h"
#include "DatabaseEnv.h"
#include "Log.h"

WorldFactionId PlayerWorldFactionPersistence::LoadMembership(ObjectGuid characterGuid)
{
    // Fail closed: ai_player_world_faction is keyed by the low GUID counter
    // alone, which a non-Player ObjectGuid (Creature, GameObject, ...) can
    // share with an unrelated player - see this class's own header comment.
    // Never query with an unchecked counter.
    if (!characterGuid.IsPlayer())
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: LoadMembership() called with a non-Player ObjectGuid ({}), refusing to query - treated as Unaffiliated",
            characterGuid.ToString());
        return WorldFactions::Unaffiliated;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_PLAYER_WORLD_FACTION);
    stmt->setUInt32(0, characterGuid.GetCounter());
    PreparedQueryResult result = CharacterDatabase.Query(stmt);
    if (!result)
        return WorldFactions::Unaffiliated;

    Field* fields = result->Fetch();
    return WorldFactionId{ fields[0].GetUInt32() };
}

bool PlayerWorldFactionPersistence::Join(ObjectGuid characterGuid, WorldFactionId faction)
{
    if (!characterGuid.IsPlayer())
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: Join() called with a non-Player ObjectGuid ({}), refusing - no DB access attempted",
            characterGuid.ToString());
        return false;
    }

    // "Joining" Unaffiliated is nonsensical - Unaffiliated is the absence
    // of membership, not a WorldFaction a character can belong to. Refuse
    // before any DB access, the same "never write a row that would violate
    // this table's own invariant" discipline the migration's own comment
    // documents.
    if (!faction)
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: refusing to Join() character guid={} to Unaffiliated - call Leave() instead",
            characterGuid.GetCounter());
        return false;
    }

    // Idempotent no-op if already a member of `faction`: joined_at marks
    // the start of the CURRENT membership, so a retried/duplicate Join()
    // to the same faction must not reset it via REPLACE INTO's own DELETE+
    // INSERT semantics. characterGuid is already known to be a Player GUID
    // here, so this LoadMembership() call cannot itself hit the IsPlayer()
    // guard above.
    if (LoadMembership(characterGuid) == faction)
        return true;

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_AI_PLAYER_WORLD_FACTION);
    stmt->setUInt32(0, characterGuid.GetCounter());
    stmt->setUInt32(1, faction.Value);
    CharacterDatabase.DirectExecute(stmt);

    // DirectExecute() reports no success/failure - confirm with a read-back,
    // the same discipline every other write in this subsystem applies.
    WorldFactionId confirmed = LoadMembership(characterGuid);
    if (confirmed != faction)
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: Join() for character guid={} to worldFactionId={} was not confirmed by read-back",
            characterGuid.GetCounter(), faction.Value);
        return false;
    }

    return true;
}

bool PlayerWorldFactionPersistence::Leave(ObjectGuid characterGuid)
{
    if (!characterGuid.IsPlayer())
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: Leave() called with a non-Player ObjectGuid ({}), refusing - no DB access attempted",
            characterGuid.ToString());
        return false;
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AI_PLAYER_WORLD_FACTION);
    stmt->setUInt32(0, characterGuid.GetCounter());
    CharacterDatabase.DirectExecute(stmt);

    WorldFactionId confirmed = LoadMembership(characterGuid);
    if (confirmed)
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: Leave() for character guid={} was not confirmed by read-back, still shows worldFactionId={}",
            characterGuid.GetCounter(), confirmed.Value);
        return false;
    }

    return true;
}

namespace
{
    // An already-resolved QueryCallback for the IsPlayer() guard's fail-fast
    // path below - no real query is ever issued, but every async method
    // here must still return a genuine QueryCallback (its ~QueryCallback()
    // has to see a valid future either way).
    QueryCallback MakeImmediatelyReadyNullResult()
    {
        std::promise<PreparedQueryResult> promise;
        promise.set_value(PreparedQueryResult(nullptr));
        return QueryCallback(promise.get_future());
    }
}

QueryCallback PlayerWorldFactionPersistence::LoadMembershipAsync(ObjectGuid characterGuid, std::function<void(WorldFactionId)> callback)
{
    if (!characterGuid.IsPlayer())
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: LoadMembershipAsync() called with a non-Player ObjectGuid ({}), refusing to query - treated as Unaffiliated",
            characterGuid.ToString());
        return MakeImmediatelyReadyNullResult().WithPreparedCallback([callback = std::move(callback)](PreparedQueryResult)
        {
            callback(WorldFactions::Unaffiliated);
        });
    }

    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_PLAYER_WORLD_FACTION);
    stmt->setUInt32(0, characterGuid.GetCounter());

    return CharacterDatabase.AsyncQuery(stmt).WithPreparedCallback([callback = std::move(callback)](PreparedQueryResult result)
    {
        if (!result)
        {
            callback(WorldFactions::Unaffiliated);
            return;
        }

        Field* fields = result->Fetch();
        callback(WorldFactionId{ fields[0].GetUInt32() });
    });
}

QueryCallback PlayerWorldFactionPersistence::JoinAsync(ObjectGuid characterGuid, WorldFactionId faction, std::function<void(bool)> callback)
{
    if (!characterGuid.IsPlayer())
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: JoinAsync() called with a non-Player ObjectGuid ({}), refusing - no DB access attempted",
            characterGuid.ToString());
        return MakeImmediatelyReadyNullResult().WithPreparedCallback([callback = std::move(callback)](PreparedQueryResult)
        {
            callback(false);
        });
    }

    if (!faction)
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: refusing to JoinAsync() character guid={} to Unaffiliated - call LeaveAsync() instead",
            characterGuid.GetCounter());
        return MakeImmediatelyReadyNullResult().WithPreparedCallback([callback = std::move(callback)](PreparedQueryResult)
        {
            callback(false);
        });
    }

    CharacterDatabasePreparedStatement* loadStmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_PLAYER_WORLD_FACTION);
    loadStmt->setUInt32(0, characterGuid.GetCounter());

    // Three chained stages, mirroring WorldSession::HandleCharCreateOpcode()'s
    // own AsyncQuery().WithChainingPreparedCallback(...) shape
    // (CharacterHandler.cpp): (1) load current membership - if already
    // `faction`, stop here (idempotent no-op, joined_at untouched, the same
    // behavior Join() itself has); otherwise queue the write. (2) REPLACE
    // INTO write - queue a confirm read regardless of its own (empty)
    // result. (3) confirm read - the terminal, non-chaining callback that
    // actually reports success/failure to the caller.
    return CharacterDatabase.AsyncQuery(loadStmt)
        .WithChainingPreparedCallback([characterGuid, faction, callback](QueryCallback& queryCallback, PreparedQueryResult loadResult)
    {
        WorldFactionId current = WorldFactions::Unaffiliated;
        if (loadResult)
        {
            Field* fields = loadResult->Fetch();
            current = WorldFactionId{ fields[0].GetUInt32() };
        }

        if (current == faction)
        {
            callback(true);
            return;
        }

        CharacterDatabasePreparedStatement* writeStmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_AI_PLAYER_WORLD_FACTION);
        writeStmt->setUInt32(0, characterGuid.GetCounter());
        writeStmt->setUInt32(1, faction.Value);
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(writeStmt));
    })
        .WithChainingPreparedCallback([characterGuid](QueryCallback& queryCallback, PreparedQueryResult /*writeResult*/)
    {
        CharacterDatabasePreparedStatement* confirmStmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_PLAYER_WORLD_FACTION);
        confirmStmt->setUInt32(0, characterGuid.GetCounter());
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(confirmStmt));
    })
        .WithPreparedCallback([characterGuid, faction, callback](PreparedQueryResult confirmResult)
    {
        bool confirmed = false;
        if (confirmResult)
        {
            Field* fields = confirmResult->Fetch();
            confirmed = WorldFactionId{ fields[0].GetUInt32() } == faction;
        }

        if (!confirmed)
            TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: JoinAsync() for character guid={} to worldFactionId={} was not confirmed by read-back",
                characterGuid.GetCounter(), faction.Value);

        callback(confirmed);
    });
}

QueryCallback PlayerWorldFactionPersistence::LeaveAsync(ObjectGuid characterGuid, std::function<void(bool)> callback)
{
    if (!characterGuid.IsPlayer())
    {
        TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: LeaveAsync() called with a non-Player ObjectGuid ({}), refusing - no DB access attempted",
            characterGuid.ToString());
        return MakeImmediatelyReadyNullResult().WithPreparedCallback([callback = std::move(callback)](PreparedQueryResult)
        {
            callback(false);
        });
    }

    CharacterDatabasePreparedStatement* deleteStmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AI_PLAYER_WORLD_FACTION);
    deleteStmt->setUInt32(0, characterGuid.GetCounter());

    return CharacterDatabase.AsyncQuery(deleteStmt)
        .WithChainingPreparedCallback([characterGuid](QueryCallback& queryCallback, PreparedQueryResult /*deleteResult*/)
    {
        CharacterDatabasePreparedStatement* confirmStmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AI_PLAYER_WORLD_FACTION);
        confirmStmt->setUInt32(0, characterGuid.GetCounter());
        queryCallback.SetNextQuery(CharacterDatabase.AsyncQuery(confirmStmt));
    })
        .WithPreparedCallback([characterGuid, callback](PreparedQueryResult confirmResult)
    {
        bool confirmed = !confirmResult;
        if (!confirmed)
        {
            Field* fields = confirmResult->Fetch();
            TC_LOG_ERROR("ai.world", "AI player WorldFaction membership: LeaveAsync() for character guid={} was not confirmed by read-back, still shows worldFactionId={}",
                characterGuid.GetCounter(), fields[0].GetUInt32());
        }

        callback(confirmed);
    });
}
