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

#include "NPCPackets.h"
#include "ItemPackets.h"

void WorldPackets::NPC::Hello::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* WorldPackets::NPC::GossipMessage::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << GossipID;
    _worldPacket << FriendshipFactionID;
    _worldPacket << TextID;

    _worldPacket << int32(GossipOptions.size());
    _worldPacket << int32(GossipText.size());

    for (ClientGossipOptions const& options : GossipOptions)
    {
        _worldPacket << options.ClientOption;
        _worldPacket << options.OptionNPC;
        _worldPacket << options.OptionFlags;
        _worldPacket << options.OptionCost;

        _worldPacket.WriteBits(options.Text.size(), 12);
        _worldPacket.WriteBits(options.Confirm.size(), 12);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(options.Text);
        _worldPacket.WriteString(options.Confirm);
    }

    for (ClientGossipText const& text : GossipText)
    {
        _worldPacket << text.QuestID;
        _worldPacket << text.QuestType;
        _worldPacket << text.QuestLevel;
        _worldPacket << text.QuestFlags[0];
        _worldPacket << text.QuestFlags[1];

        _worldPacket.WriteBit(text.Repeatable);
        _worldPacket.WriteBits(text.QuestTitle.size(), 9);
        _worldPacket.FlushBits();

        _worldPacket.WriteString(text.QuestTitle);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::VendorInventory::Write()
{
    _worldPacket << Vendor;
    _worldPacket << Reason;

    _worldPacket << int32(Items.size());
    for (VendorItem const& item : Items)
    {
        _worldPacket << item.MuID;
        _worldPacket << item.Type;
        _worldPacket << item.Item;
        _worldPacket << item.Quantity;
        _worldPacket << item.Price;
        _worldPacket << item.Durability;
        _worldPacket << item.StackCount;
        _worldPacket << item.ExtendedCostID;
        _worldPacket << item.PlayerConditionFailed;

        _worldPacket.WriteBit(item.DoNotFilterOnVendor);
        _worldPacket.FlushBits();
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::NPC::TrainerList::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << TrainerType;
    _worldPacket << TrainerID;

    _worldPacket << int32(Spells.size());
    for (TrainerListSpell const& spell : Spells)
    {
        _worldPacket << spell.SpellID;
        _worldPacket << spell.MoneyCost;
        _worldPacket << spell.ReqSkillLine;
        _worldPacket << spell.ReqSkillRank;

        for (uint32 i = 0; i < MAX_TRAINERSPELL_ABILITY_REQS; ++i)
            _worldPacket << spell.ReqAbility[i];

        _worldPacket << spell.Usable;
        _worldPacket << spell.ReqLevel;
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
