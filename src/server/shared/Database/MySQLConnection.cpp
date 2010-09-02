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


#include "Common.h"

#ifdef _WIN32
  #include <winsock2.h>
#endif
#include <mysql.h>

#include "DatabaseEnv.h"
#include "QueryResult.h"
#include "SQLOperation.h"
#include "PreparedStatement.h"
#include "MySQLConnection.h"
#include "DatabaseWorker.h"
#include "Log.h"
#include "Util.h"
#include "Timer.h"

MySQLConnection::MySQLConnection() :
m_queue(NULL),
m_worker(NULL),
m_Mysql(NULL)
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
    for (size_t i = 0; i < m_stmts.size(); ++i)
        delete m_stmts[i];

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
        sLog.outSQLDriver("MySQL client library: %s", mysql_get_client_info());
        sLog.outSQLDriver("MySQL server ver: %s ", mysql_get_server_info( m_Mysql));

        if (!mysql_autocommit(m_Mysql, 1))
            sLog.outSQLDriver("AUTOCOMMIT SUCCESSFULLY SET TO 1");
        else
            sLog.outSQLDriver("AUTOCOMMIT NOT SET TO 1");

        // set connection properties to UTF8 to properly handle locales for different
        // server configs - core sends data in UTF8, so MySQL must expect UTF8 too
        Execute("SET NAMES `utf8`");
        Execute("SET CHARACTER SET `utf8`");

    #if MYSQL_VERSION_ID >= 50003
        my_bool my_true = (my_bool)1;
        if (mysql_options(m_Mysql, MYSQL_OPT_RECONNECT, &my_true))
            sLog.outSQLDriver("Failed to turn on MYSQL_OPT_RECONNECT.");
        else
            sLog.outSQLDriver("Successfully turned on MYSQL_OPT_RECONNECT.");
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
            sLog.outSQLDriver("SQL: %s", sql);
            sLog.outSQLDriver("SQL ERROR: %s", mysql_error(m_Mysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outSQLDriver("[%u ms] SQL: %s", getMSTimeDiff(_s, getMSTime()), sql);
            #endif
        }
    }

    return true;
}

bool MySQLConnection::Execute(PreparedStatement* stmt)
{
    if (!m_Mysql)
        return false;

    uint32 index = stmt->m_index;
    MySQLPreparedStatement* m_mStmt = GetPreparedStatement(index);
    m_mStmt->m_stmt = stmt;     // Cross reference them for debug output
    stmt->m_stmt = m_mStmt;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(m_Mutex);
        
        stmt->BindParameters();

        MYSQL_STMT* msql_STMT = m_mStmt->GetSTMT();
        MYSQL_BIND* msql_BIND = m_mStmt->GetBind();

        #ifdef TRINITY_DEBUG
        uint32 _s = getMSTime();
        #endif
        if (mysql_stmt_bind_param(msql_STMT, msql_BIND))
        {
            sLog.outSQLDriver("[ERROR]: PreparedStatement (id: %u) error binding params:  %s", index, mysql_stmt_error(msql_STMT));
            m_mStmt->ClearParameters();
            return false;
        }

        if (mysql_stmt_execute(msql_STMT))
        {
            sLog.outSQLDriver("[ERROR]: PreparedStatement (id: %u) error executing:  %s", index, mysql_stmt_error(msql_STMT));
            m_mStmt->ClearParameters();
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outSQLDriver("[%u ms] Prepared SQL: %u", getMSTimeDiff(_s, getMSTime()), index);
            #endif
            m_mStmt->ClearParameters();
            return true;
        }
    }
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
            sLog.outSQLDriver("SQL: %s", sql);
            sLog.outSQLDriver("query ERROR: %s", mysql_error(m_Mysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outSQLDriver("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql);
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

MySQLPreparedStatement* MySQLConnection::GetPreparedStatement(uint32 index)
{
    return m_stmts[index];
}

void MySQLConnection::PrepareStatement(uint32 index, const char* sql)
{
    MYSQL_STMT * stmt = mysql_stmt_init(m_Mysql);
    if (!stmt)
    {
        sLog.outSQLDriver("[ERROR]: In mysql_stmt_init() id: %u, sql: \"%s\"", index, sql);
        sLog.outSQLDriver("[ERROR]: %s", mysql_error(m_Mysql));
        return;
    }

    if (mysql_stmt_prepare(stmt, sql, static_cast<unsigned long>(strlen(sql))))
    {
        mysql_stmt_close(stmt);
        sLog.outSQLDriver("[ERROR]: In mysql_stmt_close() id: %u, sql: \"%s\"", index, sql);
        sLog.outSQLDriver("[ERROR]: %s", mysql_error(m_Mysql));
        return;
    }

    MySQLPreparedStatement* mStmt = new MySQLPreparedStatement(stmt);
    m_stmts[index] = mStmt;
}
    