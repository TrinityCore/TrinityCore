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

#ifndef TRINITYCORE_SPELL_PACKETS_H
#define TRINITYCORE_SPELL_PACKETS_H

#include "MovementInfo.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Packet.h"
#include "Position.h"
#include "SharedDefines.h"

namespace WorldPackets
{
    namespace Spells
    {
        class CancelAura final : public ClientPacket
        {
        public:
            CancelAura(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_AURA, std::move(packet)) { }

            void Read() override;

            uint32 SpellID = 0;
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

        class PetCancelAura final : public ClientPacket
        {
        public:
            PetCancelAura(WorldPacket&& packet) : ClientPacket(CMSG_PET_CANCEL_AURA, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            uint32 SpellID = 0;
        };

        struct InitialSpell
        {
            uint32 SpellID = 0;
            uint16 ActionBarSlot = 0; // unused on client
        };

        struct SpellHistoryEntry
        {
            uint32 SpellID = 0;
            uint16 ItemID = 0;
            uint16 Category = 0;
            int32 RecoveryTime = 0;
            int32 CategoryRecoveryTime = 0;
            bool OnHold = false;
        };

        class InitialSpells final : public ServerPacket
        {
        public:
            explicit InitialSpells() : ServerPacket(SMSG_INITIAL_SPELLS, 1 + 2 + 2) { }

            WorldPacket const* Write() override;

            bool InitialLogin = false;
            std::vector<InitialSpell> Spells;
            std::vector<SpellHistoryEntry> SpellHistory;
        };

        class UpdateActionButtons final : public ServerPacket
        {
        public:
            static std::size_t constexpr NumActionButtons = 144;

            explicit UpdateActionButtons() : ServerPacket(SMSG_ACTION_BUTTONS, NumActionButtons * 4 + 1) { }

            WorldPacket const* Write() override;

            std::array<uint32, NumActionButtons> ActionButtons = { };
            uint8 Reason = 0;
            /*
                Reason can be 0, 1, 2
                0 - Sends initial action buttons, client does not validate if we have the spell or not
                1 - Used used after spec swaps, client validates if a spell is known.
                2 - Clears the action bars client sided. This is sent during spec swap before unlearning and before sending the new buttons
            */
        };

        class SendUnlearnSpells final : public ServerPacket
        {
        public:
            explicit SendUnlearnSpells() : ServerPacket(SMSG_SEND_UNLEARN_SPELLS, 4) { }

            WorldPacket const* Write() override;

            std::vector<uint32> Spells;
        };

        struct AuraDataInfo
        {
            int32 SpellID = 0;
            uint8 Flags = 0;
            uint8 CastLevel = 1;
            uint8 Applications = 1;
            ObjectGuid CastUnit;
            int32 Duration = 0;
            int32 Remaining = 0;
        };

        struct AuraInfo
        {
            uint8 Slot = 0;
            Optional<AuraDataInfo> AuraData;
        };

        class AuraUpdate final : public ServerPacket
        {
        public:
            explicit AuraUpdate() : ServerPacket(SMSG_AURA_UPDATE) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            AuraInfo Aura;
        };

        class AuraUpdateAll final : public ServerPacket
        {
        public:
            explicit AuraUpdateAll() : ServerPacket(SMSG_AURA_UPDATE_ALL) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            std::vector<AuraInfo> Auras;
        };

        struct TargetLocation
        {
            ObjectGuid Transport;
            TaggedPosition<Position::XYZ> Location;
        };

        struct SpellTargetData
        {
            uint32 Flags = 0;
            Optional<ObjectGuid> Unit;
            Optional<ObjectGuid> Item;
            Optional<TargetLocation> SrcLocation;
            Optional<TargetLocation> DstLocation;
            Optional<std::array<char, 128>> Name;
        };

        struct MissileTrajectoryRequest
        {
            float Pitch = 0.0f;
            float Speed = 0.0f;
            Optional<MovementInfo> MoveUpdate;
        };

        struct SpellCastRequest
        {
            uint8 CastID = 0;
            int32 SpellID = 0;
            uint8 SendCastFlags = 0;
            SpellTargetData Target;
            Optional<MissileTrajectoryRequest> MissileTrajectory;
        };

        class CastSpell final : public ClientPacket
        {
        public:
            explicit CastSpell(WorldPacket&& packet) : ClientPacket(CMSG_CAST_SPELL, std::move(packet)) { }

            void Read() override;

            SpellCastRequest Cast;
        };

        class PetCastSpell final : public ClientPacket
        {
        public:
            explicit PetCastSpell(WorldPacket&& packet) : ClientPacket(CMSG_PET_CAST_SPELL, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            SpellCastRequest Cast;
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

        struct SpellCastData
        {
            ObjectGuid CasterGUID;
            ObjectGuid CasterUnit;
            uint8 CastID = 0;
            uint32 SpellID = 0;
            uint32 CastFlags = 0;
            uint32 CastTime = 0;
            Optional<std::vector<ObjectGuid>> HitTargets;
            Optional<std::vector<SpellMissStatus>> MissStatus;
            SpellTargetData Target;
            Optional<uint32> RemainingPower;
            Optional<RuneData> RemainingRunes;
            Optional<MissileTrajectoryResult> MissileTrajectory;
            Optional<SpellAmmo> Ammo;
            Optional<uint8> DestLocSpellCastIndex;
            Optional<std::vector<TargetLocation>> TargetPoints;
            Optional<CreatureImmunities> Immunities;
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
            SpellGo() : ServerPacket(SMSG_SPELL_GO)
            {
                Cast.HitTargets.emplace();
                Cast.MissStatus.emplace();
            }

            WorldPacket const* Write() override;

            SpellCastData Cast;
        };

        class PlaySpellVisualKit final : public ServerPacket
        {
        public:
            PlaySpellVisualKit(int32 kitType) : ServerPacket(kitType ? SMSG_PLAY_SPELL_IMPACT : SMSG_PLAY_SPELL_VISUAL, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            int32 KitRecID = 0;
        };

        class CancelCast final : public ClientPacket
        {
        public:
            CancelCast(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_CAST, std::move(packet)) { }

            void Read() override;

            uint8 CastID = 0;
            uint32 SpellID = 0;
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

#endif // TRINITYCORE_SPELL_PACKETS_H
