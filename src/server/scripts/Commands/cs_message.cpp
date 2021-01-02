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
Name: message_commandscript
%Complete: 100
Comment: All message related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Language.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "World.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class message_commandscript : public CommandScript
{
public:
    message_commandscript() : CommandScript("message_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable commandTable =
        {
            { "channel set ownership",  HandleChannelSetOwnership,      rbac::RBAC_PERM_COMMAND_CHANNEL_SET_OWNERSHIP,  Console::No },
            { "nameannounce",           HandleNameAnnounceCommand,      rbac::RBAC_PERM_COMMAND_NAMEANNOUNCE,           Console::Yes },
            { "gmnameannounce",         HandleGMNameAnnounceCommand,    rbac::RBAC_PERM_COMMAND_GMNAMEANNOUNCE,         Console::Yes },
            { "announce",               HandleAnnounceCommand,          rbac::RBAC_PERM_COMMAND_ANNOUNCE,               Console::Yes },
            { "gmannounce",             HandleGMAnnounceCommand,        rbac::RBAC_PERM_COMMAND_GMANNOUNCE,             Console::Yes },
            { "notify",                 HandleNotifyCommand,            rbac::RBAC_PERM_COMMAND_NOTIFY,                 Console::Yes },
            { "gmnotify",               HandleGMNotifyCommand,          rbac::RBAC_PERM_COMMAND_GMNOTIFY,               Console::Yes },
            { "whispers",               HandleWhispersCommand,          rbac::RBAC_PERM_COMMAND_WHISPERS,               Console::No },
        };
        return commandTable;
    }

    static bool HandleChannelSetOwnership(ChatHandler* handler, std::string channelName, bool grantOwnership)
    {
        uint32 channelId = 0;
        for (uint32 i = 0; i < sChatChannelsStore.GetNumRows(); ++i)
        {
            ChatChannelsEntry const* entry = sChatChannelsStore.LookupEntry(i);
            if (!entry)
                continue;

            if (StringContainsStringI(entry->Name[handler->GetSessionDbcLocale()], channelName))
            {
                channelId = i;
                break;
            }
        }

        AreaTableEntry const* zoneEntry = nullptr;
        for (uint32 i = 0; i < sAreaTableStore.GetNumRows(); ++i)
        {
            AreaTableEntry const* entry = sAreaTableStore.LookupEntry(i);
            if (!entry)
                continue;

            if (StringContainsStringI(entry->AreaName[handler->GetSessionDbcLocale()], channelName))
            {
                zoneEntry = entry;
                break;
            }
        }

        Player* player = handler->GetSession()->GetPlayer();
        Channel* channel = nullptr;

        if (ChannelMgr* cMgr = ChannelMgr::forTeam(player->GetTeam()))
            channel = cMgr->GetChannel(channelId, channelName, player, false, zoneEntry);

        if (grantOwnership)
        {
            if (channel)
                channel->SetOwnership(true);
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHANNEL_OWNERSHIP);
            stmt->setUInt8 (0, 1);
            stmt->setString(1, channelName);
            CharacterDatabase.Execute(stmt);
            handler->PSendSysMessage(LANG_CHANNEL_ENABLE_OWNERSHIP, channelName.c_str());
        }
        else
        {
            if (channel)
                channel->SetOwnership(false);
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_CHANNEL_OWNERSHIP);
            stmt->setUInt8 (0, 0);
            stmt->setString(1, channelName);
            CharacterDatabase.Execute(stmt);
            handler->PSendSysMessage(LANG_CHANNEL_DISABLE_OWNERSHIP, channelName.c_str());
        }

        return true;
    }

    static bool HandleNameAnnounceCommand(ChatHandler* handler, Tail message)
    {
        if (message.empty())
            return false;

        std::string name("Console");
        if (WorldSession* session = handler->GetSession())
            name = session->GetPlayer()->GetName();

        sWorld->SendWorldText(LANG_ANNOUNCE_COLOR, name.c_str(), message.data());
        return true;
    }

    static bool HandleGMNameAnnounceCommand(ChatHandler* handler, Tail message)
    {
        if (message.empty())
            return false;

        std::string name("Console");
        if (WorldSession* session = handler->GetSession())
            name = session->GetPlayer()->GetName();

        sWorld->SendGMText(LANG_GM_ANNOUNCE_COLOR, name.c_str(), message.data());
        return true;
    }

    // global announce
    static bool HandleAnnounceCommand(ChatHandler* handler, Tail message)
    {
        if (message.empty())
            return false;

        sWorld->SendServerMessage(SERVER_MSG_STRING, Trinity::StringFormat(handler->GetTrinityString(LANG_SYSTEMMESSAGE), message.data()).c_str());
        return true;
    }

    // announce to logged in GMs
    static bool HandleGMAnnounceCommand(ChatHandler* /*handler*/, Tail message)
    {
        if (message.empty())
            return false;

        sWorld->SendGMText(LANG_GM_BROADCAST, message.data());
        return true;
    }

    // send on-screen notification to players
    static bool HandleNotifyCommand(ChatHandler* handler, Tail message)
    {
        if (message.empty())
            return false;

        std::string str = handler->GetTrinityString(LANG_GLOBAL_NOTIFY);
        str += message;

        WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
        data << str;
        sWorld->SendGlobalMessage(&data);

        return true;
    }

    // send on-screen notification to GMs
    static bool HandleGMNotifyCommand(ChatHandler* handler, Tail message)
    {
        if (message.empty())
            return false;

        std::string str = handler->GetTrinityString(LANG_GM_NOTIFY);
        str += message;

        WorldPacket data(SMSG_NOTIFICATION, (str.size() + 1));
        data << str;
        sWorld->SendGlobalGMMessage(&data);

        return true;
    }

    // Enable/Disable accepting whispers (for GM)
    static bool HandleWhispersCommand(ChatHandler* handler, Optional<Variant<bool, EXACT_SEQUENCE("remove")>> operationArg, Optional<std::string> playerNameArg)
    {
        if (!operationArg)
        {
            handler->PSendSysMessage(LANG_COMMAND_WHISPERACCEPTING, handler->GetSession()->GetPlayer()->isAcceptWhispers() ?  handler->GetTrinityString(LANG_ON) : handler->GetTrinityString(LANG_OFF));
            return true;
        }

        if (operationArg->holds_alternative<bool>())
        {
            if (operationArg->get<bool>())
            {
                handler->GetSession()->GetPlayer()->SetAcceptWhispers(true);
                handler->SendSysMessage(LANG_COMMAND_WHISPERON);
                return true;
            }
            else
            {
                // Remove all players from the Gamemaster's whisper whitelist
                handler->GetSession()->GetPlayer()->ClearWhisperWhiteList();
                handler->GetSession()->GetPlayer()->SetAcceptWhispers(false);
                handler->SendSysMessage(LANG_COMMAND_WHISPEROFF);
                return true;
            }
        }

        if (operationArg->holds_alternative<EXACT_SEQUENCE("remove")>())
        {
            if (!playerNameArg)
                return false;

            if (normalizePlayerName(*playerNameArg))
            {
                if (Player* player = ObjectAccessor::FindPlayerByName(*playerNameArg))
                {
                    handler->GetSession()->GetPlayer()->RemoveFromWhisperWhiteList(player->GetGUID());
                    handler->PSendSysMessage(LANG_COMMAND_WHISPEROFFPLAYER, playerNameArg->c_str());
                    return true;
                }
                else
                {
                    handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND, playerNameArg->c_str());
                    handler->SetSentErrorMessage(true);
                    return false;
                }
            }
        }
        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }
};

void AddSC_message_commandscript()
{
    new message_commandscript();
}
