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

#include "MessageBuffer.h"
#include "Log.h"
#include <atomic>
#include <vector>
#include <mutex>
#include <queue>
#include <memory>
#include <functional>
#include <type_traits>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <boost/asio/read.hpp>

using boost::asio::ip::tcp;

#define READ_BLOCK_SIZE 4096

template<class T>
class Socket : public std::enable_shared_from_this<T>
{
public:
    explicit Socket(tcp::socket&& socket) : _socket(std::move(socket)), _remoteAddress(_socket.remote_endpoint().address()),
        _remotePort(_socket.remote_endpoint().port()), _readBuffer(), _closed(false), _closing(false), _isWritingAsync(false)
    {
        _readBuffer.Resize(READ_BLOCK_SIZE);
    }

    virtual ~Socket()
    {
        boost::system::error_code error;
        _socket.close(error);
    }

    virtual void Start() = 0;

    virtual bool Update()
    {
        if (!IsOpen())
            return false;

#ifndef BOOST_ASIO_HAS_IOCP
        if (_isWritingAsync || (!_writeBuffer.GetActiveSize() && _writeQueue.empty()))
            return true;

        for (; WriteHandler(boost::system::error_code(), 0);)
            ;
#endif

        return true;
    }

    boost::asio::ip::address GetRemoteIpAddress() const
    {
        return _remoteAddress;
    }

    uint16 GetRemotePort() const
    {
        return _remotePort;
    }

    void AsyncRead()
    {
        if (!IsOpen())
            return;

        _readBuffer.Normalize();
        _socket.async_read_some(boost::asio::buffer(_readBuffer.GetWritePointer(), READ_BLOCK_SIZE),
            std::bind(&Socket<T>::ReadHandlerInternal, this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
    }

    void ReadData(std::size_t size)
    {
        if (!IsOpen())
            return;

        boost::system::error_code error;

        std::size_t bytesRead = boost::asio::read(_socket, boost::asio::buffer(_readBuffer.GetWritePointer(), size), error);

        _readBuffer.WriteCompleted(bytesRead);

        if (error || bytesRead != size)
        {
            TC_LOG_DEBUG("network", "Socket::ReadData: %s errored with: %i (%s)", GetRemoteIpAddress().to_string().c_str(), error.value(),
                error.message().c_str());

            CloseSocket();
        }
    }

    void QueuePacket(MessageBuffer&& buffer, std::unique_lock<std::mutex>& guard)
    {
        _writeQueue.push(std::move(buffer));

#ifdef BOOST_ASIO_HAS_IOCP
        AsyncProcessQueue(guard);
#else
        (void)guard;
#endif
    }

    bool IsOpen() const { return !_closed && !_closing; }

    void CloseSocket()
    {
        if (_closed.exchange(true))
            return;

        boost::system::error_code shutdownError;
        _socket.shutdown(boost::asio::socket_base::shutdown_send, shutdownError);
        if (shutdownError)
            TC_LOG_DEBUG("network", "Socket::CloseSocket: %s errored when shutting down socket: %i (%s)", GetRemoteIpAddress().to_string().c_str(),
                shutdownError.value(), shutdownError.message().c_str());
    }

    /// Marks the socket for closing after write buffer becomes empty
    void DelayedCloseSocket() { _closing = true; }

    MessageBuffer& GetReadBuffer() { return _readBuffer; }

protected:
    virtual void ReadHandler() = 0;

    bool AsyncProcessQueue(std::unique_lock<std::mutex>&)
    {
        if (_isWritingAsync)
            return true;

        _isWritingAsync = true;
        
#ifdef BOOST_ASIO_HAS_IOCP
        MessageBuffer& buffer = _writeQueue.front();
        _socket.async_write_some(boost::asio::buffer(buffer.GetReadPointer(), buffer.GetActiveSize()), std::bind(&Socket<T>::WriteHandler,
            this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
#else
        _socket.async_write_some(boost::asio::null_buffers(), std::bind(&Socket<T>::WriteHandler, this->shared_from_this(), std::placeholders::_1, std::placeholders::_2));
#endif

        return true;
    }

    std::mutex _writeLock;
    std::queue<MessageBuffer> _writeQueue;
#ifndef BOOST_ASIO_HAS_IOCP
    MessageBuffer _writeBuffer;
#endif

private:
    void ReadHandlerInternal(boost::system::error_code error, size_t transferredBytes)
    {
        if (error)
        {
            CloseSocket();
            return;
        }

        _readBuffer.WriteCompleted(transferredBytes);
        ReadHandler();
    }

#ifdef BOOST_ASIO_HAS_IOCP

    void WriteHandler(boost::system::error_code error, std::size_t transferedBytes)
    {
        if (!error)
        {
            std::unique_lock<std::mutex> deleteGuard(_writeLock);

            _isWritingAsync = false;
            _writeQueue.front().ReadCompleted(transferedBytes);
            if (!_writeQueue.front().GetActiveSize())
                _writeQueue.pop();

            if (!_writeQueue.empty())
                AsyncProcessQueue(deleteGuard);
            else if (_closing)
                CloseSocket();
        }
        else
            CloseSocket();
    }

#else

    bool WriteHandler(boost::system::error_code /*error*/, std::size_t /*transferedBytes*/)
    {
        std::unique_lock<std::mutex> guard(_writeLock, std::try_to_lock);
        if (!guard)
            return false;

        if (!IsOpen())
            return false;

        std::size_t bytesToSend = _writeBuffer.GetActiveSize();

        if (bytesToSend == 0)
            return HandleQueue(guard);

        boost::system::error_code error;
        std::size_t bytesWritten = _socket.write_some(boost::asio::buffer(_writeBuffer.GetReadPointer(), bytesToSend), error);

        if (error)
        {
            if (error == boost::asio::error::would_block || error == boost::asio::error::try_again)
                return AsyncProcessQueue(guard);

            return false;
        }
        else if (bytesWritten == 0)
            return false;
        else if (bytesWritten < bytesToSend) //now n > 0
        {
            _writeBuffer.ReadCompleted(bytesWritten);
            _writeBuffer.Normalize();
            return AsyncProcessQueue(guard);
        }

        // now bytesWritten == bytesToSend
        _writeBuffer.Reset();

        return HandleQueue(guard);
    }

    bool HandleQueue(std::unique_lock<std::mutex>& guard)
    {
        if (_writeQueue.empty())
        {
            _isWritingAsync = false;
            return false;
        }

        MessageBuffer& queuedMessage = _writeQueue.front();

        std::size_t bytesToSend = queuedMessage.GetActiveSize();

        boost::system::error_code error;
        std::size_t bytesSent = _socket.write_some(boost::asio::buffer(queuedMessage.GetReadPointer(), bytesToSend), error);

        if (error)
        {
            if (error == boost::asio::error::would_block || error == boost::asio::error::try_again)
                return AsyncProcessQueue(guard);

            _writeQueue.pop();
            return false;
        }
        else if (bytesSent == 0)
        {
            _writeQueue.pop();
            return false;
        }
        else if (bytesSent < bytesToSend) // now n > 0
        {
            queuedMessage.ReadCompleted(bytesSent);
            return AsyncProcessQueue(guard);
        }

        _writeQueue.pop();
        if (_writeQueue.empty())
        {
            _isWritingAsync = false;
            return false;
        }

        return true;
    }

#endif

    tcp::socket _socket;

    boost::asio::ip::address _remoteAddress;
    uint16 _remotePort;

    MessageBuffer _readBuffer;

    std::atomic<bool> _closed;
    std::atomic<bool> _closing;

    bool _isWritingAsync;
};

#endif // __SOCKET_H__
