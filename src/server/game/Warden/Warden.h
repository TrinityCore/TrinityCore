/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef _WARDEN_BASE_H
#define _WARDEN_BASE_H

#include "ARC4.h"
#include "AuthDefines.h"
#include "ByteBuffer.h"
#include "Optional.h"
#include "WardenCheckMgr.h"
#include <array>

enum WardenOpcodes
{
    // Client->Server
    WARDEN_CMSG_MODULE_MISSING                  = 0,
    WARDEN_CMSG_MODULE_OK                       = 1,
    WARDEN_CMSG_CHEAT_CHECKS_RESULT             = 2,
    WARDEN_CMSG_MEM_CHECKS_RESULT               = 3,        // only sent if MEM_CHECK bytes doesn't match
    WARDEN_CMSG_HASH_RESULT                     = 4,
    WARDEN_CMSG_MODULE_FAILED                   = 5,        // this is sent when client failed to load uploaded module due to cache fail

    // Server->Client
    WARDEN_SMSG_MODULE_USE                      = 0,
    WARDEN_SMSG_MODULE_CACHE                    = 1,
    WARDEN_SMSG_CHEAT_CHECKS_REQUEST            = 2,
    WARDEN_SMSG_MODULE_INITIALIZE               = 3,
    WARDEN_SMSG_MEM_CHECKS_REQUEST              = 4,        // byte len; while (!EOF) { byte unk(1); byte index(++); string module(can be 0); int offset; byte len; byte[] bytes_to_compare[len]; }
    WARDEN_SMSG_HASH_REQUEST                    = 5
};

#pragma pack(push, 1)

struct WardenModuleUse
{
    uint8 Command;
    std::array<uint8, 16> ModuleId;
    std::array<uint8, 16> ModuleKey;
    uint32 Size;
};
static_assert(sizeof(WardenModuleUse) == (1 + 16 + 16 + 4));

struct WardenModuleTransfer
{
    uint8 Command;
    uint16 DataSize;
    uint8 Data[500];
};
static_assert(sizeof(WardenModuleTransfer) == (1 + 2 + 500));

struct WardenHashRequest
{
    uint8 Command;
    std::array<uint8, 16> Seed;
};
static_assert(sizeof(WardenHashRequest) == (1 + 16));

#pragma pack(pop)

struct ClientWardenModule
{
    std::array<uint8, 16> Id;
    std::array<uint8, 16> Key;
    uint8 const* CompressedData;
    size_t CompressedSize;
};

class WorldSession;

class TC_GAME_API Warden
{
    public:
        Warden();
        virtual ~Warden();

        virtual void Init(WorldSession* session, SessionKey const& K) = 0;
        void Update(uint32 diff);
        void HandleData(ByteBuffer& buff);
        bool ProcessLuaCheckResponse(std::string const& msg);

        virtual size_t DEBUG_ForceSpecificChecks(std::vector<uint16> const& checks) = 0;

    protected:
        void DecryptData(uint8* buffer, uint32 length);
        void EncryptData(uint8* buffer, uint32 length);

        virtual void InitializeModule() = 0;
        virtual void RequestHash() = 0;
        virtual void HandleHashResult(ByteBuffer& buff) = 0;
        virtual void HandleCheckResult(ByteBuffer& buff) = 0;
        virtual void InitializeModuleForClient(ClientWardenModule& module) = 0;
        virtual void RequestChecks() = 0;

        void MakeModuleForClient();
        void SendModuleToClient();
        void RequestModule();

        static bool IsValidCheckSum(uint32 checksum, const uint8 *data, const uint16 length);
        static uint32 BuildChecksum(const uint8 *data, uint32 length);

        // If nullptr is passed, the default action from config is executed
        char const* ApplyPenalty(WardenCheck const* check);

        WorldSession* _session;
        std::array<uint8, 16> _inputKey = {};
        std::array<uint8, 16> _outputKey = {};
        std::array<uint8, 16> _seed = {};
        Trinity::Crypto::ARC4 _inputCrypto;
        Trinity::Crypto::ARC4 _outputCrypto;
        uint32 _checkTimer;                          // Timer for sending check requests
        uint32 _clientResponseTimer;                 // Timer for client response delay
        bool _dataSent;
        Optional<ClientWardenModule> _module;
        bool _initialized;
};

#endif
