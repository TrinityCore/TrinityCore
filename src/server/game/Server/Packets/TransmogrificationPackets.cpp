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

#include "TransmogrificationPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Transmogrification
{
ByteBuffer& operator>>(ByteBuffer& data, TransmogrifyItem& transmogItem)
{
    data >> transmogItem.ItemModifiedAppearanceID;
    data >> transmogItem.Slot;
    data >> transmogItem.SpellItemEnchantmentID;
    data >> transmogItem.SecondaryItemModifiedAppearanceID;

    return data;
}

void TransmogrifyItems::Read()
{
    _worldPacket >> Size<uint32>(Items);
    _worldPacket >> Npc;
    for (TransmogrifyItem& item : Items)
        _worldPacket >> item;

    _worldPacket.ResetBitPos();
    _worldPacket >> Bits<1>(CurrentSpecOnly);
}

ByteBuffer& operator>>(ByteBuffer& data, TransmogOutfitDataInfo& transmogOutfitDataInfo)
{
    data.ResetBitPos();
    data >> As<uint8>(transmogOutfitDataInfo.SetType);
    data >> transmogOutfitDataInfo.Icon;
    data >> SizedString::BitsSize<8>(transmogOutfitDataInfo.Name);
    data >> Bits<1>(transmogOutfitDataInfo.SituationsEnabled);

    data >> SizedString::Data(transmogOutfitDataInfo.Name);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TransmogOutfitDataInfo const& transmogOutfitDataInfo)
{
    data << As<uint8>(transmogOutfitDataInfo.SetType);
    data << uint32(transmogOutfitDataInfo.Icon);
    data << SizedString::BitsSize<8>(transmogOutfitDataInfo.Name);
    data << Bits<1>(transmogOutfitDataInfo.SituationsEnabled);
    data.FlushBits();

    data << SizedString::Data(transmogOutfitDataInfo.Name);

    return data;
}

void TransmogOutfitNew::Read()
{
    _worldPacket >> Npc;
    _worldPacket >> As<uint8>(Source);
    _worldPacket >> Info;
}

WorldPacket const* TransmogOutfitNewEntryAdded::Write()
{
    _worldPacket << uint32(TransmogOutfitID);

    return &_worldPacket;
}

void TransmogOutfitUpdateInfo::Read()
{
    _worldPacket >> OutfitID;
    _worldPacket >> Npc;
    _worldPacket >> Info;
}

WorldPacket const* TransmogOutfitInfoUpdated::Write()
{
    _worldPacket << uint32(TransmogOutfitID);
    _worldPacket << *OutfitInfo;

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, TransmogOutfitSituationInfo& transmogOutfitSituationInfo)
{
    data >> transmogOutfitSituationInfo.SituationID;
    data >> transmogOutfitSituationInfo.SpecID;
    data >> transmogOutfitSituationInfo.LoadoutID;
    data >> transmogOutfitSituationInfo.EquipmentSetID;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TransmogOutfitSituationInfo const& transmogOutfitSituationInfo)
{
    data << uint32(transmogOutfitSituationInfo.SituationID);
    data << uint32(transmogOutfitSituationInfo.SpecID);
    data << uint32(transmogOutfitSituationInfo.LoadoutID);
    data << uint32(transmogOutfitSituationInfo.EquipmentSetID);

    return data;
}

void TransmogOutfitUpdateSituations::Read()
{
    _worldPacket >> OutfitID;
    _worldPacket >> Npc;
    _worldPacket >> Size<uint32>(Situations);
    for (TransmogOutfitSituationInfo& situation : Situations)
        _worldPacket >> situation;

    _worldPacket.ResetBitPos();
    _worldPacket >> Bits<1>(SituationsEnabled);
}

WorldPacket const* TransmogOutfitSituationsUpdated::Write()
{
    _worldPacket << uint32(TransmogOutfitID);
    _worldPacket << Size<uint32>(Situations);

    for (TransmogOutfitSituationInfo const& situation : Situations)
        _worldPacket << situation;

    _worldPacket << Bits<1>(SituationsEnabled);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, TransmogOutfitSlotData& transmogOutfitSlotData)
{
    data >> As<int8>(transmogOutfitSlotData.Slot);
    data >> As<uint8>(transmogOutfitSlotData.SlotOption);
    data >> As<uint8>(transmogOutfitSlotData.SheatheCategory);
    data >> transmogOutfitSlotData.ItemModifiedAppearanceID;
    data >> As<uint8>(transmogOutfitSlotData.AppearanceDisplayType);
    data >> transmogOutfitSlotData.SpellItemEnchantmentID;
    data >> As<uint8>(transmogOutfitSlotData.IllusionDisplayType);
    data >> transmogOutfitSlotData.Flags;

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TransmogOutfitSlotData const& transmogOutfitSlotData)
{
    data << As<int8>(transmogOutfitSlotData.Slot);
    data << As<uint8>(transmogOutfitSlotData.SlotOption);
    data << As<uint8>(transmogOutfitSlotData.SheatheCategory);
    data << uint32(transmogOutfitSlotData.ItemModifiedAppearanceID);
    data << As<uint8>(transmogOutfitSlotData.AppearanceDisplayType);
    data << uint32(transmogOutfitSlotData.SpellItemEnchantmentID);
    data << As<uint8>(transmogOutfitSlotData.IllusionDisplayType);
    data << uint32(transmogOutfitSlotData.Flags);

    return data;
}

void TransmogOutfitUpdateSlots::Read()
{
    _worldPacket >> OutfitID;
    _worldPacket >> Size<uint32>(Slots);
    _worldPacket >> Npc;
    _worldPacket >> Cost;

    for (TransmogOutfitSlotData& slot : Slots)
        _worldPacket >> slot;

    _worldPacket.ResetBitPos();
    _worldPacket >> Bits<1>(UseAvailableDiscount);

    std::ranges::sort(Slots, std::ranges::less(), [](TransmogOutfitSlotData const& slot) { return std::pair(slot.Slot, slot.SlotOption); });
}

WorldPacket const* TransmogOutfitSlotsUpdated::Write()
{
    _worldPacket << uint32(TransmogOutfitID);
    _worldPacket << Size<uint32>(Slots);

    for (TransmogOutfitSlotData const& slot : Slots)
        _worldPacket << slot;

    return &_worldPacket;
}

WorldPacket const* AccountTransmogUpdate::Write()
{
    _worldPacket << Bits<1>(IsFullUpdate);
    _worldPacket << Bits<1>(IsSetFavorite);
    _worldPacket << Size<uint32>(FavoriteAppearances);
    _worldPacket << Size<uint32>(NewAppearances);
    if (!FavoriteAppearances.empty())
        _worldPacket.append(FavoriteAppearances.data(), FavoriteAppearances.size());

    if (!NewAppearances.empty())
        _worldPacket.append(NewAppearances.data(), NewAppearances.size());

    return &_worldPacket;
}
}
