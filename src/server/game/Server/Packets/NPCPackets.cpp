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

namespace WorldPackets::NPC
{
ByteBuffer& operator<<(ByteBuffer& data, ClientGossipOptions const& gossipOption)
{
    data << int32(gossipOption.GossipOptionID);
    data << uint8(gossipOption.OptionNPC);
    data << int8(gossipOption.OptionFlags);
    data << uint32(gossipOption.OptionCost);
    data << gossipOption.Text;
    data << gossipOption.Confirm;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ClientGossipText const& gossipText)
{
    data << int32(gossipText.QuestID);
    data << int32(gossipText.QuestType);
    data << int32(gossipText.QuestLevel);
    data << int32(gossipText.QuestFlags);
    data << uint8(gossipText.Repeatable);
    data << gossipText.QuestTitle;

    return data;
}

void Hello::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* GossipMessage::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << int32(GossipID);
    _worldPacket << int32(RandomTextID);
    _worldPacket << uint32(GossipOptions.size());

    for (ClientGossipOptions const& options : GossipOptions)
        _worldPacket << options;

    _worldPacket << uint32(GossipText.size());

    for (ClientGossipText const& text : GossipText)
        _worldPacket << text;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, VendorItem const& item)
{
    data << int32(item.MuID);
    data << uint32(item.Item);
    data << uint32(item.ItemDisplayInfoID);
    data << int32(item.Quantity);
    data << int32(item.Price);
    data << int32(item.Durability);
    data << int32(item.StackCount);
    data << int32(item.ExtendedCostID);

    return data;
}

WorldPacket const* VendorInventory::Write()
{
    _worldPacket << Vendor;
    _worldPacket << uint8(Items.size());
    for (VendorItem const& item : Items)
        _worldPacket << item;

    if (Items.empty())
        _worldPacket << int8(Reason);

    return &_worldPacket;
}

WorldPacket const* TrainerList::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << int32(TrainerType);

    _worldPacket << int32(Spells.size());
    for (TrainerListSpell const& spell : Spells)
    {
        _worldPacket << int32(spell.SpellID);
        _worldPacket << uint8(spell.Usable);
        _worldPacket << int32(spell.MoneyCost);
        _worldPacket.append(spell.PointCost.data(), spell.PointCost.size());
        _worldPacket << uint8(spell.ReqLevel);
        _worldPacket << int32(spell.ReqSkillLine);
        _worldPacket << int32(spell.ReqSkillRank);
        _worldPacket.append(spell.ReqAbility.data(), spell.ReqAbility.size());
    }

    _worldPacket << Greeting;

    return &_worldPacket;
}

WorldPacket const* GossipPOI::Write()
{
    _worldPacket << int32(Flags);
    _worldPacket << Pos;
    _worldPacket << int32(Icon);
    _worldPacket << int32(Importance);
    _worldPacket << Name;

    return &_worldPacket;
}

void TrainerBuySpell::Read()
{
    _worldPacket >> TrainerGUID;
    _worldPacket >> SpellID;
}

WorldPacket const* TrainerBuyFailed::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << int32(SpellID);
    _worldPacket << int32(TrainerFailedReason);

    return &_worldPacket;
}

WorldPacket const* TrainerBuySucceeded::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}
}
