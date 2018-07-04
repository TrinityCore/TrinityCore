/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#define _CRT_SECURE_NO_DEPRECATE
#ifndef _CRT_SECURE_NO_WARNINGS // fuck the police^Wwarnings
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef MPQ_H
#define MPQ_H

#include "Define.h"
#include "CascHandles.h"
#include <utility>

class CASCFile
{
    bool eof;
    char *buffer;
    size_t pointer,size;

    // disable copying
    CASCFile(const CASCFile &f) = delete;
    CASCFile& operator=(const CASCFile &f) = delete;

public:
    CASCFile(CASC::StorageHandle const& casc, const char* filename, bool warnNoExist = true);    // filenames are not case sensitive
    ~CASCFile() { close(); }
    size_t read(void* dest, size_t bytes);
    size_t getSize() { return size; }
    size_t getPos() { return pointer; }
    char* getBuffer() { return buffer; }
    char* getPointer() { return buffer + pointer; }
    bool isEof() { return eof; }
    void seek(int offset);
    void seekRelative(int offset);
    void close();
};

inline void flipcc(char *fcc)
{
    std::swap(fcc[0], fcc[3]);
    std::swap(fcc[1], fcc[2]);
}

#endif
