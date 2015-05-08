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
#include "ObjectMgr.h"
#include "PacketUtilities.h"

void WorldPackets::Party::SetPartyLeader::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID; 
}

void WorldPackets::Party::SetRole::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> ChangedUnit;
    _worldPacket >> Role;
}

void WorldPackets::Party::PartyUninvite::Read()
{
    _worldPacket >> PartyIndex;
    _worldPacket >> TargetGUID;
    uint32 lenReason = _worldPacket.ReadBits(8);
    Reason = _worldPacket.ReadString(lenReason);
}

void WorldPackets::Party::ClientPartyInvite::Read()
{
    _worldPacket >> PartyIndex; 
    _worldPacket >> ProposedRoles;
    _worldPacket >> TargetGUID;
    _worldPacket >> TargetCfgRealmID;
    
    uint32 lenTargetName = _worldPacket.ReadBits(9);
    uint32 lenTargetRealm = _worldPacket.ReadBits(9);
    TargetName = _worldPacket.ReadString(lenTargetName);
    TargetRealm = _worldPacket.ReadString(lenTargetRealm);
}

void WorldPackets::Party::PartyInviteResponse::Read()
{
    _worldPacket >> PartyIndex;

    Accept = _worldPacket.ReadBit();
    HasRolesDesired = _worldPacket.ReadBit();
    if (HasRolesDesired)
        _worldPacket >> RolesDesired;
}

void WorldPackets::Party::ConvertRaid::Read()
{
    Raid = _worldPacket.ReadBit();
}

WorldPacket const* WorldPackets::Party::PartyInvite::Write()
{
    _worldPacket.WriteBit(CanAccept);
    _worldPacket.WriteBit(MightCRZYou);
    _worldPacket.WriteBit(MustBeBNetFriend);
    _worldPacket.WriteBit(AllowMultipleRoles);
    _worldPacket.WriteBit(IsXRealm);

    _worldPacket.WriteBits(InviterName.length(), 6);

    _worldPacket << InviterGuid;
    _worldPacket << InviterBNetAccountID;

    _worldPacket << uint32(InviterCfgRealmID);
    _worldPacket << uint16(Unk1);

    _worldPacket.FlushBits();

    _worldPacket.WriteBit(IsLocal);
    _worldPacket.WriteBit(Unk2);

    _worldPacket.WriteBits(InviterRealmNameActual.length(), 8);
    _worldPacket.WriteBits(InviterRealmNameNormalized.length(), 8);
    _worldPacket.WriteString(InviterRealmNameActual);
    _worldPacket.WriteString(InviterRealmNameNormalized);

    _worldPacket << uint32(ProposedRoles);
    _worldPacket << uint32(LfgSlotsCount);
    _worldPacket << uint32(LfgCompletedMask);

    _worldPacket.WriteString(InviterName);

    /*for (uint32 i = 0; i < LfgSlotsCount; i++)
        _worldPacket << LfgSlots[i];*/
    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::PartyCommandResult::Write()
{
    _worldPacket.WriteBits(Name.length(), 9);
    _worldPacket.WriteBits(Command, 4);
    _worldPacket.WriteBits(Result, 6);
    _worldPacket << uint32(ResultData);
    _worldPacket << ResultGUID;
    _worldPacket.WriteString(Name);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::RoleChangedInform::Write()
{
    _worldPacket << PartyIndex;
    _worldPacket << From;
    _worldPacket << ChangedUnit;
    _worldPacket << uint32(OldRole);
    _worldPacket << uint32(NewRole);

    return &_worldPacket;
}

WorldPacket const* WorldPackets::Party::PartyUpdate::Write()
{
    _worldPacket << PartyFlags;
    _worldPacket << PartyIndex;
    _worldPacket << PartyType;

    _worldPacket << MyIndex;
    _worldPacket << LeaderGUID;
    _worldPacket << SequenceNum;
    _worldPacket << PartyGUID;

    _worldPacket << PlayerListCount;
    for (PlayerList const& list : _PlayerLists)
    {
        _worldPacket.WriteBits(list.Name.length(), 6);

        _worldPacket << list.Guid;

        _worldPacket << list.Connected;
        _worldPacket << list.Subgroup;
        _worldPacket << list.Flags;
        _worldPacket << list.RolesAssigned;
        _worldPacket << list.UnkByte;

        _worldPacket.WriteString(list.Name);
    }

    _worldPacket.WriteBit(HasLfgInfo);
    _worldPacket.WriteBit(HasLootSettings);
    _worldPacket.WriteBit(HasDifficultySettings);

    if (HasLfgInfo)
    {
        _worldPacket << MyLfgFlags;
        _worldPacket << LfgSlot;
        _worldPacket << MyLfgRandomSlot;
        _worldPacket << MyLfgPartialClear;
        _worldPacket << float(MyLfgGearDiff);
        _worldPacket << MyLfgStrangerCount;
        _worldPacket << MyLfgKickVoteCount;
        _worldPacket << LfgBootCount;

        _worldPacket.WriteBit(LfgAborted);
        _worldPacket.WriteBit(MyLfgFirstReward);
    }

    if (HasLootSettings)
    {
        _worldPacket << LootMethod;
        _worldPacket << LootMaster;
        _worldPacket << LootThreshold;
    }

    if (HasDifficultySettings)
    {
        _worldPacket << UnkInt4;
        _worldPacket << DungeonDifficultyID;
        _worldPacket << RaidDifficultyID;
    }

    return &_worldPacket;
}

