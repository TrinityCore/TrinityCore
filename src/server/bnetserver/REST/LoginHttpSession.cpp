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
#include "LoginRESTService.h"
#include "SslContext.h"
#include "Util.h"

namespace Battlenet
{
LoginHttpSession::LoginHttpSession(boost::asio::ip::tcp::socket&& socket)
    : SslSocket(std::move(socket), SslContext::instance())
{
}

LoginHttpSession::~LoginHttpSession() = default;

void LoginHttpSession::Start()
{
    std::string ip_address = GetRemoteIpAddress().to_string();
    TC_LOG_TRACE("server.http.session", "{} Accepted connection", GetClientInfo());

    // Verify that this IP is not in the ip_banned table
    LoginDatabase.Execute(LoginDatabase.GetPreparedStatement(LOGIN_DEL_EXPIRED_IP_BANS));

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_IP_INFO);
    stmt->setString(0, ip_address);

    _queryProcessor.AddCallback(LoginDatabase.AsyncQuery(stmt)
        .WithPreparedCallback([sess = shared_from_this()](PreparedQueryResult result) { sess->CheckIpCallback(std::move(result)); }));
}

void LoginHttpSession::CheckIpCallback(PreparedQueryResult result)
{
    if (result)
    {
        bool banned = false;
        do
        {
            Field* fields = result->Fetch();
            if (fields[0].GetUInt64() != 0)
                banned = true;

        } while (result->NextRow());

        if (banned)
        {
            TC_LOG_DEBUG("server.http.session", "{} tries to log in using banned IP!", GetClientInfo());
            CloseSocket();
            return;
        }
    }

    AsyncHandshake();
}

Trinity::Net::Http::RequestHandlerResult LoginHttpSession::RequestHandler(Trinity::Net::Http::RequestContext& context)
{
    return sLoginService.HandleRequest(shared_from_this(), context);
}

std::shared_ptr<Trinity::Net::Http::SessionState> LoginHttpSession::ObtainSessionState(Trinity::Net::Http::RequestContext& context) const
{
    using namespace std::string_literals;

    std::shared_ptr<Trinity::Net::Http::SessionState> state;

    auto cookieItr = context.request.find(boost::beast::http::field::cookie);
    if (cookieItr != context.request.end())
    {
        std::vector<std::string_view> cookies = Trinity::Tokenize(Trinity::Net::Http::ToStdStringView(cookieItr->value()), ';', false);
        std::size_t eq = 0;
        auto sessionIdItr = std::find_if(cookies.begin(), cookies.end(), [&](std::string_view cookie)
        {
            std::string_view name = cookie;
            eq = cookie.find('=');
            if (eq != std::string_view::npos)
                name = cookie.substr(0, eq);

            return name == SESSION_ID_COOKIE;
        });
        if (sessionIdItr != cookies.end())
        {
            std::string_view value = sessionIdItr->substr(eq + 1);
            state = sLoginService.FindAndRefreshSessionState(value, GetRemoteIpAddress());
        }
    }

    if (!state)
    {
        state = sLoginService.CreateNewSessionState(GetRemoteIpAddress());

        std::string_view host = Trinity::Net::Http::ToStdStringView(context.request[boost::beast::http::field::host]);
        if (std::size_t port = host.find(':'); port != std::string_view::npos)
            host.remove_suffix(host.length() - port);

        context.response.insert(boost::beast::http::field::set_cookie, Trinity::StringFormat("{}={}; Path=/bnetserver; Domain={}; Secure; HttpOnly; SameSite=None",
            SESSION_ID_COOKIE, boost::uuids::to_string(state->Id), host));
    }

    return state;
}
}
