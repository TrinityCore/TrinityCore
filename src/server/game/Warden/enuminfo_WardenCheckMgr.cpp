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

namespace Trinity
{
namespace Impl
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

/************************************************************************\
|* data for enum 'WardenCheckType' in 'WardenCheckMgr.h' auto-generated *|
\************************************************************************/
template <>
TC_API_EXPORT EnumText EnumUtils<WardenCheckType>::ToString(WardenCheckType value)
{
    switch (value)
    {
        case MEM_CHECK: return { "MEM_CHECK", "MEM_CHECK", "243: byte moduleNameIndex + uint Offset + byte Len (check to ensure memory isn't modified)" };
        case PAGE_CHECK_A: return { "PAGE_CHECK_A", "PAGE_CHECK_A", "178: uint Seed + byte[20] SHA1 + uint Addr + byte Len (scans all pages for specified hash)" };
        case PAGE_CHECK_B: return { "PAGE_CHECK_B", "PAGE_CHECK_B", "191: uint Seed + byte[20] SHA1 + uint Addr + byte Len (scans only pages starts with MZ+PE headers for specified hash)" };
        case MPQ_CHECK: return { "MPQ_CHECK", "MPQ_CHECK", "152: byte fileNameIndex (check to ensure MPQ file isn't modified)" };
        case LUA_STR_CHECK: return { "LUA_STR_CHECK", "LUA_STR_CHECK", "139: byte luaNameIndex (check to ensure LUA string isn't used)" };
        case DRIVER_CHECK: return { "DRIVER_CHECK", "DRIVER_CHECK", "113: uint Seed + byte[20] SHA1 + byte driverNameIndex (check to ensure driver isn't loaded)" };
        case TIMING_CHECK: return { "TIMING_CHECK", "TIMING_CHECK", "87: empty (check to ensure GetTickCount() isn't detoured)" };
        case PROC_CHECK: return { "PROC_CHECK", "PROC_CHECK", "126: uint Seed + byte[20] SHA1 + byte moluleNameIndex + byte procNameIndex + uint Offset + byte Len (check to ensure proc isn't detoured)" };
        case MODULE_CHECK: return { "MODULE_CHECK", "MODULE_CHECK", "217: uint Seed + byte[20] SHA1 (check to ensure module isn't injected)" };
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
        case 0: return MEM_CHECK;
        case 1: return PAGE_CHECK_A;
        case 2: return PAGE_CHECK_B;
        case 3: return MPQ_CHECK;
        case 4: return LUA_STR_CHECK;
        case 5: return DRIVER_CHECK;
        case 6: return TIMING_CHECK;
        case 7: return PROC_CHECK;
        case 8: return MODULE_CHECK;
        default: throw std::out_of_range("index");
    }
}
}
}
