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
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DisableMgr.h"
#include "GameEventMgr.h"
#include "Group.h"
#include "GroupMgr.h"
#include "InstanceSaveMgr.h"
#include "LFGGroupData.h"
#include "LFGPlayerData.h"
#include "LFGQueue.h"
#include "LFGScripts.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "SharedDefines.h"
#include "SocialMgr.h"
#include "World.h"
#include "WorldSession.h"

namespace lfg
{

LFGDungeonData::LFGDungeonData() : id(0), name(""), map(0), type(0), expansion(0), group(0), minlevel(0),
maxlevel(0), difficulty(DIFFICULTY_NONE), seasonal(false), x(0.0f), y(0.0f), z(0.0f), o(0.0f),
requiredItemLevel(0)
{
}

LFGDungeonData::LFGDungeonData(LFGDungeonsEntry const* dbc) : id(dbc->ID), name(dbc->Name->Str[sWorld->GetDefaultDbcLocale()]), map(dbc->MapID),
type(uint8(dbc->Type)), expansion(uint8(dbc->Expansion)), group(uint8(dbc->GroupID)),
minlevel(uint8(dbc->MinLevel)), maxlevel(uint8(dbc->MaxLevel)), difficulty(Difficulty(dbc->DifficultyID)),
seasonal((dbc->Flags & LFG_FLAG_SEASONAL) != 0), x(0.0f), y(0.0f), z(0.0f), o(0.0f),
requiredItemLevel(0)
{
}

LFGMgr::LFGMgr() : m_QueueTimer(0), m_lfgProposalId(1),
    m_options(sWorld->getIntConfig(CONFIG_LFG_OPTIONSMASK))
{
}

LFGMgr::~LFGMgr()
{
    for (LfgRewardContainer::iterator itr = RewardMapStore.begin(); itr != RewardMapStore.end(); ++itr)
        delete itr->second;
}

void LFGMgr::_LoadFromDB(Field* fields, ObjectGuid guid)
{
    if (!fields)
        return;

    if (!guid.IsParty())
        return;

    SetLeader(guid, ObjectGuid::Create<HighGuid::Player>(fields[0].GetUInt64()));

    uint32 dungeon = fields[18].GetUInt32();
    uint8 state = fields[19].GetUInt8();

    if (!dungeon || !state)
        return;

    SetDungeon(guid, dungeon);

    switch (state)
    {
        case LFG_STATE_DUNGEON:
        case LFG_STATE_FINISHED_DUNGEON:
            SetState(guid, (LfgState)state);
            break;
        default:
            break;
    }
}

void LFGMgr::_SaveToDB(ObjectGuid guid, uint32 db_guid)
{
    if (!guid.IsParty())
        return;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_LFG_DATA);
    stmt->setUInt32(0, db_guid);
    trans->Append(stmt);

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_LFG_DATA);
    stmt->setUInt32(0, db_guid);
    stmt->setUInt32(1, GetDungeon(guid));
    stmt->setUInt32(2, GetState(guid));
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

/// Load rewards for completing dungeons
void LFGMgr::LoadRewards()
{
    uint32 oldMSTime = getMSTime();

    for (LfgRewardContainer::iterator itr = RewardMapStore.begin(); itr != RewardMapStore.end(); ++itr)
        delete itr->second;
    RewardMapStore.clear();

    // ORDER BY is very important for GetRandomDungeonReward!
    QueryResult result = WorldDatabase.Query("SELECT dungeonId, maxLevel, firstQuestId, otherQuestId FROM lfg_dungeon_rewards ORDER BY dungeonId, maxLevel ASC");

    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 lfg dungeon rewards. DB table `lfg_dungeon_rewards` is empty!");
        return;
    }

    uint32 count = 0;

    Field* fields = NULL;
    do
    {
        fields = result->Fetch();
        uint32 dungeonId = fields[0].GetUInt32();
        uint32 maxLevel = fields[1].GetUInt8();
        uint32 firstQuestId = fields[2].GetUInt32();
        uint32 otherQuestId = fields[3].GetUInt32();

        if (!GetLFGDungeonEntry(dungeonId))
        {
            TC_LOG_ERROR("sql.sql", "Dungeon %u specified in table `lfg_dungeon_rewards` does not exist!", dungeonId);
            continue;
        }

        if (!maxLevel || maxLevel > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        {
            TC_LOG_ERROR("sql.sql", "Level %u specified for dungeon %u in table `lfg_dungeon_rewards` can never be reached!", maxLevel, dungeonId);
            maxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
        }

        if (!firstQuestId || !sObjectMgr->GetQuestTemplate(firstQuestId))
        {
            TC_LOG_ERROR("sql.sql", "First quest %u specified for dungeon %u in table `lfg_dungeon_rewards` does not exist!", firstQuestId, dungeonId);
            continue;
        }

        if (otherQuestId && !sObjectMgr->GetQuestTemplate(otherQuestId))
        {
            TC_LOG_ERROR("sql.sql", "Other quest %u specified for dungeon %u in table `lfg_dungeon_rewards` does not exist!", otherQuestId, dungeonId);
            otherQuestId = 0;
        }

        RewardMapStore.insert(LfgRewardContainer::value_type(dungeonId, new LfgReward(maxLevel, firstQuestId, otherQuestId)));
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u lfg dungeon rewards in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

LFGDungeonData const* LFGMgr::GetLFGDungeon(uint32 id)
{
    LFGDungeonContainer::const_iterator itr = LfgDungeonStore.find(id);
    if (itr != LfgDungeonStore.end())
        return &(itr->second);

    return NULL;
}

void LFGMgr::LoadLFGDungeons(bool reload /* = false */)
{
    uint32 oldMSTime = getMSTime();

    LfgDungeonStore.clear();

    // Initialize Dungeon map with data from dbcs
    for (uint32 i = 0; i < sLFGDungeonsStore.GetNumRows(); ++i)
    {
        LFGDungeonsEntry const* dungeon = sLFGDungeonsStore.LookupEntry(i);
        if (!dungeon)
            continue;

        switch (dungeon->Type)
        {
            case LFG_TYPE_DUNGEON:
            case LFG_TYPE_HEROIC:
            case LFG_TYPE_RAID:
            case LFG_TYPE_RANDOM:
                LfgDungeonStore[dungeon->ID] = LFGDungeonData(dungeon);
                break;
        }
    }

    // Fill teleport locations from DB
    QueryResult result = WorldDatabase.Query("SELECT dungeonId, position_x, position_y, position_z, orientation, requiredItemLevel FROM lfg_dungeon_template");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 lfg dungeon templates. DB table `lfg_dungeon_template` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 dungeonId = fields[0].GetUInt32();
        LFGDungeonContainer::iterator dungeonItr = LfgDungeonStore.find(dungeonId);
        if (dungeonItr == LfgDungeonStore.end())
        {
            TC_LOG_ERROR("sql.sql", "table `lfg_entrances` contains coordinates for wrong dungeon %u", dungeonId);
            continue;
        }

        LFGDungeonData& data    = dungeonItr->second;
        data.x                  = fields[1].GetFloat();
        data.y                  = fields[2].GetFloat();
        data.z                  = fields[3].GetFloat();
        data.o                  = fields[4].GetFloat();
        data.requiredItemLevel  = fields[5].GetUInt16();

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u lfg dungeon templates in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    // Fill all other teleport coords from areatriggers
    for (LFGDungeonContainer::iterator itr = LfgDungeonStore.begin(); itr != LfgDungeonStore.end(); ++itr)
    {
        LFGDungeonData& dungeon = itr->second;

        // No teleport coords in database, load from areatriggers
        if (dungeon.type != LFG_TYPE_RANDOM && dungeon.x == 0.0f && dungeon.y == 0.0f && dungeon.z == 0.0f)
        {
            AreaTriggerStruct const* at = sObjectMgr->GetMapEntranceTrigger(dungeon.map);
            if (!at)
            {
                TC_LOG_ERROR("sql.sql", "Failed to load dungeon %s (Id: %u), cant find areatrigger for map %u", dungeon.name.c_str(), dungeon.id, dungeon.map);
                continue;
            }

            dungeon.map = at->target_mapId;
            dungeon.x = at->target_X;
            dungeon.y = at->target_Y;
            dungeon.z = at->target_Z;
            dungeon.o = at->target_Orientation;
        }

        if (dungeon.type != LFG_TYPE_RANDOM)
            CachedDungeonMapStore[dungeon.group].insert(dungeon.id);
        CachedDungeonMapStore[0].insert(dungeon.id);
    }

    if (reload)
        CachedDungeonMapStore.clear();
}

LFGMgr* LFGMgr::instance()
{
    static LFGMgr instance;
    return &instance;
}

void LFGMgr::Update(uint32 diff)
{
    if (!isOptionEnabled(LFG_OPTION_ENABLE_DUNGEON_FINDER | LFG_OPTION_ENABLE_RAID_BROWSER))
        return;

    time_t currTime = time(NULL);

    // Remove obsolete role checks
    for (LfgRoleCheckContainer::iterator it = RoleChecksStore.begin(); it != RoleChecksStore.end();)
    {
        LfgRoleCheckContainer::iterator itRoleCheck = it++;
        LfgRoleCheck& roleCheck = itRoleCheck->second;
        if (currTime < roleCheck.cancelTime)
            continue;
        roleCheck.state = LFG_ROLECHECK_MISSING_ROLE;

        for (LfgRolesMap::const_iterator itRoles = roleCheck.roles.begin(); itRoles != roleCheck.roles.end(); ++itRoles)
        {
            ObjectGuid guid = itRoles->first;
            RestoreState(guid, "Remove Obsolete RoleCheck");
            SendLfgRoleCheckUpdate(guid, roleCheck);
            if (guid == roleCheck.leader)
                SendLfgJoinResult(guid, LfgJoinResultData(LFG_JOIN_ROLE_CHECK_FAILED, LFG_ROLECHECK_MISSING_ROLE));
        }

        RestoreState(itRoleCheck->first, "Remove Obsolete RoleCheck");
        RoleChecksStore.erase(itRoleCheck);
    }

    // Remove obsolete proposals
    for (LfgProposalContainer::iterator it = ProposalsStore.begin(); it != ProposalsStore.end();)
    {
        LfgProposalContainer::iterator itRemove = it++;
        if (itRemove->second.cancelTime < currTime)
            RemoveProposal(itRemove, LFG_UPDATETYPE_PROPOSAL_FAILED);
    }

    // Remove obsolete kicks
    for (LfgPlayerBootContainer::iterator it = BootsStore.begin(); it != BootsStore.end();)
    {
        LfgPlayerBootContainer::iterator itBoot = it++;
        LfgPlayerBoot& boot = itBoot->second;
        if (boot.cancelTime < currTime)
        {
            boot.inProgress = false;
            for (LfgAnswerContainer::const_iterator itVotes = boot.votes.begin(); itVotes != boot.votes.end(); ++itVotes)
            {
                ObjectGuid pguid = itVotes->first;
                if (pguid != boot.victim)
                    SendLfgBootProposalUpdate(pguid, boot);
            }
            SetVoteKick(itBoot->first, false);
            BootsStore.erase(itBoot);
        }
    }

    uint32 lastProposalId = m_lfgProposalId;
    // Check if a proposal can be formed with the new groups being added
    for (LfgQueueContainer::iterator it = QueuesStore.begin(); it != QueuesStore.end(); ++it)
        if (uint8 newProposals = it->second.FindGroups())
            TC_LOG_DEBUG("lfg.update", "Found %u new groups in queue %u", newProposals, it->first);

    if (lastProposalId != m_lfgProposalId)
    {
        // FIXME lastProposalId ? lastProposalId +1 ?
        for (LfgProposalContainer::const_iterator itProposal = ProposalsStore.find(m_lfgProposalId); itProposal != ProposalsStore.end(); ++itProposal)
        {
            uint32 proposalId = itProposal->first;
            LfgProposal& proposal = ProposalsStore[proposalId];

            ObjectGuid guid;
            for (LfgProposalPlayerContainer::const_iterator itPlayers = proposal.players.begin(); itPlayers != proposal.players.end(); ++itPlayers)
            {
                guid = itPlayers->first;
                SetState(guid, LFG_STATE_PROPOSAL);
                ObjectGuid gguid = GetGroup(guid);
                if (!gguid.IsEmpty())
                {
                    SetState(gguid, LFG_STATE_PROPOSAL);
                    SendLfgUpdateStatus(guid, LfgUpdateData(LFG_UPDATETYPE_PROPOSAL_BEGIN, GetSelectedDungeons(guid)), true);
                }
                else
                    SendLfgUpdateStatus(guid, LfgUpdateData(LFG_UPDATETYPE_PROPOSAL_BEGIN, GetSelectedDungeons(guid)), false);
                SendLfgUpdateProposal(guid, proposal);
            }

            if (proposal.state == LFG_PROPOSAL_SUCCESS)
                UpdateProposal(proposalId, guid, true);
        }
    }

    // Update all players status queue info
    if (m_QueueTimer > LFG_QUEUEUPDATE_INTERVAL)
    {
        m_QueueTimer = 0;
        for (LfgQueueContainer::iterator it = QueuesStore.begin(); it != QueuesStore.end(); ++it)
            it->second.UpdateQueueTimers(it->first, currTime);
    }
    else
        m_QueueTimer += diff;
}

/**
    Adds the player/group to lfg queue. If player is in a group then it is the leader
    of the group tying to join the group. Join conditions are checked before adding
    to the new queue.

   @param[in]     player Player trying to join (or leader of group trying to join)
   @param[in]     roles Player selected roles
   @param[in]     dungeons Dungeons the player/group is applying for
*/
void LFGMgr::JoinLfg(Player* player, uint8 roles, LfgDungeonSet& dungeons)
{
    if (!player || !player->GetSession() || dungeons.empty())
        return;

    Group* grp = player->GetGroup();
    ObjectGuid guid = player->GetGUID();
    ObjectGuid gguid = grp ? grp->GetGUID() : guid;
    LfgJoinResultData joinData;
    GuidSet players;
    uint32 rDungeonId = 0;
    bool isContinue = grp && grp->isLFGGroup() && GetState(gguid) != LFG_STATE_FINISHED_DUNGEON;

    // Do not allow to change dungeon in the middle of a current dungeon
    if (isContinue)
    {
        dungeons.clear();
        dungeons.insert(GetDungeon(gguid));
    }

    // Already in queue?
    LfgState state = GetState(gguid);
    if (state == LFG_STATE_QUEUED)
    {
        LFGQueue& queue = GetQueue(gguid);
        queue.RemoveFromQueue(gguid);
    }

    // Check player or group member restrictions
    if (!player->GetSession()->HasPermission(rbac::RBAC_PERM_JOIN_DUNGEON_FINDER))
        joinData.result = LFG_JOIN_NO_SLOTS_PLAYER;
    else if (player->InBattleground() || player->InArena() || player->InBattlegroundQueue())
        joinData.result = LFG_JOIN_CANT_USE_DUNGEONS;
    else if (player->HasAura(LFG_SPELL_DUNGEON_DESERTER))
        joinData.result = LFG_JOIN_DESERTER_PLAYER;
    else if (player->HasAura(LFG_SPELL_DUNGEON_COOLDOWN))
        joinData.result = LFG_JOIN_RANDOM_COOLDOWN_PLAYER;
    else if (dungeons.empty())
        joinData.result = LFG_JOIN_NO_SLOTS_PLAYER;
    else if (player->HasAura(9454)) // check Freeze debuff
        joinData.result = LFG_JOIN_NO_SLOTS_PLAYER;
    else if (grp)
    {
        if (grp->GetMembersCount() > MAX_GROUP_SIZE)
            joinData.result = LFG_JOIN_TOO_MANY_MEMBERS;
        else
        {
            uint8 memberCount = 0;
            for (GroupReference* itr = grp->GetFirstMember(); itr != NULL && joinData.result == LFG_JOIN_OK; itr = itr->next())
            {
                if (Player* plrg = itr->GetSource())
                {
                    if (!plrg->GetSession()->HasPermission(rbac::RBAC_PERM_JOIN_DUNGEON_FINDER))
                        joinData.result = LFG_JOIN_NO_LFG_OBJECT;
                    if (plrg->HasAura(LFG_SPELL_DUNGEON_DESERTER))
                        joinData.result = LFG_JOIN_DESERTER_PARTY;
                    else if (plrg->HasAura(LFG_SPELL_DUNGEON_COOLDOWN))
                        joinData.result = LFG_JOIN_RANDOM_COOLDOWN_PARTY;
                    else if (plrg->InBattleground() || plrg->InArena() || plrg->InBattlegroundQueue())
                        joinData.result = LFG_JOIN_CANT_USE_DUNGEONS;
                    else if (plrg->HasAura(9454)) // check Freeze debuff
                        joinData.result = LFG_JOIN_PARTY_NOT_MEET_REQS;
                    ++memberCount;
                    players.insert(plrg->GetGUID());
                }
            }

            if (joinData.result == LFG_JOIN_OK && memberCount != grp->GetMembersCount())
                joinData.result = LFG_JOIN_MEMBERS_NOT_PRESENT;
        }
    }
    else
        players.insert(player->GetGUID());

    // Check if all dungeons are valid
    bool isRaid = false;
    if (joinData.result == LFG_JOIN_OK)
    {
        bool isDungeon = false;
        for (LfgDungeonSet::const_iterator it = dungeons.begin(); it != dungeons.end() && joinData.result == LFG_JOIN_OK; ++it)
        {
            LfgType type = GetDungeonType(*it);
            switch (type)
            {
                case LFG_TYPE_RANDOM:
                    if (dungeons.size() > 1)               // Only allow 1 random dungeon
                        joinData.result = LFG_JOIN_INVALID_SLOT;
                    else
                        rDungeonId = (*dungeons.begin());
                    // No break on purpose (Random can only be dungeon or heroic dungeon)
                case LFG_TYPE_HEROIC:
                case LFG_TYPE_DUNGEON:
                    if (isRaid)
                        joinData.result = LFG_JOIN_MISMATCHED_SLOTS;
                    isDungeon = true;
                    break;
                case LFG_TYPE_RAID:
                    if (isDungeon)
                        joinData.result = LFG_JOIN_MISMATCHED_SLOTS;
                    isRaid = true;
                    break;
                default:
                    joinData.result = LFG_JOIN_INVALID_SLOT;
                    break;
            }
        }

        // it could be changed
        if (joinData.result == LFG_JOIN_OK)
        {
            // Expand random dungeons and check restrictions
            if (rDungeonId)
                dungeons = GetDungeonsByRandom(rDungeonId);

            // if we have lockmap then there are no compatible dungeons
            GetCompatibleDungeons(dungeons, players, joinData.lockmap, isContinue);
            if (dungeons.empty())
                joinData.result = grp ? LFG_JOIN_NO_LFG_OBJECT : LFG_JOIN_NO_SLOTS_PLAYER;
        }
    }

    // Can't join. Send result
    if (joinData.result != LFG_JOIN_OK)
    {
        TC_LOG_DEBUG("lfg.join", "%s joining with %u members. Result: %u, Dungeons: %s",
            guid.ToString().c_str(), grp ? grp->GetMembersCount() : 1, joinData.result, ConcatenateDungeons(dungeons).c_str());

        if (!dungeons.empty())                             // Only should show lockmap when have no dungeons available
            joinData.lockmap.clear();
        player->GetSession()->SendLfgJoinResult(joinData);
        return;
    }

    if (isRaid)
    {
        TC_LOG_DEBUG("lfg.join", "%s trying to join raid browser and it's disabled.", guid.ToString().c_str());
        return;
    }

    WorldPackets::LFG::RideTicket ticket;
    ticket.RequesterGuid = guid;
    ticket.Id = GetQueueId(gguid);
    ticket.Type = WorldPackets::LFG::RideType::Lfg;
    ticket.Time = int32(time(nullptr));
    std::string debugNames = "";
    if (grp)                                               // Begin rolecheck
    {
        // Create new rolecheck
        LfgRoleCheck& roleCheck = RoleChecksStore[gguid];
        roleCheck.cancelTime = time_t(time(NULL)) + LFG_TIME_ROLECHECK;
        roleCheck.state = LFG_ROLECHECK_INITIALITING;
        roleCheck.leader = guid;
        roleCheck.dungeons = dungeons;
        roleCheck.rDungeonId = rDungeonId;

        if (rDungeonId)
        {
            dungeons.clear();
            dungeons.insert(rDungeonId);
        }

        SetState(gguid, LFG_STATE_ROLECHECK);
        // Send update to player
        LfgUpdateData updateData = LfgUpdateData(LFG_UPDATETYPE_JOIN_QUEUE, dungeons);
        for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            if (Player* plrg = itr->GetSource())
            {
                ObjectGuid pguid = plrg->GetGUID();
                plrg->GetSession()->SendLfgUpdateStatus(updateData, true);
                SetState(pguid, LFG_STATE_ROLECHECK);
                SetTicket(pguid, ticket);
                if (!isContinue)
                    SetSelectedDungeons(pguid, dungeons);
                roleCheck.roles[pguid] = 0;
                if (!debugNames.empty())
                    debugNames.append(", ");
                debugNames.append(plrg->GetName());
            }
        }
        // Update leader role
        UpdateRoleCheck(gguid, guid, roles);
    }
    else                                                   // Add player to queue
    {
        LfgRolesMap rolesMap;
        rolesMap[guid] = roles;
        LFGQueue& queue = GetQueue(guid);
        queue.AddQueueData(guid, time(NULL), dungeons, rolesMap);

        if (!isContinue)
        {
            if (rDungeonId)
            {
                dungeons.clear();
                dungeons.insert(rDungeonId);
            }
            SetSelectedDungeons(guid, dungeons);
        }
        // Send update to player
        SetTicket(guid, ticket);
        SetRoles(guid, roles);
        player->GetSession()->SendLfgUpdateStatus(LfgUpdateData(LFG_UPDATETYPE_JOIN_QUEUE_INITIAL, dungeons), false);
        SetState(guid, LFG_STATE_QUEUED);
        player->GetSession()->SendLfgUpdateStatus(LfgUpdateData(LFG_UPDATETYPE_ADDED_TO_QUEUE, dungeons), false);
        player->GetSession()->SendLfgJoinResult(joinData);
        debugNames.append(player->GetName());
    }

    TC_LOG_DEBUG("lfg.join", "%s joined (%s), Members: %s. Dungeons (%u): %s", guid.ToString().c_str(),
        grp ? "group" : "player", debugNames.c_str(), uint32(dungeons.size()), ConcatenateDungeons(dungeons).c_str());
}

/**
    Leaves Dungeon System. Player/Group is removed from queue, rolechecks, proposals
    or votekicks. Player or group needs to be not NULL and using Dungeon System

   @param[in]     guid Player or group guid
*/
void LFGMgr::LeaveLfg(ObjectGuid guid, bool disconnected)
{
    ObjectGuid gguid = guid.IsParty() ? guid : GetGroup(guid);

    TC_LOG_DEBUG("lfg.leave", "%s left (%s)", guid.ToString().c_str(), guid == gguid ? "group" : "player");

    LfgState state = GetState(guid);
    switch (state)
    {
        case LFG_STATE_QUEUED:
            if (!gguid.IsEmpty())
            {
                LFGQueue& queue = GetQueue(gguid);
                queue.RemoveFromQueue(gguid);
                SetState(gguid, LFG_STATE_NONE);
                GuidSet const& players = GetPlayers(gguid);
                for (GuidSet::const_iterator it = players.begin(); it != players.end(); ++it)
                {
                    SetState(*it, LFG_STATE_NONE);
                    SendLfgUpdateStatus(*it, LfgUpdateData(LFG_UPDATETYPE_REMOVED_FROM_QUEUE), true);
                }
            }
            else
            {
                LFGQueue& queue = GetQueue(guid);
                queue.RemoveFromQueue(guid);
                SendLfgUpdateStatus(guid, LfgUpdateData(LFG_UPDATETYPE_REMOVED_FROM_QUEUE), false);
                SetState(guid, LFG_STATE_NONE);
            }
            break;
        case LFG_STATE_ROLECHECK:
            if (!gguid.IsEmpty())
                UpdateRoleCheck(gguid);                    // No player to update role = LFG_ROLECHECK_ABORTED
            break;
        case LFG_STATE_PROPOSAL:
        {
            // Remove from Proposals
            LfgProposalContainer::iterator it = ProposalsStore.begin();
            ObjectGuid pguid = gguid == guid ? GetLeader(gguid) : guid;
            while (it != ProposalsStore.end())
            {
                LfgProposalPlayerContainer::iterator itPlayer = it->second.players.find(pguid);
                if (itPlayer != it->second.players.end())
                {
                    // Mark the player/leader of group who left as didn't accept the proposal
                    itPlayer->second.accept = LFG_ANSWER_DENY;
                    break;
                }
                ++it;
            }

            // Remove from queue - if proposal is found, RemoveProposal will call RemoveFromQueue
            if (it != ProposalsStore.end())
                RemoveProposal(it, LFG_UPDATETYPE_PROPOSAL_DECLINED);
            break;
        }
        case LFG_STATE_NONE:
        case LFG_STATE_RAIDBROWSER:
            break;
        case LFG_STATE_DUNGEON:
        case LFG_STATE_FINISHED_DUNGEON:
            if (guid != gguid && !disconnected) // Player
                SetState(guid, LFG_STATE_NONE);
            break;
    }
}

WorldPackets::LFG::RideTicket const* LFGMgr::GetTicket(ObjectGuid guid) const
{
    auto itr = PlayersStore.find(guid);
    if (itr != PlayersStore.end())
        return &itr->second.GetTicket();

    return nullptr;
}

/**
   Update the Role check info with the player selected role.

   @param[in]     grp Group guid to update rolecheck
   @param[in]     guid Player guid (0 = rolecheck failed)
   @param[in]     roles Player selected roles
*/
void LFGMgr::UpdateRoleCheck(ObjectGuid gguid, ObjectGuid guid /* = ObjectGuid::Empty */, uint8 roles /* = PLAYER_ROLE_NONE */)
{
    if (!gguid)
        return;

    LfgRolesMap check_roles;
    LfgRoleCheckContainer::iterator itRoleCheck = RoleChecksStore.find(gguid);
    if (itRoleCheck == RoleChecksStore.end())
        return;

    LfgRoleCheck& roleCheck = itRoleCheck->second;
    bool sendRoleChosen = roleCheck.state != LFG_ROLECHECK_DEFAULT && !guid.IsEmpty();

    if (!guid)
        roleCheck.state = LFG_ROLECHECK_ABORTED;
    else if (roles < PLAYER_ROLE_TANK)                            // Player selected no role.
        roleCheck.state = LFG_ROLECHECK_NO_ROLE;
    else
    {
        roleCheck.roles[guid] = roles;

        // Check if all players have selected a role
        LfgRolesMap::const_iterator itRoles = roleCheck.roles.begin();
        while (itRoles != roleCheck.roles.end() && itRoles->second != PLAYER_ROLE_NONE)
            ++itRoles;

        if (itRoles == roleCheck.roles.end())
        {
            // use temporal var to check roles, CheckGroupRoles modifies the roles
            check_roles = roleCheck.roles;
            roleCheck.state = CheckGroupRoles(check_roles) ? LFG_ROLECHECK_FINISHED : LFG_ROLECHECK_WRONG_ROLES;
        }
    }

    LfgDungeonSet dungeons;
    if (roleCheck.rDungeonId)
        dungeons.insert(roleCheck.rDungeonId);
    else
        dungeons = roleCheck.dungeons;

    LfgJoinResultData joinData = LfgJoinResultData(LFG_JOIN_ROLE_CHECK_FAILED, roleCheck.state);
    for (LfgRolesMap::const_iterator it = roleCheck.roles.begin(); it != roleCheck.roles.end(); ++it)
    {
        ObjectGuid pguid = it->first;

        if (sendRoleChosen)
            SendLfgRoleChosen(pguid, guid, roles);

        SendLfgRoleCheckUpdate(pguid, roleCheck);
        switch (roleCheck.state)
        {
            case LFG_ROLECHECK_INITIALITING:
                continue;
            case LFG_ROLECHECK_FINISHED:
                SetState(pguid, LFG_STATE_QUEUED);
                SetRoles(pguid, it->second);
                SendLfgUpdateStatus(pguid, LfgUpdateData(LFG_UPDATETYPE_ADDED_TO_QUEUE, dungeons), true);
                break;
            default:
                if (roleCheck.leader == pguid)
                    SendLfgJoinResult(pguid, joinData);
                SendLfgUpdateStatus(pguid, LfgUpdateData(LFG_UPDATETYPE_ROLECHECK_FAILED), true);
                RestoreState(pguid, "Rolecheck Failed");
                break;
        }
    }

    if (roleCheck.state == LFG_ROLECHECK_FINISHED)
    {
        SetState(gguid, LFG_STATE_QUEUED);
        LFGQueue& queue = GetQueue(gguid);
        queue.AddQueueData(gguid, time_t(time(NULL)), roleCheck.dungeons, roleCheck.roles);
        RoleChecksStore.erase(itRoleCheck);
    }
    else if (roleCheck.state != LFG_ROLECHECK_INITIALITING)
    {
        RestoreState(gguid, "Rolecheck Failed");
        RoleChecksStore.erase(itRoleCheck);
    }
}

/**
   Given a list of dungeons remove the dungeons players have restrictions.

   @param[in, out] dungeons Dungeons to check restrictions
   @param[in]     players Set of players to check their dungeon restrictions
   @param[out]    lockMap Map of players Lock status info of given dungeons (Empty if dungeons is not empty)
*/
void LFGMgr::GetCompatibleDungeons(LfgDungeonSet& dungeons, GuidSet const& players, LfgLockPartyMap& lockMap, bool isContinue)
{
    lockMap.clear();

    std::map<uint32, uint32> lockedDungeons;

    for (GuidSet::const_iterator it = players.begin(); it != players.end() && !dungeons.empty(); ++it)
    {
        ObjectGuid guid = (*it);
        LfgLockMap const& cachedLockMap = GetLockedDungeons(guid);
        Player* player = ObjectAccessor::FindConnectedPlayer(guid);
        for (LfgLockMap::const_iterator it2 = cachedLockMap.begin(); it2 != cachedLockMap.end() && !dungeons.empty(); ++it2)
        {
            uint32 dungeonId = (it2->first & 0x00FFFFFF); // Compare dungeon ids
            LfgDungeonSet::iterator itDungeon = dungeons.find(dungeonId);
            if (itDungeon != dungeons.end())
            {
                bool eraseDungeon = true;

                // Don't remove the dungeon if team members are trying to continue a locked instance
                if (it2->second.lockStatus == LFG_LOCKSTATUS_RAID_LOCKED && isContinue)
                {
                    LFGDungeonData const* dungeon = GetLFGDungeon(dungeonId);
                    ASSERT(dungeon);
                    ASSERT(player);
                    if (InstancePlayerBind* playerBind = player->GetBoundInstance(dungeon->map, Difficulty(dungeon->difficulty)))
                    {
                        if (InstanceSave* playerSave = playerBind->save)
                        {
                            uint32 dungeonInstanceId = playerSave->GetInstanceId();
                            auto itLockedDungeon = lockedDungeons.find(dungeonId);
                            if (itLockedDungeon == lockedDungeons.end() || itLockedDungeon->second == dungeonInstanceId)
                                eraseDungeon = false;

                            lockedDungeons[dungeonId] = dungeonInstanceId;
                        }
                    }
                }

                if (eraseDungeon)
                    dungeons.erase(itDungeon);

                lockMap[guid][dungeonId] = it2->second;
            }
        }
    }
    if (!dungeons.empty())
        lockMap.clear();
}

/**
   Check if a group can be formed with the given group roles

   @param[in]     groles Map of roles to check
   @return True if roles are compatible
*/
bool LFGMgr::CheckGroupRoles(LfgRolesMap& groles)
{
    if (groles.empty())
        return false;

    uint8 damage = 0;
    uint8 tank = 0;
    uint8 healer = 0;

    for (LfgRolesMap::iterator it = groles.begin(); it != groles.end(); ++it)
    {
        uint8 role = it->second & ~PLAYER_ROLE_LEADER;
        if (role == PLAYER_ROLE_NONE)
            return false;

        if (role & PLAYER_ROLE_DAMAGE)
        {
            if (role != PLAYER_ROLE_DAMAGE)
            {
                it->second -= PLAYER_ROLE_DAMAGE;
                if (CheckGroupRoles(groles))
                    return true;
                it->second += PLAYER_ROLE_DAMAGE;
            }
            else if (damage == LFG_DPS_NEEDED)
                return false;
            else
                damage++;
        }

        if (role & PLAYER_ROLE_HEALER)
        {
            if (role != PLAYER_ROLE_HEALER)
            {
                it->second -= PLAYER_ROLE_HEALER;
                if (CheckGroupRoles(groles))
                    return true;
                it->second += PLAYER_ROLE_HEALER;
            }
            else if (healer == LFG_HEALERS_NEEDED)
                return false;
            else
                healer++;
        }

        if (role & PLAYER_ROLE_TANK)
        {
            if (role != PLAYER_ROLE_TANK)
            {
                it->second -= PLAYER_ROLE_TANK;
                if (CheckGroupRoles(groles))
                    return true;
                it->second += PLAYER_ROLE_TANK;
            }
            else if (tank == LFG_TANKS_NEEDED)
                return false;
            else
                tank++;
        }
    }
    return (tank + healer + damage) == uint8(groles.size());
}

/**
   Makes a new group given a proposal
   @param[in]     proposal Proposal to get info from
*/
void LFGMgr::MakeNewGroup(LfgProposal const& proposal)
{
    GuidList players;
    GuidList playersToTeleport;

    for (LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        ObjectGuid guid = it->first;
        if (guid == proposal.leader)
            players.push_front(guid);
        else
            players.push_back(guid);

        if (proposal.isNew || GetGroup(guid) != proposal.group)
            playersToTeleport.push_back(guid);
    }

    // Set the dungeon difficulty
    LFGDungeonData const* dungeon = GetLFGDungeon(proposal.dungeonId);
    ASSERT(dungeon);

    Group* grp = !proposal.group.IsEmpty() ? sGroupMgr->GetGroupByGUID(proposal.group) : NULL;
    for (GuidList::const_iterator it = players.begin(); it != players.end(); ++it)
    {
        ObjectGuid pguid = (*it);
        Player* player = ObjectAccessor::FindConnectedPlayer(pguid);
        if (!player)
            continue;

        Group* group = player->GetGroup();
        if (group && group != grp)
            group->RemoveMember(player->GetGUID());

        if (!grp)
        {
            grp = new Group();
            grp->ConvertToLFG();
            grp->Create(player);
            ObjectGuid gguid = grp->GetGUID();
            SetState(gguid, LFG_STATE_PROPOSAL);
            sGroupMgr->AddGroup(grp);
        }
        else if (group != grp)
            grp->AddMember(player);

        grp->SetLfgRoles(pguid, proposal.players.find(pguid)->second.role);

        // Add the cooldown spell if queued for a random dungeon
        if (dungeon->type == LFG_TYPE_RANDOM)
            player->CastSpell(player, LFG_SPELL_DUNGEON_COOLDOWN, false);
    }

    ASSERT(grp);
    grp->SetDungeonDifficultyID(Difficulty(dungeon->difficulty));
    ObjectGuid gguid = grp->GetGUID();
    SetDungeon(gguid, dungeon->Entry());
    SetState(gguid, LFG_STATE_DUNGEON);

    _SaveToDB(gguid, grp->GetDbStoreId());

    // Teleport Player
    for (GuidList::const_iterator it = playersToTeleport.begin(); it != playersToTeleport.end(); ++it)
        if (Player* player = ObjectAccessor::FindPlayer(*it))
            TeleportPlayer(player, false);

    // Update group info
    grp->SendUpdate();
}

uint32 LFGMgr::AddProposal(LfgProposal& proposal)
{
    proposal.id = ++m_lfgProposalId;
    ProposalsStore[m_lfgProposalId] = proposal;
    return m_lfgProposalId;
}

/**
   Update Proposal info with player answer

   @param[in]     proposalId Proposal id to be updated
   @param[in]     guid Player guid to update answer
   @param[in]     accept Player answer
*/
void LFGMgr::UpdateProposal(uint32 proposalId, ObjectGuid guid, bool accept)
{
    // Check if the proposal exists
    LfgProposalContainer::iterator itProposal = ProposalsStore.find(proposalId);
    if (itProposal == ProposalsStore.end())
        return;

    LfgProposal& proposal = itProposal->second;

    // Check if proposal have the current player
    LfgProposalPlayerContainer::iterator itProposalPlayer = proposal.players.find(guid);
    if (itProposalPlayer == proposal.players.end())
        return;

    LfgProposalPlayer& player = itProposalPlayer->second;
    player.accept = LfgAnswer(accept);

    TC_LOG_DEBUG("lfg.proposal.update", "%s, Proposal %u, Selection: %u", guid.ToString().c_str(), proposalId, accept);
    if (!accept)
    {
        RemoveProposal(itProposal, LFG_UPDATETYPE_PROPOSAL_DECLINED);
        return;
    }

    // check if all have answered and reorder players (leader first)
    bool allAnswered = true;
    for (LfgProposalPlayerContainer::const_iterator itPlayers = proposal.players.begin(); itPlayers != proposal.players.end(); ++itPlayers)
        if (itPlayers->second.accept != LFG_ANSWER_AGREE)   // No answer (-1) or not accepted (0)
            allAnswered = false;

    if (!allAnswered)
    {
        for (LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
            SendLfgUpdateProposal(it->first, proposal);

        return;
    }

    bool sendUpdate = proposal.state != LFG_PROPOSAL_SUCCESS;
    proposal.state = LFG_PROPOSAL_SUCCESS;
    time_t joinTime = time(NULL);

    LFGQueue& queue = GetQueue(guid);
    LfgUpdateData updateData = LfgUpdateData(LFG_UPDATETYPE_GROUP_FOUND);
    for (LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        ObjectGuid pguid = it->first;
        ObjectGuid gguid = it->second.group;
        uint32 dungeonId = (*GetSelectedDungeons(pguid).begin());
        int32 waitTime = -1;
        if (sendUpdate)
           SendLfgUpdateProposal(pguid, proposal);

        if (!gguid.IsEmpty())
        {
            waitTime = int32((joinTime - queue.GetJoinTime(gguid)) / IN_MILLISECONDS);
            SendLfgUpdateStatus(pguid, updateData, false);
        }
        else
        {
            waitTime = int32((joinTime - queue.GetJoinTime(pguid)) / IN_MILLISECONDS);
            SendLfgUpdateStatus(pguid, updateData, false);
        }
        updateData.updateType = LFG_UPDATETYPE_REMOVED_FROM_QUEUE;
        SendLfgUpdateStatus(pguid, updateData, true);
        SendLfgUpdateStatus(pguid, updateData, false);

        // Update timers
        uint8 role = GetRoles(pguid);
        role &= ~PLAYER_ROLE_LEADER;
        switch (role)
        {
            case PLAYER_ROLE_DAMAGE:
                queue.UpdateWaitTimeDps(waitTime, dungeonId);
                break;
            case PLAYER_ROLE_HEALER:
                queue.UpdateWaitTimeHealer(waitTime, dungeonId);
                break;
            case PLAYER_ROLE_TANK:
                queue.UpdateWaitTimeTank(waitTime, dungeonId);
                break;
            default:
                queue.UpdateWaitTimeAvg(waitTime, dungeonId);
                break;
        }

        SetState(pguid, LFG_STATE_DUNGEON);
    }

    // Remove players/groups from Queue
    for (GuidList::const_iterator it = proposal.queues.begin(); it != proposal.queues.end(); ++it)
        queue.RemoveFromQueue(*it);

    MakeNewGroup(proposal);
    ProposalsStore.erase(itProposal);
}

/**
   Remove a proposal from the pool, remove the group that didn't accept (if needed) and readd the other members to the queue

   @param[in]     itProposal Iterator to the proposal to remove
   @param[in]     type Type of removal (LFG_UPDATETYPE_PROPOSAL_FAILED, LFG_UPDATETYPE_PROPOSAL_DECLINED)
*/
void LFGMgr::RemoveProposal(LfgProposalContainer::iterator itProposal, LfgUpdateType type)
{
    LfgProposal& proposal = itProposal->second;
    proposal.state = LFG_PROPOSAL_FAILED;

    TC_LOG_DEBUG("lfg.proposal.remove", "Proposal %u, state FAILED, UpdateType %u", itProposal->first, type);
    // Mark all people that didn't answered as no accept
    if (type == LFG_UPDATETYPE_PROPOSAL_FAILED)
        for (LfgProposalPlayerContainer::iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
            if (it->second.accept == LFG_ANSWER_PENDING)
                it->second.accept = LFG_ANSWER_DENY;

    // Mark players/groups to be removed
    GuidSet toRemove;
    for (LfgProposalPlayerContainer::iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        if (it->second.accept == LFG_ANSWER_AGREE)
            continue;

        ObjectGuid guid = !it->second.group.IsEmpty() ? it->second.group : it->first;
        // Player didn't accept or still pending when no secs left
        if (it->second.accept == LFG_ANSWER_DENY || type == LFG_UPDATETYPE_PROPOSAL_FAILED)
        {
            it->second.accept = LFG_ANSWER_DENY;
            toRemove.insert(guid);
        }
    }

    // Notify players
    for (LfgProposalPlayerContainer::const_iterator it = proposal.players.begin(); it != proposal.players.end(); ++it)
    {
        ObjectGuid guid = it->first;
        ObjectGuid gguid = !it->second.group.IsEmpty() ? it->second.group : guid;

        SendLfgUpdateProposal(guid, proposal);

        if (toRemove.find(gguid) != toRemove.end())         // Didn't accept or in same group that someone that didn't accept
        {
            LfgUpdateData updateData;
            if (it->second.accept == LFG_ANSWER_DENY)
            {
                updateData.updateType = type;
                TC_LOG_DEBUG("lfg.proposal.remove", "%s didn't accept. Removing from queue and compatible cache", guid.ToString().c_str());
            }
            else
            {
                updateData.updateType = LFG_UPDATETYPE_REMOVED_FROM_QUEUE;
                TC_LOG_DEBUG("lfg.proposal.remove", "%s in same group that someone that didn't accept. Removing from queue and compatible cache", guid.ToString().c_str());
            }

            RestoreState(guid, "Proposal Fail (didn't accepted or in group with someone that didn't accept");
            if (gguid != guid)
            {
                RestoreState(it->second.group, "Proposal Fail (someone in group didn't accepted)");
                SendLfgUpdateStatus(guid, updateData, true);
            }
            else
                SendLfgUpdateStatus(guid, updateData, false);
        }
        else
        {
            TC_LOG_DEBUG("lfg.proposal.remove", "Readding %s to queue.", guid.ToString().c_str());
            SetState(guid, LFG_STATE_QUEUED);
            if (gguid != guid)
            {
                SetState(gguid, LFG_STATE_QUEUED);
                SendLfgUpdateStatus(guid, LfgUpdateData(LFG_UPDATETYPE_ADDED_TO_QUEUE, GetSelectedDungeons(guid)), true);
            }
            else
                SendLfgUpdateStatus(guid, LfgUpdateData(LFG_UPDATETYPE_ADDED_TO_QUEUE, GetSelectedDungeons(guid)), false);
        }
    }

    LFGQueue& queue = GetQueue(proposal.players.begin()->first);
    // Remove players/groups from queue
    for (GuidSet::const_iterator it = toRemove.begin(); it != toRemove.end(); ++it)
    {
        ObjectGuid guid = *it;
        queue.RemoveFromQueue(guid);
        proposal.queues.remove(guid);
    }

    // Readd to queue
    for (GuidList::const_iterator it = proposal.queues.begin(); it != proposal.queues.end(); ++it)
    {
        ObjectGuid guid = *it;
        queue.AddToQueue(guid, true);
    }

    ProposalsStore.erase(itProposal);
}

/**
   Initialize a boot kick vote

   @param[in]     gguid Group the vote kicks belongs to
   @param[in]     kicker Kicker guid
   @param[in]     victim Victim guid
   @param[in]     reason Kick reason
*/
void LFGMgr::InitBoot(ObjectGuid gguid, ObjectGuid kicker, ObjectGuid victim, std::string const& reason)
{
    SetVoteKick(gguid, true);

    LfgPlayerBoot& boot = BootsStore[gguid];
    boot.inProgress = true;
    boot.cancelTime = time_t(time(NULL)) + LFG_TIME_BOOT;
    boot.reason = reason;
    boot.victim = victim;

    GuidSet const& players = GetPlayers(gguid);

    // Set votes
    for (GuidSet::const_iterator itr = players.begin(); itr != players.end(); ++itr)
    {
        ObjectGuid guid = (*itr);
        boot.votes[guid] = LFG_ANSWER_PENDING;
    }

    boot.votes[victim] = LFG_ANSWER_DENY;                  // Victim auto vote NO
    boot.votes[kicker] = LFG_ANSWER_AGREE;                 // Kicker auto vote YES

    // Notify players
    for (GuidSet::const_iterator it = players.begin(); it != players.end(); ++it)
        SendLfgBootProposalUpdate(*it, boot);
}

/**
   Update Boot info with player answer

   @param[in]     guid Player who has answered
   @param[in]     player answer
*/
void LFGMgr::UpdateBoot(ObjectGuid guid, bool accept)
{
    ObjectGuid gguid = GetGroup(guid);
    if (!gguid)
        return;

    LfgPlayerBootContainer::iterator itBoot = BootsStore.find(gguid);
    if (itBoot == BootsStore.end())
        return;

    LfgPlayerBoot& boot = itBoot->second;

    if (boot.votes[guid] != LFG_ANSWER_PENDING)    // Cheat check: Player can't vote twice
        return;

    boot.votes[guid] = LfgAnswer(accept);

    uint8 votesNum = 0;
    uint8 agreeNum = 0;
    for (LfgAnswerContainer::const_iterator itVotes = boot.votes.begin(); itVotes != boot.votes.end(); ++itVotes)
    {
        if (itVotes->second != LFG_ANSWER_PENDING)
        {
            ++votesNum;
            if (itVotes->second == LFG_ANSWER_AGREE)
                ++agreeNum;
        }
    }

    // if we don't have enough votes (agree or deny) do nothing
    if (agreeNum < LFG_GROUP_KICK_VOTES_NEEDED && (votesNum - agreeNum) < LFG_GROUP_KICK_VOTES_NEEDED)
        return;

    // Send update info to all players
    boot.inProgress = false;
    for (LfgAnswerContainer::const_iterator itVotes = boot.votes.begin(); itVotes != boot.votes.end(); ++itVotes)
    {
        ObjectGuid pguid = itVotes->first;
        if (pguid != boot.victim)
            SendLfgBootProposalUpdate(pguid, boot);
    }

    SetVoteKick(gguid, false);
    if (agreeNum == LFG_GROUP_KICK_VOTES_NEEDED)           // Vote passed - Kick player
    {
        if (Group* group = sGroupMgr->GetGroupByGUID(gguid))
            Player::RemoveFromGroup(group, boot.victim, GROUP_REMOVEMETHOD_KICK_LFG);
        DecreaseKicksLeft(gguid);
    }
    BootsStore.erase(itBoot);
}

/**
   Teleports the player in or out the dungeon

   @param[in]     player Player to teleport
   @param[in]     out Teleport out (true) or in (false)
   @param[in]     fromOpcode Function called from opcode handlers? (Default false)
*/
void LFGMgr::TeleportPlayer(Player* player, bool out, bool fromOpcode /*= false*/)
{
    LFGDungeonData const* dungeon = NULL;
    Group* group = player->GetGroup();

    if (group && group->isLFGGroup())
        dungeon = GetLFGDungeon(GetDungeon(group->GetGUID()));

    if (!dungeon)
    {
        TC_LOG_DEBUG("lfg.teleport", "Player %s not in group/lfggroup or dungeon not found!",
            player->GetName().c_str());
        player->GetSession()->SendLfgTeleportError(LFG_TELEPORT_RESULT_NO_RETURN_LOCATION);
        return;
    }

    if (out)
    {
        TC_LOG_DEBUG("lfg.teleport", "Player %s is being teleported out. Current Map %u - Expected Map %u",
            player->GetName().c_str(), player->GetMapId(), uint32(dungeon->map));
        if (player->GetMapId() == uint32(dungeon->map))
            player->TeleportToBGEntryPoint();

        return;
    }

    LfgTeleportResult error = LFG_TELEPORT_RESULT_NONE;

    if (!player->IsAlive())
        error = LFG_TELEPORT_RESULT_DEAD;
    else if (player->IsFalling() || player->HasUnitState(UNIT_STATE_JUMPING))
        error = LFG_TELEPORT_RESULT_FALLING;
    else if (player->IsMirrorTimerActive(FATIGUE_TIMER))
        error = LFG_TELEPORT_RESULT_EXHAUSTION;
    else if (player->GetVehicle())
        error = LFG_TELEPORT_RESULT_ON_TRANSPORT;
    else if (!player->GetCharmGUID().IsEmpty())
        error = LFG_TELEPORT_RESULT_IMMUNE_TO_SUMMONS;
    else if (player->HasAura(9454)) // check Freeze debuff
        error = LFG_TELEPORT_RESULT_NO_RETURN_LOCATION;
    else if (player->GetMapId() != uint32(dungeon->map))  // Do not teleport players in dungeon to the entrance
    {
        uint32 mapid = dungeon->map;
        float x = dungeon->x;
        float y = dungeon->y;
        float z = dungeon->z;
        float orientation = dungeon->o;

        if (!fromOpcode)
        {
            // Select a player inside to be teleported to
            for (GroupReference* itr = group->GetFirstMember(); itr != NULL && !mapid; itr = itr->next())
            {
                Player* plrg = itr->GetSource();
                if (plrg && plrg != player && plrg->GetMapId() == uint32(dungeon->map))
                {
                    mapid = plrg->GetMapId();
                    x = plrg->GetPositionX();
                    y = plrg->GetPositionY();
                    z = plrg->GetPositionZ();
                    orientation = plrg->GetOrientation();
                    break;
                }
            }
        }

        if (!player->GetMap()->IsDungeon())
            player->SetBattlegroundEntryPoint();

        if (player->IsInFlight())
        {
            player->GetMotionMaster()->MovementExpired();
            player->CleanupAfterTaxiFlight();
        }

        if (!player->TeleportTo(mapid, x, y, z, orientation))
            error = LFG_TELEPORT_RESULT_NO_RETURN_LOCATION;
    }
    else
        error = LFG_TELEPORT_RESULT_NO_RETURN_LOCATION;

    if (error != LFG_TELEPORT_RESULT_NONE)
        player->GetSession()->SendLfgTeleportError(error);

    TC_LOG_DEBUG("lfg.teleport", "Player %s is being teleported in to map %u "
        "(x: %f, y: %f, z: %f) Result: %u", player->GetName().c_str(), dungeon->map,
        dungeon->x, dungeon->y, dungeon->z, error);
}

/**
   Finish a dungeon and give reward, if any.

   @param[in]     guid Group guid
   @param[in]     dungeonId Dungeonid
*/
void LFGMgr::FinishDungeon(ObjectGuid gguid, const uint32 dungeonId)
{
    uint32 gDungeonId = GetDungeon(gguid);
    if (gDungeonId != dungeonId)
    {
        TC_LOG_DEBUG("lfg.dungeon.finish", "Group %s finished dungeon %u but queued for %u", gguid.ToString().c_str(), dungeonId, gDungeonId);
        return;
    }

    if (GetState(gguid) == LFG_STATE_FINISHED_DUNGEON) // Shouldn't happen. Do not reward multiple times
    {
        TC_LOG_DEBUG("lfg.dungeon.finish", "Group: %s already rewarded", gguid.ToString().c_str());
        return;
    }

    SetState(gguid, LFG_STATE_FINISHED_DUNGEON);

    GuidSet const& players = GetPlayers(gguid);
    for (GuidSet::const_iterator it = players.begin(); it != players.end(); ++it)
    {
        ObjectGuid guid = (*it);
        if (GetState(guid) == LFG_STATE_FINISHED_DUNGEON)
        {
            TC_LOG_DEBUG("lfg.dungeon.finish", "Group: %s, Player: %s already rewarded", gguid.ToString().c_str(), guid.ToString().c_str());
            continue;
        }

        uint32 rDungeonId = 0;
        const LfgDungeonSet& dungeons = GetSelectedDungeons(guid);
        if (!dungeons.empty())
            rDungeonId = (*dungeons.begin());

        SetState(guid, LFG_STATE_FINISHED_DUNGEON);

        // Give rewards only if its a random dungeon
        LFGDungeonData const* dungeon = GetLFGDungeon(rDungeonId);

        if (!dungeon || (dungeon->type != LFG_TYPE_RANDOM && !dungeon->seasonal))
        {
            TC_LOG_DEBUG("lfg.dungeon.finish", "Group: %s, Player: %s dungeon %u is not random or seasonal", gguid.ToString().c_str(), guid.ToString().c_str(), rDungeonId);
            continue;
        }

        Player* player = ObjectAccessor::FindPlayer(guid);
        if (!player)
        {
            TC_LOG_DEBUG("lfg.dungeon.finish", "Group: %s, Player: %s not found in world", gguid.ToString().c_str(), guid.ToString().c_str());
            continue;
        }

        LFGDungeonData const* dungeonDone = GetLFGDungeon(dungeonId);
        uint32 mapId = dungeonDone ? uint32(dungeonDone->map) : 0;

        if (player->GetMapId() != mapId)
        {
            TC_LOG_DEBUG("lfg.dungeon.finish", "Group: %s, Player: %s is in map %u and should be in %u to get reward", gguid.ToString().c_str(), guid.ToString().c_str(), player->GetMapId(), mapId);
            continue;
        }

        // Update achievements
        if (dungeon->difficulty == DIFFICULTY_HEROIC)
            player->UpdateCriteria(CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS, 1);

        LfgReward const* reward = GetRandomDungeonReward(rDungeonId, player->getLevel());
        if (!reward)
            continue;

        bool done = false;
        Quest const* quest = sObjectMgr->GetQuestTemplate(reward->firstQuest);
        if (!quest)
            continue;

        // if we can take the quest, means that we haven't done this kind of "run", IE: First Heroic Random of Day.
        if (player->CanRewardQuest(quest, false))
            player->RewardQuest(quest, 0, NULL, false);
        else
        {
            done = true;
            quest = sObjectMgr->GetQuestTemplate(reward->otherQuest);
            if (!quest)
                continue;
            // we give reward without informing client (retail does this)
            player->RewardQuest(quest, 0, NULL, false);
        }

        // Give rewards
        TC_LOG_DEBUG("lfg.dungeon.finish", "Group: %s, Player: %s done dungeon %u, %s previously done.", gguid.ToString().c_str(), guid.ToString().c_str(), GetDungeon(gguid), done ? " " : " not");
        LfgPlayerRewardData data = LfgPlayerRewardData(dungeon->Entry(), GetDungeon(gguid, false), done, quest);
        player->GetSession()->SendLfgPlayerReward(data);
    }
}

// --------------------------------------------------------------------------//
// Auxiliar Functions
// --------------------------------------------------------------------------//

/**
   Get the dungeon list that can be done given a random dungeon entry.

   @param[in]     randomdungeon Random dungeon id (if value = 0 will return all dungeons)
   @returns Set of dungeons that can be done.
*/
LfgDungeonSet const& LFGMgr::GetDungeonsByRandom(uint32 randomdungeon)
{
    LFGDungeonData const* dungeon = GetLFGDungeon(randomdungeon);
    uint32 group = dungeon ? dungeon->group : 0;
    return CachedDungeonMapStore[group];
}

/**
   Get the reward of a given random dungeon at a certain level

   @param[in]     dungeon dungeon id
   @param[in]     level Player level
   @returns Reward
*/
LfgReward const* LFGMgr::GetRandomDungeonReward(uint32 dungeon, uint8 level)
{
    LfgReward const* rew = NULL;
    LfgRewardContainerBounds bounds = RewardMapStore.equal_range(dungeon & 0x00FFFFFF);
    for (LfgRewardContainer::const_iterator itr = bounds.first; itr != bounds.second; ++itr)
    {
        rew = itr->second;
        // ordered properly at loading
        if (itr->second->maxLevel >= level)
            break;
    }

    return rew;
}

/**
   Given a Dungeon id returns the dungeon Type

   @param[in]     dungeon dungeon id
   @returns Dungeon type
*/
LfgType LFGMgr::GetDungeonType(uint32 dungeonId)
{
    LFGDungeonData const* dungeon = GetLFGDungeon(dungeonId);
    if (!dungeon)
        return LFG_TYPE_NONE;

    return LfgType(dungeon->type);
}

LfgState LFGMgr::GetState(ObjectGuid guid)
{
    LfgState state;
    if (guid.IsParty())
    {
        state = GroupsStore[guid].GetState();
        TC_LOG_TRACE("lfg.data.group.state.get", "Group: %s, State: %s", guid.ToString().c_str(), GetStateString(state).c_str());
    }
    else
    {
        state = PlayersStore[guid].GetState();
        TC_LOG_TRACE("lfg.data.player.state.get", "Player: %s, State: %s", guid.ToString().c_str(), GetStateString(state).c_str());
    }

    return state;
}

LfgState LFGMgr::GetOldState(ObjectGuid guid)
{
    LfgState state;
    if (guid.IsParty())
    {
        state = GroupsStore[guid].GetOldState();
        TC_LOG_TRACE("lfg.data.group.oldstate.get", "Group: %s, Old state: %u", guid.ToString().c_str(), state);
    }
    else
    {
        state = PlayersStore[guid].GetOldState();
        TC_LOG_TRACE("lfg.data.player.oldstate.get", "Player: %s, Old state: %u", guid.ToString().c_str(), state);
    }

    return state;
}

bool LFGMgr::IsVoteKickActive(ObjectGuid gguid)
{
    ASSERT(gguid.IsParty());

    bool active = GroupsStore[gguid].IsVoteKickActive();
    TC_LOG_TRACE("lfg.data.group.votekick.get", "Group: %s, Active: %d", gguid.ToString().c_str(), active);

    return active;
}

uint32 LFGMgr::GetDungeon(ObjectGuid guid, bool asId /*= true */)
{
    uint32 dungeon = GroupsStore[guid].GetDungeon(asId);
    TC_LOG_TRACE("lfg.data.group.dungeon.get", "Group: %s, asId: %u, Dungeon: %u", guid.ToString().c_str(), asId, dungeon);
    return dungeon;
}

uint32 LFGMgr::GetDungeonMapId(ObjectGuid guid)
{
    uint32 dungeonId = GroupsStore[guid].GetDungeon(true);
    uint32 mapId = 0;
    if (dungeonId)
        if (LFGDungeonData const* dungeon = GetLFGDungeon(dungeonId))
            mapId = dungeon->map;

    TC_LOG_TRACE("lfg.data.group.dungeon.map", "Group: %s, MapId: %u (DungeonId: %u)", guid.ToString().c_str(), mapId, dungeonId);

    return mapId;
}

uint8 LFGMgr::GetRoles(ObjectGuid guid)
{
    uint8 roles = PlayersStore[guid].GetRoles();
    TC_LOG_TRACE("lfg.data.player.role.get", "Player: %s, Role: %u", guid.ToString().c_str(), roles);
    return roles;
}

LfgDungeonSet const& LFGMgr::GetSelectedDungeons(ObjectGuid guid)
{
    TC_LOG_TRACE("lfg.data.player.dungeons.selected.get", "Player: %s, Selected Dungeons: %s", guid.ToString().c_str(), ConcatenateDungeons(PlayersStore[guid].GetSelectedDungeons()).c_str());
    return PlayersStore[guid].GetSelectedDungeons();
}

LfgLockMap const LFGMgr::GetLockedDungeons(ObjectGuid guid)
{
    TC_LOG_TRACE("lfg.data.player.dungeons.locked.get", "Player: %s, LockedDungeons.", guid.ToString().c_str());
    LfgLockMap lock;
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    if (!player)
    {
        TC_LOG_WARN("lfg.data.player.dungeons.locked.get", "Player: %s not ingame while retrieving his LockedDungeons.", guid.ToString().c_str());
        return lock;
    }

    uint8 level = player->getLevel();
    uint8 expansion = player->GetSession()->GetExpansion();
    LfgDungeonSet const& dungeons = GetDungeonsByRandom(0);
    bool denyJoin = !player->GetSession()->HasPermission(rbac::RBAC_PERM_JOIN_DUNGEON_FINDER);

    for (LfgDungeonSet::const_iterator it = dungeons.begin(); it != dungeons.end(); ++it)
    {
        LFGDungeonData const* dungeon = GetLFGDungeon(*it);
        if (!dungeon) // should never happen - We provide a list from sLfgDungeonsStore
            continue;

        uint32 lockStatus = 0;
        if (denyJoin)
            lockStatus = LFG_LOCKSTATUS_RAID_LOCKED;
        else if (dungeon->expansion > expansion)
            lockStatus = LFG_LOCKSTATUS_INSUFFICIENT_EXPANSION;
        else if (DisableMgr::IsDisabledFor(DISABLE_TYPE_MAP, dungeon->map, player))
            lockStatus = LFG_LOCKSTATUS_RAID_LOCKED;
        else if (DisableMgr::IsDisabledFor(DISABLE_TYPE_LFG_MAP, dungeon->map, player))
            lockStatus = LFG_LOCKSTATUS_RAID_LOCKED;
        else if (dungeon->difficulty > DIFFICULTY_NORMAL && player->GetBoundInstance(dungeon->map, Difficulty(dungeon->difficulty)))
            lockStatus = LFG_LOCKSTATUS_RAID_LOCKED;
        else if (dungeon->minlevel > level)
            lockStatus = LFG_LOCKSTATUS_TOO_LOW_LEVEL;
        else if (dungeon->maxlevel < level)
            lockStatus = LFG_LOCKSTATUS_TOO_HIGH_LEVEL;
        else if (dungeon->seasonal && !IsSeasonActive(dungeon->id))
            lockStatus = LFG_LOCKSTATUS_NOT_IN_SEASON;
        else if (dungeon->requiredItemLevel > player->GetAverageItemLevel())
            lockStatus = LFG_LOCKSTATUS_TOO_LOW_GEAR_SCORE;
        else if (AccessRequirement const* ar = sObjectMgr->GetAccessRequirement(dungeon->map, Difficulty(dungeon->difficulty)))
        {
            if (ar->achievement && !player->HasAchieved(ar->achievement))
                lockStatus = LFG_LOCKSTATUS_MISSING_ACHIEVEMENT;
            else if (player->GetTeam() == ALLIANCE && ar->quest_A && !player->GetQuestRewardStatus(ar->quest_A))
                lockStatus = LFG_LOCKSTATUS_QUEST_NOT_COMPLETED;
            else if (player->GetTeam() == HORDE && ar->quest_H && !player->GetQuestRewardStatus(ar->quest_H))
                lockStatus = LFG_LOCKSTATUS_QUEST_NOT_COMPLETED;
            else
                if (ar->item)
                {
                    if (!player->HasItemCount(ar->item) && (!ar->item2 || !player->HasItemCount(ar->item2)))
                        lockStatus = LFG_LOCKSTATUS_MISSING_ITEM;
                }
                else if (ar->item2 && !player->HasItemCount(ar->item2))
                    lockStatus = LFG_LOCKSTATUS_MISSING_ITEM;
        }

        /* @todo VoA closed if WG is not under team control (LFG_LOCKSTATUS_RAID_LOCKED)
        lockData = LFG_LOCKSTATUS_TOO_HIGH_GEAR_SCORE;
        lockData = LFG_LOCKSTATUS_ATTUNEMENT_TOO_LOW_LEVEL;
        lockData = LFG_LOCKSTATUS_ATTUNEMENT_TOO_HIGH_LEVEL;
        */

        if (lockStatus)
            lock[dungeon->Entry()] = LfgLockInfoData(lockStatus, dungeon->requiredItemLevel, player->GetAverageItemLevel());
    }

    return lock;
}

uint8 LFGMgr::GetKicksLeft(ObjectGuid guid)
{
    uint8 kicks = GroupsStore[guid].GetKicksLeft();
    TC_LOG_TRACE("lfg.data.group.kickleft.get", "Group: %s, Kicks left: %u", guid.ToString().c_str(), kicks);
    return kicks;
}

void LFGMgr::RestoreState(ObjectGuid guid, char const* debugMsg)
{
    if (guid.IsParty())
    {
        LfgGroupData& data = GroupsStore[guid];
        TC_LOG_TRACE("lfg.data.group.state.restore", "Group: %s (%s), State: %s, Old state: %s",
            guid.ToString().c_str(), debugMsg, GetStateString(data.GetState()).c_str(),
            GetStateString(data.GetOldState()).c_str());

        data.RestoreState();
    }
    else
    {
        LfgPlayerData& data = PlayersStore[guid];
        TC_LOG_TRACE("lfg.data.player.state.restore", "Player: %s (%s), State: %s, Old state: %s",
            guid.ToString().c_str(), debugMsg, GetStateString(data.GetState()).c_str(),
            GetStateString(data.GetOldState()).c_str());

        data.RestoreState();
    }
}

void LFGMgr::SetState(ObjectGuid guid, LfgState state)
{
    if (guid.IsParty())
    {
        LfgGroupData& data = GroupsStore[guid];
        TC_LOG_TRACE("lfg.data.group.state.set", "Group: %s, New state: %s, Previous: %s, Old state: %s",
            guid.ToString().c_str(), GetStateString(state).c_str(), GetStateString(data.GetState()).c_str(),
            GetStateString(data.GetOldState()).c_str());

        data.SetState(state);
    }
    else
    {
        LfgPlayerData& data = PlayersStore[guid];
        TC_LOG_TRACE("lfg.data.player.state.set", "Player: %s, New state: %s, Previous: %s, OldState: %s",
            guid.ToString().c_str(), GetStateString(state).c_str(), GetStateString(data.GetState()).c_str(),
            GetStateString(data.GetOldState()).c_str());

        data.SetState(state);
    }
}

void LFGMgr::SetVoteKick(ObjectGuid gguid, bool active)
{
    ASSERT(gguid.IsParty());

    LfgGroupData& data = GroupsStore[gguid];
    TC_LOG_TRACE("lfg.data.group.votekick.set", "Group: %s, New state: %d, Previous: %d",
        gguid.ToString().c_str(), active, data.IsVoteKickActive());

    data.SetVoteKick(active);
}

void LFGMgr::SetDungeon(ObjectGuid guid, uint32 dungeon)
{
    TC_LOG_TRACE("lfg.data.group.dungeon.set", "Group: %s, Dungeon: %u", guid.ToString().c_str(), dungeon);
    GroupsStore[guid].SetDungeon(dungeon);
}

void LFGMgr::SetRoles(ObjectGuid guid, uint8 roles)
{
    TC_LOG_TRACE("lfg.data.player.role.set", "Player: %s, Roles: %u", guid.ToString().c_str(), roles);
    PlayersStore[guid].SetRoles(roles);
}

void LFGMgr::SetSelectedDungeons(ObjectGuid guid, LfgDungeonSet const& dungeons)
{
    TC_LOG_TRACE("lfg.data.player.dungeon.selected.set", "Player: %s, Dungeons: %s", guid.ToString().c_str(), ConcatenateDungeons(dungeons).c_str());
    PlayersStore[guid].SetSelectedDungeons(dungeons);
}

void LFGMgr::DecreaseKicksLeft(ObjectGuid guid)
{
    GroupsStore[guid].DecreaseKicksLeft();
    TC_LOG_TRACE("lfg.data.group.kicksleft.decrease", "Group: %s, Kicks: %u", guid.ToString().c_str(), GroupsStore[guid].GetKicksLeft());
}

void LFGMgr::SetTicket(ObjectGuid guid, WorldPackets::LFG::RideTicket const& ticket)
{
    PlayersStore[guid].SetTicket(ticket);
}

void LFGMgr::RemovePlayerData(ObjectGuid guid)
{
    TC_LOG_TRACE("lfg.data.player.remove", "Player: %s", guid.ToString().c_str());
    LfgPlayerDataContainer::iterator it = PlayersStore.find(guid);
    if (it != PlayersStore.end())
        PlayersStore.erase(it);
}

void LFGMgr::RemoveGroupData(ObjectGuid guid)
{
    TC_LOG_TRACE("lfg.data.group.remove", "Group: %s", guid.ToString().c_str());
    LfgGroupDataContainer::iterator it = GroupsStore.find(guid);
    if (it == GroupsStore.end())
        return;

    LfgState state = GetState(guid);
    // If group is being formed after proposal success do nothing more
    GuidSet const& players = it->second.GetPlayers();
    for (ObjectGuid playerGUID : players)
    {
        SetGroup(playerGUID, ObjectGuid::Empty);
        if (state != LFG_STATE_PROPOSAL)
        {
            SetState(playerGUID, LFG_STATE_NONE);
            SendLfgUpdateStatus(playerGUID, LfgUpdateData(LFG_UPDATETYPE_REMOVED_FROM_QUEUE), true);
        }
    }
    GroupsStore.erase(it);
}

uint8 LFGMgr::GetTeam(ObjectGuid guid)
{
    uint8 team = PlayersStore[guid].GetTeam();
    TC_LOG_TRACE("lfg.data.player.team.get", "Player: %s, Team: %u", guid.ToString().c_str(), team);
    return team;
}

uint8 LFGMgr::RemovePlayerFromGroup(ObjectGuid gguid, ObjectGuid guid)
{
    return GroupsStore[gguid].RemovePlayer(guid);
}

void LFGMgr::AddPlayerToGroup(ObjectGuid gguid, ObjectGuid guid)
{
    GroupsStore[gguid].AddPlayer(guid);
}

void LFGMgr::SetLeader(ObjectGuid gguid, ObjectGuid leader)
{
    GroupsStore[gguid].SetLeader(leader);
}

void LFGMgr::SetTeam(ObjectGuid guid, uint8 team)
{
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_GROUP))
        team = 0;

    PlayersStore[guid].SetTeam(team);
}

ObjectGuid LFGMgr::GetGroup(ObjectGuid guid)
{
    return PlayersStore[guid].GetGroup();
}

void LFGMgr::SetGroup(ObjectGuid guid, ObjectGuid group)
{
    PlayersStore[guid].SetGroup(group);
}

GuidSet const& LFGMgr::GetPlayers(ObjectGuid guid)
{
    return GroupsStore[guid].GetPlayers();
}

uint8 LFGMgr::GetPlayerCount(ObjectGuid guid)
{
    return GroupsStore[guid].GetPlayerCount();
}

ObjectGuid LFGMgr::GetLeader(ObjectGuid guid)
{
    return GroupsStore[guid].GetLeader();
}

bool LFGMgr::HasIgnore(ObjectGuid guid1, ObjectGuid guid2)
{
    Player* plr1 = ObjectAccessor::FindConnectedPlayer(guid1);
    Player* plr2 = ObjectAccessor::FindConnectedPlayer(guid2);
    return plr1 && plr2 && (plr1->GetSocial()->HasIgnore(guid2) || plr2->GetSocial()->HasIgnore(guid1));
}

void LFGMgr::SendLfgRoleChosen(ObjectGuid guid, ObjectGuid pguid, uint8 roles)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgRoleChosen(pguid, roles);
}

void LFGMgr::SendLfgRoleCheckUpdate(ObjectGuid guid, LfgRoleCheck const& roleCheck)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgRoleCheckUpdate(roleCheck);
}

void LFGMgr::SendLfgUpdateStatus(ObjectGuid guid, LfgUpdateData const& data, bool party)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgUpdateStatus(data, party);
}

void LFGMgr::SendLfgJoinResult(ObjectGuid guid, LfgJoinResultData const& data)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgJoinResult(data);
}

void LFGMgr::SendLfgBootProposalUpdate(ObjectGuid guid, LfgPlayerBoot const& boot)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgBootProposalUpdate(boot);
}

void LFGMgr::SendLfgUpdateProposal(ObjectGuid guid, LfgProposal const& proposal)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgUpdateProposal(proposal);
}

void LFGMgr::SendLfgQueueStatus(ObjectGuid guid, LfgQueueStatusData const& data)
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->GetSession()->SendLfgQueueStatus(data);
}

bool LFGMgr::IsLfgGroup(ObjectGuid guid)
{
    return !guid.IsEmpty() && guid.IsParty() && GroupsStore[guid].IsLfgGroup();
}

uint8 LFGMgr::GetQueueId(ObjectGuid guid)
{
    if (guid.IsParty())
    {
        GuidSet const& players = GetPlayers(guid);
        ObjectGuid pguid = players.empty() ? ObjectGuid::Empty : (*players.begin());
        if (!pguid.IsEmpty())
            return GetTeam(pguid);
    }

    return GetTeam(guid);
}

LFGQueue& LFGMgr::GetQueue(ObjectGuid guid)
{
    uint8 queueId = GetQueueId(guid);
    return QueuesStore[queueId];
}

bool LFGMgr::AllQueued(GuidList const& check)
{
    if (check.empty())
        return false;

    for (GuidList::const_iterator it = check.begin(); it != check.end(); ++it)
    {
        LfgState state = GetState(*it);
        if (state != LFG_STATE_QUEUED)
        {
            if (state != LFG_STATE_PROPOSAL)
                TC_LOG_DEBUG("lfg.allqueued", "Unexpected state found while trying to form new group. Guid: %s, State: %s", (*it).ToString().c_str(), GetStateString(state).c_str());

            return false;
        }
    }
    return true;
}

time_t LFGMgr::GetQueueJoinTime(ObjectGuid guid)
{
    uint8 queueId = GetQueueId(guid);
    LfgQueueContainer::const_iterator itr = QueuesStore.find(queueId);
    if (itr != QueuesStore.end())
        return itr->second.GetJoinTime(guid);

    return 0;
}

// Only for debugging purposes
void LFGMgr::Clean()
{
    QueuesStore.clear();
}

bool LFGMgr::isOptionEnabled(uint32 option)
{
    return (m_options & option) != 0;
}

uint32 LFGMgr::GetOptions()
{
    return m_options;
}

void LFGMgr::SetOptions(uint32 options)
{
    m_options = options;
}

LfgUpdateData LFGMgr::GetLfgStatus(ObjectGuid guid)
{
    LfgPlayerData& playerData = PlayersStore[guid];
    return LfgUpdateData(LFG_UPDATETYPE_UPDATE_STATUS, playerData.GetState(), playerData.GetSelectedDungeons());
}

bool LFGMgr::IsSeasonActive(uint32 dungeonId)
{
    switch (dungeonId)
    {
        case 285: // The Headless Horseman
            return IsHolidayActive(HOLIDAY_HALLOWS_END);
        case 286: // The Frost Lord Ahune
            return IsHolidayActive(HOLIDAY_FIRE_FESTIVAL);
        case 287: // Coren Direbrew
            return IsHolidayActive(HOLIDAY_BREWFEST);
        case 288: // The Crown Chemical Co.
            return IsHolidayActive(HOLIDAY_LOVE_IS_IN_THE_AIR);
    }
    return false;
}

std::string LFGMgr::DumpQueueInfo(bool full)
{
    uint32 size = uint32(QueuesStore.size());
    std::ostringstream o;

    o << "Number of Queues: " << size << "\n";
    for (LfgQueueContainer::const_iterator itr = QueuesStore.begin(); itr != QueuesStore.end(); ++itr)
    {
        std::string const& queued = itr->second.DumpQueueInfo();
        std::string const& compatibles = itr->second.DumpCompatibleInfo(full);
        o << queued << compatibles;
    }

    return o.str();
}

void LFGMgr::SetupGroupMember(ObjectGuid guid, ObjectGuid gguid)
{
    LfgDungeonSet dungeons;
    dungeons.insert(GetDungeon(gguid));
    SetSelectedDungeons(guid, dungeons);
    SetState(guid, GetState(gguid));
    SetGroup(guid, gguid);
    AddPlayerToGroup(gguid, guid);
}

bool LFGMgr::selectedRandomLfgDungeon(ObjectGuid guid)
{
    if (GetState(guid) != LFG_STATE_NONE)
    {
        LfgDungeonSet const& dungeons = GetSelectedDungeons(guid);
        if (!dungeons.empty())
        {
             LFGDungeonData const* dungeon = GetLFGDungeon(*dungeons.begin());
             if (dungeon && (dungeon->type == LFG_TYPE_RANDOM || dungeon->seasonal))
                 return true;
        }
    }

    return false;
}

bool LFGMgr::inLfgDungeonMap(ObjectGuid guid, uint32 map, Difficulty difficulty)
{
    if (!guid.IsParty())
        guid = GetGroup(guid);

    if (uint32 dungeonId = GetDungeon(guid, true))
        if (LFGDungeonData const* dungeon = GetLFGDungeon(dungeonId))
            if (uint32(dungeon->map) == map && dungeon->difficulty == difficulty)
                return true;

    return false;
}

uint32 LFGMgr::GetLFGDungeonEntry(uint32 id)
{
    if (id)
        if (LFGDungeonData const* dungeon = GetLFGDungeon(id))
            return dungeon->Entry();

    return 0;
}

LfgDungeonSet LFGMgr::GetRandomAndSeasonalDungeons(uint8 level, uint8 expansion)
{
    LfgDungeonSet randomDungeons;
    for (lfg::LFGDungeonContainer::const_iterator itr = LfgDungeonStore.begin(); itr != LfgDungeonStore.end(); ++itr)
    {
        lfg::LFGDungeonData const& dungeon = itr->second;
        if ((dungeon.type == lfg::LFG_TYPE_RANDOM || (dungeon.seasonal && sLFGMgr->IsSeasonActive(dungeon.id)))
            && dungeon.expansion <= expansion && dungeon.minlevel <= level && level <= dungeon.maxlevel)
            randomDungeons.insert(dungeon.Entry());
    }
    return randomDungeons;
}

} // namespace lfg
