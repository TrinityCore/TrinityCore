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

#ifndef CombatLogPackets_h__
#define CombatLogPackets_h__

#include "Packet.h"
#include "SpellPackets.h"

namespace WorldPackets
{
    namespace CombatLog
    {
        class SpellNonMeleeDamageLog final : public ServerPacket
        {
        public:
            SpellNonMeleeDamageLog() : ServerPacket(SMSG_SPELL_NON_MELEE_DAMAGE_LOG, 60) { }

            WorldPacket const* Write() override;

            int32 Absorbed = 0;
            int32 ShieldBlock = 0;
            ObjectGuid Me;
            int32 SpellID = 0;
            int32 Resisted = 0;
            bool Periodic = 0.0f;
            uint8 SchoolMask = 0;
            ObjectGuid CasterGUID;
            Optional<Spells::SpellCastLogData> LogData;
            int32 Damage = 0;
            // Optional<SpellNonMeleeDamageLogDebugInfo> Debug Info;
            int32 Flags = 0;
            int32 Overkill = 0;
        };

        class EnvironmentalDamageLog final : public ServerPacket
        {
        public:
            EnvironmentalDamageLog() : ServerPacket(SMSG_ENVIRONMENTALDAMAGELOG, 23) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            uint8 Type = 0; ///< @see enum EnviromentalDamage
            int32 Amount = 0;
            int32 Resisted = 0;
            int32 Absorbed = 0;
            Optional<Spells::SpellCastLogData> LogData; /// @todo: find the correct way where to use it, in sniff always false
        };
    }
}

#endif // CombatLogPackets_h__
