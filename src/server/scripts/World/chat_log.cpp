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

#include "ScriptMgr.h"
#include "Channel.h"
#include "Group.h"
#include "Guild.h"
#include "Log.h"
#include "Player.h"

#define TC_LOG_CHAT(TYPE, MESSAGE, ...)                           \
    if (lang != LANG_ADDON && lang != LANG_ADDON_LOGGED)          \
        TC_LOG_DEBUG("chat.log." TYPE, MESSAGE, __VA_ARGS__);     \
    else                                                          \
        TC_LOG_DEBUG("chat.log.addon." TYPE, MESSAGE, __VA_ARGS__);

class ChatLogScript : public PlayerScript
{
    public:
        ChatLogScript() : PlayerScript("ChatLogScript") { }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg) override
        {
            switch (type)
            {
                case CHAT_MSG_SAY:
                    TC_LOG_CHAT("say", "Player {} says (language {}): {}",
                        player->GetName(), lang, msg);
                    break;

                case CHAT_MSG_EMOTE:
                    TC_LOG_CHAT("emote", "Player {} emotes: {}",
                        player->GetName(), msg);
                    break;

                case CHAT_MSG_YELL:
                    TC_LOG_CHAT("yell", "Player {} yells (language {}): {}",
                        player->GetName(), lang, msg);
                    break;
            }
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver) override
        {
            TC_LOG_CHAT("whisper", "Player {} tells {}: {}",
               player->GetName(), receiver ? receiver->GetName().c_str() : "<unknown>", msg);
        }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group) override
        {
            //! NOTE:
            //! LANG_ADDON can only be sent by client in "PARTY", "RAID", "GUILD", "BATTLEGROUND", "WHISPER"
            switch (type)
            {
                case CHAT_MSG_PARTY:
                    TC_LOG_CHAT("party", "Player {} tells group with leader {}: {}",
                        player->GetName(), group ? group->GetLeaderName() : "<unknown>", msg);
                    break;

                case CHAT_MSG_PARTY_LEADER:
                    TC_LOG_CHAT("party", "Leader {} tells group: {}",
                        player->GetName(), msg);
                    break;

                case CHAT_MSG_RAID:
                    TC_LOG_CHAT("raid", "Player {} tells raid with leader {}: {}",
                        player->GetName(), group ? group->GetLeaderName() : "<unknown>", msg);
                    break;

                case CHAT_MSG_RAID_LEADER:
                    TC_LOG_CHAT("raid", "Leader player {} tells raid: {}",
                        player->GetName(), msg);
                    break;

                case CHAT_MSG_RAID_WARNING:
                    TC_LOG_CHAT("raid", "Leader player {} warns raid with: {}",
                        player->GetName(), msg);
                    break;

                case CHAT_MSG_INSTANCE_CHAT:
                    TC_LOG_CHAT("bg", "Player {} tells instance with leader {}: {}",
                        player->GetName(), group ? group->GetLeaderName() : "<unknown>", msg);
                    break;

                case CHAT_MSG_INSTANCE_CHAT_LEADER:
                    TC_LOG_CHAT("bg", "Leader player {} tells instance: {}",
                        player->GetName(), msg);
                    break;
            }
        }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild) override
        {
            switch (type)
            {
                case CHAT_MSG_GUILD:
                    TC_LOG_CHAT("guild", "Player {} tells guild {}: {}",
                        player->GetName(), guild ? guild->GetName().c_str() : "<unknown>", msg);
                    break;

                case CHAT_MSG_OFFICER:
                    TC_LOG_CHAT("guild.officer", "Player {} tells guild {} officers: {}",
                        player->GetName(), guild ? guild->GetName().c_str() : "<unknown>", msg);
                    break;
            }
        }

        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel) override
        {
            bool isSystem = channel &&
                            (channel->HasFlag(CHANNEL_FLAG_TRADE) ||
                             channel->HasFlag(CHANNEL_FLAG_GENERAL) ||
                             channel->HasFlag(CHANNEL_FLAG_CITY) ||
                             channel->HasFlag(CHANNEL_FLAG_LFG));

            if (isSystem)
            {
                TC_LOG_CHAT("system", "Player {} tells channel {}: {}",
                    player->GetName(), channel->GetName(), msg);
            }
            else
            {
                std::string channelName = channel ? channel->GetName() : "<unknown>";
                TC_LOG_CHAT("channel." + channelName, "Player {} tells channel {}: {}",
                    player->GetName(), channelName, msg);
            }
        }
};

void AddSC_chat_log()
{
    new ChatLogScript();
}

#undef TC_LOG_CHAT
