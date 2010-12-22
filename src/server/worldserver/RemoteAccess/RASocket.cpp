/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

/** \file
    \ingroup Trinityd
*/

#include "Common.h"
#include "Configuration/Config.h"
#include "Database/DatabaseEnv.h"
#include "AccountMgr.h"
#include "Log.h"
#include "RASocket.h"
#include "Util.h"
#include "World.h"
#include "SHA1.h"

RASocket::RASocket()
{
    iMinLevel = sConfig.GetIntDefault("RA.MinLevel", 3);
}

RASocket::~RASocket()
{
}

int RASocket::open(void *)
{
    ACE_INET_Addr remote_addr;

    if (peer().get_remote_addr(remote_addr) == -1)
    {
        sLog.outError("RASocket::open: peer().get_remote_addr error is %s", ACE_OS::strerror(errno));
        return -1;
    }

    sLog.outRemote("Incoming connection from %s", remote_addr.get_host_addr());

    return activate();
}

int RASocket::handle_close(ACE_HANDLE, ACE_Reactor_Mask)
{
    sLog.outRemote("Closing connection");
    peer().close_reader();
    wait();
    destroy();
    return 0;
}

int RASocket::send(const std::string& line)
{
    return size_t(peer().send(line.c_str(), line.length())) == line.length() ? 0 : -1;
}

int RASocket::recv_line(ACE_Message_Block& buffer)
{
    char byte;
    for (;;)
    {
        ssize_t n = peer().recv(&byte, sizeof(byte));

        if (n < 0)
        {
            return -1;
        }

        if (n == 0)
        {
            // EOF, connection was closed
            errno = ECONNRESET;
            return -1;
        }

        ACE_ASSERT(n == sizeof(byte));

        if (byte == '\n')
            break;
        else if (byte == '\r') /* Ignore CR */
            continue;
        else if (buffer.copy(&byte, sizeof(byte)) == -1)
            return -1;
    }

    const char null_term = '\0';
    if (buffer.copy(&null_term, sizeof(null_term)) == -1)
        return -1;

    return 0;
}

int RASocket::recv_line(std::string& out_line)
{
    char buf[4096];

    ACE_Data_Block db(sizeof (buf),
            ACE_Message_Block::MB_DATA,
            buf,
            0,
            0,
            ACE_Message_Block::DONT_DELETE,
            0);

    ACE_Message_Block message_block(&db,
            ACE_Message_Block::DONT_DELETE,
            0);

    if (recv_line(message_block) == -1)
    {
        sLog.outRemote("Recv error %s", ACE_OS::strerror(errno));
        return -1;
    }

    out_line = message_block.rd_ptr();

    return 0;
}

int RASocket::process_command(const std::string& command)
{
    if (command.length() == 0)
        return 0;

    sLog.outRemote("Got command: %s", command.c_str());

    // handle quit, exit and logout commands to terminate connection
    if (command == "quit" || command == "exit" || command == "logout") {
        (void) send("Bye\r\n");
        return -1;
    }

    CliCommandHolder* cmd = new CliCommandHolder(this, command.c_str(), &RASocket::zprint, &RASocket::commandFinished);
    sWorld.QueueCliCommand(cmd);

    // wait for result
    ACE_Message_Block* mb;
    for (;;)
    {
        if (getq(mb) == -1)
            return -1;

        if (mb->msg_type() == ACE_Message_Block::MB_BREAK)
        {
            mb->release();
            break;
        }

        if (size_t(peer().send(mb->rd_ptr(), mb->length())) != mb->length())
        {
            mb->release();
            return -1;
        }

        mb->release();
    }

    return 0;
}

int RASocket::check_access_level(const std::string& user)
{
    std::string safe_user = user;

    AccountMgr::normalizeString(safe_user);
    LoginDatabase.escape_string(safe_user);

    QueryResult result = LoginDatabase.PQuery("SELECT a.id, aa.gmlevel, aa.RealmID FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.username = '%s'", safe_user.c_str());

    if (!result)
    {
        sLog.outRemote("User %s does not exist in database", user.c_str());
        return -1;
    }

    Field *fields = result->Fetch();

    if (fields[1].GetUInt32() < iMinLevel)
    {
        sLog.outRemote("User %s has no privilege to login", user.c_str());
        return -1;
    }
    else if (fields[2].GetInt32() != -1)
    {
        sLog.outRemote("User %s has to be assigned on all realms (with RealmID = '-1')", user.c_str());
        return -1;
    }

    return 0;
}

int RASocket::check_password(const std::string& user, const std::string& pass)
{
    std::string safe_user = user;
    AccountMgr::normalizeString(safe_user);
    LoginDatabase.escape_string(safe_user);

    std::string safe_pass = pass;
    AccountMgr::normalizeString(safe_pass);
    LoginDatabase.escape_string(safe_pass);

    std::string hash = sAccountMgr->CalculateShaPassHash(safe_user, safe_pass);

    QueryResult check = LoginDatabase.PQuery(
            "SELECT 1 FROM account WHERE username = '%s' AND sha_pass_hash = '%s'",
            safe_user.c_str(), hash.c_str());

    if (!check)
    {
        sLog.outRemote("Wrong password for user: %s", user.c_str());
        return -1;
    }

    return 0;
}

int RASocket::authenticate()
{
    if (send(std::string("Username: ")) == -1)
        return -1;

    std::string user;
    if (recv_line(user) == -1)
        return -1;

    if (send(std::string("Password: ")) == -1)
        return -1;

    std::string pass;
    if (recv_line(pass) == -1)
        return -1;

    sLog.outRemote("Login attempt for user: %s", user.c_str());

    if (check_access_level(user) == -1)
        return -1;

    if (check_password(user, pass) == -1)
        return -1;

    sLog.outRemote("User login: %s", user.c_str());

    return 0;
}

int RASocket::svc(void)
{
    if (send("Authentication required\r\n") == -1)
        return -1;

    if (authenticate() == -1)
    {
        (void) send("Authentication failed\r\n");
        return -1;
    }

    // send motd
    if (send(std::string(sWorld.GetMotd()) + "\r\n") == -1)
        return -1;

    for(;;)
    {
        // show prompt
        const char* tc_prompt = "TC> ";
        if (size_t(peer().send(tc_prompt, strlen(tc_prompt))) != strlen(tc_prompt))
            return -1;

        std::string line;

        if (recv_line(line) == -1)
            return -1;

        if (process_command(line) == -1)
            return -1;
    }

    return 0;
}

void RASocket::zprint(void* callbackArg, const char * szText)
{
    if (!szText || !callbackArg)
        return;

    RASocket* socket = static_cast<RASocket*>(callbackArg);
    size_t sz = strlen(szText);

    ACE_Message_Block* mb = new ACE_Message_Block(sz);
    mb->copy(szText, sz);

    if (socket->putq(mb, const_cast<ACE_Time_Value*>(&ACE_Time_Value::zero)) == -1)
    {
        sLog.outRemote("Failed to enqueue message, queue is full or closed. Error is %s", ACE_OS::strerror(errno));
        mb->release();
    }
}

void RASocket::commandFinished(void* callbackArg, bool /*success*/)
{
    if (!callbackArg)
        return;

    RASocket* socket = static_cast<RASocket*>(callbackArg);

    ACE_Message_Block* mb = new ACE_Message_Block();

    mb->msg_type(ACE_Message_Block::MB_BREAK);

    // the message is 0 size control message to tell that command output is finished
    // hence we don't put timeout, because it shouldn't increase queue size and shouldn't block
    if (socket->putq(mb) == -1)
    {
        // getting here is bad, command can't be marked as complete
        sLog.outRemote("Failed to enqueue command end message. Error is %s", ACE_OS::strerror(errno));
        mb->release();
    }
}
