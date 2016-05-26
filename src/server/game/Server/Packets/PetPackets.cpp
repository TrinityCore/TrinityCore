/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

WorldPacket const* WorldPackets::Pet::PetSpells::Write()
{
    _worldPacket << PetGUID;
    _worldPacket << int16(_CreatureFamily);
    _worldPacket << int16(Specialization);
    _worldPacket << int32(TimeLimit);

    uint32 petModeAndOrders = ReactState + (CommandState << 8) + (Flag << 16);
    _worldPacket << uint32(petModeAndOrders);

    for (uint32 actionButton : ActionButtons)
        _worldPacket << int32(actionButton);

    _worldPacket << int32(Actions.size());
    _worldPacket << int32(Cooldowns.size());
    _worldPacket << int32(SpellHistory.size());

    for (uint32 action : Actions)
        _worldPacket << action;

    for (PetSpellCooldown const& cooldown : Cooldowns)
    {
        _worldPacket << int32(cooldown.SpellID);
        _worldPacket << int32(cooldown.Duration);
        _worldPacket << int32(cooldown.CategoryDuration);
        _worldPacket << int16(cooldown.Category);
    }

    for (PetSpellHistory const& history : SpellHistory)
    {
        _worldPacket << int32(history.CategoryID);
        _worldPacket << int32(history.RecoveryTime);
        _worldPacket << int8(history.ConsumedCharges);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetStableList::Write()
{
    _worldPacket << StableMaster;

    _worldPacket << uint32(Pets.size());
    for (PetStableInfo const& pet : Pets)
    {
        _worldPacket << int32(pet.PetSlot);
        _worldPacket << int32(pet.PetNumber);
        _worldPacket << int32(pet.CreatureID);
        _worldPacket << int32(pet.DisplayID);
        _worldPacket << int32(pet.ExperienceLevel);
        _worldPacket << int32(pet.PetFlags);

        _worldPacket << int8(pet.PetName.length());
        _worldPacket.WriteString(pet.PetName);
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetLearnedSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spell : Spells)
        _worldPacket << int32(spell);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetUnlearnedSpells::Write()
{
    _worldPacket << uint32(Spells.size());
    for (uint32 spell : Spells)
        _worldPacket << int32(spell);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetNameInvalid::Write()
{
    _worldPacket << RenameData.PetGUID;
    _worldPacket << int32(RenameData.PetNumber);

    _worldPacket << uint8(RenameData.NewName.length());

    _worldPacket.WriteBit(RenameData.HasDeclinedNames);
    _worldPacket.FlushBits();

    if (RenameData.HasDeclinedNames)
    {
        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
        {
            _worldPacket.WriteBits(RenameData.DeclinedNames.name[i].length(), 7);
            _worldPacket.FlushBits();
        }

        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            _worldPacket << RenameData.DeclinedNames.name[i];
    }

    _worldPacket.WriteString(RenameData.NewName);
    return &_worldPacket;
}

void WorldPackets::Pet::PetRename::Read()
{
    _worldPacket >> RenameData.PetGUID;
    _worldPacket >> RenameData.PetNumber;

    int8 nameLen = 0;
    _worldPacket >> nameLen;

    RenameData.HasDeclinedNames = _worldPacket.ReadBit();
    if (RenameData.HasDeclinedNames)
    {
        int32 count[MAX_DECLINED_NAME_CASES];
        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            count[i] = _worldPacket.ReadBits(7);

        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            RenameData.DeclinedNames.name[i] = _worldPacket.ReadString(count[i]);
    }

    RenameData.NewName = _worldPacket.ReadString(nameLen);
}

void WorldPackets::Pet::PetAction::Read()
{
    _worldPacket >> PetGUID;

    _worldPacket >> Action;
    _worldPacket >> TargetGUID;

    _worldPacket >> ActionPosition;
}

void WorldPackets::Pet::PetStopAttack::Read()
{
    _worldPacket >> PetGUID;
}

void WorldPackets::Pet::PetSetAction::Read()
{
    _worldPacket >> PetGUID;

    _worldPacket >> Index;
    _worldPacket >> Action;
}

void WorldPackets::Pet::PetAbandon::Read()
{
    _worldPacket >> Pet;
}

void WorldPackets::Pet::PetSpellAutocast::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
    AutocastEnabled = _worldPacket.ReadBit();
}

void WorldPackets::Pet::DismissCritter::Read()
{
    _worldPacket >> CritterGUID;
}

void WorldPackets::Pet::PetCancelAura::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
}

void WorldPackets::Pet::LearnPetSpecializationGroup::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpecGroupIndex;
}

WorldPacket const* WorldPackets::Pet::SetPetSpecialization::Write()
{
    _worldPacket << uint16(SpecID);

    return &_worldPacket;
}
