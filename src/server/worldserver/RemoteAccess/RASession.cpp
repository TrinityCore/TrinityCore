/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "RASession.h"
#include "AccountMgr.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "Util.h"
#include "World.h"
#include <boost/asio/buffer.hpp>
#include <boost/asio/read_until.hpp>
#include <memory>

using boost::asio::ip::tcp;

void RASession::Start()
{
    // wait 1 second for active connections to send negotiation request
    for (int counter = 0; counter < 10 && _socket.available() == 0; counter++)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Check if there are bytes available, if they are, then the client is requesting the negotiation
    if (_socket.available() > 0)
    {
        // Handle subnegotiation
        char buf[1024];
        memset(buf, 0, sizeof(buf));
        _socket.read_some(boost::asio::buffer(buf));

        // Send the end-of-negotiation packet
        uint8 const reply[2] = { 0xFF, 0xF0 };
        _socket.write_some(boost::asio::buffer(reply));
    }

    Send("Authentication Required\r\n");
    Send("Username: ");

    std::string username = ReadString();

    if (username.empty())
        return;

    TC_LOG_INFO("commands.ra", "Accepting RA connection from user %s (IP: %s)", username.c_str(), GetRemoteIpAddress().c_str());

    Send("Password: ");

    std::string password = ReadString();
    if (password.empty())
        return;

    if (!CheckAccessLevel(username) || !CheckPassword(username, password))
    {
        Send("Authentication failed\r\n");
        _socket.close();
        return;
    }

    TC_LOG_INFO("commands.ra", "User %s (IP: %s) authenticated correctly to RA", username.c_str(), GetRemoteIpAddress().c_str());

    // Authentication successful, send the motd
    for (std::string const& line : sWorld->GetMotd())
        Send(line.c_str());
    Send("\r\n");

    // Read commands
    for (;;)
    {
        Send("TC>");
        std::string command = ReadString();

        if (ProcessCommand(command))
            break;
    }

    _socket.close();
}

int RASession::Send(const char* data)
{
    std::ostream os(&_writeBuffer);
    os << data;
    size_t written = _socket.send(_writeBuffer.data());
    _writeBuffer.consume(written);
    return written;
}

std::string RASession::ReadString()
{
    boost::system::error_code error;
    size_t read = boost::asio::read_until(_socket, _readBuffer, "\r\n", error);
    if (!read)
    {
        _socket.close();
        return "";
    }

    std::string line;
    std::istream is(&_readBuffer);
    std::getline(is, line);

    if (*line.rbegin() == '\r')
        line.erase(line.length() - 1);

    return line;
}

bool RASession::CheckAccessLevel(const std::string& user)
{
    std::string safeUser = user;

    Utf8ToUpperOnlyLatin(safeUser);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_ACCESS);
    stmt->setString(0, safeUser);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("commands.ra", "User %s does not exist in database", user.c_str());
        return false;
    }

    Field* fields = result->Fetch();

    if (fields[1].GetUInt8() < sConfigMgr->GetIntDefault("Ra.MinLevel", SEC_ADMINISTRATOR))
    {
        TC_LOG_INFO("commands.ra", "User %s has no privilege to login", user.c_str());
        return false;
    }
    else if (fields[2].GetInt32() != -1)
    {
        TC_LOG_INFO("commands.ra", "User %s has to be assigned on all realms (with RealmID = '-1')", user.c_str());
        return false;
    }

    return true;
}

bool RASession::CheckPassword(const std::string& user, const std::string& pass)
{
    std::string safe_user = user;
    Utf8ToUpperOnlyLatin(safe_user);

    std::string safe_pass = pass;
    Utf8ToUpperOnlyLatin(safe_pass);

    std::string hash = AccountMgr::CalculateShaPassHash(safe_user, safe_pass);

    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_CHECK_PASSWORD_BY_NAME);

    stmt->setString(0, safe_user);
    stmt->setString(1, hash);

    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("commands.ra", "Wrong password for user: %s", user.c_str());
        return false;
    }

    return true;
}

bool RASession::ProcessCommand(std::string& command)
{
    if (command.length() == 0)
        return true;

    TC_LOG_INFO("commands.ra", "Received command: %s", command.c_str());

    // handle quit, exit and logout commands to terminate connection
    if (command == "quit" || command == "exit" || command == "logout")
    {
        Send("Bye\r\n");
        return true;
    }

    // Obtain a new promise per command
    delete _commandExecuting;
    _commandExecuting = new std::promise<void>();

    CliCommandHolder* cmd = new CliCommandHolder(this, command.c_str(), &RASession::CommandPrint, &RASession::CommandFinished);
    sWorld->QueueCliCommand(cmd);

    // Wait for the command to finish
    _commandExecuting->get_future().wait();

    return false;
}

void RASession::CommandPrint(void* callbackArg, const char* text)
{
    if (!text || !*text)
        return;

    RASession* session = static_cast<RASession*>(callbackArg);
    session->Send(text);
}

void RASession::CommandFinished(void* callbackArg, bool /*success*/)
{
    RASession* session = static_cast<RASession*>(callbackArg);
    session->_commandExecuting->set_value();
}
