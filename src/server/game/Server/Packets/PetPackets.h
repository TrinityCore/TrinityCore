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

#ifndef PetPackets_h__
#define PetPackets_h__

#include "Packet.h"
#include "PetDefines.h"
#include "Position.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include "UnitDefines.h"
#include <array>

namespace WorldPackets
{
    namespace Pet
    {
        class DismissCritter final : public ClientPacket
        {
        public:
            DismissCritter(WorldPacket&& packet) : ClientPacket(CMSG_DISMISS_CRITTER, std::move(packet)) { }

            void Read() override;

            ObjectGuid CritterGUID;
        };

        class RequestPetInfo final : public ClientPacket
        {
        public:
            RequestPetInfo(WorldPacket&& packet) : ClientPacket(CMSG_REQUEST_PET_INFO, std::move(packet)) { }

            void Read() override { }
        };

        class PetAbandon final : public ClientPacket
        {
        public:
            PetAbandon(WorldPacket&& packet) : ClientPacket(CMSG_PET_ABANDON, std::move(packet)) { }

            void Read() override;

            ObjectGuid Pet;
        };

        class PetAbandonByNumber final : public ClientPacket
        {
        public:
            PetAbandonByNumber(WorldPacket&& packet) : ClientPacket(CMSG_PET_ABANDON_BY_NUMBER, std::move(packet)) { }

            void Read() override;

            uint32 PetNumber = 0;
        };

        class PetStopAttack final : public ClientPacket
        {
        public:
            PetStopAttack(WorldPacket&& packet) : ClientPacket(CMSG_PET_STOP_ATTACK, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
        };

        class PetSpellAutocast final : public ClientPacket
        {
        public:
            PetSpellAutocast(WorldPacket&& packet) : ClientPacket(CMSG_PET_SPELL_AUTOCAST, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            uint32 SpellID = 0;
            bool AutocastEnabled = false;
        };

        struct PetSpellCooldown
        {
            int32 SpellID = 0;
            int32 Duration = 0;
            int32 CategoryDuration = 0;
            float ModRate = 1.0f;
            uint16 Category = 0;
        };

        struct PetSpellHistory
        {
            int32 CategoryID = 0;
            int32 RecoveryTime = 0;
            float ChargeModRate = 1.0f;
            int8 ConsumedCharges = 0;
        };

        class PetSpells final : public ServerPacket
        {
        public:
            PetSpells() : ServerPacket(SMSG_PET_SPELLS_MESSAGE, 100) { }

            WorldPacket const* Write() override;

            ObjectGuid PetGUID;
            uint16 _CreatureFamily = 0; ///< @see enum CreatureFamily
            uint16 Specialization = 0;
            uint32 TimeLimit = 0;
            uint8 ReactState = 0;
            uint8 CommandState = 0;
            uint8 Flag = 0;

            std::array<int, 10> ActionButtons = { };

            std::vector<uint32> Actions;
            std::vector<PetSpellCooldown> Cooldowns;
            std::vector<PetSpellHistory> SpellHistory;
        };

        class PetStableResult final : public ServerPacket
        {
        public:
            PetStableResult() : ServerPacket(SMSG_PET_STABLE_RESULT, 1) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
        };

        class PetLearnedSpells final : public ServerPacket
        {
        public:
            PetLearnedSpells() : ServerPacket(SMSG_PET_LEARNED_SPELLS, 4) { }

            WorldPacket const* Write() override;

            std::vector<uint32> Spells;
        };

        class PetUnlearnedSpells final : public ServerPacket
        {
        public:
            PetUnlearnedSpells() : ServerPacket(SMSG_PET_UNLEARNED_SPELLS, 4) { }

            WorldPacket const* Write() override;

            std::vector<uint32> Spells;
        };

        struct PetRenameData
        {
            ObjectGuid PetGUID;
            int32 PetNumber = 0;
            std::string NewName;
            Optional<DeclinedName> DeclinedNames;
        };

        class PetNameInvalid final : public ServerPacket
        {
        public:
            PetNameInvalid() : ServerPacket(SMSG_PET_NAME_INVALID, 18 + 4 + 2 + 1 + 5 * 2 + 2) { }

            WorldPacket const* Write() override;

            PetRenameData RenameData;

            uint8 Result = 0;
        };

        class PetRename final : public ClientPacket
        {
        public:
            PetRename(WorldPacket&& packet) : ClientPacket(CMSG_PET_RENAME, std::move(packet)) { }

            void Read() override;

            PetRenameData RenameData;
        };

        class PetAction final : public ClientPacket
        {
        public:
            PetAction(WorldPacket&& packet) : ClientPacket(CMSG_PET_ACTION, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            uint32 Action = 0;
            ObjectGuid TargetGUID;
            TaggedPosition<Position::XYZ> ActionPosition;
        };

        class PetSetAction final : public ClientPacket
        {
        public:
            PetSetAction(WorldPacket&& packet) : ClientPacket(CMSG_PET_SET_ACTION, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;

            uint32 Index = 0;
            uint32 Action = 0;
        };

        class PetCancelAura final : public ClientPacket
        {
        public:
            PetCancelAura(WorldPacket&& packet) : ClientPacket(CMSG_PET_CANCEL_AURA, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGUID;
            int32 SpellID = 0;
        };

        class SetPetSpecialization final : public ServerPacket
        {
        public:
            SetPetSpecialization() : ServerPacket(SMSG_SET_PET_SPECIALIZATION, 2) { }

            WorldPacket const* Write() override;

            uint16 SpecID = 0;
        };

        class PetActionFeedback final : public ServerPacket
        {
        public:
            PetActionFeedback() : ServerPacket(SMSG_PET_ACTION_FEEDBACK, 4 + 1) { }

            WorldPacket const* Write() override;

            int32 SpellID = 0;
            ::PetActionFeedback Response = ::PetActionFeedback::None;
        };

        class PetActionSound final : public ServerPacket
        {
        public:
            PetActionSound() : ServerPacket(SMSG_PET_ACTION_SOUND, 18 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid UnitGUID;
            int32 Action = 0;
        };

        class PetTameFailure final : public ServerPacket
        {
        public:
            PetTameFailure() : ServerPacket(SMSG_PET_TAME_FAILURE, 1) { }

            WorldPacket const* Write() override;

            uint8 Result = 0;
        };

        class PetMode final : public ServerPacket
        {
        public:
            PetMode() : ServerPacket(SMSG_PET_MODE, 16 + 2 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid PetGUID;
            ReactStates ReactState = REACT_PASSIVE;
            CommandStates CommandState = COMMAND_STAY;
            uint8 Flag = 0;
        };
    }
}

#endif // PetPackets_h__
