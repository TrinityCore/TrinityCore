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
#include "wdtfile.h"
#include "wmo.h"
#include "mpq_libmpq04.h"
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

bool HasDoneFile(char const* file)
{
    if(done_files.find(file) != done_files.end())
    {
        return true;
    }
    done_files.insert(file);
    return false;
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
char output_path[128]=".";
char input_path[1024]=".";
bool hasInputPathParam = false;
bool preciseVectorData = false;
std::unordered_map<std::string, WMODoodadData> WmoDoodads;

// Constants

char const* szWorkDirWmo = "./Buildings";

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
    sprintf(szLocalFile, "%s/%s", szWorkDirWmo, plain_name);
    
    // @tswow-begin
    if (FileExists(szLocalFile))
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

            WMOGroup fgroup(Trinity::StringFormat("%s_%03u.wmo", temp, i));
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
#ifdef _WIN32
    strcpy(input_path,"Data\\");
#else
    strcpy(input_path,"Data/");
#endif
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
    if(!hasInputPathParam)
        getGamePath();

    printf("\nGame path: %s\n", input_path);

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
    if (!scan_patches(Trinity::StringFormat("%spatch", input_path).c_str(), pArchiveNames))
        return(false);

    // now, scan for the patch levels in locale dirs
    printf("Scanning patch levels from locale directories.\n");
    bool foundOne = false;
    for (std::string const& locale : locales)
    {
        printf("Locale: %s\n", locale.c_str());
        if(scan_patches(Trinity::StringFormat("%s%s/patch-%s", input_path, locale.c_str(), locale.c_str()).c_str(), pArchiveNames))
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
    for (int c = 1; c < argc; ++c)
    {
        if (arg[c][0] != '-')
        {
            //Usage(arg[0]);
        }

        switch (arg[c][1])
        {
        case 'o':
            c++;
            szWorkDirWmo = arg[c];
            std::cout << "Setting the workdirwmo to " << szWorkDirWmo << "\n";
            break;
        case 's':
            c++;
            preciseVectorData = false;
            break;
        case 'i':
            c++;
            hasInputPathParam = true;
            strncpy(input_path, arg[c], sizeof(input_path));
            input_path[sizeof(input_path) - 1] = '\0';
            if (input_path[strlen(input_path) - 1] != '\\' && input_path[strlen(input_path) - 1] != '/')
                strcat(input_path, "/");
            break;
        case 'l':
            c++;
            preciseVectorData = true;
            break;
        case 'm':
        {
            c++;
            auto len = strlen(arg[c]);
            char cur[4] = { 0,0,0,0 };
            int j = 0;
            for (int i = 0; i <= len; ++i) {
                if (i == len || arg[c][i] == ',')
                {
                    std::cout << "Doing only map " << cur << "\n";
                    assembled_maps.insert(atoi(cur));
                    *((unsigned*)cur) = 0;
                    j = 0;
                }
                else
                {
                    cur[j++] = arg[c][i];
                }
            }
            break;
        }
        break;
        case 'd':
        {
            c++;
            auto len = strlen(arg[c]);
            std::string cur = "";
            for (int i = 0; i <= len; ++i)
            {
                if (i == len || arg[c][i] == ',')
                {
                    assembled_models.insert(std::string(cur));
                    cur = "";
                }
                else
                {
                    cur += arg[c][i];
                }
            }
            break;
        }
        case 't':
        {
            c++;
            auto len = strlen(arg[c]);
            char cur1[4] = { 0,0,0,0 };
            char cur2[4] = { 0,0,0,0 };
            bool passed = false;
            int j = 0;
            for (int i = 0; i <= len; ++i) {
                if (i == len || arg[c][i] == ',')
                {
                    std::cout << "Doing only tile " << cur1 << " " << cur2 << "\n";
                    assembled_tiles.insert(
                        std::make_pair<int, int>(
                            atoi(cur1)
                            , atoi(cur2)
                            ));
                    *((unsigned*)cur1) = 0;
                    *((unsigned*)cur2) = 0;
                    j = 0;
                    passed = false;
                }
                else if (arg[c][i] == '.')
                {
                    j = 0;
                    passed = true;
                }
                else
                {
                    if (passed) cur1[j++] = arg[c][i];
                    else cur2[j++] = arg[c][i];
                }
            }
            break;
        }
        break;
        default:
            std::cout << "Unsupported " << arg[c][1] << "\n";
        }
    }
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
    if (mkdir(szWorkDirWmo
#if defined(__linux__) || defined(__APPLE__)
                    , 0711
#endif
                    ))
            success = (errno == EEXIST);

    // prepare archive name list
    std::vector<std::string> archiveNames;
    fillArchiveNameVector(archiveNames);
    for (size_t i = 0; i < archiveNames.size(); ++i)
    {
        MPQArchive *archive = new MPQArchive(archiveNames[i].c_str());
        if (gOpenArchives.empty() || gOpenArchives.front() != archive)
            delete archive;
    }

    if (gOpenArchives.empty())
    {
        printf("FATAL ERROR: None MPQ archive found by path '%s'. Use -d option with proper path.\n", input_path);
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
