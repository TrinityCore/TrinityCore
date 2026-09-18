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

#include "SpawnParticipationCatalog.h"
#include "DatabaseEnv.h"
#include "Log.h"

namespace
{
    // Fail-closed range check, mirroring AgentType.h's own ToKnownAgentType():
    // a stored byte outside SpawnParticipationMode's known enumerators must
    // never be trusted as some other participation mode - defaults to the
    // most restrictive value (Excluded), never FullAgent.
    SpawnParticipationMode ToKnownParticipationMode(uint8 value)
    {
        switch (SpawnParticipationMode(value))
        {
            case SpawnParticipationMode::FullAgent:
            case SpawnParticipationMode::LightweightBackground:
            case SpawnParticipationMode::VanillaOnly:
            case SpawnParticipationMode::Excluded:
                return SpawnParticipationMode(value);
            default:
                return SpawnParticipationMode::Excluded;
        }
    }
}

void SpawnParticipationCatalog::Load()
{
    _spawnIdToParticipation.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_AI_SPAWN_PARTICIPATION_DEFAULTS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI SpawnParticipationCatalog loaded 0 spawn_id -> SpawnParticipationMode defaults (world.ai_spawn_participation_defaults empty or missing)");
        return;
    }

    _spawnIdToParticipation.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        uint64 spawnId = fields[0].GetUInt64();
        SpawnParticipationMode mode = ToKnownParticipationMode(fields[1].GetUInt8());
        _spawnIdToParticipation.emplace(spawnId, mode);
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI SpawnParticipationCatalog loaded {} spawn_id -> SpawnParticipationMode defaults", _spawnIdToParticipation.size());
}

SpawnParticipationMode SpawnParticipationCatalog::Resolve(uint64 spawnId) const
{
    auto it = _spawnIdToParticipation.find(spawnId);
    if (it == _spawnIdToParticipation.end())
        return SpawnParticipationMode::Excluded;

    return it->second;
}

bool SpawnParticipationCatalog::TryResolve(uint64 spawnId, SpawnParticipationMode& outMode) const
{
    auto it = _spawnIdToParticipation.find(spawnId);
    if (it == _spawnIdToParticipation.end())
        return false;

    outMode = it->second;
    return true;
}
