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

#ifndef TRINITYCORE_COMBAT_LOG_PACKETS_H
#define TRINITYCORE_COMBAT_LOG_PACKETS_H

#include "Packet.h"
#include "Player.h"

namespace WorldPackets
{
    namespace CombatLog
    {
        class SpellNonMeleeDamageLog final : public ServerPacket
        {
        public:
            explicit SpellNonMeleeDamageLog() : ServerPacket(SMSG_SPELLNONMELEEDAMAGELOG, 16 + 4 + 4 + 4 + 1 + 4 + 4 + 1 + 1 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Me;
            ObjectGuid CasterGUID;
            int32 SpellID = 0;
            int32 Damage = 0;
            int32 Overkill = 0;
            uint8 SchoolMask = 0;
            int32 ShieldBlock = 0;
            int32 Resisted = 0;
            bool Periodic = false;
            int32 Absorbed = 0;
            int32 Flags = 0;
            // Optional<SpellNonMeleeDamageLogDebugInfo> DebugInfo;
        };

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

        struct SubDamage
        {
            int32 SchoolMask = 0;
            float FDamage = 0.0f; // Float damage (Most of the time equals to Damage)
            int32 Damage = 0;
            int32 Absorbed = 0;
            int32 Resisted = 0;
        };

        struct HitInfoData
        {
            uint32 ArmorReduction = 0;
            float CritRollNeeded = 0.0f;
            float CombatRoll = 0.0f;
            float MissChance = 0.0f;
            float DodgeChance = 0.0f;
            float ParryChance = 0.0f;
            float BlockChance = 0.0f;
            float GlanceChance = 0.0f;
            float CrushChance = 0.0f;
            float MinDamage[2] = { };
            float MaxDamage[2] = { };
            uint32 SinceLastSwing = 0;
        };

        class AttackerStateUpdate final : public ServerPacket
        {
        public:
            explicit AttackerStateUpdate() : ServerPacket(SMSG_ATTACKERSTATEUPDATE, 4 + 5 + 5 + 4 + 4 + 1 + (4 + 4 + 4) * 2 + 4 * 2 + 4 * 2 + 1 + 4 + 4 + 4 + 4 + 4 * 12) { }

            WorldPacket const* Write() override;

            uint32 Flags = 0; // Flags
            ObjectGuid AttackerGUID;
            ObjectGuid VictimGUID;
            int32 Damage = 0;
            int32 OverDamage = -1; // (damage - health) or -1 if unit is still alive
            std::array<SubDamage, 2> SubDmg;
            uint8 SubDmgCount = 1;
            uint8 VictimState = 0;
            uint32 AttackerState = 0;
            uint32 MeleeSpellID = 0;
            int32 BlockAmount = 0;
            int32 RageGained = 0;
            HitInfoData HitInfo;
        };
    }
}

#endif // TRINITYCORE_COMBAT_LOG_PACKETS_H
