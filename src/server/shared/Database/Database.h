/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
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

#ifndef DATABASE_H
#define DATABASE_H

#include "Threading/Threading.h"
#include "Dynamic/UnorderedMap.h"
#include "Database/SqlDelayThread.h"
#include "Policies/Singleton.h"
#include "ace/Thread_Mutex.h"
#include "ace/Guard_T.h"

#ifdef _WIN32
#define FD_SETSIZE 1024
#include <winsock2.h>
#include <mysql/mysql.h>
#else
#include <mysql.h>
#endif

class SqlTransaction;
class SqlResultQueue;
class SqlQueryHolder;

typedef UNORDERED_MAP<ACE_Based::Thread* , SqlTransaction*> TransactionQueues;
typedef UNORDERED_MAP<ACE_Based::Thread* , SqlResultQueue*> QueryQueues;

#define MAX_QUERY_LEN   32*1024

class Database
{
    protected:
        TransactionQueues m_tranQueues;                     ///< Transaction queues from diff. threads
        QueryQueues m_queryQueues;                          ///< Query queues from diff threads
        SqlDelayThread* m_threadBody;                       ///< Pointer to delay sql executer (owned by m_delayThread)
        ACE_Based::Thread* m_delayThread;                   ///< Pointer to executer thread

    public:

        Database();
        ~Database();

        /*! infoString should be formated like hostname;username;password;database. */
        bool Initialize(const char *infoString);

        void InitDelayThread();
        void HaltDelayThread();

        QueryResult_AutoPtr Query(const char *sql);
        QueryResult_AutoPtr PQuery(const char *format,...) ATTR_PRINTF(2,3);
        QueryNamedResult* QueryNamed(const char *sql);
        QueryNamedResult* PQueryNamed(const char *format,...) ATTR_PRINTF(2,3);

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
            bool DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SqlQueryHolder*), SqlQueryHolder *holder);
        template<class Class, typename ParamType1>
            bool DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SqlQueryHolder*, ParamType1), SqlQueryHolder *holder, ParamType1 param1);

        bool Execute(const char *sql);
        bool PExecute(const char *format,...) ATTR_PRINTF(2,3);
        bool DirectExecute(const char* sql);
        bool DirectPExecute(const char *format,...) ATTR_PRINTF(2,3);

        bool _UpdateDataBlobValue(const uint32 guid, const uint32 field, const int32 value);
        bool _SetDataBlobValue(const uint32 guid, const uint32 field, const uint32 value);

        // Writes SQL commands to a LOG file (see worldserver.conf "LogSQL")
        bool PExecuteLog(const char *format,...) ATTR_PRINTF(2,3);

        bool BeginTransaction();
        bool CommitTransaction();
        bool RollbackTransaction();

        operator bool () const { return mMysql != NULL; }
        unsigned long escape_string(char *to, const char *from, unsigned long length);
        void escape_string(std::string& str);

        void ThreadStart();
        void ThreadEnd();

        // sets the result queue of the current thread, be careful what thread you call this from
        void SetResultQueue(SqlResultQueue * queue);

        bool CheckRequiredField(char const* table_name, char const* required_name);

    private:
        bool m_logSQL;
        std::string m_logsDir;
        ACE_Thread_Mutex mMutex;        // For thread safe operations between core and mySQL server
        ACE_Thread_Mutex nMutex;        // For thread safe operations on m_transQueues

        ACE_Based::Thread * tranThread;

        MYSQL *mMysql;

        static size_t db_count;

        bool _TransactionCmd(const char *sql);
        bool _Query(const char *sql, MYSQL_RES **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount);
};
#endif

