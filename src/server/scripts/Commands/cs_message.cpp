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
#include "Chat.h"
#include "ChatPackets.h"
#include "Channel.h"
#include "ChannelMgr.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
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

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> channelSetCommandTable =
        {
            { "ownership", rbac::RBAC_PERM_COMMAND_CHANNEL_SET_OWNERSHIP, false, &HandleChannelSetOwnership, "" },
        };
        static std::vector<ChatCommand> channelCommandTable =
        {
            { "set", rbac::RBAC_PERM_COMMAND_CHANNEL_SET, true, nullptr, "", channelSetCommandTable },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "channel",        rbac::RBAC_PERM_COMMAND_CHANNEL,        true, nullptr,                      "", channelCommandTable  },
            { "nameannounce",   rbac::RBAC_PERM_COMMAND_NAMEANNOUNCE,   true, &HandleNameAnnounceCommand,   "" },
            { "gmnameannounce", rbac::RBAC_PERM_COMMAND_GMNAMEANNOUNCE, true, &HandleGMNameAnnounceCommand, "" },
            { "announce",       rbac::RBAC_PERM_COMMAND_ANNOUNCE,       true, &HandleAnnounceCommand,       "" },
            { "gmannounce",     rbac::RBAC_PERM_COMMAND_GMANNOUNCE,     true, &HandleGMAnnounceCommand,     "" },
            { "notify",         rbac::RBAC_PERM_COMMAND_NOTIFY,         true, &HandleNotifyCommand,         "" },
            { "gmnotify",       rbac::RBAC_PERM_COMMAND_GMNOTIFY,       true, &HandleGMNotifyCommand,       "" },
            { "whispers",       rbac::RBAC_PERM_COMMAND_WHISPERS,      false, &HandleWhispersCommand,       "" },
        };
        return commandTable;
    }

    static bool HandleChannelSetOwnership(ChatHandler* handler, std::string channelName, bool grantOwnership)
    {
        uint32 channelId = 0;
        for (uint32 i = 0; i < sChatChannelsStore.GetNumRows(); ++i)
        {
            ChatChannelsEntry const* channelEntry = sChatChannelsStore.LookupEntry(i);
            if (!channelEntry)
                continue;

            if (StringContainsStringI(channelEntry->Name[handler->GetSessionDbcLocale()], channelName))
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

        if (ChannelMgr* cMgr = ChannelMgr::ForTeam(player->GetTeam()))
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

    static bool HandleNameAnnounceCommand(ChatHandler* handler, CommandArgs* args)
    {
        if (!*args)
            return false;

        std::string name("Console");
        if (WorldSession* session = handler->GetSession())
            name = session->GetPlayer()->GetName();

        sWorld->SendWorldText(LANG_ANNOUNCE_COLOR, name.c_str(), args->GetFullArgs());
        return true;
    }

    static bool HandleGMNameAnnounceCommand(ChatHandler* handler, CommandArgs* args)
    {
        if (!*args)
            return false;

        std::string name("Console");
        if (WorldSession* session = handler->GetSession())
            name = session->GetPlayer()->GetName();

        sWorld->SendGMText(LANG_GM_ANNOUNCE_COLOR, name.c_str(), args->GetFullArgs());
        return true;
    }

    // global announce
    static bool HandleAnnounceCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string str = handler->PGetParseString(LANG_SYSTEMMESSAGE, args);

        sWorld->SendServerMessage(SERVER_MSG_STRING, str);
        return true;
    }

    // announce to logged in GMs
    static bool HandleGMAnnounceCommand(ChatHandler* /*handler*/, CommandArgs* args)
    {
        if (!*args)
            return false;

        sWorld->SendGMText(LANG_GM_BROADCAST, args->GetFullArgs());
        return true;
    }

    // send on-screen notification to players
    static bool HandleNotifyCommand(ChatHandler* handler, CommandArgs* args)
    {
        if (!*args)
            return false;

        std::string str = handler->GetTrinityString(LANG_GLOBAL_NOTIFY);
        str += args->GetFullArgs();

        sWorld->SendGlobalMessage(WorldPackets::Chat::PrintNotification(str).Write());

        return true;
    }

    // send on-screen notification to GMs
    static bool HandleGMNotifyCommand(ChatHandler* handler, CommandArgs* args)
    {
        if (!*args)
            return false;

        std::string str = handler->GetTrinityString(LANG_GM_NOTIFY);
        str += args->GetFullArgs();

        sWorld->SendGlobalGMMessage(WorldPackets::Chat::PrintNotification(str).Write());

        return true;
    }

    // Enable/Disable accepting whispers (for GM)
    static bool HandleWhispersCommand(ChatHandler* handler, Optional<Variant<bool, ExactSequence<'r', 'e', 'm', 'o', 'v', 'e'>>> operationArg, Optional<std::string> playerNameArg)
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

        if (operationArg->holds_alternative<ExactSequence<'r', 'e', 'm', 'o', 'v', 'e'>>())
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
