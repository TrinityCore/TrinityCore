/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Common.h"
#include "DatabaseEnv.h"
#include "Group.h"
#include "GroupMgr.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Pet.h"
#include "Player.h"
#include "SocialMgr.h"
#include "SpellAuras.h"
#include "Util.h"
#include "Vehicle.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "SpellAuraEffects.h"
#include "MiscPackets.h"
#include "LootPackets.h"
#include "PartyPackets.h"

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
    WorldPackets::Party::PartyCommandResult data;
    data.Name = member;
    data.Command = operation;
    data.Result = res;
    data.ResultData = val; // LFD cooldown related (used with ERR_PARTY_LFG_BOOT_COOLDOWN_S and ERR_PARTY_LFG_BOOT_NOT_ELIGIBLE_S)

    SendPacket(data.Write());
}

void WorldSession::HandleGroupInviteOpcode(WorldPackets::Party::ClientPartyInvite& packet)
{
    ObjectGuid crossRealmGuid; // unused

    std::string memberName, realmName;
    memberName = packet.TargetName;
    realmName = packet.TargetRealm; // unused

    // attempt add selected player

    // cheating
    if (!normalizePlayerName(memberName))
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_BAD_PLAYER_NAME_S);
        return;
    }

    Player* player = ObjectAccessor::FindPlayerByName(memberName);

    // no player
    if (!player)
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_BAD_PLAYER_NAME_S);
        return;
    }

    // restrict invite to GMs
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_GM_GROUP) && !GetPlayer()->IsGameMaster() && player->IsGameMaster())
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_BAD_PLAYER_NAME_S);
        return;
    }

    // can't group with
    if (!GetPlayer()->IsGameMaster() && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP) && GetPlayer()->GetTeam() != player->GetTeam())
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_PLAYER_WRONG_FACTION);
        return;
    }
    if (GetPlayer()->GetInstanceId() != 0 && player->GetInstanceId() != 0 && GetPlayer()->GetInstanceId() != player->GetInstanceId() && GetPlayer()->GetMapId() == player->GetMapId())
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_TARGET_NOT_IN_INSTANCE_S);
        return;
    }
    // just ignore us
    if (player->GetInstanceId() != 0 && player->GetDungeonDifficultyID() != GetPlayer()->GetDungeonDifficultyID())
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_IGNORING_YOU_S);
        return;
    }

    if (player->GetSocial()->HasIgnore(GetPlayer()->GetGUID()))
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_IGNORING_YOU_S);
        return;
    }

    ObjectGuid invitedGuid = player->GetGUID();

    Group* group = GetPlayer()->GetGroup();
    if (group && group->isBGGroup())
        group = GetPlayer()->GetOriginalGroup();

    Group* group2 = player->GetGroup();
    if (group2 && group2->isBGGroup())
        group2 = player->GetOriginalGroup();
    // player already in another group or invited
    if (group2 || player->GetGroupInvite())
    {
        SendPartyResult(PARTY_OP_INVITE, memberName, ERR_ALREADY_IN_GROUP_S);

        if (group2)
        {
            // tell the player that they were invited but it failed as they were already in a group
            WorldPackets::Party::PartyInvite partyInvite;

            partyInvite.CanAccept = false;

            partyInvite.InviterGuid = GetPlayer()->GetGUID();
            partyInvite.InviterBNetAccountID = GetPlayer()->GetSession()->GetBattlenetAccountGUID();

            partyInvite.InviterRealmNameActual = realmName; // No crossrealm support
            partyInvite.InviterRealmNameNormalized = realmName;

            partyInvite.ProposedRoles = packet.ProposedRoles;


            partyInvite.InviterName = GetPlayer()->GetName();

            player->GetSession()->SendPacket(partyInvite.Write());
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
    WorldPackets::Party::PartyInvite partyInvite;

    partyInvite.CanAccept = true;

    partyInvite.InviterGuid = GetPlayer()->GetGUID();
    partyInvite.InviterBNetAccountID = GetPlayer()->GetSession()->GetBattlenetAccountGUID();

    partyInvite.InviterRealmNameActual = realmName; // No crossrealm support
    partyInvite.InviterRealmNameNormalized = realmName;

    partyInvite.ProposedRoles = packet.ProposedRoles;

    partyInvite.InviterName = GetPlayer()->GetName();

    player->GetSession()->SendPacket(partyInvite.Write());
    SendPartyResult(PARTY_OP_INVITE, memberName, ERR_PARTY_RESULT_OK);
}

void WorldSession::HandleGroupInviteResponseOpcode(WorldPackets::Party::PartyInviteResponse& partyInviteResponse)
{
    bool accept = partyInviteResponse.Accept;

    // Never actually received?
    /*if (accept)
        recvData.read_skip<uint32>(); // unk*/

    Group* group = GetPlayer()->GetGroupInvite();

    if (!group)
        return;

    if (accept)
    {
        // Remove player from invitees in any case
        group->RemoveInvite(GetPlayer());

        if (group->GetLeaderGUID() == GetPlayer()->GetGUID())
        {
            TC_LOG_ERROR("network", "HandleGroupAcceptOpcode: player %s (%s) tried to accept an invite to his own group", GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
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
        WorldPackets::Party::GroupDecline groupDecline;
        groupDecline.Name =  GetPlayer()->GetName();
        leader->GetSession()->SendPacket(groupDecline.Write());
    }
}

void WorldSession::HandleGroupUninviteOpcode(WorldPackets::Party::PartyUninvite& partyUninvite)
{
    ObjectGuid guid = partyUninvite.TargetGUID;
    std::string  reason = partyUninvite.Reason;

    //can't uninvite yourself
    if (guid == GetPlayer()->GetGUID())
    {
        TC_LOG_ERROR("network", "WorldSession::HandleGroupUninviteGuidOpcode: leader %s (%s) tried to uninvite himself from the group.",
            GetPlayer()->GetName().c_str(), GetPlayer()->GetGUID().ToString().c_str());
        return;
    }

    PartyResult res = GetPlayer()->CanUninviteFromGroup(guid);
    if (res != ERR_PARTY_RESULT_OK)
    {
        SendPartyResult(PARTY_OP_UNINVITE, "", res);
        return;
    }

    Group* grp = GetPlayer()->GetGroup();
    // grp is checked already above in CanUninviteFromGroup()
    ASSERT(grp);

    if (grp->IsMember(guid))
    {
        Player::RemoveFromGroup(grp, guid, GROUP_REMOVEMETHOD_KICK, GetPlayer()->GetGUID(), reason.c_str());
        return;
    }

    if (Player* player = grp->GetInvited(guid))
    {
        player->UninviteFromGroup();
        return;
    }

    SendPartyResult(PARTY_OP_UNINVITE, "", ERR_TARGET_NOT_IN_GROUP_S);
}

void WorldSession::HandleGroupSetLeaderOpcode(WorldPackets::Party::SetPartyLeader& setPartyLeader)
{

    Player* player = ObjectAccessor::FindConnectedPlayer(setPartyLeader.TargetGUID);
    Group* group = GetPlayer()->GetGroup();

    if (!group || !player)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()) || player->GetGroup() != group)
        return;

    // Everything's fine, accepted.
    group->ChangeLeader(setPartyLeader.TargetGUID);
    group->SendUpdate();
}

void WorldSession::HandleGroupSetRolesOpcode(WorldPackets::Party::SetRole& setRole)
{
    ObjectGuid guid1;                   // Assigner GUID
    ObjectGuid guid2;                   // Target GUID

    guid1 = GetPlayer()->GetGUID();

    guid2 = setRole.ChangedUnit;

    WorldPackets::Party::RoleChangedInform data;

    data.PartyIndex = setRole.PartyIndex;
    data.From = guid1;
    data.ChangedUnit = guid2;
    data.OldRole = lfg::PLAYER_ROLE_NONE;
    data.NewRole = setRole.Role;


    if (Group* group = GetPlayer()->GetGroup())
    {
        /// @todo probably should be sent only if (oldRole != newRole)
        group->BroadcastPacket(data.Write(), false);
        group->SetLfgRoles(guid2, setRole.Role);
    }
    else
        SendPacket(data.Write());
}

void WorldSession::HandleGroupDisbandOpcode(WorldPackets::Party::LeaveGroup& /*leaveGroup*/)
{
    Group* grp = GetPlayer()->GetGroup();
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

    GetPlayer()->RemoveFromGroup(GROUP_REMOVEMETHOD_LEAVE);
}

void WorldSession::HandleLootMethodOpcode(WorldPacket& recvData)
{
    uint32 lootMethod;
    ObjectGuid lootMaster;
    uint32 lootThreshold;
    recvData >> lootMethod >> lootMaster >> lootThreshold;

    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    /** error handling **/
    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;

    if (lootMethod > NEED_BEFORE_GREED)
        return;

    if (lootThreshold < ITEM_QUALITY_UNCOMMON || lootThreshold > ITEM_QUALITY_ARTIFACT)
        return;

    if (lootMethod == MASTER_LOOT && !group->IsMember(lootMaster))
        return;
    /********************/

    // everything's fine, do it
    group->SetLootMethod((LootMethod)lootMethod);
    group->SetMasterLooterGuid(lootMaster);
    group->SetLootThreshold((ItemQualities)lootThreshold);
    group->SendUpdate();
}

void WorldSession::HandleLootRoll(WorldPackets::Loot::LootRoll& packet)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    group->CountRollVote(GetPlayer()->GetGUID(), packet.LootObj, packet.RollType);

    switch (packet.RollType)
    {
        case ROLL_NEED:
            GetPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ROLL_NEED, 1);
            break;
        case ROLL_GREED:
            GetPlayer()->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_ROLL_GREED, 1);
            break;
    }
}

void WorldSession::HandleMinimapPingOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received MSG_MINIMAP_PING");

    if (!GetPlayer()->GetGroup())
        return;

    float x, y;
    recvData >> x;
    recvData >> y;

    //TC_LOG_DEBUG("misc", "Received opcode MSG_MINIMAP_PING X: %f, Y: %f", x, y);

    /** error handling **/
    /********************/

    // everything's fine, do it
    WorldPacket data(SMSG_MINIMAP_PING, (8+4+4));
    data << GetPlayer()->GetGUID();
    data << float(x);
    data << float(y);
    GetPlayer()->GetGroup()->BroadcastPacket(&data, true, -1, GetPlayer()->GetGUID());
}

void WorldSession::HandleRandomRollOpcode(WorldPackets::Misc::RandomRollClient& packet)
{
    uint32 minimum, maximum, roll;
    minimum = packet.Min;
    maximum = packet.Max;

    /** error handling **/
    if (minimum > maximum || maximum > 10000)                // < 32768 for urand call
        return;
    /********************/

    // everything's fine, do it
    roll = urand(minimum, maximum);

    //TC_LOG_DEBUG("misc", "ROLL: MIN: %u, MAX: %u, ROLL: %u", minimum, maximum, roll);

    WorldPackets::Misc::RandomRoll randomRoll;
    randomRoll.Min = minimum;
    randomRoll.Max = maximum;
    randomRoll.Result = roll;
    randomRoll.Roller = GetPlayer()->GetGUID();
    randomRoll.RollerWowAccount = GetAccountGUID();
    if (GetPlayer()->GetGroup())
        GetPlayer()->GetGroup()->BroadcastPacket(randomRoll.Write(), false);
    else
        SendPacket(randomRoll.Write());
}

void WorldSession::HandleRaidTargetUpdateOpcode(WorldPackets::Party::UpdateRaidTarget& packet)
{
    TC_LOG_DEBUG("network", "WORLD: Received MSG_RAID_TARGET_UPDATE");

    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    uint8 symbol;
    symbol = packet.Symbol;

    /** error handling **/
    /********************/

    // everything's fine, do it
    if (symbol == 0xFF)                                           // target icon request
        group->SendTargetIconList(this);
    else                                                    // target icon update
    {
        if (group->isRaidGroup() && !group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
            return;

        ObjectGuid guid;
        guid = packet.Target;

        if (guid.IsPlayer())
        {
            Player* target = ObjectAccessor::FindConnectedPlayer(guid);

            if (!target || target->IsHostileTo(GetPlayer()))
                return;
        }

        group->SetTargetIcon(symbol, _player->GetGUID(), guid);
    }
}

void WorldSession::HandleGroupRaidConvertOpcode(WorldPacket& recvData)
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

    bool toRaid;
    recvData >> toRaid;

    if (toRaid)
        group->ConvertToRaid();
    else
        group->ConvertToGroup();
}

void WorldSession::HandleGroupRequestJoinUpdates(WorldPackets::Party::RequestPartyJoinUpdates& requestPartyJoinUpdates)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    // does some stuff. dunno what.
}

void WorldSession::HandleGroupChangeSubGroupOpcode(WorldPacket& recvData)
{
    // we will get correct pointer for group here, so we don't have to check if group is BG raid
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    std::string name;
    uint8 groupNr;
    recvData >> name;
    recvData >> groupNr;

    if (groupNr >= MAX_RAID_SUBGROUPS)
        return;

    ObjectGuid senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;

    if (!group->HasFreeSlotSubGroup(groupNr))
        return;

    Player* movedPlayer = ObjectAccessor::FindConnectedPlayerByName(name);
    ObjectGuid guid;

    if (movedPlayer)
        guid = movedPlayer->GetGUID();
    else
    {
        CharacterDatabase.EscapeString(name);
        guid = ObjectMgr::GetPlayerGUIDByName(name.c_str());
    }

    group->ChangeMembersGroup(guid, groupNr);
}

void WorldSession::HandleGroupSwapSubGroupOpcode(WorldPacket& recvData)
{
    std::string unk1;
    std::string unk2;

    recvData >> unk1;
    recvData >> unk2;
}

void WorldSession::HandleGroupAssistantLeaderOpcode(WorldPacket& recvData)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (!group->IsLeader(GetPlayer()->GetGUID()))
        return;

    ObjectGuid guid;
    bool apply;
    recvData >> guid;
    recvData >> apply;

    group->SetGroupMemberFlag(guid, apply, MEMBER_FLAG_ASSISTANT);
}

void WorldSession::HandlePartyAssignmentOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received MSG_PARTY_ASSIGNMENT");

    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    ObjectGuid senderGuid = GetPlayer()->GetGUID();
    if (!group->IsLeader(senderGuid) && !group->IsAssistant(senderGuid))
        return;

    uint8 assignment;
    bool apply;
    ObjectGuid guid;
    recvData >> assignment >> apply;
    recvData >> guid;

    switch (assignment)
    {
        case GROUP_ASSIGN_MAINASSIST:
            group->RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINASSIST);
            group->SetGroupMemberFlag(guid, apply, MEMBER_FLAG_MAINASSIST);
            break;
        case GROUP_ASSIGN_MAINTANK:
            group->RemoveUniqueGroupMemberFlag(MEMBER_FLAG_MAINTANK);           // Remove main assist flag from current if any.
            group->SetGroupMemberFlag(guid, apply, MEMBER_FLAG_MAINTANK);
        default:
            break;
    }

    group->SendUpdate();
}

void WorldSession::HandleRaidReadyCheckOpcode(WorldPacket& recvData)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (recvData.empty())                                   // request
    {
        /** error handling **/
        if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
            return;
        /********************/

        // everything's fine, do it
        WorldPacket data(SMSG_READY_CHECK_STARTED, 8);
        data << GetPlayer()->GetGUID();
        group->BroadcastPacket(&data, false, -1);

        group->OfflineReadyCheck();
    }
    else                                                    // answer
    {
        uint8 state;
        recvData >> state;

        // everything's fine, do it
        WorldPacket data(SMSG_READY_CHECK_RESPONSE, 9);
        data << GetPlayer()->GetGUID();
        data << uint8(state);
        group->BroadcastReadyCheck(&data);
    }
}

//void WorldSession::BuildPartyMemberStatsChangedPacket(Player* player, WorldPacket* data)
void WorldSession::SendPartyMemberState(Player* player)
{
    Pet* pet = player->GetPet();
    Powers powerType = player->getPowerType();
    std::set<uint32> const& phases = player->GetPhases();
    
    //WorldPacket data(SMSG_PARTY_MEMBER_STATE, 4 + 2 + 2 + 2 + 1 + 2 * 6 + 8 + 1 + 8);
    WorldPackets::Party::PartyMemberState partyMemberState;
    partyMemberState.ForEnemy = false;
    partyMemberState.MemberGuid = player->GetGUID();

    uint16 playerStatus = MEMBER_STATUS_ONLINE;
    if (player->IsPvP())
        playerStatus |= MEMBER_STATUS_PVP;

    if (!player->IsAlive())
    {
        if (player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            playerStatus |= MEMBER_STATUS_GHOST;
        else
            playerStatus |= MEMBER_STATUS_DEAD;
    }

    if (player->IsFFAPvP())
        playerStatus |= MEMBER_STATUS_PVP_FFA;

    if (player->isAFK())
        playerStatus |= MEMBER_STATUS_AFK;

    if (player->isDND())
        playerStatus |= MEMBER_STATUS_DND;

    partyMemberState.PowerType = powerType;
    partyMemberState.Status = playerStatus;                                 // GROUP_UPDATE_FLAG_STATUS
    partyMemberState.CurrentHealth = player->GetHealth();           // GROUP_UPDATE_FLAG_CUR_HP
    partyMemberState.MaxHealth = player->GetMaxHealth();           // GROUP_UPDATE_FLAG_MAX_HP

    partyMemberState.CurrentPower = player->GetPower(powerType);            // GROUP_UPDATE_FLAG_CUR_POWER
    partyMemberState.MaxPower = player->GetMaxPower(powerType);         // GROUP_UPDATE_FLAG_MAX_POWER
    partyMemberState.Level = player->getLevel();                     // GROUP_UPDATE_FLAG_LEVEL
    partyMemberState.ZoneId = player->GetZoneId();                    // GROUP_UPDATE_FLAG_ZONE
    partyMemberState.PositionX = player->GetPositionX();                 // GROUP_UPDATE_FLAG_POSITION
    partyMemberState.PositionY = player->GetPositionY();                 // GROUP_UPDATE_FLAG_POSITION
    partyMemberState.PositionZ = player->GetPositionZ();               // GROUP_UPDATE_FLAG_POSITION

    partyMemberState.VehicleSeat = player->GetVehicle() ? player->GetVehicle()->GetVehicleInfo()->SeatID[player->m_movementInfo.transport.seat] : 0;

    partyMemberState.PhaseShiftFlags = phases.empty() ? 8 : 0;
    for (std::set<uint32>::const_iterator itr = phases.begin(); itr != phases.end(); ++itr)
        partyMemberState.Phases.push_back(uint16(*itr));

    for (uint8 i = 0; i < MAX_AURAS; ++i)
    {
        if (AuraApplication const* aurApp = player->GetVisibleAura(i))
        {
            WorldPackets::Party::PartyMemberState::Aura aura;

            aura.SpellId = aurApp->GetBase()->GetId();
            //todo: Scalings
            aura.EffectMask = aurApp->GetEffectMask();

            if (aurApp->GetFlags() & AFLAG_SCALABLE)
            {
                for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                {
                    if (AuraEffect const* eff = aurApp->GetBase()->GetEffect(i))
                        aura.Scales.push_back(eff->GetAmount());
                    else
                        aura.Scales.push_back(0);
                }
            }
            partyMemberState.AuraList.push_back(aura);
        }
    }

    partyMemberState.HasPet = pet ? true : false;
    if (partyMemberState.HasPet)
    {
        partyMemberState.PetName = pet->GetName();                          // GROUP_UPDATE_FLAG_PET_NAME
        partyMemberState.PetModelId = pet->GetDisplayId();          // GROUP_UPDATE_FLAG_PET_MODEL_ID
        partyMemberState.PetCurrentHealth = pet->GetHealth();
        partyMemberState.PetMaxHealth = pet->GetMaxHealth();

        for (uint8 i = 0; i < MAX_AURAS; ++i)
        {
            if (AuraApplication const* aurApp = pet->GetVisibleAura(i))
            {
                WorldPackets::Party::PartyMemberState::Aura aura;
                aura.SpellId = aurApp->GetBase()->GetId();
                //todo: Scalings
                aura.EffectMask = aurApp->GetEffectMask();

                if (aurApp->GetFlags() & AFLAG_SCALABLE)
                {
                    for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                    {
                        if (AuraEffect const* eff = aurApp->GetBase()->GetEffect(i))
                            aura.Scales.push_back(eff->GetAmount());
                        else
                            aura.Scales.push_back(0);
                    }
                }
                partyMemberState.PetAuraList.push_back(aura);
            }
        }
    }

    SendPacket(partyMemberState.Write());
}

void WorldSession::HandleRequestPartyMemberStatsOpcode(WorldPackets::Party::RequestPartyMemberStats& requestPartyMemberStats)
{
    ObjectGuid guid = requestPartyMemberStats.Target;

    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    if (!player)
    {
        WorldPackets::Party::PartyMemberState partyMemberState;
        partyMemberState.MemberGuid = guid;
        partyMemberState.Status = MEMBER_STATUS_OFFLINE;
        SendPacket(partyMemberState.Write());
        return;
    }

    SendPartyMemberState(player);
}

void WorldSession::HandleRequestRaidInfoOpcode(WorldPackets::Party::RequestRaidInfo& packet)
{
    // every time the player checks the character screen
    _player->SendRaidInfo();
}

void WorldSession::HandleOptOutOfLootOpcode(WorldPacket& recvData)
{
    bool passOnLoot;
    recvData >> passOnLoot; // 1 always pass, 0 do not pass

    // ignore if player not loaded
    if (!GetPlayer())                                        // needed because STATUS_AUTHED
    {
        if (passOnLoot)
            TC_LOG_ERROR("network", "CMSG_OPT_OUT_OF_LOOT value<>0 for not-loaded character!");
        return;
    }

    GetPlayer()->SetPassOnGroupLoot(passOnLoot != 0);
}

void WorldSession::HandleRolePollBeginOpcode(WorldPacket& recvData)
{
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    if (recvData.empty())
    {
        if (!group->IsLeader(GetPlayer()->GetGUID()) && !group->IsAssistant(GetPlayer()->GetGUID()))
            return;

        ObjectGuid guid = GetPlayer()->GetGUID();

        WorldPacket data(SMSG_ROLE_POLL_INFORM, 8);
        data.WriteBit(guid[1]);
        data.WriteBit(guid[5]);
        data.WriteBit(guid[7]);
        data.WriteBit(guid[3]);
        data.WriteBit(guid[2]);
        data.WriteBit(guid[4]);
        data.WriteBit(guid[0]);
        data.WriteBit(guid[6]);
        data.WriteByteSeq(guid[4]);
        data.WriteByteSeq(guid[7]);
        data.WriteByteSeq(guid[0]);
        data.WriteByteSeq(guid[5]);
        data.WriteByteSeq(guid[1]);
        data.WriteByteSeq(guid[6]);
        data.WriteByteSeq(guid[2]);
        data.WriteByteSeq(guid[3]);

        GetPlayer()->GetGroup()->BroadcastPacket(&data, true);
    }
}
