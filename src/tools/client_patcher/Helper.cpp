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

#include "Helper.hpp"
#include "Patterns/Common.hpp"
#include <string>
#include <stdexcept>

namespace ClientPatcher
{
    namespace Helper
    {
        std::set<size_t> SearchOffset(std::vector<uint8> const& binary, std::vector<uint8> const& pattern)
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

            return offsets.empty() ? throw std::runtime_error("unable to find pattern") : offsets;
        }
    }
}
