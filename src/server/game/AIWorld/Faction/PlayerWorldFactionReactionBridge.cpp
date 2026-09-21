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

#include "PlayerWorldFactionReactionBridge.h"
#include "DBCStores.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "WorldFactionRelationCatalog.h"
#include "WorldFactionReputationCatalog.h"

namespace PlayerWorldFactionReactionBridge
{
    void ApplySync(Player& player, WorldFactionId allegiance,
        WorldFactionReputationCatalog const& reputationCatalog,
        WorldFactionRelationCatalog const& relationCatalog)
    {
        std::vector<std::pair<WorldFactionId, uint32>> mappings = reputationCatalog.AllMappings();

        // Always clear the WHOLE known set first, unconditionally - this
        // bridge never needs to know what it previously applied (no old-
        // allegiance parameter, nothing to get out of sync). Erasing a key
        // that was never forced is a harmless no-op
        // (ReputationMgr::ApplyForceReaction()'s own apply=false branch is
        // a plain map::erase()).
        for (auto const& mapping : mappings)
            player.GetReputationMgr().ApplyForceReaction(mapping.second, REP_NEUTRAL, false);

        if (!allegiance)
            return;

        for (auto const& mapping : mappings)
        {
            WorldFactionId worldFaction = mapping.first;
            uint32 factionId = mapping.second;

            WorldFactionRelation relation = relationCatalog.Resolve(allegiance, worldFaction);
            switch (relation)
            {
                case WorldFactionRelation::Friendly:
                    player.GetReputationMgr().ApplyForceReaction(factionId, REP_FRIENDLY, true);
                    break;
                case WorldFactionRelation::Hostile:
                    player.GetReputationMgr().ApplyForceReaction(factionId, REP_HOSTILE, true);
                    break;
                case WorldFactionRelation::Neutral:
                default:
                    // No override needed - already cleared above.
                    break;
            }
        }
    }

    void NotifyAndDisengage(Player& player, WorldFactionReputationCatalog const& reputationCatalog)
    {
        player.GetReputationMgr().SendForceReactions();

        for (auto const& mapping : reputationCatalog.AllMappings())
        {
            uint32 factionId = mapping.second;

            // Mirrors AuraEffect::HandleForceReaction()'s own combined
            // apply/remove-path condition (SpellAuraEffects.cpp): stop
            // fighting this faction if it is EFFECTIVELY Friendly right
            // now, whether that is a freshly forced Friendly rank or a
            // forced override that was just removed while the player's own
            // real reputation with it is still >= REP_FRIENDLY.
            ReputationRank effectiveRank;
            if (ReputationRank const* forcedRank = player.GetReputationMgr().GetForcedRankIfAny(factionId))
                effectiveRank = *forcedRank;
            else
                effectiveRank = player.GetReputationMgr().GetRank(sFactionStore.LookupEntry(factionId));

            if (effectiveRank >= REP_FRIENDLY)
                player.StopAttackFaction(factionId);
        }
    }
}
