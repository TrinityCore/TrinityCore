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

#ifndef TRINITYCORE_ASYNC_ACCEPTOR_H
#define TRINITYCORE_ASYNC_ACCEPTOR_H

#include "IoContext.h"
#include "IpAddress.h"
#include "Log.h"
#include "Socket.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/v6_only.hpp>
#include <atomic>
#include <functional>

#define TRINITY_MAX_LISTEN_CONNECTIONS boost::asio::socket_base::max_listen_connections

namespace Trinity::Net
{
template <typename Callable>
concept AcceptCallback = std::invocable<Callable, IoContextTcpSocket&&, uint32>;

class AsyncAcceptor
{
public:
    AsyncAcceptor(Asio::IoContext& ioContext, std::string const& bindIp, uint16 port) :
        _acceptor(ioContext), _endpoint(make_address(bindIp), port),
        _socket(ioContext), _closed(false), _socketFactory([this] { return DefaultSocketFactory(); })
    {
    }

    template <AcceptCallback Callback>
    void AsyncAccept(Callback&& acceptCallback)
    {
        auto [tmpSocket, tmpThreadIndex] = _socketFactory();
        // TODO: get rid of temporary variables (clang 15 cannot handle variables from structured bindings as lambda captures)
        IoContextTcpSocket* socket = tmpSocket;
        uint32 threadIndex = tmpThreadIndex;
        _acceptor.async_accept(*socket, [this, socket, threadIndex, acceptCallback = std::forward<Callback>(acceptCallback)](boost::system::error_code const& error) mutable
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
                    TC_LOG_INFO("network", "Failed to initialize client's socket {}", err.what());
                }
            }

            if (!_closed)
                this->AsyncAccept(std::move(acceptCallback));
        });
    }

    bool Bind()
    {
        boost::system::error_code errorCode;
        _acceptor.open(_endpoint.protocol(), errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Failed to open acceptor {}", errorCode.message());
            return false;
        }

#if TRINITY_PLATFORM != TRINITY_PLATFORM_WINDOWS
        _acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true), errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Failed to set reuse_address option on acceptor {}", errorCode.message());
            return false;
        }
#endif

        // v6_only is enabled on some *BSD distributions by default
        // we want to allow both v4 and v6 connections to the same listener
        if (_endpoint.protocol() == boost::asio::ip::tcp::v6())
            _acceptor.set_option(boost::asio::ip::v6_only(false));

        _acceptor.bind(_endpoint, errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Could not bind to {}:{} {}", _endpoint.address(), _endpoint.port(), errorCode.message());
            return false;
        }

        _acceptor.listen(TRINITY_MAX_LISTEN_CONNECTIONS, errorCode);
        if (errorCode)
        {
            TC_LOG_INFO("network", "Failed to start listening on {}:{} {}", _endpoint.address(), _endpoint.port(), errorCode.message());
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

    void SetSocketFactory(std::function<std::pair<IoContextTcpSocket*, uint32>()> func) { _socketFactory = std::move(func); }

private:
    std::pair<IoContextTcpSocket*, uint32> DefaultSocketFactory() { return std::make_pair(&_socket, 0); }

    boost::asio::basic_socket_acceptor<boost::asio::ip::tcp, IoContextTcpSocket::executor_type> _acceptor;
    boost::asio::ip::tcp::endpoint _endpoint;
    IoContextTcpSocket _socket;
    std::atomic<bool> _closed;
    std::function<std::pair<IoContextTcpSocket*, uint32>()> _socketFactory;
};
}

#endif // TRINITYCORE_ASYNC_ACCEPTOR_H
