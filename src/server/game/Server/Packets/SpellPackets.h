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

#ifndef SpellPackets_h__
#define SpellPackets_h__

#include "Packet.h"

namespace WorldPackets
{
    namespace Spells
    {
        class UpdateProjectilePosition final : public ClientPacket
        {
            public:
                UpdateProjectilePosition(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_PROJECTILE_POSITION, std::move(packet)) { }

                void Read() override;

                ObjectGuid Guid;
                uint32 Spell;
                uint8 Count;
                Position Pos;    // Position of missile hit
        };

        class SetProjectilePosition final : public ServerPacket
        {
            public:
                SetProjectilePosition();

                WorldPacket const* Write() override;

                ObjectGuid Guid;
                uint8 Count;
                Position Pos;
        };
    }
}

#endif // SpellPackets_h__
