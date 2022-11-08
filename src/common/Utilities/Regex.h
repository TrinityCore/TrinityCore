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

#ifndef TrinityCore_Regex_h__
#define TrinityCore_Regex_h__

// std::wregex doesn't work with patterns provided in db2 files
// so we have to use boost
#include <boost/regex.hpp>
#define TC_REGEX_NAMESPACE boost

namespace Trinity
{
    using regex = TC_REGEX_NAMESPACE :: regex;
    using wregex = TC_REGEX_NAMESPACE :: wregex;

    using :: TC_REGEX_NAMESPACE :: regex_match;
    using :: TC_REGEX_NAMESPACE :: regex_search;
}

#endif // TrinityCore_Regex_h__
