/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

/*
----- Opcodes Not Used yet -----

SMSG_CALENDAR_EVENT_INVITE_NOTES        [ packguid(Invitee), uint64(inviteId), string(Text), Boolean(Unk) ]
?CMSG_CALENDAR_EVENT_INVITE_NOTES       [ uint32(unk1), uint32(unk2), uint32(unk3), uint32(unk4), uint32(unk5) ]
SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT  [ uint64(inviteId), string(Text) ]
SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT [ uint64(eventId), uint32(eventTime), uint32(unkFlag), uint8(deletePending) ]
SMSG_CALENDAR_RAID_LOCKOUT_UPDATED      SendCalendarRaidLockoutUpdated(InstanceSave const* save)

@todo

Finish complains' handling - what to do with received complains and how to respond?
Find out what to do with all "not used yet" opcodes
Correct errors sending (event/invite not found, invites exceeded, event already passed, permissions etc.)
Fix locked events to be displayed properly and response time shouldn't be shown for people that haven't respond yet
Copied events should probably have a new owner

*/

#include "CharacterCache.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "Opcodes.h"
#include "Player.h"
#include "SocialMgr.h"
#include "CalendarMgr.h"
#include "ObjectAccessor.h"
#include "DatabaseEnv.h"
#include "GuildMgr.h"
#include "ArenaTeamMgr.h"
#include "WorldSession.h"

void WorldSession::HandleCalendarGetCalendar(WorldPacket& /*recvData*/)
{
    ObjectGuid guid = _player->GetGUID();
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_CALENDAR [%s]", guid.ToString().c_str());

    time_t currTime = time(NULL);

    WorldPacket data(SMSG_CALENDAR_SEND_CALENDAR, 1000); // Average size if no instance

    CalendarInviteStore invites = sCalendarMgr->GetPlayerInvites(guid);
    data << uint32(invites.size());
    for (CalendarInviteStore::const_iterator itr = invites.begin(); itr != invites.end(); ++itr)
    {
        data << uint64((*itr)->GetEventId());
        data << uint64((*itr)->GetInviteId());
        data << uint8((*itr)->GetStatus());
        data << uint8((*itr)->GetRank());

        if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent((*itr)->GetEventId()))
        {
            data << uint8(calendarEvent->IsGuildEvent());
            data << calendarEvent->GetCreatorGUID().WriteAsPacked();
        }
        else
        {
            data << uint8(0);
            data << (*itr)->GetSenderGUID().WriteAsPacked();
        }
    }

    CalendarEventStore playerEvents = sCalendarMgr->GetPlayerEvents(guid);
    data << uint32(playerEvents.size());
    for (CalendarEventStore::const_iterator itr = playerEvents.begin(); itr != playerEvents.end(); ++itr)
    {
        CalendarEvent* calendarEvent = *itr;

        data << uint64(calendarEvent->GetEventId());
        data << calendarEvent->GetTitle();
        data << uint32(calendarEvent->GetType());
        data.AppendPackedTime(calendarEvent->GetEventTime());
        data << uint32(calendarEvent->GetFlags());
        data << int32(calendarEvent->GetDungeonId());
        data << calendarEvent->GetCreatorGUID().WriteAsPacked();
    }

    data << uint32(currTime);                              // server time
    data.AppendPackedTime(currTime);                       // zone time

    ByteBuffer dataBuffer;
    uint32 boundCounter = 0;
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        Player::BoundInstancesMap boundInstances = _player->GetBoundInstances(Difficulty(i));
        for (Player::BoundInstancesMap::const_iterator itr = boundInstances.begin(); itr != boundInstances.end(); ++itr)
        {
            if (itr->second.perm)
            {
                InstanceSave const* save = itr->second.save;
                dataBuffer << uint32(save->GetMapId());
                dataBuffer << uint32(save->GetDifficulty());
                dataBuffer << uint32(save->GetResetTime() - currTime);
                dataBuffer << uint64(save->GetInstanceId());     // instance save id as unique instance copy id
                ++boundCounter;
            }
        }
    }

    data << uint32(boundCounter);
    data.append(dataBuffer);

    data << uint32(1135753200);                            // Constant date, unk (28.12.2005 07:00)

    // Reuse variables
    boundCounter = 0;
    std::set<uint32> sentMaps;
    dataBuffer.clear();

    ResetTimeByMapDifficultyMap const& resets = sInstanceSaveMgr->GetResetTimeMap();
    for (ResetTimeByMapDifficultyMap::const_iterator itr = resets.begin(); itr != resets.end(); ++itr)
    {
        uint32 mapId = PAIR32_LOPART(itr->first);
        if (sentMaps.find(mapId) != sentMaps.end())
            continue;

        MapEntry const* mapEntry = sMapStore.LookupEntry(mapId);
        if (!mapEntry || !mapEntry->IsRaid())
            continue;

        sentMaps.insert(mapId);

        dataBuffer << int32(mapId);
        dataBuffer << int32(itr->second - currTime);
        dataBuffer << int32(0); // Never seen anything else in sniffs - still unknown
        ++boundCounter;
    }

    data << uint32(boundCounter);
    data.append(dataBuffer);

    /// @todo Fix this, how we do know how many and what holidays to send?
    uint32 holidayCount = 0;
    data << uint32(holidayCount);
    for (uint32 i = 0; i < holidayCount; ++i)
    {
        HolidaysEntry const* holiday = sHolidaysStore.LookupEntry(666);

        data << uint32(holiday->Id);                        // m_ID
        data << uint32(holiday->Region);                    // m_region, might be looping
        data << uint32(holiday->Looping);                   // m_looping, might be region
        data << uint32(holiday->Priority);                  // m_priority
        data << uint32(holiday->CalendarFilterType);        // m_calendarFilterType

        for (uint8 j = 0; j < MAX_HOLIDAY_DATES; ++j)
            data << uint32(holiday->Date[j]);               // 26 * m_date -- WritePackedTime ?

        for (uint8 j = 0; j < MAX_HOLIDAY_DURATIONS; ++j)
            data << uint32(holiday->Duration[j]);           // 10 * m_duration

        for (uint8 j = 0; j < MAX_HOLIDAY_FLAGS; ++j)
            data << uint32(holiday->CalendarFlags[j]);      // 10 * m_calendarFlags

        data << holiday->TextureFilename;                   // m_textureFilename (holiday name)
    }

    SendPacket(&data);
}

void WorldSession::HandleCalendarGetEvent(WorldPacket& recvData)
{
    uint64 eventId;
    recvData >> eventId;

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_EVENT. Player [%s] Event [" UI64FMTD "]", _player->GetGUID().ToString().c_str(), eventId);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
        sCalendarMgr->SendCalendarEvent(_player->GetGUID(), *calendarEvent, CALENDAR_SENDTYPE_GET);
    else
        sCalendarMgr->SendCalendarCommandResult(_player->GetGUID(), CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarGuildFilter(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GUILD_FILTER [%s]", _player->GetGUID().ToString().c_str());

    uint32 minLevel;
    uint32 maxLevel;
    uint32 minRank;

    recvData >> minLevel >> maxLevel >> minRank;

    if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
        guild->MassInviteToEvent(this, minLevel, maxLevel, minRank);

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GUILD_FILTER: Min level [%d], Max level [%d], Min rank [%d]", minLevel, maxLevel, minRank);
}

void WorldSession::HandleCalendarArenaTeam(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_ARENA_TEAM [%s]", _player->GetGUID().ToString().c_str());

    uint32 arenaTeamId;
    recvData >> arenaTeamId;

    if (ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(arenaTeamId))
        team->MassInviteToEvent(this);
}

void WorldSession::HandleCalendarAddEvent(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();

    std::string title;
    std::string description;
    uint8 type;
    uint8 repeatable;
    uint32 maxInvites;
    int32 dungeonId;
    uint32 eventPackedTime;
    uint32 unkPackedTime;
    uint32 flags;

    recvData >> title >> description >> type >> repeatable >> maxInvites >> dungeonId;
    recvData.ReadPackedTime(eventPackedTime);
    recvData.ReadPackedTime(unkPackedTime);
    recvData >> flags;

    // prevent events in the past
    // To Do: properly handle timezones and remove the "- time_t(86400L)" hack
    if (time_t(eventPackedTime) < (time(NULL) - time_t(86400L)))
    {
        recvData.rfinish();
        return;
    }

    CalendarEvent* calendarEvent = new CalendarEvent(sCalendarMgr->GetFreeEventId(), guid, 0, CalendarEventType(type), dungeonId,
        time_t(eventPackedTime), flags, time_t(unkPackedTime), title, description);

    if (calendarEvent->IsGuildEvent() || calendarEvent->IsGuildAnnouncement())
        if (Player* creator = ObjectAccessor::FindPlayer(guid))
            calendarEvent->SetGuildId(creator->GetGuildId());

    if (calendarEvent->IsGuildAnnouncement())
    {
        // 946684800 is 01/01/2000 00:00:00 - default response time
        CalendarInvite invite(0, calendarEvent->GetEventId(), ObjectGuid::Empty, guid, 946684800, CALENDAR_STATUS_NOT_SIGNED_UP, CALENDAR_RANK_PLAYER, "");
        // WARNING: By passing pointer to a local variable, the underlying method(s) must NOT perform any kind
        // of storage of the pointer as it will lead to memory corruption
        sCalendarMgr->AddInvite(calendarEvent, &invite);
    }
    else
    {
        // client limits the amount of players to be invited to 100
        const uint32 MaxPlayerInvites = 100;

        uint32 inviteCount;
        ObjectGuid invitee[MaxPlayerInvites];
        uint8 status[MaxPlayerInvites];
        uint8 rank[MaxPlayerInvites];

        memset(status, 0, sizeof(status));
        memset(rank, 0, sizeof(rank));

        try
        {
            recvData >> inviteCount;

            for (uint32 i = 0; i < inviteCount && i < MaxPlayerInvites; ++i)
            {
                recvData >> invitee[i].ReadAsPacked();
                recvData >> status[i] >> rank[i];
            }
        }
        catch (ByteBufferException const&)
        {
            delete calendarEvent;
            calendarEvent = NULL;
            throw;
        }

        SQLTransaction trans;
        if (inviteCount > 1)
            trans = CharacterDatabase.BeginTransaction();

        for (uint32 i = 0; i < inviteCount && i < MaxPlayerInvites; ++i)
        {
            // 946684800 is 01/01/2000 00:00:00 - default response time
            CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), calendarEvent->GetEventId(), invitee[i], guid, 946684800, CalendarInviteStatus(status[i]), CalendarModerationRank(rank[i]), "");
            sCalendarMgr->AddInvite(calendarEvent, invite, trans);
        }

        if (inviteCount > 1)
            CharacterDatabase.CommitTransaction(trans);
    }

    sCalendarMgr->AddEvent(calendarEvent, CALENDAR_SENDTYPE_ADD);
}

void WorldSession::HandleCalendarUpdateEvent(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    time_t oldEventTime;

    uint64 eventId;
    uint64 inviteId;
    std::string title;
    std::string description;
    uint8 type;
    uint8 repetitionType;
    uint32 maxInvites;
    int32 dungeonId;
    uint32 eventPackedTime;
    uint32 timeZoneTime;
    uint32 flags;

    recvData >> eventId >> inviteId >> title >> description >> type >> repetitionType >> maxInvites >> dungeonId;
    recvData.ReadPackedTime(eventPackedTime);
    recvData.ReadPackedTime(timeZoneTime);
    recvData >> flags;

    // prevent events in the past
    // To Do: properly handle timezones and remove the "- time_t(86400L)" hack
    if (time_t(eventPackedTime) < (time(NULL) - time_t(86400L)))
    {
        recvData.rfinish();
        return;
    }

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_UPDATE_EVENT [%s] EventId [" UI64FMTD
        "], InviteId [" UI64FMTD "] Title %s, Description %s, type %u "
        "Repeatable %u, MaxInvites %u, Dungeon ID %d, Time %u "
        "Time2 %u, Flags %u", guid.ToString().c_str(), eventId, inviteId, title.c_str(),
        description.c_str(), type, repetitionType, maxInvites, dungeonId,
        eventPackedTime, timeZoneTime, flags);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
    {
        oldEventTime = calendarEvent->GetEventTime();

        calendarEvent->SetType(CalendarEventType(type));
        calendarEvent->SetFlags(flags);
        calendarEvent->SetEventTime(time_t(eventPackedTime));
        calendarEvent->SetTimeZoneTime(time_t(timeZoneTime)); // Not sure, seems constant from the little sniffs we have
        calendarEvent->SetDungeonId(dungeonId);
        calendarEvent->SetTitle(title);
        calendarEvent->SetDescription(description);

        sCalendarMgr->UpdateEvent(calendarEvent);
        sCalendarMgr->SendCalendarEventUpdateAlert(*calendarEvent, oldEventTime);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarRemoveEvent(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    uint64 eventId;

    recvData >> eventId;
    recvData.rfinish(); // Skip flags & invite ID, we don't use them

    sCalendarMgr->RemoveEvent(eventId, guid);
}

void WorldSession::HandleCalendarCopyEvent(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    uint64 eventId;
    uint64 inviteId;
    uint32 eventTime;

    recvData >> eventId >> inviteId;
    recvData.ReadPackedTime(eventTime);
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_COPY_EVENT [%s], EventId [" UI64FMTD
        "] inviteId [" UI64FMTD "] Time: %u", guid.ToString().c_str(), eventId, inviteId, eventTime);

    // prevent events in the past
    // To Do: properly handle timezones and remove the "- time_t(86400L)" hack
    if (time_t(eventTime) < (time(NULL) - time_t(86400L)))
    {
        recvData.rfinish();
        return;
    }

    if (CalendarEvent* oldEvent = sCalendarMgr->GetEvent(eventId))
    {
        CalendarEvent* newEvent = new CalendarEvent(*oldEvent, sCalendarMgr->GetFreeEventId());
        newEvent->SetEventTime(time_t(eventTime));
        sCalendarMgr->AddEvent(newEvent, CALENDAR_SENDTYPE_COPY);

        CalendarInviteStore invites = sCalendarMgr->GetEventInvites(eventId);
        SQLTransaction trans;
        if (invites.size() > 1)
            trans = CharacterDatabase.BeginTransaction();

        for (CalendarInviteStore::const_iterator itr = invites.begin(); itr != invites.end(); ++itr)
            sCalendarMgr->AddInvite(newEvent, new CalendarInvite(**itr, sCalendarMgr->GetFreeInviteId(), newEvent->GetEventId()), trans);

        if (invites.size() > 1)
            CharacterDatabase.CommitTransaction(trans);
        // should we change owner when somebody makes a copy of event owned by another person?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventInvite(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_INVITE");

    ObjectGuid playerGuid = _player->GetGUID();

    uint64 eventId;
    uint64 inviteId;
    std::string name;
    bool isPreInvite;
    bool isGuildEvent;

    ObjectGuid inviteeGuid;
    uint32 inviteeTeam = 0;
    uint32 inviteeGuildId = 0;

    recvData >> eventId >> inviteId >> name >> isPreInvite >> isGuildEvent;

    if (!normalizePlayerName(name))
        return;

    if (Player* player = ObjectAccessor::FindConnectedPlayerByName(name))
    {
        // Invitee is online
        inviteeGuid = player->GetGUID();
        inviteeTeam = player->GetTeam();
        inviteeGuildId = player->GetGuildId();
    }
    else
    {
        // Invitee offline, get data from storage
        ObjectGuid guid = sCharacterCache->GetCharacterGuidByName(name);
        if (!guid.IsEmpty())
        {
            if (CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByGuid(guid))
            {
                inviteeGuid = guid;
                inviteeTeam = Player::TeamForRace(characterInfo->Race);
                inviteeGuildId = characterInfo->GuildId;
            }
        }
    }

    if (!inviteeGuid)
    {
        sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_PLAYER_NOT_FOUND);
        return;
    }

    if (_player->GetTeam() != inviteeTeam && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CALENDAR))
    {
        sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NOT_ALLIED);
        return;
    }

    if (QueryResult result = CharacterDatabase.PQuery("SELECT flags FROM character_social WHERE guid = %u AND friend = %u", inviteeGuid.GetCounter(), playerGuid.GetCounter()))
    {
        Field* fields = result->Fetch();
        if (fields[0].GetUInt8() & SOCIAL_FLAG_IGNORED)
        {
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_IGNORING_YOU_S, name.c_str());
            return;
        }
    }

    if (!isPreInvite)
    {
        if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
        {
            if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() == inviteeGuildId)
            {
                // we can't invite guild members to guild events
                sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NO_GUILD_INVITES);
                return;
            }

            // 946684800 is 01/01/2000 00:00:00 - default response time
            CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), eventId, inviteeGuid, playerGuid, 946684800, CALENDAR_STATUS_INVITED, CALENDAR_RANK_PLAYER, "");
            sCalendarMgr->AddInvite(calendarEvent, invite);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_EVENT_INVALID);
    }
    else
    {
        if (isGuildEvent && inviteeGuildId == _player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NO_GUILD_INVITES);
            return;
        }

        // 946684800 is 01/01/2000 00:00:00 - default response time
        CalendarInvite invite(inviteId, 0, inviteeGuid, playerGuid, 946684800, CALENDAR_STATUS_INVITED, CALENDAR_RANK_PLAYER, "");
        sCalendarMgr->SendCalendarEventInvite(invite);
    }
}

void WorldSession::HandleCalendarEventSignup(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    uint64 eventId;
    bool tentative;

    recvData >> eventId >> tentative;
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_SIGNUP [%s] EventId [" UI64FMTD "] Tentative %u", guid.ToString().c_str(), eventId, tentative);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
    {
        if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() != _player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD);
            return;
        }

        CalendarInviteStatus status = tentative ? CALENDAR_STATUS_TENTATIVE : CALENDAR_STATUS_SIGNED_UP;
        CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), eventId, guid, guid, time(NULL), status, CALENDAR_RANK_PLAYER, "");
        sCalendarMgr->AddInvite(calendarEvent, invite);
        sCalendarMgr->SendCalendarClearPendingAction(guid);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventRsvp(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    uint64 eventId;
    uint64 inviteId;
    uint32 status;

    recvData >> eventId >> inviteId >> status;
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_RSVP [%s] EventId ["
        UI64FMTD "], InviteId [" UI64FMTD "], status %u", guid.ToString().c_str(), eventId,
        inviteId, status);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
    {
        // i think we still should be able to remove self from locked events
        if (status != CALENDAR_STATUS_REMOVED && calendarEvent->GetFlags() & CALENDAR_FLAG_INVITES_LOCKED)
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_LOCKED);
            return;
        }

        if (CalendarInvite* invite = sCalendarMgr->GetInvite(inviteId))
        {
            invite->SetStatus(CalendarInviteStatus(status));
            invite->SetStatusTime(time(NULL));

            sCalendarMgr->UpdateInvite(invite);
            sCalendarMgr->SendCalendarEventStatus(*calendarEvent, *invite);
            sCalendarMgr->SendCalendarClearPendingAction(guid);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE); // correct?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventRemoveInvite(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    ObjectGuid invitee;
    uint64 eventId;
    uint64 ownerInviteId; // isn't it sender's inviteId?
    uint64 inviteId;

    recvData >> invitee.ReadAsPacked();
    recvData >> inviteId >> ownerInviteId >> eventId;

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_REMOVE_INVITE [%s] EventId [" UI64FMTD
        "], ownerInviteId [" UI64FMTD "], Invitee ([%s] id: [" UI64FMTD "])",
        guid.ToString().c_str(), eventId, ownerInviteId, invitee.ToString().c_str(), inviteId);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
    {
        if (calendarEvent->GetCreatorGUID() == invitee)
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_DELETE_CREATOR_FAILED);
            return;
        }

        sCalendarMgr->RemoveInvite(inviteId, eventId, guid);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE);
}

void WorldSession::HandleCalendarEventStatus(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    ObjectGuid invitee;
    uint64 eventId;
    uint64 inviteId;
    uint64 ownerInviteId; // isn't it sender's inviteId?
    uint8 status;

    recvData >> invitee.ReadAsPacked();
    recvData >> eventId >> inviteId >> ownerInviteId >> status;
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_STATUS [%s] EventId ["
        UI64FMTD "] ownerInviteId [" UI64FMTD "], Invitee ([%s] id: ["
        UI64FMTD "], status %u", guid.ToString().c_str(), eventId, ownerInviteId, invitee.ToString().c_str(), inviteId, status);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
    {
        if (CalendarInvite* invite = sCalendarMgr->GetInvite(inviteId))
        {
            invite->SetStatus((CalendarInviteStatus)status);
            // not sure if we should set response time when moderator changes invite status
            //invite->SetStatusTime(time(NULL));

            sCalendarMgr->UpdateInvite(invite);
            sCalendarMgr->SendCalendarEventStatus(*calendarEvent, *invite);
            sCalendarMgr->SendCalendarClearPendingAction(invitee);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE); // correct?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventModeratorStatus(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    ObjectGuid invitee;
    uint64 eventId;
    uint64 inviteId;
    uint64 ownerInviteId; // isn't it sender's inviteId?
    uint8 rank;

    recvData >> invitee.ReadAsPacked();
    recvData >> eventId >> inviteId >> ownerInviteId >> rank;
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_MODERATOR_STATUS [%s] EventId ["
        UI64FMTD "] ownerInviteId [" UI64FMTD "], Invitee ([%s] id: ["
        UI64FMTD "], rank %u", guid.ToString().c_str(), eventId, ownerInviteId, invitee.ToString().c_str(), inviteId, rank);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(eventId))
    {
        if (CalendarInvite* invite = sCalendarMgr->GetInvite(inviteId))
        {
            invite->SetRank(CalendarModerationRank(rank));
            sCalendarMgr->UpdateInvite(invite);
            sCalendarMgr->SendCalendarEventModeratorStatusAlert(*calendarEvent, *invite);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE); // correct?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarComplain(WorldPacket& recvData)
{
    ObjectGuid guid = _player->GetGUID();
    uint64 eventId;
    ObjectGuid complainGUID;

    recvData >> eventId >> complainGUID;
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_COMPLAIN [%s] EventId ["
        UI64FMTD "] guid [%s]", guid.ToString().c_str(), eventId, complainGUID.ToString().c_str());

    // what to do with complains?
}

void WorldSession::HandleCalendarGetNumPending(WorldPacket& /*recvData*/)
{
    ObjectGuid guid = _player->GetGUID();
    uint32 pending = sCalendarMgr->GetPlayerNumPending(guid);

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_NUM_PENDING: [%s] Pending: %u", guid.ToString().c_str(), pending);

    WorldPacket data(SMSG_CALENDAR_SEND_NUM_PENDING, 4);
    data << uint32(pending);
    SendPacket(&data);
}

void WorldSession::HandleSetSavedInstanceExtend(WorldPacket& recvData)
{
    uint32 mapId, difficulty;
    uint8 toggleExtend;
    recvData >> mapId >> difficulty>> toggleExtend;
    TC_LOG_DEBUG("network", "CMSG_SET_SAVED_INSTANCE_EXTEND - MapId: %u, Difficulty: %u, ToggleExtend: %s", mapId, difficulty, toggleExtend ? "On" : "Off");

    if (Player* player = GetPlayer())
    {
        InstancePlayerBind* instanceBind = player->GetBoundInstance(mapId, Difficulty(difficulty), toggleExtend == 1); // include expired instances if we are toggling extend on
        if (!instanceBind || !instanceBind->save || !instanceBind->perm)
            return;

        BindExtensionState newState;
        if (!toggleExtend || instanceBind->extendState == EXTEND_STATE_EXPIRED)
            newState = EXTEND_STATE_NORMAL;
        else
            newState = EXTEND_STATE_EXTENDED;

        player->BindToInstance(instanceBind->save, true, newState, false);
    }

    /*
    InstancePlayerBind* instanceBind = _player->GetBoundInstance(mapId, Difficulty(difficulty));
    if (!instanceBind || !instanceBind->save)
        return;

    InstanceSave* save = instanceBind->save;
    // http://www.wowwiki.com/Instance_Lock_Extension
    // SendCalendarRaidLockoutUpdated(save);
    */
}

// ----------------------------------- SEND ------------------------------------

void WorldSession::SendCalendarRaidLockout(InstanceSave const* save, bool add)
{
    TC_LOG_DEBUG("network", "%s", add ? "SMSG_CALENDAR_RAID_LOCKOUT_ADDED" : "SMSG_CALENDAR_RAID_LOCKOUT_REMOVED");
    time_t currTime = time(NULL);

    WorldPacket data(SMSG_CALENDAR_RAID_LOCKOUT_REMOVED, (add ? 4 : 0) + 4 + 4 + 4 + 8);
    if (add)
    {
        data.SetOpcode(SMSG_CALENDAR_RAID_LOCKOUT_ADDED);
        data.AppendPackedTime(currTime);
    }

    data << uint32(save->GetMapId());
    data << uint32(save->GetDifficulty());
    data << uint32(save->GetResetTime() - currTime);
    data << uint64(save->GetInstanceId());
    SendPacket(&data);
}

void WorldSession::SendCalendarRaidLockoutUpdated(InstanceSave const* save)
{
    if (!save)
        return;

    ObjectGuid guid = _player->GetGUID();
    TC_LOG_DEBUG("network", "SMSG_CALENDAR_RAID_LOCKOUT_UPDATED [%s] Map: %u, Difficulty %u",
        guid.ToString().c_str(), save->GetMapId(), save->GetDifficulty());

    time_t currTime = time(NULL);

    WorldPacket data(SMSG_CALENDAR_RAID_LOCKOUT_UPDATED, 4 + 4 + 4 + 4 + 8);
    data.AppendPackedTime(currTime);
    data << uint32(save->GetMapId());
    data << uint32(save->GetDifficulty());
    data << uint32(0); // Amount of seconds that has changed to the reset time
    data << uint32(save->GetResetTime() - currTime);
    SendPacket(&data);
}
