/*
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "DatabaseEnv.h"
#include "DatabaseWorker.h"
#include "SQLOperation.h"
#include "MySQLConnection.h"

DatabaseWorker::DatabaseWorker(ACE_Activation_Queue* new_queue, MySQLConnection* con) :
m_queue(new_queue),
m_conn(con)
{
    /// Assign thread to task
    activate();
}

int DatabaseWorker::svc()
{
    if (!m_queue)
        return -1;

    SQLOperation *request = NULL;
    while (1)
    {
        request = (SQLOperation*)(m_queue->dequeue());
        if (!request)
            break;

        request->SetConnection(m_conn);
        request->call();

        delete request;
    }

    delete m_conn;
    return 0;
}

int DatabaseWorker::activate()
{
    /* THR_DETACHED:
    Create an asynchronous thread. The exit status of the thread would not be available to any other threads.
    The thread resources are reclaimed by the operating system whenever the thread is terminated. */

    /* THR_NEW_LWP:
    Create an explicit kernel-level thread (as opposed to a user-level thread). */

    ACE_Task_Base::activate(THR_NEW_LWP | THR_DETACHED, 1);
    return 0;                                          //^ - Spawn one thread to handle this task.
                                                       // However more of these tasks may be activated
                                                       // See DatabaseWorkerPool ctor.
}