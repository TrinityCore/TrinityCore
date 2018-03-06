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

#ifndef CONNECTION_PATCHER_HELPER_HPP
#define CONNECTION_PATCHER_HELPER_HPP

#include "Constants/BinaryTypes.hpp"

#include <boost/filesystem.hpp>
#include <vector>
#include <set>

namespace Connection_Patcher
{
    namespace Helper
    {
        void CopyDir(boost::filesystem::path const & source, boost::filesystem::path const & destination);
        Constants::BinaryTypes GetBinaryType(std::vector<unsigned char> const& data);
        std::set<size_t> SearchOffset(std::vector<unsigned char> const& binary, std::vector<unsigned char> const& pattern);
        uint32_t GetBuildNumber(std::vector<unsigned char> const& binary);
    }
}

#endif
