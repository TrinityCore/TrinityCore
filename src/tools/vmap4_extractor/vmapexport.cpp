/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "Banner.h"
#include "dbcfile.h"
#include "StringFormat.h"
#include "vmapexport.h"
#include "Locales.h"
#include "Util.h"
#include "wdtfile.h"
#include "wmo.h"
#include "mpq_libmpq04.h"
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cerrno>
#include <sys/stat.h>
// @tswow-begin
#include <set>
#include <cxxopts.h>
// @tswow-end

#ifdef _WIN32
    #include <direct.h>
    #define mkdir _mkdir
#endif

// @tswow-begin
std::set<int> assembled_maps;
std::set<std::string> assembled_models;
std::set<std::pair<int, int>> assembled_tiles;
std::set<std::string> done_files;
bool use_directories = true;

bool HasDoneFile(char const* file)
{
    return done_files.find(file) != done_files.end();
}

void FinishFile(char const* file)
{
    done_files.insert(file);
}
// @tswow-end

//------------------------------------------------------------------------------
// Defines

#define MPQ_BLOCK_SIZE 0x1000

//-----------------------------------------------------------------------------

extern ArchiveSet gOpenArchives;

typedef struct
{
    char name[64];
    unsigned int id;
}map_id;

std::vector<map_id> map_ids;
uint32 map_count;
// @tswow-begin
std::string input_path = ".";
std::string output_path = ".";
// @tswow-end
bool hasInputPathParam = false;
bool preciseVectorData = false;
std::unordered_map<std::string, WMODoodadData> WmoDoodads;

// Constants

// @tswow-begin
std::string szWorkDirWmo = "./Buildings";
// @tswow-end
int bindir_counter = 0;

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

void strToLower(char* str)
{
    while (*str)
    {
        *str = tolower(*str);
        ++str;
    }
}

bool ExtractSingleWmo(std::string& fname)
{
    // @tswow-begin
    if(assembled_models.size()> 0 && assembled_models.find(fname)==assembled_models.end())
    {
        // TODO: Not implemented
        //return true;
    }
    // @tswow-end
    // Copy files from archive
    std::string originalName = fname;

    char szLocalFile[1024];
    char* plain_name = GetPlainName(&fname[0]);
    fixnamen(plain_name, strlen(plain_name));
    fixname2(plain_name, strlen(plain_name));
    // @tswow-begin
    sprintf(szLocalFile, "%s/%s", szWorkDirWmo.c_str(), plain_name);
    // @tswow-end
    
    // @tswow-begin
    if (HasDoneFile(szLocalFile))
        return true;
    // @tswow-end

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
    printf("Extracting %s\n", originalName.c_str());
    WMORoot froot(originalName);
    if (!froot.open())
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
    WMODoodadData& doodads = WmoDoodads[plain_name];
    std::swap(doodads, froot.DoodadData);
    int Wmo_nVertices = 0;
    uint32 groupCount = 0;
    //printf("root has %d groups\n", froot->nGroups);
    if (froot.nGroups !=0)
    {
        for (uint32 i = 0; i < froot.nGroups; ++i)
        {
            char temp[1024];
            strncpy(temp, fname.c_str(), 1024);
            temp[fname.length()-4] = 0;

            WMOGroup fgroup(Trinity::StringFormat("{}_{:03}.wmo", temp, i));
            if (!fgroup.open(&froot))
            {
                printf("Could not open all Group file for: %s\n", plain_name);
                file_ok = false;
                break;
            }

            if (fgroup.ShouldSkip(&froot))
                continue;

            Wmo_nVertices += fgroup.ConvertToVMAPGroupWmo(output, preciseVectorData);
            ++groupCount;
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
    // store the correct no of groups
    fwrite(&groupCount, sizeof(uint32), 1, output);
    fclose(output);

    // Delete the extracted file in the case of an error
    if (!file_ok)
        remove(szLocalFile);
    // @tswow-begin
    else
        FinishFile(szLocalFile);
    // @tswow-end
    return true;
}

void ParsMapFiles()
{
    char fn[512];
    //char id_filename[64];
    for (unsigned int i=0; i<map_count; ++i)
    {
        // @tswow-begin
        if (assembled_maps.size() > 0 && assembled_maps.find(map_ids[i].id) == assembled_maps.end())
        {
            // TODO: Not implemented
            //continue;
        }
        // @tswow-end
        sprintf(fn,"World\\Maps\\%s\\%s.wdt", map_ids[i].name, map_ids[i].name);
        WDTFile WDT(fn,map_ids[i].name);
        if (WDT.init(map_ids[i].id))
        {
            printf("Processing Map %u\n[", map_ids[i].id);
            for (int x=0; x<64; ++x)
            {
                for (int y=0; y<64; ++y)
                {
                    // @tswow-begin
                    if(assembled_tiles.size() > 0 && assembled_tiles.find(std::make_pair(x, y)) == assembled_tiles.end())
                    {
                        // TODO: Not implemented
                        //continue;
                    }
                    // @tswow-end
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

void getGamePath()
{
    input_path = "Data\\";
}

bool scan_patches(char const* scanmatch, std::vector<std::string>& pArchiveNames)
{
    int i;
    char path[512];

    for (i = 1; i <= 99; i++)
    {
        if (i != 1)
        {
            sprintf(path, "%s-%d.MPQ", scanmatch, i);
        }
        else
        {
            sprintf(path, "%s.MPQ", scanmatch);
        }
#ifdef __linux__
        if(FILE* h = fopen64(path, "rb"))
#else
        if(FILE* h = fopen(path, "rb"))
#endif
        {
            fclose(h);
            //matches.push_back(path);
            pArchiveNames.push_back(path);
        }
    }

    return(true);
}

bool fillArchiveNameVector(std::vector<std::string>& pArchiveNames)
{
    // @tswow-begin
    //if(!hasInputPathParam)
        //getGamePath();
    // @tswow-end

    printf("\nGame path: %s\n", input_path.c_str());

    std::string in_path(input_path);
    std::vector<std::string> locales, searchLocales;

    searchLocales.push_back("enGB");
    searchLocales.push_back("enUS");
    searchLocales.push_back("deDE");
    searchLocales.push_back("esES");
    searchLocales.push_back("frFR");
    searchLocales.push_back("koKR");
    searchLocales.push_back("zhCN");
    searchLocales.push_back("zhTW");
    searchLocales.push_back("enCN");
    searchLocales.push_back("enTW");
    searchLocales.push_back("esMX");
    searchLocales.push_back("ruRU");

    for (std::vector<std::string>::iterator i = searchLocales.begin(); i != searchLocales.end(); ++i)
    {
        std::string localePath = in_path + *i;
        // check if locale exists:
        struct stat status;
        if (stat(localePath.c_str(), &status))
            continue;
        if ((status.st_mode & S_IFDIR) == 0)
            continue;
        printf("Found locale '%s'\n", i->c_str());
        locales.push_back(*i);
    }
    printf("\n");

    // open locale expansion and common files
    printf("Adding data files from locale directories.\n");
    for (std::vector<std::string>::iterator i = locales.begin(); i != locales.end(); ++i)
    {
        pArchiveNames.push_back(in_path + *i + "/locale-" + *i + ".MPQ");
        pArchiveNames.push_back(in_path + *i + "/expansion-locale-" + *i + ".MPQ");
        pArchiveNames.push_back(in_path + *i + "/lichking-locale-" + *i + ".MPQ");
    }

    // open expansion and common files
    pArchiveNames.push_back(input_path + std::string("common.MPQ"));
    pArchiveNames.push_back(input_path + std::string("common-2.MPQ"));
    pArchiveNames.push_back(input_path + std::string("expansion.MPQ"));
    pArchiveNames.push_back(input_path + std::string("lichking.MPQ"));

    // now, scan for the patch levels in the core dir
    printf("Scanning patch levels from data directory.\n");
    // @tswow-begin
    if (!scan_patches(Trinity::StringFormat("{}patch", input_path.c_str()).c_str(), pArchiveNames))
    // @tswow-end
        return(false);

    // now, scan for the patch levels in locale dirs
    printf("Scanning patch levels from locale directories.\n");
    bool foundOne = false;
    for (std::string const& locale : locales)
    {
        printf("Locale: %s\n", locale.c_str());
        // @tswow-begin
        if(scan_patches(Trinity::StringFormat("{}/patch-{}", input_path.c_str(), locale.c_str(), locale.c_str()).c_str(), pArchiveNames))
        // @tswow-end
        foundOne = true;
    }

    printf("\n");

    if(!foundOne)
    {
        printf("no locale found\n");
        return false;
    }

    return true;
}

// @tswow-begin
void HandleArgs(int argc, char* arg[])
{
    cxxopts::Options options("vmap4_extractor", "Extract model data");
    options.add_options()
        ("i,input", "Input path", cxxopts::value<std::string>()->default_value("."))
        ("o,output", "Output path", cxxopts::value<std::string>()->default_value("./Buildings"))
        ("s", "use precise vector data", cxxopts::value<bool>()->default_value("1"))
        ("d", "read data from mpq directories", cxxopts::value<int>()->default_value("1"))
        ("maps", "Specify individual maps to create", cxxopts::value<std::vector<int>>()->default_value(""))
        ("tiles", "Specify individual tiles to create", cxxopts::value<std::vector<int>>()->default_value(""))
        ;

    auto result = options.parse(argc, arg);

    szWorkDirWmo = result["output"].as<std::string>();

    preciseVectorData = result["s"].as<bool>();
    use_directories = result["d"].as<int>();
    input_path = result["input"].as<std::string>();
}
// @tswow-end

// @tswow-begin
inline bool ends_with(std::string const& value, std::string const& ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
// @tswow-end

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
    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    Trinity::Banner::Show("VMAP data extractor", [](char const* text) { printf("%s\n", text); }, nullptr);

    bool success = true;
    const char *versionString = "V4.00 2012_02";

    // Use command line arguments, when some
    // @tswow-begin
    HandleArgs(argc, argv);
    if(!false) {}
    // @tswow-end
    // some simple check if working dir is dirty
    else
    {
        std::string sdir = std::string(szWorkDirWmo) + "/dir";
        std::string sdir_bin = std::string(szWorkDirWmo) + "/dir_bin";
        struct stat status;

        // @tswow-begin
        if (!stat(sdir_bin.c_str(), &status))
        {
            remove(sdir_bin.c_str());
        //    printf("Your output directory seems to be polluted, please use an empty directory!\n");
        //    printf("<press return to exit>");
        //    char garbage[2];
        //    return scanf("%c", garbage);
        }
        // @tswow-end
    }

    printf("Extract %s. Beginning work ....\n", versionString);
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Create the working directory
    // @tswow-begin
    if (mkdir(szWorkDirWmo.c_str()
    // @tswow-end
#if defined(__linux__) || defined(__APPLE__) || defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
                    , 0711
#endif
                    ))
            success = (errno == EEXIST);

    // prepare archive name list
    // @tswow-begin
    ReadMPQFiles(input_path,use_directories);
    // @tswow-end

    if (gOpenArchives.empty())
    {
        // @tswow-begin
        printf("FATAL ERROR: None MPQ archive found by path '%s'. Use -d option with proper path.\n", input_path.c_str());
        // @tswow-end
        return 1;
    }

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if (success)
    {
        DBCFile * dbc = new DBCFile("DBFilesClient\\Map.dbc");
        if (!dbc->open())
        {
            delete dbc;
            printf("FATAL ERROR: Map.dbc not found in data file.\n");
            return 1;
        }
        map_count = dbc->getRecordCount();
        map_ids.resize(map_count);
        for (unsigned int x = 0; x < map_count; ++x)
        {
            map_ids[x].id = dbc->getRecord(x).getUInt(0);

            char const* map_name = dbc->getRecord(x).getString(1);
            size_t max_map_name_length = sizeof(map_ids[x].name);
            if (strlen(map_name) >= max_map_name_length)
            {
                delete dbc;
                printf("FATAL ERROR: Map name too long.\n");
                return 1;
            }

            strncpy(map_ids[x].name, map_name, max_map_name_length);
            map_ids[x].name[max_map_name_length - 1] = '\0';
            printf("Map - %s\n", map_ids[x].name);
        }

        delete dbc;
        ParsMapFiles();
        //nError = ERROR_SUCCESS;
        // Extract models, listed in DameObjectDisplayInfo.dbc
        ExtractGameobjectModels();
    }

    printf("\n");
    if (!success)
    {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n", versionString, preciseVectorData);
        getchar();
    }

    printf("Extract %s. Work complete. No errors.\n", versionString);
    return 0;
}
