/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
    task_uri(task_uri), res_uri(res_uri)
{ }

ZmqWorker::~ZmqWorker()
{
    delete task_queue;
    delete results;
    delete inproc;
}

int ZmqWorker::HandleOpen()
{
    task_queue =  sContext->newSocket(zmqpp::socket_type::pull);
    results = sContext->newSocket(zmqpp::socket_type::push);

    task_queue->connect(task_uri);
    results->connect(res_uri);

    poller->add(*task_queue);
    return 0;
}

int ZmqWorker::HandleClose(u_long)
{
    task_queue->close();
    results->close();
    return 0;
}

int ZmqWorker::svc()
{
    while (!process_exit())
    {
        poller->poll();
        if (poller->events(*task_queue) & zmqpp::poller::poll_in)
            perform_work();
    }

    return 0;
}

void ZmqWorker::perform_work()
{
    int op1;
    do
    {
        zmqpp::message msg;
        task_queue->receive(msg);
        dispatch(msg);
        task_queue->get(zmqpp::socket_option::events, op1);
    } while (op1 & zmqpp::poller::poll_in);
}
