/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef __WORLDSOCKET_H__
#define __WORLDSOCKET_H__

#include "Common.h"
#include "AuthCrypt.h"
#include "Socket.h"
#include "Util.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include <memory>
#include <chrono>
#include <mutex>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>

using boost::asio::ip::tcp;

#pragma pack(push, 1)

struct ClientPktHeader
{
    uint16 size;
    uint32 cmd;
};

#pragma pack(pop)

class WorldSocket : public Socket<WorldSocket>
{
public:
    WorldSocket(tcp::socket&& socket);

    WorldSocket(WorldSocket const& right) = delete;
    WorldSocket& operator=(WorldSocket const& right) = delete;

    void Start() override;

    void AsyncWrite(WorldPacket const& packet);

    using Socket<WorldSocket>::AsyncWrite;

protected:
    void ReadHeaderHandler(boost::system::error_code error, size_t transferedBytes) override;
    void ReadDataHandler(boost::system::error_code error, size_t transferedBytes) override;

private:
    void HandleSendAuthSession();
    void HandleAuthSession(WorldPacket& recvPacket);
    void SendAuthResponseError(uint8 code);

    void HandlePing(WorldPacket& recvPacket);

    uint32 _authSeed;
    AuthCrypt _authCrypt;

    std::chrono::steady_clock::time_point _LastPingTime;
    uint32 _OverSpeedPings;

    WorldSession* _worldSession;
};

#endif
