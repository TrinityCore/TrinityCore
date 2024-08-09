/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "WorldSession.h"
#include "ArenaTeamMgr.h"
#include "CalendarMgr.h"
#include "CalendarPackets.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameEventMgr.h"
#include "GameTime.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceSaveMgr.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "SocialMgr.h"
#include "World.h"

void WorldSession::HandleCalendarGetCalendar(WorldPackets::Calendar::CalendarGetCalendar& /*calendarGetCalendar*/)
{
    ObjectGuid guid = _player->GetGUID();
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_CALENDAR [{}]", guid.ToString());

    time_t currTime = GameTime::GetGameTime();

    WorldPackets::Calendar::CalendarSendCalendar packet;
    packet.ServerTime = *GameTime::GetWowTime();
    packet.ServerNow = currTime;
    packet.RaidOrigin = 1135753200;                        // Constant date, unk (28.12.2005 07:00)

    CalendarInviteStore playerInvites = sCalendarMgr->GetPlayerInvites(guid);
    for (CalendarInvite const* invite : playerInvites)
    {
        WorldPackets::Calendar::CalendarSendCalendarInviteInfo& inviteInfo = packet.Invites.emplace_back();
        inviteInfo.EventID = invite->GetEventId();
        inviteInfo.InviteID = invite->GetInviteId();
        inviteInfo.InviterGuid = invite->GetSenderGUID();
        inviteInfo.Status = invite->GetStatus();
        inviteInfo.Moderator = invite->GetRank();
        if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(invite->GetEventId()))
            inviteInfo.InviteType = calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() == _player->GetGuildId();
    }

    CalendarEventStore playerEvents = sCalendarMgr->GetPlayerEvents(guid);
    for (CalendarEvent const* event : playerEvents)
    {
        WorldPackets::Calendar::CalendarSendCalendarEventInfo& eventInfo = packet.Events.emplace_back();
        eventInfo.EventID = event->GetEventId();
        eventInfo.Date.SetUtcTimeFromUnixTime(event->GetDate());
        eventInfo.Date += GetTimezoneOffset();
        eventInfo.EventName = event->GetTitle();
        eventInfo.EventType = event->GetType();
        eventInfo.Flags = event->GetFlags();
        eventInfo.OwnerGuid = event->GetOwnerGUID();
        eventInfo.TextureID = event->GetTextureId();
    }

    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        Player::BoundInstancesMap boundInstances = _player->GetBoundInstances(Difficulty(i));
        for (Player::BoundInstancesMap::const_iterator itr = boundInstances.begin(); itr != boundInstances.end(); ++itr)
        {
            if (itr->second.perm)
            {
                InstanceSave const* save = itr->second.save;
                WorldPackets::Calendar::CalendarSendCalendarRaidLockoutInfo& lockoutInfo = packet.RaidLockouts.emplace_back();
                lockoutInfo.MapID = save->GetMapId();
                lockoutInfo.DifficultyID = save->GetDifficulty();
                lockoutInfo.ExpireTime = int32(std::max(save->GetResetTime() - currTime, time_t(SI64LIT(0))));
                lockoutInfo.InstanceID = save->GetInstanceId();
            }
        }
    }

    std::set<uint32> sentMaps;

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

        WorldPackets::Calendar::CalendarSendCalendarRaidResetInfo& reset = packet.RaidResets.emplace_back();
        reset.MapID = mapId;
        reset.Duration = itr->second - currTime;
        reset.Offset = 0; // Never seen anything else in sniffs - still unknown
    }

    for (uint32 entry : sGameEventMgr->modifiedHolidays)
    {
        HolidaysEntry const* holiday = sHolidaysStore.LookupEntry(entry);

        WorldPackets::Calendar::CalendarSendCalendarHolidayInfo& holidayInfo = packet.Holidays.emplace_back();
        holidayInfo.HolidayID = holiday->ID;
        holidayInfo.Region = holiday->Region;
        holidayInfo.Looping = holiday->Looping;
        holidayInfo.Priority = holiday->Priority;
        holidayInfo.FilterType = holiday->CalendarFilterType;

        for (uint8 j = 0; j < MAX_HOLIDAY_DATES; ++j)
            holidayInfo.Date[j].SetPackedTime(holiday->Date[j]);

        for (uint8 j = 0; j < MAX_HOLIDAY_DURATIONS; ++j)
            holidayInfo.Duration[j] = holiday->Duration[j];

        for (uint8 j = 0; j < MAX_HOLIDAY_FLAGS; ++j)
            holidayInfo.CalendarFlags[j] = holiday->CalendarFlags[j];

        holidayInfo.TextureFilename = holiday->TextureFilename;
    }

    SendPacket(packet.Write());
}

void WorldSession::HandleCalendarGetEvent(WorldPackets::Calendar::CalendarGetEvent& calendarGetEvent)
{
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_EVENT. Player [{}] Event [{}]", _player->GetGUID().ToString(), calendarGetEvent.EventID);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarGetEvent.EventID))
        sCalendarMgr->SendCalendarEvent(_player->GetGUID(), *calendarEvent, CALENDAR_SENDTYPE_GET);
    else
        sCalendarMgr->SendCalendarCommandResult(_player->GetGUID(), CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarGuildFilter(WorldPackets::Calendar::CalendarGuildFilter& calendarGuildFilter)
{
    if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
        guild->MassInviteToEvent(this, calendarGuildFilter.MinLevel, calendarGuildFilter.MaxLevel, calendarGuildFilter.MaxRankOrder);

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GUILD_FILTER: Min level [{}], Max level [{}], Min rank [{}]",
        calendarGuildFilter.MinLevel, calendarGuildFilter.MaxLevel, calendarGuildFilter.MaxRankOrder);
}

void WorldSession::HandleCalendarArenaTeam(WorldPackets::Calendar::CalendarArenaTeam& calendarArenaTeam)
{
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_ARENA_TEAM [{}]", _player->GetGUID().ToString());

    if (ArenaTeam* team = sArenaTeamMgr->GetArenaTeamById(calendarArenaTeam.ArenaTeamId))
        team->MassInviteToEvent(this);
}

void WorldSession::HandleCalendarAddEvent(WorldPackets::Calendar::CalendarAddEvent& calendarAddEvent)
{
    ObjectGuid guid = _player->GetGUID();

    calendarAddEvent.Time -= GetTimezoneOffset();
    calendarAddEvent.LockDate -= GetTimezoneOffset();

    // prevent events in the past
    if (calendarAddEvent.Time < *GameTime::GetUtcWowTime())
    {
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_PASSED);
        return;
    }

    // If the event is a guild event, check if the player is in a guild
    if (CalendarEvent::IsGuildEvent(calendarAddEvent.Flags) || CalendarEvent::IsGuildAnnouncement(calendarAddEvent.Flags))
    {
        if (!_player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD);
            return;
        }
    }

    // Check if the player reached the max number of events allowed to create
    if (CalendarEvent::IsGuildEvent(calendarAddEvent.Flags) || CalendarEvent::IsGuildAnnouncement(calendarAddEvent.Flags))
    {
        if (sCalendarMgr->GetGuildEvents(_player->GetGuildId()).size() >= CALENDAR_MAX_GUILD_EVENTS)
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_EVENTS_EXCEEDED);
            return;
        }
    }
    else
    {
        if (sCalendarMgr->GetEventsCreatedBy(guid).size() >= CALENDAR_MAX_EVENTS)
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENTS_EXCEEDED);
            return;
        }
    }

    if (GetCalendarEventCreationCooldown() > GameTime::GetGameTime())
    {
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_INTERNAL);
        return;
    }
    SetCalendarEventCreationCooldown(GameTime::GetGameTime() + CALENDAR_CREATE_EVENT_COOLDOWN);

    CalendarEvent* calendarEvent = new CalendarEvent(sCalendarMgr->GetFreeEventId(), guid, 0, CalendarEventType(calendarAddEvent.EventType), calendarAddEvent.TextureID,
        calendarAddEvent.Time.GetUnixTimeFromUtcTime(), calendarAddEvent.Flags, calendarAddEvent.Title, calendarAddEvent.Description, calendarAddEvent.LockDate.GetUnixTimeFromUtcTime());

    if (calendarEvent->IsGuildEvent() || calendarEvent->IsGuildAnnouncement())
        calendarEvent->SetGuildId(_player->GetGuildId());

    if (calendarEvent->IsGuildAnnouncement())
    {
        CalendarInvite invite(0, calendarEvent->GetEventId(), ObjectGuid::Empty, guid, CALENDAR_DEFAULT_RESPONSE_TIME, CALENDAR_STATUS_NOT_SIGNED_UP, CALENDAR_RANK_PLAYER, "");
        // WARNING: By passing pointer to a local variable, the underlying method(s) must NOT perform any kind
        // of storage of the pointer as it will lead to memory corruption
        sCalendarMgr->AddInvite(calendarEvent, &invite);
    }
    else
    {
        CharacterDatabaseTransaction trans;
        if (calendarAddEvent.Invites.size() > 1)
            trans = CharacterDatabase.BeginTransaction();

        for (uint32 i = 0; i < calendarAddEvent.Invites.size(); ++i)
        {
            CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), calendarEvent->GetEventId(), calendarAddEvent.Invites[i].Guid,
                guid, CALENDAR_DEFAULT_RESPONSE_TIME, CalendarInviteStatus(calendarAddEvent.Invites[i].Status),
                CalendarModerationRank(calendarAddEvent.Invites[i].Moderator), "");
            sCalendarMgr->AddInvite(calendarEvent, invite, trans);
        }

        if (calendarAddEvent.Invites.size() > 1)
            CharacterDatabase.CommitTransaction(trans);
    }

    sCalendarMgr->AddEvent(calendarEvent, CALENDAR_SENDTYPE_ADD);
}

void WorldSession::HandleCalendarUpdateEvent(WorldPackets::Calendar::CalendarUpdateEvent& calendarUpdateEvent)
{
    calendarUpdateEvent.Time -= GetTimezoneOffset();
    calendarUpdateEvent.LockDate -= GetTimezoneOffset();

    // prevent events in the past
    if (calendarUpdateEvent.Time < *GameTime::GetUtcWowTime())
        return;

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_UPDATE_EVENT [{}] EventId [{}], "
        "InviteId [{}] Title {}, Description {}, EventType {} "
        "Dungeon ID {}, Time {} LockDate {}, Flags {}", _player->GetGUID().ToString(), calendarUpdateEvent.EventID, calendarUpdateEvent.ModeratorID,
        calendarUpdateEvent.Title, calendarUpdateEvent.Description, calendarUpdateEvent.EventType, calendarUpdateEvent.TextureID,
        calendarUpdateEvent.Time.GetUnixTimeFromUtcTime(), calendarUpdateEvent.LockDate.GetUnixTimeFromUtcTime(), calendarUpdateEvent.Flags);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarUpdateEvent.EventID))
    {
        time_t oldEventTime = calendarEvent->GetDate();

        calendarEvent->SetType(CalendarEventType(calendarUpdateEvent.EventType));
        calendarEvent->SetFlags(calendarUpdateEvent.Flags);
        calendarEvent->SetDate(calendarUpdateEvent.Time.GetUnixTimeFromUtcTime());
        calendarEvent->SetLockDate(calendarUpdateEvent.LockDate.GetUnixTimeFromUtcTime()); // Not sure, seems constant from the little sniffs we have
        calendarEvent->SetTextureId(calendarUpdateEvent.TextureID);
        calendarEvent->SetTitle(calendarUpdateEvent.Title);
        calendarEvent->SetDescription(calendarUpdateEvent.Description);

        sCalendarMgr->UpdateEvent(calendarEvent);
        sCalendarMgr->SendCalendarEventUpdateAlert(*calendarEvent, oldEventTime);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(_player->GetGUID(), CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarRemoveEvent(WorldPackets::Calendar::CalendarRemoveEvent& calendarRemoveEvent)
{
    ObjectGuid guid = _player->GetGUID();
    sCalendarMgr->RemoveEvent(calendarRemoveEvent.EventID, guid);
}

void WorldSession::HandleCalendarCopyEvent(WorldPackets::Calendar::CalendarCopyEvent& calendarCopyEvent)
{
    ObjectGuid guid = _player->GetGUID();

    calendarCopyEvent.Date -= GetTimezoneOffset();

    // prevent events in the past
    if (calendarCopyEvent.Date < *GameTime::GetUtcWowTime())
    {
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_PASSED);
        return;
    }

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_COPY_EVENT [{}], EventId [{}] inviteId [{}] Time: {}",
        guid.ToString(), calendarCopyEvent.EventID, calendarCopyEvent.ModeratorID, calendarCopyEvent.Date.GetUnixTimeFromUtcTime());

    if (CalendarEvent* oldEvent = sCalendarMgr->GetEvent(calendarCopyEvent.EventID))
    {
        // Ensure that the player has access to the event
        if (oldEvent->IsGuildEvent() || oldEvent->IsGuildAnnouncement())
        {
            if (oldEvent->GetGuildId() != _player->GetGuildId())
            {
                sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
                return;
            }
        }
        else
        {
            if (oldEvent->GetOwnerGUID() != guid)
            {
                sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
                return;
            }
        }

        // Check if the player reached the max number of events allowed to create
        if (oldEvent->IsGuildEvent() || oldEvent->IsGuildAnnouncement())
        {
            if (sCalendarMgr->GetGuildEvents(_player->GetGuildId()).size() >= CALENDAR_MAX_GUILD_EVENTS)
            {
                sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_EVENTS_EXCEEDED);
                return;
            }
        }
        else
        {
            if (sCalendarMgr->GetEventsCreatedBy(guid).size() >= CALENDAR_MAX_EVENTS)
            {
                sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENTS_EXCEEDED);
                return;
            }
        }

        if (GetCalendarEventCreationCooldown() > GameTime::GetGameTime())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_INTERNAL);
            return;
        }
        SetCalendarEventCreationCooldown(GameTime::GetGameTime() + CALENDAR_CREATE_EVENT_COOLDOWN);

        CalendarEvent* newEvent = new CalendarEvent(*oldEvent, sCalendarMgr->GetFreeEventId());
        newEvent->SetDate(calendarCopyEvent.Date.GetUnixTimeFromUtcTime());
        sCalendarMgr->AddEvent(newEvent, CALENDAR_SENDTYPE_COPY);

        CalendarInviteStore invites = sCalendarMgr->GetEventInvites(calendarCopyEvent.EventID);
        CharacterDatabaseTransaction trans;
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

void WorldSession::HandleCalendarEventInvite(WorldPackets::Calendar::CalendarInvite& calendarEventInvite)
{
    ObjectGuid playerGuid = _player->GetGUID();

    Optional<uint64> eventId;
    if (!calendarEventInvite.Creating)
        eventId = calendarEventInvite.EventID;

    bool isSignUp = calendarEventInvite.IsSignUp;

    std::string inviteeName = calendarEventInvite.Name;

    if (!normalizePlayerName(calendarEventInvite.Name))
        return;

    auto createInvite = [this, playerGuid, inviteeName, eventId, isSignUp](ObjectGuid const& inviteeGuid, uint32 inviteeTeam, ObjectGuid::LowType inviteeGuildId, bool inviteeIsIngoring)
    {
        if (!_player || _player->GetGUID() != playerGuid)
            return;

        if (_player->GetTeam() != inviteeTeam && !sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CALENDAR))
        {
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NOT_ALLIED);
            return;
        }

        if (inviteeIsIngoring)
        {
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_IGNORING_YOU_S, inviteeName.c_str());
            return;
        }

        if (eventId)
        {
            if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(*eventId))
            {
                if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() == inviteeGuildId)
                {
                    // we can't invite guild members to guild events
                    sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NO_GUILD_INVITES);
                    return;
                }

                CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), *eventId, inviteeGuid, playerGuid, CALENDAR_DEFAULT_RESPONSE_TIME, CALENDAR_STATUS_INVITED, CALENDAR_RANK_PLAYER, "");
                sCalendarMgr->AddInvite(calendarEvent, invite);
            }
            else
                sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_EVENT_INVALID);
        }
        else
        {
            if (isSignUp && inviteeGuildId == _player->GetGuildId())
            {
                sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NO_GUILD_INVITES);
                return;
            }

            CalendarInvite invite(sCalendarMgr->GetFreeInviteId(), 0L, inviteeGuid, playerGuid, CALENDAR_DEFAULT_RESPONSE_TIME, CALENDAR_STATUS_INVITED, CALENDAR_RANK_PLAYER, "");
            sCalendarMgr->SendCalendarEventInvite(invite);
        }
    };

    if (Player* player = ObjectAccessor::FindConnectedPlayerByName(calendarEventInvite.Name))
    {
        // Invitee is online
        createInvite(player->GetGUID(), player->GetTeam(), player->GetGuildId(), player->GetSocial()->HasIgnore(playerGuid));
    }
    else
    {
        // Invitee offline, get data from storage
        CharacterCacheEntry const* characterInfo = sCharacterCache->GetCharacterCacheByName(inviteeName);
        if (!characterInfo)
        {
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_PLAYER_NOT_FOUND);
            return;
        }

        GetQueryProcessor().AddCallback(CharacterDatabase.AsyncQuery(Trinity::StringFormat("SELECT 1 FROM character_social WHERE guid = {} AND friend = {} AND (flags & {}) <> 0",
            characterInfo->Guid.GetCounter(), playerGuid.GetCounter(), SOCIAL_FLAG_IGNORED).c_str()))
            .WithCallback([inviteeGuid = characterInfo->Guid, inviteeTeam = Player::TeamForRace(characterInfo->Race), inviteeGuildId = characterInfo->GuildId, continuation = std::move(createInvite)](QueryResult result)
        {
            bool isIgnoring = result != nullptr;
            continuation(inviteeGuid, inviteeTeam, inviteeGuildId, isIgnoring);
        });
    }
}

void WorldSession::HandleCalendarEventSignup(WorldPackets::Calendar::CalendarEventSignUp& calendarEventSignUp)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_SIGNUP [{}] EventId [{}] Tentative {}", guid.ToString(), calendarEventSignUp.EventID, calendarEventSignUp.Tentative);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarEventSignUp.EventID))
    {
        if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() != _player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD);
            return;
        }

        CalendarInviteStatus status = calendarEventSignUp.Tentative ? CALENDAR_STATUS_TENTATIVE : CALENDAR_STATUS_SIGNED_UP;
        CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), calendarEventSignUp.EventID, guid, guid, GameTime::GetGameTime(), status, CALENDAR_RANK_PLAYER, "");
        sCalendarMgr->AddInvite(calendarEvent, invite);
        sCalendarMgr->SendCalendarClearPendingAction(guid);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventRsvp(WorldPackets::Calendar::CalendarRSVP& calendarRSVP)
{
    ObjectGuid guid = _player->GetGUID();

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarRSVP.EventID))
    {
        // I think we still should be able to remove self from locked events
        if (calendarRSVP.Status != CALENDAR_STATUS_REMOVED && calendarEvent->IsLocked())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_LOCKED);
            return;
        }

        if (CalendarInvite* invite = sCalendarMgr->GetInvite(calendarRSVP.InviteID))
        {
            invite->SetStatus(CalendarInviteStatus(calendarRSVP.Status));
            invite->SetResponseTime(GameTime::GetGameTime());

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

void WorldSession::HandleCalendarEventRemoveInvite(WorldPackets::Calendar::CalendarRemoveInvite& calendarRemoveInvite)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_REMOVE_INVITE [{}] EventId [{}], ownerInviteId [{}], Invitee ([{}] id: [{}])",
        guid.ToString(), calendarRemoveInvite.EventID, calendarRemoveInvite.ModeratorID, calendarRemoveInvite.Guid.ToString(), calendarRemoveInvite.InviteID);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarRemoveInvite.EventID))
    {
        if (calendarEvent->GetOwnerGUID() == calendarRemoveInvite.Guid)
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_DELETE_CREATOR_FAILED);
            return;
        }

        sCalendarMgr->RemoveInvite(calendarRemoveInvite.InviteID, calendarRemoveInvite.EventID, guid);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE);
}

void WorldSession::HandleCalendarEventStatus(WorldPackets::Calendar::CalendarStatus& calendarStatus)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_STATUS [{}] EventId [{}] ownerInviteId [{}], Invitee ([{}] id: [{}], status {}",
        guid.ToString(), calendarStatus.EventID, calendarStatus.ModeratorID, calendarStatus.Guid.ToString(), calendarStatus.InviteID, calendarStatus.Status);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarStatus.EventID))
    {
        if (CalendarInvite* invite = sCalendarMgr->GetInvite(calendarStatus.InviteID))
        {
            invite->SetStatus((CalendarInviteStatus)calendarStatus.Status);

            sCalendarMgr->UpdateInvite(invite);
            sCalendarMgr->SendCalendarEventStatus(*calendarEvent, *invite);
            sCalendarMgr->SendCalendarClearPendingAction(calendarStatus.Guid);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE); // correct?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventModeratorStatus(WorldPackets::Calendar::CalendarModeratorStatusQuery& calendarModeratorStatus)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_MODERATOR_STATUS [{}] EventID [{}] ModeratorID [{}], Invitee ([{}] InviteID: [{}], Status {}",
        guid.ToString(), calendarModeratorStatus.EventID, calendarModeratorStatus.ModeratorID, calendarModeratorStatus.Guid.ToString(), calendarModeratorStatus.InviteID,
        calendarModeratorStatus.Status);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarModeratorStatus.EventID))
    {
        if (CalendarInvite* invite = sCalendarMgr->GetInvite(calendarModeratorStatus.InviteID))
        {
            invite->SetRank(CalendarModerationRank(calendarModeratorStatus.Status));
            sCalendarMgr->UpdateInvite(invite);
            sCalendarMgr->SendCalendarEventModeratorStatusAlert(*calendarEvent, *invite);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE); // correct?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarComplain(WorldPackets::Calendar::CalendarComplain& calendarComplain)
{
    ObjectGuid guid = _player->GetGUID();
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_COMPLAIN [{}] EventId [{}] guid [{}] InviteId [{}]", guid.ToString(), calendarComplain.EventID,
        calendarComplain.InvitedByGUID.ToString(), calendarComplain.InviteID);

    // what to do with complains?
}

void WorldSession::HandleCalendarGetNumPending(WorldPackets::Calendar::CalendarGetNumPending& /*calendarGetNumPending*/)
{
    ObjectGuid guid = _player->GetGUID();
    uint32 pending = sCalendarMgr->GetPlayerNumPending(guid);

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_NUM_PENDING: [{}] Pending: {}", guid.ToString(), pending);

    SendPacket(WorldPackets::Calendar::CalendarSendNumPending(pending).Write());
}

void WorldSession::HandleSetSavedInstanceExtend(WorldPackets::Calendar::SetSavedInstanceExtend& setSavedInstanceExtend)
{
    TC_LOG_DEBUG("network", "CMSG_SET_SAVED_INSTANCE_EXTEND - MapId: {}, Difficulty: {}, ToggleExtend: {}", setSavedInstanceExtend.MapID, setSavedInstanceExtend.DifficultyID, setSavedInstanceExtend.Extend ? "On" : "Off");

    if (Player* player = GetPlayer())
    {
        InstancePlayerBind* instanceBind = player->GetBoundInstance(setSavedInstanceExtend.MapID, Difficulty(setSavedInstanceExtend.DifficultyID), setSavedInstanceExtend.Extend); // include expired instances if we are toggling extend on
        if (!instanceBind || !instanceBind->save || !instanceBind->perm)
            return;

        BindExtensionState newState;
        if (!setSavedInstanceExtend.Extend || instanceBind->extendState == EXTEND_STATE_EXPIRED)
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

void WorldSession::SendCalendarRaidLockoutAdded(InstanceSave const* save)
{
    WorldPackets::Calendar::CalendarRaidLockoutAdded calendarRaidLockoutAdded;
    calendarRaidLockoutAdded.InstanceID = save->GetInstanceId();
    calendarRaidLockoutAdded.ServerTime = *GameTime::GetWowTime();
    calendarRaidLockoutAdded.MapID = int32(save->GetMapId());
    calendarRaidLockoutAdded.DifficultyID = save->GetDifficulty();
    calendarRaidLockoutAdded.TimeRemaining = int32(save->GetResetTime() - GameTime::GetGameTime());
    SendPacket(calendarRaidLockoutAdded.Write());
}

void WorldSession::SendCalendarRaidLockoutRemoved(InstanceSave const* save)
{
    WorldPackets::Calendar::CalendarRaidLockoutRemoved calendarRaidLockoutRemoved;
    calendarRaidLockoutRemoved.InstanceID = save->GetInstanceId();
    calendarRaidLockoutRemoved.MapID = int32(save->GetMapId());
    calendarRaidLockoutRemoved.DifficultyID = save->GetDifficulty();
    calendarRaidLockoutRemoved.TimeRemaining = int32(save->GetResetTime() - GameTime::GetGameTime());
    SendPacket(calendarRaidLockoutRemoved.Write());
}

void WorldSession::SendCalendarRaidLockoutUpdated(InstanceSave const* save)
{
    if (!save)
        return;

    ObjectGuid guid = _player->GetGUID();
    TC_LOG_DEBUG("network", "SMSG_CALENDAR_RAID_LOCKOUT_UPDATED [{}] Map: {}, Difficulty {}",
        guid.ToString(), save->GetMapId(), static_cast<uint32>(save->GetDifficulty()));

    WorldPackets::Calendar::CalendarRaidLockoutUpdated calendarRaidLockoutUpdated;
    calendarRaidLockoutUpdated.ServerTime = *GameTime::GetWowTime();
    calendarRaidLockoutUpdated.MapID = save->GetMapId();
    calendarRaidLockoutUpdated.DifficultyID = save->GetDifficulty();
    calendarRaidLockoutUpdated.OldTimeRemaining = 0;
    calendarRaidLockoutUpdated.NewTimeRemaining = std::max(save->GetResetTime() - GameTime::GetGameTime(), time_t(SI64LIT(0)));
    SendPacket(calendarRaidLockoutUpdated.Write());
}
