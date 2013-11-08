/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Object.h"

#include "Battlefield.h"
#include "BattlefieldMgr.h"
#include "Opcodes.h"
#include "Player.h"

//This send to player windows for invite player to join the war
//Param1:(guid) the guid of Bf
//Param2:(ZoneId) the zone where the battle is (4197 for wg)
//Param3:(time) Time in second that the player have for accept
void WorldSession::SendBfInvitePlayerToWar(uint64 guid, uint32 zoneId, uint32 pTime)
{
    ObjectGuid guidBytes = guid;

    WorldPacket data(SMSG_BATTLEFIELD_MGR_ENTRY_INVITE, 16);

    data.WriteBit(guidBytes[5]);
    data.WriteBit(guidBytes[3]);
    data.WriteBit(guidBytes[7]);
    data.WriteBit(guidBytes[2]);
    data.WriteBit(guidBytes[6]);
    data.WriteBit(guidBytes[4]);
    data.WriteBit(guidBytes[1]);
    data.WriteBit(guidBytes[0]);

    data.WriteByteSeq(guidBytes[6]);
    data << uint32(zoneId);         // Zone Id
    data.WriteByteSeq(guidBytes[1]);
    data.WriteByteSeq(guidBytes[3]);
    data.WriteByteSeq(guidBytes[4]);
    data.WriteByteSeq(guidBytes[2]);
    data.WriteByteSeq(guidBytes[0]);
    data << uint32(time(NULL) + pTime); // Invite lasts until
    data.WriteByteSeq(guidBytes[7]);
    data.WriteByteSeq(guidBytes[5]);

    //Sending the packet to player
    SendPacket(&data);
}

//This send invitation to player to join the queue
void WorldSession::SendBfInvitePlayerToQueue(uint64 guid)
{
    ObjectGuid guidBytes = guid;

    WorldPacket data(SMSG_BATTLEFIELD_MGR_QUEUE_INVITE, 5);

    data.WriteBit(1);               // unk
    data.WriteBit(0);               // Has Warmup
    data.WriteBit(1);               // unk
    data.WriteBit(guidBytes[0]);
    data.WriteBit(1);               // unk
    data.WriteBit(guidBytes[2]);
    data.WriteBit(guidBytes[6]);
    data.WriteBit(guidBytes[3]);
    data.WriteBit(1);               // unk
    data.WriteBit(0);               // unk
    data.WriteBit(guidBytes[1]);
    data.WriteBit(guidBytes[5]);
    data.WriteBit(guidBytes[4]);
    data.WriteBit(1);               // unk
    data.WriteBit(guidBytes[7]);

    data.FlushBits();

    data.WriteByteSeq(guidBytes[2]);
    data.WriteByteSeq(guidBytes[3]);
    data.WriteByteSeq(guidBytes[6]);
    data << uint8(1);               // Warmup
    data.WriteByteSeq(guidBytes[5]);
    data.WriteByteSeq(guidBytes[0]);
    data.WriteByteSeq(guidBytes[4]);
    data.WriteByteSeq(guidBytes[1]);
    data.WriteByteSeq(guidBytes[7]);

    //Sending packet to player
    SendPacket(&data);
}

//This send packet for inform player that he join queue
//Param1:(guid) the guid of Bf
//Param2:(ZoneId) the zone where the battle is (4197 for wg)
//Param3:(CanQueue) if able to queue
//Param4:(Full) on log in is full
void WorldSession::SendBfQueueInviteResponse(uint64 guid, uint32 ZoneId, bool CanQueue, bool Full)
{
    const bool hasSecondGuid = false;
    const bool warmup = true;
    ObjectGuid guidBytes = guid;

    WorldPacket data(SMSG_BATTLEFIELD_MGR_QUEUE_REQUEST_RESPONSE, 16);

    data.WriteBit(guidBytes[1]);
    data.WriteBit(guidBytes[6]);
    data.WriteBit(guidBytes[5]);
    data.WriteBit(guidBytes[7]);
    data.WriteBit(Full);  // Logging In, VERIFYME
    data.WriteBit(guidBytes[0]);
    data.WriteBit(!hasSecondGuid);
    data.WriteBit(guidBytes[4]);

    // if (hasSecondGuid) 7 3 0 4 2 6 1 5

    data.WriteBit(guidBytes[3]);
    data.WriteBit(guidBytes[2]);

    // if (hasSecondGuid) 2 5 3 0 4 6 1 7

    data.FlushBits();

    data << uint8(CanQueue);  // Accepted

    data.WriteByteSeq(guidBytes[1]);
    data.WriteByteSeq(guidBytes[3]);
    data.WriteByteSeq(guidBytes[6]);
    data.WriteByteSeq(guidBytes[7]);
    data.WriteByteSeq(guidBytes[0]);

    data << uint8(warmup);

    data.WriteByteSeq(guidBytes[2]);
    data.WriteByteSeq(guidBytes[4]);
    data.WriteByteSeq(guidBytes[5]);

    data << uint32(ZoneId);

    SendPacket(&data);
}

//This is call when player accept to join war
void WorldSession::SendBfEntered(uint64 guid)
{
    uint8 isAFK = _player->isAFK() ? 1 : 0;
    ObjectGuid guidBytes = guid;

    WorldPacket data(SMSG_BATTLEFIELD_MGR_ENTERED, 11);

    data.WriteBit(0);               // unk
    data.WriteBit(isAFK);           // Clear AFK
    data.WriteBit(guidBytes[1]);
    data.WriteBit(guidBytes[4]);
    data.WriteBit(guidBytes[5]);
    data.WriteBit(guidBytes[0]);
    data.WriteBit(guidBytes[3]);
    data.WriteBit(0);               // unk
    data.WriteBit(guidBytes[6]);
    data.WriteBit(guidBytes[7]);
    data.WriteBit(guidBytes[2]);

    data.FlushBits();

    data.WriteByteSeq(guidBytes[5]);
    data.WriteByteSeq(guidBytes[3]);
    data.WriteByteSeq(guidBytes[0]);
    data.WriteByteSeq(guidBytes[4]);
    data.WriteByteSeq(guidBytes[1]);
    data.WriteByteSeq(guidBytes[7]);
    data.WriteByteSeq(guidBytes[2]);
    data.WriteByteSeq(guidBytes[6]);

    SendPacket(&data);
}

void WorldSession::SendBfLeaveMessage(uint64 guid, BFLeaveReason reason)
{
    ObjectGuid guidBytes = guid;

    WorldPacket data(SMSG_BATTLEFIELD_MGR_EJECTED, 11);

    data.WriteBit(guidBytes[2]);
    data.WriteBit(guidBytes[5]);
    data.WriteBit(guidBytes[1]);
    data.WriteBit(guidBytes[0]);
    data.WriteBit(guidBytes[3]);
    data.WriteBit(guidBytes[6]);
    data.WriteBit(0);               // Relocated
    data.WriteBit(guidBytes[7]);
    data.WriteBit(guidBytes[4]);

    data.FlushBits();

    data << uint8(2);               // BattleStatus
    data.WriteByteSeq(guidBytes[1]);
    data.WriteByteSeq(guidBytes[7]);
    data.WriteByteSeq(guidBytes[4]);
    data.WriteByteSeq(guidBytes[2]);
    data.WriteByteSeq(guidBytes[3]);
    data << uint8(reason);          // Reason
    data.WriteByteSeq(guidBytes[6]);
    data.WriteByteSeq(guidBytes[0]);
    data.WriteByteSeq(guidBytes[5]);

    SendPacket(&data);
}

//Send by client when he click on accept for queue
void WorldSession::HandleBfQueueInviteResponse(WorldPacket& recvData)
{
    uint8 accepted;
    ObjectGuid guid;

    guid[2] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    accepted = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[5]);

    TC_LOG_ERROR("misc", "HandleQueueInviteResponse: GUID:"UI64FMTD" Accepted:%u", (uint64)guid, accepted);

    Battlefield* bf = sBattlefieldMgr->GetBattlefieldByGUID(guid);
    if (!bf)
        return;

    if (accepted)
        bf->PlayerAcceptInviteToQueue(_player);
}

//Send by client on clicking in accept or refuse of invitation windows for join game
void WorldSession::HandleBfEntryInviteResponse(WorldPacket& recvData)
{
    uint8 accepted;
    ObjectGuid guid;

    guid[6] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    accepted = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[5]);

    TC_LOG_ERROR("misc", "HandleBattlefieldInviteResponse: GUID:"UI64FMTD" Accepted:%u", (uint64)guid, accepted);

    Battlefield* bf = sBattlefieldMgr->GetBattlefieldByGUID(guid);
    if (!bf)
        return;

    if (accepted)
        bf->PlayerAcceptInviteToWar(_player);
    else
        if (_player->GetZoneId() == bf->GetZoneId())
            bf->KickPlayerFromBattlefield(_player->GetGUID());
}

void WorldSession::HandleBfExitRequest(WorldPacket& recvData)
{
    ObjectGuid guid;

    guid[2] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[6]);

    TC_LOG_ERROR("misc", "HandleBfExitRequest: GUID:"UI64FMTD" ", (uint64)guid);

    if (Battlefield* bf = sBattlefieldMgr->GetBattlefieldByGUID(guid))
        bf->AskToLeaveQueue(_player);
}
