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

#include "BattlePetPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::BattlePet
{
ByteBuffer& operator<<(ByteBuffer& data, BattlePetSlot const& slot)
{
    data << (slot.Pet.Guid.IsEmpty() ? ObjectGuid::Create<HighGuid::BattlePet>(0) : slot.Pet.Guid);
    data << uint32(slot.CollarID);
    data << uint8(slot.Index);
    data << Bits<1>(slot.Locked);
    data.FlushBits();

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, BattlePetOwnerInfo const& owner)
{
    data << owner.Guid;
    data << uint32(owner.PlayerVirtualRealm);
    data << uint32(owner.PlayerNativeRealm);

    return data;
}

ByteBuffer& operator<<(ByteBuffer& data, BattlePet const& pet)
{
    data << pet.Guid;
    data << uint32(pet.Species);
    data << uint32(pet.CreatureID);
    data << uint32(pet.DisplayID);
    data << uint16(pet.Breed);
    data << uint16(pet.Level);
    data << uint16(pet.Exp);
    data << uint16(pet.Flags);
    data << uint32(pet.Power);
    data << uint32(pet.Health);
    data << uint32(pet.MaxHealth);
    data << uint32(pet.Speed);
    data << uint8(pet.Quality);
    data << SizedString::BitsSize<7>(pet.Name);
    data << OptionalInit(pet.OwnerInfo);
    data << Bits<1>(pet.NoRename);
    data.FlushBits();

    data << SizedString::Data(pet.Name);

    if (pet.OwnerInfo)
        data << *pet.OwnerInfo;

    return data;
}

WorldPacket const* BattlePetJournal::Write()
{
    _worldPacket << uint16(Trap);
    _worldPacket << Size<uint32>(Slots);
    _worldPacket << Size<uint32>(Pets);
    _worldPacket << Bits<1>(HasJournalLock);
    _worldPacket.FlushBits();

    for (BattlePetSlot const& slot : Slots)
        _worldPacket << slot;

    for (BattlePet const& pet : Pets)
        _worldPacket << pet;

    return &_worldPacket;
}

WorldPacket const* BattlePetUpdates::Write()
{
    _worldPacket << Size<uint32>(Pets);
    _worldPacket << Bits<1>(PetAdded);
    _worldPacket.FlushBits();

    for (BattlePet const& pet : Pets)
        _worldPacket << pet;

    return &_worldPacket;
}

WorldPacket const* PetBattleSlotUpdates::Write()
{
    _worldPacket << Size<uint32>(Slots);
    _worldPacket << Bits<1>(NewSlot);
    _worldPacket << Bits<1>(AutoSlotted);
    _worldPacket.FlushBits();

    for (BattlePetSlot const& slot : Slots)
        _worldPacket << slot;

    return &_worldPacket;
}

void BattlePetSetBattleSlot::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> Slot;
}

void BattlePetModifyName::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> SizedString::BitsSize<7>(Name);
    _worldPacket >> OptionalInit(DeclinedNames);

    if (DeclinedNames)
    {
        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket >> SizedString::BitsSize<7>(DeclinedNames->name[i]);

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket >> SizedString::Data(DeclinedNames->name[i]);
    }

    _worldPacket >> SizedString::Data(Name);
}

void QueryBattlePetName::Read()
{
    _worldPacket >> BattlePetID;
    _worldPacket >> UnitGUID;
}

WorldPacket const* QueryBattlePetNameResponse::Write()
{
    _worldPacket << BattlePetID;
    _worldPacket << int32(CreatureID);
    _worldPacket << Timestamp;

    _worldPacket << Bits<1>(Allow);

    if (Allow)
    {
        _worldPacket << SizedString::BitsSize<8>(Name);
        _worldPacket << Bits<1>(HasDeclined);

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket << SizedString::BitsSize<7>(DeclinedNames.name[i]);

        _worldPacket.FlushBits();

        for (uint8 i = 0; i < MAX_DECLINED_NAME_CASES; ++i)
            _worldPacket << SizedString::Data(DeclinedNames.name[i]);

        _worldPacket << SizedString::Data(Name);
    }
    else
        _worldPacket.FlushBits();

    return &_worldPacket;
}

void BattlePetDeletePet::Read()
{
    _worldPacket >> PetGuid;
}

void BattlePetSetFlags::Read()
{
    _worldPacket >> PetGuid;
    _worldPacket >> Flags;
    _worldPacket >> Bits<2>(ControlType);
}

void BattlePetClearFanfare::Read()
{
    _worldPacket >> PetGuid;
}

void CageBattlePet::Read()
{
    _worldPacket >> PetGuid;
}

WorldPacket const* BattlePetDeleted::Write()
{
    _worldPacket << PetGuid;

    return &_worldPacket;
}

WorldPacket const* BattlePetError::Write()
{
    _worldPacket << Bits<4>(Result);
    _worldPacket << int32(CreatureID);

    return &_worldPacket;
}

void BattlePetSummon::Read()
{
    _worldPacket >> PetGuid;
}

void BattlePetUpdateNotify::Read()
{
    _worldPacket >> PetGuid;
}
}
