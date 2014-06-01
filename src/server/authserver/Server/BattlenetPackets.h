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

#ifndef __BATTLENETPACKETS_H__
#define __BATTLENETPACKETS_H__

#include "AuthCodes.h"
#include "BattlenetBitStream.h"
#include "BattlenetManager.h"
#include "Define.h"
#include "Errors.h"
#include <string>

namespace Battlenet
{
    class BitStream;

    enum Channel
    {
        AUTHENTICATION  = 0,
        CREEP           = 1,
        WOW             = 2
    };

    enum AuthOpcode
    {
        CMSG_AUTH_CHALLENGE         = 0x0,
        CMSG_AUTH_RECONNECT         = 0x1,
        CMSG_AUTH_PROOF_RESPONSE    = 0x2,

        SMSG_AUTH_COMPLETE          = 0x0,
        SMSG_AUTH_RESUME            = 0x1,
        SMSG_AUTH_PROOF_REQUEST     = 0x2
    };

    enum CreepOpcodes
    {
        CMSG_PING               = 0x0,
        CMSG_ENABLE_ENCRYPTION  = 0x5,
        CMSG_DISCONNECT         = 0x6,
        CMSG_INVALID_PACKET     = 0x9,

        SMSG_PONG               = 0x0
    };

    enum WoWOpcodes
    {
        CMSG_REALM_UPDATE_SUBSCRIBE     = 0x0,
        CMSG_REALM_UPDATE_UNSUBSCRIBE   = 0x1,
        CMSG_JOIN_REQUEST               = 0x8,

        SMSG_CHARACTER_COUNTS           = 0x0,
        SMSG_REALM_UPDATE               = 0x2,
        SMSG_REALM_UPDATE_END           = 0x3,
        SMSG_JOIN_RESULT                = 0x8
    };

    struct PacketHeader
    {
        PacketHeader(uint32 opcode, uint32 channel) : Opcode(opcode), Channel(channel) { }
        PacketHeader() : Opcode(0), Channel(AUTHENTICATION) { }

        uint32 Opcode;
        int32 Channel;

        bool operator<(PacketHeader const& right) const
        {
            if (Opcode < right.Opcode)
                return true;
            if (Opcode > right.Opcode)
                return false;

            return Channel < right.Channel;
        }

        bool operator==(PacketHeader const& right) const
        {
            return Opcode == right.Opcode && Channel == right.Channel;
        }

        std::string ToString() const;
    };

    class Packet
    {
    public:
        Packet(PacketHeader const& header, BitStream& stream) : _header(header), _stream(stream) { }
        virtual ~Packet() { }

        PacketHeader const& GetHeader() const { return _header; }

        virtual void Write() = 0;
        virtual void Read() = 0;

        virtual std::string ToString() const = 0;

    protected:
        PacketHeader _header;
        BitStream& _stream;

    private:
        Packet(Packet const& right);
        Packet& operator=(Packet const& right);
    };

    class ClientPacket : public Packet
    {
    public:
        ClientPacket(PacketHeader const& header, BitStream& stream) : Packet(header, stream) { }

        void Write() override final { ASSERT(!"Write not implemented for this packet."); }
    };

    class ServerPacket : public Packet
    {
    public:
        ServerPacket(PacketHeader const& header);
        ~ServerPacket();

        void Read() override final { ASSERT(!"Read not implemented for server packets."); }

        uint8 const* GetData() const { return _stream.GetBuffer(); }
        size_t GetSize() const { return _stream.GetSize(); }
    };

    class AuthChallenge final : public ClientPacket
    {
    public:
        AuthChallenge(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
        {
            ASSERT(header == PacketHeader(CMSG_AUTH_CHALLENGE, AUTHENTICATION) && "Invalid packet header for AuthChallenge");
        }

        void Read() override;
        std::string ToString() const override;

        std::string Program;
        std::string Platform;
        std::string Locale;
        std::vector<Component> Components;
        std::string Login;
    };

    class AuthResumeInfo final : public ClientPacket
    {
    public:
        AuthResumeInfo(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
        {
            ASSERT(header == PacketHeader(CMSG_AUTH_RECONNECT, AUTHENTICATION) && "Invalid packet header for AuthResumeInfo");
        }

        void Read() override;
        std::string ToString() const override;

        std::string Program;
        std::string Platform;
        std::string Locale;
        std::vector<Component> Components;
        std::string Login;
        uint8 Region;
        std::string GameAccountName;
    };

    class ProofRequest final : public ServerPacket
    {
    public:
        ProofRequest() : ServerPacket(PacketHeader(SMSG_AUTH_PROOF_REQUEST, AUTHENTICATION)) { }
        ~ProofRequest();

        void Write() override;
        std::string ToString() const override;

        std::vector<ModuleInfo*> Modules;
    };

    class ProofResponse final : public ClientPacket
    {
    public:
        ProofResponse(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
        {
            ASSERT(header == PacketHeader(CMSG_AUTH_PROOF_RESPONSE, AUTHENTICATION) && "Invalid packet header for ProofResponse");
        }

        ~ProofResponse();

        void Read() override;
        std::string ToString() const override;

        std::vector<BitStream*> Modules;
    };

    class AuthComplete final : public ServerPacket
    {
    public:
        AuthComplete() : ServerPacket(PacketHeader(SMSG_AUTH_COMPLETE, AUTHENTICATION)),
            Result(AUTH_OK), ErrorType(0), PingTimeout(120000), Threshold(25000000), Rate(1000),
            FirstName(""), LastName(""), GameAccountId(0), GameAccountName("")
        {
        }

        ~AuthComplete();

        void Write() override;
        std::string ToString() const override;

        std::vector<ModuleInfo*> Modules;
        void SetAuthResult(AuthResult result);
        AuthResult Result;
        uint32 ErrorType;

        int32 PingTimeout;
        uint32 Threshold;
        uint32 Rate;
        std::string FirstName;
        std::string LastName;
        uint32 GameAccountId;
        std::string GameAccountName;
        uint64 GameAccountFlags;
    };

    class AuthResume final : public ServerPacket
    {
    public:
        AuthResume() : ServerPacket(PacketHeader(SMSG_AUTH_RESUME, AUTHENTICATION)),
            Result(AUTH_OK), ErrorType(0), PingTimeout(120000), Threshold(25000000), Rate(1000)
        {
        }

        ~AuthResume();

        void Write() override;
        std::string ToString() const override;

        std::vector<ModuleInfo*> Modules;
        void SetAuthResult(AuthResult result);
        AuthResult Result;
        uint32 ErrorType;

        int32 PingTimeout;
        uint32 Threshold;
        uint32 Rate;
    };

    class Pong final : public ServerPacket
    {
    public:
        Pong() : ServerPacket(PacketHeader(SMSG_PONG, CREEP))
        {
        }

        void Write() override { }
        std::string ToString() const override { return "Battlenet::Pong"; }
    };

    class RealmCharacterCounts final : public ServerPacket
    {
    public:
        RealmCharacterCounts() : ServerPacket(PacketHeader(SMSG_CHARACTER_COUNTS, WOW))
        {
        }
        ~RealmCharacterCounts();

        struct CharacterCountEntry
        {
            RealmId Realm;
            uint32 CharacterCount;
        };

        void Write() override;
        std::string ToString() const override;

        std::vector<CharacterCountEntry> CharacterCounts;
        std::vector<ServerPacket*> RealmData;
    };

    class RealmUpdate final : public ServerPacket
    {
    public:
        RealmUpdate() : ServerPacket(PacketHeader(SMSG_REALM_UPDATE, WOW)),
            Timezone(0), Population(0.0f), Lock(0), Type(0), Name(""), Version(""),
            Address(), Flags(0), Region(0), Battlegroup(0), Index(0), Build(0)
        {
        }

        void Write() override;
        std::string ToString() const override;

        uint32 Timezone;
        float Population;
        uint8 Lock;
        uint32 Type;
        std::string Name;
        std::string Version;
        ACE_INET_Addr Address;
        uint8 Flags;
        uint8 Region;
        uint8 Battlegroup;
        uint32 Index;
        uint32 Build;
    };

    class RealmUpdateComplete final : public ServerPacket
    {
    public:
        RealmUpdateComplete() : ServerPacket(PacketHeader(SMSG_REALM_UPDATE_END, WOW))
        {
        }

        void Write() override { }
        std::string ToString() const override { return "Battlenet::RealmUpdateComplete"; }
    };

    class RealmJoinRequest final : public ClientPacket
    {
    public:
        RealmJoinRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
        {
            ASSERT(header == PacketHeader(CMSG_JOIN_REQUEST, WOW) && "Invalid packet header for RealmJoinRequest");
        }

        void Read() override;
        std::string ToString() const override;

        uint32 ClientSeed;
        uint32 Unknown;
        RealmId Realm;
    };

    class RealmJoinResult final : public ServerPacket
    {
    public:
        RealmJoinResult() : ServerPacket(PacketHeader(SMSG_JOIN_RESULT, WOW)), ServerSeed(0)
        {
        }

        void Write() override;
        std::string ToString() const override;

        uint32 ServerSeed;
        std::vector<ACE_INET_Addr> IPv4;
    };
}

#endif // __BATTLENETPACKETS_H__
