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

#include "WorldFactionReputationCatalog.h"
#include "DatabaseEnv.h"
#include "Log.h"

void WorldFactionReputationCatalog::Load()
{
    _worldFactionToFactionId.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_AI_WORLD_FACTION_REPUTATION_DEFAULTS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI WorldFactionReputationCatalog loaded 0 WorldFactionId -> Faction.dbc id rows (world.ai_world_faction_reputation_defaults empty or missing)");
        return;
    }

    _worldFactionToFactionId.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        uint32 worldFactionId = fields[0].GetUInt32();
        uint32 factionId = fields[1].GetUInt32();
        _worldFactionToFactionId.emplace(worldFactionId, factionId);
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI WorldFactionReputationCatalog loaded {} WorldFactionId -> Faction.dbc id rows", _worldFactionToFactionId.size());
}

bool WorldFactionReputationCatalog::TryResolve(WorldFactionId worldFaction, uint32& outFactionId) const
{
    auto it = _worldFactionToFactionId.find(worldFaction.Value);
    if (it == _worldFactionToFactionId.end())
        return false;

    outFactionId = it->second;
    return true;
}
