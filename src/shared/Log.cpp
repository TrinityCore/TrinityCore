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
#include "Config/ConfigEnv.h"
#include "Util.h"

#include <stdarg.h>
#include <stdio.h>

INSTANTIATE_SINGLETON_1( Log );

Log::Log() :
    raLogfile(NULL), logfile(NULL), gmLogfile(NULL), charLogfile(NULL),
    dberLogfile(NULL), chatLogfile(NULL), m_gmlog_per_account(false), m_colored(false)
    , arenaLogFile(NULL)
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

    if (chatLogfile != NULL)
        fclose(chatLogfile);
    chatLogfile = NULL;

    if (arenaLogFile != NULL)
        fclose(arenaLogFile);
    arenaLogFile = NULL;
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
    /// Check whether we'll log GM commands/RA events/character outputs/chat stuffs
    m_dbChar = sConfig.GetBoolDefault("LogDB.Char", false);
    m_dbRA = sConfig.GetBoolDefault("LogDB.RA", false);
    m_dbGM = sConfig.GetBoolDefault("LogDB.GM", false);
    m_dbChat = sConfig.GetBoolDefault("LogDB.Chat", false);

    /// Realm must be 0 by default
    SetRealmID(0);

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
    InitColors(sConfig.GetStringDefault("LogColors", ""));

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
    chatLogfile = openLogFile("ChatLogFile","ChatLogTimestamp","a");
    arenaLogFile = openLogFile("ArenaLogFile",NULL,"a");

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

void Log::outTimestamp(FILE* file)
{
    time_t t = time(NULL);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    fprintf(file,"%-4d-%02d-%02d %02d:%02d:%02d ",aTm->tm_year+1900,aTm->tm_mon+1,aTm->tm_mday,aTm->tm_hour,aTm->tm_min,aTm->tm_sec);
}

void Log::InitColors(const std::string& str)
{
    if(str.empty())
    {
        m_colored = false;
        return;
    }

    int color[4];

    std::istringstream ss(str);

    for(uint8 i = 0; i < LogLevels; ++i)
    {
        ss >> color[i];

        if(!ss)
            return;

        if(color[i] < 0 || color[i] >= Colors)
            return;
    }

    for(uint8 i = 0; i < LogLevels; ++i)
        m_colors[i] = ColorTypes(color[i]);

    m_colored = true;
}

void Log::SetColor(bool stdout_stream, ColorTypes color)
{
    #if PLATFORM == PLATFORM_WINDOWS
    static WORD WinColorFG[Colors] =
    {
        0,                                                  // BLACK
        FOREGROUND_RED,                                     // RED
        FOREGROUND_GREEN,                                   // GREEN
        FOREGROUND_RED | FOREGROUND_GREEN,                  // BROWN
        FOREGROUND_BLUE,                                    // BLUE
        FOREGROUND_RED |                    FOREGROUND_BLUE,// MAGENTA
        FOREGROUND_GREEN | FOREGROUND_BLUE,                 // CYAN
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,// WHITE
                                                            // YELLOW
        FOREGROUND_RED | FOREGROUND_GREEN |                   FOREGROUND_INTENSITY,
                                                            // RED_BOLD
        FOREGROUND_RED |                                      FOREGROUND_INTENSITY,
                                                            // GREEN_BOLD
        FOREGROUND_GREEN |                   FOREGROUND_INTENSITY,
        FOREGROUND_BLUE | FOREGROUND_INTENSITY,             // BLUE_BOLD
                                                            // MAGENTA_BOLD
        FOREGROUND_RED |                    FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                                                            // CYAN_BOLD
        FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
                                                            // WHITE_BOLD
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY
    };

    HANDLE hConsole = GetStdHandle(stdout_stream ? STD_OUTPUT_HANDLE : STD_ERROR_HANDLE );
    SetConsoleTextAttribute(hConsole, WinColorFG[color]);
    #else
    enum ANSITextAttr
    {
        TA_NORMAL=0,
        TA_BOLD=1,
        TA_BLINK=5,
        TA_REVERSE=7
    };

    enum ANSIFgTextAttr
    {
        FG_BLACK=30, FG_RED,  FG_GREEN, FG_BROWN, FG_BLUE,
        FG_MAGENTA,  FG_CYAN, FG_WHITE, FG_YELLOW
    };

    enum ANSIBgTextAttr
    {
        BG_BLACK=40, BG_RED,  BG_GREEN, BG_BROWN, BG_BLUE,
        BG_MAGENTA,  BG_CYAN, BG_WHITE
    };

    static uint8 UnixColorFG[Colors] =
    {
        FG_BLACK,                                           // BLACK
        FG_RED,                                             // RED
        FG_GREEN,                                           // GREEN
        FG_BROWN,                                           // BROWN
        FG_BLUE,                                            // BLUE
        FG_MAGENTA,                                         // MAGENTA
        FG_CYAN,                                            // CYAN
        FG_WHITE,                                           // WHITE
        FG_YELLOW,                                          // YELLOW
        FG_RED,                                             // LRED
        FG_GREEN,                                           // LGREEN
        FG_BLUE,                                            // LBLUE
        FG_MAGENTA,                                         // LMAGENTA
        FG_CYAN,                                            // LCYAN
        FG_WHITE                                            // LWHITE
    };

    fprintf((stdout_stream? stdout : stderr), "\x1b[%d%sm", UnixColorFG[color], (color >= YELLOW && color < Colors ? ";1" : ""));
    #endif
}

void Log::ResetColor(bool stdout_stream)
{
    #if PLATFORM == PLATFORM_WINDOWS
    HANDLE hConsole = GetStdHandle(stdout_stream ? STD_OUTPUT_HANDLE : STD_ERROR_HANDLE );
    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED );
    #else
    fprintf(( stdout_stream ? stdout : stderr ), "\x1b[0m");
    #endif
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

void Log::outDB(LogTypes type, const char * str)
{
    if (!str || type >= MAX_LOG_TYPES)
         return;

    std::string new_str(str);
    if (new_str.empty())
        return;
    loginDatabase.escape_string(new_str);

    loginDatabase.PExecute("INSERT INTO logs (time, realm, type, string) "
        "VALUES (" UI64FMTD ", %u, %u, '%s');", uint64(time(0)), realm, type, new_str.c_str());
}

void Log::outString(const char * str, ...)
{
    if (!str)
        return;

    if (m_enableLogDB)
    {
        // we don't want empty strings in the DB
        std::string s(str);
        if (s.empty() || s == " ")
            return;

        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_STRING, nnew_str);
        va_end(ap2);
    }

    if (m_colored)
        SetColor(true,m_colors[LOGL_NORMAL]);

    va_list ap;

    va_start(ap, str);
    vutf8printf(stdout, str, &ap);
    va_end(ap);

    if (m_colored)
        ResetColor(true);

    printf("\n");
    if(logfile)
    {
        outTimestamp(logfile);
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        fprintf(logfile, "\n");
        va_end(ap);

        fflush(logfile);
    }
    fflush(stdout);
}

void Log::outString()
{
    printf("\n");
    if (logfile)
    {
        outTimestamp(logfile);
        fprintf(logfile, "\n");
        fflush(logfile);
    }
    fflush(stdout);
}

void Log::outCrash(const char * err, ...)
{
    if (!err)
        return;

    if (m_enableLogDB)
    {
        va_list ap2;
        va_start(ap2, err);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, err, ap2);
        outDB(LOG_TYPE_CRASH, nnew_str);
        va_end(ap2);
    }

    if (m_colored)
        SetColor(false,LRED);

    va_list ap;

    va_start(ap, err);
    vutf8printf(stdout, err, &ap);
    va_end(ap);

    if (m_colored)
        ResetColor(false);

    fprintf(stderr, "\n");
    if (logfile)
    {
        outTimestamp(logfile);
        fprintf(logfile, "CRASH ALERT: ");

        va_start(ap, err);
        vfprintf(logfile, err, ap);
        va_end(ap);

        fprintf(logfile, "\n");
        fflush(logfile);
    }
    fflush(stderr);
}

void Log::outError(const char * err, ...)
{
    if (!err)
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

    if (m_colored)
        SetColor(false,LRED);

    va_list ap;

    va_start(ap, err);
    vutf8printf(stderr, err, &ap);
    va_end(ap);

    if (m_colored)
        ResetColor(false);

    fprintf( stderr, "\n");
    if (logfile)
    {
        outTimestamp(logfile);
        fprintf(logfile, "ERROR: ");

        va_start(ap, err);
        vfprintf(logfile, err, ap);
        va_end(ap);

        fprintf(logfile, "\n");
        fflush(logfile);
    }
    fflush(stderr);
}

void Log::outArena(const char * str, ...)
{
    if (!str)
        return;

    if (arenaLogFile)
    {
        va_list ap;
        outTimestamp(arenaLogFile);
        va_start(ap, str);
        vfprintf(arenaLogFile, str, ap);
        fprintf(arenaLogFile, "\n");
        va_end(ap);
        fflush(arenaLogFile);
    }
    fflush(stdout);
}

void Log::outErrorDb(const char * err, ...)
{
    if (!err)
        return;

    if (m_colored)
        SetColor(false,LRED);

    va_list ap;

    va_start(ap, err);
    vutf8printf(stderr, err, &ap);
    va_end(ap);

    if (m_colored)
        ResetColor(false);

    fprintf( stderr, "\n" );

    if (logfile)
    {
        outTimestamp(logfile);
        fprintf(logfile, "ERROR: " );

        va_start(ap, err);
        vfprintf(logfile, err, ap);
        va_end(ap);

        fprintf(logfile, "\n" );
        fflush(logfile);
    }

    if (dberLogfile)
    {
        outTimestamp(dberLogfile);
        va_start(ap, err);
        vfprintf(dberLogfile, err, ap);
        va_end(ap);

        fprintf(dberLogfile, "\n" );
        fflush(dberLogfile);
    }
    fflush(stderr);
}

void Log::outBasic(const char * str, ...)
{
    if (!str)
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

    if (m_logLevel > LOGL_NORMAL)
    {
        if (m_colored)
            SetColor(true,m_colors[LOGL_BASIC]);

        va_list ap;
        va_start(ap, str);
        vutf8printf(stdout, str, &ap);
        va_end(ap);

        if (m_colored)
            ResetColor(true);

        printf("\n");

        if (logfile)
        {
            outTimestamp(logfile);
            va_list ap;
            va_start(ap, str);
            vfprintf(logfile, str, ap);
            fprintf(logfile, "\n" );
            va_end(ap);
            fflush(logfile);
        }
    }
    fflush(stdout);
}

void Log::outDetail(const char * str, ...)
{
    if (!str)
        return;

    if (m_enableLogDB && m_dbLogLevel > LOGL_BASIC)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_DETAIL, nnew_str);
        va_end(ap2);
    }

    if (m_logLevel > LOGL_BASIC)
    {
        if (m_colored)
            SetColor(true,m_colors[LOGL_DETAIL]);

        va_list ap;
        va_start(ap, str);
        vutf8printf(stdout, str, &ap);
        va_end(ap);

        if (m_colored)
            ResetColor(true);

        printf("\n");

        if (logfile)
        {
            outTimestamp(logfile);
            va_list ap;
            va_start(ap, str);
            vfprintf(logfile, str, ap);
            va_end(ap);

            fprintf(logfile, "\n");
            fflush(logfile);
        }
    }

    fflush(stdout);
}

void Log::outDebugInLine(const char * str, ...)
{
    if (!str)
        return;

    if (m_logLevel > LOGL_DETAIL)
    {
        va_list ap;
        va_start(ap, str);
        vutf8printf(stdout, str, &ap);
        va_end(ap);

        //if(m_colored)
        //    ResetColor(true);

        if (logfile)
        {
            va_list ap;
            va_start(ap, str);
            vfprintf(logfile, str, ap);
            va_end(ap);
        }
    }
}

void Log::outDebug(const char * str, ...)
{
    if (!str)
        return;

    if (m_enableLogDB && m_dbLogLevel > LOGL_DETAIL)
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
        if (m_colored)
            SetColor(true,m_colors[LOGL_DEBUG]);

        va_list ap;
        va_start(ap, str);
        vutf8printf(stdout, str, &ap);
        va_end(ap);

        if(m_colored)
            ResetColor(true);

        printf( "\n" );

        if (logfile)
        {
            outTimestamp(logfile);
            va_list ap;
            va_start(ap, str);
            vfprintf(logfile, str, ap);
            va_end(ap);

            fprintf(logfile, "\n" );
            fflush(logfile);
        }
    }
    fflush(stdout);
}

void Log::outStringInLine(const char * str, ...)
{
    if (!str)
        return;

    va_list ap;

    va_start(ap, str);
    vutf8printf(stdout, str, &ap);
    va_end(ap);

    if (logfile)
    {
        va_start(ap, str);
        vfprintf(logfile, str, ap);
        va_end(ap);
    }
}

void Log::outCommand(uint32 account, const char * str, ...)
{
    if (!str)
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

    if (m_logLevel > LOGL_NORMAL)
    {
        if (m_colored)
            SetColor(true,m_colors[LOGL_BASIC]);

        va_list ap;
        va_start(ap, str);
        vutf8printf(stdout, str, &ap);
        va_end(ap);

        if (m_colored)
            ResetColor(true);

        printf("\n");

        if (logfile)
        {
            outTimestamp(logfile);
            va_list ap;
            va_start(ap, str);
            vfprintf(logfile, str, ap);
            fprintf(logfile, "\n" );
            va_end(ap);
            fflush(logfile);
        }
    }

    if (m_gmlog_per_account)
    {
        if (FILE* per_file = openGmlogPerAccount (account))
        {
            outTimestamp(per_file);
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
        outTimestamp(gmLogfile);
        va_list ap;
        va_start(ap, str);
        vfprintf(gmLogfile, str, ap);
        fprintf(gmLogfile, "\n" );
        va_end(ap);
        fflush(gmLogfile);
    }

    fflush(stdout);
}

void Log::outChar(const char * str, ...)
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

    if (charLogfile)
    {
        outTimestamp(charLogfile);
        va_list ap;
        va_start(ap, str);
        vfprintf(charLogfile, str, ap);
        fprintf(charLogfile, "\n" );
        va_end(ap);
        fflush(charLogfile);
    }
}

void Log::outCharDump(const char * str, uint32 account_id, uint32 guid, const char * name)
{
    if (charLogfile)
    {
        fprintf(charLogfile, "== START DUMP == (account: %u guid: %u name: %s )\n%s\n== END DUMP ==\n",account_id,guid,name,str );
        fflush(charLogfile);
    }
}

void Log::outRemote(const char * str, ...)
{
    if (!str)
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
        outTimestamp(raLogfile);
        va_list ap;
        va_start(ap, str);
        vfprintf(raLogfile, str, ap);
        fprintf(raLogfile, "\n" );
        va_end(ap);
        fflush(raLogfile);
    }
    fflush(stdout);
}

void Log::outChat(const char * str, ...)
{
    if (!str)
        return;

    if (m_enableLogDB && m_dbChat)
    {
        va_list ap2;
        va_start(ap2, str);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, str, ap2);
        outDB(LOG_TYPE_CHAT, nnew_str);
        va_end(ap2);
    }

    if (chatLogfile)
    {
        outTimestamp(chatLogfile);
        va_list ap;
        va_start(ap, str);
        vfprintf(chatLogfile, str, ap);
        fprintf(chatLogfile, "\n" );
        fflush(chatLogfile);
        va_end(ap);
    }
    fflush(stdout);
}

void outstring_log(const char * str, ...)
{
    if (!str)
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
    if (!str)
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
    if (!str)
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
    if (!str)
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
    if (!str)
        return;

    char buf[256];
    va_list ap;
    va_start(ap, str);
    vsnprintf(buf,256, str, ap);
    va_end(ap);

    Trinity::Singleton<Log>::Instance().outErrorDb(buf);
}

