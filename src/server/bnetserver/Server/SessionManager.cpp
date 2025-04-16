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

#include "SessionManager.h"
#include "Util.h"

bool Battlenet::SessionManager::StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int threadCount)
{
    if (!BaseSocketMgr::StartNetwork(ioContext, bindIp, port, threadCount))
        return false;

    _acceptor->AsyncAccept([this](Trinity::Net::IoContextTcpSocket&& sock, uint32 threadIndex)
    {
        OnSocketOpen(std::move(sock), threadIndex);
    });
    return true;
}

Trinity::Net::NetworkThread<Battlenet::Session>* Battlenet::SessionManager::CreateThreads() const
{
    return new Trinity::Net::NetworkThread<Session>[GetNetworkThreadCount()];
}

Battlenet::SessionManager& Battlenet::SessionManager::Instance()
{
    static SessionManager instance;
    return instance;
}
