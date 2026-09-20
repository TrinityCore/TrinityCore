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

namespace
{
    // Fail-closed range check, mirroring AgentType.h's own ToKnownAgentType():
    // a stored byte outside WorldFactionRelation's own known enumerators
    // must never be trusted as some other relation - defaults to Neutral,
    // the same "no data/bad data means the safest, most inert value" rule
    // ResolveWorldFactionRelation() itself applies for a missing row.
    WorldFactionRelation ToKnownWorldFactionRelation(uint8 value)
    {
        switch (WorldFactionRelation(value))
        {
            case WorldFactionRelation::Neutral:
            case WorldFactionRelation::Friendly:
            case WorldFactionRelation::Hostile:
                return WorldFactionRelation(value);
            default:
                return WorldFactionRelation::Neutral;
        }
    }
}

uint64 MakeWorldFactionRelationKey(WorldFactionId from, WorldFactionId to)
{
    return (uint64(from.Value) << 32) | uint64(to.Value);
}

WorldFactionRelation ResolveWorldFactionRelation(
    WorldFactionId from, WorldFactionId to,
    std::unordered_map<uint64, WorldFactionRelation> const& relations)
{
    // Checked BEFORE the same-faction/table lookup below, not after: a
    // stray (Unaffiliated, X) or (X, Unaffiliated) row that somehow ended
    // up in `relations` (bad data, never something a well-formed CSV/
    // generator should produce - see build_world_faction_relations_defaults.py's
    // own validation) must never override this invariant. Unaffiliated has
    // no diplomacy, full stop - data/elwynn/factions/README.md's own
    // "Nevypsaný cross-faction vztah je NEUTRAL" note applies doubly hard
    // to a side that isn't even a real WorldFaction.
    if (!from || !to)
        return WorldFactionRelation::Neutral;

    if (from == to)
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
        uint8 rawRelation = fields[2].GetUInt8();
        WorldFactionRelation relation = ToKnownWorldFactionRelation(rawRelation);
        if (uint8(relation) != rawRelation)
            TC_LOG_ERROR("ai.world", "AI WorldFactionRelationCatalog: (from={}, to={}) has unknown ai_world_faction_relations.relation={}, treated as Neutral",
                from.Value, to.Value, rawRelation);
        _relations.emplace(MakeWorldFactionRelationKey(from, to), relation);
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI WorldFactionRelationCatalog loaded {} (from, to) -> WorldFactionRelation rows", _relations.size());
}

WorldFactionRelation WorldFactionRelationCatalog::Resolve(WorldFactionId from, WorldFactionId to) const
{
    return ResolveWorldFactionRelation(from, to, _relations);
}
