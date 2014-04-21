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
    std::string nodeIp;
    uint16 nodePort;
    uint16 command;

    msg.get(nodeIp, 0);
    msg.get(nodePort, 1);
    msg.get(command, 2);
    printf("Worker received command %u from %s:%hu\n", command, nodeIp.c_str(), nodePort);
    if (command >= OPCODES_MAX)
        return;

    (this->*handlers[command])(msg, { nodeIp, nodePort });
}

void Worker::HandleBroadcastPacket(zmqpp::message const& msg, RedirectInfo const& sourceNode)
{
    results->send(const_cast<zmqpp::message&>(msg));
}

const opcode_handler handlers[OPCODES_MAX] = {
    &Worker::HandleBroadcastPacket,
    &Worker::HandleBroadcastPacket,
};
