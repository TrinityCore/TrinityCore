/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef RESTService_h__
#define RESTService_h__

#include "Define.h"
#include "Login.pb.h"
#include "RestCommon.h"
#include "server_http.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <atomic>
#include <mutex>
#include <thread>

struct soap;
struct soap_plugin;

typedef SimpleWeb::Server<SimpleWeb::HTTP> HttpServer;

class RESTService
{
public:
    RESTService() { _started = false; }

    static RESTService& Instance();

    bool Start();
    void Stop();
    void Run();

private:
    bool checkAuthTokenHeader(std::shared_ptr<HttpServer::Request> request);

    HttpServer _restServer;
    std::thread _thread;
    std::string _bindIP;
    std::string _authToken;
    RestResponse _response;
    boost::asio::ip::tcp::endpoint _externalAddress;
    boost::asio::ip::tcp::endpoint _localAddress;
    bool _started;
};

#define sRestService RESTService::Instance()

#endif // RESTService_h__
