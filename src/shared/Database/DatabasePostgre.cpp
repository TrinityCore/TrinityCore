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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifdef DO_POSTGRESQL

#include "Util.h"
#include "Policies/SingletonImp.h"
#include "Platform/Define.h"
#include "../src/zthread/ThreadImpl.h"
#include "DatabaseEnv.h"
#include "Database/PGSQLDelayThread.h"
#include "Database/SqlOperations.h"
#include "Timer.h"

void DatabasePostgre::ThreadStart()
{
}

void DatabasePostgre::ThreadEnd()
{
}

size_t DatabasePostgre::db_count = 0;

DatabasePostgre::DatabasePostgre() : Database(), mPGconn(NULL)
{
    // before first connection
    if( db_count++ == 0 )
    {

        if (!PQisthreadsafe())
        {
            sLog.outError("FATAL ERROR: PostgreSQL libpq isn't thread-safe.");
            exit(1);
        }
    }
}

DatabasePostgre::~DatabasePostgre()
{

    if (m_delayThread)
        HaltDelayThread();

    if( mPGconn )
    {
        PQfinish(mPGconn);
        mPGconn = NULL;
    }
}

bool DatabasePostgre::Initialize(const char *infoString)
{
    if(!Database::Initialize(infoString))
        return false;

    tranThread = NULL;

    InitDelayThread();

    Tokens tokens = StrSplit(infoString, ";");

    Tokens::iterator iter;

    std::string host, port_or_socket_dir, user, password, database;

    iter = tokens.begin();

    if(iter != tokens.end())
        host = *iter++;
    if(iter != tokens.end())
        port_or_socket_dir = *iter++;
    if(iter != tokens.end())
        user = *iter++;
    if(iter != tokens.end())
        password = *iter++;
    if(iter != tokens.end())
        database = *iter++;

    if (host == ".")
        mPGconn = PQsetdbLogin(NULL, port_or_socket_dir == "." ? NULL : port_or_socket_dir.c_str(), NULL, NULL, database.c_str(), user.c_str(), password.c_str());
    else
        mPGconn = PQsetdbLogin(host.c_str(), port_or_socket_dir.c_str(), NULL, NULL, database.c_str(), user.c_str(), password.c_str());

    /* check to see that the backend connection was successfully made */
    if (PQstatus(mPGconn) != CONNECTION_OK)
    {
        sLog.outError( "Could not connect to Postgre database at %s: %s",
            host.c_str(), PQerrorMessage(mPGconn));
        PQfinish(mPGconn);
        return false;
    }
    else
    {
        sLog.outDetail( "Connected to Postgre database at %s",
            host.c_str());
        sLog.outString( "PostgreSQL server ver: %d",PQserverVersion(mPGconn));
        return true;
    }

}

QueryResult* DatabasePostgre::Query(const char *sql)
{
    if (!mPGconn)
        return 0;

    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    // guarded block for thread-safe request
    ZThread::Guard<ZThread::FastMutex> query_connection_guard(mMutex);
    #ifdef TRINITY_DEBUG
    uint32 _s = getMSTime();
    #endif
    // Send the query
    PGresult * result = PQexec(mPGconn, sql);
    if (!result )
    {
        return NULL;
    }

    if (PQresultStatus(result) != PGRES_TUPLES_OK)
    {
        sLog.outErrorDb( "SQL : %s", sql );
        sLog.outErrorDb( "SQL %s", PQerrorMessage(mPGconn));
        PQclear(result);
        return NULL;
    }
    else
    {
        #ifdef TRINITY_DEBUG
        sLog.outDebug("[%u ms] SQL: %s", getMSTime() - _s, sql );
        #endif
    }

    rowCount = PQntuples(result);
    fieldCount = PQnfields(result);
    // end guarded block

    if (!rowCount)
    {
        PQclear(result);
        return NULL;
    }

    QueryResultPostgre * queryResult = new QueryResultPostgre(result, rowCount, fieldCount);
    queryResult->NextRow();

    return queryResult;
}

bool DatabasePostgre::Execute(const char *sql)
{

    if (!mPGconn)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody) return DirectExecute(sql);

    tranThread = ZThread::ThreadImpl::current();            // owner of this transaction
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
    {                                                       // Statement for transaction
        i->second->DelayExecute(sql);
    }
    else
    {
        // Simple sql statement
        m_threadBody->Delay(new SqlStatement(sql));
    }

    return true;
}

bool DatabasePostgre::DirectExecute(const char* sql)
{
    if (!mPGconn)
        return false;
    {
        // guarded block for thread-safe  request
        ZThread::Guard<ZThread::FastMutex> query_connection_guard(mMutex);
        #ifdef TRINITY_DEBUG
        uint32 _s = getMSTime();
        #endif
        PGresult *res = PQexec(mPGconn, sql);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
        {
            sLog.outErrorDb( "SQL: %s", sql );
            sLog.outErrorDb( "SQL %s", PQerrorMessage(mPGconn) );
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTime() - _s, sql );
            #endif
        }
        PQclear(res);

        // end guarded block
    }
    return true;
}

bool DatabasePostgre::_TransactionCmd(const char *sql)
{
    if (!mPGconn)
        return false;

    PGresult *res = PQexec(mPGconn, sql);
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        sLog.outError("SQL: %s", sql);
        sLog.outError("SQL ERROR: %s", PQerrorMessage(mPGconn));
        return false;
    }
    else
    {
        DEBUG_LOG("SQL: %s", sql);
    }
    return true;
}

bool DatabasePostgre::BeginTransaction()
{
    if (!mPGconn)
        return false;
    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
        if (tranThread==ZThread::ThreadImpl::current())
            return false;                                   // huh? this thread already started transaction
        mMutex.acquire();
        if (!_TransactionCmd("START TRANSACTION"))
        {
            mMutex.release();                               // can't start transaction
            return false;
        }
        return true;
    }
    // transaction started
    tranThread = ZThread::ThreadImpl::current();            // owner of this transaction
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
        // If for thread exists queue and also contains transaction
        // delete that transaction (not allow trans in trans)
        delete i->second;

    m_tranQueues[tranThread] = new SqlTransaction();

    return true;
}

bool DatabasePostgre::CommitTransaction()
{
    if (!mPGconn)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
        if (tranThread!=ZThread::ThreadImpl::current())
            return false;
        bool _res = _TransactionCmd("COMMIT");
        tranThread = NULL;
        mMutex.release();
        return _res;
    }
    tranThread = ZThread::ThreadImpl::current();
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
    {
        m_threadBody->Delay(i->second);
        i->second = NULL;
        return true;
    }
    else
        return false;
}

bool DatabasePostgre::RollbackTransaction()
{
    if (!mPGconn)
        return false;
    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
        if (tranThread!=ZThread::ThreadImpl::current())
            return false;
        bool _res = _TransactionCmd("ROLLBACK");
        tranThread = NULL;
        mMutex.release();
        return _res;
    }
    tranThread = ZThread::ThreadImpl::current();
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
    {
        delete i->second;
        i->second = NULL;
    }
    return true;
}

unsigned long DatabasePostgre::escape_string(char *to, const char *from, unsigned long length)
{
    if (!mPGconn || !to || !from || !length)
        return 0;

    return PQescapeString(to, from, length);
}

void DatabasePostgre::InitDelayThread()
{
    assert(!m_delayThread);

    //New delay thread for delay execute
    m_delayThread = new ZThread::Thread(m_threadBody = new PGSQLDelayThread(this));
}

void DatabasePostgre::HaltDelayThread()
{
    if (!m_threadBody || !m_delayThread) return;

    m_threadBody->Stop();                                   //Stop event
    m_delayThread->wait();                                  //Wait for flush to DB
    delete m_delayThread;                                   //This also deletes m_threadBody
    m_delayThread = NULL;
    m_threadBody = NULL;
}
#endif

