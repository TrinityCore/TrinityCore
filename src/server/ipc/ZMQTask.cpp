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

#include "ZMQTask.h"
#include "ZmqContext.h"
#include <zmqpp/message.hpp>

ZMQTask::ZMQTask()
{
    _poller = new zmqpp::poller();
}

ZMQTask::~ZMQTask()
{
    delete _poller;
    _poller = NULL;
    delete _inproc;
    delete _thread;
}

void ZMQTask::Start()
{
    _inproc = sIpcContext->CreateInprocSubscriber();
    _poller->add(*_inproc);

    HandleOpen();
    _thread = new std::thread(&ZMQTask::Run, this);
}

void ZMQTask::End()
{
    _thread->join();
    _inproc->close();
    HandleClose();
}

bool ZMQTask::ProcessExit()
{
    if (_poller->events(*_inproc) == zmqpp::poller::poll_in)
    {
        int op1;
        do
        {
            zmqpp::message msg;
            if (!_inproc->receive(msg, true))
                return false; //No more messages to read from sock. This shouldn't happen.

            // strip 'internalmq.' from message
            std::string cmd = msg.get(0).substr(11);
            if (cmd == "kill")
                return true;

            _inproc->get(zmqpp::socket_option::events, op1);
        } while (op1 & zmqpp::poller::poll_in);
    }

    return false;
}

void ZMQTask::Pipeline(zmqpp::socket* from, zmqpp::socket* to)
{
    /*
      Push messages from socket to socket.
    */
    if (_poller->events(*from) == zmqpp::poller::poll_in)
    {
        int32 op1, op2;
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
