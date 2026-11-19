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

#include "AreaTriggerPackets.h"
#include "PacketOperators.h"

namespace WorldPackets::AreaTrigger
{
void AreaTrigger::Read()
{
    _worldPacket >> AreaTriggerID;
    _worldPacket >> Bits<1>(Entered);
    _worldPacket >> Bits<1>(FromClient);
}

WorldPacket const* AreaTriggerDenied::Write()
{
    _worldPacket << int32(AreaTriggerID);
    _worldPacket << Bits<1>(Entered);
    _worldPacket.FlushBits();

    return &_worldPacket;
}

WorldPacket const* AreaTriggerPlaySpellVisual::Write()
{
    _worldPacket << AreaTriggerGUID;
    _worldPacket << uint32(SpellVisualID);

    return &_worldPacket;
}

void UpdateAreaTriggerVisual::Read()
{
    _worldPacket >> SpellID;
    _worldPacket >> Visual;
    _worldPacket >> TargetGUID;
}
}
