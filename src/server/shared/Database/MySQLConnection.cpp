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

#include "MySQLConnection.h"
#include "MySQLThreading.h"
#include "QueryResult.h"
#include "SQLOperation.h"
#include "PreparedStatement.h"
#include "DatabaseWorker.h"
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
    ASSERT (m_Mysql); /// MySQL context must be present at this point

    sLog.outSQLDriver("MySQLConnection::~MySQLConnection()");
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

bool MySQLConnection::Open(const MySQLConnectionInfo& connInfo)
{
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);
    if (!mysqlInit)
    {
        sLog.outError("Could not initialize Mysql connection");
        return false;
    }

    int port;
    char const* unix_socket;

    mysql_options(mysqlInit, MYSQL_SET_CHARSET_NAME, "utf8");
    #ifdef _WIN32
    if (connInfo.host == ".")                                           // named pipe use option (Windows)
    {
        unsigned int opt = MYSQL_PROTOCOL_PIPE;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        port = 0;
        unix_socket = 0;
    }
    else                                                    // generic case
    {
        port = atoi(connInfo.port_or_socket.c_str());
        unix_socket = 0;
    }
    #else
    if (connInfo.host == ".")                                           // socket use option (Unix/Linux)
    {
        unsigned int opt = MYSQL_PROTOCOL_SOCKET;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        connInfo.ChangeHost("localhost");
        port = 0;
        unix_socket = connInfo.port_or_socket.c_str();
    }
    else                                                    // generic case
    {
        port = atoi(connInfo.port_or_socket.c_str());
        unix_socket = 0;
    }
    #endif

    m_Mysql = mysql_real_connect(mysqlInit, connInfo.host.c_str(), connInfo.user.c_str(),
        connInfo.password.c_str(), connInfo.database.c_str(), port, unix_socket, 0);

    if (m_Mysql)
    {
        sLog.outSQLDriver("MySQL client library: %s", mysql_get_client_info());
        sLog.outSQLDriver("MySQL server ver: %s ", mysql_get_server_info(m_Mysql));
        if (mysql_get_server_version(m_Mysql) != mysql_get_client_version())
            sLog.outSQLDriver("[WARNING] MySQL client/server version mismatch; may conflict with behaviour of prepared statements.");

        sLog.outDetail("Connected to MySQL database at %s", connInfo.host.c_str());
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
        sLog.outError("Could not connect to MySQL database at %s: %s\n", connInfo.host.c_str(), mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return false;
    }
}

bool MySQLConnection::Execute(const char* sql)
{
    if (!m_Mysql)
        return false;

    {
        #ifdef SQLQUERY_LOG
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
            #ifdef SQLQUERY_LOG
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
    {
        MySQLPreparedStatement* m_mStmt = GetPreparedStatement(index);
        ASSERT(m_mStmt);            // Can only be null if preparation failed, server side error or bad query
        m_mStmt->m_stmt = stmt;     // Cross reference them for debug output
        stmt->m_stmt = m_mStmt;     // TODO: Cleaner way

        stmt->BindParameters();

        MYSQL_STMT* msql_STMT = m_mStmt->GetSTMT();
        MYSQL_BIND* msql_BIND = m_mStmt->GetBind();

        #ifdef SQLQUERY_LOG
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

        #ifdef SQLQUERY_LOG
        sLog.outSQLDriver("[%u ms] Prepared SQL: %u", getMSTimeDiff(_s, getMSTime()), index);
        #endif
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

        #ifdef SQLQUERY_LOG
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

        #ifdef SQLQUERY_LOG
        sLog.outSQLDriver("[%u ms] Prepared SQL: %u", getMSTimeDiff(_s, getMSTime()), index);
        #endif
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
        #ifdef SQLQUERY_LOG
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
            #ifdef SQLQUERY_LOG
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
    ASSERT(index < m_stmts.size());
    return m_stmts[index];
}

void MySQLConnection::PrepareStatement(uint32 index, const char* sql)
{
    MYSQL_STMT * stmt = mysql_stmt_init(m_Mysql);
    if (!stmt)
    {
        sLog.outSQLDriver("[ERROR]: In mysql_stmt_init() id: %u, sql: \"%s\"", index, sql);
        sLog.outSQLDriver("[ERROR]: %s", mysql_error(m_Mysql));
        exit(1);
    }

    if (mysql_stmt_prepare(stmt, sql, static_cast<unsigned long>(strlen(sql))))
    {
        sLog.outSQLDriver("[ERROR]: In mysql_stmt_prepare() id: %u, sql: \"%s\"", index, sql);
        sLog.outSQLDriver("[ERROR]: %s", mysql_stmt_error(stmt));
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
