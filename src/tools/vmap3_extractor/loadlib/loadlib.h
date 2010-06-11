#ifndef LOAD_LIB_H
#define LOAD_LIB_H

#ifdef WIN32
typedef __int64            int64;
typedef long               int32;
typedef short              int16;
typedef char               int8;
typedef unsigned __int64   uint64;
typedef unsigned long      uint32;
typedef unsigned short     uint16;
typedef unsigned char      uint8;
#else
#include <stdint.h>
#ifndef uint64_t 
#include <linux/types.h> 
#endif
typedef int64_t            int64;
typedef long               int32;
typedef short              int16;
typedef char               int8;
typedef uint64_t           uint64;
typedef unsigned long      uint32;
typedef unsigned short     uint16;
typedef unsigned char      uint8;
#endif

#define FILE_FORMAT_VERSION    18

//
// File version chunk
//
struct file_MVER
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    uint32 ver;
};

class FileLoader{
    uint8  *data;
    uint32  data_size;
public:
    virtual bool prepareLoadedData();
    uint8 *GetData()     {return data;}
    uint32 GetDataSize() {return data_size;}

    file_MVER *version;
    FileLoader();
    ~FileLoader();
    bool loadFile(char *filename, bool log = true);
    virtual void free();
};
#endif
