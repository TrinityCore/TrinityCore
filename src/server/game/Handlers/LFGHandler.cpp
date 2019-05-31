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

#include "LFGMgr.h"
#include "Group.h"
#include "LFGPackets.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

void WorldSession::HandleLfgJoinOpcode(WorldPackets::LFG::LFGJoin& lfgJoin)
{
    if (!sLFGMgr->isOptionEnabled(lfg::LFG_OPTION_ENABLE_DUNGEON_FINDER | lfg::LFG_OPTION_ENABLE_RAID_BROWSER) ||
        (GetPlayer()->GetGroup() && GetPlayer()->GetGroup()->GetLeaderGUID() != GetPlayer()->GetGUID() &&
        (GetPlayer()->GetGroup()->GetMembersCount() == MAXGROUPSIZE || !GetPlayer()->GetGroup()->isLFGGroup())))
        return;

    if (!lfgJoin.Slots.size())
    {
        TC_LOG_DEBUG("lfg", "CMSG_LFG_JOIN %s no dungeons selected", GetPlayerInfo().c_str());
        return;
    }

    lfg::LfgDungeonSet newDungeons;
    for (uint32 slot : lfgJoin.Slots)
    {
        uint32 dungeonId = slot & 0x00FFFFFF;
        if (sLFGDungeonStore.LookupEntry(dungeonId))
            newDungeons.insert(dungeonId);
    }

    TC_LOG_DEBUG("lfg", "CMSG_LFG_JOIN %s roles: %u, Dungeons: %u", GetPlayerInfo().c_str(), lfgJoin.Roles, uint8(newDungeons.size()));

    sLFGMgr->JoinLfg(GetPlayer(), uint8(lfgJoin.Roles), newDungeons, lfgJoin.Comment);
}

void WorldSession::HandleLfgLeaveOpcode(WorldPackets::LFG::LFGLeave& lfgLeave)
{
    Group* group = GetPlayer()->GetGroup();

    TC_LOG_DEBUG("lfg", "CMSG_LFG_LEAVE %s in group: %u sent guid %s.",
        GetPlayerInfo().c_str(), group ? 1 : 0, lfgLeave.Ticket.RequesterGuid.ToString().c_str());

    // Check cheating - only leader can leave the queue
    if (!group || group->GetLeaderGUID() == lfgLeave.Ticket.RequesterGuid)
    {
        sLFGMgr->SetCallToArmsRewardEnligible(lfgLeave.Ticket.RequesterGuid, false);
        sLFGMgr->LeaveLfg(lfgLeave.Ticket.RequesterGuid);
    }
}

void WorldSession::HandleLfgProposalResultOpcode(WorldPackets::LFG::LFGProposalResponse& lfgProposalResponse)
{
    TC_LOG_DEBUG("lfg", "CMSG_LFG_PROPOSAL_RESULT %s proposal: %u accept: %u",
        GetPlayerInfo().c_str(), lfgProposalResponse.ProposalID, lfgProposalResponse.Accepted ? 1 : 0);
    sLFGMgr->UpdateProposal(lfgProposalResponse.ProposalID, GetPlayer()->GetGUID(), lfgProposalResponse.Accepted);
}

void WorldSession::HandleLfgSetRolesOpcode(WorldPackets::LFG::LFGSetRoles& lfgSetRoles)
{
    ObjectGuid guid = GetPlayer()->GetGUID();
    Group* group = GetPlayer()->GetGroup();
    if (!group)
    {
        TC_LOG_DEBUG("lfg", "CMSG_LFG_SET_ROLES %s Not in group",
            GetPlayerInfo().c_str());
        return;
    }
    ObjectGuid gguid = group->GetGUID();
    TC_LOG_DEBUG("lfg", "CMSG_LFG_SET_ROLES: Group %s, Player %s, Roles: %u",
        gguid.ToString().c_str(), GetPlayerInfo().c_str(), lfgSetRoles.RolesDesired);
    sLFGMgr->UpdateRoleCheck(gguid, guid, lfgSetRoles.RolesDesired);
}

void WorldSession::HandleLfgSetCommentOpcode(WorldPackets::LFG::LFGSetComment& lfgSetComment)
{
    TC_LOG_DEBUG("lfg", "CMSG_LFG_SET_COMMENT %s comment: %s",
        GetPlayerInfo().c_str(), lfgSetComment.Comment.c_str());

    sLFGMgr->SetComment(GetPlayer()->GetGUID(), lfgSetComment.Comment);
}

void WorldSession::HandleLfgSetBootVoteOpcode(WorldPackets::LFG::LFGBootPlayerVote& lfgBootPlayerVote)
{
    ObjectGuid guid = GetPlayer()->GetGUID();
    TC_LOG_DEBUG("lfg", "CMSG_LFG_SET_BOOT_VOTE %s agree: %u",
        GetPlayerInfo().c_str(), lfgBootPlayerVote.Vote ? 1 : 0);
    sLFGMgr->UpdateBoot(guid, lfgBootPlayerVote.Vote);
}

void WorldSession::HandleLfgTeleportOpcode(WorldPackets::LFG::LFGTeleport& lfgTeleport)
{
    TC_LOG_DEBUG("lfg", "CMSG_LFG_TELEPORT %s out: %u",
        GetPlayerInfo().c_str(), lfgTeleport.TeleportOut ? 1 : 0);
    sLFGMgr->TeleportPlayer(GetPlayer(), lfgTeleport.TeleportOut, true);
}

void WorldSession::HandleLfgGetLockInfoOpcode(WorldPackets::LFG::LFGGetSystemInfo& lfgGetSystemInfo)
{
    TC_LOG_DEBUG("lfg", "CMSG_LFG_LOCK_INFO_REQUEST %s for %s", GetPlayerInfo().c_str(), (lfgGetSystemInfo.Player ? "player" : "party"));

    if (lfgGetSystemInfo.Player)
        SendLfgPlayerLockInfo();
    else
        SendLfgPartyLockInfo();
}

void WorldSession::SendLfgPlayerLockInfo()
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_PLAYER_INFO %s", GetPlayerInfo().c_str());

    // Get Random dungeons that can be done at a certain level and expansion
    uint8 level = _player->getLevel();
    lfg::LfgDungeonSet const& randomDungeons = sLFGMgr->GetRandomAndSeasonalDungeons(level, _player->GetSession()->Expansion());

    WorldPackets::LFG::LFGPlayerInfo lfgPlayerInfo;

    // Get player locked Dungeons
    for (auto const& lock : sLFGMgr->GetLockedDungeons(_player->GetGUID()))
        lfgPlayerInfo.BlackList.Slot.emplace_back(lock.first, lock.second.lockStatus, lock.second.requiredItemLevel, lock.second.currentItemLevel);

    for (uint32 slot : randomDungeons)
    {
        lfgPlayerInfo.Dungeon.emplace_back();
        WorldPackets::LFG::LfgPlayerDungeonInfo& playerDungeonInfo = lfgPlayerInfo.Dungeon.back();
        playerDungeonInfo.Slot = slot;

        bool firstReward = false;
        Quest const* currentQuest = nullptr;

        if (lfg::LfgReward const* reward = sLFGMgr->GetRandomDungeonReward(slot, level))
        {
            if (Quest const* firstQuest = sObjectMgr->GetQuestTemplate(reward->firstQuest))
            {
                firstReward = _player->CanRewardQuest(firstQuest, false);
                if (reward->completionsPerPeriod)
                    firstReward = _player->SatisfyFirstLFGReward(slot & 0x00FFFFFF, reward->completionsPerPeriod);

                if (firstReward)
                    currentQuest = firstQuest;
            }

            if (Quest const* otherQuest = sObjectMgr->GetQuestTemplate(reward->otherQuest))
                if (!firstReward)
                    currentQuest = otherQuest;

            if (firstReward && reward->completionsPerPeriod)
            {
                playerDungeonInfo.CompletionQuantity = 1;
                playerDungeonInfo.CompletionLimit = reward->completionsPerPeriod;
                playerDungeonInfo.SpecificLimit = reward->completionsPerPeriod;
                playerDungeonInfo.OverallQuantity = _player->GetFirstRewardCountForDungeonId(slot & 0x00FFFFFF);
                playerDungeonInfo.OverallLimit = reward->completionsPerPeriod;
                playerDungeonInfo.Quantity = 1;
            }
        }

        if (currentQuest)
        {
            playerDungeonInfo.Rewards.RewardMoney = _player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) ? currentQuest->GetRewOrReqMoney() : currentQuest->GetRewMoneyMaxLevel();
            playerDungeonInfo.Rewards.RewardXP = _player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) ? currentQuest->XPValue(_player) : 0;
            for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
                if (uint32 itemId = currentQuest->RewardItemId[i])
                    playerDungeonInfo.Rewards.Item.emplace_back(itemId, currentQuest->RewardItemIdCount[i]);

            for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
                if (uint32 currencyId = currentQuest->RewardCurrencyId[i])
                    if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(currencyId))
                    {
                        if (currency->Flags & CURRENCY_FLAG_HIGH_PRECISION)
                            playerDungeonInfo.Rewards.Currency.emplace_back(currencyId, currentQuest->RewardCurrencyCount[i] * CURRENCY_PRECISION);
                        else
                            playerDungeonInfo.Rewards.Currency.emplace_back(currencyId, currentQuest->RewardCurrencyCount[i]);
                    }
        }

        for (auto itr : playerDungeonInfo.Rewards.Currency)
        {
            if (itr.CurrencyID == CURRENCY_TYPE_VALOR_POINTS)
            {
                CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(CURRENCY_TYPE_VALOR_POINTS);
                if (!currency)
                    continue;

                uint32 weeklyCap = _player->GetCurrencyWeekCap(currency);
                playerDungeonInfo.CompletionQuantity += itr.Quantity;
                playerDungeonInfo.CompletionLimit = weeklyCap;
                playerDungeonInfo.CompletionCurrencyID = itr.CurrencyID;
                playerDungeonInfo.SpecificLimit = weeklyCap;
                playerDungeonInfo.OverallLimit = weeklyCap;
                playerDungeonInfo.PurseWeeklyQuantity = _player->GetCurrencyOnWeek(CURRENCY_TYPE_VALOR_POINTS, false);
                playerDungeonInfo.PurseWeeklyLimit = weeklyCap;
                playerDungeonInfo.PurseQuantity = _player->GetCurrency(CURRENCY_TYPE_VALOR_POINTS, false);
                playerDungeonInfo.Quantity += itr.Quantity;
            }
        }
    }

    SendPacket(lfgPlayerInfo.Write());
}

void WorldSession::SendLfgPartyLockInfo()
{
    ObjectGuid guid = GetPlayer()->GetGUID();
    Group* group = GetPlayer()->GetGroup();
    if (!group)
        return;

    WorldPackets::LFG::LFGPartyInfo lfgPartyInfo;

    // Get the locked dungeons of the other party members
    for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
    {
        Player* plrg = itr->GetSource();
        if (!plrg)
            continue;

        ObjectGuid pguid = plrg->GetGUID();
        if (pguid == guid)
            continue;

        lfgPartyInfo.Player.emplace_back();
        WorldPackets::LFG::LFGBlackList& lfgBlackList = lfgPartyInfo.Player.back();
        lfgBlackList.PlayerGuid = pguid;
        for (auto const& lock : sLFGMgr->GetLockedDungeons(pguid))
            lfgBlackList.Slot.emplace_back(lock.first, lock.second.lockStatus, lock.second.requiredItemLevel, lock.second.currentItemLevel);
    }

    TC_LOG_DEBUG("lfg", "SMSG_LFG_PARTY_INFO %s", GetPlayerInfo().c_str());
    SendPacket(lfgPartyInfo.Write());
}

void WorldSession::HandleLfrJoinOpcode(WorldPacket& recvData)
{
    uint32 entry;                                          // Raid id to search
    recvData >> entry;
    TC_LOG_DEBUG("lfg", "CMSG_LFG_LFR_JOIN %s dungeon entry: %u",
        GetPlayerInfo().c_str(), entry);
    //SendLfrUpdateListOpcode(entry);
}

void WorldSession::HandleLfrLeaveOpcode(WorldPacket& recvData)
{
    uint32 dungeonId;                                      // Raid id queue to leave
    recvData >> dungeonId;
    TC_LOG_DEBUG("lfg", "CMSG_LFG_LFR_LEAVE %s dungeonId: %u",
        GetPlayerInfo().c_str(), dungeonId);
    //sLFGMgr->LeaveLfr(GetPlayer(), dungeonId);
}

void WorldSession::HandleLfgGetStatus(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("lfg", "CMSG_LFG_GET_STATUS %s", GetPlayerInfo().c_str());

    if (!GetPlayer()->isUsingLfg())
        return;

    ObjectGuid guid = GetPlayer()->GetGUID();
    lfg::LfgUpdateData updateData = sLFGMgr->GetLfgStatus(guid);

    if (GetPlayer()->GetGroup())
    {
        SendLfgUpdateStatus(updateData, true);
        updateData.dungeons.clear();
        SendLfgUpdateStatus(updateData, false);
    }
    else
    {
        SendLfgUpdateStatus(updateData, false);
        updateData.dungeons.clear();
        SendLfgUpdateStatus(updateData, true);
    }
}

void WorldSession::SendLfgUpdateStatus(lfg::LfgUpdateData const& updateData, bool party)
{
    bool join = false;
    bool queued = false;
    ObjectGuid guid = _player->GetGUID();

    switch (updateData.updateType)
    {
        case lfg::LFG_UPDATETYPE_JOIN_QUEUE_INITIAL:            // Joined queue outside the dungeon
            join = true;
            break;
        case lfg::LFG_UPDATETYPE_JOIN_QUEUE:
        case lfg::LFG_UPDATETYPE_ADDED_TO_QUEUE:                // Rolecheck Success
            join = true;
            queued = true;
            break;
        case lfg::LFG_UPDATETYPE_JOIN_RAIDBROWSER:
            join = true;
            break;
        case lfg::LFG_UPDATETYPE_PROPOSAL_BEGIN:
            join = true;
            break;
        case lfg::LFG_UPDATETYPE_UPDATE_STATUS:
            join = updateData.state != lfg::LFG_STATE_ROLECHECK && updateData.state != lfg::LFG_STATE_NONE;
            queued = updateData.state == lfg::LFG_STATE_QUEUED || updateData.state == lfg::LFG_STATE_RAIDBROWSER;
            break;
        default:
            break;
    }

    TC_LOG_DEBUG("lfg", "SMSG_LFG_UPDATE_STATUS %s updatetype: %u, party %s",
        GetPlayerInfo().c_str(), updateData.updateType, party ? "true" : "false");

    WorldPackets::LFG::LFGUpdateStatus lfgUpdateStatus;
    if (WorldPackets::LFG::RideTicket const* ticket = sLFGMgr->GetTicket(guid))
        lfgUpdateStatus.Ticket = *ticket;

    lfgUpdateStatus.Reason = updateData.updateType;
    std::transform(updateData.dungeons.begin(), updateData.dungeons.end(), std::back_inserter(lfgUpdateStatus.Slots), [](uint32 dungeonId)
    {
        return sLFGMgr->GetLFGDungeonEntry(dungeonId);
    });
    lfgUpdateStatus.RequestedRoles = sLFGMgr->GetRoles(_player->GetGUID());
    //lfgUpdateStatus.SuspendedPlayers;
    lfgUpdateStatus.IsParty = party;
    lfgUpdateStatus.Joined = join;
    lfgUpdateStatus.LfgJoined = updateData.updateType != lfg::LFG_UPDATETYPE_REMOVED_FROM_QUEUE;
    lfgUpdateStatus.Queued = queued;
    lfgUpdateStatus.Comment = updateData.comment;

    SendPacket(lfgUpdateStatus.Write());
}

void WorldSession::SendLfgRoleChosen(ObjectGuid guid, uint8 roles)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_ROLE_CHOSEN %s guid: %s roles: %u",
        GetPlayerInfo().c_str(), guid.ToString().c_str(), roles);

    WorldPacket data(SMSG_LFG_ROLE_CHOSEN, 8 + 1 + 4);
    data << uint64(guid);                                  // Guid
    data << uint8(roles > 0);                              // Ready
    data << uint32(roles);                                 // Roles
    SendPacket(&data);
}

void WorldSession::SendLfgRoleCheckUpdate(lfg::LfgRoleCheck const& roleCheck)
{
    lfg::LfgDungeonSet dungeons;
    if (roleCheck.rDungeonId)
        dungeons.insert(roleCheck.rDungeonId);
    else
        dungeons = roleCheck.dungeons;

    TC_LOG_DEBUG("lfg", "SMSG_LFG_ROLE_CHECK_UPDATE %s", GetPlayerInfo().c_str());
    WorldPacket data(SMSG_LFG_ROLE_CHECK_UPDATE, 4 + 1 + 1 + dungeons.size() * 4 + 1 + roleCheck.roles.size() * (8 + 1 + 4 + 1));

    data << uint32(roleCheck.state);                       // Check result
    data << uint8(roleCheck.state == lfg::LFG_ROLECHECK_INITIALITING);
    data << uint8(dungeons.size());                        // Number of dungeons
    if (!dungeons.empty())
        for (lfg::LfgDungeonSet::iterator it = dungeons.begin(); it != dungeons.end(); ++it)
            data << uint32(sLFGMgr->GetLFGDungeonEntry(*it)); // Dungeon

    data << uint8(roleCheck.roles.size());                 // Players in group
    if (!roleCheck.roles.empty())
    {
        // Leader info MUST be sent 1st :S
        ObjectGuid guid = roleCheck.leader;
        uint8 roles = roleCheck.roles.find(guid)->second;
        Player* player = ObjectAccessor::FindConnectedPlayer(guid);
        data << uint64(guid);                              // Guid
        data << uint8(roles > 0);                          // Ready
        data << uint32(roles);                             // Roles
        data << uint8(player ? player->getLevel() : 0);    // Level

        for (lfg::LfgRolesMap::const_iterator it = roleCheck.roles.begin(); it != roleCheck.roles.end(); ++it)
        {
            if (it->first == roleCheck.leader)
                continue;

            guid = it->first;
            roles = it->second;
            player = ObjectAccessor::FindConnectedPlayer(guid);
            data << uint64(guid);                          // Guid
            data << uint8(roles > 0);                      // Ready
            data << uint32(roles);                         // Roles
            data << uint8(player ? player->getLevel() : 0);// Level
        }
    }
    SendPacket(&data);
}

void WorldSession::SendLfgJoinResult(lfg::LfgJoinResultData const& joinData)
{
    uint32 size = 0;
    ObjectGuid guid = GetPlayer()->GetGUID();
    uint32 queueId = sLFGMgr->GetQueueId(_player->GetGUID());
    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
        size += 8 + 4 + uint32(it->second.size()) * (4 + 4 + 4 + 4);

    TC_LOG_DEBUG("lfg", "SMSG_LFG_JOIN_RESULT %s checkResult: %u checkValue: %u",
        GetPlayerInfo().c_str(), joinData.result, joinData.state);

    WorldPacket data(SMSG_LFG_JOIN_RESULT, 4 + 4 + size);
    data << uint32(3);
    data << uint8(joinData.result);                        // Check Result
    data << uint32(queueId);                               // Queue Id
    data << uint8(joinData.state);                         // Check Value
    data << uint32(time(nullptr));                            // Join date
    data.WriteBit(guid[2]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[0]);
    data.WriteBits(joinData.lockmap.size(), 24);
    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
    {
        ObjectGuid playerGuid = it->first;
        data.WriteBit(playerGuid[7]);
        data.WriteBit(playerGuid[5]);
        data.WriteBit(playerGuid[3]);
        data.WriteBit(playerGuid[6]);
        data.WriteBit(playerGuid[0]);
        data.WriteBit(playerGuid[2]);
        data.WriteBit(playerGuid[4]);
        data.WriteBit(playerGuid[1]);
        data.WriteBits(it->second.size(), 22);
    }

    data.WriteBit(guid[4]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[6]);
    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
    {
        ObjectGuid playerGuid = it->first;
        for (lfg::LfgLockMap::const_iterator itr = it->second.begin(); itr != it->second.end(); ++itr)
        {
            TC_LOG_TRACE("lfg", "SendLfgJoinResult:: PlayerGUID: " UI64FMTD " DungeonID: %u Lock status: %u Required itemLevel: %u Current itemLevel: %f",
                uint64(playerGuid), (itr->first & 0x00FFFFFF), itr->second.lockStatus, itr->second.requiredItemLevel, itr->second.currentItemLevel);

            data << uint32(itr->second.lockStatus);             // Lock status
            data << uint32(itr->second.currentItemLevel);       // Current itemLevel
            data << uint32(itr->second.requiredItemLevel);      // Required itemLevel
            data << uint32(itr->first);                         // Dungeon entry (id + type)
        }

        data.WriteByteSeq(playerGuid[2]);
        data.WriteByteSeq(playerGuid[5]);
        data.WriteByteSeq(playerGuid[1]);
        data.WriteByteSeq(playerGuid[0]);
        data.WriteByteSeq(playerGuid[4]);
        data.WriteByteSeq(playerGuid[3]);
        data.WriteByteSeq(playerGuid[6]);
        data.WriteByteSeq(playerGuid[7]);
    }

    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[3]);
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[0]);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[2]);
    data.WriteByteSeq(guid[6]);

    SendPacket(&data);
}

void WorldSession::SendLfgQueueStatus(lfg::LfgQueueStatusData const& queueData)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_QUEUE_STATUS %s state: %s, dungeon: %u, waitTime: %d, "
        "avgWaitTime: %d, waitTimeTanks: %d, waitTimeHealer: %d, waitTimeDps: %d, "
        "queuedTime: %u, tanks: %u, healers: %u, dps: %u",
        GetPlayerInfo().c_str(), lfg::GetStateString(sLFGMgr->GetState(GetPlayer()->GetGUID())).c_str(), queueData.dungeonId, queueData.waitTime, queueData.waitTimeAvg,
        queueData.waitTimeTank, queueData.waitTimeHealer, queueData.waitTimeDps,
        queueData.queuedTime, queueData.tanks, queueData.healers, queueData.dps);

    ObjectGuid guid = _player->GetGUID();
    WorldPacket data(SMSG_LFG_QUEUE_STATUS, 4 + 4 + 4 + 4 + 4 + 4 + 1 + 1 + 1 + 4 + 4 + 4 + 4 + 8);
    data.WriteBit(guid[3]);
    data.WriteBit(guid[0]);
    data.WriteBit(guid[2]);
    data.WriteBit(guid[6]);
    data.WriteBit(guid[5]);
    data.WriteBit(guid[7]);
    data.WriteBit(guid[1]);
    data.WriteBit(guid[4]);

    data.WriteByteSeq(guid[0]);
    data << uint8(queueData.tanks);                        // Tanks needed
    data << int32(queueData.waitTimeTank);                 // Wait Tanks
    data << uint8(queueData.healers);                      // Healers needed
    data << int32(queueData.waitTimeHealer);               // Wait Healers
    data << uint8(queueData.dps);                          // Dps needed
    data << int32(queueData.waitTimeDps);                  // Wait Dps
    data.WriteByteSeq(guid[4]);
    data.WriteByteSeq(guid[6]);
    data << int32(queueData.waitTime);                     // Wait Time
    data << uint32(0);                    // Join time
    data << uint32(queueData.dungeonId);                   // Dungeon
    data << uint32(queueData.queuedTime);                  // Player wait time in queue
    data.WriteByteSeq(guid[5]);
    data.WriteByteSeq(guid[7]);
    data.WriteByteSeq(guid[3]);
    data << uint32(queueData.queueId);                     // Queue Id
    data.WriteByteSeq(guid[1]);
    data.WriteByteSeq(guid[2]);
    data << int32(queueData.waitTimeAvg);                  // Average Wait time
    data << uint32(3);

    SendPacket(&data);
}

void WorldSession::SendLfgPlayerReward(lfg::LfgPlayerRewardData const& rewardData)
{
    if (!rewardData.rdungeonEntry || !rewardData.sdungeonEntry || !rewardData.quest)
        return;

    TC_LOG_DEBUG("lfg", "SMSG_LFG_PLAYER_REWARD %s rdungeonEntry: %u, sdungeonEntry: %u, done: %u",
        GetPlayerInfo().c_str(), rewardData.rdungeonEntry, rewardData.sdungeonEntry, rewardData.done);

    uint8 itemNum = rewardData.quest->GetRewItemsCount() + rewardData.quest->GetRewCurrencyCount();
    if (rewardData.callToArmsQuest)
        itemNum += rewardData.callToArmsQuest->GetRewItemsCount() + rewardData.callToArmsQuest->GetRewCurrencyCount();

    WorldPacket data(SMSG_LFG_PLAYER_REWARD, 4 + 4 + 1 + 4 + 4 + 4 + 4 + 4 + 1 + itemNum * (4 + 4 + 4));
    data << uint32(rewardData.rdungeonEntry);                               // Random Dungeon Finished
    data << uint32(rewardData.sdungeonEntry);                               // Dungeon Finished
    //BuildQuestReward(data, rewardData.quest, rewardData.callToArmsQuest,GetPlayer());
    SendPacket(&data);
}

void WorldSession::SendLfgBootProposalUpdate(lfg::LfgPlayerBoot const& boot)
{
    ObjectGuid guid = GetPlayer()->GetGUID();
    lfg::LfgAnswer playerVote = boot.votes.find(guid)->second;
    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    uint32 secsleft = uint8((boot.cancelTime - time(nullptr)) / 1000);
    for (lfg::LfgAnswerContainer::const_iterator it = boot.votes.begin(); it != boot.votes.end(); ++it)
    {
        if (it->second != lfg::LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (it->second == lfg::LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }
    TC_LOG_DEBUG("lfg", "SMSG_LFG_BOOT_PROPOSAL_UPDATE %s inProgress: %u - "
        "didVote: %u - agree: %u - victim: %s votes: %u - agrees: %u - left: %u - "
        "needed: %u - reason %s",
        GetPlayerInfo().c_str(), uint8(boot.inProgress), uint8(playerVote != lfg::LFG_ANSWER_PENDING),
        uint8(playerVote == lfg::LFG_ANSWER_AGREE), boot.victim.ToString().c_str(), votesNum, agreeNum,
        secsleft, lfg::LFG_GROUP_KICK_VOTES_NEEDED, boot.reason.c_str());
    WorldPacket data(SMSG_LFG_BOOT_PROPOSAL_UPDATE, 1 + 1 + 1 + 1 + 8 + 4 + 4 + 4 + 4 + boot.reason.length());
    data << uint8(boot.inProgress);                                 // Vote in progress
    data << uint8(agreeNum >= lfg::LFG_GROUP_KICK_VOTES_NEEDED);    // Did succeed
    data << uint8(playerVote != lfg::LFG_ANSWER_PENDING);           // Did Vote
    data << uint8(playerVote == lfg::LFG_ANSWER_AGREE);             // Agree
    data << uint64(boot.victim);                                    // Victim GUID
    data << uint32(votesNum);                                       // Total Votes
    data << uint32(agreeNum);                                       // Agree Count
    data << uint32(secsleft);                                       // Time Left
    data << uint32(lfg::LFG_GROUP_KICK_VOTES_NEEDED);               // Needed Votes
    data << boot.reason.c_str();                                    // Kick reason
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateProposal(lfg::LfgProposal const& proposal)
{
    ObjectGuid guid = GetPlayer()->GetGUID();
    ObjectGuid gguid = proposal.players.find(guid)->second.group;
    bool silent = !proposal.isNew && gguid == proposal.group;
    uint32 dungeonEntry = proposal.dungeonId;
    uint32 queueId = sLFGMgr->GetQueueId(_player->GetGUID());
    time_t joinTime = sLFGMgr->GetQueueJoinTime(_player->GetGUID());

    TC_LOG_DEBUG("lfg", "SMSG_LFG_PROPOSAL_UPDATE %s state: %u",
        GetPlayerInfo().c_str(), proposal.state);

    // show random dungeon if player selected random dungeon and it's not lfg group
    if (!silent)
    {
        lfg::LfgDungeonSet const& playerDungeons = sLFGMgr->GetSelectedDungeons(guid);
        if (playerDungeons.find(proposal.dungeonId) == playerDungeons.end())
            dungeonEntry = (*playerDungeons.begin());
    }

    dungeonEntry = sLFGMgr->GetLFGDungeonEntry(dungeonEntry);

    WorldPacket data(SMSG_LFG_PROPOSAL_UPDATE, 4 + 1 + 4 + 4 + 1 + 1 + proposal.players.size() * (4 + 1 + 1 + 1 + 1 +1));
    data << uint32(joinTime);
    data << uint32(proposal.encounters);                   // Encounters done
    data << uint32(queueId);                               // Queue Id
    data << uint32(3);                                     // Always 3
    data << uint32(dungeonEntry);                          // Dungeon
    data << uint32(proposal.id);                           // Proposal Id
    data << uint8(proposal.state);                         // State

    ObjectGuid guid1 = guid;
    ObjectGuid guid2 = gguid;

    data.WriteBit(guid2[4]);
    data.WriteBit(guid1[3]);
    data.WriteBit(guid1[7]);
    data.WriteBit(guid1[0]);
    data.WriteBit(guid2[1]);
    data.WriteBit(silent);
    data.WriteBit(guid1[4]);
    data.WriteBit(guid1[5]);
    data.WriteBit(guid2[3]);
    data.WriteBits(proposal.players.size(), 23);
    data.WriteBit(guid2[7]);

    for (lfg::LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        lfg::LfgProposalPlayer const& player = it->second;

        if (!player.group)
        {
            data.WriteBit(0);
            data.WriteBit(0);
        }
        else
        {
            data.WriteBit(player.group == proposal.group);      // Is group in dungeon
            data.WriteBit(player.group == gguid);               // Same group as the player
        }

        data.WriteBit(player.accept == lfg::LFG_ANSWER_AGREE);
        data.WriteBit(player.accept != lfg::LFG_ANSWER_PENDING);
        data.WriteBit(it->first == guid);
    }

    data.WriteBit(guid2[5]);
    data.WriteBit(guid1[6]);
    data.WriteBit(guid2[2]);
    data.WriteBit(guid2[6]);
    data.WriteBit(guid1[2]);
    data.WriteBit(guid1[1]);
    data.WriteBit(guid2[0]);

    data.WriteByteSeq(guid1[5]);
    data.WriteByteSeq(guid2[3]);
    data.WriteByteSeq(guid2[6]);
    data.WriteByteSeq(guid1[6]);
    data.WriteByteSeq(guid1[0]);
    data.WriteByteSeq(guid2[5]);
    data.WriteByteSeq(guid1[1]);

    for (lfg::LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        lfg::LfgProposalPlayer const& player = it->second;
        data << uint32(player.role);
    }

    data.WriteByteSeq(guid2[7]);
    data.WriteByteSeq(guid1[4]);
    data.WriteByteSeq(guid2[0]);
    data.WriteByteSeq(guid2[1]);
    data.WriteByteSeq(guid1[2]);
    data.WriteByteSeq(guid1[7]);
    data.WriteByteSeq(guid2[2]);
    data.WriteByteSeq(guid1[3]);
    data.WriteByteSeq(guid2[4]);

    SendPacket(&data);
}

void WorldSession::SendLfgLfrList(bool update)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_LFR_LIST %s update: %u",
        GetPlayerInfo().c_str(), update ? 1 : 0);
    WorldPacket data(SMSG_LFG_UPDATE_SEARCH, 1);
    data << uint8(update);                                 // In Lfg Queue?
    SendPacket(&data);
}

void WorldSession::SendLfgDisabled()
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_DISABLED %s", GetPlayerInfo().c_str());
    WorldPacket data(SMSG_LFG_DISABLED, 0);
    SendPacket(&data);
}

void WorldSession::SendLfgOfferContinue(uint32 dungeonEntry)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_OFFER_CONTINUE %s dungeon entry: %u",
        GetPlayerInfo().c_str(), dungeonEntry);
    WorldPacket data(SMSG_LFG_OFFER_CONTINUE, 4);
    data << uint32(dungeonEntry);
    SendPacket(&data);
}

void WorldSession::SendLfgTeleportError(uint8 err)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_TELEPORT_DENIED %s reason: %u",
        GetPlayerInfo().c_str(), err);
    WorldPacket data(SMSG_LFG_TELEPORT_DENIED, 4);
    data << uint32(err);                                   // Error
    SendPacket(&data);
}

/*
void WorldSession::SendLfrUpdateListOpcode(uint32 dungeonEntry)
{
    TC_LOG_DEBUG("network", "SMSG_LFG_UPDATE_LIST %s dungeon entry: %u",
        GetPlayerInfo().c_str(), dungeonEntry);
    WorldPacket data(SMSG_LFG_UPDATE_LIST);
    SendPacket(&data);
}
*/
