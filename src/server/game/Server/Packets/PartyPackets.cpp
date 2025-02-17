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

#include "PartyPackets.h"
#include "Player.h"

void WorldPackets::Party::PartyInviteClient::Read()
{
    _worldPacket >> TargetName;
    _worldPacket >> ProposedRoles;
}

WorldPacket const* WorldPackets::Party::PartyInvite::Write()
{
    _worldPacket << uint8(CanAccept);
    _worldPacket << InviterName;
    _worldPacket << uint32(ProposedRoles);
    _worldPacket << uint8(LfgSlots.size());
    if (!LfgSlots.empty())
        _worldPacket.append(LfgSlots.data(), LfgSlots.size());

    _worldPacket << uint32(LfgCompletedMask);

    return &_worldPacket;
}

void WorldPackets::Party::PartyInvite::Initialize(Player const* inviter, uint32 proposedRoles, bool canAccept)
{
    CanAccept = canAccept;

    InviterName = inviter->GetName();

    ProposedRoles = proposedRoles;
}
