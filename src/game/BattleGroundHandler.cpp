/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
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
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "Object.h"
#include "BattleGroundMgr.h"
#include "BattleGroundWS.h"
#include "BattleGround.h"

void WorldSession::HandleBattleGroundHelloOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 guid;
    recv_data >> guid;
    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEMASTER_HELLO Message from: " I64FMT, guid);

    Creature *unit = ObjectAccessor::GetCreature(*_player, guid);
    if(!unit)
        return;

    if(!unit->isBattleMaster())                             // it's not battlemaster
        return;

    // Stop the npc if moving
    unit->StopMoving();

    uint32 bgTypeId = objmgr.GetBattleMasterBG(unit->GetEntry());

    if(!_player->GetBGAccessByLevel(bgTypeId))
    {
                                                            // temp, must be gossip message...
        SendNotification("You don't meet Battleground level requirements");
        return;
    }

    SendBattlegGroundList(guid, bgTypeId);
}

void WorldSession::SendBattlegGroundList( uint64 guid, uint32 bgTypeId )
{
    WorldPacket data;
    sBattleGroundMgr.BuildBattleGroundListPacket(&data, guid, _player, bgTypeId);
    SendPacket( &data );
}

void WorldSession::HandleBattleGroundJoinOpcode( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8+4+4+1);

    uint64 guid;
    uint32 bgTypeId;
    uint32 instanceId;
    uint8 joinAsGroup;

    recv_data >> guid;                                      // battlemaster guid
    recv_data >> bgTypeId;                                  // battleground type id (DBC id)
    recv_data >> instanceId;                                // instance id, 0 if First Available selected
    recv_data >> joinAsGroup;                               // join as group

    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEMASTER_JOIN Message from: " I64FMT " for BG (Type: %u)", guid, bgTypeId);

    if(bgTypeId >= MAX_BATTLEGROUND_TYPES)                  // cheating?
        return;

    // ignore if we already in BG or BG queue
    if(_player->InBattleGround())
        return;

    Creature *unit = ObjectAccessor::GetCreature(*_player, guid);
    if(!unit)
        return;

    if(!unit->isBattleMaster())                             // it's not battlemaster
        return;

    // check Deserter debuff
    if( !_player->CanJoinToBattleground() )
    {
        WorldPacket data(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
        data << (uint32) 0xFFFFFFFE;
        _player->GetSession()->SendPacket(&data);
        return;
    }

    // check existence
    BattleGround *bg = sBattleGroundMgr.GetBattleGround(bgTypeId);
    if(!bg)
        return;

    if(joinAsGroup && _player->GetGroup())
    {
        Group *grp = _player->GetGroup();
        for(GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player *member = itr->getSource();
            if(!member) continue;

            if( !member->CanJoinToBattleground() )
            {
                WorldPacket data(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
                data << (uint32) 0xFFFFFFFE;
                _player->GetSession()->SendPacket(&data);
                continue;
            }
            if (member->InBattleGroundQueueForBattleGroundType(bgTypeId))
                //player is already in this queue
                continue;

            WorldPacket data;
                                                            // add to queue
            uint32 queueSlot = member->AddBattleGroundQueueId(bgTypeId);
            if (queueSlot == PLAYER_MAX_BATTLEGROUND_QUEUES)
            {
                // fill data packet
                //member->GetSession()->SendPacket(data);
                continue;
            }

            // store entry point coords (same as leader entry point)
            member->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

                                                            // send status packet (in queue)
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, member->GetTeam(), queueSlot, STATUS_WAIT_QUEUE, 0, 0);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.BuildGroupJoinedBattlegroundPacket(&data, bgTypeId);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.m_BattleGroundQueues[bgTypeId].AddPlayer(member, bgTypeId);
        }
    }
    else
    {
        if (_player->InBattleGroundQueueForBattleGroundType(bgTypeId))
            //player is already in this queue
            return;
        uint32 queueSlot = _player->AddBattleGroundQueueId(bgTypeId);
        if (queueSlot == PLAYER_MAX_BATTLEGROUND_QUEUES)
        {
            WorldPacket data;
            // fill data packet
            //SendPacket(data);
            return;
        }

        // store entry point coords
        _player->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

        WorldPacket data;
                                                            // send status packet (in queue)
        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, _player->GetTeam(), queueSlot, STATUS_WAIT_QUEUE, 0, 0);
        SendPacket(&data);
        sBattleGroundMgr.m_BattleGroundQueues[bgTypeId].AddPlayer(_player, bgTypeId);
    }
}

void WorldSession::HandleBattleGroundPlayerPositionsOpcode( WorldPacket & /*recv_data*/ )
{
                                                            // empty opcode
    sLog.outDebug("WORLD: Recvd MSG_BATTLEGROUND_PLAYER_POSITIONS Message");

    BattleGround *bg = _player->GetBattleGround();
    if(!bg)                                                 // can't be received if player not in battleground
        return;

    if(bg->GetTypeID() == BATTLEGROUND_WS)
    {
        uint32 count1 = 0;
        uint32 count2 = 0;

        Player *ap = objmgr.GetPlayer(((BattleGroundWS*)bg)->GetAllianceFlagPickerGUID());
        if(ap) ++count2;

        Player *hp = objmgr.GetPlayer(((BattleGroundWS*)bg)->GetHordeFlagPickerGUID());
        if(hp) ++count2;

        WorldPacket data(MSG_BATTLEGROUND_PLAYER_POSITIONS, (4+4+16*count1+16*count2));
        data << count1;                                     // alliance flag holders count
        /*for(uint8 i = 0; i < count1; i++)
        {
            data << uint64(0);                              // guid
            data << (float)0;                               // x
            data << (float)0;                               // y
        }*/
        data << count2;                                     // horde flag holders count
        if(ap)
        {
            data << (uint64)ap->GetGUID();
            data << (float)ap->GetPositionX();
            data << (float)ap->GetPositionY();
        }
        if(hp)
        {
            data << (uint64)hp->GetGUID();
            data << (float)hp->GetPositionX();
            data << (float)hp->GetPositionY();
        }

        SendPacket(&data);
    }
}

void WorldSession::HandleBattleGroundPVPlogdataOpcode( WorldPacket & /*recv_data*/ )
{
    sLog.outDebug( "WORLD: Recvd MSG_PVP_LOG_DATA Message");

    BattleGround *bg = _player->GetBattleGround();
    if(!bg)
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

    if(bgTypeId >= MAX_BATTLEGROUND_TYPES)                  // cheating?
        return;

    // can't be received if player not in BG queue
    if(!_player->InBattleGroundQueueForBattleGroundType(bgTypeId))
        return;

    BattlemasterListEntry const* bl = sBattlemasterListStore.LookupEntry(bgTypeId);

    if(!bl)
        return;

    WorldPacket data;
    sBattleGroundMgr.BuildBattleGroundListPacket(&data, _player->GetGUID(), _player, bgTypeId);
    SendPacket( &data );
}

void WorldSession::HandleBattleGroundPlayerPortOpcode( WorldPacket &recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 1+1+4+2+1);

    sLog.outDebug( "WORLD: Recvd CMSG_BATTLEFIELD_PORT Message");

    uint8 unk1;
    uint8 unk2;                                             // unk, can be 0x0 (may be if was invited?) and 0x1
    uint32 bgTypeId;                                        // type id from dbc
    uint16 unk;                                             // 0x1F90 constant?
    uint8 action;                                           // enter battle 0x1, leave queue 0x0

    recv_data >> unk1 >> unk2 >> bgTypeId >> unk >> action;

    if(bgTypeId >= MAX_BATTLEGROUND_TYPES)                  // cheating?
        return;

    if(!_player->InBattleGroundQueueForBattleGroundType(bgTypeId))
        return;

    BattleGround *bg = sBattleGroundMgr.GetBattleGround(bgTypeId);
    if(!bg)
        return;

    uint32 queueSlot = 0;
    WorldPacket data;
    switch(action)
    {
        case 1:                                             // port to battleground
            // cheating?
            if(!_player->IsInvitedForBattleGroundType(bgTypeId))
                return;

            // check if player is not deserter
            if( !_player->CanJoinToBattleground() )
            {
                WorldPacket data2;
                data2.Initialize(SMSG_GROUP_JOINED_BATTLEGROUND, 4);
                data2 << (uint32) 0xFFFFFFFE;
                SendPacket(&data2);
                return;
            }

            // if the player is dead, resurrect him before teleport
            if(!_player->isAlive())
            {
                _player->ResurrectPlayer(1.0f,false);
                _player->SpawnCorpseBones();
            }

            // leave current group
            _player->RemoveFromGroup();

            // packet to player about BG status
            queueSlot = _player->GetBattleGroundQueueIndex(bgTypeId);
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, _player->GetTeam(), queueSlot, STATUS_IN_PROGRESS, 0, bg->GetStartTime());
            _player->GetSession()->SendPacket(&data);

            // remove battleground queue status from BGmgr
            sBattleGroundMgr.m_BattleGroundQueues[bgTypeId].RemovePlayer(_player->GetGUID(), false);

            // this is still needed here if battleground "jumping" shouldn't add deserter debuff
            // also this required to prevent stuck at old battleground after SetBattleGroundId set to new
            if (BattleGround *currentBg = _player->GetBattleGround())
                currentBg->RemovePlayerAtLeave(_player->GetGUID(), false, true);

            _player->SetBattleGroundId(bg->GetTypeID());
            sBattleGroundMgr.SendToBattleGround(_player, bgTypeId);
            bg->AddPlayer(_player);
            break;
        case 0:                                             // leave queue
            queueSlot = _player->GetBattleGroundQueueIndex(bgTypeId);
            _player->RemoveBattleGroundQueueId(bgTypeId);   // must be called this way, because if you move this call to queue->removeplayer, it causes bugs
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, _player->GetTeam(), queueSlot, STATUS_NONE, 0, 0);
            sBattleGroundMgr.m_BattleGroundQueues[bgTypeId].RemovePlayer(_player->GetGUID(), true);
            SendPacket(&data);
            break;
        default:
            sLog.outError("Battleground port: unknown action %u", action);
            break;
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
    if(_player->isInCombat())
        if(BattleGround* bg = _player->GetBattleGround())
            if(bg->GetStatus() != STATUS_WAIT_LEAVE)
                return;

    _player->LeaveBattleground();
}

void WorldSession::HandleBattlefieldStatusOpcode( WorldPacket & /*recv_data*/ )
{
    // empty opcode
    sLog.outDebug( "WORLD: Battleground status" );

    WorldPacket data;

    // TODO: we must put player back to battleground in case disconnect (< 5 minutes offline time) or teleport player on login(!) from battleground map to entry point
    if(_player->InBattleGround())
    {
        BattleGround *bg = _player->GetBattleGround();
        if(bg)
        {
            uint32 queueSlot = _player->GetBattleGroundQueueIndex(bg->GetTypeID());
            if((bg->GetStatus() <= STATUS_IN_PROGRESS))
            {
                sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, _player->GetTeam(), queueSlot, STATUS_IN_PROGRESS, 0, bg->GetStartTime());
                SendPacket(&data);
            }
            for (uint32 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; i++)
            {
                uint32 queue_id = _player->GetBattleGroundQueueId(i);
                if (i == queueSlot || !queue_id)
                    continue;
                BattleGround *bg2 = sBattleGroundMgr.GetBattleGround(queue_id);
                if(bg2)
                {
                    //in this call is small bug, this call should be filled by player's waiting time in queue
                    //this call nulls all timers for client :
                    sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg2, _player->GetTeam(), i, STATUS_WAIT_QUEUE, 0, 0);
                    SendPacket(&data);
                }
            }
        }
    }
    else
    {
        // we should update all queues? .. i'm not sure if this code is correct
        for (uint32 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; i++)
        {
            if(uint32 queue_id = _player->GetBattleGroundQueueId(i))
            {
                if(BattleGround *bg = sBattleGroundMgr.GetBattleGround(queue_id))
                {
                    sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, _player->GetTeam(), i, STATUS_WAIT_QUEUE, 0, 0);
                    SendPacket(&data);
                }
            }
        }
    }
}

void WorldSession::HandleAreaSpiritHealerQueryOpcode( WorldPacket & recv_data )
{
    sLog.outDebug("WORLD: CMSG_AREA_SPIRIT_HEALER_QUERY");

    CHECK_PACKET_SIZE(recv_data, 8);

    BattleGround *bg = _player->GetBattleGround();
    if(!bg)
        return;

    uint64 guid;
    recv_data >> guid;

    Creature *unit = ObjectAccessor::GetCreature(*_player, guid);
    if(!unit)
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
    if(!bg)
        return;

    uint64 guid;
    recv_data >> guid;

    Creature *unit = ObjectAccessor::GetCreature(*_player, guid);
    if(!unit)
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
    if(_player->InBattleGround())
        return;

    for(int qId = 0; qId < PLAYER_MAX_BATTLEGROUND_QUEUES; ++qId)
    {
        if(_player->GetBattleGroundQueueId(qId) != 0)
            return;
    }

    uint64 guid;                                            // arena Battlemaster guid
    uint8 type;                                             // 2v2, 3v3 or 5v5
    uint8 asGroup;                                          // asGroup
    uint8 isRated;                                          // isRated
    recv_data >> guid >> type >> asGroup >> isRated;

    Creature *unit = ObjectAccessor::GetCreature(*_player, guid);
    if(!unit)
        return;

    if(!unit->isBattleMaster())                             // it's not battle master
        return;

    uint8 arenatype = 0;

    switch(type)
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
            sLog.outError("Unknown arena type %u at HandleBattleGroundArenaJoin()", type);
            return;
    }

    if(isRated && !_player->GetArenaTeamId(type))           // player not in arena team of that size
    {
        _player->GetSession()->SendNotInArenaTeamPacket(arenatype);
        return;
    }

    if(asGroup && !_player->GetGroup())                     // player not in group
        return;

    // check existence
    BattleGround *bg = sBattleGroundMgr.GetBattleGround(BATTLEGROUND_AA);
    if(!bg)
        return;

    bg->SetArenaType(arenatype);
    bg->SetRated(isRated);

    if(asGroup && _player->GetGroup())
    {
        Group *grp = _player->GetGroup();
        for(GroupReference *itr = grp->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player *member = itr->getSource();
            if(!member) continue;

            /*if (!member->CanJoinToBattleground())
                //player has deserter aura .. do nothing
            */

            if (member->InBattleGroundQueueForBattleGroundType(BATTLEGROUND_AA))
                //player is already in this queue
                continue;

                                                            // add to queue
            uint32 queueSlot = member->AddBattleGroundQueueId(BATTLEGROUND_AA);
            if (queueSlot == PLAYER_MAX_BATTLEGROUND_QUEUES)
            {
                WorldPacket data;
                //fill data
                //member->GetSession()->SendPacket(data);
                continue;
            }

            // store entry point coords (same as leader entry point)
            member->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

            WorldPacket data;
            // send status packet (in queue)
            sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, member->GetTeam(), queueSlot, STATUS_WAIT_QUEUE, 0, 0);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.BuildGroupJoinedBattlegroundPacket(&data, BATTLEGROUND_AA);
            member->GetSession()->SendPacket(&data);
            sBattleGroundMgr.m_BattleGroundQueues[BATTLEGROUND_AA].AddPlayer(member, BATTLEGROUND_AA);
        }
    }
    else
    {
        /*if (!member->CanJoinToBattleground())
            //player has deserter aura .. do nothing
        */

        if (_player->InBattleGroundQueueForBattleGroundType(BATTLEGROUND_AA))
            //player is already in this queue
            return;

        uint32 queueSlot = _player->AddBattleGroundQueueId(BATTLEGROUND_AA);
        if (queueSlot == PLAYER_MAX_BATTLEGROUND_QUEUES)
        {
            WorldPacket data;
            //fill data (player is in 3 queues already)
            //SendPacket(data);
            return;
        }

        // store entry point coords
        _player->SetBattleGroundEntryPoint(_player->GetMapId(),_player->GetPositionX(),_player->GetPositionY(),_player->GetPositionZ(),_player->GetOrientation());

        WorldPacket data;
        // send status packet (in queue)
        sBattleGroundMgr.BuildBattleGroundStatusPacket(&data, bg, _player->GetTeam(), queueSlot, STATUS_WAIT_QUEUE, 0, 0);
        SendPacket(&data);
        sBattleGroundMgr.m_BattleGroundQueues[BATTLEGROUND_AA].AddPlayer(_player, BATTLEGROUND_AA);
    }
}

void WorldSession::HandleBattleGroundReportAFK( WorldPacket & recv_data )
{
    CHECK_PACKET_SIZE(recv_data, 8);

    uint64 playerGuid;
    recv_data >> playerGuid;
    Player *reportedPlayer = objmgr.GetPlayer(playerGuid);

    if(!reportedPlayer)
    {
        sLog.outDebug("WorldSession::HandleBattleGroundReportAFK: player not found");
        return;
    }

    sLog.outDebug("WorldSession::HandleBattleGroundReportAFK: %s reported %s", _player->GetName(), reportedPlayer->GetName());

    reportedPlayer->ReportedAfkBy(_player);
}
