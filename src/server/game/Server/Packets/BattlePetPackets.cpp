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

#include "BattlePetPackets.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePet::BattlePetSlot const& slot)
{
    data << (slot.Pet.Guid.IsEmpty() ? ObjectGuid::Create<HighGuid::BattlePet>(0) : slot.Pet.Guid);
    data << uint32(slot.CollarID);
    data << uint8(slot.Index);
    data.WriteBit(slot.Locked);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePet::BattlePet const& pet)
{
    data << pet.Guid;
    data << uint32(pet.Species);
    data << uint32(pet.CreatureID);
    data << uint32(pet.CollarID);
    data << uint16(pet.Breed);
    data << uint16(pet.Level);
    data << uint16(pet.Exp);
    data << uint16(pet.Flags);
    data << uint32(pet.Power);
    data << uint32(pet.Health);
    data << uint32(pet.MaxHealth);
    data << uint32(pet.Speed);
    data << uint8(pet.Quality);
    data.WriteBits(pet.Name.size(), 7);
    data.WriteBit(pet.OwnerInfo.is_initialized());
    data.WriteBit(pet.Name.empty()); // NoRename
    data.FlushBits();

    data.WriteString(pet.Name);

    if (pet.OwnerInfo)
    {
        data << pet.OwnerInfo->Guid;
        data << uint32(pet.OwnerInfo->PlayerVirtualRealm);
        data << uint32(pet.OwnerInfo->PlayerNativeRealm);
    }

    return data;
}

WorldPacket const* WorldPackets::BattlePet::BattlePetJournal::Write()
{
    _worldPacket << uint16(Trap);
    _worldPacket << uint32(Slots.size());
    _worldPacket << uint32(Pets.size());
    _worldPacket << int32(MaxPets);
    _worldPacket.WriteBit(HasJournalLock);
    _worldPacket.FlushBits();

    for (BattlePetSlot const& slot : Slots)
        _worldPacket << slot;

    for (BattlePet const& pet : Pets)
        _worldPacket << pet;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePet::BattlePetUpdates::Write()
{
    _worldPacket << uint32(Pets.size());
    _worldPacket.WriteBit(PetAdded);
    _worldPacket.FlushBits();

    for (auto const& pet : Pets)
        _worldPacket << pet;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePet::PetBattleSlotUpdates::Write()
{
    _worldPacket << uint32(Slots.size());
    _worldPacket.WriteBit(NewSlot);
    _worldPacket.WriteBit(AutoSlotted);
    _worldPacket.FlushBits();

    for (auto const& slot : Slots)
        _worldPacket << slot;

    return &_worldPacket;
}

void WorldPackets::BattlePet::BattlePetSetBattleSlot::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> Slot;
}

void WorldPackets::BattlePet::BattlePetModifyName::Read()
{
    _worldPacket >> PetGuid;
    uint32 nameLength = _worldPacket.ReadBits(7);
    bool hasDeclinedNames = _worldPacket.ReadBit();

    if (hasDeclinedNames)
    {
        uint8 declinedNameLengths[MAX_DECLINED_NAME_CASES];

        for (uint8 i = 0; i < 5; ++i)
            declinedNameLengths[i] = _worldPacket.ReadBits(7);

        for (uint8 i = 0; i < 5; ++i)
            Declined.name[i] = _worldPacket.ReadString(declinedNameLengths[i]);
    }

    Name = _worldPacket.ReadString(nameLength);
}

void WorldPackets::BattlePet::BattlePetDeletePet::Read()
{
    _worldPacket >> PetGuid;
}

void WorldPackets::BattlePet::BattlePetSetFlags::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> Flags;
    ControlType = _worldPacket.ReadBits(2);
}

void WorldPackets::BattlePet::CageBattlePet::Read()
{
    _worldPacket >> PetGuid;
}

WorldPacket const* WorldPackets::BattlePet::BattlePetDeleted::Write()
{
    _worldPacket << PetGuid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePet::BattlePetError::Write()
{
    _worldPacket.WriteBits(Result, 3);
    _worldPacket << uint32(CreatureID);

    return &_worldPacket;
}

void WorldPackets::BattlePet::BattlePetSummon::Read()
{
    _worldPacket >> PetGuid;
}
