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

#ifndef __ASYNCACCEPT_H_
#define __ASYNCACCEPT_H_

#include "IoContext.h"
#include "IpAddress.h"
#include "Log.h"
#include <boost/asio/ip/tcp.hpp>
#include <functional>
#include <atomic>

using boost::asio::ip::tcp;

#if BOOST_VERSION >= 106600
#define TRINITY_MAX_LISTEN_CONNECTIONS boost::asio::socket_base::max_listen_connections
#else
#define TRINITY_MAX_LISTEN_CONNECTIONS boost::asio::socket_base::max_connections
#endif

class AsyncAcceptor
{
public:
    typedef void(*AcceptCallback)(tcp::socket&& newSocket, uint32 threadIndex);

    AsyncAcceptor(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port) :
        _acceptor(ioContext), _endpoint(Trinity::Net::make_address(bindIp), port),
        _socket(ioContext), _closed(false), _socketFactory(std::bind(&AsyncAcceptor::DefeaultSocketFactory, this))
    {
    }

    template<class T>
    void AsyncAccept();

    template<AcceptCallback acceptCallback>
    void AsyncAcceptWithCallback()
    {
        tcp::socket* socket;
        uint32 threadIndex;
        std::tie(socket, threadIndex) = _socketFactory();
        _acceptor.async_accept(*socket, [this, socket, threadIndex](boost::system::error_code error)
        {
            if (!error)
            {
                try
                {
                    socket->non_blocking(true);

                    acceptCallback(std::move(*socket), threadIndex);
                }
                catch (boost::system::system_error const& err)
                {
                    TC_LOG_INFO("network", "Failed to initialize client's socket %s", err.what());
                }
            }

            if (!_closed)
                this->AsyncAcceptWithCallback<acceptCallback>();
        });
    }

    bool Bind()
    {
        boost::system::error_code errorCode;
        _acceptor.open(_endpoint.protocol(), errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Failed to open acceptor %s", errorCode.message().c_str());
            return false;
        }

        _acceptor.bind(_endpoint, errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Could not bind to %s:%u %s", _endpoint.address().to_string().c_str(), _endpoint.port(), errorCode.message().c_str());
            return false;
        }

        _acceptor.listen(TRINITY_MAX_LISTEN_CONNECTIONS, errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Failed to start listening on %s:%u %s", _endpoint.address().to_string().c_str(), _endpoint.port(), errorCode.message().c_str());
            return false;
        }

        return true;
    }

    void Close()
    {
        if (_closed.exchange(true))
            return;

        boost::system::error_code err;
        _acceptor.close(err);
    }

    void SetSocketFactory(std::function<std::pair<tcp::socket*, uint32>()> func) { _socketFactory = func; }

private:
    std::pair<tcp::socket*, uint32> DefeaultSocketFactory() { return std::make_pair(&_socket, 0); }

    tcp::acceptor _acceptor;
    tcp::endpoint _endpoint;
    tcp::socket _socket;
    std::atomic<bool> _closed;
    std::function<std::pair<tcp::socket*, uint32>()> _socketFactory;
};

template<class T>
void AsyncAcceptor::AsyncAccept()
{
    _acceptor.async_accept(_socket, [this](boost::system::error_code error)
    {
        if (!error)
        {
            try
            {
                // this-> is required here to fix an segmentation fault in gcc 4.7.2 - reason is lambdas in a templated class
                std::make_shared<T>(std::move(this->_socket))->Start();
            }
            catch (boost::system::system_error const& err)
            {
                TC_LOG_INFO("network", "Failed to retrieve client's remote address %s", err.what());
            }
        }

        // lets slap some more this-> on this so we can fix this bug with gcc 4.7.2 throwing internals in yo face
        if (!_closed)
            this->AsyncAccept<T>();
    });
}

#endif /* __ASYNCACCEPT_H_ */
