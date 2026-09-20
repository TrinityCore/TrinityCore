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
