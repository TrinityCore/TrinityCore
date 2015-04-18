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
#include "Util.h"
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
                ByteBuffer* AddonInfo;
        };

        class AuthResponse final : public ServerPacket
        {
            public:
                struct AuthSuccessInfo
                {
                    uint32 TimeRemain = 0; ///< the remaining game time that the account has in seconds. It is not currently implemented and probably won't ever be.
                    uint8 AccountExpansionLevel = 0; ///< the current expansion of this account, the possible values are in @ref Expansions
                    uint32 TimeRested = 0; ///< affects the return value of the GetBillingTimeRested() client API call, it is the number of seconds you have left until the experience points and loot you receive from creatures and quests is reduced. It is only used in the Asia region in retail, it's not implemented in TC and will probably never be.
                    uint8 TimeOptions = 0; ///< controls the behavior of the client regarding billing, used in Asia realms, as they don't have monthly subscriptions, possible values are in @ref BillingPlanFlags. It is not currently implemented and will probably never be.
                };

                struct AuthWaitInfo
                {
                    uint32 WaitCount = 0; ///< position of the account in the login queue
                    bool HasFCM = false; ///< true if the account has a forced character migration pending. @todo implement
                };

                AuthResponse();

                WorldPacket const* Write() override;

                Optional<AuthSuccessInfo> SuccessInfo; ///< contains the packet data in case that it has account information (It is never set when WaitInfo is set), otherwise its contents are undefined.
                Optional<AuthWaitInfo> WaitInfo; ///< contains the queue wait information in case the account is in the login queue.
                uint8 Result = 0; ///< the result of the authentication process, it is AUTH_OK if it succeeded and the account is ready to log in. It can also be AUTH_WAIT_QUEUE if the account entered the login queue (Queued, QueuePos), possible values are @ref ResponseCodes
        };

        class Ping final : public ClientPacket
        {
            public:
                Ping(WorldPacket&& packet) : ClientPacket(CMSG_PING, std::move(packet)) { }

                void Read() override;

                uint32 PingID;
                uint32 Latency;
        };

        class Pong final : public ServerPacket
        {
            public:
                Pong();

                WorldPacket const* Write() override;

                uint32 PingID;
        };
    }
}

#endif
