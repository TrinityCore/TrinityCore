/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef NetworkThread_h__
#define NetworkThread_h__

#include "Define.h"
#include "DeadlineTimer.h"
#include "Errors.h"
#include "IoContext.h"
#include "Log.h"
#include "Timer.h"
#include <boost/asio/ip/tcp.hpp>
#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>
#include <set>
#include <thread>

using boost::asio::ip::tcp;

template<class SocketType>
class NetworkThread
{
public:
    NetworkThread() : _connections(0), _stopped(false), _thread(nullptr), _ioContext(1),
        _acceptSocket(_ioContext), _updateTimer(_ioContext)
    {
    }

    virtual ~NetworkThread()
    {
        Stop();
        if (_thread)
        {
            Wait();
            delete _thread;
        }
    }

    void Stop()
    {
        _stopped = true;
        _ioContext.stop();
    }

    bool Start()
    {
        if (_thread)
            return false;

        _thread = new std::thread(&NetworkThread::Run, this);
        return true;
    }

    void Wait()
    {
        ASSERT(_thread);

        _thread->join();
        delete _thread;
        _thread = nullptr;
    }

    int32 GetConnectionCount() const
    {
        return _connections;
    }

    virtual void AddSocket(std::shared_ptr<SocketType> sock)
    {
        std::lock_guard<std::mutex> lock(_newSocketsLock);

        ++_connections;
        _newSockets.push_back(sock);
        SocketAdded(sock);
    }

    tcp::socket* GetSocketForAccept() { return &_acceptSocket; }

protected:
    virtual void SocketAdded(std::shared_ptr<SocketType> /*sock*/) { }
    virtual void SocketRemoved(std::shared_ptr<SocketType> /*sock*/) { }

    void AddNewSockets()
    {
        std::lock_guard<std::mutex> lock(_newSocketsLock);

        if (_newSockets.empty())
            return;

        for (std::shared_ptr<SocketType> sock : _newSockets)
        {
            if (!sock->IsOpen())
            {
                SocketRemoved(sock);
                --_connections;
            }
            else
                _sockets.push_back(sock);
        }

        _newSockets.clear();
    }

    void Run()
    {
        TC_LOG_DEBUG("misc", "Network Thread Starting");

        _updateTimer.expires_from_now(boost::posix_time::milliseconds(10));
        _updateTimer.async_wait(std::bind(&NetworkThread<SocketType>::Update, this));
        _ioContext.run();

        TC_LOG_DEBUG("misc", "Network Thread exits");
        _newSockets.clear();
        _sockets.clear();
    }

    void Update()
    {
        if (_stopped)
            return;

        _updateTimer.expires_from_now(boost::posix_time::milliseconds(10));
        _updateTimer.async_wait(std::bind(&NetworkThread<SocketType>::Update, this));

        AddNewSockets();

        _sockets.erase(std::remove_if(_sockets.begin(), _sockets.end(), [this](std::shared_ptr<SocketType> sock)
        {
            if (!sock->Update())
            {
                if (sock->IsOpen())
                    sock->CloseSocket();

                this->SocketRemoved(sock);

                --this->_connections;
                return true;
            }

            return false;
        }), _sockets.end());
    }

private:
    typedef std::vector<std::shared_ptr<SocketType>> SocketContainer;

    std::atomic<int32> _connections;
    std::atomic<bool> _stopped;

    std::thread* _thread;

    SocketContainer _sockets;

    std::mutex _newSocketsLock;
    SocketContainer _newSockets;

    Trinity::Asio::IoContext _ioContext;
    tcp::socket _acceptSocket;
    Trinity::Asio::DeadlineTimer _updateTimer;
};

#endif // NetworkThread_h__
