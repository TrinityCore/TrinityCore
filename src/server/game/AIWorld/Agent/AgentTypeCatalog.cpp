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

#include "AgentTypeCatalog.h"
#include "DatabaseEnv.h"
#include "Log.h"

namespace
{
    // Fail-closed range check: a stored byte outside AgentType's own known
    // enumerators (e.g. the retired value 3, or a future schema mismatch)
    // must never be trusted as some other agent's real type - the same
    // discipline AgentPersistence::LoadAgents() already applies to
    // AgentControlMode's own stored byte.
    AgentType ToKnownAgentType(uint8 value)
    {
        switch (AgentType(value))
        {
            case AgentType::Civilian:
            case AgentType::Guard:
            case AgentType::Merchant:
            case AgentType::Unclassified:
            case AgentType::Combatant:
            case AgentType::Predator:
            case AgentType::Prey:
                return AgentType(value);
            default:
                return AgentType::Unclassified;
        }
    }
}

void AgentTypeCatalog::Load()
{
    _entryToAgentType.clear();

    WorldDatabasePreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_AI_AGENT_TYPE_ENTRY_DEFAULTS);
    PreparedQueryResult result = WorldDatabase.Query(stmt);
    if (!result)
    {
        TC_LOG_INFO("ai.world", "AI AgentTypeCatalog loaded 0 creature_entry -> AgentType defaults (world.ai_agent_type_entry_defaults empty or missing)");
        return;
    }

    _entryToAgentType.reserve(result->GetRowCount());
    do
    {
        Field* fields = result->Fetch();
        uint32 creatureEntry = fields[0].GetUInt32();
        AgentType agentType = ToKnownAgentType(fields[1].GetUInt8());
        _entryToAgentType.emplace(creatureEntry, agentType);
    } while (result->NextRow());

    TC_LOG_INFO("ai.world", "AI AgentTypeCatalog loaded {} creature_entry -> AgentType defaults", _entryToAgentType.size());
}

AgentType AgentTypeCatalog::Resolve(uint32 creatureEntry) const
{
    auto it = _entryToAgentType.find(creatureEntry);
    if (it == _entryToAgentType.end())
        return AgentType::Unclassified;

    return it->second;
}
