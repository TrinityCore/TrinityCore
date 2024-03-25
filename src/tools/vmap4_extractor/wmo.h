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

#ifndef WMO_H
#define WMO_H

#include "vec3d.h"
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>

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
namespace ADT { struct MODF; }

namespace WMO
{
    struct MODS
    {
        char Name[20];
        uint32 StartIndex;     // index of first doodad instance in this set
        uint32 Count;          // number of doodad instances in this set
        char _pad[4];
    };

    struct MODD
    {
        uint32 NameIndex : 24;
        Vec3D Position;
        Quaternion Rotation;
        float Scale;
        uint32 Color;
    };
}

/* for whatever reason a certain company just can't stick to one coordinate system... */
static inline Vec3D fixCoords(Vec3D const& v){ return Vec3D(v.z, v.x, v.y); }

struct WMODoodadData
{
    std::vector<WMO::MODS> Sets;
    std::unique_ptr<char[]> Paths;
    std::unique_ptr<uint32[]> FileDataIds;
    std::vector<WMO::MODD> Spawns;
    std::unordered_set<uint16> References;
};

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

    std::vector<char> GroupNames;
    WMODoodadData DoodadData;
    std::unordered_set<uint32> ValidDoodadNames;
    std::vector<uint32> groupFileDataIDs;

    WMORoot(std::string const& filename);

    bool open();
    bool ConvertToVMAPRootWmo(FILE* output);
};

#pragma pack(push, 1)

struct WMOLiquidHeader
{
    int xverts, yverts, xtiles, ytiles;
    float pos_x;
    float pos_y;
    float pos_z;
    short material;
};

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

    std::unique_ptr<uint16[]> MPY2;
    std::unique_ptr<uint32[]> MOVX;
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
    uint32 nBatchC, fogIdx, groupLiquid, groupWMOID;
    uint32 mogpFlags2;
    int16 parentOrFirstChildSplitGroupIndex;
    int16 nextSplitChildGroupIndex;

    int moba_size;
    int LiquEx_size;
    unsigned int nVertices; // number when loaded
    int nTriangles; // number when loaded
    uint32 liquflags;

    std::vector<uint16> DoodadReferences;

    WMOGroup(std::string const& filename);
    WMOGroup(WMOGroup&&) = default;
    WMOGroup& operator=(WMOGroup&&) = default;
    ~WMOGroup();

    bool open(WMORoot* rootWMO);
    int ConvertToVMAPGroupWmo(FILE* output, bool preciseVectorData);
    uint32 GetLiquidTypeId(uint32 liquidTypeId);
    bool ShouldSkip(WMORoot const* root) const;
};

namespace MapObject
{
    void Extract(ADT::MODF const& mapObjDef, char const* WmoInstName, bool isGlobalWmo, uint32 mapID, uint32 originalMapId,
        FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache);
}

#endif
