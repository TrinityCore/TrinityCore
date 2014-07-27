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

// Forward declare buffer function here - Socket.h must know about it
struct WorldPacketBuffer;
namespace boost
{
    namespace asio
    {
        WorldPacketBuffer const& buffer(WorldPacketBuffer const& buf);
    }
}

#include "Common.h"
#include "WorldPacketCrypt.h"
#include "ServerPktHeader.h"
#include "Socket.h"
#include "Util.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include <chrono>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/buffer.hpp>

using boost::asio::ip::tcp;

#pragma pack(push, 1)

struct ClientPktHeader
{
    uint16 size;
    uint32 cmd;
};

#pragma pack(pop)

struct WorldPacketBuffer
{
    typedef boost::asio::const_buffer value_type;

    typedef boost::asio::const_buffer const* const_iterator;

    WorldPacketBuffer(ServerPktHeader header, WorldPacket&& packet) : _header(header), _packet(std::move(packet))
    {
        _buffers[0] = boost::asio::const_buffer(_header.header, _header.getHeaderLength());
        if (!_packet.empty())
            _buffers[1] = boost::asio::const_buffer(_packet.contents(), _packet.size());
    }

    const_iterator begin() const
    {
        return _buffers;
    }

    const_iterator end() const
    {
        return _buffers + (_packet.empty() ? 1 : 2);
    }

private:
    boost::asio::const_buffer _buffers[2];
    ServerPktHeader _header;
    WorldPacket _packet;
};

namespace boost
{
    namespace asio
    {
        inline WorldPacketBuffer const& buffer(WorldPacketBuffer const& buf)
        {
            return buf;
        }
    }
}

class WorldSocket : public Socket<WorldSocket, WorldPacketBuffer>
{
    typedef Socket<WorldSocket, WorldPacketBuffer> Base;

public:
    WorldSocket(tcp::socket&& socket);

    WorldSocket(WorldSocket const& right) = delete;
    WorldSocket& operator=(WorldSocket const& right) = delete;

    void Start() override;

    using Base::AsyncWrite;
    void AsyncWrite(WorldPacket& packet);

protected:
    void ReadHeaderHandler(boost::system::error_code error, size_t transferedBytes) override;
    void ReadDataHandler(boost::system::error_code error, size_t transferedBytes) override;

private:
    void HandleSendAuthSession();
    void HandleAuthSession(WorldPacket& recvPacket);
    void SendAuthResponseError(uint8 code);

    void HandlePing(WorldPacket& recvPacket);

    uint32 _authSeed;
    WorldPacketCrypt _authCrypt;

    std::chrono::steady_clock::time_point _LastPingTime;
    uint32 _OverSpeedPings;

    WorldSession* _worldSession;
};

#endif
