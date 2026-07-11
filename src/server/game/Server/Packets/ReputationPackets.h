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

#ifndef TRINITYCORE_REPUTATION_PACKETS_H
#define TRINITYCORE_REPUTATION_PACKETS_H

#include "Packet.h"

namespace WorldPackets
{
    namespace Reputation
    {
        struct FactionData
        {
            uint8 Flags = 0;
            int32 Standing = 0;
        };

        class InitializeFactions final : public ServerPacket
        {
            static constexpr uint32 FactionCount = 128;

        public:
            explicit InitializeFactions() : ServerPacket(SMSG_INITIALIZE_FACTIONS, 4 + (1 + 4) * FactionCount) { }

            WorldPacket const* Write() override;

            std::array<FactionData, FactionCount> Factions = { };
        };
    }
}

#endif // TRINITYCORE_REPUTATION_PACKETS_H
