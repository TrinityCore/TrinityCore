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

#include "BankPackets.h"

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Bank::InvUpdate& invUpdate)
{
    int32 invItemCount = data.ReadBits(2);
    invUpdate.Items.reserve(invItemCount);
    for (int32 i = 0; i < invItemCount; ++i)
    {
        WorldPackets::Bank::InvUpdate::InvItem item;
        data >> item.ContainerSlot;
        data >> item.Slot;
        invUpdate.Items.push_back(item);
    }

    return data;
}

void WorldPackets::Bank::AutoBankItem::Read()
{
    _worldPacket >> Inv >> Bag >> Slot;
}

void WorldPackets::Bank::AutoStoreBankItem::Read()
{
    _worldPacket >> Inv >> Bag >> Slot;
}

void WorldPackets::Bank::BuyBankSlot::Read()
{
    _worldPacket >> Guid;
}