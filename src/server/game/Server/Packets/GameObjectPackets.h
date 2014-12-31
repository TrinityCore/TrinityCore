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

#ifndef GOPackets_h__
#define GOPackets_h__

#include "Packet.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace GameObject
    {
        class GameObjectUse final : public ClientPacket
        {
        public:
            GameObjectUse(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJ_USE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class GameObjectReportUse final : public ClientPacket
        {
        public:
            GameObjectReportUse(WorldPacket&& packet) : ClientPacket(CMSG_GAMEOBJ_REPORT_USE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };
    }
}
#endif // GOPackets_h__
