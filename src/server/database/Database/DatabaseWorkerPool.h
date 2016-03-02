/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _DATABASEWORKERPOOL_H
#define _DATABASEWORKERPOOL_H

#include "Common.h"
#include "Callback.h"
#include "MySQLConnection.h"
#include "Transaction.h"
#include "DatabaseWorker.h"
#include "PreparedStatement.h"
#include "Log.h"
#include "QueryResult.h"
#include "QueryHolder.h"
#include "AdhocStatement.h"
#include "StringFormat.h"

#include <mysqld_error.h>
#include <memory>
#include <array>

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
class DatabaseWorkerPool
{
    private:
        enum InternalIndex
        {
            IDX_ASYNC,
            IDX_SYNCH,
            IDX_SIZE
        };

    public:
        /* Activity state */
        DatabaseWorkerPool() : _queue(new ProducerConsumerQueue<SQLOperation*>()),
            _async_threads(0), _synch_threads(0)
        {
            WPFatal(mysql_thread_safe(), "Used MySQL library isn't thread-safe.");
            WPFatal(mysql_get_client_version() >= MIN_MYSQL_CLIENT_VERSION, "TrinityCore does not support MySQL versions below 5.1");
            WPFatal(mysql_get_client_version() == MYSQL_VERSION_ID, "Used MySQL library version (%s) does not match the version used to compile TrinityCore (%s).",
                mysql_get_client_info(), MYSQL_SERVER_VERSION);
        }

        ~DatabaseWorkerPool()
        {
            _queue->Cancel();
        }

        void SetConnectionInfo(std::string const& infoString, uint8 const asyncThreads, uint8 const synchThreads)
        {
            _connectionInfo = Trinity::make_unique<MySQLConnectionInfo>(infoString);

            _async_threads = asyncThreads;
            _synch_threads = synchThreads;
        }

        uint32 Open()
        {
            WPFatal(_connectionInfo.get(), "Connection info was not set!");

            TC_LOG_INFO("sql.driver", "Opening DatabasePool '%s'. Asynchronous connections: %u, synchronous connections: %u.",
                GetDatabaseName(), _async_threads, _synch_threads);

            uint32 error = OpenConnections(IDX_ASYNC, _async_threads);

            if (error)
                return error;

            error = OpenConnections(IDX_SYNCH, _synch_threads);

            if (!error)
            {
                TC_LOG_INFO("sql.driver", "DatabasePool '%s' opened successfully. %u total connections running.",
                    GetDatabaseName(), (_connections[IDX_SYNCH].size() + _connections[IDX_ASYNC].size()));
            }

            return error;
        }

        void Close()
        {
            TC_LOG_INFO("sql.driver", "Closing down DatabasePool '%s'.", GetDatabaseName());

            //! Closes the actualy MySQL connection.
            _connections[IDX_ASYNC].clear();

            TC_LOG_INFO("sql.driver", "Asynchronous connections on DatabasePool '%s' terminated. Proceeding with synchronous connections.",
                GetDatabaseName());

            //! Shut down the synchronous connections
            //! There's no need for locking the connection, because DatabaseWorkerPool<>::Close
            //! should only be called after any other thread tasks in the core have exited,
            //! meaning there can be no concurrent access at this point.
            _connections[IDX_SYNCH].clear();

            TC_LOG_INFO("sql.driver", "All connections on DatabasePool '%s' closed.", GetDatabaseName());
        }

        //! Prepares all prepared statements
        bool PrepareStatements()
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

        inline MySQLConnectionInfo const* GetConnectionInfo() const
        {
            return _connectionInfo.get();
        }

        /**
            Delayed one-way statement methods.
        */

        //! Enqueues a one-way SQL operation in string format that will be executed asynchronously.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        void Execute(const char* sql)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return;

            BasicStatementTask* task = new BasicStatementTask(sql);
            Enqueue(task);
        }

        //! Enqueues a one-way SQL operation in string format -with variable args- that will be executed asynchronously.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        template<typename Format, typename... Args>
        void PExecute(Format&& sql, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return;

            Execute(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
        }

        //! Enqueues a one-way SQL operation in prepared statement format that will be executed asynchronously.
        //! Statement must be prepared with CONNECTION_ASYNC flag.
        void Execute(PreparedStatement* stmt)
        {
            PreparedStatementTask* task = new PreparedStatementTask(stmt);
            Enqueue(task);
        }

        /**
            Direct synchronous one-way statement methods.
        */

        //! Directly executes a one-way SQL operation in string format, that will block the calling thread until finished.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        void DirectExecute(const char* sql)
        {
            if (!sql)
                return;

            T* connection = GetFreeConnection();
            connection->Execute(sql);
            connection->Unlock();
        }

        //! Directly executes a one-way SQL operation in string format -with variable args-, that will block the calling thread until finished.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        template<typename Format, typename... Args>
        void DirectPExecute(Format&& sql, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return;

            DirectExecute(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
        }

        //! Directly executes a one-way SQL operation in prepared statement format, that will block the calling thread until finished.
        //! Statement must be prepared with the CONNECTION_SYNCH flag.
        void DirectExecute(PreparedStatement* stmt)
        {
            T* connection = GetFreeConnection();
            connection->Execute(stmt);
            connection->Unlock();

            //! Delete proxy-class. Not needed anymore
            delete stmt;
        }

        /**
            Synchronous query (with resultset) methods.
        */

        //! Directly executes an SQL query in string format that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        QueryResult Query(const char* sql, T* connection = nullptr)
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

        //! Directly executes an SQL query in string format -with variable args- that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        template<typename Format, typename... Args>
        QueryResult PQuery(Format&& sql, T* conn, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return QueryResult(nullptr);

            return Query(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str(), conn);
        }

        //! Directly executes an SQL query in string format -with variable args- that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        template<typename Format, typename... Args>
        QueryResult PQuery(Format&& sql, Args&&... args)
        {
            if (!sql)
                return QueryResult(nullptr);

            return Query(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
        }

        //! Directly executes an SQL query in prepared format that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        //! Statement must be prepared with CONNECTION_SYNCH flag.
        PreparedQueryResult Query(PreparedStatement* stmt)
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

        /**
            Asynchronous query (with resultset) methods.
        */

        //! Enqueues a query in string format that will set the value of the QueryResultFuture return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        QueryResultFuture AsyncQuery(const char* sql)
        {
            BasicStatementTask* task = new BasicStatementTask(sql, true);
            // Store future result before enqueueing - task might get already processed and deleted before returning from this method
            QueryResultFuture result = task->GetFuture();
            Enqueue(task);
            return result;
        }

        //! Enqueues a query in string format -with variable args- that will set the value of the QueryResultFuture return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        template<typename Format, typename... Args>
        QueryResultFuture AsyncPQuery(Format&& sql, Args&&... args)
        {
            return AsyncQuery(Trinity::StringFormat(std::forward<Format>(sql), std::forward<Args>(args)...).c_str());
        }

        //! Enqueues a query in prepared format that will set the value of the PreparedQueryResultFuture return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        //! Statement must be prepared with CONNECTION_ASYNC flag.
        PreparedQueryResultFuture AsyncQuery(PreparedStatement* stmt)
        {
            PreparedStatementTask* task = new PreparedStatementTask(stmt, true);
            // Store future result before enqueueing - task might get already processed and deleted before returning from this method
            PreparedQueryResultFuture result = task->GetFuture();
            Enqueue(task);
            return result;
        }

        //! Enqueues a vector of SQL operations (can be both adhoc and prepared) that will set the value of the QueryResultHolderFuture
        //! return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        //! Any prepared statements added to this holder need to be prepared with the CONNECTION_ASYNC flag.
        QueryResultHolderFuture DelayQueryHolder(SQLQueryHolder* holder)
        {
            SQLQueryHolderTask* task = new SQLQueryHolderTask(holder);
            // Store future result before enqueueing - task might get already processed and deleted before returning from this method
            QueryResultHolderFuture result = task->GetFuture();
            Enqueue(task);
            return result;
        }

        /**
            Transaction context methods.
        */

        //! Begins an automanaged transaction pointer that will automatically rollback if not commited. (Autocommit=0)
        SQLTransaction BeginTransaction()
        {
            return SQLTransaction(new Transaction);
        }

        //! Enqueues a collection of one-way SQL operations (can be both adhoc and prepared). The order in which these operations
        //! were appended to the transaction will be respected during execution.
        void CommitTransaction(SQLTransaction transaction)
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

        //! Directly executes a collection of one-way SQL operations (can be both adhoc and prepared). The order in which these operations
        //! were appended to the transaction will be respected during execution.
        void DirectCommitTransaction(SQLTransaction& transaction)
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

        //! Method used to execute prepared statements in a diverse context.
        //! Will be wrapped in a transaction if valid object is present, otherwise executed standalone.
        void ExecuteOrAppend(SQLTransaction& trans, PreparedStatement* stmt)
        {
            if (!trans)
                Execute(stmt);
            else
                trans->Append(stmt);
        }

        //! Method used to execute ad-hoc statements in a diverse context.
        //! Will be wrapped in a transaction if valid object is present, otherwise executed standalone.
        void ExecuteOrAppend(SQLTransaction& trans, const char* sql)
        {
            if (!trans)
                Execute(sql);
            else
                trans->Append(sql);
        }

        /**
            Other
        */

        typedef typename T::Statements PreparedStatementIndex;

        //! Automanaged (internally) pointer to a prepared statement object for usage in upper level code.
        //! Pointer is deleted in this->DirectExecute(PreparedStatement*), this->Query(PreparedStatement*) or PreparedStatementTask::~PreparedStatementTask.
        //! This object is not tied to the prepared statement on the MySQL context yet until execution.
        PreparedStatement* GetPreparedStatement(PreparedStatementIndex index)
        {
            return new PreparedStatement(index);
        }

        //! Apply escape string'ing for current collation. (utf8)
        void EscapeString(std::string& str)
        {
            if (str.empty())
                return;

            char* buf = new char[str.size() * 2 + 1];
            EscapeString(buf, str.c_str(), str.size());
            str = buf;
            delete[] buf;
        }

        //! Keeps all our MySQL connections alive, prevent the server from disconnecting us.
        void KeepAlive()
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
            for (auto& connection : _connections[IDX_ASYNC])
                Enqueue(new PingOperation);
        }

    private:
        uint32 OpenConnections(InternalIndex type, uint8 numConnections)
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

        unsigned long EscapeString(char *to, const char *from, unsigned long length)
        {
            if (!to || !from || !length)
                return 0;

            return mysql_real_escape_string(
                _connections[IDX_SYNCH].front()->GetHandle(), to, from, length);
        }

        void Enqueue(SQLOperation* op)
        {
            _queue->Push(op);
        }

        //! Gets a free connection in the synchronous connection pool.
        //! Caller MUST call t->Unlock() after touching the MySQL context to prevent deadlocks.
        T* GetFreeConnection()
        {
            uint8 i = 0;
            auto const num_cons = _connections[IDX_SYNCH].size();
            T* connection = nullptr;
            //! Block forever until a connection is free
            for (;;)
            {
                connection = _connections[IDX_SYNCH][++i % num_cons].get();
                //! Must be matched with t->Unlock() or you will get deadlocks
                if (connection->LockIfReady())
                    break;
            }

            return connection;
        }

        char const* GetDatabaseName() const
        {
            return _connectionInfo->database.c_str();
        }

        //! Queue shared by async worker threads.
        std::unique_ptr<ProducerConsumerQueue<SQLOperation*>> _queue;
        std::array<std::vector<std::unique_ptr<T>>, IDX_SIZE> _connections;
        std::unique_ptr<MySQLConnectionInfo> _connectionInfo;
        uint8 _async_threads, _synch_threads;
};

#endif
