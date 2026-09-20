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

#include "tc_catch2.h"

#include "Faction/WorldFactionRelationCatalog.h"

// WorldFactionRelationCatalog::Load() needs a live world DB connection this
// sandbox doesn't have - ResolveWorldFactionRelation() is the pure value
// logic seam instead (the same "pure value logic gets direct Catch2
// coverage" pattern PerceptionSystem::ObserveDirectedEvent() already uses),
// exercised here against a synthetic relations map built to match
// data/elwynn/factions/world_faction_relations.csv exactly (8 directed
// HOSTILE rows, Stormwind <-> each of Defias/Riverpaw/Kobolds/Murlocs).

namespace
{
    std::unordered_map<uint64, WorldFactionRelation> MakeElwynnRelations()
    {
        std::unordered_map<uint64, WorldFactionRelation> relations;
        auto add = [&](WorldFactionId from, WorldFactionId to)
        {
            relations.emplace(MakeWorldFactionRelationKey(from, to), WorldFactionRelation::Hostile);
        };

        add(WorldFactions::StormwindAlliance, WorldFactions::DefiasBrotherhood);
        add(WorldFactions::DefiasBrotherhood, WorldFactions::StormwindAlliance);
        add(WorldFactions::StormwindAlliance, WorldFactions::RiverpawGnolls);
        add(WorldFactions::RiverpawGnolls, WorldFactions::StormwindAlliance);
        add(WorldFactions::StormwindAlliance, WorldFactions::ElwynnKobolds);
        add(WorldFactions::ElwynnKobolds, WorldFactions::StormwindAlliance);
        add(WorldFactions::StormwindAlliance, WorldFactions::ElwynnMurlocs);
        add(WorldFactions::ElwynnMurlocs, WorldFactions::StormwindAlliance);

        return relations;
    }
}

TEST_CASE("ResolveWorldFactionRelation locks in the Elwynn diplomacy matrix", "[WorldFactionRelationCatalog]")
{
    std::unordered_map<uint64, WorldFactionRelation> relations = MakeElwynnRelations();

    SECTION("explicit bidirectional Stormwind <-> Defias is Hostile both ways")
    {
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::StormwindAlliance, WorldFactions::DefiasBrotherhood, relations) == WorldFactionRelation::Hostile);
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::DefiasBrotherhood, WorldFactions::StormwindAlliance, relations) == WorldFactionRelation::Hostile);
    }

    SECTION("explicit Stormwind -> Kobolds is Hostile")
    {
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::StormwindAlliance, WorldFactions::ElwynnKobolds, relations) == WorldFactionRelation::Hostile);
    }

    SECTION("an unlisted cross-faction pair is Neutral, not inferred from either side's other relations")
    {
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::DefiasBrotherhood, WorldFactions::ElwynnKobolds, relations) == WorldFactionRelation::Neutral);
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::ElwynnKobolds, WorldFactions::ElwynnMurlocs, relations) == WorldFactionRelation::Neutral);
    }

    SECTION("same non-Unaffiliated faction is Friendly, without needing a matrix row")
    {
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::DefiasBrotherhood, WorldFactions::DefiasBrotherhood, relations) == WorldFactionRelation::Friendly);
    }

    SECTION("Unaffiliated on either side is Neutral, never Friendly and never a matrix lookup")
    {
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::Unaffiliated, WorldFactions::DefiasBrotherhood, relations) == WorldFactionRelation::Neutral);
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::DefiasBrotherhood, WorldFactions::Unaffiliated, relations) == WorldFactionRelation::Neutral);
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::Unaffiliated, WorldFactions::Unaffiliated, relations) == WorldFactionRelation::Neutral);
    }

    SECTION("a WorldFaction with no listed relations at all (e.g. ELWYNN_WOLVES) is Neutral to everyone but itself")
    {
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::ElwynnWolves, WorldFactions::StormwindAlliance, relations) == WorldFactionRelation::Neutral);
        REQUIRE(ResolveWorldFactionRelation(WorldFactions::ElwynnWolves, WorldFactions::ElwynnWolves, relations) == WorldFactionRelation::Friendly);
    }
}

TEST_CASE("MakeWorldFactionRelationKey is directional, not symmetric", "[WorldFactionRelationCatalog]")
{
    uint64 forward = MakeWorldFactionRelationKey(WorldFactions::StormwindAlliance, WorldFactions::DefiasBrotherhood);
    uint64 backward = MakeWorldFactionRelationKey(WorldFactions::DefiasBrotherhood, WorldFactions::StormwindAlliance);
    REQUIRE(forward != backward);
}
