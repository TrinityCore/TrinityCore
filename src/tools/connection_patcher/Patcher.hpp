/*
 * Copyright (C) 2012-2014 Arctium Emulation <http://arctium.org>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CONNECTION_PATCHER_PATCHER_HPP
#define CONNECTION_PATCHER_PATCHER_HPP

#include "Helper.hpp"

#include <fstream>
#include <iostream>
#include <iterator>

namespace Connection_Patcher
{
    class Patcher
    {
    public:
        Patcher(boost::filesystem::path file);

        void Patch(std::vector<unsigned char> const& bytes, std::vector<unsigned char> const& pattern);
        void Finish(boost::filesystem::path out);
        Constants::BinaryTypes GetType() const { return binaryType; }
        std::vector<unsigned char> const& GetBinary() const { return binary; }

    private:
        void ReadFile();
        void WriteFile(boost::filesystem::path const& path);

        boost::filesystem::path filePath;
        std::vector<unsigned char> binary;
        Constants::BinaryTypes binaryType;


    };
}

#endif
