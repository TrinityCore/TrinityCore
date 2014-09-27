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

#ifndef __ZMQWORKER_H
#define __ZMQWORKER_H

#include "ZMQTask.h"
#include <zmqpp/zmqpp.hpp>

class ZmqWorker : public ZMQTask
{
public:
    ZmqWorker(std::string task_uri, std::string res_uri);
    virtual ~ZmqWorker();
    int svc();
protected:
    int HandleOpen();
    int HandleClose(u_long flags = 0);
    zmqpp::socket* results;
private:
    void perform_work();
    virtual void dispatch(const zmqpp::message&) = 0;
    zmqpp::socket* task_queue;
    std::string task_uri;
    std::string res_uri;
};

#endif
