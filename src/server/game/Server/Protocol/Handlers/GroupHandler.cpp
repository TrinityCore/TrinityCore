/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "Common.h"
#include "DatabaseEnv.h"
#include "Opcodes.h"
#include "Log.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Group.h"
#include "SocialMgr.h"
#include "Util.h"
#include "SpellAuras.h"
#include "Vehicle.h"
#include "LFGMgr.h"

class Aura;

/* differeces from off:
    -you can uninvite yourself - is is useful
    -you can accept invitation even if leader went offline
*/
/* todo:
    -group_destroyed msg is sent but not shown
    -reduce xp gaining when in raid group
    -quest sharing has to be corrected
    -FIX sending PartyMemberStats
*/

void WorldSession::SendPartyResult(PartyOperation operation, const std::string& member, PartyResult res)
{
    WorldPacket data(SMSG_PARTY_COMMAND_RESULT, (4+member.size()+1+4+4));
    data << (uint32)operation;
    data << member;
    data << (uint32)res;
    data << uint32(0);                                      // LFD cooldown related (used with ERR_PARTY_LFG_BOOT_COOLDOWN_S and ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S)

    SendPacket(&data);
}

void WorldSession::HandleGroupInviteOpcode(WorldPacket & recv_data)
{
    std::string membername;
    recv_data >> membername;

    // attempt add selected player

    // cheating
    if (!normalizePlayerName(membername))
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_BAD_PLAYER_NAME_S);
        return;
    }

    Player *player = sObjectMgr.GetPlayer(membername.c_str());

    // no player
    if (!player)
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_BAD_PLAYER_NAME_S);
        return;
    }

    // restrict invite to GMs
    if (!sWorld.getBoolConfig(CONFIG_ALLOW_GM_GROUP) && !GetPlayer()->isGameMaster() && player->isGameMaster())
        return;

    // can't group with
    if (!sWorld.getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && GetPlayer()->GetTeam() != player->GetTeam())
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_PLAYER_WRONG_FACTION);
        return;
    }
    if (GetPlayer()->GetInstanceId() != 0 && player->GetInstanceId() != 0 && GetPlayer()->GetInstanceId() != player->GetInstanceId() && GetPlayer()->GetMapId() == player->GetMapId())
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_TARGET_NOT_IN_INSTANCE_S);
        return;
    }
    // just ignore us
    if (player->GetInstanceId() != 0 && player->GetDungeonDifficulty() != GetPlayer()->GetDungeonDifficulty())
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_IGNORING_YOU_S);
        return;
    }

    if (player->GetSocial()->HasIgnore(GetPlayer()->GetGUIDLow()))
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_IGNORING_YOU_S);
        return;
    }

    Group *group = GetPlayer()->GetGroup();
    if (group && group->isBGGroup())
        group = GetPlayer()->GetOriginalGroup();

    Group *group2 = player->GetGroup();
    if (group2 && group2->isBGGroup())
        group2 = player->GetOriginalGroup();
    // player already in another group or invited
    if (group2 || player->GetGroupInvite())
    {
        SendPartyResult(PARTY_OP_INVITE, membername, ERR_ALREADY_IN_GROUP_S);

        if (group2)
        {
            // tell the player that they were invited but it failed as they were already in a group
            WorldPacket data(SMSG_GROUP_INVITE, 10);                // guess size
            data << uint8(0);                                       // invited/already in group flag
            data << GetPlayer()->GetName();                         // max len 48
            data << uint32(0);                                      // unk
            data << uint8(0);                                       // count
            data << uint32(0);                                      // unk
            player->GetSession()->SendPacket(&data);
        }

        return;
    }

    if (group)
    {
        // not have permissions for invite
        if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
        {
            SendPartyResult(PARTY_OP_INVITE, "", ERR_NOT_LEADER);
            return;
        }
        // not have place
        if (group->IsFull())
        {
            SendPartyResult(PARTY_OP_INVITE, "", ERR_GROUP_FULL);
            return;
        }
    }

    // ok, but group not exist, start a new group
    // but don't create and save the group to the DB until
    // at least one person joins
    if (!group)
    {
        group = new Group;
        // new group: if can't add then delete
        if (!group->AddLeaderInvite(GetPlayer()))
        {
            delete group;
            return;
        }
        if (!group->AddInvite(player))
        {
            delete group;
            return;
        }
    }
    else
    {
        // already existed group: if can't add then just leave
        if (!group->AddInvite(player))
        {
            return;
        }
    }

    // ok, we do it
    WorldPacket data(SMSG_GROUP_INVITE, 10);                // guess size
    data << uint8(1);                                       // invited/already in group flag
    data << GetPlayer()->GetName();                         // max len 48
    data << uint32(0);                                      // unk
    data << uint8(0);                                       // count
    data << uint32(0);                                      // unk
    player->GetSession()->SendPacket(&data);

    SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
    SendLfgUpdateParty(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
    SendPartyResult(PARTY_OP_INVITE, membername, ERR_PARTY_RESULT_OK);
}

void WorldSession::HandleGroupAcceptOpcode(WorldPacket & /*recv_data*/)
{
    Group *group = GetPlayer()->GetGroupInvite();
    if (!group) return;

    if (group->GetLeaderGUID() == GetPlayer()->GetGUID())
    {
        sLog.outError("HandleGroupAcceptOpcode: player %s(%d) tried to accept an invite to his own group", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow());
        return;
    }

    // remove in from ivites in any case
    group->RemoveInvite(GetPlayer());

    /** error handling **/
    /********************/

    // not have place
    if (group->IsFull())
    {
        SendPartyResult(PARTY_OP_INVITE, "", ERR_GROUP_FULL);
        return;
    }

    Player* leader = sObjectMgr.GetPlayer(group->GetLeaderGUID());

    // forming a new group, create it
    if (!group->IsCreated())
    {
        if (leader)
            group->RemoveInvite(leader);
        group->Create(group->GetLeaderGUID(), group->GetLeaderName());
        sObjectMgr.AddGroup(group);
    }

    // everything's fine, do it, PLAYER'S GROUP IS SET IN ADDMEMBER!!!
    if (!group->AddMember(GetPlayer()->GetGUID(), GetPlayer()->GetName()))
        return;

    SendLfgUpdatePlayer(LFG_UPDATETYPE_REMOVED_FROM_QUEUE);
    for (GroupReference *itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
        if (Player *plrg = itr->getSource())
        {
            plrg->GetSession()->SendLfgUpdatePlayer(LFG_UPDATETYPE_CLEAR_LOCK_LIST);
            plrg->GetSession()->SendLfgUpdateParty(LFG_UPDATETYPE_CLEAR_LOCK_LIST);
        }

    group->BroadcastGroupUpdate();
}

void WorldSession::HandleGroupDeclineOpcode(WorldPacket & /*recv_data*/)
{
    Group  *group  = GetPlayer()->GetGroupInvite();
    if (!group) return;

    // remember leader if online
    Player *leader = sObjectMgr.GetPlayer(group->GetLeaderGUID());

    // uninvite, group can be deleted
    GetPlayer()->UninviteFromGroup();

    if (!leader || !leader->GetSession())
        return;

    // report
    WorldPacket data(SMSG_GROUP_DECLINE, 10);             // guess size
    data << GetPlayer()->GetName();
    leader->GetSession()->SendPacket(&data);
}

void WorldSession::HandleGroupUninviteGuidOpcode(WorldPacket & recv_data)
{
    uint64 guid;
    std::string reason;
    recv_data >> guid;
    recv_data >> reason;

    //can't uninvite yourself
    if (guid == GetPlayer()->GetGUID())
    {
        sLog.outError("WorldSession::HandleGroupUninviteGuidOpcode: leader %s(%d) tried to uninvite himself from the group.", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow());
        return;
    }

    PartyResult res = GetPlayer()->CanUninviteFromGroup();
    if (res != ERR_PARTY_RESULT_OK)
    {
        SendPartyResult(PARTY_OP_UNINVITE, "", res);
        return;
    }

    Group* grp = GetPlayer()->GetGroup();
    if (!grp)
        return;

    if (grp->IsMember(guid))
    {
        if (grp->isLFGGroup())
            sLFGMgr.InitBoot(grp, GUID_LOPART(GetPlayer()->GetGUID()), GUID_LOPART(guid), reason);
        else
            Player::RemoveFromGroup(grp,guid);
        return;
    }

    if (Player* plr = grp->GetInvited(guid))
    {
        plr->UninviteFromGroup();
        return;
    }

    SendPartyResult(PARTY_OP_UNINVITE, "", ERR_TARGET_NOT_IN_GROUP_S);
}

void WorldSession::HandleGroupUninviteOpcode(WorldPacket & recv_data)
{
    std::string membername;
    recv_data >> membername;

    // player not found
    if (!normalizePlayerName(membername))
        return;

    // can't uninvite yourself
    if (GetPlayer()->GetName() == membername)
    {
        sLog.outError("WorldSession::HandleGroupUninviteOpcode: leader %s(%d) tried to uninvite himself from the group.", GetPlayer()->GetName(), GetPlayer()->GetGUIDLow());
        return;
    }

    PartyResult res = GetPlayer()->CanUninviteFromGroup();
    if (res != ERR_PARTY_RESULT_OK)
    {
        SendPartyResult(PARTY_OP_UNINVITE, "", res);
        return;
    }

    Group* grp = GetPlayer()->GetGroup();
    if (!grp)
        return;

    if (uint64 guid = grp->GetMemberGUID(membername))
    {
        if (grp->isLFGGroup())
            sLFGMgr.InitBoot(grp, GUID_LOPART(GetPlayer()->GetGUID()), GUID_LOPART(guid), "");
        else
            Player::RemoveFromGroup(grp,guid);
        return;
    }

    if (Player* plr = grp->GetInvited(membername))
    {
        plr->UninviteFromGroup();
        return;
    }

    SendPartyResult(PARTY_OP_UNINVITE, membername, ERR_TARGET_NOT_IN_GROUP_S);
}

void WorldSession::HandleGroupSetLeaderOpcode(WorldPacket & recv_data)
{
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    uint64 guid;
    recv_data >> guid;

    Player *player = sObjectMgr.GetPlayer(guid);

    /** error handling **/
    if (!player || !group->IsLeader(GetPlayer()->GetGUID()) || player->GetGroup() != group)
        return;
    /********************/

    // everything's fine, do it
    group->ChangeLeader(guid);
}

void WorldSession::HandleGroupDisbandOpcode(WorldPacket & /*recv_data*/)
{
    Group *grp = GetPlayer()->GetGroup();
    if (!grp)
        return;

    if (_player->InBattleground())
    {
        SendPartyResult(PARTY_OP_INVITE, "", ERR_INVITE_RESTRICTED);
        return;
    }

    /** error handling **/
    /********************/

    // everything's fine, do it
    SendPartyResult(PARTY_OP_LEAVE, GetPlayer()->GetName(), ERR_PARTY_RESULT_OK);

    GetPlayer()->RemoveFromGroup();
}

void WorldSession::HandleLootMethodOpcode(WorldPacket & recv_data)
{
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    uint32 lootMethod;
    uint64 lootMaster;
    uint32 lootThreshold;
    recv_data >> lootMethod >> lootMaster >> lootThreshold;

    /** error handling **/
    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;
    /********************/

    // everything's fine, do it
    group->SetLootMethod((LootMethod)lootMethod);
    group->SetLooterGuid(lootMaster);
    group->SetLootThreshold((ItemQualities)lootThreshold);
    group->SendUpdate();
}

void WorldSession::HandleLootRoll(WorldPacket &recv_data)
{
    if (!GetPlayer()->GetGroup())
        return;

    uint64 Guid;
    uint32 NumberOfPlayers;
    uint8  rollType;
    recv_data >> Guid;                                      //guid of the item rolled
    recv_data >> NumberOfPlayers;
    recv_data >> rollType;                                    //0: pass, 1: need, 2: greed

    //sLog.outDebug("WORLD RECIEVE CMSG_LOOT_ROLL, From:%u, Numberofplayers:%u, Choise:%u", (uint32)Guid, NumberOfPlayers, Choise);

    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    // everything's fine, do it
    group->CountRollVote(GetPlayer()->GetGUID(), Guid, NumberOfPlayers, rollType);

    switch (rollType)
    {
        case ROLL_NEED:
            GetPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED, 1);
            break;
        case ROLL_GREED:
            GetPlayer()->GetAchievementMgr().UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED, 1);
            break;
    }
}

void WorldSession::HandleMinimapPingOpcode(WorldPacket& recv_data)
{
    if (!GetPlayer()->GetGroup())
        return;

    float x, y;
    recv_data >> x;
    recv_data >> y;

    //sLog.outDebug("Received opcode MSG_MINIMAP_PING X: %f, Y: %f", x, y);

    /** error handling **/
    /********************/

    // everything's fine, do it
    WorldPacket data(MSG_MINIMAP_PING, (8+4+4));
    data << uint64(GetPlayer()->GetGUID());
    data << float(x);
    data << float(y);
    GetPlayer()->GetGroup()->BroadcastPacket(&data, true, -1, GetPlayer()->GetGUID());
}

void WorldSession::HandleRandomRollOpcode(WorldPacket& recv_data)
{
    uint32 minimum, maximum, roll;
    recv_data >> minimum;
    recv_data >> maximum;

    /** error handling **/
    if (minimum > maximum || maximum > 10000)                // < 32768 for urand call
        return;
    /********************/

    // everything's fine, do it
    roll = urand(minimum, maximum);

    //sLog.outDebug("ROLL: MIN: %u, MAX: %u, ROLL: %u", minimum, maximum, roll);

    WorldPacket data(MSG_RANDOM_ROLL, 4+4+4+8);
    data << uint32(minimum);
    data << uint32(maximum);
    data << uint32(roll);
    data << uint64(GetPlayer()->GetGUID());
    if (GetPlayer()->GetGroup())
        GetPlayer()->GetGroup()->BroadcastPacket(&data, false);
    else
        SendPacket(&data);
}

void WorldSession::HandleRaidTargetUpdateOpcode(WorldPacket & recv_data)
{
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    uint8  x;
    recv_data >> x;

    /** error handling **/
    /********************/

    // everything's fine, do it
    if (x == 0xFF)                                           // target icon request
    {
        group->SendTargetIconList(this);
    }
    else                                                    // target icon update
    {
        if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
            return;

        uint64 guid;
        recv_data >> guid;
        group->SetTargetIcon(x, _player->GetGUID(), guid);
    }
}

void WorldSession::HandleGroupRaidConvertOpcode(WorldPacket & /*recv_data*/)
{
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (_player->InBattleground())
        return;

    /** error handling **/
    if (!group->IsLeader(GetPlayer()->GetGUID()) || group->GetMembersCount() < 2)
        return;
    /********************/

    // everything's fine, do it (is it 0 (PARTY_OP_INVITE) correct code)
    SendPartyResult(PARTY_OP_INVITE, "", ERR_PARTY_RESULT_OK);
    group->ConvertToRaid();
}

void WorldSession::HandleGroupChangeSubGroupOpcode(WorldPacket & recv_data)
{
    // we will get correct pointer for group here, so we don't have to check if group is BG raid
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    std::string name;
    uint8 groupNr;
    recv_data >> name;
    recv_data >> groupNr;

    if (groupNr >= MAX_RAID_SUBGROUPS)
        return;

    /** error handling **/
    uint64 senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;

    if (!group->HasFreeSlotSubGroup(groupNr))
        return;
    /********************/

    Player *movedPlayer = sObjectMgr.GetPlayer(name.c_str());
    if (movedPlayer)
    {
        //Do not allow leader to change group of player in combat
        if (movedPlayer->isInCombat())
            return;

        // everything's fine, do it
        group->ChangeMembersGroup(movedPlayer, groupNr);
    }
    else
        group->ChangeMembersGroup(sObjectMgr.GetPlayerGUIDByName(name.c_str()), groupNr);
}

void WorldSession::HandleGroupAssistantLeaderOpcode(WorldPacket & recv_data)
{
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    uint64 guid;
    uint8 flag;
    recv_data >> guid;
    recv_data >> flag;

    /** error handling **/
    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;
    /********************/

    // everything's fine, do it
    group->SetAssistant(guid, (flag != 0));
}

void WorldSession::HandlePartyAssignmentOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("MSG_PARTY_ASSIGNMENT");

    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    uint8 flag, apply;
    uint64 guid;
    recv_data >> flag >> apply;
    recv_data >> guid;

    /** error handling **/
    uint64 senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;
    /********************/

    // everything's fine, do it
    if (flag == 0)
        group->SetMainTank(guid, apply);

    else if (flag == 1)
        group->SetMainAssistant(guid, apply);
}

void WorldSession::HandleRaidReadyCheckOpcode(WorldPacket & recv_data)
{
    Group *group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (recv_data.empty())                                   // request
    {
        /** error handling **/
        if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
            return;
        /********************/

        // everything's fine, do it
        WorldPacket data(MSG_RAID_READY_CHECK, 8);
        data << GetPlayer()->GetGUID();
        group->BroadcastPacket(&data, false, -1);

        group->OfflineReadyCheck();
    }
    else                                                    // answer
    {
        uint8 state;
        recv_data >> state;

        // everything's fine, do it
        WorldPacket data(MSG_RAID_READY_CHECK_CONFIRM, 9);
        data << uint64(GetPlayer()->GetGUID());
        data << uint8(state);
        group->BroadcastReadyCheck(&data);
    }
}

void WorldSession::HandleRaidReadyCheckFinishedOpcode(WorldPacket & /*recv_data*/)
{
    //Group* group = GetPlayer()->GetGroup();
    //if (!group)
    //    return;

    //if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
    //    return;

    // Is any reaction need?
}

void WorldSession::BuildPartyMemberStatsChangedPacket(Player *player, WorldPacket *data)
{
    uint32 mask = player->GetGroupUpdateFlag();

    if (mask == GROUP_UPDATE_FLAG_NONE)
        return;

    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)                // if update power type, update current/max power also
        mask |= (GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER);

    if (mask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)            // same for pets
        mask |= (GROUP_UPDATE_FLAG_PET_CUR_POWER | GROUP_UPDATE_FLAG_PET_MAX_POWER);

    uint32 byteCount = 0;
    for (int i = 1; i < GROUP_UPDATE_FLAGS_COUNT; ++i)
        if (mask & (1 << i))
            byteCount += GroupUpdateLength[i];

    data->Initialize(SMSG_PARTY_MEMBER_STATS, 8 + 4 + byteCount);
    data->append(player->GetPackGUID());
    *data << (uint32) mask;

    if (mask & GROUP_UPDATE_FLAG_STATUS)
    {
        if (player)
        {
            if (player->IsPvP())
                *data << (uint16) (MEMBER_STATUS_ONLINE | MEMBER_STATUS_PVP);
            else
                *data << (uint16) MEMBER_STATUS_ONLINE;
        }
        else
            *data << (uint16) MEMBER_STATUS_OFFLINE;
    }

    if (mask & GROUP_UPDATE_FLAG_CUR_HP)
        *data << (uint32) player->GetHealth();

    if (mask & GROUP_UPDATE_FLAG_MAX_HP)
        *data << (uint32) player->GetMaxHealth();

    Powers powerType = player->getPowerType();
    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)
        *data << (uint8) powerType;

    if (mask & GROUP_UPDATE_FLAG_CUR_POWER)
        *data << (uint16) player->GetPower(powerType);

    if (mask & GROUP_UPDATE_FLAG_MAX_POWER)
        *data << (uint16) player->GetMaxPower(powerType);

    if (mask & GROUP_UPDATE_FLAG_LEVEL)
        *data << (uint16) player->getLevel();

    if (mask & GROUP_UPDATE_FLAG_ZONE)
        *data << (uint16) player->GetZoneId();

    if (mask & GROUP_UPDATE_FLAG_POSITION)
        *data << (uint16) player->GetPositionX() << (uint16) player->GetPositionY();

    if (mask & GROUP_UPDATE_FLAG_AURAS)
    {
        const uint64& auramask = player->GetAuraUpdateMaskForRaid();
        *data << uint64(auramask);
        for (uint32 i = 0; i < MAX_AURAS; ++i)
        {
            if (auramask & (uint64(1) << i))
            {
                AuraApplication const * aurApp = player->GetVisibleAura(i);
                *data << uint32(aurApp ? aurApp->GetBase()->GetId() : 0);
                *data << uint8(1);
            }
        }
    }

    Pet *pet = player->GetPet();
    if (mask & GROUP_UPDATE_FLAG_PET_GUID)
    {
        if (pet)
            *data << (uint64) pet->GetGUID();
        else
            *data << (uint64) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_NAME)
    {
        if (pet)
            *data << pet->GetName();
        else
            *data << (uint8)  0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_MODEL_ID)
    {
        if (pet)
            *data << (uint16) pet->GetDisplayId();
        else
            *data << (uint16) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_CUR_HP)
    {
        if (pet)
            *data << (uint32) pet->GetHealth();
        else
            *data << (uint32) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_MAX_HP)
    {
        if (pet)
            *data << (uint32) pet->GetMaxHealth();
        else
            *data << (uint32) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)
    {
        if (pet)
            *data << (uint8)  pet->getPowerType();
        else
            *data << (uint8)  0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_CUR_POWER)
    {
        if (pet)
            *data << (uint16) pet->GetPower(pet->getPowerType());
        else
            *data << (uint16) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_MAX_POWER)
    {
        if (pet)
            *data << (uint16) pet->GetMaxPower(pet->getPowerType());
        else
            *data << (uint16) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_VEHICLE_SEAT)
    {
        if (player->GetVehicle()){
            Vehicle* vv=player->GetVehicle();
            *data << (uint32) vv->GetVehicleInfo()->m_seatID[player->m_movementInfo.t_seat];
        }
    }

    if (mask & GROUP_UPDATE_FLAG_PET_AURAS)
    {
        if (pet)
        {
            const uint64& auramask = pet->GetAuraUpdateMaskForRaid();
            *data << uint64(auramask);
            for (uint32 i = 0; i < MAX_AURAS; ++i)
            {
                if (auramask & (uint64(1) << i))
                {
                    AuraApplication const * aurApp = player->GetVisibleAura(i);
                    *data << uint32(aurApp ? aurApp->GetBase()->GetId() : 0);
                    *data << uint8(1);
                }
            }
        }
        else
            *data << (uint64) 0;
    }
}

/*this procedure handles clients CMSG_REQUEST_PARTY_MEMBER_STATS request*/
void WorldSession::HandleRequestPartyMemberStatsOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_REQUEST_PARTY_MEMBER_STATS");
    uint64 Guid;
    recv_data >> Guid;

    Player *player = sObjectMgr.GetPlayer(Guid);
    if (!player)
    {
        WorldPacket data(SMSG_PARTY_MEMBER_STATS_FULL, 3+4+2);
        data << uint8(0);                                   // only for SMSG_PARTY_MEMBER_STATS_FULL, probably arena/bg related
        data.appendPackGUID(Guid);
        data << (uint32) GROUP_UPDATE_FLAG_STATUS;
        data << (uint16) MEMBER_STATUS_OFFLINE;
        SendPacket(&data);
        return;
    }

    Pet *pet = player->GetPet();

    WorldPacket data(SMSG_PARTY_MEMBER_STATS_FULL, 4+2+2+2+1+2*6+8+1+8);
    data << uint8(0);                                       // only for SMSG_PARTY_MEMBER_STATS_FULL, probably arena/bg related
    data.append(player->GetPackGUID());

    uint32 mask1 = 0x00040BFF;                              // common mask, real flags used 0x000040BFF
    if (pet)
        mask1 = 0x7FFFFFFF;                                 // for hunters and other classes with pets

    Powers powerType = player->getPowerType();
    data << (uint32) mask1;                                 // group update mask
    data << (uint16) MEMBER_STATUS_ONLINE;                  // member's online status
    data << (uint32) player->GetHealth();                   // GROUP_UPDATE_FLAG_CUR_HP
    data << (uint32) player->GetMaxHealth();                // GROUP_UPDATE_FLAG_MAX_HP
    data << (uint8)  powerType;                             // GROUP_UPDATE_FLAG_POWER_TYPE
    data << (uint16) player->GetPower(powerType);           // GROUP_UPDATE_FLAG_CUR_POWER
    data << (uint16) player->GetMaxPower(powerType);        // GROUP_UPDATE_FLAG_MAX_POWER
    data << (uint16) player->getLevel();                    // GROUP_UPDATE_FLAG_LEVEL
    data << (uint16) player->GetZoneId();                   // GROUP_UPDATE_FLAG_ZONE
    data << (uint16) player->GetPositionX();                // GROUP_UPDATE_FLAG_POSITION
    data << (uint16) player->GetPositionY();                // GROUP_UPDATE_FLAG_POSITION

    uint64 auramask = 0;
    size_t maskPos = data.wpos();
    data << (uint64) auramask;                              // placeholder
    for (uint8 i = 0; i < MAX_AURAS; ++i)
    {
        if (AuraApplication * aurApp = player->GetVisibleAura(i))
        {
            auramask |= (uint64(1) << i);
            data << (uint32) aurApp->GetBase()->GetId();
            data << (uint8)  1;
        }
    }
    data.put<uint64>(maskPos,auramask);                     // GROUP_UPDATE_FLAG_AURAS

    if (pet)
    {
        Powers petpowertype = pet->getPowerType();
        data << (uint64) pet->GetGUID();                    // GROUP_UPDATE_FLAG_PET_GUID
        data << pet->GetName();                             // GROUP_UPDATE_FLAG_PET_NAME
        data << (uint16) pet->GetDisplayId();               // GROUP_UPDATE_FLAG_PET_MODEL_ID
        data << (uint32) pet->GetHealth();                  // GROUP_UPDATE_FLAG_PET_CUR_HP
        data << (uint32) pet->GetMaxHealth();               // GROUP_UPDATE_FLAG_PET_MAX_HP
        data << (uint8)  petpowertype;                      // GROUP_UPDATE_FLAG_PET_POWER_TYPE
        data << (uint16) pet->GetPower(petpowertype);       // GROUP_UPDATE_FLAG_PET_CUR_POWER
        data << (uint16) pet->GetMaxPower(petpowertype);    // GROUP_UPDATE_FLAG_PET_MAX_POWER

        uint64 petauramask = 0;
        size_t petMaskPos = data.wpos();
        data << (uint64) petauramask;                       // placeholder
        for (uint8 i = 0; i < MAX_AURAS; ++i)
        {
            if (AuraApplication * auraApp = pet->GetVisibleAura(i))
            {
                petauramask |= (uint64(1) << i);
                data << (uint32) auraApp->GetBase()->GetId();
                data << (uint8)  1;
            }
        }
        data.put<uint64>(petMaskPos,petauramask);           // GROUP_UPDATE_FLAG_PET_AURAS
    }
    else
    {
        data << (uint8)  0;                                 // GROUP_UPDATE_FLAG_PET_NAME
        data << (uint64) 0;                                 // GROUP_UPDATE_FLAG_PET_AURAS
    }

    SendPacket(&data);
}

/*!*/void WorldSession::HandleRequestRaidInfoOpcode(WorldPacket & /*recv_data*/)
{
    // every time the player checks the character screen
    _player->SendRaidInfo();
}

/*void WorldSession::HandleGroupCancelOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: got CMSG_GROUP_CANCEL.");
}*/

void WorldSession::HandleOptOutOfLootOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("WORLD: Received CMSG_OPT_OUT_OF_LOOT");

    uint32 passOnLoot;
    recv_data >> passOnLoot; // 1 always pass, 0 do not pass

    // ignore if player not loaded
    if (!GetPlayer())                                        // needed because STATUS_AUTHED
    {
        if (passOnLoot != 0)
            sLog.outError("CMSG_OPT_OUT_OF_LOOT value<>0 for not-loaded character!");
        return;
    }

    GetPlayer()->SetPassOnGroupLoot(passOnLoot);
}
