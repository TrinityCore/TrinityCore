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

#include "Worker.h"

Worker::Worker(){ }

Worker::~Worker() 
{
    delete task_queue;
    delete results;
    delete inproc;
}

int Worker::HandleOpen(zmqpp::context const* ctx)
{
    task_queue = new zmqpp::socket(*ctx, zmqpp::socket_type::pull);
    results = new zmqpp::socket(*ctx, zmqpp::socket_type::push);

    task_queue->connect("inproc://work_queue");
    results->connect("inproc://work_result");

    poller->add(*task_queue);
    poller->add(*results, zmqpp::poller::poll_out);
    return ACE_Task_Base::activate();
}

int Worker::HandleClose(u_long flags)
{
    task_queue->close();
    results->close();
    return 0;
}

int Worker::svc()
{
    while(!process_exit())
    {
        poller->poll();
        if(poller->events(*task_queue) & zmqpp::poller::poll_in)
            perform_work();
    }
}

void Worker::perform_work()
{
    int op1, op2;
    do
    {
        zmqpp::message msg;
        task_queue->receive(msg);
        dispatch(msg);
        task_queue->get(zmqpp::socket_option::events, op1);
    }while(op1 & zmqpp::poller::poll_in);
}

void Worker::dispatch(const zmqpp::message& msg)
{
    uint32 opcode;
    msg.get(opcode, 0);
    printf("worker recv opcode %u\n", opcode);
    if(opcode >= OPCODES_MAX)
        return;

    (this->*handlers[opcode])(msg);
}

void Worker::test_handler(const zmqpp::message& msg)
{
    std::string s;
    msg.get(s, 1);
    printf("Debug message recvd: %s\n", s.c_str());
}

const opcode_handler handlers[OPCODES_MAX] = {
    &Worker::test_handler,
};
