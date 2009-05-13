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

#ifndef DO_POSTGRESQL

#include "Util.h"
#include "Policies/SingletonImp.h"
#include "Platform/Define.h"
#include "Threading.h"
#include "DatabaseEnv.h"
#include "Database/MySQLDelayThread.h"
#include "Database/SqlOperations.h"
#include "Timer.h"

void DatabaseMysql::ThreadStart()
{
    mysql_thread_init();
}

void DatabaseMysql::ThreadEnd()
{
    mysql_thread_end();
}

size_t DatabaseMysql::db_count = 0;

DatabaseMysql::DatabaseMysql() : Database(), mMysql(0)
{
    // before first connection
    if( db_count++ == 0 )
    {
        // Mysql Library Init
        mysql_library_init(-1, NULL, NULL);

        if (!mysql_thread_safe())
        {
            sLog.outError("FATAL ERROR: Used MySQL library isn't thread-safe.");
            exit(1);
        }
    }
}

DatabaseMysql::~DatabaseMysql()
{
    if (m_delayThread)
        HaltDelayThread();

    if (mMysql)
        mysql_close(mMysql);

    //Free Mysql library pointers for last ~DB
    if(--db_count == 0)
        mysql_library_end();
}

bool DatabaseMysql::Initialize(const char *infoString)
{

    if(!Database::Initialize(infoString))
        return false;

    tranThread = NULL;
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);
    if (!mysqlInit)
    {
        sLog.outError( "Could not initialize Mysql connection" );
        return false;
    }

    InitDelayThread();

    Tokens tokens = StrSplit(infoString, ";");

    Tokens::iterator iter;

    std::string host, port_or_socket, user, password, database;
    int port;
    char const* unix_socket;

    iter = tokens.begin();

    if(iter != tokens.end())
        host = *iter++;
    if(iter != tokens.end())
        port_or_socket = *iter++;
    if(iter != tokens.end())
        user = *iter++;
    if(iter != tokens.end())
        password = *iter++;
    if(iter != tokens.end())
        database = *iter++;

    mysql_options(mysqlInit,MYSQL_SET_CHARSET_NAME,"utf8");
    #ifdef WIN32
    if(host==".")                                           // named pipe use option (Windows)
    {
        unsigned int opt = MYSQL_PROTOCOL_PIPE;
        mysql_options(mysqlInit,MYSQL_OPT_PROTOCOL,(char const*)&opt);
        port = 0;
        unix_socket = 0;
    }
    else                                                    // generic case
    {
        port = atoi(port_or_socket.c_str());
        unix_socket = 0;
    }
    #else
    if(host==".")                                           // socket use option (Unix/Linux)
    {
        unsigned int opt = MYSQL_PROTOCOL_SOCKET;
        mysql_options(mysqlInit,MYSQL_OPT_PROTOCOL,(char const*)&opt);
        host = "localhost";
        port = 0;
        unix_socket = port_or_socket.c_str();
    }
    else                                                    // generic case
    {
        port = atoi(port_or_socket.c_str());
        unix_socket = 0;
    }
    #endif

    mMysql = mysql_real_connect(mysqlInit, host.c_str(), user.c_str(),
        password.c_str(), database.c_str(), port, unix_socket, 0);

    if (mMysql)
    {
        sLog.outDetail( "Connected to MySQL database at %s",
            host.c_str());
        sLog.outString( "MySQL client library: %s", mysql_get_client_info());
        sLog.outString( "MySQL server ver: %s ", mysql_get_server_info( mMysql));

        /*----------SET AUTOCOMMIT ON---------*/
        // It seems mysql 5.0.x have enabled this feature
        // by default. In crash case you can lose data!!!
        // So better to turn this off
        // ---
        // This is wrong since Trinity use transactions,
        // autocommit is turned of during it.
        // Setting it to on makes atomic updates work
        if (!mysql_autocommit(mMysql, 1))
            sLog.outDetail("AUTOCOMMIT SUCCESSFULLY SET TO 1");
        else
            sLog.outDetail("AUTOCOMMIT NOT SET TO 1");
        /*-------------------------------------*/

        // set connection properties to UTF8 to properly handle locales for different
        // server configs - core sends data in UTF8, so MySQL must expect UTF8 too
        PExecute("SET NAMES `utf8`");
        PExecute("SET CHARACTER SET `utf8`");

    #if MYSQL_VERSION_ID >= 50003
        my_bool my_true = (my_bool)1;
        if (mysql_options(mMysql, MYSQL_OPT_RECONNECT, &my_true))
        {
            sLog.outDetail("Failed to turn on MYSQL_OPT_RECONNECT.");
        }
        else
        {
           sLog.outDetail("Successfully turned on MYSQL_OPT_RECONNECT.");
        }
    #else
        #warning "Your mySQL client lib version does not support reconnecting after a timeout.\nIf this causes you any trouble we advice you to upgrade your mySQL client libs to at least mySQL 5.0.13 to resolve this problem."
    #endif

        return true;
    }
    else
    {
        sLog.outError( "Could not connect to MySQL database at %s: %s\n",
            host.c_str(),mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return false;
    }
}

QueryResult* DatabaseMysql::Query(const char *sql)
{
    if (!mMysql)
        return 0;

    MYSQL_RES *result = 0;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(mMutex);
        #ifdef MANGOS_DEBUG
        uint32 _s = getMSTime();
        #endif
        if(mysql_query(mMysql, sql))
        {
            sLog.outErrorDb( "SQL: %s", sql );
            sLog.outErrorDb("query ERROR: %s", mysql_error(mMysql));
            return NULL;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql );
            #endif
        }

        result = mysql_store_result(mMysql);

        rowCount = mysql_affected_rows(mMysql);
        fieldCount = mysql_field_count(mMysql);
        // end guarded block
    }

    if (!result )
        return NULL;

    if (!rowCount)
    {
        mysql_free_result(result);
        return NULL;
    }

    QueryResultMysql *queryResult = new QueryResultMysql(result, rowCount, fieldCount);

    queryResult->NextRow();

    return queryResult;
}

bool DatabaseMysql::Execute(const char *sql)
{
    if (!mMysql)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody) return DirectExecute(sql);

    tranThread = ACE_Based::Thread::current();              // owner of this transaction
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

bool DatabaseMysql::DirectExecute(const char* sql)
{
    if (!mMysql)
        return false;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(mMutex);

        #ifdef MANGOS_DEBUG
        uint32 _s = getMSTime();
        #endif
        if(mysql_query(mMysql, sql))
        {
            sLog.outErrorDb("SQL: %s", sql);
            sLog.outErrorDb("SQL ERROR: %s", mysql_error(mMysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql );
            #endif
        }
        // end guarded block
    }

    return true;
}

bool DatabaseMysql::_TransactionCmd(const char *sql)
{
    if (mysql_query(mMysql, sql))
    {
        sLog.outError("SQL: %s", sql);
        sLog.outError("SQL ERROR: %s", mysql_error(mMysql));
        return false;
    }
    else
    {
        DEBUG_LOG("SQL: %s", sql);
    }
    return true;
}

bool DatabaseMysql::BeginTransaction()
{
    if (!mMysql)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
        if (tranThread == ACE_Based::Thread::current())
            return false;                                   // huh? this thread already started transaction

        mMutex.acquire();
        if (!_TransactionCmd("START TRANSACTION"))
        {
            mMutex.release();                               // can't start transaction
            return false;
        }
        return true;                                        // transaction started
    }

    tranThread = ACE_Based::Thread::current();              // owner of this transaction
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
        // If for thread exists queue and also contains transaction
        // delete that transaction (not allow trans in trans)
        delete i->second;

    m_tranQueues[tranThread] = new SqlTransaction();

    return true;
}

bool DatabaseMysql::CommitTransaction()
{
    if (!mMysql)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
		if (tranThread != ACE_Based::Thread::current())
            return false;
        bool _res = _TransactionCmd("COMMIT");
        tranThread = NULL;
        mMutex.release();
        return _res;
    }

    tranThread = ACE_Based::Thread::current();
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

bool DatabaseMysql::RollbackTransaction()
{
    if (!mMysql)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
        if (tranThread != ACE_Based::Thread::current())
            return false;
        bool _res = _TransactionCmd("ROLLBACK");
        tranThread = NULL;
        mMutex.release();
        return _res;
    }

    tranThread = ACE_Based::Thread::current();
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
    {
        delete i->second;
        i->second = NULL;
    }
    return true;
}

unsigned long DatabaseMysql::escape_string(char *to, const char *from, unsigned long length)
{
    if (!mMysql || !to || !from || !length)
        return 0;

    return(mysql_real_escape_string(mMysql, to, from, length));
}

void DatabaseMysql::InitDelayThread()
{
    assert(!m_delayThread);

    //New delay thread for delay execute
    m_threadBody = new MySQLDelayThread(this);
    m_delayThread = new ACE_Based::Thread(*m_threadBody);
}

void DatabaseMysql::HaltDelayThread()
{
    if (!m_threadBody || !m_delayThread) return;

    m_threadBody->Stop();                                   //Stop event
    m_delayThread->wait();                                  //Wait for flush to DB
    delete m_delayThread;                                   //This also deletes m_threadBody
    m_delayThread = NULL;
    m_threadBody = NULL;
}
#endif

