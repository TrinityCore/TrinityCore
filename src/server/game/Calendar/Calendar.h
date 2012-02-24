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

enum CalendarEventType
{
    CALENDARTYPE_RAID = 0,
    CALENDARTYPE_DUNGEON,
    CALENDARTYPE_PVP,
    CALENDARTYPE_MEETING,
    CALENDARTYPE_OTHER,
};

enum CalendarSendEventType
{
    CALENDARSENDEVENTTYPE_GET = 0,
    CALENDARSENDEVENTTYPE_ADD,
    CALENDARSENDEVENTTYPE_COPY
};

enum CalendarModerationRank
{
    CALENDARMODERATIONRANK_PLAYER = 0,
    CALENDARMODERATIONRANK_MODERATOR,
    CALENDARMODERATIONRANK_OWNER
};

enum CalendarEventStatus
{
    CALENDARSTATUS_INVITED = 0,
    CALENDARSTATUS_ACCEPTED,
    CALENDARSTATUS_DECLINED,
    CALENDARSTATUS_TENTATIVE,
    CALENDARSTATUS_OUT,
    CALENDARSTATUS_STANDBY,
    CALENDARSTATUS_CONFIRMED,
    // CALENDARSTATUS_UNK7
    // CALENDARSTATUS_UNK8
    // CALENDARSTATUS_UNK9
};

enum CalendarFlags
{
    CALENDARFLAG_NONE            = 0x000000,
    CALENDARFLAG_NORMAL          = 0x000001,
    CALENDARFLAG_INVITES_LOCKED  = 0x000010,
    CALENDARFLAG_WITHOUT_INVITES = 0x000040,
    CALENDARFLAG_GUILD_EVENT     = 0x000400
    // CALENDARFLAG_Unk10000     = 0x010000,
    // CALENDARFLAG_Unk400000    = 0x400000
};

struct CalendarEvent
{
    uint64 Id;
    uint64 CreatorGuid;
    std::string Name;
    std::string Description;
    CalendarEventType Type;
    uint8 Unk;
    uint32 DungeonId;
    uint32 UnkTime;
    uint32 Time;
    CalendarFlags Flags;
    uint32 GuildId;
};

struct CalendarInvite
{
    uint64 Id;
    uint64 Event;
    CalendarEventStatus Status;
    CalendarModerationRank Rank;
    uint8 Unk1;
    uint8 Unk2;
    uint8 Unk3;
    std::string Text;
    uint64 CreatorGuid;
    uint32 Time;
    uint64 TargetGuid;
};

typedef UNORDERED_MAP<uint64, CalendarInvite> CalendarInviteMap;
typedef UNORDERED_MAP<uint64, CalendarEvent> CalendarEventMap;

#endif
