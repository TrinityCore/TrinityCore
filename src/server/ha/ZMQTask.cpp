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
#include "ZmqContext.h"

ZMQTask::ZMQTask()
{
    poller = new zmqpp::poller();
}

ZMQTask::~ZMQTask()
{
  delete poller;
  poller = NULL;
  delete inproc;
}

int ZMQTask::open(void*)
{

    inproc = sContext->newSocket(zmqpp::socket_type::sub);
    inproc->connect("inproc://workers");
    inproc->subscribe("internalmq.");

    poller->add(*inproc);

    HandleOpen();
    thr = new boost::thread((*this));
}

int ZMQTask::close(u_long flags /*= 0 */)
{
    inproc->close();
    return HandleClose(flags);
}

bool ZMQTask::process_exit()
{
    if (poller->events(*inproc) == zmqpp::poller::poll_in)
    {
        int op1;
        do
        {
            zmqpp::message msg;
            if (!inproc->receive(msg, true))
                return false; //No more messages to read from sock. This shouldn't happen.

            // strip 'internalmq.' from message
            std::string cmd = msg.get(0).substr(11);
            if (cmd == "kill")
                return true;

            inproc->get(zmqpp::socket_option::events, op1);
        } while (op1 & zmqpp::poller::poll_in);
    }

    return false;
}

void ZMQTask::pipeline(zmqpp::socket* from, zmqpp::socket* to)
{
    /*
      Push messages from socket to socket.
    */
    if (poller->events(*from) == zmqpp::poller::poll_in)
    {
        int op1, op2;
        do
        {
            zmqpp::message msg;
            if (!from->receive(msg, true))
                return; //No more messages to read from socket. This shouldn't happen.

            to->send(msg);
            from->get(zmqpp::socket_option::events, op1);
            to->get(zmqpp::socket_option::events, op2);
        } while(op1 & zmqpp::poller::poll_in && op2 & zmqpp::poller::poll_out);
    }
}
