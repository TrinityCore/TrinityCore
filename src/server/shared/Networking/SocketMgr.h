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

#ifndef SocketMgr_h__
#define SocketMgr_h__

#include "AsyncAcceptor.h"
#include "Config.h"
#include "Errors.h"
#include "NetworkThread.h"
#include <boost/asio/ip/tcp.hpp>
#include <memory>

using boost::asio::ip::tcp;

template<class SocketType>
class SocketMgr
{
public:
    virtual ~SocketMgr()
    {
        delete[] _threads;
    }

    virtual bool StartNetwork(boost::asio::io_service& service, std::string const& bindIp, uint16 port)
    {
        _threadCount = sConfigMgr->GetIntDefault("Network.Threads", 1);

        if (_threadCount <= 0)
        {
            TC_LOG_ERROR("misc", "Network.Threads is wrong in your config file");
            return false;
        }

        _acceptor = new AsyncAcceptor(service, bindIp, port);
        _threads = CreateThreads();

        ASSERT(_threads);

        for (int32 i = 0; i < _threadCount; ++i)
            _threads[i].Start();

        return true;
    }

    virtual void StopNetwork()
    {
        if (_threadCount != 0)
            for (int32 i = 0; i < _threadCount; ++i)
                _threads[i].Stop();

        Wait();
    }

    void Wait()
    {
        if (_threadCount != 0)
            for (int32 i = 0; i < _threadCount; ++i)
                _threads[i].Wait();
    }

    virtual void OnSocketOpen(tcp::socket&& sock)
    {
        size_t min = 0;

        for (int32 i = 1; i < _threadCount; ++i)
            if (_threads[i].GetConnectionCount() < _threads[min].GetConnectionCount())
                min = i;

        try
        {
            std::shared_ptr<SocketType> newSocket = std::make_shared<SocketType>(std::move(sock));
            newSocket->Start();

            _threads[min].AddSocket(newSocket);
        }
        catch (boost::system::system_error const& err)
        {
            TC_LOG_INFO("network", "Failed to retrieve client's remote address %s", err.what());
        }
    }

    int32 GetNetworkThreadCount() const { return _threadCount; }

protected:
    SocketMgr() : _threads(nullptr), _threadCount(1)
    {
    }

    virtual NetworkThread<SocketType>* CreateThreads() const = 0;

    AsyncAcceptor* _acceptor;
    NetworkThread<SocketType>* _threads;
    int32 _threadCount;
};

#endif // SocketMgr_h__
