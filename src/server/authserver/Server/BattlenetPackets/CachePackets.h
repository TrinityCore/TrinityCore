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

#ifndef CachePackets_h__
#define CachePackets_h__

#include "BattlenetPacketsBase.h"

namespace Battlenet
{
    namespace Cache
    {
        enum Opcode
        {
            CMSG_GATEWAY_LOOKUP_REQUEST     = 0x2,  // Not implemented
            CMSG_CONNECT_REQUEST            = 0x4,  // Not implemented
            CMSG_DATA_CHUNK                 = 0x7,  // Not implemented
            SMSG_GET_STREAM_ITEMS_REQUEST   = 0x9,  // Not implemented

            SMSG_GATEWAY_LOOKUP_RESPONSE    = 0x3,  // Not implemented
            SMSG_CONNECT_RESPONSE           = 0x4,  // Not implemented
            SMSG_PUBLISH_LIST_RESPONSE      = 0x7,  // Not implemented
            SMSG_RESULT                     = 0x8,  // Not implemented
            SMSG_GET_STREAM_ITEMS_RESPONSE  = 0x9   // Not implemented
        };
    }
}

#endif // CachePackets_h__
