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
    _worldPacket >> petGuid;
    _worldPacket >> petNumber;
    _worldPacket >> petNameLenght;
    isdeclined = _worldPacket.ReadBit();
    if (isdeclined)
    {
        uint8 count[5];
        for (uint8 i = 0; i < 5; i++)
        {
            count[i] = _worldPacket.ReadBits(7);
        }

        for (uint8 i = 0; i < 5; i++)
        {
            declinedname.name[i] = _worldPacket.ReadString(count[i]);
        }
    }
    petName = _worldPacket.ReadString(petNameLenght);

    
}

void WorldPackets::Pet::PetAction::Read()
{
    _worldPacket >> petGuid;
    _worldPacket >> spellid;
    _worldPacket >> commandStat;
    _worldPacket >> activeStat;
    _worldPacket >> targetGuid;
    _worldPacket >> position_x;
    _worldPacket >> position_y;
    _worldPacket >> position_z;
 
}

void WorldPackets::Pet::PetSetAction::Read()
{
    _worldPacket >> petGuid;
    _worldPacket >> petBarIndex;
    _worldPacket >> spellid;
    _worldPacket >> commandStat;
    _worldPacket >> activeStat;
}

void WorldPackets::Pet::LearnPetSpecializationGroup::Read()
{
    _worldPacket >> petGuid;
    _worldPacket >> specGroupIndex;
}

WorldPacket const* WorldPackets::Pet::PetGuids::Write()
{
    _worldPacket << petCount;
    for (size_t i = 0; i < petCount; i++)
    {
        _worldPacket << petGuids;
    }
         
    return &_worldPacket;
}


WorldPacket const* WorldPackets::Pet::PetAdded::Write()
{
    _worldPacket << petSlot
                 << petNumber
                 << petCreatureID
                 << petDisplayID
                 << petExperienceLevel
                 << petFlags
                 << petNameLenght
                 << petName; 

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