/*
 * Copyright (C) 2011-2016 ArkCORE <http://www.arkania.net/>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "mpqfile.h"
#include <deque>
#include <cstdio>
#include "StormLib.h"

MPQFile::MPQFile(HANDLE mpq, const char* filename, bool warnNoExist /*= true*/) :
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    HANDLE file;
    if (!SFileOpenFileEx(mpq, filename, SFILE_OPEN_FROM_MPQ, &file))
    {
        if (warnNoExist || GetLastError() != ERROR_FILE_NOT_FOUND)
            fprintf(stderr, "Can't open %s, err=%u!\n", filename, GetLastError());
        eof = true;
        return;
    }

    DWORD hi = 0;
    size = SFileGetFileSize(file, &hi);

    if (hi)
    {
        fprintf(stderr, "Can't open %s, size[hi] = %u!\n", filename, uint32(hi));
        SFileCloseFile(file);
        eof = true;
        return;
    }

    if (size <= 1)
    {
        fprintf(stderr, "Can't open %s, size = %u!\n", filename, uint32(size));
        SFileCloseFile(file);
        eof = true;
        return;
    }

    DWORD read = 0;
    buffer = new char[size];
    if (!SFileReadFile(file, buffer, size, &read, NULL) || size != read)
    {
        fprintf(stderr, "Can't read %s, size=%u read=%u!\n", filename, uint32(size), uint32(read));
        SFileCloseFile(file);
        eof = true;
        return;
    }

    SFileCloseFile(file);
}

size_t MPQFile::read(void* dest, size_t bytes)
{
    if (eof) return 0;

    size_t rpos = pointer + bytes;
    if (rpos > size) {
        bytes = size - pointer;
        eof = true;
    }

    memcpy(dest, &(buffer[pointer]), bytes);

    pointer = rpos;

    return bytes;
}

void MPQFile::seek(int offset)
{
    pointer = offset;
    eof = (pointer >= size);
}

void MPQFile::seekRelative(int offset)
{
    pointer += offset;
    eof = (pointer >= size);
}

void MPQFile::close()
{
    if (buffer) delete[] buffer;
    buffer = 0;
    eof = true;
}
