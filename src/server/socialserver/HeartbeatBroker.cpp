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
#include "ZmqContext.h"

HeartbeatBroker::HeartbeatBroker() : sock(NULL)
{
}

HeartbeatBroker::~HeartbeatBroker()
{
    delete sock;
}

int HeartbeatBroker::svc()
{
    while (true)
    {
        poller->poll();
        if (process_exit())
            break;

        sock->send("");
    }

    return 0;
}

int HeartbeatBroker::HandleOpen()
{
    sock = sContext->newSocket(zmqpp::socket_type::publish);
    sock->bind("tcp://*:9999");

    poller->add(*sock);

    printf("HeartbeatBroker socket has been set up successfully");
    return 0;
}

int HeartbeatBroker::HandleClose(u_long /*flags = 0 */)
{
    sock->close();
    printf("HeartbeatBroker socket has been closed");
    return 0;
}
