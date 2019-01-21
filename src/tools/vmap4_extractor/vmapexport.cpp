/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "adtfile.h"
#include "wdtfile.h"
#include "dbcfile.h"
#include "wmo.h"
#include "mpqfile.h"
#include "vmapexport.h"
#include "Banner.h"
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#define mkdir _mkdir
#else
#include <unistd.h>
#define ERROR_PATH_NOT_FOUND ERROR_FILE_NOT_FOUND
#endif

#undef min
#undef max

#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <errno.h>

//------------------------------------------------------------------------------
// Defines

#define MPQ_BLOCK_SIZE 0x1000

//-----------------------------------------------------------------------------

HANDLE WorldMpq = nullptr;
HANDLE LocaleMpq = nullptr;

uint32 CONF_TargetBuild = 15595;              // 4.3.4.15595

// List MPQ for extract maps from
char const* CONF_mpq_list[]=
{
    "world.MPQ",
    "art.MPQ",
    "expansion1.MPQ",
    "expansion2.MPQ",
    "expansion3.MPQ",
    "world2.MPQ",
};

uint32 const Builds[] = {13164, 13205, 13287, 13329, 13596, 13623, 13914, 14007, 14333, 14480, 14545, 15005, 15050, 15211, 15354, 15595, 0};
#define LAST_DBC_IN_DATA_BUILD 13623    // after this build mpqs with dbc are back to locale folder
#define NEW_BASE_SET_BUILD  15211

#define LOCALES_COUNT 15

char const* Locales[LOCALES_COUNT] =
{
    "enGB", "enUS",
    "deDE", "esES",
    "frFR", "koKR",
    "zhCN", "zhTW",
    "enCN", "enTW",
    "esMX", "ruRU",
    "ptBR", "ptPT",
    "itIT"
};

TCHAR const* LocalesT[LOCALES_COUNT] =
{
    _T("enGB"), _T("enUS"),
    _T("deDE"), _T("esES"),
    _T("frFR"), _T("koKR"),
    _T("zhCN"), _T("zhTW"),
    _T("enCN"), _T("enTW"),
    _T("esMX"), _T("ruRU"),
    _T("ptBR"), _T("ptPT"),
    _T("itIT"),
};

struct map_info
{
    char name[64];
    int32 parent_id;
};

struct LiquidMaterialEntry
{
    int8 LVF;
};

struct LiquidObjectEntry
{
    int16 LiquidTypeID;
};

struct LiquidTypeEntry
{
    uint8 SoundBank;
    uint8 MaterialID;
};

std::map<uint32, map_info> map_ids;
std::unordered_set<uint32> maps_that_are_parents;
std::unordered_map<uint32, LiquidMaterialEntry> LiquidMaterials;
std::unordered_map<uint32, LiquidObjectEntry> LiquidObjects;
std::unordered_map<uint32, LiquidTypeEntry> LiquidTypes;
char output_path[128]=".";
char input_path[1024]=".";
bool preciseVectorData = false;
std::unordered_map<std::string, WMODoodadData> WmoDoodads;

// Constants

char const* szWorkDirWmo = "./Buildings";

bool LoadLocaleMPQFile(int locale)
{
    TCHAR buff[512];
    memset(buff, 0, sizeof(buff));
    _stprintf(buff, _T("%s%s/locale-%s.MPQ"), input_path, LocalesT[locale], LocalesT[locale]);
    if (!SFileOpenArchive(buff, 0, MPQ_OPEN_READ_ONLY, &LocaleMpq))
    {
        if (GetLastError() != ERROR_PATH_NOT_FOUND)
        {
            _tprintf(_T("Loading %s locale MPQs\n"), LocalesT[locale]);
            _tprintf(_T("Cannot open archive %s\n"), buff);
        }
        return false;
    }

    _tprintf(_T("Loading %s locale MPQs\n"), LocalesT[locale]);
    char const* prefix = nullptr;
    for (int i = 0; Builds[i] && Builds[i] <= CONF_TargetBuild; ++i)
    {
        // Do not attempt to read older MPQ patch archives past this build, they were merged with base
        // and trying to read them together with new base will not end well
        if (CONF_TargetBuild >= NEW_BASE_SET_BUILD && Builds[i] < NEW_BASE_SET_BUILD)
            continue;

        memset(buff, 0, sizeof(buff));
        if (Builds[i] > LAST_DBC_IN_DATA_BUILD)
        {
            prefix = "";
            _stprintf(buff, _T("%s%s/wow-update-%s-%u.MPQ"), input_path, LocalesT[locale], LocalesT[locale], Builds[i]);
        }
        else
        {
            prefix = Locales[locale];
            _stprintf(buff, _T("%swow-update-%u.MPQ"), input_path, Builds[i]);
        }

        if (!SFileOpenPatchArchive(LocaleMpq, buff, prefix, 0))
        {
            if (GetLastError() != ERROR_FILE_NOT_FOUND)
                _tprintf(_T("Cannot open patch archive %s\n"), buff);
            continue;
        }
    }

    printf("\n");
    return true;
}

void LoadCommonMPQFiles(uint32 build)
{
    TCHAR filename[512];
    _stprintf(filename, _T("%sworld.MPQ"), input_path);
    _tprintf(_T("Loading common MPQ files\n"));
    if (!SFileOpenArchive(filename, 0, MPQ_OPEN_READ_ONLY, &WorldMpq))
    {
        if (GetLastError() != ERROR_PATH_NOT_FOUND)
            _tprintf(_T("Cannot open archive %s\n"), filename);
        return;
    }

    int count = sizeof(CONF_mpq_list) / sizeof(char*);
    for (int i = 1; i < count; ++i)
    {
        if (build < 15211 && !strcmp("world2.MPQ", CONF_mpq_list[i]))   // 4.3.2 and higher MPQ
            continue;

        _stprintf(filename, _T("%s%s"), input_path, CONF_mpq_list[i]);
        if (!SFileOpenPatchArchive(WorldMpq, filename, "", 0))
        {
            if (GetLastError() != ERROR_PATH_NOT_FOUND)
                _tprintf(_T("Cannot open archive %s\n"), filename);
            else
                _tprintf(_T("Not found %s\n"), filename);
        }
        else
            _tprintf(_T("Loaded %s\n"), filename);
    }

    char const* prefix = nullptr;
    for (int i = 0; Builds[i] && Builds[i] <= CONF_TargetBuild; ++i)
    {
        // Do not attempt to read older MPQ patch archives past this build, they were merged with base
        // and trying to read them together with new base will not end well
        if (CONF_TargetBuild >= NEW_BASE_SET_BUILD && Builds[i] < NEW_BASE_SET_BUILD)
            continue;

        memset(filename, 0, sizeof(filename));
        if (Builds[i] > LAST_DBC_IN_DATA_BUILD)
        {
            prefix = "";
            _stprintf(filename, _T("%swow-update-base-%u.MPQ"), input_path, Builds[i]);
        }
        else
        {
            prefix = "base";
            _stprintf(filename, _T("%swow-update-%u.MPQ"), input_path, Builds[i]);
        }

        if (!SFileOpenPatchArchive(WorldMpq, filename, prefix, 0))
        {
            if (GetLastError() != ERROR_PATH_NOT_FOUND)
                _tprintf(_T("Cannot open patch archive %s\n"), filename);
            else
                _tprintf(_T("Not found %s\n"), filename);
            continue;
        }
        else
            _tprintf(_T("Loaded %s\n"), filename);
    }

    printf("\n");
}

std::map<std::pair<uint32, uint16>, uint32> uniqueObjectIds;

uint32 GenerateUniqueObjectId(uint32 clientId, uint16 clientDoodadId)
{
    return uniqueObjectIds.emplace(std::make_pair(clientId, clientDoodadId), uniqueObjectIds.size() + 1).first->second;
}
// Local testing functions

bool FileExists(char const* file)
{
    if (FILE* n = fopen(file, "rb"))
    {
        fclose(n);
        return true;
    }
    return false;
}

bool ExtractWmo()
{
    bool success = false;

    //char const* ParsArchiveNames[] = {"patch-2.MPQ", "patch.MPQ", "common.MPQ", "expansion.MPQ"};

    SFILE_FIND_DATA data;
    HANDLE find = SFileFindFirstFile(WorldMpq, "*.wmo", &data, nullptr);
    if (find != nullptr)
    {
        do
        {
            std::string str = data.cFileName;
            //printf("Extracting wmo %s\n", str.c_str());
            success |= ExtractSingleWmo(str);
        }
        while (SFileFindNextFile(find, &data));
    }
    SFileFindClose(find);

    if (success)
        printf("\nExtract wmo complete (No (fatal) errors)\n");

    return success;
}

bool ExtractSingleWmo(std::string& fname)
{
    // Copy files from archive
    std::string originalName = fname;

    char szLocalFile[1024];
    char* plain_name = GetPlainName(&fname[0]);
    FixNameCase(plain_name, strlen(plain_name));
    FixNameSpaces(plain_name, strlen(plain_name));
    sprintf(szLocalFile, "%s/%s", szWorkDirWmo, plain_name);

    if (FileExists(szLocalFile))
        return true;

    int p = 0;
    // Select root wmo files
    char const* rchr = strrchr(plain_name, '_');
    if (rchr != nullptr)
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
    std::cout << "Extracting " << originalName << std::endl;
    WMORoot froot(originalName);
    if (!froot.open())
    {
        printf("Couldn't open RootWmo!!!\n");
        return true;
    }
    FILE *output = fopen(szLocalFile,"wb");
    if (!output)
    {
        printf("couldn't open %s for writing!\n", szLocalFile);
        return false;
    }
    froot.ConvertToVMAPRootWmo(output);
    WMODoodadData& doodads = WmoDoodads[plain_name];
    std::swap(doodads, froot.DoodadData);
    int Wmo_nVertices = 0;
    //printf("root has %d groups\n", froot->nGroups);
    if (froot.nGroups !=0)
    {
        for (uint32 i = 0; i < froot.nGroups; ++i)
        {
            char temp[1024];
            strncpy(temp, fname.c_str(), 1024);
            temp[fname.length()-4] = 0;
            char groupFileName[1024];
            sprintf(groupFileName, "%s_%03u.wmo", temp, i);
            //printf("Trying to open groupfile %s\n",groupFileName);

            std::string s = groupFileName;
            WMOGroup fgroup(s);
            if (!fgroup.open(&froot))
            {
                printf("Could not open all Group file for: %s\n", plain_name);
                file_ok = false;
                break;
            }

            Wmo_nVertices += fgroup.ConvertToVMAPGroupWmo(output, preciseVectorData);
            for (uint16 groupReference : fgroup.DoodadReferences)
            {
                if (groupReference >= doodads.Spawns.size())
                    continue;

                uint32 doodadNameIndex = doodads.Spawns[groupReference].NameIndex;
                if (froot.ValidDoodadNames.find(doodadNameIndex) == froot.ValidDoodadNames.end())
                    continue;

                doodads.References.insert(groupReference);
            }
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
    std::unordered_map<uint32, WDTFile> wdts;
    auto getWDT = [&wdts](uint32 mapId) -> WDTFile*
    {
        auto itr = wdts.find(mapId);
        if (itr == wdts.end())
        {
            char fn[512];
            char* name = map_ids[mapId].name;
            sprintf(fn, "World\\Maps\\%s\\%s.wdt", name, name);
            itr = wdts.emplace(std::piecewise_construct, std::forward_as_tuple(mapId), std::forward_as_tuple(fn, name, maps_that_are_parents.count(mapId) > 0)).first;
            if (!itr->second.init(mapId))
            {
                wdts.erase(itr);
                return nullptr;
            }
        }

        return &itr->second;
    };

    for (auto itr = map_ids.begin(); itr != map_ids.end(); ++itr)
    {
        if (WDTFile* WDT = getWDT(itr->first))
        {
            WDTFile* parentWDT = itr->second.parent_id >= 0 ? getWDT(itr->second.parent_id) : nullptr;
            printf("Processing Map %u\n[", itr->first);
            for (int32 x = 0; x < 64; ++x)
            {
                for (int32 y = 0; y < 64; ++y)
                {
                    bool success = false;
                    if (ADTFile* ADT = WDT->GetMap(x, y))
                    {
                        success = ADT->init(itr->first, itr->first);
                        WDT->FreeADT(ADT);
                    }
                    if (!success && parentWDT)
                    {
                        if (ADTFile* ADT = parentWDT->GetMap(x, y))
                        {
                            ADT->init(itr->first, itr->second.parent_id);
                            parentWDT->FreeADT(ADT);
                        }
                    }
                }
                printf("#");
                fflush(stdout);
            }
            printf("]\n");
        }
    }
}

void getGamePath()
{
#ifdef _WIN32
    strcpy(input_path,"Data\\");
#else
    strcpy(input_path,"Data/");
#endif
}

bool processArgv(int argc, char ** argv, const char *versionString)
{
    bool result = true;
    bool hasInputPathParam = false;
    preciseVectorData = false;

    for(int i = 1; i < argc; ++i)
    {
        if (strcmp("-s",argv[i]) == 0)
        {
            preciseVectorData = false;
        }
        else if (strcmp("-d",argv[i]) == 0)
        {
            if ((i+1)<argc)
            {
                hasInputPathParam = true;
                strncpy(input_path, argv[i + 1], sizeof(input_path));
                input_path[sizeof(input_path) - 1] = '\0';

                if (input_path[strlen(input_path) - 1] != '\\' && input_path[strlen(input_path) - 1] != '/')
                    strcat(input_path, "/");
                ++i;
            }
            else
            {
                result = false;
            }
        }
        else if (strcmp("-?",argv[1]) == 0)
        {
            result = false;
        }
        else if (strcmp("-l",argv[i]) == 0)
        {
            preciseVectorData = true;
        }
        else if (strcmp("-b",argv[i]) == 0)
        {
            if (i + 1 < argc)                            // all ok
                CONF_TargetBuild = atoi(argv[i++ + 1]);
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
        printf("   -b : target build (default %u)\n", CONF_TargetBuild);
        printf("   -? : This message.\n");
    }

    if (!hasInputPathParam)
        getGamePath();

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
    const char *versionString = "V4.05 2018_03";

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

    LoadCommonMPQFiles(CONF_TargetBuild);

    for (int i = 0; i < LOCALES_COUNT; ++i)
    {
        //Open MPQs
        if (!LoadLocaleMPQFile(i))
        {
            if (GetLastError() != ERROR_PATH_NOT_FOUND)
                printf("Unable to load %s locale archives!\n", Locales[i]);
            continue;
        }

        printf("Detected and using locale: %s\n", Locales[i]);
        break;
    }

    // Extract models, listed in GameObjectDisplayInfo.dbc
    ExtractGameobjectModels();

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if (success)
    {
        printf("Read Map.dbc file... ");

        DBCFile dbc(LocaleMpq, "DBFilesClient\\Map.dbc");
        if (!dbc.open())
        {
            printf("FATAL ERROR: Map.dbc not found in data file.\n");
            exit(1);
        }

        for (uint32 x = 0; x < dbc.getRecordCount(); ++x)
        {
            DBCFile::Record record = dbc.getRecord(x);
            map_info& m = map_ids[record.getUInt(0)];

            char const* map_name = record.getString(1);
            size_t max_map_name_length = sizeof(m.name);
            if (strlen(map_name) >= max_map_name_length)
            {
                printf("Fatal error: Map name too long!\n");
                exit(1);
            }

            strncpy(m.name, map_name, max_map_name_length);
            m.name[max_map_name_length - 1] = '\0';
            m.parent_id = int16(record.getInt(19));
            if (m.parent_id >= 0)
                maps_that_are_parents.insert(m.parent_id);

            printf("Map - %s\n", m.name);
        }

        ParsMapFiles();
    }

    SFileCloseArchive(LocaleMpq);
    SFileCloseArchive(WorldMpq);

    printf("\n");
    if (!success)
    {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n", versionString, preciseVectorData);
        getchar();
    }

    printf("Extract %s. Work complete. No errors.\n", versionString);
    return 0;
}
