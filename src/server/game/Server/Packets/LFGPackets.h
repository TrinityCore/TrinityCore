/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef LFGPackets_h__
#define LFGPackets_h__

#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace LFG
    {
        struct RideTicket
        {
            ObjectGuid RequesterGuid;
            int32 Id = 0;
            int32 Type = 0;
            time_t Time = 0;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);

#endif // LFGPackets_h__
