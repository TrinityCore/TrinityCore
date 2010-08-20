/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <mysql.h>
#include "DatabaseEnv.h"
#include "QueryResult.h"
#include "SQLOperation.h"
#include "MySQLConnection.h"
#include "DatabaseWorker.h"
#include "Log.h"
#include "Util.h"
#include "Timer.h"

MySQLConnection::MySQLConnection() :
m_Mysql(NULL),
m_worker(NULL),
m_queue(NULL)
{
}

MySQLConnection::MySQLConnection(ACE_Activation_Queue* queue) :
m_queue(queue),
m_Mysql(NULL)
{
    m_worker = new DatabaseWorker(m_queue, this);
}

MySQLConnection::~MySQLConnection()
{
    MySQL::Thread_End();
    mysql_close(m_Mysql);
}

bool MySQLConnection::Open(const std::string& infoString)
{
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);
    if (!mysqlInit)
    {
        sLog.outError("Could not initialize Mysql connection");
        return false;
    }

    Tokens tokens = StrSplit(infoString, ";");

    Tokens::iterator iter;

    std::string host, port_or_socket, user, password, database;
    int port;
    char const* unix_socket;

    iter = tokens.begin();

    if (iter != tokens.end())
        host = *iter++;
    if (iter != tokens.end())
        port_or_socket = *iter++;
    if (iter != tokens.end())
        user = *iter++;
    if (iter != tokens.end())
        password = *iter++;
    if (iter != tokens.end())
        database = *iter++;

    mysql_options(mysqlInit, MYSQL_SET_CHARSET_NAME, "utf8");
    #ifdef _WIN32
    if (host==".")                                           // named pipe use option (Windows)
    {
        unsigned int opt = MYSQL_PROTOCOL_PIPE;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        port = 0;
        unix_socket = 0;
    }
    else                                                    // generic case
    {
        port = atoi(port_or_socket.c_str());
        unix_socket = 0;
    }
    #else
    if (host==".")                                           // socket use option (Unix/Linux)
    {
        unsigned int opt = MYSQL_PROTOCOL_SOCKET;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        host = "localhost";
        port = 0;
        unix_socket = port_or_socket.c_str();
    }
    else                                                    // generic case
    {
        port = atoi(port_or_socket.c_str());
        unix_socket = 0;
    }
    #endif

    m_Mysql = mysql_real_connect(mysqlInit, host.c_str(), user.c_str(),
        password.c_str(), database.c_str(), port, unix_socket, 0);

    if (m_Mysql)
    {
        sLog.outDetail("Connected to MySQL database at %s", host.c_str());
        sLog.outString("MySQL client library: %s", mysql_get_client_info());
        sLog.outString("MySQL server ver: %s ", mysql_get_server_info( m_Mysql));

        if (!mysql_autocommit(m_Mysql, 1))
            sLog.outDetail("AUTOCOMMIT SUCCESSFULLY SET TO 1");
        else
            sLog.outDetail("AUTOCOMMIT NOT SET TO 1");

        // set connection properties to UTF8 to properly handle locales for different
        // server configs - core sends data in UTF8, so MySQL must expect UTF8 too
        Execute("SET NAMES `utf8`");
        Execute("SET CHARACTER SET `utf8`");

    #if MYSQL_VERSION_ID >= 50003
        my_bool my_true = (my_bool)1;
        if (mysql_options(m_Mysql, MYSQL_OPT_RECONNECT, &my_true))
            sLog.outDetail("Failed to turn on MYSQL_OPT_RECONNECT.");
        else
           sLog.outDetail("Successfully turned on MYSQL_OPT_RECONNECT.");
    #else
        #warning "Your mySQL client lib version does not support reconnecting after a timeout.\nIf this causes you any trouble we advice you to upgrade your mySQL client libs to at least mySQL 5.0.13 to resolve this problem."
    #endif
        return true;
    }
    else
    {
        sLog.outError("Could not connect to MySQL database at %s: %s\n", host.c_str(), mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return false;
    }
}

bool MySQLConnection::Execute(const char* sql)
{
    if (!m_Mysql)
        return false;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(m_Mutex);

        #ifdef TRINITY_DEBUG
        uint32 _s = getMSTime();
        #endif
        if (mysql_query(m_Mysql, sql))
        {
            sLog.outErrorDb("SQL: %s", sql);
            sLog.outErrorDb("SQL ERROR: %s", mysql_error(m_Mysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTimeDiff(_s, getMSTime()), sql);
            #endif
        }
    }

    return true;
}

QueryResult_AutoPtr MySQLConnection::Query(const char* sql)
{
    if (!sql)
        return QueryResult_AutoPtr(NULL);

    MYSQL_RES *result = NULL;
    MYSQL_FIELD *fields = NULL;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(sql, &result, &fields, &rowCount, &fieldCount))
        return QueryResult_AutoPtr(NULL);

    QueryResult *queryResult = new QueryResult(result, fields, rowCount, fieldCount);

    queryResult->NextRow();

    return QueryResult_AutoPtr(queryResult);
}

bool MySQLConnection::_Query(const char *sql, MYSQL_RES **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount)
{
    if (!m_Mysql)
        return false;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(m_Mutex);
        #ifdef TRINITY_DEBUG
        uint32 _s = getMSTime();
        #endif
        if (mysql_query(m_Mysql, sql))
        {
            sLog.outErrorDb("SQL: %s", sql);
            sLog.outErrorDb("query ERROR: %s", mysql_error(m_Mysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql);
            #endif
        }

        *pResult = mysql_store_result(m_Mysql);
        *pRowCount = mysql_affected_rows(m_Mysql);
        *pFieldCount = mysql_field_count(m_Mysql);
    }

    if (!*pResult )
        return false;

    if (!*pRowCount)
    {
        mysql_free_result(*pResult);
        return false;
    }

    *pFields = mysql_fetch_fields(*pResult);
    return true;
}

void MySQLConnection::BeginTransaction()
{
    Execute("START TRANSACTION");
}

void MySQLConnection::RollbackTransaction()
{
    Execute("ROLLBACK");
}

void MySQLConnection::CommitTransaction()
{
    Execute("COMMIT");
}
