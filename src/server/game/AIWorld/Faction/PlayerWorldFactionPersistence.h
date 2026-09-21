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
#include "QueryCallback.h"
#include "WorldFactionId.h"
#include <functional>

// Player WorldFaction membership vertical slice (AIWorld_Current_Roadmap.md):
// persistent storage for a character's own social/political allegiance -
// separate from earned reputation (TrinityCore's own character_reputation/
// ReputationMgr, untouched by this) and from any diplomacy/combat
// consequence. This class is pure persistence, nothing else.
//
// Architectural audit (2026-09-21, AIWorld_Current_Roadmap.md): TrinityCore's
// own Faction.dbc/FactionTemplate.dbc/WorldObject::GetReactionTo()/
// ReputationMgr remains the SOLE gameplay reaction authority - there is no
// PlayerFactionRelationResolver and none will be built (it would be a second,
// parallel GetReactionTo()). The actual consumer of the value stored here is
// PlayerWorldFactionReactionBridge (Faction/PlayerWorldFactionReactionBridge.h),
// called once per lifecycle event (login, .aiworld faction join/leave) to
// push a ReputationMgr::ApplyForceReaction() sync via WorldFactionRelationCatalog
// + WorldFactionReputationCatalog - never a per-interaction resolver, never
// something a live Player*/Creature* reaction check consults directly.
//
// This class's own methods (LoadMembership()/Join()/Leave() and their async
// counterparts) are still never called from Player::LoadFromDB() directly -
// login instead reads the same CHAR_SEL_AI_PLAYER_WORLD_FACTION statement
// through PLAYER_LOGIN_QUERY_LOAD_AI_WORLD_FACTION in the ordinary
// LoginQueryHolder batch (CharacterHandler.cpp), independent of this class.
// Every method here remains an independent,
// on-demand characters-DB query keyed by ObjectGuid, the same "contained,
// no core-file changes" shape AgentPersistence already uses for ai_agents.
// Stateless (holds no member data). LoadMembership()/Join()/Leave() are
// synchronous (CONNECTION_SYNCH/DirectExecute()) and must never be called
// from the world update loop - CMSG_MESSAGECHAT and most other opcodes are
// PROCESS_THREADUNSAFE (Opcodes.cpp) and are processed inline on
// World::UpdateSessions(), the world thread itself, so even a GM chat
// command handler counts as "the world update loop" here. Use the
// LoadMembershipAsync()/JoinAsync()/LeaveAsync() counterparts below from
// any such context instead - see their own comment for the exact call
// shape.
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

        // Async counterparts - safe to call from the world thread (a GM
        // chat command handler included, see this class's own comment on
        // why). The DB work runs on a database worker thread; `callback`
        // fires later, on the world thread, whenever the CALLER's own
        // QueryCallbackProcessor next drains ready callbacks (WorldSession::
        // GetQueryProcessor(), pumped every WorldSession::Update() tick) -
        // never synchronously, never blocking the caller's own stack frame.
        // The caller owns registering the returned QueryCallback:
        //
        //   session->GetQueryProcessor().AddCallback(
        //       persistence.JoinAsync(guid, faction, [](bool confirmed) { ... }));
        //
        // Same fail-closed semantics as the synchronous methods (IsPlayer()
        // guard, Join() refuses Unaffiliated, Join() is idempotent for an
        // already-current faction without resetting joined_at, every write
        // is confirmed by a read-back before the callback reports success) -
        // just reached via chained QueryCallback stages instead of blocking
        // calls, mirroring WorldSession::HandleCharCreateOpcode()'s own
        // multi-step AsyncQuery().WithChainingPreparedCallback(...) chain
        // (CharacterHandler.cpp) rather than inventing a new async shape.
        QueryCallback LoadMembershipAsync(ObjectGuid characterGuid, std::function<void(WorldFactionId)> callback);
        QueryCallback JoinAsync(ObjectGuid characterGuid, WorldFactionId faction, std::function<void(bool)> callback);
        QueryCallback LeaveAsync(ObjectGuid characterGuid, std::function<void(bool)> callback);
};

#endif // AIWORLD_PLAYERWORLDFACTIONPERSISTENCE_H
