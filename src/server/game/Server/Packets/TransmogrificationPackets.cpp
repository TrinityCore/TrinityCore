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

    _worldPacket >> Bits<1>(CurrentSpecOnly);
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

ByteBuffer& operator>>(ByteBuffer& data, TransmogOutfitSlot& slot)
{
    data >> slot.Slot;
    data >> slot.SlotOption;
    data >> slot.ItemModifiedAppearanceID;
    data >> slot.AppearanceDisplayType;
    data >> slot.SpellItemEnchantmentID;
    data >> slot.IllusionDisplayType;
    data >> slot.Flags;
    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, TransmogOutfitSlot const& slot)
{
    data << slot.Slot;
    data << slot.SlotOption;
    data << slot.ItemModifiedAppearanceID;
    data << slot.AppearanceDisplayType;
    data << slot.SpellItemEnchantmentID;
    data << slot.IllusionDisplayType;
    data << slot.Flags;
    return data;
}

void TransmogOutfitUpdateSlots::Read()
{
    _worldPacket >> OutfitID;
    uint32 slotCount;
    _worldPacket >> slotCount;
    _worldPacket >> Npc;

    // Skip 8 bytes of extra header between GUID and slot data
    _worldPacket.rpos(_worldPacket.rpos() + 8);

    uint32 clampedSlotCount = std::min(slotCount, MAX_OUTFIT_SLOTS);
    Slots.resize(clampedSlotCount);
    for (uint32 i = 0; i < clampedSlotCount; ++i)
    {
        _worldPacket >> Slots[i];
    }
    // 1 trailing byte remains in the packet (boolean flag, unused)
}


WorldPacket const* TransmogOutfitSlotsUpdated::Write()
{
    _worldPacket << OutfitID;
    _worldPacket << uint32(Slots.size());
    for (TransmogOutfitSlot const& slot : Slots)
        _worldPacket << slot;

    return &_worldPacket;
}

void TransmogOutfitNew::Read()
{
    _worldPacket >> Npc;

    // Skip 2 unknown header bytes (index/flags)
    _worldPacket.rpos(_worldPacket.rpos() + 2);

    _worldPacket >> Icon;

    // Name length is encoded as uint16 with high bit as a flag
    uint16 nameInfo;
    _worldPacket >> nameInfo;
    uint16 nameLength = nameInfo & 0x7FFF;
    Name = _worldPacket.ReadString(nameLength);
}

void ClearNewAppearance::Read()
{
    _worldPacket >> ItemModifiedAppearanceID;
}

void TransmogOutfitUpdateInfo::Read()
{
    _worldPacket >> Npc;
    _worldPacket >> OutfitID;
    _worldPacket >> Icon;
    uint32 nameLength = _worldPacket.ReadBits(7);
    _worldPacket.ResetBitPos();
    Name = _worldPacket.ReadString(nameLength);
    TC_LOG_DEBUG("network", "TransmogOutfitUpdateInfo::Read - Npc={}, OutfitID={}, Icon={}, NameLength={}, Name='{}'", Npc.ToString(), OutfitID, Icon, nameLength, Name);
}

WorldPacket const* TransmogOutfitInfoUpdated::Write()
{
    _worldPacket << OutfitID;
    return &_worldPacket;
}

WorldPacket const* TransmogOutfitNewEntryAdded::Write()
{
    _worldPacket << OutfitID;
    return &_worldPacket;
}
}
