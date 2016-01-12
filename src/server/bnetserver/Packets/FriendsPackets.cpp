/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Session.h"
#include "FriendsPackets.h"

void Battlenet::Friends::GetFriendsOfFriend::Read()
{
    _stream.Read<uint8>(2);
    _stream.Read<uint32>(32);
}

std::string Battlenet::Friends::GetFriendsOfFriend::ToString() const
{
    return "Battlenet::Friends::GetFriendsOfFriend";
}

void Battlenet::Friends::SocialNetworkCheckConnected::Read()
{
    SocialNetworkId = _stream.Read<uint32>(32);
}

std::string Battlenet::Friends::SocialNetworkCheckConnected::ToString() const
{
    return "Battlenet::Friends::SocialNetworkCheckConnected SocialNetworkId " + std::to_string(SocialNetworkId);
}

void Battlenet::Friends::SocialNetworkCheckConnected::CallHandler(Session* session)
{
    session->HandleSocialNetworkCheckConnected(*this);
}

void Battlenet::Friends::RealIdFriendInvite::Read()
{
    _stream.Read<uint32>(32);
    uint8 type = _stream.Read<uint8>(3);

    switch (type)
    {
        case 0:
        {
            _stream.Read<uint32>(32); // Presence Id?
            break;
        }
        case 1: // GameAccount?
        {
            _stream.Read<uint8>(8);
            _stream.Read<uint32>(32);
            _stream.Read<uint32>(32);
            uint8 size = _stream.Read<uint8>(7); // Only if *(a1 + 16) <= 0x64
            _stream.ReadBytes(size);
            break;
        }
        case 2:
            Email = _stream.ReadString(9, 3);
            break;
        case 3:
        {
            _stream.Read<uint32>(32);
            break;
        }
        case 4:
        {
            _stream.Read<uint64>(64);
            _stream.Read<uint32>(32);
            break;
        }
    }

    _stream.Read<uint8>(1);

    if (_stream.Read<uint8>(1))
        Message = _stream.ReadString(9);

    _stream.Read<uint32>(32);
}

std::string Battlenet::Friends::RealIdFriendInvite::ToString() const
{
    return "Battlenet::Friends::RealIdFriendInvite Mail: " + Email + " Message: " + Message;
}

std::string Battlenet::Friends::FriendInviteResult::ToString() const
{
    return "Battlenet::Friends::RealIdFriendInviteResult";
}

void Battlenet::Friends::FriendInviteResult::Write()
{
    bool hasNames = false;
    _stream.Write(hasNames, 1);
    if (hasNames)
    {
        _stream.WriteString("Testing1", 8);
        _stream.WriteString("Testing2", 8);
    }
    _stream.Write(5, 32);

    _stream.Write(0, 0xC); // Ignored

    _stream.Write(1, 16);

    bool moreInfo = true;
    _stream.Write(moreInfo, 1);
    if (moreInfo)
    {
        _stream.Write(0, 8);
        _stream.Write(4, 32);
        _stream.Write(3, 32);
        _stream.WriteString("Testing3", 7, 2);
    }
}

std::string Battlenet::Friends::SocialNetworkCheckConnectedResult::ToString() const
{
    return "Battlenet::Friends::SocialNetworkCheckConnectedResult";
}

void Battlenet::Friends::SocialNetworkCheckConnectedResult::Write()
{
    _stream.WriteSkip(23);
    _stream.Write(Result, 16);
    _stream.Write(SocialNetworkId, 32);
}
