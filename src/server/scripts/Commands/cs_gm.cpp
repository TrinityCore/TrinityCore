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
Name: gm_commandscript
%Complete: 100
Comment: All gm related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "DatabaseEnv.h"
#include "Language.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "RealmList.h"
#include "World.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class gm_commandscript : public CommandScript
{
public:
    gm_commandscript() : CommandScript("gm_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable gmCommandTable =
        {
            { "chat",       HandleGMChatCommand,        rbac::RBAC_PERM_COMMAND_GM_CHAT,        Console::No },
            { "fly",        HandleGMFlyCommand,         rbac::RBAC_PERM_COMMAND_GM_FLY,         Console::No },
            { "ingame",     HandleGMListIngameCommand,  rbac::RBAC_PERM_COMMAND_GM_INGAME,      Console::Yes },
            { "list",       HandleGMListFullCommand,    rbac::RBAC_PERM_COMMAND_GM_LIST,        Console::Yes },
            { "visible",    HandleGMVisibleCommand,     rbac::RBAC_PERM_COMMAND_GM_VISIBLE,     Console::No },
            { "on",         HandleGMOnCommand,          rbac::RBAC_PERM_COMMAND_GM,             Console::No },
            { "off",        HandleGMOffCommand,         rbac::RBAC_PERM_COMMAND_GM,             Console::No },
        };
        static ChatCommandTable commandTable =
        {
            { "gm", gmCommandTable },
        };
        return commandTable;
    }

    // Enables or disables the staff badge
    static bool HandleGMChatCommand(ChatHandler* handler, Optional<bool> enableArg)
    {
        if (WorldSession* session = handler->GetSession())
        {
            if (!enableArg)
            {
                if (session->HasPermission(rbac::RBAC_PERM_CHAT_USE_STAFF_BADGE) && session->GetPlayer()->isGMChat())
                    session->SendNotification(LANG_GM_CHAT_ON);
                else
                    session->SendNotification(LANG_GM_CHAT_OFF);
                return true;
            }

            if (*enableArg)
            {
                session->GetPlayer()->SetGMChat(true);
                session->SendNotification(LANG_GM_CHAT_ON);
                return true;
            }
            else
            {
                session->GetPlayer()->SetGMChat(false);
                session->SendNotification(LANG_GM_CHAT_OFF);
                return true;
            }
        }

        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }

    static bool HandleGMFlyCommand(ChatHandler* handler, bool enable)
    {
        Player* target = handler->getSelectedPlayer();
        if (!target)
            target = handler->GetSession()->GetPlayer();

        if (enable)
        {
            target->SetCanFly(true);
            target->SetCanTransitionBetweenSwimAndFly(true);
        }
        else
        {
            target->SetCanFly(false);
            target->SetCanTransitionBetweenSwimAndFly(false);
        }

        handler->PSendSysMessage(LANG_COMMAND_FLYMODE_STATUS, handler->GetNameLink(target).c_str(), enable ? "on" : "off");
        return true;
    }

    static bool HandleGMListIngameCommand(ChatHandler* handler)
    {
        bool first = true;
        bool footer = false;

        std::shared_lock<std::shared_mutex> lock(*HashMapHolder<Player>::GetLock());
        for (auto&& [playerGuid, player] : ObjectAccessor::GetPlayers())
        {
            AccountTypes playerSec = player->GetSession()->GetSecurity();
            if ((player->IsGameMaster() ||
                (player->GetSession()->HasPermission(rbac::RBAC_PERM_COMMANDS_APPEAR_IN_GM_LIST) &&
                    playerSec <= AccountTypes(sWorld->getIntConfig(CONFIG_GM_LEVEL_IN_GM_LIST)))) &&
                (!handler->GetSession() || player->IsVisibleGloballyFor(handler->GetSession()->GetPlayer())))
            {
                if (first)
                {
                    first = false;
                    footer = true;
                    handler->SendSysMessage(LANG_GMS_ON_SRV);
                    handler->SendSysMessage("========================");
                }
                std::string const& name = player->GetName();
                uint8 size = uint8(name.size());
                uint8 security = playerSec;
                uint8 max = ((16 - size) / 2);
                uint8 max2 = max;
                if ((max + max2 + size) == 16)
                    max2 = max - 1;
                if (handler->GetSession())
                    handler->PSendSysMessage("|    %s GMLevel %u", name.c_str(), security);
                else
                    handler->PSendSysMessage("|%*s%s%*s|   %u  |", max, " ", name.c_str(), max2, " ", security);
            }
        }
        if (footer)
            handler->SendSysMessage("========================");
        if (first)
            handler->SendSysMessage(LANG_GMS_NOT_LOGGED);
        return true;
    }

    /// Display the list of GMs
    static bool HandleGMListFullCommand(ChatHandler* handler)
    {
        ///- Get the accounts with GM Level >0
        LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_GM_ACCOUNTS);
        stmt->setUInt8(0, uint8(SEC_MODERATOR));
        stmt->setInt32(1, int32(sRealmList->GetCurrentRealmId().Realm));
        PreparedQueryResult result = LoginDatabase.Query(stmt);

        if (result)
        {
            handler->SendSysMessage(LANG_GMLIST);
            handler->SendSysMessage("========================");
            ///- Cycle through them. Display username and GM level
            do
            {
                Field* fields = result->Fetch();
                char const* name = fields[0].GetCString();
                uint8 security = fields[1].GetUInt8();
                uint8 max = (16 - strlen(name)) / 2;
                uint8 max2 = max;
                if ((max + max2 + strlen(name)) == 16)
                    max2 = max - 1;
                if (handler->GetSession())
                    handler->PSendSysMessage("|    %s GMLevel %u", name, security);
                else
                    handler->PSendSysMessage("|%*s%s%*s|   %u  |", max, " ", name, max2, " ", security);
            } while (result->NextRow());
            handler->SendSysMessage("========================");
        }
        else
            handler->PSendSysMessage(LANG_GMLIST_EMPTY);
        return true;
    }

    //Enable\Disable Invisible mode
    static bool HandleGMVisibleCommand(ChatHandler* handler, Optional<bool> visibleArg)
    {
        Player* _player = handler->GetSession()->GetPlayer();

        if (!visibleArg)
        {
            handler->PSendSysMessage(LANG_YOU_ARE, _player->isGMVisible() ? handler->GetTrinityString(LANG_VISIBLE) : handler->GetTrinityString(LANG_INVISIBLE));
            return true;
        }

        const uint32 VISUAL_AURA = 37800;

        if (*visibleArg)
        {
            if (_player->HasAura(VISUAL_AURA))
                _player->RemoveAurasDueToSpell(VISUAL_AURA);

            _player->SetGMVisible(true);
            _player->UpdateObjectVisibility();
            handler->GetSession()->SendNotification(LANG_INVISIBLE_VISIBLE);
        }
        else
        {
            _player->AddAura(VISUAL_AURA, _player);
            _player->SetGMVisible(false);
            _player->UpdateObjectVisibility();
            handler->GetSession()->SendNotification(LANG_INVISIBLE_INVISIBLE);
        }

        return true;
    }

    static bool HandleGMOnCommand(ChatHandler* handler)
    {
        handler->GetPlayer()->SetGameMaster(true);
        handler->GetPlayer()->UpdateTriggerVisibility();
        handler->GetSession()->SendNotification(LANG_GM_ON);
        return true;
    }

    static bool HandleGMOffCommand(ChatHandler* handler)
    {
        handler->GetPlayer()->SetGameMaster(false);
        handler->GetPlayer()->UpdateTriggerVisibility();
        handler->GetSession()->SendNotification(LANG_GM_OFF);
        return true;
    }
};

void AddSC_gm_commandscript()
{
    new gm_commandscript();
}
