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

#ifndef __SOCKET_H__
#define __SOCKET_H__

#include "Define.h"
#include "Log.h"
#include <vector>
#include <mutex>
#include <queue>
#include <memory>
#include <functional>
#include <type_traits>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>

using boost::asio::ip::tcp;

template<class T, class PacketType>
class Socket : public std::enable_shared_from_this<T>
{
public:
    Socket(tcp::socket&& socket, std::size_t headerSize) : _socket(std::move(socket)), _headerSize(headerSize) { }

    virtual void Start() = 0;

    boost::asio::ip::address GetRemoteIpAddress() const
    {
        boost::system::error_code error;
        auto ep = _socket.remote_endpoint(error);

        if (error)
        {
            TC_LOG_DEBUG("network", "Socket::GetRemoteIpAddress: errored with: %i (%s)", error.value(), error.message().c_str());
            return boost::asio::ip::address();
        }
        else
            return ep.address();
    }

    uint16 GetRemotePort() const
    {
        boost::system::error_code error;
        auto ep = _socket.remote_endpoint(error);

        if (error)
        {
            TC_LOG_DEBUG("network", "Socket::GetRemotePort: errored with: %i (%s)", error.value(), error.message().c_str());
            return 0;
        }
        else
            return ep.port();
    }

    void AsyncReadHeader()
    {
        _socket.async_read_some(boost::asio::buffer(_readBuffer, _headerSize), std::bind(&Socket<T, PacketType>::ReadHeaderHandlerInternal, this->shared_from_this(),
            std::placeholders::_1, std::placeholders::_2));
    }

    void AsyncReadData(std::size_t size, std::size_t bufferOffset)
    {
        _socket.async_read_some(boost::asio::buffer(&_readBuffer[bufferOffset], size), std::bind(&Socket<T, PacketType>::ReadDataHandlerInternal, this->shared_from_this(),
            std::placeholders::_1, std::placeholders::_2));
    }

    void ReadData(std::size_t size, std::size_t bufferOffset)
    {
        boost::system::error_code error;

        _socket.read_some(boost::asio::buffer(&_readBuffer[bufferOffset], size), error);

        if (error)
        {
            TC_LOG_DEBUG("network", "Socket::ReadData: %s errored with: %i (%s)", GetRemoteIpAddress().to_string().c_str(), error.value(), error.message().c_str());

            CloseSocket();
        }
    }

    void AsyncWrite(PacketType const& data)
    {
        boost::asio::async_write(_socket, boost::asio::buffer(data), std::bind(&Socket<T, PacketType>::WriteHandler, this->shared_from_this(), std::placeholders::_1,
            std::placeholders::_2));
    }

    bool IsOpen() const { return _socket.is_open(); }
    void CloseSocket()
    {
        boost::system::error_code error;
        _socket.close(error);
        if (error)
            TC_LOG_DEBUG("network", "Socket::CloseSocket: %s errored when closing socket: %i (%s)", GetRemoteIpAddress().to_string().c_str(),
                error.value(), error.message().c_str());
    }

    uint8* GetReadBuffer() { return _readBuffer; }

protected:
    virtual void ReadHeaderHandler(boost::system::error_code error, size_t transferedBytes) = 0;
    virtual void ReadDataHandler(boost::system::error_code error, size_t transferedBytes) = 0;

    std::mutex _writeLock;
    std::queue<PacketType> _writeQueue;

private:
    void ReadHeaderHandlerInternal(boost::system::error_code error, size_t transferedBytes) { ReadHeaderHandler(error, transferedBytes); }
    void ReadDataHandlerInternal(boost::system::error_code error, size_t transferedBytes) { ReadDataHandler(error, transferedBytes); }

    void WriteHandler(boost::system::error_code error, size_t /*transferedBytes*/)
    {
        if (!error)
        {
            std::lock_guard<std::mutex> deleteGuard(_writeLock);

            DeletePacket(_writeQueue.front());
            _writeQueue.pop();

            if (!_writeQueue.empty())
                AsyncWrite(_writeQueue.front());
        }
        else
            CloseSocket();
    }

    template<typename Q = PacketType>
    typename std::enable_if<std::is_pointer<Q>::value>::type DeletePacket(PacketType& packet) { delete packet; }

    template<typename Q = PacketType>
    typename std::enable_if<!std::is_pointer<Q>::value>::type DeletePacket(PacketType const& /*packet*/) { }

    tcp::socket _socket;

    uint8 _readBuffer[4096];

    std::size_t _headerSize;
};

#endif // __SOCKET_H__
