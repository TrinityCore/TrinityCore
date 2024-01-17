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

#ifndef LoginRESTService_h__
#define LoginRESTService_h__

#include "HttpService.h"
#include "Login.pb.h"
#include "LoginHttpSession.h"

namespace Battlenet
{
enum class SrpVersion : int8
{
    v1  = 1,
    v2  = 2
};

enum class SrpHashFunction
{
    Sha256  = 0,
    Sha512  = 1
};

enum class BanMode
{
    BAN_IP = 0,
    BAN_ACCOUNT = 1
};

class LoginRESTService : public Trinity::Net::Http::HttpService<LoginHttpSession>
{
public:
    using RequestHandlerResult = Trinity::Net::Http::RequestHandlerResult;
    using HttpRequest = Trinity::Net::Http::Request;
    using HttpResponse = Trinity::Net::Http::Response;
    using HttpRequestContext = Trinity::Net::Http::RequestContext;
    using HttpSessionState = Trinity::Net::Http::SessionState;

    LoginRESTService() : HttpService("login"), _port(0), _loginTicketDuration(0) { }

    static LoginRESTService& Instance();

    bool StartNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int32 threadCount = 1) override;

    std::string const& GetHostnameForClient(boost::asio::ip::address const& address) const;
    uint16 GetPort() const { return _port; }

    std::shared_ptr<Trinity::Net::Http::SessionState> CreateNewSessionState(boost::asio::ip::address const& address) override;

private:
    static void OnSocketAccept(boost::asio::ip::tcp::socket&& sock, uint32 threadIndex);

    static std::string ExtractAuthorization(HttpRequest const& request);

    RequestHandlerResult HandleGetForm(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const;
    static RequestHandlerResult HandleGetGameAccounts(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context);
    RequestHandlerResult HandleGetPortal(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const;

    RequestHandlerResult HandlePostLogin(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const;
    static RequestHandlerResult HandlePostLoginSrpChallenge(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context);
    RequestHandlerResult HandlePostRefreshLoginTicket(std::shared_ptr<LoginHttpSession> session, HttpRequestContext& context) const;

    static std::unique_ptr<Trinity::Crypto::SRP::BnetSRP6Base> CreateSrpImplementation(SrpVersion version, SrpHashFunction hashFunction,
        std::string const& username, Trinity::Crypto::SRP::Salt const& salt, Trinity::Crypto::SRP::Verifier const& verifier);

    void MigrateLegacyPasswordHashes() const;

    JSON::Login::FormInputs _formInputs;
    std::string _bindIP;
    uint16 _port;
    std::array<std::string, 2> _hostnames;
    std::array<boost::asio::ip::address, 2> _addresses;
    uint32 _loginTicketDuration;
};
}

#define sLoginService Battlenet::LoginRESTService::Instance()

#endif // LoginRESTService_h__
