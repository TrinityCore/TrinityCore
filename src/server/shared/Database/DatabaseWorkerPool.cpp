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

#include "DatabaseEnv.h"
#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"
#include "SQLOperation.h"

DatabaseWorkerPool::DatabaseWorkerPool() :
m_queue(new ACE_Activation_Queue(new ACE_Message_Queue<ACE_MT_SYNCH>)),
m_connections(0)
{
    m_infoString = "";

    mysql_library_init(-1, NULL, NULL);
    WPFatal (mysql_thread_safe(), "Used MySQL library isn't thread-safe.");
}

DatabaseWorkerPool::~DatabaseWorkerPool()
{
}

bool DatabaseWorkerPool::Open(const std::string& infoString, uint8 num_threads)
{
    sLog.outDebug("Creating bundled/master MySQL connection.");
    m_bundle_conn = new MySQLConnection();
    m_bundle_conn->Open(infoString);
    ++m_connections;
            
    m_async_connections.resize(num_threads);

    /// Open the Async pool
    for (uint8 i = 0; i < num_threads; i++)
    {
        m_async_connections[i] = new MySQLConnection(m_queue);
        m_async_connections[i]->Open(infoString);
        ++m_connections;
        sLog.outDebug("Async database thread pool opened. Worker thread count: %u", num_threads);
    }

    m_infoString = infoString;
    return true;
}

void DatabaseWorkerPool::Close()
{
    sLog.outStaticDebug("Closing down %u connections on this DatabaseWorkerPool", (uint32)m_connections.value());
    /// Shuts down worker threads for this connection pool.
    ACE_Thread_Mutex shutdown_Mtx;
    ACE_Condition_Thread_Mutex m_condition(shutdown_Mtx);
    for (uint8 i = 0; i < m_async_connections.size(); i++)
    {
        Enqueue(new DatabaseWorkerPoolEnd(m_condition));
        m_condition.wait();
        --m_connections;
    }
    
    m_queue->queue()->deactivate();

    delete m_bundle_conn;
    m_bundle_conn = NULL;
    --m_connections;
    sLog.outStaticDebug("Closed bundled connection.");

    //- MySQL::Thread_End() should be called manually from the aborting calling threads
    sLog.outStaticDebug("Waiting for %u synchroneous database threads to exit.", (uint32)m_connections.value());
    while (!m_sync_connections.empty())
    {
    }
    sLog.outStaticDebug("Synchroneous database threads exited succesfuly.");

    mysql_library_end();
}

/*! This function creates a new MySQL connection for every MapUpdate thread
    and every unbundled task.
 */
void DatabaseWorkerPool::Init_MySQL_Connection()
{
    MySQLConnection* conn = new MySQLConnection();
    conn->Open(m_infoString);

    {
        ACE_Guard<ACE_Thread_Mutex> guard(m_connectionMap_mtx);
        m_sync_connections[ACE_Based::Thread::current()] = conn;
    }

    sLog.outDebug("Core thread with ID ["UI64FMTD"] initializing MySQL connection.",
        (uint64)ACE_Based::Thread::currentId());

    ++m_connections;
}

void DatabaseWorkerPool::End_MySQL_Connection()
{
    MySQLConnection* conn;
    {
        ACE_Guard<ACE_Thread_Mutex> guard(m_connectionMap_mtx);
        ConnectionMap::iterator itr = m_sync_connections.find(ACE_Based::Thread::current());
        conn = itr->second;
        m_sync_connections.erase(itr);
    }
    delete conn;
    conn = NULL;
    --m_connections;
}

void DatabaseWorkerPool::Execute(const char* sql)
{
    if (!sql)
        return;

    BasicStatementTask* task = new BasicStatementTask(sql);
    Enqueue(task);
}

void DatabaseWorkerPool::PExecute(const char* sql, ...)
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

void DatabaseWorkerPool::DirectExecute(const char* sql)
{
    if (sql)
        GetConnection()->Execute(sql);
}

void DatabaseWorkerPool::DirectPExecute(const char* sql, ...)
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

QueryResult_AutoPtr DatabaseWorkerPool::Query(const char* sql)
{
    return GetConnection()->Query(sql);
}

QueryResult_AutoPtr DatabaseWorkerPool::PQuery(const char* sql, ...)
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

SQLTransaction DatabaseWorkerPool::BeginTransaction()
{
    return SQLTransaction(new Transaction);
}

void DatabaseWorkerPool::CommitTransaction(SQLTransaction transaction)
{
    #ifdef _DEBUG
    if (transaction->GetSize() == 0)
    {
        sLog.outError("Transaction contains 0 queries");
        return;
    }
    if (transaction->GetSize() == 1)
    {
        sLog.outDetail("Warning: Transaction only holds 1 query, consider removing Transaction context in code.");
    }
    #endif
    Enqueue(new TransactionTask(transaction));
}

ACE_Future<QueryResult_AutoPtr> DatabaseWorkerPool::AsyncQuery(const char* sql)
{
    QueryResultFuture res;
    BasicStatementTask* task = new BasicStatementTask(sql, res);
    Enqueue(task);
    return res;         //! Fool compiler, has no use yet
}

ACE_Future<QueryResult_AutoPtr> DatabaseWorkerPool::AsyncPQuery(const char* sql, ...)
{
    va_list ap;
    char szQuery[MAX_QUERY_LEN];
    va_start(ap, sql);
    vsnprintf(szQuery, MAX_QUERY_LEN, sql, ap);
    va_end(ap);

    return AsyncQuery(szQuery);
}

QueryResultHolderFuture DatabaseWorkerPool::DelayQueryHolder(SQLQueryHolder* holder)
{
    QueryResultHolderFuture res;
    SQLQueryHolderTask* task = new SQLQueryHolderTask(holder, res);
    Enqueue(task);
    return res;     //! Fool compiler, has no use yet
}

MySQLConnection* DatabaseWorkerPool::GetConnection()
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
