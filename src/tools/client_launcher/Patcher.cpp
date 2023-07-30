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
#include "Patterns/Common.hpp"

#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <stdexcept>
#include <winternl.h>

namespace
{
    struct NtdllFunctions
    {
        decltype(&::NtQueryInformationProcess) NtQueryInformationProcess;
    };

    template<typename T>
    void AssignHelper(T& func, FARPROC proc) { func = (T)proc; }

    std::unique_ptr<NtdllFunctions> GetNtFunctions()
    {
        HMODULE ntdll = GetModuleHandleA("ntdll.dll");

        std::unique_ptr<NtdllFunctions> functions = std::make_unique<NtdllFunctions>();
        AssignHelper(functions->NtQueryInformationProcess, GetProcAddress(ntdll, "NtQueryInformationProcess"));
        return functions;
    }

    std::set<size_t> SearchOffset(std::vector<unsigned char> const& binary, std::vector<unsigned char> const& pattern)
    {
        std::set<size_t> offsets;
        for (size_t i = 0; (i + pattern.size()) < binary.size(); i++)
        {
            size_t matches = 0;

            for (size_t j = 0; j < pattern.size(); j++)
            {
                if (pattern[j] == 0)
                {
                    matches++;
                    continue;
                }

                if (binary[i + j] != pattern[j])
                    break;

                matches++;
            }

            if (matches == pattern.size())
            {
                offsets.insert(i);
                i += matches;
            }
        }

        return offsets.empty() ? throw std::exception("SearchOffset | ERROR: unable to find pattern") : offsets;
    }
}

namespace ClientLauncher
{
    void FilePatcher::WriteFile(boost::filesystem::path const& path, std::vector<unsigned char> const& data)
    {
        std::ofstream ofs(path.string(), std::ofstream::binary);
        if (!ofs)
            throw std::runtime_error("could not open " + path.string());

        ofs << std::noskipws;

        std::copy(data.begin(), data.end(), std::ostream_iterator<unsigned char>(ofs));
    }

    void FilePatcher::Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern)
    {
        if (_binary.size() < pattern.size())
            throw std::logic_error("pattern larger than binary");

        if (pattern.empty())
            return;

        for (size_t const offset : SearchOffset(_binary, pattern))
        {
            std::cout << "Found offset " << offset << "\n";

            if (offset != 0 && _binary.size() >= bytes.size())
                for (size_t i = 0; i < bytes.size(); i++)
                    _binary[offset + i] = bytes[i];
        }
    }

    void FilePatcher::Finish(boost::filesystem::path out)
    {
        if (boost::filesystem::exists(out))
            boost::filesystem::remove(out);

        WriteFile(out, _binary);
    }

    std::vector<unsigned char> MemoryPatcher::GetProcessMemory(HANDLE process)
    {
        std::unique_ptr<NtdllFunctions> ntdll = GetNtFunctions();
        std::vector<uint8_t> binaryData;
        ULONG dummy;

        PROCESS_BASIC_INFORMATION pbi;
        if (!NT_SUCCESS(ntdll->NtQueryInformationProcess(process, ProcessBasicInformation, &pbi, sizeof(pbi), &dummy)))
            return binaryData;

#ifdef _M_IX86
        uint32_t imageBase;
#else
        uint64_t imageBase;
#endif

        if (!ReadProcessMemory(process, &pbi.PebBaseAddress->Reserved3[1], &imageBase, sizeof(imageBase), nullptr))
            return binaryData;

        MEMORY_BASIC_INFORMATION mbi;

        _baseAddress = imageBase;

#ifdef _M_IX86
        uint32_t baseAddr = imageBase;
#else
        uint64_t baseAddr = imageBase;
#endif

        while (true)
        {
            if (!VirtualQueryEx(process, (void*)baseAddr, &mbi, sizeof(mbi)))
                throw std::exception("MemoryPatcher::GetProcessMemory | ERROR: VirtualQueryEx failed.");

            if (mbi.AllocationBase == 0)
                break;

            std::vector<BYTE> temp(mbi.RegionSize);
            if (!ReadProcessMemory(process, mbi.BaseAddress, temp.data(), mbi.RegionSize, nullptr))
                throw std::exception("MemoryPatcher::GetProcessMemory | ERROR: ReadProcessMemory failed.");
            binaryData.insert(binaryData.end(), temp.begin(), temp.end());
            baseAddr += mbi.RegionSize;
        }

        return binaryData;
    }

    void MemoryPatcher::Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern)
    {
        if (_binary.size() < pattern.size())
            throw std::logic_error("MemoryPatcher::GetProcessMemory  | ERROR: pattern larger than binary");

        if (pattern.empty())
            return;

        for (size_t const offset : SearchOffset(_binary, pattern))
        {
            std::cout << "Found offset " << offset << "\n";

            if (offset != 0 && _binary.size() >= bytes.size())
            {
                DWORD oldprotect;
                VirtualProtectEx(_processHandle, (void*)(_baseAddress + offset), bytes.size(), PAGE_EXECUTE_READWRITE, &oldprotect);
                WriteProcessMemory(_processHandle, (void*)(_baseAddress + offset), bytes.data(), bytes.size(), nullptr);
                VirtualProtectEx(_processHandle, (void*)(_baseAddress + offset), bytes.size(), oldprotect, &oldprotect);
            }
        }
    }

    bool MemoryPatcher::IsSupportedBuild()
    {
        std::set<size_t> offsets = SearchOffset(_binary, Patterns::Common::BinaryVersionCheck());

        if (!offsets.empty())
            return true;

        return false;
    }
}
