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

#ifndef AIWORLD_WORLDFACTIONID_H
#define AIWORLD_WORLDFACTIONID_H

#include "Define.h"

// AI WorldFactionId - the social/political affiliation layer described in
// data/elwynn/factions/README.md. Deliberately NOT a Faction.dbc or
// FactionTemplate.dbc id (those govern TrinityCore combat reaction/
// reputation; this governs AgentRecord affiliation, coalition eligibility
// and future Living World/holdings logic) - the two are independent and
// must never be confused or merged into one id space.
struct WorldFactionId
{
    uint32 Value = 0;

    // 0 (WorldFactions::Unaffiliated) reads as false - "has no social/
    // political affiliation", not an error state.
    constexpr explicit operator bool() const { return Value != 0; }
    constexpr bool operator==(WorldFactionId const& other) const { return Value == other.Value; }
    constexpr bool operator!=(WorldFactionId const& other) const { return Value != other.Value; }
};

// The stable catalog in data/elwynn/factions/world_factions.csv - source of
// truth for these ids and their keys. NEUTRAL_UNAFFILIATED is deliberately
// not a member here: per that catalog's own README, it is not a WorldFaction
// entity at all, only the explicit absence of one (WorldFactionId{0} /
// Unaffiliated below).
namespace WorldFactions
{
    constexpr WorldFactionId Unaffiliated{0};
    constexpr WorldFactionId StormwindAlliance{1};
    constexpr WorldFactionId DefiasBrotherhood{2};
    constexpr WorldFactionId RiverpawGnolls{3};
    constexpr WorldFactionId ElwynnKobolds{4};
    constexpr WorldFactionId ElwynnMurlocs{5};
    constexpr WorldFactionId ElwynnWolves{6};
}

#endif // AIWORLD_WORLDFACTIONID_H
