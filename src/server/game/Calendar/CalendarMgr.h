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
    CALENDAR_RANK_PLAYER            = 0,
    CALENDAR_RANK_MODERATOR         = 1,
    CALENDAR_RANK_OWNER             = 2
};

enum CalendarSendEventType
{
    CALENDAR_SENDTYPE_GET           = 0,
    CALENDAR_SENDTYPE_ADD           = 1,
    CALENDAR_SENDTYPE_COPY          = 2
};

enum CalendarEventType
{
    CALENDAR_TYPE_RAID              = 0,
    CALENDAR_TYPE_DUNGEON           = 1,
    CALENDAR_TYPE_PVP               = 2,
    CALENDAR_TYPE_MEETING           = 3,
    CALENDAR_TYPE_OTHER             = 4,
    CALENDAR_TYPE_HEROIC            = 5
};

enum CalendarRepeatType
{
    CALENDAR_REPEAT_NEVER           = 0,
    CALENDAR_REPEAT_WEEKLY          = 1,
    CALENDAR_REPEAT_BIWEEKLY        = 2,
    CALENDAR_REPEAT_MONTHLY         = 3
};

enum CalendarInviteStatus
{
    CALENDAR_STATUS_INVITED         = 0,
    CALENDAR_STATUS_ACCEPTED        = 1,
    CALENDAR_STATUS_DECLINED        = 2,
    CALENDAR_STATUS_CONFIRMED       = 3,
    CALENDAR_STATUS_OUT             = 4,
    CALENDAR_STATUS_STANDBY         = 5,
    CALENDAR_STATUS_SIGNED_UP       = 6,
    CALENDAR_STATUS_NOT_SIGNED_UP   = 7,
    CALENDAR_STATUS_TENTATIVE       = 8,
    CALENDAR_STATUS_REMOVED         = 9     // correct name?
};

enum CalendarError
{
    CALENDAR_OK                                 = 0,
    CALENDAR_ERROR_GUILD_EVENTS_EXCEEDED        = 1,
    CALENDAR_ERROR_EVENTS_EXCEEDED              = 2,
    CALENDAR_ERROR_SELF_INVITES_EXCEEDED        = 3,
    CALENDAR_ERROR_OTHER_INVITES_EXCEEDED       = 4,
    CALENDAR_ERROR_PERMISSIONS                  = 5,
    CALENDAR_ERROR_EVENT_INVALID                = 6,
    CALENDAR_ERROR_NOT_INVITED                  = 7,
    CALENDAR_ERROR_INTERNAL                     = 8,
    CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD    = 9,
    CALENDAR_ERROR_ALREADY_INVITED_TO_EVENT_S   = 10,
    CALENDAR_ERROR_PLAYER_NOT_FOUND             = 11,
    CALENDAR_ERROR_NOT_ALLIED                   = 12,
    CALENDAR_ERROR_IGNORING_YOU_S               = 13,
    CALENDAR_ERROR_INVITES_EXCEEDED             = 14,
    CALENDAR_ERROR_INVALID_DATE                 = 16,
    CALENDAR_ERROR_INVALID_TIME                 = 17,

    CALENDAR_ERROR_NEEDS_TITLE                  = 19,
    CALENDAR_ERROR_EVENT_PASSED                 = 20,
    CALENDAR_ERROR_EVENT_LOCKED                 = 21,
    CALENDAR_ERROR_DELETE_CREATOR_FAILED        = 22,
    CALENDAR_ERROR_SYSTEM_DISABLED              = 24,
    CALENDAR_ERROR_RESTRICTED_ACCOUNT           = 25,
    CALENDAR_ERROR_ARENA_EVENTS_EXCEEDED        = 26,
    CALENDAR_ERROR_RESTRICTED_LEVEL             = 27,
    CALENDAR_ERROR_USER_SQUELCHED               = 28,
    CALENDAR_ERROR_NO_INVITE                    = 29,

    CALENDAR_ERROR_EVENT_WRONG_SERVER           = 36,
    CALENDAR_ERROR_INVITE_WRONG_SERVER          = 37,
    CALENDAR_ERROR_NO_GUILD_INVITES             = 38,
    CALENDAR_ERROR_INVALID_SIGNUP               = 39,
    CALENDAR_ERROR_NO_MODERATOR                 = 40
};

#define CALENDAR_MAX_EVENTS             30
#define CALENDAR_MAX_GUILD_EVENTS       100
#define CALENDAR_MAX_INVITES            100
#define CALENDAR_DEFAULT_RESPONSE_TIME  946684800 // 01/01/2000 00:00:00

struct TC_GAME_API CalendarInvite
{
    public:
        CalendarInvite(CalendarInvite const& calendarInvite, uint64 inviteId, uint64 eventId)
        {
            _inviteId = inviteId;
            _eventId = eventId;
            _invitee = calendarInvite.GetInviteeGUID();
            _senderGUID = calendarInvite.GetSenderGUID();
            _responseTime = calendarInvite.GetResponseTime();
            _status = calendarInvite.GetStatus();
            _rank = calendarInvite.GetRank();
            _note = calendarInvite.GetNote();
        }

        CalendarInvite() : _inviteId(1), _eventId(0), _invitee(), _senderGUID(), _responseTime(0),
            _status(CALENDAR_STATUS_INVITED), _rank(CALENDAR_RANK_PLAYER), _note("") { }

        CalendarInvite(uint64 inviteId, uint64 eventId, ObjectGuid invitee, ObjectGuid senderGUID, time_t responseTime,
            CalendarInviteStatus status, CalendarModerationRank rank, std::string note) :
            _inviteId(inviteId), _eventId(eventId), _invitee(invitee), _senderGUID(senderGUID), _responseTime(responseTime),
            _status(status), _rank(rank), _note(note) { }

        ~CalendarInvite();

        void SetInviteId(uint64 inviteId) { _inviteId = inviteId; }
        uint64 GetInviteId() const { return _inviteId; }

        void SetEventId(uint64 eventId) { _eventId = eventId; }
        uint64 GetEventId() const { return _eventId; }

        void SetSenderGUID(ObjectGuid guid) { _senderGUID = guid; }
        ObjectGuid GetSenderGUID() const { return _senderGUID; }

        void SetInvitee(ObjectGuid guid) { _invitee = guid; }
        ObjectGuid GetInviteeGUID() const { return _invitee; }

        void SetResponseTime(time_t responseTime) { _responseTime = responseTime; }
        time_t GetResponseTime() const { return _responseTime; }

        void SetNote(std::string const& note) { _note = note; }
        std::string GetNote() const { return _note; }

        void SetStatus(CalendarInviteStatus status) { _status = status; }
        CalendarInviteStatus GetStatus() const { return _status; }

        void SetRank(CalendarModerationRank rank) { _rank = rank; }
        CalendarModerationRank GetRank() const { return _rank; }

    private:
        uint64 _inviteId;
        uint64 _eventId;
        ObjectGuid _invitee;
        ObjectGuid _senderGUID;
        time_t _responseTime;
        CalendarInviteStatus _status;
        CalendarModerationRank _rank;
        std::string _note;
};

struct TC_GAME_API CalendarEvent
{
    public:
        CalendarEvent(CalendarEvent const& calendarEvent, uint64 eventId)
        {
            _eventId = eventId;
            _ownerGUID = calendarEvent.GetOwnerGUID();
            _eventGuildId = calendarEvent.GetGuildId();
            _eventType = calendarEvent.GetType();
            _textureId = calendarEvent.GetTextureId();
            _date = calendarEvent.GetDate();
            _flags = calendarEvent.GetFlags();
            _title = calendarEvent.GetTitle();
            _description = calendarEvent.GetDescription();
            _lockDate = calendarEvent.GetLockDate();
        }

        CalendarEvent(uint64 eventId, ObjectGuid ownerGUID, ObjectGuid::LowType guildId, CalendarEventType type, int32 textureId,
            time_t date, uint32 flags, std::string title, std::string description, time_t lockDate) :
            _eventId(eventId), _ownerGUID(ownerGUID), _eventGuildId(guildId), _eventType(type), _textureId(textureId),
            _date(date), _flags(flags), _title(title), _description(description), _lockDate(lockDate) { }

        CalendarEvent() : _eventId(1), _ownerGUID(), _eventGuildId(UI64LIT(0)), _eventType(CALENDAR_TYPE_OTHER), _textureId(-1), _date(0),
            _flags(0), _title(""), _description(""), _lockDate(0) { }

        ~CalendarEvent();

        void SetEventId(uint64 eventId) { _eventId = eventId; }
        uint64 GetEventId() const { return _eventId; }

        void SetOwnerGUID(ObjectGuid guid) { _ownerGUID = guid; }
        ObjectGuid GetOwnerGUID() const { return _ownerGUID; }

        void SetGuildId(ObjectGuid::LowType guildId) { _eventGuildId = guildId; }
        ObjectGuid::LowType GetGuildId() const { return _eventGuildId; }

        void SetTitle(std::string const& title) { _title = title; }
        std::string GetTitle() const { return _title; }

        void SetDescription(std::string const& description) { _description = description; }
        std::string GetDescription() const { return _description; }

        void SetType(CalendarEventType eventType) { _eventType = eventType; }
        CalendarEventType GetType() const { return _eventType; }

        void SetTextureId(int32 textureId) { _textureId = textureId; }
        int32 GetTextureId() const { return _textureId; }

        void SetDate(time_t date) { _date = date; }
        time_t GetDate() const { return _date; }

        void SetFlags(uint32 flags) { _flags = flags; }
        uint32 GetFlags() const { return _flags; }

        bool IsGuildEvent() const { return (_flags & CALENDAR_FLAG_GUILD_EVENT) != 0; }
        bool IsGuildAnnouncement() const { return (_flags & CALENDAR_FLAG_WITHOUT_INVITES) != 0; }
        bool IsLocked() const { return (_flags & CALENDAR_FLAG_INVITES_LOCKED) != 0; }

        void SetLockDate(time_t lockDate) { _lockDate = lockDate; }
        time_t GetLockDate() const { return _lockDate; }

        std::string BuildCalendarMailSubject(ObjectGuid remover) const;
        std::string BuildCalendarMailBody() const;

    private:
        uint64 _eventId;
        ObjectGuid _ownerGUID;
        ObjectGuid::LowType _eventGuildId;
        CalendarEventType _eventType;
        int32 _textureId;
        time_t _date;
        uint32 _flags;
        std::string _title;
        std::string _description;
        time_t _lockDate;
};
typedef std::vector<CalendarInvite*> CalendarInviteStore;
typedef std::set<CalendarEvent*> CalendarEventStore;
typedef std::map<uint64 /* eventID */, CalendarInviteStore > CalendarEventInviteStore;

class TC_GAME_API CalendarMgr
{
    private:
        CalendarMgr();
        ~CalendarMgr();

        CalendarEventStore _events;
        CalendarEventInviteStore _invites;

        std::deque<uint64> _freeEventIds;
        std::deque<uint64> _freeInviteIds;
        uint64 _maxEventId;
        uint64 _maxInviteId;

    public:
        static CalendarMgr* instance();

        void LoadFromDB();

        CalendarEvent* GetEvent(uint64 eventId) const;
        CalendarEventStore const& GetEvents() const { return _events; }
        CalendarEventStore GetPlayerEvents(ObjectGuid guid);

        CalendarInvite* GetInvite(uint64 inviteId) const;
        CalendarEventInviteStore const& GetInvites() const { return _invites; }
        CalendarInviteStore const& GetEventInvites(uint64 eventId);
        CalendarInviteStore GetPlayerInvites(ObjectGuid guid);

        void FreeEventId(uint64 id);
        uint64 GetFreeEventId();
        void FreeInviteId(uint64 id);
        uint64 GetFreeInviteId();

        uint32 GetPlayerNumPending(ObjectGuid guid);

        void AddEvent(CalendarEvent* calendarEvent, CalendarSendEventType sendType);
        void RemoveEvent(uint64 eventId, ObjectGuid remover);
        void UpdateEvent(CalendarEvent* calendarEvent);

        void AddInvite(CalendarEvent* calendarEvent, CalendarInvite* invite);
        void AddInvite(CalendarEvent* calendarEvent, CalendarInvite* invite, CharacterDatabaseTransaction& trans);
        void RemoveInvite(uint64 inviteId, uint64 eventId, ObjectGuid remover);
        void UpdateInvite(CalendarInvite* invite);
        void UpdateInvite(CalendarInvite* invite, CharacterDatabaseTransaction& trans);

        void RemoveAllPlayerEventsAndInvites(ObjectGuid guid);
        void RemovePlayerGuildEventsAndSignups(ObjectGuid guid, ObjectGuid::LowType guildId);

        void SendCalendarEvent(ObjectGuid guid, CalendarEvent const& calendarEvent, CalendarSendEventType sendType);
        void SendCalendarEventInvite(CalendarInvite const& invite);
        void SendCalendarEventInviteAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarEventInviteRemove(CalendarEvent const& calendarEvent, CalendarInvite const& invite, uint32 flags);
        void SendCalendarEventInviteRemoveAlert(ObjectGuid guid, CalendarEvent const& calendarEvent, CalendarInviteStatus status);
        void SendCalendarEventUpdateAlert(CalendarEvent const& calendarEvent, time_t originalDate);
        void SendCalendarEventStatus(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarEventRemovedAlert(CalendarEvent const& calendarEvent);
        void SendCalendarEventModeratorStatusAlert(CalendarEvent const& calendarEvent, CalendarInvite const& invite);
        void SendCalendarClearPendingAction(ObjectGuid guid);
        void SendCalendarCommandResult(ObjectGuid guid, CalendarError err, char const* param = NULL);

        void SendPacketToAllEventRelatives(WorldPacket const* packet, CalendarEvent const& calendarEvent);
};

#define sCalendarMgr CalendarMgr::instance()

#endif
