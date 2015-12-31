/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include <deque>
#include <fstream>
#include <set>
#include <cstdlib>
#include <cstring>

#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include "Common.h"
#ifdef PLATFORM_WINDOWS
#undef PLATFORM_WINDOWS
#endif
#include "DBFilesClientList.h"
#include "CascLib.h"
#include "dbcfile.h"
#include "StringFormat.h"

#include "adt.h"
#include "wdt.h"

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

HANDLE CascStorage = NULL;

typedef struct
{
    char name[64];
    uint32 id;
} map_id;

map_id *map_ids;
uint16 *areas;
uint16 *LiqType;
#define MAX_PATH_LENGTH 128
char output_path[MAX_PATH_LENGTH];
char input_path[MAX_PATH_LENGTH];
uint32 maxAreaId = 0;

// **************************************************
// Extractor options
// **************************************************
enum Extract
{
    EXTRACT_MAP = 1,
    EXTRACT_DBC = 2
};

// Select data for extract
int   CONF_extract = EXTRACT_MAP | EXTRACT_DBC;

// This option allow limit minimum height to some value (Allow save some memory)
bool  CONF_allow_height_limit = true;
float CONF_use_minHeight = -500.0f;

// This option allow use float to int conversion
bool  CONF_allow_float_to_int   = true;
float CONF_float_to_int8_limit  = 2.0f;      // Max accuracy = val/256
float CONF_float_to_int16_limit = 2048.0f;   // Max accuracy = val/65536
float CONF_flat_height_delta_limit = 0.005f; // If max - min less this value - surface is flat
float CONF_flat_liquid_delta_limit = 0.001f; // If max - min less this value - liquid surface is flat

uint32 CONF_Locale = 0;

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

void CreateDir(boost::filesystem::path const& path)
{
    namespace fs = boost::filesystem;
    if (fs::exists(path))
        return;

    if (!fs::create_directory(path))
        throw new std::runtime_error("Unable to create directory" + path.string());
}

void Usage(char const* prg)
{
    printf(
        "Usage:\n"\
        "%s -[var] [value]\n"\
        "-i set input path (max %d characters)\n"\
        "-o set output path (max %d characters)\n"\
        "-e extract only MAP(1)/DBC(2) - standard: both(3)\n"\
        "-f height stored as int (less map size but lost some accuracy) 1 by default\n"\
        "-l dbc locale\n"\
        "Example: %s -f 0 -i \"c:\\games\\game\"\n", prg, MAX_PATH_LENGTH - 1, MAX_PATH_LENGTH - 1, prg);
    exit(1);
}

void HandleArgs(int argc, char* arg[])
{
    for (int c = 1; c < argc; ++c)
    {
        // i - input path
        // o - output path
        // e - extract only MAP(1)/DBC(2) - standard both(3)
        // f - use float to int conversion
        // h - limit minimum height
        // b - target client build
        if (arg[c][0] != '-')
            Usage(arg[0]);

        switch (arg[c][1])
        {
            case 'i':
                if (c + 1 < argc && strlen(arg[c + 1]) < MAX_PATH_LENGTH) // all ok
                {
                    strncpy(input_path, arg[c++ + 1], MAX_PATH_LENGTH);
                    input_path[MAX_PATH_LENGTH - 1] = '\0';
                }
                else
                    Usage(arg[0]);
                break;
            case 'o':
                if (c + 1 < argc && strlen(arg[c + 1]) < MAX_PATH_LENGTH) // all ok
                {
                    strncpy(output_path, arg[c++ + 1], MAX_PATH_LENGTH);
                    output_path[MAX_PATH_LENGTH - 1] = '\0';
                }
                else
                    Usage(arg[0]);
                break;
            case 'f':
                if (c + 1 < argc)                            // all ok
                    CONF_allow_float_to_int = atoi(arg[c++ + 1])!=0;
                else
                    Usage(arg[0]);
                break;
            case 'e':
                if (c + 1 < argc)                            // all ok
                {
                    CONF_extract = atoi(arg[c++ + 1]);
                    if (!(CONF_extract > 0 && CONF_extract < 4))
                        Usage(arg[0]);
                }
                else
                    Usage(arg[0]);
                break;
            case 'l':
                if (c + 1 < argc)                            // all ok
                {
                    for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
                        if (!strcmp(arg[c + 1], localeNames[i]))
                            CONF_Locale = 1 << i;
                    ++c;
                }
                else
                    Usage(arg[0]);
                break;
            case 'h':
                Usage(arg[0]);
                break;
            default:
                break;
        }
    }
}

uint32 ReadBuild(int locale)
{
    // include build info file also
    std::string filename = Trinity::StringFormat("component.wow-%s.txt", localeNames[locale]);
    //printf("Read %s file... ", filename.c_str());

    HANDLE dbcFile;
    if (!CascOpenFile(CascStorage, filename.c_str(), CASC_LOCALE_ALL, 0, &dbcFile))
    {
        printf("Locale %s not installed.\n", localeNames[locale]);
        return 0;
    }

    char buff[512];
    DWORD readBytes = 0;
    CascReadFile(dbcFile, buff, 512, &readBytes);
    if (!readBytes)
    {
        printf("Fatal error: Not found %s file!\n", filename.c_str());
        exit(1);
    }

    std::string text = std::string(buff, readBytes);
    CascCloseFile(dbcFile);

    size_t pos = text.find("version=\"");
    size_t pos1 = pos + strlen("version=\"");
    size_t pos2 = text.find("\"", pos1);
    if (pos == text.npos || pos2 == text.npos || pos1 >= pos2)
    {
        printf("Fatal error: Invalid  %s file format!\n", filename.c_str());
        exit(1);
    }

    std::string build_str = text.substr(pos1,pos2-pos1);

    int build = atoi(build_str.c_str());
    if (build <= 0)
    {
        printf("Fatal error: Invalid  %s file format!\n", filename.c_str());
        exit(1);
    }

    return build;
}

uint32 ReadMapDBC()
{
    printf("Read Map.dbc file... ");

    HANDLE dbcFile;
    if (!CascOpenFile(CascStorage, "DBFilesClient\\Map.dbc", CASC_LOCALE_NONE, 0, &dbcFile))
    {
        printf("Fatal error: Cannot find Map.dbc in archive! %s\n", HumanReadableCASCError(GetLastError()));
        exit(1);
    }

    DBCFile dbc(dbcFile);
    if (!dbc.open())
    {
        printf("Fatal error: Invalid Map.dbc file format!\n");
        exit(1);
    }

    size_t map_count = dbc.getRecordCount();
    map_ids = new map_id[map_count];
    for(uint32 x = 0; x < map_count; ++x)
    {
        map_ids[x].id = dbc.getRecord(x).getUInt(0);

        const char* map_name = dbc.getRecord(x).getString(1);
        size_t max_map_name_length = sizeof(map_ids[x].name);
        if (strlen(map_name) >= max_map_name_length)
        {
            printf("Fatal error: Map name too long!\n");
            exit(1);
        }

        strncpy(map_ids[x].name, map_name, max_map_name_length);
        map_ids[x].name[max_map_name_length - 1] = '\0';
    }

    CascCloseFile(dbcFile);
    printf("Done! (" SZFMTD " maps loaded)\n", map_count);
    return map_count;
}

void ReadAreaTableDBC()
{
    printf("Read AreaTable.dbc file...");
    HANDLE dbcFile;
    if (!CascOpenFile(CascStorage, "DBFilesClient\\AreaTable.dbc", CASC_LOCALE_NONE, 0, &dbcFile))
    {
        printf("Fatal error: Cannot find AreaTable.dbc in archive! %s\n", HumanReadableCASCError(GetLastError()));
        exit(1);
    }

    DBCFile dbc(dbcFile);
    if(!dbc.open())
    {
        printf("Fatal error: Invalid AreaTable.dbc file format!\n");
        exit(1);
    }

    size_t area_count = dbc.getRecordCount();
    maxAreaId = dbc.getMaxId();
    areas = new uint16[maxAreaId + 1];
    memset(areas, 0xFF, sizeof(uint16) * (maxAreaId + 1));

    for (uint32 x = 0; x < area_count; ++x)
        areas[dbc.getRecord(x).getUInt(0)] = dbc.getRecord(x).getUInt(3);

    CascCloseFile(dbcFile);
    printf("Done! (" SZFMTD " areas loaded)\n", area_count);
}

void ReadLiquidTypeTableDBC()
{
    printf("Read LiquidType.dbc file...");
    HANDLE dbcFile;
    if (!CascOpenFile(CascStorage, "DBFilesClient\\LiquidType.dbc", CASC_LOCALE_NONE, 0, &dbcFile))
    {
        printf("Fatal error: Cannot find LiquidType.dbc in archive! %s\n", HumanReadableCASCError(GetLastError()));
        exit(1);
    }

    DBCFile dbc(dbcFile);
    if(!dbc.open())
    {
        printf("Fatal error: Invalid LiquidType.dbc file format!\n");
        exit(1);
    }

    size_t liqTypeCount = dbc.getRecordCount();
    size_t liqTypeMaxId = dbc.getMaxId();
    LiqType = new uint16[liqTypeMaxId + 1];
    memset(LiqType, 0xff, (liqTypeMaxId + 1) * sizeof(uint16));

    for(uint32 x = 0; x < liqTypeCount; ++x)
        LiqType[dbc.getRecord(x).getUInt(0)] = dbc.getRecord(x).getUInt(3);

    CascCloseFile(dbcFile);
    printf("Done! (" SZFMTD " LiqTypes loaded)\n", liqTypeCount);
}

//
// Adt file convertor function and data
//

// Map file format data
static char const* MAP_MAGIC         = "MAPS";
static char const* MAP_VERSION_MAGIC = "v1.5";
static char const* MAP_AREA_MAGIC    = "AREA";
static char const* MAP_HEIGHT_MAGIC  = "MHGT";
static char const* MAP_LIQUID_MAGIC  = "MLIQ";

struct map_fileheader
{
    uint32 mapMagic;
    uint32 versionMagic;
    uint32 buildMagic;
    uint32 areaMapOffset;
    uint32 areaMapSize;
    uint32 heightMapOffset;
    uint32 heightMapSize;
    uint32 liquidMapOffset;
    uint32 liquidMapSize;
    uint32 holesOffset;
    uint32 holesSize;
};

#define MAP_AREA_NO_AREA      0x0001

struct map_areaHeader
{
    uint32 fourcc;
    uint16 flags;
    uint16 gridArea;
};

#define MAP_HEIGHT_NO_HEIGHT  0x0001
#define MAP_HEIGHT_AS_INT16   0x0002
#define MAP_HEIGHT_AS_INT8    0x0004

struct map_heightHeader
{
    uint32 fourcc;
    uint32 flags;
    float  gridHeight;
    float  gridMaxHeight;
};

#define MAP_LIQUID_TYPE_NO_WATER    0x00
#define MAP_LIQUID_TYPE_WATER       0x01
#define MAP_LIQUID_TYPE_OCEAN       0x02
#define MAP_LIQUID_TYPE_MAGMA       0x04
#define MAP_LIQUID_TYPE_SLIME       0x08

#define MAP_LIQUID_TYPE_DARK_WATER  0x10
#define MAP_LIQUID_TYPE_WMO_WATER   0x20


#define MAP_LIQUID_NO_TYPE    0x0001
#define MAP_LIQUID_NO_HEIGHT  0x0002

struct map_liquidHeader
{
    uint32 fourcc;
    uint16 flags;
    uint16 liquidType;
    uint8  offsetX;
    uint8  offsetY;
    uint8  width;
    uint8  height;
    float  liquidLevel;
};

float selectUInt8StepStore(float maxDiff)
{
    return 255 / maxDiff;
}

float selectUInt16StepStore(float maxDiff)
{
    return 65535 / maxDiff;
}
// Temporary grid data store
uint16 area_flags[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];

float V8[ADT_GRID_SIZE][ADT_GRID_SIZE];
float V9[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];
uint16 uint16_V8[ADT_GRID_SIZE][ADT_GRID_SIZE];
uint16 uint16_V9[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];
uint8  uint8_V8[ADT_GRID_SIZE][ADT_GRID_SIZE];
uint8  uint8_V9[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];

uint16 liquid_entry[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];
uint8 liquid_flags[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];
bool  liquid_show[ADT_GRID_SIZE][ADT_GRID_SIZE];
float liquid_height[ADT_GRID_SIZE+1][ADT_GRID_SIZE+1];
uint8 holes[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID][8];

bool TransformToHighRes(uint16 holes, uint8 hiResHoles[8])
{
    for (uint8 i = 0; i < 8; i++)
    {
        for (uint8 j = 0; j < 8; j++)
        {
            int32 holeIdxL = (i / 2) * 4 + (j / 2);
            if (((holes >> holeIdxL) & 1) == 1)
                hiResHoles[i] |= (1 << j);
        }
    }

    return *((uint64*)hiResHoles) != 0;
}

bool ConvertADT(std::string const& inputPath, std::string const& outputPath, int /*cell_y*/, int /*cell_x*/, uint32 build)
{
    ChunkedFile adt;

    if (!adt.loadFile(CascStorage, inputPath))
        return false;

    // Prepare map header
    map_fileheader map;
    map.mapMagic = *reinterpret_cast<uint32 const*>(MAP_MAGIC);
    map.versionMagic = *reinterpret_cast<uint32 const*>(MAP_VERSION_MAGIC);
    map.buildMagic = build;

    // Get area flags data
    memset(area_flags, 0xFF, sizeof(area_flags));
    memset(V9, 0, sizeof(V9));
    memset(V8, 0, sizeof(V8));

    memset(liquid_show, 0, sizeof(liquid_show));
    memset(liquid_flags, 0, sizeof(liquid_flags));
    memset(liquid_entry, 0, sizeof(liquid_entry));

    memset(holes, 0, sizeof(holes));

    bool hasHoles = false;

    for (std::multimap<std::string, FileChunk*>::const_iterator itr = adt.chunks.lower_bound("MCNK"); itr != adt.chunks.upper_bound("MCNK"); ++itr)
    {
        adt_MCNK* mcnk = itr->second->As<adt_MCNK>();

        // Area data
        if (mcnk->areaid <= maxAreaId && areas[mcnk->areaid] != 0xFFFF)
            area_flags[mcnk->iy][mcnk->ix] = areas[mcnk->areaid];

        // Height
        // Height values for triangles stored in order:
        // 1     2     3     4     5     6     7     8     9
        //    10    11    12    13    14    15    16    17
        // 18    19    20    21    22    23    24    25    26
        //    27    28    29    30    31    32    33    34
        // . . . . . . . .
        // For better get height values merge it to V9 and V8 map
        // V9 height map:
        // 1     2     3     4     5     6     7     8     9
        // 18    19    20    21    22    23    24    25    26
        // . . . . . . . .
        // V8 height map:
        //    10    11    12    13    14    15    16    17
        //    27    28    29    30    31    32    33    34
        // . . . . . . . .

        // Set map height as grid height
        for (int y = 0; y <= ADT_CELL_SIZE; y++)
        {
            int cy = mcnk->iy * ADT_CELL_SIZE + y;
            for (int x = 0; x <= ADT_CELL_SIZE; x++)
            {
                int cx = mcnk->ix * ADT_CELL_SIZE + x;
                V9[cy][cx] = mcnk->ypos;
            }
        }

        for (int y = 0; y < ADT_CELL_SIZE; y++)
        {
            int cy = mcnk->iy * ADT_CELL_SIZE + y;
            for (int x = 0; x < ADT_CELL_SIZE; x++)
            {
                int cx = mcnk->ix * ADT_CELL_SIZE + x;
                V8[cy][cx] = mcnk->ypos;
            }
        }

        // Get custom height
        if (FileChunk* chunk = itr->second->GetSubChunk("MCVT"))
        {
            adt_MCVT* mcvt = chunk->As<adt_MCVT>();
            // get V9 height map
            for (int y = 0; y <= ADT_CELL_SIZE; y++)
            {
                int cy = mcnk->iy * ADT_CELL_SIZE + y;
                for (int x = 0; x <= ADT_CELL_SIZE; x++)
                {
                    int cx = mcnk->ix * ADT_CELL_SIZE + x;
                    V9[cy][cx] += mcvt->height_map[y*(ADT_CELL_SIZE * 2 + 1) + x];
                }
            }
            // get V8 height map
            for (int y = 0; y < ADT_CELL_SIZE; y++)
            {
                int cy = mcnk->iy * ADT_CELL_SIZE + y;
                for (int x = 0; x < ADT_CELL_SIZE; x++)
                {
                    int cx = mcnk->ix * ADT_CELL_SIZE + x;
                    V8[cy][cx] += mcvt->height_map[y*(ADT_CELL_SIZE * 2 + 1) + ADT_CELL_SIZE + 1 + x];
                }
            }
        }

        // Liquid data
        if (mcnk->sizeMCLQ > 8)
        {
            if (FileChunk* chunk = itr->second->GetSubChunk("MCLQ"))
            {
                adt_MCLQ* liquid = chunk->As<adt_MCLQ>();
                int count = 0;
                for (int y = 0; y < ADT_CELL_SIZE; ++y)
                {
                    int cy = mcnk->iy * ADT_CELL_SIZE + y;
                    for (int x = 0; x < ADT_CELL_SIZE; ++x)
                    {
                        int cx = mcnk->ix * ADT_CELL_SIZE + x;
                        if (liquid->flags[y][x] != 0x0F)
                        {
                            liquid_show[cy][cx] = true;
                            if (liquid->flags[y][x] & (1 << 7))
                                liquid_flags[mcnk->iy][mcnk->ix] |= MAP_LIQUID_TYPE_DARK_WATER;
                            ++count;
                        }
                    }
                }

                uint32 c_flag = mcnk->flags;
                if (c_flag & (1 << 2))
                {
                    liquid_entry[mcnk->iy][mcnk->ix] = 1;
                    liquid_flags[mcnk->iy][mcnk->ix] |= MAP_LIQUID_TYPE_WATER;            // water
                }
                if (c_flag & (1 << 3))
                {
                    liquid_entry[mcnk->iy][mcnk->ix] = 2;
                    liquid_flags[mcnk->iy][mcnk->ix] |= MAP_LIQUID_TYPE_OCEAN;            // ocean
                }
                if (c_flag & (1 << 4))
                {
                    liquid_entry[mcnk->iy][mcnk->ix] = 3;
                    liquid_flags[mcnk->iy][mcnk->ix] |= MAP_LIQUID_TYPE_MAGMA;            // magma/slime
                }

                if (!count && liquid_flags[mcnk->iy][mcnk->ix])
                    fprintf(stderr, "Wrong liquid detect in MCLQ chunk");

                for (int y = 0; y <= ADT_CELL_SIZE; ++y)
                {
                    int cy = mcnk->iy * ADT_CELL_SIZE + y;
                    for (int x = 0; x <= ADT_CELL_SIZE; ++x)
                    {
                        int cx = mcnk->ix * ADT_CELL_SIZE + x;
                        liquid_height[cy][cx] = liquid->liquid[y][x].height;
                    }
                }
            }
        }

        // Hole data
        if (!(mcnk->flags & 0x10000))
        {
            if (uint16 hole = mcnk->holes)
                if (TransformToHighRes(hole, holes[mcnk->iy][mcnk->ix]))
                    hasHoles = true;
        }
        else
        {
            memcpy(holes[mcnk->iy][mcnk->ix], mcnk->union_5_3_0.HighResHoles, sizeof(uint64));
            if (*((uint64*)holes[mcnk->iy][mcnk->ix]) != 0)
                hasHoles = true;
        }
    }

    // Get liquid map for grid (in WOTLK used MH2O chunk)
    if (FileChunk* chunk = adt.GetChunk("MH2O"))
    {
        adt_MH2O* h2o = chunk->As<adt_MH2O>();
        for (int i = 0; i < ADT_CELLS_PER_GRID; i++)
        {
            for (int j = 0; j < ADT_CELLS_PER_GRID; j++)
            {
                adt_liquid_header *h = h2o->getLiquidData(i, j);
                if (!h)
                    continue;

                int count = 0;
                uint64 show = h2o->getLiquidShowMap(h);
                for (int y = 0; y < h->height; y++)
                {
                    int cy = i * ADT_CELL_SIZE + y + h->yOffset;
                    for (int x = 0; x < h->width; x++)
                    {
                        int cx = j * ADT_CELL_SIZE + x + h->xOffset;
                        if (show & 1)
                        {
                            liquid_show[cy][cx] = true;
                            ++count;
                        }
                        show >>= 1;
                    }
                }

                liquid_entry[i][j] = h->liquidType;
                switch (LiqType[h->liquidType])
                {
                    case LIQUID_TYPE_WATER: liquid_flags[i][j] |= MAP_LIQUID_TYPE_WATER; break;
                    case LIQUID_TYPE_OCEAN: liquid_flags[i][j] |= MAP_LIQUID_TYPE_OCEAN; break;
                    case LIQUID_TYPE_MAGMA: liquid_flags[i][j] |= MAP_LIQUID_TYPE_MAGMA; break;
                    case LIQUID_TYPE_SLIME: liquid_flags[i][j] |= MAP_LIQUID_TYPE_SLIME; break;
                    default:
                        printf("\nCan't find Liquid type %u for map %s\nchunk %d,%d\n", h->liquidType, inputPath.c_str(), i, j);
                        break;
                }
                // Dark water detect
                if (LiqType[h->liquidType] == LIQUID_TYPE_OCEAN)
                {
                    uint8* lm = h2o->getLiquidLightMap(h);
                    if (!lm)
                        liquid_flags[i][j] |= MAP_LIQUID_TYPE_DARK_WATER;
                }

                if (!count && liquid_flags[i][j])
                    printf("Wrong liquid detect in MH2O chunk");

                float* height = h2o->getLiquidHeightMap(h);
                int pos = 0;
                for (int y = 0; y <= h->height; y++)
                {
                    int cy = i * ADT_CELL_SIZE + y + h->yOffset;
                    for (int x = 0; x <= h->width; x++)
                    {
                        int cx = j * ADT_CELL_SIZE + x + h->xOffset;

                        if (height)
                            liquid_height[cy][cx] = height[pos];
                        else
                            liquid_height[cy][cx] = h->heightLevel1;

                        pos++;
                    }
                }
            }
        }
    }

    //============================================
    // Try pack area data
    //============================================
    bool fullAreaData = false;
    uint32 areaflag = area_flags[0][0];
    for (int y=0;y<ADT_CELLS_PER_GRID;y++)
    {
        for(int x=0;x<ADT_CELLS_PER_GRID;x++)
        {
            if(area_flags[y][x]!=areaflag)
            {
                fullAreaData = true;
                break;
            }
        }
    }

    map.areaMapOffset = sizeof(map);
    map.areaMapSize   = sizeof(map_areaHeader);

    map_areaHeader areaHeader;
    areaHeader.fourcc = *reinterpret_cast<uint32 const*>(MAP_AREA_MAGIC);
    areaHeader.flags = 0;
    if (fullAreaData)
    {
        areaHeader.gridArea = 0;
        map.areaMapSize+=sizeof(area_flags);
    }
    else
    {
        areaHeader.flags |= MAP_AREA_NO_AREA;
        areaHeader.gridArea = static_cast<uint16>(areaflag);
    }

    //============================================
    // Try pack height data
    //============================================
    float maxHeight = -20000;
    float minHeight =  20000;
    for (int y=0; y<ADT_GRID_SIZE; y++)
    {
        for(int x=0;x<ADT_GRID_SIZE;x++)
        {
            float h = V8[y][x];
            if (maxHeight < h) maxHeight = h;
            if (minHeight > h) minHeight = h;
        }
    }
    for (int y=0; y<=ADT_GRID_SIZE; y++)
    {
        for(int x=0;x<=ADT_GRID_SIZE;x++)
        {
            float h = V9[y][x];
            if (maxHeight < h) maxHeight = h;
            if (minHeight > h) minHeight = h;
        }
    }

    // Check for allow limit minimum height (not store height in deep ochean - allow save some memory)
    if (CONF_allow_height_limit && minHeight < CONF_use_minHeight)
    {
        for (int y=0; y<ADT_GRID_SIZE; y++)
            for(int x=0;x<ADT_GRID_SIZE;x++)
                if (V8[y][x] < CONF_use_minHeight)
                    V8[y][x] = CONF_use_minHeight;
        for (int y=0; y<=ADT_GRID_SIZE; y++)
            for(int x=0;x<=ADT_GRID_SIZE;x++)
                if (V9[y][x] < CONF_use_minHeight)
                    V9[y][x] = CONF_use_minHeight;
        if (minHeight < CONF_use_minHeight)
            minHeight = CONF_use_minHeight;
        if (maxHeight < CONF_use_minHeight)
            maxHeight = CONF_use_minHeight;
    }

    map.heightMapOffset = map.areaMapOffset + map.areaMapSize;
    map.heightMapSize = sizeof(map_heightHeader);

    map_heightHeader heightHeader;
    heightHeader.fourcc = *reinterpret_cast<uint32 const*>(MAP_HEIGHT_MAGIC);
    heightHeader.flags = 0;
    heightHeader.gridHeight    = minHeight;
    heightHeader.gridMaxHeight = maxHeight;

    if (maxHeight == minHeight)
        heightHeader.flags |= MAP_HEIGHT_NO_HEIGHT;

    // Not need store if flat surface
    if (CONF_allow_float_to_int && (maxHeight - minHeight) < CONF_flat_height_delta_limit)
        heightHeader.flags |= MAP_HEIGHT_NO_HEIGHT;

    // Try store as packed in uint16 or uint8 values
    if (!(heightHeader.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        float step = 0;
        // Try Store as uint values
        if (CONF_allow_float_to_int)
        {
            float diff = maxHeight - minHeight;
            if (diff < CONF_float_to_int8_limit)      // As uint8 (max accuracy = CONF_float_to_int8_limit/256)
            {
                heightHeader.flags|=MAP_HEIGHT_AS_INT8;
                step = selectUInt8StepStore(diff);
            }
            else if (diff<CONF_float_to_int16_limit)  // As uint16 (max accuracy = CONF_float_to_int16_limit/65536)
            {
                heightHeader.flags|=MAP_HEIGHT_AS_INT16;
                step = selectUInt16StepStore(diff);
            }
        }

        // Pack it to int values if need
        if (heightHeader.flags&MAP_HEIGHT_AS_INT8)
        {
            for (int y=0; y<ADT_GRID_SIZE; y++)
                for(int x=0;x<ADT_GRID_SIZE;x++)
                    uint8_V8[y][x] = uint8((V8[y][x] - minHeight) * step + 0.5f);
            for (int y=0; y<=ADT_GRID_SIZE; y++)
                for(int x=0;x<=ADT_GRID_SIZE;x++)
                    uint8_V9[y][x] = uint8((V9[y][x] - minHeight) * step + 0.5f);
            map.heightMapSize+= sizeof(uint8_V9) + sizeof(uint8_V8);
        }
        else if (heightHeader.flags&MAP_HEIGHT_AS_INT16)
        {
            for (int y=0; y<ADT_GRID_SIZE; y++)
                for(int x=0;x<ADT_GRID_SIZE;x++)
                    uint16_V8[y][x] = uint16((V8[y][x] - minHeight) * step + 0.5f);
            for (int y=0; y<=ADT_GRID_SIZE; y++)
                for(int x=0;x<=ADT_GRID_SIZE;x++)
                    uint16_V9[y][x] = uint16((V9[y][x] - minHeight) * step + 0.5f);
            map.heightMapSize+= sizeof(uint16_V9) + sizeof(uint16_V8);
        }
        else
            map.heightMapSize+= sizeof(V9) + sizeof(V8);
    }

    //============================================
    // Pack liquid data
    //============================================
    uint8 type = liquid_flags[0][0];
    bool fullType = false;
    for (int y = 0; y < ADT_CELLS_PER_GRID; y++)
    {
        for (int x = 0; x < ADT_CELLS_PER_GRID; x++)
        {
            if (liquid_flags[y][x] != type)
            {
                fullType = true;
                y = ADT_CELLS_PER_GRID;
                break;
            }
        }
    }

    map_liquidHeader liquidHeader;

    // no water data (if all grid have 0 liquid type)
    if (type == 0 && !fullType)
    {
        // No liquid data
        map.liquidMapOffset = 0;
        map.liquidMapSize   = 0;
    }
    else
    {
        int minX = 255, minY = 255;
        int maxX = 0, maxY = 0;
        maxHeight = -20000;
        minHeight = 20000;
        for (int y=0; y<ADT_GRID_SIZE; y++)
        {
            for(int x=0; x<ADT_GRID_SIZE; x++)
            {
                if (liquid_show[y][x])
                {
                    if (minX > x) minX = x;
                    if (maxX < x) maxX = x;
                    if (minY > y) minY = y;
                    if (maxY < y) maxY = y;
                    float h = liquid_height[y][x];
                    if (maxHeight < h) maxHeight = h;
                    if (minHeight > h) minHeight = h;
                }
                else
                    liquid_height[y][x] = CONF_use_minHeight;
            }
        }
        map.liquidMapOffset = map.heightMapOffset + map.heightMapSize;
        map.liquidMapSize = sizeof(map_liquidHeader);
        liquidHeader.fourcc = *reinterpret_cast<uint32 const*>(MAP_LIQUID_MAGIC);
        liquidHeader.flags = 0;
        liquidHeader.liquidType = 0;
        liquidHeader.offsetX = minX;
        liquidHeader.offsetY = minY;
        liquidHeader.width   = maxX - minX + 1 + 1;
        liquidHeader.height  = maxY - minY + 1 + 1;
        liquidHeader.liquidLevel = minHeight;

        if (maxHeight == minHeight)
            liquidHeader.flags |= MAP_LIQUID_NO_HEIGHT;

        // Not need store if flat surface
        if (CONF_allow_float_to_int && (maxHeight - minHeight) < CONF_flat_liquid_delta_limit)
            liquidHeader.flags |= MAP_LIQUID_NO_HEIGHT;

        if (!fullType)
            liquidHeader.flags |= MAP_LIQUID_NO_TYPE;

        if (liquidHeader.flags & MAP_LIQUID_NO_TYPE)
            liquidHeader.liquidType = type;
        else
            map.liquidMapSize += sizeof(liquid_entry) + sizeof(liquid_flags);

        if (!(liquidHeader.flags & MAP_LIQUID_NO_HEIGHT))
            map.liquidMapSize += sizeof(float)*liquidHeader.width*liquidHeader.height;
    }

    if (map.liquidMapOffset)
        map.holesOffset = map.liquidMapOffset + map.liquidMapSize;
    else
        map.holesOffset = map.heightMapOffset + map.heightMapSize;

    if (hasHoles)
        map.holesSize = sizeof(holes);
    else
        map.holesSize = 0;

    // Ok all data prepared - store it
    std::ofstream outFile(outputPath, std::ofstream::out | std::ofstream::binary);
    if (!outFile)
    {
        printf("Can't create the output file '%s'\n", outputPath.c_str());
        return false;
    }

    outFile.write(reinterpret_cast<const char*>(&map), sizeof(map));
    // Store area data
    outFile.write(reinterpret_cast<const char*>(&areaHeader), sizeof(areaHeader));
    if (!(areaHeader.flags&MAP_AREA_NO_AREA))
        outFile.write(reinterpret_cast<const char*>(area_flags), sizeof(area_flags));

    // Store height data
    outFile.write(reinterpret_cast<const char*>(&heightHeader), sizeof(heightHeader));
    if (!(heightHeader.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        if (heightHeader.flags & MAP_HEIGHT_AS_INT16)
        {
            outFile.write(reinterpret_cast<const char*>(uint16_V9), sizeof(uint16_V9));
            outFile.write(reinterpret_cast<const char*>(uint16_V8), sizeof(uint16_V8));
        }
        else if (heightHeader.flags & MAP_HEIGHT_AS_INT8)
        {
            outFile.write(reinterpret_cast<const char*>(uint8_V9), sizeof(uint8_V9));
            outFile.write(reinterpret_cast<const char*>(uint8_V8), sizeof(uint8_V8));
        }
        else
        {
            outFile.write(reinterpret_cast<const char*>(V9), sizeof(V9));
            outFile.write(reinterpret_cast<const char*>(V8), sizeof(V8));
        }
    }

    // Store liquid data if need
    if (map.liquidMapOffset)
    {
        outFile.write(reinterpret_cast<const char*>(&liquidHeader), sizeof(liquidHeader));
        if (!(liquidHeader.flags & MAP_LIQUID_NO_TYPE))
        {
            outFile.write(reinterpret_cast<const char*>(liquid_entry), sizeof(liquid_entry));
            outFile.write(reinterpret_cast<const char*>(liquid_flags), sizeof(liquid_flags));
        }

        if (!(liquidHeader.flags & MAP_LIQUID_NO_HEIGHT))
        {
            for (int y = 0; y < liquidHeader.height; y++)
                outFile.write(reinterpret_cast<const char*>(&liquid_height[y + liquidHeader.offsetY][liquidHeader.offsetX]), sizeof(float) * liquidHeader.width);
        }
    }

    // store hole data
    if (hasHoles)
        outFile.write(reinterpret_cast<const char*>(holes), map.holesSize);

    outFile.close();

    return true;
}

void ExtractWmos(ChunkedFile& file, std::set<std::string>& wmoList)
{
    if (FileChunk* chunk = file.GetChunk("MWMO"))
    {
        file_MWMO* wmo = chunk->As<file_MWMO>();
        if (wmo->size)
        {
            char* fileName = wmo->FileList;
            while (fileName < wmo->FileList + wmo->size)
            {
                wmoList.insert(fileName);
                fileName += strlen(fileName) + 1;
            }
        }
    }
}

void ExtractMaps(uint32 build)
{
    std::string storagePath;
    std::string outputFileName;

    printf("Extracting maps...\n");

    uint32 map_count = ReadMapDBC();

    ReadAreaTableDBC();
    ReadLiquidTypeTableDBC();

    std::string path = output_path;
    path += "/maps/";
    CreateDir(path);

    std::set<std::string> wmoList;

    printf("Convert map files\n");
    for (uint32 z = 0; z < map_count; ++z)
    {
        printf("Extract %s (%d/%u)                  \n", map_ids[z].name, z+1, map_count);
        // Loadup map grid data
        storagePath = Trinity::StringFormat("World\\Maps\\%s\\%s.wdt", map_ids[z].name, map_ids[z].name);
        ChunkedFile wdt;
        if (!wdt.loadFile(CascStorage, storagePath, false))
            continue;

        ExtractWmos(wdt, wmoList);

        FileChunk* chunk = wdt.GetChunk("MAIN");
        for (uint32 y = 0; y < WDT_MAP_SIZE; ++y)
        {
            for (uint32 x = 0; x < WDT_MAP_SIZE; ++x)
            {
                if (!(chunk->As<wdt_MAIN>()->adt_list[y][x].flag & 0x1))
                    continue;

                storagePath = Trinity::StringFormat("World\\Maps\\%s\\%s_%u_%u.adt", map_ids[z].name, map_ids[z].name, x, y);
                outputFileName =  Trinity::StringFormat("%s/maps/%04u_%02u_%02u.map", output_path, map_ids[z].id, y, x);
                ConvertADT(storagePath, outputFileName, y, x, build);

                storagePath = Trinity::StringFormat("World\\Maps\\%s\\%s_%u_%u_obj0.adt", map_ids[z].name, map_ids[z].name, x, y);
                ChunkedFile adtObj;
                if (adtObj.loadFile(CascStorage, storagePath, false))
                    ExtractWmos(adtObj, wmoList);
            }

            // draw progress bar
            printf("Processing........................%d%%\r", (100 * (y+1)) / WDT_MAP_SIZE);
        }
    }

    if (!wmoList.empty())
    {
        if (FILE* wmoListFile = fopen("wmo_list.txt", "w"))
        {
            for (std::string const& wmo : wmoList)
                fprintf(wmoListFile, "%s\n", wmo.c_str());

            fclose(wmoListFile);
        }
    }

    printf("\n");
    delete[] areas;
    delete[] map_ids;
}

bool ExtractFile(HANDLE fileInArchive, std::string filename)
{
    FILE* output = fopen(filename.c_str(), "wb");
    if (!output)
    {
        printf("Can't create the output file '%s'\n", filename.c_str());
        return false;
    }

    char  buffer[0x10000];
    DWORD readBytes = 1;

    while (readBytes > 0)
    {
        CascReadFile(fileInArchive, buffer, sizeof(buffer), &readBytes);
        if (readBytes > 0)
            fwrite(buffer, 1, readBytes, output);
    }

    fclose(output);
    return true;
}

void ExtractDBFilesClient(int l)
{
    printf("Extracting dbc/db2 files...\n");

    std::string outputPath = output_path;
    outputPath += "/dbc/";

    CreateDir(outputPath);
    outputPath += localeNames[l];
    outputPath += "/";
    CreateDir(outputPath);

    printf("locale %s output path %s\n", localeNames[l], outputPath.c_str());

    uint32 index = 0;
    uint32 count = 0;
    char const* fileName = DBFilesClientList[index];
    HANDLE dbcFile;
    while (fileName)
    {
        std::string filename = fileName;
        if (CascOpenFile(CascStorage, (filename = (filename + ".db2")).c_str(), WowLocaleToCascLocaleFlags[l], 0, &dbcFile) ||
            CascOpenFile(CascStorage, (filename = (filename.substr(0, filename.length() - 4) + ".dbc")).c_str(), WowLocaleToCascLocaleFlags[l], 0, &dbcFile))
        {
            filename = outputPath + filename.substr(filename.rfind('\\') + 1);

            if (!boost::filesystem::exists(filename))
                if (ExtractFile(dbcFile, filename))
                    ++count;

            CascCloseFile(dbcFile);
        }
        else
            printf("Unable to open file %s in the archive for locale %s: %s\n", fileName, localeNames[l], HumanReadableCASCError(GetLastError()));

        fileName = DBFilesClientList[++index];
    }

    printf("Extracted %u files\n\n", count);
}

bool OpenCascStorage(int locale)
{
    try
    {
        boost::filesystem::path const storage_dir(boost::filesystem::canonical(input_path) / "Data");
        if (!CascOpenStorage(storage_dir.string().c_str(), WowLocaleToCascLocaleFlags[locale], &CascStorage))
        {
            printf("error opening casc storage '%s' locale %s: %s\n", storage_dir.string().c_str(), localeNames[locale], HumanReadableCASCError(GetLastError()));
            return false;
        }
        printf("opened casc storage '%s' locale %s\n", storage_dir.string().c_str(), localeNames[locale]);
        return true;
    }
    catch (boost::filesystem::filesystem_error& error)
    {
        printf("error opening casc storage : %s\n", error.what());
        return false;
    }
}

int main(int argc, char * arg[])
{
    printf("Map & DBC Extractor\n");
    printf("===================\n");

    boost::filesystem::path current(boost::filesystem::current_path());
    strcpy(input_path, current.string().c_str());
    strcpy(output_path, current.string().c_str());

    HandleArgs(argc, arg);

    int FirstLocale = -1;
    uint32 build = 0;

    for (int i = 0; i < TOTAL_LOCALES; ++i)
    {
        if (CONF_Locale && !(CONF_Locale & (1 << i)))
            continue;

        if (i == LOCALE_none)
            continue;

        if (!OpenCascStorage(i))
            continue;

        if ((CONF_extract & EXTRACT_DBC) == 0)
        {
            FirstLocale = i;
            build = ReadBuild(i);
            if (!build)
            {
                CascCloseStorage(CascStorage);
                continue;
            }

            printf("Detected client build: %u\n\n", build);
            break;
        }

        //Extract DBC files
        uint32 tempBuild = ReadBuild(i);
        if (!tempBuild)
        {
            CascCloseStorage(CascStorage);
            continue;
        }

        printf("Detected client build %u for locale %s\n\n", tempBuild, localeNames[i]);
        ExtractDBFilesClient(i);
        CascCloseStorage(CascStorage);

        if (FirstLocale < 0)
        {
            FirstLocale = i;
            build = tempBuild;
        }
    }

    if (FirstLocale < 0)
    {
        printf("No locales detected\n");
        return 0;
    }

    if (CONF_extract & EXTRACT_MAP)
    {
        OpenCascStorage(FirstLocale);
        ExtractMaps(build);
        CascCloseStorage(CascStorage);
    }

    return 0;
}
