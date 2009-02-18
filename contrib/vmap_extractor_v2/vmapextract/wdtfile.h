#ifndef WDTFILE_H
#define WDTFILE_H

#define __STORMLIB_SELF__

#include "mpq.h"
#include "adtfile.h"
#include "wmo.h"
#include <string>
#include "stdlib.h"

class WDTFile
{
public:
    WDTFile(char* file_name, char* file_name1);
    ~WDTFile(void);
    bool init(char *map_id);

    string* gWmoInstansName;
    int gnWMO, nMaps;

    ADTFile* GetMap(int x, int z);

private:
    MPQFile WDT;
    bool maps[64][64];
    string filename;
};

#endif

