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
#include "ObjectGuid.h"
#include "Optional.h"

namespace WorldPackets
{
    namespace CombatLog
    {
        struct SubDamage
        {
            int32 SchoolMask = 0;
            float FDamage = 0.0f; // Float damage (Most of the time equals to Damage)
            int32 Damage = 0;
            int32 Absorbed = 0;
            int32 Resisted = 0;
        };

        struct UnkAttackerState
        {
            int32 State1 = 0;
            float State2 = 0.0f;
            float State3 = 0.0f;
            float State4 = 0.0f;
            float State5 = 0.0f;
            float State6 = 0.0f;
            float State7 = 0.0f;
            float State8 = 0.0f;
            float State9 = 0.0f;
            float State10 = 0.0f;
            float State11 = 0.0f;
            int32 State12 = 0;
            int32 State13 = 0;
        };

        class AttackerStateUpdate final : public ServerPacket
        {
        public:
            AttackerStateUpdate() : ServerPacket(SMSG_ATTACKER_STATE_UPDATE, 62) { }

            WorldPacket const* Write() override;

            uint32 HitInfo = 0; // Flags
            ObjectGuid AttackerGUID;
            ObjectGuid VictimGUID;
            int32 Damage = 0;
            int32 OverDamage = -1; // (damage - health) or -1 if unit is still alive
            Optional<SubDamage> SubDmg;
            uint8 VictimState = 0;
            uint32 AttackerState = 0;
            uint32 MeleeSpellID = 0;
            int32 BlockAmount = 0;
            int32 RageGained = 0;
            UnkAttackerState UnkState;
            float Unk = 0.0f;
        };

        class SpellEnergizeLog final : public ServerPacket
        {
        public:
            SpellEnergizeLog() : ServerPacket(SMSG_SPELL_ENERGIZE_LOG, 8 + 8 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid TargetGUID;
            int32 SpellID = 0;
            int32 Type = 0;
            int32 Amount = 0;
        };

        class EnvironmentalDamageLog final : public ServerPacket
        {
        public:
            EnvironmentalDamageLog() : ServerPacket(SMSG_ENVIRONMENTAL_DAMAGE_LOG, 8 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            int32 Amount = 0;
            int32 Resisted = 0;
            int32 Absorbed = 0;
            uint8 Type = 0; ///< @see enum EnviromentalDamage
        };
    }
}

#endif // CombatLogPackets_h__
