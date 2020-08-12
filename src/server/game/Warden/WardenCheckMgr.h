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

#ifndef _WARDENCHECKMGR_H
#define _WARDENCHECKMGR_H

#include "Define.h"
#include <shared_mutex>
#include <unordered_map>
#include <vector>

// EnumUtils: DESCRIBE THIS
enum WardenActions : uint8
{
    WARDEN_ACTION_LOG, // TITLE Log
    WARDEN_ACTION_KICK, // TITLE Kick
    WARDEN_ACTION_BAN // TITLE Ban
};

// EnumUtils: DESCRIBE THIS
enum WardenCheckType : uint8
{
    MEM_CHECK = 0xF3, // 243: byte moduleNameIndex + uint Offset + byte Len (check to ensure memory isn't modified)
    PAGE_CHECK_A = 0xB2, // 178: uint Seed + byte[20] SHA1 + uint Addr + byte Len (scans all pages for specified hash)
    PAGE_CHECK_B = 0xBF, // 191: uint Seed + byte[20] SHA1 + uint Addr + byte Len (scans only pages starts with MZ+PE headers for specified hash)
    MPQ_CHECK = 0x98, // 152: byte fileNameIndex (check to ensure MPQ file isn't modified)
    LUA_STR_CHECK = 0x8B, // 139: byte luaNameIndex (check to ensure LUA string isn't used)
    DRIVER_CHECK = 0x71, // 113: uint Seed + byte[20] SHA1 + byte driverNameIndex (check to ensure driver isn't loaded)
    TIMING_CHECK = 0x57, //  87: empty (check to ensure GetTickCount() isn't detoured)
    PROC_CHECK = 0x7E, // 126: uint Seed + byte[20] SHA1 + byte moluleNameIndex + byte procNameIndex + uint Offset + byte Len (check to ensure proc isn't detoured)
    MODULE_CHECK = 0xD9  // 217: uint Seed + byte[20] SHA1 (check to ensure module isn't injected)
};

struct WardenCheck
{
    WardenCheckType Type;
    std::vector<uint8> Data;
    uint32 Address;                                         // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    uint8 Length;                                           // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    std::string Str;                                        // LUA, MPQ, DRIVER
    std::string Comment;
    uint16 CheckId;
    WardenActions Action;
};

using WardenCheckResult = std::vector<uint8>;

class TC_GAME_API WardenCheckMgr
{
    private:
        WardenCheckMgr();

    public:
        static WardenCheckMgr* instance();

        WardenCheck const& GetCheckDataById(uint16 Id) const;
        WardenCheckResult const& GetCheckResultById(uint16 Id) const;

        std::vector<uint16> const& GetAvailableMemoryChecks() const { return MemChecksIdPool; }
        std::vector<uint16> const& GetAvailableOtherChecks() const { return OtherChecksIdPool; }

        void LoadWardenChecks();
        void LoadWardenOverrides();

    private:
        std::vector<WardenCheck> CheckStore;
        std::unordered_map<uint32, WardenCheckResult> CheckResultStore;
        std::vector<uint16> MemChecksIdPool;
        std::vector<uint16> OtherChecksIdPool;
};

#define sWardenCheckMgr WardenCheckMgr::instance()

#endif
