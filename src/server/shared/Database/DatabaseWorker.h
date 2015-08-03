/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include <thread>
#include "ProducerConsumerQueue.h"

class MySQLConnection;
class SQLOperation;

class DatabaseWorker
{
    public:
        DatabaseWorker(ProducerConsumerQueue<SQLOperation*>* newQueue, MySQLConnection* connection);
        ~DatabaseWorker();

    private:
        ProducerConsumerQueue<SQLOperation*>* _queue;
        MySQLConnection* _connection;

        void WorkerThread();
        std::thread _workerThread;

        std::atomic_bool _cancelationToken;

        DatabaseWorker(DatabaseWorker const& right) = delete;
        DatabaseWorker& operator=(DatabaseWorker const& right) = delete;
};

#endif
