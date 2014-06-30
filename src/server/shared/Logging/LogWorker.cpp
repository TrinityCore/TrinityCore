/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "LogWorker.h"
#include <thread>

LogWorker::LogWorker()
{
    _cancelationToken = false;
    _workerThread = std::thread(&LogWorker::WorkerThread, this);
}

LogWorker::~LogWorker()
{
    _cancelationToken = true;

    _queue.Cancel();

    _workerThread.join();
}

void LogWorker::Enqueue(LogOperation* op)
{
    return _queue.Push(op);
}

void LogWorker::WorkerThread()
{
    while (1)
    {
        LogOperation* operation = nullptr;
        
        _queue.WaitAndPop(operation);

        if (_cancelationToken)
            return;

        operation->call();

        delete operation;
    }
}
