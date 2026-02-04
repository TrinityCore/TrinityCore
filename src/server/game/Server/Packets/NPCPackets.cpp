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
#include "PacketOperators.h"

namespace WorldPackets::NPC
{
ByteBuffer& operator<<(ByteBuffer& data, TreasureItem const& treasureItem)
{
    data << Bits<1>(treasureItem.Type);
    data << int32(treasureItem.ID);
    data << int32(treasureItem.Quantity);
    data << int8(treasureItem.ItemContext);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TreasureLootList const& treasureLootList)
{
    data << Size<uint32>(treasureLootList.Items);
    for (TreasureItem const& treasureItem : treasureLootList.Items)
        data << treasureItem;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ClientGossipOptions const& gossipOption)
{
    data << int32(gossipOption.GossipOptionID);
    data << uint32(gossipOption.OptionNPC);
    data << int8(gossipOption.OptionFlags);
    data << uint64(gossipOption.OptionCost);
    data << uint32(gossipOption.OptionLanguage);
    data << int32(gossipOption.Flags);
    data << int32(gossipOption.OrderIndex);
    data << SizedString::BitsSize<12>(gossipOption.Text);
    data << SizedString::BitsSize<12>(gossipOption.Confirm);
    data << Bits<2>(gossipOption.Status);
    data << OptionalInit(gossipOption.SpellID);
    data << OptionalInit(gossipOption.OverrideIconID);
    data << SizedCString::BitsSize<8>(gossipOption.FailureDescription);
    data.FlushBits();

    data << gossipOption.Treasure;

    data << SizedString::Data(gossipOption.Text);
    data << SizedString::Data(gossipOption.Confirm);

    if (gossipOption.SpellID)
        data << int32(*gossipOption.SpellID);

    if (gossipOption.OverrideIconID)
        data << int32(*gossipOption.OverrideIconID);

    data << SizedCString::Data(gossipOption.FailureDescription);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, ClientGossipText const& gossipText)
{
    data << int32(gossipText.QuestID);
    data << int32(gossipText.ContentTuningID);
    data << int32(gossipText.QuestType);
    data << int32(gossipText.Unused1102);
    data.append(gossipText.QuestFlags);

    data << Bits<1>(gossipText.Repeatable);
    data << Bits<1>(gossipText.ResetByScheduler);
    data << Bits<1>(gossipText.Important);
    data << Bits<1>(gossipText.Meta);
    data << SizedString::BitsSize<9>(gossipText.QuestTitle);
    data.FlushBits();

    data << SizedString::Data(gossipText.QuestTitle);

    return data;
}

void Hello::Read()
{
    _worldPacket >> Unit;
}

WorldPacket const* NPCInteractionOpenResult::Write()
{
    _worldPacket << Npc;
    _worldPacket << int32(InteractionType);
    _worldPacket << Bits<1>(Success);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* GossipMessage::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << int32(GossipID);
    _worldPacket << int32(LfgDungeonsID);
    _worldPacket << int32(FriendshipFactionID);
    _worldPacket << Size<uint32>(GossipOptions);
    _worldPacket << Size<uint32>(GossipText);
    _worldPacket << OptionalInit(RandomTextID);
    _worldPacket << OptionalInit(BroadcastTextID);
    _worldPacket.FlushBits();

    for (ClientGossipOptions const& options : GossipOptions)
        _worldPacket << options;

    if (RandomTextID)
        _worldPacket << int32(*RandomTextID);

    if (BroadcastTextID)
        _worldPacket << int32(*BroadcastTextID);

    for (ClientGossipText const& text : GossipText)
        _worldPacket << text;

    return &_worldPacket;
}

ByteBuffer& operator<<(ByteBuffer& data, VendorItem const& item)
{
    data << uint64(item.Price);
    data << uint32(item.MuID);
    data << int32(item.Type);
    data << int32(item.StackCount);
    data << int32(item.Quantity);
    data << int32(item.ExtendedCostID);
    data << int32(item.PlayerConditionFailed);
    data << Bits<1>(item.Locked);
    data << Bits<1>(item.DoNotFilterOnVendor);
    data << Bits<1>(item.Refundable);
    data.FlushBits();

    data << item.Item;

    return data;
}

WorldPacket const* VendorInventory::Write()
{
    _worldPacket << Vendor;
    _worldPacket << int32(Reason);
    _worldPacket << Size<uint32>(Items);
    for (VendorItem const& item : Items)
        _worldPacket << item;

    return &_worldPacket;
}

WorldPacket const* TrainerList::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << int8(TrainerType);
    _worldPacket << uint32(TrainerID);

    _worldPacket << Size<uint32>(Spells);
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

    _worldPacket << SizedString::BitsSize<11>(Greeting);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Greeting);

    return &_worldPacket;
}

void GossipSelectOption::Read()
{
    _worldPacket >> GossipUnit;
    _worldPacket >> GossipID;
    _worldPacket >> GossipOptionID;
    _worldPacket >> SizedString::BitsSize<8>(PromotionCode);
    _worldPacket >> SizedString::Data(PromotionCode);
}

WorldPacket const* GossipOptionNPCInteraction::Write()
{
    _worldPacket << GossipGUID;
    _worldPacket << int32(GossipNpcOptionID);
    _worldPacket << OptionalInit(FriendshipFactionID);
    _worldPacket.FlushBits();

    if (FriendshipFactionID)
        _worldPacket << int32(*FriendshipFactionID);

    return &_worldPacket;
}

WorldPacket const* GossipComplete::Write()
{
    _worldPacket << Bits<1>(SuppressSound);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* GossipPOI::Write()
{
    _worldPacket << int32(ID);
    _worldPacket << int32(Flags);
    _worldPacket << Pos;
    _worldPacket << int32(Icon);
    _worldPacket << int32(Importance);
    _worldPacket << int32(WMOGroupID);
    _worldPacket << SizedString::BitsSize<6>(Name);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Name);

    return &_worldPacket;
}

void SpiritHealerActivate::Read()
{
    _worldPacket >> Healer;
}

void TabardVendorActivate::Read()
{
    _worldPacket >> Vendor;
    _worldPacket >> Type;
}

void TrainerBuySpell::Read()
{
    _worldPacket >> TrainerGUID;
    _worldPacket >> TrainerID;
    _worldPacket >> SpellID;
}

WorldPacket const* TrainerBuyFailed::Write()
{
    _worldPacket << TrainerGUID;
    _worldPacket << SpellID;
    _worldPacket << TrainerFailedReason;

    return &_worldPacket;
}

void RequestStabledPets::Read()
{
    _worldPacket >> StableMaster;
}

void SetPetSlot::Read()
{
    _worldPacket >> PetNumber;
    _worldPacket >> DestSlot;
    _worldPacket >> StableMaster;
}
}
