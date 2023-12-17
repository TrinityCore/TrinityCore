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

#ifndef TRINITYCORE_LOGIN_HTTP_SESSION_H
#define TRINITYCORE_LOGIN_HTTP_SESSION_H

#include "HttpSslSocket.h"

namespace Battlenet
{
class LoginHttpSession : public Trinity::Net::Http::SslSocket<LoginHttpSession>
{
public:
    static constexpr std::string_view SESSION_ID_COOKIE = "JSESSIONID";

    explicit LoginHttpSession(boost::asio::ip::tcp::socket&& socket);
    ~LoginHttpSession();

    void Start() override;

    void CheckIpCallback(PreparedQueryResult result);

    Trinity::Net::Http::RequestHandlerResult RequestHandler(Trinity::Net::Http::RequestContext& context) override;

protected:
    std::shared_ptr<Trinity::Net::Http::SessionState> ObtainSessionState(Trinity::Net::Http::RequestContext& context) const override;
};
}
#endif // TRINITYCORE_LOGIN_HTTP_SESSION_H
