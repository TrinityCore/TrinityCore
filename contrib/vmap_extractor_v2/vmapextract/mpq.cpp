#include "mpq.h"
//#include <vector>
#include "Stormlib.h"
#define __STORMLIB_SELF__

typedef std::vector<MPQArchive*> ArchiveSet;
ArchiveSet gOpenArchives;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
MPQArchive::MPQArchive(const char* filename)
{
    BOOL succ = SFileOpenArchive(filename, 0, 0,&hMPQ);
    if (succ)
    {
        MPQArchive*ar = (MPQArchive*)(hMPQ);
        printf("Opening %s\n", filename);
        gOpenArchives.push_back(ar);
        succ = true;

    }
    else
    {
        printf("Error!!!Not open archive %s\n", filename);
    }
}

void MPQArchive::close()
{
    SFileCloseArchive(hMPQ);
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
MPQFile::MPQFile(const char* filename):
    eof(false),
    buffer(0),
    pointer(0),
    size(0)
{
    for(ArchiveSet::iterator i=gOpenArchives.begin(); i!=gOpenArchives.end();++i)
    {

     HANDLE hFile = "";
     MPQArchive*(hMPQ) = *i;
     BOOL succ = SFileOpenFileEx(hMPQ,filename,0, &hFile);
       if (succ)
       {
         DWORD s = SFileGetFileSize(hFile, 0);
         if (!s)
         {
            eof = true;
            buffer = 0;
            return;
         }
         size = (size_t)s;
         buffer = new char[s];
         SFileReadFile(hFile, buffer, s, 0, 0);
         SFileCloseFile(hFile);

         eof = false;
         return;
       }
    }

    eof = true;
    buffer = 0;

}

MPQFile::~MPQFile()
{
    close();
}

size_t MPQFile::read(void* dest, size_t bytes)
{
    if (eof)
    return 0;

    size_t rpos = pointer + bytes;
    if (rpos > size)
    {
        bytes = size - pointer;
        eof = true;
    }

    memcpy(dest, &(buffer[pointer]), bytes);

    pointer = rpos;

    return bytes;
}

bool MPQFile::isEof()
{
    return eof;
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
    if (buffer)
    delete[] buffer;
    buffer = 0;
    eof = true;
}

size_t MPQFile::getSize()
{
    return size;
}

size_t MPQFile::getPos()
{
    return pointer;
}

char* MPQFile::getBuffer()
{
    return buffer;
}

char* MPQFile::getPointer()
{
    return buffer + pointer;
}


