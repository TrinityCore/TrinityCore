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

        class SendAuraUpdate final : public ServerPacket
        {
        public:
            SendAuraUpdate() : ServerPacket(SMSG_AURA_UPDATE) { }

            WorldPacket const* Write() override;
            void Init(bool IsFullUpdate, ObjectGuid Target, uint32 Count);
            void BuildUpdatePacket(AuraApplication* aurApp, bool remove, uint16 level);
        };    

        class SpellCastRequest final : public ClientPacket
        {
        public:
            SpellCastRequest(WorldPacket&& packet) : ClientPacket(std::move(packet))
            {
                ASSERT(packet.GetOpcode() == CMSG_CAST_SPELL || packet.GetOpcode() == CMSG_PET_CAST_SPELL);
            }

            void Read() override;

            ObjectGuid PetGuid;
            uint8 CastID;
            uint32 SpellID;
            uint32 Misc;
            uint32 TargetFlags;
            ObjectGuid UnitGuid;
            ObjectGuid ItemGuid;
            
            ObjectGuid SrcTransportGuid;
            ObjectGuid DstTransportGuid;
            Position SrcPos;
            Position DstPos;
            float Orientation;

            std::string Name;
            float Pitch;
            float Speed;
            ObjectGuid Guid;
            uint32 SendCastFlags;

            MovementInfo movementInfo;
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
            Optional<float> Orientation; // Not found in JAM structures
            std::string Name;
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
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastLogData const& spellCastLogData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::TargetLocation const& targetLocation);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellTargetData const& spellTargetData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellMissStatus const& spellMissStatus);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellPowerData const& spellPowerData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::RuneData const& runeData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::MissileTrajectoryResult const& missileTrajectory);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellAmmo const& spellAmmo);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::ProjectileVisualData const& projectileVisual);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::CreatureImmunities const& immunities);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellHealPrediction const& spellPred);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellCastData const& spellCastData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifierData const& spellModifierData);
ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Spells::SpellModifier const& spellModifier);

#endif // SpellPackets_h__
