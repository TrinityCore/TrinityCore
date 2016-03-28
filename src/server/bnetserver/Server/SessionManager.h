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

#ifndef SessionManager_h__
#define SessionManager_h__

#include "SocketMgr.h"
#include "Session.h"

namespace Battlenet
{
    class SessionManager : public SocketMgr<Session>
    {
        typedef SocketMgr<Session> BaseSocketMgr;

    public:
        static SessionManager& Instance();

        bool StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port, int threadCount = 1) override;

    protected:
        NetworkThread<Session>* CreateThreads() const override;

    private:
        static void OnSocketAccept(tcp::socket&& sock, uint32 threadIndex);
    };
}

#define sSessionMgr Battlenet::SessionManager::Instance()

#endif // SessionManager_h__
