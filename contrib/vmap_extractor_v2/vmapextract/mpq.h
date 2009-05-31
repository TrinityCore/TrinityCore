#define _CRT_SECURE_NO_DEPRECATE

#ifndef MPQ_H
#define MPQ_H

#define __STORMLIB_SELF__

#include <string.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include "Stormlib.h"

using namespace std;

typedef unsigned int uint32;

class MPQArchive
{
    public:
	    HANDLE hMPQ;
	    MPQArchive(const char* filename);
	    void close();
        bool isOpen() const { return hMPQ != 0; }
};

typedef std::vector<MPQArchive> ArchiveSet;

class MPQArchiveSet
{
    public:
        MPQArchiveSet() {}
        ~MPQArchiveSet();

        bool Open(std::vector<std::string> const& archiveNames);

        ArchiveSet archives;
};

extern MPQArchiveSet gOpenArchives;

class MPQFile
{
    HANDLE hFile;
    HANDLE hMPQ;
    bool eof;
    char *buffer;
    size_t pointer,
    size;

    // disable copying
    //MPQFile(const MPQFile &f) {}
    //void operator=(const MPQFile &f) {}

public:
    MPQFile(const char* filename);
    ~MPQFile();
    size_t read(void* dest, size_t bytes);
    size_t getSize();
    size_t getPos();
    char* getBuffer();
    char* getPointer();
    bool isEof();
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
