/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "Channel.h"
#include "Common.h"
#include "Configuration/Config.h"
#include "Group.h"
#include "Guild.h"
#include "Log.h"
#include "Player.h"

class ChatLogScript : public PlayerScript
{
    public:
        ChatLogScript() : PlayerScript("ChatLogScript") { }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg) override
        {
            switch (type)
            {
                case CHAT_MSG_SAY:
                    TC_LOG_DEBUG("chat.log.say", "Player %s says (language %u): %s",
                        player->GetName().c_str(), lang, msg.c_str());
                    break;

                case CHAT_MSG_EMOTE:
                    TC_LOG_DEBUG("chat.log.emote", "Player %s emotes: %s",
                        player->GetName().c_str(), msg.c_str());
                    break;

                case CHAT_MSG_YELL:
                    TC_LOG_DEBUG("chat.log.yell", "Player %s yells (language %u): %s",
                        player->GetName().c_str(), lang, msg.c_str());
                    break;
            }
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver) override
        {
            if (lang != LANG_ADDON)
                TC_LOG_DEBUG("chat.log.whisper", "Player %s tells %s: %s",
                    player->GetName().c_str(), receiver ? receiver->GetName().c_str() : "<unknown>", msg.c_str());
            else
                TC_LOG_DEBUG("chat.log.addon.whisper", "Player %s tells %s: %s",
                    player->GetName().c_str(), receiver ? receiver->GetName().c_str() : "<unknown>", msg.c_str());
        }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group) override
        {
            //! NOTE:
            //! LANG_ADDON can only be sent by client in "PARTY", "RAID", "GUILD", "BATTLEGROUND", "WHISPER"
            switch (type)
            {
                case CHAT_MSG_PARTY:
                    if (lang != LANG_ADDON)
                        TC_LOG_DEBUG("chat.log.party", "Player %s tells group with leader %s: %s",
                            player->GetName().c_str(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                    else
                        TC_LOG_DEBUG("chat.log.addon.party", "Player %s tells group with leader %s: %s",
                            player->GetName().c_str(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                    break;

                case CHAT_MSG_PARTY_LEADER:
                    TC_LOG_DEBUG("chat.log.party", "Leader %s tells group: %s",
                        player->GetName().c_str(), msg.c_str());
                    break;

                case CHAT_MSG_RAID:
                    if (lang != LANG_ADDON)
                        TC_LOG_DEBUG("chat.log.raid", "Player %s tells raid with leader %s: %s",
                            player->GetName().c_str(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                    else
                        TC_LOG_DEBUG("chat.log.addon.raid", "Player %s tells raid with leader %s: %s",
                            player->GetName().c_str(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                    break;

                case CHAT_MSG_RAID_LEADER:
                    TC_LOG_DEBUG("chat.log.raid", "Leader player %s tells raid: %s",
                        player->GetName().c_str(), msg.c_str());
                    break;

                case CHAT_MSG_RAID_WARNING:
                    TC_LOG_DEBUG("chat.log.raid", "Leader player %s warns raid with: %s",
                        player->GetName().c_str(), msg.c_str());
                    break;

                case CHAT_MSG_INSTANCE_CHAT:
                    if (lang != LANG_ADDON)
                        TC_LOG_DEBUG("chat.log.bg", "Player %s tells instance with leader %s: %s",
                            player->GetName().c_str(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                    else
                        TC_LOG_DEBUG("chat.log.addon.bg", "Player %s tells instance with leader %s: %s",
                            player->GetName().c_str(), group ? group->GetLeaderName() : "<unknown>", msg.c_str());
                    break;

                case CHAT_MSG_INSTANCE_CHAT_LEADER:
                    TC_LOG_DEBUG("chat.log.bg", "Leader player %s tells instance: %s",
                        player->GetName().c_str(), msg.c_str());
                    break;
            }
        }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild) override
        {
            switch (type)
            {
                case CHAT_MSG_GUILD:
                    if (lang != LANG_ADDON)
                        TC_LOG_DEBUG("chat.log.guild", "Player %s tells guild %s: %s",
                            player->GetName().c_str(), guild ? guild->GetName().c_str() : "<unknown>", msg.c_str());
                    else
                        TC_LOG_DEBUG("chat.log.addon.guild", "Player %s sends to guild %s: %s",
                            player->GetName().c_str(), guild ? guild->GetName().c_str() : "<unknown>", msg.c_str());
                    break;

                case CHAT_MSG_OFFICER:
                    TC_LOG_DEBUG("chat.log.guild.officer", "Player %s tells guild %s officers: %s",
                        player->GetName().c_str(), guild ? guild->GetName().c_str() : "<unknown>", msg.c_str());
                    break;
            }
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Channel* channel) override
        {
            bool isSystem = channel &&
                            (channel->HasFlag(CHANNEL_FLAG_TRADE) ||
                             channel->HasFlag(CHANNEL_FLAG_GENERAL) ||
                             channel->HasFlag(CHANNEL_FLAG_CITY) ||
                             channel->HasFlag(CHANNEL_FLAG_LFG));

            if (isSystem)
                TC_LOG_DEBUG("chat.log.system", "Player %s tells channel %s: %s",
                    player->GetName().c_str(), channel->GetName().c_str(), msg.c_str());
            else
            {
                std::string channelName = channel ? channel->GetName() : "<unknown>";
                TC_LOG_DEBUG("chat.log.channel." + channelName, "Player %s tells channel %s: %s",
                    player->GetName().c_str(), channelName.c_str(), msg.c_str());
            }

#ifdef WITH_CPR
            if (sConfigMgr->GetBoolDefault("WorldToDiscord.Enabled", false))
            {
                if (player->GetSession() && channel->IsWorld())
                {
                    DiscordMessage* new_message = new DiscordMessage();
                    new_message->channel        = player->GetTeamId() == TEAM_ALLIANCE ? DISCORD_WORLD_A : DISCORD_WORLD_H;
                    new_message->isGm           = player->isGMChat();
                    new_message->characterName  = player->GetName();
                    new_message->message        = msg;
                    DiscordMessageQueue.add(new_message);
                }
            }
#endif
        }
};

void AddSC_chat_log()
{
    new ChatLogScript();
}
