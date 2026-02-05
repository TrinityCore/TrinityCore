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

#ifndef TRINITYCORE_COMBAT_PACKETS_H
#define TRINITYCORE_COMBAT_PACKETS_H

#include "Packet.h"
#include "ObjectGuid.h"
#include "UnitDefines.h"

class Unit;
enum Powers : int8;

namespace WorldPackets
{
    namespace Combat
    {
        class AttackSwing final : public ClientPacket
        {
        public:
            explicit AttackSwing(WorldPacket&& packet) : ClientPacket(CMSG_ATTACK_SWING, std::move(packet)) { }

            void Read() override;

            ObjectGuid Victim;
        };

        class AttackSwingError final : public ServerPacket
        {
        public:
            explicit AttackSwingError() : ServerPacket(SMSG_ATTACK_SWING_ERROR, 4) { }
            explicit AttackSwingError(AttackSwingErr reason) : ServerPacket(SMSG_ATTACK_SWING_ERROR, 4), Reason(reason) { }

            WorldPacket const* Write() override;

            AttackSwingErr Reason = AttackSwingErr::CantAttack;
        };

        class AttackStop final : public ClientPacket
        {
        public:
            explicit AttackStop(WorldPacket&& packet) : ClientPacket(CMSG_ATTACK_STOP, std::move(packet)) { }

            void Read() override { }
        };

        class AttackStart final : public ServerPacket
        {
        public:
            explicit AttackStart() : ServerPacket(SMSG_ATTACK_START, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
        };

        class SAttackStop final : public ServerPacket
        {
        public:
            explicit SAttackStop() : ServerPacket(SMSG_ATTACK_STOP, 16 + 16 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
            bool NowDead = false;
        };

        struct ThreatInfo
        {
            ObjectGuid UnitGUID;
            int64 Threat = 0;
        };

        class ThreatUpdate final : public ServerPacket
        {
        public:
            explicit ThreatUpdate() : ServerPacket(SMSG_THREAT_UPDATE, 24) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
        };

        class HighestThreatUpdate final : public ServerPacket
        {
        public:
            explicit HighestThreatUpdate() : ServerPacket(SMSG_HIGHEST_THREAT_UPDATE, 44) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<ThreatInfo> ThreatList;
            ObjectGuid HighestThreatGUID;
        };

        class ThreatRemove final : public ServerPacket
        {
        public:
            explicit ThreatRemove() : ServerPacket(SMSG_THREAT_REMOVE, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid AboutGUID; // Unit to remove threat from (e.g. player, pet, guardian)
            ObjectGuid UnitGUID; // Unit being attacked (e.g. creature, boss)
        };

        class AIReaction final : public ServerPacket
        {
        public:
            explicit AIReaction() : ServerPacket(SMSG_AI_REACTION, 12) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            uint32 Reaction = 0;
        };

        class CancelCombat final : public ServerPacket
        {
        public:
            explicit CancelCombat() : ServerPacket(SMSG_CANCEL_COMBAT, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        struct PowerUpdatePower
        {
            PowerUpdatePower(int32 power, uint8 powerType) : Power(power), PowerType(powerType) { }

            int32 Power = 0;
            uint8 PowerType = 0;
        };

        class PowerUpdate final : public ServerPacket
        {
        public:
            explicit PowerUpdate() : ServerPacket(SMSG_POWER_UPDATE, 16 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            std::vector<PowerUpdatePower> Powers;
        };

        class InterruptPowerRegen final : public ServerPacket
        {
        public:
            explicit InterruptPowerRegen(Powers powerType) : ServerPacket(SMSG_INTERRUPT_POWER_REGEN, 1), PowerType(powerType) { }

            WorldPacket const* Write() override;

            Powers PowerType;
        };

        class SetSheathed final : public ClientPacket
        {
        public:
            explicit SetSheathed(WorldPacket&& packet) : ClientPacket(CMSG_SET_SHEATHED, std::move(packet)) { }

            void Read() override;

            int32 CurrentSheathState = 0;
            bool Animate = true;
        };

        class CancelAutoRepeat final : public ServerPacket
        {
        public:
            explicit CancelAutoRepeat() : ServerPacket(SMSG_CANCEL_AUTO_REPEAT, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };

        class HealthUpdate final : public ServerPacket
        {
        public:
            explicit HealthUpdate() : ServerPacket(SMSG_HEALTH_UPDATE, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
            int64 Health = 0;
        };

        class ThreatClear final : public ServerPacket
        {
        public:
            explicit ThreatClear() : ServerPacket(SMSG_THREAT_CLEAR, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
        };

        class PvPCredit final : public ServerPacket
        {
        public:
            explicit PvPCredit() : ServerPacket(SMSG_PVP_CREDIT, 4 + 16 + 4) { }

            WorldPacket const* Write() override;

            int32 OriginalHonor = 0;
            int32 Honor = 0;
            ObjectGuid Target;
            int8 Rank = 0;
        };

        class BreakTarget final : public ServerPacket
        {
        public:
            explicit BreakTarget() : ServerPacket(SMSG_BREAK_TARGET, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
        };
    }
}

#endif // TRINITYCORE_COMBAT_PACKETS_H
