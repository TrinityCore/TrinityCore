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
#include "CharacterCache.h"
#include "Chat.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GroupMgr.h"
#include "Language.h"
#include "LFG.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

class group_commandscript : public CommandScript
{
public:
    group_commandscript() : CommandScript("group_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> groupSetCommandTable =
        {
            { "leader",     rbac::RBAC_PERM_COMMAND_GROUP_LEADER,     false, &HandleGroupLeaderCommand,     "" },
            { "assistant",  rbac::RBAC_PERM_COMMAND_GROUP_ASSISTANT,  false, &HandleGroupAssistantCommand,  "" },
            { "maintank",   rbac::RBAC_PERM_COMMAND_GROUP_MAINTANK,   false, &HandleGroupMainTankCommand,   "" },
            { "mainassist", rbac::RBAC_PERM_COMMAND_GROUP_MAINASSIST, false, &HandleGroupMainAssistCommand, "" },
        };

        static std::vector<ChatCommand> groupCommandTable =
        {
            { "set",     rbac::RBAC_PERM_COMMAND_GROUP_SET,     false, nullptr,                    "", groupSetCommandTable },
            { "leader",  rbac::RBAC_PERM_COMMAND_GROUP_LEADER,  false, &HandleGroupLeaderCommand,  "" },
            { "disband", rbac::RBAC_PERM_COMMAND_GROUP_DISBAND, false, &HandleGroupDisbandCommand, "" },
            { "remove",  rbac::RBAC_PERM_COMMAND_GROUP_REMOVE,  false, &HandleGroupRemoveCommand,  "" },
            { "join",    rbac::RBAC_PERM_COMMAND_GROUP_JOIN,    false, &HandleGroupJoinCommand,    "" },
            { "list",    rbac::RBAC_PERM_COMMAND_GROUP_LIST,    false, &HandleGroupListCommand,    "" },
            { "summon",  rbac::RBAC_PERM_COMMAND_GROUP_SUMMON,  false, &HandleGroupSummonCommand,  "" },
        };

        static std::vector<ChatCommand> commandTable =
        {
            { "group", rbac::RBAC_PERM_COMMAND_GROUP, false, nullptr, "", groupCommandTable },
        };
        return commandTable;
    }

    // Summon group of player
    static bool HandleGroupSummonCommand(ChatHandler* handler, char const* args)
    {
        Player* target;
        if (!handler->extractPlayerTarget((char*)args, &target))
            return false;

        // check online security
        if (handler->HasLowerSecurity(target, ObjectGuid::Empty))
            return false;

        Group* group = target->GetGroup();

        std::string nameLink = handler->GetNameLink(target);

        if (!group)
        {
            handler->PSendSysMessage(LANG_NOT_IN_GROUP, nameLink.c_str());
            return false;
        }

        Player* gmPlayer = handler->GetSession()->GetPlayer();
        Map* gmMap = gmPlayer->GetMap();
        bool toInstance = gmMap->Instanceable();
        bool onlyLocalSummon = false;

        // make sure people end up on our instance of the map, disallow far summon if intended destination is different from actual destination
        // note: we could probably relax this further by checking permanent saves and the like, but eh
        // :close enough:
        if (toInstance)
        {
            Player* groupLeader = ObjectAccessor::GetPlayer(gmMap, group->GetLeaderGUID());
            if (!groupLeader || (groupLeader->GetMapId() != gmMap->GetId()) || (groupLeader->GetInstanceId() != gmMap->GetInstanceId()))
            {
                handler->SendSysMessage(LANG_PARTIAL_GROUP_SUMMON);
                onlyLocalSummon = true;
            }
        }

        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* player = itr->GetSource();

            if (!player || player == gmPlayer || !player->GetSession())
                continue;

            // check online security
            if (handler->HasLowerSecurity(player, ObjectGuid::Empty))
                continue;

            std::string plNameLink = handler->GetNameLink(player);

            if (player->IsBeingTeleported())
            {
                handler->PSendSysMessage(LANG_IS_TELEPORTED, plNameLink.c_str());
                continue;
            }

            if (toInstance)
            {
                Map* playerMap = player->GetMap();

                if (
                    (onlyLocalSummon || (playerMap->Instanceable() && playerMap->GetId() == gmMap->GetId())) && // either no far summon allowed or we're in the same map as player (no map switch)
                    ((playerMap->GetId() != gmMap->GetId()) || (playerMap->GetInstanceId() != gmMap->GetInstanceId())) // so we need to be in the same map and instance of the map, otherwise skip
                    )
                {
                    // cannot summon from instance to instance
                    handler->PSendSysMessage(LANG_CANNOT_SUMMON_INST_INST, plNameLink.c_str());
                    continue;
                }
            }

            handler->PSendSysMessage(LANG_SUMMONING, plNameLink.c_str(), "");
            if (handler->needReportToTarget(player))
                ChatHandler(player->GetSession()).PSendSysMessage(LANG_SUMMONED_BY, handler->GetNameLink().c_str());

            // stop flight if need
            if (player->IsInFlight())
            {
                player->GetMotionMaster()->MovementExpired();
                player->CleanupAfterTaxiFlight();
            }
            // save only in non-flight case
            else
                player->SaveRecallPosition();

            // before GM
            float x, y, z;
            gmPlayer->GetClosePoint(x, y, z, player->GetCombatReach());
            player->TeleportTo(gmPlayer->GetMapId(), x, y, z, player->GetOrientation());
        }

        return true;
    }

    static bool HandleGroupLeaderCommand(ChatHandler* handler, char const* args)
    {
        Player* player = nullptr;
        Group* group = nullptr;
        ObjectGuid guid;
        char* nameStr = strtok((char*)args, " ");

        if (!handler->GetPlayerGroupAndGUIDByName(nameStr, player, group, guid))
            return false;

        if (!group)
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_GROUP, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (group->GetLeaderGUID() != guid)
        {
            group->ChangeLeader(guid);
            group->SendUpdate();
        }

        return true;
    }

    static bool GroupFlagCommand(ChatHandler* handler, char const* args, GroupMemberFlags flag, char const* what)
    {
        Player* player = nullptr;
        Group* group = nullptr;
        ObjectGuid guid;
        char* nameStr = strtok((char*)args, " ");

        if (!handler->GetPlayerGroupAndGUIDByName(nameStr, player, group, guid))
            return false;

        if (!group)
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_GROUP, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!group->isRaidGroup())
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_RAID_GROUP, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (flag == MEMBER_FLAG_ASSISTANT && group->IsLeader(guid))
        {
            handler->PSendSysMessage(LANG_LEADER_CANNOT_BE_ASSISTANT, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (group->GetMemberFlags(guid) & flag)
        {
            group->SetGroupMemberFlag(guid, false, flag);
            handler->PSendSysMessage(LANG_GROUP_ROLE_CHANGED, player->GetName().c_str(), "no longer", what);
        }
        else
        {
            group->SetGroupMemberFlag(guid, true, flag);
            handler->PSendSysMessage(LANG_GROUP_ROLE_CHANGED, player->GetName().c_str(), "now", what);
        }
        return true;
    }

    static bool HandleGroupAssistantCommand(ChatHandler* handler, char const* args)
    {
        return GroupFlagCommand(handler, args, MEMBER_FLAG_ASSISTANT, "Assistant");
    }

    static bool HandleGroupMainTankCommand(ChatHandler* handler, char const* args)
    {
        return GroupFlagCommand(handler, args, MEMBER_FLAG_MAINTANK, "Main Tank");
    }

    static bool HandleGroupMainAssistCommand(ChatHandler* handler, char const* args)
    {
        return GroupFlagCommand(handler, args, MEMBER_FLAG_MAINASSIST, "Main Assist");
    }

    static bool HandleGroupDisbandCommand(ChatHandler* handler, char const* args)
    {
        Player* player = nullptr;
        Group* group = nullptr;
        ObjectGuid guid;
        char* nameStr = strtok((char*)args, " ");

        if (!handler->GetPlayerGroupAndGUIDByName(nameStr, player, group, guid))
            return false;

        if (!group)
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_GROUP, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        group->Disband();
        return true;
    }

    static bool HandleGroupRemoveCommand(ChatHandler* handler, char const* args)
    {
        Player* player = nullptr;
        Group* group = nullptr;
        ObjectGuid guid;
        char* nameStr = strtok((char*)args, " ");

        if (!handler->GetPlayerGroupAndGUIDByName(nameStr, player, group, guid))
            return false;

        if (!group)
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_GROUP, player->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        group->RemoveMember(guid);
        return true;
    }

    static bool HandleGroupJoinCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Player* playerSource = nullptr;
        Player* playerTarget = nullptr;
        Group* groupSource = nullptr;
        Group* groupTarget = nullptr;
        ObjectGuid guidSource;
        ObjectGuid guidTarget;
        char* nameplgrStr = strtok((char*)args, " ");
        char* nameplStr = strtok(nullptr, " ");

        if (!handler->GetPlayerGroupAndGUIDByName(nameplgrStr, playerSource, groupSource, guidSource, true))
            return false;

        if (!groupSource)
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_GROUP, playerSource->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!handler->GetPlayerGroupAndGUIDByName(nameplStr, playerTarget, groupTarget, guidTarget, true))
            return false;

        if (groupTarget || playerTarget->GetGroup() == groupSource)
        {
            handler->PSendSysMessage(LANG_GROUP_ALREADY_IN_GROUP, playerTarget->GetName().c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (groupSource->IsFull())
        {
            handler->PSendSysMessage(LANG_GROUP_FULL);
            handler->SetSentErrorMessage(true);
            return false;
        }

        groupSource->AddMember(playerTarget);
        groupSource->BroadcastGroupUpdate();
        handler->PSendSysMessage(LANG_GROUP_PLAYER_JOINED, playerTarget->GetName().c_str(), playerSource->GetName().c_str());
        return true;
    }

    static bool HandleGroupListCommand(ChatHandler* handler, char const* args)
    {
        // Get ALL the variables!
        Player* playerTarget;
        uint32 phase = 0;
        ObjectGuid guidTarget;
        std::string nameTarget;
        std::string zoneName;
        char const* onlineState = "";

        // Parse the guid to uint32...
        ObjectGuid parseGUID(HighGuid::Player, uint32(atoul(args)));

        // ... and try to extract a player out of it.
        if (sCharacterCache->GetCharacterNameByGuid(parseGUID, nameTarget))
        {
            playerTarget = ObjectAccessor::FindPlayer(parseGUID);
            guidTarget = parseGUID;
        }
        // If not, we return false and end right away.
        else if (!handler->extractPlayerTarget((char*)args, &playerTarget, &guidTarget, &nameTarget))
            return false;

        // Next, we need a group. So we define a group variable.
        Group* groupTarget = nullptr;

        // We try to extract a group from an online player.
        if (playerTarget)
            groupTarget = playerTarget->GetGroup();

        // If not, we extract it from the SQL.
        if (!groupTarget)
        {
            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_GROUP_MEMBER);
            stmt->setUInt32(0, guidTarget.GetCounter());
            PreparedQueryResult resultGroup = CharacterDatabase.Query(stmt);
            if (resultGroup)
                groupTarget = sGroupMgr->GetGroupByDbStoreId((*resultGroup)[0].GetUInt32());
        }

        // If both fails, players simply has no party. Return false.
        if (!groupTarget)
        {
            handler->PSendSysMessage(LANG_GROUP_NOT_IN_GROUP, nameTarget.c_str());
            handler->SetSentErrorMessage(true);
            return false;
        }

        // We get the group members after successfully detecting a group.
        Group::MemberSlotList const& members = groupTarget->GetMemberSlots();

        // To avoid a cluster fuck, namely trying multiple queries to simply get a group member count...
        handler->PSendSysMessage(LANG_GROUP_TYPE, (groupTarget->isRaidGroup() ? "raid" : "party"), members.size());
        // ... we simply move the group type and member count print after retrieving the slots and simply output it's size.

        // While rather dirty codestyle-wise, it saves space (if only a little). For each member, we look several informations up.
        for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
        {
            // Define temporary variable slot to iterator.
            Group::MemberSlot const& slot = *itr;

            // Check for given flag and assign it to that iterator
            std::string flags;
            if (slot.flags & MEMBER_FLAG_ASSISTANT)
                flags = "Assistant";

            if (slot.flags & MEMBER_FLAG_MAINTANK)
            {
                if (!flags.empty())
                    flags.append(", ");
                flags.append("MainTank");
            }

            if (slot.flags & MEMBER_FLAG_MAINASSIST)
            {
                if (!flags.empty())
                    flags.append(", ");
                flags.append("MainAssist");
            }

            if (flags.empty())
                flags = "None";

            // Check if iterator is online. If is...
            Player* p = ObjectAccessor::FindPlayer((*itr).guid);
            if (p)
            {
                // ... than, it prints information like "is online", where he is, etc...
                onlineState = "online";
                phase = (!p->IsGameMaster() ? p->GetPhaseMask() : -1);
                uint32 locale = handler->GetSessionDbcLocale();

                AreaTableEntry const* area = sAreaTableStore.LookupEntry(p->GetAreaId());
                if (area)
                {
                    AreaTableEntry const* zone = sAreaTableStore.LookupEntry(area->zone);
                    if (zone)
                        zoneName = zone->area_name[locale];
                }
            }
            else
            {
                // ... else, everything is set to offline or neutral values.
                zoneName    = "<ERROR>";
                onlineState = "Offline";
                phase       = 0;
            }

            // Now we can print those informations for every single member of each group!
            handler->PSendSysMessage(LANG_GROUP_PLAYER_NAME_GUID, slot.name.c_str(), onlineState,
                zoneName.c_str(), phase, slot.guid.GetCounter(), flags.c_str(),
                lfg::GetRolesString(slot.roles).c_str());
        }

        // And finish after every iterator is done.
        return true;
    }
};

void AddSC_group_commandscript()
{
    new group_commandscript();
}
