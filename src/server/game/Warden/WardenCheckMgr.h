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
#include "World.h"
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
enum WardenCheckCategory : uint8
{
    INJECT_CHECK_CATEGORY = 0, // checks that test whether the client's execution has been interfered with
    LUA_CHECK_CATEGORY,        // checks that test whether the lua sandbox has been modified
    MODDED_CHECK_CATEGORY,     // checks that test whether the client has been modified

    NUM_CHECK_CATEGORIES // SKIP
};

// EnumUtils: DESCRIBE THIS
enum WardenCheckType : uint8
{
    NONE_CHECK     =   0, // SKIP
    TIMING_CHECK   =  87, // nyi
    DRIVER_CHECK   = 113, // uint Seed + byte[20] SHA1 + byte driverNameIndex (check to ensure driver isn't loaded)
    PROC_CHECK     = 126, // nyi
    LUA_EVAL_CHECK = 139, // evaluate arbitrary Lua check
    MPQ_CHECK      = 152, // get hash of MPQ file (to check it is not modified)
    PAGE_CHECK_A   = 178, // scans all pages for specified SHA1 hash
    PAGE_CHECK_B   = 191, // scans only pages starts with MZ+PE headers for specified hash
    MODULE_CHECK   = 217, // check to make sure module isn't injected
    MEM_CHECK      = 243, // retrieve specific memory
};

constexpr WardenCheckCategory GetWardenCheckCategory(WardenCheckType type)
{
    switch (type)
    {
        case TIMING_CHECK:   return NUM_CHECK_CATEGORIES;
        case DRIVER_CHECK:   return INJECT_CHECK_CATEGORY;
        case PROC_CHECK:     return NUM_CHECK_CATEGORIES;
        case LUA_EVAL_CHECK: return LUA_CHECK_CATEGORY;
        case MPQ_CHECK:      return MODDED_CHECK_CATEGORY;
        case PAGE_CHECK_A:   return INJECT_CHECK_CATEGORY;
        case PAGE_CHECK_B:   return INJECT_CHECK_CATEGORY;
        case MODULE_CHECK:   return INJECT_CHECK_CATEGORY;
        case MEM_CHECK:      return MODDED_CHECK_CATEGORY;
        default:             return NUM_CHECK_CATEGORIES;
    }
}

constexpr WorldIntConfigs GetWardenCategoryCountConfig(WardenCheckCategory category)
{
    switch (category)
    {
        case INJECT_CHECK_CATEGORY: return CONFIG_WARDEN_NUM_INJECT_CHECKS;
        case LUA_CHECK_CATEGORY:    return CONFIG_WARDEN_NUM_LUA_CHECKS;
        case MODDED_CHECK_CATEGORY: return CONFIG_WARDEN_NUM_CLIENT_MOD_CHECKS;
        default:                    return INT_CONFIG_VALUE_COUNT;
    }
}

constexpr bool IsWardenCategoryInWorldOnly(WardenCheckCategory category)
{
    switch (category)
    {
        case INJECT_CHECK_CATEGORY: return false;
        case LUA_CHECK_CATEGORY:    return true;
        case MODDED_CHECK_CATEGORY: return false;
        default:                    return false;
    }
}

struct WardenCheck
{
    uint16 CheckId = 0;
    WardenCheckType Type = NONE_CHECK;
    std::vector<uint8> Data;
    uint32 Address = 0;                                     // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    uint8 Length = 0;                                       // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    std::string Str;                                        // LUA, MPQ, DRIVER
    std::string Comment;
    std::array<char, 4> IdStr = {};                         // LUA
    WardenActions Action = WARDEN_ACTION_LOG;
};

constexpr uint8 WARDEN_MAX_LUA_CHECK_LENGTH = 170;

using WardenCheckResult = std::vector<uint8>;

class TC_GAME_API WardenCheckMgr
{
    private:
        WardenCheckMgr();

    public:
        static WardenCheckMgr* instance();

        uint16 GetMaxValidCheckId() const { return static_cast<uint16>(_checks.size()); }
        WardenCheck const& GetCheckData(uint16 Id) const;
        WardenCheckResult const& GetCheckResult(uint16 Id) const;

        std::vector<uint16> const& GetAvailableChecks(WardenCheckCategory category) { return _pools[category]; }

        void LoadWardenChecks();
        void LoadWardenOverrides();

    private:
        std::vector<WardenCheck> _checks;
        std::unordered_map<uint16, WardenCheckResult> _checkResults;
        std::array<std::vector<uint16>, NUM_CHECK_CATEGORIES> _pools;
};

#define sWardenCheckMgr WardenCheckMgr::instance()

#endif
