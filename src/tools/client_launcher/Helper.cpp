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

#include "Helper.hpp"
#include "Patterns/Common.hpp"
#include <string>

namespace ClientLauncher
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

        uint32 GetBuildNumber(std::vector<uint8> const& binary)
        {
            std::set<size_t> offsets = SearchOffset(binary, Patterns::Common::BinaryVersion());

            if (!offsets.empty())
            {
                size_t const verOffset = (*offsets.begin());
                std::string ver(&binary[verOffset + 16], &binary[verOffset + 21]);

                return std::stoi(ver);
            }
            return 0;
        }
    }
}
