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

#ifndef SpellPackets_h__
#define SpellPackets_h__

#include "Packet.h"
#include "Player.h"
#include "SpellAuras.h"
#include "Spell.h"

namespace WorldPackets
{
    namespace Spells
    {
        class CancelAura final : public ClientPacket
        {
        public:
            CancelAura(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_AURA, std::move(packet)) { }

            void Read() override;

            ObjectGuid CasterGUID;
            int32 SpellID = 0;
        };

        class CategoryCooldown final : public ServerPacket
        {
        public:
            struct CategoryCooldownInfo
            {
                CategoryCooldownInfo(uint32 category, int32 cooldown)
                    : Category(category), ModCooldown(cooldown) { }

                uint32 Category   = 0; ///< SpellCategory Id
                int32 ModCooldown = 0; ///< Reduced Cooldown in ms
            };

            CategoryCooldown() : ServerPacket(SMSG_SPELL_CATEGORY_COOLDOWN, 4) { }

            WorldPacket const* Write() override;

            std::vector<CategoryCooldownInfo> CategoryCooldowns;
        };

        class SendKnownSpells final : public ServerPacket
        {
        public:
            SendKnownSpells() : ServerPacket(SMSG_INITIAL_SPELLS, 5) { }

            WorldPacket const* Write() override;

            bool InitialLogin = false;
            std::vector<uint32> KnownSpells;
        };

        class UpdateActionButtons final : public ServerPacket
        {
        public:
            UpdateActionButtons() : ServerPacket(SMSG_ACTION_BUTTONS, MAX_ACTION_BUTTONS * 8 + 1)
            {
                std::memset(ActionButtons, 0, sizeof(ActionButtons));
            }

            WorldPacket const* Write() override;

            uint64 ActionButtons[MAX_ACTION_BUTTONS];
            uint8 Reason = 0;
            /*
                Reason can be 0, 1, 2
                0 - Sends initial action buttons, client does not validate if we have the spell or not
                1 - Used used after spec swaps, client validates if a spell is known.
                2 - Clears the action bars client sided. This is sent during spec swap before unlearning and before sending the new buttons
            */
        };

        class SetActionButton final : public ClientPacket
        {
        public:
            SetActionButton(WorldPacket&& packet) : ClientPacket(CMSG_SET_ACTION_BUTTON, std::move(packet)) {}

            void Read() override;

            uint64 Action = 0; ///< two packed uint32 (action and type)
            uint8 Index = 0;
        };

        class SendUnlearnSpells final : public ServerPacket
        {
        public:
            SendUnlearnSpells() : ServerPacket(SMSG_SEND_UNLEARN_SPELLS, 4) { }

            WorldPacket const* Write() override;

            std::vector<uint32> Spells;
        };

        struct SpellLogPowerData
        {
            int32 PowerType = 0;
            int32 Amount    = 0;
        };

        struct SpellCastLogData
        {
            int32 Health        = 0;
            int32 AttackPower   = 0;
            int32 SpellPower    = 0;
            std::vector<SpellLogPowerData> PowerData;
        };

        struct AuraDataInfo
        {
            int32 SpellID = 0;
            uint8 Flags = 0;
            uint32 ActiveFlags = 0;
            uint16 CastLevel = 1;
            uint8 Applications = 1;
            Optional<ObjectGuid> CastUnit;
            Optional<int32> Duration;
            Optional<int32> Remaining;
            std::vector<float> Points;
            std::vector<float> EstimatedPoints;
        };

        struct AuraInfo
        {
            uint8 Slot = 0;
            Optional<AuraDataInfo> AuraData;
        };

        class AuraUpdate final : public ServerPacket
        {
        public:
            AuraUpdate() : ServerPacket(SMSG_AURA_UPDATE) { }

            WorldPacket const* Write() override;

            bool UpdateAll = false;
            ObjectGuid UnitGUID;
            std::vector<AuraInfo> Auras;
        };

        struct TargetLocation
        {
            ObjectGuid Transport;
            Position Location;
        };

        struct SpellTargetData
        {
            uint32 Flags = 0;
            ObjectGuid Unit;
            ObjectGuid Item;
            Optional<TargetLocation> SrcLocation;
            Optional<TargetLocation> DstLocation;
            Optional<float> Orientation;
            std::string Name;
        };

        struct MissileTrajectoryRequest
        {
            float Pitch = 0.0f;
            float Speed = 0.0f;
        };

        struct SpellWeight
        {
            uint32 Type = 0;
            int32 ID = 0;
            uint32 Quantity = 0;
        };

        struct SpellCastRequest
        {
            uint8 CastID = 0;
            int32 SpellID = 0;
            int32 Misc = 0;
            uint8 SendCastFlags = 0;
            SpellTargetData Target;
            MissileTrajectoryRequest MissileTrajectory;
            Optional<MovementInfo> MoveUpdate;
            std::vector<SpellWeight> Weight;
            ObjectGuid Charmer;
        };

        class CastSpell final : public ClientPacket
        {
        public:
            CastSpell(WorldPacket&& packet) : ClientPacket(CMSG_CAST_SPELL, std::move(packet)) { }

            void Read() override;

            SpellCastRequest Cast;
        };

        class PetCastSpell final : public ClientPacket
        {
        public:
            PetCastSpell(WorldPacket&& packet) : ClientPacket(CMSG_PET_CAST_SPELL, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            SpellCastRequest Cast;
        };

        class UseItem final : public ClientPacket
        {
        public:
            UseItem(WorldPacket&& packet) : ClientPacket(CMSG_USE_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 PackSlot = 0;
            uint8 Slot = 0;
            ObjectGuid CastItem;
            SpellCastRequest Cast;
        };

        struct SpellMissStatus
        {
            uint8 Reason = 0;
            uint8 ReflectStatus = 0;
        };

        struct SpellPowerData
        {
            int32 Cost = 0;
            int8 Type = 0;
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
            int32 DisplayID = 0;
            int8 InventoryType = 0;
        };

        struct ProjectileVisualData
        {
            int32 ID[2];
        };

        struct CreatureImmunities
        {
            uint32 School = 0;
            uint32 Value = 0;
        };

        struct SpellHealPrediction
        {
            ObjectGuid BeaconGUID;
            uint32 Points = 0;
            uint8 Type = 0;
        };

        struct SpellCastData
        {
            ObjectGuid CasterGUID;
            ObjectGuid CasterUnit;
            uint8 CastID        = 0;
            int32 SpellID       = 0;
            uint32 CastFlags    = 0;
            uint32 CastFlagsEx  = 0;
            uint32 CastTime     = 0;
            std::vector<ObjectGuid> HitTargets;
            std::vector<ObjectGuid> MissTargets;
            std::vector<SpellMissStatus> MissStatus;
            SpellTargetData Target;
            std::vector<SpellPowerData> RemainingPower;
            Optional<RuneData> RemainingRunes;
            MissileTrajectoryResult MissileTrajectory;
            SpellAmmo Ammo;
            Optional<ProjectileVisualData> ProjectileVisual;
            uint8 DestLocSpellCastIndex = 0;
            std::vector<TargetLocation> TargetPoints;
            CreatureImmunities Immunities;
            SpellHealPrediction Predict;
        };

        class SpellGo final : public ServerPacket
        {
        public:
            SpellGo() : ServerPacket(SMSG_SPELL_GO) { }

            WorldPacket const* Write() override;

            Optional<SpellCastLogData> LogData;
            SpellCastData Cast;
        };

        class SpellStart final : public ServerPacket
        {
        public:
            SpellStart() : ServerPacket(SMSG_SPELL_START) { }

            WorldPacket const* Write() override;

            SpellCastData Cast;
        };

        class LearnedSpells final : public ServerPacket
        {
        public:
            LearnedSpells() : ServerPacket(SMSG_LEARNED_SPELLS, 9) { }

            WorldPacket const* Write() override;

            std::vector<int32> SpellID;
            bool SuppressMessaging = false;
        };

        class SpellFailure final : public ServerPacket
        {
        public:
            SpellFailure() : ServerPacket(SMSG_SPELL_FAILURE, 16+4+1+1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterUnit;
            uint32 SpellID  = 0;
            uint8 Reason    = 0;
            uint8 CastID    = 0;
        };

        class SpellFailedOther final : public ServerPacket
        {
        public:
            SpellFailedOther() : ServerPacket(SMSG_SPELL_FAILED_OTHER, 16+4+1+1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterUnit;
            uint32 SpellID  = 0;
            uint16 Reason   = 0;
            uint8 CastID    = 0;
        };

        class CastFailed final : public ServerPacket
        {
        public:
            CastFailed(OpcodeServer opcode) : ServerPacket(opcode, 4+4+4+4+1) { }

            WorldPacket const* Write() override;

            int32 Reason        = 0;
            int32 FailedArg1    = -1;
            int32 FailedArg2    = -1;
            int32 SpellID       = 0;
            uint8 CastID        = 0;
        };

        struct SpellModifierData
        {
            float ModifierValue = 0.0f;
            uint8 ClassIndex = 0;
        };

        struct SpellModifier
        {
            uint8 ModIndex = 0;
            std::vector<SpellModifierData> ModifierData;
        };

        class SetSpellModifier final : public ServerPacket
        {
        public:
            SetSpellModifier(OpcodeServer opcode) : ServerPacket(opcode, 20) { }

            WorldPacket const* Write() override;

            std::vector<SpellModifier> Modifiers;
        };

        class UnlearnedSpells final : public ServerPacket
        {
        public:
            UnlearnedSpells() : ServerPacket(SMSG_UNLEARNED_SPELLS, 4) { }

            WorldPacket const* Write() override;

            std::vector<uint32> SpellID;
        };

        class CooldownEvent final : public ServerPacket
        {
        public:
            CooldownEvent() : ServerPacket(SMSG_COOLDOWN_EVENT, 16 + 4) { }
            CooldownEvent(ObjectGuid casterGuid, int32 spellId) : ServerPacket(SMSG_COOLDOWN_EVENT, 16 + 4), CasterGUID(casterGuid), SpellID(spellId) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            int32 SpellID;
        };

        class ClearCooldowns final : public ServerPacket
        {
        public:
            ClearCooldowns() : ServerPacket(SMSG_CLEAR_COOLDOWNS, 4 + 16) { }

            WorldPacket const* Write() override;

            std::vector<int32> SpellID;
            ObjectGuid Guid;
        };

        class ClearCooldown final : public ServerPacket
        {
        public:
            ClearCooldown() : ServerPacket(SMSG_CLEAR_COOLDOWN, 16 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            int32 SpellID = 0;
            bool ClearOnHold = false;
        };

        class ModifyCooldown final : public ServerPacket
        {
        public:
            ModifyCooldown() : ServerPacket(SMSG_MODIFY_COOLDOWN, 16 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            int32 DeltaTime = 0;
            int32 SpellID = 0;
        };

        struct SpellCooldownStruct
        {
            SpellCooldownStruct() { }
            SpellCooldownStruct(uint32 spellId, uint32 forcedCooldown) : SrecID(spellId), ForcedCooldown(forcedCooldown) { }

            uint32 SrecID = 0;
            uint32 ForcedCooldown = 0;
        };

        class SpellCooldown : public ServerPacket
        {
        public:
            SpellCooldown() : ServerPacket(SMSG_SPELL_COOLDOWN, 4 + 16 + 1) { }

            WorldPacket const* Write() override;

            std::vector<SpellCooldownStruct> SpellCooldowns;
            ObjectGuid Caster;
            uint8 Flags = 0;
        };

        struct SpellHistoryEntry
        {
            uint32 SpellID = 0;
            uint32 ItemID = 0;
            uint32 Category = 0;
            int32 RecoveryTime = 0;
            int32 CategoryRecoveryTime = 0;
            bool OnHold = false;
        };

        class SendSpellHistory final : public ServerPacket
        {
        public:
            SendSpellHistory() : ServerPacket(SMSG_SEND_SPELL_HISTORY, 4) { }

            WorldPacket const* Write() override;

            std::vector<SpellHistoryEntry> Entries;
        };

        class ClearAllSpellCharges final : public ServerPacket
        {
        public:
            ClearAllSpellCharges() : ServerPacket(SMSG_CLEAR_ALL_SPELL_CHARGES, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
        };

        class ClearSpellCharges final : public ServerPacket
        {
        public:
            ClearSpellCharges() : ServerPacket(SMSG_CLEAR_SPELL_CHARGES, 20) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            int32 Category = 0;
        };

        class SetSpellCharges final : public ServerPacket
        {
        public:
            SetSpellCharges() : ServerPacket(SMSG_SET_SPELL_CHARGES, 1 + 4 + 4) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
            float Count = 0.0f;
            int32 Category = 0;
        };

        struct SpellChargeEntry
        {
            uint32 Category = 0;
            uint32 NextRecoveryTime = 0;
            uint8 ConsumedCharges = 0;
        };

        class SendSpellCharges final : public ServerPacket
        {
        public:
            SendSpellCharges() : ServerPacket(SMSG_SEND_SPELL_CHARGES, 4) { }

            WorldPacket const* Write() override;

            std::vector<SpellChargeEntry> Entries;
        };

        class ClearTarget final : public ServerPacket
        {
        public:
            ClearTarget() : ServerPacket(SMSG_CLEAR_TARGET, 8) { }

            WorldPacket const* Write() override;

            ObjectGuid Guid;
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastLogData const& spellCastLogData);

#endif // SpellPackets_h__
