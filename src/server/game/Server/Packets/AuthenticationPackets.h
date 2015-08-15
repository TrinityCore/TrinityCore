/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef AuthenticationPackets_h__
#define AuthenticationPackets_h__

#include "Packet.h"
#include "Common.h"
#include "SHA1.h"

namespace WorldPackets
{
    namespace Auth
    {
        class AuthChallenge final : public ServerPacket
        {
            public:
                AuthChallenge() : ServerPacket(SMSG_AUTH_CHALLENGE, 4 + 32 + 4) { }

                WorldPacket const* Write() override;

                uint32 Challenge = 0;
                uint32 DosChallenge[8]; ///< Encryption seeds
                uint32 DosZeroBits = 0;
        };

        class AuthSession final : public ClientPacket
        {
            public:
                AuthSession(WorldPacket&& packet) : ClientPacket(CMSG_AUTH_SESSION, std::move(packet)) { }

                void Read() override;

                uint32 BattlegroupID = 0;
                uint32 LoginServerType = 0;           ///< Auth type used - 0 GRUNT, 1 battle.net
                uint32 RealmID = 0;
                uint32 Build = 0;
                uint32 LocalChallenge = 0;
                uint32 LoginServerID = 0;
                uint32 RegionID = 0;
                uint64 DosResponse = 0;
                uint8 Digest[SHA_DIGEST_LENGTH];
                std::string Account;
                WorldPacket AddonInfo;
        };
    }
}

#endif
