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

#include "PartyPackets.h"

void WorldPackets::Party::SetPartyLeader::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID; 
}

void WorldPackets::Party::PartyInvite::Read()
{
    _worldPacket >> PartyIndex; 
    _worldPacket >> ProposedRoles;
    _worldPacket >> TargetGUID;
    _worldPacket >> TargetCfgRealmID;
    
	_worldPacket.ResetBitPos(); //packet.ResetBitReader(); in WPP
    
    uint32 lenTargetName = _worldPacket.ReadBits(9);
    TargetName = _worldPacket.ReadString(lenTargetName);
    uint32 lenTargetRealm = _worldPacket.ReadBits(9);
    TargetRealm = _worldPacket.ReadString(lenTargetRealm);
}

void WorldPackets::Party::ConvertRaid::Read()
{
    Raid = _worldPacket.ReadBit();
}


