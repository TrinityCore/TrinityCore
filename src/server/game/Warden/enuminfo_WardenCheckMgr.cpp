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

#include "WardenCheckMgr.h"
#include "Define.h"
#include "SmartEnum.h"
#include <stdexcept>

namespace Trinity::Impl::EnumUtilsImpl
{

/**********************************************************************\
|* data for enum 'WardenActions' in 'WardenCheckMgr.h' auto-generated *|
\**********************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<WardenActions>::ToString(WardenActions value)
{
    switch (value)
    {
        case WARDEN_ACTION_LOG: return { "WARDEN_ACTION_LOG", "Log", "" };
        case WARDEN_ACTION_KICK: return { "WARDEN_ACTION_KICK", "Kick", "" };
        case WARDEN_ACTION_BAN: return { "WARDEN_ACTION_BAN", "Ban", "" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WardenActions>::Count() { return 3; }

template <>
TC_API_EXPORT WardenActions EnumUtils<WardenActions>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return WARDEN_ACTION_LOG;
        case 1: return WARDEN_ACTION_KICK;
        case 2: return WARDEN_ACTION_BAN;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WardenActions>::ToIndex(WardenActions value)
{
    switch (value)
    {
        case WARDEN_ACTION_LOG: return 0;
        case WARDEN_ACTION_KICK: return 1;
        case WARDEN_ACTION_BAN: return 2;
        default: throw std::out_of_range("value");
    }
}

/****************************************************************************\
|* data for enum 'WardenCheckCategory' in 'WardenCheckMgr.h' auto-generated *|
\****************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<WardenCheckCategory>::ToString(WardenCheckCategory value)
{
    switch (value)
    {
        case INJECT_CHECK_CATEGORY: return { "INJECT_CHECK_CATEGORY", "INJECT_CHECK_CATEGORY", "checks that test whether the client's execution has been interfered with" };
        case LUA_CHECK_CATEGORY: return { "LUA_CHECK_CATEGORY", "LUA_CHECK_CATEGORY", "checks that test whether the lua sandbox has been modified" };
        case MODDED_CHECK_CATEGORY: return { "MODDED_CHECK_CATEGORY", "MODDED_CHECK_CATEGORY", "checks that test whether the client has been modified" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WardenCheckCategory>::Count() { return 3; }

template <>
TC_API_EXPORT WardenCheckCategory EnumUtils<WardenCheckCategory>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return INJECT_CHECK_CATEGORY;
        case 1: return LUA_CHECK_CATEGORY;
        case 2: return MODDED_CHECK_CATEGORY;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WardenCheckCategory>::ToIndex(WardenCheckCategory value)
{
    switch (value)
    {
        case INJECT_CHECK_CATEGORY: return 0;
        case LUA_CHECK_CATEGORY: return 1;
        case MODDED_CHECK_CATEGORY: return 2;
        default: throw std::out_of_range("value");
    }
}

/************************************************************************\
|* data for enum 'WardenCheckType' in 'WardenCheckMgr.h' auto-generated *|
\************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<WardenCheckType>::ToString(WardenCheckType value)
{
    switch (value)
    {
        case TIMING_CHECK: return { "TIMING_CHECK", "TIMING_CHECK", "nyi" };
        case DRIVER_CHECK: return { "DRIVER_CHECK", "DRIVER_CHECK", "uint Seed + byte[20] SHA1 + byte driverNameIndex (check to ensure driver isn't loaded)" };
        case PROC_CHECK: return { "PROC_CHECK", "PROC_CHECK", "nyi" };
        case LUA_EVAL_CHECK: return { "LUA_EVAL_CHECK", "LUA_EVAL_CHECK", "evaluate arbitrary Lua check" };
        case MPQ_CHECK: return { "MPQ_CHECK", "MPQ_CHECK", "get hash of MPQ file (to check it is not modified)" };
        case PAGE_CHECK_A: return { "PAGE_CHECK_A", "PAGE_CHECK_A", "scans all pages for specified SHA1 hash" };
        case PAGE_CHECK_B: return { "PAGE_CHECK_B", "PAGE_CHECK_B", "scans only pages starts with MZ+PE headers for specified hash" };
        case MODULE_CHECK: return { "MODULE_CHECK", "MODULE_CHECK", "check to make sure module isn't injected" };
        case MEM_CHECK: return { "MEM_CHECK", "MEM_CHECK", "retrieve specific memory" };
        default: throw std::out_of_range("value");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WardenCheckType>::Count() { return 9; }

template <>
TC_API_EXPORT WardenCheckType EnumUtils<WardenCheckType>::FromIndex(size_t index)
{
    switch (index)
    {
        case 0: return TIMING_CHECK;
        case 1: return DRIVER_CHECK;
        case 2: return PROC_CHECK;
        case 3: return LUA_EVAL_CHECK;
        case 4: return MPQ_CHECK;
        case 5: return PAGE_CHECK_A;
        case 6: return PAGE_CHECK_B;
        case 7: return MODULE_CHECK;
        case 8: return MEM_CHECK;
        default: throw std::out_of_range("index");
    }
}

template <>
TC_API_EXPORT size_t EnumUtils<WardenCheckType>::ToIndex(WardenCheckType value)
{
    switch (value)
    {
        case TIMING_CHECK: return 0;
        case DRIVER_CHECK: return 1;
        case PROC_CHECK: return 2;
        case LUA_EVAL_CHECK: return 3;
        case MPQ_CHECK: return 4;
        case PAGE_CHECK_A: return 5;
        case PAGE_CHECK_B: return 6;
        case MODULE_CHECK: return 7;
        case MEM_CHECK: return 8;
        default: throw std::out_of_range("value");
    }
}
}
