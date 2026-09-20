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

#ifndef AIWORLD_WORLDFACTIONRELATION_H
#define AIWORLD_WORLDFACTIONRELATION_H

#include "Define.h"

// The static diplomacy layer between two AI WorldFactions (data/elwynn/
// factions/README.md) - deliberately NOT a player-facing Friendly/Neutral/
// Hostile reaction (that is TrinityCore's own ReputationMgr/FactionTemplate
// job) and NOT the same axis as AgentType (see AgentType.h's own comment on
// Combatant: hostility is never an agent property, only ever a relationship
// between two WorldFactions). This is that relationship, computed between
// two WorldFactionId values - the first building block player membership/
// diplomacy will eventually resolve through, not itself a player-facing
// concept yet.
enum class WorldFactionRelation : uint8
{
    Neutral = 0,
    Friendly = 1,
    Hostile = 2
};

inline char const* ToString(WorldFactionRelation relation)
{
    switch (relation)
    {
        case WorldFactionRelation::Neutral:  return "NEUTRAL";
        case WorldFactionRelation::Friendly: return "FRIENDLY";
        case WorldFactionRelation::Hostile:  return "HOSTILE";
        default:                             return "UNKNOWN";
    }
}

#endif // AIWORLD_WORLDFACTIONRELATION_H
