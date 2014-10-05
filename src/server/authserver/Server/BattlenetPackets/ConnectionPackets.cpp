/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "BattlenetSession.h"
#include "ConnectionPackets.h"

std::string Battlenet::Connection::Ping::ToString() const
{
    return "Battlenet::Connection::Ping";
}

void Battlenet::Connection::Ping::CallHandler(Session* session) const
{
    session->HandlePing(*this);
}

std::string Battlenet::Connection::EnableEncryption::ToString() const
{
    return "Battlenet::Connection::EnableEncryption";
}

void Battlenet::Connection::EnableEncryption::CallHandler(Session* session) const
{
    session->HandleEnableEncryption(*this);
}

std::string Battlenet::Connection::LogoutRequest::ToString() const
{
    return "Battlenet::Connection::LogoutRequest";
}

void Battlenet::Connection::LogoutRequest::CallHandler(Session* session) const
{
    session->HandleLogoutRequest(*this);
}

std::string Battlenet::Connection::Pong::ToString() const
{
    return "Battlenet::Connection::Pong";
}
