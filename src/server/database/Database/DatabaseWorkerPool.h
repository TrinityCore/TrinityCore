/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AsioHacksFwd.h"
#include "Define.h"
#include "DatabaseEnvFwd.h"
#include "StringFormat.h"
#include <array>
#include <atomic>
#include <string>
#include <vector>

struct MySQLConnectionInfo;

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
        DatabaseWorkerPool();

        ~DatabaseWorkerPool();

        void SetConnectionInfo(std::string const& infoString, uint8 const asyncThreads, uint8 const synchThreads);

        uint32 Open();

        void Close();

        //! Prepares all prepared statements
        bool PrepareStatements();

        inline MySQLConnectionInfo const* GetConnectionInfo() const
        {
            return _connectionInfo.get();
        }

        /**
            Delayed one-way statement methods.
        */

        //! Enqueues a one-way SQL operation in string format that will be executed asynchronously.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        void Execute(char const* sql);

        //! Enqueues a one-way SQL operation in string format -with variable args- that will be executed asynchronously.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        template<typename... Args>
        void PExecute(Trinity::FormatString<Args...> sql, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return;

            Execute(Trinity::StringFormat(sql, std::forward<Args>(args)...).c_str());
        }

        //! Enqueues a one-way SQL operation in prepared statement format that will be executed asynchronously.
        //! Statement must be prepared with CONNECTION_ASYNC flag.
        void Execute(PreparedStatement<T>* stmt);

        /**
            Direct synchronous one-way statement methods.
        */

        //! Directly executes a one-way SQL operation in string format, that will block the calling thread until finished.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        void DirectExecute(char const* sql);

        //! Directly executes a one-way SQL operation in string format -with variable args-, that will block the calling thread until finished.
        //! This method should only be used for queries that are only executed once, e.g during startup.
        template<typename... Args>
        void DirectPExecute(Trinity::FormatString<Args...> sql, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return;

            DirectExecute(Trinity::StringFormat(sql, std::forward<Args>(args)...).c_str());
        }

        //! Directly executes a one-way SQL operation in prepared statement format, that will block the calling thread until finished.
        //! Statement must be prepared with the CONNECTION_SYNCH flag.
        void DirectExecute(PreparedStatement<T>* stmt);

        /**
            Synchronous query (with resultset) methods.
        */

        //! Directly executes an SQL query in string format that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        QueryResult Query(char const* sql, T* connection = nullptr);

        //! Directly executes an SQL query in string format -with variable args- that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        template<typename... Args>
        QueryResult PQuery(Trinity::FormatString<Args...> sql, T* conn, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return QueryResult(nullptr);

            return Query(Trinity::StringFormat(sql, std::forward<Args>(args)...).c_str(), conn);
        }

        //! Directly executes an SQL query in string format -with variable args- that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        template<typename... Args>
        QueryResult PQuery(Trinity::FormatString<Args...> sql, Args&&... args)
        {
            if (Trinity::IsFormatEmptyOrNull(sql))
                return QueryResult(nullptr);

            return Query(Trinity::StringFormat(sql, std::forward<Args>(args)...).c_str());
        }

        //! Directly executes an SQL query in prepared format that will block the calling thread until finished.
        //! Returns reference counted auto pointer, no need for manual memory management in upper level code.
        //! Statement must be prepared with CONNECTION_SYNCH flag.
        PreparedQueryResult Query(PreparedStatement<T>* stmt);

        /**
            Asynchronous query (with resultset) methods.
        */

        //! Enqueues a query in string format that will set the value of the QueryResultFuture return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        QueryCallback AsyncQuery(char const* sql);

        //! Enqueues a query in prepared format that will set the value of the PreparedQueryResultFuture return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        //! Statement must be prepared with CONNECTION_ASYNC flag.
        QueryCallback AsyncQuery(PreparedStatement<T>* stmt);

        //! Enqueues a vector of SQL operations (can be both adhoc and prepared) that will set the value of the QueryResultHolderFuture
        //! return object as soon as the query is executed.
        //! The return value is then processed in ProcessQueryCallback methods.
        //! Any prepared statements added to this holder need to be prepared with the CONNECTION_ASYNC flag.
        SQLQueryHolderCallback DelayQueryHolder(std::shared_ptr<SQLQueryHolder<T>> holder);

        /**
            Transaction context methods.
        */

        //! Begins an automanaged transaction pointer that will automatically rollback if not commited. (Autocommit=0)
        SQLTransaction<T> BeginTransaction();

        //! Enqueues a collection of one-way SQL operations (can be both adhoc and prepared). The order in which these operations
        //! were appended to the transaction will be respected during execution.
        void CommitTransaction(SQLTransaction<T> transaction);

        //! Enqueues a collection of one-way SQL operations (can be both adhoc and prepared). The order in which these operations
        //! were appended to the transaction will be respected during execution.
        TransactionCallback AsyncCommitTransaction(SQLTransaction<T> transaction);

        //! Directly executes a collection of one-way SQL operations (can be both adhoc and prepared). The order in which these operations
        //! were appended to the transaction will be respected during execution.
        void DirectCommitTransaction(SQLTransaction<T>& transaction);

        //! Method used to execute ad-hoc statements in a diverse context.
        //! Will be wrapped in a transaction if valid object is present, otherwise executed standalone.
        void ExecuteOrAppend(SQLTransaction<T>& trans, char const* sql);

        //! Method used to execute prepared statements in a diverse context.
        //! Will be wrapped in a transaction if valid object is present, otherwise executed standalone.
        void ExecuteOrAppend(SQLTransaction<T>& trans, PreparedStatement<T>* stmt);

        /**
            Other
        */

        typedef typename T::Statements PreparedStatementIndex;

        //! Automanaged (internally) pointer to a prepared statement object for usage in upper level code.
        //! Pointer is deleted in this->DirectExecute(PreparedStatement*), this->Query(PreparedStatement*) or PreparedStatementTask::~PreparedStatementTask.
        //! This object is not tied to the prepared statement on the MySQL context yet until execution.
        PreparedStatement<T>* GetPreparedStatement(PreparedStatementIndex index);

        //! Apply escape string'ing for current collation. (utf8)
        void EscapeString(std::string& str);

        //! Keeps all our MySQL connections alive, prevent the server from disconnecting us.
        void KeepAlive();

#ifdef TRINITY_DEBUG
        static void WarnAboutSyncQueries(bool warn);
#else
        static void WarnAboutSyncQueries([[maybe_unused]] bool warn) { }
#endif

        size_t QueueSize() const;

    private:
        uint32 OpenConnections(InternalIndex type, uint8 numConnections);

        unsigned long EscapeString(char* to, char const* from, unsigned long length);

        //! Gets a free connection in the synchronous connection pool.
        //! Caller MUST call t->Unlock() after touching the MySQL context to prevent deadlocks.
        T* GetFreeConnection();

        T* GetAsyncConnectionForCurrentThread() const;

        char const* GetDatabaseName() const;

        struct QueueSizeTracker;
        friend QueueSizeTracker;

        //! Queue shared by async worker threads.
        std::unique_ptr<Trinity::Asio::IoContext> _ioContext;
        std::atomic<size_t> _queueSize;
        std::array<std::vector<std::unique_ptr<T>>, IDX_SIZE> _connections;
        std::unique_ptr<MySQLConnectionInfo> _connectionInfo;
        std::vector<uint8> _preparedStatementSize;
        uint8 _async_threads, _synch_threads;
};

#endif
