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

#include "ZmqWorker.h"
#include "ZmqContext.h"

ZmqWorker::ZmqWorker(std::string task_uri, std::string res_uri) :
    _taskUri(task_uri), _resultsUri(res_uri)
{
}

ZmqWorker::~ZmqWorker()
{
    delete _taskQueue;
    delete _results;
    delete _inproc;
}

void ZmqWorker::HandleOpen()
{
    _taskQueue =  sIpcContext->CreateNewSocket(zmqpp::socket_type::pull);
    _results = sIpcContext->CreateNewSocket(zmqpp::socket_type::push);

    _taskQueue->connect(_taskUri);
    _results->connect(_resultsUri);

    _poller->add(*_taskQueue);
}

void ZmqWorker::HandleClose()
{
    _taskQueue->close();
    _results->close();
}

void ZmqWorker::Run()
{
    while (!ProcessExit())
    {
        _poller->poll();
        if (_poller->events(*_taskQueue) & zmqpp::poller::poll_in)
            PerformWork();
    }
}

void ZmqWorker::PerformWork()
{
    int32 op1;
    do
    {
        zmqpp::message msg;
        _taskQueue->receive(msg);
        Dispatch(msg);
        _taskQueue->get(zmqpp::socket_option::events, op1);
    } while (op1 & zmqpp::poller::poll_in);
}
