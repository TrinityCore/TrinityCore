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

#ifndef SpellPackets_h__
#define SpellPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include "SharedDefines.h"

namespace WorldPackets
{
    namespace Spells
    {
        class CancelCast final : public ClientPacket
        {
        public:
            CancelCast(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_CAST, std::move(packet)) { }

            void Read() override;

            uint8 CastID = 0;
            uint32 SpellID = 0;
        };

        class CancelAura final : public ClientPacket
        {
        public:
            CancelAura(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_AURA, std::move(packet)) { }

            void Read() override;

            uint32 SpellID = 0;
        };

        class PetCancelAura final : public ClientPacket
        {
        public:
            PetCancelAura(WorldPacket&& packet) : ClientPacket(CMSG_PET_CANCEL_AURA, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            uint32 SpellID = 0;
        };

        class CancelGrowthAura final : public ClientPacket
        {
        public:
            CancelGrowthAura(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_GROWTH_AURA, std::move(packet)) { }

            void Read() override { }
        };

        class CancelMountAura final : public ClientPacket
        {
        public:
            CancelMountAura(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_MOUNT_AURA, std::move(packet)) { }

            void Read() override { }
        };

        class CancelAutoRepeatSpell final : public ClientPacket
        {
        public:
            CancelAutoRepeatSpell(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_AUTO_REPEAT_SPELL, std::move(packet)) { }

            void Read() override { }
        };

        class CancelChannelling final : public ClientPacket
        {
        public:
            CancelChannelling(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_CHANNELLING, std::move(packet)) { }

            void Read() override;

            uint32 ChannelSpell = 0;
        };

        struct SpellMissStatus
        {
            ObjectGuid TargetGUID;
            uint8 Reason = 0;
            uint8 ReflectStatus = 0;
        };

        struct RuneData
        {
            uint8 Start = 0;
            uint8 Count = 0;
            std::vector<uint8> Cooldowns;
        };

        struct MissileTrajectoryResult
        {
            uint32 TravelTime = 0;
            float Pitch = 0.0f;
        };

        struct SpellAmmo
        {
            uint32 DisplayID = 0;
            uint32 InventoryType = 0;
        };

        struct CreatureImmunities
        {
            uint32 School = 0;
            uint32 Value = 0;
        };

        struct TargetLocation
        {
            ObjectGuid Transport;
            Position Location;
        };

        struct SpellTargetData
        {
            uint32 Flags = 0;
            Optional<ObjectGuid> Unit;
            Optional<ObjectGuid> Item;
            Optional<TargetLocation> SrcLocation;
            Optional<TargetLocation> DstLocation;
            Optional<std::string> Name;
        };

        struct SpellCastData
        {
            ObjectGuid CasterGUID;
            ObjectGuid CasterUnit;
            uint8 CastID = 0;
            uint32 SpellID = 0;
            uint32 CastFlags = 0;
            uint32 CastTime = 0;
            mutable Optional<std::vector<ObjectGuid>> HitTargets;
            mutable Optional<std::vector<SpellMissStatus>> MissStatus;
            SpellTargetData Target;
            Optional<uint32> RemainingPower;
            Optional<RuneData> RemainingRunes;
            Optional<MissileTrajectoryResult> MissileTrajectory;
            Optional<SpellAmmo> Ammo;
            Optional<CreatureImmunities> Immunities;
        };

        class SpellGo final : public ServerPacket
        {
            public:
                SpellGo() : ServerPacket(SMSG_SPELL_GO)
                {
                    Cast.HitTargets.emplace();
                    Cast.MissStatus.emplace();
                }

                WorldPacket const* Write() override;

                SpellCastData Cast;
        };

        class SpellStart final : public ServerPacket
        {
            public:
                SpellStart() : ServerPacket(SMSG_SPELL_START) { }

                WorldPacket const* Write() override;

                SpellCastData Cast;
        };

        struct ResyncRune
        {
            uint8 RuneType = 0;
            uint8 Cooldown = 0;
        };

        class ResyncRunes final : public ServerPacket
        {
        public:
            ResyncRunes() : ServerPacket(SMSG_RESYNC_RUNES, 4 + 2 * MAX_RUNES) { }

            WorldPacket const* Write() override;

            uint32 Count = 0;
            std::vector<ResyncRune> Runes;
        };

        class MountResult final : public ServerPacket
        {
        public:
            MountResult() : ServerPacket(SMSG_MOUNT_RESULT, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };
    }
}

#endif // SpellPackets_h__
