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

#ifndef PresencePackets_h__
#define PresencePackets_h__

#include "BattlenetPacketsBase.h"

namespace Battlenet
{
    namespace Presence
    {
        enum Opcode
        {
            CMSG_UPDATE_REQUEST         = 0x0,
            CMSG_STATISTIC_SUBSCRIBE    = 0x2,

            SMSG_UPDATE_NOTIFY          = 0x0,
            SMSG_FIELD_SPEC_ANNOUNCE    = 0x1,
            SMSG_STATISTICS_UPDATE      = 0x3
        };
    }
}

#endif // PresencePackets_h__
