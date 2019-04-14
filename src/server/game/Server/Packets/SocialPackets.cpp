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

#include "SocialPackets.h"
#include "ObjectMgr.h"
#include "SocialMgr.h"
#include "World.h"

void WorldPackets::Social::SendContactList::Read()
{
    _worldPacket >> Flags;
}

WorldPackets::Social::ContactInfo::ContactInfo(ObjectGuid const& guid, FriendInfo const& friendInfo)
{
    Guid = guid;
    WowAccountGuid = friendInfo.WowAccountGuid;
    VirtualRealmAddr = GetVirtualRealmAddress();
    NativeRealmAddr = GetVirtualRealmAddress();
    TypeFlags = friendInfo.Flags;
    Notes = friendInfo.Note;
    Status = friendInfo.Status;
    AreaID = friendInfo.Area;
    Level = friendInfo.Level;
    ClassID = friendInfo.Class;
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Social::ContactInfo const& contact)
{
    data << contact.Guid;
    data << contact.WowAccountGuid;
    data << uint32(contact.VirtualRealmAddr);
    data << uint32(contact.NativeRealmAddr);
    data << uint32(contact.TypeFlags);
    data << uint8(contact.Status);
    data << uint32(contact.AreaID);
    data << uint32(contact.Level);
    data << uint32(contact.ClassID);
    data.WriteBits(contact.Notes.length(), 10);
    data.FlushBits();
    data.WriteString(contact.Notes);

    return data;
}

WorldPacket const* WorldPackets::Social::ContactList::Write()
{
    _worldPacket << uint32(Flags);
    _worldPacket.WriteBits(Contacts.size(), 8);
    _worldPacket.FlushBits();

    for (size_t i = 0; i < Contacts.size(); ++i)
        _worldPacket << Contacts[i];

    return &_worldPacket;
}

void WorldPackets::Social::FriendStatus::Initialize(ObjectGuid const& guid, FriendsResult result, FriendInfo const& friendInfo)
{
    VirtualRealmAddress = GetVirtualRealmAddress();
    Notes = friendInfo.Note;
    ClassID = friendInfo.Class;
    Status = friendInfo.Status;
    Guid = guid;
    WowAccountGuid = friendInfo.WowAccountGuid;
    Level = friendInfo.Level;
    AreaID = friendInfo.Area;
    FriendResult = result;
}

WorldPacket const* WorldPackets::Social::FriendStatus::Write()
{
    _worldPacket << uint8(FriendResult);
    _worldPacket << Guid;
    _worldPacket << WowAccountGuid;
    _worldPacket << uint32(VirtualRealmAddress);
    _worldPacket << uint8(Status);
    _worldPacket << uint32(AreaID);
    _worldPacket << uint32(Level);
    _worldPacket << uint32(ClassID);
    _worldPacket.WriteBits(Notes.length(), 10);
    _worldPacket.FlushBits();
    _worldPacket.WriteString(Notes);

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, WorldPackets::Social::QualifiedGUID& qGuid)
{
    data >> qGuid.VirtualRealmAddress;
    data >> qGuid.Guid;

    return data;
}

void WorldPackets::Social::AddFriend::Read()
{
    uint32 nameLength = _worldPacket.ReadBits(9);
    uint32 noteslength = _worldPacket.ReadBits(10);
    Name = _worldPacket.ReadString(nameLength);
    Notes = _worldPacket.ReadString(noteslength);
}

void WorldPackets::Social::DelFriend::Read()
{
    _worldPacket >> Player;
}

void WorldPackets::Social::SetContactNotes::Read()
{
    _worldPacket >> Player;
    Notes = _worldPacket.ReadString(_worldPacket.ReadBits(10));
}

void WorldPackets::Social::AddIgnore::Read()
{
    Name = _worldPacket.ReadString(_worldPacket.ReadBits(9));
}

void WorldPackets::Social::DelIgnore::Read()
{
    _worldPacket >> Player;
}
