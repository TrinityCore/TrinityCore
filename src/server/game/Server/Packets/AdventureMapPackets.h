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

#ifndef TRINITYCORE_ADVENTURE_MAP_PACKETS_H
#define TRINITYCORE_ADVENTURE_MAP_PACKETS_H

#include "Packet.h"

namespace WorldPackets
{
    namespace AdventureMap
    {
        class CheckIsAdventureMapPoiValid final : public ClientPacket
        {
        public:
            explicit CheckIsAdventureMapPoiValid(WorldPacket&& packet) : ClientPacket(CMSG_CHECK_IS_ADVENTURE_MAP_POI_VALID, std::move(packet)) { }

            void Read() override;

            uint32 AdventureMapPoiID = 0;
        };

        class PlayerIsAdventureMapPoiValid final : public ServerPacket
        {
        public:
            explicit PlayerIsAdventureMapPoiValid() : ServerPacket(SMSG_PLAYER_IS_ADVENTURE_MAP_POI_VALID) { }

            WorldPacket const* Write() override;

            int32 AdventureMapPoiID = 0;
            bool IsVisible = false;
        };

        class AdventureMapStartQuest final : public ClientPacket
        {
        public:
            explicit AdventureMapStartQuest(WorldPacket&& packet) : ClientPacket(CMSG_ADVENTURE_MAP_START_QUEST, std::move(packet)) { }

            void Read() override;

            int32 QuestID = 0;
        };
    }
}

#endif // TRINITYCORE_ADVENTURE_MAP_PACKETS_H
