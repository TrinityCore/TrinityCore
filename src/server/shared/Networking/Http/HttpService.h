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

#ifndef TRINITYCORE_HTTP_SERVICE_H
#define TRINITYCORE_HTTP_SERVICE_H

#include "AsioHacksFwd.h"
#include "Concepts.h"
#include "Define.h"
#include "EnumFlag.h"
#include "HttpCommon.h"
#include "HttpSessionState.h"
#include "Optional.h"
#include "SocketMgr.h"
#include <boost/uuid/uuid.hpp>
#include <functional>
#include <map>
#include <set>
#include <shared_mutex>

namespace Trinity::Net::Http
{
class AbstractSocket;

enum class RequestHandlerFlag
{
    None                    = 0x0,
    DoNotLogRequestContent  = 0x1,
    DoNotLogResponseContent = 0x2,
};

DEFINE_ENUM_FLAG(RequestHandlerFlag);

struct RequestHandler
{
    std::function<RequestHandlerResult(std::shared_ptr<AbstractSocket> session, RequestContext& context)> Func;
    EnumFlag<RequestHandlerFlag> Flags = RequestHandlerFlag::None;
};

class TC_SHARED_API DispatcherService
{
public:
    explicit DispatcherService(std::string_view loggerSuffix) : _logger("server.http.dispatcher.")
    {
        _logger.append(loggerSuffix);
    }

    RequestHandlerResult HandleRequest(std::shared_ptr<AbstractSocket> session, RequestContext& context);

    static RequestHandlerResult HandleBadRequest(std::shared_ptr<AbstractSocket> session, RequestContext& context);
    static RequestHandlerResult HandleUnauthorized(std::shared_ptr<AbstractSocket> session, RequestContext& context);
    static RequestHandlerResult HandlePathNotFound(std::shared_ptr<AbstractSocket> session, RequestContext& context);

protected:
    void RegisterHandler(boost::beast::http::verb method, std::string_view path,
        std::function<RequestHandlerResult(std::shared_ptr<AbstractSocket> session, RequestContext& context)> handler,
        RequestHandlerFlag flags = RequestHandlerFlag::None);

private:
    using HttpMethodHandlerMap = std::map<std::string, RequestHandler, std::less<>>;

    HttpMethodHandlerMap _getHandlers;
    HttpMethodHandlerMap _postHandlers;

    std::string _logger;
};

class TC_SHARED_API SessionService
{
public:
    explicit SessionService(std::string_view loggerSuffix) : _logger("server.http.session.")
    {
        _logger.append(loggerSuffix);
    }

    void Start(Asio::IoContext& ioContext);
    void Stop();

    std::shared_ptr<SessionState> FindAndRefreshSessionState(std::string_view id, boost::asio::ip::address const& address);
    void MarkSessionInactive(boost::uuids::uuid const& id);

protected:
    void InitAndStoreSessionState(std::shared_ptr<SessionState> state, boost::asio::ip::address const& address);

    void KillInactiveSessions();

private:
    std::shared_mutex _sessionsMutex;
    std::map<boost::uuids::uuid, std::shared_ptr<SessionState>> _sessions;

    std::mutex _inactiveSessionsMutex;
    std::set<boost::uuids::uuid> _inactiveSessions;
    std::unique_ptr<Asio::DeadlineTimer> _inactiveSessionsKillTimer;

    std::string _logger;
};

template<typename Callable, typename SessionImpl>
concept HttpRequestHandler = invocable_r<Callable, RequestHandlerResult, std::shared_ptr<SessionImpl>, RequestContext&>;

template<typename SessionImpl>
class HttpService : public SocketMgr<SessionImpl>, public DispatcherService, public SessionService
{
public:
    HttpService(std::string_view loggerSuffix) : DispatcherService(loggerSuffix), SessionService(loggerSuffix), _ioContext(nullptr), _logger("server.http.")
    {
        _logger.append(loggerSuffix);
    }

    bool StartNetwork(Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int32 threadCount = 1) override
    {
        if (!SocketMgr<SessionImpl>::StartNetwork(ioContext, bindIp, port, threadCount))
            return false;

        SessionService::Start(ioContext);
        return true;
    }

    void StopNetwork() override
    {
        SessionService::Stop();
        SocketMgr<SessionImpl>::StopNetwork();
    }

    // http handling
    using DispatcherService::RegisterHandler;

    template<HttpRequestHandler<SessionImpl> Callable>
    void RegisterHandler(boost::beast::http::verb method, std::string_view path, Callable handler, RequestHandlerFlag flags = RequestHandlerFlag::None)
    {
        this->DispatcherService::RegisterHandler(method, path, [handler = std::move(handler)](std::shared_ptr<AbstractSocket> session, RequestContext& context) -> RequestHandlerResult
        {
            return handler(std::static_pointer_cast<SessionImpl>(std::move(session)), context);
        }, flags);
    }

    // session tracking
    virtual std::shared_ptr<SessionState> CreateNewSessionState(boost::asio::ip::address const& address)
    {
        std::shared_ptr<SessionState> state = std::make_shared<SessionState>();
        InitAndStoreSessionState(state, address);
        return state;
    }

protected:
    class Thread : public NetworkThread<SessionImpl>
    {
    protected:
        void SocketRemoved(std::shared_ptr<SessionImpl> session) override
        {
            if (Optional<boost::uuids::uuid> id = session->GetSessionId())
                _service->MarkSessionInactive(*id);
        }

    private:
        friend HttpService;

        SessionService* _service;
    };

    NetworkThread<SessionImpl>* CreateThreads() const override
    {
        Thread* threads = new Thread[this->GetNetworkThreadCount()];
        for (int32 i = 0; i < this->GetNetworkThreadCount(); ++i)
            threads[i]._service = const_cast<HttpService*>(this);
        return threads;
    }

    Asio::IoContext* _ioContext;
    std::string _logger;
};
}

#endif // TRINITYCORE_HTTP_SERVICE_H
