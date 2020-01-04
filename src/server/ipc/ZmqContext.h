/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Common.h"
#include <zmqpp/zmqpp.hpp>
#include <mutex>

/*
 * We need to serialize access to zmq context otherwise stuff blows up.
 */
class TC_IPC_API ZmqContext
{
public:
    static ZmqContext* Instance();

    ~ZmqContext();

    zmqpp::socket* CreateNewSocket(zmqpp::socket_type);
    void Initialize();
    zmqpp::socket* CreateInprocSubscriber();
    void Close();

private:
    ZmqContext();
    ZmqContext(ZmqContext const&) = delete;
    ZmqContext& operator=(ZmqContext const&) = delete;

    zmqpp::context _context;
    std::mutex _mutex;
    zmqpp::socket* _inproc;
};

#define sIpcContext ZmqContext::Instance()

#endif
