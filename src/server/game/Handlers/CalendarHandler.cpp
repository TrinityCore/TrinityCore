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

SMSG_CALENDAR_EVENT_INVITE_NOTES        [ ObjectGuid(InviteGuid), bool(ClearPending), std::string(Notes), uint64(EventID) ]
?CMSG_CALENDAR_EVENT_INVITE_NOTES       [ ObjectGuid(Guid), uint64(EventID), uint64(InviteID), uint64(ModeratorID), std::string(Notes) ]
SMSG_CALENDAR_EVENT_INVITE_NOTES_ALERT  [ uint64(EventID), std::string(Notes) ]
SMSG_CALENDAR_EVENT_INVITE_STATUS_ALERT [ uint64(EventID), uint32(Date), uint32(Flags), uint8(Status) ]
SMSG_CALENDAR_RAID_LOCKOUT_UPDATED      SendCalendarRaidLockoutUpdated(InstanceLock const* save)

@todo

Finish complains' handling - what to do with received complains and how to respond?
Find out what to do with all "not used yet" opcodes
Correct errors sending (event/invite not found, invites exceeded, event already passed, permissions etc.)
Fix locked events to be displayed properly and response time shouldn't be shown for people that haven't respond yet
Copied events should probably have a new owner

*/

#include "WorldSession.h"
#include "CalendarMgr.h"
#include "CalendarPackets.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "InstanceLockMgr.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SocialMgr.h"
#include "World.h"

void WorldSession::HandleCalendarGetCalendar(WorldPackets::Calendar::CalendarGetCalendar& /*calendarGetCalendar*/)
{
    ObjectGuid guid = _player->GetGUID();

    WorldPackets::Calendar::CalendarSendCalendar packet;
    packet.ServerTime = *GameTime::GetWowTime();

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
        eventInfo.EventClubID = event->GetGuildId();
        eventInfo.EventName = event->GetTitle();
        eventInfo.EventType = event->GetType();
        eventInfo.Flags = event->GetFlags();
        eventInfo.OwnerGuid = event->GetOwnerGUID();
        eventInfo.TextureID = event->GetTextureId();
    }

    for (InstanceLock const* lock : sInstanceLockMgr.GetInstanceLocksForPlayer(_player->GetGUID()))
    {
        WorldPackets::Calendar::CalendarSendCalendarRaidLockoutInfo& lockoutInfo = packet.RaidLockouts.emplace_back();
        lockoutInfo.MapID = lock->GetMapId();
        lockoutInfo.DifficultyID = lock->GetDifficultyId();
        lockoutInfo.ExpireTime = int32(std::max(std::chrono::duration_cast<Seconds>(lock->GetEffectiveExpiryTime() - GameTime::GetSystemTime()).count(), SI64LIT(0)));
        lockoutInfo.InstanceID = lock->GetInstanceId();
    }

    SendPacket(packet.Write());
}

void WorldSession::HandleCalendarGetEvent(WorldPackets::Calendar::CalendarGetEvent& calendarGetEvent)
{
    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarGetEvent.EventID))
        sCalendarMgr->SendCalendarEvent(_player->GetGUID(), *calendarEvent, CALENDAR_SENDTYPE_GET);
    else
        sCalendarMgr->SendCalendarCommandResult(_player->GetGUID(), CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarCommunityInvite(WorldPackets::Calendar::CalendarCommunityInviteRequest& calendarCommunityInvite)
{
    if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
        guild->MassInviteToEvent(this, calendarCommunityInvite.MinLevel, calendarCommunityInvite.MaxLevel, GuildRankOrder(calendarCommunityInvite.MaxRankOrder));
}

void WorldSession::HandleCalendarAddEvent(WorldPackets::Calendar::CalendarAddEvent& calendarAddEvent)
{
    ObjectGuid guid = _player->GetGUID();

    calendarAddEvent.EventInfo.Time -= GetTimezoneOffset();

    // prevent events in the past
    if (calendarAddEvent.EventInfo.Time < *GameTime::GetUtcWowTime())
    {
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_PASSED);
        return;
    }

    // If the event is a guild event, check if the player is in a guild
    if (CalendarEvent::IsGuildEvent(calendarAddEvent.EventInfo.Flags) || CalendarEvent::IsGuildAnnouncement(calendarAddEvent.EventInfo.Flags))
    {
        if (!_player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD);
            return;
        }
    }

    // Check if the player reached the max number of events allowed to create
    if (CalendarEvent::IsGuildEvent(calendarAddEvent.EventInfo.Flags) || CalendarEvent::IsGuildAnnouncement(calendarAddEvent.EventInfo.Flags))
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

    CalendarEvent* calendarEvent = new CalendarEvent(sCalendarMgr->GetFreeEventId(), guid, UI64LIT(0), CalendarEventType(calendarAddEvent.EventInfo.EventType), calendarAddEvent.EventInfo.TextureID,
        calendarAddEvent.EventInfo.Time.GetUnixTimeFromUtcTime(), calendarAddEvent.EventInfo.Flags, calendarAddEvent.EventInfo.Title, calendarAddEvent.EventInfo.Description, time_t(0));

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
        if (calendarAddEvent.EventInfo.Invites.size() > 1)
            trans = CharacterDatabase.BeginTransaction();

        for (uint32 i = 0; i < calendarAddEvent.EventInfo.Invites.size(); ++i)
        {
            CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), calendarEvent->GetEventId(), calendarAddEvent.EventInfo.Invites[i].Guid,
                guid, CALENDAR_DEFAULT_RESPONSE_TIME, CalendarInviteStatus(calendarAddEvent.EventInfo.Invites[i].Status),
                CalendarModerationRank(calendarAddEvent.EventInfo.Invites[i].Moderator), "");
            sCalendarMgr->AddInvite(calendarEvent, invite, trans);
        }

        if (calendarAddEvent.EventInfo.Invites.size() > 1)
            CharacterDatabase.CommitTransaction(trans);
    }

    sCalendarMgr->AddEvent(calendarEvent, CALENDAR_SENDTYPE_ADD);
}

void WorldSession::HandleCalendarUpdateEvent(WorldPackets::Calendar::CalendarUpdateEvent& calendarUpdateEvent)
{
    ObjectGuid guid = _player->GetGUID();
    time_t oldEventTime = time_t(0);

    calendarUpdateEvent.EventInfo.Time -= GetTimezoneOffset();

    // prevent events in the past
    if (calendarUpdateEvent.EventInfo.Time < *GameTime::GetUtcWowTime())
        return;

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarUpdateEvent.EventInfo.EventID))
    {
        oldEventTime = calendarEvent->GetDate();

        calendarEvent->SetType(CalendarEventType(calendarUpdateEvent.EventInfo.EventType));
        calendarEvent->SetFlags(calendarUpdateEvent.EventInfo.Flags);
        calendarEvent->SetDate(calendarUpdateEvent.EventInfo.Time.GetUnixTimeFromUtcTime());
        calendarEvent->SetTextureId(calendarUpdateEvent.EventInfo.TextureID);
        calendarEvent->SetTitle(calendarUpdateEvent.EventInfo.Title);
        calendarEvent->SetDescription(calendarUpdateEvent.EventInfo.Description);

        sCalendarMgr->UpdateEvent(calendarEvent);
        sCalendarMgr->SendCalendarEventUpdateAlert(*calendarEvent, oldEventTime);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
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
        // Should we change owner when somebody makes a copy of event owned by another person?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarInvite(WorldPackets::Calendar::CalendarInvite& calendarEventInvite)
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
        createInvite(player->GetGUID(), player->GetTeam(), player->GetGuildId(), player->GetSocial()->HasIgnore(playerGuid, GetAccountGUID()));
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

        GetQueryProcessor().AddCallback(CharacterDatabase.AsyncQuery(Trinity::StringFormat("SELECT 1 FROM character_social cs INNER JOIN characters friend_character ON cs.friend = friend_character.guid WHERE cs.guid = {} AND friend_character.account = {} AND (cs.flags & {}) <> 0",
            characterInfo->Guid.GetCounter(), characterInfo->AccountId, SOCIAL_FLAG_IGNORED).c_str()))
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

void WorldSession::HandleCalendarRsvp(WorldPackets::Calendar::CalendarRSVP& calendarRSVP)
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

void WorldSession::HandleCalendarStatus(WorldPackets::Calendar::CalendarStatus& calendarStatus)
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

void WorldSession::HandleCalendarModeratorStatus(WorldPackets::Calendar::CalendarModeratorStatusQuery& calendarModeratorStatus)
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

    // cannot modify locks currently in use
    if (_player->GetMapId() == uint32(setSavedInstanceExtend.MapID))
        return;

    std::pair<InstanceResetTimePoint, InstanceResetTimePoint> expiryTimes = sInstanceLockMgr.UpdateInstanceLockExtensionForPlayer(_player->GetGUID(),
        { uint32(setSavedInstanceExtend.MapID), Difficulty(setSavedInstanceExtend.DifficultyID) }, setSavedInstanceExtend.Extend);

    if (expiryTimes.first == InstanceResetTimePoint::min())
        return;

    WorldPackets::Calendar::CalendarRaidLockoutUpdated calendarRaidLockoutUpdated;
    calendarRaidLockoutUpdated.ServerTime = *GameTime::GetWowTime();
    calendarRaidLockoutUpdated.MapID = setSavedInstanceExtend.MapID;
    calendarRaidLockoutUpdated.DifficultyID = setSavedInstanceExtend.DifficultyID;
    calendarRaidLockoutUpdated.OldTimeRemaining = std::max(std::chrono::duration_cast<Seconds>(expiryTimes.first - GameTime::GetSystemTime()).count(), SI64LIT(0));
    calendarRaidLockoutUpdated.NewTimeRemaining = std::max(std::chrono::duration_cast<Seconds>(expiryTimes.second - GameTime::GetSystemTime()).count(), SI64LIT(0));
    SendPacket(calendarRaidLockoutUpdated.Write());
}

// ----------------------------------- SEND ------------------------------------

void WorldSession::SendCalendarRaidLockoutAdded(InstanceLock const* lock)
{
    WorldPackets::Calendar::CalendarRaidLockoutAdded calendarRaidLockoutAdded;
    calendarRaidLockoutAdded.InstanceID = lock->GetInstanceId();
    calendarRaidLockoutAdded.ServerTime = uint32(GameTime::GetGameTime());
    calendarRaidLockoutAdded.MapID = int32(lock->GetMapId());
    calendarRaidLockoutAdded.DifficultyID = lock->GetDifficultyId();
    calendarRaidLockoutAdded.TimeRemaining = int32(std::chrono::duration_cast<Seconds>(lock->GetEffectiveExpiryTime() - GameTime::GetSystemTime()).count());
    SendPacket(calendarRaidLockoutAdded.Write());
}

void WorldSession::SendCalendarRaidLockoutRemoved(InstanceLock const* lock)
{
    WorldPackets::Calendar::CalendarRaidLockoutRemoved calendarRaidLockoutRemoved;
    calendarRaidLockoutRemoved.InstanceID = lock->GetInstanceId();
    calendarRaidLockoutRemoved.MapID = int32(lock->GetMapId());
    calendarRaidLockoutRemoved.DifficultyID = lock->GetDifficultyId();
    SendPacket(calendarRaidLockoutRemoved.Write());
}
