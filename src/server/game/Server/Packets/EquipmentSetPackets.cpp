/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

WorldPacket const* WorldPackets::EquipmentSet::LoadEquipmentSet::Write()
{
    _worldPacket << uint32(SetData.size());

    for (EquipmentSetData const& equipSet : SetData)
    {
        _worldPacket << uint64(equipSet.Guid);
        _worldPacket << uint32(equipSet.SetID);
        _worldPacket << uint32(equipSet.IgnoreMask);

        for (ObjectGuid const& guid : equipSet.Pieces)
            _worldPacket << guid;

        _worldPacket.WriteBits(equipSet.SetName.length(), 8);
        _worldPacket.WriteBits(equipSet.SetIcon.length(), 9);
        _worldPacket.WriteString(equipSet.SetName);
        _worldPacket.WriteString(equipSet.SetIcon);
    }

    return &_worldPacket;
}
