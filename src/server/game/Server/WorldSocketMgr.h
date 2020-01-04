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

/** \addtogroup u2w User to World Communication
 *  @{
 *  \file WorldSocketMgr.h
 *  \author Derex <derex101@gmail.com>
 */

#ifndef __WORLDSOCKETMGR_H
#define __WORLDSOCKETMGR_H

#include "SocketMgr.h"

class WorldSocket;

/// Manages all sockets connected to peers and network threads
class TC_GAME_API WorldSocketMgr : public SocketMgr<WorldSocket>
{
    typedef SocketMgr<WorldSocket> BaseSocketMgr;

public:
    ~WorldSocketMgr();

    static WorldSocketMgr& Instance();

    /// Start network, listen at address:port .
    bool StartWorldNetwork(Trinity::Asio::IoContext& ioContext, std::string const& bindIp, uint16 port, int networkThreads);

    /// Stops all network threads, It will wait for all running threads .
    void StopNetwork() override;

    void OnSocketOpen(tcp::socket&& sock, uint32 threadIndex) override;

    std::size_t GetApplicationSendBufferSize() const { return _socketApplicationSendBufferSize; }

protected:
    WorldSocketMgr();

    NetworkThread<WorldSocket>* CreateThreads() const override;

private:
    AsyncAcceptor* _instanceAcceptor;
    int32 _socketSystemSendBufferSize;
    int32 _socketApplicationSendBufferSize;
    bool _tcpNoDelay;
};

#define sWorldSocketMgr WorldSocketMgr::Instance()

#endif
/// @}
