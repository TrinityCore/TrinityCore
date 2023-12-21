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

#include "AsyncCallbackProcessor.h"
#include "DatabaseEnvFwd.h"
#include "HttpCommon.h"
#include "HttpSessionState.h"
#include "Optional.h"
#include "QueryCallback.h"
#include "Socket.h"
#include <boost/asio/buffers_iterator.hpp>
#include <boost/beast/http/parser.hpp>
#include <boost/beast/http/string_body.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace Trinity::Net::Http
{
using RequestParser = boost::beast::http::request_parser<RequestBody>;

class TC_SHARED_API AbstractSocket
{
public:
    AbstractSocket() = default;
    AbstractSocket(AbstractSocket const& other) = default;
    AbstractSocket(AbstractSocket&& other) = default;
    AbstractSocket& operator=(AbstractSocket const& other) = default;
    AbstractSocket& operator=(AbstractSocket&& other) = default;
    virtual ~AbstractSocket() = default;

    static bool ParseRequest(MessageBuffer& packet, RequestParser& parser);

    static std::string SerializeRequest(Request const& request);
    static MessageBuffer SerializeResponse(Request const& request, Response& response);

    virtual void SendResponse(RequestContext& context) = 0;

    virtual void QueueQuery(QueryCallback&& queryCallback) = 0;

    virtual std::string GetClientInfo() const = 0;

    virtual Optional<boost::uuids::uuid> GetSessionId() const = 0;
};

template<typename Derived, typename Stream>
class BaseSocket : public ::Socket<Derived, Stream>, public AbstractSocket
{
    using Base = ::Socket<Derived, Stream>;

public:
    template<typename... Args>
    explicit BaseSocket(boost::asio::ip::tcp::socket&& socket, Args&&... args)
        : Base(std::move(socket), std::forward<Args>(args)...) { }

    BaseSocket(BaseSocket const& other) = delete;
    BaseSocket(BaseSocket&& other) = delete;
    BaseSocket& operator=(BaseSocket const& other) = delete;
    BaseSocket& operator=(BaseSocket&& other) = delete;

    ~BaseSocket() = default;

    void ReadHandler() override
    {
        if (!this->IsOpen())
            return;

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
                break;
            }

            this->ResetHttpParser();
        }

        this->AsyncRead();
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

    void SendResponse(RequestContext& context) override
    {
        MessageBuffer buffer = SerializeResponse(context.request, context.response);

        TC_LOG_DEBUG("server.http", "{} Request {} {} done, status {}", this->GetClientInfo(), ToStdStringView(context.request.method_string()),
            ToStdStringView(context.request.target()), context.response.result_int());
        if (sLog->ShouldLog("server.http", LOG_LEVEL_TRACE))
        {
            sLog->OutMessage("server.http", LOG_LEVEL_TRACE, "{} Request: {}", this->GetClientInfo(),
                CanLogRequestContent(context) ? SerializeRequest(context.request) : "<REDACTED>");
            sLog->OutMessage("server.http", LOG_LEVEL_TRACE, "{} Response: {}", this->GetClientInfo(),
                CanLogResponseContent(context) ? std::string_view(reinterpret_cast<char const*>(buffer.GetBasePointer()), buffer.GetActiveSize()) : "<REDACTED>");
        }

        this->QueuePacket(std::move(buffer));

        if (!context.response.keep_alive())
            this->DelayedCloseSocket();
    }

    void QueueQuery(QueryCallback&& queryCallback) override
    {
        this->_queryProcessor.AddCallback(std::move(queryCallback));
    }

    bool Update() override
    {
        if (!this->Base::Update())
            return false;

        this->_queryProcessor.ProcessReadyCallbacks();
        return true;
    }

    std::string GetClientInfo() const override
    {
        std::string info;
        info.reserve(500);
        auto itr = StringFormatTo(std::back_inserter(info), "[{}:{}", this->GetRemoteIpAddress().to_string(), this->GetRemotePort());
        if (_state)
            itr = StringFormatTo(itr, ", Session Id: {}", boost::uuids::to_string(_state->Id));

        StringFormatTo(itr, "]");
        return info;
    }

    Optional<boost::uuids::uuid> GetSessionId() const final
    {
        if (this->_state)
            return this->_state->Id;

        return {};
    }

protected:
    void ResetHttpParser()
    {
        this->_httpParser.reset();
        this->_httpParser.emplace();
        this->_httpParser->eager(true);
    }

    virtual std::shared_ptr<SessionState> ObtainSessionState(RequestContext& context) const = 0;

    QueryCallbackProcessor _queryProcessor;
    Optional<RequestParser> _httpParser;
    std::shared_ptr<SessionState> _state;
};
}

#endif // TRINITYCORE_BASE_HTTP_SOCKET_H
