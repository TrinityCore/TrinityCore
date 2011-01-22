/*
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
#include "ObjectMgr.h"
#include "Chat.h"

class anticheat_commandscript : public CommandScript
{
public:
    anticheat_commandscript() : CommandScript("anticheat_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand anticheatCommandTable[] =
        {
            { "global",         SEC_GAMEMASTER,     true,  &HandleAntiCheatGlobalCommand,         "", NULL },
            { "player",         SEC_GAMEMASTER,     true,  &HandleAntiCheatPlayerCommand,         "", NULL },
            { "delete",         SEC_ADMINISTRATOR,  true,  &HandleAntiCheatDeleteCommand,         "", NULL },
            { "handle",         SEC_ADMINISTRATOR,  true,  &HandleAntiCheatHandleCommand,         "", NULL },
            { "jail",           SEC_GAMEMASTER,     true,  &HandleAnticheatJailCommand,         "", NULL },
            { "warn",           SEC_GAMEMASTER,     true,  &HandleAnticheatWarnCommand,         "", NULL },
            { NULL,             0,                     false, NULL,                                           "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "anticheat",      SEC_GAMEMASTER,     true, NULL,                     "",  anticheatCommandTable},
            { NULL,             0,                  false, NULL,                               "", NULL }
        };

        return commandTable;
    }

    static bool HandleAnticheatWarnCommand(ChatHandler* handler, const char* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        Player* pTarget = NULL;
        
        std::string strCommand;

        char* command = strtok((char*)args, " ");

        if (command)
        {
            strCommand = command;
            normalizePlayerName(strCommand);

            pTarget = sObjectMgr->GetPlayer(strCommand.c_str()); //get player by name
        }else 
            pTarget = handler->getSelectedPlayer();

        if (!pTarget)
            return false;
        
        WorldPacket data;

        // need copy to prevent corruption by strtok call in LineFromMessage original string
        char* buf = strdup("The anticheat system has reported several times that you may be cheating. You will be monitored to confirm if this is accurate.");
        char* pos = buf;

        while (char* line = handler->LineFromMessage(pos))
        {
            handler->FillSystemMessageData(&data, line);
            pTarget->GetSession()->SendPacket(&data);
        }

        free(buf);
        return true;
    }

    static bool HandleAnticheatJailCommand(ChatHandler* handler, const char* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        Player* pTarget = NULL;
        
        std::string strCommand;

        char* command = strtok((char*)args, " ");

        if (command)
        {
            strCommand = command;
            normalizePlayerName(strCommand);

            pTarget = sObjectMgr->GetPlayer(strCommand.c_str()); //get player by name
        }else 
            pTarget = handler->getSelectedPlayer();

        if (!pTarget)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (pTarget == handler->GetSession()->GetPlayer())
            return false;
    
        // teleport both to jail.
        pTarget->TeleportTo(1,16226.5f,16403.6f,-64.5f,3.2f);
        handler->GetSession()->GetPlayer()->TeleportTo(1,16226.5f,16403.6f,-64.5f,3.2f);

        WorldLocation loc;

        // the player should be already there, but no :(
        // pTarget->GetPosition(&loc);

        loc.m_mapId = 1;
        loc.m_positionX = 16226.5f;
        loc.m_positionY = 16403.6f;
        loc.m_positionZ = -64.5f;
        loc.m_orientation = 3.2f;

        pTarget->SetHomebind(loc,876);
        return true;
    }

    static bool HandleAntiCheatDeleteCommand(ChatHandler* handler, const char* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        std::string strCommand;

        char* command = strtok((char*)args, " "); //get entered name

        if (!command)
            return true;
        
        strCommand = command;
        
        if (strCommand.compare("deleteall") == 0)
            CharacterDatabase.PExecute("DELETE FROM players_reports_status;");
        else
        {
            normalizePlayerName(strCommand);
            Player* pPlayer = sObjectMgr->GetPlayer(strCommand.c_str()); //get player by name

            if (!pPlayer)
                handler->PSendSysMessage("Player doesn't exist");
            else
                CharacterDatabase.PExecute("DELETE FROM players_reports_status WHERE guid=%u;",pPlayer->GetGUIDLow());
        }

        return true;
    }

    static bool HandleAntiCheatPlayerCommand(ChatHandler* handler, const char* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        std::string strCommand;

        char* command = strtok((char*)args, " ");

        uint32 uiGUID = 0;
        Player* player = NULL;
        
        if (command)
        {
            strCommand = command;

            normalizePlayerName(strCommand);
            player = sObjectMgr->GetPlayer(strCommand.c_str()); //get player by name

            if (player)
                uiGUID = player->GetGUIDLow();
        }else 
        {
            player = handler->getSelectedPlayer();
            if (player)
                uiGUID = player->GetGUIDLow();  
        }

        if (uiGUID == 0)
        {
            handler->PSendSysMessage("There is no player.");
            return true;
        }
        

        uint32 average = player->anticheatData.average;
        uint32 total_reports = player->anticheatData.total_reports;
        uint32 speed_reports = player->anticheatData.type_reports[0];
        uint32 fly_reports = player->anticheatData.type_reports[1];
        uint32 jump_reports = player->anticheatData.type_reports[3];
        uint32 waterwalk_reports = player->anticheatData.type_reports[2];
        uint32 teleportplane_reports = player->anticheatData.type_reports[4];

        handler->PSendSysMessage("Information about player %s",player->GetName());
        handler->PSendSysMessage("Average: %u || Total Reports: %u ",average,total_reports);
        handler->PSendSysMessage("Speed Reports: %u || Fly Reports: %u || Jump Reports: %u ",speed_reports,fly_reports,jump_reports);
        handler->PSendSysMessage("Walk On Water Reports: %u  || Teleport To Plane Reports: %u",waterwalk_reports,teleportplane_reports);

        return true;
    }

    static bool HandleAntiCheatHandleCommand(ChatHandler* handler, const char* args)
    {
        std::string strCommand;

        char* command = strtok((char*)args, " ");
        
        if (!command)
            return true;

        if (!handler->GetSession()->GetPlayer())
            return true;

        strCommand = command;

        if (strCommand.compare("on") == 0)
        {
            sWorld->setBoolConfig(CONFIG_ANTICHEAT_ENABLE,true);
            handler->SendSysMessage("The Anticheat System is now: Enabled!");
        }
        else if (strCommand.compare("off") == 0)
        {
            sWorld->setBoolConfig(CONFIG_ANTICHEAT_ENABLE,false);
            handler->SendSysMessage("The Anticheat System is now: Disabled!");
        }
        
        return true;
    }

    static bool HandleAntiCheatGlobalCommand(ChatHandler* handler, const char* args)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        {
            handler->PSendSysMessage("The Anticheat System is disabled.");
            return true;
        }

        QueryResult resultDB = CharacterDatabase.Query("SELECT guid,average,total_reports FROM players_reports_status WHERE total_reports != 0 ORDER BY average ASC LIMIT 3;");
        if (!resultDB)
        {
            handler->PSendSysMessage("No players found.");
            return true;
        } else
        {
                handler->SendSysMessage("=============================");
                handler->PSendSysMessage("Players with the lowest averages:");
                do
                {
                    Field *fieldsDB = resultDB->Fetch();
     
                    uint64 guid = fieldsDB[0].GetUInt64();
                    uint32 average = fieldsDB[1].GetUInt32();
                    uint32 total_reports = fieldsDB[2].GetUInt32();

                     if (Player* player = sObjectMgr->GetPlayerByLowGUID(guid))
                         handler->PSendSysMessage("Player: %s Average: %u Total Reports: %u",player->GetName(),average,total_reports);

                } while (resultDB->NextRow());
        }

        resultDB = CharacterDatabase.Query("SELECT guid,average,total_reports FROM players_reports_status WHERE total_reports != 0 ORDER BY total_reports DESC LIMIT 3;");
        
        // this should never happen
        if (!resultDB)
        {
            handler->PSendSysMessage("No players found.");
            return true;
        } else
        {
            handler->SendSysMessage("=============================");
            handler->PSendSysMessage("Players with the more reports:");
            do
            {
                Field *fieldsDB = resultDB->Fetch();
     
                uint64 guid = fieldsDB[0].GetUInt64();
                uint32 average = fieldsDB[1].GetUInt32();
                uint32 total_reports = fieldsDB[2].GetUInt32();

                    if (Player* player = sObjectMgr->GetPlayerByLowGUID(guid))
                        handler->PSendSysMessage("Player: %s Total Reports: %u Average: %u",player->GetName(),total_reports,average);

            } while (resultDB->NextRow());
        }

        return true;
    }
};

void AddSC_anticheat_commandscript()
{
    new anticheat_commandscript();
}
