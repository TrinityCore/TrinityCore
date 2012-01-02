/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

enum CalendarCommandError
{
    CALENDAR_ERROR_GUILD_EVENTS_EXCEEDED      = 1,
    CALENDAR_ERROR_EVENTS_EXCEEDED            = 2,
    CALENDAR_ERROR_SELF_INVITES_EXCEEDED      = 3,
    CALENDAR_ERROR_OTHER_INVITES_EXCEEDED     = 4,
    CALENDAR_ERROR_PERMISSIONS                = 5,
    CALENDAR_ERROR_EVENT_INVALID              = 6,
    CALENDAR_ERROR_NOT_INVITED                = 7,
    CALENDAR_ERROR_INTERNAL                   = 8,
    CALENDAR_ERROR_GUILD_PLAYER_NOT_IN_GUILD  = 9,
    CALENDAR_ERROR_ALREADY_INVITED_TO_EVENT_S = 10,
    CALENDAR_ERROR_PLAYER_NOT_FOUND           = 11,
    CALENDAR_ERROR_NOT_ALLIED                 = 12,
    CALENDAR_ERROR_IGNORING_YOU_S             = 13,
    CALENDAR_ERROR_INVITES_EXCEEDED           = 14,
    CALENDAR_ERROR_INVALID_DATE               = 16,
    CALENDAR_ERROR_INVALID_TIME               = 17,
    CALENDAR_ERROR_NEEDS_TITLE                = 19,
    CALENDAR_ERROR_EVENT_PASSED               = 20,
    CALENDAR_ERROR_EVENT_LOCKED               = 21,
    CALENDAR_ERROR_DELETE_CREATOR_FAILED      = 22,
    CALENDAR_ERROR_SYSTEM_DISABLED            = 24,
    CALENDAR_ERROR_RESTRICTED_ACCOUNT         = 25,
    CALENDAR_ERROR_ARENA_EVENTS_EXCEEDED      = 26,
    CALENDAR_ERROR_RESTRICTED_LEVEL           = 27,
    CALENDAR_ERROR_USER_SQUELCHED             = 28,
    CALENDAR_ERROR_NO_INVITE                  = 29,
    CALENDAR_ERROR_EVENT_WRONG_SERVER         = 36,
    CALENDAR_ERROR_INVITE_WRONG_SERVER        = 37,
    CALENDAR_ERROR_NO_GUILD_INVITES           = 38,
    CALENDAR_ERROR_INVALID_SIGNUP             = 39,
    CALENDAR_ERROR_NO_MODERATOR               = 40
};

class Calendar
{

};
#endif
