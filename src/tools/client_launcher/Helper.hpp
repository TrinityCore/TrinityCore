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

#ifndef Helper_h__
#define Helper_h__

#include "Define.h"
#include <set>
#include <vector>

namespace ClientLauncher
{
    namespace Helper
    {
        std::set<size_t> SearchOffset(std::vector<uint8> const& binary, std::vector<uint8> const& pattern);
        uint32 GetBuildNumber(std::vector<uint8> const& binary);
    }
}

#endif // Helper_h__
