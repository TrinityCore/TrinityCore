/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "WorldPacket.h"
#include "WorldSession.h"
#include "CalendarMgr.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"

void WorldSession::HandleCalendarGetCalendar(WorldPacket & /*recv_data*/)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_GET_CALENDAR");     // empty

    time_t cur_time = time(NULL);

    // we can't really get the real size of this packet...
    WorldPacket data(SMSG_CALENDAR_SEND_CALENDAR, 4+4*0+4+4*0+4+4);

    sCalendarMgr->AppendInvitesToCalendarPacketForPlayer(data, GetPlayer());
    sCalendarMgr->AppendEventsToCalendarPacketForPlayer(data, GetPlayer());

    InstanceSave *save = NULL;
    uint32 counter = 0;
    size_t p_counter = data.wpos();
    data << uint32(counter);                                // instance save count

    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
        for (Player::BoundInstancesMap::const_iterator itr = _player->m_boundInstances[i].begin(); itr != _player->m_boundInstances[i].end(); ++itr)
            if (itr->second.perm)
            {
                save = itr->second.save;
                data << uint32(save->GetMapId());
                data << uint32(save->GetDifficulty());
                data << uint32(save->GetResetTime() - cur_time);
                data << uint64(save->GetInstanceId());      // instance save id as unique instance copy id
                ++counter;
            }

    data.put<uint32>(p_counter, counter);

    data << uint32(1135753200);                             // unk (28.12.2005 07:00)

    uint32 mapid = 0;
    MapEntry const* mapEnt;
    counter = 0;
    p_counter = data.wpos();
    data << uint32(counter);                                // raid reset count

    ResetTimeByMapDifficultyMap const& resets = sInstanceSaveMgr.GetResetTimeMap();
    for (ResetTimeByMapDifficultyMap::const_iterator itr = resets.begin(); itr != resets.end(); ++itr)
    {
        mapid = PAIR32_LOPART(itr->first);
        mapEnt = sMapStore.LookupEntry(mapid);
        if (!mapEnt || !mapEnt->IsRaid())
            continue;

        data << uint32(mapid);
        data << uint32(itr->second - cur_time);
        data << uint32(mapEnt->unk_time);
        ++counter;
    }

    data.put<uint32>(p_counter, counter);

    // TODO: Fix this -- read from DBC?
    std::string holidayName = "";
    uint32 holidaycount = 0;
    data << uint32(holidaycount);                           // holiday count
    for (uint32 i = 0; i < holidaycount; ++i)
    {
        data << uint32(0);                                  // Unk
        data << uint32(0);                                  // Unk
        data << uint32(0);                                  // Unk
        data << uint32(0);                                  // Unk
        data << uint32(0);                                  // Unk
        for (uint8 j = 0; j < 26; ++j)
            data << uint32(0);                              // Unk
        for (uint8 j = 0; j < 10; ++j)
            data << uint32(0);                              // Unk
        for (uint8 j = 0; j < 10; ++j)
            data << uint32(0);                              // Unk
        data << holidayName.c_str();                        // holiday name
    }

    sLog->outDebug(LOG_FILTER_NETWORKIO, "Sending calendar");
    data.hexlike();
    SendPacket(&data);
}

void WorldSession::HandleCalendarGetEvent(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_GET_EVENT");
    uint64 eventId;
    recv_data >> eventId;
    if (!eventId)
        return;
    //SendCalendarEvent(eventId);
}

void WorldSession::HandleCalendarGuildFilter(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_GUILD_FILTER");
    uint32 unk1;
    uint32 unk2;
    uint32 unk3;
    recv_data >> unk1;
    recv_data >> unk2;
    recv_data >> unk3;
}

void WorldSession::HandleCalendarArenaTeam(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_ARENA_TEAM");
    uint32 unk1;
    recv_data >> unk1;
}

void WorldSession::HandleCalendarAddEvent(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_ADD_EVENT");
    std::string title;
    std::string description;
    uint8 type;
    uint8 unkbyte;
    uint32 maxInvites;
    uint32 dungeonId;
    uint32 eventPackedTime;
    uint32 unkPackedTime;
    uint32 flags;

    recv_data >> title;
    recv_data >> description;
    recv_data >> type;
    recv_data >> unkbyte;
    recv_data >> maxInvites;
    recv_data >> dungeonId;
    recv_data >> eventPackedTime;
    recv_data >> unkPackedTime;
    recv_data >> flags;

    CalendarEvent event;
    event.id = sCalendarMgr->GetNextEventID();
    event.name = title;
    event.description = description;
    event.type = type;
    event.unk = unkbyte;
    event.dungeonId = dungeonId;
    event.flags = flags;
    event.time = eventPackedTime;
    event.unkTime = unkPackedTime;
    event.creator_guid = GetPlayer()->GetGUID();

    sCalendarMgr->AddEvent(event);

    if (((flags >> 6) & 1))
        return;

    uint32 inviteCount;
    recv_data >> inviteCount;

    if (!inviteCount)
        return;

    uint64 guid;
    uint8 status;
    uint8 rank;
    for (int32 i = 0; i < inviteCount; ++i)
    {
        CalendarInvite invite;
        invite.id = sCalendarMgr->GetNextInviteID();
        recv_data.readPackGUID(guid);
        recv_data >> status;
        recv_data >> rank;
        invite.event = event.id;
        invite.creator_guid = GetPlayer()->GetGUID();
        invite.target_guid = guid;
        invite.status = status;
        invite.rank = rank;
        invite.time = event.time;
        invite.text = ""; // hmm...
        invite.unk1 = invite.unk2 = invite.unk3 = 0;
        sCalendarMgr->AddInvite(invite);
    }
    //SendCalendarEvent(eventId, true);
}

void WorldSession::HandleCalendarUpdateEvent(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_UPDATE_EVENT");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> std::string
    //recv_data >> std::string
    //recv_data >> uint8
    //recv_data >> uint8
    //recv_data >> uint32
    //recv_data >> uint32
    //recv_data >> uint32
    //recv_data >> uint32
    //recv_data >> uint32
}

void WorldSession::HandleCalendarRemoveEvent(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_REMOVE_EVENT");
    uint64 eventId;
    uint64 creatorGuid;
    uint32 unk1;

    recv_data >> eventId;
    recv_data >> creatorGuid;
    recv_data >> unk1;
}

void WorldSession::HandleCalendarCopyEvent(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_COPY_EVENT");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32

}

void WorldSession::HandleCalendarEventInvite(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_EVENT_INVITE");

    uint64 eventId;
    uint64 inviteId;
    std::string name;
    uint8 status;
    uint8 rank;
 
    recv_data >> eventId;
    recv_data >> inviteId;
    recv_data >> name;
    recv_data >> status;
    recv_data >> rank;

    //FIXME - Finish it
}

void WorldSession::HandleCalendarEventRsvp(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_EVENT_RSVP");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32

}

void WorldSession::HandleCalendarEventRemoveInvite(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_EVENT_REMOVE_INVITE");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data.readPackGUID(guid)
    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint64
}

void WorldSession::HandleCalendarEventStatus(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_EVENT_STATUS");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data.readPackGUID(guid)
    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32
}

void WorldSession::HandleCalendarEventModeratorStatus(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_EVENT_MODERATOR_STATUS");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data.readPackGUID(guid)
    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32
}

void WorldSession::HandleCalendarComplain(WorldPacket &recv_data)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_COMPLAIN");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint64
}

void WorldSession::HandleCalendarGetNumPending(WorldPacket & /*recv_data*/)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CALENDAR_GET_NUM_PENDING");  // empty

    WorldPacket data(SMSG_CALENDAR_SEND_NUM_PENDING, 4);
    data << uint32(0);                                      // number of pending invites
    SendPacket(&data);
}

void WorldSession::SendCalendarEvent(uint64 eventId, bool added)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_CALENDAR_SEND_EVENT");
    WorldPacket data(SMSG_CALENDAR_SEND_EVENT);
    data << uint8(added);                                   // from add_event
    data.appendPackGUID(0);                                 // creator GUID
    data << uint64(0);                                      // event ID
    data << uint8(0);                                       // event name
    data << uint8(0);                                       // event description
    data << uint8(0);                                       // event type
    data << uint8(0);                                       // unk
    data << uint32(100);                                    // Max invites
    data << int32(0);                                       // dungeon ID
    data << uint32(0);                                      // unk time
    data << uint32(0);                                      // event time
    data << uint32(0);                                      // event flags
    data << uint32(0);                                      // event guild id

    if (false) // invites exist
    {
        data << uint32(0);                                  // invite count
        for (uint8 i = 0; i < 0; ++i)
        {         
            data << uint64(0);                              // invite played guid
            data << uint8(0);                               // unk
            data << uint8(0);                               // status
            data << uint8(0);                               // rank
            data << uint8(0);                               // unk
            data << uint64(0);                              // invite ID
            data << uint32(0);                              // unk
            data << uint8(0);                               // text
        }
    }
    SendPacket(&data);
}

void WorldSession::SendCalendarEventInviteAlert(uint64 eventId, uint64 inviteId)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_CALENDAR_EVENT_INVITE_ALERT");
    WorldPacket data(SMSG_CALENDAR_EVENT_INVITE_ALERT);
    data << uint64(0);                           // event ID
    data << uint8(0);                            // event title
    data << uint32(0);                           // event time
    uint32 unknum = 1;
    data << uint32(unknum);
    data << uint8(0);                            // event type
    data << uint32(0);                           // dungeon id
    data << uint64(0);                           // invite id
    data << uint8(0);                            // invite status
    data << uint8(0);                            // invite rank
    data.appendPackGUID(0);                      // event creator
    data.appendPackGUID(0);                      // invite sender
    SendPacket(&data);
}

void WorldSession::SendCalendarEventRemovedAlert(uint64 eventId)
{
    sLog->outDebug(LOG_FILTER_NETWORKIO, "SMSG_CALENDAR_EVENT_REMOVED_ALERT");
    WorldPacket data(SMSG_CALENDAR_EVENT_REMOVED_ALERT);
    data << uint8(0);                            // unk
    data << uint64(0);                           // invite id
    data << uint32(0);                           // invite time
    SendPacket(&data);
}
