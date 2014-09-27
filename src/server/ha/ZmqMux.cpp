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

#include "ZmqMux.h"
#include "ZmqContext.h"

ZmqMux::~ZmqMux()
{
    delete from;
    delete to;
}

ZmqMux::ZmqMux(std::string from_uri, std::string to_uri):
  addr(from_uri)
{
    printf("Opening muxer thread from %s to %s\n", from_uri.c_str(), to_uri.c_str());
    from = sContext->newSocket(zmqpp::socket_type::pull);
    to = sContext->newSocket(zmqpp::socket_type::push);

    from->bind(from_uri);
    to->connect(to_uri);
}

int ZmqMux::HandleOpen()
{
    poller->add(*from);
    poller->add(*to, zmqpp::poller::poll_out);
}

int ZmqMux::HandleClose(u_long)
{
    return 0;
}

bool ZmqMux::send(zmqpp::message* m, bool dont_block)
{
  if(sock.get() == nullptr)
    {
      sock.reset(sContext->newSocket(zmqpp::socket_type::push));
      sock->connect(addr);
    }

  return sock->send(*m, dont_block);
}

int ZmqMux::svc()
{
    while(true)
    {
        if(!poller->poll())
            break;

        if(process_exit())
            break;

        pipeline(from, to);
    }

    return 0;
}
