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

#ifndef CombatLogPackets_h__
#define CombatLogPackets_h__

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace CombatLog
    {
        class EnvironmentalDamageLog final : public ServerPacket
        {
        public:
            EnvironmentalDamageLog() : ServerPacket(SMSG_ENVIRONMENTAL_DAMAGE_LOG, 21) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            EnviromentalDamage Type = DAMAGE_EXHAUSTED;
            uint32 Amount = 0;
            uint32 Resisted = 0;
            uint32 Absorbed = 0;
        };
    }
}

#endif // CombatLogPackets_h__
