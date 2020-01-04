/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

ZmqListener::ZmqListener(std::string const& from, std::string const& to)
{
    _from = sIpcContext->CreateNewSocket(zmqpp::socket_type::sub);
    _to = sIpcContext->CreateNewSocket(zmqpp::socket_type::push);
    _from->connect(from);
    _to->bind(to);
}

ZmqListener::~ZmqListener()
{
    delete _from;
    delete _to;
}

void ZmqListener::HandleOpen()
{
}

void ZmqListener::HandleClose()
{
    _from->close();
    _to->close();
}

void ZmqListener::Run()
{
    while (!ProcessExit())
    {
        _poller->poll();

        while (_poller->events(*_from) & zmqpp::poller::poll_in &&
              _poller->events(*_to) & zmqpp::poller::poll_out)
        {
            zmqpp::message msg;
            _from->receive(msg);
            _to->send(msg);
        }
    }
}

void ZmqListener::Subscribe(std::string const& keyword)
{
    _from->subscribe(keyword);
}

void ZmqListener::Unsubscribe(std::string const& keyword)
{
    _from->unsubscribe(keyword);
}
