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

#ifndef _SQLOPERATION_H
#define _SQLOPERATION_H

#include <ace/Method_Request.h>
#include <ace/Activation_Queue.h>

#include "Common.h"
#include "Callback.h"

class MySQLConnection;

class SQLOperation : public ACE_Method_Request
{
    public:
        SQLOperation(){};
        int call()
        {
            Execute();
            return 0;
        }
        virtual bool Execute() = 0;

        virtual void SetConnection(MySQLConnection* con) { m_conn = con; }

        MySQLConnection* m_conn;
};

/*! Raw, ad-hoc query. */
class BasicStatementTask :  public SQLOperation
{
    public:
        BasicStatementTask(const char* sql);
        ~BasicStatementTask();

        bool Execute();

    private:
        const char* m_sql;      //- Raw query to be executed
};

/*! Transactions */
class TransactionTask : public SQLOperation
{
    public:
        TransactionTask();
        ~TransactionTask();
        void ForcefulDelete();

        bool Execute();

    private:
        std::queue<char*> m_queries;
};

/*! ResultQueue */
class SQLResultQueue : public ACE_Based::LockedQueue<Trinity::IQueryCallback* , ACE_Thread_Mutex>
{
    public:
        SQLResultQueue() {}
        void Update();
};

class SQLQueryHolder
{
    friend class SQLQueryHolderTask;
    private:
        typedef std::pair<const char*, QueryResult_AutoPtr> SQLResultPair;
        std::vector<SQLResultPair> m_queries;
    public:
        SQLQueryHolder() {}
        ~SQLQueryHolder();
        bool SetQuery(size_t index, const char *sql);
        bool SetPQuery(size_t index, const char *format, ...) ATTR_PRINTF(3,4);
        void SetSize(size_t size);
        QueryResult_AutoPtr GetResult(size_t index);
        void SetResult(size_t index, QueryResult_AutoPtr result);
};

class SQLQueryHolderTask : public SQLOperation
{
    private:
        SQLQueryHolder * m_holder;
        Trinity::IQueryCallback * m_callback;
        SQLResultQueue * m_queue;
    public:
        SQLQueryHolderTask(SQLQueryHolder *holder, Trinity::IQueryCallback * callback, SQLResultQueue * queue)
            : m_holder(holder), m_callback(callback), m_queue(queue) {}
        bool Execute();
};

class SQLQueryTask : public SQLOperation
{
    private:
        const char *m_sql;
        Trinity::IQueryCallback * m_callback;
        SQLResultQueue * m_queue;
    public:
        SQLQueryTask(const char *sql, Trinity::IQueryCallback * callback, SQLResultQueue * queue)
            : m_sql(strdup(sql)), m_callback(callback), m_queue(queue) {}
        ~SQLQueryTask() { void* tofree = const_cast<char*>(m_sql); free(tofree); }
        bool Execute();
};


#endif
