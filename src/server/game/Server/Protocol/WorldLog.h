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

/// \addtogroup u2w
/// @{
/// \file

#ifndef TRINITY_WORLDLOG_H
#define TRINITY_WORLDLOG_H

#include "Common.h"
#include <ace/Singleton.h>
#include "Errors.h"

#include <stdarg.h>

/// %Log packets to a file
class WorldLog
{
    friend class ACE_Singleton<WorldLog, ACE_Thread_Mutex>;

    private:
        WorldLog();
        ~WorldLog();
        WorldLog(const WorldLog &);
        WorldLog& operator=(const WorldLog &);
        ACE_Thread_Mutex Lock;

    public:
        void Initialize();
        /// Is the world logger active?
        bool LogWorld(void) const { return (i_file != NULL); }
        /// %Log to the file
        void outLog(char const* fmt, ...);
        void outTimestampLog(char const* fmt, ...);

    private:
        FILE* i_file;

        bool m_dbWorld;
};

#define sWorldLog ACE_Singleton<WorldLog, ACE_Thread_Mutex>::instance()
#endif
/// @}

