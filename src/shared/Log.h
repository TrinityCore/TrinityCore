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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITYCORE_LOG_H
#define TRINITYCORE_LOG_H

#include "Common.h"
#include "Policies/Singleton.h"

class Config;

// bitmask
enum LogFilters
{
    LOG_FILTER_TRANSPORT_MOVES    = 1,
    LOG_FILTER_CREATURE_MOVES     = 2,
    LOG_FILTER_VISIBILITY_CHANGES = 4
};

enum Color
{
    BLACK,
    RED,
    GREEN,
    BROWN,
    BLUE,
    MAGENTA,
    CYAN,
    GREY,
    YELLOW,
    LRED,
    LGREEN,
    LBLUE,
    LMAGENTA,
    LCYAN,
    WHITE
};

const int Color_count = int(WHITE)+1;

class Log : public Trinity::Singleton<Log, Trinity::ClassLevelLockable<Log, ZThread::FastMutex> >
{
    friend class Trinity::OperatorNew<Log>;
    Log();

    ~Log()
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

        if (arenaLogFile != NULL)
            fclose(arenaLogFile);
        arenaLogFile = NULL;
    }
    public:
        void Initialize();
        void InitColors(const std::string& init_str);
        void outTitle( const char * str);
        void outCommand( uint32 account, const char * str, ...) ATTR_PRINTF(3,4);
        void outString();                                   // any log level
                                                            // any log level
        void outString( const char * str, ... )      ATTR_PRINTF(2,3);
                                                            // any log level
        void outError( const char * err, ... )       ATTR_PRINTF(2,3);
                                                            // log level >= 1
        void outBasic( const char * str, ... )       ATTR_PRINTF(2,3);
                                                            // log level >= 2
        void outDetail( const char * str, ... )      ATTR_PRINTF(2,3);
                                                            // log level >= 3
        void outDebugInLine( const char * str, ... ) ATTR_PRINTF(2,3);
                                                            // log level >= 3
        void outDebug( const char * str, ... )       ATTR_PRINTF(2,3);
                                                            // any log level
        void outMenu( const char * str, ... )        ATTR_PRINTF(2,3);
                                                            // any log level
        void outErrorDb( const char * str, ... )     ATTR_PRINTF(2,3);
                                                            // any log level
        void outChar( const char * str, ... )        ATTR_PRINTF(2,3);
                                                            // any log level
        void outCharDump( const char * str, uint32 account_id, uint32 guid, const char * name );
        void outRALog( const char * str, ... )       ATTR_PRINTF(2,3);
        void outArena( const char * str, ... )       ATTR_PRINTF(2,3);
        void SetLogLevel(char * Level);
        void SetLogFileLevel(char * Level);
        void SetColor(bool stdout_stream, Color color);
        void ResetColor(bool stdout_stream);
        void outTime();
        static void outTimestamp(FILE* file);
        static std::string GetTimestampStr();
        uint32 getLogFilter() const { return m_logFilter; }
        bool IsOutDebug() const { return m_logLevel > 2 || (m_logFileLevel > 2 && logfile); }
        bool IsOutCharDump() const { return m_charLog_Dump; }
        bool IsIncludeTime() const { return m_includeTime; }
    private:
        FILE* openLogFile(char const* configFileName,char const* configTimeStampFlag, char const* mode);
        FILE* openGmlogPerAccount(uint32 account);

        FILE* raLogfile;
        FILE* logfile;
        FILE* gmLogfile;
        FILE* charLogfile;
        FILE* dberLogfile;
        FILE* arenaLogFile;

        // log/console control
        uint32 m_logLevel;
        uint32 m_logFileLevel;
        bool m_colored;
        bool m_includeTime;
        Color m_colors[4];
        uint32 m_logFilter;

        // cache values for after initilization use (like gm log per account case)
        std::string m_logsDir;
        std::string m_logsTimestamp;

        // char log control
        bool m_charLog_Dump;

        // gm log control
        bool m_gmlog_per_account;

        std::string m_gmlog_filename_format;
};

#define sLog Trinity::Singleton<Log>::Instance()

#ifdef TRINITY_DEBUG
#define DEBUG_LOG Trinity::Singleton<Log>::Instance().outDebug
#else
#define DEBUG_LOG
#endif

// primary for script library
void TRINITY_DLL_SPEC outstring_log(const char * str, ...) ATTR_PRINTF(1,2);
void TRINITY_DLL_SPEC detail_log(const char * str, ...) ATTR_PRINTF(1,2);
void TRINITY_DLL_SPEC debug_log(const char * str, ...) ATTR_PRINTF(1,2);
void TRINITY_DLL_SPEC error_log(const char * str, ...) ATTR_PRINTF(1,2);
void TRINITY_DLL_SPEC error_db_log(const char * str, ...) ATTR_PRINTF(1,2);
#endif

