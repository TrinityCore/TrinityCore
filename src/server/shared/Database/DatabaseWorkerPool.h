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

#ifndef _DATABASEWORKERPOOL_H
#define _DATABASEWORKERPOOL_H

#include <ace/Atomic_Op_T.h>
#include <ace/Thread_Mutex.h>

#include "Common.h"
#include "Callback.h"
#include "MySQLConnection.h"
#include "Transaction.h"
#include "DatabaseWorker.h"
#include "PreparedStatement.h"
#include "Log.h"

enum MySQLThreadBundle
{
    MYSQL_BUNDLE_NONE   = 0x00,     //- Each task will run their own MySQL connection
    MYSQL_BUNDLE_CLI    = 0x01,     //- Commandline interface thread
    MYSQL_BUNDLE_RA     = 0x02,     //- Remote admin thread
    MYSQL_BUNDLE_RAR    = 0x04,     //- Reactor runnable thread
    MYSQL_BUNDLE_WORLD  = 0x08,     //- WorldRunnable
    MYSQL_BUNDLE_ALL    = MYSQL_BUNDLE_CLI | MYSQL_BUNDLE_RA | MYSQL_BUNDLE_RAR | MYSQL_BUNDLE_WORLD,
};

template <class T>
class DatabaseWorkerPool
{
    private:
        typedef UNORDERED_MAP<ACE_Based::Thread*, MySQLConnection*> ConnectionMap;
        typedef ACE_Atomic_Op<ACE_SYNCH_MUTEX, uint32> AtomicUInt;

    public:
        DatabaseWorkerPool() :
        m_queue(new ACE_Activation_Queue(new ACE_Message_Queue<ACE_MT_SYNCH>)),
        m_connections(0)
        {
            m_infoString = "";

            mysql_library_init(-1, NULL, NULL);
            WPFatal (mysql_thread_safe(), "Used MySQL library isn't thread-safe.");
        }

        ~DatabaseWorkerPool()
        {
            mysql_library_end();
        }

        bool Open(const std::string& infoString, uint8 num_threads)
        {
            sLog.outSQLDriver("Creating bundled/master MySQL connection.");
            m_bundle_conn = new T();
            m_bundle_conn->Open(infoString);
            ++m_connections;
            
            m_async_connections.resize(num_threads);

            /// Open the Async pool
            for (uint8 i = 0; i < num_threads; i++)
            {
                m_async_connections[i] = new T(m_queue);
                m_async_connections[i]->Open(infoString);
                ++m_connections;
                sLog.outSQLDriver("Async database thread pool opened. Worker thread count: %u", num_threads);
            }

            m_infoString = infoString;
            return true;
        }

        void Close()
        {
            sLog.outSQLDriver("Closing down %u connections on this DatabaseWorkerPool", (uint32)m_connections.value());
            /// Shuts down worker threads for this connection pool.
            m_queue->queue()->deactivate();
    
            for (uint8 i = 0; i < m_async_connections.size(); i++)
            {
                m_async_connections[i]->m_worker->wait();
                --m_connections;
            }
    
            delete m_bundle_conn;
            m_bundle_conn = NULL;
            --m_connections;
            sLog.outSQLDriver("Closed bundled connection.");

            //- MySQL::Thread_End() should be called manually from the aborting calling threads
            sLog.outSQLDriver("Waiting for %u synchroneous database threads to exit.", (uint32)m_connections.value());
            while (!m_sync_connections.empty())
            {
            }
            sLog.outSQLDriver("Synchroneous database threads exited succesfuly.");
        }

        void Init_MySQL_Connection()
        {
            T* conn = new T();
            conn->Open(m_infoString);

            // no idea why it doesn't accept sLog here
            {
                ACE_Guard<ACE_Thread_Mutex> guard(m_connectionMap_mtx);
                ConnectionMap::const_iterator itr = m_sync_connections.find(ACE_Based::Thread::current());
                #ifdef _DEBUG
                if (itr != m_sync_connections.end())
                    ACE_Singleton<Log, ACE_Thread_Mutex>::instance()->outSQLDriver("Thread ["UI64FMTD"] already started a MySQL connection", (uint64)ACE_Based::Thread::currentId());
                #endif
                m_sync_connections[ACE_Based::Thread::current()] = conn;
            }

            ACE_Singleton<Log, ACE_Thread_Mutex>::instance()->outSQLDriver("Core thread with ID ["UI64FMTD"] initializing MySQL connection.",
                (uint64)ACE_Based::Thread::currentId());

            ++m_connections;
        }

        void End_MySQL_Connection()
        {
            MySQLConnection* conn;
            {
                ACE_Guard<ACE_Thread_Mutex> guard(m_connectionMap_mtx);
                ConnectionMap::iterator itr = m_sync_connections.find(ACE_Based::Thread::current());
                #ifdef _DEBUG
                if (itr == m_sync_connections.end())
                    sLog.outSQLDriver("Thread ["UI64FMTD"] already shut down their MySQL connection.", (uint64)ACE_Based::Thread::currentId());
                #endif
                conn = itr->second;
                m_sync_connections.erase(itr);
            }
            delete conn;
            conn = NULL;
            --m_connections;
        }

        void Execute(const char* sql)
        {
            if (!sql)
                return;

            BasicStatementTask* task = new BasicStatementTask(sql);
            Enqueue(task);
        }

        void PExecute(const char* sql, ...)
        {
            if (!sql)
                return;

            va_list ap;
            char szQuery[MAX_QUERY_LEN];
            va_start(ap, sql);
            vsnprintf(szQuery, MAX_QUERY_LEN, sql, ap);
            va_end(ap);

            Execute(szQuery);
        }

        void DirectExecute(const char* sql)
        {
            if (sql)
                GetConnection()->Execute(sql);
        }

        void DirectPExecute(const char* sql, ...)
        {
            if (!sql)
                return;

            va_list ap;
            char szQuery[MAX_QUERY_LEN];
            va_start(ap, sql);
            vsnprintf(szQuery, MAX_QUERY_LEN, sql, ap);
            va_end(ap);

            return DirectExecute(szQuery);
        }

        QueryResult_AutoPtr Query(const char* sql)
        {
            return GetConnection()->Query(sql);
        }

        QueryResult_AutoPtr PQuery(const char* sql, ...)
        {
            if (!sql)
                return QueryResult_AutoPtr(NULL);

            va_list ap;
            char szQuery[MAX_QUERY_LEN];
            va_start(ap, sql);
            vsnprintf(szQuery, MAX_QUERY_LEN, sql, ap);
            va_end(ap);

            return Query(szQuery);
        }

        ACE_Future<QueryResult_AutoPtr> AsyncQuery(const char* sql)
        {
            QueryResultFuture res;
            BasicStatementTask* task = new BasicStatementTask(sql, res);
            Enqueue(task);
            return res;         //! Actual return value has no use yet
        }

        ACE_Future<QueryResult_AutoPtr> AsyncPQuery(const char* sql, ...)
        {
            va_list ap;
            char szQuery[MAX_QUERY_LEN];
            va_start(ap, sql);
            vsnprintf(szQuery, MAX_QUERY_LEN, sql, ap);
            va_end(ap);

            return AsyncQuery(szQuery);
        }

        QueryResultHolderFuture DelayQueryHolder(SQLQueryHolder* holder)
        {
            QueryResultHolderFuture res;
            SQLQueryHolderTask* task = new SQLQueryHolderTask(holder, res);
            Enqueue(task);
            return res;     //! Fool compiler, has no use yet
        }
        
        SQLTransaction BeginTransaction()
        {
            return SQLTransaction(new Transaction);
        }

        void CommitTransaction(SQLTransaction transaction)
        {
            #ifdef TRINITY_DEBUG
            if (transaction->GetSize() == 0)
            {
                sLog.outSQLDriver("Transaction contains 0 queries. Not executing.");
                return;
            }
            if (transaction->GetSize() == 1)
            {
                sLog.outSQLDriver("Warning: Transaction only holds 1 query, consider removing Transaction context in code.");
            }
            #endif
            Enqueue(new TransactionTask(transaction));
        }

        PreparedStatement* GetPreparedStatement(uint32 index)
        {
            return new PreparedStatement(index);
        }

        void Execute(PreparedStatement* stmt)
        {
            PreparedStatementTask* task = new PreparedStatementTask(stmt);
            Enqueue(task);
        }

        void escape_string(std::string& str)
        {
            if (str.empty())
                return;

            char* buf = new char[str.size()*2+1];
            escape_string(buf,str.c_str(),str.size());
            str = buf;
            delete[] buf;
        }

        unsigned long escape_string(char *to, const char *from, unsigned long length)
        {
            if (!to || !from || !length)
                return 0;
            return (mysql_real_escape_string(GetConnection()->GetHandle(), to, from, length));
        }

    private:
        void Enqueue(SQLOperation* op)
        {
            m_queue->enqueue(op);
        }

        MySQLConnection* GetConnection()
        {
            MySQLConnection* conn;
            ConnectionMap::const_iterator itr;
            {
                /*! MapUpdate + unbundled threads */
                ACE_Guard<ACE_Thread_Mutex> guard(m_connectionMap_mtx);
                itr = m_sync_connections.find(ACE_Based::Thread::current());
                if (itr != m_sync_connections.end())
                    conn = itr->second;
            }
            /*! Bundled threads */
            conn = m_bundle_conn;
            ASSERT (conn);
            return conn;
        }

    private:
        ACE_Activation_Queue*           m_queue;             //! Queue shared by async worker threads.
        ACE_Thread_Mutex                m_queue_mtx;         //! For thread safe enqueues of delayed statements. 
        std::vector<T*>                 m_async_connections;
        ConnectionMap                   m_sync_connections;  //! Holds a mysql connection+thread per mapUpdate thread and unbundled runnnables.
        ACE_Thread_Mutex                m_connectionMap_mtx; //! For thread safe access to the synchroneous connection map
        T*                              m_bundle_conn;       //! Bundled connection (see Database.ThreadBundleMask config)
        AtomicUInt                      m_connections;       //! Counter of MySQL connections; 
        std::string                     m_infoString;        //! Infostring that is passed on to child connections.
};

#endif
