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
#include "ChatCommand.h"
#include "DB2Stores.h"
#include "GameTime.h"
#include "Group.h"
#include "InstanceLockMgr.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Map.h"
#include "MapManager.h"
#include "Player.h"
#include "RBAC.h"
#include "Util.h"
#include "World.h"
#include "WorldSession.h"
#include <sstream>

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

        InstanceResetTimePoint now = GameTime::GetTime<InstanceResetTimePoint::clock>();
        std::vector<InstanceLock const*> instanceLocks = sInstanceLockMgr.GetInstanceLocksForPlayer(player->GetGUID());
        for (InstanceLock const* instanceLock : instanceLocks)
        {
            MapDb2Entries entries{ instanceLock->GetMapId(), instanceLock->GetDifficultyId() };
            std::string timeleft = !instanceLock->IsExpired() ? secsToTimeString(std::chrono::duration_cast<Seconds>(instanceLock->GetEffectiveExpiryTime() - now).count()) : "-";
            handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_INFO,
                entries.Map->ID, entries.Map->MapName[sWorld->GetDefaultDbcLocale()],
                uint32(entries.MapDifficulty->DifficultyID), sDifficultyStore.AssertEntry(entries.MapDifficulty->DifficultyID)->Name[sWorld->GetDefaultDbcLocale()],
                instanceLock->GetInstanceId(),
                handler->GetTrinityString(instanceLock->IsExpired() ? LANG_YES : LANG_NO),
                handler->GetTrinityString(instanceLock->IsExtended() ? LANG_YES : LANG_NO),
                timeleft.c_str());
        }

        handler->PSendSysMessage(LANG_COMMAND_LIST_BIND_PLAYER_BINDS, uint32(instanceLocks.size()));
        return true;
    }

    static bool HandleInstanceUnbindCommand(ChatHandler* handler, Variant<uint32, EXACT_SEQUENCE("all")> mapArg, Optional<uint32> difficultyArg)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
            player = handler->GetSession()->GetPlayer();

        Optional<uint32> mapId;
        Optional<Difficulty> difficulty;

        if (mapArg.holds_alternative<uint32>())
            mapId = mapArg.get<uint32>();

        if (difficultyArg && sDifficultyStore.LookupEntry(*difficultyArg))
            difficulty = Difficulty(*difficultyArg);

        std::vector<InstanceLock const*> locksReset;
        std::vector<InstanceLock const*> locksNotReset;

        sInstanceLockMgr.ResetInstanceLocksForPlayer(player->GetGUID(), mapId, difficulty, &locksReset, &locksNotReset);

        InstanceResetTimePoint now = GameTime::GetTime<InstanceResetTimePoint::clock>();
        for (InstanceLock const* instanceLock : locksReset)
        {
            MapDb2Entries entries{ instanceLock->GetMapId(), instanceLock->GetDifficultyId() };
            std::string timeleft = !instanceLock->IsExpired() ? secsToTimeString(std::chrono::duration_cast<Seconds>(instanceLock->GetEffectiveExpiryTime() - now).count()) : "-";
            handler->PSendSysMessage(LANG_COMMAND_INST_UNBIND_UNBINDING,
                entries.Map->ID, entries.Map->MapName[sWorld->GetDefaultDbcLocale()],
                uint32(entries.MapDifficulty->DifficultyID), sDifficultyStore.AssertEntry(entries.MapDifficulty->DifficultyID)->Name[sWorld->GetDefaultDbcLocale()],
                instanceLock->GetInstanceId(),
                handler->GetTrinityString(instanceLock->IsExpired() ? LANG_YES : LANG_NO),
                handler->GetTrinityString(instanceLock->IsExtended() ? LANG_YES : LANG_NO),
                timeleft.c_str());
        }

        handler->PSendSysMessage(LANG_COMMAND_INST_UNBIND_UNBOUND, uint32(locksReset.size()));

        for (InstanceLock const* instanceLock : locksNotReset)
        {
            MapDb2Entries entries{ instanceLock->GetMapId(), instanceLock->GetDifficultyId() };
            std::string timeleft = !instanceLock->IsExpired() ? secsToTimeString(std::chrono::duration_cast<Seconds>(instanceLock->GetEffectiveExpiryTime() - now).count()) : "-";
            handler->PSendSysMessage(LANG_COMMAND_INST_UNBIND_FAILED,
                entries.Map->ID, entries.Map->MapName[sWorld->GetDefaultDbcLocale()],
                uint32(entries.MapDifficulty->DifficultyID), sDifficultyStore.AssertEntry(entries.MapDifficulty->DifficultyID)->Name[sWorld->GetDefaultDbcLocale()],
                instanceLock->GetInstanceId(),
                handler->GetTrinityString(instanceLock->IsExpired() ? LANG_YES : LANG_NO),
                handler->GetTrinityString(instanceLock->IsExtended() ? LANG_YES : LANG_NO),
                timeleft.c_str());
        }

        player->SendRaidInfo();

        return true;
    }

    static bool HandleInstanceStatsCommand(ChatHandler* handler)
    {
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_LOADED_INST, sMapMgr->GetNumInstances());
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_PLAYERS_IN, sMapMgr->GetNumPlayersInInstances());

        InstanceLocksStatistics statistics = sInstanceLockMgr.GetStatistics();

        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_SAVES, statistics.InstanceCount);
        handler->PSendSysMessage(LANG_COMMAND_INST_STAT_PLAYERSBOUND, statistics.PlayerCount);

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
