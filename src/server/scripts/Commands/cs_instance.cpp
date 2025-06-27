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

using namespace Trinity::ChatCommands;

class instance_commandscript : public CommandScript
{
public:
    instance_commandscript() : CommandScript("instance_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable instanceCommandTable =
        {
            { "listbinds",    HandleInstanceListBindsCommand,    rbac::RBAC_PERM_COMMAND_INSTANCE_LISTBINDS,      Console::No },
            { "unbind",       HandleInstanceUnbindCommand,       rbac::RBAC_PERM_COMMAND_INSTANCE_UNBIND,         Console::No },
            { "stats",        HandleInstanceStatsCommand,        rbac::RBAC_PERM_COMMAND_INSTANCE_STATS,          Console::Yes },
            { "savedata",     HandleInstanceSaveDataCommand,     rbac::RBAC_PERM_COMMAND_INSTANCE_SAVEDATA,       Console::No },
            { "setbossstate", HandleInstanceSetBossStateCommand, rbac::RBAC_PERM_COMMAND_INSTANCE_SET_BOSS_STATE, Console::Yes },
            { "getbossstate", HandleInstanceGetBossStateCommand, rbac::RBAC_PERM_COMMAND_INSTANCE_GET_BOSS_STATE, Console::Yes },
        };

        static ChatCommandTable commandTable =
        {
            { "instance", instanceCommandTable },
        };

        return commandTable;
    }

    static bool HandleInstanceListBindsCommand(ChatHandler* handler)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        uint32 counter = 0;
        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        {
            for (auto const& [mapId, bind] : player->GetBoundInstances(Difficulty(i)))
            {
                InstanceSave const* save = bind.save;
                std::string timeleft = secsToTimeString(save->GetResetTime() - GameTime::GetGameTime(), TimeFormat::ShortText);
                handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_INFO, mapId, save->GetInstanceId(), bind.perm ? "yes" : "no", bind.extendState == EXTEND_STATE_EXPIRED ? "expired" : bind.extendState == EXTEND_STATE_EXTENDED ? "yes" : "no", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                counter++;
            }
        }
        handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_PLAYER_BINDS, counter);

        counter = 0;
        if (Group* group = player->GetGroup())
        {
            for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
            {
                for (auto const& [mapId, bind] : group->GetBoundInstances(Difficulty(i)))
                {
                    InstanceSave* save = bind.save;
                    std::string timeleft = secsToTimeString(save->GetResetTime() - GameTime::GetGameTime(), TimeFormat::ShortText);
                    handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_INFO, mapId, save->GetInstanceId(), bind.perm ? "yes" : "no", "-", save->GetDifficulty(), save->CanReset() ? "yes" : "no", timeleft.c_str());
                    counter++;
                }
            }
        }
        handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_GROUP_BINDS, counter);

        return true;
    }

    static bool HandleInstanceUnbindCommand(ChatHandler* handler, Variant<uint16, EXACT_SEQUENCE("all")> mapArg, Optional<uint8> difficultyArg)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        uint16 counter = 0;
        uint16 mapId = 0;

        if (mapArg.holds_alternative<uint16>())
        {
            mapId = mapArg.get<uint16>();
            if (!mapId)
                return false;
        }

        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        {
            Player::BoundInstancesMap& binds = player->GetBoundInstances(Difficulty(i));
            for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
            {
                InstanceSave const* save = itr->second.save;
                if (itr->first != player->GetMapId() && (!mapId || mapId == itr->first) && (!difficultyArg || difficultyArg == save->GetDifficulty()))
                {
                    std::string timeleft = secsToTimeString(save->GetResetTime() - GameTime::GetGameTime(), TimeFormat::ShortText);
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

    static bool HandleInstanceStatsCommand(ChatHandler* handler)
    {
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_LOADED_INST, sMapMgr->GetNumInstances());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_PLAYERS_IN, sMapMgr->GetNumPlayersInInstances());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_SAVES, sInstanceSaveMgr->GetNumInstanceSaves());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_PLAYERSBOUND, sInstanceSaveMgr->GetNumBoundPlayersTotal());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_GROUPSBOUND, sInstanceSaveMgr->GetNumBoundGroupsTotal());

        return true;
    }

    static bool HandleInstanceSaveDataCommand(ChatHandler* handler)
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

    static bool HandleInstanceSetBossStateCommand(ChatHandler* handler, uint32 encounterId, EncounterState state, Optional<PlayerIdentifier> player)
    {
        // Character name must be provided when using this from console.
        if (!player && !handler->GetSession())
        {
            handler->PSendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!player)
            player = PlayerIdentifier::FromSelf(handler);

        if (!player->IsConnected())
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        InstanceMap* map = player->GetConnectedPlayer()->GetMap()->ToInstanceMap();
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

        // Reject improper values.
        if (encounterId > map->GetInstanceScript()->GetEncounterCount())
        {
            handler->PSendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        map->GetInstanceScript()->SetBossState(encounterId, state);
        handler->PSendSysMessage(LANG_COMMAND_INST_SET_BOSS_STATE, encounterId, state, EnumUtils::ToConstant(state));
        return true;
    }

    static bool HandleInstanceGetBossStateCommand(ChatHandler* handler, uint32 encounterId, Optional<PlayerIdentifier> player)
    {
        // Character name must be provided when using this from console.
        if (!player && !handler->GetSession())
        {
            handler->PSendSysMessage(LANG_CMD_SYNTAX);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!player)
            player = PlayerIdentifier::FromSelf(handler);

        if (!player->IsConnected())
        {
            handler->PSendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        InstanceMap* map = player->GetConnectedPlayer()->GetMap()->ToInstanceMap();
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

        if (encounterId > map->GetInstanceScript()->GetEncounterCount())
        {
            handler->PSendSysMessage(LANG_BAD_VALUE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        EncounterState state = map->GetInstanceScript()->GetBossState(encounterId);
        handler->PSendSysMessage(LANG_COMMAND_INST_GET_BOSS_STATE, encounterId, state, EnumUtils::ToConstant(state));
        return true;
    }
};

void AddSC_instance_commandscript()
{
    new instance_commandscript();
}
