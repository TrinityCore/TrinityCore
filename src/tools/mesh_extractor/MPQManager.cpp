#include "MPQManager.h"
#include "MPQ.h"

char* MPQManager::Files[] = { 
    "common.MPQ",
    "common-2.MPQ",
    "expansion.MPQ",
    "lichking.MPQ",
    "patch.MPQ",
    "patch-2.MPQ",
    "patch-3.MPQ"
};

void MPQManager::Initialize()
{
    LoadMPQs();
}

void MPQManager::LoadMaps()
{

}

void MPQManager::LoadMPQs()
{
    // Load the locale MPQ files first
    char filename[512];

    /*sprintf(filename,"Data/%s/locale-%s.MPQ", langs[locale], langs[locale]);*/
    Archives.push_front(new MPQArchive("Data/enUS/locale-enUS.MPQ"));

    for(int i = 0; i < 3; ++i)
    {
        char ext[3] = "";
        if (i)
            sprintf(ext, "-%i", i + 1);

        sprintf(filename, "Data/enUS/patch-enUS%s.MPQ", ext);
        Archives.push_front(new MPQArchive(filename));
    }

    // Now load the common MPQ files
    int count = sizeof(Files) / sizeof(char*);
    for (int i = 0; i < count; ++i)
    {
        sprintf(filename, "Data/%s", Files[i]);
        Archives.push_front(new MPQArchive(filename));
    }
    printf("Loaded %u MPQ files succesfully\n", Archives.size());
}

FILE* MPQManager::GetFile( std::string path )
{
    MPQFile file(path.c_str());
    if (file.isEof())
        return NULL;
    return file.GetFileStream();
}
