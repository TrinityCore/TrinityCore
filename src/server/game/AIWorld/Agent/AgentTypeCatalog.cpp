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
        uint8 rawAgentType = fields[1].GetUInt8();
        AgentType agentType = ToKnownAgentType(rawAgentType);
        if (uint8(agentType) != rawAgentType)
            TC_LOG_ERROR("ai.world", "AI AgentTypeCatalog: creature_entry={} has unknown ai_agent_type_entry_defaults.agent_type={}, treated as Unclassified",
                creatureEntry, rawAgentType);
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
