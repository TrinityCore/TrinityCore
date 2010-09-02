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

#ifndef TRINITYCORE_LOG_H
#define TRINITYCORE_LOG_H

#include "Common.h"
#include <ace/Singleton.h>

class Config;

enum LogFilters
{
    LOG_FILTER_TRANSPORT_MOVES     = 1,
    LOG_FILTER_CREATURE_MOVES      = 2,
    LOG_FILTER_VISIBILITY_CHANGES  = 4,
    LOG_FILTER_ACHIEVEMENT_UPDATES = 8
};

enum LogTypes
{
    LOG_TYPE_STRING = 0,
    LOG_TYPE_ERROR  = 1,
    LOG_TYPE_BASIC  = 2,
    LOG_TYPE_DETAIL = 3,
    LOG_TYPE_DEBUG  = 4,
    LOG_TYPE_CHAR   = 5,
    LOG_TYPE_WORLD  = 6,
    LOG_TYPE_RA     = 7,
    LOG_TYPE_GM     = 8,
    LOG_TYPE_CRASH  = 9,
    LOG_TYPE_CHAT   = 10,
    MAX_LOG_TYPES
};

enum LogLevel
{
    LOGL_NORMAL = 0,
    LOGL_BASIC,
    LOGL_DETAIL,
    LOGL_DEBUG
};

const int LogLevels = int(LOGL_DEBUG)+1;

enum ColorTypes
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

const int Colors = int(WHITE)+1;

class Log
{
    friend class ACE_Singleton<Log, ACE_Thread_Mutex>;
    Log();
    ~Log();

    public:
        void Initialize();

        void InitColors(const std::string& init_str);
        void SetColor(bool stdout_stream, ColorTypes color);
        void ResetColor(bool stdout_stream);

        void outDB( LogTypes type, const char * str );
        void outString( const char * str, ... )                 ATTR_PRINTF(2,3);
        void outString( );
        void outStringInLine( const char * str, ... )           ATTR_PRINTF(2,3);
        void outError( const char * err, ... )                  ATTR_PRINTF(2,3);
        void outCrash( const char * err, ... )                  ATTR_PRINTF(2,3);
        void outBasic( const char * str, ... )                  ATTR_PRINTF(2,3);
        void outDetail( const char * str, ... )                 ATTR_PRINTF(2,3);
        void outDebug( const char * str, ... )                  ATTR_PRINTF(2,3);
        void outStaticDebug( const char * str, ... )            ATTR_PRINTF(2,3);
        void outDebugInLine( const char * str, ... )            ATTR_PRINTF(2,3);
        void outErrorDb( const char * str, ... )                ATTR_PRINTF(2,3);
        void outChar( const char * str, ... )                   ATTR_PRINTF(2,3);
        void outCommand( uint32 account, const char * str, ...) ATTR_PRINTF(3,4);
        void outRemote( const char * str, ... )                 ATTR_PRINTF(2,3);
        void outChat( const char * str, ... )                   ATTR_PRINTF(2,3);
        void outArena( const char * str, ... )                  ATTR_PRINTF(2,3);
        void outSQLDriver( const char* str, ... )               ATTR_PRINTF(2,3);
        void outCharDump( const char * str, uint32 account_id, uint32 guid, const char * name );

        static void outTimestamp(FILE* file);
        static std::string GetTimestampStr();

        void SetLogLevel(char * Level);
        void SetLogFileLevel(char * Level);
        void SetDBLogLevel(char * Level);
        void SetRealmID(uint32 id) { realm = id; }

        uint32 getLogFilter() const { return m_logFilter; }
        bool IsOutDebug() const { return m_logLevel > 2 || (m_logFileLevel > 2 && logfile); }
        bool IsOutCharDump() const { return m_charLog_Dump; }

        bool GetLogDB() { return m_enableLogDB; }
        bool GetLogDBLater() { return m_enableLogDBLater; }
        void SetLogDB(bool enable) { m_enableLogDB = enable; }
        void SetLogDBLater(bool value) { m_enableLogDBLater = value; }
    private:
        FILE* openLogFile(char const* configFileName,char const* configTimeStampFlag, char const* mode);
        FILE* openGmlogPerAccount(uint32 account);

        FILE* raLogfile;
        FILE* logfile;
        FILE* gmLogfile;
        FILE* charLogfile;
        FILE* dberLogfile;
        FILE* chatLogfile;
        FILE* arenaLogFile;
        FILE* sqlLogFile;

        // cache values for after initilization use (like gm log per account case)
        std::string m_logsDir;
        std::string m_logsTimestamp;

        // gm log control
        bool m_gmlog_per_account;
        std::string m_gmlog_filename_format;

        bool m_enableLogDBLater;
        bool m_enableLogDB;
        uint32 realm;

        // log coloring
        bool m_colored;
        ColorTypes m_colors[4];

        // log levels:
        // 0 minimum/string, 1 basic/error, 2 detail, 3 full/debug
        uint8 m_dbLogLevel;
        uint8 m_logLevel;
        uint8 m_logFileLevel;
        uint8 m_logFilter;
        bool m_dbChar;
        bool m_dbRA;
        bool m_dbGM;
        bool m_dbChat;
        bool m_charLog_Dump;
        bool m_charLog_Dump_Separate;
        std::string m_dumpsDir;
};

#define sLog (*ACE_Singleton<Log, ACE_Thread_Mutex>::instance())

#endif

