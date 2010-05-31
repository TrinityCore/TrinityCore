/*
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "LFGMgr.h"
#include "WorldSession.h"
#include "WorldPacket.h"
#include "Player.h"

void WorldSession::HandleLfgJoinOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_LFG_JOIN");

    uint8 numDungeons;
    uint32 dungeon;
    uint32 roles;
    std::string comment;

    recv_data >> roles;
    recv_data.read_skip<uint8>();                           // unk - always 0
    recv_data.read_skip<uint8>();                           // unk - always 0
    recv_data >> numDungeons;
    if (!numDungeons)
    {
        sLog.outError("Invalid CMSG_LFG_JOIN packet sent by %s", GetPlayer()->GetName());
        recv_data.rpos(recv_data.wpos());
        return;
    }

    GetPlayer()->m_lookingForGroup.roles = uint8(roles);
    for (int8 i = 0 ; i < numDungeons; ++i)
    {
        recv_data >> dungeon;
        // remove the type from the dungeon entry
        GetPlayer()->m_lookingForGroup.applyDungeons.insert((dungeon & 0x00FFFFFF));
    }

    recv_data >> numDungeons;                               // unk - always 3
    for (int8 i = 0 ; i < numDungeons; ++i)
        recv_data.read_skip<uint8>();                       // unk - always 0

    recv_data >> comment;

    GetPlayer()->m_lookingForGroup.comment = comment;
    sLFGMgr.Join(GetPlayer());
}

void WorldSession::HandleLfgLeaveOpcode(WorldPacket & /*recv_data*/)
{
    sLog.outDebug("CMSG_LFG_LEAVE");

    // Check cheating - only leader can leave the queue
    if (Group *grp = GetPlayer()->GetGroup())
    {
        if (grp->GetLeaderGUID() != GetPlayer()->GetGUID())
            return;
        else
            sLFGMgr.Leave(GetPlayer(), grp);
    }
    else
        sLFGMgr.Leave(GetPlayer());
}

void WorldSession::HandleLfgSetRolesOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_LFG_SET_ROLES");

    uint8 roles;
    recv_data >> roles;                                    // Player Group Roles

    Group *grp = GetPlayer()->GetGroup();
    if (!grp)
        return;
    GetPlayer()->m_lookingForGroup.roles = roles;
    sLFGMgr.UpdateRoleCheck(grp, GetPlayer());
}

void WorldSession::HandleSetLfgCommentOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_SET_LFG_COMMENT");

    std::string comment;
    recv_data >> comment;

    GetPlayer()->m_lookingForGroup.comment = comment;
}

void WorldSession::HandleLfgPlayerLockInfoRequestOpcode(WorldPacket &/*recv_data*/)
{
    sLog.outDebug("CMSG_LFD_PLAYER_LOCK_INFO_REQUEST");
    sLFGMgr.SendLfgPlayerInfo(GetPlayer());
}

void WorldSession::HandleLfgPartyLockInfoRequestOpcode(WorldPacket &/*recv_data*/)
{
    sLog.outDebug("CMSG_LFD_PARTY_LOCK_INFO_REQUEST");
    sLFGMgr.SendLfgPartyInfo(GetPlayer());
}

void WorldSession::SendLfgUpdatePlayer(uint8 updateType)
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
    case LFG_UPDATETYPE_PROPOSAL_FOUND:
        extrainfo = true;
        break;
    }
    sLog.outDebug("SMSG_LFG_UPDATE_PLAYER");
    WorldPacket data(SMSG_LFG_UPDATE_PLAYER, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + GetPlayer()->m_lookingForGroup.applyDungeons.size() * 4 + GetPlayer()->m_lookingForGroup.comment.length()));
    data << uint8(updateType);                              // Lfg Update type
    data << uint8(extrainfo);                               // Extra info
    if (extrainfo)
    {
        data << uint8(queued);                              // Join the queue
        data << uint8(0);                                   // unk - Always 0
        data << uint8(0);                                   // unk - Always 0

        uint8 size = GetPlayer()->m_lookingForGroup.applyDungeons.size();
        data << uint8(size);

        for (LfgDungeonSet::const_iterator it = GetPlayer()->m_lookingForGroup.applyDungeons.begin(); it != GetPlayer()->m_lookingForGroup.applyDungeons.end(); ++it)
            data << uint32(*it);
        data << GetPlayer()->m_lookingForGroup.comment;
    }
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateParty(uint8 updateType)
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
    case LFG_UPDATETYPE_PROPOSAL_FOUND:
        extrainfo = true;
        join = true;
        break;
    }

    sLog.outDebug("SMSG_LFG_UPDATE_PARTY");
    WorldPacket data(SMSG_LFG_UPDATE_PARTY, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + 1 + GetPlayer()->m_lookingForGroup.applyDungeons.size() * 4 + GetPlayer()->m_lookingForGroup.comment.length()));
    data << uint8(updateType);                              // Lfg Update type
    data << uint8(extrainfo);                               // Extra info
    if (extrainfo)
    {
        data << uint8(join);                                // LFG Join
        data << uint8(queued);                              // Join the queue
        data << uint8(0);                                   // unk - Always 0
        data << uint8(0);                                   // unk - Always 0
        for (uint8 i = 0; i < 3; ++i)
            data << uint8(0);                               // unk - Always 0

        uint8 size = GetPlayer()->m_lookingForGroup.applyDungeons.size();
        data << uint8(size);

        for (LfgDungeonSet::const_iterator it = GetPlayer()->m_lookingForGroup.applyDungeons.begin(); it != GetPlayer()->m_lookingForGroup.applyDungeons.end(); ++it)
            data << uint32(*it);

        data << GetPlayer()->m_lookingForGroup.comment;
    }
    SendPacket(&data);
}

void WorldSession::SendLfgRoleChosen(uint64 guid, uint8 roles)
{
    sLog.outDebug("SMSG_LFG_ROLE_CHOSEN");

    WorldPacket data(SMSG_LFG_ROLE_CHOSEN);
    data << uint64(guid);                                   // Guid
    data << uint8(roles > 0);                               // Ready
    data << uint32(roles);                                  // Roles
    SendPacket(&data);
}

void WorldSession::SendLfgJoinResult(uint8 checkResult, uint8 checkValue)
{
    if (checkResult == LFG_JOIN_PARTY_NOT_MEET_REQS)        // Should never happen - its handled in Mgr
        return;

    sLog.outDebug("SMSG_LFG_JOIN_RESULT");

    WorldPacket data(SMSG_LFG_JOIN_RESULT);
    data << uint32(checkResult);                            // Check Result
    data << uint32(checkValue);                             // Check Value
    SendPacket(&data);
}

void WorldSession::SendLfgQueueStatus(uint32 dungeon, int32 waitTime, int32 avgWaitTime, int32 waitTimeTanks, int32 waitTimeHealer, int32 waitTimeDps, uint32 queuedTime, uint8 tanks, uint8 healers, uint8 dps)
{
    sLog.outDebug("SMSG_LFG_QUEUE_STATUS");
    WorldPacket data(SMSG_LFG_QUEUE_STATUS);

    data << uint32(dungeon);                                // Dungeon
    data << uint32(avgWaitTime);                            // Average Wait time
    data << uint32(waitTime);                               // Wait Time
    data << uint32(waitTimeTanks);                          // Wait Tanks
    data << uint32(waitTimeHealer);                         // Wait Healers
    data << uint32(waitTimeDps);                            // Wait Dps
    data << uint8(tanks);                                   // Tanks needed
    data << uint8(healers);                                 // Healers needed
    data << uint8(dps);                                     // Dps needed
    data << uint32(queuedTime);                             // Player wait time in queue
    SendPacket(&data);
}

void WorldSession::SendLfgUpdateSearch(bool update)
{
    sLog.outDebug("SMSG_LFG_UPDATE_SEARCH");

    WorldPacket data(SMSG_LFG_UPDATE_SEARCH);
    data << uint8(update);                                  // In Lfg Queue?
    SendPacket(&data);
}
