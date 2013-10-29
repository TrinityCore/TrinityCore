/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "MPQManager.h"
#include "MPQ.h"
#include "DBC.h"
#include "Utils.h"
#include "Stream.h"
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

char const* MPQManager::LocalePatchFiles[] = {
    "Data/%s/patch-%s.MPQ",
    "Data/%s/patch-%s-2.MPQ",
    "Data/%s/patch-%s-3.MPQ"
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
    uint32 size = sizeof(Languages) / sizeof(char*);
    MPQArchive* _baseLocale = NULL;
    for (uint32 i = 0; i < size; ++i)
    {
        std::string _fileName = "Data/" + std::string(Languages[i]) + "/locale-" + std::string(Languages[i]) + ".MPQ";
        FILE* file = fopen(_fileName.c_str(), "rb");
        if (file)
        {
            if (BaseLocale == -1)
                BaseLocale = i;

            // Load the base locale file
            MPQArchive* arch = new MPQArchive(_fileName.c_str());
            LocaleFiles[i].push_front(arch);
            
            Archives.push_front(arch); // For lookup in GetFile

            // Load the locale patches
            for (uint32 j = 0; j < sizeof(LocalePatchFiles) / sizeof(char*); ++j)
            {
                char patchName[100];
                sprintf(patchName, LocalePatchFiles[j], Languages[i], Languages[i]);
                FILE* patch = fopen(patchName, "rb");
                if (file)
                {
                    MPQArchive* archP = new MPQArchive(patchName);
                    LocaleFiles[i].push_front(archP);
                    Archives.push_front(archP); // For lookup in GetFile
                    fclose(patch);
                }
            }

            AvailableLocales.insert(i);
            printf("Detected locale: %s\n", Languages[i]);
        }
    }

    if (BaseLocale == -1)
    {
        printf("No locale data detected. Please make sure that the executable is in the same folder as your WoW installation.\n");
        ASSERT(false);
    }
    else
        printf("Using default locale: %s\n", Languages[BaseLocale]);
}

Stream* MPQManager::GetFile(const std::string& path )
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

Stream* MPQManager::GetFileFromLocale( const std::string& path, uint32 locale )
{
    ACE_GUARD_RETURN(ACE_Thread_Mutex, g, mutex, NULL);
    std::deque<MPQArchive*> files = LocaleFiles[locale];
    Stream* ret = NULL;
    for (std::deque<MPQArchive*>::iterator itr = files.begin(); itr != files.end(); ++itr)
    {
        mpq_archive* mpq_a = (*itr)->mpq_a;

        uint32_t filenum;
        if(libmpq__file_number(mpq_a, path.c_str(), &filenum))
            continue;
        libmpq__off_t transferred;
        libmpq__off_t size = 0;
        libmpq__file_unpacked_size(mpq_a, filenum, &size);

        // HACK: in patch.mpq some files don't want to open and give 1 for filesize
        if (size <= 1)
            continue;

        char* buffer = new char[size];

        //libmpq_file_getdata
        libmpq__file_read(mpq_a, filenum, (unsigned char*)buffer, size, &transferred);
        
        ret = new Stream(buffer, size);

        delete[] buffer;
        break;
    }
    return ret;
}

Stream* MPQManager::GetFileFrom(const std::string& path, MPQArchive* file )
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
    Stream* ret = new Stream((char*)buffer, size);
    delete[] buffer;
    return ret;
}
