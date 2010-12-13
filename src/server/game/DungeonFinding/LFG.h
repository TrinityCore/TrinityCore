/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _LFG_H
#define _LFG_H

#include "Common.h"
#include "SharedDefines.h"

enum LfgRoles
{
    ROLE_NONE   = 0x00,
    ROLE_LEADER = 0x01,
    ROLE_TANK   = 0x02,
    ROLE_HEALER = 0x04,
    ROLE_DAMAGE = 0x08,
};

enum LfgUpdateType
{
    LFG_UPDATETYPE_DEFAULT              = 0,               // Internal Use
    LFG_UPDATETYPE_LEADER               = 1,
    LFG_UPDATETYPE_ROLECHECK_ABORTED    = 4,
    LFG_UPDATETYPE_JOIN_PROPOSAL        = 5,
    LFG_UPDATETYPE_ROLECHECK_FAILED     = 6,
    LFG_UPDATETYPE_REMOVED_FROM_QUEUE   = 7,
    LFG_UPDATETYPE_PROPOSAL_FAILED      = 8,
    LFG_UPDATETYPE_PROPOSAL_DECLINED    = 9,
    LFG_UPDATETYPE_GROUP_FOUND          = 10,
    LFG_UPDATETYPE_ADDED_TO_QUEUE       = 12,
    LFG_UPDATETYPE_PROPOSAL_BEGIN       = 13,
    LFG_UPDATETYPE_CLEAR_LOCK_LIST      = 14,
    LFG_UPDATETYPE_GROUP_MEMBER_OFFLINE = 15,
    LFG_UPDATETYPE_GROUP_DISBAND        = 16,
};

typedef std::set<uint32> LfgDungeonSet;

struct LookingForGroup
{
    LookingForGroup(): roles(0), state(LFG_STATE_NONE), oldState(LFG_STATE_NONE) {}
    uint8 roles;
    LfgState state;
    LfgState oldState;
    LfgDungeonSet applyDungeons;                            // Dungeons the player have applied for
    std::string comment;
};

#endif
