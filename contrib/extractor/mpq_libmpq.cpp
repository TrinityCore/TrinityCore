#include "mpq_libmpq.h"
#include <deque>

ArchiveSet gOpenArchives;

MPQArchive::MPQArchive(const char* filename)
{
    int result = libmpq_archive_open(&mpq_a, (unsigned char*)filename);
    printf("Opening %s\n", filename);
    if(result) {
        switch(result) {
            case LIBMPQ_EFILE :                   /* error on file operation */
                printf("Error opening archive '%s': File operation Error\n", filename);
                break;
            case LIBMPQ_EFILE_FORMAT :            /* bad file format */
                printf("Error opening archive '%s': Bad file format\n", filename);
                break;
            case LIBMPQ_EFILE_CORRUPT :           /* file corrupt */
                printf("Error opening archive '%s': File corrupt\n", filename);
                break;
            case LIBMPQ_EFILE_NOT_FOUND :         /* file in archive not found */
                printf("Error opening archive '%s': File in archive not found\n", filename);
                break;
            case LIBMPQ_EFILE_READ :              /* Read error in archive */
                printf("Error opening archive '%s': Read error in archive\n", filename);
                break;
            case LIBMPQ_EALLOCMEM :               /* maybe not enough memory? :) */
                printf("Error opening archive '%s': Maybe not enough memory\n", filename);
                break;
            case LIBMPQ_EFREEMEM :                /* can not free memory */
                printf("Error opening archive '%s': Cannot free memory\n", filename);
                break;
            case LIBMPQ_EINV_RANGE :              /* Given filenumber is out of range */
                printf("Error opening archive '%s': Given filenumber is out of range\n", filename);
                break;
            case LIBMPQ_EHASHTABLE :              /* error in reading hashtable */
                printf("Error opening archive '%s': Error in reading hashtable\n", filename);
                break;
            case LIBMPQ_EBLOCKTABLE :             /* error in reading blocktable */
                printf("Error opening archive '%s': Error in reading blocktable\n", filename);
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
    libmpq_archive_close(&mpq_a);
}

MPQFile::MPQFile(const char* filename):
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    for(ArchiveSet::iterator i=gOpenArchives.begin(); i!=gOpenArchives.end();++i)
    {
        mpq_archive &mpq_a = (*i)->mpq_a;

        mpq_hash hash = (*i)->GetHashEntry(filename);
        uint32 blockindex = hash.blockindex;

        if ((blockindex == 0xFFFFFFFF) || (blockindex == 0)) {
            continue; //file not found
        }

        uint32 fileno = blockindex;

        //int fileno = libmpq_file_number(&mpq_a, filename);
        //if(fileno == LIBMPQ_EFILE_NOT_FOUND)
        //    continue;

        // Found!
        size = libmpq_file_info(&mpq_a, LIBMPQ_FILE_UNCOMPRESSED_SIZE, fileno);
        // HACK: in patch.mpq some files don't want to open and give 1 for filesize
        if (size<=1) {
            eof = true;
            buffer = 0;
            return;
        }
        buffer = new char[size];

        //libmpq_file_getdata
        libmpq_file_getdata(&mpq_a, hash, fileno, (unsigned char*)buffer);
        return;

    }
    eof = true;
    buffer = 0;
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
