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

#include "ZmqContext.h"

ZmqContext::ZmqContext() : _inproc(nullptr)
{
}

ZmqContext::~ZmqContext()
{
}

ZmqContext* ZmqContext::Instance()
{
    static ZmqContext instance;
    return &instance;
}

zmqpp::socket* ZmqContext::CreateNewSocket(zmqpp::socket_type type)
{
    std::unique_lock<std::mutex> lock(_mutex);
    zmqpp::socket* socket = new zmqpp::socket(_context, type);
    socket->set(zmqpp::socket_option::linger, 0);
    return socket;
}

void ZmqContext::Initialize()
{
    _inproc = new zmqpp::socket(_context, zmqpp::socket_type::pub);
    _inproc->bind("inproc://workers");
}

zmqpp::socket* ZmqContext::CreateInprocSubscriber()
{
    zmqpp::socket* sub = CreateNewSocket(zmqpp::socket_type::sub);
    sub->connect("inproc://workers");
    sub->subscribe("internalmq.");
    return sub;
}

void ZmqContext::Close()
{
    _inproc->send("internalmq.kill");
    delete _inproc;
    _inproc = nullptr;
}
