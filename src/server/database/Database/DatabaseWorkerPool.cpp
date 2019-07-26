/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "DatabaseWorkerPool.h"
#include "AdhocStatement.h"
#include "Common.h"
#include "Errors.h"
#include "Implementation/LoginDatabase.h"
#include "Implementation/WorldDatabase.h"
#include "Implementation/CharacterDatabase.h"
#include "Implementation/HotfixDatabase.h"
#include "Log.h"
#include "PreparedStatement.h"
#include "ProducerConsumerQueue.h"
#include "QueryCallback.h"
#include "QueryHolder.h"
#include "QueryResult.h"
#include "SQLOperation.h"
#include "Transaction.h"
#ifdef _WIN32 // hack for broken mysql.h not including the correct winsock header for SOCKET definition, fixed in 5.7
#include <winsock2.h>
#endif
#include <mysql.h>
#include <mysqld_error.h>

#define MIN_MYSQL_SERVER_VERSION 50100u
#define MIN_MYSQL_CLIENT_VERSION 50100u

class PingOperation : public SQLOperation
{
    //! Operation for idle delaythreads
    bool Execute() override
    {
        m_conn->Ping();
        return true;
    }
};

template <class T>
DatabaseWorkerPool<T>::DatabaseWorkerPool()
    : _queue(new ProducerConsumerQueue<SQLOperation*>()),
      _async_threads(0), _synch_threads(0)
{
    WPFatal(mysql_thread_safe(), "Used MySQL library isn't thread-safe.");
    WPFatal(mysql_get_client_version() >= MIN_MYSQL_CLIENT_VERSION, "TrinityCore does not support MySQL versions below 5.1");
    WPFatal(mysql_get_client_version() == MYSQL_VERSION_ID, "Used MySQL library version (%s) does not match the version used to compile TrinityCore (%s). Search on forum for TCE00011.",
        mysql_get_client_info(), MYSQL_SERVER_VERSION);
}

template <class T>
DatabaseWorkerPool<T>::~DatabaseWorkerPool()
{
    _queue->Cancel();
}

template <class T>
void DatabaseWorkerPool<T>::SetConnectionInfo(std::string const& infoString,
    uint8 const asyncThreads, uint8 const synchThreads)
{
    _connectionInfo = Trinity::make_unique<MySQLConnectionInfo>(infoString);

    _async_threads = asyncThreads;
    _synch_threads = synchThreads;
}

template <class T>
uint32 DatabaseWorkerPool<T>::Open()
{
    WPFatal(_connectionInfo.get(), "Connection info was not set!");

    TC_LOG_INFO("sql.driver", "Opening DatabasePool '%s'. "
        "Asynchronous connections: %u, synchronous connections: %u.",
        GetDatabaseName(), _async_threads, _synch_threads);

    uint32 error = OpenConnections(IDX_ASYNC, _async_threads);

    if (error)
        return error;

    error = OpenConnections(IDX_SYNCH, _synch_threads);

    if (!error)
    {
        TC_LOG_INFO("sql.driver", "DatabasePool '%s' opened successfully. " SZFMTD
                    " total connections running.", GetDatabaseName(),
                    (_connections[IDX_SYNCH].size() + _connections[IDX_ASYNC].size()));
    }

    return error;
}

template <class T>
void DatabaseWorkerPool<T>::Close()
{
    TC_LOG_INFO("sql.driver", "Closing down DatabasePool '%s'.", GetDatabaseName());

    //! Closes the actualy MySQL connection.
    _connections[IDX_ASYNC].clear();

    TC_LOG_INFO("sql.driver", "Asynchronous connections on DatabasePool '%s' terminated. "
                "Proceeding with synchronous connections.",
        GetDatabaseName());

    //! Shut down the synchronous connections
    //! There's no need for locking the connection, because DatabaseWorkerPool<>::Close
    //! should only be called after any other thread tasks in the core have exited,
    //! meaning there can be no concurrent access at this point.
    _connections[IDX_SYNCH].clear();

    TC_LOG_INFO("sql.driver", "All connections on DatabasePool '%s' closed.", GetDatabaseName());
}

template <class T>
bool DatabaseWorkerPool<T>::PrepareStatements()
{
    for (auto& connections : _connections)
        for (auto& connection : connections)
        {
            connection->LockIfReady();
            if (!connection->PrepareStatements())
            {
                connection->Unlock();
                Close();
                return false;
            }
            else
                connection->Unlock();
        }

    return true;
}

template <class T>
QueryResult DatabaseWorkerPool<T>::Query(const char* sql, T* connection /*= nullptr*/)
{
    if (!connection)
        connection = GetFreeConnection();

    ResultSet* result = connection->Query(sql);
    connection->Unlock();
    if (!result || !result->GetRowCount() || !result->NextRow())
    {
        delete result;
        return QueryResult(NULL);
    }

    return QueryResult(result);
}

template <class T>
PreparedQueryResult DatabaseWorkerPool<T>::Query(PreparedStatement<T>* stmt)
{
    auto connection = GetFreeConnection();
    PreparedResultSet* ret = connection->Query(stmt);
    connection->Unlock();

    //! Delete proxy-class. Not needed anymore
    delete stmt;

    if (!ret || !ret->GetRowCount())
    {
        delete ret;
        return PreparedQueryResult(NULL);
    }

    return PreparedQueryResult(ret);
}

template <class T>
QueryCallback DatabaseWorkerPool<T>::AsyncQuery(const char* sql)
{
    BasicStatementTask* task = new BasicStatementTask(sql, true);
    // Store future result before enqueueing - task might get already processed and deleted before returning from this method
    QueryResultFuture result = task->GetFuture();
    Enqueue(task);
    return QueryCallback(std::move(result));
}

template <class T>
QueryCallback DatabaseWorkerPool<T>::AsyncQuery(PreparedStatement<T>* stmt)
{
    PreparedStatementTask* task = new PreparedStatementTask(stmt, true);
    // Store future result before enqueueing - task might get already processed and deleted before returning from this method
    PreparedQueryResultFuture result = task->GetFuture();
    Enqueue(task);
    return QueryCallback(std::move(result));
}

template <class T>
QueryResultHolderFuture DatabaseWorkerPool<T>::DelayQueryHolder(SQLQueryHolder* holder)
{
    SQLQueryHolderTask* task = new SQLQueryHolderTask(holder);
    // Store future result before enqueueing - task might get already processed and deleted before returning from this method
    QueryResultHolderFuture result = task->GetFuture();
    Enqueue(task);
    return result;
}

template <class T>
SQLTransaction DatabaseWorkerPool<T>::BeginTransaction()
{
    return std::make_shared<Transaction>();
}

template <class T>
void DatabaseWorkerPool<T>::CommitTransaction(SQLTransaction transaction)
{
#ifdef TRINITY_DEBUG
    //! Only analyze transaction weaknesses in Debug mode.
    //! Ideally we catch the faults in Debug mode and then correct them,
    //! so there's no need to waste these CPU cycles in Release mode.
    switch (transaction->GetSize())
    {
    case 0:
        TC_LOG_DEBUG("sql.driver", "Transaction contains 0 queries. Not executing.");
        return;
    case 1:
        TC_LOG_DEBUG("sql.driver", "Warning: Transaction only holds 1 query, consider removing Transaction context in code.");
        break;
    default:
        break;
    }
#endif // TRINITY_DEBUG

    Enqueue(new TransactionTask(transaction));
}

template <class T>
void DatabaseWorkerPool<T>::DirectCommitTransaction(SQLTransaction& transaction)
{
    T* connection = GetFreeConnection();
    int errorCode = connection->ExecuteTransaction(transaction);
    if (!errorCode)
    {
        connection->Unlock();      // OK, operation succesful
        return;
    }

    //! Handle MySQL Errno 1213 without extending deadlock to the core itself
    /// @todo More elegant way
    if (errorCode == ER_LOCK_DEADLOCK)
    {
        uint8 loopBreaker = 5;
        for (uint8 i = 0; i < loopBreaker; ++i)
        {
            if (!connection->ExecuteTransaction(transaction))
                break;
        }
    }

    //! Clean up now.
    transaction->Cleanup();

    connection->Unlock();
}

template <class T>
PreparedStatement<T>* DatabaseWorkerPool<T>::GetPreparedStatement(PreparedStatementIndex index)
{
    return new PreparedStatement<T>(index);
}

template <class T>
void DatabaseWorkerPool<T>::EscapeString(std::string& str)
{
    if (str.empty())
        return;

    char* buf = new char[str.size() * 2 + 1];
    EscapeString(buf, str.c_str(), uint32(str.size()));
    str = buf;
    delete[] buf;
}

template <class T>
void DatabaseWorkerPool<T>::KeepAlive()
{
    //! Ping synchronous connections
    for (auto& connection : _connections[IDX_SYNCH])
    {
        if (connection->LockIfReady())
        {
            connection->Ping();
            connection->Unlock();
        }
    }

    //! Assuming all worker threads are free, every worker thread will receive 1 ping operation request
    //! If one or more worker threads are busy, the ping operations will not be split evenly, but this doesn't matter
    //! as the sole purpose is to prevent connections from idling.
    auto const count = _connections[IDX_ASYNC].size();
    for (uint8 i = 0; i < count; ++i)
        Enqueue(new PingOperation);
}

template <class T>
uint32 DatabaseWorkerPool<T>::OpenConnections(InternalIndex type, uint8 numConnections)
{
    for (uint8 i = 0; i < numConnections; ++i)
    {
        // Create the connection
        auto connection = [&] {
            switch (type)
            {
            case IDX_ASYNC:
                return Trinity::make_unique<T>(_queue.get(), *_connectionInfo);
            case IDX_SYNCH:
                return Trinity::make_unique<T>(*_connectionInfo);
            default:
                ABORT();
            }
        }();

        if (uint32 error = connection->Open())
        {
            // Failed to open a connection or invalid version, abort and cleanup
            _connections[type].clear();
            return error;
        }
        else if (mysql_get_server_version(connection->GetHandle()) < MIN_MYSQL_SERVER_VERSION)
        {
            TC_LOG_ERROR("sql.driver", "TrinityCore does not support MySQL versions below 5.1");
            return 1;
        }
        else
        {
            _connections[type].push_back(std::move(connection));
        }
    }

    // Everything is fine
    return 0;
}

template <class T>
unsigned long DatabaseWorkerPool<T>::EscapeString(char *to, const char *from, unsigned long length)
{
    if (!to || !from || !length)
        return 0;

    return mysql_real_escape_string(
        _connections[IDX_SYNCH].front()->GetHandle(), to, from, length);
}

template <class T>
void DatabaseWorkerPool<T>::Enqueue(SQLOperation* op)
{
    _queue->Push(op);
}

template <class T>
T* DatabaseWorkerPool<T>::GetFreeConnection()
{
    uint8 i = 0;
    auto const num_cons = _connections[IDX_SYNCH].size();
    T* connection = nullptr;
    //! Block forever until a connection is free
    for (;;)
    {
        connection = _connections[IDX_SYNCH][i++ % num_cons].get();
        //! Must be matched with t->Unlock() or you will get deadlocks
        if (connection->LockIfReady())
            break;
    }

    return connection;
}

template <class T>
char const* DatabaseWorkerPool<T>::GetDatabaseName() const
{
    return _connectionInfo->database.c_str();
}

template <class T>
void DatabaseWorkerPool<T>::Execute(const char* sql)
{
    if (Trinity::IsFormatEmptyOrNull(sql))
        return;

    BasicStatementTask* task = new BasicStatementTask(sql);
    Enqueue(task);
}

template <class T>
void DatabaseWorkerPool<T>::Execute(PreparedStatement<T>* stmt)
{
    PreparedStatementTask* task = new PreparedStatementTask(stmt);
    Enqueue(task);
}

template <class T>
void DatabaseWorkerPool<T>::DirectExecute(const char* sql)
{
    if (Trinity::IsFormatEmptyOrNull(sql))
        return;

    T* connection = GetFreeConnection();
    connection->Execute(sql);
    connection->Unlock();
}

template <class T>
void DatabaseWorkerPool<T>::DirectExecute(PreparedStatement<T>* stmt)
{
    T* connection = GetFreeConnection();
    connection->Execute(stmt);
    connection->Unlock();

    //! Delete proxy-class. Not needed anymore
    delete stmt;
}

template <class T>
void DatabaseWorkerPool<T>::ExecuteOrAppend(SQLTransaction& trans, const char* sql)
{
    if (!trans)
        Execute(sql);
    else
        trans->Append(sql);
}

template <class T>
void DatabaseWorkerPool<T>::ExecuteOrAppend(SQLTransaction& trans, PreparedStatement<T>* stmt)
{
    if (!trans)
        Execute(stmt);
    else
        trans->Append(stmt);
}

template class TC_DATABASE_API DatabaseWorkerPool<LoginDatabaseConnection>;
template class TC_DATABASE_API DatabaseWorkerPool<WorldDatabaseConnection>;
template class TC_DATABASE_API DatabaseWorkerPool<CharacterDatabaseConnection>;
template class TC_DATABASE_API DatabaseWorkerPool<HotfixDatabaseConnection>;
