#include "cascfile.h"
#include <deque>
#include <cstdio>

CASCFile::CASCFile(CASC::StorageHandle const& casc, const char* filename, bool warnNoExist /*= true*/) :
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    CASC::FileHandle file = CASC::OpenFile(casc, filename, CASC_LOCALE_ALL, false);
    if (!file)
    {
        if (warnNoExist || GetLastError() != ERROR_FILE_NOT_FOUND)
            fprintf(stderr, "Can't open %s, err=%u!\n", filename, GetLastError());
        eof = true;
        return;
    }

    DWORD hi = 0;
    size = CASC::GetFileSize(file, &hi);

    if (hi)
    {
        fprintf(stderr, "Can't open %s, size[hi] = %u!\n", filename, uint32(hi));
        eof = true;
        return;
    }

    if (size <= 1)
    {
        fprintf(stderr, "Can't open %s, size = %u!\n", filename, uint32(size));
        eof = true;
        return;
    }

    DWORD read = 0;
    buffer = new char[size];
    if (!CASC::ReadFile(file, buffer, size, &read) || size != read)
    {
        fprintf(stderr, "Can't read %s, size=%u read=%u!\n", filename, uint32(size), uint32(read));
        eof = true;
        return;
    }
}

size_t CASCFile::read(void* dest, size_t bytes)
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

void CASCFile::seek(int offset)
{
    pointer = offset;
    eof = (pointer >= size);
}

void CASCFile::seekRelative(int offset)
{
    pointer += offset;
    eof = (pointer >= size);
}

void CASCFile::close()
{
    if (buffer) delete[] buffer;
    buffer = 0;
    eof = true;
}
