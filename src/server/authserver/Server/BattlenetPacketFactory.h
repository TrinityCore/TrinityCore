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

#ifndef BattlenetPacketFactory_h__
#define BattlenetPacketFactory_h__

#include "BattlenetPackets.h"
#include <map>

namespace Battlenet
{
    class PacketFactory
    {
        typedef ClientPacket*(*PacketCreateFn)(PacketHeader const& header, BitStream& stream);

    public:
        ClientPacket* Create(PacketHeader const& header, BitStream& stream)
        {
            auto creator = _creators.find(header);
            if (creator == _creators.end())
                return nullptr;

            ClientPacket* packet = creator->second(header, stream);
            packet->Read();
            return packet;
        }

        static PacketFactory& Instance()
        {
            static PacketFactory instance;
            return instance;
        }

    private:
        PacketFactory()
        {
            _creators[PacketHeader(Authentication::CMSG_LOGON_REQUEST, AUTHENTICATION)] = &New<Authentication::LogonRequest>;
            _creators[PacketHeader(Authentication::CMSG_RESUME_REQUEST, AUTHENTICATION)] = &New<Authentication::ResumeRequest>;
            _creators[PacketHeader(Authentication::CMSG_PROOF_RESPONSE, AUTHENTICATION)] = &New<Authentication::ProofResponse>;

            _creators[PacketHeader(Connection::CMSG_PING, CONNECTION)] = &New<Connection::Ping>;
            _creators[PacketHeader(Connection::CMSG_ENABLE_ENCRYPTION, CONNECTION)] = &New<Connection::EnableEncryption>;
            _creators[PacketHeader(Connection::CMSG_LOGOUT_REQUEST, CONNECTION)] = &New<Connection::LogoutRequest>;

            _creators[PacketHeader(WoWRealm::CMSG_LIST_SUBSCRIBE_REQUEST, WOWREALM)] = &New<WoWRealm::ListSubscribeRequest>;
            _creators[PacketHeader(WoWRealm::CMSG_JOIN_REQUEST_V2, WOWREALM)] = &New<WoWRealm::JoinRequestV2>;
        }

        template<class PacketType>
        static ClientPacket* New(PacketHeader const& header, BitStream& stream)
        {
            return new PacketType(header, stream);
        }

        std::map<PacketHeader, PacketCreateFn> _creators;
    };
}

#define sBattlenetPacketFactory Battlenet::PacketFactory::Instance()

#endif // BattlenetPacketFactory_h__
