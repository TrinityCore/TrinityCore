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

#ifndef Patcher_h__
#define Patcher_h__

#include <boost/filesystem.hpp>

#include <vector>
#include <Windows.h>
#include <string>
#include "Helper.hpp"

namespace ClientLauncher
{
    class Patcher
    {
    public:
        Patcher(std::vector<unsigned char> binary)
            : _binary(binary)
        {}

        virtual void Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern) = 0;
        std::vector<unsigned char> const& GetBinary() const { return _binary; }

    protected:
        std::vector<unsigned char> _binary;
    };

    class FilePatcher : public Patcher
    {
    public:
        FilePatcher(boost::filesystem::path file)
            : Patcher(Helper::ReadFile(file))
        {}

        void Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern);
        void Finish(boost::filesystem::path out);

        void WriteFile(boost::filesystem::path const& path, std::vector<unsigned char> const& data);
    };

    class MemoryPatcher : public Patcher
    {
    public:
        MemoryPatcher(HANDLE process)
            : Patcher(GetProcessMemory(process)), _processHandle(process)
        {}

        void Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern);
        std::vector<unsigned char> GetProcessMemory(HANDLE process);
        bool IsSupportedBuild();
    protected:
        HANDLE _processHandle;
#ifdef _M_IX86
        uint32_t _baseAddress;
#else
        uint64_t _baseAddress;
#endif
    };
}

#endif // Patcher_h__
