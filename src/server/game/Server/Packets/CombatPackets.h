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
#include "ObjectGuid.h"
#include "SpellPackets.h"

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

            void Read() override { }
        };

        class AttackStart final : public ServerPacket
        {
        public:
            AttackStart() : ServerPacket(SMSG_ATTACKSTART, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
        };

        class SAttackStop final : public ServerPacket
        {
        public:
            SAttackStop() : ServerPacket(SMSG_ATTACKSTOP, 17) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
            bool Dead = false;
        };

        struct ThreatInfo
        {
            ObjectGuid UnitGUID;
            int32 Threat = 0;
        };

        class ThreatUpdate final : public ServerPacket
        {
        public:
            ThreatUpdate() : ServerPacket(SMSG_THREAT_UPDATE, 24) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
        };

        class HighestThreatUpdate final : public ServerPacket
        {
        public:
            HighestThreatUpdate() : ServerPacket(SMSG_HIGHEST_THREAT_UPDATE, 44) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
            ObjectGuid HighestThreatGUID;
        };

        class ThreatRemove final : public ServerPacket
        {
        public:
            ThreatRemove() : ServerPacket(SMSG_THREAT_REMOVE, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid AboutGUID; // Unit to remove threat from (e.g. player, pet, guardian)
            ObjectGuid UnitGUID; // Unit being attacked (e.g. creature, boss)
        };

        class AIReaction final : public ServerPacket
        {
        public:
            AIReaction() : ServerPacket(SMSG_AI_REACTION, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            uint32 Reaction = 0;
        };

        struct SubDamage
        {
            int32 SchoolMask    = 0;
            float FDamage       = 0.0f; // Float damage (Most of the time equals to Damage)
            int32 Damage        = 0;
            int32 Absorbed      = 0;
            int32 Resisted      = 0;
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

        class AttackerStateUpdate final : public ServerPacket
        {
        public:
            AttackerStateUpdate() : ServerPacket(SMSG_ATTACKERSTATEUPDATE, 70) { }

            WorldPacket const* Write() override;

            Optional<WorldPackets::Spells::SpellCastLogData> LogData;
            uint32 HitInfo          = 0; // Flags
            ObjectGuid AttackerGUID;
            ObjectGuid VictimGUID;
            int32 Damage            = 0;
            int32 OverDamage        = -1; // (damage - health) or -1 if unit is still alive
            Optional<SubDamage> SubDmg;
            uint8 VictimState       = 0;
            int32 AttackerState     = -1;
            int32 MeleeSpellID      = 0;
            int32 BlockAmount       = 0;
            int32 RageGained        = 0;
            UnkAttackerState UnkState;
            float Unk               = 0.0f;
        };
    }
}

#endif // CombatPackets_h__
