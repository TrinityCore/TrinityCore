/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "Common.h"
#include "BigNumber.h"
#include "SHA1.h"
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;

namespace WorldPackets
{
    namespace Auth
    {
        class AuthChallenge final : public ServerPacket
        {
        public:
            AuthChallenge() : ServerPacket(SMSG_AUTH_CHALLENGE, 4 + 32 + 1) { }

            WorldPacket const* Write() override;

            uint32 Challenge = 0;
            uint32 DosChallenge[8]; ///< Encryption seeds
            uint8 DosZeroBits = 0;
        };

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

        class AuthResponse final : public ServerPacket
        {
        public:
            struct RealmInfo
            {
                RealmInfo(uint32 realmAddress, bool isHomeRealm, bool isInternalRealm, std::string const& realmNameActual, std::string const& realmNameNormalized) :
                    RealmAddress(realmAddress), IsLocal(isHomeRealm), IsInternalRealm(isInternalRealm), RealmNameActual(realmNameActual), RealmNameNormalized(realmNameNormalized) { }

                uint32 RealmAddress;             ///< the virtual address of this realm, constructed as RealmHandle::Region << 24 | RealmHandle::Battlegroup << 16 | RealmHandle::Index
                bool IsLocal;                    ///< true if the realm is the same as the account's home realm
                bool IsInternalRealm;            ///< @todo research
                std::string RealmNameActual;     ///< the name of the realm
                std::string RealmNameNormalized; ///< the name of the realm without spaces
            };

            struct AuthSuccessInfo
            {
                uint32 TimeRemain = 0; ///< the remaining game time that the account has in seconds. It is not currently implemented and probably won't ever be.
                uint8 AccountExpansionLevel = 0; ///< the current expansion of this account, the possible values are in @ref Expansions
                uint8 ActiveExpansionLevel = 0; ///< the current server expansion, the possible values are in @ref Expansions
                uint32 TimeRested = 0; ///< affects the return value of the GetBillingTimeRested() client API call, it is the number of seconds you have left until the experience points and loot you receive from creatures and quests is reduced. It is only used in the Asia region in retail, it's not implemented in TC and will probably never be.
                uint8 TimeOptions = 0; ///< controls the behavior of the client regarding billing, used in Asia realms, as they don't have monthly subscriptions, possible values are in @ref BillingPlanFlags. It is not currently implemented and will probably never be.

                uint32 VirtualRealmAddress = 0; ///< a special identifier made from the Index, BattleGroup and Region.
                uint32 RealmNamesCount = 0; ///< the number of realms connected to this one (inclusive). @todo implement
                uint32 TimeSecondsUntilPCKick = 0; ///< @todo research
                uint32 CurrencyID = 0; ///< this is probably used for the ingame shop. @todo implement

                std::vector<RealmInfo> VirtualRealms;     ///< list of realms connected to this one (inclusive) @todo implement
                std::vector<CharacterTemplate> Templates; ///< list of pre-made character templates.

                ExpansionRequirementContainer const* AvailableClasses = nullptr; ///< the minimum AccountExpansion required to select the classes
                ExpansionRequirementContainer const* AvailableRaces = nullptr; ///< the minimum AccountExpansion required to select the races

                bool IsExpansionTrial = false;
                bool ForceCharacterTemplate = false; ///< forces the client to always use a character template when creating a new character. @see Templates. @todo implement
                Optional<uint16> NumPlayersHorde; ///< number of horde players in this realm. @todo implement
                Optional<uint16> NumPlayersAlliance; ///< number of alliance players in this realm. @todo implement
                bool IsVeteranTrial = false; ///< @todo research
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
            static uint8 const PiDigits[130];

            struct ConnectPayload
            {
                tcp::endpoint Where;
                uint32 Adler32 = 0;
                uint8 XorMagic = 0x2A;
                uint8 PanamaKey[32];
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

        class ConnectToFailed final : public ClientPacket
        {
        public:
            ConnectToFailed(WorldPacket&& packet) : ClientPacket(CMSG_CONNECT_TO_FAILED, std::move(packet)) { }

            void Read() override;

            ConnectToSerial Serial = ConnectToSerial::None;
            uint8 Con = 0;
        };
    }
}

#endif // AuthenticationPacketsWorld_h__
