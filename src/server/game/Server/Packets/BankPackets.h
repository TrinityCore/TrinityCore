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
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"

enum class PlayerInteractionType : int32;

namespace WorldPackets
{
    namespace Bank
    {
        class AutoBankItem final : public ClientPacket
        {
        public:
            AutoBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOBANK_ITEM, std::move(packet)) { }

            void Read() override;

            WorldPackets::Item::InvUpdate Inv;
            ::BankType BankType = ::BankType::Character;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class AutoStoreBankItem final : public ClientPacket
        {
        public:
            AutoStoreBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_BANK_ITEM, std::move(packet)) { }

            void Read() override;

            WorldPackets::Item::InvUpdate Inv;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class BuyBankSlot final : public ClientPacket
        {
        public:
            BuyBankSlot(WorldPacket&& packet) : ClientPacket(CMSG_BUY_BANK_SLOT, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class AutoBankReagent final : public ClientPacket
        {
        public:
            AutoBankReagent(WorldPacket&& packet) : ClientPacket(CMSG_AUTOBANK_REAGENT, std::move(packet)) { }

            void Read() override;

            WorldPackets::Item::InvUpdate Inv;
            uint8 Slot = 0;
            uint8 PackSlot = 0;
        };

        class AutoStoreBankReagent final : public ClientPacket
        {
        public:
            AutoStoreBankReagent(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_BANK_REAGENT, std::move(packet)) { }

            void Read() override;

            WorldPackets::Item::InvUpdate Inv;
            uint8 Slot = 0;
            uint8 PackSlot = 0;
        };

        // CMSG_BUY_REAGENT_BANK
        // CMSG_REAGENT_BANK_DEPOSIT
        class ReagentBank final : public ClientPacket
        {
        public:
            ReagentBank(WorldPacket&& packet) : ClientPacket(std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
        };

        class BankerActivate final : public ClientPacket
        {
        public:
            explicit BankerActivate(WorldPacket&& packet) : ClientPacket(CMSG_BANKER_ACTIVATE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            PlayerInteractionType InteractionType = { };
        };
    }
}
#endif // BankPackets_h__
