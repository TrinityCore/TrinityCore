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

#ifndef BankPackets_h__
#define BankPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Bank
    {
        class AutoBankItem final : public ClientPacket
        {
        public:
            AutoBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOBANK_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class AutoStoreBankItem final : public ClientPacket
        {
        public:
            AutoStoreBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_BANK_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class BuyBankSlot final : public ClientPacket
        {
        public:
            BuyBankSlot(WorldPacket&& packet) : ClientPacket(CMSG_BUY_BANK_SLOT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
        };

        class BuyBankSlotResult final : public ServerPacket
        {
        public:
            BuyBankSlotResult() : ServerPacket(SMSG_BUY_BANK_SLOT_RESULT, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };

        class ShowBank final : public ServerPacket
        {
        public:
            ShowBank() : ServerPacket(SMSG_SHOW_BANK, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Banker;
        };
    }
}
#endif // BankPackets_h__
