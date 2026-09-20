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

#ifndef AIWORLD_WORLDFACTIONRELATIONCATALOG_H
#define AIWORLD_WORLDFACTIONRELATIONCATALOG_H

#include "Define.h"
#include "WorldFactionId.h"
#include "WorldFactionRelation.h"
#include <unordered_map>

// Combines (from, to) into the single key both the catalog and
// ResolveWorldFactionRelation() below use for their relations map - never
// symmetric (a from/to pair and its reverse are two distinct keys), since
// the underlying data (data/elwynn/factions/world_faction_relations.csv)
// is deliberately directional: a bidirectional relationship is expressed as
// two explicit rows, never inferred from one.
TC_GAME_API uint64 MakeWorldFactionRelationKey(WorldFactionId from, WorldFactionId to);

// Pure resolution logic, no catalog/DB dependency - callable directly by
// WorldFactionRelationCatalog::Resolve() below AND by unit tests (tests/
// game/WorldFactionRelationCatalog.cpp), which construct `relations`
// synthetically instead of loading it from a live world DB connection a
// test sandbox doesn't have (the same "pure value logic gets direct Catch2
// coverage" seam PerceptionSystem::ObserveDirectedEvent() already uses).
//
// Rules, in order:
//   1. from == to AND both non-Unaffiliated -> Friendly (a WorldFaction is
//      always friendly/coalition-compatible with itself - never looked up
//      in `relations`, so an explicit same-faction row would be redundant,
//      never contradictory).
//   2. an explicit (from, to) row exists in `relations` -> that value.
//   3. otherwise -> Neutral (an unlisted cross-faction pair, OR either side
//      Unaffiliated, is Neutral by design - see data/elwynn/factions/
//      README.md's own "Nevypsaný cross-faction vztah je NEUTRAL" note).
TC_GAME_API WorldFactionRelation ResolveWorldFactionRelation(
    WorldFactionId from, WorldFactionId to,
    std::unordered_map<uint64, WorldFactionRelation> const& relations);

// Loads world.ai_world_faction_relations once at AIWorldMgr::Initialize()
// into an in-memory (from, to) -> WorldFactionRelation map - same Load()/
// Resolve() shape and lifecycle as WorldFactionCatalog/AgentTypeCatalog.
// That table is itself generated from data/elwynn/factions/
// world_faction_relations.csv (see tools/elwynn/build_world_faction_relations_defaults.py)
// - this class never reads the CSV directly, only the world DB table it
// was used to populate.
//
// Deliberately NOT wired into any player/combat/reputation decision yet -
// this is only the static WorldFaction <-> WorldFaction diplomacy layer;
// player membership and the TrinityCore ReputationMgr bridge are separate,
// later steps (AIWorld_Current_Roadmap.md).
class TC_GAME_API WorldFactionRelationCatalog
{
    public:
        // Replaces any previously loaded content. Startup-only, synchronous
        // (CONNECTION_SYNCH) - the same pattern WorldFactionCatalog::Load()/
        // AgentTypeCatalog::Load() already use, never called from the world
        // update loop.
        void Load();

        WorldFactionRelation Resolve(WorldFactionId from, WorldFactionId to) const;

    private:
        std::unordered_map<uint64, WorldFactionRelation> _relations;
};

#endif // AIWORLD_WORLDFACTIONRELATIONCATALOG_H
