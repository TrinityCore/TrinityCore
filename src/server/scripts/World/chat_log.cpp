/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ScriptPCH.h"
#include "Channel.h"
#include "Guild.h"

class ChatLogScript : public PlayerScript
{
public:
    ChatLogScript() : PlayerScript("ChatLogScript") { }

    void OnChat(Player* player, uint32 type, uint32 lang, std::string msg, void* param)
    {
        switch (type)
        {
            case CHAT_MSG_ADDON:
                if (sWorld.getConfig(CONFIG_CHATLOG_ADDON))
                    sLog.outChat("[ADDON] Player %s sends: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_SAY:
                if (sWorld.getConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog.outChat("[SAY] Player %s says (language %u): %s",
                        player->GetName(), lang, msg.c_str());
                break;

            case CHAT_MSG_EMOTE:
                if (sWorld.getConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog.outChat("[TEXTEMOTE] Player %s emotes: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_YELL:
                if (sWorld.getConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog.outChat("[YELL] Player %s yells (language %u): %s",
                        player->GetName(), lang, msg.c_str());
                break;

            case CHAT_MSG_WHISPER:
                if (sWorld.getConfig(CONFIG_CHATLOG_WHISPER))
                {
                    Player* pReceiver = reinterpret_cast <Player*> (param);
                    sLog.outChat("[WHISPER] Player %s tells %s: %s",
                        player->GetName(), pReceiver ? pReceiver->GetName() : "<unknown>", msg.c_str());
                }
                break;

            case CHAT_MSG_PARTY:
                if (sWorld.getConfig(CONFIG_CHATLOG_PARTY))
                {
                    Group* pGroup = reinterpret_cast <Group*> (param);
                    sLog.outChat("[PARTY] Player %s tells group with leader %s: %s",
                        player->GetName(), pGroup ? pGroup->GetLeaderName() : "<unknown>", msg.c_str());
                }
                break;

            case CHAT_MSG_PARTY_LEADER:
                if (sWorld.getConfig(CONFIG_CHATLOG_PARTY))
                    sLog.outChat("[PARTY] Leader %s tells group: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_GUILD:
            {
                Guild* pGuild = reinterpret_cast <Guild*> (param);
                if (lang != LANG_ADDON && sWorld.getConfig(CONFIG_CHATLOG_GUILD))
                {
                    sLog.outChat("[GUILD] Player %s tells guild %s: %s",
                        player->GetName(), pGuild ? pGuild->GetName().c_str() : "<unknown>", msg.c_str());
                }
                else if (lang == LANG_ADDON && sWorld.getConfig(CONFIG_CHATLOG_ADDON))
                {
                    sLog.outChat("[ADDON] Player %s sends to guild %s: %s",
                        player->GetName(), pGuild ? pGuild->GetName().c_str() : "<unknown>", msg.c_str());
                }
                break;
            }

            case CHAT_MSG_OFFICER:
                if (sWorld.getConfig(CONFIG_CHATLOG_GUILD))
                {
                    Guild* pGuild = reinterpret_cast <Guild*> (param);
                    sLog.outChat("[OFFICER] Player %s tells guild %s officers: %s",
                        player->GetName(), pGuild ? pGuild->GetName().c_str() : "<unknown>", msg.c_str());
                }
                break;

            case CHAT_MSG_RAID:
                if (sWorld.getConfig(CONFIG_CHATLOG_RAID))
                {
                    Group* pGroup = reinterpret_cast <Group*> (param);
                    sLog.outChat("[RAID] Player %s tells raid with leader %s: %s",
                        player->GetName(), pGroup ? pGroup->GetLeaderName() : "<unknown>", msg.c_str());
                }
                break;

            case CHAT_MSG_RAID_LEADER:
                if (sWorld.getConfig(CONFIG_CHATLOG_RAID))
                    sLog.outChat("[RAID] Leader player %s tells raid: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_RAID_WARNING:
                if (sWorld.getConfig(CONFIG_CHATLOG_RAID))
                    sLog.outChat("[RAID] Leader player %s warns raid with: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_BATTLEGROUND:
                if (sWorld.getConfig(CONFIG_CHATLOG_BGROUND))
                {
                    Group* pGroup = reinterpret_cast <Group*> (param);
                    sLog.outChat("[BATTLEGROUND] Player %s tells battleground with leader %s: %s",
                        player->GetName(), pGroup ? pGroup->GetLeaderName() : "<unknown>", msg.c_str());
                }
                break;

            case CHAT_MSG_BATTLEGROUND_LEADER:
                if (sWorld.getConfig(CONFIG_CHATLOG_BGROUND))
                    sLog.outChat("[RAID] Leader player %s tells battleground: %s",
                        player->GetName(), msg.c_str());
                break;

            case CHAT_MSG_CHANNEL:
            {
                Channel* pChannel = reinterpret_cast <Channel*> (param);
                bool isSystem = pChannel && 
                    (pChannel->HasFlag(CHANNEL_FLAG_TRADE) ||
                     pChannel->HasFlag(CHANNEL_FLAG_GENERAL) ||
                     pChannel->HasFlag(CHANNEL_FLAG_CITY) ||
                     pChannel->HasFlag(CHANNEL_FLAG_LFG));
                if (sWorld.getConfig(CONFIG_CHATLOG_SYSCHAN) && isSystem)
                    sLog.outChat("[SYSCHAN] Player %s tells channel %s: %s",
                        player->GetName(), pChannel->GetName().c_str(), msg.c_str());
                else if (sWorld.getConfig(CONFIG_CHATLOG_CHANNEL))
                    sLog.outChat("[CHANNEL] Player %s tells channel %s: %s",
                        player->GetName(), pChannel ? pChannel->GetName().c_str() : "<unknown>", msg.c_str());
                break;
            }
        }
    }
};

void AddSC_chat_log()
{
    new ChatLogScript();
}
