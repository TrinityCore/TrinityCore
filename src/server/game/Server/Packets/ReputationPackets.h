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

#ifndef ReputationPackets_h__
#define ReputationPackets_h__

#include "Packet.h"
#include <array>

namespace WorldPackets
{
    namespace Reputation
    {
        static uint16 const FactionCount = 400;

        class InitializeFactions final : public ServerPacket
        {
        public:
            InitializeFactions() : ServerPacket(SMSG_INITIALIZE_FACTIONS, FactionCount * (4 + 1) + FactionCount / 8)
            {
                FactionStandings.fill(0);
                FactionHasBonus.fill(false);
                FactionFlags.fill(0);
            }

            WorldPacket const* Write() override;

            std::array<int32, FactionCount> FactionStandings;
            std::array<bool, FactionCount> FactionHasBonus; ///< @todo: implement faction bonus
            std::array<uint8, FactionCount> FactionFlags; ///< @see enum FactionFlags
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

        struct FactionStandingData
        {
            FactionStandingData() { }
            FactionStandingData(int32 index, int32 standing) : Index(index), Standing(standing) { }

            int32 Index = 0;
            int32 Standing = 0;
        };

        class SetFactionStanding final : public ServerPacket
        {
        public:
            SetFactionStanding() : ServerPacket(SMSG_SET_FACTION_STANDING) { }

            WorldPacket const* Write() override;

            float ReferAFriendBonus = 0.0f;
            float BonusFromAchievementSystem = 0.0f;
            std::vector<FactionStandingData> Faction;
            bool ShowVisual = false;
        };
    }
}

#endif // ReputationPackets_h__
