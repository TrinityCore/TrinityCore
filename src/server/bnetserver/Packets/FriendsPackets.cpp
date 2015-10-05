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

#include "Session.h"
#include "FriendsPackets.h"

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

void Battlenet::Friends::SendInvitationRequest::Read()
{
    Token = _stream.Read<uint32>(32);

    if (_stream.Read<bool>(1))
        PresenceId = _stream.Read<uint32>(32);

    if (_stream.Read<bool>(1))
        AccountMail = _stream.ReadString(9, 3);

    if (_stream.Read<bool>(1))
        AccountId = _stream.Read<uint32>(32);

    if (_stream.Read<bool>(1))
    {
        GameAccount = boost::in_place();
        GameAccount->Region = _stream.Read<uint8>(8);
        GameAccount->ProgramId = _stream.ReadFourCC();
        GameAccount->Id = _stream.Read<uint32>(32);
    }

    _stream.ReadSkip(7);

    if (_stream.Read<bool>(1))
        Nickname = _stream.ReadString(7);

    Source = _stream.ReadFourCC();
    Role = _stream.Read<uint32>(32);

    if (_stream.Read<bool>(1))
        InvitationMsg = _stream.ReadString(9);
}

std::string Battlenet::Friends::SendInvitationRequest::ToString() const
{
    std::ostringstream stream;
    stream << "Battlenet::Friends::SendInvitationRequest" << std::endl;
    APPEND_FIELD(stream, Token);
    APPEND_FIELD(stream, PresenceId);
    APPEND_FIELD(stream, GameAccount);
    APPEND_FIELD(stream, AccountId);
    APPEND_FIELD(stream, AccountMail);
    APPEND_FIELD(stream, Nickname);
    APPEND_FIELD(stream, InvitationMsg);
    APPEND_FIELD(stream, Source);
    APPEND_FIELD(stream, Role);
    return stream.str();
}

void Battlenet::Friends::SendInvitationRequest::CallHandler(Session* /*session*/)
{
}
