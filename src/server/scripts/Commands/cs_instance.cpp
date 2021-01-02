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
Name: instance_commandscript
%Complete: 100
Comment: All instance related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "GameTime.h"
#include "Group.h"
#include "InstanceSaveMgr.h"
#include "InstanceScript.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

#if TRINITY_COMPILER == TRINITY_COMPILER_GNU
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

class instance_commandscript : public CommandScript
{
public:
    instance_commandscript() : CommandScript("instance_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> instanceCommandTable =
        {
            { "listbinds",    rbac::RBAC_PERM_COMMAND_INSTANCE_LISTBINDS,     false, &HandleInstanceListBindsCommand,    "" },
            { "unbind",       rbac::RBAC_PERM_COMMAND_INSTANCE_UNBIND,        false, &HandleInstanceUnbindCommand,       "" },
            { "stats",        rbac::RBAC_PERM_COMMAND_INSTANCE_STATS,          true, &HandleInstanceStatsCommand,        "" },
            { "savedata",     rbac::RBAC_PERM_COMMAND_INSTANCE_SAVEDATA,      false, &HandleInstanceSaveDataCommand,     "" },
            { "setbossstate", rbac::RBAC_PERM_COMMAND_INSTANCE_SET_BOSS_STATE, true, &HandleInstanceSetBossStateCommand, "" },
            { "getbossstate", rbac::RBAC_PERM_COMMAND_INSTANCE_GET_BOSS_STATE, true, &HandleInstanceGetBossStateCommand, "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "instance", rbac::RBAC_PERM_COMMAND_INSTANCE,  true, nullptr, "", instanceCommandTable },
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
                std::string timeleft = GetTimeString(save->GetResetTime() - GameTime::GetGameTime());
                handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_INFO, itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no", itr->second.extendState == EXTEND_STATE_EXPIRED ? "expired" : itr->second.extendState == EXTEND_STATE_EXTENDED ? "yes" : "no", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                counter++;
            }
        }
        handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_PLAYER_BINDS, counter);

        counter = 0;
        if (Group* group = player->GetGroup())
        {
            for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
            {
                Group::BoundInstancesMap &binds = group->GetBoundInstances(Difficulty(i));
                for (Group::BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end(); ++itr)
                {
                    InstanceSave* save = itr->second.save;
                    std::string timeleft = GetTimeString(save->GetResetTime() - GameTime::GetGameTime());
                    handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_INFO, itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no", "-", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                    counter++;
                }
            }
        }
        handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_GROUP_BINDS, counter);

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
        char* pDiff = strtok(nullptr, " ");
        int8 diff = -1;
        if (pDiff)
            diff = atoi(pDiff);
        uint16 counter = 0;
        uint16 MapId = 0;

        if (strcmp(map, "all") != 0)
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
                    std::string timeleft = GetTimeString(save->GetResetTime() - GameTime::GetGameTime());
                    handler->PSendSysMessage(LANG_COMMAND_INST_UNBIND_UNBINDING, itr->first, save->GetInstanceId(), itr->second.perm ? "yes" : "no", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                    player->UnbindInstance(itr, Difficulty(i));
                    counter++;
                }
                else
                    ++itr;
            }
        }
        handler->PSendSysMessage(LANG_COMMAND_INST_UNBIND_UNBOUND, counter);

        return true;
    }

    static bool HandleInstanceStatsCommand(ChatHandler* handler, char const* /*args*/)
    {
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_LOADED_INST, sMapMgr->GetNumInstances());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_PLAYERS_IN, sMapMgr->GetNumPlayersInInstances());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_SAVES, sInstanceSaveMgr->GetNumInstanceSaves());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_PLAYERSBOUND, sInstanceSaveMgr->GetNumBoundPlayersTotal());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_GROUPSBOUND, sInstanceSaveMgr->GetNumBoundGroupsTotal());

        return true;
    }

    static bool HandleInstanceSaveDataCommand(ChatHandler* handler, char const* /*args*/)
    {
        Player* player = handler->GetSession()->GetPlayer();
        InstanceMap* map = player->GetMap()->ToInstanceMap();
        if (!map)
        {
            handler->PSendSysMessage(LANG_NOT_DUNGEON);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!map->GetInstanceScript())
        {
            handler->PSendSysMessage(LANG_NO_INSTANCE_DATA);
            handler->SetSentErrorMessage(true);
            return false;
        }

        map->GetInstanceScript()->SaveToDB();

        return true;
    }

    static bool HandleInstanceSetBossStateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* param1 = strtok((char*)args, " ");
        char* param2 = strtok(nullptr, " ");
        char* param3 = strtok(nullptr, " ");
        uint32 encounterId = 0;
        int32 state = 0;
        Player* player = nullptr;
        std::string playerName;

        // Character name must be provided when using this from console.
        if (!param2 || (!param3 && !handler->GetSession()))
        {
            handler->PSendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!param3)
            player = handler->GetSession()->GetPlayer();
        else
        {
            playerName = param3;
            if (normalizePlayerName(playerName))
                player = ObjectAccessor::FindPlayerByName(playerName);
        }

        if (!player)
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        InstanceMap* map = player->GetMap()->ToInstanceMap();
        if (!map)
        {
            handler->PSendSysMessage(LANG_NOT_DUNGEON);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!map->GetInstanceScript())
        {
            handler->PSendSysMessage(LANG_NO_INSTANCE_DATA);
            handler->SetSentErrorMessage(true);
            return false;
        }

        encounterId = atoi(param1);
        state = atoi(param2);

        // Reject improper values.
        if (state > TO_BE_DECIDED || encounterId > map->GetInstanceScript()->GetEncounterCount())
        {
            handler->PSendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        map->GetInstanceScript()->SetBossState(encounterId, EncounterState(state));
        handler->PSendSysMessage(LANG_COMMAND_INST_SET_BOSS_STATE, encounterId, state, InstanceScript::GetBossStateName(state));
        return true;
    }

    static bool HandleInstanceGetBossStateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* param1 = strtok((char*)args, " ");
        char* param2 = strtok(nullptr, " ");
        uint32 encounterId = 0;
        Player* player = nullptr;
        std::string playerName;

        // Character name must be provided when using this from console.
        if (!param1 || (!param2 && !handler->GetSession()))
        {
            handler->PSendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!param2)
            player = handler->GetSession()->GetPlayer();
        else
        {
            playerName = param2;
            if (normalizePlayerName(playerName))
                player = ObjectAccessor::FindPlayerByName(playerName);
        }

        if (!player)
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        InstanceMap* map = player->GetMap()->ToInstanceMap();
        if (!map)
        {
            handler->PSendSysMessage(LANG_NOT_DUNGEON);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!map->GetInstanceScript())
        {
            handler->PSendSysMessage(LANG_NO_INSTANCE_DATA);
            handler->SetSentErrorMessage(true);
            return false;
        }

        encounterId = atoi(param1);

        if (encounterId > map->GetInstanceScript()->GetEncounterCount())
        {
            handler->PSendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 state = map->GetInstanceScript()->GetBossState(encounterId);
        handler->PSendSysMessage(LANG_COMMAND_INST_GET_BOSS_STATE, encounterId, state, InstanceScript::GetBossStateName(state));
        return true;
    }
};

void AddSC_instance_commandscript()
{
    new instance_commandscript();
}
