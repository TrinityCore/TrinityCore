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

#include "NPCPackets.h"

void WorldPackets::NPC::Hello::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* WorldPackets::NPC::GossipMessage::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << int32(GossipID);
    _worldPacket << int32(FriendshipFactionID);
    _worldPacket << int32(TextID);
    _worldPacket << uint32(GossipOptions.size());
    _worldPacket << uint32(GossipText.size());

    for (ClientGossipOptions const& options : GossipOptions)
    {
        _worldPacket << int32(options.ClientOption);
        _worldPacket << uint8(options.OptionNPC);
        _worldPacket << int8(options.OptionFlags);
        _worldPacket << int32(options.OptionCost);
        _worldPacket.WriteBits(options.Text.size(), 12);
        _worldPacket.WriteBits(options.Confirm.size(), 12);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(options.Text);
        _worldPacket.WriteString(options.Confirm);
    }

    for (ClientGossipText const& text : GossipText)
    {
        _worldPacket << int32(text.QuestID);
        _worldPacket << int32(text.QuestType);
        _worldPacket << int32(text.QuestLevel);
        _worldPacket << int32(text.QuestMaxScalingLevel);
        _worldPacket << int32(text.QuestFlags[0]);
        _worldPacket << int32(text.QuestFlags[1]);

        _worldPacket.WriteBit(text.Repeatable);
        _worldPacket.WriteBits(text.QuestTitle.size(), 9);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(text.QuestTitle);
    }

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::NPC::VendorItem const &item)
{
    data << uint32(item.MuID);
    data << int32(item.Type);
    data << int32(item.Quantity);
    data << uint64(item.Price);
    data << int32(item.Durability);
    data << int32(item.StackCount);
    data << int32(item.ExtendedCostID);
    data << int32(item.PlayerConditionFailed);
    data << item.Item;
    data.WriteBit(item.DoNotFilterOnVendor);
    data.WriteBit(item.Refundable);
    data.FlushBits();

    return data;
}

WorldPacket const* WorldPackets::NPC::VendorInventory::Write()
{
    _worldPacket << Vendor;
    _worldPacket << uint8(Reason);
    _worldPacket << uint32(Items.size());
    for (VendorItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::TrainerList::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << uint32(TrainerType);
    _worldPacket << uint32(TrainerID);

    _worldPacket << uint32(Spells.size());
    for (TrainerListSpell const& spell : Spells)
    {
        _worldPacket << int32(spell.SpellID);
        _worldPacket << uint32(spell.MoneyCost);
        _worldPacket << uint32(spell.ReqSkillLine);
        _worldPacket << uint32(spell.ReqSkillRank);
        _worldPacket.append(spell.ReqAbility.data(), spell.ReqAbility.size());
        _worldPacket << uint8(spell.Usable);
        _worldPacket << uint8(spell.ReqLevel);
    }

    _worldPacket.WriteBits(Greeting.length(), 11);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Greeting);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::ShowBank::Write()
{
    _worldPacket << Guid;

    return &_worldPacket;
}

void WorldPackets::NPC::GossipSelectOption::Read()
{
    _worldPacket >> GossipUnit;
    _worldPacket >> GossipID;
    _worldPacket >> GossipIndex;

    uint32 length = _worldPacket.ReadBits(8);
    PromotionCode = _worldPacket.ReadString(length);
}

WorldPacket const* WorldPackets::NPC::PlayerTabardVendorActivate::Write()
{
    _worldPacket << Vendor;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::GossipPOI::Write()
{
    _worldPacket << int32(ID);
    _worldPacket << Pos;
    _worldPacket << int32(Icon);
    _worldPacket << int32(Importance);
    _worldPacket.WriteBits(Flags, 14);
    _worldPacket.WriteBits(Name.length(), 6);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

void WorldPackets::NPC::SpiritHealerActivate::Read()
{
    _worldPacket >> Healer;
}

WorldPacket const* WorldPackets::NPC::SpiritHealerConfirm::Write()
{
    _worldPacket << Unit;

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
    _worldPacket << SpellID;
    _worldPacket << TrainerFailedReason;

    return &_worldPacket;
}

void WorldPackets::NPC::RequestStabledPets::Read()
{
    _worldPacket >> StableMaster;
}
