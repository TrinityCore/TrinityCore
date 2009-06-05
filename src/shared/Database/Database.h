/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
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

#include "Threading.h"
#include "Utilities/UnorderedMap.h"
#include "Database/SqlDelayThread.h"

class SqlTransaction;
class SqlResultQueue;
class SqlQueryHolder;

typedef UNORDERED_MAP<ACE_Based::Thread* , SqlTransaction*> TransactionQueues;
typedef UNORDERED_MAP<ACE_Based::Thread* , SqlResultQueue*> QueryQueues;

#define MAX_QUERY_LEN   32*1024

class TRINITY_DLL_SPEC Database
{
    protected:
        Database() : m_threadBody(NULL), m_delayThread(NULL) {};

        TransactionQueues m_tranQueues;                     ///< Transaction queues from diff. threads
        QueryQueues m_queryQueues;                          ///< Query queues from diff threads
        SqlDelayThread* m_threadBody;                       ///< Pointer to delay sql executer
        ACE_Based::Thread* m_delayThread;                   ///< Pointer to executer thread

    public:

        virtual ~Database();

        virtual bool Initialize(const char *infoString);
        virtual void InitDelayThread() = 0;
        virtual void HaltDelayThread() = 0;

        virtual QueryResult* Query(const char *sql) = 0;
        QueryResult* PQuery(const char *format,...) ATTR_PRINTF(2,3);
        virtual QueryNamedResult* QueryNamed(const char *sql) = 0;
        QueryNamedResult* PQueryNamed(const char *format,...) ATTR_PRINTF(2,3);

        /// Async queries and query holders, implemented in DatabaseImpl.h

        // Query / member
        template<class Class>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult*), const char *sql);
        template<class Class, typename ParamType1>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1), ParamType1 param1, const char *sql);
        template<class Class, typename ParamType1, typename ParamType2>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql);
        template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql);
        // Query / static
        template<typename ParamType1>
            bool AsyncQuery(void (*method)(QueryResult*, ParamType1), ParamType1 param1, const char *sql);
        template<typename ParamType1, typename ParamType2>
            bool AsyncQuery(void (*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql);
        template<typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncQuery(void (*method)(QueryResult*, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql);
        // PQuery / member
        template<class Class>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult*), const char *format,...) ATTR_PRINTF(4,5);
        template<class Class, typename ParamType1>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1), ParamType1 param1, const char *format,...) ATTR_PRINTF(5,6);
        template<class Class, typename ParamType1, typename ParamType2>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...) ATTR_PRINTF(6,7);
        template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncPQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...) ATTR_PRINTF(7,8);
        // PQuery / static
        template<typename ParamType1>
            bool AsyncPQuery(void (*method)(QueryResult*, ParamType1), ParamType1 param1, const char *format,...) ATTR_PRINTF(4,5);
        template<typename ParamType1, typename ParamType2>
            bool AsyncPQuery(void (*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...) ATTR_PRINTF(5,6);
        template<typename ParamType1, typename ParamType2, typename ParamType3>
            bool AsyncPQuery(void (*method)(QueryResult*, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...) ATTR_PRINTF(6,7);
        template<class Class>
        // QueryHolder
            bool DelayQueryHolder(Class *object, void (Class::*method)(QueryResult*, SqlQueryHolder*), SqlQueryHolder *holder);
        template<class Class, typename ParamType1>
            bool DelayQueryHolder(Class *object, void (Class::*method)(QueryResult*, SqlQueryHolder*, ParamType1), SqlQueryHolder *holder, ParamType1 param1);

        virtual bool Execute(const char *sql) = 0;
        bool PExecute(const char *format,...) ATTR_PRINTF(2,3);
        virtual bool DirectExecute(const char* sql) = 0;
        bool DirectPExecute(const char *format,...) ATTR_PRINTF(2,3);

        // Writes SQL commands to a LOG file (see Trinityd.conf "LogSQL")
        bool PExecuteLog(const char *format,...) ATTR_PRINTF(2,3);

        virtual bool BeginTransaction()                     // nothing do if DB not support transactions
        {
            return true;
        }
        virtual bool CommitTransaction()                    // nothing do if DB not support transactions
        {
            return true;
        }
        virtual bool RollbackTransaction()                  // can't rollback without transaction support
        {
            return false;
        }

        virtual operator bool () const = 0;

        virtual unsigned long escape_string(char *to, const char *from, unsigned long length) { strncpy(to,from,length); return length; }
        void escape_string(std::string& str);

        // must be called before first query in thread (one time for thread using one from existed Database objects)
        virtual void ThreadStart();
        // must be called before finish thread run (one time for thread using one from existed Database objects)
        virtual void ThreadEnd();

        // sets the result queue of the current thread, be careful what thread you call this from
        void SetResultQueue(SqlResultQueue * queue);

    private:
        bool m_logSQL;
        std::string m_logsDir;
};
#endif

