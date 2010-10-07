/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _MYSQLTHREADING_H
#define _MYSQLTHREADING_H

#include "Log.h"

class MySQL
{
    public:
        /*! Create a thread on the MySQL server to mirrior the calling thread,
            initializes thread-specific variables and allows thread-specific
            operations without concurrence from other threads.
            This should only be called if multiple core threads are running
            on the same MySQL connection. Seperate MySQL connections implicitly
            create a mirror thread.
        */
        static void Thread_Init()
        {
            mysql_thread_init();
            printf("Core thread with ID ["UI64FMTD"] initializing MySQL thread.\n",
                    (uint64)ACE_Based::Thread::currentId());
        }

        /*! Shuts down MySQL thread and frees resources, should only be called
            when we terminate. MySQL threads and connections are not configurable
            during runtime.
        */
        static void Thread_End()
        {
            mysql_thread_end();
            printf("Core thread with ID ["UI64FMTD"] shutting down MySQL thread.\n",
                (uint64)ACE_Based::Thread::currentId());
        }
};

#endif