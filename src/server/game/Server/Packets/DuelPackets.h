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

#ifndef TRINITYCORE_DUEL_PACKETS_H
#define TRINITYCORE_DUEL_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"

namespace WorldPackets
{
    namespace Duel
    {
        class DuelResponse final : public ClientPacket
        {
        public:
            explicit DuelResponse(WorldPacket&& packet);

            void Read() override;

            ObjectGuid ArbiterGUID;
        };
    }
}

#endif // TRINITYCORE_DUEL_PACKETS_H
