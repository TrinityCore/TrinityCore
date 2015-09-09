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

#include "BattlePetPackets.h"
#include "World.h"

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePet::BattlePetSlot const& slot)
{
    data << (slot.Pet.Guid.IsEmpty() ? ObjectGuid::Create<HighGuid::BattlePet>(0) : slot.Pet.Guid);
    data << slot.CollarID;
    data << slot.Index;
    data.WriteBit(slot.Locked);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::BattlePet::BattlePet const& pet)
{
    data << pet.Guid;
    data << pet.Species;
    data << pet.CreatureID;
    data << pet.CollarID;
    data << pet.Breed;
    data << pet.Level;
    data << pet.Exp;
    data << pet.Flags;
    data << pet.Power;
    data << pet.Health;
    data << pet.MaxHealth;
    data << pet.Speed;
    data << pet.Quality;
    data.WriteBits(pet.Name.size(), 7);
    data.WriteBit(!pet.Owner.IsEmpty()); // HasOwnerInfo
    data.WriteBit(pet.Name.empty()); // NoRename
    data.FlushBits();

    if (!pet.Owner.IsEmpty())
    {
        data << pet.Owner;
        data << GetVirtualRealmAddress(); // Virtual
        data << GetVirtualRealmAddress(); // Native
    }

    data.WriteString(pet.Name);

    return data;
}

WorldPacket const* WorldPackets::BattlePet::BattlePetJournal::Write()
{
    _worldPacket << Trap;
    _worldPacket << Slots.size();
    _worldPacket << Pets.size();

    for (auto const& slot : Slots)
        _worldPacket << slot;

    for (auto const& pet : Pets)
        _worldPacket << pet;

    _worldPacket.WriteBit(1); // HasJournalLock
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::BattlePet::BattlePetUpdates::Write()
{
    _worldPacket << Pets.size();

    for (auto const& pet : Pets)
        _worldPacket << pet;

    _worldPacket.WriteBit(PetAdded);
    _worldPacket.FlushBits();

    return &_worldPacket;
}


WorldPacket const* WorldPackets::BattlePet::PetBattleSlotUpdates::Write()
{
    _worldPacket << Slots.size();

    for (auto const& slot : Slots)
        _worldPacket << slot;

    _worldPacket.WriteBit(NewSlot);
    _worldPacket.WriteBit(AutoSlotted);
    _worldPacket.FlushBits();

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
    Name = _worldPacket.ReadString(nameLength);

    if (hasDeclinedNames)
    {
        uint8 declinedNameLengths[MAX_DECLINED_NAME_CASES];

        for (uint8 i = 0; i < 5; ++i)
            declinedNameLengths[i] = _worldPacket.ReadBits(7);

        for (uint8 i = 0; i < 5; ++i)
            Declined.name[i] = _worldPacket.ReadString(declinedNameLengths[i]);
    }
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
    _worldPacket.WriteBits(Result, 4);
    _worldPacket.FlushBits();
    _worldPacket << CreatureID;

    return &_worldPacket;
}

void WorldPackets::BattlePet::BattlePetSummon::Read()
{
    _worldPacket >> PetGuid;
}
