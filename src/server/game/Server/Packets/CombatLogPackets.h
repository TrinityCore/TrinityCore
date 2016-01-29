/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
        class CombatLogServerPacket : public ServerPacket
        {
        public:
            CombatLogServerPacket(OpcodeServer opcode, size_t initialSize = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT)
                : ServerPacket(opcode, initialSize, connection), _fullLogPacket(opcode, initialSize, connection) { }

            WorldPacket const* GetFullLogPacket() const { return &_fullLogPacket; }
            WorldPacket const* GetBasicLogPacket() const { return &_worldPacket; }

            Spells::SpellCastLogData LogData;

        protected:
            template<typename T>
            void operator<<(T const& val)
            {
                _worldPacket << val;
                _fullLogPacket << val;
            }

            void WriteLogDataBit()
            {
                _worldPacket.WriteBit(false);
                _fullLogPacket.WriteBit(true);
            }

            void FlushBits()
            {
                _worldPacket.FlushBits();
                _fullLogPacket.FlushBits();
            }

            bool WriteBit(bool bit)
            {
                _worldPacket.WriteBit(bit);
                _fullLogPacket.WriteBit(bit);
                return bit;
            }

            void WriteBits(uint32 value, uint32 bitCount)
            {
                _worldPacket.WriteBits(value, bitCount);
                _fullLogPacket.WriteBits(value, bitCount);
            }

            ByteBuffer& WriteLogData() { return _fullLogPacket << LogData; }

            WorldPacket _fullLogPacket;
        };

        class SpellNonMeleeDamageLog final : public CombatLogServerPacket
        {
        public:
            SpellNonMeleeDamageLog() : CombatLogServerPacket(SMSG_SPELL_NON_MELEE_DAMAGE_LOG, 60) { }

            WorldPacket const* Write() override;

            int32 Absorbed = 0;
            int32 ShieldBlock = 0;
            ObjectGuid Me;
            int32 SpellID = 0;
            int32 Resisted = 0;
            bool Periodic = 0.0f;
            uint8 SchoolMask = 0;
            ObjectGuid CasterGUID;
            int32 Damage = 0;
            // Optional<SpellNonMeleeDamageLogDebugInfo> Debug Info;
            int32 Flags = 0;
            int32 Overkill = 0;
        };

        class EnvironmentalDamageLog final : public CombatLogServerPacket
        {
        public:
            EnvironmentalDamageLog() : CombatLogServerPacket(SMSG_ENVIRONMENTAL_DAMAGE_LOG, 23) { }

            WorldPacket const* Write() override;

            ObjectGuid Victim;
            uint8 Type = 0; ///< @see enum EnviromentalDamage
            int32 Amount = 0;
            int32 Resisted = 0;
            int32 Absorbed = 0;
        };

        class SpellExecuteLog final : public CombatLogServerPacket
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

            SpellExecuteLog() : CombatLogServerPacket(SMSG_SPELL_EXECUTE_LOG, 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            int32 SpellID = 0;
            std::vector<SpellLogEffect> Effects;
        };

        class SpellHealLog final : public CombatLogServerPacket
        {
        public:
            SpellHealLog() : CombatLogServerPacket(SMSG_SPELL_HEAL_LOG, 16 + 16 + 4 * 4 + 1) { }

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
        };

        class SpellPeriodicAuraLog final : public CombatLogServerPacket
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

            SpellPeriodicAuraLog() : CombatLogServerPacket(SMSG_SPELL_PERIODIC_AURA_LOG, 16 + 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid TargetGUID;
            ObjectGuid CasterGUID;
            int32 SpellID = 0;
            std::vector<SpellLogEffect> Effects;
        };

        class SpellInterruptLog final : public ServerPacket
        {
        public:
            SpellInterruptLog() : ServerPacket(SMSG_SPELL_INTERRUPT_LOG, 16 + 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            ObjectGuid Victim;
            int32 InterruptedSpellID = 0;
            int32 SpellID = 0;
        };

        class SpellEnergizeLog final : public CombatLogServerPacket
        {
        public:
            SpellEnergizeLog() : CombatLogServerPacket(SMSG_SPELL_ENERGIZE_LOG, 16 + 16 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid TargetGUID;
            int32 SpellID = 0;
            int32 Type = 0;
            int32 Amount = 0;
        };

        class SpellInstakillLog final : public ServerPacket
        {
        public:
            SpellInstakillLog() : ServerPacket(SMSG_SPELL_INSTAKILL_LOG, 16 + 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Target;
            ObjectGuid Caster;
            int32 SpellID = 0;
        };

        struct SpellLogMissDebug
        {
            float HitRoll = 0.0f;
            float HitRollNeeded = 0.0f;
        };

        struct SpellLogMissEntry
        {
            SpellLogMissEntry(ObjectGuid const& victim, uint8 missReason) : Victim(victim), MissReason(missReason) { }

            ObjectGuid Victim;
            uint8 MissReason = 0;
            Optional<SpellLogMissDebug> Debug;
        };

        class SpellMissLog final : public ServerPacket
        {
        public:
            SpellMissLog() : ServerPacket(SMSG_SPELL_MISS_LOG) { }

            WorldPacket const* Write() override;

            int32 SpellID = 0;
            ObjectGuid Caster;
            std::vector<SpellLogMissEntry> Entries;
        };

        class ProcResist final : public ServerPacket
        {
        public:
            ProcResist() : ServerPacket(SMSG_PROC_RESIST, 16 + 4 + 4 + 4 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            ObjectGuid Target;
            int32 SpellID = 0;
            Optional<float> Rolled;
            Optional<float> Needed;
        };

        class SpellOrDamageImmune final : public ServerPacket
        {
        public:
            SpellOrDamageImmune() : ServerPacket(SMSG_SPELL_OR_DAMAGE_IMMUNE, 16 + 1 + 4 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid VictimGUID;
            uint32 SpellID = 0;
            bool IsPeriodic = false;
        };

        class SpellDamageShield final : public CombatLogServerPacket
        {
        public:
            SpellDamageShield() : CombatLogServerPacket(SMSG_SPELL_DAMAGE_SHIELD, 4 + 16 + 4 + 4 + 16 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Defender;
            int32 SpellID = 0;
            int32 TotalDamage = 0;
            int32 OverKill = 0;
            int32 SchoolMask = 0;
            int32 LogAbsorbed = 0;
        };

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
        };

        class AttackerStateUpdate final : public CombatLogServerPacket
        {
        public:
            AttackerStateUpdate() : CombatLogServerPacket(SMSG_ATTACKER_STATE_UPDATE, 70) { }

            WorldPacket const* Write() override;

            uint32 HitInfo = 0; // Flags
            ObjectGuid AttackerGUID;
            ObjectGuid VictimGUID;
            int32 Damage = 0;
            int32 OverDamage = -1; // (damage - health) or -1 if unit is still alive
            Optional<SubDamage> SubDmg;
            uint8 VictimState = 0;
            int32 AttackerState = -1;
            int32 MeleeSpellID = 0;
            int32 BlockAmount = 0;
            int32 RageGained = 0;
            UnkAttackerState UnkState;
            float Unk = 0.0f;
        };
    }
}

#endif // CombatLogPackets_h__
