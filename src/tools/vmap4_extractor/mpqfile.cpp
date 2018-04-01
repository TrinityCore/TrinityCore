#include "mpqfile.h"
#include <deque>
#include <cstdio>
#include "StormLib.h"

MPQFile::MPQFile(HANDLE mpq, char const* filename, bool warnNoExist /*= true*/) :
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    HANDLE file;
    if (!SFileOpenFileEx(mpq, filename, SFILE_OPEN_PATCHED_FILE, &file))
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
    if (!SFileReadFile(file, buffer, size, &read) || size != read)
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
