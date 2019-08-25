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

#ifndef SocketMgr_h__
#define SocketMgr_h__

#include "AsyncAcceptor.h"
#include "Errors.h"
#include "NetworkThread.h"
#include <boost/asio/ip/tcp.hpp>
#include <memory>

using boost::asio::ip::tcp;

template<class SocketType>
class SocketMgr
{
    using PNetThreadT = std::unique_ptr< NetworkThread<SocketType> > ;
public:
    virtual ~SocketMgr()
    {
        ASSERT(!_threads.empty() && !_acceptor, "StopNetwork must be called prior to SocketMgr destruction");
    }

    virtual bool StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int threadCount)
    {
        ASSERT(threadCount > 0);

        AsyncAcceptor* acceptor = nullptr;
        try
        {
            acceptor = new AsyncAcceptor(ioContext, bindIp, port);
        }
        catch (boost::system::system_error const& err)
        {
            TC_LOG_ERROR("network", "Exception caught in SocketMgr.StartNetwork (%s:%u): %s", bindIp.c_str(), port, err.what());
            return false;
        }

        if (!acceptor->Bind())
        {
            TC_LOG_ERROR("network", "StartNetwork failed to bind socket acceptor");
            delete acceptor;
            return false;
        }

        _acceptor = acceptor;
        _threads.reserve(threadCount); // Reserve memory for pointers
        // Create the _threads
        for (size_t i=0; i < threadCount; i++) {
            _threads.push_back(std::make_unique<NetworkThread<SocketType>>());
        };

        ASSERT(!_threads.empty());

        for (auto& thread : _threads) {
            thread->Start();
        }

        return true;
    }

    virtual void StopNetwork()
    {
        _acceptor->Close();

        for (auto& thread : _threads) {
            thread->Stop();
        };

        Wait();

        delete _acceptor;
        _acceptor = nullptr;
        _threads.clear();
    }

    void Wait()
    {
        for (auto& thread : _threads) {
            thread->Wait();
        }
    }

    virtual void OnSocketOpen(tcp::socket&& sock, uint32 threadIndex)
    {
        try
        {
            std::shared_ptr<SocketType> newSocket = std::make_shared<SocketType>(std::move(sock));
            newSocket->Start();

            _threads[threadIndex]->AddSocket(newSocket);
        }
        catch (boost::system::system_error const& err)
        {
            TC_LOG_WARN("network", "Failed to retrieve client's remote address %s", err.what());
        }
    }

    uint32 SelectThreadWithMinConnections() const
    {
        uint32 min = 0;

        for (size_t i{1}; i < _threads.size(); ++i)
            if (_threads[i]->GetConnectionCount() < _threads[min]->GetConnectionCount())
                min = i;

        return min;
    }

    std::pair<tcp::socket*, uint32> GetSocketForAccept()
    {
        uint32 threadIndex = SelectThreadWithMinConnections();
        return std::make_pair(_threads[threadIndex]->GetSocketForAccept(), threadIndex);

        //Easier to understand?? Define comparison lambda for pointers to _threads
        //auto comp = [](const PNetThreadT& nt1, const PNetThreadT& nt2) { return *nt1.GetConnectionCount() < *nt2.GetConnectionCount(); };
        //auto iter = std::min_element(std::begin(_threads), std::end(_threads), comp);
        //return std::make_pair( (*iter)->GetSocketForAccept(), (iter - _threads.begin()) );
    }

protected:
    SocketMgr() : _acceptor(nullptr), _threads(0)
    {
    }

    AsyncAcceptor* _acceptor;
    std::vector<PNetThreadT> _threads;
};

#endif // SocketMgr_h__
