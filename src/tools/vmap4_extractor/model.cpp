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

#include "vmapexport.h"
#include "Errors.h"
#include "model.h"
#include "wmo.h"
#include "adtfile.h"
#include "cascfile.h"
#include "VMapDefinitions.h"
#include <G3D/Quat.h>
#include <algorithm>
#include <cstdio>
#include <limits>

extern std::shared_ptr<CASC::Storage> CascStorage;

Model::Model(std::string &filename) : filename(filename), header(), vertices(nullptr), indices(nullptr)
{
}

bool Model::open()
{
    CASCFile f(CascStorage, filename.c_str());

    if (f.isEof())
    {
        f.close();
        // Do not show this error on console to avoid confusion, the extractor can continue working even if some models fail to load
        //printf("Error loading model %s\n", filename.c_str());
        return false;
    }

    _unload();

    uint32 m2start = 0;
    char const* ptr = f.getBuffer();
    while (m2start + 4 < f.getSize() && memcmp(ptr, "MD20", 4) != 0)
    {
        ++m2start;
        ++ptr;
        if (m2start + sizeof(ModelHeader) > f.getSize())
            return false;
    }

    memcpy(&header, f.getBuffer() + m2start, sizeof(ModelHeader));
    bounds = header.collisionBox;
    if (header.nBoundingTriangles > 0)
    {
        f.seek(m2start);
        f.seekRelative(header.ofsBoundingVertices);
        vertices = new Vec3D[header.nBoundingVertices];
        f.read(vertices,header.nBoundingVertices*12);
        for (uint32 i=0; i<header.nBoundingVertices; i++)
            vertices[i] = fixCoordSystem(vertices[i]);
        f.seek(m2start);
        f.seekRelative(header.ofsBoundingTriangles);
        indices = new uint16[header.nBoundingTriangles];
        f.read(indices,header.nBoundingTriangles*2);
        f.close();
    }
    else
    {
        //printf("not included %s\n", filename.c_str());
        f.close();
        return false;
    }
    return true;
}

bool Model::ConvertToVMAPModel(const char * outfilename)
{
    int N[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    FILE* output=fopen(outfilename, "wb");
    if (!output)
    {
        printf("Can't create the output file '%s'\n",outfilename);
        return false;
    }
    fwrite(VMAP::RAW_VMAP_MAGIC, 8, 1, output);
    uint32 nVertices = header.nBoundingVertices;
    fwrite(&nVertices, sizeof(int), 1, output);
    uint32 nofgroups = 1;
    fwrite(&nofgroups, sizeof(uint32), 1, output);
    fwrite(N, 4 * 3, 1, output);// rootwmoid, flags, groupid
    fwrite(&bounds, sizeof(AaBox3D), 1, output);//bbox, only needed for WMO currently
    fwrite(N, 4, 1, output);// liquidflags
    fwrite("GRP ", 4, 1, output);
    uint32 branches = 1;
    int wsize;
    wsize = sizeof(branches) + sizeof(uint32) * branches;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&branches, sizeof(branches), 1, output);
    uint32 nIndexes = header.nBoundingTriangles;
    fwrite(&nIndexes, sizeof(uint32), 1, output);
    fwrite("INDX",4, 1, output);
    wsize = sizeof(uint32) + sizeof(unsigned short) * nIndexes;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nIndexes, sizeof(uint32), 1, output);
    if (nIndexes > 0)
    {
        for (uint32 i = 0; i < nIndexes; ++i)
        {
            if ((i % 3) - 1 == 0 && i + 1 < nIndexes)
            {
                uint16 tmp = indices[i];
                indices[i] = indices[i + 1];
                indices[i + 1] = tmp;
            }
        }
        fwrite(indices, sizeof(unsigned short), nIndexes, output);
    }

    fwrite("VERT", 4, 1, output);
    wsize = sizeof(int) + sizeof(float) * 3 * nVertices;
    fwrite(&wsize, sizeof(int), 1, output);
    fwrite(&nVertices, sizeof(int), 1, output);
    if (nVertices >0)
    {
        for (uint32 vpos = 0; vpos < nVertices; ++vpos)
        {
            float tmp = vertices[vpos].y;
            vertices[vpos].y = -vertices[vpos].z;
            vertices[vpos].z = tmp;
        }

        fwrite(vertices, sizeof(float)*3, nVertices, output);
    }

    fclose(output);

    return true;
}

Vec3D fixCoordSystem(Vec3D const& v)
{
    return Vec3D(v.x, v.z, -v.y);
}

void Doodad::Extract(ADT::MDDF const& doodadDef, char const* ModelInstName, uint32 mapID, uint32 originalMapId, FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache)
{
    char tempname[1036];
    sprintf(tempname, "%s/%s", szWorkDirWmo, ModelInstName);
    FILE* input = fopen(tempname, "r+b");

    if (!input)
        return;

    fseek(input, 8, SEEK_SET); // get the correct no of vertices
    int nVertices;
    int count = fread(&nVertices, sizeof (int), 1, input);
    fclose(input);

    if (count != 1 || nVertices == 0)
        return;

    // scale factor - divide by 1024. blizzard devs must be on crack, why not just use a float?
    float sc = doodadDef.Scale / 1024.0f;

    Vec3D position = fixCoords(doodadDef.Position);

    uint16 nameSet = 0;// not used for models
    uint32 uniqueId = GenerateUniqueObjectId(doodadDef.UniqueId, 0);
    uint32 tcflags = MOD_M2;
    if (mapID != originalMapId)
        tcflags |= MOD_PARENT_SPAWN;

    //write mapID, Flags, NameSet, UniqueId, Pos, Rot, Scale, name
    fwrite(&mapID, sizeof(uint32), 1, pDirfile);
    fwrite(&tcflags, sizeof(uint32), 1, pDirfile);
    fwrite(&nameSet, sizeof(uint16), 1, pDirfile);
    fwrite(&uniqueId, sizeof(uint32), 1, pDirfile);
    fwrite(&position, sizeof(Vec3D), 1, pDirfile);
    fwrite(&doodadDef.Rotation, sizeof(Vec3D), 1, pDirfile);
    fwrite(&sc, sizeof(float), 1, pDirfile);
    uint32 nlen = strlen(ModelInstName);
    fwrite(&nlen, sizeof(uint32), 1, pDirfile);
    fwrite(ModelInstName, sizeof(char), nlen, pDirfile);

    if (dirfileCache)
    {
        dirfileCache->emplace_back();
        ADTOutputCache& cacheModelData = dirfileCache->back();
        cacheModelData.Flags = tcflags & ~MOD_PARENT_SPAWN;
        cacheModelData.Data.resize(
            sizeof(uint16) +    // nameSet
            sizeof(uint32) +    // uniqueId
            sizeof(Vec3D) +     // position
            sizeof(Vec3D) +     // doodadDef.Rotation
            sizeof(float) +     // sc
            sizeof(uint32) +    // nlen
            nlen);              // ModelInstName

        uint8* cacheData = cacheModelData.Data.data();
#define CACHE_WRITE(value, size, cnt, dest) memcpy(dest, value, size * cnt); dest += size * cnt;

        CACHE_WRITE(&nameSet, sizeof(uint16), 1, cacheData);
        CACHE_WRITE(&uniqueId, sizeof(uint32), 1, cacheData);
        CACHE_WRITE(&position, sizeof(Vec3D), 1, cacheData);
        CACHE_WRITE(&doodadDef.Rotation, sizeof(Vec3D), 1, cacheData);
        CACHE_WRITE(&sc, sizeof(float), 1, cacheData);
        CACHE_WRITE(&nlen, sizeof(uint32), 1, cacheData);
        CACHE_WRITE(ModelInstName, sizeof(char), nlen, cacheData);
    }
}

void Doodad::ExtractSet(WMODoodadData const& doodadData, ADT::MODF const& wmo, bool isGlobalWmo, uint32 mapID, uint32 originalMapId,
    FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache)
{
    if (wmo.DoodadSet >= doodadData.Sets.size())
        return;

    G3D::Vector3 wmoPosition(wmo.Position.z, wmo.Position.x, wmo.Position.y);
    G3D::Matrix3 wmoRotation = G3D::Matrix3::fromEulerAnglesZYX(G3D::toRadians(wmo.Rotation.y), G3D::toRadians(wmo.Rotation.x), G3D::toRadians(wmo.Rotation.z));

    if (isGlobalWmo)
        wmoPosition += G3D::Vector3(533.33333f * 32, 533.33333f * 32, 0.0f);

    uint16 doodadId = 0;
    WMO::MODS const& doodadSetData = doodadData.Sets[wmo.DoodadSet];
    for (uint16 doodadIndex : doodadData.References)
    {
        if (doodadIndex < doodadSetData.StartIndex ||
            doodadIndex >= doodadSetData.StartIndex + doodadSetData.Count)
            continue;

        WMO::MODD const& doodad = doodadData.Spawns[doodadIndex];

        char ModelInstName[1024];
        if (doodadData.Paths)
            sprintf(ModelInstName, "%s", GetPlainName(&doodadData.Paths[doodad.NameIndex]));
        else if (doodadData.FileDataIds)
            sprintf(ModelInstName, "FILE%08X.xxx", doodadData.FileDataIds[doodad.NameIndex]);
        else
            ASSERT(false);

        uint32 nlen = strlen(ModelInstName);
        NormalizeFileName(ModelInstName, nlen);
        if (nlen > 3)
        {
            char const* extension = &ModelInstName[nlen - 4];
            if (!strcmp(extension, ".mdx") || !strcmp(extension, ".mdl"))
            {
                ModelInstName[nlen - 2] = '2';
                ModelInstName[nlen - 1] = '\0';
            }
        }

        char tempname[1036];
        sprintf(tempname, "%s/%s", szWorkDirWmo, ModelInstName);
        FILE* input = fopen(tempname, "r+b");
        if (!input)
            continue;

        fseek(input, 8, SEEK_SET); // get the correct no of vertices
        int nVertices;
        int count = fread(&nVertices, sizeof(int), 1, input);
        fclose(input);

        if (count != 1 || nVertices == 0)
            continue;

        ASSERT(doodadId < std::numeric_limits<uint16>::max());
        ++doodadId;

        G3D::Vector3 position = wmoPosition + (wmoRotation * G3D::Vector3(doodad.Position.x, doodad.Position.y, doodad.Position.z));

        Vec3D rotation;
        (G3D::Quat(doodad.Rotation.X, doodad.Rotation.Y, doodad.Rotation.Z, doodad.Rotation.W)
            .toRotationMatrix() * wmoRotation)
            .toEulerAnglesXYZ(rotation.z, rotation.x, rotation.y);

        rotation.z = G3D::toDegrees(rotation.z);
        rotation.x = G3D::toDegrees(rotation.x);
        rotation.y = G3D::toDegrees(rotation.y);

        uint16 nameSet = 0;     // not used for models
        uint32 uniqueId = GenerateUniqueObjectId(wmo.UniqueId, doodadId);
        uint32 tcflags = MOD_M2;
        if (mapID != originalMapId)
            tcflags |= MOD_PARENT_SPAWN;

        //write mapID, Flags, NameSet, UniqueId, Pos, Rot, Scale, name
        fwrite(&mapID, sizeof(uint32), 1, pDirfile);
        fwrite(&tcflags, sizeof(uint32), 1, pDirfile);
        fwrite(&nameSet, sizeof(uint16), 1, pDirfile);
        fwrite(&uniqueId, sizeof(uint32), 1, pDirfile);
        fwrite(&position, sizeof(Vec3D), 1, pDirfile);
        fwrite(&rotation, sizeof(Vec3D), 1, pDirfile);
        fwrite(&doodad.Scale, sizeof(float), 1, pDirfile);
        fwrite(&nlen, sizeof(uint32), 1, pDirfile);
        fwrite(ModelInstName, sizeof(char), nlen, pDirfile);

        if (dirfileCache)
        {
            dirfileCache->emplace_back();
            ADTOutputCache& cacheModelData = dirfileCache->back();
            cacheModelData.Flags = tcflags & ~MOD_PARENT_SPAWN;
            cacheModelData.Data.resize(
                sizeof(uint16) +    // nameSet
                sizeof(uint32) +    // uniqueId
                sizeof(Vec3D) +     // position
                sizeof(Vec3D) +     // rotation
                sizeof(float) +     // doodad.Scale
                sizeof(uint32) +    // nlen
                nlen);              // ModelInstName

            uint8* cacheData = cacheModelData.Data.data();
            CACHE_WRITE(&nameSet, sizeof(uint16), 1, cacheData);
            CACHE_WRITE(&uniqueId, sizeof(uint32), 1, cacheData);
            CACHE_WRITE(&position, sizeof(Vec3D), 1, cacheData);
            CACHE_WRITE(&rotation, sizeof(Vec3D), 1, cacheData);
            CACHE_WRITE(&doodad.Scale, sizeof(float), 1, cacheData);
            CACHE_WRITE(&nlen, sizeof(uint32), 1, cacheData);
            CACHE_WRITE(ModelInstName, sizeof(char), nlen, cacheData);
        }
    }
}

#undef CACHE_WRITE
