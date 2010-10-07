/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "Channel.h"
#include "Guild.h"

class ChatLogScript : public PlayerScript
{
public:
    ChatLogScript() : PlayerScript("ChatLogScript") { }

    void OnChat(Player* player, uint32 type, uint32 lang, std::string msg)
    {
        switch (type)
        {
            case CHAT_MSG_ADDON:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog.outChat("[ADDON] Player %s sends: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_SAY:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog.outChat("[SAY] Player %s says (language %u): %s",
                        player->GetName(), lang, msg.c_str());
                break;

            case CHAT_MSG_EMOTE:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog.outChat("[TEXTEMOTE] Player %s emotes: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_YELL:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog.outChat("[YELL] Player %s yells (language %u): %s",
                        player->GetName(), lang, msg.c_str());
                break;
        }
    }

    void OnChat(Player *player, uint32 /*type*/, uint32 /*lang*/, std::string msg, Player *receiver)
    {
        if (sWorld.getBoolConfig(CONFIG_CHATLOG_WHISPER))
            sLog.outChat("[WHISPER] Player %s tells %s: %s",
                player->GetName(), receiver ? receiver->GetName() : "<unknown>", msg.c_str());
    }

    void OnChat(Player *player, uint32 type, uint32 /*lang*/, std::string msg, Group *group)
    {
        switch (type)
        {
            case CHAT_MSG_PARTY:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_PARTY))
                    sLog.outChat("[PARTY] Player %s tells group with leader %s: %s",
                        player->GetName(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                break;

            case CHAT_MSG_PARTY_LEADER:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_PARTY))
                    sLog.outChat("[PARTY] Leader %s tells group: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_RAID:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_RAID))
                    sLog.outChat("[RAID] Player %s tells raid with leader %s: %s",
                        player->GetName(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                break;

            case CHAT_MSG_RAID_LEADER:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_RAID))
                    sLog.outChat("[RAID] Leader player %s tells raid: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_RAID_WARNING:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_RAID))
                    sLog.outChat("[RAID] Leader player %s warns raid with: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_BATTLEGROUND:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_BGROUND))
                    sLog.outChat("[BATTLEGROUND] Player %s tells battleground with leader %s: %s",
                        player->GetName(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                break;

            case CHAT_MSG_BATTLEGROUND_LEADER:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_BGROUND))
                    sLog.outChat("[BATTLEGROUND] Leader player %s tells battleground: %s",
                        player->GetName(), msg.c_str());
                break;
        }
    }

    void OnChat(Player *player, uint32 type, uint32 lang, std::string msg, Guild *guild)
    {
        switch(type)
        {
            case CHAT_MSG_GUILD:
                if (lang != LANG_ADDON && sWorld.getBoolConfig(CONFIG_CHATLOG_GUILD))
                    sLog.outChat("[GUILD] Player %s tells guild %s: %s",
                        player->GetName(), guild ? guild->GetName().c_str() : "<unknown>", msg.c_str());
                else if (lang == LANG_ADDON && sWorld.getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog.outChat("[ADDON] Player %s sends to guild %s: %s",
                        player->GetName(), guild ? guild->GetName().c_str() : "<unknown>", msg.c_str());
                break;

            case CHAT_MSG_OFFICER:
                if (sWorld.getBoolConfig(CONFIG_CHATLOG_GUILD))
                    sLog.outChat("[OFFICER] Player %s tells guild %s officers: %s",
                        player->GetName(), guild ? guild->GetName().c_str() : "<unknown>", msg.c_str());
                break;
        }
    }

    void OnChat(Player *player, uint32 /*type*/, uint32 /*lang*/, std::string msg, Channel *channel)
    {
        bool isSystem = channel &&
                        (channel->HasFlag(CHANNEL_FLAG_TRADE) ||
                         channel->HasFlag(CHANNEL_FLAG_GENERAL) ||
                         channel->HasFlag(CHANNEL_FLAG_CITY) ||
                         channel->HasFlag(CHANNEL_FLAG_LFG));

        if (sWorld.getBoolConfig(CONFIG_CHATLOG_SYSCHAN) && isSystem)
            sLog.outChat("[SYSCHAN] Player %s tells channel %s: %s",
                player->GetName(), channel->GetName().c_str(), msg.c_str());
        else if (sWorld.getBoolConfig(CONFIG_CHATLOG_CHANNEL))
            sLog.outChat("[CHANNEL] Player %s tells channel %s: %s",
                player->GetName(), channel ? channel->GetName().c_str() : "<unknown>", msg.c_str());
    }
};

void AddSC_chat_log()
{
    new ChatLogScript();
}
