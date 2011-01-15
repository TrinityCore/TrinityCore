/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

class MySQLConnection;

class DatabaseWorker : protected ACE_Task_Base
{
    public:
        DatabaseWorker(ACE_Activation_Queue* new_queue, MySQLConnection* con);

        ///- Inherited from ACE_Task_Base
        int svc();
        int wait() { return ACE_Task_Base::wait(); }

    private:
        DatabaseWorker() : ACE_Task_Base() {}
        ACE_Activation_Queue* m_queue;
        MySQLConnection* m_conn;
};

#endif
