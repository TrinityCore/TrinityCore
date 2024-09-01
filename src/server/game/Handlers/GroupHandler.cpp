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

#include "WorldSession.h"
#include "Common.h"
#include "DatabaseEnv.h"
#include "Group.h"
#include "GroupMgr.h"
#include "LFG.h"
#include "Log.h"
#include "Loot.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "PartyPackets.h"
#include "Player.h"
#include "SocialMgr.h"
#include "World.h"

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

void WorldSession::SendPartyResult(PartyOperation operation, const std::string& member, PartyResult res, uint32 val /* = 0 */)
{
    WorldPackets::Party::PartyCommandResult packet;

    packet.Name = member;
    packet.Command = uint8(operation);
    packet.Result = uint8(res);
    packet.ResultData = val;
    packet.ResultGUID = ObjectGuid::Empty;

    SendPacket(packet.Write());
}

void WorldSession::HandlePartyInviteOpcode(WorldPackets::Party::PartyInviteClient& packet)
{
    Player* invitingPlayer = GetPlayer();
    Player* invitedPlayer = ObjectAccessor::FindPlayerByName(packet.TargetName);

    // no player
    if (!invitedPlayer)
    {
        SendPartyResult(PARTY_OP_INVITE, packet.TargetName, ERR_BAD_PLAYER_NAME_S);
        return;
    }

    // player trying to invite himself (most likely cheating)
    if (invitedPlayer == invitingPlayer)
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_BAD_PLAYER_NAME_S);
        return;
    }

    // restrict invite to GMs
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_GM_GROUP) && !invitingPlayer->IsGameMaster() && invitedPlayer->IsGameMaster())
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_BAD_PLAYER_NAME_S);
        return;
    }

    // can't group with
    if (!invitingPlayer->IsGameMaster() && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && invitingPlayer->GetTeam() != invitedPlayer->GetTeam())
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_PLAYER_WRONG_FACTION);
        return;
    }
    if (invitingPlayer->GetInstanceId() != 0 && invitedPlayer->GetInstanceId() != 0 && invitingPlayer->GetInstanceId() != invitedPlayer->GetInstanceId() && invitingPlayer->GetMapId() == invitedPlayer->GetMapId())
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_TARGET_NOT_IN_INSTANCE_S);
        return;
    }
    // just ignore us
    if (invitedPlayer->GetInstanceId() != 0 && invitedPlayer->GetDungeonDifficultyID() != invitingPlayer->GetDungeonDifficultyID())
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_IGNORING_YOU_S);
        return;
    }

    if (invitedPlayer->GetSocial()->HasIgnore(invitingPlayer->GetGUID(), invitingPlayer->GetSession()->GetAccountGUID()))
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_IGNORING_YOU_S);
        return;
    }

    if (!invitedPlayer->GetSocial()->HasFriend(invitingPlayer->GetGUID()) && invitingPlayer->GetLevel() < sWorld->getIntConfig(CONFIG_PARTY_LEVEL_REQ))
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_INVITE_RESTRICTED);
        return;
    }

    Group* group = invitingPlayer->GetGroup(packet.PartyIndex);
    if (!group)
        group = invitingPlayer->GetGroupInvite();

    Group* group2 = invitedPlayer->GetGroup(packet.PartyIndex);
    // player already in another group or invited
    if (group2 || invitedPlayer->GetGroupInvite())
    {
        SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_ALREADY_IN_GROUP_S);

        if (group2)
        {
            // tell the player that they were invited but it failed as they were already in a group
            WorldPackets::Party::PartyInvite partyInvite;
            partyInvite.Initialize(invitingPlayer, packet.ProposedRoles, false);
            invitedPlayer->SendDirectMessage(partyInvite.Write());
        }

        return;
    }

    if (group)
    {
        // not have permissions for invite
        if (!group->IsLeader(invitingPlayer->GetGUID()) && !group->IsAssistant(invitingPlayer->GetGUID()))
        {
            if (group->IsCreated())
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
        group = new Group();
        // new group: if can't add then delete
        if (!group->AddLeaderInvite(invitingPlayer))
        {
            delete group;
            return;
        }
        if (!group->AddInvite(invitedPlayer))
        {
            group->RemoveAllInvites();
            delete group;
            return;
        }
    }
    else
    {
        // already existed group: if can't add then just leave
        if (!group->AddInvite(invitedPlayer))
        {
            return;
        }
    }

    WorldPackets::Party::PartyInvite partyInvite;
    partyInvite.Initialize(invitingPlayer, packet.ProposedRoles, true);
    invitedPlayer->SendDirectMessage(partyInvite.Write());

    SendPartyResult(PARTY_OP_INVITE, invitedPlayer->GetName(), ERR_PARTY_RESULT_OK);
}

void WorldSession::HandlePartyInviteResponseOpcode(WorldPackets::Party::PartyInviteResponse& packet)
{
    Group* group = GetPlayer()->GetGroupInvite();

    if (!group)
        return;

    if (packet.PartyIndex && group->GetGroupCategory() != GroupCategory(*packet.PartyIndex))
        return;

    if (packet.Accept)
    {
        // Remove player from invitees in any case
        group->RemoveInvite(GetPlayer());

        if (group->GetLeaderGUID() == GetPlayer()->GetGUID())
        {
            TC_LOG_ERROR("network", "HandleGroupAcceptOpcode: player {} {} tried to accept an invite to his own group", GetPlayer()->GetName(), GetPlayer()->GetGUID().ToString());
            return;
        }

        // Group is full
        if (group->IsFull())
        {
            SendPartyResult(PARTY_OP_INVITE, "", ERR_GROUP_FULL);
            return;
        }

        Player* leader = ObjectAccessor::FindPlayer(group->GetLeaderGUID());

        // Forming a new group, create it
        if (!group->IsCreated())
        {
            // This can happen if the leader is zoning. To be removed once delayed actions for zoning are implemented
            if (!leader)
            {
                group->RemoveAllInvites();
                return;
            }

            // If we're about to create a group there really should be a leader present
            ASSERT(leader);
            group->RemoveInvite(leader);
            group->Create(leader);
            sGroupMgr->AddGroup(group);
        }

        // Everything is fine, do it, PLAYER'S GROUP IS SET IN ADDMEMBER!!!
        if (!group->AddMember(GetPlayer()))
            return;

        group->BroadcastGroupUpdate();
    }
    else
    {
        // Remember leader if online (group pointer will be invalid if group gets disbanded)
        Player* leader = ObjectAccessor::FindConnectedPlayer(group->GetLeaderGUID());

        // uninvite, group can be deleted
        GetPlayer()->UninviteFromGroup();

        if (!leader || !leader->GetSession())
            return;

        // report
        WorldPackets::Party::GroupDecline decline(GetPlayer()->GetName());
        leader->SendDirectMessage(decline.Write());
    }
}

void WorldSession::HandlePartyUninviteOpcode(WorldPackets::Party::PartyUninvite& packet)
{
    // can't uninvite yourself
    if (packet.TargetGUID == GetPlayer()->GetGUID())
    {
        TC_LOG_ERROR("network", "WorldSession::HandleGroupUninviteGuidOpcode: leader {} {} tried to uninvite himself from the group.",
            GetPlayer()->GetName(), GetPlayer()->GetGUID().ToString());
        return;
    }

    PartyResult res = GetPlayer()->CanUninviteFromGroup(packet.TargetGUID, packet.PartyIndex);
    if (res != ERR_PARTY_RESULT_OK)
    {
        SendPartyResult(PARTY_OP_UNINVITE, "", res);
        return;
    }

    Group* grp = GetPlayer()->GetGroup(packet.PartyIndex);
    // grp is checked already above in CanUninviteFromGroup()
    ASSERT(grp);

    if (grp->IsMember(packet.TargetGUID))
    {
        Player::RemoveFromGroup(grp, packet.TargetGUID, GROUP_REMOVEMETHOD_KICK, GetPlayer()->GetGUID(), packet.Reason.c_str());
        return;
    }

    if (Player* player = grp->GetInvited(packet.TargetGUID))
    {
        player->UninviteFromGroup();
        return;
    }

    SendPartyResult(PARTY_OP_UNINVITE, "", ERR_TARGET_NOT_IN_GROUP_S);
}

void WorldSession::HandleSetPartyLeaderOpcode(WorldPackets::Party::SetPartyLeader& packet)
{
    Player* player = ObjectAccessor::FindConnectedPlayer(packet.TargetGUID);
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);

    if (!group || !player)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()) || player->GetGroup() != group)
        return;

    // Everything's fine, accepted.
    group->ChangeLeader(packet.TargetGUID);
    group->SendUpdate();
}

void WorldSession::HandleSetRoleOpcode(WorldPackets::Party::SetRole& packet)
{
    WorldPackets::Party::RoleChangedInform roleChangedInform;

    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    uint8 oldRole = group ? group->GetLfgRoles(packet.TargetGUID) : 0;
    if (oldRole == packet.Role)
        return;

    roleChangedInform.From = GetPlayer()->GetGUID();
    roleChangedInform.ChangedUnit = packet.TargetGUID;
    roleChangedInform.OldRole = oldRole;
    roleChangedInform.NewRole = packet.Role;

    if (group)
    {
        roleChangedInform.PartyIndex = group->GetGroupCategory();
        group->BroadcastPacket(roleChangedInform.Write(), false);
        group->SetLfgRoles(packet.TargetGUID, packet.Role);
    }
    else
        SendPacket(roleChangedInform.Write());
}

void WorldSession::HandleLeaveGroupOpcode(WorldPackets::Party::LeaveGroup& packet)
{
    Group* grp = GetPlayer()->GetGroup(packet.PartyIndex);
    Group* grpInvite = GetPlayer()->GetGroupInvite();
    if (!grp && !grpInvite)
        return;

    if (_player->InBattleground())
    {
        SendPartyResult(PARTY_OP_INVITE, "", ERR_INVITE_RESTRICTED);
        return;
    }

    /** error handling **/
    /********************/

    // everything's fine, do it
    if (grp)
    {
        SendPartyResult(PARTY_OP_LEAVE, GetPlayer()->GetName(), ERR_PARTY_RESULT_OK);
        GetPlayer()->RemoveFromGroup(GROUP_REMOVEMETHOD_LEAVE);
    }
    else if (grpInvite && grpInvite->GetLeaderGUID() == GetPlayer()->GetGUID())
    { // pending group creation being cancelled
        SendPartyResult(PARTY_OP_LEAVE, GetPlayer()->GetName(), ERR_PARTY_RESULT_OK);
        grpInvite->Disband();
    }
}

void WorldSession::HandleSetLootMethodOpcode(WorldPackets::Party::SetLootMethod& /*packet*/)
{
    // not allowed to change
    /*
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;

    if (group->isLFGGroup())
        return;

    switch (packet.LootMethod)
    {
        case FREE_FOR_ALL:
        case MASTER_LOOT:
        case GROUP_LOOT:
        case PERSONAL_LOOT:
            break;
        default:
            return;
    }

    if (packet.LootThreshold < ITEM_QUALITY_UNCOMMON || packet.LootThreshold > ITEM_QUALITY_ARTIFACT)
        return;

    if (packet.LootMethod == MASTER_LOOT && !group->IsMember(packet.LootMasterGUID))
        return;

    // everything's fine, do it
    group->SetLootMethod(static_cast<LootMethod>(packet.LootMethod));
    group->SetMasterLooterGuid(packet.LootMasterGUID);
    group->SetLootThreshold(static_cast<ItemQualities>(packet.LootThreshold));
    group->SendUpdate();
    */
}

void WorldSession::HandleMinimapPingOpcode(WorldPackets::Party::MinimapPingClient& packet)
{
    Group const* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    WorldPackets::Party::MinimapPing minimapPing;
    minimapPing.Sender = GetPlayer()->GetGUID();
    minimapPing.PositionX = packet.PositionX;
    minimapPing.PositionY = packet.PositionY;
    group->BroadcastPacket(minimapPing.Write(), true, -1, GetPlayer()->GetGUID());
}

void WorldSession::HandleRandomRollOpcode(WorldPackets::Misc::RandomRollClient& packet)
{
    /** error handling **/
    if (packet.Min > packet.Max || packet.Max > 1000000)
        return;
    /********************/

    GetPlayer()->DoRandomRoll(packet.Min, packet.Max);
}

void WorldSession::HandleUpdateRaidTargetOpcode(WorldPackets::Party::UpdateRaidTarget& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    if (packet.Symbol == -1)                  // target icon request
        group->SendTargetIconList(this);
    else                                        // target icon update
    {
        if (group->isRaidGroup() && !group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
            return;

        if (packet.Target.IsPlayer())
        {
            Player* target = ObjectAccessor::FindConnectedPlayer(packet.Target);
            if (!target || target->IsHostileTo(GetPlayer()))
                return;
        }

        group->SetTargetIcon(packet.Symbol, packet.Target, GetPlayer()->GetGUID());
    }
}

void WorldSession::HandleConvertRaidOpcode(WorldPackets::Party::ConvertRaid& packet)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (_player->InBattleground())
        return;

    // error handling
    if (!group->IsLeader(GetPlayer()->GetGUID()) || group->GetMembersCount() < 2)
        return;

    // everything's fine, do it (is it 0 (PARTY_OP_INVITE) correct code)
    SendPartyResult(PARTY_OP_INVITE, "", ERR_PARTY_RESULT_OK);

    // New 4.x: it is now possible to convert a raid to a group if member count is 5 or less
    if (packet.Raid)
        group->ConvertToRaid();
    else
        group->ConvertToGroup();
}

void WorldSession::HandleRequestPartyJoinUpdates(WorldPackets::Party::RequestPartyJoinUpdates& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    group->SendTargetIconList(this);
    group->SendRaidMarkersChanged(this);
}

void WorldSession::HandleChangeSubGroupOpcode(WorldPackets::Party::ChangeSubGroup& packet)
{
    // we will get correct pointer for group here, so we don't have to check if group is BG raid
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    if (packet.NewSubGroup >= MAX_RAID_SUBGROUPS)
        return;

    ObjectGuid senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;

    if (!group->HasFreeSlotSubGroup(packet.NewSubGroup))
        return;

    group->ChangeMembersGroup(packet.TargetGUID, packet.NewSubGroup);
}

void WorldSession::HandleSwapSubGroupsOpcode(WorldPackets::Party::SwapSubGroups& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    ObjectGuid senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;

    group->SwapMembersGroups(packet.FirstTarget, packet.SecondTarget);
}

void WorldSession::HandleSetAssistantLeaderOpcode(WorldPackets::Party::SetAssistantLeader& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;

    group->SetGroupMemberFlag(packet.Target, packet.Apply, MEMBER_FLAG_ASSISTANT);
}

void WorldSession::HandleSetPartyAssignment(WorldPackets::Party::SetPartyAssignment& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    ObjectGuid senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;

    switch (packet.Assignment)
    {
        case GROUP_ASSIGN_MAINASSIST:
            group->RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINASSIST);
            group->SetGroupMemberFlag(packet.Target, packet.Set, MEMBER_FLAG_MAINASSIST);
            break;
        case GROUP_ASSIGN_MAINTANK:
            group->RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINTANK);           // Remove main assist flag from current if any.
            group->SetGroupMemberFlag(packet.Target, packet.Set, MEMBER_FLAG_MAINTANK);
            break;
        default:
            break;
    }

    group->SendUpdate();
}

void WorldSession::HandleDoReadyCheckOpcode(WorldPackets::Party::DoReadyCheck& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    /** error handling **/
    if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
        return;
    /********************/

    // everything's fine, do it
    group->StartReadyCheck(GetPlayer()->GetGUID());
}

void WorldSession::HandleReadyCheckResponseOpcode(WorldPackets::Party::ReadyCheckResponseClient& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    // everything's fine, do it
    group->SetMemberReadyCheck(GetPlayer()->GetGUID(), packet.IsReady);
}

void WorldSession::HandleRequestPartyMemberStatsOpcode(WorldPackets::Party::RequestPartyMemberStats& packet)
{
    WorldPackets::Party::PartyMemberFullState partyMemberStats;

    Player* player = ObjectAccessor::FindConnectedPlayer(packet.TargetGUID);
    if (!player)
    {
        partyMemberStats.MemberGuid = packet.TargetGUID;
        partyMemberStats.MemberStats.Status = MEMBER_STATUS_OFFLINE;
    }
    else
        partyMemberStats.Initialize(player);

    SendPacket(partyMemberStats.Write());
}

void WorldSession::HandleRequestRaidInfoOpcode(WorldPackets::Party::RequestRaidInfo& /*packet*/)
{
    // every time the player checks the character screen
    _player->SendRaidInfo();
}

void WorldSession::HandleOptOutOfLootOpcode(WorldPackets::Party::OptOutOfLoot& packet)
{
    // ignore if player not loaded
    if (!GetPlayer())                                        // needed because STATUS_AUTHED
    {
        if (packet.PassOnLoot)
            TC_LOG_ERROR("network", "CMSG_OPT_OUT_OF_LOOT value<>0 for not-loaded character!");
        return;
    }

    GetPlayer()->SetPassOnGroupLoot(packet.PassOnLoot);
}

void WorldSession::HandleInitiateRolePoll(WorldPackets::Party::InitiateRolePoll& packet)
{
    Group const* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    ObjectGuid guid = GetPlayer()->GetGUID();
    if (!group->IsLeader(guid) && !group->IsAssistant(guid))
        return;

    WorldPackets::Party::RolePollInform rolePollInform;
    rolePollInform.From = GetPlayer()->GetGUID();
    rolePollInform.PartyIndex = group->GetGroupCategory();
    group->BroadcastPacket(rolePollInform.Write(), true);
}

void WorldSession::HandleSetEveryoneIsAssistant(WorldPackets::Party::SetEveryoneIsAssistant& packet)
{
    Group* group = GetPlayer()->GetGroup(packet.PartyIndex);
    if (!group)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;

    group->SetEveryoneIsAssistant(packet.EveryoneIsAssistant);
}

void WorldSession::HandleClearRaidMarker(WorldPackets::Party::ClearRaidMarker& packet)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (group->isRaidGroup() && !group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
        return;

    group->DeleteRaidMarker(packet.MarkerId);
}

namespace
{
bool CanSendPing(Player const& player, PingSubjectType type, Group const*& group)
{
    if (type >= PingSubjectType::Max)
        return false;

    if (!player.GetSession()->CanSpeak())
        return false;

    group = player.GetGroup();
    if (!group)
        return false;

    if (group->IsLeader(player.GetGUID()))
        return true;

    switch (group->GetRestrictPings())
    {
        case RestrictPingsTo::None:
            return true;
        case RestrictPingsTo::Lead:
            return false;
        case RestrictPingsTo::Assist:
            if (!group->IsAssistant(player.GetGUID()))
                return false;
            break;
        case RestrictPingsTo::TankHealer:
            if (!(group->GetLfgRoles(player.GetGUID()) & (lfg::PLAYER_ROLE_TANK | lfg::PLAYER_ROLE_HEALER)))
                return false;
            break;
    }

    return true;
}
}

void WorldSession::HandleSetRestrictPingsToAssistants(WorldPackets::Party::SetRestrictPingsToAssistants const& setRestrictPingsToAssistants)
{
    Group* group = GetPlayer()->GetGroup(setRestrictPingsToAssistants.PartyIndex);
    if (!group)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;

    group->SetRestrictPingsTo(setRestrictPingsToAssistants.RestrictTo);
}

void WorldSession::HandleSendPingUnit(WorldPackets::Party::SendPingUnit const& pingUnit)
{
    Group const* group = nullptr;
    if (!CanSendPing(*_player, pingUnit.Type, group))
        return;

    Unit const* target = ObjectAccessor::GetUnit(*_player, pingUnit.TargetGUID);
    if (!target || !_player->HaveAtClient(target))
        return;

    WorldPackets::Party::ReceivePingUnit broadcastPingUnit;
    broadcastPingUnit.SenderGUID = _player->GetGUID();
    broadcastPingUnit.TargetGUID = pingUnit.TargetGUID;
    broadcastPingUnit.Type = pingUnit.Type;
    broadcastPingUnit.PinFrameID = pingUnit.PinFrameID;
    broadcastPingUnit.PingDuration = pingUnit.PingDuration;
    broadcastPingUnit.Write();

    for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player const* member = itr->GetSource();
        if (_player == member || !_player->IsInMap(member))
            continue;

        member->SendDirectMessage(broadcastPingUnit.GetRawPacket());
    }
}

void WorldSession::HandleSendPingWorldPoint(WorldPackets::Party::SendPingWorldPoint const& pingWorldPoint)
{
    Group const* group = nullptr;
    if (!CanSendPing(*_player, pingWorldPoint.Type, group))
        return;

    if (_player->GetMapId() != pingWorldPoint.MapID)
        return;

    WorldPackets::Party::ReceivePingWorldPoint broadcastPingWorldPoint;
    broadcastPingWorldPoint.SenderGUID = _player->GetGUID();
    broadcastPingWorldPoint.MapID = pingWorldPoint.MapID;
    broadcastPingWorldPoint.Point = pingWorldPoint.Point;
    broadcastPingWorldPoint.Type = pingWorldPoint.Type;
    broadcastPingWorldPoint.PinFrameID = pingWorldPoint.PinFrameID;
    broadcastPingWorldPoint.Transport = pingWorldPoint.Transport;
    broadcastPingWorldPoint.PingDuration = pingWorldPoint.PingDuration;
    broadcastPingWorldPoint.Write();

    for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player const* member = itr->GetSource();
        if (_player == member || !_player->IsInMap(member))
            continue;

        member->SendDirectMessage(broadcastPingWorldPoint.GetRawPacket());
    }
}
