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

#include "Banner.h"
#include "DB2FileLoader.h"
#include "DB2FileSystemSource.h"
#include "ExtractorDB2LoadInfo.h"
#include "MapBuilder.h"
#include "PathCommon.h"
#include "Timer.h"
#include "VMapFactory.h"
#include "VMapManager2.h"
#include <boost/filesystem/operations.hpp>
#include <unordered_map>
#include <vector>

using namespace MMAP;

namespace
{
    std::unordered_map<uint32, uint8> _liquidTypes;
}

bool checkDirectories(bool debugOutput, std::vector<std::string>& dbcLocales)
{
    if (getDirContents(dbcLocales, "dbc") == LISTFILE_DIRECTORY_NOT_FOUND || dbcLocales.empty())
    {
        printf("'dbc' directory is empty or does not exist\n");
        return false;
    }

    std::vector<std::string> dirFiles;

    if (getDirContents(dirFiles, "maps") == LISTFILE_DIRECTORY_NOT_FOUND || dirFiles.empty())
    {
        printf("'maps' directory is empty or does not exist\n");
        return false;
    }

    dirFiles.clear();
    if (getDirContents(dirFiles, "vmaps", "*.vmtree") == LISTFILE_DIRECTORY_NOT_FOUND || dirFiles.empty())
    {
        printf("'vmaps' directory is empty or does not exist\n");
        return false;
    }

    dirFiles.clear();
    if (getDirContents(dirFiles, "mmaps") == LISTFILE_DIRECTORY_NOT_FOUND)
    {
        if (!boost::filesystem::create_directory("mmaps"))
        {
            printf("'mmaps' directory does not exist and failed to create it\n");
            return false;
        }
    }

    dirFiles.clear();
    if (debugOutput)
    {
        if (getDirContents(dirFiles, "meshes") == LISTFILE_DIRECTORY_NOT_FOUND)
        {
            if (!boost::filesystem::create_directory("meshes"))
            {
                printf("'meshes' directory does not exist and failed to create it (no place to put debugOutput files)\n");
                return false;
            }
        }
    }

    return true;
}

bool handleArgs(int argc, char** argv,
               int &mapnum,
               int &tileX,
               int &tileY,
               float &maxAngle,
               bool &skipLiquid,
               bool &skipContinents,
               bool &skipJunkMaps,
               bool &skipBattlegrounds,
               bool &debugOutput,
               bool &silent,
               bool &bigBaseUnit,
               char* &offMeshInputPath,
               char* &file,
               unsigned int& threads)
{
    char* param = NULL;
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--maxAngle") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            float maxangle = atof(param);
            if (maxangle <= 90.f && maxangle >= 45.f)
                maxAngle = maxangle;
            else
                printf("invalid option for '--maxAngle', using default\n");
        }
        else if (strcmp(argv[i], "--threads") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            threads = static_cast<unsigned int>(std::max(0, atoi(param)));
        }
        else if (strcmp(argv[i], "--file") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;
            file = param;
        }
        else if (strcmp(argv[i], "--tile") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            char* stileX = strtok(param, ",");
            char* stileY = strtok(NULL, ",");
            int tilex = atoi(stileX);
            int tiley = atoi(stileY);

            if ((tilex > 0 && tilex < 64) || (tilex == 0 && strcmp(stileX, "0") == 0))
                tileX = tilex;
            if ((tiley > 0 && tiley < 64) || (tiley == 0 && strcmp(stileY, "0") == 0))
                tileY = tiley;

            if (tileX < 0 || tileY < 0)
            {
                printf("invalid tile coords.\n");
                return false;
            }
        }
        else if (strcmp(argv[i], "--skipLiquid") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipLiquid = true;
            else if (strcmp(param, "false") == 0)
                skipLiquid = false;
            else
                printf("invalid option for '--skipLiquid', using default\n");
        }
        else if (strcmp(argv[i], "--skipContinents") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipContinents = true;
            else if (strcmp(param, "false") == 0)
                skipContinents = false;
            else
                printf("invalid option for '--skipContinents', using default\n");
        }
        else if (strcmp(argv[i], "--skipJunkMaps") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipJunkMaps = true;
            else if (strcmp(param, "false") == 0)
                skipJunkMaps = false;
            else
                printf("invalid option for '--skipJunkMaps', using default\n");
        }
        else if (strcmp(argv[i], "--skipBattlegrounds") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                skipBattlegrounds = true;
            else if (strcmp(param, "false") == 0)
                skipBattlegrounds = false;
            else
                printf("invalid option for '--skipBattlegrounds', using default\n");
        }
        else if (strcmp(argv[i], "--debugOutput") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                debugOutput = true;
            else if (strcmp(param, "false") == 0)
                debugOutput = false;
            else
                printf("invalid option for '--debugOutput', using default true\n");
        }
        else if (strcmp(argv[i], "--silent") == 0)
        {
            silent = true;
        }
        else if (strcmp(argv[i], "--bigBaseUnit") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            if (strcmp(param, "true") == 0)
                bigBaseUnit = true;
            else if (strcmp(param, "false") == 0)
                bigBaseUnit = false;
            else
                printf("invalid option for '--bigBaseUnit', using default false\n");
        }
        else if (strcmp(argv[i], "--offMeshInput") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            offMeshInputPath = param;
        }
        else
        {
            int map = atoi(argv[i]);
            if (map > 0 || (map == 0 && (strcmp(argv[i], "0") == 0)))
                mapnum = map;
            else
            {
                printf("invalid map id\n");
                return false;
            }
        }
    }

    return true;
}

int finish(const char* message, int returnValue)
{
    printf("%s", message);
    getchar(); // Wait for user input
    return returnValue;
}

std::unordered_map<uint32, uint8> LoadLiquid(std::string const& locale)
{
    DB2FileLoader liquidDb2;
    std::unordered_map<uint32, uint8> liquidData;
    DB2FileSystemSource liquidTypeSource((boost::filesystem::path("dbc") / locale / "LiquidType.db2").string());
    if (liquidDb2.Load(&liquidTypeSource, LiquidTypeLoadInfo::Instance()))
    {
        for (uint32 x = 0; x < liquidDb2.GetRecordCount(); ++x)
        {
            DB2Record record = liquidDb2.GetRecord(x);
            if (!record)
                continue;

            liquidData[record.GetId()] = record.GetUInt8("SoundBank");
        }
    }

    return liquidData;
}

std::unordered_map<uint32, std::vector<uint32>> LoadMap(std::string const& locale)
{
    DB2FileLoader mapDb2;
    std::unordered_map<uint32, std::vector<uint32>> mapData;
    DB2FileSystemSource mapSource((boost::filesystem::path("dbc") / locale / "Map.db2").string());
    if (mapDb2.Load(&mapSource, MapLoadInfo::Instance()))
    {
        for (uint32 x = 0; x < mapDb2.GetRecordCount(); ++x)
        {
            DB2Record record = mapDb2.GetRecord(x);
            if (!record)
                continue;

            mapData.emplace(std::piecewise_construct, std::forward_as_tuple(record.GetId()), std::forward_as_tuple());
            int16 parentMapId = int16(record.GetUInt16("ParentMapID"));
            if (parentMapId != -1)
                mapData[parentMapId].push_back(record.GetId());
        }
    }

    return mapData;
}

int main(int argc, char** argv)
{
    Trinity::Banner::Show("MMAP generator", [](char const* text) { printf("%s\n", text); }, nullptr);

    unsigned int threads = std::thread::hardware_concurrency();
    int mapnum = -1;
    float maxAngle = 70.0f;
    int tileX = -1, tileY = -1;
    bool skipLiquid = false,
         skipContinents = false,
         skipJunkMaps = true,
         skipBattlegrounds = false,
         debugOutput = false,
         silent = false,
         bigBaseUnit = false;
    char* offMeshInputPath = NULL;
    char* file = NULL;

    bool validParam = handleArgs(argc, argv, mapnum,
                                 tileX, tileY, maxAngle,
                                 skipLiquid, skipContinents, skipJunkMaps, skipBattlegrounds,
                                 debugOutput, silent, bigBaseUnit, offMeshInputPath, file, threads);

    if (!validParam)
        return silent ? -1 : finish("You have specified invalid parameters", -1);

    if (mapnum == -1 && debugOutput)
    {
        if (silent)
            return -2;

        printf("You have specifed debug output, but didn't specify a map to generate.\n");
        printf("This will generate debug output for ALL maps.\n");
        printf("Are you sure you want to continue? (y/n) ");
        if (getchar() != 'y')
            return 0;
    }

    std::vector<std::string> dbcLocales;
    if (!checkDirectories(debugOutput, dbcLocales))
        return silent ? -3 : finish("Press ENTER to close...", -3);

    _liquidTypes = LoadLiquid(dbcLocales[0]);
    if (_liquidTypes.empty())
        return silent ? -5 : finish("Failed to load LiquidType.db2", -5);

    std::unordered_map<uint32, std::vector<uint32>> mapData = LoadMap(dbcLocales[0]);
    if (mapData.empty())
        return silent ? -4 : finish("Failed to load Map.db2", -4);

    static_cast<VMAP::VMapManager2*>(VMAP::VMapFactory::createOrGetVMapManager())->InitializeThreadUnsafe(mapData);
    static_cast<VMAP::VMapManager2*>(VMAP::VMapFactory::createOrGetVMapManager())->GetLiquidFlagsPtr = [](uint32 liquidId) -> uint32
    {
        auto itr = _liquidTypes.find(liquidId);
        return itr != _liquidTypes.end() ? (1 << itr->second) : 0;
    };

    MapBuilder builder(maxAngle, skipLiquid, skipContinents, skipJunkMaps,
                       skipBattlegrounds, debugOutput, bigBaseUnit, mapnum, offMeshInputPath);

    uint32 start = getMSTime();
    if (file)
        builder.buildMeshFromFile(file);
    else if (tileX > -1 && tileY > -1 && mapnum >= 0)
        builder.buildSingleTile(mapnum, tileX, tileY);
    else if (mapnum >= 0)
        builder.buildMap(uint32(mapnum));
    else
        builder.buildAllMaps(threads);

    VMAP::VMapFactory::clear();

    if (!silent)
        printf("Finished. MMAPS were built in %u ms!\n", GetMSTimeDiffToNow(start));
    return 0;
}
