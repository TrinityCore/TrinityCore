/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef CombatPackets_h__
#define CombatPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Combat
    {
        class AttackSwing final : public ClientPacket
        {
        public:
            AttackSwing(WorldPacket&& packet) : ClientPacket(CMSG_ATTACKSWING, std::move(packet)) { }

            void Read() override;

            ObjectGuid Victim;
        };

        class AttackStop final : public ClientPacket
        {
        public:
            AttackStop(WorldPacket&& packet) : ClientPacket(CMSG_ATTACKSTOP, std::move(packet)) { }

            void Read() override {};
        };
    }
}

#endif // CombatPackets_h__
