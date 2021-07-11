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

#ifndef _WARDENCHECKMGR_H
#define _WARDENCHECKMGR_H

#include <array>
#include <map>
#include <mutex>
#include "Auth/BigNumber.h"
#include "Anticheat.h"

enum
{
    WARDEN_SIGNATURE_SIZE   = 264,
    WARDEN_KEY_SIZE         = 16,
    WARDEN_SCAN_TYPES_COUNT = 9,
};

struct WardenCheck
{
    uint8 Type;
    BigNumber Data;
    uint32 Address;                                         // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    uint8 Length;                                           // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    std::string Str;                                        // LUA, MPQ, DRIVER
    std::string Comment;
    uint16 CheckId;
    enum WardenActions Action;
};

struct WardenCheckResult
{
    uint16 Id;
    BigNumber Result;                                       // MEM_CHECK
};

#pragma pack(push, 1)
struct ChallengeResponseEntry
{
    uint8 seed[16];
    uint8 reply[20];
    uint8 clientKey[16];
    uint8 serverKey[16];
};
#pragma pack(pop)

struct WardenModule
{
    std::vector<uint8> binaryData;
    std::vector<uint8> binaryHash;
    std::array<uint8, WARDEN_KEY_SIZE> moduleKey;
    std::array<uint8, WARDEN_SCAN_TYPES_COUNT> scanTypes;
    std::vector<ChallengeResponseEntry> challengeData;
};

class WardenMgr
{
    private:
        WardenMgr();
        ~WardenMgr();

    public:
        static WardenMgr* instance()
        {
            static WardenMgr instance;
            return &instance;
        }

        WardenCheck* GetWardenDataById(uint16 /*build*/, uint16 /*id*/);
        WardenCheckResult* GetWardenResultById(uint16 /*build*/, uint16 /*id*/);
        void GetWardenCheckIds(bool isMemCheck /* true = MEM */, uint16 build, std::list<uint16>& list);

        WardenModule* GetRandomWardenModule(bool windows);

        void LoadWardenChecks();
        void LoadWardenModules();
        void LoadWardenModule(std::string module_name);

    private:
        typedef std::multimap< uint16, WardenCheck* > CheckMap;
        typedef std::multimap< uint16, WardenCheckResult* > CheckResultMap;

        typedef std::lock_guard<std::mutex> ReadGuard;
        typedef std::lock_guard<std::mutex> WriteGuard;

        std::mutex     m_lock;
        CheckMap       CheckStore;
        CheckResultMap CheckResultStore;
        std::vector<WardenModule> m_vWindowsModules;
        std::vector<WardenModule> m_vMacModules;
};

#define sWardenMgr WardenMgr::instance()

#endif
