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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "DatabaseEnv.h"
#include "Configuration/ConfigEnv.h"

#include "Common.h"
#include "Updates/UpdateFields.h"

#include "Utilities/Util.h"
#include "Define.h"
#include "Threading/Threading.h"
#include "Database/SqlDelayThread.h"
#include "Database/SqlOperations.h"
#include "Utilities/Timer.h"


#include <ctime>
#include <iostream>
#include <fstream>

size_t Database::db_count = 0;

Database::Database() : mMysql(NULL) 
{
    // before first connection
    if (db_count++ == 0)
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

Database::~Database()
{
    if (m_delayThread)
        HaltDelayThread();

    if (mMysql)
        mysql_close(mMysql);

    // Free Mysql library pointers for last ~DB
    if (--db_count == 0)
        mysql_library_end();
}

bool Database::Initialize(const char *infoString)
{
    // Enable logging of SQL commands (usally only GM commands)
    // (See method: PExecuteLog)
    m_logSQL = sConfig.GetBoolDefault("LogSQL", false);
    m_logsDir = sConfig.GetStringDefault("LogsDir","");
    if (!m_logsDir.empty())
    {
        if ((m_logsDir.at(m_logsDir.length()-1)!='/') && (m_logsDir.at(m_logsDir.length()-1)!='\\'))
            m_logsDir.append("/");
    }

    tranThread = NULL;
    MYSQL *mysqlInit;
    mysqlInit = mysql_init(NULL);
    if (!mysqlInit)
    {
        sLog.outError("Could not initialize Mysql connection");
        return false;
    }

    InitDelayThread();

    Tokens tokens = StrSplit(infoString, ";");

    Tokens::iterator iter;

    std::string host, port_or_socket, user, password, database;
    int port;
    char const* unix_socket;

    iter = tokens.begin();

    if (iter != tokens.end())
        host = *iter++;
    if (iter != tokens.end())
        port_or_socket = *iter++;
    if (iter != tokens.end())
        user = *iter++;
    if (iter != tokens.end())
        password = *iter++;
    if (iter != tokens.end())
        database = *iter++;

    mysql_options(mysqlInit, MYSQL_SET_CHARSET_NAME, "utf8");
    #ifdef _WIN32
    if (host==".")                                           // named pipe use option (Windows)
    {
        unsigned int opt = MYSQL_PROTOCOL_PIPE;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
        port = 0;
        unix_socket = 0;
    }
    else                                                    // generic case
    {
        port = atoi(port_or_socket.c_str());
        unix_socket = 0;
    }
    #else
    if (host==".")                                           // socket use option (Unix/Linux)
    {
        unsigned int opt = MYSQL_PROTOCOL_SOCKET;
        mysql_options(mysqlInit, MYSQL_OPT_PROTOCOL, (char const*)&opt);
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
        sLog.outDetail("Connected to MySQL database at %s", host.c_str());
        sLog.outString("MySQL client library: %s", mysql_get_client_info());
        sLog.outString("MySQL server ver: %s ", mysql_get_server_info( mMysql));

        if (!mysql_autocommit(mMysql, 1))
            sLog.outDetail("AUTOCOMMIT SUCCESSFULLY SET TO 1");
        else
            sLog.outDetail("AUTOCOMMIT NOT SET TO 1");

        // set connection properties to UTF8 to properly handle locales for different
        // server configs - core sends data in UTF8, so MySQL must expect UTF8 too
        PExecute("SET NAMES `utf8`");
        PExecute("SET CHARACTER SET `utf8`");

    #if MYSQL_VERSION_ID >= 50003
        my_bool my_true = (my_bool)1;
        if (mysql_options(mMysql, MYSQL_OPT_RECONNECT, &my_true))
            sLog.outDetail("Failed to turn on MYSQL_OPT_RECONNECT.");
        else
           sLog.outDetail("Successfully turned on MYSQL_OPT_RECONNECT.");
    #else
        #warning "Your mySQL client lib version does not support reconnecting after a timeout.\nIf this causes you any trouble we advice you to upgrade your mySQL client libs to at least mySQL 5.0.13 to resolve this problem."
    #endif
        return true;
    }
    else
    {
        sLog.outError("Could not connect to MySQL database at %s: %s\n", host.c_str(),mysql_error(mysqlInit));
        mysql_close(mysqlInit);
        return false;
    }
}

void Database::ThreadStart()
{
    mysql_thread_init();
}

void Database::ThreadEnd()
{
    mysql_thread_end();
}

void Database::escape_string(std::string& str)
{
    if (str.empty())
        return;

    char* buf = new char[str.size()*2+1];
    escape_string(buf,str.c_str(),str.size());
    str = buf;
    delete[] buf;
}

unsigned long Database::escape_string(char *to, const char *from, unsigned long length)
{
    if (!mMysql || !to || !from || !length)
        return 0;

    return(mysql_real_escape_string(mMysql, to, from, length));
}


bool Database::PExecuteLog(const char * format,...)
{
    if (!format)
        return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    if (m_logSQL)
    {
        time_t curr;
        tm local;
        time(&curr);                                        // get current time_t value
        local=*(localtime(&curr));                          // dereference and assign
        char fName[128];
        sprintf(fName, "%04d-%02d-%02d_logSQL.sql", local.tm_year+1900, local.tm_mon+1, local.tm_mday);

        FILE* log_file;
        std::string logsDir_fname = m_logsDir+fName;
        log_file = fopen(logsDir_fname.c_str(), "a");
        if (log_file)
        {
            fprintf(log_file, "%s;\n", szQuery);
            fclose(log_file);
        }
        else
        {
            // The file could not be opened
            sLog.outError("SQL-Logging is disabled - Log file for the SQL commands could not be openend: %s",fName);
        }
    }

    return Execute(szQuery);
}

void Database::SetResultQueue(SqlResultQueue * queue)
{
    m_queryQueues[ACE_Based::Thread::current()] = queue;
}

bool Database::_Query(const char *sql, MYSQL_RES **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount)
{
    if (!mMysql)
        return 0;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(mMutex);
        #ifdef TRINITY_DEBUG
        uint32 _s = getMSTime();
        #endif
        if (mysql_query(mMysql, sql))
        {
            sLog.outErrorDb("SQL: %s", sql);
            sLog.outErrorDb("query ERROR: %s", mysql_error(mMysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql );
            #endif
        }

        *pResult = mysql_store_result(mMysql);
        *pRowCount = mysql_affected_rows(mMysql);
        *pFieldCount = mysql_field_count(mMysql);
    }

    if (!*pResult )
        return false;

    if (!*pRowCount)
    {
        mysql_free_result(*pResult);
        return false;
    }

    *pFields = mysql_fetch_fields(*pResult);
    return true;
}

QueryResult_AutoPtr Database::Query(const char *sql)
{
    MYSQL_RES *result = NULL;
    MYSQL_FIELD *fields = NULL;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(sql, &result, &fields, &rowCount, &fieldCount))
        return QueryResult_AutoPtr(NULL);

    QueryResult *queryResult = new QueryResult(result, fields, rowCount, fieldCount);

    queryResult->NextRow();

    return QueryResult_AutoPtr(queryResult);
}

QueryResult_AutoPtr Database::PQuery(const char *format,...)
{
    if (!format)
        return QueryResult_AutoPtr(NULL);

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return QueryResult_AutoPtr(NULL);
    }

    return Query(szQuery);
}

QueryNamedResult* Database::QueryNamed(const char *sql)
{
    MYSQL_RES *result = NULL;
    MYSQL_FIELD *fields = NULL;
    uint64 rowCount = 0;
    uint32 fieldCount = 0;

    if (!_Query(sql, &result, &fields, &rowCount, &fieldCount))
        return NULL;

    QueryFieldNames names(fieldCount);
    for (uint32 i = 0; i < fieldCount; i++)
         names[i] = fields[i].name;

    QueryResult *queryResult = new QueryResult(result, fields, rowCount, fieldCount);

    queryResult->NextRow();

    return new QueryNamedResult(queryResult, names);
}

QueryNamedResult* Database::PQueryNamed(const char *format,...)
{
    if (!format)
        return NULL;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return QueryNamed(szQuery);
}

bool Database::Execute(const char *sql)
{
    if (!mMysql)
        return false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
        return DirectExecute(sql);

    nMutex.acquire();
    tranThread = ACE_Based::Thread::current();              // owner of this transaction
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
        i->second->DelayExecute(sql);                       // Statement for transaction
    else
        m_threadBody->Delay(new SqlStatement(sql));         // Simple sql statement

    nMutex.release();
    return true;
}

bool Database::PExecute(const char * format,...)
{
    if (!format)
        return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return Execute(szQuery);
}

bool Database::_UpdateDataBlobValue(const uint32 guid, const uint32 field, const int32 value)
{
    return PExecute(
        "UPDATE characters SET data="
        "CONCAT(SUBSTRING_INDEX(`data`,' ',%u),' ',"
        "GREATEST(SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',%u),' ',-1)+%i,0),"
        "' ',SUBSTRING_INDEX(`data`,' ',%i)) WHERE guid=%u",
        field, field+1, value, -int32(PLAYER_END-field), guid);
}

bool Database::_SetDataBlobValue(const uint32 guid, const uint32 field, const uint32 value)
{
    return PExecute(
        "UPDATE characters SET data="
        "CONCAT(SUBSTRING_INDEX(`data`,' ',%u),' ',"
        "%u,' ',SUBSTRING_INDEX(`data`,' ',%i)) WHERE guid=%u",
        field, value, -int32(PLAYER_END-field), guid);
}

bool Database::DirectExecute(const char* sql)
{
    if (!mMysql)
        return false;

    {
        // guarded block for thread-safe mySQL request
        ACE_Guard<ACE_Thread_Mutex> query_connection_guard(mMutex);

        #ifdef TRINITY_DEBUG
        uint32 _s = getMSTime();
        #endif
        if (mysql_query(mMysql, sql))
        {
            sLog.outErrorDb("SQL: %s", sql);
            sLog.outErrorDb("SQL ERROR: %s", mysql_error(mMysql));
            return false;
        }
        else
        {
            #ifdef TRINITY_DEBUG
            sLog.outDebug("[%u ms] SQL: %s", getMSTimeDiff(_s,getMSTime()), sql);
            #endif
        }
    }

    return true;
}

bool Database::DirectPExecute(const char * format,...)
{
    if (!format)
        return false;

    va_list ap;
    char szQuery [MAX_QUERY_LEN];
    va_start(ap, format);
    int res = vsnprintf(szQuery, MAX_QUERY_LEN, format, ap);
    va_end(ap);

    if (res==-1)
    {
        sLog.outError("SQL Query truncated (and not execute) for format: %s",format);
        return false;
    }

    return DirectExecute(szQuery);
}

bool Database::CheckRequiredField(char const* table_name, char const* required_name)
{
    // check required field
    QueryResult_AutoPtr result = PQuery("SELECT %s FROM %s LIMIT 1",required_name,table_name);
    if (result)
        return true;

    // check fail, prepare readabale error message

    // search current required_* field in DB
    QueryNamedResult* result2 = PQueryNamed("SELECT * FROM %s LIMIT 1",table_name);
    if (result2)
    {
        QueryFieldNames const& namesMap = result2->GetFieldNames();
        std::string reqName;
        for (QueryFieldNames::const_iterator itr = namesMap.begin(); itr != namesMap.end(); ++itr)
        {
            if (itr->substr(0,9)=="required_")
            {
                reqName = *itr;
                break;
            }
        }

        delete result2;

        if (!reqName.empty())
            sLog.outErrorDb("Table `%s` have field `%s` but expected `%s`! Not all sql updates applied?",table_name,reqName.c_str(),required_name);
        else
            sLog.outErrorDb("Table `%s` not have required_* field but expected `%s`! Not all sql updates applied?",table_name,required_name);
    }
    else
        sLog.outErrorDb("Table `%s` fields list query fail but expected have `%s`! No records in `%s`?",table_name,required_name,table_name);

    return false;
}

bool Database::_TransactionCmd(const char *sql)
{
    if (mysql_query(mMysql, sql))
    {
        sLog.outError("SQL: %s", sql);
        sLog.outError("SQL ERROR: %s", mysql_error(mMysql));
        return false;
    }
    else
        DEBUG_LOG("SQL: %s", sql);

    return true;
}

bool Database::BeginTransaction()
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

    nMutex.acquire();
    tranThread = ACE_Based::Thread::current();              // owner of this transaction
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
        // If for thread exists queue and also contains transaction
        // delete that transaction (not allow trans in trans)
        delete i->second;

    m_tranQueues[tranThread] = new SqlTransaction();
    nMutex.release();
    return true;
}

bool Database::CommitTransaction()
{
    if (!mMysql)
        return false;

    bool _res = false;

    // don't use queued execution if it has not been initialized
    if (!m_threadBody)
    {
        if (tranThread != ACE_Based::Thread::current())
            return false;

        _res = _TransactionCmd("COMMIT");
        tranThread = NULL;
        mMutex.release();
        return _res;
    }

    nMutex.acquire();
    tranThread = ACE_Based::Thread::current();
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
    {
        m_threadBody->Delay(i->second);
        m_tranQueues.erase(i);
        _res = true;
    }
    nMutex.release();
    return _res;
}

bool Database::RollbackTransaction()
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

    nMutex.acquire();
    tranThread = ACE_Based::Thread::current();
    TransactionQueues::iterator i = m_tranQueues.find(tranThread);
    if (i != m_tranQueues.end() && i->second != NULL)
    {
        delete i->second;
        i->second = NULL;
        m_tranQueues.erase(i);
    }
    nMutex.release();
    return true;
}

void Database::InitDelayThread()
{
    assert(!m_delayThread);

    //New delay thread for delay execute
    m_threadBody = new SqlDelayThread(this);              // will deleted at m_delayThread delete
    m_delayThread = new ACE_Based::Thread(m_threadBody);
}

void Database::HaltDelayThread()
{
    if (!m_threadBody || !m_delayThread)
        return;

    m_threadBody->Stop();                                   //Stop event
    m_delayThread->wait();                                  //Wait for flush to DB
    delete m_delayThread;                                   //This also deletes m_threadBody
    m_delayThread = NULL;
    m_threadBody = NULL;
}

