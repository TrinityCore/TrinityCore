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

#include "LFGPacketsCommon.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::LFG::RideTicket& ticket)
{
    data >> ticket.RequesterGuid;
    data >> ticket.Id;
    ticket.Type = data.read<WorldPackets::LFG::RideType>();
    data >> ticket.Time;
    ticket.Unknown925 = data.ReadBit();
    data.ResetBitPos();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::RideTicket const& ticket)
{
    data << ticket.RequesterGuid;
    data << uint32(ticket.Id);
    data << uint32(ticket.Type);
    data << ticket.Time;
    data.WriteBit(ticket.Unknown925);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& playerQuestRewardItem)
{
    data << int32(playerQuestRewardItem.ItemID);
    data << int32(playerQuestRewardItem.Quantity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& playerQuestRewardCurrency)
{
    data << int32(playerQuestRewardCurrency.CurrencyID);
    data << int32(playerQuestRewardCurrency.Quantity);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestReward)
{
    data << uint8(playerQuestReward.Mask);
    data << int32(playerQuestReward.RewardMoney);
    data << int32(playerQuestReward.RewardXP);
    data << uint32(playerQuestReward.Item.size());
    data << uint32(playerQuestReward.Currency.size());
    data << uint32(playerQuestReward.BonusCurrency.size());

    for (WorldPackets::LFG::LfgPlayerQuestRewardItem const& item : playerQuestReward.Item)
        data << item;

    for (WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& currency : playerQuestReward.Currency)
        data << currency;

    for (WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& bonusCurrency : playerQuestReward.BonusCurrency)
        data << bonusCurrency;

    data.WriteBit(playerQuestReward.RewardSpellID.has_value());
    data.WriteBit(playerQuestReward.Unused1.has_value());
    data.WriteBit(playerQuestReward.Unused2.has_value());
    data.WriteBit(playerQuestReward.Honor.has_value());
    data.FlushBits();

    if (playerQuestReward.RewardSpellID)
        data << int32(*playerQuestReward.RewardSpellID);

    if (playerQuestReward.Unused1)
        data << int32(*playerQuestReward.Unused1);

    if (playerQuestReward.Unused2)
        data << uint64(*playerQuestReward.Unused2);

    if (playerQuestReward.Honor)
        data << int32(*playerQuestReward.Honor);

    return data;
}
