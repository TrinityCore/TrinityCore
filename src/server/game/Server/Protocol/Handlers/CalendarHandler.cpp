/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "InstanceSaveMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"

void WorldSession::HandleCalendarGetCalendar(WorldPacket & /*recv_data*/)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_GET_CALENDAR");     // empty

    time_t cur_time = time(NULL);

    WorldPacket data(SMSG_CALENDAR_SEND_CALENDAR,4+4*0+4+4*0+4+4);

    data << uint32(0);                                      // invite count
    /*
    for (;;)
    {
        uint64 inviteId;
        uint64 unkGuid0;
        uint8 unk1, unk2, unk3;
        uint64 creatorGuid;
    }
    */

    data << uint32(0);                                      // event count
    /*
    for (;;)
    {
        uint64 eventId;
        std::string title;                                  // 128 chars
        uint32 type;
        uint32 occurrenceTime;
        uint32 flags;
        uint32 unk4; -- possibly mapid for dungeon/raid
        uint64 creatorGuid;
    }
    */

    data << uint32(0);                                      // unk
    data << uint32(secsToTimeBitFields(cur_time));          // current time

    uint32 counter = 0;
    size_t p_counter = data.wpos();
    data << uint32(counter);                                // instance save count

    for (int i = 0; i < MAX_DIFFICULTY; ++i)
    {
        for (Player::BoundInstancesMap::const_iterator itr = _player->m_boundInstances[i].begin(); itr != _player->m_boundInstances[i].end(); ++itr)
        {
            if (itr->second.perm)
            {
                InstanceSave *save = itr->second.save;
                data << uint32(save->GetMapId());
                data << uint32(save->GetDifficulty());
                data << uint32(save->GetResetTime() - cur_time);
                data << uint64(save->GetInstanceId());      // instance save id as unique instance copy id
                ++counter;
            }
        }
    }

    data.put<uint32>(p_counter, counter);

    data << uint32(1135753200);                             // unk (28.12.2005 12:00)

    counter = 0;
    p_counter = data.wpos();
    data << uint32(counter);                                // raid reset count

    ResetTimeByMapDifficultyMap const& resets = sInstanceSaveMgr->GetResetTimeMap();
    for (ResetTimeByMapDifficultyMap::const_iterator itr = resets.begin(); itr != resets.end(); ++itr)
    {
        uint32 mapid = PAIR32_LOPART(itr->first);
        MapEntry const* mapEnt = sMapStore.LookupEntry(mapid);
        if (!mapEnt || !mapEnt->IsRaid())
            continue;

        data << uint32(mapid);
        data << uint32(itr->second - cur_time);
        data << uint32(mapEnt->unk_time);
        ++counter;
    }

    data.put<uint32>(p_counter, counter);

    data << uint32(0);                                      // holiday count?
    /*
    for (;;)
    {
        uint32 unk5, unk6, unk7, unk8, unk9;
        for (uint32 j = 0; j < 26; ++j)
        {
            uint32 unk10;
        }
        for (uint32 j = 0; j < 10; ++j)
        {
            uint32 unk11;
        }
        for (uint32 j = 0; j < 10; ++j)
        {
            uint32 unk12;
        }
        std::string holidayName;                            // 64 chars
    }
    */

    sLog->outDebug("Sending calendar");
    data.hexlike();
    SendPacket(&data);
}

void WorldSession::HandleCalendarGetEvent(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_GET_EVENT");
    recv_data.hexlike();
    recv_data.read_skip<uint64>();                          // unk
}

void WorldSession::HandleCalendarGuildFilter(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_GUILD_FILTER");
    recv_data.hexlike();
    recv_data.read_skip<uint32>();                          // unk1
    recv_data.read_skip<uint32>();                          // unk2
    recv_data.read_skip<uint32>();                          // unk3
}

void WorldSession::HandleCalendarArenaTeam(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_ARENA_TEAM");
    recv_data.hexlike();
    recv_data.read_skip<uint32>();                          // unk
}

void WorldSession::HandleCalendarAddEvent(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_ADD_EVENT");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //std::string unk1, unk2;
    //recv_data >> (std::string)unk1;
    //recv_data >> (std::string)unk2;

    //uint8   unk3, unk4;
    //uint32  unk5, unk6, unk7, unk8, unk9, count = 0;
    //recv_data >> (uint8)unk3;
    //recv_data >> (uint8)unk4;
    //recv_data >> (uint32)unk5;
    //recv_data >> (uint32)unk6;
    //recv_data >> (uint32)unk7;
    //recv_data >> (uint32)unk8;
    //recv_data >> (uint32)unk9;
    //if (!((unk9 >> 6) & 1))
    //{
    //    recv_data >> (uint32)count;
    //    if (count)
    //    {
    //        uint8 unk12,unk13;
    //        uint64 guid;
    //        for (int i=0; i<count; i++)
    //        {
    //            recv_data.readPackGUID(guid);
    //            recv_data >> (uint8)unk12;
    //            recv_data >> (uint8)unk13;
    //        }
    //    }
    //}
}

void WorldSession::HandleCalendarUpdateEvent(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_UPDATE_EVENT");
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
    sLog->outDebug("WORLD: CMSG_CALENDAR_REMOVE_EVENT");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32

}

void WorldSession::HandleCalendarCopyEvent(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_COPY_EVENT");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32

}

void WorldSession::HandleCalendarEventInvite(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_EVENT_INVITE");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> std::string
    //recv_data >> uint8
    //recv_data >> uint8

}

void WorldSession::HandleCalendarEventRsvp(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_EVENT_RSVP");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint32

}

void WorldSession::HandleCalendarEventRemoveInvite(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_EVENT_REMOVE_INVITE");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data.readPackGUID(guid)
    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint64
}

void WorldSession::HandleCalendarEventStatus(WorldPacket &recv_data)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_EVENT_STATUS");
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
    sLog->outDebug("WORLD: CMSG_CALENDAR_EVENT_MODERATOR_STATUS");
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
    sLog->outDebug("WORLD: CMSG_CALENDAR_COMPLAIN");
    recv_data.hexlike();
    recv_data.rpos(recv_data.wpos());                       // set to end to avoid warnings spam

    //recv_data >> uint64
    //recv_data >> uint64
    //recv_data >> uint64
}

void WorldSession::HandleCalendarGetNumPending(WorldPacket & /*recv_data*/)
{
    sLog->outDebug("WORLD: CMSG_CALENDAR_GET_NUM_PENDING");  // empty

    WorldPacket data(SMSG_CALENDAR_SEND_NUM_PENDING, 4);
    data << uint32(0);                                      // 0 - no pending invites, 1 - some pending invites
    SendPacket(&data);
}
