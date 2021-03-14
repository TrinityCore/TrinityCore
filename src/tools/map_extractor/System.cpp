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
#include "CascHandles.h"
#include "Common.h"
#include "DB2CascFileSource.h"
#include "DB2Meta.h"
#include "DBFilesClientList.h"
#include "ExtractorDB2LoadInfo.h"
#include "StringFormat.h"
#include "adt.h"
#include "wdt.h"
#include <CascLib.h>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <bitset>
#include <cstdio>
#include <deque>
#include <fstream>
#include <set>
#include <unordered_map>
#include <cstdlib>
#include <cstring>
#if TRINITY_PLATFORM == TRINITY_PLATFORM_WINDOWS
#include <io.h>
#else
#include <unistd.h>
#endif

std::shared_ptr<CASC::Storage> CascStorage;

struct MapEntry
{
    uint32 Id = 0;
    int32 WdtFileDataId = 0;
    std::string Name;
    std::string Directory;
};

struct LiquidMaterialEntry
{
    int8 LVF = 0;
};

struct LiquidObjectEntry
{
    int16 LiquidTypeID = 0;
};

struct LiquidTypeEntry
{
    uint8 SoundBank = 0;
    uint8 MaterialID = 0;
};

std::vector<MapEntry> map_ids;
std::unordered_map<uint32, LiquidMaterialEntry> LiquidMaterials;
std::unordered_map<uint32, LiquidObjectEntry> LiquidObjects;
std::unordered_map<uint32, LiquidTypeEntry> LiquidTypes;
std::set<uint32> CameraFileDataIds;
bool PrintProgress = true;
boost::filesystem::path input_path;
boost::filesystem::path output_path;

// **************************************************
// Extractor options
// **************************************************
enum Extract : uint8
{
    EXTRACT_MAP     = 0x1,
    EXTRACT_DBC     = 0x2,
    EXTRACT_CAMERA  = 0x4,
    EXTRACT_GT      = 0x8,

    EXTRACT_ALL = EXTRACT_MAP | EXTRACT_DBC | EXTRACT_CAMERA | EXTRACT_GT
};

// Select data for extract
int   CONF_extract = EXTRACT_ALL;

// This option allow limit minimum height to some value (Allow save some memory)
bool  CONF_allow_height_limit = true;
float CONF_use_minHeight = -2000.0f;

// This option allow use float to int conversion
bool  CONF_allow_float_to_int   = true;
float CONF_float_to_int8_limit  = 2.0f;      // Max accuracy = val/256
float CONF_float_to_int16_limit = 2048.0f;   // Max accuracy = val/65536
float CONF_flat_height_delta_limit = 0.005f; // If max - min less this value - surface is flat
float CONF_flat_liquid_delta_limit = 0.001f; // If max - min less this value - liquid surface is flat

uint32 CONF_Locale = 0;

char const* CONF_Product = "wow";

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
        "-i set input path\n"\
        "-o set output path\n"\
        "-e extract only MAP(1)/DBC(2)/Camera(4)/gt(8) - standard: all(15)\n"\
        "-f height stored as int (less map size but lost some accuracy) 1 by default\n"\
        "-l dbc locale\n"\
        "-p which installed product to open (wow/wowt/wow_beta)\n"\
        "Example: %s -f 0 -i \"c:\\games\\game\"\n", prg, prg);
    exit(1);
}

void HandleArgs(int argc, char* arg[])
{
    for (int c = 1; c < argc; ++c)
    {
        // i - input path
        // o - output path
        // e - extract only MAP(1)/DBC(2)/Camera(4)/gt(8) - standard: all(11)
        // f - use float to int conversion
        // h - limit minimum height
        // l - dbc locale
        if (arg[c][0] != '-')
            Usage(arg[0]);

        switch (arg[c][1])
        {
            case 'i':
                if (c + 1 < argc && strlen(arg[c + 1])) // all ok
                    input_path = boost::filesystem::path(arg[c++ + 1]);
                else
                    Usage(arg[0]);
                break;
            case 'o':
                if (c + 1 < argc && strlen(arg[c + 1])) // all ok
                    output_path = boost::filesystem::path(arg[c++ + 1]);
                else
                    Usage(arg[0]);
                break;
            case 'f':
                if (c + 1 < argc)                            // all ok
                    CONF_allow_float_to_int = atoi(arg[c++ + 1]) != 0;
                else
                    Usage(arg[0]);
                break;
            case 'e':
                if (c + 1 < argc)                            // all ok
                {
                    CONF_extract = atoi(arg[c++ + 1]);
                    if (!(CONF_extract > 0 && CONF_extract <= EXTRACT_ALL))
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
            case 'p':
                if (c + 1 < argc && strlen(arg[c + 1]))      // all ok
                    CONF_Product = arg[++c];
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

void TryLoadDB2(char const* name, DB2CascFileSource* source, DB2FileLoader* db2, DB2FileLoadInfo const* loadInfo)
{
    try
    {
        db2->Load(source, loadInfo);
    }
    catch (std::exception const& e)
    {
        printf("Fatal error: Invalid %s file format! %s\n%s\n", name, CASC::HumanReadableCASCError(GetCascError()), e.what());
        exit(1);
    }
}

void ReadMapDBC()
{
    printf("Read Map.db2 file...\n");

    DB2CascFileSource source(CascStorage, MapLoadInfo::Instance()->Meta->FileDataId);
    DB2FileLoader db2;
    TryLoadDB2("Map.db2", &source, &db2, MapLoadInfo::Instance());

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
        map.Name = record.GetString("MapName");
        map.Directory = record.GetString("Directory");
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
            map.Name = map_ids[itr->second].Name;
            map.Directory = map_ids[itr->second].Directory;
            map_ids.push_back(map);
        }
    }

    map_ids.erase(std::remove_if(map_ids.begin(), map_ids.end(), [](MapEntry const& map) { return !map.WdtFileDataId; }), map_ids.end());

    printf("Done! (" SZFMTD " maps loaded)\n", map_ids.size());
}

void ReadLiquidMaterialTable()
{
    printf("Read LiquidMaterial.db2 file...\n");

    DB2CascFileSource source(CascStorage, LiquidMaterialLoadInfo::Instance()->Meta->FileDataId);
    DB2FileLoader db2;
    TryLoadDB2("LiquidMaterial.db2", &source, &db2, LiquidMaterialLoadInfo::Instance());

    for (uint32 x = 0; x < db2.GetRecordCount(); ++x)
    {
        DB2Record record = db2.GetRecord(x);
        if (!record)
            continue;

        LiquidMaterialEntry& liquidType = LiquidMaterials[record.GetId()];
        liquidType.LVF = record.GetUInt8("LVF");
    }

    for (uint32 x = 0; x < db2.GetRecordCopyCount(); ++x)
        LiquidMaterials[db2.GetRecordCopy(x).NewRowId] = LiquidMaterials[db2.GetRecordCopy(x).SourceRowId];

    printf("Done! (" SZFMTD " LiquidMaterials loaded)\n", LiquidMaterials.size());
}

void ReadLiquidObjectTable()
{
    printf("Read LiquidObject.db2 file...\n");

    DB2CascFileSource source(CascStorage, LiquidObjectLoadInfo::Instance()->Meta->FileDataId);
    DB2FileLoader db2;
    TryLoadDB2("LiquidObject.db2", &source, &db2, LiquidObjectLoadInfo::Instance());

    for (uint32 x = 0; x < db2.GetRecordCount(); ++x)
    {
        DB2Record record = db2.GetRecord(x);
        if (!record)
            continue;

        LiquidObjectEntry& liquidType = LiquidObjects[record.GetId()];
        liquidType.LiquidTypeID = record.GetUInt16("LiquidTypeID");
    }

    for (uint32 x = 0; x < db2.GetRecordCopyCount(); ++x)
        LiquidObjects[db2.GetRecordCopy(x).NewRowId] = LiquidObjects[db2.GetRecordCopy(x).SourceRowId];

    printf("Done! (" SZFMTD " LiquidObjects loaded)\n", LiquidObjects.size());
}

void ReadLiquidTypeTable()
{
    printf("Read LiquidType.db2 file...\n");

    DB2CascFileSource source(CascStorage, LiquidTypeLoadInfo::Instance()->Meta->FileDataId);
    DB2FileLoader db2;
    TryLoadDB2("LiquidType.db2", &source, &db2, LiquidTypeLoadInfo::Instance());

    for (uint32 x = 0; x < db2.GetRecordCount(); ++x)
    {
        DB2Record record = db2.GetRecord(x);
        if (!record)
            continue;

        LiquidTypeEntry& liquidType = LiquidTypes[record.GetId()];
        liquidType.SoundBank = record.GetUInt8("SoundBank");
        liquidType.MaterialID = record.GetUInt8("MaterialID");
    }

    for (uint32 x = 0; x < db2.GetRecordCopyCount(); ++x)
        LiquidTypes[db2.GetRecordCopy(x).NewRowId] = LiquidTypes[db2.GetRecordCopy(x).SourceRowId];

    printf("Done! (" SZFMTD " LiquidTypes loaded)\n", LiquidTypes.size());
}

bool ReadCinematicCameraDBC()
{
    printf("Read CinematicCamera.db2 file...\n");

    DB2CascFileSource source(CascStorage, CinematicCameraLoadInfo::Instance()->Meta->FileDataId);
    DB2FileLoader db2;
    TryLoadDB2("CinematicCamera.db2", &source, &db2, CinematicCameraLoadInfo::Instance());

    // get camera file list from DB2
    for (size_t i = 0; i < db2.GetRecordCount(); ++i)
    {
        DB2Record record = db2.GetRecord(i);
        if (!record)
            continue;

        CameraFileDataIds.insert(record.GetUInt32("FileDataID"));
    }

    printf("Done! (" SZFMTD " CinematicCameras loaded)\n", CameraFileDataIds.size());
    return true;
}

//
// Adt file convertor function and data
//

// Map file format data
static char const* MAP_MAGIC         = "MAPS";
static char const* MAP_VERSION_MAGIC = "v1.9";
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

#define MAP_HEIGHT_NO_HEIGHT            0x0001
#define MAP_HEIGHT_AS_INT16             0x0002
#define MAP_HEIGHT_AS_INT8              0x0004
#define MAP_HEIGHT_HAS_FLIGHT_BOUNDS    0x0008

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

#define MAP_LIQUID_NO_TYPE    0x0001
#define MAP_LIQUID_NO_HEIGHT  0x0002

struct map_liquidHeader
{
    uint32 fourcc;
    uint8 flags;
    uint8 liquidFlags;
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
uint16 area_ids[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];

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

int16 flight_box_max[3][3];
int16 flight_box_min[3][3];

LiquidVertexFormatType adt_MH2O::GetLiquidVertexFormat(adt_liquid_instance const* liquidInstance) const
{
    if (liquidInstance->LiquidVertexFormat < 42)
        return static_cast<LiquidVertexFormatType>(liquidInstance->LiquidVertexFormat);

    if (liquidInstance->LiquidType == 2)
        return LiquidVertexFormatType::Depth;

    auto liquidType = LiquidTypes.find(liquidInstance->LiquidType);
    if (liquidType != LiquidTypes.end())
    {
        auto liquidMaterial = LiquidMaterials.find(liquidType->second.MaterialID);
        if (liquidMaterial != LiquidMaterials.end())
            return static_cast<LiquidVertexFormatType>(liquidMaterial->second.LVF);
    }

    return static_cast<LiquidVertexFormatType>(-1);
}

bool TransformToHighRes(uint16 lowResHoles, uint8 hiResHoles[8])
{
    for (uint8 i = 0; i < 8; i++)
    {
        for (uint8 j = 0; j < 8; j++)
        {
            int32 holeIdxL = (i / 2) * 4 + (j / 2);
            if (((lowResHoles >> holeIdxL) & 1) == 1)
                hiResHoles[i] |= (1 << j);
        }
    }

    return *((uint64*)hiResHoles) != 0;
}

bool ConvertADT(ChunkedFile& adt, std::string const& mapName, std::string const& outputPath, int gx, int gy, uint32 build, bool ignoreDeepWater)
{
    // Prepare map header
    map_fileheader map;
    map.mapMagic = *reinterpret_cast<uint32 const*>(MAP_MAGIC);
    map.versionMagic = *reinterpret_cast<uint32 const*>(MAP_VERSION_MAGIC);
    map.buildMagic = build;

    // Get area flags data
    memset(area_ids, 0, sizeof(area_ids));
    memset(V9, 0, sizeof(V9));
    memset(V8, 0, sizeof(V8));

    memset(liquid_show, 0, sizeof(liquid_show));
    memset(liquid_flags, 0, sizeof(liquid_flags));
    memset(liquid_entry, 0, sizeof(liquid_entry));

    memset(holes, 0, sizeof(holes));

    bool hasHoles = false;
    bool hasFlightBox = false;

    for (std::multimap<std::string, FileChunk*>::const_iterator itr = adt.chunks.lower_bound("MCNK"); itr != adt.chunks.upper_bound("MCNK"); ++itr)
    {
        adt_MCNK* mcnk = itr->second->As<adt_MCNK>();

        // Area data
        area_ids[mcnk->iy][mcnk->ix] = mcnk->areaid;

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
                            if (!ignoreDeepWater && liquid->flags[y][x] & (1 << 7))
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
        for (int32 i = 0; i < ADT_CELLS_PER_GRID; i++)
        {
            for (int32 j = 0; j < ADT_CELLS_PER_GRID; j++)
            {
                adt_liquid_instance const* h = h2o->GetLiquidInstance(i, j);
                if (!h)
                    continue;

                adt_liquid_attributes attrs = h2o->GetLiquidAttributes(i, j);

                int32 count = 0;
                uint64 existsMask = h2o->GetLiquidExistsBitmap(h);
                for (int32 y = 0; y < h->GetHeight(); y++)
                {
                    int32 cy = i * ADT_CELL_SIZE + y + h->GetOffsetY();
                    for (int32 x = 0; x < h->GetWidth(); x++)
                    {
                        int32 cx = j * ADT_CELL_SIZE + x + h->GetOffsetX();
                        if (existsMask & 1)
                        {
                            liquid_show[cy][cx] = true;
                            ++count;
                        }
                        existsMask >>= 1;
                    }
                }

                liquid_entry[i][j] = h2o->GetLiquidType(h);
                switch (LiquidTypes.at(liquid_entry[i][j]).SoundBank)
                {
                    case LIQUID_TYPE_WATER: liquid_flags[i][j] |= MAP_LIQUID_TYPE_WATER; break;
                    case LIQUID_TYPE_OCEAN: liquid_flags[i][j] |= MAP_LIQUID_TYPE_OCEAN; if (!ignoreDeepWater && attrs.Deep) liquid_flags[i][j] |= MAP_LIQUID_TYPE_DARK_WATER; break;
                    case LIQUID_TYPE_MAGMA: liquid_flags[i][j] |= MAP_LIQUID_TYPE_MAGMA; break;
                    case LIQUID_TYPE_SLIME: liquid_flags[i][j] |= MAP_LIQUID_TYPE_SLIME; break;
                    default:
                        printf("\nCan't find Liquid type %u for map %s [%u,%u]\nchunk %d,%d\n", h->LiquidType, mapName.c_str(), gx, gy, i, j);
                        break;
                }

                if (!count && liquid_flags[i][j])
                    printf("Wrong liquid detect in MH2O chunk");

                int32 pos = 0;
                for (int32 y = 0; y <= h->GetHeight(); y++)
                {
                    int32 cy = i * ADT_CELL_SIZE + y + h->GetOffsetY();
                    for (int32 x = 0; x <= h->GetWidth(); x++)
                    {
                        int32 cx = j * ADT_CELL_SIZE + x + h->GetOffsetX();
                        liquid_height[cy][cx] = h2o->GetLiquidHeight(h, pos);
                        pos++;
                    }
                }
            }
        }
    }

    if (FileChunk* chunk = adt.GetChunk("MFBO"))
    {
        adt_MFBO* mfbo = chunk->As<adt_MFBO>();
        memcpy(flight_box_max, &mfbo->max, sizeof(flight_box_max));
        memcpy(flight_box_min, &mfbo->min, sizeof(flight_box_min));
        hasFlightBox = true;
    }

    //============================================
    // Try pack area data
    //============================================
    bool fullAreaData = false;
    uint32 areaId = area_ids[0][0];
    for (int y = 0; y < ADT_CELLS_PER_GRID; ++y)
    {
        for (int x = 0; x < ADT_CELLS_PER_GRID; ++x)
        {
            if (area_ids[y][x] != areaId)
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
        map.areaMapSize += sizeof(area_ids);
    }
    else
    {
        areaHeader.flags |= MAP_AREA_NO_AREA;
        areaHeader.gridArea = static_cast<uint16>(areaId);
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

    if (hasFlightBox)
    {
        heightHeader.flags |= MAP_HEIGHT_HAS_FLIGHT_BOUNDS;
        map.heightMapSize += sizeof(flight_box_max) + sizeof(flight_box_min);
    }

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
                heightHeader.flags |= MAP_HEIGHT_AS_INT8;
                step = selectUInt8StepStore(diff);
            }
            else if (diff < CONF_float_to_int16_limit)  // As uint16 (max accuracy = CONF_float_to_int16_limit/65536)
            {
                heightHeader.flags |= MAP_HEIGHT_AS_INT16;
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
    uint16 firstLiquidType = liquid_entry[0][0];
    uint8 firstLiquidFlag = liquid_flags[0][0];
    bool fullType = false;
    for (int y = 0; y < ADT_CELLS_PER_GRID; y++)
    {
        for (int x = 0; x < ADT_CELLS_PER_GRID; x++)
        {
            if (liquid_entry[y][x] != firstLiquidType || liquid_flags[y][x] != firstLiquidFlag)
            {
                fullType = true;
                y = ADT_CELLS_PER_GRID;
                break;
            }
        }
    }

    map_liquidHeader liquidHeader;

    // no water data (if all grid have 0 liquid type)
    if (firstLiquidFlag == 0 && !fullType)
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
        {
            liquidHeader.liquidFlags = firstLiquidFlag;
            liquidHeader.liquidType = firstLiquidType;
        }
        else
            map.liquidMapSize += sizeof(liquid_entry) + sizeof(liquid_flags);

        if (!(liquidHeader.flags & MAP_LIQUID_NO_HEIGHT))
            map.liquidMapSize += sizeof(float)*liquidHeader.width*liquidHeader.height;
    }

    if (hasHoles)
    {
        if (map.liquidMapOffset)
            map.holesOffset = map.liquidMapOffset + map.liquidMapSize;
        else
            map.holesOffset = map.heightMapOffset + map.heightMapSize;

        map.holesSize = sizeof(holes);
    }
    else
    {
        map.holesOffset = 0;
        map.holesSize = 0;
    }

    // Ok all data prepared - store it
    std::ofstream outFile(outputPath, std::ofstream::out | std::ofstream::binary);
    if (!outFile)
    {
        printf("Can't create the output file '%s'\n", outputPath.c_str());
        return false;
    }

    outFile.write(reinterpret_cast<char const*>(&map), sizeof(map));
    // Store area data
    outFile.write(reinterpret_cast<char const*>(&areaHeader), sizeof(areaHeader));
    if (!(areaHeader.flags & MAP_AREA_NO_AREA))
        outFile.write(reinterpret_cast<char const*>(area_ids), sizeof(area_ids));

    // Store height data
    outFile.write(reinterpret_cast<char const*>(&heightHeader), sizeof(heightHeader));
    if (!(heightHeader.flags & MAP_HEIGHT_NO_HEIGHT))
    {
        if (heightHeader.flags & MAP_HEIGHT_AS_INT16)
        {
            outFile.write(reinterpret_cast<char const*>(uint16_V9), sizeof(uint16_V9));
            outFile.write(reinterpret_cast<char const*>(uint16_V8), sizeof(uint16_V8));
        }
        else if (heightHeader.flags & MAP_HEIGHT_AS_INT8)
        {
            outFile.write(reinterpret_cast<char const*>(uint8_V9), sizeof(uint8_V9));
            outFile.write(reinterpret_cast<char const*>(uint8_V8), sizeof(uint8_V8));
        }
        else
        {
            outFile.write(reinterpret_cast<char const*>(V9), sizeof(V9));
            outFile.write(reinterpret_cast<char const*>(V8), sizeof(V8));
        }
    }

    if (heightHeader.flags & MAP_HEIGHT_HAS_FLIGHT_BOUNDS)
    {
        outFile.write(reinterpret_cast<char*>(flight_box_max), sizeof(flight_box_max));
        outFile.write(reinterpret_cast<char*>(flight_box_min), sizeof(flight_box_min));
    }

    // Store liquid data if need
    if (map.liquidMapOffset)
    {
        outFile.write(reinterpret_cast<char const*>(&liquidHeader), sizeof(liquidHeader));
        if (!(liquidHeader.flags & MAP_LIQUID_NO_TYPE))
        {
            outFile.write(reinterpret_cast<char const*>(liquid_entry), sizeof(liquid_entry));
            outFile.write(reinterpret_cast<char const*>(liquid_flags), sizeof(liquid_flags));
        }

        if (!(liquidHeader.flags & MAP_LIQUID_NO_HEIGHT))
        {
            for (int y = 0; y < liquidHeader.height; y++)
                outFile.write(reinterpret_cast<char const*>(&liquid_height[y + liquidHeader.offsetY][liquidHeader.offsetX]), sizeof(float) * liquidHeader.width);
        }
    }

    // store hole data
    if (hasHoles)
        outFile.write(reinterpret_cast<char const*>(holes), map.holesSize);

    outFile.close();

    return true;
}

bool ConvertADT(std::string const& fileName, std::string const& mapName, std::string const& outputPath, int gx, int gy, uint32 build, bool ignoreDeepWater)
{
    ChunkedFile adt;

    if (!adt.loadFile(CascStorage, fileName))
        return false;

    return ConvertADT(adt, mapName, outputPath, gx, gy, build, ignoreDeepWater);
}

bool ConvertADT(uint32 fileDataId, std::string const& mapName, std::string const& outputPath, int gx, int gy, uint32 build, bool ignoreDeepWater)
{
    ChunkedFile adt;

    if (!adt.loadFile(CascStorage, fileDataId, Trinity::StringFormat("Map %s grid [%u,%u]", mapName.c_str(), gx, gy)))
        return false;

    return ConvertADT(adt, mapName, outputPath, gx, gy, build, ignoreDeepWater);
}

bool IsDeepWaterIgnored(uint32 mapId, uint32 x, uint32 y)
{
    if (mapId == 0)
    {
        //                                                                                                GRID(39, 24) || GRID(39, 25) || GRID(39, 26) ||
        //                                                                                                GRID(40, 24) || GRID(40, 25) || GRID(40, 26) ||
        //GRID(41, 18) || GRID(41, 19) || GRID(41, 20) || GRID(41, 21) || GRID(41, 22) || GRID(41, 23) || GRID(41, 24) || GRID(41, 25) || GRID(41, 26) ||
        //GRID(42, 18) || GRID(42, 19) || GRID(42, 20) || GRID(42, 21) || GRID(42, 22) || GRID(42, 23) || GRID(42, 24) || GRID(42, 25) || GRID(42, 26) ||
        //GRID(43, 18) || GRID(43, 19) || GRID(43, 20) || GRID(43, 21) || GRID(43, 22) || GRID(43, 23) || GRID(43, 24) || GRID(43, 25) || GRID(43, 26) ||
        //GRID(44, 18) || GRID(44, 19) || GRID(44, 20) || GRID(44, 21) || GRID(44, 22) || GRID(44, 23) || GRID(44, 24) || GRID(44, 25) || GRID(44, 26) ||
        //GRID(45, 18) || GRID(45, 19) || GRID(45, 20) || GRID(45, 21) || GRID(45, 22) || GRID(45, 23) || GRID(45, 24) || GRID(45, 25) || GRID(45, 26) ||
        //GRID(46, 18) || GRID(46, 19) || GRID(46, 20) || GRID(46, 21) || GRID(46, 22) || GRID(46, 23) || GRID(46, 24) || GRID(46, 25) || GRID(46, 26)

        // Vashj'ir grids completely ignore fatigue
        return (x >= 39 && x <= 40 && y >= 24 && y <= 26) || (x >= 41 && x <= 46 && y >= 18 && y <= 26);
    }

    if (mapId == 1)
    {
        // GRID(43, 39) || GRID(43, 40)
        // Thousand Needles
        return x == 43 && (y == 39 || y == 40);
    }

    return false;
}

void ExtractMaps(uint32 build)
{
    std::string outputFileName;

    printf("Extracting maps...\n");

    ReadMapDBC();

    ReadLiquidMaterialTable();
    ReadLiquidObjectTable();
    ReadLiquidTypeTable();

    CreateDir(output_path / "maps");

    printf("Convert map files\n");
    for (std::size_t z = 0; z < map_ids.size(); ++z)
    {
        printf("Extract %s (" SZFMTD "/" SZFMTD ")                  \n", map_ids[z].Name.c_str(), z + 1, map_ids.size());
        // Loadup map grid data
        ChunkedFile wdt;
        std::bitset<(WDT_MAP_SIZE) * (WDT_MAP_SIZE)> existingTiles;
        if (wdt.loadFile(CascStorage, map_ids[z].WdtFileDataId, Trinity::StringFormat("WDT for map %u", map_ids[z].Id), false))
        {
            FileChunk* mphd = wdt.GetChunk("MPHD");
            FileChunk* main = wdt.GetChunk("MAIN");
            FileChunk* maid = wdt.GetChunk("MAID");
            for (uint32 y = 0; y < WDT_MAP_SIZE; ++y)
            {
                for (uint32 x = 0; x < WDT_MAP_SIZE; ++x)
                {
                    if (!(main->As<wdt_MAIN>()->adt_list[y][x].flag & 0x1))
                        continue;

                    outputFileName = Trinity::StringFormat("%s/maps/%04u_%02u_%02u.map", output_path.string().c_str(), map_ids[z].Id, y, x);
                    bool ignoreDeepWater = IsDeepWaterIgnored(map_ids[z].Id, y, x);
                    if (mphd && mphd->As<wdt_MPHD>()->flags & 0x200)
                    {
                        existingTiles[y * WDT_MAP_SIZE + x] = ConvertADT(maid->As<wdt_MAID>()->adt_files[y][x].rootADT, map_ids[z].Name, outputFileName, y, x, build, ignoreDeepWater);
                    }
                    else
                    {
                        std::string storagePath = Trinity::StringFormat(R"(World\Maps\%s\%s_%u_%u.adt)", map_ids[z].Directory.c_str(), map_ids[z].Directory.c_str(), x, y);
                        existingTiles[y * WDT_MAP_SIZE + x] = ConvertADT(storagePath, map_ids[z].Name, outputFileName, y, x, build, ignoreDeepWater);
                    }
                }

                // draw progress bar
                if (PrintProgress)
                    printf("Processing........................%d%%\r", (100 * (y + 1)) / WDT_MAP_SIZE);
            }
        }

        if (FILE* tileList = fopen(Trinity::StringFormat("%s/maps/%04u.tilelist", output_path.string().c_str(), map_ids[z].Id).c_str(), "wb"))
        {
            fwrite(MAP_MAGIC, 1, strlen(MAP_MAGIC), tileList);
            fwrite(MAP_VERSION_MAGIC, 1, strlen(MAP_VERSION_MAGIC), tileList);
            fwrite(&build, sizeof(build), 1, tileList);
            fwrite(existingTiles.to_string().c_str(), 1, existingTiles.size(), tileList);
            fclose(tileList);
        }
    }

    printf("\n");
}

bool ExtractFile(CASC::File* fileInArchive, std::string const& filename)
{
    int64 fileSize = fileInArchive->GetSize();
    if (fileSize == -1)
    {
        printf("Can't read file size of '%s'\n", filename.c_str());
        return false;
    }

    FILE* output = fopen(filename.c_str(), "wb");
    if (!output)
    {
        printf("Can't create the output file '%s'\n", filename.c_str());
        return false;
    }

    char  buffer[0x10000];
    uint32 readBytes;

    do
    {
        readBytes = 0;
        if (!fileInArchive->ReadFile(buffer, std::min<uint32>(fileSize, sizeof(buffer)), &readBytes))
        {
            printf("Can't read file '%s'\n", filename.c_str());
            fclose(output);
            boost::filesystem::remove(filename);
            return false;
        }

        if (!readBytes)
            break;

        fwrite(buffer, 1, readBytes, output);
        fileSize -= readBytes;
        if (!fileSize) // now we have read entire file
            break;

    } while (true);

    fclose(output);
    return true;
}

bool ExtractDB2File(uint32 fileDataId, char const* cascFileName, int locale, boost::filesystem::path const& outputPath)
{
    DB2CascFileSource source(CascStorage, fileDataId, false);
    if (!source.IsOpen())
    {
        printf("Unable to open file %s in the archive for locale %s: %s\n", cascFileName, localeNames[locale], CASC::HumanReadableCASCError(GetCascError()));
        return false;
    }

    int64 fileSize = source.GetFileSize();
    if (fileSize == -1)
    {
        printf("Can't read file size of '%s'\n", cascFileName);
        return false;
    }

    DB2FileLoader db2;
    try
    {
        db2.LoadHeaders(&source, nullptr);
    }
    catch (std::exception const& e)
    {
        printf("Can't read DB2 headers of '%s': %s\n", cascFileName, e.what());
        return false;
    }

    std::string outputFileName = outputPath.string();
    FILE* output = fopen(outputFileName.c_str(), "wb");
    if (!output)
    {
        printf("Can't create the output file '%s'\n", outputFileName.c_str());
        return false;
    }

    DB2Header header = db2.GetHeader();

    int64 posAfterHeaders = 0;
    posAfterHeaders += fwrite(&header, 1, sizeof(header), output);

    // erase TactId from header if key is known
    for (uint32 i = 0; i < header.SectionCount; ++i)
    {
        DB2SectionHeader sectionHeader = db2.GetSectionHeader(i);
        if (sectionHeader.TactId && CascStorage->HasTactKey(sectionHeader.TactId))
            sectionHeader.TactId = 0;

        posAfterHeaders += fwrite(&sectionHeader, 1, sizeof(sectionHeader), output);
    }

    char buffer[0x10000];
    uint32 readBatchSize = 0x10000;
    uint32 readBytes;
    source.SetPosition(posAfterHeaders);

    do
    {
        readBytes = 0;
        if (!source.GetNativeHandle()->ReadFile(buffer, std::min<uint32>(fileSize, readBatchSize), &readBytes))
        {
            printf("Can't read file '%s'\n", outputFileName.c_str());
            fclose(output);
            boost::filesystem::remove(outputPath);
            return false;
        }

        if (!readBytes)
            break;

        fwrite(buffer, 1, readBytes, output);
        fileSize -= readBytes;
        readBatchSize = 0x10000;
        if (!fileSize) // now we have read entire file
            break;

    } while (true);

    fclose(output);
    return true;
}

char const* GetCascFilenamePart(char const* cascPath)
{
    if (char const* lastSep = strrchr(cascPath, '\\'))
        return lastSep + 1;

    return cascPath;
}

void ExtractDBFilesClient(int l)
{
    printf("Extracting dbc/db2 files...\n");

    boost::filesystem::path localePath = output_path / "dbc" / localeNames[l];

    CreateDir(output_path / "dbc");
    CreateDir(localePath);

    printf("locale %s output path %s\n", localeNames[l], localePath.string().c_str());

    uint32 count = 0;
    for (DB2FileInfo const& db2 : DBFilesClientList)
    {
        boost::filesystem::path filePath = localePath / db2.Name;

        if (!boost::filesystem::exists(filePath))
            if (ExtractDB2File(db2.FileDataId, db2.Name, l, filePath.string()))
                ++count;

    }

    printf("Extracted %u files\n\n", count);
}

void ExtractCameraFiles()
{
    printf("Extracting camera files...\n");

    if (!ReadCinematicCameraDBC())
        return;

    boost::filesystem::path outputPath = output_path / "cameras";

    CreateDir(outputPath);

    printf("output path %s\n", outputPath.string().c_str());

    // extract M2s
    uint32 count = 0;
    for (uint32 cameraFileDataId : CameraFileDataIds)
    {
        std::unique_ptr<CASC::File> cameraFile(CascStorage->OpenFile(cameraFileDataId, CASC_LOCALE_NONE));
        if (cameraFile)
        {
            boost::filesystem::path filePath = outputPath / Trinity::StringFormat("FILE%08X.xxx", cameraFileDataId);

            if (!boost::filesystem::exists(filePath))
                if (ExtractFile(cameraFile.get(), filePath.string()))
                    ++count;
        }
        else
            printf("Unable to open file %u in the archive: %s\n", cameraFileDataId, CASC::HumanReadableCASCError(GetCascError()));
    }

    printf("Extracted %u camera files\n", count);
}

void ExtractGameTables()
{
    printf("Extracting game tables...\n");

    boost::filesystem::path outputPath = output_path / "gt";

    CreateDir(outputPath);

    printf("output path %s\n", outputPath.string().c_str());

    DB2FileInfo GameTables[] =
    {
        { 1582086, "ArtifactKnowledgeMultiplier.txt" },
        { 1391662, "ArtifactLevelXP.txt" },
        { 1391663, "BarberShopCostBase.txt" },
        { 1391664, "BaseMp.txt" },
        { 1391665, "BattlePetTypeDamageMod.txt" },
        { 1391666, "BattlePetXP.txt" },
        { 1391667, "ChallengeModeDamage.txt" },
        { 1391668, "ChallengeModeHealth.txt" },
        { 1391669, "CombatRatings.txt" },
        { 1391670, "CombatRatingsMultByILvl.txt" },
        { 1391671, "HonorLevel.txt" },
        { 1391642, "HpPerSta.txt" },
        { 2012881, "ItemLevelByLevel.txt" },
        { 1726830, "ItemLevelSquish.txt" },
        { 1391643, "ItemSocketCostPerLevel.txt" },
        { 1391651, "NPCManaCostScaler.txt" },
        { 1391659, "SandboxScaling.txt" },
        { 1391660, "SpellScaling.txt" },
        { 1980632, "StaminaMultByILvl.txt" },
        { 1391661, "xp.txt" }
    };

    uint32 count = 0;
    for (DB2FileInfo const& gt : GameTables)
    {
        std::unique_ptr<CASC::File> dbcFile(CascStorage->OpenFile(gt.FileDataId, CASC_LOCALE_NONE));
        if (dbcFile)
        {
            boost::filesystem::path filePath = outputPath / gt.Name;

            if (!boost::filesystem::exists(filePath))
                if (ExtractFile(dbcFile.get(), filePath.string()))
                    ++count;
        }
        else
            printf("Unable to open file %s in the archive: %s\n", gt.Name, CASC::HumanReadableCASCError(GetCascError()));
    }

    printf("Extracted %u files\n\n", count);
}

bool OpenCascStorage(int locale)
{
    try
    {
        boost::filesystem::path const storage_dir(boost::filesystem::canonical(input_path) / "Data");
        CascStorage.reset(CASC::Storage::Open(storage_dir, WowLocaleToCascLocaleFlags[locale], CONF_Product));
        if (!CascStorage)
        {
            printf("error opening casc storage '%s' locale %s\n", storage_dir.string().c_str(), localeNames[locale]);
            return false;
        }

        return true;
    }
    catch (boost::filesystem::filesystem_error const& error)
    {
        printf("Error opening CASC storage: %s\n", error.what());
        return false;
    }
}

uint32 GetInstalledLocalesMask()
{
    try
    {
        boost::filesystem::path const storage_dir(boost::filesystem::canonical(input_path) / "Data");
        std::unique_ptr<CASC::Storage> storage(CASC::Storage::Open(storage_dir, CASC_LOCALE_ALL_WOW, CONF_Product));
        if (!storage)
            return false;

        return storage->GetInstalledLocalesMask();
    }
    catch (boost::filesystem::filesystem_error const& error)
    {
        printf("Unable to determine installed locales mask: %s\n", error.what());
    }

    return 0;
}

static bool RetardCheck()
{
    try
    {
        boost::filesystem::path storageDir(boost::filesystem::canonical(input_path) / "Data");
        boost::filesystem::directory_iterator end;
        for (boost::filesystem::directory_iterator itr(storageDir); itr != end; ++itr)
        {
            if (itr->path().extension() == ".MPQ")
            {
                printf("MPQ files found in Data directory!\n");
                printf("This tool works only with World of Warcraft: Battle for Azeroth\n");
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

int main(int argc, char * arg[])
{
    Trinity::Banner::Show("Map & DBC Extractor", [](char const* text) { printf("%s\n", text); }, nullptr);

    PrintProgress = isatty(fileno(stdout));
    input_path = boost::filesystem::current_path();
    output_path = boost::filesystem::current_path();

    HandleArgs(argc, arg);

    if (!RetardCheck())
        return 1;

    uint32 installedLocalesMask = GetInstalledLocalesMask();
    int32 firstInstalledLocale = -1;
    uint32 build = 0;

    for (int i = 0; i < TOTAL_LOCALES; ++i)
    {
        if (CONF_Locale && !(CONF_Locale & (1 << i)))
            continue;

        if (i == LOCALE_none)
            continue;

        if (!(installedLocalesMask & WowLocaleToCascLocaleFlags[i]))
            continue;

        if (!OpenCascStorage(i))
            continue;

        if ((CONF_extract & EXTRACT_DBC) == 0)
        {
            firstInstalledLocale = i;
            build = CascStorage->GetBuildNumber();
            if (!build)
            {
                CascStorage.reset();
                continue;
            }

            printf("Detected client build: %u\n\n", build);
            break;
        }

        //Extract DBC files
        uint32 tempBuild = CascStorage->GetBuildNumber();
        if (!tempBuild)
        {
            CascStorage.reset();
            continue;
        }

        printf("Detected client build %u for locale %s\n\n", tempBuild, localeNames[i]);
        ExtractDBFilesClient(i);
        CascStorage.reset();

        if (firstInstalledLocale < 0)
        {
            firstInstalledLocale = i;
            build = tempBuild;
        }
    }

    if (firstInstalledLocale < 0)
    {
        printf("No locales detected\n");
        return 0;
    }

    if (CONF_extract & EXTRACT_CAMERA)
    {
        OpenCascStorage(firstInstalledLocale);
        ExtractCameraFiles();
        CascStorage.reset();
    }

    if (CONF_extract & EXTRACT_GT)
    {
        OpenCascStorage(firstInstalledLocale);
        ExtractGameTables();
        CascStorage.reset();
    }

    if (CONF_extract & EXTRACT_MAP)
    {
        OpenCascStorage(firstInstalledLocale);
        ExtractMaps(build);
        CascStorage.reset();
    }

    return 0;
}
