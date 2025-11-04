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

#ifndef TRINITYCORE_MMAP_COMMON_H
#define TRINITYCORE_MMAP_COMMON_H

#include "Common.h"
#include <boost/filesystem/directory.hpp>
#include <string_view>
#include <unordered_map>

namespace MMAP
{
    inline bool matchWildcardFilter(std::string_view filter, std::string_view str)
    {
        if (filter.empty() || str.empty())
            return false;

        auto filterItr = filter.begin();
        auto filterEnd = filter.end();
        auto strItr = str.begin();
        auto strEnd = str.end();

        // end on null character
        while (filterItr != filterEnd && strItr != strEnd)
        {
            if (*filterItr == '*')
            {
                if (++filterItr == filterEnd)   // wildcard at end of filter means all remaing chars match
                    return true;

                while (*filterItr != *strItr)
                {
                    if (strItr == strEnd)
                        return false;   // reached end of string without matching next filter character
                    ++strItr;
                }
            }
            else if (*filterItr != *strItr)
                return false;           // mismatch

            ++filterItr;
            ++strItr;
        }

        return (filterItr == filterEnd || (*filterItr == '*' && filterItr + 1 == filterEnd)) && strItr == strEnd;
    }

    enum ListFilesResult
    {
        LISTFILE_DIRECTORY_NOT_FOUND = 0,
        LISTFILE_OK = 1
    };

    inline ListFilesResult getDirContents(std::vector<std::string>& fileList, boost::filesystem::path const& dirpath,
        boost::filesystem::file_type type = boost::filesystem::regular_file, std::string_view filter = "*"sv)
    {
        boost::system::error_code ec;
        boost::filesystem::directory_iterator dirItr(dirpath, ec);
        if (ec)
            return LISTFILE_DIRECTORY_NOT_FOUND;

        for (boost::filesystem::directory_entry const& dirEntry : dirItr)
        {
            if (dirEntry.status(ec).type() != type || ec)
                continue;

            std::string fileName = dirEntry.path().filename().string();
            if (!matchWildcardFilter(filter, fileName))
                continue;

            fileList.push_back(std::move(fileName));
        }

        return LISTFILE_OK;
    }

    struct MapEntry
    {
        uint8 MapType = 0;
        int8 InstanceType = 0;
        int16 ParentMapID = -1;
        int32 Flags = 0;
    };

    extern std::unordered_map<uint32, MapEntry> sMapStore;

    namespace VMapFactory
    {
        std::unique_ptr<VMAP::VMapManager> CreateVMapManager(uint32 mapId);
}
}

#endif
