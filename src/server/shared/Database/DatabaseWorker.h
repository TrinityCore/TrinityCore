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

#ifndef _WORKERTHREAD_H
#define _WORKERTHREAD_H

#include <ace/Task.h>
#include <ace/Activation_Queue.h>

#include "DatabaseWorkerPool.h"
#include "SQLOperation.h"
#include "MySQLConnection.h"
#include "MySQLThreading.h"

class MySQLConnection;

template <typename T>
class DatabaseWorker : public ACE_Task_Base
{
    public:
        DatabaseWorker(ACE_Activation_Queue* new_queue, DatabaseWorkerPool<T>* pool) :
        m_queue(new_queue),
        m_pool(pool)
        {
            /// Assign thread to task
            activate();
        }


        ///- Inherited from ACE_Task_Base
        int svc()
        {
            if (!m_queue)
                return -1;

            SQLOperation *request = NULL;
            while (1)
            {
                request = (SQLOperation*)(m_queue->dequeue());
                if (!request)
                    break;

                MySQLConnection* con = m_pool->GetFreeConnection();
                request->SetConnection(con);
                request->call();
                con->Unlock();

                delete request;
            }

            m_conn->Close();
            return 0;
        }

        int activate()
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

        int wait() { return ACE_Task_Base::wait(); }

    private:
        DatabaseWorker() : ACE_Task_Base() {}
        ACE_Activation_Queue* m_queue;
        MySQLConnection* m_conn;
        DatabaseWorkerPool<T>* m_pool;  // Databasepool we operate on
};

#endif
