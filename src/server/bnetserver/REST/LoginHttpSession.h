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

#include "HttpSocket.h"
#include "HttpSslSocket.h"
#include "SRP6.h"
#include <variant>

namespace Battlenet
{
struct LoginSessionState : public Trinity::Net::Http::SessionState
{
    std::unique_ptr<Trinity::Crypto::SRP::BnetSRP6Base> Srp;
};

class LoginHttpSessionWrapper;
std::shared_ptr<Trinity::Net::Http::SessionState> ObtainSessionState(Trinity::Net::Http::RequestContext& context, boost::asio::ip::address const& remoteAddress);

template<template<typename> typename SocketImpl>
class LoginHttpSession : public SocketImpl<LoginHttpSession<SocketImpl>>
{
    using BaseSocket = SocketImpl<LoginHttpSession<SocketImpl>>;

public:
    explicit LoginHttpSession(boost::asio::ip::tcp::socket&& socket, LoginHttpSessionWrapper& owner);
    ~LoginHttpSession();

    void Start() override;

    void CheckIpCallback(PreparedQueryResult result);

    Trinity::Net::Http::RequestHandlerResult RequestHandler(Trinity::Net::Http::RequestContext& context) override;

    LoginSessionState* GetSessionState() const { return static_cast<LoginSessionState*>(this->_state.get()); }

protected:
    std::shared_ptr<Trinity::Net::Http::SessionState> ObtainSessionState(Trinity::Net::Http::RequestContext& context) const override
    {
        return Battlenet::ObtainSessionState(context, this->GetRemoteIpAddress());
    }

    LoginHttpSessionWrapper& _owner;
};

class LoginHttpSessionWrapper : public Trinity::Net::Http::AbstractSocket, public std::enable_shared_from_this<LoginHttpSessionWrapper>
{
public:
    static constexpr std::string_view SESSION_ID_COOKIE = "JSESSIONID";

    explicit LoginHttpSessionWrapper(boost::asio::ip::tcp::socket&& socket);

    void Start() { return std::visit([&](auto&& socket) { return socket->Start(); }, _socket); }
    bool Update() { return std::visit([&](auto&& socket) { return socket->Update(); }, _socket); }
    boost::asio::ip::address GetRemoteIpAddress() const { return std::visit([&](auto&& socket) { return socket->GetRemoteIpAddress(); }, _socket); }
    bool IsOpen() const { return std::visit([&](auto&& socket) { return socket->IsOpen(); }, _socket); }
    void CloseSocket() { return std::visit([&](auto&& socket) { return socket->CloseSocket(); }, _socket); }

    void SendResponse(Trinity::Net::Http::RequestContext& context) override { return std::visit([&](auto&& socket) { return socket->SendResponse(context); }, _socket); }
    void QueueQuery(QueryCallback&& queryCallback) override { return std::visit([&](auto&& socket) { return socket->QueueQuery(std::move(queryCallback)); }, _socket); }
    std::string GetClientInfo() const override { return std::visit([&](auto&& socket) { return socket->GetClientInfo(); }, _socket); }
    Optional<boost::uuids::uuid> GetSessionId() const override { return std::visit([&](auto&& socket) { return socket->GetSessionId(); }, _socket); }
    LoginSessionState* GetSessionState() const { return std::visit([&](auto&& socket) { return socket->GetSessionState(); }, _socket); }

private:
    std::variant<
        std::shared_ptr<LoginHttpSession<Trinity::Net::Http::SslSocket>>,
        std::shared_ptr<LoginHttpSession<Trinity::Net::Http::Socket>>
    > _socket;
};
}
#endif // TRINITYCORE_LOGIN_HTTP_SESSION_H
