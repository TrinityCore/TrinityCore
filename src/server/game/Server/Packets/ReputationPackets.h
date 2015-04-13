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

#ifndef ReputationPackets_h__
#define ReputationPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Reputation
    {
        static uint16 const FactionCount = 256;

        class InitializeFactions final : public ServerPacket
        {
        public:
            InitializeFactions() : ServerPacket(SMSG_INITIALIZE_FACTIONS, 1312)
            {
                for (uint16 i = 0; i < FactionCount; ++i)
                {
                    FactionStandings[i] = 0;
                    FactionHasBonus[i] = false;
                    FactionFlags[i] = 0;
                }
            }

            WorldPacket const* Write() override;

            int32 FactionStandings[FactionCount];
            bool FactionHasBonus[FactionCount]; ///< @todo: implement faction bonus
            uint8 FactionFlags[FactionCount]; ///< @see enum FactionFlags
        };

        class RequestForcedReactions final : public ClientPacket
        {
        public:
            RequestForcedReactions(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_FORCED_REACTIONS, std::move(packet)) { }

            void Read() override { }
        };

        struct ForcedReaction
        {
            int32 Faction = 0;
            int32 Reaction = 0;
        };

        class SetForcedReactions final : public ServerPacket
        {
        public:
            SetForcedReactions() : ServerPacket(SMSG_SET_FORCED_REACTIONS) { }

            WorldPacket const* Write() override;

            std::vector<ForcedReaction> Reactions;
        };
    }
}

#endif // ReputationPackets_h__
