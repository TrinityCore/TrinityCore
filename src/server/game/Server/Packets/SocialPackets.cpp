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
#include "SocialMgr.h"

namespace WorldPackets::Social
{
void SendContactList::Read()
{
    _worldPacket >> Flags;
}

ByteBuffer& operator<<(ByteBuffer& data, ContactInfo const& contact)
{
    data << contact.Guid;
    data << uint32(contact.TypeFlags);
    data << contact.Notes;
    if (contact.TypeFlags & SOCIAL_FLAG_FRIEND)              // if IsFriend()
    {
        data << uint8(contact.Status);
        if (contact.Status)                            // if online
        {
            data << uint32(contact.AreaID);
            data << uint32(contact.Level);
            data << uint32(contact.ClassID);
        }
    }

    return data;
}

WorldPacket const* ContactList::Write()
{
    _worldPacket << uint32(Flags);
    _worldPacket << uint32(Contacts.size());

    for (ContactInfo const& contact : Contacts)
        _worldPacket << contact;

    return &_worldPacket;
}

WorldPacket const* FriendStatus::Write()
{
    _worldPacket << uint8(FriendResult);
    _worldPacket << Guid;

    switch (FriendResult)
    {
        case FRIEND_ADDED_ONLINE:
            _worldPacket << Notes;
            [[fallthrough]];
        case FRIEND_ONLINE:
            _worldPacket << uint8(Status);
            _worldPacket << uint32(AreaID);
            _worldPacket << uint32(Level);
            _worldPacket << uint32(ClassID);
            break;
        case FRIEND_ADDED_OFFLINE:
            _worldPacket << Notes;
            break;
        default:
            break;
    }

    return &_worldPacket;
}

void AddFriend::Read()
{
    _worldPacket >> Name;
    _worldPacket >> Notes;
}

void DelFriend::Read()
{
    _worldPacket >> Player;
}

void SetContactNotes::Read()
{
    _worldPacket >> Player;
    _worldPacket >> Notes;
}

void AddIgnore::Read()
{
    _worldPacket >> Name;
}

void DelIgnore::Read()
{
    _worldPacket >> Player;
}
}
