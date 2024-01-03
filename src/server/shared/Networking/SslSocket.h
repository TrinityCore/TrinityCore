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

#ifndef SslSocket_h__
#define SslSocket_h__

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/system/error_code.hpp>

namespace boostssl = boost::asio::ssl;

template<class Stream = boostssl::stream<boost::asio::ip::tcp::socket>>
class SslSocket
{
public:
    explicit SslSocket(boost::asio::ip::tcp::socket&& socket, boost::asio::ssl::context& sslContext) : _sslSocket(std::move(socket), sslContext)
    {
        _sslSocket.set_verify_mode(boostssl::verify_none);
    }

    // adapting tcp::socket api
    void close(boost::system::error_code& error)
    {
        _sslSocket.lowest_layer().close(error);
    }

    void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        _sslSocket.shutdown(shutdownError);
        _sslSocket.lowest_layer().shutdown(what, shutdownError);
    }

    template<typename MutableBufferSequence, typename ReadHandlerType>
    void async_read_some(MutableBufferSequence const& buffers, ReadHandlerType&& handler)
    {
        _sslSocket.async_read_some(buffers, std::move(handler));
    }

    template<typename ConstBufferSequence, typename WriteHandlerType>
    void async_write_some(ConstBufferSequence const& buffers, WriteHandlerType&& handler)
    {
        _sslSocket.async_write_some(buffers, std::move(handler));
    }

    template<typename ConstBufferSequence>
    std::size_t write_some(ConstBufferSequence const& buffers, boost::system::error_code& error)
    {
        return _sslSocket.write_some(buffers, error);
    }

    template<typename SettableSocketOption>
    void set_option(SettableSocketOption const& option, boost::system::error_code& error)
    {
        _sslSocket.lowest_layer().set_option(option, error);
    }

    boost::asio::ip::tcp::socket::endpoint_type remote_endpoint() const
    {
        return _sslSocket.lowest_layer().remote_endpoint();
    }

    // ssl api
    template<typename HandshakeHandlerType>
    void async_handshake(boostssl::stream_base::handshake_type type, HandshakeHandlerType&& handler)
    {
        _sslSocket.async_handshake(type, std::move(handler));
    }

protected:
    Stream _sslSocket;
};

#endif // SslSocket_h__
