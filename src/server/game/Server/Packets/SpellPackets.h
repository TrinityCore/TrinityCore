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

#include <array>

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellMissStatus
        {
            SpellMissStatus() { }
            SpellMissStatus(ObjectGuid missTarget, uint8 reason, uint8 reflectStatus) : MissTarget(missTarget), Reason(reason), ReflectStatus(reflectStatus) { }

            ObjectGuid MissTarget;
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

        struct ProjectileVisual
        {
            std::array<int32, 2> Id = { };
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

        struct SpellHealPrediction
        {
            Optional<ObjectGuid> BeaconGUID;
            uint32 Points = 0;
            uint8 Type = 0;
        };

        struct SpellHitInfo
        {
            std::vector<ObjectGuid> HitTargets;
            std::vector<SpellMissStatus> MissStatus;
        };

        struct SpellCastData
        {
            ObjectGuid CasterGUID;
            ObjectGuid CasterUnit;
            uint8 CastID = 0;
            uint32 SpellID = 0;
            uint32 CastFlags = 0;
            uint32 CastFlagsEx = 0;
            uint32 CastTime = 0;
            SpellTargetData Target;
            Optional<SpellHitInfo> HitInfo;
            Optional<uint8> DestLocSpellCastIndex;
            Optional<SpellHealPrediction> Predict;
            Optional<CreatureImmunities> Immunities;
            Optional<SpellAmmo> Ammo;
            Optional<MissileTrajectoryResult> MissileTrajectory;
            Optional<uint32> RemainingPower;
            Optional<RuneData> RemainingRunes;
            Optional<ProjectileVisual> ProjectileVisuals;
        };

        class SpellStart final : public ServerPacket
        {
        public:
            SpellStart() : ServerPacket(SMSG_SPELL_START) { }

            WorldPacket const* Write() override;

            SpellCastData Cast;
        };

        class SpellGo final : public ServerPacket
        {
        public:
            SpellGo() : ServerPacket(SMSG_SPELL_GO) { }

            WorldPacket const* Write() override;

            SpellCastData Cast;
        };

        struct ChannelStartInterruptImmunities
        {
            int32 SchoolImmunities = 0;
            int32 Immunities = 0;
        };

        struct TargetedHealPrediction
        {
            TargetedHealPrediction() { }
            TargetedHealPrediction(ObjectGuid targetGuid, SpellHealPrediction prediction) : TargetGUID(targetGuid), Predict(prediction) { }

            ObjectGuid TargetGUID;
            SpellHealPrediction Predict;
        };

        class ChannelStart final : public ServerPacket
        {
        public:
            ChannelStart() : ServerPacket(OpcodeServer(MSG_CHANNEL_START)) { }

            WorldPacket const* Write() override;

            Optional<TargetedHealPrediction> HealPrediction;
            Optional<ChannelStartInterruptImmunities> InterruptImmunities;
            ObjectGuid CasterGUID;
            int32 SpellID = 0;
            uint32 ChannelDuration = 0;
        };

        class MountResult final : public ServerPacket
        {
        public:
            MountResult() : ServerPacket(SMSG_MOUNT_RESULT, 4) { }

            WorldPacket const* Write() override;

            uint32 Result = 0;
        };

        struct AuraDataInfo
        {
            int32 SpellID = 0;
            int16 Flags = 0;
            uint8 CastLevel = 0;
            uint8 Applications = 0;
            Optional<ObjectGuid> CastUnit;
            Optional<int32> Duration;
            Optional<int32> Remaining;
            std::array<Optional<int32>, 3 /*MAX_SPELL_EFFECTS*/> Points;
        };

        struct AuraInfo
        {
            uint8 Slot = 0;
            AuraDataInfo AuraData;
        };

        class AuraUpdate final : public ServerPacket
        {
        public:
            AuraUpdate() : ServerPacket(SMSG_AURA_UPDATE) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<AuraInfo> Auras;
        };

        class AuraUpdateAll final : public ServerPacket
        {
        public:
            AuraUpdateAll() : ServerPacket(SMSG_AURA_UPDATE_ALL) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<AuraInfo> Auras;
        };

        class MissileCancel final : public ServerPacket
        {
        public:
            MissileCancel() : ServerPacket(SMSG_MISSILE_CANCEL, 13) { }

            WorldPacket const* Write() override;

            ObjectGuid OwnerGUID;
            bool Reverse = false;
            int32 SpellID = 0;
        };
    }
}

#endif
