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

#include "EquipmentSetPackets.h"

WorldPacket const* WorldPackets::EquipmentSet::EquipmentSetID::Write()
{
    _worldPacket << int32(Type);
    _worldPacket << uint32(SetID);
    _worldPacket << uint64(GUID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::EquipmentSet::LoadEquipmentSet::Write()
{
    _worldPacket << uint32(SetData.size());

    for (EquipmentSetInfo::EquipmentSetData const* equipSet : SetData)
    {
        _worldPacket << int32(equipSet->Type);
        _worldPacket << uint64(equipSet->Guid);
        _worldPacket << uint32(equipSet->SetID);
        _worldPacket << uint32(equipSet->IgnoreMask);

        for (std::size_t i = 0; i < EQUIPMENT_SET_SLOTS; ++i)
        {
            _worldPacket << equipSet->Pieces[i];
            _worldPacket << int32(equipSet->Appearances[i]);
        }

        _worldPacket.append(equipSet->Enchants.data(), equipSet->Enchants.size());

        _worldPacket << int32(equipSet->SecondaryShoulderApparanceID);
        _worldPacket << int32(equipSet->SecondaryShoulderSlot);
        _worldPacket << int32(equipSet->SecondaryWeaponAppearanceID);
        _worldPacket << int32(equipSet->SecondaryWeaponSlot);

        _worldPacket.WriteBit(equipSet->AssignedSpecIndex != -1);
        _worldPacket.WriteBits(equipSet->SetName.length(), 8);
        _worldPacket.WriteBits(equipSet->SetIcon.length(), 9);
        _worldPacket.FlushBits();

        if (equipSet->AssignedSpecIndex != -1)
            _worldPacket << int32(equipSet->AssignedSpecIndex);

        _worldPacket.WriteString(equipSet->SetName);
        _worldPacket.WriteString(equipSet->SetIcon);
    }

    return &_worldPacket;
}

void WorldPackets::EquipmentSet::SaveEquipmentSet::Read()
{
    _worldPacket >> As<int32>(Set.Type);
    _worldPacket >> Set.Guid;
    _worldPacket >> Set.SetID;
    _worldPacket >> Set.IgnoreMask;

    for (uint8 i = 0; i < EQUIPMENT_SET_SLOTS; ++i)
    {
        _worldPacket >> Set.Pieces[i];
        _worldPacket >> Set.Appearances[i];
    }

    _worldPacket >> Set.Enchants[0];
    _worldPacket >> Set.Enchants[1];

    _worldPacket >> Set.SecondaryShoulderApparanceID;
    _worldPacket >> Set.SecondaryShoulderSlot;
    _worldPacket >> Set.SecondaryWeaponAppearanceID;
    _worldPacket >> Set.SecondaryWeaponSlot;

    bool hasSpecIndex = _worldPacket.ReadBit();

    uint32 setNameLength = _worldPacket.ReadBits(8);
    uint32 setIconLength = _worldPacket.ReadBits(9);

    if (hasSpecIndex)
        _worldPacket >> Set.AssignedSpecIndex;

    Set.SetName = _worldPacket.ReadString(setNameLength);
    Set.SetIcon = _worldPacket.ReadString(setIconLength);
}

void WorldPackets::EquipmentSet::DeleteEquipmentSet::Read()
{
    _worldPacket >> ID;
}

void WorldPackets::EquipmentSet::UseEquipmentSet::Read()
{
    _worldPacket >> Inv;

    for (uint8 i = 0; i < EQUIPMENT_SET_SLOTS; ++i)
    {
        _worldPacket >> Items[i].Item;
        _worldPacket >> Items[i].ContainerSlot;
        _worldPacket >> Items[i].Slot;
    }

    _worldPacket >> GUID;
}

WorldPacket const* WorldPackets::EquipmentSet::UseEquipmentSetResult::Write()
{
    _worldPacket << int32(Reason);
    _worldPacket << uint64(GUID);

    return &_worldPacket;
}
