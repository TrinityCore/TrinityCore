/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef __ZMQMUX_H
#define __ZMQMUX_H

#include "ZMQTask.h"
#include <string>
#include <boost/thread/tss.hpp>

/*
 * Multiplexes zmq messages from many threads, 
 * and then passes them to another socket.
 */
class ZmqMux : public ZMQTask
{
public:
    ZmqMux(std::string from, std::string to);
    ~ZmqMux();
    bool Send(zmqpp::message*, bool dont_block = false);
    void Run() override;

protected:
    void HandleOpen() override;

private:
    boost::thread_specific_ptr<zmqpp::socket> _socket;
    zmqpp::socket* _from;
    zmqpp::socket* _to;
    std::string const _fromAddress;
};

#endif
