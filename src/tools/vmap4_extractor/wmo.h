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

#ifndef WMO_H
#define WMO_H
#define TILESIZE (533.33333f)
#define CHUNKSIZE ((TILESIZE) / 16.0f)

#include <string>
#include <set>
#include <vector>
#include "vec3d.h"
#include "cascfile.h"

// MOPY flags
enum MopyFlags
{
    WMO_MATERIAL_UNK01          = 0x01,
    WMO_MATERIAL_NOCAMCOLLIDE   = 0x02,
    WMO_MATERIAL_DETAIL         = 0x04,
    WMO_MATERIAL_COLLISION      = 0x08,
    WMO_MATERIAL_HINT           = 0x10,
    WMO_MATERIAL_RENDER         = 0x20,
    WMO_MATERIAL_WALL_SURFACE   = 0x40, // Guessed
    WMO_MATERIAL_COLLIDE_HIT    = 0x80
};

class WMOInstance;
class WMOManager;
class CASCFile;
struct ADTOutputCache;

/* for whatever reason a certain company just can't stick to one coordinate system... */
static inline Vec3D fixCoords(const Vec3D &v){ return Vec3D(v.z, v.x, v.y); }

class WMORoot
{
private:
    std::string filename;
public:
    unsigned int color;
    uint32 nTextures, nGroups, nPortals, nLights, nDoodadNames, nDoodadDefs, nDoodadSets, RootWMOID;
    float bbcorn1[3];
    float bbcorn2[3];
    uint16 flags, numLod;

    std::vector<uint32> groupFileDataIDs;

    WMORoot(std::string& filename);

    bool open();
    bool ConvertToVMAPRootWmo(FILE* output);
};

struct WMOLiquidHeader
{
    int xverts, yverts, xtiles, ytiles;
    float pos_x;
    float pos_y;
    float pos_z;
    short type;
};

#pragma pack(push, 1)

struct WMOLiquidVert
{
    uint16 unk1;
    uint16 unk2;
    float height;
};

#pragma pack(pop)

class WMOGroup
{
private:
    std::string filename;
public:
    // MOGP

    char* MOPY;
    uint16* MOVI;
    uint16* MoviEx;
    float* MOVT;
    uint16* MOBA;
    int* MobaEx;
    WMOLiquidHeader* hlq;
    WMOLiquidVert* LiquEx;
    char* LiquBytes;
    int groupName, descGroupName;
    int mogpFlags;
    float bbcorn1[3];
    float bbcorn2[3];
    uint16 moprIdx;
    uint16 moprNItems;
    uint16 nBatchA;
    uint16 nBatchB;
    uint32 nBatchC, fogIdx, liquidType, groupWMOID;

    int mopy_size, moba_size;
    int LiquEx_size;
    unsigned int nVertices; // number when loaded
    int nTriangles; // number when loaded
    uint32 liquflags;

    WMOGroup(std::string const& filename);
    ~WMOGroup();

    bool open();
    int ConvertToVMAPGroupWmo(FILE* output, WMORoot* rootWMO, bool preciseVectorData);
};

class WMOInstance
{
    static std::set<int> ids;
public:
    std::string MapName;
    int currx;
    int curry;
    WMOGroup* wmo;
    int doodadset;
    Vec3D pos;
    Vec3D pos2, pos3, rot;
    uint32 indx, id;

    WMOInstance(CASCFile&f , char const* WmoInstName, uint32 mapID, uint32 tileX, uint32 tileY, uint32 originalMapId, FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache);
};

#endif
