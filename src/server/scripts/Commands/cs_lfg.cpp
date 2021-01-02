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
#include "CharacterCache.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Language.h"
#include "LFGMgr.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "RBAC.h"

using namespace Trinity::ChatCommands;

void PrintPlayerInfo(ChatHandler* handler, Player const* player)
{
    if (!player)
        return;

    ObjectGuid guid = player->GetGUID();
    lfg::LfgDungeonSet dungeons = sLFGMgr->GetSelectedDungeons(guid);

    std::string const& state = lfg::GetStateString(sLFGMgr->GetState(guid));
    handler->PSendSysMessage(LANG_LFG_PLAYER_INFO, player->GetName().c_str(),
        state.c_str(), uint8(dungeons.size()), lfg::ConcatenateDungeons(dungeons).c_str(),
        lfg::GetRolesString(sLFGMgr->GetRoles(guid)).c_str(), sLFGMgr->GetComment(guid).c_str());
}

class lfg_commandscript : public CommandScript
{
public:
    lfg_commandscript() : CommandScript("lfg_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable lfgCommandTable =
        {
            { "player",     HandleLfgPlayerInfoCommand,     rbac::RBAC_PERM_COMMAND_LFG_PLAYER,     Console::No },
            { "group",      HandleLfgGroupInfoCommand,      rbac::RBAC_PERM_COMMAND_LFG_GROUP,      Console::No },
            { "queue",      HandleLfgQueueInfoCommand,      rbac::RBAC_PERM_COMMAND_LFG_QUEUE,      Console::Yes },
            { "clean",      HandleLfgCleanCommand,          rbac::RBAC_PERM_COMMAND_LFG_CLEAN,      Console::Yes },
            { "options",    HandleLfgOptionsCommand,        rbac::RBAC_PERM_COMMAND_LFG_OPTIONS,    Console::Yes },
        };

        static ChatCommandTable commandTable =
        {
            { "lfg", lfgCommandTable },
        };
        return commandTable;
    }

    static bool HandleLfgPlayerInfoCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        if (Player* target = player->GetConnectedPlayer())
        {
            PrintPlayerInfo(handler, target);
            return true;
        }

        return false;
    }

    static bool HandleLfgGroupInfoCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!player)
            player = PlayerIdentifier::FromTargetOrSelf(handler);
        if (!player)
            return false;

        Group* groupTarget = nullptr;

        if (Player* target = player->GetConnectedPlayer())
            groupTarget = target->GetGroup();
        else
        {
            CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GROUP_MEMBER);
            stmt->setUInt32(0, player->GetGUID().GetCounter());
            PreparedQueryResult resultGroup = CharacterDatabase.Query(stmt);
            if (resultGroup)
                groupTarget = sGroupMgr->GetGroupByDbStoreId((*resultGroup)[0].GetUInt32());
        }

        if (!groupTarget)
        {
            handler->PSendSysMessage(LANG_LFG_NOT_IN_GROUP, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        ObjectGuid guid = groupTarget->GetGUID();
        std::string const& state = lfg::GetStateString(sLFGMgr->GetState(guid));
        handler->PSendSysMessage(LANG_LFG_GROUP_INFO, groupTarget->isLFGGroup(),
            state.c_str(), sLFGMgr->GetDungeon(guid));

        for (Group::MemberSlot const& slot : groupTarget->GetMemberSlots())
        {
            Player* p = ObjectAccessor::FindPlayer(slot.guid);
            if (p)
                PrintPlayerInfo(handler, p);
            else
                handler->PSendSysMessage("%s is offline.", slot.name.c_str());
        }

        return true;
    }

    static bool HandleLfgOptionsCommand(ChatHandler* handler, Optional<uint32> optionsArg)
    {
        if (optionsArg)
        {
            sLFGMgr->SetOptions(*optionsArg);
            handler->PSendSysMessage(LANG_LFG_OPTIONS_CHANGED);
        }
        handler->PSendSysMessage(LANG_LFG_OPTIONS, sLFGMgr->GetOptions());
        return true;
    }

    static bool HandleLfgQueueInfoCommand(ChatHandler* handler, Tail full)
    {
        handler->SendSysMessage(sLFGMgr->DumpQueueInfo(!full.empty()).c_str(), true);
        return true;
    }

    static bool HandleLfgCleanCommand(ChatHandler* handler)
    {
        handler->PSendSysMessage(LANG_LFG_CLEAN);
        sLFGMgr->Clean();
        return true;
    }
};

void AddSC_lfg_commandscript()
{
    new lfg_commandscript();
}
