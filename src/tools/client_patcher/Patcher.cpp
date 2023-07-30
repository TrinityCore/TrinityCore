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

#include "Patcher.hpp"
#include "Helper.hpp"
#include <iostream>

namespace ClientPatcher
{
    Patcher::Patcher(std::vector<uint8> const& data, HANDLE process, HMODULE module)
        : processHandle(process), moduleHandle(module), binary(data.begin(), data.end())
    {
    }

    void Patcher::Patch(std::vector<uint8> const& bytes, std::vector<uint8> const& pattern)
    {
        if (binary.size() < pattern.size())
            throw std::logic_error("pattern larger than binary");

        if (pattern.empty())
            return;

        for (size_t const offset : Helper::SearchOffset(binary, pattern))
        {
            std::cout << "Found offset " << offset << "\n";

            if (offset != 0 && binary.size() >= bytes.size())
            {
#ifdef _M_IX86
                uint32_t baseAddr = reinterpret_cast<uint32_t>(moduleHandle);
#else
                uint64_t baseAddr = reinterpret_cast<uint64_t>(moduleHandle);
#endif

                DWORD oldprotect;
                VirtualProtectEx(processHandle, (void*)(baseAddr + offset), bytes.size(), PAGE_EXECUTE_READWRITE, &oldprotect);
                memcpy((void*)(baseAddr + offset), bytes.data(), bytes.size());
                VirtualProtectEx(processHandle, (void*)(baseAddr + offset), bytes.size(), oldprotect, &oldprotect);
            }
        }
    }
}
