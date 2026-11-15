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

#include "BaseHttpSocket.h"
#include "IpAddress.h"
#include <boost/asio/buffers_iterator.hpp>
#include <boost/beast/http/serializer.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace Trinity::Net::Http
{
using RequestSerializer = boost::beast::http::request_serializer<ResponseBody>;
using ResponseSerializer = boost::beast::http::response_serializer<ResponseBody>;

bool AbstractSocket::ParseRequest(MessageBuffer& packet, RequestParser& parser)
{
    if (!parser.is_done())
    {
        // need more data in the payload
        boost::system::error_code ec = {};
        std::size_t readDataSize = parser.put(boost::asio::const_buffer(packet.GetReadPointer(), packet.GetActiveSize()), ec);
        packet.ReadCompleted(readDataSize);
    }

    return parser.is_done();
}

bool AbstractSocket::ParseResponse(MessageBuffer& packet, ResponseParser& parser)
{
    if (!parser.is_done())
    {
        // need more data in the payload
        boost::system::error_code ec = {};
        std::size_t readDataSize = parser.put(boost::asio::const_buffer(packet.GetReadPointer(), packet.GetActiveSize()), ec);
        packet.ReadCompleted(readDataSize);
    }

    return parser.is_done();
}

MessageBuffer AbstractSocket::SerializeRequest(Request const& request)
{
    RequestSerializer serializer(request);

    MessageBuffer buffer;
    while (!serializer.is_done())
    {
        serializer.limit(buffer.GetRemainingSpace());

        size_t totalBytes = 0;
        boost::system::error_code ec = {};
        serializer.next(ec, [&]<typename ConstBufferSequence>(boost::system::error_code& currentError, ConstBufferSequence const& buffers)
        {
            size_t totalBytesInBuffers = boost::asio::buffer_size(buffers);
            if (totalBytesInBuffers > buffer.GetRemainingSpace())
            {
                currentError = boost::beast::http::error::need_more;
                return;
            }

            auto begin = boost::asio::buffers_begin(buffers);
            auto end = boost::asio::buffers_end(buffers);

            std::copy(begin, end, buffer.GetWritePointer());
            buffer.WriteCompleted(totalBytesInBuffers);
            totalBytes += totalBytesInBuffers;
        });

        serializer.consume(totalBytes);

        if (ec == boost::beast::http::error::need_more)
            buffer.Resize(buffer.GetBufferSize() + 4096);
    }

    return buffer;
}

MessageBuffer AbstractSocket::SerializeResponse(Request const& request, Response const& response)
{
    ResponseSerializer serializer(response);
    bool (*serializerIsDone)(ResponseSerializer&);
    if (request.method() != boost::beast::http::verb::head)
    {
        serializerIsDone = [](ResponseSerializer& s) { return s.is_done(); };
    }
    else
    {
        serializerIsDone = [](ResponseSerializer& s) { return s.is_header_done(); };
        serializer.split(true);
    }

    MessageBuffer buffer;
    while (!serializerIsDone(serializer))
    {
        serializer.limit(buffer.GetRemainingSpace());

        size_t totalBytes = 0;
        boost::system::error_code ec = {};
        serializer.next(ec, [&]<typename ConstBufferSequence>(boost::system::error_code& currentError, ConstBufferSequence const& buffers)
        {
            size_t totalBytesInBuffers = boost::asio::buffer_size(buffers);
            if (totalBytesInBuffers > buffer.GetRemainingSpace())
            {
                currentError = boost::beast::http::error::need_more;
                return;
            }

            auto begin = boost::asio::buffers_begin(buffers);
            auto end = boost::asio::buffers_end(buffers);

            std::copy(begin, end, buffer.GetWritePointer());
            buffer.WriteCompleted(totalBytesInBuffers);
            totalBytes += totalBytesInBuffers;
        });

        serializer.consume(totalBytes);

        if (ec == boost::beast::http::error::need_more)
            buffer.Resize(buffer.GetBufferSize() + 4096);
    }

    return buffer;
}

void AbstractSocket::LogRequestAndResponse(RequestContext const& context, MessageBuffer& buffer) const
{
    if (Logger const* logger = sLog->GetEnabledLogger("server.http", LOG_LEVEL_DEBUG))
    {
        std::string clientInfo = GetClientInfo();
        sLog->OutMessageTo(logger, "server.http", LOG_LEVEL_DEBUG, "{} Request {} {} done, status {}", clientInfo,
            ToStdStringView(context.request.method_string()), ToStdStringView(context.request.target()), context.response.result_int());
        if (sLog->ShouldLog("server.http", LOG_LEVEL_TRACE))
        {
            if (CanLogRequestContent(context))
            {
                MessageBuffer request = SerializeRequest(context.request);
                sLog->OutMessageTo(logger, "server.http", LOG_LEVEL_TRACE, "{} Request: {}", clientInfo,
                    std::string_view(reinterpret_cast<char const*>(request.GetBasePointer()), request.GetActiveSize()));
            }
            else
                sLog->OutMessageTo(logger, "server.http", LOG_LEVEL_TRACE, "{} Request: <REDACTED>", clientInfo);

            if (CanLogResponseContent(context))
                sLog->OutMessageTo(logger, "server.http", LOG_LEVEL_TRACE, "{} Response: {}", clientInfo,
                    std::string_view(reinterpret_cast<char const*>(buffer.GetBasePointer()), buffer.GetActiveSize()));
            else
                sLog->OutMessageTo(logger, "server.http", LOG_LEVEL_TRACE, "{} Response: <REDACTED>", clientInfo);
        }
    }
}

std::string AbstractSocket::GetClientInfo(boost::asio::ip::address const& address, uint16 port, SessionState const* state)
{
    std::string info = StringFormat("[{}:{}", address, port);
    if (state)
    {
        info.append(", Session Id: ");
        info.append(boost::uuids::to_string(state->Id));
    }

    info += ']';
    return info;
}
}
