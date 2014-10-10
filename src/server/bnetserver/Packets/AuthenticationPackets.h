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

#ifndef AuthenticationPackets_h__
#define AuthenticationPackets_h__

#include "PacketsBase.h"

namespace Battlenet
{
    namespace Authentication
    {
        enum Opcode
        {
            CMSG_LOGON_REQUEST          = 0x0,
            CMSG_RESUME_REQUEST         = 0x1,
            CMSG_PROOF_RESPONSE         = 0x2,

            SMSG_LOGON_RESPONSE         = 0x0,
            SMSG_RESUME_RESPONSE        = 0x1,
            SMSG_PROOF_REQUEST          = 0x2,
            SMSG_PATCH                  = 0x3,  // Not implemented
            SMSG_AUTHORIZED_LICENSES    = 0x4   // Not implemented
        };

        class LogonRequest final : public ClientPacket
        {
        public:
            LogonRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_LOGON_REQUEST, AUTHENTICATION) && "Invalid packet header for LogonRequest");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) const override;

            std::string Program;
            std::string Platform;
            std::string Locale;
            std::vector<Component> Components;
            std::string Login;
        };

        class ResumeRequest final : public ClientPacket
        {
        public:
            ResumeRequest(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_RESUME_REQUEST, AUTHENTICATION) && "Invalid packet header for ResumeRequest");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) const override;

            std::string Program;
            std::string Platform;
            std::string Locale;
            std::vector<Component> Components;
            std::string Login;
            uint8 Region;
            std::string GameAccountName;
        };

        class ProofResponse final : public ClientPacket
        {
        public:
            ProofResponse(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_PROOF_RESPONSE, AUTHENTICATION) && "Invalid packet header for ProofResponse");
            }

            ~ProofResponse();

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) const override;

            std::vector<BitStream*> Modules;
        };

        class ProofRequest final : public ServerPacket
        {
        public:
            ProofRequest() : ServerPacket(PacketHeader(SMSG_PROOF_REQUEST, AUTHENTICATION)) { }
            ~ProofRequest();

            void Write() override;
            std::string ToString() const override;

            std::vector<ModuleInfo*> Modules;
        };

        class ResponseFailure
        {
        public:
            enum Result
            {
                UPDATE = 0,
                FAILURE = 1,
                VERSION_CHECK_DISCONNECT = 2
            };

            ResponseFailure() : ResultValue(UPDATE), Error(AUTH_OK), Wait(0) { }

            Result ResultValue;
            AuthResult Error;
            int32 Wait;
        };

        class Regulator
        {
        public:
            enum Info
            {
                NONE = 0,
                LEAKY_BUCKET = 1
            };

            Regulator() : Type(LEAKY_BUCKET), Threshold(25000000), Rate(1000) { }

            Info Type;
            uint32 Threshold;
            uint32 Rate;
        };

        class LogonResponse final : public ServerPacket
        {
        public:
            LogonResponse() : ServerPacket(PacketHeader(SMSG_LOGON_RESPONSE, AUTHENTICATION)),
                PingTimeout(120000), FirstName(""), LastName(""), AccountId(0), Region(2), Flags(0),
                GameAccountRegion(2), GameAccountName(""), FailedLogins(0)
            {
            }

            ~LogonResponse();

            void Write() override;
            std::string ToString() const override;

            std::vector<ModuleInfo*> Modules;
            void SetAuthResult(AuthResult result);
            ResponseFailure Result;

            int32 PingTimeout;
            Regulator RegulatorRules;
            std::string FirstName;
            std::string LastName;
            uint32 AccountId;
            uint8 Region;
            uint64 Flags;
            uint8 GameAccountRegion;
            std::string GameAccountName;
            uint64 GameAccountFlags;

            uint32 FailedLogins;
        };

        class ResumeResponse final : public ServerPacket
        {
        public:
            ResumeResponse() : ServerPacket(PacketHeader(SMSG_RESUME_RESPONSE, AUTHENTICATION)), PingTimeout(120000)
            {
            }

            ~ResumeResponse();

            void Write() override;
            std::string ToString() const override;

            std::vector<ModuleInfo*> Modules;
            void SetAuthResult(AuthResult result);
            ResponseFailure Result;

            int32 PingTimeout;
            Regulator RegulatorRules;
        };
    }
}

#endif // AuthenticationPackets_h__
