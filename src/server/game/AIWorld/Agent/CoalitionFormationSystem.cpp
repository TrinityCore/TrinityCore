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

#include "CoalitionFormationSystem.h"
#include <algorithm>

std::optional<CoalitionProposal> CoalitionFormationSystem::Propose(std::vector<CoalitionCandidate> const& candidates, CoalitionFormationProfile const& profile) const
{
    // Step 1: only candidates this profile actually recognizes at all -
    // see this class's own header comment for the WORLD OBSERVATION /
    // FORMATION PROFILE split this preserves (the caller's own candidate
    // collection has no idea which CreatureEntry values matter to any
    // particular profile).
    // AI WorldFactionId gate (data/elwynn/factions/README.md): a second,
    // independent check alongside CreatureEntry - see CoalitionFormationProfile::
    // RequiredWorldFaction's own comment for why CreatureEntry alone is no
    // longer treated as sufficient. In practice a CreatureEntry's own
    // WorldFactionId is already fixed by WorldFactionCatalog, so this is
    // defense-in-depth rather than a filter expected to reject anything
    // CreatureEntry didn't already - but it is the check that makes "one
    // coalition = one WorldFactionId" an enforced invariant here, not just
    // an assumption.
    std::vector<CoalitionCandidate> compatible;
    for (CoalitionCandidate const& candidate : candidates)
        if (candidate.CreatureEntry == profile.CreatureEntry && candidate.WorldFaction == profile.RequiredWorldFaction)
            compatible.push_back(candidate);

    if (uint32(compatible.size()) < profile.MinMembers)
        return std::nullopt;

    // Deterministic seed TRIAL order: lowest AgentId first, regardless of
    // the caller's own iteration order.
    std::sort(compatible.begin(), compatible.end(),
        [](CoalitionCandidate const& a, CoalitionCandidate const& b) { return a.Id.Value < b.Id.Value; });

    float radiusSq = profile.FormationRadius * profile.FormationRadius;

    for (std::size_t seedIndex = 0; seedIndex < compatible.size(); ++seedIndex)
    {
        CoalitionCandidate const& seed = compatible[seedIndex];

        std::vector<CoalitionCandidate> neighbors;
        for (std::size_t i = 0; i < compatible.size(); ++i)
        {
            if (i == seedIndex)
                continue;

            CoalitionCandidate const& candidate = compatible[i];
            if (candidate.MapId != seed.MapId)
                continue;

            float dx = candidate.X - seed.X;
            float dy = candidate.Y - seed.Y;
            float dz = candidate.Z - seed.Z;
            float distanceSq = dx * dx + dy * dy + dz * dz;
            if (distanceSq > radiusSq)
                continue;

            neighbors.push_back(candidate);
        }

        std::sort(neighbors.begin(), neighbors.end(),
            [&seed](CoalitionCandidate const& a, CoalitionCandidate const& b)
            {
                float dxa = a.X - seed.X, dya = a.Y - seed.Y, dza = a.Z - seed.Z;
                float dxb = b.X - seed.X, dyb = b.Y - seed.Y, dzb = b.Z - seed.Z;
                float distanceSqA = dxa * dxa + dya * dya + dza * dza;
                float distanceSqB = dxb * dxb + dyb * dyb + dzb * dzb;
                if (distanceSqA != distanceSqB)
                    return distanceSqA < distanceSqB;
                return a.Id.Value < b.Id.Value;
            });

        // profile.MaxMembers is always >= 1 by the time it reaches here -
        // AIWorldMgr builds every CoalitionFormationProfile it owns from
        // AgentGroupPolicyConfig fields already clamped to at least 1 (see
        // CoalitionFormationProfile.h) - so MaxMembers - 1 never
        // underflows.
        if (uint32(neighbors.size()) > profile.MaxMembers - 1)
            neighbors.resize(profile.MaxMembers - 1);

        if (uint32(1 + neighbors.size()) < profile.MinMembers)
            continue; // this seed cannot form a viable coalition - try the next

        CoalitionProposal proposal;
        proposal.Kind = profile.Kind;
        proposal.TerritoryMapId = seed.MapId;
        proposal.TerritoryX = seed.X;
        proposal.TerritoryY = seed.Y;
        proposal.TerritoryZ = seed.Z;
        proposal.Members.push_back(seed.Id);
        for (CoalitionCandidate const& neighbor : neighbors)
            proposal.Members.push_back(neighbor.Id);

        return proposal;
    }

    return std::nullopt;
}
