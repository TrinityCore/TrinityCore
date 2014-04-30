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
        NOT_SPECIFIED   = -1,

        AUTHENTICATION  = 0,
        CREEP           = 1,
        WOW             = 2
    };

    enum AuthOpcode
    {
        CMSG_AUTH_CHALLENGE         = 0x0,
        CMSG_AUTH_PROOF_RESPONSE    = 0x2,
        CMSG_AUTH_CHALLENGE_NEW     = 0x9,  // MoP

        SMSG_AUTH_COMPLETE          = 0x0,
        SMSG_AUTH_PROOF_REQUEST     = 0x2,
    };

    struct PacketHeader
    {
        PacketHeader(uint32 opcode, uint32 channel) : Opcode(opcode), Channel(channel) { }
        PacketHeader() : Opcode(0), Channel(NOT_SPECIFIED) { }

        uint32 Opcode;
        int32 Channel;

        bool operator<(PacketHeader const& right) const
        {
            return Opcode < right.Opcode || Channel < right.Channel;
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

        void Write() override { ASSERT(!"Write not implemented for this packet."); }

        virtual std::string ToString() const override { return "Battenet::ClientPacket"; };
    };

    class ServerPacket : public Packet
    {
    public:
        ServerPacket(PacketHeader const& header);
        ~ServerPacket();

        void Read() override { ASSERT(!"Read not implemented for server packets."); }

        virtual std::string ToString() const override { return "Battenet::ServerPacket"; };

        uint8 const* GetData() const { return _stream.GetBuffer(); }
        size_t GetSize() const { return _stream.GetSize(); }
    };

    class AuthChallenge final : public ClientPacket
    {
    public:
        AuthChallenge(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
        {
            ASSERT(header.Channel == AUTHENTICATION && (header.Opcode == CMSG_AUTH_CHALLENGE || header.Opcode == CMSG_AUTH_CHALLENGE_NEW) && "Invalid packet header for AuthChallenge");
        }

        void Read() override;
        std::string ToString() const override;

        std::string Program;
        std::string Platform;
        std::string Locale;
        std::vector<Component> Components;
        std::string Login;
    };

    struct ModuleInfo
    {
        std::string AuthString;
        std::string Locale;
        uint8 ModuleId[32];
        uint32 BlobSize;
        uint8* Blob;
    };

    class ProofRequest final : public ServerPacket
    {
    public:
        ProofRequest() : ServerPacket(PacketHeader(SMSG_AUTH_PROOF_REQUEST, AUTHENTICATION)) { }

        void Write() override;
        std::string ToString() const override;

        std::vector<ModuleInfo> Modules;
    };

    class ProofResponse final : public ClientPacket
    {
    public:
        ProofResponse(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
        {
            ASSERT(header == PacketHeader(CMSG_AUTH_PROOF_RESPONSE, AUTHENTICATION) && "Invalid packet header for ProofResponse");
        }

        ~ProofResponse();

        struct ModuleData
        {
            uint32 Size;
            uint8* Data;
        };

        void Read() override;
        std::string ToString() const override;

        std::vector<ModuleData> Modules;
    };

    class AuthComplete final : public ServerPacket
    {
    public:
        AuthComplete() : ServerPacket(PacketHeader(SMSG_AUTH_COMPLETE, AUTHENTICATION)),
            Result(AUTH_OK), ErrorType(0), PingTimeout(120000), Threshold(1000000), Rate(1000)
        {
        }

        void Write() override;
        std::string ToString() const override;

        std::vector<ModuleInfo> Modules;
        void SetAuthResult(AuthResult result);
        AuthResult Result;
        uint32 ErrorType;

        int32 PingTimeout;
        uint32 Threshold;
        uint32 Rate;
        std::string FirstName;
        std::string LastName;
    };
}

#endif // __BATTLENETPACKETS_H__
