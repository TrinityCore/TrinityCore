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

#include "BattlenetSessionManager.h"

bool Battlenet::SessionManager::StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port)
{
    if (!BaseSocketMgr::StartNetwork(service, bindIp, port))
        return false;

    _acceptor->AsyncAcceptManaged(&OnSocketAccept);
    return true;
}

NetworkThread<Battlenet::Session>* Battlenet::SessionManager::CreateThreads() const
{
    return new NetworkThread<Session>[GetNetworkThreadCount()];
}

void Battlenet::SessionManager::OnSocketAccept(tcp::socket&& sock)
{
    sBattlenetSessionMgr.OnSocketOpen(std::forward<tcp::socket>(sock));
}
