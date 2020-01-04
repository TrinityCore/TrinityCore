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
#include "Containers.h"
#include "Hash.h"
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

namespace
{
    std::unordered_map<std::pair<uint32 /*accountId*/, uint32 /*gameAccountId*/>, Battlenet::Session*> _sessions;
    std::unordered_map<uint32, std::list<Battlenet::Session*>> _sessionsByAccountId;
    boost::shared_mutex _sessionMutex;
}

Battlenet::SessionManager::SessionManager() : SocketMgr<Session>()
{
}

Battlenet::SessionManager::~SessionManager()
{
}

Battlenet::SessionManager& Battlenet::SessionManager::Instance()
{
    static SessionManager instance;
    return instance;
}

bool Battlenet::SessionManager::StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int threadCount /*= 1*/)
{
    if (!BaseSocketMgr::StartNetwork(ioContext, bindIp, port, threadCount))
        return false;

    _acceptor->SetSocketFactory(std::bind(&BaseSocketMgr::GetSocketForAccept, this));
    _acceptor->AsyncAcceptWithCallback<&OnSocketAccept>();
    return true;
}

NetworkThread<Battlenet::Session>* Battlenet::SessionManager::CreateThreads() const
{
    return new NetworkThread<Session>[GetNetworkThreadCount()];
}

void Battlenet::SessionManager::OnSocketAccept(tcp::socket&& sock, uint32 threadIndex)
{
    sSessionMgr.OnSocketOpen(std::forward<tcp::socket>(sock), threadIndex);
}

void Battlenet::SessionManager::AddSession(Session* session)
{
    std::unique_lock<boost::shared_mutex> lock(_sessionMutex);
    _sessions[{ session->GetAccountId(), session->GetGameAccountId() }] = session;
    _sessionsByAccountId[session->GetAccountId()].push_back(session);
}

void Battlenet::SessionManager::RemoveSession(Session* session)
{
    std::unique_lock<boost::shared_mutex> lock(_sessionMutex);
    auto itr = _sessions.find({ session->GetAccountId(), session->GetGameAccountId() });
    // Remove old session only if it was not overwritten by reconnecting
    if (itr != _sessions.end() && itr->second == session)
        _sessions.erase(itr);

    _sessionsByAccountId[session->GetAccountId()].remove(session);
}

Battlenet::Session* Battlenet::SessionManager::GetSession(uint32 accountId, uint32 gameAccountId) const
{
    boost::shared_lock<boost::shared_mutex> lock(_sessionMutex);
    return Trinity::Containers::MapGetValuePtr(_sessions, { accountId, gameAccountId });
}

std::list<Battlenet::Session*>* Battlenet::SessionManager::GetSessions(uint32 accountId) const
{
    boost::shared_lock<boost::shared_mutex> lock(_sessionMutex);
    return Trinity::Containers::MapGetValuePtr(_sessionsByAccountId, accountId);
}

void Battlenet::SessionManager::LockedForEach(std::function<void(Session*)>&& iterator) const
{
    boost::shared_lock<boost::shared_mutex> lock(_sessionMutex);
    for (auto const& pair : _sessions)
        iterator(pair.second);
}
