/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "MySQLConnection.h"
#include "Common.h"
#include "DatabaseWorker.h"
#include "Log.h"
#include "PreparedStatement.h"
#include "QueryResult.h"
#include "Timer.h"
#include "Transaction.h"
#include "Util.h"
#include <errmsg.h>
#ifdef _WIN32 // hack for broken mysql.h not including the correct winsock header for SOCKET definition, fixed in 5.7
#include <winsock2.h>
#endif
#include <mysql.h>
#include <mysqld_error.h>

MySQLConnectionInfo::MySQLConnectionInfo(std::string const& infoString)
{
    Tokenizer tokens(infoString, ';');

    if (tokens.size() != 5)
        return;

    uint8 i = 0;

    host.assign(tokens[i++]);
    port_or_socket.assign(tokens[i++]);
    user.assign(tokens[i++]);
    password.assign(tokens[i++]);
    database.assign(tokens[i++]);
}

MySQLConnection::MySQLConnection(MySQLConnectionInfo& connInfo) :
m_reconnecting(false),
m_prepareError(false),
m_queue(nullptr),
m_Mysql(nullptr),
m_connectionInfo(connInfo),
m_connectionFlags(CONNECTION_SYNCH) { }

MySQLConnection::MySQLConnection(ProducerConsumerQueue<SQLOperation*>* queue, MySQLConnectionInfo& connInfo) :
m_reconnecting(false),
m_prepareError(false),
m_queue(queue),
m_Mysql(nullptr),
m_connectionInfo(connInfo),
m_connectionFlags(CONNECTION_ASYNC)
{
    m_worker = Trinity::make_unique<DatabaseWorker>(m_queue, this);
}

MySQLConnection::~MySQLConnection()
{
    Close();
}

void MySQLConnection::Close()
{
    // Stop the worker thread before the statements are cleared
    m_worker.reset();

    m_stmts.clear();

    if (m_Mysql)
    {
        mysql_close(m_Mysql);
        m_Mysql = nullptr;
    }
}

uint32 MySQLConnection::Open()
{
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(nullptr);
    if (!mysqlInit)
    {
        TC_LOG_ERROR("sql.sql", "Could not initialize Mysql connection to database `%s`", m_connectionInfo.database.c_str());
        return CR_UNKNOWN_ERROR;
    }

    int port;
    char const* unix_socket;
    //unsigned int timeout = 10;

    mysql_options(mysqlInit, MYSQL_SET_CHARSET_NAME, "utf8");
    //mysql_options(mysqlInit, MYSQL_OPT_READ_TIMEOUT, (char const*)&timeout);
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
        unix_socket = nullptr;
    }
    #endif

    m_Mysql = mysql_real_connect(mysqlInit, m_connectionInfo.host.c_str(), m_connectionInfo.user.c_str(),
        m_connectionInfo.password.c_str(), m_connectionInfo.database.c_str(), port, unix_socket, 0);

    if (m_Mysql)
    {
        if (!m_reconnecting)
        {
            TC_LOG_INFO("sql.sql", "MySQL client library: %s", mysql_get_client_info());
            TC_LOG_INFO("sql.sql", "MySQL server ver: %s ", mysql_get_server_info(m_Mysql));
            // MySQL version above 5.1 IS required in both client and server and there is no known issue with different versions above 5.1
            // if (mysql_get_server_version(m_Mysql) != mysql_get_client_version())
            //     TC_LOG_INFO("sql.sql", "[WARNING] MySQL client/server version mismatch; may conflict with behaviour of prepared statements.");
        }

        TC_LOG_INFO("sql.sql", "Connected to MySQL database at %s", m_connectionInfo.host.c_str());
        mysql_autocommit(m_Mysql, 1);

        // set connection properties to UTF8 to properly handle locales for different
        // server configs - core sends data in UTF8, so MySQL must expect UTF8 too
        mysql_set_character_set(m_Mysql, "utf8");
        return 0;
    }
    else
    {
        TC_LOG_ERROR("sql.sql", "Could not connect to MySQL database at %s: %s", m_connectionInfo.host.c_str(), mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return mysql_errno(mysqlInit);
    }
}

bool MySQLConnection::PrepareStatements()
{
    DoPrepareStatements();
    return !m_prepareError;
}

bool MySQLConnection::Execute(char const* sql)
{
    if (!m_Mysql)
        return false;

    {
        uint32 _s = getMSTime();

        if (mysql_query(m_Mysql, sql))
        {
            uint32 lErrno = mysql_errno(m_Mysql);

            TC_LOG_INFO("sql.sql", "SQL: %s", sql);
            TC_LOG_ERROR("sql.sql", "[%u] %s", lErrno, mysql_error(m_Mysql));

            if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled successfully (i.e. reconnection)
                return Execute(sql);       // Try again

            return false;
        }
        else
            TC_LOG_DEBUG("sql.sql", "[%u ms] SQL: %s", getMSTimeDiff(_s, getMSTime()), sql);
    }

    return true;
}

bool MySQLConnection::Execute(PreparedStatement* stmt)
{
    if (!m_Mysql)
        return false;

    uint32 index = stmt->m_index;

    MySQLPreparedStatement* m_mStmt = GetPreparedStatement(index);
    ASSERT(m_mStmt);            // Can only be null if preparation failed, server side error or bad query
    m_mStmt->m_stmt = stmt;     // Cross reference them for debug output

    stmt->BindParameters(m_mStmt);

    MYSQL_STMT* msql_STMT = m_mStmt->GetSTMT();
    MYSQL_BIND* msql_BIND = m_mStmt->GetBind();

    uint32 _s = getMSTime();

    if (mysql_stmt_bind_param(msql_STMT, msql_BIND))
    {
        uint32 lErrno = mysql_errno(m_Mysql);
        TC_LOG_ERROR("sql.sql", "SQL(p): %s\n [ERROR]: [%u] %s", m_mStmt->getQueryString().c_str(), lErrno, mysql_stmt_error(msql_STMT));

        if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled successfully (i.e. reconnection)
            return Execute(stmt);       // Try again

        m_mStmt->ClearParameters();
        return false;
    }

    if (mysql_stmt_execute(msql_STMT))
    {
        uint32 lErrno = mysql_errno(m_Mysql);
        TC_LOG_ERROR("sql.sql", "SQL(p): %s\n [ERROR]: [%u] %s", m_mStmt->getQueryString().c_str(), lErrno, mysql_stmt_error(msql_STMT));

        if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled successfully (i.e. reconnection)
            return Execute(stmt);       // Try again

        m_mStmt->ClearParameters();
        return false;
    }

    TC_LOG_DEBUG("sql.sql", "[%u ms] SQL(p): %s", getMSTimeDiff(_s, getMSTime()), m_mStmt->getQueryString().c_str());

    m_mStmt->ClearParameters();
    return true;
}

bool MySQLConnection::_Query(PreparedStatement* stmt, MYSQL_RES **pResult, uint64* pRowCount, uint32* pFieldCount)
{
    if (!m_Mysql)
        return false;

    uint32 index = stmt->m_index;

    MySQLPreparedStatement* m_mStmt = GetPreparedStatement(index);
    ASSERT(m_mStmt);            // Can only be null if preparation failed, server side error or bad query
    m_mStmt->m_stmt = stmt;     // Cross reference them for debug output

    stmt->BindParameters(m_mStmt);

    MYSQL_STMT* msql_STMT = m_mStmt->GetSTMT();
    MYSQL_BIND* msql_BIND = m_mStmt->GetBind();

    uint32 _s = getMSTime();

    if (mysql_stmt_bind_param(msql_STMT, msql_BIND))
    {
        uint32 lErrno = mysql_errno(m_Mysql);
        TC_LOG_ERROR("sql.sql", "SQL(p): %s\n [ERROR]: [%u] %s", m_mStmt->getQueryString().c_str(), lErrno, mysql_stmt_error(msql_STMT));

        if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled successfully (i.e. reconnection)
            return _Query(stmt, pResult, pRowCount, pFieldCount);       // Try again

        m_mStmt->ClearParameters();
        return false;
    }

    if (mysql_stmt_execute(msql_STMT))
    {
        uint32 lErrno = mysql_errno(m_Mysql);
        TC_LOG_ERROR("sql.sql", "SQL(p): %s\n [ERROR]: [%u] %s",
            m_mStmt->getQueryString().c_str(), lErrno, mysql_stmt_error(msql_STMT));

        if (_HandleMySQLErrno(lErrno))  // If it returns true, an error was handled successfully (i.e. reconnection)
            return _Query(stmt, pResult, pRowCount, pFieldCount);      // Try again

        m_mStmt->ClearParameters();
        return false;
    }

    TC_LOG_DEBUG("sql.sql", "[%u ms] SQL(p): %s", getMSTimeDiff(_s, getMSTime()), m_mStmt->getQueryString().c_str());

    m_mStmt->ClearParameters();

    *pResult = mysql_stmt_result_metadata(msql_STMT);
    *pRowCount = mysql_stmt_num_rows(msql_STMT);
    *pFieldCount = mysql_stmt_field_count(msql_STMT);

    return true;
}

ResultSet* MySQLConnection::Query(char const* sql)
{
    if (!sql)
        return nullptr;

    MYSQL_RES *result = nullptr;
    MYSQL_FIELD *fields = nullptr;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(sql, &result, &fields, &rowCount, &fieldCount))
        return nullptr;

    return new ResultSet(result, fields, rowCount, fieldCount);
}

bool MySQLConnection::_Query(const char *sql, MYSQL_RES **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount)
{
    if (!m_Mysql)
        return false;

    {
        uint32 _s = getMSTime();

        if (mysql_query(m_Mysql, sql))
        {
            uint32 lErrno = mysql_errno(m_Mysql);
            TC_LOG_INFO("sql.sql", "SQL: %s", sql);
            TC_LOG_ERROR("sql.sql", "[%u] %s", lErrno, mysql_error(m_Mysql));

            if (_HandleMySQLErrno(lErrno))      // If it returns true, an error was handled successfully (i.e. reconnection)
                return _Query(sql, pResult, pFields, pRowCount, pFieldCount);    // We try again

            return false;
        }
        else
            TC_LOG_DEBUG("sql.sql", "[%u ms] SQL: %s", getMSTimeDiff(_s, getMSTime()), sql);

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

int MySQLConnection::ExecuteTransaction(SQLTransaction& transaction)
{
    std::vector<SQLElementData> const& queries = transaction->m_queries;
    if (queries.empty())
        return -1;

    BeginTransaction();

    for (auto itr = queries.begin(); itr != queries.end(); ++itr)
    {
        SQLElementData const& data = *itr;
        switch (itr->type)
        {
            case SQL_ELEMENT_PREPARED:
            {
                PreparedStatement* stmt = data.element.stmt;
                ASSERT(stmt);
                if (!Execute(stmt))
                {
                    TC_LOG_WARN("sql.sql", "Transaction aborted. %u queries not executed.", (uint32)queries.size());
                    int errorCode = GetLastError();
                    RollbackTransaction();
                    return errorCode;
                }
            }
            break;
            case SQL_ELEMENT_RAW:
            {
                char const* sql = data.element.query;
                ASSERT(sql);
                if (!Execute(sql))
                {
                    TC_LOG_WARN("sql.sql", "Transaction aborted. %u queries not executed.", (uint32)queries.size());
                    int errorCode = GetLastError();
                    RollbackTransaction();
                    return errorCode;
                }
            }
            break;
        }
    }

    // we might encounter errors during certain queries, and depending on the kind of error
    // we might want to restart the transaction. So to prevent data loss, we only clean up when it's all done.
    // This is done in calling functions DatabaseWorkerPool<T>::DirectCommitTransaction and TransactionTask::Execute,
    // and not while iterating over every element.

    CommitTransaction();
    return 0;
}

void MySQLConnection::Ping()
{
    mysql_ping(m_Mysql);
}

uint32 MySQLConnection::GetLastError()
{
    return mysql_errno(m_Mysql);
}

bool MySQLConnection::LockIfReady()
{
    return m_Mutex.try_lock();
}

void MySQLConnection::Unlock()
{
    m_Mutex.unlock();
}

MySQLPreparedStatement* MySQLConnection::GetPreparedStatement(uint32 index)
{
    ASSERT(index < m_stmts.size());
    MySQLPreparedStatement* ret = m_stmts[index].get();
    if (!ret)
        TC_LOG_ERROR("sql.sql", "Could not fetch prepared statement %u on database `%s`, connection type: %s.",
            index, m_connectionInfo.database.c_str(), (m_connectionFlags & CONNECTION_ASYNC) ? "asynchronous" : "synchronous");

    return ret;
}

void MySQLConnection::PrepareStatement(uint32 index, std::string const& sql, ConnectionFlags flags)
{
    // Check if specified query should be prepared on this connection
    // i.e. don't prepare async statements on synchronous connections
    // to save memory that will not be used.
    if (!(m_connectionFlags & flags))
    {
        m_stmts[index].reset();
        return;
    }

    MYSQL_STMT* stmt = mysql_stmt_init(m_Mysql);
    if (!stmt)
    {
        TC_LOG_ERROR("sql.sql", "In mysql_stmt_init() id: %u, sql: \"%s\"", index, sql.c_str());
        TC_LOG_ERROR("sql.sql", "%s", mysql_error(m_Mysql));
        m_prepareError = true;
    }
    else
    {
        if (mysql_stmt_prepare(stmt, sql.c_str(), static_cast<unsigned long>(sql.size())))
        {
            TC_LOG_ERROR("sql.sql", "In mysql_stmt_prepare() id: %u, sql: \"%s\"", index, sql.c_str());
            TC_LOG_ERROR("sql.sql", "%s", mysql_stmt_error(stmt));
            mysql_stmt_close(stmt);
            m_prepareError = true;
        }
        else
            m_stmts[index] = Trinity::make_unique<MySQLPreparedStatement>(stmt, sql);
    }
}

PreparedResultSet* MySQLConnection::Query(PreparedStatement* stmt)
{
    MYSQL_RES *result = nullptr;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(stmt, &result, &rowCount, &fieldCount))
        return nullptr;

    if (mysql_more_results(m_Mysql))
    {
        mysql_next_result(m_Mysql);
    }
    return new PreparedResultSet(stmt->m_stmt->GetSTMT(), result, rowCount, fieldCount);
}

bool MySQLConnection::_HandleMySQLErrno(uint32 errNo, uint8 attempts /*= 5*/)
{
    switch (errNo)
    {
        case CR_SERVER_GONE_ERROR:
        case CR_SERVER_LOST:
        case CR_INVALID_CONN_HANDLE:
        case CR_SERVER_LOST_EXTENDED:
        {
            if (m_Mysql)
            {
                TC_LOG_ERROR("sql.sql", "Lost the connection to the MySQL server!");

                mysql_close(GetHandle());
                m_Mysql = nullptr;
            }

            /*no break*/
        }
        case CR_CONN_HOST_ERROR:
        {
            TC_LOG_INFO("sql.sql", "Attempting to reconnect to the MySQL server...");

            m_reconnecting = true;

            uint32 const lErrno = Open();
            if (!lErrno)
            {
                // Don't remove 'this' pointer unless you want to skip loading all prepared statements...
                if (!this->PrepareStatements())
                {
                    TC_LOG_FATAL("sql.sql", "Could not re-prepare statements!");
                    std::this_thread::sleep_for(std::chrono::seconds(10));
                    std::abort();
                }

                TC_LOG_INFO("sql.sql", "Successfully reconnected to %s @%s:%s (%s).",
                    m_connectionInfo.database.c_str(), m_connectionInfo.host.c_str(), m_connectionInfo.port_or_socket.c_str(),
                        (m_connectionFlags & CONNECTION_ASYNC) ? "asynchronous" : "synchronous");

                m_reconnecting = false;
                return true;
            }

            if ((--attempts) == 0)
            {
                // Shut down the server when the mysql server isn't
                // reachable for some time
                TC_LOG_FATAL("sql.sql", "Failed to reconnect to the MySQL server, "
                             "terminating the server to prevent data corruption!");

                // We could also initiate a shutdown through using std::raise(SIGTERM)
                std::this_thread::sleep_for(std::chrono::seconds(10));
                std::abort();
            }
            else
            {
                // It's possible this attempted reconnect throws 2006 at us.
                // To prevent crazy recursive calls, sleep here.
                std::this_thread::sleep_for(std::chrono::seconds(3)); // Sleep 3 seconds
                return _HandleMySQLErrno(lErrno, attempts); // Call self (recursive)
            }
        }

        case ER_LOCK_DEADLOCK:
            return false;    // Implemented in TransactionTask::Execute and DatabaseWorkerPool<T>::DirectCommitTransaction
        // Query related errors - skip query
        case ER_WRONG_VALUE_COUNT:
        case ER_DUP_ENTRY:
            return false;

        // Outdated table or database structure - terminate core
        case ER_BAD_FIELD_ERROR:
        case ER_NO_SUCH_TABLE:
            TC_LOG_ERROR("sql.sql", "Your database structure is not up to date. Please make sure you've executed all queries in the sql/updates folders.");
            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::abort();
            return false;
        case ER_PARSE_ERROR:
            TC_LOG_ERROR("sql.sql", "Error while parsing SQL. Core fix required.");
            std::this_thread::sleep_for(std::chrono::seconds(10));
            std::abort();
            return false;
        default:
            TC_LOG_ERROR("sql.sql", "Unhandled MySQL errno %u. Unexpected behaviour possible.", errNo);
            return false;
    }
}
