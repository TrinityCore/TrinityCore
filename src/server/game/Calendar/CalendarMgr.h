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

#ifndef TRINITY_CALENDARMGR_H
#define TRINITY_CALENDARMGR_H

#include "Common.h"
#include "DatabaseEnvFwd.h"
#include "ObjectGuid.h"
#include <deque>
#include <map>
#include <set>
#include <vector>

class WorldPacket;

enum CalendarMailAnswers
{
    // else
    CALENDAR_EVENT_REMOVED_MAIL_SUBJECT     = 0,
    // if ( *(_DWORD *)(a1 + 8292) & 0x100 )
    CALENDAR_INVITE_REMOVED_MAIL_SUBJECT    = 0x100
};

enum CalendarFlags
{
    CALENDAR_FLAG_ALL_ALLOWED       = 0x001,
    CALENDAR_FLAG_INVITES_LOCKED    = 0x010,
    CALENDAR_FLAG_WITHOUT_INVITES   = 0x040,
    CALENDAR_FLAG_GUILD_EVENT       = 0x400
};

enum CalendarModerationRank
{
    CALENDAR_RANK_PLAYER,
    CALENDAR_RANK_MODERATOR,
    CALENDAR_RANK_OWNER 
};

enum CalendarSendEventType
{
    CALENDAR_SENDTYPE_GET,
    CALENDAR_SENDTYPE_ADD,
    CALENDAR_SENDTYPE_COPY  
};

enum CalendarEventType
{
    CALENDAR_TYPE_RAID,
    CALENDAR_TYPE_DUNGEON,
    CALENDAR_TYPE_PVP,
    CALENDAR_TYPE_MEETING,
    CALENDAR_TYPE_OTHER 
};

enum CalendarRepeatType
{
    CALENDAR_REPEAT_NEVER,
    CALENDAR_REPEAT_WEEKLY,
    CALENDAR_REPEAT_BIWEEKLY,
    CALENDAR_REPEAT_MONTHLY
};

enum CalendarInviteStatus
{
    CALENDAR_STATUS_INVITED,
    CALENDAR_STATUS_ACCEPTED,
    CALENDAR_STATUS_DECLINED,
    CALENDAR_STATUS_CONFIRMED,
    CALENDAR_STATUS_OUT,
    CALENDAR_STATUS_STANDBY,
    CALENDAR_STATUS_SIGNED_UP,
    CALENDAR_STATUS_NOT_SIGNED_UP,
    CALENDAR_STATUS_TENTATIVE,
    CALENDAR_STATUS_REMOVED  
};

enum CalendarError
{
    CALENDAR_OK,
    CALENDAR_ERROR_GUILD_EVENTS_EXCEEDED,
    CALENDAR_ERROR_EVENTS_EXCEEDED,
    CALENDAR_ERROR_SELF_INVITES_EXCEEDED,
    CALENDAR_ERROR_OTHER_INVITES_EXCEEDED,
    CALENDAR_ERROR_PERMISSIONS,
    CALENDAR_ERROR_EVENT_INVALID,
    CALENDAR_ERROR_NOT_INVITED,
    CALENDAR_ERROR_INTERNAL,
    CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD,
    CALENDAR_ERROR_ALREADY_INVITED_TO_EVENT_S,
    CALENDAR_ERROR_PLAYER_NOT_FOUND,
    CALENDAR_ERROR_NOT_ALLIED,
    CALENDAR_ERROR_IGNORING_YOU_S,
    CALENDAR_ERROR_INVITES_EXCEEDED,
    CALENDAR_ERROR_INVALID_DATE,
    CALENDAR_ERROR_INVALID_TIME,

    CALENDAR_ERROR_NEEDS_TITLE,
    CALENDAR_ERROR_EVENT_PASSED,
    CALENDAR_ERROR_EVENT_LOCKED,
    CALENDAR_ERROR_DELETE_CREATOR_FAILED,
    CALENDAR_ERROR_SYSTEM_DISABLED,
    CALENDAR_ERROR_RESTRICTED_ACCOUNT,
    CALENDAR_ERROR_ARENA_EVENTS_EXCEEDED,
    CALENDAR_ERROR_RESTRICTED_LEVEL,
    CALENDAR_ERROR_USER_SQUELCHED,
    CALENDAR_ERROR_NO_INVITE,

    CALENDAR_ERROR_EVENT_WRONG_SERVER,
    CALENDAR_ERROR_INVITE_WRONG_SERVER,
    CALENDAR_ERROR_NO_GUILD_INVITES,
    CALENDAR_ERROR_INVALID_SIGNUP,
    CALENDAR_ERROR_NO_MODERATOR  
};

enum CalendarLimits
{
    CALENDAR_MAX_EVENTS = 30,
    CALENDAR_MAX_GUILD_EVENTS = 100,
    CALENDAR_MAX_INVITES = 100,
    CALENDAR_CREATE_EVENT_COOLDOWN = 5,
    CALENDAR_OLD_EVENTS_DELETION_TIME = 1 * MONTH,
};

struct TC_GAME_API CalendarInvite
{
    public:
        CalendarInvite(CalendarInvite const& calendarInvite, uint64 inviteId, uint64 eventId)
        {
            _inviteId = inviteId;
            _eventId = eventId;
            _invitee = calendarInvite.GetInviteeGUID();
            _senderGUID = calendarInvite.GetSenderGUID();
            _statusTime = calendarInvite.GetStatusTime();
            _status = calendarInvite.GetStatus();
            _rank = calendarInvite.GetRank();
            _text = calendarInvite.GetText();
        }

        CalendarInvite();

        CalendarInvite(uint64 inviteId, uint64 eventId, ObjectGuid invitee, ObjectGuid senderGUID, time_t statusTime,
            CalendarInviteStatus status, CalendarModerationRank rank, std::string text) :
            _inviteId(inviteId), _eventId(eventId), _invitee(invitee), _senderGUID(senderGUID), _statusTime(statusTime),
            _status(status), _rank(rank), _text(text) { }

        ~CalendarInvite();

        void SetInviteId(uint64 inviteId) { _inviteId = inviteId; }
        uint64 GetInviteId() const { return _inviteId; }

        void SetEventId(uint64 eventId) { _eventId = eventId; }
        uint64 GetEventId() const { return _eventId; }

        void SetSenderGUID(ObjectGuid guid) { _senderGUID = guid; }
        ObjectGuid GetSenderGUID() const { return _senderGUID; }

        void SetInvitee(ObjectGuid guid) { _invitee = guid; }
        ObjectGuid GetInviteeGUID() const { return _invitee; }

        void SetStatusTime(time_t statusTime) { _statusTime = statusTime; }
        time_t GetStatusTime() const { return _statusTime; }

        void SetText(const std::string& text) { _text = text; }
        std::string GetText() const { return _text; }

        void SetStatus(CalendarInviteStatus status) { _status = status; }
        CalendarInviteStatus GetStatus() const { return _status; }

        void SetRank(CalendarModerationRank rank) { _rank = rank; }
        CalendarModerationRank GetRank() const { return _rank; }

    private:
        uint64 _inviteId;
        uint64 _eventId;
        ObjectGuid _invitee;
        ObjectGuid _senderGUID;
        time_t _statusTime;
        CalendarInviteStatus _status;
        CalendarModerationRank _rank;
        std::string _text;
};

struct TC_GAME_API CalendarEvent
{
    public:
        CalendarEvent(CalendarEvent const& calendarEvent, uint64 eventId)
        {
            _eventId = eventId;
            _creatorGUID = calendarEvent.GetCreatorGUID();
            _guildId = calendarEvent.GetGuildId();
            _type = calendarEvent.GetType();
            _dungeonId = calendarEvent.GetDungeonId();
            _eventTime = calendarEvent.GetEventTime();
            _flags = calendarEvent.GetFlags();
            _timezoneTime = calendarEvent.GetTimeZoneTime();
            _title = calendarEvent.GetTitle();
            _description = calendarEvent.GetDescription();
        }

        CalendarEvent(uint64 eventId, ObjectGuid creatorGUID, ObjectGuid::LowType guildId, CalendarEventType type, int32 dungeonId,
            time_t eventTime, uint32 flags, time_t timezoneTime, std::string title, std::string description) :
            _eventId(eventId), _creatorGUID(creatorGUID), _guildId(guildId), _type(type), _dungeonId(dungeonId),
            _eventTime(eventTime), _flags(flags), _timezoneTime(timezoneTime), _title(title),
            _description(description) { }

        CalendarEvent() : _eventId(1), _creatorGUID(), _guildId(0), _type(CALENDAR_TYPE_OTHER), _dungeonId(-1), _eventTime(0),
            _flags(0), _timezoneTime(0), _title(""), _description("") { }

        ~CalendarEvent();

        void SetEventId(uint64 eventId) { _eventId = eventId; }
        uint64 GetEventId() const { return _eventId; }

        void SetCreatorGUID(ObjectGuid guid) { _creatorGUID = guid; }
        ObjectGuid GetCreatorGUID() const { return _creatorGUID; }

        void SetGuildId(ObjectGuid::LowType guildId) { _guildId = guildId; }
        ObjectGuid::LowType GetGuildId() const { return _guildId; }

        void SetTitle(const std::string& title) { _title = title; }
        std::string GetTitle() const { return _title; }

        void SetDescription(const std::string& description) { _description = description; }
        std::string GetDescription() const { return _description; }

        void SetType(CalendarEventType type) { _type = type; }
        CalendarEventType GetType() const { return _type; }

        void SetDungeonId(int32 dungeonId) { _dungeonId = dungeonId; }
        int32 GetDungeonId() const { return _dungeonId; }

        void SetEventTime(time_t eventTime) { _eventTime = eventTime; }
        time_t GetEventTime() const { return _eventTime; }

        void SetFlags(uint32 flags) { _flags = flags; }
        uint32 GetFlags() const { return _flags; }

        void SetTimeZoneTime(time_t timezoneTime) { _timezoneTime = timezoneTime; }
        time_t GetTimeZoneTime() const { return _timezoneTime; }

        bool IsGuildEvent() const { return (_flags & CALENDAR_FLAG_GUILD_EVENT) != 0; }
        bool IsGuildAnnouncement() const { return (_flags & CALENDAR_FLAG_WITHOUT_INVITES) != 0; }

        static bool IsGuildEvent(uint32 flags) { return (flags & CALENDAR_FLAG_GUILD_EVENT) != 0; }
        static bool IsGuildAnnouncement(uint32 flags) { return (flags & CALENDAR_FLAG_WITHOUT_INVITES) != 0; }

        std::string BuildCalendarMailSubject(ObjectGuid remover) const;
        std::string BuildCalendarMailBody() const;

    private:
        uint64 _eventId;
        ObjectGuid _creatorGUID;
        ObjectGuid::LowType _guildId;
        CalendarEventType _type;
        int32 _dungeonId;
        time_t _eventTime;
        uint32 _flags;
        time_t _timezoneTime;
        std::string _title;
        std::string _description;
};
typedef std::vector<CalendarInvite*> CalendarInviteStore;
typedef std::set<CalendarEvent*> CalendarEventStore;
typedef std::map<uint64 /* eventId */, CalendarInviteStore > CalendarEventInviteStore;

class TC_GAME_API CalendarMgr
{
    public:
        static CalendarMgr* instance();

        void LoadFromDB();

        CalendarEvent* GetEvent(uint64 eventId) const;
        CalendarEventStore const& GetEvents() const { return _events; }
        CalendarEventStore GetEventsCreatedBy(ObjectGuid guid, bool includeGuildEvents = false);
        CalendarEventStore GetPlayerEvents(ObjectGuid guid);
        CalendarEventStore GetGuildEvents(ObjectGuid::LowType guildId);

        CalendarInvite* GetInvite(uint64 inviteId) const;
        CalendarEventInviteStore const& GetInvites() const { return _invites; }
        CalendarInviteStore const& GetEventInvites(uint64 eventId);
        CalendarInviteStore GetPlayerInvites(ObjectGuid guid);

        void FreeEventId(uint64 id);
        uint64 GetFreeEventId();
        void FreeInviteId(uint64 id);
        uint64 GetFreeInviteId();

        void DeleteOldEvents();

        uint32 GetPlayerNumPending(ObjectGuid guid);

        void AddEvent(CalendarEvent* calendarEvent, CalendarSendEventType sendType);
        void RemoveEvent(uint64 eventId, ObjectGuid remover);
        void RemoveEvent(CalendarEvent* calendarEvent, ObjectGuid remover);
        void UpdateEvent(CalendarEvent* calendarEvent);

        void AddInvite(CalendarEvent* calendarEvent, CalendarInvite* invite);
        void AddInvite(CalendarEvent* calendarEvent, CalendarInvite* invite, CharacterDatabaseTransaction trans);
        void RemoveInvite(uint64 inviteId, uint64 eventId, ObjectGuid remover);
        void UpdateInvite(CalendarInvite* invite);
        void UpdateInvite(CalendarInvite* invite, CharacterDatabaseTransaction trans);

        void RemoveAllPlayerEventsAndInvites(ObjectGuid guid);
        void RemovePlayerGuildEventsAndSignups(ObjectGuid guid, ObjectGuid::LowType guildId);

        void SendCalendarEvent(ObjectGuid guid, CalendarEvent const& calendarEvent, CalendarSendEventType sendType);
        void SendCalendarEventInvite(CalendarInvite const& invite);
        void SendCalendarEventInviteAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarEventInviteRemove(CalendarEvent const& calendarEvent, CalendarInvite const& invite, uint32 flags);
        void SendCalendarEventInviteRemoveAlert(ObjectGuid guid, CalendarEvent const& calendarEvent, CalendarInviteStatus status);
        void SendCalendarEventUpdateAlert(CalendarEvent const& calendarEvent, time_t oldEventTime);
        void SendCalendarEventStatus(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarEventRemovedAlert(CalendarEvent const& calendarEvent);
        void SendCalendarEventModeratorStatusAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarClearPendingAction(ObjectGuid guid);
        void SendCalendarCommandResult(ObjectGuid guid, CalendarError err, char const* param = nullptr);

        void SendPacketToAllEventRelatives(WorldPacket& packet, CalendarEvent const& calendarEvent);

    private:
        CalendarMgr();
        ~CalendarMgr();

        CalendarEventStore _events;
        CalendarEventInviteStore _invites;

        std::deque<uint64> _freeEventIds;
        std::deque<uint64> _freeInviteIds;
        uint64 _maxEventId;
        uint64 _maxInviteId;
};

#define sCalendarMgr CalendarMgr::instance()

#endif
