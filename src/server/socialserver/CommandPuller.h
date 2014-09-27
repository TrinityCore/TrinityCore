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

#ifndef __COMMANDPULLER_H
#define __COMMANDPULLER_H

#include "ZMQTask.h"
#include <zmqpp/zmqpp.hpp>

/*
  This class serves as main message broker, and task enqueuer.
  Every social event broadcasted is received by puller, and then
  pushed down the work_queue socket, where one of worker threads receive it.
  After processing worker thread sends ready message to work_res queue.
  When received, it will be broadcasted via broadcast socket.
*/
class CommandPuller : public ZMQTask
{
public:
    CommandPuller();
    ~CommandPuller();

    int svc();

protected:
    int HandleOpen();
    int HandleClose(u_long flags = 0);

private:
    //PULL socket for nodes to announce events
    zmqpp::socket* commands;

    //PUB socket for broadcasting events
    zmqpp::socket* broadcast;

    //IPC PUSH socket for enqueuing work
    zmqpp::socket* work_queue;

    //IPC PULL socket for work results
    zmqpp::socket* work_res;
};

#endif // __COMMANDPULLER_H
