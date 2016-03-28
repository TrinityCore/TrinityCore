/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Session.h"
#include "Define.h"
#include "Login.pb.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <atomic>
#include <mutex>
#include <thread>

struct soap;
struct soap_plugin;

class LoginRESTService
{
public:
    LoginRESTService() : _stopped(false), _port(0) { }

    static LoginRESTService& Instance();

    bool Start(boost::asio::io_service& ioService);
    void Stop();

    boost::asio::ip::tcp::endpoint const& GetAddressForClient(boost::asio::ip::address const& address) const;

    std::unique_ptr<Battlenet::Session::AccountInfo> VerifyLoginTicket(std::string const& id);

private:
    void Run();

    friend int32 handle_get_plugin(soap* soapClient);
    int32 HandleGet(soap* soapClient);

    friend int32 handle_post_plugin(soap* soapClient);
    int32 HandlePost(soap* soapClient);

    int32 SendResponse(soap* soapClient, google::protobuf::Message const& response);

    std::string CalculateShaPassHash(std::string const& name, std::string const& password);

    void AddLoginTicket(std::string const& id, std::unique_ptr<Battlenet::Session::AccountInfo> accountInfo);
    void CleanupLoginTickets(boost::system::error_code const& error);

    struct LoginTicket
    {
        std::string Id;
        std::unique_ptr<Battlenet::Session::AccountInfo> Account;
        std::time_t ExpiryTime;
    };

    struct ResponseCodePlugin
    {
        static char const* const PluginId;
        static int32 Init(soap* s, soap_plugin*, void*);
        static void Destroy(soap* s, soap_plugin* p);
        static int32 ChangeResponse(soap* s, int32 originalResponse, size_t contentLength);

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

    std::thread _thread;
    std::atomic<bool> _stopped;
    Battlenet::JSON::Login::FormInputs _formInputs;
    std::string _bindIP;
    int32 _port;
    boost::asio::ip::tcp::endpoint _externalAddress;
    boost::asio::ip::tcp::endpoint _localAddress;
    std::mutex _loginTicketMutex;
    std::unordered_map<std::string, LoginTicket> _validLoginTickets;
    boost::asio::deadline_timer* _loginTicketCleanupTimer;
};

#define sLoginService LoginRESTService::Instance()

#endif // LoginRESTService_h__
