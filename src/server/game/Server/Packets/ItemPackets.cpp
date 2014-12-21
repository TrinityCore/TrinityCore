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

namespace WorldPackets::Item
{
WorldPacket const* SetProficiency::Write()
{
    _worldPacket << uint8(ProficiencyClass);
    _worldPacket << uint32(ProficiencyMask);

    return &_worldPacket;
}

WorldPacket const* InventoryChangeFailure::Write()
{
    _worldPacket << uint8(BagResult);
    if (BagResult != EQUIP_ERR_OK)
    {
        _worldPacket << Item[0];
        _worldPacket << Item[1];
        _worldPacket << uint8(ContainerBSlot); // bag type subclass, used with EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM and EQUIP_ERR_WRONG_BAG_TYPE_2

        switch (BagResult)
        {
            case EQUIP_ERR_CANT_EQUIP_LEVEL_I:
            case EQUIP_ERR_PURCHASE_LEVEL_TOO_LOW:
                _worldPacket << int32(Level);
                break;
            case EQUIP_ERR_EVENT_AUTOEQUIP_BIND_CONFIRM:
                _worldPacket << SrcContainer;
                _worldPacket << int32(SrcSlot);
                _worldPacket << DstContainer;
                break;
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_COUNT_EXCEEDED_IS:
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_SOCKETED_EXCEEDED_IS:
            case EQUIP_ERR_ITEM_MAX_LIMIT_CATEGORY_EQUIPPED_EXCEEDED_IS:
                _worldPacket << int32(LimitCategory);
                break;
            default:
                break;
        }
    }

    return &_worldPacket;
}

void SplitItem::Read()
{
    _worldPacket >> FromPackSlot;
    _worldPacket >> FromSlot;
    _worldPacket >> ToPackSlot;
    _worldPacket >> ToSlot;
    _worldPacket >> Quantity;
}

void SwapInvItem::Read()
{
    _worldPacket >> Slot2;
    _worldPacket >> Slot1;
}

void SwapItem::Read()
{
    _worldPacket >> ContainerSlotB;
    _worldPacket >> SlotB;
    _worldPacket >> ContainerSlotA;
    _worldPacket >> SlotA;
}

void AutoEquipItem::Read()
{
    _worldPacket >> PackSlot;
    _worldPacket >> Slot;
}

void DestroyItem::Read()
{
    _worldPacket >> ContainerId;
    _worldPacket >> SlotNum;
    _worldPacket >> Count;
}
}
