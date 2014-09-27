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

#ifndef __HEARTBEATBROKER_H
#define __HEARTBEATBROKER_H

#include "ZMQTask.h"
#include <zmqpp/zmqpp.hpp>

/*
  This object's only role is to send heartbeat every second to nodes.
  That's it, really.
*/
class HeartbeatBroker : public ZMQTask
{
public:
    HeartbeatBroker();
    ~HeartbeatBroker();

    int svc();

protected:
    int HandleOpen();
    int HandleClose(u_long flags = 0);

private:
    zmqpp::socket* sock;
};

#endif // __HEARTBEATBROKER_H
