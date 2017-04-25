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

#ifndef TRINITY_IRCBRIDGE_H
#define TRINITY_IRCBRIDGE_H

#include "Common.h"
#include "IRCBridgeSocket.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <thread>

enum IRCBridgeStatus
{
    IRCBRIDGESTATUS_SHUTDOWN,
    IRCBRIDGESTATUS_IDLE,
    IRCBRIDGESTATUS_WAITING_CONNECTION,
    IRCBRIDGESTATUS_CONNECTED,
    IRCBRIDGESTATUS_WAITING_CONFIRMATION,
    IRCBRIDGESTATUS_LOGGED
};

enum IRCBridgeReportType
{
    REPORTTYPE_ERROR
};

enum ConfigurationType
{
    CONFIGURATIONTYPE_UINT,
    CONFIGURATIONTYPE_STRING
};

enum IRCBridgeConfigurationUintValues
{
    CONFIGURATION_IRCBRIDGE_PORT,
    CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD,
    CONFIGURATION_IRCBRIDGE_CONNECTION_WAIT,
    CONFIGURATION_IRCBRIDGE_CONNECTION_ATTEMPTS,
    CONFIGURATION_IRCBRIDGE_UINT_COUNT
};

enum IRCBridgeConfigurationStringValues
{
    CONFIGURATION_IRCBRIDGE_HOST,
    CONFIGURATION_IRCBRIDGE_USERNAME,
    CONFIGURATION_IRCBRIDGE_NICKNAME,
    CONFIGURATION_IRCBRIDGE_PASSWORD,
    CONFIGURATION_IRCBRIDGE_AUTHENTICATION_NICKNAME,
    CONFIGURATION_IRCBRIDGE_CONNECTION_CODE,
    CONFIGURATION_IRCBRIDGE_STRING_COUNT
};

struct IRCCommand
{
    uint8 type;
    std::string data;
    size_t size;
};

class IRCBridge
{
    public:
        IRCBridge();
        ~IRCBridge();

        static IRCBridge* instance();

        void Initialize(boost::asio::io_service* service);
        void Run();
        void Stop();

        bool IsActive() const { return _active; }
        bool IsConnected() const { return _status >= IRCBRIDGESTATUS_CONNECTED; }

        bool LoadConfigurations();
        uint32 GetConfiguration(IRCBridgeConfigurationUintValues index) const { return _configurationUintValues[index]; }
        std::string GetConfiguration(IRCBridgeConfigurationStringValues index) const { return _configurationStringValues[index]; }

        void Send(std::string message);
        void Report(IRCBridgeReportType report);
        void HandleMessage(std::string const& message);

    private:
        void ThreadLoop();
        void StartNetwork(std::string const& bindIp, std::string const& port);
        void OnConnect(boost::asio::ip::tcp::socket&& socket);
        void Login();

        template<ConfigurationType T, typename N>
        N LoadConfiguration(char const* fieldname, N defvalue) const;

        void SetConfiguration(IRCBridgeConfigurationUintValues index, uint32 value) { _configurationUintValues[index] = value; }
        void SetConfiguration(IRCBridgeConfigurationStringValues index, std::string value) { _configurationStringValues[index] = value; }

        std::string MakeStringUpper(std::string string);

        uint32 _configurationUintValues[CONFIGURATION_IRCBRIDGE_UINT_COUNT];
        std::string _configurationStringValues[CONFIGURATION_IRCBRIDGE_STRING_COUNT];

        boost::asio::io_service* _ioService;
        boost::asio::strand* _strand;
        std::shared_ptr<IRCBridgeSocket> _socket;
        std::thread _thread;

        IRCBridgeStatus _status;
        bool _active;
};

#define sIRCBridge IRCBridge::instance()

#endif // TRINITY_IRCBRIDGE_H
