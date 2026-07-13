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
    _worldPacket << uint32(SetID);
    _worldPacket.appendPackGUID(GUID);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::EquipmentSet::LoadEquipmentSet::Write()
{
    _worldPacket << uint32(SetData.size());

    for (EquipmentSetInfo::EquipmentSetData const* equipSet : SetData)
    {
        _worldPacket.appendPackGUID(equipSet->Guid);
        _worldPacket << uint32(equipSet->SetID);
        _worldPacket << equipSet->SetName;
        _worldPacket << equipSet->SetIcon;

        for (uint32 i = 0; i < EQUIPMENT_SET_SLOTS; ++i)
        {
            // ignored slots stored in IgnoreMask, client wants "1" as raw GUID, so no HighGuid::Item
            if (equipSet->IgnoreMask & (1 << i))
                _worldPacket << EquipmentSetInfo::IgnoredSlot.WriteAsPacked();
            else
                _worldPacket << equipSet->Pieces[i].WriteAsPacked();
        }
    }

    return &_worldPacket;
}

void WorldPackets::EquipmentSet::SaveEquipmentSet::Read()
{
    _worldPacket.readPackGUID(Set.Guid);
    _worldPacket >> Set.SetID;
    _worldPacket >> Set.SetName;
    _worldPacket >> Set.SetIcon;

    for (uint8 i = 0; i < EQUIPMENT_SET_SLOTS; ++i)
        _worldPacket >> Set.Pieces[i].ReadAsPacked();
}
