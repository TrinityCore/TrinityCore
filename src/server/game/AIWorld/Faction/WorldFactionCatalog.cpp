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

#include "WorldFactionCatalog.h"
#include "DatabaseEnv.h"
#include "Log.h"

void WorldFactionCatalog::Load()
{
    _entryToWorldFaction.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_AI_WORLD_FACTION_ENTRY_DEFAULTS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI WorldFactionCatalog loaded 0 creature_entry -> WorldFaction defaults (world.ai_world_faction_entry_defaults empty or missing)");
        return;
    }

    _entryToWorldFaction.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        uint32 creatureEntry = fields[0].GetUInt32();
        uint32 worldFactionId = fields[1].GetUInt32();
        _entryToWorldFaction.emplace(creatureEntry, WorldFactionId{ worldFactionId });
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI WorldFactionCatalog loaded {} creature_entry -> WorldFaction defaults", _entryToWorldFaction.size());
}

WorldFactionId WorldFactionCatalog::Resolve(uint32 creatureEntry) const
{
    auto it = _entryToWorldFaction.find(creatureEntry);
    if (it == _entryToWorldFaction.end())
        return WorldFactions::Unaffiliated;

    return it->second;
}
