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

#include "SocialPackets.h"
#include "PacketUtilities.h"
#include "SocialMgr.h"
#include "World.h"

namespace WorldPackets::Social
{
void SendContactList::Read()
{
    _worldPacket >> Flags;
}

ContactInfo::ContactInfo(ObjectGuid const& guid, FriendInfo const& friendInfo)
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

ByteBuffer& operator<<(ByteBuffer& data, ContactInfo const& contact)
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
    data << SizedString::BitsSize<10>(contact.Notes);
    data.FlushBits();

    data << SizedString::Data(contact.Notes);

    return data;
}

WorldPacket const* ContactList::Write()
{
    _worldPacket << uint32(Flags);
    _worldPacket << BitsSize<8>(Contacts);
    _worldPacket.FlushBits();

    for (ContactInfo const& contact : Contacts)
        _worldPacket << contact;

    return &_worldPacket;
}

void FriendStatus::Initialize(ObjectGuid const& guid, FriendsResult result, FriendInfo const& friendInfo)
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

WorldPacket const* FriendStatus::Write()
{
    _worldPacket << uint8(FriendResult);
    _worldPacket << Guid;
    _worldPacket << WowAccountGuid;
    _worldPacket << uint32(VirtualRealmAddress);
    _worldPacket << uint8(Status);
    _worldPacket << uint32(AreaID);
    _worldPacket << uint32(Level);
    _worldPacket << uint32(ClassID);
    _worldPacket << SizedString::BitsSize<10>(Notes);
    _worldPacket.FlushBits();

    _worldPacket << SizedString::Data(Notes);

    return &_worldPacket;
}

ByteBuffer& operator>>(ByteBuffer& data, QualifiedGUID& qGuid)
{
    data >> qGuid.VirtualRealmAddress;
    data >> qGuid.Guid;

    return data;
}

void AddFriend::Read()
{
    _worldPacket >> SizedString::BitsSize<9>(Name);
    _worldPacket >> SizedString::BitsSize<9>(Notes);
    _worldPacket >> SizedString::Data(Name);
    _worldPacket >> SizedString::Data(Notes);
}

void DelFriend::Read()
{
    _worldPacket >> Player;
}

void SetContactNotes::Read()
{
    _worldPacket >> Player;
    _worldPacket >> SizedString::BitsSize<10>(Notes);
    _worldPacket >> SizedString::Data(Notes);
}

void AddIgnore::Read()
{
    _worldPacket >> SizedString::BitsSize<9>(Name);
    _worldPacket >> AccountGUID;
    _worldPacket >> SizedString::Data(Name);
}

void DelIgnore::Read()
{
    _worldPacket >> Player;
}

WorldPacket const* WorldPackets::Social::SocialContractRequestResponse::Write()
{
    _worldPacket << Bits<1>(ShowSocialContract);
    _worldPacket.FlushBits();

    return &_worldPacket;
}
}
