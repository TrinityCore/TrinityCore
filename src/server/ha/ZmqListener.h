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

#ifndef __ZMQLISTENER_H
#define __ZMQLISTENER_H

#include "ZMQTask.h"
#include <zmqpp/zmqpp.hpp>

class ZmqListener : public ZMQTask
{
/*
 * Read broadcasts from remote PUB socket, and forward them to 
 * another socket. 
 *
 * from - client SUB socket
 * to - listen PUSH socket
 *
 */
public:
    ZmqListener(std::string& from, std::string& to);
    virtual ~ZmqListener();
    int svc();
    
    int HandleOpen();
    int HandleClose(u_long);
    void subscribe(std::string& keyword);
    void unsubscribe(std::string& keyword);

private:
    zmqpp::socket* from;
    zmqpp::socket* to;
    
};

#endif
