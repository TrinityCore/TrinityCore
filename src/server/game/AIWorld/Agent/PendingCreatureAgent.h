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

#ifndef AIWORLD_PENDINGCREATUREAGENT_H
#define AIWORLD_PENDINGCREATUREAGENT_H

#include "AgentType.h"
#include "Define.h"
#include "Faction/WorldFactionId.h"

// Milestone 2.12F4B: a not-yet-persisted creature agent identity, pure
// value - AgentPersistence::CreateCreatureAgentsBatch()'s own input and
// SpawnReconciliationPlan::Missing's element type. SpawnId is bound as
// agent_id explicitly (2.12F4A2 - AgentId == SpawnId), never derived/
// generated.
struct PendingCreatureAgent
{
    // AgentType identity fix - resolved once by BuildReconciliationPlan()
    // from CreatureSpawnIdentity::Entry via AgentTypeCatalog::Resolve(),
    // the same "resolve once, carry the value" shape WorldFaction below
    // already has. No longer derived from npcFlags (DeriveCreatureAgentType,
    // retired) - the catalog is the single source of truth now.
    AgentType Type = AgentType::Unclassified;
    uint32 MapId = 0;
    uint64 SpawnId = 0;

    // AI WorldFactionId - resolved once by BuildReconciliationPlan() from
    // CreatureSpawnIdentity::Entry via WorldFactionCatalog::Resolve(),
    // carried here so CreateCreatureAgentsBatch() can insert it directly
    // instead of re-resolving per row. Defaults to Unaffiliated, the same
    // fail-closed default AgentRecord::WorldFaction itself uses.
    WorldFactionId WorldFaction = WorldFactions::Unaffiliated;
};

#endif // AIWORLD_PENDINGCREATUREAGENT_H
