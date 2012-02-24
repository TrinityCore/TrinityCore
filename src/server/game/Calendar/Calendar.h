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

#include "Common.h"
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
        CalendarInvite(uint64 _inviteId = 0);
        ~CalendarInvite();

        void SetInviteId(uint64 inviteId);
        uint64 GetInviteId() const;
        void SetEventId(uint64 eventId);
        uint64 GetEventId() const;
        void SetSenderGUID(uint64 guid);
        uint64 GetSenderGUID() const;
        void SetInvitee(uint64 guid);
        uint64 GetInvitee() const;
        void SetStatusTime(uint32 statusTime);
        uint32 GetStatusTime() const;
        void SetText(std::string text);
        std::string GetText() const;
        void SetStatus(uint8 _status);
        uint8 GetStatus() const;
        void SetRank(uint8 _rank);
        uint8 GetRank() const;

        std::string GetDebugString() const;
    private:
        uint64 inviteId;
        uint64 eventId;
        uint64 invitee;
        uint64 senderGUID;
        uint32 statusTime;
        uint8 status;
        uint8 rank;
        std::string text;
};

typedef std::set<uint64> CalendarinviteIdList;

class CalendarEvent
{
    public:
        CalendarEvent(uint64 _eventId = 0);
        ~CalendarEvent();

        void SetEventId(uint64 eventId);
        uint64 GetEventId() const;
        void SetCreatorGUID(uint64 guid);
        uint64 GetCreatorGUID() const;
        void SetGuildId(uint32 guild);
        uint32 GetGuildId() const;
        void SetTitle(std::string title);
        std::string GetTitle() const;
        void SetDescription(std::string description);
        std::string GetDescription() const;
        void SetType(uint8 type);
        uint8 GetType() const;
        void SetMaxInvites(uint32 max);
        uint32 GetMaxInvites() const;
        void SetDungeonId(int32 dungeonId);
        int32 GetDungeonId() const;
        void SetTime(uint32 eventTime);
        uint32 GetTime() const;
        void SetFlags(uint32 flags);
        uint32 GetFlags() const;
        void SetRepeatable(bool repeatable);
        uint8 GetRepeatable() const;
        void SetTimeZoneTime(uint32 time);
        uint32 GetTimeZoneTime() const;

        void AddInvite(uint64 inviteId);
        void RemoveInvite(uint64 inviteId);
        bool HasInvite(uint64 inviteId) const;
        CalendarinviteIdList const& GetInviteIdList() const;
        void SetInviteIdList(CalendarinviteIdList const& list);
        void ClearInviteIdList();

        std::string GetDebugString() const;
    private:
        uint64 eventId;
        uint64 creatorGUID;
        uint32 guildId;
        uint8 type;
        int32 dungeonId;
        uint32 maxInvites;
        uint32 eventTime;
        uint32 flags;
        uint8 repeatable;
        uint32 timezoneTime;
        std::string title;
        std::string description;
        CalendarinviteIdList _invites;
};

typedef std::set<uint64> CalendarEventIdList;
typedef std::map<uint64, CalendarinviteIdList> CalendarPlayerinviteIdMap;
typedef std::map<uint64, CalendarEventIdList> CalendarPlayerEventIdMap;
typedef std::map<uint64, CalendarInvite> CalendarInviteMap;
typedef std::map<uint64, CalendarEvent> CalendarEventMap;

struct CalendarAction
{
    CalendarAction(): _action(CALENDAR_ACTION_NONE), _guid(0), _inviteId(0), _data(0) {};
        std::string GetDebugString() const;

        void SetAction(CalendarActionData data) { _action = data; }
        void SetGUID(uint64 guid) { _guid = guid; }
        void SetInviteId(uint64 id) { _inviteId = id; }
        void SetExtraData(uint32 data) { _data = data; }

        uint64 GetGUID() const { return _guid; }
        CalendarActionData GetAction() const { return _action; }
        uint64 GetInviteId() const { return _inviteId; }
        uint32 GetExtraData() const { return _data; }

        CalendarEvent Event;
        CalendarInvite Invite;
    private:        
        CalendarActionData _action;
        uint64 _guid;
        uint64 _inviteId;
        uint32 _data;
};

#endif
