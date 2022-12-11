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
#include "PetDefines.h"

WorldPacket const* WorldPackets::Pet::PetDismissSound::Write()
{
    _worldPacket << int32(ModelID);
    _worldPacket << ModelPosition;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetGuids::Write()
{
    _worldPacket << int32(PetGUIDs.size());
    for (ObjectGuid const& guid : PetGUIDs)
        _worldPacket << guid;

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::SPetMode::Write()
{
    _worldPacket << PetGUID;
    _worldPacket << uint32(PetMode);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetActionFeedback::Write()
{
    _worldPacket << uint8(Response);

    switch (Response)
    {
        case FEEDBACK_NOTHING_TO_ATT:
        case FEEDBACK_CANT_ATT_TARGET:
            _worldPacket << int32(SpellID);
            break;
        default:
            break;
    }

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetActionSound::Write()
{
    _worldPacket << UnitGUID;
    _worldPacket << int32(Action);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Pet::PetAdded::Write()
{
    _worldPacket << int32(Level);
    _worldPacket << int32(PetSlot);
    _worldPacket << uint8(Flags);
    _worldPacket << int32(CreatureID);
    _worldPacket << int32(PetNumber);
    _worldPacket.WriteBits(Name.length(), 8);
    _worldPacket << Name;

    return &_worldPacket;
}
