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
#include "Config/ConfigEnv.h"

#include "Common.h"
#include "../../game/UpdateFields.h"

#include <ctime>
#include <iostream>
#include <fstream>

Database::~Database()
{
    /*Delete objects*/
}

bool Database::Initialize(const char *)
{
    // Enable logging of SQL commands (usally only GM commands)
    // (See method: PExecuteLog)
    m_logSQL = sConfig.GetBoolDefault("LogSQL", false);
    m_logsDir = sConfig.GetStringDefault("LogsDir","");
    if(!m_logsDir.empty())
    {
        if((m_logsDir.at(m_logsDir.length()-1)!='/') && (m_logsDir.at(m_logsDir.length()-1)!='\\'))
            m_logsDir.append("/");
    }

    return true;
}

void Database::ThreadStart()
{
}

void Database::ThreadEnd()
{
}

void Database::escape_string(std::string& str)
{
    if(str.empty())
        return;

    char* buf = new char[str.size()*2+1];
    escape_string(buf,str.c_str(),str.size());
    str = buf;
    delete[] buf;
}

bool Database::PExecuteLog(const char * format,...)
{
    if (!format)
        return false;

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

    if( m_logSQL )
    {
        time_t curr;
        tm local;
        time(&curr);                                        // get current time_t value
        local=*(localtime(&curr));                          // dereference and assign
        char fName[128];
        sprintf( fName, "%04d-%02d-%02d_logSQL.sql", local.tm_year+1900, local.tm_mon+1, local.tm_mday );

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

QueryResult* Database::PQuery(const char *format,...)
{
    if(!format) return NULL;

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

    return Query(szQuery);
}

QueryNamedResult* Database::PQueryNamed(const char *format,...)
{
    if(!format) return NULL;

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

    return QueryNamed(szQuery);
}

bool Database::PExecute(const char * format,...)
{
    if (!format)
        return false;

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

bool Database::DirectPExecute(const char * format,...)
{
    if (!format)
        return false;

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

    return DirectExecute(szQuery);
}

bool Database::CheckRequiredField( char const* table_name, char const* required_name )
{
    // check required field
    QueryResult* result = PQuery("SELECT %s FROM %s LIMIT 1",required_name,table_name);
    if(result)
    {
        delete result;
        return true;
    }

    // check fail, prepare readabale error message

    // search current required_* field in DB
    QueryNamedResult* result2 = PQueryNamed("SELECT * FROM %s LIMIT 1",table_name);
    if(result2)
    {
        QueryFieldNames const& namesMap = result2->GetFieldNames();
        std::string reqName;
        for (QueryFieldNames::const_iterator itr = namesMap.begin(); itr != namesMap.end(); ++itr)
        {
            if(itr->substr(0,9)=="required_")
            {
                reqName = *itr;
                break;
            }
        }

        delete result2;

        if(!reqName.empty())
            sLog.outErrorDb("Table `%s` have field `%s` but expected `%s`! Not all sql updates applied?",table_name,reqName.c_str(),required_name);
        else
            sLog.outErrorDb("Table `%s` not have required_* field but expected `%s`! Not all sql updates applied?",table_name,required_name);
    }
    else
        sLog.outErrorDb("Table `%s` fields list query fail but expected have `%s`! No records in `%s`?",table_name,required_name,table_name);

    return false;
}
