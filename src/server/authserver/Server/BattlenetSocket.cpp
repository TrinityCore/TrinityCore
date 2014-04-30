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

#include "AuthCodes.h"
#include "BattlenetBitStream.h"
#include "BattlenetPackets.h"
#include "BattlenetSocket.h"
#include <map>

bool Battlenet::Socket::HandleAuthChallenge(PacketHeader& header, BitStream& packet)
{
    AuthChallenge info(header, packet);
    info.Read();

    printf("%s\n", info.ToString().c_str());

    _accountName = info.Login;

    ProofRequest request;
    request.Write();
    _socket.send((char const*)request.GetData(), request.GetSize());
    return true;
}

bool Battlenet::Socket::HandleAuthProofResponse(PacketHeader& header, BitStream& packet)
{
    ProofResponse response(header, packet);
    response.Read();

    printf("%s\n", response.ToString().c_str());

    AuthComplete complete;
    complete.ErrorType = 1;
    complete.AuthResult = AUTH_USE_GRUNT_LOGON;
    complete.Write();
    _socket.send((char const*)complete.GetData(), complete.GetSize());
    return true;
}

std::map<Battlenet::PacketHeader, Battlenet::Socket::PacketHandler> InitHandlers()
{
    std::map<Battlenet::PacketHeader, Battlenet::Socket::PacketHandler> handlers;

    handlers[Battlenet::PacketHeader(Battlenet::CMSG_AUTH_CHALLENGE, Battlenet::AUTHENTICATION)] = &Battlenet::Socket::HandleAuthChallenge;
    handlers[Battlenet::PacketHeader(Battlenet::CMSG_AUTH_PROOF_RESPONSE, Battlenet::AUTHENTICATION)] = &Battlenet::Socket::HandleAuthProofResponse;

    return handlers;
}

std::map<Battlenet::PacketHeader, Battlenet::Socket::PacketHandler> Handlers = InitHandlers();

Battlenet::Socket::Socket(RealmSocket& socket) : _socket(socket), _currentChannel(0)
{
}

void Battlenet::Socket::OnRead()
{
    while (1)
    {
        size_t length = _socket.recv_len();
        if (!length)
            return;

        BitStream packet(length);
        if (!_socket.recv((char*)packet.GetBuffer(), length))
            return;

        while (!packet.IsRead())
        {
            try
            {
                PacketHeader header;
                header.Opcode = packet.Read<uint32>(6);
                if (packet.Read<uint32>(1))
                    _currentChannel = header.Channel = packet.Read<int32>(4);

                printf("Battlenet::Socket::OnRead %s\n", header.ToString().c_str());
                std::map<PacketHeader, PacketHandler>::const_iterator itr = Handlers.find(header);
                if (itr != Handlers.end())
                {
                    if (!(this->*(itr->second))(header, packet))
                    {
                        _socket.shutdown();
                        return;
                    }
                }
                else
                    printf("Battlenet::Socket::OnRead Unhandled opcode %s\n", header.ToString().c_str());

                packet.AlignToNextByte();
            }
            catch (BitStreamPositionException const& e)
            {
                printf("Battlenet::Socket::OnRead Exception: %s\n", e.what());
                _socket.shutdown();
                return;
            }
        }
    }
}

void Battlenet::Socket::OnAccept()
{
    printf("Battlenet::Socket::OnAccept\n");
}

void Battlenet::Socket::OnClose()
{
    printf("Battlenet::Socket::OnClose\n");
}
