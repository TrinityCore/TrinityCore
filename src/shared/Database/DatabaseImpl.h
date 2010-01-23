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

#include "Database/Database.h"
#include "Database/SqlOperations.h"

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
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr), const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class>(object, method), itr->second));
}

template<class Class, typename ParamType1>
bool
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class, ParamType1>(object, method, (QueryResult_AutoPtr)NULL, param1), itr->second));
}

template<class Class, typename ParamType1, typename ParamType2>
bool
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class, ParamType1, ParamType2>(object, method, (QueryResult_AutoPtr)NULL, param1, param2), itr->second));
}

template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
bool
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class, ParamType1, ParamType2, ParamType3>(object, method, (QueryResult_AutoPtr)NULL, param1, param2, param3), itr->second));
}

// -- Query / static --

template<typename ParamType1>
bool
Database::AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::SQueryCallback<ParamType1>(method, (QueryResult_AutoPtr)NULL, param1), itr->second));
}

template<typename ParamType1, typename ParamType2>
bool
Database::AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::SQueryCallback<ParamType1, ParamType2>(method, (QueryResult_AutoPtr)NULL, param1, param2), itr->second));
}

template<typename ParamType1, typename ParamType2, typename ParamType3>
bool
Database::AsyncQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *sql)
{
    ASYNC_QUERY_BODY(sql, itr)
    return m_threadBody->Delay(new SqlQuery(sql, new Trinity::SQueryCallback<ParamType1, ParamType2, ParamType3>(method, (QueryResult_AutoPtr)NULL, param1, param2, param3), itr->second));
}

// -- PQuery / member --

template<class Class>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr), const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, szQuery);
}

template<class Class, typename ParamType1>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, param1, szQuery);
}

template<class Class, typename ParamType1, typename ParamType2>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, param1, param2, szQuery);
}

template<class Class, typename ParamType1, typename ParamType2, typename ParamType3>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(object, method, param1, param2, param3, szQuery);
}

// -- PQuery / static --

template<typename ParamType1>
bool
Database::AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1), ParamType1 param1, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(method, param1, szQuery);
}

template<typename ParamType1, typename ParamType2>
bool
Database::AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(method, param1, param2, szQuery);
}

template<typename ParamType1, typename ParamType2, typename ParamType3>
bool
Database::AsyncPQuery(void (*method)(QueryResult_AutoPtr, ParamType1, ParamType2, ParamType3), ParamType1 param1, ParamType2 param2, ParamType3 param3, const char *format,...)
{
    ASYNC_PQUERY_BODY(format, szQuery)
    return AsyncQuery(method, param1, param2, param3, szQuery);
}

// -- QueryHolder --

template<class Class>
bool
Database::DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SqlQueryHolder*), SqlQueryHolder *holder)
{
    ASYNC_DELAYHOLDER_BODY(holder, itr)
    return holder->Execute(new Trinity::QueryCallback<Class, SqlQueryHolder*>(object, method, (QueryResult_AutoPtr)NULL, holder), m_threadBody, itr->second);
}

template<class Class, typename ParamType1>
bool
Database::DelayQueryHolder(Class *object, void (Class::*method)(QueryResult_AutoPtr, SqlQueryHolder*, ParamType1), SqlQueryHolder *holder, ParamType1 param1)
{
    ASYNC_DELAYHOLDER_BODY(holder, itr)
    return holder->Execute(new Trinity::QueryCallback<Class, SqlQueryHolder*, ParamType1>(object, method, (QueryResult_AutoPtr)NULL, holder, param1), m_threadBody, itr->second);
}

#undef ASYNC_QUERY_BODY
#undef ASYNC_PQUERY_BODY
#undef ASYNC_DELAYHOLDER_BODY

