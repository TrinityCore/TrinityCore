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

#include "HeartbeatBroker.h"
#include <zmqpp/socket_types.hpp>

HeartbeatBroker::HeartbeatBroker() : ZMQTask(), sock(NULL)
{
}

HeartbeatBroker::~HeartbeatBroker()
{
    delete sock;
}

int HeartbeatBroker::HandleOpen(zmqpp::context const* ctx)
{
    sock = new zmqpp::socket(*ctx, zmqpp::socket_type::publish);
    sock->bind("tcp://*:9999");
    printf("bound HeartbeatBroker socket to tcp://*:9999\n");

    poller->add(*sock);
    ACE_Task_Base::activate(THR_NEW_LWP | THR_JOINABLE);
    printf("HeartbeatBroker opened\n");
    return 0;
}

int HeartbeatBroker::HandleClose(u_long /*flags  = 0 */)
{
    printf("HeartbeatBroker::HandleClose\n");
    sock->close();
    printf("HeartbeatBroker sock closed\n");
    return 0;
}

int HeartbeatBroker::svc()
{
    while (true)
    {
        poller->poll(1000);
        if (process_exit())
            break;

        sock->send("");
    }

    printf("HeartbeatBroker::svc() exited\n");
    return 0;
}
