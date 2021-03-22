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

#include "Define.h"
#include "IoContext.h"
#include "IpAddress.h"
#include "Login.pb.h"
#include "Session.h"
#include <boost/asio/ip/tcp.hpp>
#include <atomic>
#include <thread>

class AsyncRequest;
struct soap;
struct soap_plugin;

enum class BanMode
{
    BAN_IP = 0,
    BAN_ACCOUNT = 1
};

class LoginRESTService
{
public:
    LoginRESTService() : _ioContext(nullptr), _stopped(false), _port(0), _loginTicketDuration(0) { }

    static LoginRESTService& Instance();

    bool Start(Trinity::Asio::IoContext* ioContext);
    void Stop();

    boost::asio::ip::tcp::endpoint const& GetAddressForClient(boost::asio::ip::address const& address) const;

private:
    void Run();

    friend int32 handle_get_plugin(soap* soapClient);
    friend int32 handle_post_plugin(soap* soapClient);

    using HttpMethodHandlerMap = std::unordered_map<std::string, int32(LoginRESTService::*)(std::shared_ptr<AsyncRequest>)>;
    int32 HandleHttpRequest(soap* soapClient, char const* method, HttpMethodHandlerMap const& handlers);

    int32 HandleGetForm(std::shared_ptr<AsyncRequest> request);
    int32 HandleGetGameAccounts(std::shared_ptr<AsyncRequest> request);
    int32 HandleGetPortal(std::shared_ptr<AsyncRequest> request);

    int32 HandlePostLogin(std::shared_ptr<AsyncRequest> request);
    int32 HandlePostRefreshLoginTicket(std::shared_ptr<AsyncRequest> request);

    int32 SendResponse(soap* soapClient, google::protobuf::Message const& response);

    void HandleAsyncRequest(std::shared_ptr<AsyncRequest> request);

    std::string CalculateShaPassHash(std::string const& name, std::string const& password);

    struct ResponseCodePlugin
    {
        static char const* const PluginId;
        static int32 Init(soap* s, soap_plugin*, void*);
        static int32 Copy(soap* s, soap_plugin* dst, soap_plugin* src);
        static void Destroy(soap* s, soap_plugin* p);
        static int32 ChangeResponse(soap* s, int32 originalResponse, size_t contentLength);

        static ResponseCodePlugin* GetForClient(soap* s);

        int32(*fresponse)(soap* s, int32 status, size_t length);
        int32 ErrorCode;
    };

    struct ContentTypePlugin
    {
        static char const* const PluginId;
        static int32 Init(soap* s, soap_plugin* p, void*);
        static void Destroy(soap* s, soap_plugin* p);
        static int32 OnSetHeader(soap* s, char const* key, char const* value);

        int32(*fposthdr)(soap* s, char const* key, char const* value);
        char const* ContentType;
    };

    Trinity::Asio::IoContext* _ioContext;
    std::thread _thread;
    std::atomic<bool> _stopped;
    Battlenet::JSON::Login::FormInputs _formInputs;
    std::string _bindIP;
    int32 _port;
    boost::asio::ip::tcp::endpoint _externalAddress;
    boost::asio::ip::tcp::endpoint _localAddress;
    boost::asio::ip::address_v4 _localNetmask;
    uint32 _loginTicketDuration;

    HttpMethodHandlerMap _getHandlers;
    HttpMethodHandlerMap _postHandlers;
};

#define sLoginService LoginRESTService::Instance()

#endif // LoginRESTService_h__
