/* 
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

template<class Class>
bool
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult*), const char *sql)
{
    if (!sql) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class>(object, method), itr->second));
    return true;
}

template<class Class, typename ParamType1>
bool
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1), ParamType1 param1, const char *sql)
{
    if (!sql) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class, ParamType1>(object, method, (QueryResult*)NULL, param1), itr->second));
    return true;
}

template<class Class, typename ParamType1, typename ParamType2>
bool
Database::AsyncQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql)
{
    if (!sql) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    m_threadBody->Delay(new SqlQuery(sql, new Trinity::QueryCallback<Class, ParamType1, ParamType2>(object, method, (QueryResult*)NULL, param1, param2), itr->second));
    return true;
}

template<typename ParamType1>
bool
Database::AsyncQuery(void (*method)(QueryResult*, ParamType1), ParamType1 param1, const char *sql)
{
    if (!sql) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    m_threadBody->Delay(new SqlQuery(sql, new Trinity::SQueryCallback<ParamType1>(method, (QueryResult*)NULL, param1), itr->second));
    return true;
}

template<typename ParamType1, typename ParamType2>
bool
Database::AsyncQuery(void (*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *sql)
{
    if (!sql) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    m_threadBody->Delay(new SqlQuery(sql, new Trinity::SQueryCallback<ParamType1, ParamType2>(method, (QueryResult*)NULL, param1, param2), itr->second));
    return true;
}

template<class Class>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult*), const char *format,...)
{
    if(!format) return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf( szQuery, MAX_QUERY_LEN, format, ap );
    va_end(ap);

    if(res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return AsyncQuery(object, method, szQuery);
}

template<class Class, typename ParamType1>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1), ParamType1 param1, const char *format,...)
{
    if(!format) return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf( szQuery, MAX_QUERY_LEN, format, ap );
    va_end(ap);

    if(res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return AsyncQuery(object, method, param1, szQuery);
}

template<class Class, typename ParamType1, typename ParamType2>
bool
Database::AsyncPQuery(Class *object, void (Class::*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...)
{
    if(!format) return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf( szQuery, MAX_QUERY_LEN, format, ap );
    va_end(ap);

    if(res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return AsyncQuery(object, method, param1, param2, szQuery);
}

template<typename ParamType1>
bool
Database::AsyncPQuery(void (*method)(QueryResult*, ParamType1), ParamType1 param1, const char *format,...)
{
    if(!format) return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf( szQuery, MAX_QUERY_LEN, format, ap );
    va_end(ap);

    if(res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return AsyncQuery(method, param1, szQuery);
}

template<typename ParamType1, typename ParamType2>
bool
Database::AsyncPQuery(void (*method)(QueryResult*, ParamType1, ParamType2), ParamType1 param1, ParamType2 param2, const char *format,...)
{
    if(!format) return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf( szQuery, MAX_QUERY_LEN, format, ap );
    va_end(ap);

    if(res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return AsyncQuery(method, param1, param2, szQuery);
}

template<class Class>
bool
Database::DelayQueryHolder(Class *object, void (Class::*method)(QueryResult*, SqlQueryHolder*), SqlQueryHolder *holder)
{
    if (!holder) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    holder->Execute(new Trinity::QueryCallback<Class, SqlQueryHolder*>(object, method, (QueryResult*)NULL, holder), m_threadBody, itr->second);
    return true;
}

template<class Class, typename ParamType1>
bool
Database::DelayQueryHolder(Class *object, void (Class::*method)(QueryResult*, SqlQueryHolder*, ParamType1), SqlQueryHolder *holder, ParamType1 param1)
{
    if (!holder) return false;
    ZThread::ThreadImpl * queryThread = ZThread::ThreadImpl::current();
    QueryQueues::iterator itr = m_queryQueues.find(queryThread);
    if (itr == m_queryQueues.end()) return false;
    holder->Execute(new Trinity::QueryCallback<Class, SqlQueryHolder*, ParamType1>(object, method, (QueryResult*)NULL, holder, param1), m_threadBody, itr->second);
    return true;
}
