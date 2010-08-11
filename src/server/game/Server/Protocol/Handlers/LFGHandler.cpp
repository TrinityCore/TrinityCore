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

    GetPlayer()->SetLfgRoles(uint8(roles));

    // Check if it's offer continue
    Group *grp = GetPlayer()->GetGroup();
    if (grp && grp->isLFGGroup())
    {
        LfgDungeonSet *dungeons = GetPlayer()->GetLfgDungeons();
        if (grp->GetLfgStatus() == LFG_STATUS_COMPLETE)     // Dungeon complete add all dungeons
        {
            dungeons->clear();
            for (int8 i = 0 ; i < numDungeons; ++i)
            {
                recv_data >> dungeon;
                dungeons->insert((dungeon & 0x00FFFFFF));
            }
        }
        else if (dungeons->size() > 1 || dungeons->size() ==1 && !sLFGMgr.isRandomDungeon(*dungeons->begin()))
        {
            dungeons->clear();
            // ignore the list and select the current dungeon
            for (int8 i = 0 ; i < numDungeons; ++i)
                recv_data.read_skip<uint32>();
            dungeons->insert(grp->GetLfgDungeonEntry());
        }
        else // currently added to random Dungeon
        {
            for (int8 i = 0 ; i < numDungeons; ++i)
            {
                recv_data >> dungeon;
                // remove the type from the dungeon entry
                GetPlayer()->GetLfgDungeons()->insert((dungeon & 0x00FFFFFF));
            }
        }
    }
    else
    {
        for (int8 i = 0 ; i < numDungeons; ++i)
        {
            recv_data >> dungeon;
            // remove the type from the dungeon entry
            GetPlayer()->GetLfgDungeons()->insert((dungeon & 0x00FFFFFF));
        }
    }

    recv_data >> numDungeons;                               // unk - always 3
    for (int8 i = 0 ; i < numDungeons; ++i)
        recv_data.read_skip<uint8>();                       // unk - always 0

    recv_data >> comment;

    GetPlayer()->SetLfgComment(comment);
    sLFGMgr.Join(GetPlayer());
}

void WorldSession::HandleLfgLeaveOpcode(WorldPacket & /*recv_data*/)
{
    sLog.outDebug("CMSG_LFG_LEAVE");
    Group *grp = GetPlayer()->GetGroup();

    // Check cheating - only leader can leave the queue
    if (!grp || grp->GetLeaderGUID() == GetPlayer()->GetGUID())
        sLFGMgr.Leave(GetPlayer());
}

void WorldSession::HandleLfgProposalResultOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_LFG_PROPOSAL_RESULT");

    uint32 lfgGroupID;                                      // Internal lfgGroupID
    uint8 accept;                                           // Accept to join?
    recv_data >> lfgGroupID;
    recv_data >> accept;

    if (accept < 2)
        sLFGMgr.UpdateProposal(lfgGroupID, GetPlayer()->GetGUIDLow(), accept);
}

void WorldSession::HandleLfgSetRolesOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_LFG_SET_ROLES");

    uint8 roles;
    recv_data >> roles;                                     // Player Group Roles

    Group *grp = GetPlayer()->GetGroup();
    if (!grp)
        return;
    GetPlayer()->SetLfgRoles(roles);
    sLFGMgr.UpdateRoleCheck(grp, GetPlayer());
}

void WorldSession::HandleSetLfgCommentOpcode(WorldPacket & recv_data)
{
    sLog.outDebug("CMSG_SET_LFG_COMMENT");

    std::string comment;
    recv_data >> comment;

    GetPlayer()->SetLfgComment(comment);
}

void WorldSession::HandleLfgSetBootVoteOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_LFG_SET_BOOT_VOTE");

    uint8 agree;                                             // Agree to kick player
    recv_data >> agree;

}

void WorldSession::HandleLfgTeleportOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_LFG_TELEPORT");

    bool out;
    recv_data >> out;

    sLFGMgr.TeleportPlayer(GetPlayer(), out);
}

void WorldSession::HandleLfgPlayerLockInfoRequestOpcode(WorldPacket &/*recv_data*/)
{
    sLog.outDebug("CMSG_LFD_PLAYER_LOCK_INFO_REQUEST");
    sLFGMgr.SendLfgPlayerInfo(GetPlayer());
}

void WorldSession::HandleLfgPartyLockInfoRequestOpcode(WorldPacket &/*recv_data*/)
{
    sLog.outDebug("CMSG_LFD_PARTY_LOCK_INFO_REQUEST");
    //sLFGMgr.SendLfgPartyInfo(GetPlayer());
}

void WorldSession::HandleLfrSearchOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_SEARCH_LFG_JOIN");

    uint32 entry;                                           // Raid id to search
    recv_data >> entry;
    //SendLfrUpdateListOpcode(entry);
}

void WorldSession::HandleLfrLeaveOpcode(WorldPacket &recv_data)
{
    sLog.outDebug("CMSG_SEARCH_LFG_LEAVE");

    uint32 dungeonId;                                       // Raid id queue to leave
    recv_data >> dungeonId;
    //sLFGMgr.LeaveLfr(GetPlayer(), dungeonId);
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
    case LFG_UPDATETYPE_PROPOSAL_BEGIN:
        extrainfo = true;
        break;
    }
    LfgDungeonSet *dungeons = GetPlayer()->GetLfgDungeons();
    uint8 size = dungeons->size();
    std::string comment = GetPlayer()->GetLfgComment();
    sLog.outDebug("SMSG_LFG_UPDATE_PLAYER");
    WorldPacket data(SMSG_LFG_UPDATE_PLAYER, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + size * 4 + comment.length()));
    data << uint8(updateType);                              // Lfg Update type
    data << uint8(extrainfo);                               // Extra info
    if (extrainfo)
    {
        data << uint8(queued);                              // Join the queue
        data << uint8(0);                                   // unk - Always 0
        data << uint8(0);                                   // unk - Always 0

        data << uint8(size);

        for (LfgDungeonSet::const_iterator it = dungeons->begin(); it != dungeons->end(); ++it)
            data << uint32(*it);
        data << comment;
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
    case LFG_UPDATETYPE_PROPOSAL_BEGIN:
        extrainfo = true;
        join = true;
        break;
    }

    LfgDungeonSet *dungeons = GetPlayer()->GetLfgDungeons();
    uint8 size = dungeons->size();
    std::string comment = GetPlayer()->GetLfgComment();
    sLog.outDebug("SMSG_LFG_UPDATE_PARTY");
    WorldPacket data(SMSG_LFG_UPDATE_PARTY, 1 + 1 + (extrainfo ? 1 : 0) * (1 + 1 + 1 + 1 + 1 + size * 4 + comment.length()));
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

        data << uint8(size);

        for (LfgDungeonSet::const_iterator it = dungeons->begin(); it != dungeons->end(); ++it)
            data << uint32(*it);

        data << comment;
    }
    SendPacket(&data);
}

void WorldSession::SendLfgRoleChosen(uint64 guid, uint8 roles)
{
    sLog.outDebug("SMSG_LFG_ROLE_CHOSEN");

    WorldPacket data(SMSG_LFG_ROLE_CHOSEN, 8 + 1 + 4);
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

    WorldPacket data(SMSG_LFG_JOIN_RESULT, 4 + 4);
    data << uint32(checkResult);                            // Check Result
    data << uint32(checkValue);                             // Check Value
    SendPacket(&data);
}

void WorldSession::SendLfgQueueStatus(uint32 dungeon, int32 waitTime, int32 avgWaitTime, int32 waitTimeTanks, int32 waitTimeHealer, int32 waitTimeDps, uint32 queuedTime, uint8 tanks, uint8 healers, uint8 dps)
{
    sLog.outDebug("SMSG_LFG_QUEUE_STATUS");
    WorldPacket data(SMSG_LFG_QUEUE_STATUS, 4 + 4 + 4 + 4 + 4 +4 + 1 + 1 + 1 + 4);

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

    WorldPacket data(SMSG_LFG_UPDATE_SEARCH, 1);
    data << uint8(update);                                  // In Lfg Queue?
    SendPacket(&data);
}

void WorldSession::SendLfgDisabled()
{
    sLog.outDebug("SMSG_LFG_DISABLED");
    WorldPacket data(SMSG_LFG_DISABLED, 0);
    SendPacket(&data);
}

void WorldSession::SendLfgOfferContinue(uint32 dungeonEntry)
{
    sLog.outDebug("SMSG_LFG_OFFER_CONTINUE");

    WorldPacket data(SMSG_LFG_OFFER_CONTINUE, 4);
    data << uint32(dungeonEntry);
    SendPacket(&data);
}

void WorldSession::SendLfgTeleportError(uint8 err)
{
    sLog.outDebug("SMSG_LFG_TELEPORT_DENIED");

    WorldPacket data(SMSG_LFG_TELEPORT_DENIED, 4);
    data << uint32(err);                                    // Error
    SendPacket(&data);
}

/*
void WorldSession::SendLfrUpdateListOpcode(uint32 entry)
{
    sLog.outDebug("SMSG_UPDATE_LFG_LIST");
    WorldPacket data(SMSG_UPDATE_LFG_LIST);
    sLFGMgr.BuildLfrUpdateList(data, entry);
    SendPacket(&data);
}
*/
