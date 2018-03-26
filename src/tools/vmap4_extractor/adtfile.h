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

#include "cascfile.h"
#include "wmo.h"
#include "model.h"

#define TILESIZE (533.33333f)
#define CHUNKSIZE ((TILESIZE) / 16.0f)
#define UNITSIZE (CHUNKSIZE / 8.0f)

class Liquid;

typedef struct
{
    float x;
    float y;
    float z;
}svec;

struct vec
{
    double x;
    double y;
    double z;
};

struct triangle
{
    vec v[3];
};

typedef struct
{
    float v9[16*8+1][16*8+1];
    float v8[16*8][16*8];
}Cell;

typedef struct
{
    double v9[9][9];
    double v8[8][8];
    uint16 area_id;
    //Liquid *lq;
    float waterlevel[9][9];
    uint8 flag;
}chunk;

typedef struct
{
    chunk ch[16][16];
}mcell;

struct MapChunkHeader
{
    uint32 flags;
    uint32 ix;
    uint32 iy;
    uint32 nLayers;
    uint32 nDoodadRefs;
    uint32 ofsHeight;
    uint32 ofsNormal;
    uint32 ofsLayer;
    uint32 ofsRefs;
    uint32 ofsAlpha;
    uint32 sizeAlpha;
    uint32 ofsShadow;
    uint32 sizeShadow;
    uint32 areaid;
    uint32 nMapObjRefs;
    uint32 holes;
    uint16 s1;
    uint16 s2;
    uint32 d1;
    uint32 d2;
    uint32 d3;
    uint32 predTex;
    uint32 nEffectDoodad;
    uint32 ofsSndEmitters;
    uint32 nSndEmitters;
    uint32 ofsLiquid;
    uint32 sizeLiquid;
    float  zpos;
    float  xpos;
    float  ypos;
    uint32 textureId;
    uint32 props;
    uint32 effectId;
};

struct ADTOutputCache
{
    uint32 Flags;
    std::vector<uint8> Data;
};

class ADTFile
{
private:
    CASCFile ADT;
    std::string Adtfilename;
    bool cacheable;
    std::vector<ADTOutputCache>* dirfileCache;
public:
    ADTFile(char* filename, bool cache);
    ~ADTFile();
    int nWMO;
    int nMDX;
    std::vector<std::string> WmoInstanceNames;
    std::vector<std::string> ModelInstanceNames;
    bool init(uint32 map_num, uint32 tileX, uint32 tileY, uint32 originalMapId);
    bool initFromCache(uint32 map_num, uint32 tileX, uint32 tileY, uint32 originalMapId);
};

char const* GetPlainName(char const* FileName);
char* GetPlainName(char* FileName);
char* GetExtension(char* FileName);
void FixNameCase(char* name, size_t len);
void FixNameSpaces(char* name, size_t len);
//void fixMapNamen(char *name, size_t len);

#endif
