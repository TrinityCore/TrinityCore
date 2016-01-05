/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#ifndef _MMAP_COMMON_H
#define _MMAP_COMMON_H

#include "Common.h"

#include <vector>

#ifndef _WIN32
    #include <stddef.h>
    #include <dirent.h>
#endif

#ifdef __linux__
    #include <errno.h>
#endif

enum NavTerrain
{
    NAV_EMPTY   = 0x00,
    NAV_GROUND  = 0x01,
    NAV_MAGMA   = 0x02,
    NAV_SLIME   = 0x04,
    NAV_WATER   = 0x08,
    NAV_UNUSED1 = 0x10,
    NAV_UNUSED2 = 0x20,
    NAV_UNUSED3 = 0x40,
    NAV_UNUSED4 = 0x80
    // we only have 8 bits
};

namespace MMAP
{
    inline bool matchWildcardFilter(const char* filter, const char* str)
    {
        if (!filter || !str)
            return false;

        // end on null character
        while (*filter && *str)
        {
            if (*filter == '*')
            {
                if (*++filter == '\0')   // wildcard at end of filter means all remaing chars match
                    return true;

                for (;;)
                {
                    if (*filter == *str)
                        break;
                    if (*str == '\0')
                        return false;   // reached end of string without matching next filter character
                    str++;
                }
            }
            else if (*filter != *str)
                return false;           // mismatch

            filter++;
            str++;
        }

        return ((*filter == '\0' || (*filter == '*' && *++filter == '\0')) && *str == '\0');
    }

    enum ListFilesResult
    {
        LISTFILE_DIRECTORY_NOT_FOUND = 0,
        LISTFILE_OK = 1
    };

    inline ListFilesResult getDirContents(std::vector<std::string> &fileList, std::string dirpath = ".", std::string filter = "*")
    {
    #ifdef WIN32
        HANDLE hFind;
        WIN32_FIND_DATA findFileInfo;
        std::string directory;

        directory = dirpath + "/" + filter;

        hFind = FindFirstFile(directory.c_str(), &findFileInfo);

        if (hFind == INVALID_HANDLE_VALUE)
            return LISTFILE_DIRECTORY_NOT_FOUND;
        do
        {
            if ((findFileInfo.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
                fileList.push_back(std::string(findFileInfo.cFileName));
        }
        while (FindNextFile(hFind, &findFileInfo));

        FindClose(hFind);

    #else
        const char *p = dirpath.c_str();
        DIR * dirp = opendir(p);
        struct dirent * dp;

        while (dirp)
        {
            errno = 0;
            if ((dp = readdir(dirp)) != NULL)
            {
                if (matchWildcardFilter(filter.c_str(), dp->d_name))
                    fileList.push_back(std::string(dp->d_name));
            }
            else
                break;
        }

        if (dirp)
            closedir(dirp);
        else
            return LISTFILE_DIRECTORY_NOT_FOUND;
    #endif

        return LISTFILE_OK;
    }
}

#endif
