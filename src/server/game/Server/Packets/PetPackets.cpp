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

#include "PetPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::Pet
{
WorldPacket const* PetSpells::Write()
{
    _worldPacket << PetGUID;
    _worldPacket << uint16(_CreatureFamily);
    _worldPacket << uint16(Specialization);
    _worldPacket << uint32(TimeLimit);
    _worldPacket << uint8(CommandState);
    _worldPacket << uint8(Flag);
    _worldPacket << uint8(ReactState);
    _worldPacket.append(ActionButtons.data(), ActionButtons.size());
    _worldPacket << Size<uint32>(Actions);
    _worldPacket << Size<uint32>(Cooldowns);
    _worldPacket << Size<uint32>(SpellHistory);

    for (uint32 action : Actions)
        _worldPacket << uint32(action);

    for (PetSpellCooldown const& cooldown : Cooldowns)
    {
        _worldPacket << int32(cooldown.SpellID);
        _worldPacket << int32(cooldown.Duration);
        _worldPacket << int32(cooldown.CategoryDuration);
        _worldPacket << float(cooldown.ModRate);
        _worldPacket << uint16(cooldown.Category);
    }

    for (PetSpellHistory const& history : SpellHistory)
    {
        _worldPacket << int32(history.CategoryID);
        _worldPacket << int32(history.RecoveryTime);
        _worldPacket << float(history.ChargeModRate);
        _worldPacket << int8(history.ConsumedCharges);
    }

    return &_worldPacket;
}

WorldPacket const* PetStableResult::Write()
{
    _worldPacket << int32(Result);

    return &_worldPacket;
}

WorldPacket const* PetLearnedSpells::Write()
{
    _worldPacket << Size<uint32>(Spells);
    for (uint32 spell : Spells)
        _worldPacket << int32(spell);

    return &_worldPacket;
}

WorldPacket const* PetUnlearnedSpells::Write()
{
    _worldPacket << Size<uint32>(Spells);
    for (uint32 spell : Spells)
        _worldPacket << int32(spell);

    return &_worldPacket;
}

WorldPacket const* PetNameInvalid::Write()
{
    _worldPacket << uint32(Result);
    _worldPacket << RenameData.PetGUID;
    _worldPacket << int32(RenameData.PetNumber);

    _worldPacket << SizedString::BitsSize<8>(RenameData.NewName);
    _worldPacket << OptionalInit(RenameData.DeclinedNames);

    if (RenameData.DeclinedNames)
    {
        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            _worldPacket << SizedString::BitsSize<7>(RenameData.DeclinedNames->name[i]);

        _worldPacket.FlushBits();

        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            _worldPacket << SizedString::Data(RenameData.DeclinedNames->name[i]);
    }
    else
        _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(RenameData.NewName);

    return &_worldPacket;
}

void PetRename::Read()
{
    _worldPacket >> RenameData.PetGUID;
    _worldPacket >> RenameData.PetNumber;

    _worldPacket >> SizedString::BitsSize<8>(RenameData.NewName);
    _worldPacket >> OptionalInit(RenameData.DeclinedNames);

    if (RenameData.DeclinedNames)
    {
        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            _worldPacket >> SizedString::BitsSize<7>(RenameData.DeclinedNames->name[i]);

        for (int32 i = 0; i < MAX_DECLINED_NAME_CASES; i++)
            _worldPacket >> SizedString::Data(RenameData.DeclinedNames->name[i]);
    }

    _worldPacket >> SizedString::Data(RenameData.NewName);
}

void PetAction::Read()
{
    _worldPacket >> PetGUID;

    _worldPacket >> Action;
    _worldPacket >> TargetGUID;

    _worldPacket >> ActionPosition;
}

void PetStopAttack::Read()
{
    _worldPacket >> PetGUID;
}

void PetSetAction::Read()
{
    _worldPacket >> PetGUID;

    _worldPacket >> Index;
    _worldPacket >> Action;
}

void PetAbandon::Read()
{
    _worldPacket >> Pet;
}

void PetAbandonByNumber::Read()
{
    _worldPacket >> PetNumber;
}

void PetSpellAutocast::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
    _worldPacket >> Bits<1>(AutocastEnabled);
}

void DismissCritter::Read()
{
    _worldPacket >> CritterGUID;
}

void PetCancelAura::Read()
{
    _worldPacket >> PetGUID;
    _worldPacket >> SpellID;
}

WorldPacket const* SetPetSpecialization::Write()
{
    _worldPacket << uint16(SpecID);

    return &_worldPacket;
}

WorldPacket const* PetActionFeedback::Write()
{
    _worldPacket << int32(Response);
    _worldPacket << int32(SpellID);

    return &_worldPacket;
}

WorldPacket const* PetActionSound::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << int32(Action);

    return &_worldPacket;
}

WorldPacket const* PetTameFailure::Write()
{
    _worldPacket << uint32(Result);

    return &_worldPacket;
}

WorldPacket const* PetMode::Write()
{
    _worldPacket << PetGUID;
    _worldPacket << uint8(CommandState);
    _worldPacket << uint8(Flag);
    _worldPacket << uint8(ReactState);

    return &_worldPacket;
}
}
