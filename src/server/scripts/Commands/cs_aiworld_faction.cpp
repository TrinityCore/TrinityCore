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
    subcommand calls straight into the existing LoadMembership()/Join()/
    Leave() methods, no direct SQL here. Operates on the command issuer's
    own character, the same "self" convention .gm on/off already uses -
    there is no target-player syntax (a GM testing their own membership
    across relog/restart does not need one, and adding target selection is
    easy to bolt on later without breaking this command's own shape).
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

using namespace Trinity::ChatCommands;

namespace
{
    // Debug-only display name for the known WorldFactions - mirrors the
    // named constants in WorldFactionId.h's own WorldFactions namespace
    // (data/elwynn/factions/world_factions.csv is the real source of
    // truth). Not a general-purpose catalog lookup - just enough for this
    // command's own status/join/leave feedback.
    char const* WorldFactionDisplayName(WorldFactionId faction)
    {
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
        return "Unaffiliated";
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
        Player* player = handler->GetSession()->GetPlayer();

        PlayerWorldFactionPersistence persistence;
        WorldFactionId current = persistence.LoadMembership(player->GetGUID());

        handler->PSendSysMessage("AIWorld WorldFaction membership: %s", WorldFactionDisplayName(current));
        return true;
    }

    static bool HandleAIWorldFactionLeaveCommand(ChatHandler* handler)
    {
        Player* player = handler->GetSession()->GetPlayer();

        PlayerWorldFactionPersistence persistence;
        if (!persistence.Leave(player->GetGUID()))
        {
            handler->PSendSysMessage("AIWorld WorldFaction membership: Leave() failed - see the worldserver log for details.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("AIWorld WorldFaction membership: left (now Unaffiliated).");
        return true;
    }

    static bool HandleJoin(ChatHandler* handler, WorldFactionId faction)
    {
        Player* player = handler->GetSession()->GetPlayer();

        PlayerWorldFactionPersistence persistence;
        if (!persistence.Join(player->GetGUID(), faction))
        {
            handler->PSendSysMessage("AIWorld WorldFaction membership: Join(%s) failed - see the worldserver log for details.", WorldFactionDisplayName(faction));
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage("AIWorld WorldFaction membership: joined %s.", WorldFactionDisplayName(faction));
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
