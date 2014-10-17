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

#ifndef SessionManager_h__
#define SessionManager_h__

#include "Session.h"
#include "SocketMgr.h"
#include <boost/thread/locks.hpp>
#include <boost/thread/shared_mutex.hpp>

namespace Battlenet
{
#pragma pack(push, 1)

    struct SessionInfo
    {
        uint32 AccountId;
        uint32 GameAccountId;

        bool operator<(SessionInfo const& right) const
        {
            return memcmp(this, &right, sizeof(SessionInfo)) < 0;
        }
    };

#pragma pack(pop)

    class SessionManager : SocketMgr<Session>
    {
        typedef SocketMgr<Session> BaseSocketMgr;
        typedef std::map<SessionInfo, Session*> SessionMap;
        typedef std::map<uint32, std::list<Session*>> SessionByAccountMap;

    public:
        static SessionManager& Instance()
        {
            static SessionManager instance;
            return instance;
        }

        bool StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port) override;

        // noop for now, will be needed later to broadcast realmlist updates for example
        void AddSession(Session* /*session*/);

        void RemoveSession(Session* /*session*/);

        Session* GetSession(uint32 accountId, uint32 gameAccountId) const;
        std::list<Session*> GetSessions(uint32 accountId) const;

        template<typename Iterator>
        void LockedForEach(Iterator iterator)
        {
            boost::shared_lock<boost::shared_mutex> lock(_sessionMutex);
            for (SessionMap::value_type const& pair : _sessions)
                iterator(pair.second);
        }

    protected:
        NetworkThread<Session>* CreateThreads() const override;

    private:
        static void OnSocketAccept(tcp::socket&& sock);

        SessionMap _sessions;
        SessionByAccountMap _sessionsByAccountId;
        boost::shared_mutex _sessionMutex;
    };
}

#define sSessionMgr Battlenet::SessionManager::Instance()

#endif // SessionManager_h__
