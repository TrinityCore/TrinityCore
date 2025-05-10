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

#include "AsyncCallbackProcessor.h"
#include "BaseHttpSocket.h"
#include "DatabaseEnvFwd.h"
#include "SRP6.h"

namespace Battlenet
{
struct LoginSessionState : public Trinity::Net::Http::SessionState
{
    std::unique_ptr<Trinity::Crypto::SRP::BnetSRP6Base> Srp;
};

class LoginHttpSession : public Trinity::Net::Http::AbstractSocket, public std::enable_shared_from_this<LoginHttpSession>
{
public:
    static constexpr std::string_view SESSION_ID_COOKIE = "JSESSIONID=";

    explicit LoginHttpSession(Trinity::Net::IoContextTcpSocket&& socket);
    ~LoginHttpSession();

    void Start() override;
    bool Update() override;
    boost::asio::ip::address const& GetRemoteIpAddress() const  override { return _socket->GetRemoteIpAddress(); }
    bool IsOpen() const override { return _socket->IsOpen(); }
    void CloseSocket() override { return _socket->CloseSocket(); }

    void SendResponse(Trinity::Net::Http::RequestContext& context) override { return _socket->SendResponse(context); }
    void QueueQuery(QueryCallback&& queryCallback);
    std::string GetClientInfo() const override { return _socket->GetClientInfo(); }
    LoginSessionState* GetSessionState() const override { return static_cast<LoginSessionState*>(_socket->GetSessionState()); }

private:
    std::shared_ptr<Trinity::Net::Http::AbstractSocket> _socket;
    QueryCallbackProcessor _queryProcessor;
};
}

#endif // TRINITYCORE_LOGIN_HTTP_SESSION_H
