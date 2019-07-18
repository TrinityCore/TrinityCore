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

#include "TotemPackets.h"

void WorldPackets::Totem::TotemDestroyed::Read()
{
    _worldPacket >> Slot;
    _worldPacket >> TotemGUID;
}

WorldPacket const* WorldPackets::Totem::TotemCreated::Write()
{
    _worldPacket << uint8(Slot);
    _worldPacket << Totem;
    _worldPacket << int32(Duration);
    _worldPacket << int32(SpellID);
    _worldPacket << float(TimeMod);
    _worldPacket.WriteBit(CannotDismiss);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Totem::TotemMoved::Write()
{
    _worldPacket << uint8(Slot);
    _worldPacket << uint8(NewSlot);
    _worldPacket << Totem;

    return &_worldPacket;
}
