#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#ifndef MPQ_H
#define MPQ_H

#include "libmpq/mpq.h"
#include <string.h>
#include <ctype.h>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

typedef unsigned int uint32;
class MPQArchive
{

public:
    mpq_archive mpq_a;

    MPQArchive(const char* filename);
    void close();

    uint32 HashString(const char* Input, uint32 Offset) {
        uint32 seed1 = 0x7fed7fed;
        uint32 seed2 = 0xeeeeeeee;

        for (uint32 i = 0; i < strlen(Input); i++) {
            uint32 val = toupper(Input[i]);
            seed1 = mpq_a.buf[Offset + val] ^ (seed1 + seed2);
            seed2 = val + seed1 + seed2 + (seed2 << 5) + 3;
        }

        return seed1;
    }
    mpq_hash GetHashEntry(const char* Filename) {
        uint32 index = HashString(Filename, 0);
        index &= mpq_a.header->hashtablesize - 1;
        uint32 name1 = HashString(Filename, 0x100);
        uint32 name2 = HashString(Filename, 0x200);

        for(uint32 i = index; i < mpq_a.header->hashtablesize; ++i) {
            mpq_hash hash = mpq_a.hashtable[i];
            if (hash.name1 == name1 && hash.name2 == name2) return hash;
        }

        mpq_hash nullhash;
        nullhash.blockindex = 0xFFFFFFFF;
        return nullhash;
    }

    void GetFileListTo(vector<string>& filelist) {
        mpq_hash hash = GetHashEntry("(listfile)");
        uint32 blockindex = hash.blockindex;

        if ((blockindex == 0xFFFFFFFF) || (blockindex == 0))
            return;

        uint32 size = libmpq_file_info(&mpq_a, LIBMPQ_FILE_UNCOMPRESSED_SIZE, blockindex);
        char *buffer = new char[size];

        libmpq_file_getdata(&mpq_a, hash, blockindex, (unsigned char*)buffer);

        char seps[] = "\n";
        char *token;

        token = strtok( buffer, seps );
        uint32 counter = 0;
        while ((token != NULL) && (counter < size)) {
            //cout << token << endl;
            token[strlen(token) - 1] = 0;
            string s = token;
            filelist.push_back(s);
            counter += strlen(token) + 2;
            token = strtok(NULL, seps);
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
    size_t pointer,size;

    // disable copying
    MPQFile(const MPQFile &f) {}
    void operator=(const MPQFile &f) {}

public:
    MPQFile(const char* filename);    // filenames are not case sensitive
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
