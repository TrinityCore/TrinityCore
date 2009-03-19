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

#include "Common.h"
#include "Log.h"
#include "Policies/SingletonImp.h"
#include "Database/DatabaseEnv.h"
#include "Config/ConfigEnv.h"
#include "Util.h"

#include <stdarg.h>
#include <stdio.h>

INSTANTIATE_SINGLETON_1( Log );

enum LogType
{
    LogNormal = 0,
    LogDetails,
    LogDebug,
    LogError
};

const int LogType_count = int(LogError) +1;

Log::Log() :
    raLogfile(NULL), logfile(NULL), gmLogfile(NULL), charLogfile(NULL),
    dberLogfile(NULL), m_gmlog_per_account(false)
{
    Initialize();
}

Log::~Log()
{
    if( logfile != NULL )
        fclose(logfile);
    logfile = NULL;

    if( gmLogfile != NULL )
        fclose(gmLogfile);
    gmLogfile = NULL;

    if (charLogfile != NULL)
        fclose(charLogfile);
    charLogfile = NULL;

    if( dberLogfile != NULL )
        fclose(dberLogfile);
    dberLogfile = NULL;

    if (raLogfile != NULL)
        fclose(raLogfile);
    raLogfile = NULL;
}

void Log::SetLogLevel(char *Level)
{
    int32 NewLevel =atoi((char*)Level);
    if ( NewLevel <0 )
        NewLevel = 0;
    m_logLevel = NewLevel;

    outString( "LogLevel is %u",m_logLevel );
}

void Log::SetLogFileLevel(char *Level)
{
    int32 NewLevel =atoi((char*)Level);
    if ( NewLevel <0 )
        NewLevel = 0;
    m_logFileLevel = NewLevel;

    outString( "LogFileLevel is %u",m_logFileLevel );
}

void Log::SetDBLogLevel(char *Level)
{
    int32 NewLevel = atoi((char*)Level);
    if ( NewLevel < 0 )
		NewLevel = 0;
	m_dbLogLevel = NewLevel;

	outString( "DBLogLevel is %u",m_dbLogLevel );
}

void Log::Initialize()
{
    /// Check whether we'll log GM commands/RA events/character outputs
    m_dbChar = sConfig.GetBoolDefault("DBLog.Char", false);
    m_dbRA = sConfig.GetBoolDefault("DBLog.RA", false);
    m_dbGM = sConfig.GetBoolDefault("DBLog.GM", false);

    /// Common log files data
    m_logsDir = sConfig.GetStringDefault("LogsDir","");
    if(!m_logsDir.empty())
    {
        if((m_logsDir.at(m_logsDir.length()-1)!='/') && (m_logsDir.at(m_logsDir.length()-1)!='\\'))
            m_logsDir.append("/");
    }

    m_logsTimestamp = "_" + GetTimestampStr();

    /// Open specific log files
    logfile = openLogFile("LogFile","LogTimestamp","w");

    m_gmlog_per_account = sConfig.GetBoolDefault("GmLogPerAccount",false);
    if(!m_gmlog_per_account)
        gmLogfile = openLogFile("GMLogFile","GmLogTimestamp","a");
    else
    {
        // GM log settings for per account case
        m_gmlog_filename_format = sConfig.GetStringDefault("GMLogFile", "");
        if(!m_gmlog_filename_format.empty())
        {
            bool m_gmlog_timestamp = sConfig.GetBoolDefault("GmLogTimestamp",false);

            size_t dot_pos = m_gmlog_filename_format.find_last_of(".");
            if(dot_pos!=m_gmlog_filename_format.npos)
            {
                if(m_gmlog_timestamp)
                    m_gmlog_filename_format.insert(dot_pos,m_logsTimestamp);

                m_gmlog_filename_format.insert(dot_pos,"_#%u");
            }
            else
            {
                m_gmlog_filename_format += "_#%u";

                if(m_gmlog_timestamp)
                    m_gmlog_filename_format += m_logsTimestamp;
            }

            m_gmlog_filename_format = m_logsDir + m_gmlog_filename_format;
        }
    }

    charLogfile = openLogFile("CharLogFile","CharLogTimestamp","a");

    dberLogfile = openLogFile("DBErrorLogFile",NULL,"a");
    raLogfile = openLogFile("RaLogFile",NULL,"a");

    // Main log file settings
    m_logLevel     = sConfig.GetIntDefault("LogLevel", LOGL_NORMAL);
    m_logFileLevel = sConfig.GetIntDefault("LogFileLevel", LOGL_NORMAL);
    m_dbLogLevel   = sConfig.GetIntDefault("DBLogLevel", LOGL_NORMAL);

    m_logFilter = 0;

    if(sConfig.GetBoolDefault("LogFilter_TransportMoves", true))
        m_logFilter |= LOG_FILTER_TRANSPORT_MOVES;
    if(sConfig.GetBoolDefault("LogFilter_CreatureMoves", true))
        m_logFilter |= LOG_FILTER_CREATURE_MOVES;
    if(sConfig.GetBoolDefault("LogFilter_VisibilityChanges", true))
        m_logFilter |= LOG_FILTER_VISIBILITY_CHANGES;
    if(sConfig.GetBoolDefault("LogFilter_AchievementUpdates", true))
        m_logFilter |= LOG_FILTER_ACHIEVEMENT_UPDATES;

    // Char log settings
    m_charLog_Dump = sConfig.GetBoolDefault("CharLogDump", false);
}

FILE* Log::openLogFile(char const* configFileName,char const* configTimeStampFlag, char const* mode)
{
    std::string logfn=sConfig.GetStringDefault(configFileName, "");
    if(logfn.empty())
        return NULL;

    if(configTimeStampFlag && sConfig.GetBoolDefault(configTimeStampFlag,false))
    {
        size_t dot_pos = logfn.find_last_of(".");
        if(dot_pos!=logfn.npos)
            logfn.insert(dot_pos,m_logsTimestamp);
        else
            logfn += m_logsTimestamp;
    }

    return fopen((m_logsDir+logfn).c_str(), mode);
}

FILE* Log::openGmlogPerAccount(uint32 account)
{
    if(m_gmlog_filename_format.empty())
        return NULL;

    char namebuf[TRINITY_PATH_MAX];
    snprintf(namebuf,TRINITY_PATH_MAX,m_gmlog_filename_format.c_str(),account);
    return fopen(namebuf, "a");
}

std::string Log::GetTimestampStr()
{
    time_t t = time(NULL);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    char buf[20];
    snprintf(buf,20,"%04d-%02d-%02d_%02d-%02d-%02d",aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday,aTm->tm_hour,aTm->tm_min,aTm->tm_sec);
    return std::string(buf);
}

void Log::outDB( uint8 type, const char * str, ... )
{
    if(!str)
        return;

    std::string new_str(str);
    LoginDatabase.escape_string(new_str);
    char nnew_str[MAX_QUERY_LEN];

    va_list ap;
    va_start(ap, str);
    int res = vsnprintf(nnew_str, MAX_QUERY_LEN, new_str.c_str(), ap);
    va_end(ap);

    if ( (res < 0) || (!nnew_str) || (std::string(nnew_str).empty()) )
        return;

    LoginDatabase.PExecute("INSERT INTO logs (time, realm, type, string) "
        "VALUES (%u, %u, %u, '%s');", time(0), realm, type, nnew_str);
}

void Log::outString( const char * str, ... )
{
    if( !str )
        return;

    if (m_enableLogDB)
    {
        // we don't want empty strings in the DB
        std::string s(str);
        if(s.empty() || s == " ")
            return;

        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_STRING, nnew_str);
        va_end(ap2);
    }

    UTF8PRINTF(stdout,str,);

    printf( "\n" );
    if(logfile)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        fprintf(logfile, "\n" );
        va_end(ap);

        fflush(logfile);
    }
    fflush(stdout);
}

void Log::outError( const char * err, ... )
{
    if( !err )
        return;

    if (m_enableLogDB)
    {
        va_list ap2;
        va_start(ap2, err);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, err, ap2);
        outDB(LOG_TYPE_ERROR, nnew_str);
        va_end(ap2);
    }

    UTF8PRINTF(stderr,err,);

    fprintf( stderr, "\n" );
    if(logfile)
    {
        fprintf(logfile, "ERROR:" );

        va_list ap;
        va_start(ap, err);
        vfprintf(logfile, err, ap);
        va_end(ap);

        fprintf(logfile, "\n" );
        fflush(logfile);
    }
    fflush(stderr);
}

void Log::outErrorDb( const char * err, ... )
{
    if( !err )
        return;

    if (m_enableLogDB)
    {
        va_list ap2;
        va_start(ap2, err);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, err, ap2);
        outDB(LOG_TYPE_DBERR, nnew_str);
        va_end(ap2);
    }

    UTF8PRINTF(stderr,err,);

    fprintf( stderr, "\n" );

    if(logfile)
    {
        fprintf(logfile, "ERROR:" );

        va_list ap;
        va_start(ap, err);
        vfprintf(logfile, err, ap);
        va_end(ap);

        fprintf(logfile, "\n" );
        fflush(logfile);
    }

    if(dberLogfile)
    {
        va_list ap;
        va_start(ap, err);
        vfprintf(dberLogfile, err, ap);
        va_end(ap);

        fprintf(dberLogfile, "\n" );
        fflush(dberLogfile);
    }
    fflush(stderr);
}

void Log::outBasic( const char * str, ... )
{
    if( !str )
        return;

    if (m_enableLogDB && m_dbLogLevel > LOGL_NORMAL)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_BASIC, nnew_str);
        va_end(ap2);
    }

    if( m_logLevel > LOGL_NORMAL )
    {
        UTF8PRINTF(stdout,str,);

        printf( "\n" );
    }

    if(logfile && m_logFileLevel > LOGL_NORMAL)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        fprintf(logfile, "\n" );
        va_end(ap);
        fflush(logfile);
    }
    fflush(stdout);
}

void Log::outDetail( const char * str, ... )
{
    if( !str )
        return;

    if (m_enableLogDB && m_dbLogLevel >= LOGL_BASIC)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_DETAIL, nnew_str);
        va_end(ap2);
    }

    if( m_logLevel > LOGL_BASIC )
    {
        UTF8PRINTF(stdout,str,);

        printf( "\n" );
    }
    if(logfile && m_logFileLevel > LOGL_BASIC)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        fprintf(logfile, "\n" );
        va_end(ap);
        fflush(logfile);
    }

    fflush(stdout);
}

void Log::outDebugInLine( const char * str, ... )
{
    if( !str )
        return;
    if( m_logLevel > LOGL_DETAIL )
    {
        UTF8PRINTF(stdout,str,);
    }
    if(logfile && m_logFileLevel > LOGL_DETAIL)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        va_end(ap);
    }
}

void Log::outDebug( const char * str, ... )
{
    if( !str )
        return;

    if (m_enableLogDB && m_dbLogLevel >= LOGL_DETAIL)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_DEBUG, nnew_str);
        va_end(ap2);
    }

    if( m_logLevel > LOGL_DETAIL )
    {
        UTF8PRINTF(stdout,str,);

        printf( "\n" );
    }
    if(logfile && m_logFileLevel > LOGL_DETAIL)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        va_end(ap);

        fprintf(logfile, "\n" );
        fflush(logfile);
    }
    fflush(stdout);
}

void Log::outCommand( uint32 account, const char * str, ... )
{
    if( !str )
        return;

    // TODO: support accountid
    if (m_enableLogDB && m_dbGM)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_GM, nnew_str);
        va_end(ap2);
    }

    if( m_logLevel > LOGL_NORMAL )
    {
        UTF8PRINTF(stdout,str,);

        printf( "\n" );
    }
    if(logfile && m_logFileLevel > LOGL_NORMAL)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        fprintf(logfile, "\n" );
        va_end(ap);
        fflush(logfile);
    }

    if (m_gmlog_per_account)
    {
        if (FILE* per_file = openGmlogPerAccount (account))
        {
            va_list ap;
            va_start(ap, str);
            vfprintf(per_file, str, ap);
            fprintf(per_file, "\n" );
            va_end(ap);
            fclose(per_file);
        }
    }
    else if (gmLogfile)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(gmLogfile, str, ap);
        fprintf(gmLogfile, "\n" );
        va_end(ap);
        fflush(gmLogfile);
    }

    fflush(stdout);
}

void Log::outChar(const char * str, ... )
{
    if (!str)
        return;

    if (m_enableLogDB && m_dbChar)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_CHAR, nnew_str);
        va_end(ap2);
    }

    if(charLogfile)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(charLogfile, str, ap);
        fprintf(charLogfile, "\n" );
        va_end(ap);
        fflush(charLogfile);
    }
}

void Log::outCharDump( const char * str, uint32 account_id, uint32 guid, const char * name )
{
    if(charLogfile)
    {
        fprintf(charLogfile, "== START DUMP == (account: %u guid: %u name: %s )\n%s\n== END DUMP ==\n",account_id,guid,name,str );
        fflush(charLogfile);
    }
}

void Log::outRemote(    const char * str, ... )
{
    if( !str )
        return;

    if (m_enableLogDB && m_dbRA)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_RA, nnew_str);
        va_end(ap2);
    }

    if (raLogfile)
    {
        va_list ap;
        va_start(ap, str);
        vfprintf(raLogfile, str, ap);
        fprintf(raLogfile, "\n" );
        va_end(ap);
        fflush(raLogfile);
    }
    fflush(stdout);
}

void outstring_log(const char * str, ...)
{
    if( !str )
        return;

    char buf[256];
    va_list ap;
    va_start(ap, str);
    vsnprintf(buf,256, str, ap);
    va_end(ap);

    Trinity::Singleton<Log>::Instance().outString(buf);
}

void detail_log(const char * str, ...)
{
    if( !str )
        return;

    char buf[256];
    va_list ap;
    va_start(ap, str);
    vsnprintf(buf,256, str, ap);
    va_end(ap);

    Trinity::Singleton<Log>::Instance().outDetail(buf);
}

void debug_log(const char * str, ...)
{
    if( !str )
        return;

    char buf[256];
    va_list ap;
    va_start(ap, str);
    vsnprintf(buf,256, str, ap);
    va_end(ap);

    Trinity::Singleton<Log>::Instance().outDebug(buf);
}

void error_log(const char * str, ...)
{
    if( !str )
        return;

    char buf[256];
    va_list ap;
    va_start(ap, str);
    vsnprintf(buf,256, str, ap);
    va_end(ap);

    Trinity::Singleton<Log>::Instance().outError(buf);
}

void error_db_log(const char * str, ...)
{
    if( !str )
        return;

    char buf[256];
    va_list ap;
    va_start(ap, str);
    vsnprintf(buf,256, str, ap);
    va_end(ap);

    Trinity::Singleton<Log>::Instance().outErrorDb(buf);
}

