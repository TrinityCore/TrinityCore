/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "ArenaTeamMgr.h"
#include "WorldPacket.h"
#include "WorldSession.h"

#include "ArenaTeam.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "Chat.h"
#include "Language.h"
#include "Log.h"
#include "Player.h"
#include "Object.h"
#include "Opcodes.h"
#include "DisableMgr.h"
#include "Group.h"

void WorldSession::HandleBattlemasterHelloOpcode(WorldPacket& recvData)
{
    uint64 guid;
    recvData >> guid;
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_BATTLEMASTER_HELLO Message from (GUID: %u TypeId:%u)", GUID_LOPART(guid), GuidHigh2TypeId(GUID_HIPART(guid)));

    Creature* unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if (!unit->IsBattleMaster())                             // it's not battlemaster
        return;

    // Stop the npc if moving
    unit->StopMoving();

    BattlegroundTypeId bgTypeId = sBattlegroundMgr->GetBattleMasterBG(unit->GetEntry());

    if (!_player->GetBGAccessByLevel(bgTypeId))
    {
                                                            // temp, must be gossip message...
        SendNotification(LANG_YOUR_BG_LEVEL_REQ_ERROR);
        return;
    }

    SendBattleGroundList(guid, bgTypeId);
}

void WorldSession::SendBattleGroundList(uint64 guid, BattlegroundTypeId bgTypeId)
{
    WorldPacket data;
    sBattlegroundMgr->BuildBattlegroundListPacket(&data, guid, _player, bgTypeId, 0);
    SendPacket(&data);
}

void WorldSession::HandleBattlemasterJoinOpcode(WorldPacket& recvData)
{
    uint64 guid;
    uint32 bgTypeId_;
    uint32 instanceId;
    uint8 joinAsGroup;
    bool isPremade = false;
    Group* grp = NULL;

    recvData >> guid;                                      // battlemaster guid
    recvData >> bgTypeId_;                                 // battleground type id (DBC id)
    recvData >> instanceId;                                // instance id, 0 if First Available selected
    recvData >> joinAsGroup;                               // join as group

    if (!sBattlemasterListStore.LookupEntry(bgTypeId_))
    {
        TC_LOG_ERROR("network", "Battleground: invalid bgtype (%u) received. possible cheater? player guid %u", bgTypeId_, _player->GetGUIDLow());
        return;
    }

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, bgTypeId_, NULL))
    {
        ChatHandler(this).PSendSysMessage(LANG_BG_DISABLED);
        return;
    }

    BattlegroundTypeId bgTypeId = BattlegroundTypeId(bgTypeId_);

    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_BATTLEMASTER_JOIN Message from (GUID: %u TypeId:%u)", GUID_LOPART(guid), GuidHigh2TypeId(GUID_HIPART(guid)));

    // can do this, since it's battleground, not arena
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, 0);
    BattlegroundQueueTypeId bgQueueTypeIdRandom = BattlegroundMgr::BGQueueTypeId(BATTLEGROUND_RB, 0);

    // ignore if player is already in BG
    if (_player->InBattleground())
        return;

    // get bg instance or bg template if instance not found
    Battleground* bg = NULL;
    if (instanceId)
        bg = sBattlegroundMgr->GetBattlegroundThroughClientInstance(instanceId, bgTypeId);

    if (!bg)
        bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
    if (!bg)
        return;

    // expected bracket entry
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->getLevel());
    if (!bracketEntry)
        return;

    GroupJoinBattlegroundResult err;

    // check queue conditions
    if (!joinAsGroup)
    {
        if (GetPlayer()->isUsingLfg())
        {
            // player is using dungeon finder or raid finder
            WorldPacket data;
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, ERR_LFG_CANT_USE_BATTLEGROUND);
            GetPlayer()->GetSession()->SendPacket(&data);
            return;
        }

        // check Deserter debuff
        if (!_player->CanJoinToBattleground(bg))
        {
            WorldPacket data;
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
            _player->GetSession()->SendPacket(&data);
            return;
        }

        if (_player->GetBattlegroundQueueIndex(bgQueueTypeIdRandom) < PLAYER_MAX_BATTLEGROUND_QUEUES)
        {
            // player is already in random queue
            WorldPacket data;
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, ERR_IN_RANDOM_BG);
            _player->GetSession()->SendPacket(&data);
            return;
        }

        if (_player->InBattlegroundQueue() && bgTypeId == BATTLEGROUND_RB)
        {
            // player is already in queue, can't start random queue
            WorldPacket data;
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, ERR_IN_NON_RANDOM_BG);
            _player->GetSession()->SendPacket(&data);
            return;
        }

        // check if already in queue
        if (_player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            // player is already in this queue
            return;

        // check if has free queue slots
        if (!_player->HasFreeBattlegroundQueueId())
        {
            WorldPacket data;
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, ERR_BATTLEGROUND_TOO_MANY_QUEUES);
            _player->GetSession()->SendPacket(&data);
            return;
        }

        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);

        GroupQueueInfo* ginfo = bgQueue.AddGroup(_player, NULL, bgTypeId, bracketEntry, 0, false, isPremade, 0, 0);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        // already checked if queueSlot is valid, now just get it
        uint32 queueSlot = _player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPacket data;
                                                            // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, ginfo->ArenaType, 0);
        SendPacket(&data);
        TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for bg queue type %u bg type %u: GUID %u, NAME %s",
                       bgQueueTypeId, bgTypeId, _player->GetGUIDLow(), _player->GetName().c_str());
    }
    else
    {
        grp = _player->GetGroup();
        // no group found, error
        if (!grp)
            return;
        if (grp->GetLeaderGUID() != _player->GetGUID())
            return;
        err = grp->CanJoinBattlegroundQueue(bg, bgQueueTypeId, 0, bg->GetMaxPlayersPerTeam(), false, 0);
        isPremade = (grp->GetMembersCount() >= bg->GetMinPlayersPerTeam());

        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo* ginfo = NULL;
        uint32 avgTime = 0;

        if (err > 0)
        {
            TC_LOG_DEBUG("bg.battleground", "Battleground: the following players are joining as group:");
            ginfo = bgQueue.AddGroup(_player, grp, bgTypeId, bracketEntry, 0, false, isPremade, 0, 0);
            avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        }

        for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* member = itr->GetSource();
            if (!member)
                continue;   // this should never happen

            WorldPacket data;

            if (err <= 0)
            {
                sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, err);
                member->GetSession()->SendPacket(&data);
                continue;
            }

            // add to queue
            uint32 queueSlot = member->AddBattlegroundQueueId(bgQueueTypeId);

            // send status packet (in queue)
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, ginfo->ArenaType, 0);
            member->GetSession()->SendPacket(&data);
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, err);
            member->GetSession()->SendPacket(&data);
            TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for bg queue type %u bg type %u: GUID %u, NAME %s",
                bgQueueTypeId, bgTypeId, member->GetGUIDLow(), member->GetName().c_str());
        }
        TC_LOG_DEBUG("bg.battleground", "Battleground: group end");
    }
    sBattlegroundMgr->ScheduleQueueUpdate(0, 0, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());
}

void WorldSession::HandleBattlegroundPlayerPositionsOpcode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd MSG_BATTLEGROUND_PLAYER_POSITIONS Message");

    Battleground* bg = _player->GetBattleground();
    if (!bg)                                                 // can't be received if player not in battleground
        return;

    uint32 flagCarrierCount = 0;
    Player* allianceFlagCarrier = NULL;
    Player* hordeFlagCarrier = NULL;

    if (uint64 guid = bg->GetFlagPickerGUID(TEAM_ALLIANCE))
    {
        allianceFlagCarrier = ObjectAccessor::FindPlayer(guid);
        if (allianceFlagCarrier)
            ++flagCarrierCount;
    }

    if (uint64 guid = bg->GetFlagPickerGUID(TEAM_HORDE))
    {
        hordeFlagCarrier = ObjectAccessor::FindPlayer(guid);
        if (hordeFlagCarrier)
            ++flagCarrierCount;
    }

    WorldPacket data(MSG_BATTLEGROUND_PLAYER_POSITIONS, 4 + 4 + 16 * flagCarrierCount);
    // Used to send several player positions (found used in AV)
    data << 0;  // CGBattlefieldInfo__m_numPlayerPositions
    /*
    for (CGBattlefieldInfo__m_numPlayerPositions)
        data << guid << posx << posy;
    */
    data << flagCarrierCount;
    if (allianceFlagCarrier)
    {
        data << uint64(allianceFlagCarrier->GetGUID());
        data << float(allianceFlagCarrier->GetPositionX());
        data << float(allianceFlagCarrier->GetPositionY());
    }

    if (hordeFlagCarrier)
    {
        data << uint64(hordeFlagCarrier->GetGUID());
        data << float(hordeFlagCarrier->GetPositionX());
        data << float(hordeFlagCarrier->GetPositionY());
    }

    SendPacket(&data);
}

void WorldSession::HandlePVPLogDataOpcode(WorldPacket & /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd MSG_PVP_LOG_DATA Message");

    Battleground* bg = _player->GetBattleground();
    if (!bg)
        return;

    // Prevent players from sending BuildPvpLogDataPacket in an arena except for when sent in BattleGround::EndBattleGround.
    if (bg->isArena())
        return;

    WorldPacket data;
    sBattlegroundMgr->BuildPvpLogDataPacket(&data, bg);
    SendPacket(&data);

    TC_LOG_DEBUG("network", "WORLD: Sent MSG_PVP_LOG_DATA Message");
}

void WorldSession::HandleBattlefieldListOpcode(WorldPacket &recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_BATTLEFIELD_LIST Message");

    uint32 bgTypeId;
    recvData >> bgTypeId;                                  // id from DBC

    uint8 fromWhere;
    recvData >> fromWhere;                                 // 0 - battlemaster (lua: ShowBattlefieldList), 1 - UI (lua: RequestBattlegroundInstanceInfo)

    uint8 canGainXP;
    recvData >> canGainXP;                                 // players with locked xp have their own bg queue on retail

    BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(bgTypeId);
    if (!bl)
    {
        TC_LOG_DEBUG("bg.battleground", "BattlegroundHandler: invalid bgtype (%u) with player (Name: %s, GUID: %u) received.", bgTypeId, _player->GetName().c_str(), _player->GetGUIDLow());
        return;
    }

    WorldPacket data;
    sBattlegroundMgr->BuildBattlegroundListPacket(&data, 0, _player, BattlegroundTypeId(bgTypeId), fromWhere);
    SendPacket(&data);
}

void WorldSession::HandleBattleFieldPortOpcode(WorldPacket &recvData)
{
    uint8 type;                                             // arenatype if arena
    uint8 unk2;                                             // unk, can be 0x0 (may be if was invited?) and 0x1
    uint32 bgTypeId_;                                       // type id from dbc
    uint16 unk;                                             // 0x1F90 constant?
    uint8 action;                                           // enter battle 0x1, leave queue 0x0

    recvData >> type >> unk2 >> bgTypeId_ >> unk >> action;
    if (!sBattlemasterListStore.LookupEntry(bgTypeId_))
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT %s ArenaType: %u, Unk: %u, BgType: %u, Action: %u. Invalid BgType!",
            GetPlayerInfo().c_str(), type, unk2, bgTypeId_, action);
        return;
    }

    if (!_player->InBattlegroundQueue())
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT %s ArenaType: %u, Unk: %u, BgType: %u, Action: %u. Player not in queue!",
            GetPlayerInfo().c_str(), type, unk2, bgTypeId_, action);
        return;
    }

    //get GroupQueueInfo from BattlegroundQueue
    BattlegroundTypeId bgTypeId = BattlegroundTypeId(bgTypeId_);
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, type);
    BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
    //we must use temporary variable, because GroupQueueInfo pointer can be deleted in BattlegroundQueue::RemovePlayer() function
    GroupQueueInfo ginfo;
    if (!bgQueue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT %s ArenaType: %u, Unk: %u, BgType: %u, Action: %u. Player not in queue (No player Group Info)!",
            GetPlayerInfo().c_str(), type, unk2, bgTypeId_, action);
        return;
    }
    // if action == 1, then instanceId is required
    if (!ginfo.IsInvitedToBGInstanceGUID && action == 1)
    {
        TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT %s ArenaType: %u, Unk: %u, BgType: %u, Action: %u. Player is not invited to any bg!",
            GetPlayerInfo().c_str(), type, unk2, bgTypeId_, action);
        return;
    }

    Battleground* bg = sBattlegroundMgr->GetBattleground(ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
    if (!bg)
    {
        if (action)
        {
            TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT %s ArenaType: %u, Unk: %u, BgType: %u, Action: %u. Cant find BG with id %u!",
                GetPlayerInfo().c_str(), type, unk2, bgTypeId_, action, ginfo.IsInvitedToBGInstanceGUID);
            return;
        }

        bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
        if (!bg)
        {
            TC_LOG_ERROR("network", "BattlegroundHandler: bg_template not found for type id %u.", bgTypeId);
            return;
        }
    }

    TC_LOG_DEBUG("bg.battleground", "CMSG_BATTLEFIELD_PORT %s ArenaType: %u, Unk: %u, BgType: %u, Action: %u.",
        GetPlayerInfo().c_str(), type, unk2, bgTypeId_, action);

    // expected bracket entry
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->getLevel());
    if (!bracketEntry)
        return;

    //some checks if player isn't cheating - it is not exactly cheating, but we cannot allow it
    if (action == 1 && ginfo.ArenaType == 0)
    {
        //if player is trying to enter battleground (not arena!) and he has deserter debuff, we must just remove him from queue
        if (!_player->CanJoinToBattleground(bg))
        {
            //send bg command result to show nice message
            WorldPacket data2;
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data2, ERR_GROUP_JOIN_BATTLEGROUND_DESERTERS);
            _player->GetSession()->SendPacket(&data2);
            action = 0;
            TC_LOG_DEBUG("bg.battleground", "Player %s (%u) has a deserter debuff, do not port him to battleground!", _player->GetName().c_str(), _player->GetGUIDLow());
        }
        //if player don't match battleground max level, then do not allow him to enter! (this might happen when player leveled up during his waiting in queue
        if (_player->getLevel() > bg->GetMaxLevel())
        {
            TC_LOG_ERROR("network", "Player %s (%u) has level (%u) higher than maxlevel (%u) of battleground (%u)! Do not port him to battleground!",
                _player->GetName().c_str(), _player->GetGUIDLow(), _player->getLevel(), bg->GetMaxLevel(), bg->GetTypeID());
            action = 0;
        }
    }
    uint32 queueSlot = _player->GetBattlegroundQueueIndex(bgQueueTypeId);
    WorldPacket data;
    if (action)
    {
        if (!_player->IsInvitedForBattlegroundQueueType(bgQueueTypeId))
            return;                                 // cheating?

        if (!_player->InBattleground())
            _player->SetBattlegroundEntryPoint();

        // resurrect the player
        if (!_player->IsAlive())
        {
            _player->ResurrectPlayer(1.0f);
            _player->SpawnCorpseBones();
        }
        // stop taxi flight at port
        if (_player->IsInFlight())
        {
            _player->GetMotionMaster()->MovementExpired();
            _player->CleanupAfterTaxiFlight();
        }

        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_IN_PROGRESS, 0, bg->GetStartTime(), bg->GetArenaType(), ginfo.Team);
        _player->GetSession()->SendPacket(&data);

        // remove battleground queue status from BGmgr
        bgQueue.RemovePlayer(_player->GetGUID(), false);
        // this is still needed here if battleground "jumping" shouldn't add deserter debuff
        // also this is required to prevent stuck at old battleground after SetBattlegroundId set to new
        if (Battleground* currentBg = _player->GetBattleground())
            currentBg->RemovePlayerAtLeave(_player->GetGUID(), false, true);

        // set the destination instance id
        _player->SetBattlegroundId(bg->GetInstanceID(), bgTypeId);
        // set the destination team
        _player->SetBGTeam(ginfo.Team);

        // bg->HandleBeforeTeleportToBattleground(_player);
        sBattlegroundMgr->SendToBattleground(_player, ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
        // add only in HandleMoveWorldPortAck()
        // bg->AddPlayer(_player, team);
        TC_LOG_DEBUG("bg.battleground", "Battleground: player %s (%u) joined battle for bg %u, bgtype %u, queue type %u.", _player->GetName().c_str(), _player->GetGUIDLow(), bg->GetInstanceID(), bg->GetTypeID(), bgQueueTypeId);
    }
    else // leave queue
    {
        if (bg->isArena() && bg->GetStatus() > STATUS_WAIT_QUEUE)
            return;

        // if player leaves rated arena match before match start, it is counted as he played but he lost
        if (ginfo.IsRated && ginfo.IsInvitedToBGInstanceGUID)
        {
            ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ginfo.Team);
            if (at)
            {
                TC_LOG_DEBUG("bg.battleground", "UPDATING memberLost's personal arena rating for %u by opponents rating: %u, because he has left queue!", GUID_LOPART(_player->GetGUID()), ginfo.OpponentsTeamRating);
                at->MemberLost(_player, ginfo.OpponentsMatchmakerRating);
                at->SaveToDB();
            }
        }
        _player->RemoveBattlegroundQueueId(bgQueueTypeId);  // must be called this way, because if you move this call to queue->removeplayer, it causes bugs
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0, 0);
        bgQueue.RemovePlayer(_player->GetGUID(), true);
        // player left queue, we should update it - do not update Arena Queue
        if (!ginfo.ArenaType)
            sBattlegroundMgr->ScheduleQueueUpdate(ginfo.ArenaMatchmakerRating, ginfo.ArenaType, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());
        SendPacket(&data);
        TC_LOG_DEBUG("bg.battleground", "Battleground: player %s (%u) left queue for bgtype %u, queue type %u.", _player->GetName().c_str(), _player->GetGUIDLow(), bg->GetTypeID(), bgQueueTypeId);
    }
}

void WorldSession::HandleBattlefieldLeaveOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Recvd CMSG_LEAVE_BATTLEFIELD Message");

    recvData.read_skip<uint8>();                           // unk1
    recvData.read_skip<uint8>();                           // unk2
    recvData.read_skip<uint32>();                          // BattlegroundTypeId
    recvData.read_skip<uint16>();                          // unk3

    // not allow leave battleground in combat
    if (_player->IsInCombat())
        if (Battleground* bg = _player->GetBattleground())
            if (bg->GetStatus() != STATUS_WAIT_LEAVE)
                return;

    _player->LeaveBattleground();
}

void WorldSession::HandleBattlefieldStatusOpcode(WorldPacket & /*recvData*/)
{
    // empty opcode
    TC_LOG_DEBUG("network", "WORLD: Battleground status");

    WorldPacket data;
    // we must update all queues here
    Battleground* bg = NULL;
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
    {
        BattlegroundQueueTypeId bgQueueTypeId = _player->GetBattlegroundQueueTypeId(i);
        if (!bgQueueTypeId)
            continue;
        BattlegroundTypeId bgTypeId = BattlegroundMgr::BGTemplateId(bgQueueTypeId);
        uint8 arenaType = BattlegroundMgr::BGArenaType(bgQueueTypeId);
        if (bgTypeId == _player->GetBattlegroundTypeId())
        {
            bg = _player->GetBattleground();
            //i cannot check any variable from player class because player class doesn't know if player is in 2v2 / 3v3 or 5v5 arena
            //so i must use bg pointer to get that information
            if (bg && bg->GetArenaType() == arenaType)
            {
                // this line is checked, i only don't know if GetStartTime is changing itself after bg end!
                // send status in Battleground
                sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, i, STATUS_IN_PROGRESS, bg->GetEndTime(), bg->GetStartTime(), arenaType, _player->GetBGTeam());
                SendPacket(&data);
                continue;
            }
        }
        //we are sending update to player about queue - he can be invited there!
        //get GroupQueueInfo for queue status
        BattlegroundQueue& bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
        GroupQueueInfo ginfo;
        if (!bgQueue.GetPlayerGroupInfoData(_player->GetGUID(), &ginfo))
            continue;
        if (ginfo.IsInvitedToBGInstanceGUID)
        {
            bg = sBattlegroundMgr->GetBattleground(ginfo.IsInvitedToBGInstanceGUID, bgTypeId);
            if (!bg)
                continue;
            uint32 remainingTime = getMSTimeDiff(getMSTime(), ginfo.RemoveInviteTime);
            // send status invited to Battleground
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, i, STATUS_WAIT_JOIN, remainingTime, 0, arenaType, 0);
            SendPacket(&data);
        }
        else
        {
            bg = sBattlegroundMgr->GetBattlegroundTemplate(bgTypeId);
            if (!bg)
                continue;

            // expected bracket entry
            PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->getLevel());
            if (!bracketEntry)
                continue;

            uint32 avgTime = bgQueue.GetAverageQueueWaitTime(&ginfo, bracketEntry->GetBracketId());
            // send status in Battleground Queue
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, i, STATUS_WAIT_QUEUE, avgTime, getMSTimeDiff(ginfo.JoinTime, getMSTime()), arenaType, 0);
            SendPacket(&data);
        }
    }
}

void WorldSession::HandleBattlemasterJoinArena(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_BATTLEMASTER_JOIN_ARENA");

    uint64 guid;                                            // arena Battlemaster guid
    uint8 arenaslot;                                        // 2v2, 3v3 or 5v5
    uint8 asGroup;                                          // asGroup
    uint8 isRated;                                          // isRated
    Group* grp = NULL;

    recvData >> guid >> arenaslot >> asGroup >> isRated;

    // ignore if we already in BG or BG queue
    if (_player->InBattleground())
        return;

    Creature* unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if (!unit->IsBattleMaster())                             // it's not battle master
        return;

    uint8 arenatype = 0;
    uint32 arenaRating = 0;
    uint32 matchmakerRating = 0;

    switch (arenaslot)
    {
        case 0:
            arenatype = ARENA_TYPE_2v2;
            break;
        case 1:
            arenatype = ARENA_TYPE_3v3;
            break;
        case 2:
            arenatype = ARENA_TYPE_5v5;
            break;
        default:
            TC_LOG_ERROR("network", "Unknown arena slot %u at HandleBattlemasterJoinArena()", arenaslot);
            return;
    }

    //check existance
    Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
    if (!bg)
    {
        TC_LOG_ERROR("network", "Battleground: template bg (all arenas) not found");
        return;
    }

    if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
    {
        ChatHandler(this).PSendSysMessage(LANG_ARENA_DISABLED);
        return;
    }

    BattlegroundTypeId bgTypeId = bg->GetTypeID();
    BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
    PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), _player->getLevel());
    if (!bracketEntry)
        return;

    GroupJoinBattlegroundResult err = ERR_GROUP_JOIN_BATTLEGROUND_FAIL;

    if (!asGroup)
    {
        // check if already in queue
        if (_player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return;
        // check if has free queue slots
        if (!_player->HasFreeBattlegroundQueueId())
            return;
    }
    else
    {
        grp = _player->GetGroup();
        // no group found, error
        if (!grp)
            return;
        if (grp->GetLeaderGUID() != _player->GetGUID())
            return;
        err = grp->CanJoinBattlegroundQueue(bg, bgQueueTypeId, arenatype, arenatype, (bool)isRated, arenaslot);
    }

    uint32 ateamId = 0;

    if (isRated)
    {
        ateamId = _player->GetArenaTeamId(arenaslot);
        // check real arenateam existence only here (if it was moved to group->CanJoin .. () then we would ahve to get it twice)
        ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ateamId);
        if (!at)
        {
            _player->GetSession()->SendNotInArenaTeamPacket(arenatype);
            return;
        }
        // get the team rating for queueing
        arenaRating = at->GetRating();
        matchmakerRating = at->GetAverageMMR(grp);
        // the arenateam id must match for everyone in the group

        if (arenaRating <= 0)
            arenaRating = 1;
    }

    BattlegroundQueue &bgQueue = sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId);
    if (asGroup)
    {
        uint32 avgTime = 0;

        if (err > 0)
        {
            TC_LOG_DEBUG("bg.battleground", "Battleground: arena join as group start");
            if (isRated)
            {
                TC_LOG_DEBUG("bg.battleground", "Battleground: arena team id %u, leader %s queued with matchmaker rating %u for type %u", _player->GetArenaTeamId(arenaslot), _player->GetName().c_str(), matchmakerRating, arenatype);
                bg->SetRated(true);
            }
            else
                bg->SetRated(false);

            GroupQueueInfo* ginfo = bgQueue.AddGroup(_player, grp, bgTypeId, bracketEntry, arenatype, isRated, false, arenaRating, matchmakerRating, ateamId);
            avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        }

        for (GroupReference* itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player* member = itr->GetSource();
            if (!member)
                continue;

            WorldPacket data;

            if (err <= 0)
            {
                sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, err);
                member->GetSession()->SendPacket(&data);
                continue;
            }

            // add to queue
            uint32 queueSlot = member->AddBattlegroundQueueId(bgQueueTypeId);

            // send status packet (in queue)
            sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype, 0);
            member->GetSession()->SendPacket(&data);
            sBattlegroundMgr->BuildGroupJoinedBattlegroundPacket(&data, err);
            member->GetSession()->SendPacket(&data);
            TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for arena as group bg queue type %u bg type %u: GUID %u, NAME %s", bgQueueTypeId, bgTypeId, member->GetGUIDLow(), member->GetName().c_str());
        }
    }
    else
    {
        GroupQueueInfo* ginfo = bgQueue.AddGroup(_player, NULL, bgTypeId, bracketEntry, arenatype, isRated, false, arenaRating, matchmakerRating, ateamId);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        uint32 queueSlot = _player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPacket data;
        // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype, 0);
        SendPacket(&data);
        TC_LOG_DEBUG("bg.battleground", "Battleground: player joined queue for arena, skirmish, bg queue type %u bg type %u: GUID %u, NAME %s", bgQueueTypeId, bgTypeId, _player->GetGUIDLow(), _player->GetName().c_str());
    }
    sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());
}

void WorldSession::HandleReportPvPAFK(WorldPacket& recvData)
{
    uint64 playerGuid;
    recvData >> playerGuid;
    Player* reportedPlayer = ObjectAccessor::FindPlayer(playerGuid);

    if (!reportedPlayer)
    {
        TC_LOG_DEBUG("bg.battleground", "WorldSession::HandleReportPvPAFK: player not found");
        return;
    }

    TC_LOG_DEBUG("bg.battleground", "WorldSession::HandleReportPvPAFK: %s reported %s", _player->GetName().c_str(), reportedPlayer->GetName().c_str());

    reportedPlayer->ReportedAfkBy(_player);
}
