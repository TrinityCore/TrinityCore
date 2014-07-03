/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __RASESSION_H__
#define __RASESSION_H__

#include <memory>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include "Common.h"

#include <future>

using boost::asio::ip::tcp;

const size_t bufferSize = 4096;

#define BUFFER_SIZE 4096

class RASession : public std::enable_shared_from_this <RASession>
{
public:
    RASession(tcp::socket socket) : _socket(std::move(socket)), _commandExecuting(nullptr)
    {
    }

    void Start();

    const std::string GetRemoteIpAddress() const { return _socket.remote_endpoint().address().to_string(); };
    unsigned short GetRemotePort() const { return _socket.remote_endpoint().port(); }

private:
    int Send(const char* data);
    std::string ReadString();
    bool CheckAccessLevel(const std::string& user);
    bool CheckPassword(const std::string& user, const std::string& pass);
    bool ProcessCommand(std::string& command);

    static void CommandPrint(void* callbackArg, const char* text);
    static void CommandFinished(void* callbackArg, bool success);

    tcp::socket _socket;
    boost::asio::streambuf _readBuffer;
    boost::asio::streambuf _writeBuffer;
    std::promise<void>* _commandExecuting;
};

#endif
