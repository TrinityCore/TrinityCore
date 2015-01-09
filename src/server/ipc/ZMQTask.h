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

#ifndef __ZMQTASK_H
#define __ZMQTASK_H

#include "Define.h"
#include <thread>
#include <zmqpp/poller.hpp>
#include <zmqpp/socket.hpp>

/*
  This class serves as a base for all long running tasks
  It is set up to terminate its running task upon receiving "kill" command
*/
class ZMQTask
{
public:
    ZMQTask();
    virtual ~ZMQTask();

    void Start();
    void End();
    virtual void Run() = 0;

protected:
    virtual void HandleOpen() { }
    virtual void HandleClose() { }
    void Pipeline(zmqpp::socket* from, zmqpp::socket* to);
    bool ProcessExit();

    zmqpp::poller* _poller;

    zmqpp::socket* _inproc = nullptr;
    std::thread* _thread = nullptr;
};

#endif // __ZMQTASK_H
