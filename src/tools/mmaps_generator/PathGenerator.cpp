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
#include "DBCFileLoader.h"
#include "MapBuilder.h"
#include "PathCommon.h"
#include "Timer.h"
#include "Util.h"
#include <boost/filesystem.hpp>
#include <unordered_map>
 // @tswow-begin
#include <cxxopts.h>
// @tswow-end

using namespace MMAP;

namespace
{
    std::unordered_map<uint32, uint8> _liquidTypes;
}

uint32 GetLiquidFlags(uint32 liquidId)
{
    auto itr = _liquidTypes.find(liquidId);
    return itr != _liquidTypes.end() ? (1 << itr->second) : 0;
}

bool checkDirectories(bool debugOutput)
{
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
        return boost::filesystem::create_directory("mmaps");

    dirFiles.clear();
    if (debugOutput)
    {
        if (getDirContents(dirFiles, "meshes") == LISTFILE_DIRECTORY_NOT_FOUND)
        {
            printf("'meshes' directory does not exist (no place to put debugOutput files)\n");
            return false;
        }
    }

    return true;
}

// @tswow-begin
void Usage(cxxopts::Options const& opts, std::string const& error)
{
    printf("Error %s\n%s", error.c_str(), opts.help().c_str());
    exit(1);
}

std::string input;
std::string output;
std::set<uint32> generated_maps;
std::set<std::pair<int, int>> generated_tiles;
bool handleArgs(int argc, char** argv,
    int& mapnum,
    int& tileX,
    int& tileY,
    Optional<float>& maxAngle,
    Optional<float>& maxAngleNotSteep,
    bool& skipLiquid,
    bool& skipContinents,
    bool& skipJunkMaps,
    bool& skipBattlegrounds,
    bool& debugOutput,
    bool& silent,
    bool& bigBaseUnit,
    char*& offMeshInputPath,
    char*& file,
    unsigned int& threads)
{
    cxxopts::Options options("mmaps_generator", "Generate mmaps");
    options.add_options()
        ("i,input", "Input path", cxxopts::value<std::string>()->default_value("Buildings"))
        ("o,output", "Output path", cxxopts::value<std::string>()->default_value("vmaps"))
        ("offMeshInput", "", cxxopts::value<bool>()->default_value("0"))
        ("silent", "", cxxopts::value<bool>()->default_value("0"))
        ("debugOutput", "", cxxopts::value<bool>()->default_value("0"))
        ("skipBattlegrounds", "", cxxopts::value<bool>()->default_value("0"))
        ("skipJunkMaps", "", cxxopts::value<bool>()->default_value("0"))
        ("skipLiquid", "", cxxopts::value<bool>()->default_value("0"))
        ("file", "", cxxopts::value<std::string>()->default_value(""))
        ("threads", "", cxxopts::value<int>()->default_value("3"))
        ("maxAngle", "", cxxopts::value<int>()->default_value("0"))
        ("maxAngleNotSteep", "", cxxopts::value<int>()->default_value("0"))
        ("maps", "Specify individual maps to create", cxxopts::value<std::vector<int>>()->default_value(""))
        ("tiles", "Specify individual tiles to create", cxxopts::value<std::vector<int>>()->default_value(""))
        ;

    auto result = options.parse(argc, argv);
    input = result["input"].as<std::string>();
    output = result["output"].as<std::string>();

    if (result.count("maxAngle") > 0)
    {
        maxAngle = result["maxAngle"].as<float>();
    }

    if (result.count("maxAngleNotSteep") > 0)
    {
        maxAngleNotSteep = result["maxAngleNotSteep"].as<float>();
    }

    silent = result["silent"].as<bool>();
    debugOutput = result["debugOutput"].as<bool>();
    skipBattlegrounds = result["skipBattlegrounds"].as<bool>();
    skipJunkMaps = result["skipJunkMaps"].as<bool>();
    skipLiquid = result["skipLiquid"].as<bool>();
    threads = result["threads"].as<int>();

    auto maps = result["maps"].as<std::vector<int>>();
    for (auto map : maps) generated_maps.insert(map);

    auto tiles = result["tiles"].as<std::vector<int>>();
    if (tiles.size() % 2 == 1)
    {
        Usage(options, "Error: uneven set of tile coordinates");
    }
    for (unsigned i = 0; i < tiles.size() / 2; ++i)
    {
        unsigned nxt = i + 1;
        generated_tiles.insert({ tiles[i],tiles[nxt] });
    }

    return true;
}
// @tswow-end

int finish(char const* message, int returnValue)
{
    printf("%s", message);
    getchar(); // Wait for user input
    return returnValue;
}

std::unordered_map<uint32, uint8> LoadLiquid()
{
    DBCFileLoader liquidDbc;
    std::unordered_map<uint32, uint8> liquidData;
    // format string doesnt matter as long as it has correct length (only used for mapping to structures in worldserver)
    if (liquidDbc.Load((boost::filesystem::path("dbc") / "LiquidType.dbc").string().c_str(), "nxxixixxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"))
    {
        for (uint32 x = 0; x < liquidDbc.GetNumRows(); ++x)
        {
            DBCFileLoader::Record record = liquidDbc.getRecord(x);
            liquidData[record.getUInt(0)] = record.getUInt(3);
        }
    }

    return liquidData;
}

int main(int argc, char** argv)
{
    Trinity::Banner::Show("MMAP generator", [](char const* text) { printf("%s\n", text); }, nullptr);

    unsigned int threads = std::thread::hardware_concurrency();
    int mapnum = -1;
    int tileX = -1, tileY = -1;
    Optional<float> maxAngle, maxAngleNotSteep;
    bool skipLiquid = false,
        skipContinents = false,
        skipJunkMaps = true,
        skipBattlegrounds = false,
        debugOutput = false,
        silent = false,
        bigBaseUnit = false;
    char* offMeshInputPath = nullptr;
    char* file = nullptr;

    bool validParam = handleArgs(argc, argv, mapnum,
        tileX, tileY, maxAngle, maxAngleNotSteep,
        skipLiquid, skipContinents, skipJunkMaps, skipBattlegrounds,
        debugOutput, silent, bigBaseUnit, offMeshInputPath, file, threads);

    if (!validParam)
        return silent ? -1 : finish("You have specified invalid parameters", -1);

    // @tswow-begin
    if (generated_maps.size() > 0 && debugOutput)
        // @tswow-end
    {
        if (silent)
            return -2;

        printf("You have specifed debug output, but didn't specify a map to generate.\n");
        printf("This will generate debug output for ALL maps.\n");
        printf("Are you sure you want to continue? (y/n) ");
        if (getchar() != 'y')
            return 0;
    }

    if (!checkDirectories(debugOutput))
        return silent ? -3 : finish("Press ENTER to close...", -3);

    _liquidTypes = LoadLiquid();
    if (_liquidTypes.empty())
        return silent ? -5 : finish("Failed to load LiquidType.dbc", -5);

    MapBuilder builder(maxAngle, maxAngleNotSteep, skipLiquid, skipContinents, skipJunkMaps,
        // @tswow-begin
        skipBattlegrounds, debugOutput, bigBaseUnit, generated_maps, offMeshInputPath, threads);
    // @tswow-end

    uint32 start = getMSTime();
    if (file)
        builder.buildMeshFromFile(file);
    // @tswow-begin
    else builder.buildMaps(generated_maps, generated_tiles);
    // @tswow-end

    if (!silent)
        printf("Finished. MMAPS were built in %s\n", secsToTimeString(GetMSTimeDiffToNow(start) / 1000).c_str());
    return 0;
}
