/*
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#include "LFGPackets.h"

void WorldPackets::LFG::LFGJoin::Read()
{
    _worldPacket >> Roles;
    for (uint8 i = 0; i < 3; ++i)
        _worldPacket.read_skip<uint32>();

    uint32 commentLength = _worldPacket.ReadBits(9);
    Slots.resize(_worldPacket.ReadBits(24));
    Comment = _worldPacket.ReadString(commentLength);

    for (uint32& slot : Slots)
        _worldPacket >> slot;
}

void WorldPackets::LFG::LFGLeave::Read()
{
    _worldPacket.read_skip<uint32>();
    _worldPacket >> Ticket.Time;
    uint32 type = 0;
    _worldPacket >> type;
    Ticket.Type = RideType(type);
    _worldPacket >> Ticket.Id;

    ObjectGuid& requesterGuid = Ticket.RequesterGuid;
    requesterGuid[4] = _worldPacket.ReadBit();
    requesterGuid[5] = _worldPacket.ReadBit();
    requesterGuid[0] = _worldPacket.ReadBit();
    requesterGuid[6] = _worldPacket.ReadBit();
    requesterGuid[2] = _worldPacket.ReadBit();
    requesterGuid[7] = _worldPacket.ReadBit();
    requesterGuid[1] = _worldPacket.ReadBit();
    requesterGuid[3] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(requesterGuid[7]);
    _worldPacket.ReadByteSeq(requesterGuid[4]);
    _worldPacket.ReadByteSeq(requesterGuid[3]);
    _worldPacket.ReadByteSeq(requesterGuid[2]);
    _worldPacket.ReadByteSeq(requesterGuid[6]);
    _worldPacket.ReadByteSeq(requesterGuid[0]);
    _worldPacket.ReadByteSeq(requesterGuid[1]);
    _worldPacket.ReadByteSeq(requesterGuid[5]);
}

void WorldPackets::LFG::LFGProposalResponse::Read()
{
    _worldPacket >> ProposalID;
    _worldPacket >> Ticket.Time;
    uint32 type = 0;
    _worldPacket >> type;
    Ticket.Type = RideType(type);
    _worldPacket >> Ticket.Id;

    ObjectGuid& requesterGuid = Ticket.RequesterGuid;
    requesterGuid[4] = _worldPacket.ReadBit();
    requesterGuid[5] = _worldPacket.ReadBit();
    requesterGuid[0] = _worldPacket.ReadBit();
    requesterGuid[6] = _worldPacket.ReadBit();
    requesterGuid[2] = _worldPacket.ReadBit();
    requesterGuid[7] = _worldPacket.ReadBit();
    requesterGuid[1] = _worldPacket.ReadBit();
    requesterGuid[3] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(requesterGuid[7]);
    _worldPacket.ReadByteSeq(requesterGuid[4]);
    _worldPacket.ReadByteSeq(requesterGuid[3]);
    _worldPacket.ReadByteSeq(requesterGuid[2]);
    _worldPacket.ReadByteSeq(requesterGuid[6]);
    _worldPacket.ReadByteSeq(requesterGuid[0]);
    _worldPacket.ReadByteSeq(requesterGuid[1]);
    _worldPacket.ReadByteSeq(requesterGuid[5]);

    ObjectGuid instaceId;
    instaceId[7] = _worldPacket.ReadBit();
    Accepted = _worldPacket.ReadBit();
    instaceId[1] = _worldPacket.ReadBit();
    instaceId[3] = _worldPacket.ReadBit();
    instaceId[0] = _worldPacket.ReadBit();
    instaceId[5] = _worldPacket.ReadBit();
    instaceId[4] = _worldPacket.ReadBit();
    instaceId[6] = _worldPacket.ReadBit();
    instaceId[2] = _worldPacket.ReadBit();

    _worldPacket.ReadByteSeq(instaceId[7]);
    _worldPacket.ReadByteSeq(instaceId[1]);
    _worldPacket.ReadByteSeq(instaceId[5]);
    _worldPacket.ReadByteSeq(instaceId[6]);
    _worldPacket.ReadByteSeq(instaceId[3]);
    _worldPacket.ReadByteSeq(instaceId[4]);
    _worldPacket.ReadByteSeq(instaceId[0]);
    _worldPacket.ReadByteSeq(instaceId[2]);
    InstanceID = uint64(instaceId);
}

void WorldPackets::LFG::LFGSetRoles::Read()
{
    _worldPacket >> RolesDesired;
}

void WorldPackets::LFG::LFGSetComment::Read()
{
    uint32 length = _worldPacket.ReadBits(9);
    Comment = _worldPacket.ReadString(length);
}

void WorldPackets::LFG::LFGBootPlayerVote::Read()
{
    _worldPacket >> Vote;
}

void WorldPackets::LFG::LFGTeleport::Read()
{
    _worldPacket >> TeleportOut;
}

void WorldPackets::LFG::LFGGetSystemInfo::Read()
{
    Player = _worldPacket.ReadBit();
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackListSlot const& lfgBlackListSlot)
{
    data << uint32(lfgBlackListSlot.Slot);
    data << uint32(lfgBlackListSlot.Reason);
    data << uint32(lfgBlackListSlot.SubReason1);
    data << uint32(lfgBlackListSlot.SubReason2);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LFGBlackList const& blackList)
{
    if (blackList.PlayerGuid)
        data << *blackList.PlayerGuid;

    data << uint32(blackList.Slot.size());
    for (WorldPackets::LFG::LFGBlackListSlot const& slot : blackList.Slot)
        data << slot;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardItem const& playerQuestRewardItem)
{
    ItemTemplate const* item = sObjectMgr->GetItemTemplate(playerQuestRewardItem.ItemID);
    data << int32(playerQuestRewardItem.ItemID);
    data << int32(item ? item->DisplayInfoID : 0);
    data << int32(playerQuestRewardItem.Quantity);
    data << uint8(0);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& playerQuestRewardCurrency)
{
    data << int32(playerQuestRewardCurrency.CurrencyID);
    data << int32(0);
    data << int32(playerQuestRewardCurrency.Quantity);
    data << uint8(1);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerQuestReward const& playerQuestReward)
{
    data << int32(playerQuestReward.RewardMoney);
    data << int32(playerQuestReward.RewardXP);
    data << uint8(playerQuestReward.Item.size() + playerQuestReward.Currency.size());

    for (WorldPackets::LFG::LfgPlayerQuestRewardCurrency const& currency : playerQuestReward.Currency)
        data << currency;

    for (WorldPackets::LFG::LfgPlayerQuestRewardItem const& item : playerQuestReward.Item)
        data << item;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::LFG::LfgPlayerDungeonInfo const& playerDungeonInfo)
{
    data << uint32(playerDungeonInfo.Slot);
    data << uint8(playerDungeonInfo.FirstReward);
    data << uint32(playerDungeonInfo.CompletionQuantity);
    data << uint32(playerDungeonInfo.CompletionLimit);
    data << uint32(playerDungeonInfo.CompletionCurrencyID);
    data << uint32(playerDungeonInfo.SpecificQuantity);
    data << uint32(playerDungeonInfo.SpecificLimit);
    data << uint32(playerDungeonInfo.OverallQuantity);
    data << uint32(playerDungeonInfo.OverallLimit);
    data << uint32(playerDungeonInfo.PurseWeeklyQuantity);
    data << uint32(playerDungeonInfo.PurseWeeklyLimit);
    data << uint32(playerDungeonInfo.PurseQuantity);
    data << uint32(playerDungeonInfo.PurseLimit);
    data << uint32(playerDungeonInfo.Quantity);
    data << uint32(playerDungeonInfo.CompletedMask);
    data << uint8(playerDungeonInfo.ShortageEligible);

    // Todo: Shortage System (Call to Arms)
    for (uint8 i = 0; i < 3; i++)
        data << uint32(0);

    data << playerDungeonInfo.Rewards;

    return data;
}

WorldPacket const* WorldPackets::LFG::LFGPlayerInfo::Write()
{
    _worldPacket << uint8(Dungeon.size());
    for (LfgPlayerDungeonInfo const& playerDungeonInfo : Dungeon)
        _worldPacket << playerDungeonInfo;

    _worldPacket << uint32(BlackList.Slot.size());
    for (WorldPackets::LFG::LFGBlackListSlot const& slot : BlackList.Slot)
        _worldPacket << slot;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGPartyInfo::Write()
{
    _worldPacket << uint8(Player.size());
    for (WorldPackets::LFG::LFGBlackList const& player : Player)
        _worldPacket << player;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::LFG::LFGUpdateStatus::Write()
{
    _worldPacket.WriteBit(Ticket.RequesterGuid[1]);
    _worldPacket.WriteBit(IsParty);
    _worldPacket.WriteBits(Slots.size(), 24);
    _worldPacket.WriteBit(Ticket.RequesterGuid[6]);
    _worldPacket.WriteBit(Joined);
    _worldPacket.WriteBits(Comment.length(), 9);
    _worldPacket.WriteBit(Ticket.RequesterGuid[4]);
    _worldPacket.WriteBit(Ticket.RequesterGuid[7]);
    _worldPacket.WriteBit(Ticket.RequesterGuid[2]);
    _worldPacket.WriteBit(LfgJoined);
    _worldPacket.WriteBit(Ticket.RequesterGuid[0]);
    _worldPacket.WriteBit(Ticket.RequesterGuid[3]);
    _worldPacket.WriteBit(Ticket.RequesterGuid[5]);
    _worldPacket.WriteBit(Queued);
    _worldPacket << uint8(Reason);
    _worldPacket.WriteString(Comment);

    _worldPacket << uint32(Ticket.Id);
    _worldPacket << uint32(Ticket.Time);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[6]);

    for (uint8 i = 0; i < 3; ++i)
        _worldPacket << uint8(0); // unk - Always 0

    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[1]);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[2]);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[4]);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[3]);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[5]);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[0]);
    _worldPacket << uint32(Ticket.Type);
    _worldPacket.WriteByteSeq(Ticket.RequesterGuid[7]);

    for (uint32 slot : Slots)
        _worldPacket << uint32(slot);

    return &_worldPacket;
}
