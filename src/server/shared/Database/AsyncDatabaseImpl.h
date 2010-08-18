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


#include "DatabaseWorkerPool.h"
#include "SQLOperation.h"


/// Function body definitions for the template function members of the Database class

#define ASYNC_QUERY_BODY(sql, queue_itr) \
    if (!sql) return false; \
    \
    QueryQueues::iterator queue_itr; \
    \
    { \
        ACE_Based::Thread * queryThread = ACE_Based::Thread::current(); \
        queue_itr = m_queryQueues.find(queryThread); \
        if (queue_itr == m_queryQueues.end()) return false; \
    }

#define ASYNC_PQUERY_BODY(format, szQuery) \
    if(!format) return false; \
    \
    char szQuery [MAX_QUERY_LEN]; \
    \
    { \
        va_list ap; \
        \
        va_start(ap, format); \
        int res = vsnprintf( szQuery, MAX_QUERY_LEN, format, ap ); \
        va_end(ap); \
        \
        if(res==-1) \
        { \
            sLog.outError("SQL Query truncated (and not execute) for format: %s",format); \
            return false; \
        } \
    }


#define ASYNC_DELAYHOLDER_BODY(holder, queue_itr) \
    if (!holder) return false; \
    \
    QueryQueues::iterator queue_itr; \
    \
    { \
        ACE_Based::Thread * queryThread = ACE_Based::Thread::current(); \
        queue_itr = m_queryQueues.find(queryThread); \
        if (queue_itr == m_queryQueues.end()) return false; \
    }


// -- Query / member --


template<class Class>
bool
DatabaseWorkerPool::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr), const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::QueryCallback<Class>(object, method), itr->second);
    Enqueue(task);
    return true;
}


template<class Class, typename ParamType1>
bool
DatabaseWorkerPool::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::QueryCallback<Class, ParamType1>(object, method, (QueryResult_AutoPtr)NULL, param1), itr->second);
    Enqueue(task);
    return true;
}


template<class Class, typename ParamType1, typename ParamType2>
bool
DatabaseWorkerPool::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::QueryCallback<Class, ParamType1, ParamType2>(object, method, (QueryResult_AutoPtr)NULL, param1, param2), itr->second);
    Enqueue(task);
    return true;
}


template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
bool
DatabaseWorkerPool::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::QueryCallback<Class, ParamType1, ParamType2, ParamType3>(object, method, (QueryResult_AutoPtr)NULL, param1, param2, param3), itr->second);
    Enqueue(task);
    return true;
}


// -- Query / static --


template<typename ParamType1>
bool
DatabaseWorkerPool::AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::SQueryCallback<ParamType1>(method, (QueryResult_AutoPtr)NULL, param1), itr->second);
    Enqueue(task);
    return true;
}


template<typename ParamType1, typename ParamType2>
bool
DatabaseWorkerPool::AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::SQueryCallback<ParamType1, ParamType2>(method, (QueryResult_AutoPtr)NULL, param1, param2), itr->second);
    Enqueue(task);
    return true;
}


template<typename ParamType1, typename ParamType2, typename ParamType3>
bool
DatabaseWorkerPool::AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    SQLQueryTask* task = new SQLQueryTask(sql, new Trinity::SQueryCallback<ParamType1, ParamType2, ParamType3>(method, (QueryResult_AutoPtr)NULL, param1, param2, param3), itr->second);
    Enqueue(task);
    return true;
}


// -- PQuery / member --


template<class Class>
bool
DatabaseWorkerPool::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr), const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, szQuery);
}


template<class Class, typename ParamType1>
bool
DatabaseWorkerPool::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, param1, szQuery);
}


template<class Class, typename ParamType1, typename ParamType2>
bool
DatabaseWorkerPool::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, param1, param2, szQuery);
}


template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
bool
DatabaseWorkerPool::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, param1, param2, param3, szQuery);
}


// -- PQuery / static --


template<typename ParamType1>
bool
DatabaseWorkerPool::AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(method, param1, szQuery);
}


template<typename ParamType1, typename ParamType2>
bool
DatabaseWorkerPool::AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(method, param1, param2, szQuery);
}


template<typename ParamType1, typename ParamType2, typename ParamType3>
bool
DatabaseWorkerPool::AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(method, param1, param2, param3, szQuery);
}


// -- QueryHolder --


template<class Class>
bool
DatabaseWorkerPool::DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SQLQueryHolder*), SQLQueryHolder *holder)
{
    ASYNC_DELAYHOLDER_BODY(holder, itr)
    SQLQueryHolderTask *task = new SQLQueryHolderTask(holder, new Trinity::QueryCallback<Class, SQLQueryHolder*>(object, method, (QueryResult_AutoPtr)NULL, holder),  itr->second);
    Enqueue(task);
    return true;
}


template<class Class, typename ParamType1>
bool
DatabaseWorkerPool::DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SQLQueryHolder*, ParamType1), SQLQueryHolder *holder, ParamType1 param1)
{
    ASYNC_DELAYHOLDER_BODY(holder, itr)
    SQLQueryHolderTask *task = new SQLQueryHolderTask(holder, new Trinity::QueryCallback<Class, SQLQueryHolder*, ParamType1>(object, method, (QueryResult_AutoPtr)NULL, holder, param1),  itr->second);
    Enqueue(task);
    return true;
}


#undef ASYNC_QUERY_BODY
#undef ASYNC_PQUERY_BODY
#undef ASYNC_DELAYHOLDER_BODY
