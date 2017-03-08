/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
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

#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <errno.h>

#ifdef WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #include <sys/stat.h>
    #include <direct.h>
    #define mkdir _mkdir
#else
    #include <sys/stat.h>
    #define ERROR_PATH_NOT_FOUND ERROR_FILE_NOT_FOUND
#endif

#include <map>
#include <fstream>

#include "Common.h"
//From Extractor
#include "adtfile.h"
#include "wdtfile.h"
#include "DB2.h"
#include "wmo.h"
#include "cascfile.h"

#include "vmapexport.h"
#include "Banner.h"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

//------------------------------------------------------------------------------
// Defines

#define MPQ_BLOCK_SIZE 0x1000

//-----------------------------------------------------------------------------

CASC::StorageHandle CascStorage;

typedef struct
{
    char name[64];
    unsigned int id;
}map_id;

std::vector<map_id> map_ids;
std::vector<uint16> LiqType;
uint32 map_count;
boost::filesystem::path input_path;
bool preciseVectorData = false;

struct LiquidTypeMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "sifffffsifihhbbbbbi";
        static uint8 const arraySizes[19] = { 1, 1, 1, 1, 1, 1, 1, 6, 2, 18, 4, 1, 1, 1, 1, 1, 1, 6, 1 };
        static DB2Meta instance(-1, 19, 0x99FC34E5, types, arraySizes);
        return &instance;
    }
};

struct MapMeta
{
    static DB2Meta const* Instance()
    {
        static char const* types = "siffssshhhhhhhbbbbb";
        static uint8 const arraySizes[19] = { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
        static DB2Meta instance(-1, 19, 0xF7CF2DA2, types, arraySizes);
        return &instance;
    }
};

// Constants

//static const char * szWorkDirMaps = ".\\Maps";
const char* szWorkDirWmo = "./Buildings";
const char* szRawVMAPMagic = "VMAP044";

#define CASC_LOCALES_COUNT 17
char const* CascLocaleNames[CASC_LOCALES_COUNT] =
{
    "none", "enUS",
    "koKR", "unknown",
    "frFR", "deDE",
    "zhCN", "esES",
    "zhTW", "enGB",
    "enCN", "enTW",
    "esMX", "ruRU",
    "ptBR", "itIT",
    "ptPT"
};

uint32 WowLocaleToCascLocaleFlags[12] =
{
    CASC_LOCALE_ENUS | CASC_LOCALE_ENGB,
    CASC_LOCALE_KOKR,
    CASC_LOCALE_FRFR,
    CASC_LOCALE_DEDE,
    CASC_LOCALE_ZHCN,
    CASC_LOCALE_ZHTW,
    CASC_LOCALE_ESES,
    CASC_LOCALE_ESMX,
    CASC_LOCALE_RURU,
    0,
    CASC_LOCALE_PTBR | CASC_LOCALE_PTPT,
    CASC_LOCALE_ITIT,
};

namespace
{
    const char* HumanReadableCASCError(int error)
    {
        switch (error)
        {
        case ERROR_SUCCESS: return "SUCCESS";
        case ERROR_FILE_CORRUPT: return "FILE_CORRUPT";
        case ERROR_CAN_NOT_COMPLETE: return "CAN_NOT_COMPLETE";
        case ERROR_HANDLE_EOF: return "HANDLE_EOF";
        case ERROR_NO_MORE_FILES: return "NO_MORE_FILES";
        case ERROR_BAD_FORMAT: return "BAD_FORMAT";
        case ERROR_INSUFFICIENT_BUFFER: return "INSUFFICIENT_BUFFER";
        case ERROR_ALREADY_EXISTS: return "ALREADY_EXISTS";
        case ERROR_DISK_FULL: return "DISK_FULL";
        case ERROR_INVALID_PARAMETER: return "INVALID_PARAMETER";
        case ERROR_NOT_SUPPORTED: return "NOT_SUPPORTED";
        case ERROR_NOT_ENOUGH_MEMORY: return "NOT_ENOUGH_MEMORY";
        case ERROR_INVALID_HANDLE: return "INVALID_HANDLE";
        case ERROR_ACCESS_DENIED: return "ACCESS_DENIED";
        case ERROR_FILE_NOT_FOUND: return "FILE_NOT_FOUND";
        default: return "UNKNOWN";
        }
    }
}

uint32 ReadBuild(int locale)
{
    // include build info file also
    std::string filename = std::string("component.wow-") + localeNames[locale] + ".txt";
    //printf("Read %s file... ", filename.c_str());

    CASC::FileHandle dbcFile = CASC::OpenFile(CascStorage, filename.c_str(), CASC_LOCALE_ALL);
    if (!dbcFile)
    {
        printf("Locale %s not installed.\n", localeNames[locale]);
        return 0;
    }

    char buff[512];
    DWORD readBytes = 0;
    CASC::ReadFile(dbcFile, buff, 512, &readBytes);
    if (!readBytes)
    {
        printf("Fatal error: Not found %s file!\n", filename.c_str());
        exit(1);
    }

    std::string text = std::string(buff, readBytes);

    size_t pos = text.find("version=\"");
    size_t pos1 = pos + strlen("version=\"");
    size_t pos2 = text.find("\"", pos1);
    if (pos == text.npos || pos2 == text.npos || pos1 >= pos2)
    {
        printf("Fatal error: Invalid  %s file format!\n", filename.c_str());
        exit(1);
    }

    std::string build_str = text.substr(pos1, pos2 - pos1);

    int build = atoi(build_str.c_str());
    if (build <= 0)
    {
        printf("Fatal error: Invalid  %s file format!\n", filename.c_str());
        exit(1);
    }

    return build;
}

bool OpenCascStorage(int locale)
{
    try
    {
        boost::filesystem::path const storage_dir(boost::filesystem::canonical(input_path) / "Data");
        CascStorage = CASC::OpenStorage(storage_dir, WowLocaleToCascLocaleFlags[locale]);
        if (!CascStorage)
        {
            printf("error opening casc storage '%s' locale %s\n", storage_dir.string().c_str(), localeNames[locale]);
            return false;
        }

        return true;
    }
    catch (boost::filesystem::filesystem_error& error)
    {
        printf("error opening casc storage : %s\n", error.what());
        return false;
    }
}

// Local testing functions
bool FileExists(const char* file)
{
    if (FILE* n = fopen(file, "rb"))
    {
        fclose(n);
        return true;
    }
    return false;
}

void strToLower(char* str)
{
    while(*str)
    {
        *str=tolower(*str);
        ++str;
    }
}

// copied from src\tools\map_extractor\System.cpp
void ReadLiquidTypeTableDBC()
{
    printf("Read LiquidType.dbc file...");
    CASC::FileHandle dbcFile = CASC::OpenFile(CascStorage, "DBFilesClient\\LiquidType.db2", CASC_LOCALE_NONE, true);
    if (!dbcFile)
    {
        exit(1);
    }

    DB2FileLoader db2;
    if (!db2.Load(dbcFile, LiquidTypeMeta::Instance()))
    {
        printf("Fatal error: Invalid LiquidType.db2 file format!\n");
        exit(1);
    }

    LiqType.resize(db2.GetMaxId() + 1, 0xFFFF);

    for (uint32 x = 0; x < db2.GetNumRows(); ++x)
    {
        uint32 liquidTypeId;
        if (LiquidTypeMeta::Instance()->HasIndexFieldInData())
            liquidTypeId = db2.getRecord(x).getUInt(LiquidTypeMeta::Instance()->GetIndexField(), 0);
        else
            liquidTypeId = db2.getId(x);

        LiqType[liquidTypeId] = db2.getRecord(x).getUInt8(13, 0);
    }

    for (uint32 x = 0; x < db2.GetNumRowCopies(); ++x)
        LiqType[db2.GetRowCopy(x).second] = LiqType[db2.GetRowCopy(x).first];

    printf("Done! (" SZFMTD " LiqTypes loaded)\n", LiqType.size());
}

bool ExtractWmo()
{
    bool success = true;

    std::ifstream wmoList("wmo_list.txt");
    if (!wmoList)
    {
        printf("\nUnable to open wmo_list.txt! Nothing extracted.\n");
        return false;
    }

    std::set<std::string> wmos;
    for (;;)
    {
        std::string str;
        std::getline(wmoList, str);
        if (str.empty())
            break;

        wmos.insert(std::move(str));
    }

    for (std::string str : wmos)
        success &= ExtractSingleWmo(str);

    if (success)
        printf("\nExtract wmo complete (No (fatal) errors)\n");

    return success;
}

bool ExtractSingleWmo(std::string& fname)
{
    // Copy files from archive

    char szLocalFile[1024];
    const char * plain_name = GetPlainName(fname.c_str());
    sprintf(szLocalFile, "%s/%s", szWorkDirWmo, plain_name);
    FixNameCase(szLocalFile,strlen(szLocalFile));

    if (FileExists(szLocalFile))
        return true;

    int p = 0;
    // Select root wmo files
    char const* rchr = strrchr(plain_name, '_');
    if (rchr != NULL)
    {
        char cpy[4];
        memcpy(cpy, rchr, 4);
        for (int i = 0; i < 4; ++i)
        {
            int m = cpy[i];
            if (isdigit(m))
                p++;
        }
    }

    if (p == 3)
        return true;

    bool file_ok = true;
    std::cout << "Extracting " << fname << std::endl;
    WMORoot froot(fname);
    if(!froot.open())
    {
        printf("Couldn't open RootWmo!!!\n");
        return true;
    }
    FILE *output = fopen(szLocalFile,"wb");
    if(!output)
    {
        printf("couldn't open %s for writing!\n", szLocalFile);
        return false;
    }
    froot.ConvertToVMAPRootWmo(output);
    int Wmo_nVertices = 0;
    //printf("root has %d groups\n", froot->nGroups);
    if (!froot.groupFileDataIDs.empty())
    {
        for (std::size_t i = 0; i < froot.groupFileDataIDs.size(); ++i)
        {
            char groupFileName[1024];
            sprintf(groupFileName, "FILE%08X", froot.groupFileDataIDs[i]);
            //printf("Trying to open groupfile %s\n",groupFileName);

            std::string s = groupFileName;
            WMOGroup fgroup(s);
            if(!fgroup.open())
            {
                printf("Could not open all Group file for: %s\n", plain_name);
                file_ok = false;
                break;
            }

            Wmo_nVertices += fgroup.ConvertToVMAPGroupWmo(output, &froot, preciseVectorData);
        }
    }

    fseek(output, 8, SEEK_SET); // store the correct no of vertices
    fwrite(&Wmo_nVertices,sizeof(int),1,output);
    fclose(output);

    // Delete the extracted file in the case of an error
    if (!file_ok)
        remove(szLocalFile);
    return true;
}

void ParsMapFiles()
{
    char fn[512];
    //char id_filename[64];
    char id[10];
    for (unsigned int i = 0; i < map_ids.size(); ++i)
    {
        sprintf(id, "%04u", map_ids[i].id);
        sprintf(fn,"World\\Maps\\%s\\%s.wdt", map_ids[i].name, map_ids[i].name);
        WDTFile WDT(fn,map_ids[i].name);
        if(WDT.init(id, map_ids[i].id))
        {
            printf("Processing Map %u\n[", map_ids[i].id);
            for (int x=0; x<64; ++x)
            {
                for (int y=0; y<64; ++y)
                {
                    if (ADTFile *ADT = WDT.GetMap(x,y))
                    {
                        //sprintf(id_filename,"%02u %02u %03u",x,y,map_ids[i].id);//!!!!!!!!!
                        ADT->init(map_ids[i].id, x, y);
                        delete ADT;
                    }
                }
                printf("#");
                fflush(stdout);
            }
            printf("]\n");
        }
    }
}

bool processArgv(int argc, char ** argv, const char *versionString)
{
    bool result = true;
    preciseVectorData = false;

    for (int i = 1; i < argc; ++i)
    {
        if (strcmp("-s", argv[i]) == 0)
        {
            preciseVectorData = false;
        }
        else if (strcmp("-d", argv[i]) == 0)
        {
            if ((i + 1) < argc)
            {
                input_path = boost::filesystem::path(argv[i + 1]);
                ++i;
            }
            else
            {
                result = false;
            }
        }
        else if (strcmp("-?", argv[1]) == 0)
        {
            result = false;
        }
        else if(strcmp("-l",argv[i]) == 0)
        {
            preciseVectorData = true;
        }
        else
        {
            result = false;
            break;
        }
    }

    if (!result)
    {
        printf("Extract %s.\n",versionString);
        printf("%s [-?][-s][-l][-d <path>]\n", argv[0]);
        printf("   -s : (default) small size (data size optimization), ~500MB less vmap data.\n");
        printf("   -l : large size, ~500MB more vmap data. (might contain more details)\n");
        printf("   -d <path>: Path to the vector data source folder.\n");
        printf("   -? : This message.\n");
    }

    return result;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// Main
//
// The program must be run with two command line arguments
//
// Arg1 - The source MPQ name (for testing reading and file find)
// Arg2 - Listfile name
//

int main(int argc, char ** argv)
{
    Trinity::Banner::Show("VMAP data extractor", [](char const* text) { printf("%s\n", text); }, nullptr);

    bool success = true;
    const char *versionString = "V4.03 2015_05";

    // Use command line arguments, when some
    if (!processArgv(argc, argv, versionString))
        return 1;

    // some simple check if working dir is dirty
    else
    {
        std::string sdir = std::string(szWorkDirWmo) + "/dir";
        std::string sdir_bin = std::string(szWorkDirWmo) + "/dir_bin";
        struct stat status;
        if (!stat(sdir.c_str(), &status) || !stat(sdir_bin.c_str(), &status))
        {
            printf("Your output directory seems to be polluted, please use an empty directory!\n");
            printf("<press return to exit>");
            char garbage[2];
            return scanf("%c", garbage);
        }
    }

    printf("Extract %s. Beginning work ....\n\n", versionString);
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Create the working directory
    if (mkdir(szWorkDirWmo
#if defined(__linux__) || defined(__APPLE__)
                    , 0711
#endif
                    ))
            success = (errno == EEXIST);

    int FirstLocale = -1;
    for (int i = 0; i < TOTAL_LOCALES; ++i)
    {
        if (i == LOCALE_none)
            continue;

        if (!OpenCascStorage(i))
            continue;

        FirstLocale = i;
        uint32 build = ReadBuild(i);
        if (!build)
        {
            CascStorage.reset();
            continue;
        }

        printf("Detected client build: %u\n\n", build);
        break;
    }

    if (FirstLocale == -1)
    {
        printf("FATAL ERROR: No locales defined, unable to continue.\n");
        return 1;
    }

    // Extract models, listed in GameObjectDisplayInfo.dbc
    ExtractGameobjectModels();

    ReadLiquidTypeTableDBC();

    // extract data
    if (success)
        success = ExtractWmo();

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if (success)
    {
        printf("Read Map.dbc file... ");

        CASC::FileHandle dbcFile = CASC::OpenFile(CascStorage, "DBFilesClient\\Map.db2", CASC_LOCALE_NONE, true);
        if (!dbcFile)
        {
            exit(1);
        }

        DB2FileLoader db2;
        if (!db2.Load(dbcFile, MapMeta::Instance()))
        {
            printf("Fatal error: Invalid Map.db2 file format! %s\n", HumanReadableCASCError(GetLastError()));
            exit(1);
        }

        map_ids.resize(db2.GetNumRows());
        std::unordered_map<uint32, uint32> idToIndex;
        for (uint32 x = 0; x < db2.GetNumRows(); ++x)
        {
            if (MapMeta::Instance()->HasIndexFieldInData())
                map_ids[x].id = db2.getRecord(x).getUInt(MapMeta::Instance()->GetIndexField(), 0);
            else
                map_ids[x].id = db2.getId(x);

            const char* map_name = db2.getRecord(x).getString(0, 0);
            size_t max_map_name_length = sizeof(map_ids[x].name);
            if (strlen(map_name) >= max_map_name_length)
            {
                printf("Fatal error: Map name too long!\n");
                exit(1);
            }

            strncpy(map_ids[x].name, map_name, max_map_name_length);
            map_ids[x].name[max_map_name_length - 1] = '\0';
            idToIndex[map_ids[x].id] = x;
        }

        for (uint32 x = 0; x < db2.GetNumRowCopies(); ++x)
        {
            uint32 from = db2.GetRowCopy(x).first;
            uint32 to = db2.GetRowCopy(x).second;
            auto itr = idToIndex.find(from);
            if (itr != idToIndex.end())
            {
                map_id id;
                id.id = to;
                strcpy(id.name, map_ids[itr->second].name);
                map_ids.push_back(id);
            }
        }

        printf("Done! (" SZFMTD " maps loaded)\n", map_ids.size());
        ParsMapFiles();
    }

    CascStorage.reset();

    printf("\n");
    if (!success)
    {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n", versionString, preciseVectorData);
        getchar();
    }

    printf("Extract %s. Work complete. No errors.\n", versionString);
    return 0;
}
