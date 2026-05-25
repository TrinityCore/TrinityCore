/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef TRINITYCORE_GAME_OBJECT_PACKETS_H
#define TRINITYCORE_GAME_OBJECT_PACKETS_H

#include "ObjectGuid.h"
#include "Packet.h"

namespace WorldPackets
{
    namespace GameObject
    {
        class GameObjUse final : public ClientPacket
        {
        public:
            explicit GameObjUse(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJ_USE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class GameObjReportUse final : public ClientPacket
        {
        public:
            explicit GameObjReportUse(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJ_REPORT_USE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };
    }
}

#endif // TRINITYCORE_GAME_OBJECT_PACKETS_H
