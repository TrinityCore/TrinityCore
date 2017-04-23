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
#include "Socket.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <thread>
#include <functional>

enum ConfigurationType
{
    CONFIGURATIONTYPE_UINT,
    CONFIGURATIONTYPE_STRING
};

enum IRCBridgeConfigurationUintValues
{
    CONFIGURATION_IRCBRIDGE_PORT,
    CONFIGURATION_IRCBRIDGE_AUTHENTICATION_METHOD,
    CONFIGURATION_IRCBRIDGE_CONNECTION_CODE,
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
    CONFIGURATION_IRCBRIDGE_STRING_COUNT
};

void IRCBridgeThread();

class IRCBridgeSocket : public Socket<IRCBridgeSocket>
{
    public:
        IRCBridgeSocket(tcp::socket&& socket);
        ~IRCBridgeSocket();

        void Start() override;
        void OnClose() override;
        void ReadHandler() override;

        void Send(MessageBuffer message);
    private:

};

class IRCBridge
{
    public:
        IRCBridge();
        ~IRCBridge();

        static IRCBridge* instance()
        {
            static IRCBridge instance;
            return &instance;
        }

        void Initialize(boost::asio::io_service* service);
        void Run();
        void Stop();

        bool IsActive() const { return _active; }
        bool IsConnected() const { return _connected; }

        bool LoadConfigurations();
        uint32 GetConfiguration(IRCBridgeConfigurationUintValues index) const { return _configurationUintValues[index]; }
        std::string GetConfiguration(IRCBridgeConfigurationStringValues index) const { return _configurationStringValues[index]; }

        void Send(std::string const message);

        void Login();

    private:
        void StartNetwork(boost::asio::io_service& service, std::string const& bindIp, std::string const& port);
        void OnConnect(tcp::socket&& socket);

        template<ConfigurationType T, typename N>
        N LoadConfiguration(char const* fieldname, N defvalue) const;

        void SetConfiguration(IRCBridgeConfigurationUintValues index, uint32 value) { _configurationUintValues[index] = value; }
        void SetConfiguration(IRCBridgeConfigurationStringValues index, std::string value) { _configurationStringValues[index] = value; }

        uint32 _configurationUintValues[CONFIGURATION_IRCBRIDGE_UINT_COUNT];
        std::string _configurationStringValues[CONFIGURATION_IRCBRIDGE_STRING_COUNT];

        boost::asio::io_service* _ioService;
        boost::asio::strand* _strand;
        std::shared_ptr<IRCBridgeSocket> _socket;
        std::thread _thread;

        bool _active;
        bool _connected;
};

#define sIRCBridge IRCBridge::instance()

#endif // TRINITY_IRCBRIDGE_H
