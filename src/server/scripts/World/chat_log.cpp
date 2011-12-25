/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "Group.h"

class ChatLogScript : public PlayerScript
{
public:
    ChatLogScript() : PlayerScript("ChatLogScript") { }

    void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg)
    {
        switch (type)
        {
            case CHAT_MSG_ADDON:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog->outChat("[ADDON] [%s][%s][ID:%d] a envoyé : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;

            case CHAT_MSG_SAY:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog->outChat("[DIRE] [%s][%s][ID:%d] a dit : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;

            case CHAT_MSG_EMOTE:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog->outChat("[EMOTE] [%s][%s][ID:%d] %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;

            case CHAT_MSG_YELL:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_PUBLIC))
                    sLog->outChat("[CRIER] [%s][%s][ID:%d] a crié : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;
        }
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver)
    {
        if (lang != LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_WHISPER))
            sLog->outChat("[CHUCHOTER] [%s][%s][ID:%d] chuchote à [%s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), receiver ? receiver->GetName() : "<INCONNU>", msg.c_str());
        else if (lang == LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_ADDON))
            sLog->outChat("[CHUCHOTER][ADDON] [%s][%s][ID:%d] chuchote à [%s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), receiver ? receiver->GetName() : "<INCONNU>", msg.c_str());
    }

    void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group)
    {
        //! NOTE:
        //! LANG_ADDON can only be sent by client in "PARTY", "RAID", "GUILD", "BATTLEGROUND", "WHISPER"
        switch (type)
        {
            case CHAT_MSG_PARTY:
                if (lang != LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_PARTY))
                    sLog->outChat("[GROUPE] [%s][%s][ID:%d][Groupe de %s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), group ? group->GetLeaderName() : "<INCONNU>", msg.c_str());
                else if (lang == LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog->outChat("[GROUPE][ADDON] [%s][%s][ID:%d][Groupe de %s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), group ? group->GetLeaderName() : "<INCONNU>", msg.c_str());
                break;

            case CHAT_MSG_PARTY_LEADER:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_PARTY))
                    sLog->outChat("[GROUPE] [%s][%s][ID:%d][Chef de groupe] : %s", player->GetSession()->GetRankString().c_str(),player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;

            case CHAT_MSG_RAID:
                if (lang != LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_RAID))
                    sLog->outChat("[RAID] [%s][%s][ID:%d][Raid de %s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), group ? group->GetLeaderName() : "<INCONNU>", msg.c_str());
                else if (lang == LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog->outChat("[RAID][ADDON] [%s][%s][ID:%d][Raid de %s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), group ? group->GetLeaderName() : "<INCONNU>", msg.c_str());
                break;

            case CHAT_MSG_RAID_LEADER:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_RAID))
					sLog->outChat("[RAID] [%s][%s][ID:%d][Chef de raid] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;

            case CHAT_MSG_RAID_WARNING:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_RAID))
                    sLog->outChat("[RAID] [ALERTE][%s][%s][ID:%d][Chef de raid] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;

            case CHAT_MSG_BATTLEGROUND:
                if (lang != LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_BGROUND))
                    sLog->outChat("[CHAMP DE BATAILLE] [%s][%s][ID:%d][Champ de bataille de %s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), group ? group->GetLeaderName() : "<INCONNU>", msg.c_str());
                else if (lang == LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog->outChat("[CHAMP DE BATAILLE][ADDON] [%s][%s][ID:%d][Champ de bataille de %s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), group ? group->GetLeaderName() : "<INCONNU>", msg.c_str());
                break;

            case CHAT_MSG_BATTLEGROUND_LEADER:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_BGROUND))
                    sLog->outChat("[CHAMP DE BATAILLE] [%s][%s][ID:%d][Chef de raid] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), msg.c_str());
                break;
        }
    }

    void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
    {
        switch (type)
        {
            case CHAT_MSG_GUILD:
                if (lang != LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_GUILD))
                    sLog->outChat("[GUILDE] [%s][%s][ID:%d][Guilde <%s>] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), guild ? guild->GetName().c_str() : "<INCONNU>", msg.c_str());
                else if (lang == LANG_ADDON && sWorld->getBoolConfig(CONFIG_CHATLOG_ADDON))
                    sLog->outChat("[GUILDE][ADDON] [%s][%s][ID:%d][Guilde <%s>] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), guild ? guild->GetName().c_str() : "<INCONNU>", msg.c_str());
                break;

            case CHAT_MSG_OFFICER:
                if (sWorld->getBoolConfig(CONFIG_CHATLOG_GUILD))
                    sLog->outChat("[GUILDE][OFFICIER] [%s][%s][ID:%d][Guilde <%s>] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), guild ? guild->GetName().c_str() : "<INCONNU>", msg.c_str());
                break;
        }
    }

    void OnChat(Player* player, uint32 /*type*/, uint32 /*lang*/, std::string& msg, Channel* channel)
    {
        bool isSystem = channel &&
                        (channel->HasFlag(CHANNEL_FLAG_TRADE) ||
                         channel->HasFlag(CHANNEL_FLAG_GENERAL) ||
                         channel->HasFlag(CHANNEL_FLAG_CITY) ||
                         channel->HasFlag(CHANNEL_FLAG_LFG));

        if (sWorld->getBoolConfig(CONFIG_CHATLOG_SYSCHAN) && isSystem)
            sLog->outChat("[SYSCHAN] [%s][%s][ID:%d][%s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), channel->GetName().c_str(), msg.c_str());
        else if (sWorld->getBoolConfig(CONFIG_CHATLOG_CHANNEL))
            sLog->outChat("[CHANNEL] [%s][%s][ID:%d][%s] : %s", player->GetSession()->GetRankString().c_str(), player->GetName(), player->GetSession()->GetAccountId(), channel ? channel->GetName().c_str() : "<INCONNU>", msg.c_str());
    }
};

void AddSC_chat_log()
{
    new ChatLogScript();
}
