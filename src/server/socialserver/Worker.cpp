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

#include "Worker.h"
#include "ZmqContext.h"

void Worker::dispatch(const zmqpp::message& msg)
{
    uint32 source;
    uint16 command;

    msg.get(source, 0);
    msg.get(command, 1);

    printf("Worker received command %u from %u\n", command, source);
    if (command >= OPCODES_MAX)
        return;

    (this->*handlers[command])(msg);
}

void Worker::HandleBroadcastPacket(zmqpp::message const& msg)
{
    zmqpp::message m = msg.copy();
    m.push_front(0xFFFFFFFF);
    results->send(const_cast<zmqpp::message&>(m));
}

const opcode_handler handlers[OPCODES_MAX] = {
    &Worker::HandleBroadcastPacket,
    &Worker::HandleBroadcastPacket,
};
