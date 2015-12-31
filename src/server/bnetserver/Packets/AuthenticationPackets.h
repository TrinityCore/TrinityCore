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

#ifndef AuthenticationPackets_h__
#define AuthenticationPackets_h__

#include "PacketsBase.h"
#include "ComponentManager.h"
#include "ModuleManager.h"

namespace Battlenet
{
    namespace Authentication
    {
        enum Opcode
        {
            CMSG_LOGON_REQUEST                              = 0x0,  // Deprecated
            CMSG_RESUME_REQUEST                             = 0x1,
            CMSG_PROOF_RESPONSE                             = 0x2,
            CMSG_GENERATE_SINGLE_SIGN_ON_TOKEN_REQUEST_2    = 0x8,  // Not implemented
            CMSG_LOGON_REQUEST_3                            = 0x9,
            CMSG_SINGLE_SIGN_ON_REQUEST_3                   = 0xA,  // Not implemented

            SMSG_LOGON_RESPONSE                             = 0x0,
            SMSG_RESUME_RESPONSE                            = 0x1,
            SMSG_PROOF_REQUEST                              = 0x2,
            SMSG_PATCH                                      = 0x3,  // Not implemented
            SMSG_AUTHORIZED_LICENSES                        = 0x4,  // Not implemented
            SMSG_GENERATE_SINGLE_SIGN_ON_TOKEN_RESPONSE_2   = 0x8   // Not implemented
        };

        struct RequestCommon : public PrintableComponent
        {
            std::string Program;
            std::string Platform;
            std::string Locale;
            std::vector<Version::Record> Versions;

            std::string ToString() const override;
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
            void CallHandler(Session* session) override;

            RequestCommon Common;
            std::string Account;
            uint8 GameAccountRegion = 0;
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
            void CallHandler(Session* session) override;

            std::vector<BitStream*> Response;
        };

        class LogonRequest3 final : public ClientPacket
        {
        public:
            LogonRequest3(PacketHeader const& header, BitStream& stream) : ClientPacket(header, stream)
            {
                ASSERT(header == PacketHeader(CMSG_LOGON_REQUEST_3, AUTHENTICATION) && "Invalid packet header for LogonRequest3");
            }

            void Read() override;
            std::string ToString() const override;
            void CallHandler(Session* session) override;

            RequestCommon Common;
            std::string Account;
            uint64 Compatibility = 0;
        };

        struct FailureType : public PrintableComponent
        {
            Optional<Cache::Handle> Strings;

            enum
            {
                UPDATE = 0,
                FAILURE = 1,
                VERSION_CHECK_DISCONNECT = 2
            };

            struct ResultType : public PrintableComponent
            {
                int32 Type = FAILURE;

                struct UpdateType : public PrintableComponent
                {
                    std::string ToString() const override;
                } Update;

                struct FailureType : public PrintableComponent
                {
                    AuthResult Error = AUTH_OK;
                    int32 Wait = 0;

                    std::string ToString() const override;
                } Failure;

                struct VersionCheckDisconnectType : public PrintableComponent
                {
                    std::string ToString() const override;
                } VersionCheckDisconnect;

                std::string ToString() const override;
            } Result;

            std::string ToString() const override;
        };

        struct Regulator : public PrintableComponent
        {
            enum
            {
                NONE = 0,
                LEAKY_BUCKET = 1
            };

            int32 Type = LEAKY_BUCKET;
            struct NoneType : public PrintableComponent
            {
                std::string ToString() const override;
            } None;

            struct LeakyBucketType : public PrintableComponent
            {
                uint32 Threshold = 25000000;
                uint32 Rate = 1000;

                std::string ToString() const override;
            } LeakyBucket;

            std::string ToString() const override;
        };

        class LogonResponse final : public ServerPacket
        {
        public:
            LogonResponse() : ServerPacket(PacketHeader(SMSG_LOGON_RESPONSE, AUTHENTICATION))
            {
            }

            ~LogonResponse();

            void Write() override;
            std::string ToString() const override;
            void SetAuthResult(AuthResult result);

            struct ResultType : public PrintableComponent
            {
                enum
                {
                    SUCCESS = 0,
                    FAILURE = 1
                };

                int32 Type = SUCCESS;
                struct SuccessType : public PrintableComponent
                {
                    std::vector<ModuleInfo*> FinalRequest;
                    int32 PingTimeout = 120000;
                    Optional<Regulator> RegulatorRules;
                    Battlenet::Account::FullName FullName;
                    uint32 AccountId = 0;
                    uint8 Region = 2;
                    uint64 Flags = 0;
                    uint8 GameAccountRegion = 2;
                    std::string GameAccountName;
                    uint64 GameAccountFlags = 0;
                    uint32 LogonFailures = 0;

                    std::string ToString() const override;
                } Success;

                FailureType Failure;

                std::string ToString() const override;
            } Result;

            Optional<std::vector<uint8>> Raf;
        };

        class ResumeResponse final : public ServerPacket
        {
        public:
            ResumeResponse() : ServerPacket(PacketHeader(SMSG_RESUME_RESPONSE, AUTHENTICATION))
            {
            }

            ~ResumeResponse();

            void Write() override;
            std::string ToString() const override;

            void SetAuthResult(AuthResult result);

            struct ResultType
            {
                enum
                {
                    SUCCESS = 0,
                    FAILURE = 1
                };

                int32 Type = SUCCESS;
                struct SuccessType
                {
                    std::vector<ModuleInfo*> FinalRequest;
                    int32 PingTimeout = 120000;
                    Optional<Regulator> RegulatorRules;
                } Success;

                FailureType Failure;
            } Result;
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
    }
}

#endif // AuthenticationPackets_h__
