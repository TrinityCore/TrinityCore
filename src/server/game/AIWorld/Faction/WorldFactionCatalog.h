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

#ifndef AIWORLD_WORLDFACTIONCATALOG_H
#define AIWORLD_WORLDFACTIONCATALOG_H

#include "Define.h"
#include "WorldFactionId.h"
#include <unordered_map>

// Loads world.ai_world_faction_entry_defaults once at AIWorldMgr::
// Initialize() into an in-memory CreatureEntry -> WorldFactionId map. That
// table is itself generated from data/elwynn/factions/
// world_faction_assignments.csv/world_factions.csv (see that directory's
// own README) - this class never reads the CSVs directly, only the world
// DB table they were used to populate.
//
// Read-only after Load(): AIWorldMgr::BuildReconciliationPlan()'s own
// caller (RunSpawnReconciliation()) is the only thing that calls Resolve(),
// once per eligible CreatureSpawnIdentity - never a per-spawn world DB
// query.
class TC_GAME_API WorldFactionCatalog
{
    public:
        // Replaces any previously loaded content. Startup-only, synchronous
        // (CONNECTION_SYNCH) - the same pattern AgentPersistence's own
        // startup-only methods use, never called from the world update
        // loop.
        void Load();

        // A CreatureEntry absent from the table - never classified, or
        // explicitly assigned NEUTRAL_UNAFFILIATED in the source CSV -
        // resolves to WorldFactions::Unaffiliated. Fail-closed: this never
        // guesses an affiliation for an entry it has no explicit data for.
        WorldFactionId Resolve(uint32 creatureEntry) const;

    private:
        std::unordered_map<uint32, WorldFactionId> _entryToWorldFaction;
};

#endif // AIWORLD_WORLDFACTIONCATALOG_H
