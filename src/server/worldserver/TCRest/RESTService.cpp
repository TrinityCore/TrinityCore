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

#include "RESTService.h"
#include "Log.h"
#include "ScriptMgr.h"
#include "Configuration/Config.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>

bool RESTService::Start(boost::asio::io_service& ioService)
{
    _bindIP = sConfigMgr->GetStringDefault("BindIP", "0.0.0.0");
    _port = sConfigMgr->GetIntDefault("WorldREST.Port", 8082);
    if (_port < 0 || _port > 0xFFFF)
    {
        TC_LOG_ERROR("server.rest", "Specified world rest service port (%d) out of allowed range (1-65535), defaulting to 8082", _port);
        _port = 8082;
    }

    _restServer.config.port = _port;

    _restServer.resource[".+"]["GET"] = [](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request)
    {
        try
        {
            TC_LOG_DEBUG("server.rest", "[%s:%d] Handling GET request path=\"%s\"", request->remote_endpoint_address, request->remote_endpoint_port, request->path);

            RestResponse restResponse;
            sScriptMgr->OnRestGetReceived(request->path, restResponse);

            std::string serializedResponse = restResponse.serialize();

            *response << "HTTP/1.1 200 OK\r\nContent-Length: " << serializedResponse.length() << "\r\n\r\n" << serializedResponse;
        }
        catch (const std::exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                << e.what();
        }
    };

    _restServer.resource[".+"]["POST"] = [](std::shared_ptr<HttpServer::Response> response, std::shared_ptr<HttpServer::Request> request)
    {
        try
        {
            TC_LOG_DEBUG("server.rest", "[%s:%d] Handling POST request path=\"%s\"", request->remote_endpoint_address, request->remote_endpoint_port, request->path);

            boost::property_tree::ptree pt;
            read_json(request->content, pt);

            RestResponse restResponse;
            sScriptMgr->OnRestPostReceived(request->path, pt, restResponse);

            std::string serializedResponse = restResponse.serialize();

            *response << "HTTP/1.1 200 OK\r\nContent-Length: " << serializedResponse.length() << "\r\n\r\n" << serializedResponse;
        }
        catch (const std::exception &e)
        {
            *response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << strlen(e.what()) << "\r\n\r\n"
                << e.what();
        }
    };

    _thread = std::thread(std::bind(&RESTService::Run, this));

    return true;
}

void RESTService::Stop()
{
    _restServer.stop();
}

void RESTService::Run()
{
    TC_LOG_DEBUG("server.rest", "Starting WorldRest server");
    _restServer.start();
}

RESTService& RESTService::Instance()
{
    static RESTService instance;
    return instance;
}
