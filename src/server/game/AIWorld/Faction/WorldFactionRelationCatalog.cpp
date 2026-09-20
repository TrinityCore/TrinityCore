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

#include "WorldFactionRelationCatalog.h"
#include "DatabaseEnv.h"
#include "Log.h"

uint64 MakeWorldFactionRelationKey(WorldFactionId from, WorldFactionId to)
{
    return (uint64(from.Value) << 32) | uint64(to.Value);
}

WorldFactionRelation ResolveWorldFactionRelation(
    WorldFactionId from, WorldFactionId to,
    std::unordered_map<uint64, WorldFactionRelation> const& relations)
{
    if (from && to && from == to)
        return WorldFactionRelation::Friendly;

    auto it = relations.find(MakeWorldFactionRelationKey(from, to));
    if (it != relations.end())
        return it->second;

    return WorldFactionRelation::Neutral;
}

void WorldFactionRelationCatalog::Load()
{
    _relations.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_AI_WORLD_FACTION_RELATIONS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI WorldFactionRelationCatalog loaded 0 (from, to) -> WorldFactionRelation rows (world.ai_world_faction_relations empty or missing)");
        return;
    }

    _relations.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        WorldFactionId from{ fields[0].GetUInt32() };
        WorldFactionId to{ fields[1].GetUInt32() };
        auto relation = WorldFactionRelation(fields[2].GetUInt8());
        _relations.emplace(MakeWorldFactionRelationKey(from, to), relation);
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI WorldFactionRelationCatalog loaded {} (from, to) -> WorldFactionRelation rows", _relations.size());
}

WorldFactionRelation WorldFactionRelationCatalog::Resolve(WorldFactionId from, WorldFactionId to) const
{
    return ResolveWorldFactionRelation(from, to, _relations);
}
