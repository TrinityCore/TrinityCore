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

#include "BankPackets.h"
#include "DBCEnums.h"

void WorldPackets::Bank::AutoBankItem::Read()
{
    _worldPacket >> Inv
                 >> As<int8>(BankType)
                 >> Bag
                 >> Slot;
}

void WorldPackets::Bank::AutoStoreBankItem::Read()
{
    _worldPacket >> Inv
                 >> Bag
                 >> Slot;
}

void WorldPackets::Bank::BuyBankSlot::Read()
{
    _worldPacket >> Guid;
}

void WorldPackets::Bank::AutoBankReagent::Read()
{
    _worldPacket >> Inv;
    _worldPacket >> PackSlot;
    _worldPacket >> Slot;
}

void WorldPackets::Bank::AutoStoreBankReagent::Read()
{
    _worldPacket >> Inv;
    _worldPacket >> Slot;
    _worldPacket >> PackSlot;
}

void WorldPackets::Bank::ReagentBank::Read()
{
    _worldPacket >> Banker;
}

void WorldPackets::Bank::BankerActivate::Read()
{
    _worldPacket >> Banker;
    _worldPacket >> As<int32>(InteractionType);
}
