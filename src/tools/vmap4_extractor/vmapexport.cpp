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
#include "Common.h"
#include "cascfile.h"
#include "DB2CascFileSource.h"
#include "ExtractorDB2LoadInfo.h"
#include "StringFormat.h"
#include "VMapDefinitions.h"
#include "vmapexport.h"
#include "Locales.h"
#include "Util.h"
#include "wdtfile.h"
#include "wmo.h"
#include <algorithm>
#include <CascLib.h>
#include <boost/filesystem/directory.hpp>
#include <boost/filesystem/operations.hpp>
#include <fstream>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdio>
#include <cerrno>

//-----------------------------------------------------------------------------

std::shared_ptr<CASC::Storage> CascStorage;

struct MapEntry
{
    uint32 Id = 0;
    int32 WdtFileDataId = 0;
    int16 ParentMapID = 0;
    std::string Name;
    std::string Directory;
};

std::vector<MapEntry> map_ids; // partitioned by parent maps first
std::unordered_set<uint32> maps_that_are_parents;
boost::filesystem::path input_path;
bool preciseVectorData = false;
char const* CascProduct = "wow";
char const* CascRegion = "eu";
bool UseRemoteCasc = false;
uint32 DbcLocale = 0;
std::unordered_map<std::string, WMODoodadData> WmoDoodads;

// Constants

char const* szWorkDirWmo = "./Buildings";

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

bool OpenCascStorage(int locale)
{
    try
    {
        if (UseRemoteCasc)
        {
            boost::filesystem::path const casc_cache_dir(boost::filesystem::canonical(input_path) / "CascCache");
            CascStorage.reset(CASC::Storage::OpenRemote(casc_cache_dir, WowLocaleToCascLocaleFlags[locale], CascProduct, CascRegion));
            if (CascStorage)
                return true;

            printf("Unable to open remote casc fallback to local casc\n");
        }

        boost::filesystem::path const storage_dir(boost::filesystem::canonical(input_path) / "Data");
        CascStorage.reset(CASC::Storage::Open(storage_dir, WowLocaleToCascLocaleFlags[locale], CascProduct));
        if (!CascStorage)
        {
            printf("error opening casc storage '%s' locale %s\n", storage_dir.string().c_str(), localeNames[locale]);
            return false;
        }

        return true;
    }
    catch (std::exception const& error)
    {
        printf("error opening casc storage : %s\n", error.what());
        return false;
    }
}

uint32 GetInstalledLocalesMask()
{
    try
    {
        if (UseRemoteCasc)
        {
            boost::filesystem::path const casc_cache_dir(boost::filesystem::canonical(input_path) / "CascCache");

            std::unique_ptr<CASC::Storage> storage(CASC::Storage::OpenRemote(casc_cache_dir, 0, CascProduct, CascRegion));
            if (storage)
                return CASC_LOCALE_ALL_WOW;

            printf("Unable to open remote casc fallback to local casc\n");
        }

        boost::filesystem::path const storage_dir(boost::filesystem::canonical(input_path) / "Data");
        std::unique_ptr<CASC::Storage> storage(CASC::Storage::Open(storage_dir, 0, CascProduct));
        if (!storage)
            return false;

        return storage->GetInstalledLocalesMask();
    }
    catch (std::exception const& error)
    {
        printf("Unable to determine installed locales mask: %s\n", error.what());
    }

    return 0;
}

uint32 uniqueObjectIdGenerator = std::numeric_limits<uint32>::max() - 1;
std::map<std::pair<uint32, uint16>, uint32> uniqueObjectIds;

uint32 GenerateUniqueObjectId(uint32 clientId, uint16 clientDoodadId, bool isWmo)
{
    // WMO client ids must be preserved, they are used in DB2 files
    uint32 newId = isWmo ? clientId : uniqueObjectIdGenerator--;
    return uniqueObjectIds.emplace(std::make_pair(clientId, clientDoodadId), newId).first->second;
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

bool ExtractSingleWmo(std::string& fname)
{
    // Copy files from archive
    std::string originalName = fname;

    char* plain_name = GetPlainName(&fname[0]);
    NormalizeFileName(plain_name, strlen(plain_name));
    std::string szLocalFile = Trinity::StringFormat("{}/{}", szWorkDirWmo, plain_name);

    if (FileExists(szLocalFile.c_str()))
        return true;

    int p = 0;
    // Select root wmo files
    char const* rchr = strrchr(plain_name, '_');
    if (rchr != nullptr)
        for (int i = 0; i < 4; ++i)
            if (isdigit(rchr[i]))
                p++;

    if (p == 3)
        return true;

    bool file_ok = true;
    WMORoot froot(originalName);
    if (!froot.open())
    {
        printf("Couldn't open RootWmo!!!\n");
        return true;
    }
    FILE *output = fopen(szLocalFile.c_str(),"wb");
    if(!output)
    {
        printf("couldn't open %s for writing!\n", szLocalFile.c_str());
        return false;
    }
    froot.ConvertToVMAPRootWmo(output);
    WMODoodadData& doodads = WmoDoodads[plain_name];
    std::swap(doodads, froot.DoodadData);
    int Wmo_nVertices = 0;
    uint32 groupCount = 0;
    //printf("root has %d groups\n", froot->nGroups);
    std::vector<WMOGroup> groups;
    groups.reserve(froot.groupFileDataIDs.size());
    for (std::size_t i = 0; i < froot.groupFileDataIDs.size(); ++i)
    {
        std::string s = Trinity::StringFormat("FILE{:08X}.xxx", froot.groupFileDataIDs[i]);
        WMOGroup& fgroup = groups.emplace_back(s);
        if (!fgroup.open(&froot))
        {
            printf("Could not open all Group file for: %s\n", plain_name);
            file_ok = false;
            break;
        }
    }

    for (WMOGroup& fgroup : groups)
    {
        if (fgroup.ShouldSkip(&froot))
            continue;

        if (fgroup.mogpFlags2 & 0x80
            && fgroup.parentOrFirstChildSplitGroupIndex >= 0
            && size_t(fgroup.parentOrFirstChildSplitGroupIndex) < groups.size())
            fgroup.groupWMOID = groups[fgroup.parentOrFirstChildSplitGroupIndex].groupWMOID;

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

    fseek(output, 8, SEEK_SET); // store the correct no of vertices
    fwrite(&Wmo_nVertices, sizeof(int), 1, output);
    // store the correct no of groups
    fwrite(&groupCount, sizeof(uint32), 1, output);
    fclose(output);

    // Delete the extracted file in the case of an error
    if (!file_ok)
        remove(szLocalFile.c_str());
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
            auto mapEntryItr = std::find_if(map_ids.begin(), map_ids.end(), [mapId](MapEntry const& mapEntry) { return mapEntry.Id == mapId; });
            if (mapEntryItr == map_ids.end())
                return nullptr;

            uint32 fileDataId = mapEntryItr->WdtFileDataId;
            if (!fileDataId)
                return nullptr;

            std::string description = Trinity::StringFormat("WDT for map {} - {} (FileDataID {})", mapId, mapEntryItr->Name, fileDataId);
            std::string directory = mapEntryItr->Directory;
            itr = wdts.emplace(std::piecewise_construct, std::forward_as_tuple(mapId), std::forward_as_tuple(fileDataId, description, std::move(directory), maps_that_are_parents.count(mapId) > 0)).first;
            if (!itr->second.init(mapId))
            {
                wdts.erase(itr);
                return nullptr;
            }
        }

        return &itr->second;
    };

    for (MapEntry const& mapEntry : map_ids)
    {
        if (WDTFile* WDT = getWDT(mapEntry.Id))
        {
            WDTFile* parentWDT = mapEntry.ParentMapID >= 0 ? getWDT(mapEntry.ParentMapID) : nullptr;
            printf("Processing Map %u\n[", mapEntry.Id);
            for (int32 x = 0; x < 64; ++x)
            {
                for (int32 y = 0; y < 64; ++y)
                {
                    bool success = false;
                    if (ADTFile* ADT = WDT->GetMap(x, y))
                    {
                        success = ADT->init(mapEntry.Id, mapEntry.Id);
                        WDT->FreeADT(ADT);
                    }
                    if (!success && parentWDT)
                    {
                        if (ADTFile* ADT = parentWDT->GetMap(x, y))
                        {
                            ADT->init(mapEntry.Id, mapEntry.ParentMapID);
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
        else if (strcmp("-l", argv[i]) == 0)
        {
            preciseVectorData = true;
        }
        else if (strcmp("-p", argv[i]) == 0)
        {
            if (i + 1 < argc && strlen(argv[i + 1]))
                CascProduct = argv[++i];
            else
                result = false;
        }
        else if (strcmp("-c", argv[i]) == 0)
        {
            UseRemoteCasc = true;
        }
        else if (strcmp("-r", argv[i]) == 0)
        {
            if (i + 1 < argc && strlen(argv[i + 1]))
                CascRegion = argv[++i];
            else
                result = false;
        }
        else if (strcmp("-dl", argv[i]) == 0)
        {
            if (i + 1 < argc && strlen(argv[i + 1]))
            {
                for (uint32 l = 0; l < TOTAL_LOCALES; ++l)
                    if (!strcmp(argv[i + 1], localeNames[l]))
                        DbcLocale = 1 << l;
                i++;
            }
            else
                result = false;
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
        printf("%s [-?][-s][-l][-d <path>][-p <product>]\n", argv[0]);
        printf("   -s  : (default) small size (data size optimization), ~500MB less vmap data.\n");
        printf("   -l  : large size, ~500MB more vmap data. (might contain more details)\n");
        printf("   -d  <path>: Path to the vector data source folder.\n");
        printf("   -p  <product>: which installed product to open (wow/wowt/wow_beta)\n");
        printf("   -c  use remote casc\n");
        printf("   -r  set remote casc region - standard: eu\n");
        printf("   -dl dbc locale\n");
        printf("   -? : This message.\n");
    }

    return result;
}

static bool RetardCheck()
{
    try
    {
        if (UseRemoteCasc)
            return true;

        boost::filesystem::path storageDir(boost::filesystem::canonical(input_path) / "Data");
        boost::filesystem::directory_iterator end;
        for (boost::filesystem::directory_iterator itr(storageDir); itr != end; ++itr)
        {
            if (itr->path().extension() == ".MPQ")
            {
                printf("MPQ files found in Data directory!\n");
                printf("This tool works only with World of Warcraft: Dragonflight\n");
                printf("\n");
                printf("To extract maps for Wrath of the Lich King, rebuild tools using 3.3.5 branch!\n");
                printf("\n");
                printf("Press ENTER to exit...\n");
                getchar();
                return false;
            }
        }
    }
    catch (std::exception const& error)
    {
        printf("Error checking client version: %s\n", error.what());
    }

    return true;
}

int main(int argc, char ** argv)
{
    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    Trinity::Banner::Show("VMAP data extractor", [](char const* text) { printf("%s\n", text); }, nullptr);

    bool success = true;

    // Use command line arguments, when some
    if (!processArgv(argc, argv, VMAP::VMAP_MAGIC))
        return 1;

    if (!RetardCheck())
        return 1;

    // some simple check if working dir is dirty
    boost::filesystem::path sdir_bin = boost::filesystem::path(szWorkDirWmo) / "dir_bin";
    {
        boost::system::error_code ec;
        if (boost::filesystem::exists(sdir_bin, ec) && !boost::filesystem::is_empty(sdir_bin, ec))
        {
            printf("Your output directory seems to be polluted, please use an empty directory!\n");
            printf("<press return to exit>");
            char garbage[2];
            return scanf("%c", garbage);
        }
    }

    printf("Extract %s. Beginning work ....\n", VMAP::VMAP_MAGIC);
    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    // Create the working directory
    success = boost::filesystem::create_directories(sdir_bin) || boost::filesystem::is_directory(sdir_bin);

    uint32 installedLocalesMask = GetInstalledLocalesMask();
    int32 FirstLocale = -1;
    for (int i = 0; i < TOTAL_LOCALES; ++i)
    {
        if (DbcLocale && !(DbcLocale & (1 << i)))
            continue;

        if (i == LOCALE_none)
            continue;

        if (!(installedLocalesMask & WowLocaleToCascLocaleFlags[i]))
            continue;

        if (!OpenCascStorage(i))
            continue;

        FirstLocale = i;
        uint32 build = CascStorage->GetBuildNumber();
        if (!build)
        {
            CascStorage.reset();
            continue;
        }

        printf("Detected client build %u for locale %s\n\n", build, localeNames[i]);
        break;
    }

    if (FirstLocale == -1)
    {
        printf("FATAL ERROR: No locales defined, unable to continue.\n");
        return 1;
    }

    // Extract models, listed in GameObjectDisplayInfo.dbc
    ExtractGameobjectModels();

    //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
    //map.dbc
    if (success)
    {
        printf("Read Map.dbc file... ");

        DB2CascFileSource source(CascStorage, MapLoadInfo::Instance.Meta->FileDataId);
        DB2FileLoader db2;
        try
        {
            db2.Load(&source, &MapLoadInfo::Instance);
        }
        catch (std::exception const& e)
        {
            printf("Fatal error: Invalid Map.db2 file format! %s\n%s\n", CASC::HumanReadableCASCError(GetCascError()), e.what());
            exit(1);
        }

        map_ids.reserve(db2.GetRecordCount());
        std::unordered_map<uint32, std::size_t> idToIndex;
        for (uint32 x = 0; x < db2.GetRecordCount(); ++x)
        {
            DB2Record record = db2.GetRecord(x);
            if (!record)
                continue;

            MapEntry map;
            map.Id = record.GetId();
            map.WdtFileDataId = record.GetInt32("WdtFileDataID");
            map.ParentMapID = int16(record.GetUInt16("ParentMapID"));
            map.Name = record.GetString("MapName");
            map.Directory = record.GetString("Directory");

            if (map.ParentMapID < 0)
                map.ParentMapID = int16(record.GetUInt16("CosmeticParentMapID"));

            if (map.ParentMapID >= 0)
                maps_that_are_parents.insert(map.ParentMapID);

            idToIndex[map.Id] = map_ids.size();
            map_ids.push_back(map);
        }

        for (uint32 x = 0; x < db2.GetRecordCopyCount(); ++x)
        {
            DB2RecordCopy copy = db2.GetRecordCopy(x);
            auto itr = idToIndex.find(copy.SourceRowId);
            if (itr != idToIndex.end())
            {
                MapEntry map;
                map.Id = copy.NewRowId;
                map.WdtFileDataId = map_ids[itr->second].WdtFileDataId;
                map.ParentMapID = map_ids[itr->second].ParentMapID;
                map.Name = map_ids[itr->second].Name;
                map.Directory = map_ids[itr->second].Directory;
                map_ids.push_back(map);
            }
        }

        map_ids.erase(std::remove_if(map_ids.begin(), map_ids.end(), [](MapEntry const& map) { return !map.WdtFileDataId; }), map_ids.end());

        // force parent maps to be extracted first
        std::stable_partition(map_ids.begin(), map_ids.end(), [](MapEntry const& map) { return maps_that_are_parents.count(map.Id) > 0; });

        printf("Done! (" SZFMTD " maps loaded)\n", map_ids.size());
        ParsMapFiles();
    }

    CascStorage.reset();

    printf("\n");
    if (!success)
    {
        printf("ERROR: Extract %s. Work NOT complete.\n   Precise vector data=%d.\nPress any key.\n", VMAP::VMAP_MAGIC, preciseVectorData);
        getchar();
    }

    printf("Extract %s. Work complete. No errors.\n", VMAP::VMAP_MAGIC);
    return 0;
}
