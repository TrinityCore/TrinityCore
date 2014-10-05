/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef AchievementPackets_h__
#define AchievementPackets_h__

#include "BattlenetPacketsBase.h"

namespace Battlenet
{
    namespace Achievement
    {
        enum Opcode
        {
            CMSG_LISTEN_REQUEST             = 0x0,  // Not implemented
            CMSG_CRITERIA_FLUSH_REQUEST     = 0x3,  // Not implemented
            CMSG_CHANGE_TROPHY_CASE_REQUEST = 0x5,  // Not implemented

            SMSG_DATA                       = 0x2,  // Not implemented
            SMSG_CRITERIA_FLUSH_RESPONSE    = 0x3,  // Not implemented
            SMSG_ACHIEVEMENT_HANDLE_UPDATE  = 0x4,  // Not implemented
            SMSG_CHANGE_TROPHY_CASE_RESULE  = 0x6   // Not implemented
        };
    }
}

#endif // AchievementPackets_h__

