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
        
        class PetRename final : public ClientPacket
        {
        public:
            PetRename(WorldPacket&& packet) : ClientPacket(CMSG_PET_RENAME, std::move(packet)) { }

            void Read() override;

            ObjectGuid PetGuid;
            uint32 PetNumber = 0;
            uint8 PetNameLenght = 0;
            std::string PetName;
            bool IsDeclined = false;
            DeclinedName DeclinedName;
            
        };

        
        class PetAction final : public ClientPacket
        {
        public:
            PetAction(WorldPacket&& packet) : ClientPacket(CMSG_PET_ACTION, std::move(packet)) { }

            void Read() override;
	        ObjectGuid PetGuid;
            ObjectGuid TargetGuid;
            uint16 SpellId = 0;
            uint8 CommandStat = 0;
            uint8 ActiveStat = 0;
            float PositionX = 0.0f;
            float PositionY = 0.0f;
            float PositionZ = 0.0f;
        };


       
        class PetSetAction final : public ClientPacket
        {
        public:
            PetSetAction(WorldPacket&& packet) : ClientPacket(CMSG_PET_SET_ACTION, std::move(packet)) { }

            void Read() override;
			
			ObjectGuid petGuid;
			uint32 position[2];
			uint32 data[2];
        };

       
        class LearnPetSpecializationGroup final : public ClientPacket
        {
        public:
            LearnPetSpecializationGroup(WorldPacket&& packet) : ClientPacket(CMSG_LEARN_PET_SPECIALIZATION_GROUP, std::move(packet)) { }

            void Read() override;

            ObjectGuid petGuid;
            int32 specGroupIndex = 0;
        };


       
        class PetGuids final : public ServerPacket
        {
        public:
            PetGuids() : ServerPacket(SMSG_PET_GUIDS, 16 + 4 ) { }

            WorldPacket const* Write() override;

            uint32 PetCount = 0;
            ObjectGuid PetGuid;
           
        };
		///@todo not complet 
         class PetSpellsMessage final : public ServerPacket
        {
        public:
            PetSpellsMessage() : ServerPacket(SMSG_PET_SPELLS_MESSAGE, 16 + 2 + 2 + 4 + 1 + 1 + 2 + 4 * MAX_UNIT_ACTION_BAR_INDEX + 4 + 4 + 4) { }

            WorldPacket const* Write() override;

            ObjectGuid petGUID;
            uint16 creatureFamily = CREATURE_FAMILY_WOLF;   // Creature family (required for pet talents)
            uint16 specialization = 0;                      // Specialization  
            int32 timeLimit = 0;                            // TimeLimit
            uint8 reactState = 3;                           // Recast Assist
            uint8 commandState = 1;                         // Follow
            uint16 flags = 0;                               // Flags, mostly unknown
            std::vector<uint32> PetSpellActionBar;
            int32 actionsCount = 0;                         //ActionsCount
            uint32 cooldownsCount = 0;                      //CooldownsCount
            uint32 spellHistoryCount = 0;                   //SpellHistoryCount
            
            //ActionsList
            std::vector<uint32> ActionList;

            //CooldownsList
            std::vector<uint32> CooldownList;
            
            //SpellHistoryList
            std::vector<uint32> SpellHistoryList;
        };

       
        class PetAdded final : public ServerPacket
        {
        public:
            PetAdded() : ServerPacket(SMSG_PET_ADDED, 5 * 4 + 1 + 1 + 10) { }

            WorldPacket const* Write() override;

            int32 PetSlot = 0;
			int32 PetNumber = 0;         
            int32 PetCreatureID = 0; 
            int32 PetDisplayID = 0;
            int32 PetExperienceLevel = 1;
            int8  PetFlags = 0;
            std::string PetName = "Pet";
        };

       
        class PetLearnedSpells final : public ServerPacket
        {
        public:
            PetLearnedSpells(PetSpellMap petSp) : ServerPacket(SMSG_PET_LEARNED_SPELLS, 4 + petSp.size() * 4), PetSp(petSp) { }

            WorldPacket const* Write() override;
                        
            PetSpellMap PetSp;
        };

       
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