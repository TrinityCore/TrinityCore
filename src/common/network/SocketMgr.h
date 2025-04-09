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

#ifndef TRINITYCORE_SOCKET_MGR_H
#define TRINITYCORE_SOCKET_MGR_H

#include "AsyncAcceptor.h"
#include "Errors.h"
#include "NetworkThread.h"
#include "Socket.h"
#include <boost/asio/ip/tcp.hpp>
#include <memory>

namespace Trinity::Net
{
template<class SocketType>
class SocketMgr
{
public:
    SocketMgr(SocketMgr const&) = delete;
    SocketMgr(SocketMgr&&) = delete;
    SocketMgr& operator=(SocketMgr const&) = delete;
    SocketMgr& operator=(SocketMgr&&) = delete;

    virtual ~SocketMgr()
    {
        ASSERT(!_threads && !_acceptor && !_threadCount, "StopNetwork must be called prior to SocketMgr destruction");
    }

    virtual bool StartNetwork(Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int threadCount)
    {
        ASSERT(threadCount > 0);

        std::unique_ptr<AsyncAcceptor> acceptor = nullptr;
        try
        {
            acceptor = std::make_unique<AsyncAcceptor>(ioContext, bindIp, port);
        }
        catch (boost::system::system_error const& err)
        {
            TC_LOG_ERROR("network", "Exception caught in SocketMgr.StartNetwork ({}:{}): {}", bindIp, port, err.what());
            return false;
        }

        if (!acceptor->Bind())
        {
            TC_LOG_ERROR("network", "StartNetwork failed to bind socket acceptor");
            return false;
        }

        _acceptor = std::move(acceptor);
        _threadCount = threadCount;
        _threads.reset(CreateThreads());

        ASSERT(_threads);

        for (int32 i = 0; i < _threadCount; ++i)
            _threads[i].Start();

        _acceptor->SetSocketFactory([this]() { return GetSocketForAccept(); });

        return true;
    }

    virtual void StopNetwork()
    {
        _acceptor->Close();

        for (int32 i = 0; i < _threadCount; ++i)
            _threads[i].Stop();

        Wait();

        _acceptor = nullptr;
        _threads = nullptr;
        _threadCount = 0;
    }

    void Wait()
    {
        for (int32 i = 0; i < _threadCount; ++i)
            _threads[i].Wait();
    }

    virtual void OnSocketOpen(IoContextTcpSocket&& sock, uint32 threadIndex)
    {
        try
        {
            std::shared_ptr<SocketType> newSocket = std::make_shared<SocketType>(std::move(sock));
            newSocket->Start();

            _threads[threadIndex].AddSocket(newSocket);
        }
        catch (boost::system::system_error const& err)
        {
            TC_LOG_WARN("network", "Failed to retrieve client's remote address {}", err.what());
        }
    }

    int32 GetNetworkThreadCount() const { return _threadCount; }

    uint32 SelectThreadWithMinConnections() const
    {
        uint32 min = 0;

        for (int32 i = 1; i < _threadCount; ++i)
            if (_threads[i].GetConnectionCount() < _threads[min].GetConnectionCount())
                min = i;

        return min;
    }

    std::pair<IoContextTcpSocket*, uint32> GetSocketForAccept()
    {
        uint32 threadIndex = SelectThreadWithMinConnections();
        return std::make_pair(_threads[threadIndex].GetSocketForAccept(), threadIndex);
    }

protected:
    SocketMgr() : _threadCount(0)
    {
    }

    virtual NetworkThread<SocketType>* CreateThreads() const = 0;

    std::unique_ptr<AsyncAcceptor> _acceptor;
    std::unique_ptr<NetworkThread<SocketType>[]> _threads;
    int32 _threadCount;
};
}

#endif // TRINITYCORE_SOCKET_MGR_H
