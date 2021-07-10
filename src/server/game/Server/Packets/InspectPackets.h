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

#ifndef InspectPackets_h__
#define InspectPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Inspect
    {
        class InspectHonorStats final : public ServerPacket
        {
        public:
            InspectHonorStats() : ServerPacket(SMSG_INSPECT_HONOR_STATS, 17) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            uint32 LifetimeHK = 0;
            uint16 YesterdayHK = 0;
            uint16 TodayHK = 0;
            uint8 LifetimeMaxRank = 0;
        };

        class RequestHonorStats final : public ClientPacket
        {
        public:
            RequestHonorStats(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_HONOR_STATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetGUID;
        };

        class RequestInspectRatedBgStats final : public ClientPacket
        {
        public:
            RequestInspectRatedBgStats(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_INSPECT_RATED_BG_STATS, std::move(packet)) { }

            void Read() override;

            ObjectGuid TargetGUID;
        };

        class InspectRatedBgStats final : public ServerPacket
        {
        public:
            InspectRatedBgStats() : ServerPacket(SMSG_INSPECT_RATED_BG_STATS, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid PlayerGUID;
            int32 Rating = 0;
            int32 Played = 0;
            int32 Won = 0;
        };
    }
}

#endif
