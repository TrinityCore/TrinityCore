/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "Transaction.h"
#include "Util.h"
#include "ProducerConsumerQueue.h"

#ifndef _MYSQLCONNECTION_H
#define _MYSQLCONNECTION_H

class DatabaseWorker;
class PreparedStatement;
class MySQLPreparedStatement;
class PingOperation;

enum ConnectionFlags
{
    CONNECTION_ASYNC = 0x1,
    CONNECTION_SYNCH = 0x2,
    CONNECTION_BOTH = CONNECTION_ASYNC | CONNECTION_SYNCH
};

struct TC_DATABASE_API MySQLConnectionInfo
{
    explicit MySQLConnectionInfo(std::string const& infoString)
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

    std::string user;
    std::string password;
    std::string database;
    std::string host;
    std::string port_or_socket;
};

class TC_DATABASE_API MySQLConnection
{
    template <class T> friend class DatabaseWorkerPool;
    friend class PingOperation;

    public:
        MySQLConnection(MySQLConnectionInfo& connInfo);                               //! Constructor for synchronous connections.
        MySQLConnection(ProducerConsumerQueue<SQLOperation*>* queue, MySQLConnectionInfo& connInfo);  //! Constructor for asynchronous connections.
        virtual ~MySQLConnection();

        virtual uint32 Open();
        void Close();

        bool PrepareStatements();

    public:
        bool Execute(const char* sql);
        bool Execute(PreparedStatement* stmt);
        ResultSet* Query(const char* sql);
        PreparedResultSet* Query(PreparedStatement* stmt);
        bool _Query(const char *sql, MYSQL_RES **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount);
        bool _Query(PreparedStatement* stmt, MYSQL_RES **pResult, uint64* pRowCount, uint32* pFieldCount);

        void BeginTransaction();
        void RollbackTransaction();
        void CommitTransaction();
        int ExecuteTransaction(SQLTransaction& transaction);

        operator bool () const { return m_Mysql != NULL; }
        void Ping() { mysql_ping(m_Mysql); }

        uint32 GetLastError() { return mysql_errno(m_Mysql); }

    protected:
        bool LockIfReady()
        {
            /// Tries to acquire lock. If lock is acquired by another thread
            /// the calling parent will just try another connection
            return m_Mutex.try_lock();
        }

        void Unlock()
        {
            /// Called by parent databasepool. Will let other threads access this connection
            m_Mutex.unlock();
        }

        MYSQL* GetHandle()  { return m_Mysql; }
        MySQLPreparedStatement* GetPreparedStatement(uint32 index);
        void PrepareStatement(uint32 index, std::string const& sql, ConnectionFlags flags);

        virtual void DoPrepareStatements() = 0;

    protected:
        typedef std::vector<std::unique_ptr<MySQLPreparedStatement>> PreparedStatementContainer;

        PreparedStatementContainer           m_stmts;         //! PreparedStatements storage
        bool                                 m_reconnecting;  //! Are we reconnecting?
        bool                                 m_prepareError;  //! Was there any error while preparing statements?

    private:
        bool _HandleMySQLErrno(uint32 errNo, uint8 attempts = 5);

    private:
        ProducerConsumerQueue<SQLOperation*>* m_queue;      //! Queue shared with other asynchronous connections.
        std::unique_ptr<DatabaseWorker> m_worker;           //! Core worker task.
        MYSQL*                m_Mysql;                      //! MySQL Handle.
        MySQLConnectionInfo&  m_connectionInfo;             //! Connection info (used for logging)
        ConnectionFlags       m_connectionFlags;            //! Connection flags (for preparing relevant statements)
        std::mutex            m_Mutex;

        MySQLConnection(MySQLConnection const& right) = delete;
        MySQLConnection& operator=(MySQLConnection const& right) = delete;
};

#endif
