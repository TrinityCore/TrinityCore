#ifndef WDTFILE_H
#define WDTFILE_H

#include "mpq_libmpq04.h"
#include "wmo.h"
#include <string>
#include "stdlib.h"

class ADTFile;

class WDTFile
{
private:
    MPQFile WDT;
    string filename;
public:
    WDTFile(char* file_name, char* file_name1);
    ~WDTFile(void);
    bool init(char* map_id, unsigned int mapID);

    string* gWmoInstansName;
    int gnWMO;

    ADTFile* GetMap(int x, int z);
};

#endif
