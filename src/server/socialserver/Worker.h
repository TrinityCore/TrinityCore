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

#ifndef __WORKER_H
#define __WORKER_H

#include "ZMQTask.h"
#include <zmqpp/zmqpp.hpp>

class Worker;

enum Operations
{
    TEST,
    OPCODES_MAX
};

typedef void (Worker::*opcode_handler)(const zmqpp::message&);

extern const opcode_handler handlers[OPCODES_MAX];

class Worker : public ZMQTask
{
public:
    Worker();
    ~Worker();
    int svc();
    void test_handler(const zmqpp::message&);
protected:
    int HandleOpen(zmqpp::context const* ctx) OVERRIDE;
    int HandleClose(u_long flags = 0) OVERRIDE;
private:
    void perform_work();
    void dispatch(const zmqpp::message&);
    zmqpp::socket* task_queue;
    zmqpp::socket* results;
};

#endif
