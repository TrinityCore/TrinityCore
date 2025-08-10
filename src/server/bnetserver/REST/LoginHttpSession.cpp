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

#include "LoginHttpSession.h"
#include "DatabaseEnv.h"
#include "HttpSocket.h"
#include "HttpSslSocket.h"
#include "IpBanCheckConnectionInitializer.h"
#include "LoginRESTService.h"
#include "SslContext.h"
#include "Util.h"
#include <boost/container/static_vector.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace
{
std::shared_ptr<Trinity::Net::Http::SessionState> ObtainSessionState(Trinity::Net::Http::RequestContext& context, boost::asio::ip::address const& remoteAddress)
{
    std::shared_ptr<Trinity::Net::Http::SessionState> state;
    auto cookieItr = context.request.find(boost::beast::http::field::cookie);
    if (cookieItr != context.request.end())
    {
        std::vector<std::string_view> cookies = Trinity::Tokenize(Trinity::Net::Http::ToStdStringView(cookieItr->value()), ';', false);
        auto sessionIdItr = std::ranges::find_if(cookies, [](std::string_view const& cookie)
        {
            return cookie.length() > Battlenet::LoginHttpSession::SESSION_ID_COOKIE.length()
                && cookie.starts_with(Battlenet::LoginHttpSession::SESSION_ID_COOKIE);
        });
        if (sessionIdItr != cookies.end())
        {
            sessionIdItr->remove_prefix(Battlenet::LoginHttpSession::SESSION_ID_COOKIE.length());
            state = sLoginService.FindAndRefreshSessionState(*sessionIdItr, remoteAddress);
        }
    }
    if (!state)
    {
        state = sLoginService.CreateNewSessionState(remoteAddress);

        std::string_view host = Trinity::Net::Http::ToStdStringView(context.request[boost::beast::http::field::host]);
        if (size_t port = host.find(':'); port != std::string_view::npos)
            host.remove_suffix(host.length() - port);

        context.response.insert(boost::beast::http::field::set_cookie, Trinity::StringFormat("{}{}; Path=/bnetserver; Domain={}; Secure; HttpOnly; SameSite=None",
            Battlenet::LoginHttpSession::SESSION_ID_COOKIE, boost::uuids::to_string(state->Id), host));
    }
    return state;
}

template<typename SocketImpl>
class LoginHttpSocketImpl final : public SocketImpl
{
public:
    using BaseSocket = SocketImpl;

    explicit LoginHttpSocketImpl(Trinity::Net::IoContextTcpSocket&& socket, Battlenet::LoginHttpSession& owner)
        : BaseSocket(std::move(socket)), _owner(owner)
    {
    }

    LoginHttpSocketImpl(LoginHttpSocketImpl const&) = delete;
    LoginHttpSocketImpl(LoginHttpSocketImpl&&) = delete;
    LoginHttpSocketImpl& operator=(LoginHttpSocketImpl const&) = delete;
    LoginHttpSocketImpl& operator=(LoginHttpSocketImpl&&) = delete;

    ~LoginHttpSocketImpl() = default;

    void Start() override
    {
        // build initializer chain
        boost::container::static_vector<std::shared_ptr<Trinity::Net::SocketConnectionInitializer>, 4> initializers;

        initializers.stable_emplace_back(std::make_shared<Trinity::Net::IpBanCheckConnectionInitializer<Battlenet::LoginHttpSession>>(&_owner));

        if constexpr (std::is_same_v<BaseSocket, Trinity::Net::Http::SslSocket>)
            initializers.stable_emplace_back(std::make_shared<Trinity::Net::SslHandshakeConnectionInitializer<BaseSocket>>(this));

        initializers.stable_emplace_back(std::make_shared<Trinity::Net::Http::HttpConnectionInitializer<BaseSocket>>(this));
        initializers.stable_emplace_back(std::make_shared<Trinity::Net::ReadConnectionInitializer<BaseSocket>>(this));

        Trinity::Net::SocketConnectionInitializer::SetupChain(std::span(initializers.data(), initializers.size()))->Start();
    }

    Trinity::Net::Http::RequestHandlerResult RequestHandler(Trinity::Net::Http::RequestContext& context) override
    {
        return sLoginService.HandleRequest(_owner.shared_from_this(), context);
    }

protected:
    std::shared_ptr<Trinity::Net::Http::SessionState> ObtainSessionState(Trinity::Net::Http::RequestContext& context) const override
    {
        return ::ObtainSessionState(context, this->GetRemoteIpAddress());
    }

    Battlenet::LoginHttpSession& _owner;
};

template<>
LoginHttpSocketImpl<Trinity::Net::Http::SslSocket>::LoginHttpSocketImpl(Trinity::Net::IoContextTcpSocket&& socket, Battlenet::LoginHttpSession& owner)
    : BaseSocket(std::move(socket), Battlenet::SslContext::instance()), _owner(owner)
{
}
}

namespace Battlenet
{
LoginHttpSession::LoginHttpSession(Trinity::Net::IoContextTcpSocket&& socket)
    : _socket(!SslContext::UsesDevWildcardCertificate()
        ? std::shared_ptr<AbstractSocket>(std::make_shared<LoginHttpSocketImpl<Trinity::Net::Http::SslSocket>>(std::move(socket), *this))
        : std::shared_ptr<AbstractSocket>(std::make_shared<LoginHttpSocketImpl<Trinity::Net::Http::Socket>>(std::move(socket), *this)))
{
}

LoginHttpSession::~LoginHttpSession() = default;

void LoginHttpSession::Start()
{
    TC_LOG_TRACE("server.http.session", "{} Accepted connection", GetClientInfo());

    return _socket->Start();
}

bool LoginHttpSession::Update()
{
    if (!_socket->Update())
        return false;

    _queryProcessor.ProcessReadyCallbacks();
    return true;
}

void LoginHttpSession::QueueQuery(QueryCallback&& queryCallback)
{
    _queryProcessor.AddCallback(std::move(queryCallback));
}
}
