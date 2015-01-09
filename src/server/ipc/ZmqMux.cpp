/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

ZmqMux::ZmqMux(std::string const& fromUri, std::string const& toUri):
    _fromAddress(fromUri)
{
    printf("Opening muxer thread from %s to %s\n", fromUri.c_str(), toUri.c_str());
    _from = sIpcContext->CreateNewSocket(zmqpp::socket_type::pull);
    _to = sIpcContext->CreateNewSocket(zmqpp::socket_type::push);

    _from->bind(fromUri);
    _to->connect(toUri);
}

ZmqMux::~ZmqMux()
{
    delete _from;
    delete _to;
}

void ZmqMux::HandleOpen()
{
    _poller->add(*_from);
    _poller->add(*_to, zmqpp::poller::poll_out);
}

bool ZmqMux::Send(zmqpp::message* m, bool dont_block)
{
    if (_socket.get() == nullptr)
    {
        _socket.reset(sIpcContext->CreateNewSocket(zmqpp::socket_type::push));
        _socket->connect(_fromAddress);
    }

    return _socket->send(*m, dont_block);
}

void ZmqMux::Run()
{
    for (;;)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        if (!_poller->poll())
            break;

        if (ProcessExit())
            break;

        Pipeline(_from, _to);
    }
}
