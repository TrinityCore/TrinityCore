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

/* ScriptData
Name: aiworld_faction_commandscript
%Complete: 100
Comment: .aiworld faction status/join/leave - GM/debug interface for
    PlayerWorldFactionPersistence (AIWorld_Current_Roadmap.md, player
    WorldFaction membership vertical slice). A thin wrapper only: every
    subcommand calls straight into the existing LoadMembershipAsync()/
    JoinAsync()/LeaveAsync() methods, no direct SQL here. Operates on the
    command issuer's own character, the same "self" convention .gm on/off
    already uses - there is no target-player syntax.

    Async, NOT the synchronous LoadMembership()/Join()/Leave() overloads:
    CMSG_MESSAGECHAT is PROCESS_THREADUNSAFE (Opcodes.cpp) and is processed
    inline on World::UpdateSessions(), the world thread itself - a
    CONNECTION_SYNCH/DirectExecute() call from here would block the whole
    world tick on a DB round trip (up to three, for Join()'s own load-then-
    write-then-confirm sequence), exactly what PlayerWorldFactionPersistence's
    own header comment says never to do. Every subcommand instead registers
    the returned QueryCallback on the command issuer's own WorldSession::
    GetQueryProcessor(), so the DB work happens on a database worker thread
    and the result is only applied (PSendSysMessage etc.) later, on the
    world thread, once that session's query processor drains it - never
    blocking this handler's own stack frame.

    Deliberately long-lived tooling, not a temporary startup smoke test:
    this is the only way to exercise Join()/Leave()/LoadMembership() at all
    right now, since PlayerFactionRelationResolver (the intended production
    consumer) does not exist yet.
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Faction/PlayerWorldFactionPersistence.h"
#include "Faction/WorldFactionId.h"
#include "Player.h"
#include "WorldSession.h"
#include <string>

using namespace Trinity::ChatCommands;

namespace
{
    // Debug-only display name for the known WorldFactions - mirrors the
    // named constants in WorldFactionId.h's own WorldFactions namespace
    // (data/elwynn/factions/world_factions.csv is the real source of
    // truth). Not a general-purpose catalog lookup - just enough for this
    // command's own status/join/leave feedback.
    //
    // Returns a distinct "UNKNOWN(<id>)" string for any nonzero id outside
    // the known set, never silently folded into "Unaffiliated" - the
    // schema has no FK/check constraint against a WorldFaction catalog, so
    // a corrupt/out-of-range stored world_faction_id is a real possibility
    // this diagnostic tool must surface, not mask as if nothing were wrong.
    std::string WorldFactionDisplayName(WorldFactionId faction)
    {
        if (!faction)
            return "Unaffiliated";
        if (faction == WorldFactions::StormwindAlliance)
            return "Stormwind Alliance";
        if (faction == WorldFactions::DefiasBrotherhood)
            return "Defias Brotherhood";
        if (faction == WorldFactions::RiverpawGnolls)
            return "Riverpaw Gnolls";
        if (faction == WorldFactions::ElwynnKobolds)
            return "Elwynn Kobolds";
        if (faction == WorldFactions::ElwynnMurlocs)
            return "Elwynn Murlocs";
        if (faction == WorldFactions::ElwynnWolves)
            return "Elwynn Wolves";
        return "UNKNOWN(" + std::to_string(faction.Value) + ")";
    }
}

class aiworld_faction_commandscript : public CommandScript
{
public:
    aiworld_faction_commandscript() : CommandScript("aiworld_faction_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable joinFactionTable =
        {
            { "stormwind", HandleAIWorldFactionJoinStormwindCommand, rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "defias",    HandleAIWorldFactionJoinDefiasCommand,    rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "riverpaw",  HandleAIWorldFactionJoinRiverpawCommand,  rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "kobolds",   HandleAIWorldFactionJoinKoboldsCommand,   rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "murlocs",   HandleAIWorldFactionJoinMurlocsCommand,   rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "wolves",    HandleAIWorldFactionJoinWolvesCommand,    rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
        };
        static ChatCommandTable factionTable =
        {
            { "status", HandleAIWorldFactionStatusCommand, rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "leave",  HandleAIWorldFactionLeaveCommand,  rbac::RBAC_PERM_COMMAND_DEBUG, Console::No },
            { "join",   joinFactionTable },
        };
        static ChatCommandTable aiworldTable =
        {
            { "faction", factionTable },
        };
        static ChatCommandTable commandTable =
        {
            { "aiworld", aiworldTable },
        };
        return commandTable;
    }

    static bool HandleAIWorldFactionStatusCommand(ChatHandler* handler)
    {
        WorldSession* session = handler->GetSession();
        ObjectGuid characterGuid = session->GetPlayer()->GetGUID();

        PlayerWorldFactionPersistence persistence;
        session->GetQueryProcessor().AddCallback(persistence.LoadMembershipAsync(characterGuid,
            [session](WorldFactionId current)
        {
            session->SendNotification("AIWorld WorldFaction membership: %s", WorldFactionDisplayName(current).c_str());
        }));

        return true;
    }

    static bool HandleAIWorldFactionLeaveCommand(ChatHandler* handler)
    {
        WorldSession* session = handler->GetSession();
        ObjectGuid characterGuid = session->GetPlayer()->GetGUID();

        PlayerWorldFactionPersistence persistence;
        session->GetQueryProcessor().AddCallback(persistence.LeaveAsync(characterGuid,
            [session](bool confirmed)
        {
            if (!confirmed)
            {
                session->SendNotification("AIWorld WorldFaction membership: Leave() failed - see the worldserver log for details.");
                return;
            }

            session->SendNotification("AIWorld WorldFaction membership: left (now Unaffiliated).");
        }));

        return true;
    }

    static bool HandleJoin(ChatHandler* handler, WorldFactionId faction)
    {
        WorldSession* session = handler->GetSession();
        ObjectGuid characterGuid = session->GetPlayer()->GetGUID();
        std::string factionName = WorldFactionDisplayName(faction);

        PlayerWorldFactionPersistence persistence;
        session->GetQueryProcessor().AddCallback(persistence.JoinAsync(characterGuid, faction,
            [session, factionName](bool confirmed)
        {
            if (!confirmed)
            {
                session->SendNotification("AIWorld WorldFaction membership: Join(%s) failed - see the worldserver log for details.", factionName.c_str());
                return;
            }

            session->SendNotification("AIWorld WorldFaction membership: joined %s.", factionName.c_str());
        }));

        return true;
    }

    static bool HandleAIWorldFactionJoinStormwindCommand(ChatHandler* handler) { return HandleJoin(handler, WorldFactions::StormwindAlliance); }
    static bool HandleAIWorldFactionJoinDefiasCommand(ChatHandler* handler)    { return HandleJoin(handler, WorldFactions::DefiasBrotherhood); }
    static bool HandleAIWorldFactionJoinRiverpawCommand(ChatHandler* handler)  { return HandleJoin(handler, WorldFactions::RiverpawGnolls); }
    static bool HandleAIWorldFactionJoinKoboldsCommand(ChatHandler* handler)   { return HandleJoin(handler, WorldFactions::ElwynnKobolds); }
    static bool HandleAIWorldFactionJoinMurlocsCommand(ChatHandler* handler)   { return HandleJoin(handler, WorldFactions::ElwynnMurlocs); }
    static bool HandleAIWorldFactionJoinWolvesCommand(ChatHandler* handler)    { return HandleJoin(handler, WorldFactions::ElwynnWolves); }
};

void AddSC_aiworld_faction_commandscript()
{
    new aiworld_faction_commandscript();
}
