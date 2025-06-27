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

#ifndef CombatPackets_h__
#define CombatPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"

class Unit;

namespace WorldPackets
{
    namespace Combat
    {
        class AttackSwing final : public ClientPacket
        {
        public:
            AttackSwing(WorldPacket&& packet) : ClientPacket(CMSG_ATTACK_SWING, std::move(packet)) { }

            void Read() override;

            ObjectGuid Victim;
        };

        class AttackSwingNotInRange final : public ServerPacket
        {
        public:
            AttackSwingNotInRange() : ServerPacket(SMSG_ATTACK_SWING_NOT_IN_RANGE, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AttackSwingBadFacing final : public ServerPacket
        {
        public:
            AttackSwingBadFacing() : ServerPacket(SMSG_ATTACK_SWING_BAD_FACING, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AttackSwingDeadTarget final : public ServerPacket
        {
        public:
            AttackSwingDeadTarget() : ServerPacket(SMSG_ATTACK_SWING_DEAD_TARGET, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AttackSwingCantAttack final : public ServerPacket
        {
        public:
            AttackSwingCantAttack() : ServerPacket(SMSG_ATTACK_SWING_CANT_ATTACK, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class AttackStop final : public ClientPacket
        {
        public:
            AttackStop(WorldPacket&& packet) : ClientPacket(CMSG_ATTACK_STOP, std::move(packet)) { }

            void Read() override { }
        };

        class AttackStart final : public ServerPacket
        {
        public:
            AttackStart() : ServerPacket(SMSG_ATTACK_START, 8 + 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Attacker;
            ObjectGuid Victim;
        };

        class SAttackStop final : public ServerPacket
        {
        public:
            SAttackStop() : ServerPacket(SMSG_ATTACK_STOP, 8 + 8 + 4) { }
            SAttackStop(Unit const* attacker, Unit const* victim);

            WorldPacket const* Write() override;

            PackedGuid Attacker;
            PackedGuid Victim;
            bool NowDead = false;
        };

        class CancelCombat final : public ServerPacket
        {
        public:
            CancelCombat() : ServerPacket(SMSG_CANCEL_COMBAT, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class CancelAutoRepeat final : public ServerPacket
        {
        public:
            CancelAutoRepeat() : ServerPacket(SMSG_CANCEL_AUTO_REPEAT, 8) { }

            WorldPacket const* Write() override;

            PackedGuid Guid;
        };

        class SetSheathed final : public ClientPacket
        {
        public:
            SetSheathed(WorldPacket&& packet) : ClientPacket(CMSG_SET_SHEATHED, std::move(packet)) { }

            void Read() override;

            uint32 CurrentSheathState = 0;
        };
    }
}

#endif // CombatPackets_h__
