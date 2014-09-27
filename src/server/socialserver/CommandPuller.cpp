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

#include "CommandPuller.h"
#include "ZmqContext.h"

CommandPuller::CommandPuller() :
    commands(NULL), broadcast(NULL), work_queue(NULL), work_res(NULL)
{
}

CommandPuller::~CommandPuller()
{
    delete commands;
    delete broadcast;
    delete work_queue;
    delete work_res;
}

int CommandPuller::svc()
{
    /*
      Polling strategy is pretty simple right now.
      There are two socket pairs that need to be read and write ready for magic to happen.
      commands read -> work_queue write
      work_res read -> broadcast write
      So we're only doing stuff if both of them can handle writes/reads,
     */
    while (true)
    {
        if (!poller->poll())
            break;

        if (process_exit())
            break;

        pipeline(commands, work_queue);
        pipeline(work_res, broadcast);
    }

    return 0;
}

int CommandPuller::HandleOpen()
{
    commands = sContext->newSocket(zmqpp::socket_type::pull);
    broadcast = sContext->newSocket(zmqpp::socket_type::publish);
    work_queue = sContext->newSocket(zmqpp::socket_type::push);
    work_res = sContext->newSocket(zmqpp::socket_type::pull);

    commands->bind("tcp://*:9997");
    broadcast->bind("tcp://*:9998");
    work_queue->bind("inproc://work_queue");
    work_res->bind("inproc://work_result");

    poller->add(*commands);
    poller->add(*work_res);

    printf("CommandPuller sockets have been set up successfully\n");
    return 0;
}

int CommandPuller::HandleClose(u_long /*flags  = 0 */)
{
    work_res->close();
    work_queue->close();
    broadcast->close();
    commands->close();
    printf("CommandPuller sockets have been closed\n");
    return 0;
}
