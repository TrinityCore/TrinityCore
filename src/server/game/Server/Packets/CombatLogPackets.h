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
#include "Spell.h"
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
            EnvironmentalDamageLog() : ServerPacket(SMSG_ENVIRONMENTAL_DAMAGE_LOG, 23) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            uint8 Type = 0; ///< @see enum EnviromentalDamage
            int32 Amount = 0;
            int32 Resisted = 0;
            int32 Absorbed = 0;
            Optional<Spells::SpellCastLogData> LogData; /// @todo: find the correct way where to use it, in sniff always false
        };

        class SpellExecuteLog final : public ServerPacket
        {
        public:
            struct SpellLogEffect
            {
                int32 Effect = 0;

                std::vector<SpellLogEffectPowerDrainParams> PowerDrainTargets;
                std::vector<SpellLogEffectExtraAttacksParams> ExtraAttacksTargets;
                std::vector<SpellLogEffectDurabilityDamageParams> DurabilityDamageTargets;
                std::vector<SpellLogEffectGenericVictimParams> GenericVictimTargets;
                std::vector<SpellLogEffectTradeSkillItemParams> TradeSkillTargets;
                std::vector<SpellLogEffectFeedPetParams> FeedPetTargets;
            };

            SpellExecuteLog() : ServerPacket(SMSG_SPELL_EXECUTE_LOG, 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            int32 SpellID = 0;
            std::vector<SpellLogEffect> Effects;
            Optional<Spells::SpellCastLogData> LogData; /// @todo: find the correct way where to use it, in sniff always false
        };

        class SpellHealLog final : public ServerPacket
        {
        public:
            SpellHealLog() : ServerPacket(SMSG_SPELL_HEAL_LOG, 16 + 16 + 4 * 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid TargetGUID;
            int32 SpellID       = 0;
            int32 Health        = 0;
            int32 OverHeal      = 0;
            int32 Absorbed      = 0;
            bool Crit           = false;
            bool Multistrike    = false;
            Optional<float> CritRollMade;
            Optional<float> CritRollNeeded;
            Optional<Spells::SpellCastLogData> LogData; /// @todo: find the correct way where to use it, in sniff always false
        };

        class SpellPeriodicAuraLog final : public ServerPacket
        {
        public:
            struct PeriodicalAuraLogEffectDebugInfo
            {
                float CritRollMade = 0.0f;
                float CritRollNeeded = 0.0f;
            };

            struct SpellLogEffect
            {
                int32 Effect              = 0;
                int32 Amount              = 0;
                int32 OverHealOrKill      = 0;
                int32 SchoolMaskOrPower   = 0;
                int32 AbsorbedOrAmplitude = 0;
                int32 Resisted            = 0;
                bool Crit                 = false;
                bool Multistrike          = false;
                Optional<PeriodicalAuraLogEffectDebugInfo> DebugInfo;
            };

            SpellPeriodicAuraLog() : ServerPacket(SMSG_SPELL_PERIODIC_AURA_LOG, 16 + 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid TargetGUID;
            ObjectGuid CasterGUID;
            int32 SpellID = 0;
            std::vector<SpellLogEffect> Effects;
            Optional<Spells::SpellCastLogData> LogData; /// @todo: find the correct way where to use it, in sniff always false
        };
    }
}

#endif // CombatLogPackets_h__
