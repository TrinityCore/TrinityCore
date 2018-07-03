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

#ifndef ADT_H
#define ADT_H

#include "Define.h"

#define TILESIZE (533.33333f)
#define CHUNKSIZE ((TILESIZE) / 16.0f)
#define UNITSIZE (CHUNKSIZE / 8.0f)

enum LiquidType
{
    LIQUID_TYPE_WATER = 0,
    LIQUID_TYPE_OCEAN = 1,
    LIQUID_TYPE_MAGMA = 2,
    LIQUID_TYPE_SLIME = 3
};

//**************************************************************************************
// ADT file class
//**************************************************************************************
#define ADT_CELLS_PER_GRID    16
#define ADT_CELL_SIZE         8
#define ADT_GRID_SIZE         (ADT_CELLS_PER_GRID*ADT_CELL_SIZE)

#pragma pack(push, 1)

//
// Adt file height map chunk
//
struct adt_MCVT
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    float height_map[(ADT_CELL_SIZE+1)*(ADT_CELL_SIZE+1)+ADT_CELL_SIZE*ADT_CELL_SIZE];
};

//
// Adt file liquid map chunk (old)
//
struct adt_MCLQ
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    float height1;
    float height2;
    struct liquid_data{
        uint32 light;
        float  height;
    } liquid[ADT_CELL_SIZE+1][ADT_CELL_SIZE+1];

    // 1<<0 - ochen
    // 1<<1 - lava/slime
    // 1<<2 - water
    // 1<<6 - all water
    // 1<<7 - dark water
    // == 0x0F - not show liquid
    uint8 flags[ADT_CELL_SIZE][ADT_CELL_SIZE];
    uint8 data[84];
};

//
// Adt file cell chunk
//
struct adt_MCNK
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    uint32 flags;
    uint32 ix;
    uint32 iy;
    uint32 nLayers;
    uint32 nDoodadRefs;
    union
    {
        struct
        {
            uint32 offsMCVT;        // height map
            uint32 offsMCNR;        // Normal vectors for each vertex
        } offsets;
        uint8 HighResHoles[8];
    } union_5_3_0;
    uint32 offsMCLY;        // Texture layer definitions
    uint32 offsMCRF;        // A list of indices into the parent file's MDDF chunk
    uint32 offsMCAL;        // Alpha maps for additional texture layers
    uint32 sizeMCAL;
    uint32 offsMCSH;        // Shadow map for static shadows on the terrain
    uint32 sizeMCSH;
    uint32 areaid;
    uint32 nMapObjRefs;
    uint32 holes;
    uint16 s[2];
    uint32 data1;
    uint32 data2;
    uint32 data3;
    uint32 predTex;
    uint32 nEffectDoodad;
    uint32 offsMCSE;
    uint32 nSndEmitters;
    uint32 offsMCLQ;         // Liqid level (old)
    uint32 sizeMCLQ;         //
    float  zpos;
    float  xpos;
    float  ypos;
    uint32 offsMCCV;         // offsColorValues in WotLK
    uint32 props;
    uint32 effectId;
};

#define ADT_LIQUID_HEADER_FULL_LIGHT   0x01
#define ADT_LIQUID_HEADER_NO_HIGHT     0x02

enum class LiquidVertexFormatType : uint16
{
    HeightDepth             = 0,
    HeightTextureCoord      = 1,
    Depth                   = 2,
    HeightDepthTextureCoord = 3,
    Unk4                    = 4,
    Unk5                    = 5
};

struct adt_liquid_instance
{
    uint16 LiquidType;              // Index from LiquidType.db2
    uint16 LiquidVertexFormat;      // Id from LiquidObject.db2 if >= 42
    float MinHeightLevel;
    float MaxHeightLevel;
    uint8 OffsetX;
    uint8 OffsetY;
    uint8 Width;
    uint8 Height;
    uint32 OffsetExistsBitmap;
    uint32 OffsetVertexData;

    uint8 GetOffsetX() const { return LiquidVertexFormat < 42 ? OffsetX : 0; }
    uint8 GetOffsetY() const { return LiquidVertexFormat < 42 ? OffsetY : 0; }
    uint8 GetWidth() const { return LiquidVertexFormat < 42 ? Width : 8; }
    uint8 GetHeight() const { return LiquidVertexFormat < 42 ? Height : 8; }
};

struct adt_liquid_attributes
{
    uint64 Fishable;
    uint64 Deep;
};

//
// Adt file liquid data chunk (new)
//
struct adt_MH2O
{
    union{
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;

    struct adt_LIQUID{
        uint32 OffsetInstances;
        uint32 used;
        uint32 OffsetAttributes;
    } liquid[ADT_CELLS_PER_GRID][ADT_CELLS_PER_GRID];

    adt_liquid_instance const* GetLiquidInstance(int32 x, int32 y) const
    {
        if (liquid[x][y].used && liquid[x][y].OffsetInstances)
            return (adt_liquid_instance *)((uint8*)this + 8 + liquid[x][y].OffsetInstances);
        return nullptr;
    }

    adt_liquid_attributes GetLiquidAttributes(int32 x, int32 y) const
    {
        if (liquid[x][y].used)
        {
            if (liquid[x][y].OffsetAttributes)
                return *((adt_liquid_attributes *)((uint8*)this + 8 + liquid[x][y].OffsetAttributes));
            return { 0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF };
        }
        return { 0, 0 };
    }

    uint16 GetLiquidType(adt_liquid_instance const* h) const
    {
        if (GetLiquidVertexFormat(h) == LiquidVertexFormatType::Depth)
            return 2;

        return h->LiquidType;
    }

    float GetLiquidHeight(adt_liquid_instance const* h, int32 pos) const
    {
        if (!h->OffsetVertexData)
            return 0.0f;
        if (GetLiquidVertexFormat(h) == LiquidVertexFormatType::Depth)
            return 0.0f;

        switch (GetLiquidVertexFormat(h))
        {
            case LiquidVertexFormatType::HeightDepth:
            case LiquidVertexFormatType::HeightTextureCoord:
            case LiquidVertexFormatType::HeightDepthTextureCoord:
                return ((float const*)((uint8*)this + 8 + h->OffsetVertexData))[pos];
            case LiquidVertexFormatType::Depth:
                return 0.0f;
            case LiquidVertexFormatType::Unk4:
            case LiquidVertexFormatType::Unk5:
                return ((float const*)((uint8*)this + 8 + h->OffsetVertexData + 4))[pos * 2];
            default:
                break;
        }

        return 0.0f;
    }

    int8 GetLiquidDepth(adt_liquid_instance const* h, int32 pos) const
    {
        if (!h->OffsetVertexData)
            return -1;

        switch (GetLiquidVertexFormat(h))
        {
            case LiquidVertexFormatType::HeightDepth:
                return ((int8 const*)((int8 const*)this + 8 + h->OffsetVertexData + (h->GetWidth() + 1) * (h->GetHeight() + 1) * 4))[pos];
            case LiquidVertexFormatType::HeightTextureCoord:
                return 0;
            case LiquidVertexFormatType::Depth:
                return ((int8 const*)((uint8*)this + 8 + h->OffsetVertexData))[pos];
            case LiquidVertexFormatType::HeightDepthTextureCoord:
                return ((int8 const*)((int8 const*)this + 8 + h->OffsetVertexData + (h->GetWidth() + 1) * (h->GetHeight() + 1) * 8))[pos];
            case LiquidVertexFormatType::Unk4:
                return ((int8 const*)((uint8*)this + 8 + h->OffsetVertexData))[pos * 8];
            case LiquidVertexFormatType::Unk5:
                return 0;
            default:
                break;
        }
        return 0;
    }

    uint16 const* GetLiquidTextureCoordMap(adt_liquid_instance const* h, int32 pos) const
    {
        if (!h->OffsetVertexData)
            return nullptr;

        switch (GetLiquidVertexFormat(h))
        {
            case LiquidVertexFormatType::HeightDepth:
            case LiquidVertexFormatType::Depth:
            case LiquidVertexFormatType::Unk4:
                return nullptr;
            case LiquidVertexFormatType::HeightTextureCoord:
            case LiquidVertexFormatType::HeightDepthTextureCoord:
                return (uint16 const*)((uint8 const*)this + 8 + h->OffsetVertexData + 4 * ((h->GetWidth() + 1) * (h->GetHeight() + 1) + pos));
            case LiquidVertexFormatType::Unk5:
                return (uint16 const*)((uint8 const*)this + 8 + h->OffsetVertexData + 8 * ((h->GetWidth() + 1) * (h->GetHeight() + 1) + pos));
            default:
                break;
        }
        return nullptr;
    }

    uint64 GetLiquidExistsBitmap(adt_liquid_instance const* h) const
    {
        if (h->OffsetExistsBitmap)
            return *((uint64 *)((uint8*)this + 8 + h->OffsetExistsBitmap));
        else
            return 0xFFFFFFFFFFFFFFFFuLL;
    }

    LiquidVertexFormatType GetLiquidVertexFormat(adt_liquid_instance const* liquidInstance) const;
};

struct adt_MFBO
{
    union
    {
        uint32 fcc;
        char   fcc_txt[4];
    };
    uint32 size;
    struct plane
    {
        int16 coords[9];
    };
    plane max;
    plane min;
};

#pragma pack(pop)

#endif
