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

#ifndef AIWORLD_PLAYERWORLDFACTIONREACTIONBRIDGE_H
#define AIWORLD_PLAYERWORLDFACTIONREACTIONBRIDGE_H

#include "Define.h"
#include "WorldFactionId.h"

class Player;
class WorldFactionRelationCatalog;
class WorldFactionReputationCatalog;

// The ONE point of contact between AIWorld's own WorldFaction diplomacy
// layer and TrinityCore's own gameplay reaction authority
// (AIWorld_Current_Roadmap.md, architectural audit 2026-09-21):
// WorldObject::GetReactionTo() never reads WorldFactionId/
// WorldFactionRelationCatalog directly and never will - these two free
// functions are the only place AIWorld ever calls into ReputationMgr, and
// only on an explicit lifecycle event (login, .aiworld faction join/leave),
// never per reaction check.
namespace PlayerWorldFactionReactionBridge
{
    // Pure state mutation on `player`'s own ReputationMgr::_forcedReactions -
    // clears EVERY Faction.dbc id `reputationCatalog` could ever map to
    // (the whole known WorldFactionReputationCatalog range), then, if
    // `allegiance` is not WorldFactions::Unaffiliated, applies a forced
    // Friendly/Hostile reaction for every WorldFaction `relationCatalog`
    // resolves as non-Neutral relative to `allegiance` (Neutral needs no
    // override - already cleared). Same-faction Friendly falls out of
    // WorldFactionRelationCatalog::Resolve()'s own rule 1 (from == to), no
    // special case needed here for the allegiance's own faction.
    //
    // Stateless/idempotent by construction - never needs to know what was
    // previously forced (always clears the full known set first), safe to
    // call identically from Player::LoadFromDB() at login and from a GM
    // command callback on an already-live Player. Never calls
    // ReputationMgr::SendForceReactions() or Unit::StopAttackFaction() -
    // see NotifyAndDisengage() below for that, and why login must not call
    // it.
    TC_GAME_API void ApplySync(Player& player, WorldFactionId allegiance,
        WorldFactionReputationCatalog const& reputationCatalog,
        WorldFactionRelationCatalog const& relationCatalog);

    // For an ALREADY-LIVE player only - never call this from
    // Player::LoadFromDB() (login). Player::SendInitialPacketsBeforeAddToMap()
    // calls ReputationMgr::SendInitialReputations()/SendForceReactions()
    // itself shortly after LoadFromDB() returns, so login gets the client
    // notified for free; a freshly-loaded player also has no live combat
    // state yet for Unit::StopAttackFaction() to meaningfully act on.
    //
    // Sends the player's current complete forced-reaction set to the client
    // (ReputationMgr::SendForceReactions() itself always resends the whole
    // map, never a delta, so this is safe to call after any ApplySync()).
    // Then, for every Faction.dbc id `reputationCatalog` knows, stops the
    // player's own combat/attackers/minions against it
    // (Unit::StopAttackFaction()) if that faction is now EFFECTIVELY
    // Friendly - either freshly forced Friendly, or a forced override was
    // just removed and the player's own real (unforced) reputation with it
    // is still >= REP_FRIENDLY. Mirrors AuraEffect::HandleForceReaction()'s
    // own apply/remove-path condition (SpellAuraEffects.cpp) exactly, just
    // applied across the whole managed set instead of a single changed
    // faction - StopAttackFaction() is a safe no-op for anything the player
    // isn't actually fighting.
    TC_GAME_API void NotifyAndDisengage(Player& player, WorldFactionReputationCatalog const& reputationCatalog);
}

#endif // AIWORLD_PLAYERWORLDFACTIONREACTIONBRIDGE_H
