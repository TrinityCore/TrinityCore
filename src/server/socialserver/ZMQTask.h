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

#ifndef __ZMQTASK_H
#define __ZMQTASK_H

#include "Define.h"
#include <ace/Task.h>
#include <zmqpp/poller.hpp>
#include <zmqpp/socket.hpp>

class ZMQTask : public ACE_Task_Base
{
public:
    ZMQTask();
    virtual ~ZMQTask();

    int open(void* data);
    int close(u_long flags = 0);
    virtual int svc() = 0;

protected:
    bool process_exit();

    virtual int HandleOpen(zmqpp::context const* ctx) = 0;
    virtual int HandleClose(u_long flags = 0) = 0;

    zmqpp::poller* poller;

    zmqpp::socket* inproc;

private:
    static ACE_Atomic_Op<ACE_Thread_Mutex, bool> _closed;
};

#endif // __ZMQTASK_H