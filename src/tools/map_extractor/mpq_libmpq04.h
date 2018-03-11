/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef MPQ_H
#define MPQ_H

#include "loadlib/loadlib.h"
#include "libmpq/mpq.h"
#include <string.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <deque>

class MPQArchive
{

public:
    mpq_archive_s *mpq_a;

    MPQArchive(char const* filename);
    ~MPQArchive() { close(); }
    void close();

    void GetFileListTo(std::vector<std::string>& filelist) {
        uint32_t filenum;
        if(libmpq__file_number(mpq_a, "(listfile)", &filenum)) return;
        libmpq__off_t size, transferred;
        libmpq__file_size_unpacked(mpq_a, filenum, &size);

        char *buffer = new char[size+1];
        buffer[size] = '\0';

        libmpq__file_read(mpq_a, filenum, (unsigned char*)buffer, size, &transferred);

        char seps[] = "\n";
        char *token;

        token = strtok( buffer, seps );
        uint32 counter = 0;
        while ((token != nullptr) && (counter < size)) {
            //cout << token << endl;
            token[strlen(token) - 1] = 0;
            std::string s = token;
            filelist.push_back(s);
            counter += strlen(token) + 2;
            token = strtok(nullptr, seps);
        }

        delete[] buffer;
    }
};
typedef std::deque<MPQArchive*> ArchiveSet;

class MPQFile
{
    //MPQHANDLE handle;
    bool eof;
    char *buffer;
    libmpq__off_t pointer,size;

    // disable copying
    MPQFile(MPQFile const& /*f*/) = delete;
    void operator=(MPQFile const& /*f*/) = delete;

public:
    MPQFile(char const* filename);    // filenames are not case sensitive
    ~MPQFile() { close(); }
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
    char t;
    t=fcc[0];
    fcc[0]=fcc[3];
    fcc[3]=t;
    t=fcc[1];
    fcc[1]=fcc[2];
    fcc[2]=t;
}

#endif
