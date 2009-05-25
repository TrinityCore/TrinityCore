/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "WorldPacket.h"
#include "Opcodes.h"
#include "Log.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "WorldSession.h"
#include "ObjectAccessor.h"
#include "Object.h"
#include "Chat.h"
#include "BattleGroundMgr.h"
#include "BattleGroundWS.h"
#include "BattleGround.h"
#include "ArenaTeam.h"
#include "Language.h"

void WorldSession::HandleBattleGroundHelloOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;
    recv_data >> guid;
    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEMASTER_HELLO Message from: " I64FMT, guid);

    Creature *unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if(!unit->isBattleMaster())                             // it's not battlemaster
        return;

    // Stop the npc if moving
    unit->StopMoving();

    BattleGroundTypeId bgTypeId = sBattleGroundMgr.GetBattleMasterBG(unit->GetEntry());

    if (!_player->GetBGAccessByLevel(bgTypeId))
    {
                                                            // temp, must be gossip message...
        SendNotification(LANG_YOUR_BG_LEVEL_REQ_ERROR);
        return;
    }

    SendBattlegGroundList(guid, bgTypeId);
}

void WorldSession::SendBattlegGroundList( uint64 guid, BattleGroundTypeId bgTypeId )
{
    WorldPacket data;
    sBattleGroundMgr.BuildBattleGroundListPacket(&data, guid, _player, bgTypeId);
    SendPacket( &data );
}

void WorldSession::HandleBattleGroundJoinOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+4+4+1);

    uint64 guid;
    uint32 bgTypeId_;
    uint32 instanceId;
    uint8 joinAsGroup;
    bool isPremade = false;
    Group * grp;

    recv_data >> guid;                                      // battlemaster guid
    recv_data >> bgTypeId_;                                 // battleground type id (DBC id)
    recv_data >> instanceId;                                // instance id, 0 if First Available selected
    recv_data >> joinAsGroup;                               // join as group

    if (!sBattlemasterListStore.LookupEntry(bgTypeId_))
    {
        sLog.outError("Battleground: invalid bgtype (%u) received. possible cheater? player guid %u",bgTypeId_,_player->GetGUIDLow());
        return;
    }

    BattleGroundTypeId bgTypeId = BattleGroundTypeId(bgTypeId_);

    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEMASTER_JOIN Message from: " I64FMT, guid);

    // can do this, since it's battleground, not arena
    BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(bgTypeId, 0);

    // ignore if player is already in BG
    if (_player->InBattleGround())
        return;

    Creature *unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if(!unit->isBattleMaster())                             // it's not battlemaster
        return;

    // get bg instance or bg template if instance not found
    BattleGround *bg = NULL;
    if (instanceId)
        bg = sBattleGroundMgr.GetBattleGroundThroughClientInstance(instanceId, bgTypeId);

    if (!bg && !(bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId)))
    {
        sLog.outError("Battleground: no available bg / template found");
        return;
    }

    // check queueing conditions
    if (!joinAsGroup)
    {
        // check Deserter debuff
        if (!_player->CanJoinToBattleground())
        {
            WorldPacket data(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
            data << uint32(0xFFFFFFFE);
            _player->GetSession()->SendPacket(&data);
            return;
        }
        // check if already in queue
        if (_player->GetBattleGroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return;
        // check if has free queue slots
        if (!_player->HasFreeBattleGroundQueueId())
            return;
    }
    else
    {
        grp = _player->GetGroup();
        // no group found, error
        if (!grp)
            return;
        uint32 err = grp->CanJoinBattleGroundQueue(bgTypeId, bgQueueTypeId, 0, bg->GetMaxPlayersPerTeam(), false, 0);
        isPremade = (grp->GetMembersCount() >= bg->GetMinPlayersPerTeam());
        if (err != BG_JOIN_ERR_OK)
        {
            SendBattleGroundOrArenaJoinError(err);
            return;
        }
    }
    // if we're here, then the conditions to join a bg are met. We can proceed in joining.

    // _player->GetGroup() was already checked, grp is already initialized
    GroupQueueInfo * ginfo = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AddGroup(_player, bgTypeId, 0, false, isPremade, 0);
    uint32 avgTime = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].GetAverageQueueWaitTime(ginfo, _player->GetBattleGroundQueueIdFromLevel(bgTypeId));
    if (joinAsGroup /* && _player->GetGroup()*/)
    {
        sLog.outDebug("Battleground: the following players are joining as group:");
        for(GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player *member = itr->getSource();
            if(!member) continue;   // this should never happen

            uint32 queueSlot = member->AddBattleGroundQueueId(bgQueueTypeId);           // add to queue

            // store entry point coords (same as leader entry point)
            member->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

            WorldPacket data;
                                                            // send status packet (in queue)
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, ginfo->ArenaType);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.BuildGroupJoinedBattlegroundPacket(&data, bgTypeId);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AddPlayer(member, ginfo);
            sLog.outDebug("Battleground: player joined queue for bg queue type %u bg type %u: GUID %u, NAME %s",bgQueueTypeId,bgTypeId,member->GetGUIDLow(), member->GetName());
        }
        sLog.outDebug("Battleground: group end");
    }
    else
    {
        // already checked if queueSlot is valid, now just get it
        uint32 queueSlot = _player->AddBattleGroundQueueId(bgQueueTypeId);
        // store entry point coords
        _player->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

        WorldPacket data;
                                                            // send status packet (in queue)
        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, ginfo->ArenaType);
        SendPacket(&data);

        sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AddPlayer(_player, ginfo);
        sLog.outDebug("Battleground: player joined queue for bg queue type %u bg type %u: GUID %u, NAME %s",bgQueueTypeId,bgTypeId,_player->GetGUIDLow(), _player->GetName());
    }
    sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].Update(bgTypeId, _player->GetBattleGroundQueueIdFromLevel(bgTypeId));
    if (!ginfo->IsInvitedToBGInstanceGUID)
        sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AnnounceWorld(ginfo, _player->GetGUID(), true);
}

void WorldSession::HandleBattleGroundPlayerPositionsOpcode( WorldPacket & /*recv_data*/ )
{
                                                            // empty opcode
    sLog.outDebug("WORLD: Recvd MSG_BATTLEGROUND_PLAYER_POSITIONS Message");

    BattleGround *bg = _player->GetBattleGround();
    if(!bg)                                                 // can't be received if player not in battleground
        return;

    switch( bg->GetTypeID() )
    {
        case BATTLEGROUND_WS:
            {
                uint32 count1 = 0;                                  //always constant zero?
                uint32 count2 = 0;                                  //count of next fields

                Player *ali_plr = objmgr.GetPlayer(((BattleGroundWS*)bg)->GetAllianceFlagPickerGUID());
                if (ali_plr)
                    ++count2;

                Player *horde_plr = objmgr.GetPlayer(((BattleGroundWS*)bg)->GetHordeFlagPickerGUID());
                if (horde_plr)
                    ++count2;

                WorldPacket data(MSG_BATTLEGROUND_PLAYER_POSITIONS, (4+4+16*count1+16*count2));
                data << count1;                                     // alliance flag holders count - obsolete, now always 0
                /*for(uint8 i = 0; i < count1; ++i)
                {
                    data << uint64(0);                              // guid
                    data << (float)0;                               // x
                    data << (float)0;                               // y
                }*/
                data << count2;                                     // horde flag holders count - obsolete, now count of next fields
                if (ali_plr)
                {
                    data << (uint64)ali_plr->GetGUID();
                    data << (float)ali_plr->GetPositionX();
                    data << (float)ali_plr->GetPositionY();
                }
                if (horde_plr)
                {
                    data << (uint64)horde_plr->GetGUID();
                    data << (float)horde_plr->GetPositionX();
                    data << (float)horde_plr->GetPositionY();
                }

                SendPacket(&data);
            }
            break;
        case BATTLEGROUND_EY:
            //TODO : fix me!
            break;
        case BATTLEGROUND_AB:
        case BATTLEGROUND_AV:
            {
                //for other BG types - send default
                WorldPacket data(MSG_BATTLEGROUND_PLAYER_POSITIONS, (4+4));
                data << uint32(0);
                data << uint32(0);
                SendPacket(&data);
            }
            break;
        default:
            //maybe it is sent also in arena - do nothing
            break;
    }
}

void WorldSession::HandleBattleGroundPVPlogdataOpcode( WorldPacket & /*recv_data*/ )
{
    sLog.outDebug( "WORLD: Recvd MSG_PVP_LOG_DATA Message");

    BattleGround *bg = _player->GetBattleGround();
    if (!bg)
        return;

    WorldPacket data;
    sBattleGroundMgr.BuildPvpLogDataPacket(&data, bg);
    SendPacket(&data);

    sLog.outDebug( "WORLD: Sent MSG_PVP_LOG_DATA Message");
}

void WorldSession::HandleBattleGroundListOpcode( WorldPacket &recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 4);

    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEFIELD_LIST Message");

    uint32 bgTypeId;
    recv_data >> bgTypeId;                                  // id from DBC

    BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(bgTypeId);
    if (!bl)
    {
        sLog.outError("Battleground: invalid bgtype received.");
        return;
    }

    WorldPacket data;
    sBattleGroundMgr.BuildBattleGroundListPacket(&data, _player->GetGUID(), _player, BattleGroundTypeId(bgTypeId));
    SendPacket( &data );
}

void WorldSession::HandleBattleGroundPlayerPortOpcode( WorldPacket &recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 1+1+4+2+1);

    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEFIELD_PORT Message");

    uint8 type;                                             // arenatype if arena
    uint8 unk2;                                             // unk, can be 0x0 (may be if was invited?) and 0x1
    uint32 instanceId;
    uint32 bgTypeId_;                                       // type id from dbc
    uint16 unk;                                             // 0x1F90 constant?
    uint8 action;                                           // enter battle 0x1, leave queue 0x0

    recv_data >> type >> unk2 >> bgTypeId_ >> unk >> action;

    if (!sBattlemasterListStore.LookupEntry(bgTypeId_))
    {
        sLog.outError("Battleground: invalid bgtype (%u) received.", bgTypeId_);
        // update battleground slots for the player to fix his UI and sent data.
        // this is a HACK, I don't know why the client starts sending invalid packets in the first place.
        // it usually happens with extremely high latency (if debugging / stepping in the code for example)
        if (_player->InBattleGroundQueue())
        {
            // update all queues, send invitation info if player is invited, queue info if queued
            for (uint32 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
            {
                BattleGroundQueueTypeId bgQueueTypeId = _player->GetBattleGroundQueueTypeId(i);
                if (!bgQueueTypeId)
                    continue;
                BattleGroundTypeId bgTypeId = BattleGroundMgr::BGTemplateId(bgQueueTypeId);
                BattleGroundQueue::QueuedPlayersMap& qpMap = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].m_QueuedPlayers;
                BattleGroundQueue::QueuedPlayersMap::iterator itrPlayerStatus = qpMap.find(_player->GetGUID());
                // if the player is not in queue, continue or no group information - this should never happen
                if (itrPlayerStatus == qpMap.end() || !itrPlayerStatus->second.GroupInfo)
                    continue;

                BattleGround * bg = NULL;
                // get possibly needed data from groupinfo
                uint8 arenatype = itrPlayerStatus->second.GroupInfo->ArenaType;
                uint8 status = 0;

                if (!itrPlayerStatus->second.GroupInfo->IsInvitedToBGInstanceGUID)
                {
                    // not invited to bg, get template
                    bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
                    status = STATUS_WAIT_QUEUE;
                }
                else
                {
                    // get the bg we're invited to
                    bg = sBattleGroundMgr.GetBattleGround(itrPlayerStatus->second.GroupInfo->IsInvitedToBGInstanceGUID, bgTypeId);
                    status = STATUS_WAIT_JOIN;
                }

                // if bg not found, then continue, don't invite if already in the instance
                if (!bg || (_player->InBattleGround() && _player->GetBattleGround() && _player->GetBattleGround()->GetInstanceID() == bg->GetInstanceID()))
                    continue;

                // re - invite player with proper data
                WorldPacket data;
                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, i, status, INVITE_ACCEPT_WAIT_TIME, 0, arenatype);
                SendPacket(&data);
            }
        }
        return;
    }

    //get GroupQueueInfo from BattleGroundQueue
    BattleGroundTypeId bgTypeId = BattleGroundTypeId(bgTypeId_);
    BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(bgTypeId, type);
    BattleGroundQueue::QueuedPlayersMap& qpMap = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].m_QueuedPlayers;
    BattleGroundQueue::QueuedPlayersMap::iterator itrPlayerStatus = qpMap.find(_player->GetGUID());
    if (itrPlayerStatus == qpMap.end())
    {
        sLog.outError("Battleground: itrplayerstatus not found.");
        return;
    }

    instanceId = itrPlayerStatus->second.GroupInfo->IsInvitedToBGInstanceGUID;
    // if action == 1, then instanceId is required
    if (!instanceId && action == 1)
    {
        sLog.outError("Battleground: instance not found.");
        return;
    }

    BattleGround *bg = sBattleGroundMgr.GetBattleGround(instanceId, bgTypeId);

    // bg template might and must be used in case of leaving queue, when instance is not created yet
    if (!bg && action == 0)
        bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
    if (!bg)
    {
        sLog.outError("Battleground: bg_template not found for type id %u.", bgTypeId);
        return;
    }

    if (_player->InBattleGroundQueue())
    {
        //we must use temporary variables, because GroupQueueInfo pointer can be deleted in BattleGroundQueue::RemovePlayer() function!
        uint32 team = itrPlayerStatus->second.GroupInfo->Team;
        uint32 arenaType = itrPlayerStatus->second.GroupInfo->ArenaType;
        uint32 isRated = itrPlayerStatus->second.GroupInfo->IsRated;
        uint32 rating = itrPlayerStatus->second.GroupInfo->ArenaTeamRating;
        uint32 opponentsRating = itrPlayerStatus->second.GroupInfo->OpponentsTeamRating;

        //some checks if player isn't cheating - it is not exactly cheating, but we cannot allow it
        if (action == 1 && arenaType == 0)
        {
            //if player is trying to enter battleground (not arena!) and he has deserter debuff, we must just remove him from queue
            if (!_player->CanJoinToBattleground())
            {
                //send bg command result to show nice message
                WorldPacket data2(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
                data2 << uint32(0xFFFFFFFE);
                _player->GetSession()->SendPacket(&data2);
                action = 0;
                sLog.outDebug("Battleground: player %s (%u) has a deserter debuff, do not port him to battleground!", _player->GetName(), _player->GetGUIDLow());
            }
            //if player don't match battleground max level, then do not allow him to enter! (this might happen when player leveled up during his waiting in queue
            if (_player->getLevel() > bg->GetMaxLevel())
            {
                sLog.outError("Battleground: Player %s (%u) has level higher than maxlevel of battleground! Do not port him to battleground!", _player->GetName(), _player->GetGUIDLow());
                action = 0;
            }
        }
        uint32 queueSlot = _player->GetBattleGroundQueueIndex(bgQueueTypeId);
        WorldPacket data;
        switch( action )
        {
            case 1:                                         // port to battleground
                if (!_player->IsInvitedForBattleGroundQueueType(bgQueueTypeId))
                    return;                                 // cheating?
                // resurrect the player
                if (!_player->isAlive())
                {
                    _player->ResurrectPlayer(1.0f);
                    _player->SpawnCorpseBones();
                }
                // stop taxi flight at port
                if (_player->isInFlight())
                {
                    _player->GetMotionMaster()->MovementExpired();
                    _player->m_taxi.ClearTaxiDestinations();
                }

                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_IN_PROGRESS, 0, bg->GetStartTime(), bg->GetArenaType());
                _player->GetSession()->SendPacket(&data);
                // remove battleground queue status from BGmgr
                sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].RemovePlayer(_player->GetGUID(), false);
                // this is still needed here if battleground "jumping" shouldn't add deserter debuff
                // also this is required to prevent stuck at old battleground after SetBattleGroundId set to new
                if (BattleGround *currentBg = _player->GetBattleGround())
                    currentBg->RemovePlayerAtLeave(_player->GetGUID(), false, true);

                // set the destination instance id
                _player->SetBattleGroundId(bg->GetInstanceID(), bgTypeId);
                // set the destination team
                _player->SetBGTeam(team);
                // clear AFK
                if(_player->isAFK())
                    _player->ToggleAFK();
                // bg->HandleBeforeTeleportToBattleGround(_player);
                sBattleGroundMgr.SendToBattleGround(_player, instanceId, bgTypeId);
                // add only in HandleMoveWorldPortAck()
                // bg->AddPlayer(_player,team);
                sLog.outDebug("Battleground: player %s (%u) joined battle for bg %u, bgtype %u, queue type %u.", _player->GetName(), _player->GetGUIDLow(), bg->GetInstanceID(), bg->GetTypeID(), bgQueueTypeId);
                break;
            case 0:                                         // leave queue
                // if player leaves rated arena match before match start, it is counted as he played but he lost
                if (isRated)
                {
                    ArenaTeam * at = objmgr.GetArenaTeamById(team);
                    if (at)
                    {
                        sLog.outDebug("UPDATING memberLost's personal arena rating for %u by opponents rating: %u, because he has left queue!", GUID_LOPART(_player->GetGUID()), opponentsRating);
                        at->MemberLost(_player, opponentsRating);
                        at->SaveToDB();
                    }
                }
                _player->RemoveBattleGroundQueueId(bgQueueTypeId);  // must be called this way, because if you move this call to queue->removeplayer, it causes bugs
                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_NONE, 0, 0, 0);
                sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].RemovePlayer(_player->GetGUID(), true);
                // player left queue, we should update it - do not update Arena Queue
                if (!arenaType)
                    sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].Update(bgTypeId, _player->GetBattleGroundQueueIdFromLevel(bgTypeId), arenaType, isRated, rating);
                SendPacket(&data);
                sLog.outDebug("Battleground: player %s (%u) left queue for bgtype %u, queue type %u.", _player->GetName(), _player->GetGUIDLow(), bg->GetTypeID(), bgQueueTypeId);
                break;
            default:
                sLog.outError("Battleground port: unknown action %u", action);
                break;
        }
    }
}

void WorldSession::HandleBattleGroundLeaveOpcode( WorldPacket & /*recv_data*/ )
{
    //CHECK_PACKET_SIZE(recv_data, 1+1+4+2);

    sLog.outDebug( "WORLD: Recvd CMSG_LEAVE_BATTLEFIELD Message");

    //uint8 unk1, unk2;
    //uint32 bgTypeId;                                        // id from DBC
    //uint16 unk3;

    //recv_data >> unk1 >> unk2 >> bgTypeId >> unk3; - no used currently

    //if(bgTypeId >= MAX_BATTLEGROUND_TYPES)                  // cheating? but not important in this case
    //    return;

    // not allow leave battleground in combat
    if (_player->isInCombat())
        if (BattleGround* bg = _player->GetBattleGround())
            if (bg->GetStatus() != STATUS_WAIT_LEAVE)
                return;

    _player->LeaveBattleground();
}

void WorldSession::HandleBattlefieldStatusOpcode( WorldPacket & /*recv_data*/ )
{
    // empty opcode
    sLog.outDebug( "WORLD: Battleground status" );

    WorldPacket data;
    // we must update all queues here
    BattleGround *bg = NULL;
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
    {
        BattleGroundQueueTypeId bgQueueTypeId = _player->GetBattleGroundQueueTypeId(i);
        if (!bgQueueTypeId)
            continue;
        BattleGroundTypeId bgTypeId = BattleGroundMgr::BGTemplateId(bgQueueTypeId);
        uint8 arenaType = BattleGroundMgr::BGArenaType(bgQueueTypeId);
        if (bgTypeId == _player->GetBattleGroundTypeId())
        {
            bg = _player->GetBattleGround();
            //i cannot check any variable from player class because player class doesn't know if player is in 2v2 / 3v3 or 5v5 arena
            //so i must use bg pointer to get that information
            if (bg && bg->GetArenaType() == arenaType)
            {
                // this line is checked, i only don't know if GetStartTime is changing itself after bg end!
                // send status in BattleGround
                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, i, STATUS_IN_PROGRESS, bg->GetEndTime(), bg->GetStartTime(), arenaType);
                SendPacket(&data);
                continue;
            }
        }
        //we are sending update to player about queue - he can be invited there!
        //get GroupQueueInfo for queue status
        BattleGroundQueue::QueuedPlayersMap& qpMap = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].m_QueuedPlayers;
        BattleGroundQueue::QueuedPlayersMap::iterator itrPlayerStatus = qpMap.find(_player->GetGUID());
        if (itrPlayerStatus == qpMap.end())
            continue;
        if (itrPlayerStatus->second.GroupInfo->IsInvitedToBGInstanceGUID)
        {
            bg = sBattleGroundMgr.GetBattleGround(itrPlayerStatus->second.GroupInfo->IsInvitedToBGInstanceGUID, bgTypeId);
            if (!bg)
                continue;
            uint32 remainingTime = getMSTimeDiff(getMSTime(), itrPlayerStatus->second.GroupInfo->RemoveInviteTime);
            // send status invited to BattleGround
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, i, STATUS_WAIT_JOIN, remainingTime, 0, arenaType);
            SendPacket(&data);
        }
        else
        {
            bg = sBattleGroundMgr.GetBattleGroundTemplate(bgTypeId);
            if (!bg)
                continue;
            uint32 avgTime = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].GetAverageQueueWaitTime(itrPlayerStatus->second.GroupInfo, _player->GetBattleGroundQueueIdFromLevel(bgTypeId));
            // send status in BattleGround Queue
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, i, STATUS_WAIT_QUEUE, avgTime, getMSTimeDiff(itrPlayerStatus->second.GroupInfo->JoinTime, getMSTime()), arenaType);
            SendPacket(&data);
        }
    }
}

void WorldSession::HandleAreaSpiritHealerQueryOpcode( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_AREA_SPIRIT_HEALER_QUERY");

    CHECK_PACKET_SIZE(recv_data, 8);

    BattleGround *bg = _player->GetBattleGround();
    if (!bg)
        return;

    uint64 guid;
    recv_data >> guid;

    Creature *unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if(!unit->isSpiritService())                            // it's not spirit service
        return;

    sBattleGroundMgr.SendAreaSpiritHealerQueryOpcode(_player, bg, guid);
}

void WorldSession::HandleAreaSpiritHealerQueueOpcode( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_AREA_SPIRIT_HEALER_QUEUE");

    CHECK_PACKET_SIZE(recv_data, 8);

    BattleGround *bg = _player->GetBattleGround();
    if (!bg)
        return;

    uint64 guid;
    recv_data >> guid;

    Creature *unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if(!unit->isSpiritService())                            // it's not spirit service
        return;

    bg->AddPlayerToResurrectQueue(guid, _player->GetGUID());
}

void WorldSession::HandleBattleGroundArenaJoin( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+1+1+1);

    sLog.outDebug("WORLD: CMSG_BATTLEMASTER_JOIN_ARENA");
    recv_data.hexlike();

    // ignore if we already in BG or BG queue
    if (_player->InBattleGround())
        return;

    uint64 guid;                                            // arena Battlemaster guid
    uint8 arenaslot;                                        // 2v2, 3v3 or 5v5
    uint8 asGroup;                                          // asGroup
    uint8 isRated;                                          // isRated
    Group * grp;

    recv_data >> guid >> arenaslot >> asGroup >> isRated;

    Creature *unit = GetPlayer()->GetMap()->GetCreature(guid);
    if (!unit)
        return;

    if(!unit->isBattleMaster())                             // it's not battle master
        return;

    uint8 arenatype = 0;
    uint32 arenaRating = 0;

    switch(arenaslot)
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
            sLog.outError("Unknown arena slot %u at HandleBattleGroundArenaJoin()", arenaslot);
            return;
    }

    //check existance
    BattleGround* bg = NULL;
    if (!(bg = sBattleGroundMgr.GetBattleGroundTemplate(BATTLEGROUND_AA)))
    {
        sLog.outError("Battleground: template bg (all arenas) not found");
        return;
    }

    BattleGroundTypeId bgTypeId = bg->GetTypeID();
    BattleGroundQueueTypeId bgQueueTypeId = BattleGroundMgr::BGQueueTypeId(bgTypeId, arenatype);

    // check queueing conditions
    if (!asGroup)
    {
        // check if already in queue
        if (_player->GetBattleGroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return;
        // check if has free queue slots
        if (!_player->HasFreeBattleGroundQueueId())
            return;
    }
    else
    {
        grp = _player->GetGroup();
        // no group found, error
        if (!grp)
            return;
        uint32 err = grp->CanJoinBattleGroundQueue(bgTypeId, bgQueueTypeId, arenatype, arenatype, (bool)isRated, arenaslot);
        if (err != BG_JOIN_ERR_OK)
        {
            SendBattleGroundOrArenaJoinError(err);
            return;
        }
    }

    uint32 ateamId = 0;

    if (isRated)
    {
        ateamId = _player->GetArenaTeamId(arenaslot);
        // check real arenateam existence only here (if it was moved to group->CanJoin .. () then we would ahve to get it twice)
        ArenaTeam * at = objmgr.GetArenaTeamById(ateamId);
        if (!at)
        {
            _player->GetSession()->SendNotInArenaTeamPacket(arenatype);
            return;
        }
        // get the team rating for queueing
        arenaRating = at->GetRating();
        // the arenateam id must match for everyone in the group
        // get the personal ratings for queueing
        uint32 avg_pers_rating = 0;
        for(GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player *member = itr->getSource();

            // calc avg personal rating
            avg_pers_rating += member->GetUInt32Value(PLAYER_FIELD_ARENA_TEAM_INFO_1_1 + (arenaslot*6) + 5);
        }

        if (arenatype)
            avg_pers_rating /= arenatype;

        // if avg personal rating is more than 150 points below the teams rating, the team will be queued against an opponent matching or similar to the average personal rating
        if (avg_pers_rating + 150 < arenaRating)
            arenaRating = avg_pers_rating;
    }

    GroupQueueInfo * ginfo = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AddGroup(_player, bgTypeId, arenatype, isRated, false, arenaRating, ateamId);
    uint32 avgTime = sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].GetAverageQueueWaitTime(ginfo, _player->GetBattleGroundQueueIdFromLevel(bgTypeId));
    if (asGroup)
    {
        sLog.outDebug("Battleground: arena join as group start");
        if (isRated)
            sLog.outDebug("Battleground: arena team id %u, leader %s queued with rating %u for type %u",_player->GetArenaTeamId(arenaslot),_player->GetName(),arenaRating,arenatype);
        for(GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player *member = itr->getSource();
            if(!member) continue;

            uint32 queueSlot = member->AddBattleGroundQueueId(bgQueueTypeId);// add to queue

            // store entry point coords (same as leader entry point)
            member->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

            WorldPacket data;
            // send status packet (in queue)
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.BuildGroupJoinedBattlegroundPacket(&data, bgTypeId);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AddPlayer(member, ginfo);
            sLog.outDebug("Battleground: player joined queue for arena as group bg queue type %u bg type %u: GUID %u, NAME %s",bgQueueTypeId,bgTypeId,member->GetGUIDLow(), member->GetName());
        }
        sLog.outDebug("Battleground: arena join as group end");
        if (isRated)
            sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AnnounceWorld(ginfo, _player->GetGUID(), true);
    }
    else
    {
        uint32 queueSlot = _player->AddBattleGroundQueueId(bgQueueTypeId);

        // store entry point coords
        _player->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

        WorldPacket data;
        // send status packet (in queue)
        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype);
        SendPacket(&data);
        sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].AddPlayer(_player, ginfo);
        sLog.outDebug("Battleground: player joined queue for arena, skirmish, bg queue type %u bg type %u: GUID %u, NAME %s",bgQueueTypeId,bgTypeId,_player->GetGUIDLow(), _player->GetName());
    }
    sBattleGroundMgr.m_BattleGroundQueues[bgQueueTypeId].Update(bgTypeId, _player->GetBattleGroundQueueIdFromLevel(bgTypeId), arenatype, isRated, arenaRating);
}

void WorldSession::HandleBattleGroundReportAFK( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 playerGuid;
    recv_data >> playerGuid;
    Player *reportedPlayer = objmgr.GetPlayer(playerGuid);

    if (!reportedPlayer)
    {
        sLog.outDebug("WorldSession::HandleBattleGroundReportAFK: player not found");
        return;
    }

    sLog.outDebug("WorldSession::HandleBattleGroundReportAFK: %s reported %s", _player->GetName(), reportedPlayer->GetName());

    reportedPlayer->ReportedAfkBy(_player);
}

void WorldSession::SendBattleGroundOrArenaJoinError(uint8 err)
{
    WorldPacket data;
    int32 msg;
    switch (err)
    {
        case BG_JOIN_ERR_OFFLINE_MEMBER:
            msg = LANG_BG_GROUP_OFFLINE_MEMBER;
            break;
        case BG_JOIN_ERR_GROUP_TOO_MANY:
            msg = LANG_BG_GROUP_TOO_LARGE;
            break;
        case BG_JOIN_ERR_MIXED_FACTION:
            msg = LANG_BG_GROUP_MIXED_FACTION;
            break;
        case BG_JOIN_ERR_MIXED_LEVELS:
            msg = LANG_BG_GROUP_MIXED_LEVELS;
            break;
        case BG_JOIN_ERR_GROUP_MEMBER_ALREADY_IN_QUEUE:
            msg = LANG_BG_GROUP_MEMBER_ALREADY_IN_QUEUE;
            break;
        case BG_JOIN_ERR_GROUP_DESERTER:
            msg = LANG_BG_GROUP_MEMBER_DESERTER;
            break;
        case BG_JOIN_ERR_ALL_QUEUES_USED:
            msg = LANG_BG_GROUP_MEMBER_NO_FREE_QUEUE_SLOTS;
            break;
        case BG_JOIN_ERR_GROUP_NOT_ENOUGH:
        case BG_JOIN_ERR_MIXED_ARENATEAM:
        default:
            return;
            break;
    }
    ChatHandler::FillMessageData(&data, NULL, CHAT_MSG_BG_SYSTEM_NEUTRAL, LANG_UNIVERSAL, NULL, 0, GetTrinityString(msg), NULL);
    SendPacket(&data);
    return;
}

