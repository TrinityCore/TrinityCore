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
#include "adtfile.h"
#include "cascfile.h"
#include "Errors.h"
#include "StringFormat.h"
#include "vec3d.h"
#include "VMapDefinitions.h"
#include "wmo.h"
#include <algorithm>
#include <fstream>
#include <map>
#include <cstdio>
#include <cstdlib>

WMORoot::WMORoot(std::string const& filename)
    : filename(filename), color(0), nTextures(0), nGroups(0), nPortals(0), nLights(0),
    nDoodadNames(0), nDoodadDefs(0), nDoodadSets(0), RootWMOID(0), flags(0), numLod(0)
{
    memset(bbcorn1, 0, sizeof(bbcorn1));
    memset(bbcorn2, 0, sizeof(bbcorn2));
}

extern std::shared_ptr<CASC::Storage> CascStorage;

bool WMORoot::open()
{
    CASCFile f(CascStorage, filename.c_str());
    if(f.isEof ())
    {
        printf("No such file.\n");
        return false;
    }

    uint32 size;
    char fourcc[5];

    while (!f.isEof())
    {
        f.read(fourcc,4);
        f.read(&size, 4);

        flipcc(fourcc);
        fourcc[4] = 0;

        size_t nextpos = f.getPos() + size;

        if (!strcmp(fourcc,"MOHD")) // header
        {
            f.read(&nTextures, 4);
            f.read(&nGroups, 4);
            f.read(&nPortals, 4);
            f.read(&nLights, 4);
            f.read(&nDoodadNames, 4);
            f.read(&nDoodadDefs, 4);
            f.read(&nDoodadSets, 4);
            f.read(&color, 4);
            f.read(&RootWMOID, 4);
            f.read(bbcorn1, 12);
            f.read(bbcorn2, 12);
            f.read(&flags, 2);
            f.read(&numLod, 2);
        }
        else if (!strcmp(fourcc, "MODS"))
        {
            DoodadData.Sets.resize(size / sizeof(WMO::MODS));
            f.read(DoodadData.Sets.data(), size);
        }
        else if (!strcmp(fourcc,"MODN"))
        {
            ASSERT(!DoodadData.FileDataIds);

            char* ptr = f.getPointer();
            char* end = ptr + size;
            DoodadData.Paths = std::make_unique<char[]>(size);
            memcpy(DoodadData.Paths.get(), ptr, size);
            while (ptr < end)
            {
                std::string path = ptr;

                char* s = GetPlainName(ptr);
                NormalizeFileName(s, strlen(s));

                uint32 doodadNameIndex = ptr - f.getPointer();
                ptr += path.length() + 1;

                if (ExtractSingleModel(path))
                    ValidDoodadNames.insert(doodadNameIndex);
            }
        }
        else if (!strcmp(fourcc, "MODI"))
        {
            ASSERT(!DoodadData.Paths);

            uint32 fileDataIdCount = size / sizeof(uint32);
            DoodadData.FileDataIds = std::make_unique<uint32[]>(fileDataIdCount);
            f.read(DoodadData.FileDataIds.get(), size);
            for (uint32 i = 0; i < fileDataIdCount; ++i)
            {
                if (!DoodadData.FileDataIds[i])
                    continue;

                std::string path = Trinity::StringFormat("FILE{:08X}.xxx", DoodadData.FileDataIds[i]);
                if (ExtractSingleModel(path))
                    ValidDoodadNames.insert(i);
            }
        }
        else if (!strcmp(fourcc,"MODD"))
        {
            DoodadData.Spawns.resize(size / sizeof(WMO::MODD));
            f.read(DoodadData.Spawns.data(), size);
        }
        else if (!strcmp(fourcc, "MOGN"))
        {
            GroupNames.resize(size);
            f.read(GroupNames.data(), size);
        }
        else if (!strcmp(fourcc, "GFID"))
        {
            // full LOD reading code for reference
            // commented out as we are not interested in any of them beyond first, most detailed

            //uint16 lodCount = 1;
            //if (flags & 0x10)
            //{
            //    if (numLod)
            //        lodCount = numLod;
            //    else
            //        lodCount = 3;
            //}

            //for (uint32 lod = 0; lod < lodCount; ++lod)
            //{
                for (uint32 gp = 0; gp < nGroups; ++gp)
                {
                    uint32 fileDataId;
                    f.read(&fileDataId, 4);
                    if (fileDataId)
                        groupFileDataIDs.push_back(fileDataId);
                }
            //}
        }
        /*
        else if (!strcmp(fourcc,"MOTX"))
        {
        }
        else if (!strcmp(fourcc,"MOMT"))
        {
        }
        else if (!strcmp(fourcc,"MOGI"))
        {
        }
        else if (!strcmp(fourcc,"MOLT"))
        {
        }
        else if (!strcmp(fourcc,"MOSB"))
        {
        }
        else if (!strcmp(fourcc,"MOPV"))
        {
        }
        else if (!strcmp(fourcc,"MOPT"))
        {
        }
        else if (!strcmp(fourcc,"MOPR"))
        {
        }
        else if (!strcmp(fourcc,"MFOG"))
        {
        }
        */
        f.seek((int)nextpos);
    }
    f.close ();
    return true;
}

bool WMORoot::ConvertToVMAPRootWmo(FILE* pOutfile)
{
    //printf("Convert RootWmo...\n");

    fwrite(VMAP::RAW_VMAP_MAGIC, 1, 8, pOutfile);
    unsigned int nVectors = 0;
    fwrite(&nVectors,sizeof(nVectors), 1, pOutfile); // will be filled later
    fwrite(&nGroups, 4, 1, pOutfile);
    fwrite(&RootWMOID, 4, 1, pOutfile);
    return true;
}

WMOGroup::WMOGroup(const std::string &filename) :
    filename(filename), MPY2(nullptr), MOVX(nullptr), MOVT(nullptr), MOBA(nullptr), MobaEx(nullptr),
    hlq(nullptr), LiquEx(nullptr), LiquBytes(nullptr), groupName(0), descGroupName(0), mogpFlags(0),
    moprIdx(0), moprNItems(0), nBatchA(0), nBatchB(0), nBatchC(0), fogIdx(0),
    groupLiquid(0), groupWMOID(0), moba_size(0), LiquEx_size(0),
    nVertices(0), nTriangles(0), liquflags(0)
{
    memset(bbcorn1, 0, sizeof(bbcorn1));
    memset(bbcorn2, 0, sizeof(bbcorn2));
}

bool WMOGroup::open(WMORoot* rootWMO)
{
    CASCFile f(CascStorage, filename.c_str());
    if(f.isEof ())
    {
        printf("No such file.\n");
        return false;
    }
    uint32 size;
    char fourcc[5] = { };
    while (!f.isEof())
    {
        f.read(fourcc,4);
        f.read(&size, 4);
        flipcc(fourcc);
        if (!strcmp(fourcc,"MOGP")) //size specified in MOGP chunk is all the other chunks combined, adjust to read MOGP-only
            size = 68;

        size_t nextpos = f.getPos() + size;
        if (!strcmp(fourcc,"MOGP"))//header
        {
            f.read(&groupName, 4);
            f.read(&descGroupName, 4);
            f.read(&mogpFlags, 4);
            f.read(bbcorn1, 12);
            f.read(bbcorn2, 12);
            f.read(&moprIdx, 2);
            f.read(&moprNItems, 2);
            f.read(&nBatchA, 2);
            f.read(&nBatchB, 2);
            f.read(&nBatchC, 4);
            f.read(&fogIdx, 4);
            f.read(&groupLiquid, 4);
            f.read(&groupWMOID,4);

            // according to WoW.Dev Wiki:
            if (rootWMO->flags & 4)
                groupLiquid = GetLiquidTypeId(groupLiquid);
            else if (groupLiquid == 15)
                groupLiquid = 0;
            else
                groupLiquid = GetLiquidTypeId(groupLiquid + 1);

            if (groupLiquid)
                liquflags |= 2;
        }
        else if (!strcmp(fourcc,"MOPY"))
        {
            MPY2 = std::make_unique<uint16[]>(size);
            std::unique_ptr<uint8[]> MOPY = std::make_unique<uint8[]>(size);
            nTriangles = (int)size / 2;
            f.read(MOPY.get(), size);
            std::copy_n(MOPY.get(), size, MPY2.get());
        }
        else if (!strcmp(fourcc,"MPY2"))
        {
            MPY2 = std::make_unique<uint16[]>(size / 2);
            nTriangles = (int)size / 4;
            f.read(MPY2.get(), size);
        }
        else if (!strcmp(fourcc,"MOVI"))
        {
            MOVX = std::make_unique<uint32[]>(size / 2);
            std::unique_ptr<uint16[]> MOVI = std::make_unique<uint16[]>(size / 2);
            f.read(MOVI.get(), size);
            std::copy_n(MOVI.get(), size / 2, MOVX.get());
        }
        else if (!strcmp(fourcc,"MOVX"))
        {
            MOVX = std::make_unique<uint32[]>(size / 4);
            f.read(MOVX.get(), size);
        }
        else if (!strcmp(fourcc,"MOVT"))
        {
            MOVT = new float[size/4];
            f.read(MOVT, size);
            nVertices = (int)size / 12;
        }
        else if (!strcmp(fourcc,"MONR"))
        {
        }
        else if (!strcmp(fourcc,"MOTV"))
        {
        }
        else if (!strcmp(fourcc,"MOBA"))
        {
            MOBA = new uint16[size/2];
            moba_size = size/2;
            f.read(MOBA, size);
        }
        else if (!strcmp(fourcc,"MODR"))
        {
            DoodadReferences.resize(size / sizeof(uint16));
            f.read(DoodadReferences.data(), size);
        }
        else if (!strcmp(fourcc,"MLIQ"))
        {
            liquflags |= 1;
            hlq = new WMOLiquidHeader();
            f.read(hlq, sizeof(WMOLiquidHeader));
            LiquEx_size = sizeof(WMOLiquidVert) * hlq->xverts * hlq->yverts;
            LiquEx = new WMOLiquidVert[hlq->xverts * hlq->yverts];
            f.read(LiquEx, LiquEx_size);
            int nLiquBytes = hlq->xtiles * hlq->ytiles;
            LiquBytes = new char[nLiquBytes];
            f.read(LiquBytes, nLiquBytes);

            // Determine legacy liquid type
            if (!groupLiquid)
            {
                for (int i = 0; i < hlq->xtiles * hlq->ytiles; ++i)
                {
                    if ((LiquBytes[i] & 0xF) != 15)
                    {
                        groupLiquid = GetLiquidTypeId((LiquBytes[i] & 0xF) + 1);
                        break;
                    }
                }
            }

            /* std::ofstream llog("Buildings/liquid.log", ios_base::out | ios_base::app);
            llog << filename;
            llog << "\nbbox: " << bbcorn1[0] << ", " << bbcorn1[1] << ", " << bbcorn1[2] << " | " << bbcorn2[0] << ", " << bbcorn2[1] << ", " << bbcorn2[2];
            llog << "\nlpos: " << hlq->pos_x << ", " << hlq->pos_y << ", " << hlq->pos_z;
            llog << "\nx-/yvert: " << hlq->xverts << "/" << hlq->yverts << " size: " << size << " expected size: " << 30 + hlq->xverts*hlq->yverts*8 + hlq->xtiles*hlq->ytiles << std::endl;
            llog.close(); */
        }
        f.seek((int)nextpos);
    }
    f.close();
    return true;
}

int WMOGroup::ConvertToVMAPGroupWmo(FILE* output, bool preciseVectorData)
{
    fwrite(&mogpFlags,sizeof(uint32),1,output);
    fwrite(&groupWMOID,sizeof(uint32),1,output);
    // group bound
    fwrite(bbcorn1, sizeof(float), 3, output);
    fwrite(bbcorn2, sizeof(float), 3, output);
    fwrite(&liquflags,sizeof(uint32),1,output);
    int nColTriangles = 0;
    if (preciseVectorData)
    {
        char GRP[] = "GRP ";
        fwrite(GRP,1,4,output);

        int k = 0;
        int moba_batch = moba_size/12;
        MobaEx = new int[moba_batch*4];
        for(int i=8; i<moba_size; i+=12)
        {
            MobaEx[k++] = MOBA[i];
        }
        int moba_size_grp = moba_batch*4+4;
        fwrite(&moba_size_grp,4,1,output);
        fwrite(&moba_batch,4,1,output);
        fwrite(MobaEx,4,k,output);
        delete [] MobaEx;

        uint32 nIdexes = nTriangles * 3;

        if(fwrite("INDX",4, 1, output) != 1)
        {
            printf("Error while writing file nbraches ID");
            exit(0);
        }
        int wsize = sizeof(uint32) + sizeof(unsigned short) * nIdexes;
        if(fwrite(&wsize, sizeof(int), 1, output) != 1)
        {
            printf("Error while writing file wsize");
            // no need to exit?
        }
        if(fwrite(&nIdexes, sizeof(uint32), 1, output) != 1)
        {
            printf("Error while writing file nIndexes");
            exit(0);
        }
        if(nIdexes >0)
        {
            if (fwrite(MOVX.get(), sizeof(uint32), nIdexes, output) != nIdexes)
            {
                printf("Error while writing file indexarray");
                exit(0);
            }
        }

        if(fwrite("VERT",4, 1, output) != 1)
        {
            printf("Error while writing file nbraches ID");
            exit(0);
        }
        wsize = sizeof(int) + sizeof(float) * 3 * nVertices;
        if(fwrite(&wsize, sizeof(int), 1, output) != 1)
        {
            printf("Error while writing file wsize");
            // no need to exit?
        }
        if(fwrite(&nVertices, sizeof(int), 1, output) != 1)
        {
            printf("Error while writing file nVertices");
            exit(0);
        }
        if(nVertices >0)
        {
            if(fwrite(MOVT, sizeof(float)*3, nVertices, output) != nVertices)
            {
                printf("Error while writing file vectors");
                exit(0);
            }
        }

        nColTriangles = nTriangles;
    }
    else
    {
        char GRP[] = "GRP ";
        fwrite(GRP,1,4,output);
        int k = 0;
        int moba_batch = moba_size/12;
        MobaEx = new int[moba_batch*4];
        for(int i=8; i<moba_size; i+=12)
        {
            MobaEx[k++] = MOBA[i];
        }

        int moba_size_grp = moba_batch*4+4;
        fwrite(&moba_size_grp,4,1,output);
        fwrite(&moba_batch,4,1,output);
        fwrite(MobaEx,4,k,output);
        delete [] MobaEx;

        //-------INDX------------------------------------
        //-------MOPY/MPY2--------
        std::unique_ptr<uint32[]> MovxEx = std::make_unique<uint32[]>(nTriangles*3); // "worst case" size...
        std::unique_ptr<int32[]> IndexRenum = std::make_unique<int32[]>(nVertices);
        std::fill_n(IndexRenum.get(), nVertices, -1);
        for (int i=0; i<nTriangles; ++i)
        {
            // Skip no collision triangles
            bool isRenderFace = (MPY2[2 * i] & WMO_MATERIAL_RENDER) && !(MPY2[2 * i] & WMO_MATERIAL_DETAIL);
            bool isCollision = MPY2[2 * i] & WMO_MATERIAL_COLLISION || isRenderFace;

            if (!isCollision)
                continue;

            // Use this triangle
            for (int j=0; j<3; ++j)
            {
                IndexRenum[MOVX[3*i + j]] = 1;
                MovxEx[3*nColTriangles + j] = MOVX[3*i + j];
            }
            ++nColTriangles;
        }

        // assign new vertex index numbers
        uint32 nColVertices = 0;
        for (uint32 i=0; i<nVertices; ++i)
        {
            if (IndexRenum[i] == 1)
            {
                IndexRenum[i] = nColVertices;
                ++nColVertices;
            }
        }

        // translate triangle indices to new numbers
        for (int i=0; i<3*nColTriangles; ++i)
        {
            ASSERT(MovxEx[i] < nVertices);
            MovxEx[i] = IndexRenum[MovxEx[i]];
        }

        // write triangle indices
        int INDX[] = {0x58444E49, nColTriangles*6+4, nColTriangles*3};
        fwrite(INDX,4,3,output);
        fwrite(MovxEx.get(),4,nColTriangles*3,output);

        // write vertices
        uint32 VERT[] = {0x54524556u, nColVertices*3*static_cast<uint32>(sizeof(float))+4, nColVertices};// "VERT"
        int check = 3*nColVertices;
        fwrite(VERT,4,3,output);
        for (uint32 i=0; i<nVertices; ++i)
            if(IndexRenum[i] >= 0)
                check -= fwrite(MOVT+3*i, sizeof(float), 3, output);

        ASSERT(check==0);
    }

    //------LIQU------------------------
    if (liquflags & 3)
    {
        int LIQU_totalSize = sizeof(uint32);
        if (liquflags & 1)
        {
            LIQU_totalSize += sizeof(WMOLiquidHeader);
            LIQU_totalSize += LiquEx_size / sizeof(WMOLiquidVert) * sizeof(float);
            LIQU_totalSize += hlq->xtiles * hlq->ytiles;
        }
        int LIQU_h[] = { 0x5551494C, LIQU_totalSize };// "LIQU"
        fwrite(LIQU_h, 4, 2, output);

        /* std::ofstream llog("Buildings/liquid.log", ios_base::out | ios_base::app);
        llog << filename;
        llog << ":\nliquidEntry: " << liquidEntry << " type: " << hlq->type << " (root:" << rootWMO->flags << " group:" << flags << ")\n";
        llog.close(); */

        fwrite(&groupLiquid, sizeof(uint32), 1, output);
        if (liquflags & 1)
        {
            fwrite(hlq, sizeof(WMOLiquidHeader), 1, output);
            // only need height values, the other values are unknown anyway
            for (uint32 i = 0; i < LiquEx_size / sizeof(WMOLiquidVert); ++i)
                fwrite(&LiquEx[i].height, sizeof(float), 1, output);
            // todo: compress to bit field
            fwrite(LiquBytes, 1, hlq->xtiles * hlq->ytiles, output);
        }
    }

    return nColTriangles;
}

uint32 WMOGroup::GetLiquidTypeId(uint32 liquidTypeId)
{
    if (liquidTypeId < 21 && liquidTypeId)
    {
        switch (((static_cast<uint8>(liquidTypeId) - 1) & 3))
        {
            case 0: return ((mogpFlags & 0x80000) != 0) + 13;
            case 1: return 14;
            case 2: return 19;
            case 3: return 20;
            default: break;
        }
    }
    return liquidTypeId;
}

bool WMOGroup::ShouldSkip(WMORoot const* root) const
{
    // skip unreachable
    if (mogpFlags & 0x80)
        return true;

    // skip antiportals
    if (mogpFlags & 0x4000000)
        return true;

    if (groupName < int32(root->GroupNames.size()) && !strcmp(&root->GroupNames[groupName], "antiportal"))
        return true;

    return false;
}

WMOGroup::~WMOGroup()
{
    delete [] MOVT;
    delete [] MOBA;
    delete hlq;
    delete [] LiquEx;
    delete [] LiquBytes;
}

void MapObject::Extract(ADT::MODF const& mapObjDef, char const* WmoInstName, bool isGlobalWmo, uint32 mapID, uint32 originalMapId, FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache)
{
    // destructible wmo, do not dump. we can handle the vmap for these
    // in dynamic tree (gameobject vmaps)
    if ((mapObjDef.Flags & 0x1) != 0)
        return;

    //-----------add_in _dir_file----------------

    std::string tempname = Trinity::StringFormat("{}/{}", szWorkDirWmo, WmoInstName);
    FILE* input = fopen(tempname.c_str(), "r+b");

    if (!input)
    {
        printf("WMOInstance::WMOInstance: couldn't open %s\n", tempname.c_str());
        return;
    }

    fseek(input, 8, SEEK_SET); // get the correct no of vertices
    int nVertices;
    int count = fread(&nVertices, sizeof(int), 1, input);
    fclose(input);

    if (count != 1 || nVertices == 0)
        return;

    Vec3D position = fixCoords(mapObjDef.Position);
    AaBox3D bounds;
    bounds.min = fixCoords(mapObjDef.Bounds.min);
    bounds.max = fixCoords(mapObjDef.Bounds.max);

    if (isGlobalWmo)
    {
        position += Vec3D(533.33333f * 32, 533.33333f * 32, 0.0f);
        bounds += Vec3D(533.33333f * 32, 533.33333f * 32, 0.0f);
    }

    float scale = 1.0f;
    if (mapObjDef.Flags & 0x4)
        scale = mapObjDef.Scale / 1024.0f;
    uint32 uniqueId = GenerateUniqueObjectId(mapObjDef.UniqueId, 0);
    uint8 flags = MOD_HAS_BOUND;
    uint8 nameSet = mapObjDef.NameSet;
    if (mapID != originalMapId)
        flags |= MOD_PARENT_SPAWN;

    //write mapID, Flags, NameSet, UniqueId, Pos, Rot, Scale, Bound_lo, Bound_hi, name
    fwrite(&mapID, sizeof(uint32), 1, pDirfile);
    fwrite(&flags, sizeof(uint8), 1, pDirfile);
    fwrite(&nameSet, sizeof(uint8), 1, pDirfile);
    fwrite(&uniqueId, sizeof(uint32), 1, pDirfile);
    fwrite(&position, sizeof(Vec3D), 1, pDirfile);
    fwrite(&mapObjDef.Rotation, sizeof(Vec3D), 1, pDirfile);
    fwrite(&scale, sizeof(float), 1, pDirfile);
    fwrite(&bounds, sizeof(AaBox3D), 1, pDirfile);
    uint32 nlen = strlen(WmoInstName);
    fwrite(&nlen, sizeof(uint32), 1, pDirfile);
    fwrite(WmoInstName, sizeof(char), nlen, pDirfile);

    if (dirfileCache)
    {
        dirfileCache->emplace_back();
        ADTOutputCache& cacheModelData = dirfileCache->back();
        cacheModelData.Flags = flags & ~MOD_PARENT_SPAWN;
        cacheModelData.Data.resize(
            sizeof(uint8) +     // nameSet
            sizeof(uint32) +    // uniqueId
            sizeof(Vec3D) +     // position
            sizeof(Vec3D) +     // mapObjDef.Rotation
            sizeof(float) +     // scale
            sizeof(AaBox3D) +   // bounds
            sizeof(uint32) +    // nlen
            nlen);              // WmoInstName

        uint8* cacheData = cacheModelData.Data.data();
#define CACHE_WRITE(value, size, count, dest) memcpy(dest, value, size * count); dest += size * count;

        CACHE_WRITE(&nameSet, sizeof(uint8), 1, cacheData);
        CACHE_WRITE(&uniqueId, sizeof(uint32), 1, cacheData);
        CACHE_WRITE(&position, sizeof(Vec3D), 1, cacheData);
        CACHE_WRITE(&mapObjDef.Rotation, sizeof(Vec3D), 1, cacheData);
        CACHE_WRITE(&scale, sizeof(float), 1, cacheData);
        CACHE_WRITE(&bounds, sizeof(AaBox3D), 1, cacheData);
        CACHE_WRITE(&nlen, sizeof(uint32), 1, cacheData);
        CACHE_WRITE(WmoInstName, sizeof(char), nlen, cacheData);

#undef CACHE_WRITE
    }
}
