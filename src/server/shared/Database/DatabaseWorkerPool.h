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

#include "Common.h"
#include "Logging/Log.h"

#include <ace/Activation_Queue.h>
#include <ace/Atomic_Op_T.h>
#include <ace/Thread_Mutex.h>

#include "SQLOperation.h"
#include "QueryResult.h"
#include "MySQLConnection.h"

enum MySQLThreadBundle
{
    MYSQL_BUNDLE_NONE   = 0x00,     //- Each task will run their own MySQL connection
    MYSQL_BUNDLE_CLI    = 0x01,     //- Commandline interface thread
    MYSQL_BUNDLE_RA     = 0x02,     //- Remote admin thread
    MYSQL_BUNDLE_RAR    = 0x04,     //- Reactor runnable thread
    MYSQL_BUNDLE_WORLD  = 0x08,     //- WorldRunnable
    MYSQL_BUNDLE_ALL    = MYSQL_BUNDLE_CLI | MYSQL_BUNDLE_RA | MYSQL_BUNDLE_RAR | MYSQL_BUNDLE_WORLD,
};

class DatabaseWorkerPool
{
    public:
        DatabaseWorkerPool();
        ~DatabaseWorkerPool();

        bool Open(const std::string& infoString, uint8 num_threads);
        void Close();

        void Init_MySQL_Connection();
        void End_MySQL_Connection();

        void Execute(const char* sql);
        void PExecute(const char* sql, ...);
        void DirectExecute(const char* sql);
        void DirectPExecute(const char* sql, ...);
        QueryResult_AutoPtr Query(const char* sql);
        QueryResult_AutoPtr PQuery(const char* sql, ...);
       
        /// Async queries and query holders, implemented in DatabaseImpl.h

        // Query / member
        template<class Class>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr), const char *sql);
        template<class Class, typename ParamType1>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *sql);
        template<class Class, typename ParamType1, typename ParamType2>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql);
        template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql);
        // Query / static
        template<typename ParamType1>
            bool AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *sql);
        template<typename ParamType1, typename ParamType2>
            bool AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql);
        template<typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql);
        // PQuery / member
        template<class Class>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr), const char *format,...) ATTR_PRINTF(4,5);
        template<class Class, typename ParamType1>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *format,...) ATTR_PRINTF(5,6);
        template<class Class, typename ParamType1, typename ParamType2>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...) ATTR_PRINTF(6,7);
        template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...) ATTR_PRINTF(7,8);
        // PQuery / static
        template<typename ParamType1>
            bool AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *format,...) ATTR_PRINTF(4,5);
        template<typename ParamType1, typename ParamType2>
            bool AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...) ATTR_PRINTF(5,6);
        template<typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...) ATTR_PRINTF(6,7);
        template<class Class>
        // QueryHolder
            bool DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SQLQueryHolder*), SQLQueryHolder *holder);
        template<class Class, typename ParamType1>
            bool DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SQLQueryHolder*, ParamType1), SQLQueryHolder *holder, ParamType1 param1);

        void SetResultQueue(SQLResultQueue * queue)
        {
            m_queryQueues[ACE_Based::Thread::current()] = queue;
        }

        void BeginTransaction();
        void RollbackTransaction();
        void CommitTransaction();

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

        MySQLConnection* GetConnection();

    private:
        typedef UNORDERED_MAP<ACE_Based::Thread*, MySQLConnection*> ConnectionMap;
        typedef UNORDERED_MAP<ACE_Based::Thread*, TransactionTask*> TransactionQueues;
        typedef UNORDERED_MAP<ACE_Based::Thread*, SQLResultQueue*> QueryQueues;
        typedef ACE_Atomic_Op<ACE_SYNCH_MUTEX, uint32> AtomicUInt;

    private:
        ACE_Activation_Queue*           m_queue;             //! Queue shared by async worker threads.
        ACE_Thread_Mutex                m_queue_mtx;         //! For thread safe enqueues of delayed statements. 
        std::vector<MySQLConnection*>   m_async_connections;
        ConnectionMap                   m_sync_connections;  //! Holds a mysql connection+thread per mapUpdate thread and unbundled runnnables.
        ACE_Thread_Mutex                m_connectionMap_mtx; //! For thread safe access to the synchroneous connection map
        MySQLConnection*                m_bundle_conn;       //! Bundled connection (see Database.ThreadBundleMask config)
        AtomicUInt                      m_connections;       //! Counter of MySQL connections; 
        std::string                     m_infoString;        //! Infostring that is passed on to child connections.
        TransactionQueues               m_tranQueues;        //! Transaction queues from diff. threads
        ACE_Thread_Mutex                m_transQueues_mtx;   //! To guard m_transQueues
        QueryQueues                     m_queryQueues;       //! Query queues from diff threads
};

#endif