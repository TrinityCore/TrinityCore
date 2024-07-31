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

#ifndef LFGPacketsCommon_h__
#define LFGPacketsCommon_h__

#include "ObjectGuid.h"
#include "PacketUtilities.h"

namespace WorldPackets
{
    namespace LFG
    {
        enum class RideType : uint32
        {
            None = 0,
            Battlegrounds = 1,
            Lfg = 2
        };

        struct RideTicket
        {
            ObjectGuid RequesterGuid;
            uint32 Id = 0;
            RideType Type = RideType::None;
            Timestamp<> Time;
            bool Unknown925 = false;
        };

        struct LfgPlayerQuestRewardItem
        {
            LfgPlayerQuestRewardItem() = default;
            LfgPlayerQuestRewardItem(int32 itemId, int32 quantity) : ItemID(itemId), Quantity(quantity) { }

            int32 ItemID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestRewardCurrency
        {
            LfgPlayerQuestRewardCurrency() = default;
            LfgPlayerQuestRewardCurrency(int32 currencyID, int32 quantity) : CurrencyID(currencyID), Quantity(quantity) { }

            int32 CurrencyID = 0;
            int32 Quantity = 0;
        };

        struct LfgPlayerQuestReward
        {
            uint8 Mask = 0;                                             // Roles required for this reward, only used by ShortageReward in SMSG_LFG_PLAYER_INFO
            int32 RewardMoney = 0;                                      // Only used by SMSG_LFG_PLAYER_INFO
            int32 RewardXP = 0;
            std::vector<LfgPlayerQuestRewardItem> Item;
            std::vector<LfgPlayerQuestRewardCurrency> Currency;         // Only used by SMSG_LFG_PLAYER_INFO
            std::vector<LfgPlayerQuestRewardCurrency> BonusCurrency;    // Only used by SMSG_LFG_PLAYER_INFO
            Optional<int32> RewardSpellID;                              // Only used by SMSG_LFG_PLAYER_INFO
            Optional<int32> Unused1;
            Optional<uint64> Unused2;
            Optional<int32> Honor;                                      // Only used by SMSG_REQUEST_PVP_REWARDS_RESPONSE
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& playerQuestRewardItem);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& playerQuestRewardCurrency);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestReward);

#endif // LFGPacketsCommon_h__
