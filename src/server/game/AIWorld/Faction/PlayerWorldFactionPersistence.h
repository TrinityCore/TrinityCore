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

#ifndef AIWORLD_PLAYERWORLDFACTIONPERSISTENCE_H
#define AIWORLD_PLAYERWORLDFACTIONPERSISTENCE_H

#include "Define.h"
#include "ObjectGuid.h"
#include "WorldFactionId.h"

// Player WorldFaction membership vertical slice (AIWorld_Current_Roadmap.md):
// persistent storage for a character's own social/political allegiance -
// separate from earned reputation (TrinityCore's own character_reputation/
// ReputationMgr, untouched by this) and from any diplomacy/combat
// consequence (WorldFactionRelationCatalog, a future resolver, and any
// ReputationMgr::ApplyForceReaction() bridge are all later, separate
// steps - this class is pure persistence, nothing else).
//
// Deliberately NOT integrated with Player::LoadFromDB()'s LoginQueryHolder/
// cached on the live Player object - every method here is an independent,
// on-demand characters-DB query keyed by ObjectGuid, the same "contained,
// no core-file changes" shape AgentPersistence already uses for ai_agents.
// Stateless (holds no member data) - every call is synchronous
// (CONNECTION_SYNCH/DirectExecute()) and must never be called from the
// world update loop.
//
// V1: at most one active membership per character. "No membership" is the
// ABSENCE of a row, never an explicit WorldFactionId{0} (Unaffiliated) row -
// LoadMembership() returns WorldFactions::Unaffiliated for both "row
// absent" and "querying an unknown/never-joined character", the same
// fail-closed default every other WorldFactionId-resolving call in this
// subsystem already uses.
//
// Every method fail-closed validates characterGuid.IsPlayer() before
// touching character_guid at all: ai_player_world_faction is keyed by the
// low GUID counter alone (ObjectGuid::GetCounter(), matching character_reputation's
// own "guid" column convention), and a Creature/GameObject/etc. ObjectGuid
// can share that same low counter with an unrelated Player - passing one
// through unchecked could read/overwrite a real player's membership by
// accident. A non-Player (or empty) ObjectGuid is refused before any DB
// access, never silently treated as "GUID 0".
class TC_GAME_API PlayerWorldFactionPersistence
{
    public:
        // Returns WorldFactions::Unaffiliated if the character has no
        // active membership row (never distinguishes that from "unknown
        // character" - there is nothing meaningful to distinguish here),
        // OR if characterGuid is not a Player GUID at all (fail closed,
        // logged - see this class's own comment).
        WorldFactionId LoadMembership(ObjectGuid characterGuid);

        // Joins (or switches to, if already a member of a different
        // WorldFaction) `faction` - REPLACE INTO, so this always succeeds
        // in overwriting any prior row rather than needing a separate
        // UPDATE-vs-INSERT branch. Refuses (returns false, no DB write at
        // all) if `faction` is WorldFactions::Unaffiliated - "joining
        // nothing" is nonsensical; call Leave() instead. Returns whether
        // the write was confirmed by read-back matching `faction` - fail
        // closed, the same discipline every batch/single persistence
        // method in this subsystem already applies; the caller must not
        // assume membership changed until this returns true. Also returns
        // false (no DB access at all) if characterGuid is not a Player
        // GUID - see this class's own comment.
        bool Join(ObjectGuid characterGuid, WorldFactionId faction);

        // Deletes the membership row entirely - the character returns to
        // "none" (LoadMembership() will report Unaffiliated afterward).
        // Returns whether confirmed by read-back (no row found for
        // characterGuid afterward) - true either way if there was already
        // no row to begin with. Returns false (no DB access at all) if
        // characterGuid is not a Player GUID - see this class's own
        // comment.
        bool Leave(ObjectGuid characterGuid);
};

#endif // AIWORLD_PLAYERWORLDFACTIONPERSISTENCE_H
