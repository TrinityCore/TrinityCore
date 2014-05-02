/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef _BATTLENETSOCKET_H
#define _BATTLENETSOCKET_H

#include "RealmSocket.h"
#include "BattlenetPackets.h"
#include "BattlenetPacketCrypt.h"

namespace Battlenet
{
    struct PacketHeader;
    class BitStream;

    class Socket : public RealmSocket::Session
    {
    public:
        Socket(RealmSocket& socket);

        typedef bool(Socket::*PacketHandler)(PacketHeader& socket, BitStream& packet);

        bool HandleAuthChallenge(PacketHeader& header, BitStream& packet);
        bool HandleAuthProofResponse(PacketHeader& header, BitStream& packet);

        void OnRead() override;
        void OnAccept() override;
        void OnClose() override;

        void Send(ServerPacket& packet);

    private:
        RealmSocket& _socket;
        uint32 _currentChannel;

        std::string _accountName;
        std::string _locale;
        std::string _os;

        PacketCrypt _crypt;
    };

}

#endif // _BATTLENETSOCKET_H
