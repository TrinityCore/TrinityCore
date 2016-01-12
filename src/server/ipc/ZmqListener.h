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
    ZmqListener(std::string const& from, std::string const& to);
    ~ZmqListener();
    void Run() override;

    void Subscribe(std::string const& keyword);
    void Unsubscribe(std::string const& keyword);

protected:
    void HandleOpen() override;
    void HandleClose() override;

private:
    zmqpp::socket* _from;
    zmqpp::socket* _to;
};

#endif
