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

#ifndef _MMAP_COMMON_H
#define _MMAP_COMMON_H

#include "Define.h"
#include <memory>
#include <string>
#include <vector>

#ifndef _WIN32
    #include <cstddef>
    #include <cstring>
    #include <dirent.h>
#else
    #include <Windows.h>
#endif

#ifndef _WIN32
    #include <cerrno>
#endif

namespace MMAP
{
    struct OffMeshConnection
    {
        OffMeshConnection() {}

        OffMeshConnection(uint32 mapID, uint32 tileX, uint32 tileY, float startX, float startY, float startZ,
            float endX, float endY, float endZ, uint32 agentSize)
        {
            m_mapID = mapID;
            m_tileX = tileX;
            m_tileY = tileY;
            m_start[0] = startX;
            m_start[1] = startY;
            m_start[2] = startZ;
            m_end[0] = endX;
            m_end[1] = endY;
            m_end[2] = endZ;
            m_agentSize = agentSize;
        }

        uint32 m_mapID;
        uint32 m_tileX;
        uint32 m_tileY;
        float m_start[3];
        float m_end[3];
        uint32 m_agentSize;
    };

    static const std::vector<OffMeshConnection> DefaultOffMeshConnections =
    {
        { 0, 31, 59, -14429.889648f, 450.344452f, 15.430828f, -14424.218750f, 444.332855f, 12.773965f, 2 }, // booty bay dock
        { 562, 31, 20, 6234.545898f, 256.902100f, 11.075373f, 6230.961914f, 252.127274f, 11.180979f, 2 },   // Blade's Edge Arena
        { 562, 31, 20, 6243.081543f, 266.918854f, 11.059557f, 6246.507324f, 271.623505f, 11.230524f, 2 }   // Blade's Edge Arena
        //{ 562, 31, 20, 6230.59f, 251.90f, 11.19f, 6234.70f, 257.03f, 11.07f, 1 },
        //{ 562, 31, 20, 6246.68f, 271.90f, 11.23f, 6242.68f, 267.07f, 11.09f, 1 }
    };

    inline bool matchWildcardFilter(char const* filter, char const* str)
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
            if ((dp = readdir(dirp)) != nullptr)
            {
                if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0 && matchWildcardFilter(filter.c_str(), dp->d_name))
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
