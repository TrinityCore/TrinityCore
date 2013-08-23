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

#include "ZMQTask.h"
#include <zmqpp/message.hpp>

ACE_Atomic_Op<ACE_Thread_Mutex, bool> ZMQTask::_closed = false;

ZMQTask::ZMQTask()
{
    poller = new zmqpp::poller();
}

ZMQTask::~ZMQTask()
{
    delete poller;
    poller = NULL;
}

bool ZMQTask::process_exit()
{
    if (_closed.value())
        return true;

    if (poller->events(*inproc) == zmqpp::poller::poll_in)
    {
        int op1;
        do
        {
            zmqpp::message msg;
            if (!inproc->receive(msg, true))
            {
                printf("ZMQTask::process_exit() nothing to receive\n");
                return false; //No more messages to read from sock. This shouldn't happen.
            }

            std::string cmd = msg.get(0);
            printf("ZMQTask::process_exit() got message %s\n", cmd.c_str());
            if (cmd == "kill")
            {
                _closed = true;
                return true;
            }

            inproc->get(zmqpp::socket_option::events, op1);
        } while (op1 & zmqpp::poller::poll_in);
    }

    return false;
}

int ZMQTask::open(void* data)
{
    zmqpp::context const* ctx = reinterpret_cast<zmqpp::context const*>(data);

    inproc = new zmqpp::socket(*ctx, zmqpp::socket_type::rep);
    inproc->connect("inproc://workers");

    poller->add(*inproc);

    return HandleOpen(ctx);
}

int ZMQTask::close(u_long flags /* = 0 */)
{
    inproc->close();
    printf("ZMQTask::close");
    return HandleClose(flags);
}
