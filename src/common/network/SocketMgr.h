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
template <typename Traits>
class SocketMgr
{
public:
    using Self = typename Traits::Self;
    using SocketType = typename Traits::SocketType;
    using ThreadType = typename Traits::ThreadType;

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
        _threads = static_cast<Self*>(this)->CreateThreads();

        ASSERT(_threads);

        for (int32 i = 0; i < _threadCount; ++i)
            _threads[i].Start();

        _acceptor->AsyncAccept(
            [this]{ return SelectThreadWithMinConnections(); },
            [this](IoContextTcpSocket&& sock) { static_cast<Self*>(this)->OnSocketOpen(std::move(sock)); });

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

    virtual void OnSocketOpen(IoContextTcpSocket&& sock)
    {
        try
        {
            int32 threadIndex = 0;
            for (; threadIndex < _threadCount; ++threadIndex)
                if (_threads[threadIndex].GetIoContext()->get_executor() == sock.get_executor())
                    break;

            std::shared_ptr<SocketType> newSocket = std::make_shared<SocketType>(std::move(sock));
            newSocket->Start();

            _threads[threadIndex].AddSocket(std::move(newSocket));
        }
        catch (boost::system::system_error const& err)
        {
            TC_LOG_WARN("network", "Failed to retrieve client's remote address {}", err.what());
        }
    }

    int32 GetNetworkThreadCount() const { return _threadCount; }

    Asio::IoContext* SelectThreadWithMinConnections() const
    {
        ThreadType* min = &_threads[0];

        for (ThreadType* i = min + 1; i != _threads.get() + _threadCount; ++i)
            if (i->GetConnectionCount() < min->GetConnectionCount())
                min = i;

        return min->GetIoContext();
    }

protected:
    SocketMgr() : _threadCount(0)
    {
    }

    virtual std::unique_ptr<ThreadType[]> CreateThreads() const
    {
        return std::make_unique<ThreadType[]>(GetNetworkThreadCount());
    }

    std::unique_ptr<AsyncAcceptor> _acceptor;
    std::unique_ptr<ThreadType[]> _threads;
    int32 _threadCount;
};
}

#endif // TRINITYCORE_SOCKET_MGR_H
