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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __SQLDELAYTHREAD_H
#define __SQLDELAYTHREAD_H

#include "zthread/Thread.h"
#include "zthread/Runnable.h"
#include "zthread/FastMutex.h"
#include "zthread/LockedQueue.h"

class Database;
class SqlOperation;

class SqlDelayThread : public ZThread::Runnable
{
    typedef ZThread::LockedQueue<SqlOperation*, ZThread::FastMutex> SqlQueue;
    private:
        SqlQueue m_sqlQueue;                                ///< Queue of SQL statements
        Database* m_dbEngine;                               ///< Pointer to used Database engine
        bool m_running;

        SqlDelayThread();
    public:
        SqlDelayThread(Database* db);

        ///< Put sql statement to delay queue
        inline bool Delay(SqlOperation* sql) { m_sqlQueue.add(sql); return true; }

        virtual void Stop();                                ///< Stop event
        virtual void run();                                 ///< Main Thread loop
};
#endif                                                      //__SQLDELAYTHREAD_H

