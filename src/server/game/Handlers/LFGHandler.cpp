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

#include "DBCStores.h"
#include "GameTime.h"
#include "Group.h"
#include "LFGMgr.h"
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
        sLFGMgr->LeaveLfg(lfgLeave.Ticket.RequesterGuid);
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

    // Role validation
    if (!sLFGMgr->CanPerformSelectedRoles(GetPlayer()->getClass(), lfgSetRoles.RolesDesired))
        lfgSetRoles.RolesDesired = 0;

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
    lfg::LfgDungeonSet const& randomDungeons = sLFGMgr->GetRandomAndSeasonalDungeons(level, GetExpansion());

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
        Quest const* shortageQuest = nullptr;

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

            if (!_player->GetGroup())
            {
                if (LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(slot & 0x00FFFFFF))
                {
                    if (uint32 roleMask = sLFGMgr->GetShortageRoleMask(dungeon->ID))
                    {
                        shortageQuest = sObjectMgr->GetQuestTemplate(reward->shortageQuest);
                        playerDungeonInfo.ShortageRoleMask = roleMask;
                    }
                }
            }
        }

        if (currentQuest)
        {
            playerDungeonInfo.Rewards.RewardMoney = currentQuest->GetRewOrReqMoney(_player);
            playerDungeonInfo.Rewards.RewardXP = _player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) ? currentQuest->GetXPReward(_player) : 0;
            for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
                if (uint32 itemId = currentQuest->RewardItemId[i])
                    playerDungeonInfo.Rewards.Item.emplace_back(itemId, currentQuest->RewardItemIdCount[i]);

            for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
                if (uint32 currencyId = currentQuest->RewardCurrencyId[i])
                    if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(currencyId))
                    {
                        if (currency->GetFlags().HasFlag(CurrencyTypeFlags::Uses1To100ScalarForDisplay))
                            playerDungeonInfo.Rewards.Currency.emplace_back(currencyId, currentQuest->RewardCurrencyCount[i] * CURRENCY_PRECISION);
                        else
                            playerDungeonInfo.Rewards.Currency.emplace_back(currencyId, currentQuest->RewardCurrencyCount[i]);
                    }
        }

        if (shortageQuest)
        {
            playerDungeonInfo.ShortageEligible = true;
            playerDungeonInfo.ShortageReward.RewardMoney = shortageQuest->GetRewOrReqMoney(_player);;
            playerDungeonInfo.ShortageReward.RewardXP = _player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) ? shortageQuest->GetXPReward(_player) : 0;
            for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
                if (uint32 itemId = shortageQuest->RewardItemId[i])
                    playerDungeonInfo.ShortageReward.Item.emplace_back(itemId, shortageQuest->RewardItemIdCount[i]);

            for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
                if (uint32 currencyId = shortageQuest->RewardCurrencyId[i])
                    if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(currencyId))
                    {
                        if (currency->GetFlags().HasFlag(CurrencyTypeFlags::Uses1To100ScalarForDisplay))
                            playerDungeonInfo.ShortageReward.Currency.emplace_back(currencyId, shortageQuest->RewardCurrencyCount[i] * CURRENCY_PRECISION);
                        else
                            playerDungeonInfo.ShortageReward.Currency.emplace_back(currencyId, shortageQuest->RewardCurrencyCount[i]);
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
        case lfg::LFG_UPDATETYPE_PROPOSAL_BEGIN:
            join = true;
            break;
        case lfg::LFG_UPDATETYPE_UPDATE_STATUS:
            join = updateData.state != lfg::LFG_STATE_ROLECHECK && updateData.state != lfg::LFG_STATE_NONE &&
                updateData.state != lfg::LFG_STATE_DUNGEON && updateData.state != lfg::LFG_STATE_FINISHED_DUNGEON;
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

    WorldPackets::LFG::RoleChosen roleChosen;
    roleChosen.Player = guid;
    roleChosen.RoleMask = roles;
    roleChosen.Accepted = roles > 0;
    SendPacket(roleChosen.Write());
}

void WorldSession::SendLfgRoleCheckUpdate(lfg::LfgRoleCheck const& roleCheck)
{
    lfg::LfgDungeonSet dungeons;
    if (roleCheck.rDungeonId)
        dungeons.insert(roleCheck.rDungeonId);
    else
        dungeons = roleCheck.dungeons;

    TC_LOG_DEBUG("lfg", "SMSG_LFG_ROLE_CHECK_UPDATE %s", GetPlayerInfo().c_str());
    WorldPackets::LFG::LFGRoleCheckUpdate lfgRoleCheckUpdate;
    lfgRoleCheckUpdate.RoleCheckStatus = roleCheck.state;
    std::transform(dungeons.begin(), dungeons.end(), std::back_inserter(lfgRoleCheckUpdate.JoinSlots), [](uint32 dungeonId)
    {
        return sLFGMgr->GetLFGDungeonEntry(dungeonId);
    });
    if (!roleCheck.roles.empty())
    {
        // Leader info MUST be sent 1st :S
        uint8 roles = roleCheck.roles.find(roleCheck.leader)->second;
        lfgRoleCheckUpdate.Members.emplace_back(roleCheck.leader, roles, ASSERT_NOTNULL(ObjectAccessor::FindConnectedPlayer(roleCheck.leader))->getLevel(), roles > 0);

        for (lfg::LfgRolesMap::const_iterator it = roleCheck.roles.begin(); it != roleCheck.roles.end(); ++it)
        {
            if (it->first == roleCheck.leader)
                continue;

            roles = it->second;
            lfgRoleCheckUpdate.Members.emplace_back(it->first, roles, ASSERT_NOTNULL(ObjectAccessor::FindConnectedPlayer(roleCheck.leader))->getLevel(), roles > 0);
        }
    }

    SendPacket(lfgRoleCheckUpdate.Write());
}

void WorldSession::SendLfgJoinResult(lfg::LfgJoinResultData const& joinData)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_JOIN_RESULT %s checkResult: %u checkValue: %u",
        GetPlayerInfo().c_str(), joinData.result, joinData.state);

    WorldPackets::LFG::LFGJoinResult lfgJoinResult;
    if (WorldPackets::LFG::RideTicket const* ticket = sLFGMgr->GetTicket(GetPlayer()->GetGUID()))
        lfgJoinResult.Ticket = *ticket;
    lfgJoinResult.Result = joinData.result;
    if (joinData.result == lfg::LFG_JOIN_ROLE_CHECK_FAILED)
        lfgJoinResult.ResultDetail = joinData.state;

    for (lfg::LfgLockPartyMap::const_iterator it = joinData.lockmap.begin(); it != joinData.lockmap.end(); ++it)
    {
        lfgJoinResult.BlackList.emplace_back();
        WorldPackets::LFG::LFGJoinBlackList& blackList = lfgJoinResult.BlackList.back();
        blackList.Guid = it->first;

        for (lfg::LfgLockMap::const_iterator itr = it->second.begin(); itr != it->second.end(); ++itr)
        {
            TC_LOG_TRACE("lfg", "SendLfgJoinResult:: %s DungeonID: %u Lock status: %u Required itemLevel: %u Current itemLevel: %f",
                it->first.ToString().c_str(), (itr->first & 0x00FFFFFF), itr->second.lockStatus, itr->second.requiredItemLevel, itr->second.currentItemLevel);

            blackList.Slots.emplace_back(itr->first, itr->second.lockStatus, itr->second.requiredItemLevel, itr->second.currentItemLevel);
        }
    }

    SendPacket(lfgJoinResult.Write());
}

void WorldSession::SendLfgQueueStatus(lfg::LfgQueueStatusData const& queueData)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_QUEUE_STATUS %s state: %s, dungeon: %u, waitTime: %d, "
        "avgWaitTime: %d, waitTimeTanks: %d, waitTimeHealer: %d, waitTimeDps: %d, "
        "queuedTime: %u, tanks: %u, healers: %u, dps: %u",
        GetPlayerInfo().c_str(), lfg::GetStateString(sLFGMgr->GetState(GetPlayer()->GetGUID())).c_str(), queueData.dungeonId, queueData.waitTime, queueData.waitTimeAvg,
        queueData.waitTimeTank, queueData.waitTimeHealer, queueData.waitTimeDps,
        queueData.queuedTime, queueData.tanks, queueData.healers, queueData.dps);

    WorldPackets::LFG::LFGQueueStatus lfgQueueStatus;
    if (WorldPackets::LFG::RideTicket const* ticket = sLFGMgr->GetTicket(GetPlayer()->GetGUID()))
        lfgQueueStatus.Ticket = *ticket;
    lfgQueueStatus.Slot = sLFGMgr->GetLFGDungeonEntry(queueData.dungeonId);
    lfgQueueStatus.AvgWaitTimeMe = queueData.waitTime;
    lfgQueueStatus.AvgWaitTime = queueData.waitTimeAvg;
    lfgQueueStatus.AvgWaitTimeByRole[0] = queueData.waitTimeTank;
    lfgQueueStatus.AvgWaitTimeByRole[1] = queueData.waitTimeHealer;
    lfgQueueStatus.AvgWaitTimeByRole[2] = queueData.waitTimeDps;
    lfgQueueStatus.LastNeeded[0] = queueData.tanks;
    lfgQueueStatus.LastNeeded[1] = queueData.healers;
    lfgQueueStatus.LastNeeded[2] = queueData.dps;
    lfgQueueStatus.QueuedTime = queueData.queuedTime;
    SendPacket(lfgQueueStatus.Write());
}

void WorldSession::SendLfgPlayerReward(lfg::LfgPlayerRewardData const& rewardData)
{
    if (!rewardData.rdungeonEntry || !rewardData.sdungeonEntry || !rewardData.quest)
        return;

    TC_LOG_DEBUG("lfg", "SMSG_LFG_PLAYER_REWARD %s rdungeonEntry: %u, sdungeonEntry: %u, done: %u",
        GetPlayerInfo().c_str(), rewardData.rdungeonEntry, rewardData.sdungeonEntry, rewardData.done);

    WorldPackets::LFG::LFGPlayerReward lfgPlayerReward;
    lfgPlayerReward.QueuedSlot = rewardData.rdungeonEntry;
    lfgPlayerReward.ActualSlot = rewardData.sdungeonEntry;
    uint32 rewardMoney = rewardData.quest->GetRewOrReqMoney(_player);
    uint32 rewardExp = _player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) ? rewardData.quest->GetXPReward(_player) : 0;

    if (rewardData.shortageQuest)
    {
        rewardMoney += rewardData.shortageQuest->GetRewOrReqMoney(_player);
        rewardExp += _player->getLevel() < sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) ? rewardData.shortageQuest->GetXPReward(_player) : 0;
    }

    lfgPlayerReward.RewardMoney = rewardMoney;
    lfgPlayerReward.AddedXP = rewardExp;

    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        if (uint32 itemId = rewardData.quest->RewardItemId[i])
            lfgPlayerReward.Rewards.emplace_back(itemId, rewardData.quest->RewardItemIdCount[i], false);

    if (rewardData.shortageQuest)
    {
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
            if (uint32 itemId = rewardData.shortageQuest->RewardItemId[i])
                lfgPlayerReward.Rewards.emplace_back(itemId, rewardData.shortageQuest->RewardItemIdCount[i], false);
    }

    for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
        if (uint32 currencyId = rewardData.quest->RewardCurrencyId[i])
            if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(currencyId))
            {
                if (currency->GetFlags().HasFlag(CurrencyTypeFlags::Uses1To100ScalarForDisplay))
                    lfgPlayerReward.Rewards.emplace_back(currencyId, rewardData.quest->RewardCurrencyCount[i] * CURRENCY_PRECISION, true);
                else
                    lfgPlayerReward.Rewards.emplace_back(currencyId, rewardData.quest->RewardCurrencyCount[i], true);
            }


    if (rewardData.shortageQuest)
    {
        for (uint32 i = 0; i < QUEST_REWARD_CURRENCY_COUNT; ++i)
            if (uint32 currencyId = rewardData.shortageQuest->RewardCurrencyId[i])
                if (CurrencyTypesEntry const* currency = sCurrencyTypesStore.LookupEntry(currencyId))
                {
                    if (currency->GetFlags().HasFlag(CurrencyTypeFlags::Uses1To100ScalarForDisplay))
                        lfgPlayerReward.Rewards.emplace_back(currencyId, rewardData.shortageQuest->RewardCurrencyCount[i] * CURRENCY_PRECISION, true);
                    else
                        lfgPlayerReward.Rewards.emplace_back(currencyId, rewardData.shortageQuest->RewardCurrencyCount[i], true);
                }
    }

    SendPacket(lfgPlayerReward.Write());
}

void WorldSession::SendLfgBootProposalUpdate(lfg::LfgPlayerBoot const& boot)
{
    lfg::LfgAnswer playerVote = boot.votes.find(GetPlayer()->GetGUID())->second;
    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    int32 secsleft = int32((boot.cancelTime - GameTime::GetGameTime()) / 1000);
    for (const auto& vote : boot.votes)
    {
        if (vote.second != lfg::LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (vote.second == lfg::LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }
    TC_LOG_DEBUG("lfg", "SMSG_LFG_BOOT_PROPOSAL_UPDATE %s inProgress: %u - "
        "didVote: %u - agree: %u - victim: %s votes: %u - agrees: %u - left: %u - "
        "needed: %u - reason %s",
        GetPlayerInfo().c_str(), uint8(boot.inProgress), uint8(playerVote != lfg::LFG_ANSWER_PENDING),
        uint8(playerVote == lfg::LFG_ANSWER_AGREE), boot.victim.ToString().c_str(), votesNum, agreeNum,
        secsleft, lfg::LFG_GROUP_KICK_VOTES_NEEDED, boot.reason.c_str());

    WorldPackets::LFG::LfgBootPlayer lfgBootPlayer;
    lfgBootPlayer.Info.VoteInProgress = boot.inProgress;
    lfgBootPlayer.Info.VotePassed = agreeNum >= lfg::LFG_GROUP_KICK_VOTES_NEEDED;
    lfgBootPlayer.Info.MyVoteCompleted = playerVote != lfg::LFG_ANSWER_PENDING;
    lfgBootPlayer.Info.MyVote = playerVote == lfg::LFG_ANSWER_AGREE;
    lfgBootPlayer.Info.Target = boot.victim;
    lfgBootPlayer.Info.TotalVotes = votesNum;
    lfgBootPlayer.Info.BootVotes = agreeNum;
    lfgBootPlayer.Info.TimeLeft = secsleft;
    lfgBootPlayer.Info.VotesNeeded = lfg::LFG_GROUP_KICK_VOTES_NEEDED;
    lfgBootPlayer.Info.Reason = boot.reason;
    SendPacket(lfgBootPlayer.Write());
}

void WorldSession::SendLfgUpdateProposal(lfg::LfgProposal const& proposal)
{
    ObjectGuid guid = GetPlayer()->GetGUID();
    ObjectGuid gguid = proposal.players.find(guid)->second.group;
    bool silent = !proposal.isNew && gguid == proposal.group;
    uint32 dungeonEntry = proposal.dungeonId;

    TC_LOG_DEBUG("lfg", "SMSG_LFG_PROPOSAL_UPDATE %s state: %u",
        GetPlayerInfo().c_str(), proposal.state);

    // show random dungeon if player selected random dungeon and it's not lfg group
    if (!silent)
    {
        lfg::LfgDungeonSet const& playerDungeons = sLFGMgr->GetSelectedDungeons(guid);
        if (playerDungeons.find(proposal.dungeonId) == playerDungeons.end())
            dungeonEntry = (*playerDungeons.begin());
    }

    WorldPackets::LFG::LFGProposalUpdate lfgProposalUpdate;
    if (WorldPackets::LFG::RideTicket const* ticket = sLFGMgr->GetTicket(GetPlayer()->GetGUID()))
        lfgProposalUpdate.Ticket = *ticket;

    lfgProposalUpdate.InstanceID = 0;
    lfgProposalUpdate.ProposalID = proposal.id;
    lfgProposalUpdate.Slot = sLFGMgr->GetLFGDungeonEntry(dungeonEntry);
    lfgProposalUpdate.State = proposal.state;
    lfgProposalUpdate.CompletedMask = proposal.encounters;
    lfgProposalUpdate.ProposalSilent = silent;

    for (auto const& player : proposal.players)
    {
        lfgProposalUpdate.Players.emplace_back();
        auto& proposalPlayer = lfgProposalUpdate.Players.back();
        proposalPlayer.Roles = player.second.role;
        proposalPlayer.Me = player.first == guid;
        proposalPlayer.MyParty = !player.second.group.IsEmpty() && player.second.group == proposal.group;
        proposalPlayer.SameParty = !player.second.group.IsEmpty() && player.second.group == gguid;
        proposalPlayer.Responded = player.second.accept != lfg::LFG_ANSWER_PENDING;
        proposalPlayer.Accepted = player.second.accept == lfg::LFG_ANSWER_AGREE;
    }

    SendPacket(lfgProposalUpdate.Write());
}

void WorldSession::SendLfgLfrList(bool update)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_LFR_LIST %s update: %u",
        GetPlayerInfo().c_str(), update ? 1 : 0);
}

void WorldSession::SendLfgDisabled()
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_DISABLED %s", GetPlayerInfo().c_str());
    SendPacket(WorldPackets::LFG::LFGDisabled().Write());
}

void WorldSession::SendLfgOfferContinue(uint32 dungeonEntry)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_OFFER_CONTINUE %s dungeon entry: %u",
        GetPlayerInfo().c_str(), dungeonEntry);
    SendPacket(WorldPackets::LFG::LFGOfferContinue(sLFGMgr->GetLFGDungeonEntry(dungeonEntry)).Write());
}

void WorldSession::SendLfgTeleportError(lfg::LfgTeleportResult err)
{
    TC_LOG_DEBUG("lfg", "SMSG_LFG_TELEPORT_DENIED %s reason: %u",
        GetPlayerInfo().c_str(), err);
    SendPacket(WorldPackets::LFG::LFGTeleportDenied(err).Write());
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
