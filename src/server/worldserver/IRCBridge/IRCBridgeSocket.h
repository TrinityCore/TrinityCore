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

#ifndef TRINITY_IRCBRIDGESOCKET_H
#define TRINITY_IRCBRIDGESOCKET_H

#include "Common.h"
#include "Socket.h"

#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>

enum IRCCommandType : uint8
{
    IRCCOMMAND_PING,
    IRCCOMMAND_PONG,
    IRCCOMMAND_ERROR,
    IRCCOMMAND_MAX
};

struct IRCCommand
{
    IRCCommandType type;
    std::string data;
    size_t size;
};

class IRCBridgeSocket : public Socket<IRCBridgeSocket>
{
    public:
        IRCBridgeSocket(boost::asio::ip::tcp::socket&& socket);
        ~IRCBridgeSocket();

        void Start() override;
        void OnClose() override;
        void ReadHandler() override;

        void Send(std::string const& message);
    private:
        void HandleMessage(std::string const& message);

};

#endif // TRINITY_IRCBRIDGESOCKET_H
