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

#ifndef TRINITYCORE_BANK_PACKETS_H
#define TRINITYCORE_BANK_PACKETS_H

#include "Packet.h"
#include "ItemPacketsCommon.h"
#include "ObjectGuid.h"

enum class BagSlotFlags : uint32;
enum class PlayerInteractionType : int32;

namespace WorldPackets
{
    namespace Bank
    {
        class AutoBankItem final : public ClientPacket
        {
        public:
            explicit AutoBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOBANK_ITEM, std::move(packet)) { }

            void Read() override;

            WorldPackets::Item::InvUpdate Inv;
            ::BankType BankType = ::BankType::Character;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class AutoStoreBankItem final : public ClientPacket
        {
        public:
            explicit AutoStoreBankItem(WorldPacket&& packet) : ClientPacket(CMSG_AUTOSTORE_BANK_ITEM, std::move(packet)) { }

            void Read() override;

            WorldPackets::Item::InvUpdate Inv;
            uint8 Bag = 0;
            uint8 Slot = 0;
        };

        class BuyBankTab final : public ClientPacket
        {
        public:
            explicit BuyBankTab(WorldPacket&& packet) : ClientPacket(CMSG_BUY_ACCOUNT_BANK_TAB, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            ::BankType BankType = ::BankType::Character;
        };

        class AutoDepositCharacterBank final : public ClientPacket
        {
        public:
            explicit AutoDepositCharacterBank(WorldPacket&& packet) : ClientPacket(CMSG_AUTO_DEPOSIT_CHARACTER_BANK, std::move(packet)) { }

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

        struct BankTabSettings
        {
            std::string Name;
            std::string Icon;
            std::string Description;
            BagSlotFlags DepositFlags = { };
        };

        class UpdateBankTabSettings final : public ClientPacket
        {
        public:
            explicit UpdateBankTabSettings(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_ACCOUNT_BANK_TAB_SETTINGS, std::move(packet)) { }

            void Read() override;

            ObjectGuid Banker;
            ::BankType BankType = ::BankType::Character;
            uint8 Tab = 0;
            BankTabSettings Settings;
        };
    }
}

#endif // TRINITYCORE_BANK_PACKETS_H
