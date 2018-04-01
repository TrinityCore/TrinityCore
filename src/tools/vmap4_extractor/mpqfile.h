#define _CRT_SECURE_NO_DEPRECATE
#ifndef _CRT_SECURE_NO_WARNINGS // fuck the police^Wwarnings
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef MPQ_H
#define MPQ_H

#include <string.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <deque>
#include "StormLib.h"
#include "Define.h"

#ifdef _WIN32
#include <Windows.h>    // mainly only HANDLE definition is required
#endif

using namespace std;

class MPQFile
{
    //MPQHANDLE handle;
    bool eof;
    char *buffer;
    size_t pointer,size;

    // disable copying
    MPQFile(MPQFile const& f) = delete;
    void operator=(MPQFile const& f) = delete;

public:
    MPQFile(HANDLE mpq, char const* filename, bool warnNoExist = true);    // filenames are not case sensitive
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
