/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "CombatLogPacketsCommon.h"
#include "MovementInfo.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "Position.h"
#include "SharedDefines.h"
#include <array>

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

            int32 ChannelSpell = 0;
            int32 Reason = 0;       // 40 = /run SpellStopCasting(), 16 = movement/AURA_INTERRUPT_FLAG_MOVE, 41 = turning/AURA_INTERRUPT_FLAG_TURNING
                                    // does not match SpellCastResult enum
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

        class RequestCategoryCooldowns final : public ClientPacket
        {
        public:
            RequestCategoryCooldowns(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_CATEGORY_COOLDOWNS, std::move(packet)) { }

            void Read() override { }
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

            CategoryCooldown() : ServerPacket(SMSG_CATEGORY_COOLDOWN, 4) { }

            WorldPacket const* Write() override;

            std::vector<CategoryCooldownInfo> CategoryCooldowns;
        };

        class SendKnownSpells final : public ServerPacket
        {
        public:
            SendKnownSpells() : ServerPacket(SMSG_SEND_KNOWN_SPELLS, 5) { }

            WorldPacket const* Write() override;

            bool InitialLogin = false;
            std::vector<uint32> KnownSpells;
            std::vector<uint32> FavoriteSpells;         // tradeskill recipes
        };

        class UpdateActionButtons final : public ServerPacket
        {
        public:
            static std::size_t constexpr NumActionButtons = 132;

            UpdateActionButtons() : ServerPacket(SMSG_UPDATE_ACTION_BUTTONS, NumActionButtons * 8 + 1)
            {
                ActionButtons.fill(0);
            }

            WorldPacket const* Write() override;

            std::array<uint64, NumActionButtons> ActionButtons;
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

        struct AuraDataInfo
        {
            ObjectGuid CastID;
            int32 SpellID = 0;
            int32 SpellXSpellVisualID = 0;
            uint8 Flags = 0;
            uint32 ActiveFlags = 0;
            uint16 CastLevel = 1;
            uint8 Applications = 1;
            int32 ContentTuningID = 0;
            Optional<ContentTuningParams> ContentTuning;
            Optional<ObjectGuid> CastUnit;
            Optional<int32> Duration;
            Optional<int32> Remaining;
            Optional<float> TimeMod;
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
            Optional<int32> MapID;
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
            ObjectGuid CastID;
            int32 SpellID = 0;
            uint32 SpellXSpellVisualID = 0;
            uint8 SendCastFlags = 0;
            SpellTargetData Target;
            MissileTrajectoryRequest MissileTrajectory;
            Optional<MovementInfo> MoveUpdate;
            std::vector<SpellWeight> Weight;
            ObjectGuid CraftingNPC;
            int32 Misc[2] = { };
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

        class SpellPrepare final : public ServerPacket
        {
        public:
            SpellPrepare() : ServerPacket(SMSG_SPELL_PREPARE, 16 + 16) { }

            WorldPacket const* Write() override;

            ObjectGuid ClientCastID;
            ObjectGuid ServerCastID;
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
            ObjectGuid CastID;
            ObjectGuid OriginalCastID;
            int32 SpellID       = 0;
            uint32 SpellXSpellVisualID = 0;
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
            uint8 DestLocSpellCastIndex = 0;
            std::vector<TargetLocation> TargetPoints;
            CreatureImmunities Immunities;
            SpellHealPrediction Predict;
        };

        class SpellGo final : public CombatLog::CombatLogServerPacket
        {
        public:
            SpellGo() : CombatLog::CombatLogServerPacket(SMSG_SPELL_GO) { }

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

        class LearnedSpells final : public ServerPacket
        {
        public:
            LearnedSpells() : ServerPacket(SMSG_LEARNED_SPELLS, 9) { }

            WorldPacket const* Write() override;

            std::vector<int32> SpellID;
            std::vector<int32> FavoriteSpellID;
            bool SuppressMessaging = false;
        };

        class SupercededSpells final : public ServerPacket
        {
        public:
            SupercededSpells() : ServerPacket(SMSG_SUPERCEDED_SPELLS, 4 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            std::vector<int32> SpellID;
            std::vector<int32> Superceded;
            std::vector<int32> FavoriteSpellID;
        };

        class SpellFailure final : public ServerPacket
        {
        public:
            SpellFailure() : ServerPacket(SMSG_SPELL_FAILURE, 16+4+2+1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterUnit;
            uint32 SpellID  = 0;
            uint32 SpellXSpellVisualID = 0;
            uint16 Reason   = 0;
            ObjectGuid CastID;
        };

        class SpellFailedOther final : public ServerPacket
        {
        public:
            SpellFailedOther() : ServerPacket(SMSG_SPELL_FAILED_OTHER, 16+4+1+1) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterUnit;
            uint32 SpellID  = 0;
            uint32 SpellXSpellVisualID = 0;
            uint8 Reason    = 0;
            ObjectGuid CastID;
        };

        class TC_GAME_API CastFailed final : public ServerPacket
        {
        public:
            CastFailed() : ServerPacket(SMSG_CAST_FAILED, 4 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid CastID;
            int32 SpellID             = 0;
            int32 SpellXSpellVisualID = 0;
            int32 Reason              = 0;
            int32 FailedArg1          = -1;
            int32 FailedArg2          = -1;
        };

        class TC_GAME_API PetCastFailed final : public ServerPacket
        {
        public:
            PetCastFailed() : ServerPacket(SMSG_PET_CAST_FAILED, 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid CastID;
            int32 SpellID = 0;
            int32 Reason = 0;
            int32 FailedArg1 = -1;
            int32 FailedArg2 = -1;
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

        class TC_GAME_API SetSpellModifier final : public ServerPacket
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
            bool SuppressMessaging = false;
        };

        class CooldownEvent final : public ServerPacket
        {
        public:
            CooldownEvent() : ServerPacket(SMSG_COOLDOWN_EVENT, 1 + 4) { }
            CooldownEvent(bool isPet, int32 spellId) : ServerPacket(SMSG_COOLDOWN_EVENT, 16 + 4), IsPet(isPet), SpellID(spellId) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
            int32 SpellID;
        };

        class ClearCooldowns final : public ServerPacket
        {
        public:
            ClearCooldowns() : ServerPacket(SMSG_CLEAR_COOLDOWNS, 4 + 1) { }

            WorldPacket const* Write() override;

            std::vector<int32> SpellID;
            bool IsPet = false;
        };

        class ClearCooldown final : public ServerPacket
        {
        public:
            ClearCooldown() : ServerPacket(SMSG_CLEAR_COOLDOWN, 1 + 4 + 1) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
            int32 SpellID = 0;
            bool ClearOnHold = false;
        };

        class ModifyCooldown final : public ServerPacket
        {
        public:
            ModifyCooldown() : ServerPacket(SMSG_MODIFY_COOLDOWN, 1 + 4 + 4) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
            int32 DeltaTime = 0;
            int32 SpellID = 0;
        };

        struct SpellCooldownStruct
        {
            SpellCooldownStruct() { }
            SpellCooldownStruct(uint32 spellId, uint32 forcedCooldown) : SrecID(spellId), ForcedCooldown(forcedCooldown) { }

            uint32 SrecID = 0;
            uint32 ForcedCooldown = 0;
            float ModRate = 1.0f;
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
            float ModRate = 1.0f;
            bool OnHold = false;
            Optional<uint32> unused622_1;   ///< This field is not used for anything in the client in 6.2.2.20444
            Optional<uint32> unused622_2;   ///< This field is not used for anything in the client in 6.2.2.20444
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
            ClearAllSpellCharges() : ServerPacket(SMSG_CLEAR_ALL_SPELL_CHARGES, 1) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
        };

        class ClearSpellCharges final : public ServerPacket
        {
        public:
            ClearSpellCharges() : ServerPacket(SMSG_CLEAR_SPELL_CHARGES, 1 + 4) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
            int32 Category = 0;
        };

        class SetSpellCharges final : public ServerPacket
        {
        public:
            SetSpellCharges() : ServerPacket(SMSG_SET_SPELL_CHARGES, 4 + 4 + 1 + 4 + 1) { }

            WorldPacket const* Write() override;

            bool IsPet = false;
            uint32 Category = 0;
            uint32 NextRecoveryTime = 0;
            uint8 ConsumedCharges = 0;
            float ChargeModRate = 1.0f;
        };

        struct SpellChargeEntry
        {
            uint32 Category = 0;
            uint32 NextRecoveryTime = 0;
            float ChargeModRate = 1.0f;
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

        class CancelOrphanSpellVisual final : public ServerPacket
        {
        public:
            CancelOrphanSpellVisual() : ServerPacket(SMSG_CANCEL_ORPHAN_SPELL_VISUAL, 4) { }

            WorldPacket const* Write() override;

            int32 SpellVisualID = 0;
        };

        class CancelSpellVisual final : public ServerPacket
        {
        public:
            CancelSpellVisual() : ServerPacket(SMSG_CANCEL_SPELL_VISUAL, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Source;
            int32 SpellVisualID = 0;
        };

        class CancelSpellVisualKit final : public ServerPacket
        {
        public:
            CancelSpellVisualKit() : ServerPacket(SMSG_CANCEL_SPELL_VISUAL_KIT, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Source;
            int32 SpellVisualKitID = 0;
        };

        class PlayOrphanSpellVisual final : public ServerPacket
        {
        public:
            PlayOrphanSpellVisual() : ServerPacket(SMSG_PLAY_ORPHAN_SPELL_VISUAL, 16 + 3 * 4 + 4 + 1 + 4 + 3 * 4 + 3 * 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Target; // Exclusive with TargetLocation
            TaggedPosition<Position::XYZ> SourceLocation;
            int32 SpellVisualID = 0;
            bool SpeedAsTime = false;
            float TravelSpeed = 0.0f;
            float UnkZero = 0.0f; // Always zero
            float Unk801 = 0.0f;
            TaggedPosition<Position::XYZ> SourceRotation; // Vector of rotations, Orientation is z
            TaggedPosition<Position::XYZ> TargetLocation; // Exclusive with Target
        };

        class PlaySpellVisual final : public ServerPacket
        {
        public:
            PlaySpellVisual() : ServerPacket(SMSG_PLAY_SPELL_VISUAL, 16 + 16 + 2 + 4 + 1 + 2 + 4 + 4 * 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Source;
            ObjectGuid Target; // Exclusive with TargetPosition
            ObjectGuid Unk801_1;
            uint16 MissReason = 0;
            uint32 SpellVisualID = 0;
            bool SpeedAsTime = false;
            uint16 ReflectStatus = 0;
            float TravelSpeed = 0.0f;
            TaggedPosition<Position::XYZ> TargetPosition; // Exclusive with Target
            float Orientation = 0.0f;
            float Unk801_2 = 0.0f;
        };

        class PlaySpellVisualKit final : public ServerPacket
        {
        public:
            PlaySpellVisualKit() : ServerPacket(SMSG_PLAY_SPELL_VISUAL_KIT, 16 + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Unit;
            int32 KitRecID = 0;
            int32 KitType = 0;
            uint32 Duration = 0;
        };

        class CancelCast final : public ClientPacket
        {
        public:
            CancelCast(WorldPacket&& packet) : ClientPacket(CMSG_CANCEL_CAST, std::move(packet)) { }

            void Read() override;

            uint32 SpellID = 0;
            ObjectGuid CastID;
        };

        class OpenItem final : public ClientPacket
        {
        public:
            OpenItem(WorldPacket&& packet) : ClientPacket(CMSG_OPEN_ITEM, std::move(packet)) { }

            void Read() override;

            uint8 Slot = 0;
            uint8 PackSlot = 0;
        };

        struct SpellChannelStartInterruptImmunities
        {
            int32 SchoolImmunities = 0;
            int32 Immunities = 0;
        };

        struct SpellTargetedHealPrediction
        {
            ObjectGuid TargetGUID;
            SpellHealPrediction Predict;
        };

        class SpellChannelStart final : public ServerPacket
        {
        public:
            SpellChannelStart() : ServerPacket(SMSG_SPELL_CHANNEL_START, 4 + 16 + 4) { }

            WorldPacket const* Write() override;

            int32 SpellID = 0;
            int32 SpellXSpellVisualID = 0;
            Optional<SpellChannelStartInterruptImmunities> InterruptImmunities;
            ObjectGuid CasterGUID;
            Optional<SpellTargetedHealPrediction> HealPrediction;
            uint32 ChannelDuration = 0;
        };

        class SpellChannelUpdate final : public ServerPacket
        {
        public:
            SpellChannelUpdate() : ServerPacket(SMSG_SPELL_CHANNEL_UPDATE, 16 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            int32 TimeRemaining = 0;
        };

        class ResurrectRequest final : public ServerPacket
        {
        public:
            ResurrectRequest() : ServerPacket(SMSG_RESURRECT_REQUEST, 16 + 4 + 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid ResurrectOffererGUID;
            uint32 ResurrectOffererVirtualRealmAddress  = 0;
            uint32 PetNumber                            = 0;
            int32 SpellID                               = 0;
            bool UseTimer                               = false;
            bool Sickness                               = false;
            std::string Name;
        };

        class UnlearnSkill final : public ClientPacket
        {
        public:
            UnlearnSkill(WorldPacket&& packet) : ClientPacket(CMSG_UNLEARN_SKILL, std::move(packet)) { }

            void Read() override;

            uint32 SkillLine = 0;
        };

        class SelfRes final : public ClientPacket
        {
        public:
            SelfRes(WorldPacket&& packet) : ClientPacket(CMSG_SELF_RES, std::move(packet)) { }

            void Read() override;

            int32 SpellID = 0;
        };

        class GetMirrorImageData final : public ClientPacket
        {
        public:
            GetMirrorImageData(WorldPacket&& packet) : ClientPacket(CMSG_GET_MIRROR_IMAGE_DATA, std::move(packet)) {}

            void Read() override;

            ObjectGuid UnitGUID;
            uint32 DisplayID = 0;
        };

        class MirrorImageComponentedData final : public ServerPacket
        {
        public:
            MirrorImageComponentedData() : ServerPacket(SMSG_MIRROR_IMAGE_COMPONENTED_DATA, 8 + 4 + 8 * 1 + 8 + 11 * 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            int32 DisplayID = 0;
            uint8 RaceID = 0;
            uint8 Gender = 0;
            uint8 ClassID = 0;
            uint8 SkinColor = 0;
            uint8 FaceVariation = 0;
            uint8 HairVariation = 0;
            uint8 HairColor = 0;
            uint8 BeardVariation = 0;
            std::array<uint8, PLAYER_CUSTOM_DISPLAY_SIZE> CustomDisplay;
            ObjectGuid GuildGUID;

            std::vector<int32> ItemDisplayID;
        };

        class MirrorImageCreatureData final : public ServerPacket
        {
        public:
            MirrorImageCreatureData() : ServerPacket(SMSG_MIRROR_IMAGE_CREATURE_DATA, 8 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            int32 DisplayID = 0;
        };

        class SpellClick final : public ClientPacket
        {
        public:
            SpellClick(WorldPacket&& packet) : ClientPacket(CMSG_SPELL_CLICK, std::move(packet)) { }

            void Read() override;

            ObjectGuid SpellClickUnitGuid;
            bool TryAutoDismount = false;
        };

        class ResyncRunes final : public ServerPacket
        {
        public:
            ResyncRunes(size_t size) : ServerPacket(SMSG_RESYNC_RUNES, 1 + 1 + 4 + size) { }

            WorldPacket const* Write() override;

            RuneData Runes;
        };

        class AddRunePower final : public ServerPacket
        {
        public:
            AddRunePower() : ServerPacket(SMSG_ADD_RUNE_POWER, 4) { }

            WorldPacket const* Write() override;

            uint32 AddedRunesMask = 0;
        };

        class MissileTrajectoryCollision final : public ClientPacket
        {
        public:
            MissileTrajectoryCollision(WorldPacket&& packet) : ClientPacket(CMSG_MISSILE_TRAJECTORY_COLLISION, std::move(packet)) { }

            void Read() override;

            ObjectGuid Target;
            int32 SpellID = 0;
            ObjectGuid CastID;
            TaggedPosition<Position::XYZ> CollisionPos;
        };

        class NotifyMissileTrajectoryCollision final : public ServerPacket
        {
        public:
            NotifyMissileTrajectoryCollision() : ServerPacket(SMSG_NOTIFY_MISSILE_TRAJECTORY_COLLISION, 8 + 1 + 12) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            ObjectGuid CastID;
            TaggedPosition<Position::XYZ> CollisionPos;
        };

        class UpdateMissileTrajectory final : public ClientPacket
        {
        public:
            UpdateMissileTrajectory(WorldPacket&& packet) : ClientPacket(CMSG_UPDATE_MISSILE_TRAJECTORY, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
            uint16 MoveMsgID = 0;
            int32 SpellID = 0;
            float Pitch = 0.0f;
            float Speed = 0.0f;
            TaggedPosition<Position::XYZ> FirePos;
            TaggedPosition<Position::XYZ> ImpactPos;
            Optional<MovementInfo> Status;
        };

        class SpellDelayed final : public ServerPacket
        {
        public:
            SpellDelayed() : ServerPacket(SMSG_SPELL_DELAYED, sizeof(ObjectGuid) + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid Caster;
            int32 ActualDelay = 0;
        };

        class DispelFailed final : public ServerPacket
        {
        public:
            DispelFailed() : ServerPacket(SMSG_DISPEL_FAILED, 16 + 16 + 4 + 4 + 4 /* predict a single failure on average */) { }

            WorldPacket const* Write() override;

            ObjectGuid CasterGUID;
            ObjectGuid VictimGUID;
            uint32 SpellID = 0;
            std::vector<int32> FailedSpells;
        };

        class CustomLoadScreen final : public ServerPacket
        {
        public:
            CustomLoadScreen(uint32 teleportSpellId, uint32 loadingScreenId) : ServerPacket(SMSG_CUSTOM_LOAD_SCREEN), TeleportSpellID(teleportSpellId), LoadingScreenID(loadingScreenId) { }

            WorldPacket const* Write() override;

            uint32 TeleportSpellID;
            uint32 LoadingScreenID;
        };
    }
}

ByteBuffer& operator>>(ByteBuffer& buffer, WorldPackets::Spells::SpellCastRequest& request);

#endif // SpellPackets_h__
