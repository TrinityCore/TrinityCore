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

#ifndef __ZMQCONTEX_H
#define __ZMQCONTEX_H

#include <zmqpp/zmqpp.hpp>
#include <boost/thread/mutex.hpp>

/*
 * We need to serialize access to zmq context otherwise stuff blows up.
 */
class ZmqContext {

public:
    zmqpp::socket* newSocket(zmqpp::socket_type);
    ZmqContext() {}
private:
    ZmqContext(ZmqContext&){}
    zmqpp::context ctx;
    boost::mutex mtx;
};
static ZmqContext *sContext = new ZmqContext(); 

#endif
