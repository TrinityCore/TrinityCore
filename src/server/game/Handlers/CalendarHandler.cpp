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
SMSG_CALENDAR_RAID_LOCKOUT_UPDATED      SendCalendarRaidLockoutUpdated(InstanceSave const* save)

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
#include "DB2Stores.h"
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
    time_t currTime = time(NULL);

    WorldPackets::Calendar::CalendarSendCalendar packet;
    packet.ServerTime = currTime;

    CalendarInviteStore playerInvites = sCalendarMgr->GetPlayerInvites(guid);
    for (auto const& invite : playerInvites)
    {
        WorldPackets::Calendar::CalendarSendCalendarInviteInfo inviteInfo;
        inviteInfo.EventID = invite->GetEventId();
        inviteInfo.InviteID = invite->GetInviteId();
        inviteInfo.InviterGuid = invite->GetSenderGUID();
        inviteInfo.Status = invite->GetStatus();
        inviteInfo.Moderator = invite->GetRank();
        if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(invite->GetEventId()))
            inviteInfo.InviteType = calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() == _player->GetGuildId();

        packet.Invites.push_back(inviteInfo);
    }

    CalendarEventStore playerEvents = sCalendarMgr->GetPlayerEvents(guid);
    for (auto const& event : playerEvents)
    {
        WorldPackets::Calendar::CalendarSendCalendarEventInfo eventInfo;
        eventInfo.EventID = event->GetEventId();
        eventInfo.Date = event->GetDate();
        eventInfo.EventClubID = event->GetGuildId();
        eventInfo.EventName = event->GetTitle();
        eventInfo.EventType = event->GetType();
        eventInfo.Flags = event->GetFlags();
        eventInfo.OwnerGuid = event->GetOwnerGUID();
        eventInfo.TextureID = event->GetTextureId();

        packet.Events.push_back(eventInfo);
    }

    for (DifficultyEntry const* difficulty : sDifficultyStore)
    {
        auto boundInstances = _player->GetBoundInstances(Difficulty(difficulty->ID));
        if (boundInstances != _player->m_boundInstances.end())
        {
            for (auto const& boundInstance : boundInstances->second)
            {
                if (boundInstance.second.perm)
                {
                    WorldPackets::Calendar::CalendarSendCalendarRaidLockoutInfo lockoutInfo;

                    InstanceSave const* save = boundInstance.second.save;
                    lockoutInfo.MapID = save->GetMapId();
                    lockoutInfo.DifficultyID = save->GetDifficultyID();
                    lockoutInfo.ExpireTime = save->GetResetTime() - currTime;
                    lockoutInfo.InstanceID = save->GetInstanceId(); // instance save id as unique instance copy id

                    packet.RaidLockouts.push_back(lockoutInfo);
                }
            }
        }
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

void WorldSession::HandleCalendarCommunityFilter(WorldPackets::Calendar::CalendarCommunityFilter& calendarCommunityFilter)
{
    if (Guild* guild = sGuildMgr->GetGuildById(_player->GetGuildId()))
        guild->MassInviteToEvent(this, calendarCommunityFilter.MinLevel, calendarCommunityFilter.MaxLevel, calendarCommunityFilter.MaxRankOrder);
}

void WorldSession::HandleCalendarAddEvent(WorldPackets::Calendar::CalendarAddEvent& calendarAddEvent)
{
    ObjectGuid guid = _player->GetGUID();

    // prevent events in the past
    // To Do: properly handle timezones and remove the "- time_t(86400L)" hack
    if (calendarAddEvent.EventInfo.Time < (time(NULL) - time_t(86400L)))
        return;

    CalendarEvent* calendarEvent = new CalendarEvent(sCalendarMgr->GetFreeEventId(), guid, UI64LIT(0), CalendarEventType(calendarAddEvent.EventInfo.EventType), calendarAddEvent.EventInfo.TextureID,
        calendarAddEvent.EventInfo.Time, calendarAddEvent.EventInfo.Flags, calendarAddEvent.EventInfo.Title, calendarAddEvent.EventInfo.Description, time_t(0));

    if (calendarEvent->IsGuildEvent() || calendarEvent->IsGuildAnnouncement())
        if (Player* creator = ObjectAccessor::FindPlayer(guid))
            calendarEvent->SetGuildId(creator->GetGuildId());

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

    // prevent events in the past
    // To Do: properly handle timezones and remove the "- time_t(86400L)" hack
    if (calendarUpdateEvent.EventInfo.Time < (time(NULL) - time_t(86400L)))
        return;

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarUpdateEvent.EventInfo.EventID))
    {
        oldEventTime = calendarEvent->GetDate();

        calendarEvent->SetType(CalendarEventType(calendarUpdateEvent.EventInfo.EventType));
        calendarEvent->SetFlags(calendarUpdateEvent.EventInfo.Flags);
        calendarEvent->SetDate(calendarUpdateEvent.EventInfo.Time);
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

    // prevent events in the past
    // To Do: properly handle timezones and remove the "- time_t(86400L)" hack
    if (calendarCopyEvent.Date < (time(NULL) - time_t(86400L)))
        return;

    if (CalendarEvent* oldEvent = sCalendarMgr->GetEvent(calendarCopyEvent.EventID))
    {
        CalendarEvent* newEvent = new CalendarEvent(*oldEvent, sCalendarMgr->GetFreeEventId());
        newEvent->SetDate(calendarCopyEvent.Date);
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

void WorldSession::HandleCalendarEventInvite(WorldPackets::Calendar::CalendarEventInvite& calendarEventInvite)
{
    ObjectGuid playerGuid = _player->GetGUID();

    ObjectGuid inviteeGuid;
    uint32 inviteeTeam = 0;
    ObjectGuid::LowType inviteeGuildId = UI64LIT(0);

    if (!normalizePlayerName(calendarEventInvite.Name))
        return;

    if (Player* player = ObjectAccessor::FindConnectedPlayerByName(calendarEventInvite.Name))
    {
        // Invitee is online
        inviteeGuid = player->GetGUID();
        inviteeTeam = player->GetTeam();
        inviteeGuildId = player->GetGuildId();
    }
    else
    {
        // Invitee offline, get data from storage
        ObjectGuid guid = sCharacterCache->GetCharacterGuidByName(calendarEventInvite.Name);
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
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_IGNORING_YOU_S, calendarEventInvite.Name.c_str());
            return;
        }
    }

    if (!calendarEventInvite.Creating)
    {
        if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarEventInvite.EventID))
        {
            if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() == inviteeGuildId)
            {
                // we can't invite guild members to guild events
                sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NO_GUILD_INVITES);
                return;
            }

            CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), calendarEventInvite.EventID, inviteeGuid, playerGuid, CALENDAR_DEFAULT_RESPONSE_TIME, CALENDAR_STATUS_INVITED, CALENDAR_RANK_PLAYER, "");
            sCalendarMgr->AddInvite(calendarEvent, invite);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_EVENT_INVALID);
    }
    else
    {
        if (calendarEventInvite.IsSignUp && inviteeGuildId == _player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(playerGuid, CALENDAR_ERROR_NO_GUILD_INVITES);
            return;
        }

        CalendarInvite invite(sCalendarMgr->GetFreeInviteId(), 0L, inviteeGuid, playerGuid, CALENDAR_DEFAULT_RESPONSE_TIME, CALENDAR_STATUS_INVITED, CALENDAR_RANK_PLAYER, "");
        sCalendarMgr->SendCalendarEventInvite(invite);
    }
}

void WorldSession::HandleCalendarEventSignup(WorldPackets::Calendar::CalendarEventSignUp& calendarEventSignUp)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_SIGNUP [%s] EventId [" UI64FMTD "] Tentative %u", guid.ToString().c_str(), calendarEventSignUp.EventID, calendarEventSignUp.Tentative);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarEventSignUp.EventID))
    {
        if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() != _player->GetGuildId())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD);
            return;
        }

        CalendarInviteStatus status = calendarEventSignUp.Tentative ? CALENDAR_STATUS_TENTATIVE : CALENDAR_STATUS_SIGNED_UP;
        CalendarInvite* invite = new CalendarInvite(sCalendarMgr->GetFreeInviteId(), calendarEventSignUp.EventID, guid, guid, time(NULL), status, CALENDAR_RANK_PLAYER, "");
        sCalendarMgr->AddInvite(calendarEvent, invite);
        sCalendarMgr->SendCalendarClearPendingAction(guid);
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventRsvp(WorldPackets::Calendar::CalendarEventRSVP& calendarEventRSVP)
{
    ObjectGuid guid = _player->GetGUID();

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarEventRSVP.EventID))
    {
        // I think we still should be able to remove self from locked events
        if (calendarEventRSVP.Status != CALENDAR_STATUS_REMOVED && calendarEvent->IsLocked())
        {
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_LOCKED);
            return;
        }

        if (CalendarInvite* invite = sCalendarMgr->GetInvite(calendarEventRSVP.InviteID))
        {
            invite->SetStatus(CalendarInviteStatus(calendarEventRSVP.Status));
            invite->SetResponseTime(time(NULL));

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

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_REMOVE_INVITE [%s] EventId [" UI64FMTD
        "], ownerInviteId [" UI64FMTD "], Invitee ([%s] id: [" UI64FMTD "])",
        guid.ToString().c_str(), calendarRemoveInvite.EventID, calendarRemoveInvite.ModeratorID, calendarRemoveInvite.Guid.ToString().c_str(), calendarRemoveInvite.InviteID);

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

void WorldSession::HandleCalendarEventStatus(WorldPackets::Calendar::CalendarEventStatus& calendarEventStatus)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_STATUS [%s] EventId ["
        UI64FMTD "] ownerInviteId [" UI64FMTD "], Invitee ([%s] id: ["
        UI64FMTD "], status %u", guid.ToString().c_str(), calendarEventStatus.EventID, calendarEventStatus.ModeratorID, calendarEventStatus.Guid.ToString().c_str(), calendarEventStatus.InviteID, calendarEventStatus.Status);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarEventStatus.EventID))
    {
        if (CalendarInvite* invite = sCalendarMgr->GetInvite(calendarEventStatus.InviteID))
        {
            invite->SetStatus((CalendarInviteStatus)calendarEventStatus.Status);

            sCalendarMgr->UpdateInvite(invite);
            sCalendarMgr->SendCalendarEventStatus(*calendarEvent, *invite);
            sCalendarMgr->SendCalendarClearPendingAction(calendarEventStatus.Guid);
        }
        else
            sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_NO_INVITE); // correct?
    }
    else
        sCalendarMgr->SendCalendarCommandResult(guid, CALENDAR_ERROR_EVENT_INVALID);
}

void WorldSession::HandleCalendarEventModeratorStatus(WorldPackets::Calendar::CalendarEventModeratorStatus& calendarEventModeratorStatus)
{
    ObjectGuid guid = _player->GetGUID();

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_EVENT_MODERATOR_STATUS [%s] EventID ["
        UI64FMTD "] ModeratorID [" UI64FMTD "], Invitee ([%s] InviteID: ["
        UI64FMTD "], Status %u", guid.ToString().c_str(), calendarEventModeratorStatus.EventID, calendarEventModeratorStatus.ModeratorID, calendarEventModeratorStatus.Guid.ToString().c_str(), calendarEventModeratorStatus.InviteID, calendarEventModeratorStatus.Status);

    if (CalendarEvent* calendarEvent = sCalendarMgr->GetEvent(calendarEventModeratorStatus.EventID))
    {
        if (CalendarInvite* invite = sCalendarMgr->GetInvite(calendarEventModeratorStatus.InviteID))
        {
            invite->SetRank(CalendarModerationRank(calendarEventModeratorStatus.Status));
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
    TC_LOG_DEBUG("network", "CMSG_CALENDAR_COMPLAIN [%s] EventId ["
        UI64FMTD "] guid [%s] InviteId [" UI64FMTD "]", guid.ToString().c_str(), calendarComplain.EventID,
        calendarComplain.InvitedByGUID.ToString().c_str(), calendarComplain.InviteID);

    // what to do with complains?
}

void WorldSession::HandleCalendarGetNumPending(WorldPackets::Calendar::CalendarGetNumPending& /*calendarGetNumPending*/)
{
    ObjectGuid guid = _player->GetGUID();
    uint32 pending = sCalendarMgr->GetPlayerNumPending(guid);

    TC_LOG_DEBUG("network", "CMSG_CALENDAR_GET_NUM_PENDING: [%s] Pending: %u", guid.ToString().c_str(), pending);

    SendPacket(WorldPackets::Calendar::CalendarSendNumPending(pending).Write());
}

void WorldSession::HandleSetSavedInstanceExtend(WorldPackets::Calendar::SetSavedInstanceExtend& setSavedInstanceExtend)
{
    TC_LOG_DEBUG("network", "CMSG_SET_SAVED_INSTANCE_EXTEND - MapId: %u, Difficulty: %u, ToggleExtend: %s", setSavedInstanceExtend.MapID, setSavedInstanceExtend.DifficultyID, setSavedInstanceExtend.Extend ? "On" : "Off");

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
    InstancePlayerBind* instanceBind = _player->GetBoundInstance(setSavedInstanceExtend.MapID, Difficulty(setSavedInstanceExtend.DifficultyID));
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
    time_t currTime = time(NULL);
    if (add)
    {
        WorldPackets::Calendar::CalendarRaidLockoutAdded calendarRaidLockoutAdded;
        calendarRaidLockoutAdded.InstanceID = save->GetInstanceId();
        calendarRaidLockoutAdded.ServerTime = uint32(currTime);
        calendarRaidLockoutAdded.MapID = int32(save->GetMapId());
        calendarRaidLockoutAdded.DifficultyID = save->GetDifficultyID();
        calendarRaidLockoutAdded.TimeRemaining = uint32(save->GetResetTime() - currTime);
        SendPacket(calendarRaidLockoutAdded.Write());
    }
    else
    {
        WorldPackets::Calendar::CalendarRaidLockoutRemoved calendarRaidLockoutRemoved;
        calendarRaidLockoutRemoved.InstanceID = save->GetInstanceId();
        calendarRaidLockoutRemoved.MapID = int32(save->GetMapId());
        calendarRaidLockoutRemoved.DifficultyID = save->GetDifficultyID();
        SendPacket(calendarRaidLockoutRemoved.Write());
    }
}

void WorldSession::SendCalendarRaidLockoutUpdated(InstanceSave const* save)
{
    if (!save)
        return;

    ObjectGuid guid = _player->GetGUID();
    TC_LOG_DEBUG("network", "SMSG_CALENDAR_RAID_LOCKOUT_UPDATED [%s] Map: %u, Difficulty %u", guid.ToString().c_str(), save->GetMapId(), save->GetDifficultyID());

    time_t currTime = time(NULL);

    WorldPackets::Calendar::CalendarRaidLockoutUpdated packet;
    packet.DifficultyID = save->GetDifficultyID();
    packet.MapID = save->GetMapId();
    packet.NewTimeRemaining = 0; // FIXME
    packet.OldTimeRemaining = save->GetResetTime() - currTime;

    SendPacket(packet.Write());
}
