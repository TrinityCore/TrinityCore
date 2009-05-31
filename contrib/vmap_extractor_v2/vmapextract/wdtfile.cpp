#define __STORMLIB_SELF__

#include "wdtfile.h"
#include "adtfile.h"

char * wdtGetPlainName(char * FileName)
{
    char * szTemp;

    if((szTemp = strrchr(FileName, '\\')) != NULL)
        FileName = szTemp + 1;
    return FileName;
}

WDTFile::WDTFile(char* file_name, char* file_name1):WDT(file_name)
{
    filename.append(file_name1,strlen(file_name1));
}

bool WDTFile::init(char *map_id)
{
    if (WDT.isEof())
    {
        //printf("Can't find WDT file.\n");
        return false;
    }

    char fourcc[5];
    size_t size;

    const char dirname[] = "buildings\\dir";
    FILE *dirfile;
    dirfile = fopen(dirname, "ab");
    if(!dirfile)
    {
        printf("Can't open dirfile!'%s'\n");
        return false;
    }

    while (!WDT.isEof())
    {
        WDT.read(fourcc,4);
        WDT.read(&size, 4);

        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = WDT.getPos() + size;

        if (!strcmp(fourcc,"MAIN"))
        {
        }
        if (!strcmp(fourcc,"MWMO"))
        {
            // global map objects
            if (size)
            {
                char *buf = new char[size];
                WDT.read(buf, size);
                char *p=buf;
                int q = 0;
                gWmoInstansName = new string[size];
                while (p<buf+size)
                {
                    string path(p);
                    char* s=wdtGetPlainName(p);
                    fixnamen(s,strlen(s));
                    p=p+strlen(p)+1;
                    gWmoInstansName[q++] = s;
                }
                delete[] buf;
            }
        }
        else if (!strcmp(fourcc,"MODF"))
        {
            // global wmo instance data
            if (size)
            {
                gnWMO = (int)size / 64;
                string gWMO_mapname;
                string fake_mapname;
                fake_mapname = "65 65 ";
                //gWMO_mapname = fake_mapname + filename;
                gWMO_mapname = fake_mapname + std::string(map_id);
                for (int i=0; i<gnWMO; ++i)
                {
                    int id;
                    WDT.read(&id, 4);
                    WMOInstance inst(WDT,gWmoInstansName[id].c_str(),gWMO_mapname.c_str(), dirfile);
                }
                delete[] gWmoInstansName;
            }
        }
        WDT.seek((int)nextpos);
    }

    WDT.close();
    fclose(dirfile);
    return true;
}

WDTFile::~WDTFile(void)
{
    WDT.close();
}

ADTFile* WDTFile::GetMap(int x, int z)
{
    if(!(x>=0 && z >= 0 && x<64 && z<64))
        return NULL;

    char name[512];

    sprintf(name,"World\\Maps\\%s\\%s_%d_%d.adt", filename.c_str(), filename.c_str(), x, z);
    return new ADTFile(name);
}
