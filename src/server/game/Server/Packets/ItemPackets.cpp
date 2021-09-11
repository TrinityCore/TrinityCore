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

#include "ItemPackets.h"

WorldPacket const* WorldPackets::Item::SetProficiency::Write()
{
    _worldPacket << uint8(ProficiencyClass);
    _worldPacket << uint32(ProficiencyMask);

    return &_worldPacket;
}

void WorldPackets::Item::TransmogrifyItems::Read()
{
    Items.resize(_worldPacket.ReadBits(22));

    for (TransmogrifyItem& item : Items)
    {
        item.SrcItemGUID[0] = _worldPacket.ReadBit();
        item.SrcItemGUID[5] = _worldPacket.ReadBit();
        item.SrcItemGUID[6] = _worldPacket.ReadBit();
        item.SrcItemGUID[2] = _worldPacket.ReadBit();
        item.SrcItemGUID[3] = _worldPacket.ReadBit();
        item.SrcItemGUID[7] = _worldPacket.ReadBit();
        item.SrcItemGUID[4] = _worldPacket.ReadBit();
        item.SrcItemGUID[1] = _worldPacket.ReadBit();
    }

    Npc[7] = _worldPacket.ReadBit();
    Npc[3] = _worldPacket.ReadBit();
    Npc[5] = _worldPacket.ReadBit();
    Npc[6] = _worldPacket.ReadBit();
    Npc[1] = _worldPacket.ReadBit();
    Npc[4] = _worldPacket.ReadBit();
    Npc[0] = _worldPacket.ReadBit();
    Npc[2] = _worldPacket.ReadBit();

    for (TransmogrifyItem& item : Items)
    {
        _worldPacket >> item.ItemID;

        _worldPacket.ReadByteSeq(item.SrcItemGUID[1]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[5]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[0]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[4]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[6]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[7]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[3]);
        _worldPacket.ReadByteSeq(item.SrcItemGUID[2]);

        _worldPacket >> item.Slot;
    }

    _worldPacket.ReadByteSeq(Npc[7]);
    _worldPacket.ReadByteSeq(Npc[2]);
    _worldPacket.ReadByteSeq(Npc[5]);
    _worldPacket.ReadByteSeq(Npc[4]);
    _worldPacket.ReadByteSeq(Npc[3]);
    _worldPacket.ReadByteSeq(Npc[1]);
    _worldPacket.ReadByteSeq(Npc[6]);
    _worldPacket.ReadByteSeq(Npc[0]);
}

void WorldPackets::Item::DestroyItem::Read()
{
    _worldPacket >> ContainerId;
    _worldPacket >> SlotNum;
    _worldPacket >> Count;
}
