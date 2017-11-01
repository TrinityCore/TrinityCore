/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

namespace ClientLauncher
{
    Patcher::Patcher(std::vector<uint8> const& data, HANDLE process)
        : processHandle(process), binary(data.begin(), data.end())
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
            std::cout << "Found offset " << offset << std::endl;

            if (offset != 0 && binary.size() >= bytes.size())
                for (size_t i = 0; i < bytes.size(); i++)
                    binary[offset + i] = bytes[i];
        }
    }
}
