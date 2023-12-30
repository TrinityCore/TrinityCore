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

#include "HttpService.h"
#include "BaseHttpSocket.h"
#include "CryptoRandom.h"
#include "Timezone.h"
#include <boost/beast/version.hpp>
#include <boost/uuid/string_generator.hpp>
#include <fmt/chrono.h>

namespace Trinity::Net::Http
{
bool CanLogRequestContent(RequestContext const& context)
{
    return !context.handler || !context.handler->Flags.HasFlag(RequestHandlerFlag::DoNotLogRequestContent);
}

bool CanLogResponseContent(RequestContext const& context)
{
    return !context.handler || !context.handler->Flags.HasFlag(RequestHandlerFlag::DoNotLogResponseContent);
}

RequestHandlerResult DispatcherService::HandleRequest(std::shared_ptr<AbstractSocket> session, RequestContext& context)
{
    TC_LOG_DEBUG(_logger, "{} Starting request {} {}", session->GetClientInfo(),
        ToStdStringView(context.request.method_string()), ToStdStringView(context.request.target()));

    std::string_view path = [&]
    {
        std::string_view path = ToStdStringView(context.request.target());
        size_t queryIndex = path.find('?');
        if (queryIndex != std::string_view::npos)
            path = path.substr(0, queryIndex);
        return path;
    }();

    context.handler = [&]() -> HttpMethodHandlerMap::mapped_type const*
    {
        switch (context.request.method())
        {
            case boost::beast::http::verb::get:
            case boost::beast::http::verb::head:
            {
                auto itr = _getHandlers.find(path);
                return itr != _getHandlers.end() ? &itr->second : nullptr;
            }
            case boost::beast::http::verb::post:
            {
                auto itr = _postHandlers.find(path);
                return itr != _postHandlers.end() ? &itr->second : nullptr;
            }
            default:
                break;
        }
        return nullptr;
    }();

    SystemTimePoint responseDate = SystemTimePoint::clock::now();
    context.response.set(boost::beast::http::field::date, StringFormat("{:%a, %d %b %Y %T GMT}", responseDate - Timezone::GetSystemZoneOffsetAt(responseDate)));
    context.response.set(boost::beast::http::field::server, BOOST_BEAST_VERSION_STRING);
    context.response.keep_alive(context.request.keep_alive());

    if (!context.handler)
        return HandlePathNotFound(std::move(session), context);

    return context.handler->Func(std::move(session), context);
}

RequestHandlerResult DispatcherService::HandleBadRequest(std::shared_ptr<AbstractSocket> /*session*/, RequestContext& context)
{
    context.response.result(boost::beast::http::status::bad_request);
    return RequestHandlerResult::Handled;
}

RequestHandlerResult DispatcherService::HandleUnauthorized(std::shared_ptr<AbstractSocket> /*session*/, RequestContext& context)
{
    context.response.result(boost::beast::http::status::unauthorized);
    return RequestHandlerResult::Handled;
}

RequestHandlerResult DispatcherService::HandlePathNotFound(std::shared_ptr<AbstractSocket> /*session*/, RequestContext& context)
{
    context.response.result(boost::beast::http::status::not_found);
    return RequestHandlerResult::Handled;
}

void DispatcherService::RegisterHandler(boost::beast::http::verb method, std::string_view path,
    std::function<RequestHandlerResult(std::shared_ptr<AbstractSocket> session, RequestContext& context)> handler,
    RequestHandlerFlag flags)
{
    HttpMethodHandlerMap& handlerMap = [&]() -> HttpMethodHandlerMap&
    {
        switch (method)
        {
            case boost::beast::http::verb::get:
                return _getHandlers;
            case boost::beast::http::verb::post:
                return _postHandlers;
            default:
            {
                std::string_view methodString = ToStdStringView(boost::beast::http::to_string(method));
                ABORT_MSG("Tried to register a handler for unsupported HTTP method " STRING_VIEW_FMT, STRING_VIEW_FMT_ARG(methodString));
            }
        }
    }();

    handlerMap[std::string(path)] = { .Func = std::move(handler), .Flags = flags };
    TC_LOG_INFO(_logger, "Registered new handler for {} {}", ToStdStringView(boost::beast::http::to_string(method)), path);
}

void SessionService::InitAndStoreSessionState(std::shared_ptr<SessionState> state, boost::asio::ip::address const& address)
{
    state->RemoteAddress = address;

    // Generate session id
    {
        std::unique_lock lock{ _sessionsMutex };

        while (state->Id.is_nil() || _sessions.contains(state->Id))
            std::copy_n(Trinity::Crypto::GetRandomBytes<16>().begin(), 16, state->Id.begin());

        TC_LOG_DEBUG(_logger, "Client at {} created new session {}", address.to_string(), boost::uuids::to_string(state->Id));
        _sessions[state->Id] = std::move(state);
    }
}

void SessionService::Start(Asio::IoContext& ioContext)
{
    _inactiveSessionsKillTimer = std::make_unique<Asio::DeadlineTimer>(ioContext);
    _inactiveSessionsKillTimer->expires_from_now(boost::posix_time::minutes(1));
    _inactiveSessionsKillTimer->async_wait([this](boost::system::error_code const& err)
    {
        if (err)
            return;

        KillInactiveSessions();
    });
}

void SessionService::Stop()
{
    _inactiveSessionsKillTimer = nullptr;
    {
        std::unique_lock lock{ _sessionsMutex };
        _sessions.clear();
    }
    {
        std::unique_lock lock{ _inactiveSessionsMutex };
        _inactiveSessions.clear();
    }
}

std::shared_ptr<SessionState> SessionService::FindAndRefreshSessionState(std::string_view id, boost::asio::ip::address const& address)
{
    std::shared_ptr<SessionState> state;

    {
        std::shared_lock lock{ _sessionsMutex };
        auto itr = _sessions.find(boost::uuids::string_generator()(id.begin(), id.end()));
        if (itr == _sessions.end())
        {
            TC_LOG_DEBUG(_logger, "Client at {} attempted to use a session {} that was expired", address.to_string(), id);
            return nullptr; // no session
        }

        state = itr->second;
    }

    if (state->RemoteAddress != address)
    {
        TC_LOG_ERROR(_logger, "Client at {} attempted to use a session {} that was last accessed from {}, denied access",
            address.to_string(), id, state->RemoteAddress.to_string());
        return nullptr;
    }

    {
        std::unique_lock inactiveSessionsLock{ _inactiveSessionsMutex };
        _inactiveSessions.erase(state->Id);
    }

    return state;
}

void SessionService::MarkSessionInactive(boost::uuids::uuid const& id)
{
    bool wasActive = true;
    {
        std::unique_lock inactiveSessionsLock{ _inactiveSessionsMutex };
        wasActive = _inactiveSessions.insert(id).second;
    }

    if (wasActive)
    {
        std::shared_lock lock{ _sessionsMutex };
        auto itr = _sessions.find(id);
        if (itr != _sessions.end())
        {
            itr->second->InactiveTimestamp = TimePoint::clock::now() + Minutes(5);
            TC_LOG_TRACE(_logger, "Session {} marked as inactive", boost::uuids::to_string(id));
        }
    }
}

void SessionService::KillInactiveSessions()
{
    std::set<boost::uuids::uuid> inactiveSessions;

    {
        std::unique_lock lock{ _inactiveSessionsMutex };
        std::swap(_inactiveSessions, inactiveSessions);
    }

    {
        TimePoint now = TimePoint::clock::now();
        std::size_t inactiveSessionsCount = inactiveSessions.size();

        std::unique_lock lock{ _sessionsMutex };
        for (auto itr = inactiveSessions.begin(); itr != inactiveSessions.end(); )
        {
            auto sessionItr = _sessions.find(*itr);
            if (sessionItr == _sessions.end() || sessionItr->second->InactiveTimestamp < now)
            {
                _sessions.erase(sessionItr);
                itr = inactiveSessions.erase(itr);
            }
            else
                ++itr;
        }

        TC_LOG_DEBUG(_logger, "Killed {} inactive sessions", inactiveSessionsCount - inactiveSessions.size());
    }

    {
        // restore sessions not killed to inactive queue
        std::unique_lock lock{ _inactiveSessionsMutex };
        for (auto itr = inactiveSessions.begin(); itr != inactiveSessions.end(); )
        {
            auto node = inactiveSessions.extract(itr++);
            _inactiveSessions.insert(std::move(node));
        }
    }

    _inactiveSessionsKillTimer->expires_from_now(boost::posix_time::minutes(1));
    _inactiveSessionsKillTimer->async_wait([this](boost::system::error_code const& err)
    {
        if (err)
            return;

        KillInactiveSessions();
    });
}
}
