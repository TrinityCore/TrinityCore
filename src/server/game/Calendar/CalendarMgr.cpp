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

#include "CalendarMgr.h"
#include "CalendarPackets.h"
#include "CharacterCache.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Guild.h"
#include "GuildMgr.h"
#include "Log.h"
#include "Mail.h"
#include "MapUtils.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "StringConvert.h"
#include "WorldSession.h"
#include "WowTime.h"

CalendarInvite::CalendarInvite() : _inviteId(1), _eventId(0), _invitee(), _senderGUID(), _responseTime(0),
_status(CALENDAR_STATUS_INVITED), _rank(CALENDAR_RANK_PLAYER), _note() { }

CalendarInvite::~CalendarInvite()
{
    // Free _inviteId only if it's a real invite and not just a pre-invite or guild announcement
    if (_inviteId != 0 && _eventId != 0)
        sCalendarMgr->FreeInviteId(_inviteId);
}

CalendarEvent::~CalendarEvent()
{
    sCalendarMgr->FreeEventId(_eventId);
}

CalendarMgr::CalendarMgr() : _maxEventId(0), _maxInviteId(0) { }

CalendarMgr::~CalendarMgr()
{
    for (CalendarEventStore::iterator itr = _events.begin(); itr != _events.end(); ++itr)
        delete *itr;

    for (CalendarEventInviteStore::iterator itr = _invites.begin(); itr != _invites.end(); ++itr)
        for (CalendarInviteStore::iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            delete *itr2;
}

CalendarMgr* CalendarMgr::instance()
{
    static CalendarMgr instance;
    return &instance;
}

void CalendarMgr::LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    uint32 count = 0;
    _maxEventId = 0;
    _maxInviteId = 0;

    //                                                       0        1      2      3            4          5          6     7      8
    if (QueryResult result = CharacterDatabase.Query("SELECT EventID, Owner, Title, Description, EventType, TextureID, Date, Flags, LockDate FROM calendar_events"))
        do
        {
            Field* fields = result->Fetch();

            uint64 eventID          = fields[0].GetUInt64();
            ObjectGuid ownerGUID    = ObjectGuid::Create<HighGuid::Player>(fields[1].GetUInt64());
            std::string title       = fields[2].GetString();
            std::string description = fields[3].GetString();
            CalendarEventType type  = CalendarEventType(fields[4].GetUInt8());
            int32 textureID         = fields[5].GetInt32();
            time_t date             = fields[6].GetInt64();
            uint32 flags            = fields[7].GetUInt32();
            time_t lockDate         = fields[8].GetInt64();
            ObjectGuid::LowType guildID = UI64LIT(0);

            if (flags & CALENDAR_FLAG_GUILD_EVENT || flags & CALENDAR_FLAG_WITHOUT_INVITES)
                guildID = sCharacterCache->GetCharacterGuildIdByGuid(ownerGUID);

            CalendarEvent* calendarEvent = new CalendarEvent(eventID, ownerGUID, guildID, type, textureID, date, flags, title, description, lockDate);
            _events.insert(calendarEvent);

            _maxEventId = std::max(_maxEventId, eventID);

            ++count;
        }
        while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} calendar events in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
    count = 0;
    oldMSTime = getMSTime();

    //                                                       0         1        2        3       4       5             6               7
    if (QueryResult result = CharacterDatabase.Query("SELECT InviteID, EventID, Invitee, Sender, Status, ResponseTime, ModerationRank, Note FROM calendar_invites"))
        do
        {
            Field* fields = result->Fetch();

            uint64 inviteId             = fields[0].GetUInt64();
            uint64 eventId              = fields[1].GetUInt64();
            ObjectGuid invitee          = ObjectGuid::Create<HighGuid::Player>(fields[2].GetUInt64());
            ObjectGuid senderGUID       = ObjectGuid::Create<HighGuid::Player>(fields[3].GetUInt64());
            CalendarInviteStatus status = CalendarInviteStatus(fields[4].GetUInt8());
            time_t responseTime         = fields[5].GetInt64();
            CalendarModerationRank rank = CalendarModerationRank(fields[6].GetUInt8());
            std::string note            = fields[7].GetString();

            CalendarInvite* invite = new CalendarInvite(inviteId, eventId, invitee, senderGUID, responseTime, status, rank, note);
            _invites[eventId].push_back(invite);

            _maxInviteId = std::max(_maxInviteId, inviteId);

            ++count;
        }
        while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} calendar invites in {} ms", count, GetMSTimeDiffToNow(oldMSTime));

    for (uint64 i = 1; i < _maxEventId; ++i)
        if (!GetEvent(i))
            _freeEventIds.push_back(i);

    for (uint64 i = 1; i < _maxInviteId; ++i)
        if (!GetInvite(i))
            _freeInviteIds.push_back(i);
}

void CalendarMgr::AddEvent(CalendarEvent* calendarEvent, CalendarSendEventType sendType)
{
    _events.insert(calendarEvent);
    UpdateEvent(calendarEvent);
    SendCalendarEvent(calendarEvent->GetOwnerGUID(), *calendarEvent, sendType);
}

void CalendarMgr::AddInvite(CalendarEvent* calendarEvent, CalendarInvite* invite, CharacterDatabaseTransaction trans)
{
    if (!calendarEvent->IsGuildAnnouncement() && calendarEvent->GetOwnerGUID() != invite->GetInviteeGUID())
        SendCalendarEventInvite(*invite);

    if (!calendarEvent->IsGuildEvent() || invite->GetInviteeGUID() == calendarEvent->GetOwnerGUID())
        SendCalendarEventInviteAlert(*calendarEvent, *invite);

    if (!calendarEvent->IsGuildAnnouncement())
    {
        _invites[invite->GetEventId()].push_back(invite);
        UpdateInvite(invite, trans);
    }
}

void CalendarMgr::RemoveEvent(uint64 eventId, ObjectGuid remover)
{
    CalendarEvent* calendarEvent = GetEvent(eventId);

    if (!calendarEvent)
    {
        SendCalendarCommandResult(remover, CALENDAR_ERROR_EVENT_INVALID);
        return;
    }

    RemoveEvent(calendarEvent, remover);
}

void CalendarMgr::RemoveEvent(CalendarEvent* calendarEvent, ObjectGuid remover)
{
    if (!calendarEvent)
    {
        SendCalendarCommandResult(remover, CALENDAR_ERROR_EVENT_INVALID);
        return;
    }

    SendCalendarEventRemovedAlert(*calendarEvent);

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    CharacterDatabasePreparedStatement* stmt;

    CalendarInviteStore& eventInvites = _invites[calendarEvent->GetEventId()];
    for (size_t i = 0; i < eventInvites.size(); ++i)
    {
        CalendarInvite* invite = eventInvites[i];
        stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CALENDAR_INVITE);
        stmt->setUInt64(0, invite->GetInviteId());
        trans->Append(stmt);

        // guild events only? check invite status here?
        // When an event is deleted, all invited (accepted/declined? - verify) guildies are notified via in-game mail. (wowwiki)
        if (!remover.IsEmpty() && invite->GetInviteeGUID() != remover)
        {
            MailDraft mail(calendarEvent->BuildCalendarMailSubject(remover), calendarEvent->BuildCalendarMailBody(ObjectAccessor::FindConnectedPlayer(invite->GetInviteeGUID())));
            mail.SendMailTo(trans, MailReceiver(invite->GetInviteeGUID().GetCounter()), calendarEvent, MAIL_CHECK_MASK_COPIED);
        }

        delete invite;
    }

    _invites.erase(calendarEvent->GetEventId());

    stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CALENDAR_EVENT);
    stmt->setUInt64(0, calendarEvent->GetEventId());
    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);

    _events.erase(calendarEvent);
    delete calendarEvent;
}

void CalendarMgr::RemoveInvite(uint64 inviteId, uint64 eventId, ObjectGuid /*remover*/)
{
    CalendarEvent* calendarEvent = GetEvent(eventId);

    if (!calendarEvent)
        return;

    CalendarInviteStore::iterator itr = _invites[eventId].begin();
    for (; itr != _invites[eventId].end(); ++itr)
        if ((*itr)->GetInviteId() == inviteId)
            break;

    if (itr == _invites[eventId].end())
        return;

    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CALENDAR_INVITE);
    stmt->setUInt64(0, (*itr)->GetInviteId());
    trans->Append(stmt);
    CharacterDatabase.CommitTransaction(trans);

    if (!calendarEvent->IsGuildEvent())
        SendCalendarEventInviteRemoveAlert((*itr)->GetInviteeGUID(), *calendarEvent, CALENDAR_STATUS_REMOVED);

    SendCalendarEventInviteRemove(*calendarEvent, **itr, calendarEvent->GetFlags());

    // we need to find out how to use CALENDAR_INVITE_REMOVED_MAIL_SUBJECT to force client to display different mail
    //if ((*itr)->GetInviteeGUID() != remover)
    //    MailDraft(calendarEvent->BuildCalendarMailSubject(remover), calendarEvent->BuildCalendarMailBody())
    //        .SendMailTo(trans, MailReceiver((*itr)->GetInvitee()), calendarEvent, MAIL_CHECK_MASK_COPIED);

    delete *itr;
    _invites[eventId].erase(itr);
}

void CalendarMgr::UpdateEvent(CalendarEvent* calendarEvent)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CALENDAR_EVENT);
    stmt->setUInt64(0, calendarEvent->GetEventId());
    stmt->setUInt64(1, calendarEvent->GetOwnerGUID().GetCounter());
    stmt->setString(2, calendarEvent->GetTitle());
    stmt->setString(3, calendarEvent->GetDescription());
    stmt->setUInt8(4, calendarEvent->GetType());
    stmt->setInt32(5, calendarEvent->GetTextureId());
    stmt->setInt64(6, calendarEvent->GetDate());
    stmt->setUInt32(7, calendarEvent->GetFlags());
    stmt->setInt64(8, calendarEvent->GetLockDate());
    CharacterDatabase.Execute(stmt);
}

void CalendarMgr::UpdateInvite(CalendarInvite* invite, CharacterDatabaseTransaction trans)
{
    CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CALENDAR_INVITE);
    stmt->setUInt64(0, invite->GetInviteId());
    stmt->setUInt64(1, invite->GetEventId());
    stmt->setUInt64(2, invite->GetInviteeGUID().GetCounter());
    stmt->setUInt64(3, invite->GetSenderGUID().GetCounter());
    stmt->setUInt8(4, invite->GetStatus());
    stmt->setInt64(5, invite->GetResponseTime());
    stmt->setUInt8(6, invite->GetRank());
    stmt->setString(7, invite->GetNote());
    CharacterDatabase.ExecuteOrAppend(trans, stmt);
}

void CalendarMgr::RemoveAllPlayerEventsAndInvites(ObjectGuid guid)
{
    for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end();)
    {
        CalendarEvent* event = *itr;
        ++itr;
        if (event->GetOwnerGUID() == guid)
            RemoveEvent(event, ObjectGuid::Empty); // don't send mail if removing a character
    }

    CalendarInviteStore playerInvites = GetPlayerInvites(guid);
    for (CalendarInviteStore::const_iterator itr = playerInvites.begin(); itr != playerInvites.end(); ++itr)
        RemoveInvite((*itr)->GetInviteId(), (*itr)->GetEventId(), guid);
}

void CalendarMgr::RemovePlayerGuildEventsAndSignups(ObjectGuid guid, ObjectGuid::LowType guildId)
{
    for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end(); ++itr)
        if ((*itr)->GetOwnerGUID() == guid && ((*itr)->IsGuildEvent() || (*itr)->IsGuildAnnouncement()))
            RemoveEvent((*itr)->GetEventId(), guid);

    CalendarInviteStore playerInvites = GetPlayerInvites(guid);
    for (CalendarInviteStore::const_iterator itr = playerInvites.begin(); itr != playerInvites.end(); ++itr)
        if (CalendarEvent* calendarEvent = GetEvent((*itr)->GetEventId()))
            if (calendarEvent->IsGuildEvent() && calendarEvent->GetGuildId() == guildId)
                RemoveInvite((*itr)->GetInviteId(), (*itr)->GetEventId(), guid);
}

CalendarEvent* CalendarMgr::GetEvent(uint64 eventId) const
{
    for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end(); ++itr)
        if ((*itr)->GetEventId() == eventId)
            return *itr;

    TC_LOG_DEBUG("calendar", "CalendarMgr::GetEvent: [{}] not found!", eventId);
    return nullptr;
}

CalendarInvite* CalendarMgr::GetInvite(uint64 inviteId) const
{
    for (CalendarEventInviteStore::const_iterator itr = _invites.begin(); itr != _invites.end(); ++itr)
        for (CalendarInviteStore::const_iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            if ((*itr2)->GetInviteId() == inviteId)
                return *itr2;

    TC_LOG_DEBUG("calendar", "CalendarMgr::GetInvite: [{}] not found!", inviteId);
    return nullptr;
}

void CalendarMgr::FreeEventId(uint64 id)
{
    if (id == _maxEventId)
        --_maxEventId;
    else
        _freeEventIds.push_back(id);
}

uint64 CalendarMgr::GetFreeEventId()
{
    if (_freeEventIds.empty())
        return ++_maxEventId;

    uint64 eventId = _freeEventIds.front();
    _freeEventIds.pop_front();
    return eventId;
}

void CalendarMgr::FreeInviteId(uint64 id)
{
    if (id == _maxInviteId)
        --_maxInviteId;
    else
        _freeInviteIds.push_back(id);
}

uint64 CalendarMgr::GetFreeInviteId()
{
    if (_freeInviteIds.empty())
        return ++_maxInviteId;

    uint64 inviteId = _freeInviteIds.front();
    _freeInviteIds.pop_front();
    return inviteId;
}

void CalendarMgr::DeleteOldEvents()
{
    time_t oldEventsTime = GameTime::GetGameTime() - CALENDAR_OLD_EVENTS_DELETION_TIME;

    for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end();)
    {
        CalendarEvent* event = *itr;
        ++itr;
        if (event->GetDate() < oldEventsTime)
            RemoveEvent(event, ObjectGuid::Empty);
    }
}

CalendarEventStore CalendarMgr::GetEventsCreatedBy(ObjectGuid guid, bool includeGuildEvents) const
{
    CalendarEventStore result;
    for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end(); ++itr)
        if ((*itr)->GetOwnerGUID() == guid && (includeGuildEvents || (!(*itr)->IsGuildEvent() && !(*itr)->IsGuildAnnouncement())))
            result.insert(*itr);

    return result;
}

CalendarEventStore CalendarMgr::GetGuildEvents(ObjectGuid::LowType guildId) const
{
    CalendarEventStore result;

    if (!guildId)
        return result;

    for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end(); ++itr)
        if ((*itr)->IsGuildEvent() || (*itr)->IsGuildAnnouncement())
            if ((*itr)->GetGuildId() == guildId)
                result.insert(*itr);

    return result;
}

CalendarEventStore CalendarMgr::GetPlayerEvents(ObjectGuid guid) const
{
    CalendarEventStore events;

    for (CalendarEventInviteStore::const_iterator itr = _invites.begin(); itr != _invites.end(); ++itr)
        for (CalendarInviteStore::const_iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            if ((*itr2)->GetInviteeGUID() == guid)
                if (CalendarEvent* event = GetEvent(itr->first)) // NULL check added as attempt to fix #11512
                    events.insert(event);

    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        if (player->GetGuildId())
            for (CalendarEventStore::const_iterator itr = _events.begin(); itr != _events.end(); ++itr)
                if ((*itr)->GetGuildId() == player->GetGuildId())
                    events.insert(*itr);

    return events;
}

CalendarInviteStore CalendarMgr::GetEventInvites(uint64 eventId) const
{
    CalendarInviteStore invites;
    if (CalendarInviteStore const* invitesStore = Trinity::Containers::MapGetValuePtr(_invites, eventId))
        invites = *invitesStore;

    return invites;
}

CalendarInviteStore CalendarMgr::GetPlayerInvites(ObjectGuid guid) const
{
    CalendarInviteStore invites;

    for (CalendarEventInviteStore::const_iterator itr = _invites.begin(); itr != _invites.end(); ++itr)
        for (CalendarInviteStore::const_iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); ++itr2)
            if ((*itr2)->GetInviteeGUID() == guid)
                invites.push_back(*itr2);

    return invites;
}

uint32 CalendarMgr::GetPlayerNumPending(ObjectGuid guid)
{
    CalendarInviteStore const& invites = GetPlayerInvites(guid);

    uint32 pendingNum = 0;
    for (CalendarInviteStore::const_iterator itr = invites.begin(); itr != invites.end(); ++itr)
    {
        switch ((*itr)->GetStatus())
        {
            case CALENDAR_STATUS_INVITED:
            case CALENDAR_STATUS_TENTATIVE:
            case CALENDAR_STATUS_NOT_SIGNED_UP:
                ++pendingNum;
                break;
            default:
                break;
        }
    }

    return pendingNum;
}

std::string CalendarEvent::BuildCalendarMailSubject(ObjectGuid remover) const
{
    return Trinity::StringFormat("{}:{}", remover.ToString(), _title);
}

std::string CalendarEvent::BuildCalendarMailBody(Player const* invitee) const
{
    WowTime time;
    time.SetUtcTimeFromUnixTime(_date);
    if (invitee)
        time += invitee->GetSession()->GetTimezoneOffset();

    return Trinity::ToString(time.GetPackedTime());
}

void CalendarMgr::SendCalendarEventInvite(CalendarInvite const& invite) const
{
    CalendarEvent* calendarEvent = GetEvent(invite.GetEventId());

    ObjectGuid invitee = invite.GetInviteeGUID();
    Player* player = ObjectAccessor::FindConnectedPlayer(invitee);

    uint8 level = player ? player->GetLevel() : sCharacterCache->GetCharacterLevelByGuid(invitee);

    auto packetBuilder = [&](Player const* receiver)
    {
        WorldPackets::Calendar::CalendarInviteAdded packet;
        packet.EventID = calendarEvent ? calendarEvent->GetEventId() : 0;
        packet.InviteGuid = invitee;
        packet.InviteID = calendarEvent ? invite.GetInviteId() : 0;
        packet.Level = level;
        packet.ResponseTime.SetUtcTimeFromUnixTime(invite.GetResponseTime());
        packet.ResponseTime += receiver->GetSession()->GetTimezoneOffset();
        packet.Status = invite.GetStatus();
        packet.Type = calendarEvent ? calendarEvent->IsGuildEvent() : 0; // Correct ?
        packet.ClearPending = calendarEvent ? !calendarEvent->IsGuildEvent() : true; // Correct ?

        receiver->SendDirectMessage(packet.Write());
    };

    if (!calendarEvent) // Pre-invite
    {
        if (Player* playerSender = ObjectAccessor::FindConnectedPlayer(invite.GetSenderGUID()))
            packetBuilder(playerSender);
    }
    else
    {
        if (calendarEvent->GetOwnerGUID() != invite.GetInviteeGUID()) // correct?
            for (Player* receiver : GetAllEventRelatives(*calendarEvent))
                packetBuilder(receiver);
    }
}

void CalendarMgr::SendCalendarEventUpdateAlert(CalendarEvent const& calendarEvent, time_t originalDate) const
{
    auto packetBuilder = [&](Player const* receiver)
    {
        WorldPackets::Calendar::CalendarEventUpdatedAlert packet;
        packet.ClearPending = calendarEvent.GetOwnerGUID() == receiver->GetGUID();
        packet.Date.SetUtcTimeFromUnixTime(calendarEvent.GetDate());
        packet.Date += receiver->GetSession()->GetTimezoneOffset();
        packet.Description = calendarEvent.GetDescription();
        packet.EventClubID = calendarEvent.GetGuildId();
        packet.EventID = calendarEvent.GetEventId();
        packet.EventName = calendarEvent.GetTitle();
        packet.EventType = calendarEvent.GetType();
        packet.Flags = calendarEvent.GetFlags();
        packet.LockDate.SetUtcTimeFromUnixTime(calendarEvent.GetLockDate()); // Always 0 ?
        if (calendarEvent.GetLockDate())
            packet.LockDate += receiver->GetSession()->GetTimezoneOffset();
        packet.OriginalDate.SetUtcTimeFromUnixTime(originalDate);
        packet.OriginalDate += receiver->GetSession()->GetTimezoneOffset();
        packet.TextureID = calendarEvent.GetTextureId();

        receiver->SendDirectMessage(packet.Write());
    };

    for (Player* receiver : GetAllEventRelatives(calendarEvent))
        packetBuilder(receiver);
}

void CalendarMgr::SendCalendarEventStatus(CalendarEvent const& calendarEvent, CalendarInvite const& invite) const
{
    auto packetBuilder = [&](Player const* receiver)
    {
        WorldPackets::Calendar::CalendarInviteStatus packet;
        packet.ClearPending = invite.GetInviteeGUID() == receiver->GetGUID();
        packet.Date.SetUtcTimeFromUnixTime(calendarEvent.GetDate());
        packet.Date += receiver->GetSession()->GetTimezoneOffset();
        packet.EventID = calendarEvent.GetEventId();
        packet.Flags = calendarEvent.GetFlags();
        packet.InviteGuid = invite.GetInviteeGUID();
        packet.ResponseTime.SetUtcTimeFromUnixTime(invite.GetResponseTime());
        packet.ResponseTime += receiver->GetSession()->GetTimezoneOffset();
        packet.Status = invite.GetStatus();

        receiver->SendDirectMessage(packet.Write());
    };

    for (Player* receiver : GetAllEventRelatives(calendarEvent))
        packetBuilder(receiver);
}

void CalendarMgr::SendCalendarEventRemovedAlert(CalendarEvent const& calendarEvent) const
{
    auto packetBuilder = [&](Player const* receiver)
    {
        WorldPackets::Calendar::CalendarEventRemovedAlert packet;
        packet.ClearPending = calendarEvent.GetOwnerGUID() == receiver->GetGUID();
        packet.Date.SetUtcTimeFromUnixTime(calendarEvent.GetDate());
        packet.Date += receiver->GetSession()->GetTimezoneOffset();
        packet.EventID = calendarEvent.GetEventId();

        receiver->SendDirectMessage(packet.Write());
    };

    for (Player* receiver : GetAllEventRelatives(calendarEvent))
        packetBuilder(receiver);
}

void CalendarMgr::SendCalendarEventInviteRemove(CalendarEvent const& calendarEvent, CalendarInvite const& invite, uint32 flags) const
{
    WorldPackets::Calendar::CalendarInviteRemoved packet;
    packet.ClearPending = true; // FIXME
    packet.EventID = calendarEvent.GetEventId();
    packet.Flags = flags;
    packet.InviteGuid = invite.GetInviteeGUID();

    SendPacketToAllEventRelatives(packet.Write(), calendarEvent);
}

void CalendarMgr::SendCalendarEventModeratorStatusAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite) const
{
    WorldPackets::Calendar::CalendarModeratorStatus packet;
    packet.ClearPending = true; // FIXME
    packet.EventID = calendarEvent.GetEventId();
    packet.InviteGuid = invite.GetInviteeGUID();
    packet.Status = invite.GetStatus();

    SendPacketToAllEventRelatives(packet.Write(), calendarEvent);
}

void CalendarMgr::SendCalendarEventInviteAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite) const
{
    auto packetBuilder = [&](Player const* receiver)
    {
        WorldPackets::Calendar::CalendarInviteAlert packet;
        packet.Date.SetUtcTimeFromUnixTime(calendarEvent.GetDate());
        packet.Date += receiver->GetSession()->GetTimezoneOffset();
        packet.EventID = calendarEvent.GetEventId();
        packet.EventName = calendarEvent.GetTitle();
        packet.EventType = calendarEvent.GetType();
        packet.Flags = calendarEvent.GetFlags();
        packet.InviteID = invite.GetInviteId();
        packet.InvitedByGuid = invite.GetSenderGUID();
        packet.ModeratorStatus = invite.GetRank();
        packet.OwnerGuid = calendarEvent.GetOwnerGUID();
        packet.Status = invite.GetStatus();
        packet.TextureID = calendarEvent.GetTextureId();
        packet.EventClubID = calendarEvent.GetGuildId();

        receiver->SendDirectMessage(packet.Write());
    };

    if (calendarEvent.IsGuildEvent() || calendarEvent.IsGuildAnnouncement())
    {
        if (Guild* guild = sGuildMgr->GetGuildById(calendarEvent.GetGuildId()))
            guild->BroadcastWorker(packetBuilder);
    }
    else if (Player* player = ObjectAccessor::FindConnectedPlayer(invite.GetInviteeGUID()))
        packetBuilder(player);
}

void CalendarMgr::SendCalendarEvent(ObjectGuid guid, CalendarEvent const& calendarEvent, CalendarSendEventType sendType) const
{
    Player* player = ObjectAccessor::FindConnectedPlayer(guid);
    if (!player)
        return;

    WorldPackets::Calendar::CalendarSendEvent packet;
    packet.Date.SetUtcTimeFromUnixTime(calendarEvent.GetDate());
    packet.Date += player->GetSession()->GetTimezoneOffset();
    packet.Description = calendarEvent.GetDescription();
    packet.EventID = calendarEvent.GetEventId();
    packet.EventName = calendarEvent.GetTitle();
    packet.EventType = sendType;
    packet.Flags = calendarEvent.GetFlags();
    packet.GetEventType = calendarEvent.GetType();
    packet.LockDate.SetUtcTimeFromUnixTime(calendarEvent.GetLockDate()); // Always 0 ?
    if (calendarEvent.GetLockDate())
        packet.LockDate += player->GetSession()->GetTimezoneOffset();
    packet.OwnerGuid = calendarEvent.GetOwnerGUID();
    packet.TextureID = calendarEvent.GetTextureId();
    packet.EventClubID = calendarEvent.GetGuildId();

    if (CalendarInviteStore const* eventInviteeList = Trinity::Containers::MapGetValuePtr(_invites, calendarEvent.GetEventId()))
    {
        for (CalendarInvite const* calendarInvite : *eventInviteeList)
        {
            ObjectGuid inviteeGuid = calendarInvite->GetInviteeGUID();
            Player* invitee = ObjectAccessor::FindPlayer(inviteeGuid);

            uint8 inviteeLevel = invitee ? invitee->GetLevel() : sCharacterCache->GetCharacterLevelByGuid(inviteeGuid);
            ObjectGuid::LowType inviteeGuildId = invitee ? invitee->GetGuildId() : sCharacterCache->GetCharacterGuildIdByGuid(inviteeGuid);

            WorldPackets::Calendar::CalendarEventInviteInfo inviteInfo;
            inviteInfo.Guid = inviteeGuid;
            inviteInfo.Level = inviteeLevel;
            inviteInfo.Status = calendarInvite->GetStatus();
            inviteInfo.Moderator = calendarInvite->GetRank();
            inviteInfo.InviteType = calendarEvent.IsGuildEvent() && calendarEvent.GetGuildId() == inviteeGuildId;
            inviteInfo.InviteID = calendarInvite->GetInviteId();
            inviteInfo.ResponseTime.SetUtcTimeFromUnixTime(calendarInvite->GetResponseTime());
            inviteInfo.ResponseTime += player->GetSession()->GetTimezoneOffset();
            inviteInfo.Notes = calendarInvite->GetNote();

            packet.Invites.push_back(inviteInfo);
        }
    }

    player->SendDirectMessage(packet.Write());
}

void CalendarMgr::SendCalendarEventInviteRemoveAlert(ObjectGuid guid, CalendarEvent const& calendarEvent, CalendarInviteStatus status) const
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
    {
        WorldPackets::Calendar::CalendarInviteRemovedAlert packet;
        packet.Date.SetUtcTimeFromUnixTime(calendarEvent.GetDate());
        packet.Date += player->GetSession()->GetTimezoneOffset();
        packet.EventID = calendarEvent.GetEventId();
        packet.Flags = calendarEvent.GetFlags();
        packet.Status = status;

        player->SendDirectMessage(packet.Write());
    }
}

void CalendarMgr::SendCalendarClearPendingAction(ObjectGuid guid) const
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
        player->SendDirectMessage(WorldPackets::Calendar::CalendarClearPendingAction().Write());
}

void CalendarMgr::SendCalendarCommandResult(ObjectGuid guid, CalendarError err, char const* param /*= nullptr*/) const
{
    if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
    {
        WorldPackets::Calendar::CalendarCommandResult packet;
        packet.Command = 1; // FIXME
        packet.Result = err;

        switch (err)
        {
            case CALENDAR_ERROR_OTHER_INVITES_EXCEEDED:
            case CALENDAR_ERROR_ALREADY_INVITED_TO_EVENT_S:
            case CALENDAR_ERROR_IGNORING_YOU_S:
                packet.Name = param;
                break;
            default:
                break;
        }

        player->SendDirectMessage(packet.Write());
    }
}

void CalendarMgr::SendPacketToAllEventRelatives(WorldPacket const* packet, CalendarEvent const& calendarEvent) const
{
    for (Player* player : GetAllEventRelatives(calendarEvent))
        player->SendDirectMessage(packet);
}

std::vector<Player*> CalendarMgr::GetAllEventRelatives(CalendarEvent const& calendarEvent) const
{
    std::vector<Player*> relatedPlayers;

    // Send packet to all guild members
    if (calendarEvent.IsGuildEvent() || calendarEvent.IsGuildAnnouncement())
    {
        if (Guild* guild = sGuildMgr->GetGuildById(calendarEvent.GetGuildId()))
        {
            auto memberCollector = [&](Player* player) { relatedPlayers.push_back(player); };
            guild->BroadcastWorker(memberCollector);
        }
    }

    // Send packet to all invitees if event is non-guild, in other case only to non-guild invitees (packet was broadcasted for them)
    if (auto itr =_invites.find(calendarEvent.GetEventId()); itr != _invites.end())
    {
        CalendarInviteStore invites = itr->second;
        for (CalendarInvite const* invite : invites)
            if (Player* player = ObjectAccessor::FindConnectedPlayer(invite->GetInviteeGUID()))
                if (!calendarEvent.IsGuildEvent() || player->GetGuildId() != calendarEvent.GetGuildId())
                    relatedPlayers.push_back(player);
    }

    return relatedPlayers;
}
