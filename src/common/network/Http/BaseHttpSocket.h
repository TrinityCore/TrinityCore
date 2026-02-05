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

#ifndef TRINITYCORE_BASE_HTTP_SOCKET_H
#define TRINITYCORE_BASE_HTTP_SOCKET_H

#include "HttpCommon.h"
#include "HttpSessionState.h"
#include "Optional.h"
#include "Socket.h"
#include "SocketConnectionInitializer.h"
#include <boost/beast/core/basic_stream.hpp>
#include <boost/beast/http/parser.hpp>
#include <boost/beast/http/string_body.hpp>

namespace Trinity::Net::Http
{
using IoContextHttpSocket = boost::beast::basic_stream<boost::asio::ip::tcp, boost::asio::io_context::executor_type, boost::beast::unlimited_rate_policy>;

namespace Impl
{
class BoostBeastSocketWrapper : public IoContextHttpSocket
{
public:
    using IoContextHttpSocket::basic_stream;

    bool is_open() const
    {
        return socket().is_open();
    }

    void close(boost::system::error_code& /*error*/)
    {
        IoContextHttpSocket::close();
    }

    void shutdown(boost::asio::socket_base::shutdown_type what, boost::system::error_code& shutdownError)
    {
        socket().shutdown(what, shutdownError);
    }

    template<typename WaitHandlerType>
    void async_wait(boost::asio::socket_base::wait_type type, WaitHandlerType&& handler)
    {
        socket().async_wait(type, std::forward<WaitHandlerType>(handler));
    }

    template <typename SettableSocketOption>
    void set_option(SettableSocketOption const& option, boost::system::error_code& ec)
    {
        socket().set_option(option, ec);
    }

    IoContextTcpSocket::endpoint_type remote_endpoint() const
    {
        return socket().remote_endpoint();
    }
};
}

using RequestParser = boost::beast::http::request_parser<RequestBody>;
using ResponseParser = boost::beast::http::response_parser<RequestBody>;

class TC_NETWORK_API AbstractSocket
{
public:
    AbstractSocket() = default;
    AbstractSocket(AbstractSocket const& other) = default;
    AbstractSocket(AbstractSocket&& other) = default;
    AbstractSocket& operator=(AbstractSocket const& other) = default;
    AbstractSocket& operator=(AbstractSocket&& other) = default;
    virtual ~AbstractSocket() = default;

    static bool ParseRequest(MessageBuffer& packet, RequestParser& parser);
    static bool ParseResponse(MessageBuffer& packet, ResponseParser& parser);

    static MessageBuffer SerializeRequest(Request const& request);
    static MessageBuffer SerializeResponse(Request const& request, Response const& response);

    virtual void SendResponse(RequestContext& context) = 0;

    void LogRequestAndResponse(RequestContext const& context, MessageBuffer& buffer) const;

    virtual std::string GetClientInfo() const = 0;

    static std::string GetClientInfo(boost::asio::ip::address const& address, uint16 port, SessionState const* state);

    virtual SessionState* GetSessionState() const = 0;

    Optional<boost::uuids::uuid> GetSessionId() const
    {
        if (SessionState* state = this->GetSessionState())
            return state->Id;

        return {};
    }

    virtual void Start() = 0;

    virtual bool Update() = 0;

    virtual boost::asio::ip::address const& GetRemoteIpAddress() const = 0;

    virtual bool IsOpen() const = 0;

    virtual void CloseSocket() = 0;
};

template <typename SocketImpl>
struct HttpConnectionInitializer final : SocketConnectionInitializer
{
    explicit HttpConnectionInitializer(SocketImpl* socket) : _socket(socket) { }

    void Start() override
    {
        _socket->ResetHttpParser();

        this->InvokeNext();
    }

private:
    SocketImpl* _socket;
};

template<typename Stream>
class BaseSocket : public Trinity::Net::Socket<Stream>, public AbstractSocket
{
    using Base = Trinity::Net::Socket<Stream>;

public:
    using Base::Base;

    BaseSocket(BaseSocket const& other) = delete;
    BaseSocket(BaseSocket&& other) = delete;
    BaseSocket& operator=(BaseSocket const& other) = delete;
    BaseSocket& operator=(BaseSocket&& other) = delete;

    ~BaseSocket() = default;

    SocketReadCallbackResult ReadHandler() final
    {
        MessageBuffer& packet = this->GetReadBuffer();
        while (packet.GetActiveSize() > 0)
        {
            if (!ParseRequest(packet, *_httpParser))
            {
                // Couldn't receive the whole data this time.
                break;
            }

            if (!HandleMessage(_httpParser->get()))
            {
                this->CloseSocket();
                return SocketReadCallbackResult::Stop;
            }

            this->ResetHttpParser();
        }

        return SocketReadCallbackResult::KeepReading;
    }

    bool HandleMessage(Request& request)
    {
        RequestContext context { .request = std::move(request) };

        if (!_state)
            _state = this->ObtainSessionState(context);

        RequestHandlerResult status = this->RequestHandler(context);

        if (status != RequestHandlerResult::Async)
            this->SendResponse(context);

        return status != RequestHandlerResult::Error;
    }

    virtual RequestHandlerResult RequestHandler(RequestContext& context) = 0;

    void SendResponse(RequestContext& context) final
    {
        context.response.prepare_payload();

        MessageBuffer buffer = SerializeResponse(context.request, context.response);

        this->LogRequestAndResponse(context, buffer);

        this->QueuePacket(std::move(buffer));

        if (!context.response.keep_alive())
            this->DelayedCloseSocket();
    }

    void Start() override { return this->Base::Start(); }

    bool Update() override { return this->Base::Update(); }

    boost::asio::ip::address const& GetRemoteIpAddress() const final { return this->Base::GetRemoteIpAddress(); }

    bool IsOpen() const final { return this->Base::IsOpen(); }

    void CloseSocket() final { return this->Base::CloseSocket(); }

    std::string GetClientInfo() const override
    {
        return AbstractSocket::GetClientInfo(this->GetRemoteIpAddress(), this->GetRemotePort(), this->_state.get());
    }

    SessionState* GetSessionState() const override { return _state.get(); }

    void ResetHttpParser()
    {
        this->_httpParser.reset();
        this->_httpParser.emplace();
        this->_httpParser->eager(true);
    }

protected:
    virtual std::shared_ptr<SessionState> ObtainSessionState(RequestContext& context) const = 0;

    Optional<RequestParser> _httpParser;
    std::shared_ptr<SessionState> _state;
};
}

#endif // TRINITYCORE_BASE_HTTP_SOCKET_H
