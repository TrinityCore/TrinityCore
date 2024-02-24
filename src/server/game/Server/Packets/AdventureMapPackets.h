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

#ifndef AdventureMapPackets_h__
#define AdventureMapPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace AdventureMap
    {
        class CheckIsAdventureMapPoiValid final : public ClientPacket
        {
        public:
            CheckIsAdventureMapPoiValid(WorldPacket&& packet) : ClientPacket(CMSG_CHECK_IS_ADVENTURE_MAP_POI_VALID, std::move(packet)) { }

            void Read() override;

            uint32 AdventureMapPoiID = 0;
        };

        class PlayerIsAdventureMapPoiValid final : public ServerPacket
        {
        public:
            PlayerIsAdventureMapPoiValid() : ServerPacket(SMSG_PLAYER_IS_ADVENTURE_MAP_POI_VALID) { }

            WorldPacket const* Write() override;

            int32 AdventureMapPoiID = 0;
            bool IsVisible = false;
        };

        class AdventureMapStartQuest final : public ClientPacket
        {
        public:
            AdventureMapStartQuest(WorldPacket&& packet) : ClientPacket(CMSG_ADVENTURE_MAP_START_QUEST, std::move(packet)) { }

            void Read() override;

            int32 QuestID = 0;
        };
    }
}

#endif // AdventureMapPackets_h__
