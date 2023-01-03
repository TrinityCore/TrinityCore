/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "NPCPackets.h"

void WorldPackets::NPC::Hello::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* WorldPackets::NPC::TrainerList::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << uint32(TrainerType);
    _worldPacket << uint32(TrainerID);

    _worldPacket << uint32(Spells.size());
    for (TrainerListSpell const& spell : Spells)
    {
        _worldPacket << uint32(spell.SpellID);
        _worldPacket << uint8(spell.Usable);
        _worldPacket << uint32(spell.MoneyCost);
        _worldPacket << uint8(spell.ReqLevel);
        _worldPacket << uint32(spell.ReqSkillLine);
        _worldPacket << uint32(spell.ReqSkillRank);
        _worldPacket.append(spell.ReqAbility.data(), spell.ReqAbility.size());
        _worldPacket << uint32(spell.ProfessionDialog);
        _worldPacket << uint32(spell.ProfessionButton);
    }

    _worldPacket << Greeting;

    return &_worldPacket;
}

void WorldPackets::NPC::TrainerBuySpell::Read()
{
    _worldPacket >> TrainerGUID;
    _worldPacket >> TrainerID;
    _worldPacket >> SpellID;
}

WorldPacket const* WorldPackets::NPC::TrainerBuyFailed::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << int32(SpellID);
    _worldPacket << int32(TrainerFailedReason);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::TrainerBuySucceeded::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}


ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::NPC::VendorItem const& item)
{
    data << int32(item.MuID);
    data << int32(item.Durability);

    if (item.ExtendedCostID.has_value())
        data << uint32(*item.ExtendedCostID);

    data << uint32(item.ItemID);
    data << uint32(item.Type);
    data << uint32(item.Price);
    data << uint32(item.ItemDisplayInfoID);

    if (item.PlayerConditionFailed.has_value())
        data << int32(*item.PlayerConditionFailed);

    data << int32(item.Quantity);
    data << uint32(item.StackCount);

    return data;
}

WorldPacket const* WorldPackets::NPC::VendorInventory::Write()
{
    _worldPacket.WriteBit(Vendor[1]);
    _worldPacket.WriteBit(Vendor[0]);
    _worldPacket.WriteBits(Items.size(), 21);
    _worldPacket.WriteBit(Vendor[3]);
    _worldPacket.WriteBit(Vendor[6]);
    _worldPacket.WriteBit(Vendor[5]);
    _worldPacket.WriteBit(Vendor[2]);
    _worldPacket.WriteBit(Vendor[7]);

    for (VendorItem const& item : Items)
    {
        _worldPacket.WriteBit(!item.ExtendedCostID.has_value());
        _worldPacket.WriteBit(!item.PlayerConditionFailed.has_value());
    }

    _worldPacket.WriteBit(Vendor[4]);
    _worldPacket.FlushBits();

    for (VendorItem const& item : Items)
        _worldPacket << item;

    _worldPacket.WriteByteSeq(Vendor[5]);
    _worldPacket.WriteByteSeq(Vendor[4]);
    _worldPacket.WriteByteSeq(Vendor[1]);
    _worldPacket.WriteByteSeq(Vendor[0]);
    _worldPacket.WriteByteSeq(Vendor[6]);

    _worldPacket << uint8(Reason);

    _worldPacket.WriteByteSeq(Vendor[2]);
    _worldPacket.WriteByteSeq(Vendor[3]);
    _worldPacket.WriteByteSeq(Vendor[7]);

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::NPC::SGossipOptions const& gossipOption)
{
    data << int32(gossipOption.ClientOption);
    data << uint8(gossipOption.OptionNPC);
    data << int8(gossipOption.OptionFlags);
    data << int32(gossipOption.OptionCost);
    data << gossipOption.Text;
    data << gossipOption.Confirm;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::NPC::GossipText const& gossipText)
{
    data << int32(gossipText.QuestID);
    data << int32(gossipText.QuestType);
    data << int32(gossipText.QuestLevel);
    data << int32(gossipText.QuestFlags);
    data << bool(gossipText.Repeatable);
    data << gossipText.QuestTitle;

    return data;
}

WorldPacket const* WorldPackets::NPC::GossipMessage::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << uint32(GossipID);
    _worldPacket << uint32(TextID);

    _worldPacket << uint32(GossipOptions.size());
    for (WorldPackets::NPC::SGossipOptions const& gossipOption : GossipOptions)
        _worldPacket << gossipOption;

    _worldPacket << uint32(GossipQuestText.size());
    for (WorldPackets::NPC::GossipText const& gossipText : GossipQuestText)
        _worldPacket << gossipText;

    return &_worldPacket;
}
