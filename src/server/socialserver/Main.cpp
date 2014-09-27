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
#include "CommandPuller.h"
#include "Worker.h"
#include <zmqpp/zmqpp.hpp>
#include "ZmqContext.h"


int main(int /*argc*/, char** /*argv*/)
{
    zmqpp::context ctx;
    zmqpp::socket *inproc = sContext->newSocket(zmqpp::socket_type::pub);
    inproc->bind("inproc://workers");

    CommandPuller puller;
    Worker worker("inproc://work_queue", "inproc://work_result");

    puller.open(&ctx);
    worker.open(&ctx);

    //    puller.wait();
    delete inproc;
    return 0;
}
