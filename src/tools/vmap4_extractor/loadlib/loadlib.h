/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef LOAD_LIB_H
#define LOAD_LIB_H

#ifdef WIN32
typedef __int64            int64;
typedef __int32            int32;
typedef __int16            int16;
typedef __int8             int8;
typedef unsigned __int64   uint64;
typedef unsigned __int32   uint32;
typedef unsigned __int16   uint16;
typedef unsigned __int8    uint8;
#else
#include <stdint.h>
#ifndef uint64_t
#ifdef __linux__
#include <linux/types.h>
#endif
#endif
typedef int64_t            int64;
typedef int32_t            int32;
typedef int16_t            int16;
typedef int8_t             int8;
typedef uint64_t           uint64;
typedef uint32_t           uint32;
typedef uint16_t           uint16;
typedef uint8_t            uint8;
#endif

#define FILE_FORMAT_VERSION    18

//
// File version chunk
//
struct file_MVER
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    uint32 ver;
};

class FileLoader{
    uint8  *data;
    uint32  data_size;
public:
    virtual bool prepareLoadedData();
    uint8 *GetData()     {return data;}
    uint32 GetDataSize() {return data_size;}

    file_MVER *version;
    FileLoader();
    ~FileLoader();
    bool loadFile(char *filename, bool log = true);
    virtual void free();
};
#endif
