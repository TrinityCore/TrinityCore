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

#include "PetPackets.h"


void WorldPackets::Pet::PetRename::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> PetNumber;
    _worldPacket >> PetNameLenght;
    IsDeclined = _worldPacket.ReadBit();
    if (IsDeclined)
    {
        uint8 count[5];
        for (uint8 i = 0; i < 5; i++)
        {
            count[i] = _worldPacket.ReadBits(7);
        }

        for (uint8 i = 0; i < 5; i++)
        {
            DeclinedName.name[i] = _worldPacket.ReadString(count[i]);
        }
    }
    PetName = _worldPacket.ReadString(PetNameLenght);   
}

void WorldPackets::Pet::PetAction::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> SpellId;
    _worldPacket >> CommandStat;
    _worldPacket >> ActiveStat;
    _worldPacket >> TargetGuid;
    _worldPacket >> PositionX;
    _worldPacket >> PositionY;
    _worldPacket >> PositionZ;
 
}

void WorldPackets::Pet::PetSetAction::Read()
{
	
	 auto count = (_worldPacket.size() == 24) ? 2 : 1;
	 
	 _worldPacket >> petGuid;
	 
	 for (uint8 i = 0; i < count; ++i)
	 {
		 _worldPacket >> position[i];
		 _worldPacket >> data[i];
	 }
   
}

void WorldPackets::Pet::LearnPetSpecializationGroup::Read()
{
    _worldPacket >> petGuid;
    _worldPacket >> specGroupIndex;
}

WorldPacket const* WorldPackets::Pet::PetGuids::Write()
{
    _worldPacket << PetCount;
    for (size_t i = 0; i < PetCount; i++)
    {
        _worldPacket << PetGuid;
    }
         
    return &_worldPacket;
}


WorldPacket const* WorldPackets::Pet::PetAdded::Write()
{
    _worldPacket << PetSlot;
    _worldPacket << PetNumber;
    _worldPacket << PetCreatureID;
    _worldPacket << PetDisplayID;
    _worldPacket << PetExperienceLevel;
    _worldPacket << PetFlags;
    _worldPacket << PetName.size();
    _worldPacket << PetName;

    return &_worldPacket;
}


WorldPacket const* WorldPackets::Pet::PetLearnedSpells::Write()
{
    _worldPacket << uint32(PetSp.size());
    for(auto& spellMap : PetSp)
    {
        _worldPacket << uint32(spellMap.first);
    }
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetUnlearnedSpells::Write()
{
    _worldPacket << uint32(PetSp.size());
    for (auto& spellMap : PetSp)
    {
        _worldPacket << uint32(spellMap.first);
    }
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetSpellsMessage::Write()
{
    _worldPacket << petGUID;
    _worldPacket << creatureFamily;
    _worldPacket << specialization;
    _worldPacket << timeLimit;
    _worldPacket << reactState;
    _worldPacket << commandState;
    _worldPacket << flags;

    for (uint8 i = 0; i < ACTION_BAR_INDEX_END; ++i)
        _worldPacket << PetSpellActionBar.at(i);
     
    _worldPacket << actionsCount;
    _worldPacket << cooldownsCount;
    _worldPacket << spellHistoryCount;
       
    _worldPacket << ActionList;
    _worldPacket << SpellHistoryList;
    _worldPacket << CooldownList;

    return &_worldPacket;
}
