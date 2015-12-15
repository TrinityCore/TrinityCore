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

WorldPacket const* WorldPackets::Pet::PetSpells::Write()
{
    _worldPacket << PetGUID;
    _worldPacket << int16(CreatureFamily);
    _worldPacket << int16(Specialization);
    _worldPacket << int32(TimeLimit);
    uint32 PetModeAndOrders = ReactState + (CommandState << 8) + (Flag << 16);
    _worldPacket << uint32(PetModeAndOrders);

    for (uint32 actionButton : ActionButtons)
        _worldPacket << int32(actionButton);

    _worldPacket << int32(Actions.size());
    _worldPacket << int32(Cooldowns.size());
    _worldPacket << int32(SpellHistory.size());

    for (uint32 action : Actions)
        _worldPacket << action;

    for (PetSpellCooldown cooldown : Cooldowns)
    {
        _worldPacket << int32(cooldown.SpellID);
        _worldPacket << int32(cooldown.Duration);
        _worldPacket << int32(cooldown.CategoryDuration);
        _worldPacket << int16(cooldown.Category);
    }

    for (PetSpellHistory history : SpellHistory)
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

    _worldPacket << pets.size();
    for (PetStableInfo pet : pets)
    {
        _worldPacket << int32(pet.PetSlot);
        _worldPacket << int32(pet.PetNumber);
        _worldPacket << int32(pet.CreatureID);
        _worldPacket << int32(pet.DisplayID);
        _worldPacket << int32(pet.ExperienceLevel);
        _worldPacket << int32(pet.PetFlags);

        _worldPacket << int8(pet.PetName.length());
        _worldPacket << pet.PetName;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetLearnedSpells::Write()
{
    _worldPacket << uint32(spells.size());
    for (uint32 spell : spells)
        _worldPacket << int32(spell);
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetUnlearnedSpells::Write()
{
    _worldPacket << uint32(spells.size());
    for (uint32 spell : spells)
        _worldPacket << int32(spell);
    return &_worldPacket;
}