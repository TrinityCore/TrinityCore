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

#include "mpq_libmpq04.h"
#include <deque>
#include <cstdio>

ArchiveSet gOpenArchives;

MPQArchive::MPQArchive(char const* filename)
{
    int result = libmpq__archive_open(&mpq_a, filename, -1);
    printf("Opening %s\n", filename);
    if(result) {
        switch(result) {
            case LIBMPQ_ERROR_OPEN :
                printf("Error opening archive '%s': Does file really exist?\n", filename);
                break;
            case LIBMPQ_ERROR_FORMAT :            /* bad file format */
                printf("Error opening archive '%s': Bad file format\n", filename);
                break;
            case LIBMPQ_ERROR_SEEK :         /* seeking in file failed */
                printf("Error opening archive '%s': Seeking in file failed\n", filename);
                break;
            case LIBMPQ_ERROR_READ :              /* Read error in archive */
                printf("Error opening archive '%s': Read error in archive\n", filename);
                break;
            case LIBMPQ_ERROR_MALLOC :               /* maybe not enough memory? :) */
                printf("Error opening archive '%s': Maybe not enough memory\n", filename);
                break;
            default:
                printf("Error opening archive '%s': Unknown error\n", filename);
                break;
        }
        return;
    }
    gOpenArchives.push_front(this);
}

void MPQArchive::close()
{
    //gOpenArchives.erase(erase(&mpq_a);
    libmpq__archive_close(mpq_a);
}

MPQFile::MPQFile(char const* filename):
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    for(ArchiveSet::iterator i=gOpenArchives.begin(); i!=gOpenArchives.end();++i)
    {
        mpq_archive *mpq_a = (*i)->mpq_a;

        uint32_t filenum;
        if(libmpq__file_number(mpq_a, filename, &filenum)) continue;
        libmpq__off_t transferred;
        libmpq__file_size_unpacked(mpq_a, filenum, &size);

        // HACK: in patch.mpq some files don't want to open and give 1 for filesize
        if (size<=1) {
//            printf("warning: file %s has size %d; cannot read.\n", filename, size);
            eof = true;
            buffer = 0;
            return;
        }
        buffer = new char[size];

        //libmpq_file_getdata
        libmpq__file_read(mpq_a, filenum, (unsigned char*)buffer, size, &transferred);
        /*libmpq_file_getdata(&mpq_a, hash, fileno, (unsigned char*)buffer);*/
        return;

    }
    eof = true;
    buffer = 0;
}

size_t MPQFile::read(void* dest, size_t bytes)
{
    if (eof) return 0;

    size_t rpos = pointer + bytes;
    if (rpos > size_t(size)) {
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
