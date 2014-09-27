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

#include "ZmqListener.h"
#include "ZmqContext.h"

ZmqListener::ZmqListener(std::string& from_uri, std::string& to_uri)
{
    from = sContext->newSocket(zmqpp::socket_type::sub);
    to = sContext->newSocket(zmqpp::socket_type::push);
    from->connect(from_uri);
    to->bind(to_uri);
}

ZmqListener::~ZmqListener()
{
    delete from;
    delete to;
}

int ZmqListener::HandleOpen()
{
  return 0;
}

int ZmqListener::HandleClose(u_long)
{
    from->close();
    to->close();
    return 0;
}

int ZmqListener::svc()
{
    while(!process_exit())
    {
        poller->poll();

        while(poller->events(*from) & zmqpp::poller::poll_in &&
              poller->events(*to) & zmqpp::poller::poll_out)
        {
            zmqpp::message msg;
            from->receive(msg);
            to->send(msg);
        }
    }
    return 0;
}

void ZmqListener::subscribe(std::string& keyword)
{
    from->subscribe(keyword);
}

void ZmqListener::unsubscribe(std::string& keyword)
{
    from->unsubscribe(keyword);
}
