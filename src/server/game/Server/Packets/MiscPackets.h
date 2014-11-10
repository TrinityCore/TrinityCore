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

#ifndef MiscPackets_h__
#define MiscPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Misc
    {
        class ViolenceLevel final : public ClientPacket
        {
        public:
            ViolenceLevel(WorldPacket&& packet) : ClientPacket(CMSG_VIOLENCE_LEVEL, std::move(packet)) { }

            void Read() override;

            int8 ViolenceLevel = -1; ///< 0 - no combat effects, 1 - display some combat effects, 2 - blood, 3 - bloody, 4 - bloodier, 5 - bloodiest
        };
    }
}

#endif // MiscPackets_h__
