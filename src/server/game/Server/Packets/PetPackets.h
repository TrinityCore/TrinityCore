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

#ifndef PetPackets_h__
#define PetPackets_h__

#include "Packet.h"
#include "ObjectGuid.h"
#include "Pet.h"
class WorldObject;

namespace WorldPackets
{
    namespace Pet
    {
         //CMSG_PET_ACTION
        class PetAction final : public ClientPacket
        {
        public:
            PetAction(WorldPacket&& packet) : ClientPacket(CMSG_PET_ACTION, std::move(packet)) { }

            void Read() override;

            ObjectGuid petGuid;
            ObjectGuid targetGuid;
            uint32 petdata;
            uint32 spellid = 0;
            uint32 actionsFlag = 0;
            uint8 actionSlot = 0;
            float position_x, position_y, position_z;
        };


        //CMSG_LEARN_PET_SPECIALIZATION_GROUP
        class LearnPetSpecializationGroup final : public ClientPacket
        {
        public:
            LearnPetSpecializationGroup(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_PET_SPECIALIZATION_GROUP, std::move(packet)) { }

            void Read() override;

            ObjectGuid petGuid;
            int32 specGroupIndex = 0;
        };


        // SMSG_PET_GUIDS
        class PetGuids final : public ServerPacket
        {
        public:
            PetGuids() : ServerPacket(SMSG_PET_GUIDS, 16 + 4 ) { }

            WorldPacket const* Write() override;

            uint32 petCount = 0;
            //std::vector<ObjectGuid> petGuids;
            ObjectGuid petGuids;
           
        };

        //SMSG_PET_SPELLS_MESSAGE
        class PetSpellsMessage final : public ServerPacket
        {
        public:

            struct AuctionButton
            {
                int16 spell16 = 0;
                uint8 spell8 = 0;
                int32 spellid = spell16+(spell8 << 16);
                uint8 Slot = 0;
            };

            PetSpellsMessage() : ServerPacket(SMSG_PET_SPELLS_MESSAGE, 16 + 2 + 2 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid PetGUID;
            uint16 creatureFamily = CREATURE_FAMILY_WOLF;
            uint16 specialization = 0;
            uint32 timeLimit = 0;
            uint32 petModeAndOrders = 0;
            // ActionButtons

            int32 actionsCount = 0;
            uint32 cooldownsCount = 0;
            uint32 spellHistoryCount = 0;
            //Actions

            // PetSpellCooldown

            // PetSpellHistory

        };

        // SMSG_PET_ADDED
        class PetAdded final : public ServerPacket
        {
        public:
            PetAdded() : ServerPacket(SMSG_PET_ADDED, 5 * 4 + 1 + 1 + 10) { }

            WorldPacket const* Write() override;

            int32 petSlot = 0;
            int32 petNumber = 0; //lowGuid (42129178)
            int32 petCreatureID = 42717; //default Wolf PEt Hunter
            int32 petDisplayID = 903;
            int32 petExperienceLevel = 1;
            int8  petFlags = 0;

            //reset bit
            int8 petNameLenght = petName.length();
            std::string petName = "Pet";

        };

        //SMSG_PET_LEARNED_SPELLS
        class PetLearnedSpells final : public ServerPacket
        {
        public:
            PetLearnedSpells(PetSpellMap petSp) : ServerPacket(SMSG_PET_LEARNED_SPELLS, 4 + petSp.size() * 4), PetSp(petSp) { }

            WorldPacket const* Write() override;
                        
            PetSpellMap PetSp;
        };

        //SMSG_PET_UNLEARNED_SPELLS
        class PetUnlearnedSpells final : public ServerPacket
        {
        public:
            PetUnlearnedSpells(PetSpellMap petSp) : ServerPacket(SMSG_PET_UNLEARNED_SPELLS, 4 + petSp.size() * 4), PetSp(petSp) { }

            WorldPacket const* Write() override;

            PetSpellMap PetSp;
        };
    }
}
#endif // PetPackets_h__