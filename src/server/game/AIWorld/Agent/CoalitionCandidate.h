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

#ifndef AIWORLD_COALITIONCANDIDATE_H
#define AIWORLD_COALITIONCANDIDATE_H

#include "AgentId.h"
#include "Define.h"
#include "Faction/WorldFactionId.h"

// Milestone 2.12E4R (generalized from 2.12E4A's WolfCoalitionCandidate):
// one currently-observable agent's position and creature identity, as a
// plain value - never a Creature*/Map*. AIWorldMgr::CollectCoalitionCandidates()
// is the only thing that ever builds one, from a live Creature it has
// already resolved for an agent that is Materialized and alive - it does
// NOT decide whether this agent is a good fit for any particular coalition
// (that is CoalitionFormationProfile's job, matched against CreatureEntry
// by CoalitionFormationSystem::Propose() - see its own class comment for
// the WORLD OBSERVATION / FORMATION PROFILE split this exists to preserve).
// A transient formation-scan input only, never stored anywhere past one
// Propose() call - deliberately not folded into AgentRecord/
// AgentGroupMembership.
struct CoalitionCandidate
{
    AgentId Id;
    uint32 MapId = 0;
    float X = 0.0f;
    float Y = 0.0f;
    float Z = 0.0f;
    uint32 CreatureEntry = 0;

    // AI WorldFactionId (data/elwynn/factions/README.md) - copied from
    // AgentRecord::WorldFaction by AIWorldMgr::CollectCoalitionCandidates(),
    // the same "resolve once, carry the value" shape CreatureEntry already
    // has here. CoalitionFormationSystem::Propose() matches this against
    // CoalitionFormationProfile::RequiredWorldFaction as a second,
    // independent compatibility gate alongside CreatureEntry - see that
    // profile field's own comment for why CreatureEntry alone is not
    // considered sufficient any more.
    WorldFactionId WorldFaction = WorldFactions::Unaffiliated;
};

#endif // AIWORLD_COALITIONCANDIDATE_H
