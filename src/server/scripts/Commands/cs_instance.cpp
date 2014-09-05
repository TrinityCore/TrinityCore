/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
Name: instance_commandscript
%Complete: 100
Comment: All instance related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "MapManager.h"
#include "Player.h"

class instance_commandscript : public CommandScript
{
public:
    instance_commandscript() : CommandScript("instance_commandscript") { }

    ChatCommand* GetCommands() const override
    {
        static ChatCommand instanceCommandTable[] =
        {
            { "listbinds", rbac::RBAC_PERM_COMMAND_INSTANCE_LISTBINDS, false, &HandleInstanceListBindsCommand,    "", NULL },
            { "unbind",    rbac::RBAC_PERM_COMMAND_INSTANCE_UNBIND,    false, &HandleInstanceUnbindCommand,       "", NULL },
            { "stats",     rbac::RBAC_PERM_COMMAND_INSTANCE_STATS,     true,  &HandleInstanceStatsCommand,        "", NULL },
            { "savedata",  rbac::RBAC_PERM_COMMAND_INSTANCE_SAVEDATA,  false, &HandleInstanceSaveDataCommand,     "", NULL },
            { "setdata",   rbac::RBAC_PERM_COMMAND_INSTANCE_SETDATA,   true, &HandleInstanceSetDataCommand,      "", NULL },
            { "getdata",   rbac::RBAC_PERM_COMMAND_INSTANCE_GETDATA,   true, &HandleInstanceGetDataCommand,      "", NULL },
            { NULL,        0,                                          false, NULL,                               "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "instance", rbac::RBAC_PERM_COMMAND_INSTANCE,  true, NULL, "", instanceCommandTable },
            { NULL,       0,                          false, NULL, "", NULL }
        };

        return commandTable;
    }

    static std::string GetTimeString(uint64 time)
    {
        uint64 days = time / DAY, hours = (time % DAY) / HOUR, minute = (time % HOUR) / MINUTE;
        std::ostringstream ss;
        if (days)
            ss << days << "d ";
        if (hours)
            ss << hours << "h ";
        ss << minute << 'm';
        return ss.str();
    }

    static bool HandleInstanceListBindsCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        uint32 counter = 0;
        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        {
            Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
            for (Player::BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end(); ++itr)
            {
                InstanceSave* save = itr->second.save;
                std::string timeleft = GetTimeString(save->GetResetTime() - time(NULL));
                handler->PSendSysMessage("map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no",  save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                counter++;
            }
        }
        handler->PSendSysMessage("player binds: %d", counter);

        counter = 0;
        if (Group* group = player->GetGroup())
        {
            for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
            {
                Group::BoundInstancesMap &binds = group->GetBoundInstances(Difficulty(i));
                for (Group::BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end(); ++itr)
                {
                    InstanceSave* save = itr->second.save;
                    std::string timeleft = GetTimeString(save->GetResetTime() - time(NULL));
                    handler->PSendSysMessage("map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no",  save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                    counter++;
                }
            }
        }
        handler->PSendSysMessage("group binds: %d", counter);

        return true;
    }

    static bool HandleInstanceUnbindCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        char* map = strtok((char*)args, " ");
        char* pDiff = strtok(NULL, " ");
        int8 diff = -1;
        if (pDiff)
            diff = atoi(pDiff);
        uint16 counter = 0;
        uint16 MapId = 0;

        if (strcmp(map, "all"))
        {
            MapId = uint16(atoi(map));
            if (!MapId)
                return false;
        }

        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        {
            Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
            for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
            {
                InstanceSave* save = itr->second.save;
                if (itr->first != player->GetMapId() && (!MapId || MapId == itr->first) && (diff == -1 || diff == save->GetDifficulty()))
                {
                    std::string timeleft = GetTimeString(save->GetResetTime() - time(NULL));
                    handler->PSendSysMessage("unbinding map: %d inst: %d perm: %s diff: %d canReset: %s TTR: %s", itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                    player->UnbindInstance(itr, Difficulty(i));
                    counter++;
                }
                else
                    ++itr;
            }
        }
        handler->PSendSysMessage("instances unbound: %d", counter);

        return true;
    }

    static bool HandleInstanceStatsCommand(ChatHandler* handler, char const* /*args*/)
    {
        handler->PSendSysMessage("instances loaded: %d", sMapMgr->GetNumInstances());
        handler->PSendSysMessage("players in instances: %d", sMapMgr->GetNumPlayersInInstances());
        handler->PSendSysMessage("instance saves: %d", sInstanceSaveMgr->GetNumInstanceSaves());
        handler->PSendSysMessage("players bound: %d", sInstanceSaveMgr->GetNumBoundPlayersTotal());
        handler->PSendSysMessage("groups bound: %d", sInstanceSaveMgr->GetNumBoundGroupsTotal());

        return true;
    }

    static bool HandleInstanceSaveDataCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        Map* map = player->GetMap();
        if (!map->IsDungeon())
        {
            handler->PSendSysMessage("Map is not a dungeon.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!((InstanceMap*)map)->GetInstanceScript())
        {
            handler->PSendSysMessage("Map has no instance data.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        ((InstanceMap*)map)->GetInstanceScript()->SaveToDB();

        return true;
    }

    static bool HandleInstanceSetDataCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* param1 = strtok((char*)args, " ");
        char* param2 = strtok(NULL, " ");
        char* param3 = strtok(NULL, " ");

        int32 field = 0;
        int32 value = 0;

        Player* target;

        std::string playerName;

        if (!param2 || !param1)
        {
            handler->PSendSysMessage("Missing parameters.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!param3)
        {
            value = atoi(param2);
            field = atoi(param1);
            
            if (handler->GetSession())
                target = handler->GetSession()->GetPlayer();
        }
        else
        {
            value = atoi(param2);
            field = atoi(param1);
            playerName = param3;
            if (normalizePlayerName(playerName))
                target = sObjectAccessor->FindPlayerByName(playerName);
        }

        if (!target)
        {
            handler->PSendSysMessage("Player not found.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Map* map = target->GetMap();
        if (!map->IsDungeon())
        {
            handler->PSendSysMessage("Map is not a dungeon.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!((InstanceMap*)map)->GetInstanceScript())
        {
            handler->PSendSysMessage("Map has no instance data.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (value > 5)
        {
            handler->PSendSysMessage("State index out of range.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        ((InstanceMap*)map)->GetInstanceScript()->SetBossState(field, (EncounterState)value);
        handler->PSendSysMessage("Instance data field %i is now set to %i.", field, value);
        return true;
    }

    static bool HandleInstanceGetDataCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* param1 = strtok((char*)args, " ");
        char* param2 = strtok(NULL, " ");

        int32 field = 0;

        Player* target;

        std::string playerName;
        std::string output;

        if (!param1)
        {
            handler->PSendSysMessage("Missing parameters.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!param2)
        {
            field = atoi(param1);
            target = handler->GetSession()->GetPlayer();
        }
        else
        {
            field = atoi(param1);
            playerName = param2;
            if (normalizePlayerName(playerName))
                target = sObjectAccessor->FindPlayerByName(playerName);
        }

        if (!target)
        {
            handler->PSendSysMessage("Player not found.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        Map* map = target->GetMap();
        if (!map->IsDungeon())
        {
            handler->PSendSysMessage("Map is not a dungeon.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!((InstanceMap*)map)->GetInstanceScript())
        {
            handler->PSendSysMessage("Map has no instance data.");
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 value = ((InstanceMap*)map)->GetInstanceScript()->GetBossState(field);

        // Funky way to do this - improve if you can!
        switch (value)
        {
            case NOT_STARTED:
                output = "0 - (NOT_STARTED)";
                break;
            case IN_PROGRESS:
                output = "1 - (IN_PROGRESS)";
                break;
            case FAIL:
                output = "2 - (FAIL)";
                break;
            case DONE:
                output = "3 - (DONE)";
                break;
            case SPECIAL:
                output = "4 - (SPECIAL)";
                break;
            case TO_BE_DECIDED:
                output = "5 - (TO_BE_DECIDED)";
                break;
            default: 
                break;
        }

        handler->PSendSysMessage("Instance data for field %i is %s.", field, output.c_str());
        return true;
    }
};

void AddSC_instance_commandscript()
{
    new instance_commandscript();
}
