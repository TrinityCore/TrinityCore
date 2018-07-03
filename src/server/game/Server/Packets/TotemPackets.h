/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TotemPackets_h__
#define TotemPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Totem
    {
        class TotemDestroyed final : public ClientPacket
        {
        public:
            TotemDestroyed(WorldPacket&& packet) : ClientPacket(CMSG_TOTEM_DESTROYED, std::move(packet)) { }

            void Read() override;

            ObjectGuid TotemGUID;
            uint8 Slot = 0;
        };

        class TotemCreated final : public ServerPacket
        {
        public:
            TotemCreated() : ServerPacket(SMSG_TOTEM_CREATED, 25) { }

            WorldPacket const* Write() override;

            ObjectGuid Totem;
            int32 SpellID = 0;
            int32 Duration = 0;
            int8 Slot = 0;
            float TimeMod = 1.0f;
            bool CannotDismiss = false;
        };

        class TotemMoved final : public ServerPacket
        {
        public:
            TotemMoved() : ServerPacket(SMSG_TOTEM_MOVED, 18) { }

            WorldPacket const* Write() override;

            ObjectGuid Totem;
            uint8 Slot = 0;
            uint8 NewSlot = 0;
        };
    }
}

#endif // TotemPackets_h__
