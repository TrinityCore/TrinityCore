#include "MPQManager.h"
#include "MPQ.h"
#include "DBC.h"
#include "Utils.h"

char* MPQManager::Files[] = { 
    "common.MPQ",
    "common-2.MPQ",
    "expansion.MPQ",
    "lichking.MPQ",
    "patch.MPQ",
    "patch-2.MPQ",
    "patch-3.MPQ"
};

char* MPQManager::Languages[] = { "esES", "enUS", "enGB", "esMX", "deDE" };

void MPQManager::Initialize()
{
    InitializeDBC();
    uint32 size = sizeof(Files) / sizeof(char*);
    for (uint32 i = 0; i < size; ++i)
    {
        MPQArchive* arc = new MPQArchive(std::string("Data/" + std::string(Files[i])).c_str());
        Archives.push_front(arc);
        printf("Opened %s\n", Files[i]);
    }
}

void MPQManager::LoadMaps()
{
    DBC* file = GetDBC("Map");
    printf("NAME %s\n", file->GetRecordById(608)->GetString(1).c_str());
}

void MPQManager::InitializeDBC()
{
    CurLocale = 0;
    std::string fileName;
    uint32 size = sizeof(Languages) / sizeof(char*);
    for (uint32 i = 0; i < size; ++i)
    {
        fileName = "Data/" + std::string(Languages[i]) + "/locale-" + std::string(Languages[i]) + ".MPQ";
        FILE* file = fopen(fileName.c_str(), "rb");
        if (file)
        {
            CurLocale = i;
            break;
        }
    }
    Archives.push_front(new MPQArchive(fileName.c_str()));
    printf("Using locale: %s\n", Languages[CurLocale]);
}

FILE* MPQManager::GetFile( std::string path )
{
    MPQFile file(path.c_str());
    if (file.isEof())
        return NULL;
    return file.GetFileStream();
}

DBC* MPQManager::GetDBC( std::string name )
{
    std::string path = "DBFilesClient\\" + name + ".dbc";
    return new DBC(GetFile(path));
}
