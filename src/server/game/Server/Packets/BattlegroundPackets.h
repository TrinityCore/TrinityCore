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

#ifndef BattlegroundPackets_h__
#define BattlegroundPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Battleground
    {
        class PVPOptionsEnabled final : public ServerPacket
        {
        public:
            PVPOptionsEnabled() : ServerPacket(SMSG_PVP_OPTIONS_ENABLED, 1) { }

            WorldPacket const* Write() override;

            bool RatedArenas = false;
            bool WargameBattlegrounds = false;
            bool RatedBattlegrounds = false;
        };

        struct ClientBracketInfo
        {
            int32 WeeklyPlayed = 0;
            int32 WeeklyWon = 0;
        };

        class RatedBattlefieldInfo final : public ServerPacket
        {
        public:
            RatedBattlefieldInfo() : ServerPacket(SMSG_RATED_BG_STATS, 72) { }

            WorldPacket const* Write() override;

            std::array<ClientBracketInfo, 3> Brackets;
        };

        class BattlefieldRatedInfo final : public ServerPacket
        {
        public:
            BattlefieldRatedInfo() : ServerPacket(SMSG_BATTLEFIELD_RATED_INFO, 29) { }

            WorldPacket const* Write() override;

            int32 Reward = 0;
            int32 PersonalRating = 0;
            int32 RewardWeeklyLimit = 0;
            int32 PurseQuantity = 0;
            int8 Unk = 0; // Same value as in cmsg
        };
    }

}

#endif // BattlegroundPackets_h__
