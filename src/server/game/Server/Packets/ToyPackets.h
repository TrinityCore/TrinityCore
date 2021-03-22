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

#ifndef ToyPackets_h__
#define ToyPackets_h__

#include "SpellPackets.h"
#include "CollectionMgr.h"

namespace WorldPackets
{
    namespace Toy
    {
        class AddToy final : public ClientPacket
        {
        public:
            AddToy(WorldPacket&& packet) : ClientPacket(CMSG_ADD_TOY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class UseToy final : public ClientPacket
        {
        public:
            UseToy(WorldPacket&& packet) : ClientPacket(CMSG_USE_TOY, std::move(packet)) { }

            void Read() override;

            WorldPackets::Spells::SpellCastRequest Cast;
        };

        class AccountToyUpdate final : public ServerPacket
        {
        public:
            AccountToyUpdate() : ServerPacket(SMSG_ACCOUNT_TOY_UPDATE, 1 + 4 + 1) { }

            WorldPacket const* Write() override;

            bool IsFullUpdate = false;
            ToyBoxContainer const* Toys = nullptr;
        };

        class ToyClearFanfare final : public ClientPacket
        {
        public:
            ToyClearFanfare(WorldPacket&& packet) : ClientPacket(CMSG_TOY_CLEAR_FANFARE, std::move(packet)) { }

            void Read() override;

            uint32 ItemID = 0;
        };
    }
}

#endif // ToyPackets_h__
