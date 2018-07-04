/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Define.h"
#include "Optional.h"
#include <array>
#include <unordered_map>

struct CharacterTemplate;

namespace WorldPackets
{
    namespace Auth
    {
        class EarlyProcessClientPacket : public ClientPacket
        {
        public:
            EarlyProcessClientPacket(OpcodeClient opcode, WorldPacket&& packet) : ClientPacket(opcode, std::move(packet)) { }

            bool ReadNoThrow();
        };

        class Ping final : public EarlyProcessClientPacket
        {
        public:
            Ping(WorldPacket&& packet) : EarlyProcessClientPacket(CMSG_PING, std::move(packet)) { }

            uint32 Serial = 0;
            uint32 Latency = 0;

        private:
            void Read();
        };

        class Pong final : public ServerPacket
        {
        public:
            Pong(uint32 serial) : ServerPacket(SMSG_PONG, 4), Serial(serial) { }

            WorldPacket const* Write() override;

            uint32 Serial = 0;
        };

        class AuthChallenge final : public ServerPacket
        {
        public:
            AuthChallenge() : ServerPacket(SMSG_AUTH_CHALLENGE, 4 + 32 + 1) { }

            WorldPacket const* Write() override;

            std::array<uint8, 16> Challenge = { };
            uint32 DosChallenge[8] = { }; ///< Encryption seeds
            uint8 DosZeroBits = 0;
        };

        class AuthSession final : public EarlyProcessClientPacket
        {
        public:
            static uint32 const DigestLength = 24;

            AuthSession(WorldPacket&& packet) : EarlyProcessClientPacket(CMSG_AUTH_SESSION, std::move(packet))
            {
                LocalChallenge.fill(0);
                Digest.fill(0);
            }

            uint16 Build = 0;
            int8 BuildType = 0;
            uint32 RegionID = 0;
            uint32 BattlegroupID = 0;
            uint32 RealmID = 0;
            std::array<uint8, 16> LocalChallenge;
            std::array<uint8, DigestLength> Digest;
            uint64 DosResponse = 0;
            std::string RealmJoinTicket;
            bool UseIPv6 = false;

        private:
            void Read() override;
        };

        struct AuthWaitInfo
        {
            uint32 WaitCount = 0; ///< position of the account in the login queue
            uint32 WaitTime = 0; ///< Wait time in login queue in minutes, if sent queued and this value is 0 client displays "unknown time"
            bool HasFCM = false; ///< true if the account has a forced character migration pending. @todo implement
        };

        struct VirtualRealmNameInfo
        {
            VirtualRealmNameInfo() : IsLocal(false), IsInternalRealm(false) { }
            VirtualRealmNameInfo(bool isHomeRealm, bool isInternalRealm, std::string const& realmNameActual, std::string const& realmNameNormalized) :
                IsLocal(isHomeRealm), IsInternalRealm(isInternalRealm), RealmNameActual(realmNameActual), RealmNameNormalized(realmNameNormalized) { }

            bool IsLocal;                    ///< true if the realm is the same as the account's home realm
            bool IsInternalRealm;            ///< @todo research
            std::string RealmNameActual;     ///< the name of the realm
            std::string RealmNameNormalized; ///< the name of the realm without spaces
        };

        struct VirtualRealmInfo
        {
            VirtualRealmInfo(uint32 realmAddress, bool isHomeRealm, bool isInternalRealm, std::string const& realmNameActual, std::string const& realmNameNormalized) :
                RealmAddress(realmAddress), RealmNameInfo(isHomeRealm, isInternalRealm, realmNameActual, realmNameNormalized) { }

            uint32 RealmAddress;             ///< the virtual address of this realm, constructed as RealmHandle::Region << 24 | RealmHandle::Battlegroup << 16 | RealmHandle::Index
            VirtualRealmNameInfo RealmNameInfo;
        };

        class AuthResponse final : public ServerPacket
        {
        public:
            struct AuthSuccessInfo
            {
                struct BillingInfo
                {
                    uint32 BillingPlan = 0;
                    uint32 TimeRemain = 0;
                    uint32 Unknown735 = 0;
                    bool InGameRoom = false;
                };

                uint8 AccountExpansionLevel = 0; ///< the current expansion of this account, the possible values are in @ref Expansions
                uint8 ActiveExpansionLevel = 0; ///< the current server expansion, the possible values are in @ref Expansions
                uint32 TimeRested = 0; ///< affects the return value of the GetBillingTimeRested() client API call, it is the number of seconds you have left until the experience points and loot you receive from creatures and quests is reduced. It is only used in the Asia region in retail, it's not implemented in TC and will probably never be.

                uint32 VirtualRealmAddress = 0; ///< a special identifier made from the Index, BattleGroup and Region.
                uint32 TimeSecondsUntilPCKick = 0; ///< @todo research
                uint32 CurrencyID = 0; ///< this is probably used for the ingame shop. @todo implement
                int32 Time = 0;

                BillingInfo Billing;

                std::vector<VirtualRealmInfo> VirtualRealms;     ///< list of realms connected to this one (inclusive) @todo implement
                std::vector<CharacterTemplate const*> Templates; ///< list of pre-made character templates.

                std::unordered_map<uint8, uint8> const* AvailableClasses = nullptr; ///< the minimum AccountExpansion required to select the classes

                bool IsExpansionTrial = false;
                bool ForceCharacterTemplate = false; ///< forces the client to always use a character template when creating a new character. @see Templates. @todo implement
                Optional<uint16> NumPlayersHorde; ///< number of horde players in this realm. @todo implement
                Optional<uint16> NumPlayersAlliance; ///< number of alliance players in this realm. @todo implement
            };

            AuthResponse();

            WorldPacket const* Write() override;

            Optional<AuthSuccessInfo> SuccessInfo; ///< contains the packet data in case that it has account information (It is never set when WaitInfo is set), otherwise its contents are undefined.
            Optional<AuthWaitInfo> WaitInfo; ///< contains the queue wait information in case the account is in the login queue.
            uint32 Result = 0; ///< the result of the authentication process, possible values are @ref BattlenetRpcErrorCode
        };

        class WaitQueueUpdate final : public ServerPacket
        {
        public:
            WaitQueueUpdate() : ServerPacket(SMSG_WAIT_QUEUE_UPDATE, 4 + 4 + 1) { }

            WorldPacket const* Write() override;

            AuthWaitInfo WaitInfo;
        };

        class WaitQueueFinish final : public ServerPacket
        {
        public:
            WaitQueueFinish() : ServerPacket(SMSG_WAIT_QUEUE_FINISH, 0) { }

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
            static uint8 const PiDigits[130];

        public:
            static bool InitializeEncryption();

            enum AddressType : uint8
            {
                IPv4 = 1,
                IPv6 = 2
            };

            struct ConnectPayload
            {
                std::array<uint8, 16> Where;
                uint16 Port;
                AddressType Type;
                uint32 Adler32 = 0;
                uint8 XorMagic = 0x2A;
                uint8 PanamaKey[32];
            };

            ConnectTo();

            WorldPacket const* Write() override;

            uint64 Key = 0;
            ConnectToSerial Serial = ConnectToSerial::None;
            ConnectPayload Payload;
            uint8 Con = 0;
        };

        class AuthContinuedSession final : public EarlyProcessClientPacket
        {
        public:
            static uint32 const DigestLength = 24;

            AuthContinuedSession(WorldPacket&& packet) : EarlyProcessClientPacket(CMSG_AUTH_CONTINUED_SESSION, std::move(packet))
            {
                LocalChallenge.fill(0);
                Digest.fill(0);
            }

            uint64 DosResponse = 0;
            uint64 Key = 0;
            std::array<uint8, 16> LocalChallenge;
            std::array<uint8, DigestLength> Digest;

        private:
            void Read() override;
        };

        class ResumeComms final : public ServerPacket
        {
        public:
            ResumeComms(ConnectionType connection) : ServerPacket(SMSG_RESUME_COMMS, 0, connection) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };

        class ConnectToFailed final : public EarlyProcessClientPacket
        {
        public:
            ConnectToFailed(WorldPacket&& packet) : EarlyProcessClientPacket(CMSG_CONNECT_TO_FAILED, std::move(packet)) { }

            ConnectToSerial Serial = ConnectToSerial::None;
            uint8 Con = 0;

        private:
            void Read() override;
        };

        class EnableEncryption final : public ServerPacket
        {
        public:
            EnableEncryption() : ServerPacket(SMSG_ENABLE_ENCRYPTION, 0) { }

            WorldPacket const* Write() override { return &_worldPacket; }
        };
    }
}

ByteBuffer& operator<<(ByteBuffer& data, WorldPackets::Auth::VirtualRealmNameInfo const& realmInfo);

#endif // AuthenticationPacketsWorld_h__
