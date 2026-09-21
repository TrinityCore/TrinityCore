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

#ifndef AIWORLD_WORLDFACTIONREPUTATIONCATALOG_H
#define AIWORLD_WORLDFACTIONREPUTATIONCATALOG_H

#include "Define.h"
#include "WorldFactionId.h"
#include <unordered_map>
#include <utility>
#include <vector>

// WorldFactionId -> Trinity Faction.dbc id bridge (AIWorld_Current_Roadmap.md,
// architectural audit 2026-09-21): the ONLY reason this mapping exists is to
// let a future login/allegiance-change bridge call
// ReputationMgr::ApplyForceReaction() with a real Faction.dbc id - it is NOT
// a general WorldFactionId identity concept and must never be consulted from
// a per-interaction reaction check (WorldObject::GetReactionTo() stays the
// sole gameplay reaction authority).
//
// Loads world.ai_world_faction_reputation_defaults once at AIWorldMgr::
// Initialize() into an in-memory WorldFactionId -> Faction.dbc id map - same
// Load()/lifecycle shape as WorldFactionCatalog/WorldFactionRelationCatalog.
// That table is itself generated from data/elwynn/factions/factions.csv +
// world_faction_vanilla_reputation.csv + world_factions.csv (see
// tools/elwynn/build_world_faction_reputation_defaults.py) - this class
// never reads the CSVs directly, only the world DB table they were used to
// populate.
//
// Deliberately incomplete: not every WorldFactionId has a row (e.g.
// ELWYNN_WOLVES never will - ecological/social only, never a player-visible
// reputation). TryResolve() surfaces that as an explicit "no mapping" rather
// than Resolve()-style guessing a fallback value, because there is no
// meaningful fallback Faction.dbc id here.
class TC_GAME_API WorldFactionReputationCatalog
{
    public:
        // Replaces any previously loaded content. Startup-only, synchronous
        // (CONNECTION_SYNCH) - the same pattern WorldFactionCatalog::Load()/
        // WorldFactionRelationCatalog::Load() already use, never called
        // from the world update loop.
        void Load();

        // Returns true and sets *outFactionId if `worldFaction` has a
        // player-visible Trinity Faction.dbc id; returns false (outFactionId
        // left unchanged) if it does not - the caller must not force any
        // reaction for a WorldFactionId this returns false for.
        bool TryResolve(WorldFactionId worldFaction, uint32& outFactionId) const;

        // Every (WorldFactionId, Faction.dbc id) pair this catalog knows -
        // lets a caller (PlayerWorldFactionReactionBridge) enumerate every
        // Faction.dbc id it might ever need to clear/apply without
        // hardcoding the known WorldFaction set a second time in C++. The
        // generated world DB table stays the only source of truth for
        // "which WorldFactions have a player-visible reputation" - this
        // just exposes it for iteration, same data Resolve()/TryResolve()
        // already serve one at a time.
        std::vector<std::pair<WorldFactionId, uint32>> AllMappings() const;

    private:
        std::unordered_map<uint32, uint32> _worldFactionToFactionId;
};

#endif // AIWORLD_WORLDFACTIONREPUTATIONCATALOG_H
