/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_CALENDAR_H
#define TRINITY_CALENDAR_H

#include "Errors.h"
#include <map>

enum CalendarFlags
{
    CALENDAR_FLAG_ALL_ALLOWED     = 0x001,
    CALENDAR_FLAG_INVITES_LOCKED  = 0x010,
    CALENDAR_FLAG_WITHOUT_INVITES = 0x040,
    CALENDAR_FLAG_GUILD_ONLY      = 0x400,
};

enum CalendarActionData
{
    CALENDAR_ACTION_NONE,
    CALENDAR_ACTION_ADD_EVENT,
    CALENDAR_ACTION_MODIFY_EVENT,
    CALENDAR_ACTION_REMOVE_EVENT,
    CALENDAR_ACTION_COPY_EVENT,
    CALENDAR_ACTION_ADD_EVENT_INVITE,
    CALENDAR_ACTION_MODIFY_EVENT_INVITE,
    CALENDAR_ACTION_MODIFY_MODERATOR_EVENT_INVITE,
    CALENDAR_ACTION_REMOVE_EVENT_INVITE,
    CALENDAR_ACTION_SIGNUP_TO_EVENT,
};

enum CalendarRanks
{
    CALENDAR_RANK_PLAYER,
    CALENDAR_RANK_MODERATOR,
    CALENDAR_RANK_OWNER,
};

enum CalendarSendEventType
{
    CALENDAR_SENDTYPE_GET,
    CALENDAR_SENDTYPE_ADD,
    CALENDAR_SENDTYPE_COPY,
};

enum CalendarEventType
{
    CALENDAR_TYPE_RAID,
    CALENDAR_TYPE_DUNGEON,
    CALENDAR_TYPE_PVP,
    CALENDAR_TYPE_MEETING,
    CALENDAR_TYPE_OTHER,
};

enum CalendarInviteStatus
{
    CALENDAR_STATUS_INVITED,
    CALENDAR_STATUS_ACCEPTED,
    CALENDAR_STATUS_DECLINED,
    CALENDAR_STATUS_TENTATIVE,
    CALENDAR_STATUS_OUT,
    CALENDAR_STATUS_STANDBY,
    CALENDAR_STATUS_CONFIRMED,
    CALENDAR_STATUS_NO_OWNER,
    CALENDAR_STATUS_8,
    CALENDAR_STATUS_9,
};

class CalendarInvite
{
    public:
        CalendarInvite() : _inviteId(0) { Init(); }
        explicit CalendarInvite(uint64 inviteId) : _inviteId(inviteId) { Init(); }

        ~CalendarInvite() { }

        void SetInviteId(uint64 inviteId) { _inviteId = inviteId; }
        uint64 GetInviteId() const { return _inviteId; }

        void SetEventId(uint64 eventId) { _eventId = eventId; }
        uint64 GetEventId() const { return _eventId; }

        void SetSenderGUID(uint64 guid) { _senderGUID = guid; }
        uint64 GetSenderGUID() const { return _senderGUID; }

        void SetInvitee(uint64 guid) { _invitee = guid; }
        uint64 GetInvitee() const { return _invitee; }

        void SetStatusTime(uint32 statusTime) { _statusTime = statusTime; }
        uint32 GetStatusTime() const { return _statusTime; }

        void SetText(std::string text) { _text = text; }
        std::string GetText() const { return _text; }

        void SetStatus(uint8 status) { _status = status; }
        uint8 GetStatus() const { return _status; }

        void SetRank(uint8 rank) { _rank = rank; }
        uint8 GetRank() const { return _rank; }

        std::string GetDebugString() const;

    private:
        void Init();

        uint64 _inviteId;
        uint64 _eventId;
        uint64 _invitee;
        uint64 _senderGUID;
        uint32 _statusTime;
        uint8 _status;
        uint8 _rank;
        std::string _text;
};

typedef std::set<uint64> CalendarinviteIdList;

class CalendarEvent
{
    public:
        CalendarEvent() : _eventId(0) { Init(); }
        explicit CalendarEvent(uint64 eventId) : _eventId(eventId) { Init(); }

        ~CalendarEvent() { }

        void SetEventId(uint64 eventId) { _eventId = eventId; }
        uint64 GetEventId() const { return _eventId; }

        void SetCreatorGUID(uint64 guid) { _creatorGUID = guid; }
        uint64 GetCreatorGUID() const { return _creatorGUID; }

        void SetGuildId(uint32 guildId) { _guildId = guildId; }
        uint32 GetGuildId() const { return _guildId; }

        void SetTitle(std::string title) { _title = title; }
        std::string GetTitle() const { return _title; }

        void SetDescription(std::string description) { _description = description; }
        std::string GetDescription() const { return _description; }

        void SetType(uint8 type) { _type = type; }
        uint8 GetType() const { return _type; }

        void SetMaxInvites(uint32 limit) { _maxInvites = limit; }
        uint32 GetMaxInvites() const { return _maxInvites; }

        void SetDungeonId(int32 dungeonId) { _dungeonId = dungeonId; }
        int32 GetDungeonId() const { return _dungeonId; }

        void SetTime(uint32 eventTime) { _eventTime = eventTime; }
        uint32 GetTime() const { return _eventTime; }

        void SetFlags(uint32 flags) { _flags = flags; }
        uint32 GetFlags() const { return _flags; }

        void SetRepeatable(bool repeatable) { _repeatable = repeatable; }
        uint8 GetRepeatable() const { return _repeatable; }

        void SetTimeZoneTime(uint32 timezoneTime) { _timezoneTime = timezoneTime; }
        uint32 GetTimeZoneTime() const { return _timezoneTime; }

        void AddInvite(uint64 inviteId)
        {
            if (inviteId)
                _invites.insert(inviteId);
        }

        void RemoveInvite(uint64 inviteId) { _invites.erase(inviteId); }
        bool HasInvite(uint64 inviteId) const { return _invites.find(inviteId) != _invites.end(); }
        CalendarinviteIdList const& GetInviteIdList() const { return _invites; }
        void SetInviteIdList(CalendarinviteIdList const& list) { _invites = list; }
        void ClearInviteIdList() { _invites.clear(); }

        std::string GetDebugString() const;

    private:
        void Init();

        uint64 _eventId;
        uint64 _creatorGUID;
        uint32 _guildId;
        uint8 _type;
        int32 _dungeonId;
        uint32 _maxInvites;
        uint32 _eventTime;
        uint32 _flags;
        uint8 _repeatable;
        uint32 _timezoneTime;
        std::string _title;
        std::string _description;
        CalendarinviteIdList _invites;
};

typedef std::set<uint64> CalendarEventIdList;
typedef std::map<uint64, CalendarinviteIdList> CalendarPlayerinviteIdMap;
typedef std::map<uint64, CalendarEventIdList> CalendarPlayerEventIdMap;
typedef std::map<uint64, CalendarInvite> CalendarInviteMap;
typedef std::map<uint64, CalendarEvent> CalendarEventMap;

class Player;

struct CalendarAction
{
        CalendarAction(): _action(CALENDAR_ACTION_NONE), _player(NULL), _guid(0), _inviteId(0), _data(0)
        {
        }

        void SetAction(CalendarActionData data) { _action = data; }
        CalendarActionData GetAction() const { return _action; }

        void SetPlayer(Player* player) { ASSERT(player); _player = player; }
        Player* GetPlayer() const { return _player; }

        void SetInviteId(uint64 id) { _inviteId = id; }
        uint64 GetInviteId() const { return _inviteId; }

        void SetExtraData(uint32 data) { _data = data; }
        uint32 GetExtraData() const { return _data; }

        CalendarEvent Event;
        CalendarInvite Invite;

        std::string GetDebugString() const;

    private:
        CalendarActionData _action;
        Player* _player;
        uint64 _inviteId;
        uint32 _data;
};

#endif
