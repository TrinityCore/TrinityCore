/*
 * Copyright (C) 2008-2019 TrinityCore <http://www.trinitycore.org/>
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

#ifndef AuthenticationPacketsWorld_h__
#define AuthenticationPacketsWorld_h__

#include "Packet.h"
#include "ObjectMgr.h"
#include "Util.h"
#include "BigNumber.h"
#include "SHA1.h"
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;

namespace WorldPackets
{
    namespace Auth
    {
        class AuthSession final : public ClientPacket
        {
        public:
            AuthSession(WorldPacket&& packet) : ClientPacket(CMSG_AUTH_SESSION, std::move(packet))
            {
                memset(Digest, 0, SHA_DIGEST_LENGTH);
            }

            void Read() override;

            uint32 BattlegroupID = 0;
            int8 LoginServerType = 0;           ///< Auth type used - 0 GRUNT, 1 battle.net
            int8 BuildType = 0;
            uint32 RealmID = 0;
            uint16 Build = 0;
            uint32 LocalChallenge = 0;
            int32 LoginServerID = 0;
            uint32 RegionID = 0;
            uint64 DosResponse = 0;
            uint8 Digest[SHA_DIGEST_LENGTH];
            std::string Account;
            bool UseIPv6 = false;
            ByteBuffer AddonInfo;
        };

        class AuthContinuedSession final : public ClientPacket
        {
        public:
            AuthContinuedSession(WorldPacket&& packet) : ClientPacket(CMSG_AUTH_CONTINUED_SESSION, std::move(packet))
            {
                memset(Digest, 0, SHA_DIGEST_LENGTH);
            }

            void Read() override;

            uint64 DosResponse = 0;
            uint64 Key = 0;
            uint8 Digest[SHA_DIGEST_LENGTH];
        };

        class ResumeComms final : public ServerPacket
        {
        public:
            ResumeComms(ConnectionType connection) : ServerPacket(SMSG_RESUME_COMMS, 0, connection) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        enum class ConnectToSerial : uint32
        {
            None            = 0,
            Realm           = 14,
            WorldAttempt1   = 17,
            WorldAttempt2   = 35,
            WorldAttempt3   = 53,
            WorldAttempt4   = 71,
            WorldAttempt5   = 89
        };

        class ConnectTo final : public ServerPacket
        {
            static std::string const Haiku;
            static uint8 const PiDigits[142];

            struct ConnectPayload
            {
                tcp::endpoint Where;
                uint32 Adler32 = 0;
                uint8 XorMagic = 0x2A;
            };

        public:
            ConnectTo();

            WorldPacket const* Write() override;

            uint64 Key = 0;
            ConnectToSerial Serial = ConnectToSerial::None;
            ConnectPayload Payload;
            uint8 Con = 0;

        private:
            BigNumber p;
            BigNumber q;
            BigNumber dmp1;
            BigNumber dmq1;
            BigNumber iqmp;
        };
    }
}

#endif // AuthenticationPacketsWorld_h__
