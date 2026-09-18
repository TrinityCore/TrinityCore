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

#ifndef AIWORLD_SPAWNPARTICIPATIONCATALOG_H
#define AIWORLD_SPAWNPARTICIPATIONCATALOG_H

#include "Define.h"
#include "SpawnParticipationMode.h"
#include <unordered_map>

// Runtime participation/scope boundary fix (AIWorld_Current_Roadmap.md,
// Etapa 3): loads world.ai_spawn_participation_defaults once at
// AIWorldMgr::Initialize() into an in-memory SpawnId -> SpawnParticipationMode
// map - same Load()/Resolve() shape and lifecycle as WorldFactionCatalog/
// AgentTypeCatalog, but keyed by SpawnId (uint64), not CreatureEntry: unlike
// AgentType/WorldFactionId, participation is a spawn-level distinction (the
// same CreatureEntry can have some spawns permanent and others event-gated
// - see data/elwynn/census/README/coverage.md). That table is itself
// generated from data/elwynn/census/spawn_classification.csv's own
// participation_mode column (see tools/elwynn/build_agent_participation_defaults.py)
// - this class never reads the CSV directly, only the world DB table it
// was used to populate.
//
// Read-only after Load(): AIWorldMgr::BuildReconciliationPlan()'s own
// caller (RunSpawnReconciliation()) is the only thing that calls Resolve().
class TC_GAME_API SpawnParticipationCatalog
{
    public:
        // Replaces any previously loaded content. Startup-only, synchronous
        // (CONNECTION_SYNCH) - the same pattern WorldFactionCatalog::Load()/
        // AgentTypeCatalog::Load() already use, never called from the world
        // update loop.
        void Load();

        // A SpawnId absent from the table - never classified by the Elwynn
        // census, or genuinely outside its zone scope - resolves to
        // Excluded. Fail-closed the OPPOSITE way WorldFactionCatalog/
        // AgentTypeCatalog default (Unaffiliated/Unclassified, a harmless
        // "unknown" value): here, "no data" must mean "never treat this as
        // a permanent agent", not silently fall through as FullAgent.
        SpawnParticipationMode Resolve(uint64 spawnId) const;

        // Distinguishes "explicitly classified Excluded" from "simply
        // outside this catalog's census scope" - Resolve() alone cannot,
        // since both cases fall back to the same Excluded value. A caller
        // that enforces policy across the WHOLE AgentRegistry (not just a
        // known census zone, e.g. AIWorldMgr::ApplyParticipationControlPolicy())
        // must use this instead of Resolve(): treating every non-Elwynn
        // agent as Excluded just because this catalog has no data for it
        // would incorrectly quarantine the entire rest of the game world.
        // Returns false (outMode left unchanged) for a SpawnId absent from
        // the table; true (outMode set) otherwise.
        bool TryResolve(uint64 spawnId, SpawnParticipationMode& outMode) const;

    private:
        std::unordered_map<uint64, SpawnParticipationMode> _spawnIdToParticipation;
};

#endif // AIWORLD_SPAWNPARTICIPATIONCATALOG_H
