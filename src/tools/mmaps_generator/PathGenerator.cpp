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
#include "IoContext.h"
#include "Locales.h"
#include "Log.h"
#include "MapBuilder.h"
#include "Memory.h"
#include "PathCommon.h"
#include "Timer.h"
#include "Util.h"
#include "VMapManager.h"
#include <boost/filesystem/operations.hpp>
#include <unordered_map>
#include <vector>

constexpr char Readme[] =
{
#include "Info/readme.txt"
};

namespace
{
    std::unordered_map<uint32, uint8> _liquidTypes;
}

namespace MMAP
{
    std::unordered_map<uint32, MapEntry> sMapStore;

    namespace VMapFactory
    {
        std::unique_ptr<VMAP::VMapManager> CreateVMapManager(uint32 mapId)
        {
            std::unique_ptr<VMAP::VMapManager> vmgr = std::make_unique<VMAP::VMapManager>();

            do
            {
                int32 parentMapId = sMapStore[mapId].ParentMapID;

                vmgr->InitializeThreadUnsafe(mapId, parentMapId);
                if (parentMapId < 0)
                    break;

                mapId = parentMapId;
            } while (true);

            vmgr->GetLiquidFlagsPtr = [](uint32 liquidId) -> uint32
            {
                auto itr = _liquidTypes.find(liquidId);
                return itr != _liquidTypes.end() ? (1 << itr->second) : 0;
            };
            vmgr->LoadPathOnlyModels = true;
            return vmgr;
        }
    }
}

void SetupLogging(Trinity::Asio::IoContext* ioContext)
{
    Log* log = sLog;

    log->SetAsynchronous(ioContext);

    log->CreateAppenderFromConfigLine("Appender.Console", "1,2,0");         // APPENDER_CONSOLE | LOG_LEVEL_DEBUG | APPENDER_FLAGS_NONE
    log->CreateLoggerFromConfigLine("Logger.root", "2,Console");            // LOG_LEVEL_DEBUG | Console appender
    log->CreateLoggerFromConfigLine("Logger.tool.mmapgen", "2,Console");    // LOG_LEVEL_DEBUG | Console appender
    log->CreateLoggerFromConfigLine("Logger.maps", "3,Console");            // LOG_LEVEL_DEBUG | Console appender
    log->CreateLoggerFromConfigLine("Logger.maps.mmapgen", "2,Console");    // LOG_LEVEL_DEBUG | Console appender
}

bool checkDirectories(boost::filesystem::path const& inputDirectory, boost::filesystem::path const& outputDirectory,
    bool debugOutput, std::vector<std::string>& dbcLocales)
{
    if (MMAP::getDirContents(dbcLocales, inputDirectory / "dbc", boost::filesystem::directory_file) == MMAP::LISTFILE_DIRECTORY_NOT_FOUND || dbcLocales.empty())
    {
        TC_LOG_ERROR("tool.mmapgen", "'dbc' directory is empty or does not exist");
        return false;
    }

    std::vector<std::string> dirFiles;

    if (MMAP::getDirContents(dirFiles, inputDirectory / "maps") == MMAP::LISTFILE_DIRECTORY_NOT_FOUND || dirFiles.empty())
    {
        TC_LOG_ERROR("tool.mmapgen", "'maps' directory is empty or does not exist");
        return false;
    }

    dirFiles.clear();
    if (MMAP::getDirContents(dirFiles, inputDirectory / "vmaps" / "0000", boost::filesystem::regular_file, "*.vmtree") == MMAP::LISTFILE_DIRECTORY_NOT_FOUND || dirFiles.empty())
    {
        TC_LOG_ERROR("tool.mmapgen", "'vmaps' directory is empty or does not exist");
        return false;
    }

    boost::system::error_code ec;
    if (!boost::filesystem::create_directories(outputDirectory / "mmaps", ec) && ec)
    {
        TC_LOG_ERROR("tool.mmapgen", "'mmaps' directory does not exist and failed to create it");
        return false;
    }

    if (debugOutput)
    {
        if (!boost::filesystem::create_directories(outputDirectory / "meshes", ec) && ec)
        {
            TC_LOG_ERROR("tool.mmapgen", "'meshes' directory does not exist and failed to create it (no place to put debugOutput files)");
            return false;
        }
    }

    return true;
}

int finish(char const* message, int returnValue)
{
    TC_LOG_FATAL("tool.mmapgen.commandline", "{}", message);
    getchar(); // Wait for user input
    return returnValue;
}

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
               char const*& offMeshInputPath,
               char const*& file,
               unsigned int& threads,
               boost::filesystem::path& inputDirectory,
               boost::filesystem::path& outputDirectory)
{
    char* param = nullptr;
    [[maybe_unused]] bool allowDebug = false;
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], "--maxAngle") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            float maxangle = atof(param);
            if (maxangle <= 90.f && maxangle >= 0.f)
                maxAngle = maxangle;
            else
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--maxAngle', using default");
        }
        else if (strcmp(argv[i], "--maxAngleNotSteep") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            float maxangle = atof(param);
            if (maxangle <= 90.f && maxangle >= 0.f)
                maxAngleNotSteep = maxangle;
            else
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--maxAngleNotSteep', using default");
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
            char* stileY = strtok(nullptr, ",");
            int tilex = atoi(stileX);
            int tiley = atoi(stileY);

            if ((tilex > 0 && tilex < 64) || (tilex == 0 && strcmp(stileX, "0") == 0))
                tileX = tilex;
            if ((tiley > 0 && tiley < 64) || (tiley == 0 && strcmp(stileY, "0") == 0))
                tileY = tiley;

            if (tileX < 0 || tileY < 0)
            {
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid tile coords.");
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
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--skipLiquid', using default");
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
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--skipContinents', using default");
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
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--skipJunkMaps', using default");
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
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--skipBattlegrounds', using default");
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
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--debugOutput', using default true");
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
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid option for '--bigBaseUnit', using default false");
        }
        else if (strcmp(argv[i], "--offMeshInput") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            offMeshInputPath = param;
        }
        else if (strcmp(argv[i], "--input") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            inputDirectory = param;
        }
        else if (strcmp(argv[i], "--output") == 0)
        {
            param = argv[++i];
            if (!param)
                return false;

            outputDirectory = param;
        }
        else if (strcmp(argv[i], "--allowDebug") == 0)
        {
            allowDebug = true;
        }
        else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-?"))
        {
            TC_LOG_INFO("tool.mmapgen", "{}", Readme);
            silent = true;
            return false;
        }
        else
        {
            int map = atoi(argv[i]);
            if (map > 0 || (map == 0 && (strcmp(argv[i], "0") == 0)))
                mapnum = map;
            else
            {
                TC_LOG_ERROR("tool.mmapgen.commandline", "invalid map id {}", map);
                return false;
            }
        }
    }

#if !defined(NDEBUG)
    if (!allowDebug)
    {
        finish("Build mmaps_generator in RelWithDebInfo or Release mode or it will take hours to complete!!!\nUse '--allowDebug' argument if you really want to run this tool in Debug.", -2);
        silent = true;
        return false;
    }
#endif

    return true;
}

std::unordered_map<uint32, uint8> LoadLiquid(boost::filesystem::path const& inputDirectory, std::string const& locale, bool silent, int32 errorExitCode)
{
    DB2FileLoader liquidDb2;
    std::unordered_map<uint32, uint8> liquidData;
    DB2FileSystemSource liquidTypeSource((inputDirectory / "dbc" / locale / "LiquidType.db2").string());
    try
    {
        liquidDb2.Load(&liquidTypeSource, &LiquidTypeLoadInfo::Instance);
        for (uint32 x = 0; x < liquidDb2.GetRecordCount(); ++x)
        {
            DB2Record record = liquidDb2.GetRecord(x);
            if (!record)
                continue;

            liquidData[record.GetId()] = record.GetUInt8("SoundBank");
        }
    }
    catch (std::exception const& e)
    {
        if (silent)
            exit(errorExitCode);

        exit(finish(e.what(), errorExitCode));
    }

    return liquidData;
}

void LoadMap(boost::filesystem::path const& inputDirectory, std::string const& locale, bool silent, int32 errorExitCode)
{
    DB2FileLoader mapDb2;
    DB2FileSystemSource mapSource((inputDirectory / "dbc" / locale / "Map.db2").string());
    try
    {
        mapDb2.Load(&mapSource, &MapLoadInfo::Instance);
        for (uint32 x = 0; x < mapDb2.GetRecordCount(); ++x)
        {
            DB2Record record = mapDb2.GetRecord(x);
            if (!record)
                continue;

            int16 parentMapId = int16(record.GetUInt16("ParentMapID"));
            if (parentMapId < 0)
                parentMapId = int16(record.GetUInt16("CosmeticParentMapID"));

            MMAP::MapEntry& map = MMAP::sMapStore[record.GetId()];
            map.MapType = record.GetUInt8("MapType");
            map.InstanceType = record.GetUInt8("InstanceType");
            map.ParentMapID = parentMapId;
            map.Flags = record.GetInt32("Flags1");
        }
    }
    catch (std::exception const& e)
    {
        if (silent)
            exit(errorExitCode);

        exit(finish(e.what(), errorExitCode));
    }
}

int main(int argc, char** argv)
{
    Trinity::VerifyOsVersion();

    Trinity::Locale::Init();

    Trinity::Asio::IoContext ioContext(1);

    SetupLogging(&ioContext);

    std::thread loggingThread;

    auto workGuard = std::pair(
        Trinity::make_unique_ptr_with_deleter(&loggingThread, [](std::thread* thread) { thread->join(); }),
        boost::asio::make_work_guard(ioContext.get_executor())
    );

    loggingThread = std::thread([](Trinity::Asio::IoContext* context) { context->run(); }, &ioContext);

    Trinity::Banner::Show("MMAP generator", [](char const* text) { TC_LOG_INFO("tool.mmapgen", "{}", text); }, nullptr);

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
    char const* offMeshInputPath = nullptr;
    char const* file = nullptr;
    boost::filesystem::path inputDirectory = boost::filesystem::current_path();
    boost::filesystem::path outputDirectory = boost::filesystem::current_path();

    bool validParam = handleArgs(argc, argv, mapnum,
                                 tileX, tileY, maxAngle, maxAngleNotSteep,
                                 skipLiquid, skipContinents, skipJunkMaps, skipBattlegrounds,
                                 debugOutput, silent, bigBaseUnit, offMeshInputPath, file, threads,
                                 inputDirectory, outputDirectory);

    if (!validParam)
        return silent ? -1 : finish("You have specified invalid parameters", -1);

    if (mapnum == -1 && debugOutput)
    {
        if (silent)
            return -2;

        TC_LOG_INFO("tool.mmapgen", "You have specifed debug output, but didn't specify a map to generate.");
        TC_LOG_INFO("tool.mmapgen", "This will generate debug output for ALL maps.");
        TC_LOG_INFO("tool.mmapgen", "Are you sure you want to continue? (y/n)");
        if (getchar() != 'y')
            return 0;
    }

    std::vector<std::string> dbcLocales;
    if (!checkDirectories(inputDirectory, outputDirectory, debugOutput, dbcLocales))
        return silent ? -3 : finish("Press ENTER to close...", -3);

    _liquidTypes = LoadLiquid(inputDirectory, dbcLocales[0], silent, -5);

    LoadMap(inputDirectory, dbcLocales[0], silent, -4);

    MMAP::CreateVMapManager = &MMAP::VMapFactory::CreateVMapManager;

    MMAP::MapBuilder builder(inputDirectory, outputDirectory, maxAngle, maxAngleNotSteep, skipLiquid, skipContinents, skipJunkMaps,
                       skipBattlegrounds, debugOutput, bigBaseUnit, mapnum, offMeshInputPath, threads);

    uint32 start = getMSTime();
    if (file)
        builder.buildMeshFromFile(file);
    else if (tileX > -1 && tileY > -1 && mapnum >= 0)
        builder.buildSingleTile(mapnum, tileX, tileY);
    else if (mapnum >= 0)
        builder.buildMaps(uint32(mapnum));
    else
        builder.buildMaps({});

    if (!silent)
        TC_LOG_INFO("tool.mmapgen", "Finished. MMAPS were built in {}", secsToTimeString(GetMSTimeDiffToNow(start) / 1000));

    return 0;
}

#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include "WheatyExceptionReport.h"
// must be at end of file because of init_seg pragma
INIT_CRASH_HANDLER();
#endif
