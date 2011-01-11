/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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


#include "Common.h"

#ifdef _WIN32
  #include <winsock2.h>
#endif
#include <mysql.h>

#include "MySQLConnection.h"
#include "MySQLThreading.h"
#include "QueryResult.h"
#include "SQLOperation.h"
#include "PreparedStatement.h"
#include "DatabaseWorker.h"
#include "Timer.h"
#include "Log.h"

MySQLConnection::MySQLConnection(MySQLConnectionInfo& connInfo) :
m_statementTable(NULL),
m_reconnecting(false),
m_queue(NULL),
m_worker(NULL),
m_Mysql(NULL),
m_connectionInfo(connInfo),
m_connectionFlags(CONNECTION_SYNCH)
{
}

MySQLConnection::MySQLConnection(ACE_Activation_Queue* queue, MySQLConnectionInfo& connInfo) :
m_statementTable(NULL),
m_reconnecting(false),
m_queue(queue),
m_Mysql(NULL),
m_connectionInfo(connInfo),
m_connectionFlags(CONNECTION_ASYNC)
{
    m_worker = new DatabaseWorker(m_queue, this);
}

MySQLConnection::~MySQLConnection()
{
    ASSERT (m_Mysql); /// MySQL context must be present at this point

    sLog->outSQLDriver("MySQLConnection::~MySQLConnection()");
    for (size_t i = 0; i < m_stmts.size(); ++i)
        delete m_stmts[i];

    mysql_close(m_Mysql);
    Unlock();   /// Unlock while we die, how ironic
}

void MySQLConnection::Close()
{
    /// Only close us if we're not operating
    delete this;
}

bool MySQLConnection::Open()
{
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);
    if (!mysqlInit)
    {
        sLog->outError("Could not initialize Mysql connection to database `%s`", m_connectionInfo.database.c_str());
        return false;
    }

    int port;
    char const* unix_socket;

    mysql_options(mysqlInit, MYSQL_SET_CHARSET_NAME, "utf8");
    #ifdef _WIN32
    if (m_connectionInfo.host == ".")                                           // named pipe use option (Windows)
    {
        unsigned int opt = MYSQL_PROTOCOL_PIPE;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        port = 0;
        unix_socket = 0;
    }
    else                                                    // generic case
    {
        port = atoi(m_connectionInfo.port_or_socket.c_str());
        unix_socket = 0;
    }
    #else
    if (m_connectionInfo.host == ".")                                           // socket use option (Unix/Linux)
    {
        unsigned int opt = MYSQL_PROTOCOL_SOCKET;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        m_connectionInfo.host = "localhost";
        port = 0;
        unix_socket = m_connectionInfo.port_or_socket.c_str();
    }
    else                                                    // generic case
    {
        port = atoi(m_connectionInfo.port_or_socket.c_str());
        unix_socket = 0;
    }
    #endif

    m_Mysql = mysql_real_connect(mysqlInit, m_connectionInfo.host.c_str(), m_connectionInfo.user.c_str(),
        m_connectionInfo.password.c_str(), m_connectionInfo.database.c_str(), port, unix_socket, 0);

    if (m_Mysql)
    {
        if (!m_reconnecting)
        {
            sLog->outSQLDriver("MySQL client library: %s", mysql_get_client_info());
            sLog->outSQLDriver("MySQL server ver: %s ", mysql_get_server_info(m_Mysql));
            if (mysql_get_server_version(m_Mysql) != mysql_get_client_version())
                sLog->outSQLDriver("[WARNING] MySQL client/server version mismatch; may conflict with behaviour of prepared statements.");
        }

        sLog->outDetail("Connected to MySQL database at %s", m_connectionInfo.host.c_str());
        mysql_autocommit(m_Mysql, 1);

        // set connection properties to UTF8 to properly handle locales for different
        // server configs - core sends data in UTF8, so MySQL must expect UTF8 too
        mysql_set_character_set(m_Mysql, "utf8");
        return true;
    }
    else
    {
        sLog->outError("Could not connect to MySQL database at %s: %s\n", m_connectionInfo.host.c_str(), mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return false;
    }
}

bool MySQLConnection::Execute(const char* sql)
{
    if (!m_Mysql)
        return false;

    {
        uint32 _s = 0;
        if (sLog->GetSQLDriverQueryLogging())
            _s = getMSTime();

        if (mysql_query(m_Mysql, sql))
        {
            uint32 lErrno = mysql_errno(m_Mysql);

            sLog->outSQLDriver("SQL: %s", sql);
            sLog->outSQLDriver("ERROR: [%u] %s", lErrno, mysql_error(m_Mysql));

            if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled succesfuly (ie reconnection)
                return Execute(sql);       // Try again

            return false;
        }
        else if (sLog->GetSQLDriverQueryLogging())
        {
            sLog->outSQLDriver("[%u ms] SQL: %s", getMSTimeDiff(_s, getMSTime()), sql);
        }
    }

    return true;
}

bool MySQLConnection::Execute(PreparedStatement* stmt)
{
    if (!m_Mysql)
        return false;

    uint32 index = stmt->m_index;
    {
        MySQLPreparedStatement* m_mStmt = GetPreparedStatement(index);
        ASSERT(m_mStmt);            // Can only be null if preparation failed, server side error or bad query
        m_mStmt->m_stmt = stmt;     // Cross reference them for debug output
        stmt->m_stmt = m_mStmt;     // TODO: Cleaner way

        stmt->BindParameters();

        MYSQL_STMT* msql_STMT = m_mStmt->GetSTMT();
        MYSQL_BIND* msql_BIND = m_mStmt->GetBind();

        uint32 _s = 0;
        if (sLog->GetSQLDriverQueryLogging())
            _s = getMSTime();

        if (mysql_stmt_bind_param(msql_STMT, msql_BIND))
        {
            uint32 lErrno = mysql_errno(m_Mysql);
            sLog->outSQLDriver("SQL(p): %s\n [ERROR]: [%u] %s",
                m_statementTable[index].query, lErrno, mysql_stmt_error(msql_STMT));

            if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled succesfuly (ie reconnection)
                return Execute(stmt);       // Try again

            m_mStmt->ClearParameters();
            return false;
        }

        if (mysql_stmt_execute(msql_STMT))
        {
            uint32 lErrno = mysql_errno(m_Mysql);
            sLog->outSQLDriver("SQL(p): %s\n [ERROR]: [%u] %s",
                m_statementTable[index].query, lErrno, mysql_stmt_error(msql_STMT));

            if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled succesfuly (ie reconnection)
                return Execute(stmt);       // Try again

            m_mStmt->ClearParameters();
            return false;
        }

        if (sLog->GetSQLDriverQueryLogging())
            sLog->outSQLDriver("[%u ms] SQL(p): %s",
            getMSTimeDiff(_s, getMSTime()), m_statementTable[index].query);

        m_mStmt->ClearParameters();
        return true;
    }
}

bool MySQLConnection::_Query(PreparedStatement* stmt, MYSQL_RES **pResult, uint64* pRowCount, uint32* pFieldCount)
{
    if (!m_Mysql)
        return false;

    uint32 index = stmt->m_index;
    {
        MySQLPreparedStatement* m_mStmt = GetPreparedStatement(index);
        ASSERT(m_mStmt);            // Can only be null if preparation failed, server side error or bad query
        m_mStmt->m_stmt = stmt;     // Cross reference them for debug output
        stmt->m_stmt = m_mStmt;     // TODO: Cleaner way

        stmt->BindParameters();

        MYSQL_STMT* msql_STMT = m_mStmt->GetSTMT();
        MYSQL_BIND* msql_BIND = m_mStmt->GetBind();

        uint32 _s = 0;
        if (sLog->GetSQLDriverQueryLogging())
            _s = getMSTime();

        if (mysql_stmt_bind_param(msql_STMT, msql_BIND))
        {
            uint32 lErrno = mysql_errno(m_Mysql);
            sLog->outSQLDriver("SQL(p): %s\n [ERROR]: [%u] %s",
                m_statementTable[index].query, lErrno, mysql_stmt_error(msql_STMT));

            if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled succesfuly (ie reconnection)
                return _Query(stmt, pResult, pRowCount, pFieldCount);       // Try again

            m_mStmt->ClearParameters();
            return false;
        }

        if (mysql_stmt_execute(msql_STMT))
        {
            uint32 lErrno = mysql_errno(m_Mysql);
            sLog->outSQLDriver("SQL(p): %s\n [ERROR]: [%u] %s",
                m_statementTable[index].query, lErrno, mysql_stmt_error(msql_STMT));

            if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled succesfuly (ie reconnection)
                return _Query(stmt, pResult, pRowCount, pFieldCount);      // Try again

            m_mStmt->ClearParameters();
            return false;
        }

        if (sLog->GetSQLDriverQueryLogging())
            sLog->outSQLDriver("[%u ms] SQL(p): %s",
                getMSTimeDiff(_s, getMSTime()), m_statementTable[index].query);

        m_mStmt->ClearParameters();

        *pResult = mysql_stmt_result_metadata(msql_STMT);
        *pRowCount = mysql_stmt_num_rows(msql_STMT);
        *pFieldCount = mysql_stmt_field_count(msql_STMT);

        return true;

    }
}

ResultSet* MySQLConnection::Query(const char* sql)
{
    if (!sql)
        return NULL;

    MYSQL_RES *result = NULL;
    MYSQL_FIELD *fields = NULL;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(sql, &result, &fields, &rowCount, &fieldCount))
        return NULL;

    return new ResultSet(result, fields, rowCount, fieldCount);
}

bool MySQLConnection::_Query(const char *sql, MYSQL_RES **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount)
{
    if (!m_Mysql)
        return false;

    {
        uint32 _s = 0;
        if (sLog->GetSQLDriverQueryLogging())
            _s = getMSTime();

        if (mysql_query(m_Mysql, sql))
        {
            uint32 lErrno = mysql_errno(m_Mysql);
            sLog->outSQLDriver("SQL: %s", sql);
            sLog->outSQLDriver("ERROR: [%u] %s", lErrno, mysql_error(m_Mysql));

            if (_HandleMySQLErrno(lErrno))      // If it returns true, an error was handled succesfuly (ie reconnection)
                return _Query(sql, pResult, pFields, pRowCount, pFieldCount);    // We try again 

            return false;
        }
        else if (sLog->GetSQLDriverQueryLogging())
        {
            sLog->outSQLDriver("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql);
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
    ASSERT(index < m_stmts.size());
    MySQLPreparedStatement* ret = m_stmts[index];
    if (!ret)
        sLog->outSQLDriver("ERROR: Could not fetch prepared statement %u on database `%s`, connection type: %s.",
            index, m_connectionInfo.database.c_str(), (m_connectionFlags & CONNECTION_ASYNC) ? "asynchronous" : "synchronous");

    return ret;
}

void MySQLConnection::PrepareStatement(uint32 index, const char* sql, ConnectionFlags flags)
{
    // For reconnection case
    if (m_reconnecting)
        delete m_stmts[index];

    // Check if specified query should be prepared on this connection
    // ie. don't prepare async statements on synchronous connections
    // to save memory that will not be used.
    if (!(m_connectionFlags & flags))
    {
        m_stmts[index] = NULL;
        return;
    }

    MYSQL_STMT * stmt = mysql_stmt_init(m_Mysql);
    if (!stmt)
    {
        sLog->outSQLDriver("[ERROR]: In mysql_stmt_init() id: %u, sql: \"%s\"", index, sql);
        sLog->outSQLDriver("[ERROR]: %s", mysql_error(m_Mysql));
        exit(1);
    }

    if (mysql_stmt_prepare(stmt, sql, static_cast<unsigned long>(strlen(sql))))
    {
        sLog->outSQLDriver("[ERROR]: In mysql_stmt_prepare() id: %u, sql: \"%s\"", index, sql);
        sLog->outSQLDriver("[ERROR]: %s", mysql_stmt_error(stmt));
        mysql_stmt_close(stmt);
        exit(1);
    }

    MySQLPreparedStatement* mStmt = new MySQLPreparedStatement(stmt);
    m_stmts[index] = mStmt;
}

PreparedResultSet* MySQLConnection::Query(PreparedStatement* stmt)
{
    MYSQL_RES *result = NULL;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(stmt, &result, &rowCount, &fieldCount))
        return NULL;

    if (mysql_more_results(m_Mysql))
    {
        mysql_next_result(m_Mysql);
    }
    return new PreparedResultSet(stmt->m_stmt->GetSTMT(), result, rowCount, fieldCount);
}

bool MySQLConnection::_HandleMySQLErrno(uint32 errNo)
{
    sLog->outDebug("%s", __FUNCTION__);

    switch (errNo)
    {
        case 2006:  // "MySQL server has gone away"
        case 2013:  // "Lost connection to MySQL server during query"
        case 2048:  // "Invalid connection handle"
        case 2055:  // "Lost connection to MySQL server at '%s', system error: %d"
        {
            m_reconnecting = true;
            uint64 oldThreadId = mysql_thread_id(GetHandle());
            mysql_close(GetHandle());
            if (this->Open())                           // Don't remove 'this' pointer unless you want to skip loading all prepared statements....
            {
                sLog->outSQLDriver("Connection to the MySQL server is active.");
                if (oldThreadId != mysql_thread_id(GetHandle()))
                    sLog->outSQLDriver("Succesfuly reconnected to %s @%s:%s (%s).", 
                        m_connectionInfo.database.c_str(), m_connectionInfo.host.c_str(), m_connectionInfo.port_or_socket.c_str(),
                            (m_connectionFlags & CONNECTION_ASYNC) ? "asynchronous" : "synchronous");

                m_reconnecting = false;
                return true;
            }

            uint32 lErrno = mysql_errno(GetHandle());   // It's possible this attempted reconnect throws 2006 at us. To prevent crazy recursive calls, sleep here.
            ACE_OS::sleep(3);                           // Sleep 3 seconds
            return _HandleMySQLErrno(lErrno);           // Call self (recursive)
        }

        // Query related errors - skip query
        case 1058:      // "Column count doesn't match value count"
        case 1062:      // "Duplicate entry '%s' for key '%d'"
        case 1054:      // "Unknown column '%s' in 'order clause'"
            return false;

        default:
            sLog->outSQLDriver("Unhandled MySQL errno %u. Unexpected behaviour possible.", errNo);
            return false;
    }
}
