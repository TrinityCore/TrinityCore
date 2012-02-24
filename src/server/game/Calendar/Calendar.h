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

// TODO - Get correct values
enum CalendarEventType
{
    CALENDARTYPE_RAID = 0,
    CALENDARTYPE_DUNGEON,
    CALENDARTYPE_PVP,
    CALENDARTYPE_MEETING,
    CALENDARTYPE_OTHER,
};

// TODO - Get correct values
enum CalendarInviteStatus
{
    CALENDARSTATUS_INVITED = 0,
    CALENDARSTATUS_ACCEPTED,
    CALENDARSTATUS_DECLINED,
    CALENDARSTATUS_TENTATIVE,
    CALENDARSTATUS_OUT,
    CALENDARSTATUS_STANDBY,
    CALENDARSTATUS_CONFIRMED,
};

struct CalendarEvent
{
    uint64 Id;
    uint64 CreatorGuid;
    std::string Name;
    std::string Description;
    uint8 Type;
    uint8 Unk;
    uint32 DungeonId;
    uint32 UnkTime;
    uint32 Time;
    uint32 Flags;
    uint32 GuildId;
};

struct CalendarInvite
{
    uint64 Id;
    uint64 Event;
    uint8 Status;
    uint8 Rank;
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
