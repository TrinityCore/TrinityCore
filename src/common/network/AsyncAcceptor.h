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

#include "Concepts.h"
#include "IoContext.h"
#include "IpAddress.h"
#include "Log.h"
#include "Socket.h"
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/v6_only.hpp>
#include <atomic>

#define TRINITY_MAX_LISTEN_CONNECTIONS boost::asio::socket_base::max_listen_connections

namespace Trinity::Net
{
template <typename Callable>
concept AcceptCallback = std::invocable<Callable, IoContextTcpSocket&&>;

template <typename Callable>
concept SelectIoContextForNewSocketFn = Trinity::invocable_r<Callable, Asio::IoContext*>;

class AsyncAcceptor
{
public:
    AsyncAcceptor(Asio::IoContext& ioContext, std::string const& bindIp, uint16 port) :
        _acceptor(ioContext), _endpoint(make_address(bindIp), port), _closed(false)
    {
    }

    template <SelectIoContextForNewSocketFn SelectIoContextForNewSocket, AcceptCallback Callback>
    void AsyncAccept(SelectIoContextForNewSocket&& selectIoContext, Callback&& acceptCallback)
    {
        Asio::IoContext* context = selectIoContext();
        _acceptor.async_accept(context->get_executor(), [this,
            selectIoContext = std::forward<SelectIoContextForNewSocket>(selectIoContext),
            acceptCallback = std::forward<Callback>(acceptCallback)](boost::system::error_code const& error, IoContextTcpSocket&& socket) mutable
        {
            if (!error)
            {
                try
                {
                    socket.non_blocking(true);

                    acceptCallback(std::move(socket));
                }
                catch (boost::system::system_error const& err)
                {
                    TC_LOG_INFO("network", "Failed to initialize client's socket {}", err.what());
                }
            }

            if (!_closed)
                this->AsyncAccept(std::move(selectIoContext), std::move(acceptCallback));
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
        {
            _acceptor.set_option(boost::asio::ip::v6_only(false), errorCode);
            if (errorCode)
            {
                TC_LOG_INFO("network", "Could not disable v6_only option {}", errorCode.message());
                return false;
            }
        }

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

private:
    boost::asio::basic_socket_acceptor<boost::asio::ip::tcp, IoContextTcpSocket::executor_type> _acceptor;
    boost::asio::ip::tcp::endpoint _endpoint;
    std::atomic<bool> _closed;
};
}

#endif // TRINITYCORE_ASYNC_ACCEPTOR_H
