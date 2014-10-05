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

#ifndef ProfilePackets_h__
#define ProfilePackets_h__

#include "BattlenetPacketsBase.h"

namespace Battlenet
{
    namespace Profile
    {
        enum Opcode
        {
            CMSG_READ_REQUEST                           = 0x0,  // Not implemented
            CMSG_ADDRESS_QUERY_REQUEST                  = 0x1,  // Not implemented
            CMSG_RESOLVE_TOON_HANDLE_TO_NAME_REQUEST    = 0x2,  // Not implemented
            CMSG_RESOLVE_TOON_NAME_TO_HANDLE_REQUEST    = 0x3,  // Not implemented
            CMSG_CHANGE_SETTINGS                        = 0x5,  // Not implemented

            SMSG_READ_RESPONSE                          = 0x0,  // Not implemented
            SMSG_ADDRESS_QUERY_RESPONSE                 = 0x1,  // Not implemented
            SMSG_RESOLVE_TOON_HANDLE_TO_NAME_RESPONSE   = 0x2,  // Not implemented
            SMSG_RESOLVE_TOON_NAME_TO_HANDLE_RESPONSE   = 0x3,  // Not implemented
            SMSG_SETTINGS_AVAILABLE                     = 0x4   // Not implemented
        };
    }
}

#endif // ProfilePackets_h__
