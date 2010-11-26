/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldSession.h"
#include "WorldPacket.h"
#include "Player.h"
#include "ObjectMgr.h"

void BuildPlayerLockDungeonBlock(WorldPacket &data, LfgLockStatusSet* lockSet)
{
    if (!lockSet || !lockSet->size())
    {
        data << uint8(0);
        return;
    }
    data << uint32(lockSet->size());                        // Size of lock dungeons
    for (LfgLockStatusSet::iterator it = lockSet->begin(); it != lockSet->end(); ++it)
    {
        data << uint32((*it)->dungeon);                     // Dungeon entry + type
        data << uint32((*it)->lockstatus);                  // Lock status
        delete (*it);
    }
    lockSet->clear();
    delete lockSet;
}

void BuildPartyLockDungeonBlock(WorldPacket &data, LfgLockStatusMap* lockMap)
{
    if (!lockMap || !lockMap->size())
    {
        data << uint8(0);
        return;
    }

    data << uint8(lockMap->size());
    for (LfgLockStatusMap::const_iterator it = lockMap->begin(); it != lockMap->end(); ++it)
    {
        data << uint64(MAKE_NEW_GUID(it->first, 0, HIGHGUID_PLAYER)); // Player guid
        BuildPlayerLockDungeonBlock(data, it->second);
    }
    lockMap->clear();
    delete lockMap;
}

void WorldSession::HandleLfgJoinOpcode(WorldPacket &recv_data)
{
    if (!sWorld.getBoolConfig(CONFIG_DUNGEON_FINDER_ENABLE) ||
        (GetPlayer()->GetGroup() && GetPlayer()->GetGroup()->GetLeaderGUID() != GetPlayer()->GetGUID()))
    {
        recv_data.rpos(recv_data.wpos());
        return;
    }

    uint8 numDungeons;
    uint32 dungeon;
    uint32 roles;
    std::string comment;
    LfgDungeonSet* newDungeons;

    recv_data >> roles;
    recv_data.read_skip<uint16>();                         // uint8 (always 0) - uint8 (always 0)
    recv_data >> numDungeons;
    if (!numDungeons)
    {
        sLog.outDebug("CMSG_LFG_JOIN [" UI64FMTD "] no dungeons selected", GetPlayer()->GetGUID());
        recv_data.rpos(recv_data.wpos());
        return;
    }

    newDungeons = new LfgDungeonSet();
    for (int8 i = 0 ; i < numDungeons; ++i)
    {
        recv_data >> dungeon;
        newDungeons->insert((dungeon & 0x00FFFFFF));       // remove the type from the dungeon entry
    }

    recv_data.read_skip<uint32>();                         // for 0..uint8 (always 3) { uint8 (always 0) }

    recv_data >> comment;
    sLog.outDebug("CMSG_LFG_JOIN [" UI64FMTD "] roles: %u, Dungeons: %u, Comment: %s", GetPlayer()->GetGUID(), roles, uint8(newDungeons->size()), comment.c_str());
    sLFGMgr.Join(GetPlayer(), uint8(roles), newDungeons, comment);
}

void WorldSession::HandleLfgLeaveOpcode(WorldPacket & /*recv_data*/)
{
    Group* grp = GetPlayer()->GetGroup();

    sLog.outDebug("CMSG_LFG_LEAVE [" UI64FMTD "] in group: %u", GetPlayer()->GetGUID(), grp ? 1 : 0);

    // Check cheating - only leader can leave the queue
    if (!grp || grp->GetLeaderGUID() == GetPlayer()->GetGUID())
        sLFGMgr.Leave(GetPlayer(), grp);
}

void WorldSession::HandleLfgProposalResultOpcode(WorldPacket &recv_data)
{
    uint32 lfgGroupID;                                      // Internal lfgGroupID
    bool accept;                                            // Accept to join?
    recv_data >> lfgGroupID;
    recv_data >> accept;

    sLog.outDebug("CMSG_LFG_PROPOSAL_RESULT [" UI64FMTD "] proposal: %u accept: %u", GetPlayer()->GetGUID(), lfgGroupID, accept ? 1 : 0);
    sLFGMgr.UpdateProposal(lfgGroupID, GetPlayer()->GetGUIDLow(), accept);
}

void WorldSession::HandleLfgSetRolesOpcode(WorldPacket &recv_data)
{
    uint8 roles;
    recv_data >> roles;                                     // Player Group Roles

    Group* grp = GetPlayer()->GetGroup();
    if (!grp)
    {
        sLog.outDebug("CMSG_LFG_SET_ROLES [" UI64FMTD "] Not in group", GetPlayer()->GetGUID());
        return;
    }
    else
        sLog.outDebug("CMSG_LFG_SET_ROLES [" UI64FMTD "] Roles: %u", GetPlayer()->GetGUID(), roles);

    GetPlayer()->SetLfgRoles(roles);
    sLFGMgr.UpdateRoleCheck(grp, GetPlayer());
}

void WorldSession::HandleSetLfgCommentOpcode(WorldPacket & recv_data)
{
    std::string comment;
    recv_data >> comment;

    sLog.outDebug("CMSG_SET_LFG_COMMENT [" UI64FMTD "] comment: %s", GetPlayer()->GetGUID(), comment.c_str());
    GetPlayer()->SetLfgComment(comment);
}

void WorldSession::HandleLfgSetBootVoteOpcode(WorldPacket &recv_data)
{
    bool agree;                                             // Agree to kick player
    recv_data >> agree;

    sLog.outDebug("CMSG_LFG_SET_BOOT_VOTE [" UI64FMTD "] agree: %u", GetPlayer()->GetGUID(), agree ? 1 : 0);
    sLFGMgr.UpdateBoot(GetPlayer(), agree);
}

void WorldSession::HandleLfgTeleportOpcode(WorldPacket &recv_data)
{
    bool out;
    recv_data >> out;

    sLog.outDebug("CMSG_LFG_TELEPORT [" UI64FMTD "] out: %u", GetPlayer()->GetGUID(), out ? 1 : 0);
    sLFGMgr.TeleportPlayer(GetPlayer(), out, true);
}

void WorldSession::HandleLfgPlayerLockInfoRequestOpcode(WorldPacket &/*recv_data*/)
{
    sLog.outDebug("CMSG_LFD_PLAYER_LOCK_INFO_REQUEST [" UI64FMTD "]", GetPlayer()->GetGUID());
    uint32 rsize = 0;
    uint32 lsize = 0;
    LfgDungeonSet* randomlist = sLFGMgr.GetRandomDungeons(GetPlayer()->getLevel(), GetPlayer()->GetSession()->Expansion());
    LfgLockStatusSet* lockSet = sLFGMgr.GetPlayerLockStatusDungeons(GetPlayer());

    if (randomlist)
        rsize = randomlist->size();

    if (lockSet)
        lsize = lockSet->size();

    sLog.outDebug("SMSG_LFG_PLAYER_INFO [" UI64FMTD "]", GetPlayer()->GetGUID());
    WorldPacket data(SMSG_LFG_PLAYER_INFO, 1 + rsize * (4 + 1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4) + 4 + lsize * (1 + 4 + 4 + 4 + 4 + 1 + 4 + 4 + 4));
    if (!randomlist)
        data << uint8(0);
    else
    {
        LfgReward const* reward = NULL;
        Quest const* qRew = NULL;
        uint8 done;

        data << uint8(randomlist->size());                  // Random Dungeon count
        for (LfgDungeonSet::iterator it = randomlist->begin(); it != randomlist->end(); ++it)
        {
            data << uint32(*it);                            // Entry
            reward = sLFGMgr.GetRandomDungeonReward(*it, GetPlayer()->getLevel());
            qRew = NULL;
            if (reward)
            {
                qRew = sObjectMgr.GetQuestTemplate(reward->reward[0].questId);
                if (qRew)
                {
                    done = !GetPlayer()->CanRewardQuest(qRew,false);
                    if (done)
                        qRew = sObjectMgr.GetQuestTemplate(reward->reward[1].questId);
                }

            }
            if (qRew)
            {
                data << uint8(done);
                data << uint32(qRew->GetRewOrReqMoney());
                data << uint32(qRew->XPValue(GetPlayer()));
                data << uint32(reward->reward[done].variableMoney);
                data << uint32(reward->reward[done].variableXP);
                data << uint8(qRew->GetRewItemsCount());
                if (qRew->GetRewItemsCount())
                {
                    ItemPrototype const* iProto = NULL;
                    for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
                    {
                        if (!qRew->RewItemId[i])
                            continue;

                        iProto = ObjectMgr::GetItemPrototype(qRew->RewItemId[i]);

                        data << uint32(qRew->RewItemId[i]);
                        data << uint32(iProto ? iProto->DisplayInfoID : 0);
                        data << uint32(qRew->RewItemCount[i]);
                    }
                }
            }
            else
            {
                data << uint8(0);
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
                data << uint32(0);
                data << uint8(0);
            }
        }
        randomlist->clear();
        delete randomlist;
    }
    BuildPlayerLockDungeonBlock(data, lockSet);
    SendPacket(&data);
}

void WorldSession::HandleLfgPartyLockInfoRequestOpcode(WorldPacket & /*recv_data*/)
{
    sLog.outDebug("CMSG_LFD_PARTY_LOCK_INFO_REQUEST [" UI64FMTD "]", GetPlayer()->GetGUID());
    if (LfgLockStatusMap* lockMap = sLFGMgr.GetPartyLockStatusDungeons(GetPlayer()))
    {
        uint32 size = 0;
        for (LfgLockStatusMap::const_iterator it = lockMap->begin(); it != lockMap->end(); ++it)
            size += 8 + 4 + it->second->size() * (4 + 4);
        sLog.outDebug("SMSG_LFG_PARTY_INFO [" UI64FMTD "]", GetPlayer()->GetGUID());
        WorldPacket data(SMSG_LFG_PARTY_INFO, 1 + size);
        BuildPartyLockDungeonBlock(data, lockMap);
        SendPacket(&data);
    }
}

void WorldSession::HandleLfrSearchOpcode(WorldPacket &recv_data)
{
    uint32 entry;                                           // Raid id to search
    recv_data >> entry;
    sLog.outDebug("CMSG_SEARCH_LFG_JOIN [" UI64FMTD "] dungeon entry: %u", GetPlayer()->GetGUID(), entry);
    //SendLfrUpdateListOpcode(entry);
}

void WorldSession::HandleLfrLeaveOpcode(WorldPacket &recv_data)
{
    uint32 dungeonId;                                       // Raid id queue to leave
    recv_data >> dungeonId;
    sLog.outDebug("CMSG_SEARCH_LFG_LEAVE [" UI64FMTD "] dungeonId: %u", GetPlayer()->GetGUID(), dungeonId);
    //sLFGMgr.LeaveLfr(GetPlayer(), dungeonId);
}

void WorldSession::SendLfgUpdatePlayer(uint8 updateType, LfgDungeonSet* dungeons /* = NULL */, std::string comment /* = "" */)
{
    bool queued = false;
    bool extrainfo = false;

    switch(updateType)
    {
    case LFG_UPDATETYPE_JOIN_PROPOSAL:
    case LFG_UPDATETYPE_ADDED_TO_QUEUE:
        queued = true;
        extrainfo = true;
        break;
    //case LFG_UPDATETYPE_CLEAR_LOCK_LIST: // TODO: Sometimes has extrainfo - Check ocurrences...
    case LFG_UPDATETYPE_PROPOSAL_BEGIN:
        extrainfo = true;
        break;
    }

    uint64 guid = GetPlayer()->GetGUID();
    uint8 size = dungeons ? dungeons->size() : 0;

    sLog.outDebug("SMSG_LFG_UPDATE_PLAYER [" UI64FMTD "] updatetype: %u", guid, updateType);
    WorldPacket data(SMSG_LFG_UPDATE_PLAYER, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + size * 4 + comment.length()));
    data << uint8(updateType);                             // Lfg Update type
    data << uint8(extrainfo);                              // Extra info
    if (extrainfo)
    {
        data << uint8(queued);                             // Join the queue
        data << uint8(0);                                  // unk - Always 0
        data << uint8(0);                                  // unk - Always 0

        data << uint8(size);
        if (size)
            for (LfgDungeonSet::const_iterator it = dungeons->begin(); it != dungeons->end(); ++it)
                data << uint32(*it);
        data << comment;
    }
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateParty(uint8 updateType, LfgDungeonSet* dungeons /* = NULL */, std::string comment /* = "" */)
{
    bool join = false;
    bool extrainfo = false;
    bool queued = false;

    switch(updateType)
    {
    case LFG_UPDATETYPE_JOIN_PROPOSAL:
        extrainfo = true;
        break;
    case LFG_UPDATETYPE_ADDED_TO_QUEUE:
        extrainfo = true;
        join = true;
        queued = true;
        break;
    case LFG_UPDATETYPE_CLEAR_LOCK_LIST:
        // join = true;  // TODO: Sometimes queued and extrainfo - Check ocurrences...
        queued = true;
        break;
    case LFG_UPDATETYPE_PROPOSAL_BEGIN:
        extrainfo = true;
        join = true;
        break;
    }

    uint64 guid = GetPlayer()->GetGUID();
    uint8 size = dungeons ? dungeons->size() : 0;

    sLog.outDebug("SMSG_LFG_UPDATE_PARTY [" UI64FMTD "] updatetype: %u", guid, updateType);
    WorldPacket data(SMSG_LFG_UPDATE_PARTY, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + 1 + size * 4 + comment.length()));
    data << uint8(updateType);                             // Lfg Update type
    data << uint8(extrainfo);                              // Extra info
    if (extrainfo)
    {
        data << uint8(join);                               // LFG Join
        data << uint8(queued);                             // Join the queue
        data << uint8(0);                                  // unk - Always 0
        data << uint8(0);                                  // unk - Always 0
        for (uint8 i = 0; i < 3; ++i)
            data << uint8(0);                              // unk - Always 0

        data << uint8(size);
        if (size)
            for (LfgDungeonSet::const_iterator it = dungeons->begin(); it != dungeons->end(); ++it)
                data << uint32(*it);
        data << comment;
    }
    SendPacket(&data);
}

void WorldSession::SendLfgRoleChosen(uint64 guid, uint8 roles)
{
    sLog.outDebug("SMSG_LFG_ROLE_CHOSEN [" UI64FMTD "] guid: [" UI64FMTD "] roles: %u", GetPlayer()->GetGUID(), guid, roles);

    WorldPacket data(SMSG_LFG_ROLE_CHOSEN, 8 + 1 + 4);
    data << uint64(guid);                                   // Guid
    data << uint8(roles > 0);                               // Ready
    data << uint32(roles);                                  // Roles
    SendPacket(&data);
}

void WorldSession::SendLfgRoleCheckUpdate(LfgRoleCheck* pRoleCheck)
{
    ASSERT(pRoleCheck);

    sLog.outDebug("SMSG_LFG_ROLE_CHECK_UPDATE [" UI64FMTD "]", GetPlayer()->GetGUID());
    WorldPacket data(SMSG_LFG_ROLE_CHECK_UPDATE, 4 + 1 + 1 + pRoleCheck->dungeons.size() * 4 + 1 + pRoleCheck->roles.size() * (8 + 1 + 4 + 1));

    Player* plr;
    uint8 roles;

    data << uint32(pRoleCheck->result);                     // Check result
    data << uint8(pRoleCheck->result == LFG_ROLECHECK_INITIALITING);
    data << uint8(pRoleCheck->dungeons.size());             // Number of dungeons
    LFGDungeonEntry const* dungeon;
    for (LfgDungeonSet::iterator it = pRoleCheck->dungeons.begin(); it != pRoleCheck->dungeons.end(); ++it)
    {
        dungeon = sLFGDungeonStore.LookupEntry(*it);
        if (!dungeon)
        {
            sLog.outError("BuildLfgRoleCheck: Dungeon %u does not exist in dbcs", (*it));
            data << uint32(0);
        }
        else
            data << uint32(dungeon->Entry());               // Dungeon
    }

    data << uint8(pRoleCheck->roles.size());                // Players in group
    // Leader info MUST be sent 1st :S
    roles = pRoleCheck->roles[pRoleCheck->leader];
    uint64 guid = MAKE_NEW_GUID(pRoleCheck->leader, 0, HIGHGUID_PLAYER);
    data << uint64(guid);                                   // Guid
    data << uint8(roles > 0);                               // Ready
    data << uint32(roles);                                  // Roles
    plr = sObjectMgr.GetPlayer(guid);
    data << uint8(plr ? plr->getLevel() : 0);               // Level

    for (LfgRolesMap::const_iterator itPlayers = pRoleCheck->roles.begin(); itPlayers != pRoleCheck->roles.end(); ++itPlayers)
    {
        if (itPlayers->first == pRoleCheck->leader)
            continue;

        roles = itPlayers->second;
        guid = MAKE_NEW_GUID(itPlayers->first, 0, HIGHGUID_PLAYER);
        data << uint64(guid);                               // Guid
        data << uint8(roles > 0);                           // Ready
        data << uint32(roles);                              // Roles
        plr = sObjectMgr.GetPlayer(guid);
        data << uint8(plr ? plr->getLevel() : 0);           // Level
    }
    SendPacket(&data);
}

void WorldSession::SendLfgJoinResult(uint8 checkResult, uint8 checkValue /* = 0 */, LfgLockStatusMap* playersLockMap /* = NULL */)
{
    uint32 size = 0;
    if (playersLockMap)
    {
        for (LfgLockStatusMap::const_iterator it = playersLockMap->begin(); it != playersLockMap->end(); ++it)
            size += 8 + 4 + it->second->size() * (4 + 4);
    }

    sLog.outDebug("SMSG_LFG_ROLE_CHOSEN [" UI64FMTD "] checkResult: %u checkValue: %u", GetPlayer()->GetGUID(), checkResult, checkValue);
    WorldPacket data(SMSG_LFG_JOIN_RESULT, 4 + 4 + size);
    data << uint32(checkResult);                            // Check Result
    data << uint32(checkValue);                             // Check Value
    if (playersLockMap)
        BuildPartyLockDungeonBlock(data, playersLockMap);
    SendPacket(&data);
}

void WorldSession::SendLfgQueueStatus(uint32 dungeon, int32 waitTime, int32 avgWaitTime, int32 waitTimeTanks, int32 waitTimeHealer, int32 waitTimeDps, uint32 queuedTime, uint8 tanks, uint8 healers, uint8 dps)
{
    sLog.outDebug("SMSG_LFG_QUEUE_STATUS [" UI64FMTD "] dungeon: %u - waitTime: %d - avgWaitTime: %d - waitTimeTanks: %d - waitTimeHealer: %d - waitTimeDps: %d - queuedTime: %u - tanks: %u - healers: %u - dps: %u", GetPlayer()->GetGUID(), dungeon, waitTime, avgWaitTime, waitTimeTanks, waitTimeHealer, waitTimeDps, queuedTime, tanks, healers, dps);

    WorldPacket data(SMSG_LFG_QUEUE_STATUS, 4 + 4 + 4 + 4 + 4 +4 + 1 + 1 + 1 + 4);
    data << uint32(dungeon);                                // Dungeon
    data << int32(avgWaitTime);                             // Average Wait time
    data << int32(waitTime);                                // Wait Time
    data << int32(waitTimeTanks);                           // Wait Tanks
    data << int32(waitTimeHealer);                          // Wait Healers
    data << int32(waitTimeDps);                             // Wait Dps
    data << uint8(tanks);                                   // Tanks needed
    data << uint8(healers);                                 // Healers needed
    data << uint8(dps);                                     // Dps needed
    data << uint32(queuedTime);                             // Player wait time in queue
    SendPacket(&data);
}

void WorldSession::SendLfgPlayerReward(uint32 rdungeonEntry, uint32 sdungeonEntry, uint8 done, const LfgReward* reward, const Quest* qRew)
{
    if (!rdungeonEntry || !sdungeonEntry || !qRew)
        return;

    uint8 itemNum = qRew ? qRew->GetRewItemsCount() : 0;

    sLog.outDebug("SMSG_LFG_PLAYER_REWARD [" UI64FMTD "] rdungeonEntry: %u - sdungeonEntry: %u - done: %u", GetPlayer()->GetGUID(), rdungeonEntry, sdungeonEntry, done);
    WorldPacket data(SMSG_LFG_PLAYER_REWARD, 4 + 4 + 1 + 4 + 4 + 4 + 4 + 4 + 1 + itemNum * (4 + 4 + 4));
    data << uint32(rdungeonEntry);                          // Random Dungeon Finished
    data << uint32(sdungeonEntry);                          // Dungeon Finished
    data << uint8(done);
    data << uint32(1);
    data << uint32(qRew->GetRewOrReqMoney());
    data << uint32(qRew->XPValue(GetPlayer()));
    data << uint32(reward->reward[done].variableMoney);
    data << uint32(reward->reward[done].variableXP);
    data << uint8(itemNum);
    if (itemNum)
    {
        ItemPrototype const* iProto = NULL;
        for (uint8 i = 0; i < QUEST_REWARDS_COUNT; ++i)
        {
            if (!qRew->RewItemId[i])
                continue;

            iProto = ObjectMgr::GetItemPrototype(qRew->RewItemId[i]);

            data << uint32(qRew->RewItemId[i]);
            data << uint32(iProto ? iProto->DisplayInfoID : 0);
            data << uint32(qRew->RewItemCount[i]);
        }
    }
    SendPacket(&data);
}

void WorldSession::SendLfgBootPlayer(LfgPlayerBoot* pBoot)
{
    int8 playerVote = pBoot->votes[GetPlayer()->GetGUIDLow()];
    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    uint32 secsleft = uint8((pBoot->cancelTime - time(NULL)) / 1000);
    for (LfgAnswerMap::const_iterator it = pBoot->votes.begin(); it != pBoot->votes.end(); ++it)
    {
        if (it->second != LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (it->second == LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }
    uint64 victimguid = MAKE_NEW_GUID(pBoot->victimLowGuid, 0, HIGHGUID_PLAYER);

    sLog.outDebug("SMSG_LFG_BOOT_PLAYER [" UI64FMTD "] inProgress: %u - didVote: %u - agree: %u - victim: [" UI64FMTD "] votes: %u - agrees: %u - left: %u - needed: %u - reason %s",
        GetPlayer()->GetGUID(), uint8(pBoot->inProgress), uint8(playerVote != LFG_ANSWER_PENDING), uint8(playerVote == LFG_ANSWER_AGREE), victimguid, votesNum, agreeNum, secsleft, pBoot->votedNeeded, pBoot->reason.c_str());
    WorldPacket data(SMSG_LFG_BOOT_PLAYER, 1 + 1 + 1 + 8 + 4 + 4 + 4 + 4 + pBoot->reason.length());
    data << uint8(pBoot->inProgress);                       // Vote in progress
    data << uint8(playerVote != LFG_ANSWER_PENDING);        // Did Vote
    data << uint8(playerVote == LFG_ANSWER_AGREE);          // Agree
    data << uint64(victimguid);                             // Victim GUID
    data << uint32(votesNum);                               // Total Votes
    data << uint32(agreeNum);                               // Agree Count
    data << uint32(secsleft);                               // Time Left
    data << uint32(pBoot->votedNeeded);                     // Needed Votes
    data << pBoot->reason.c_str();                          // Kick reason
    SendPacket(&data);
}

void WorldSession::SendUpdateProposal(uint32 proposalId, LfgProposal* pProp)
{
    if (!pProp)
        return;

    uint32 pLogGuid = GetPlayer()->GetGUIDLow();
    LfgProposalPlayerMap::const_iterator itPlayer = pProp->players.find(pLogGuid);
    if (itPlayer == pProp->players.end())                   // Player MUST be in the proposal
        return;

    LfgProposalPlayer* ppPlayer = itPlayer->second;
    uint32 pLowGroupGuid = ppPlayer->groupLowGuid;
    uint32 dLowGuid = pProp->groupLowGuid;
    uint32 dungeonId = pProp->dungeonId;
    uint32 isSameDungeon = GetPlayer()->GetGroup() && GetPlayer()->GetGroup()->GetLfgDungeonEntry() == dungeonId;

    sLog.outDebug("SMSG_LFG_PROPOSAL_UPDATE [" UI64FMTD "] state: %u", GetPlayer()->GetGUID(), pProp->state);
    WorldPacket data(SMSG_LFG_PROPOSAL_UPDATE, 4 + 1 + 4 + 4 + 1 + 1 + pProp->players.size() * (4 + 1 + 1 + 1 + 1 +1));
    if (!dLowGuid && GetPlayer()->GetLfgDungeons()->size() == 1)    // New group - select the dungeon the player selected
        dungeonId = (*GetPlayer()->GetLfgDungeons()->begin());
    if (LFGDungeonEntry const* dungeon = sLFGDungeonStore.LookupEntry(dungeonId))
        dungeonId = dungeon->Entry();
    data << uint32(dungeonId);                              // Dungeon
    data << uint8(pProp->state);                            // Result state
    data << uint32(proposalId);                             // Internal Proposal ID
    data << uint32(0);                                      // Bosses killed - FIXME
    data << uint8(isSameDungeon);                           // Silent (show client window)
    data << uint8(pProp->players.size());                   // Group size

    for (itPlayer = pProp->players.begin(); itPlayer != pProp->players.end(); ++itPlayer)
    {
        ppPlayer = itPlayer->second;
        data << uint32(ppPlayer->role);                     // Role
        data << uint8(itPlayer->first == pLogGuid);         // Self player
        if (!ppPlayer->groupLowGuid)                        // Player not it a group
        {
            data << uint8(0);                               // Not in dungeon
            data << uint8(0);                               // Not same group
        }
        else
        {
            data << uint8(ppPlayer->groupLowGuid == dLowGuid);  // In dungeon (silent)
            data << uint8(ppPlayer->groupLowGuid == pLowGroupGuid); // Same Group than player
        }
        data << uint8(ppPlayer->accept != LFG_ANSWER_PENDING); // Answered
        data << uint8(ppPlayer->accept == LFG_ANSWER_AGREE); // Accepted
    }
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateSearch(bool update)
{
    sLog.outDebug("SMSG_LFG_UPDATE_SEARCH [" UI64FMTD "] update: %u", GetPlayer()->GetGUID(), update ? 1 : 0);
    WorldPacket data(SMSG_LFG_UPDATE_SEARCH, 1);
    data << uint8(update);                                  // In Lfg Queue?
    SendPacket(&data);
}

void WorldSession::SendLfgDisabled()
{
    sLog.outDebug("SMSG_LFG_DISABLED [" UI64FMTD "]", GetPlayer()->GetGUID());
    WorldPacket data(SMSG_LFG_DISABLED, 0);
    SendPacket(&data);
}

void WorldSession::SendLfgOfferContinue(uint32 dungeonEntry)
{
    sLog.outDebug("SMSG_LFG_OFFER_CONTINUE [" UI64FMTD "] dungeon entry: %u", GetPlayer()->GetGUID(), dungeonEntry);
    WorldPacket data(SMSG_LFG_OFFER_CONTINUE, 4);
    data << uint32(dungeonEntry);
    SendPacket(&data);
}

void WorldSession::SendLfgTeleportError(uint8 err)
{
    sLog.outDebug("SMSG_LFG_TELEPORT_DENIED [" UI64FMTD "] reason: %u", GetPlayer()->GetGUID(), err);
    WorldPacket data(SMSG_LFG_TELEPORT_DENIED, 4);
    data << uint32(err);                                    // Error
    SendPacket(&data);
}

/*
void WorldSession::SendLfrUpdateListOpcode(uint32 dungeonEntry)
{
    sLog.outDebug("SMSG_UPDATE_LFG_LIST [" UI64FMTD "] dungeon entry: %u", GetPlayer()->GetGUID(), dungeonEntry);
    WorldPacket data(SMSG_UPDATE_LFG_LIST);
    SendPacket(&data);
}
*/
