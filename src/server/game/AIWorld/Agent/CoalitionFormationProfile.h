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

#ifndef AIWORLD_COALITIONFORMATIONPROFILE_H
#define AIWORLD_COALITIONFORMATIONPROFILE_H

#include "AgentGroupKind.h"
#include "CoalitionFormationProfileId.h"
#include "Define.h"
#include "Faction/WorldFactionId.h"

// Milestone 2.12E4R (generalized from 2.12E4A's WolfCoalitionFormationConfig):
// everything CoalitionFormationSystem::Propose() needs beyond the candidate
// list itself, PLUS which kind of coalition this is (unlike the wolf-only
// predecessor this replaces, CoalitionFormationSystem itself no longer
// knows anything about wolves specifically - only about profiles). Built
// once by AIWorldMgr at Initialize() for each formation feature it
// supports - AIWorld's own WolfLoose profile (CreatureEntry =
// AIWorld.WolfGroupCreatureEntry, Kind = Loose, FormationRadius =
// AIWorld.WolfGroupFormationRadius, MinMembers/MaxMembers copied from
// AgentGroupPolicyConfig::LooseMinMembers/LooseMaxMembers - see this
// struct's own field comment for why those are never independently-tunable
// here), and (Milestone 2.12G1 - the exact genericity proof this comment
// already predicted) AIWorld's own DefiasLoose profile, built the same way
// from AIWorld.DefiasGroupCreatureEntry/FormationRadius - confirming a
// second SINGLE-CreatureEntry profile really is just another
// CoalitionFormationProfile value and a matching AIWorldMgr::
// RunCoalitionFormation() call site, with zero change to
// CoalitionFormationSystem/CoalitionCandidate/CoalitionProposal. STATIC
// review (2.12E4R): that claim does NOT extend to a
// MIXED-entry coalition (e.g. a caravan of a merchant + guards + pack
// animals) - CreatureEntry is still the only SPECIES compatibility signal
// CoalitionFormationSystem::Propose() checks, so a profile can only ever
// gather one CreatureEntry at a time. AI WorldFactionId (see
// RequiredWorldFaction below) adds a second, independent gate on top of
// that - social/political affiliation, not species - so a mixed-entry
// coalition is still not possible; that remains explicitly deferred.
struct CoalitionFormationProfile
{
    // Milestone 2.12E4R P3 fix (STATIC review): defaults to Invalid, not
    // WolfLoose - see CoalitionFormationProfileId.h for why. Every real
    // profile (today: AIWorldMgr::_wolfLooseFormationProfile) sets this
    // explicitly at construction time.
    CoalitionFormationProfileId Id = CoalitionFormationProfileId::Invalid;

    AgentGroupKind Kind = AgentGroupKind::Loose;

    // The one CoalitionCandidate::CreatureEntry this profile accepts -
    // CoalitionFormationSystem::Propose() filters candidates against this
    // before anything else (see its own class comment). A single fixed
    // entry, not a list/category - deliberately narrow, matching this
    // milestone's own one-profile scope.
    uint32 CreatureEntry = 0;

    // AI WorldFactionId (data/elwynn/factions/README.md) - a second,
    // independent compatibility gate CoalitionFormationSystem::Propose()
    // checks alongside CreatureEntry above, closing the gap this struct's
    // own header comment flagged as explicitly deferred: CreatureEntry
    // alone cannot tell "same species, but socially/politically distinct
    // populations" apart. Every real profile (WolfLoose/DefiasLoose) sets
    // this explicitly at construction time, the same discipline Id already
    // requires - defaults to Unaffiliated, which is only ever correct for
    // a profile whose CreatureEntry itself resolves to Unaffiliated in
    // WorldFactionCatalog.
    WorldFactionId RequiredWorldFaction = WorldFactions::Unaffiliated;

    // Deliberately NOT independently-tunable values of their own for the
    // WolfLoose profile - AIWorldMgr copies them straight from
    // AgentGroupPolicyConfig::LooseMinMembers/LooseMaxMembers when it
    // builds that profile. A wolf pack IS a Loose AgentGroup, so its
    // formation must obey the exact same size bounds
    // AgentGroupPolicySystem::CanJoin()/ShouldDissolve() already enforce
    // for one - a second, independently-configured min/max could quietly
    // drift out of sync with the policy layer's own rules and propose a
    // group CanJoin() would then reject as GroupFull, or one
    // ShouldDissolve() would flag as below minimum the moment it formed. A
    // future non-Loose profile is not bound by this precedent - it would
    // read whatever policy config actually governs its own Kind.
    uint32 MinMembers = 2;
    uint32 MaxMembers = 5;

    float FormationRadius = 30.0f;
};

#endif // AIWORLD_COALITIONFORMATIONPROFILE_H
