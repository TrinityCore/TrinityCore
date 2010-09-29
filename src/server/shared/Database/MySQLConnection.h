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

#include <ace/Activation_Queue.h>
#include "DatabaseWorkerPool.h"
#include "Util.h"

#ifndef _MYSQLCONNECTION_H
#define _MYSQLCONNECTION_H

class DatabaseWorker;
class PreparedStatement;
class MySQLPreparedStatement;
class PingOperation;

struct MySQLConnectionInfo
{
    MySQLConnectionInfo() {}
    MySQLConnectionInfo(const std::string& infoString)
    {
        Tokens tokens = StrSplit(infoString, ";");
        Tokens::iterator iter = tokens.begin();

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
    }

    std::string user;
    std::string password;
    std::string database;
    std::string host;
    std::string port_or_socket;
};

class MySQLConnection
{
    template <class T> friend class DatabaseWorkerPool;
    friend class PingOperation;

    public:
        MySQLConnection();                                  //! Constructor for synchroneous connections.
        MySQLConnection(ACE_Activation_Queue* queue);       //! Constructor for asynchroneous connections.
        ~MySQLConnection();

        virtual bool Open(const MySQLConnectionInfo& connInfo);   //! Connection details.
        void Close();

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

        operator bool () const { return m_Mysql != NULL; }
        void Ping() { mysql_ping(m_Mysql); }

    protected:
        MYSQL* GetHandle()  { return m_Mysql; }
        MySQLPreparedStatement* GetPreparedStatement(uint32 index);
        void PrepareStatement(uint32 index, const char* sql);
        std::vector<MySQLPreparedStatement*> m_stmts;       //! PreparedStatements storage

        bool LockIfReady()
        {
            /// Tries to acquire lock. If lock is acquired by another thread
            /// the calling parent will just try another connection
            return m_Mutex.tryacquire() != -1;
        }

        void Unlock()
        {
            /// Called by parent databasepool. Will let other threads access this connection
            m_Mutex.release();
        }

    private:
        ACE_Activation_Queue* m_queue;                      //! Queue shared with other asynchroneous connections.
        DatabaseWorker*       m_worker;                     //! Core worker task.
        MYSQL *               m_Mysql;                      //! MySQL Handle.
        ACE_Thread_Mutex      m_Mutex;
};

#endif
