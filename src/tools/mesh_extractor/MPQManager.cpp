#include "MPQManager.h"
#include "MPQ.h"
#include "DBC.h"
#include "Utils.h"
#include <ace/Guard_T.h>

char const* MPQManager::Files[] = {
    "common.MPQ",
    "common-2.MPQ",
    "expansion.MPQ",
    "lichking.MPQ",
    "patch.MPQ",
    "patch-2.MPQ",
    "patch-3.MPQ"
};

char const* MPQManager::Languages[] = { "enGB", "enUS", "deDE", "esES", "frFR", "koKR", "zhCN", "zhTW", "enCN", "enTW", "esMX", "ruRU" };

void MPQManager::Initialize()
{
    InitializeDBC();
    uint32 size = sizeof(Files) / sizeof(char*);
    for (uint32 i = 0; i < size; ++i)
    {
        MPQArchive* arc = new MPQArchive(std::string("Data/" + std::string(Files[i])).c_str());
        Archives.push_front(arc); // MPQ files have to be transversed in reverse order to properly account for patched files
        printf("Opened %s\n", Files[i]);
    }
}

void MPQManager::InitializeDBC()
{
    BaseLocale = -1;
    std::string fileName;
    uint32 size = sizeof(Languages) / sizeof(char*);
    MPQArchive* _baseLocale = NULL;
    for (uint32 i = 0; i < size; ++i)
    {
        std::string _fileName = "Data/" + std::string(Languages[i]) + "/locale-" + std::string(Languages[i]) + ".MPQ";
        FILE* file = fopen(_fileName.c_str(), "rb");
        if (file)
        {
            if (BaseLocale == -1)
            {
                BaseLocale = i;
                _baseLocale = new MPQArchive(_fileName.c_str());
                fileName = _fileName;
                LocaleFiles[i] = _baseLocale;
            }
            else
                LocaleFiles[i] = new MPQArchive(_fileName.c_str());

            AvailableLocales.insert(i);
            printf("Detected locale: %s\n", Languages[i]);
        }
    }
    Archives.push_front(_baseLocale);
    if (BaseLocale == -1)
    {
        printf("No locale data detected. Please make sure that the executable is in the same folder as your WoW installation.\n");
        ASSERT(false);
    }
    else
        printf("Using default locale: %s\n", Languages[BaseLocale]);
}

FILE* MPQManager::GetFile(const std::string& path )
{
    ACE_GUARD_RETURN(ACE_Thread_Mutex, g, mutex, NULL);
    MPQFile file(path.c_str());
    if (file.isEof())
        return NULL;
    return file.GetFileStream();
}

DBC* MPQManager::GetDBC(const std::string& name )
{
    std::string path = "DBFilesClient\\" + name + ".dbc";
    return new DBC(GetFile(path));
}

FILE* MPQManager::GetFileFrom(const std::string& path, MPQArchive* file )
{
    ACE_GUARD_RETURN(ACE_Thread_Mutex, g, mutex, NULL);
    mpq_archive* mpq_a = file->mpq_a;

    uint32_t filenum;
    if(libmpq__file_number(mpq_a, path.c_str(), &filenum))
        return NULL;

    libmpq__off_t transferred;
    libmpq__off_t size = 0;
    libmpq__file_unpacked_size(mpq_a, filenum, &size);

    // HACK: in patch.mpq some files don't want to open and give 1 for filesize
    if (size <= 1)
        return NULL;

    uint8* buffer = new uint8[size];

    //libmpq_file_getdata
    libmpq__file_read(mpq_a, filenum, (unsigned char*)buffer, size, &transferred);

    // Pack the return into a FILE stream
    FILE* ret = tmpfile();
    if (!ret)
    {
        printf("Could not create temporary file. Please run as Administrator or root\n");
        exit(1);
    }
    fwrite(buffer, sizeof(uint8), size, ret);
    fseek(ret, 0, SEEK_SET);
    delete[] buffer;
    return ret;
}
