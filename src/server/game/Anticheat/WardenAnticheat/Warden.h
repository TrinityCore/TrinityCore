/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _WARDEN_BASE_H
#define _WARDEN_BASE_H

#include <map>
#include "Auth/ARC4.h"
#include "Auth/BigNumber.h"
#include "ByteBuffer.h"
#include "WardenMgr.h"
#include "Database/DatabaseEnv.h"
#include "Anticheat.h"

class Object;
class Player;

// the default client version with info in warden_checks; for other version checks, see warden_build_specific
#define DEFAULT_CLIENT_BUILD  5875

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

enum WardenCheckType
{
    MEM_CHECK,        // byte moduleNameIndex + uint Offset + byte Len (check to ensure memory isn't modified)
    MODULE_CHECK,     // uint Seed + byte[20] SHA1 (check to ensure module isn't injected)
    PAGE_CHECK_B,     // uint Seed + byte[20] SHA1 + uint Addr + byte Len (scans only pages starts with MZ+PE headers for specified hash)
    PAGE_CHECK_A,     // uint Seed + byte[20] SHA1 + uint Addr + byte Len (scans all pages for specified hash)
    MPQ_CHECK,        // byte fileNameIndex (check to ensure MPQ file isn't modified)
    LUA_STR_CHECK,    // byte luaNameIndex (check to ensure LUA string isn't used)
    PROC_CHECK,       // uint Seed + byte[20] SHA1 + byte moluleNameIndex + byte procNameIndex + uint Offset + byte Len (check to ensure proc isn't detoured)
    DRIVER_CHECK,     // uint Seed + byte[20] SHA1 + byte driverNameIndex (check to ensure driver isn't loaded)
    TIMING_CHECK,     // empty (check to ensure GetTickCount() isn't detoured)
    WARDEN_CHECK_MAX
};

#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

struct WardenModuleUse
{
    uint8 Command;
    uint8 ModuleId[16];
    uint8 ModuleKey[16];
    uint32 Size;
};

struct WardenModuleTransfer
{
    uint8 Command;
    uint16 DataSize;
    uint8 Data[500];
};

struct WardenHashRequest
{
    uint8 Command;
    uint8 Seed[16];
};

namespace WardenState
{
    enum Value
    {
        STATE_INITIAL,
        STATE_REQUESTED_MODULE,
        STATE_SENT_MODULE,
        STATE_REQUESTED_HASH,
        STATE_INITIALIZE_MODULE,
        STATE_REQUESTED_DATA,
        STATE_RESTING
    };

    inline const char* to_string(WardenState::Value value)
    {
        switch (value)
        {
            case WardenState::STATE_INITIAL:
                return "STATE_INITIAL";
            case WardenState::STATE_REQUESTED_MODULE:
                return "STATE_REQUESTED_MODULE";
            case WardenState::STATE_SENT_MODULE:
                return "STATE_SENT_MODULE";
            case WardenState::STATE_REQUESTED_HASH:
                return "STATE_REQUESTED_HASH";
            case WardenState::STATE_INITIALIZE_MODULE:
                return "STATE_INITIALIZE_MODULE";
            case WardenState::STATE_REQUESTED_DATA:
                return "STATE_REQUESTED_DATA";
            case WardenState::STATE_RESTING:
                return "STATE_RESTING";
        }
        return "UNDEFINED STATE";
    }
};

#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

struct ClientWardenModule
{
    uint8 Id[16];
    uint8 Key[16];
    uint32 CompressedSize;
    uint8* CompressedData;
};

class WorldSession;
struct WardenCheck;
struct WardenModule;

class Warden
{
    public:
        Warden();
        virtual ~Warden();

        virtual void Init(WorldSession* session, BigNumber* k) = 0;
        virtual ClientWardenModule* GetModuleForClient() = 0;
        virtual void InitializeModule();
        virtual void RequestHash();
        virtual void HandleHashResult(ByteBuffer &buff) = 0;
        virtual void RequestData();
        virtual void HandleData(ByteBuffer &buff);
        virtual void HandleWardenDataOpcode(WorldPacket & recv_data);

        void SendModuleToClient();
        void RequestModule();
        void Update();
        void DecryptData(uint8* buffer, uint32 length);
        void EncryptData(uint8* buffer, uint32 length);

        void SetNewState(WardenState::Value state);
        WorldSession* GetSession() { return m_session; }

        static bool IsValidCheckSum(uint32 checksum, const uint8 *data, const uint16 length);
        static uint32 BuildChecksum(const uint8 *data, uint32 length);

        // If no check is passed, the default action from config is executed
        void ApplyPenalty(std::string message, WardenCheck* check = nullptr);

    protected:
        void LogPositiveToDB(WardenCheck* check);

        WorldSession* m_session;
        uint8 m_inputKey[16];
        uint8 m_outputKey[16];
        uint8 m_seed[16];
        ARC4 m_inputCrypto;
        ARC4 m_outputCrypto;
        uint32 m_checkTimer;                          // Timer for sending check requests
        uint32 m_clientResponseTimer;                 // Timer for client response delay
        uint32 m_previousTimestamp;
        ClientWardenModule* m_module;
        WardenModule* m_selectedModule;
        WardenState::Value m_state;
};

#endif
