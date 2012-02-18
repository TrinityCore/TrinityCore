/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/** \file
    \ingroup u2w
*/

#include "WorldLog.h"
#include "Config.h"
#include "Log.h"
#include "DatabaseWorkerPool.h"

WorldLog::WorldLog() : i_file(NULL)
{
    Initialize();
}

WorldLog::~WorldLog()
{
    if (i_file != NULL)
        fclose(i_file);
    i_file = NULL;
}

/// Open the log file (if specified so in the configuration file)
void WorldLog::Initialize()
{
    std::string logsDir = ConfigMgr::GetStringDefault("LogsDir", "");

    if (!logsDir.empty())
    {
        if ((logsDir.at(logsDir.length()-1) != '/') && (logsDir.at(logsDir.length()-1) != '\\'))
            logsDir.push_back('/');
    }

    std::string logname = ConfigMgr::GetStringDefault("WorldLogFile", "");
    if (!logname.empty())
    {
        i_file = fopen((logsDir+logname).c_str(), "w");
    }

    m_dbWorld = ConfigMgr::GetBoolDefault("LogDB.World", false); // can be VERY heavy if enabled
}

void WorldLog::outTimestampLog(char const* fmt, ...)
{
    if (LogWorld())
    {
        TRINITY_GUARD(ACE_Thread_Mutex, Lock);
        ASSERT(i_file);

        Log::outTimestamp(i_file);
        va_list args;
        va_start(args, fmt);
        vfprintf(i_file, fmt, args);
        //fprintf(i_file, "\n");
        va_end(args);

        fflush(i_file);
    }

    if (sLog->GetLogDB() && m_dbWorld)
    {
        va_list ap2;
        va_start(ap2, fmt);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, fmt, ap2);
        sLog->outDB(LOG_TYPE_WORLD, nnew_str);
        va_end(ap2);
    }
}

void WorldLog::outLog(char const* fmt, ...)
{
    if (LogWorld())
    {
        TRINITY_GUARD(ACE_Thread_Mutex, Lock);
        ASSERT(i_file);

        va_list args;
        va_start(args, fmt);
        vfprintf(i_file, fmt, args);
        //fprintf(i_file, "\n");
        va_end(args);

        fflush(i_file);
    }

    if (sLog->GetLogDB() && m_dbWorld)
    {
        va_list ap2;
        va_start(ap2, fmt);
        char nnew_str[MAX_QUERY_LEN];
        vsnprintf(nnew_str, MAX_QUERY_LEN, fmt, ap2);
        sLog->outDB(LOG_TYPE_WORLD, nnew_str);
        va_end(ap2);
    }
}
