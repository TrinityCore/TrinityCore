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

#include "TerrainBuilder.h"
#include "MapBuilder.h"
#include "MapDefines.h"
#include "MapTree.h"
#include "ModelInstance.h"
#include "VMapFactory.h"
#include "VMapManager2.h"

// ******************************************
// Map file format defines
// ******************************************
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

#define MAP_LIQUID_TYPE_NO_WATER    0x00
#define MAP_LIQUID_TYPE_WATER       0x01
#define MAP_LIQUID_TYPE_OCEAN       0x02
#define MAP_LIQUID_TYPE_MAGMA       0x04
#define MAP_LIQUID_TYPE_SLIME       0x08
#define MAP_LIQUID_TYPE_DARK_WATER  0x10

namespace MMAP
{
    char const* MAP_VERSION_MAGIC = "v1.9";

    TerrainBuilder::TerrainBuilder(bool skipLiquid) : m_skipLiquid (skipLiquid){ }
    TerrainBuilder::~TerrainBuilder() { }

    /**************************************************************************/
    void TerrainBuilder::getLoopVars(Spot portion, int &loopStart, int &loopEnd, int &loopInc)
    {
        switch (portion)
        {
            case ENTIRE:
                loopStart = 0;
                loopEnd = V8_SIZE_SQ;
                loopInc = 1;
                break;
            case TOP:
                loopStart = 0;
                loopEnd = V8_SIZE;
                loopInc = 1;
                break;
            case LEFT:
                loopStart = 0;
                loopEnd = V8_SIZE_SQ - V8_SIZE + 1;
                loopInc = V8_SIZE;
                break;
            case RIGHT:
                loopStart = V8_SIZE - 1;
                loopEnd = V8_SIZE_SQ;
                loopInc = V8_SIZE;
                break;
            case BOTTOM:
                loopStart = V8_SIZE_SQ - V8_SIZE;
                loopEnd = V8_SIZE_SQ;
                loopInc = 1;
                break;
        }
    }

    /**************************************************************************/
    void TerrainBuilder::loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData)
    {
        if (loadMap(mapID, tileX, tileY, meshData, ENTIRE))
        {
            loadMap(mapID, tileX+1, tileY, meshData, LEFT);
            loadMap(mapID, tileX-1, tileY, meshData, RIGHT);
            loadMap(mapID, tileX, tileY+1, meshData, TOP);
            loadMap(mapID, tileX, tileY-1, meshData, BOTTOM);
        }
    }

    /**************************************************************************/
    bool TerrainBuilder::loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData, Spot portion)
    {
        char mapFileName[255];
        sprintf(mapFileName, "maps/%04u_%02u_%02u.map", mapID, tileY, tileX);

        FILE* mapFile = fopen(mapFileName, "rb");
        if (!mapFile)
        {
            int32 parentMapId = static_cast<VMapManager2*>(VMapFactory::createOrGetVMapManager())->getParentMapId(mapID);
            if (parentMapId != -1)
            {
                sprintf(mapFileName, "maps/%04d_%02u_%02u.map", parentMapId, tileY, tileX);
                mapFile = fopen(mapFileName, "rb");
            }
        }

        if (!mapFile)
            return false;

        map_fileheader fheader;
        if (fread(&fheader, sizeof(map_fileheader), 1, mapFile) != 1 ||
            fheader.versionMagic != *((uint32 const*)(MAP_VERSION_MAGIC)))
        {
            fclose(mapFile);
            printf("%s is the wrong version, please extract new .map files\n", mapFileName);
            return false;
        }

        map_heightHeader hheader;
        fseek(mapFile, fheader.heightMapOffset, SEEK_SET);

        bool haveTerrain = false;
        bool haveLiquid = false;
        if (fread(&hheader, sizeof(map_heightHeader), 1, mapFile) == 1)
        {
            haveTerrain = !(hheader.flags & MAP_HEIGHT_NO_HEIGHT);
            haveLiquid = fheader.liquidMapOffset && !m_skipLiquid;
        }

        // no data in this map file
        if (!haveTerrain && !haveLiquid)
        {
            fclose(mapFile);
            return false;
        }

        // data used later
        uint8 holes[16][16][8];
        memset(holes, 0, sizeof(holes));
        uint16 liquid_entry[16][16];
        memset(liquid_entry, 0, sizeof(liquid_entry));
        uint8 liquid_flags[16][16];
        memset(liquid_flags, 0, sizeof(liquid_flags));
        G3D::Array<int> ltriangles;
        G3D::Array<int> ttriangles;

        // terrain data
        if (haveTerrain)
        {
            float heightMultiplier;
            float V9[V9_SIZE_SQ], V8[V8_SIZE_SQ];
            int expected = V9_SIZE_SQ + V8_SIZE_SQ;

            if (hheader.flags & MAP_HEIGHT_AS_INT8)
            {
                uint8 v9[V9_SIZE_SQ];
                uint8 v8[V8_SIZE_SQ];
                int count = 0;
                count += fread(v9, sizeof(uint8), V9_SIZE_SQ, mapFile);
                count += fread(v8, sizeof(uint8), V8_SIZE_SQ, mapFile);
                if (count != expected)
                    printf("TerrainBuilder::loadMap: Failed to read some data expected %d, read %d\n", expected, count);

                heightMultiplier = (hheader.gridMaxHeight - hheader.gridHeight) / 255;

                for (int i = 0; i < V9_SIZE_SQ; ++i)
                    V9[i] = (float)v9[i]*heightMultiplier + hheader.gridHeight;

                for (int i = 0; i < V8_SIZE_SQ; ++i)
                    V8[i] = (float)v8[i]*heightMultiplier + hheader.gridHeight;
            }
            else if (hheader.flags & MAP_HEIGHT_AS_INT16)
            {
                uint16 v9[V9_SIZE_SQ];
                uint16 v8[V8_SIZE_SQ];
                int count = 0;
                count += fread(v9, sizeof(uint16), V9_SIZE_SQ, mapFile);
                count += fread(v8, sizeof(uint16), V8_SIZE_SQ, mapFile);
                if (count != expected)
                    printf("TerrainBuilder::loadMap: Failed to read some data expected %d, read %d\n", expected, count);

                heightMultiplier = (hheader.gridMaxHeight - hheader.gridHeight) / 65535;

                for (int i = 0; i < V9_SIZE_SQ; ++i)
                    V9[i] = (float)v9[i]*heightMultiplier + hheader.gridHeight;

                for (int i = 0; i < V8_SIZE_SQ; ++i)
                    V8[i] = (float)v8[i]*heightMultiplier + hheader.gridHeight;
            }
            else
            {
                int count = 0;
                count += fread(V9, sizeof(float), V9_SIZE_SQ, mapFile);
                count += fread(V8, sizeof(float), V8_SIZE_SQ, mapFile);
                if (count != expected)
                    printf("TerrainBuilder::loadMap: Failed to read some data expected %d, read %d\n", expected, count);
            }

            // hole data
            if (fheader.holesSize != 0)
            {
                memset(holes, 0, fheader.holesSize);
                fseek(mapFile, fheader.holesOffset, SEEK_SET);
                if (fread(holes, fheader.holesSize, 1, mapFile) != 1)
                    printf("TerrainBuilder::loadMap: Failed to read some data expected 1, read 0\n");
            }

            int count = meshData.solidVerts.size() / 3;
            float xoffset = (float(tileX)-32)*GRID_SIZE;
            float yoffset = (float(tileY)-32)*GRID_SIZE;

            float coord[3];

            for (int i = 0; i < V9_SIZE_SQ; ++i)
            {
                getHeightCoord(i, GRID_V9, xoffset, yoffset, coord, V9);
                meshData.solidVerts.append(coord[0]);
                meshData.solidVerts.append(coord[2]);
                meshData.solidVerts.append(coord[1]);
            }

            for (int i = 0; i < V8_SIZE_SQ; ++i)
            {
                getHeightCoord(i, GRID_V8, xoffset, yoffset, coord, V8);
                meshData.solidVerts.append(coord[0]);
                meshData.solidVerts.append(coord[2]);
                meshData.solidVerts.append(coord[1]);
            }

            int indices[] = { 0, 0, 0 };
            int loopStart = 0, loopEnd = 0, loopInc = 0;
            getLoopVars(portion, loopStart, loopEnd, loopInc);
            for (int i = loopStart; i < loopEnd; i+=loopInc)
                for (int j = TOP; j <= BOTTOM; j+=1)
                {
                    getHeightTriangle(i, Spot(j), indices);
                    ttriangles.append(indices[2] + count);
                    ttriangles.append(indices[1] + count);
                    ttriangles.append(indices[0] + count);
                }
        }

        // liquid data
        if (haveLiquid)
        {
            map_liquidHeader lheader;
            fseek(mapFile, fheader.liquidMapOffset, SEEK_SET);
            if (fread(&lheader, sizeof(map_liquidHeader), 1, mapFile) != 1)
                printf("TerrainBuilder::loadMap: Failed to read some data expected 1, read 0\n");

            float* liquid_map = nullptr;

            if (!(lheader.flags & MAP_LIQUID_NO_TYPE))
            {
                if (fread(liquid_entry, sizeof(liquid_entry), 1, mapFile) != 1)
                    printf("TerrainBuilder::loadMap: Failed to read some data expected 1, read 0\n");
                if (fread(liquid_flags, sizeof(liquid_flags), 1, mapFile) != 1)
                    printf("TerrainBuilder::loadMap: Failed to read some data expected 1, read 0\n");
            }
            else
            {
                std::fill_n(&liquid_entry[0][0], 16 * 16, lheader.liquidType);
                std::fill_n(&liquid_flags[0][0], 16 * 16, lheader.liquidFlags);
            }

            if (!(lheader.flags & MAP_LIQUID_NO_HEIGHT))
            {
                uint32 toRead = lheader.width * lheader.height;
                liquid_map = new float [toRead];
                if (fread(liquid_map, sizeof(float), toRead, mapFile) != toRead)
                {
                    printf("TerrainBuilder::loadMap: Failed to read some data expected 1, read 0\n");
                    delete[] liquid_map;
                    liquid_map = nullptr;
                }
            }

            int count = meshData.liquidVerts.size() / 3;
            float xoffset = (float(tileX)-32)*GRID_SIZE;
            float yoffset = (float(tileY)-32)*GRID_SIZE;

            float coord[3];
            int row, col;

            // generate coordinates
            if (!(lheader.flags & MAP_LIQUID_NO_HEIGHT))
            {
                int j = 0;
                for (int i = 0; i < V9_SIZE_SQ; ++i)
                {
                    row = i / V9_SIZE;
                    col = i % V9_SIZE;

                    if (row < lheader.offsetY || row >= lheader.offsetY + lheader.height ||
                        col < lheader.offsetX || col >= lheader.offsetX + lheader.width)
                    {
                        // dummy vert using invalid height
                        meshData.liquidVerts.append((xoffset+col*GRID_PART_SIZE)*-1, INVALID_MAP_LIQ_HEIGHT, (yoffset+row*GRID_PART_SIZE)*-1);
                        continue;
                    }

                    getLiquidCoord(i, j, xoffset, yoffset, coord, liquid_map);
                    meshData.liquidVerts.append(coord[0]);
                    meshData.liquidVerts.append(coord[2]);
                    meshData.liquidVerts.append(coord[1]);
                    j++;
                }
            }
            else
            {
                for (int i = 0; i < V9_SIZE_SQ; ++i)
                {
                    row = i / V9_SIZE;
                    col = i % V9_SIZE;
                    meshData.liquidVerts.append((xoffset+col*GRID_PART_SIZE)*-1, lheader.liquidLevel, (yoffset+row*GRID_PART_SIZE)*-1);
                }
            }

            delete[] liquid_map;

            int indices[] = { 0, 0, 0 };
            int loopStart = 0, loopEnd = 0, loopInc = 0, triInc = BOTTOM-TOP;
            getLoopVars(portion, loopStart, loopEnd, loopInc);

            // generate triangles
            for (int i = loopStart; i < loopEnd; i += loopInc)
            {
                for (int j = TOP; j <= BOTTOM; j += triInc)
                {
                    getHeightTriangle(i, Spot(j), indices, true);
                    ltriangles.append(indices[2] + count);
                    ltriangles.append(indices[1] + count);
                    ltriangles.append(indices[0] + count);
                }
            }
        }

        fclose(mapFile);

        // now that we have gathered the data, we can figure out which parts to keep:
        // liquid above ground, ground above liquid
        int loopStart = 0, loopEnd = 0, loopInc = 0, tTriCount = 4;
        bool useTerrain, useLiquid;

        float* lverts = meshData.liquidVerts.getCArray();
        int* ltris = ltriangles.getCArray();

        float* tverts = meshData.solidVerts.getCArray();
        int* ttris = ttriangles.getCArray();

        if ((ltriangles.size() + ttriangles.size()) == 0)
            return false;

        // make a copy of liquid vertices
        // used to pad right-bottom frame due to lost vertex data at extraction
        float* lverts_copy = NULL;
        if (meshData.liquidVerts.size())
        {
            lverts_copy = new float[meshData.liquidVerts.size()];
            memcpy(lverts_copy, lverts, sizeof(float)*meshData.liquidVerts.size());
        }

        getLoopVars(portion, loopStart, loopEnd, loopInc);
        for (int i = loopStart; i < loopEnd; i+=loopInc)
        {
            for (int j = 0; j < 2; ++j)
            {
                // default is true, will change to false if needed
                useTerrain = true;
                useLiquid = true;
                uint8 liquidType = MAP_LIQUID_TYPE_NO_WATER;

                // if there is no liquid, don't use liquid
                if (!meshData.liquidVerts.size() || !ltriangles.size())
                    useLiquid = false;
                else
                {
                    liquidType = getLiquidType(i, liquid_flags);
                    if (liquidType & MAP_LIQUID_TYPE_DARK_WATER)
                    {
                        // players should not be here, so logically neither should creatures
                        useTerrain = false;
                        useLiquid = false;
                    }
                    else if ((liquidType & (MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN)) != 0)
                        liquidType = NAV_AREA_WATER;
                    else if ((liquidType & (MAP_LIQUID_TYPE_MAGMA | MAP_LIQUID_TYPE_SLIME)) != 0)
                        liquidType = NAV_AREA_MAGMA_SLIME;
                    else
                        useLiquid = false;
                }


                // if there is no terrain, don't use terrain
                if (!ttriangles.size())
                    useTerrain = false;

                // while extracting ADT data we are losing right-bottom vertices
                // this code adds fair approximation of lost data
                if (useLiquid)
                {
                    float quadHeight = 0;
                    uint32 validCount = 0;
                    for(uint32 idx = 0; idx < 3; idx++)
                    {
                        float h = lverts_copy[ltris[idx]*3 + 1];
                        if (h != INVALID_MAP_LIQ_HEIGHT && h < INVALID_MAP_LIQ_HEIGHT_MAX)
                        {
                            quadHeight += h;
                            validCount++;
                        }
                    }

                    // update vertex height data
                    if (validCount > 0 && validCount < 3)
                    {
                        quadHeight /= validCount;
                        for(uint32 idx = 0; idx < 3; idx++)
                        {
                            float h = lverts[ltris[idx]*3 + 1];
                            if (h == INVALID_MAP_LIQ_HEIGHT || h > INVALID_MAP_LIQ_HEIGHT_MAX)
                                lverts[ltris[idx]*3 + 1] = quadHeight;
                        }
                    }

                    // no valid vertexes - don't use this poly at all
                    if (validCount == 0)
                        useLiquid = false;
                }

                // if there is a hole here, don't use the terrain
                if (useTerrain && fheader.holesSize != 0)
                    useTerrain = !isHole(i, holes);

                // we use only one terrain kind per quad - pick higher one
                if (useTerrain && useLiquid)
                {
                    float minLLevel = INVALID_MAP_LIQ_HEIGHT_MAX;
                    float maxLLevel = INVALID_MAP_LIQ_HEIGHT;
                    for(uint32 x = 0; x < 3; x++)
                    {
                        float h = lverts[ltris[x]*3 + 1];
                        if (minLLevel > h)
                            minLLevel = h;

                        if (maxLLevel < h)
                            maxLLevel = h;
                    }

                    float maxTLevel = INVALID_MAP_LIQ_HEIGHT;
                    float minTLevel = INVALID_MAP_LIQ_HEIGHT_MAX;
                    for(uint32 x = 0; x < 6; x++)
                    {
                        float h = tverts[ttris[x]*3 + 1];
                        if (maxTLevel < h)
                            maxTLevel = h;

                        if (minTLevel > h)
                            minTLevel = h;
                    }

                    // terrain under the liquid?
                    if (minLLevel > maxTLevel)
                        useTerrain = false;

                    //liquid under the terrain?
                    if (minTLevel > maxLLevel)
                        useLiquid = false;
                }

                // store the result
                if (useLiquid)
                {
                    meshData.liquidType.append(liquidType);
                    for (int k = 0; k < 3; ++k)
                        meshData.liquidTris.append(ltris[k]);
                }

                if (useTerrain)
                    for (int k = 0; k < 3*tTriCount/2; ++k)
                        meshData.solidTris.append(ttris[k]);

                // advance to next set of triangles
                ltris += 3;
                ttris += 3*tTriCount/2;
            }
        }

        if (lverts_copy)
            delete [] lverts_copy;

        return meshData.solidTris.size() || meshData.liquidTris.size();
    }

    /**************************************************************************/
    void TerrainBuilder::getHeightCoord(int index, Grid grid, float xOffset, float yOffset, float* coord, float* v)
    {
        // wow coords: x, y, height
        // coord is mirroed about the horizontal axes
        switch (grid)
        {
        case GRID_V9:
            coord[0] = (xOffset + index%(V9_SIZE)*GRID_PART_SIZE) * -1.f;
            coord[1] = (yOffset + (int)(index/(V9_SIZE))*GRID_PART_SIZE) * -1.f;
            coord[2] = v[index];
            break;
        case GRID_V8:
            coord[0] = (xOffset + index%(V8_SIZE)*GRID_PART_SIZE + GRID_PART_SIZE/2.f) * -1.f;
            coord[1] = (yOffset + (int)(index/(V8_SIZE))*GRID_PART_SIZE + GRID_PART_SIZE/2.f) * -1.f;
            coord[2] = v[index];
            break;
        }
    }

    /**************************************************************************/
    void TerrainBuilder::getHeightTriangle(int square, Spot triangle, int* indices, bool liquid/* = false*/)
    {
        int rowOffset = square/V8_SIZE;
        if (!liquid)
            switch (triangle)
        {
            case TOP:
                indices[0] = square+rowOffset;                  //           0-----1 .... 128
                indices[1] = square+1+rowOffset;                //           |\ T /|
                indices[2] = (V9_SIZE_SQ)+square;               //           | \ / |
                break;                                          //           |L 0 R| .. 127
            case LEFT:                                          //           | / \ |
                indices[0] = square+rowOffset;                  //           |/ B \|
                indices[1] = (V9_SIZE_SQ)+square;               //          129---130 ... 386
                indices[2] = square+V9_SIZE+rowOffset;          //           |\   /|
                break;                                          //           | \ / |
            case RIGHT:                                         //           | 128 | .. 255
                indices[0] = square+1+rowOffset;                //           | / \ |
                indices[1] = square+V9_SIZE+1+rowOffset;        //           |/   \|
                indices[2] = (V9_SIZE_SQ)+square;               //          258---259 ... 515
                break;
            case BOTTOM:
                indices[0] = (V9_SIZE_SQ)+square;
                indices[1] = square+V9_SIZE+1+rowOffset;
                indices[2] = square+V9_SIZE+rowOffset;
                break;
            default: break;
        }
        else
            switch (triangle)
        {                                                           //           0-----1 .... 128
            case TOP:                                               //           |\    |
                indices[0] = square+rowOffset;                      //           | \ T |
                indices[1] = square+1+rowOffset;                    //           |  \  |
                indices[2] = square+V9_SIZE+1+rowOffset;            //           | B \ |
                break;                                              //           |    \|
            case BOTTOM:                                            //          129---130 ... 386
                indices[0] = square+rowOffset;                      //           |\    |
                indices[1] = square+V9_SIZE+1+rowOffset;            //           | \   |
                indices[2] = square+V9_SIZE+rowOffset;              //           |  \  |
                break;                                              //           |   \ |
            default: break;                                         //           |    \|
        }                                                           //          258---259 ... 515

    }

    /**************************************************************************/
    void TerrainBuilder::getLiquidCoord(int index, int index2, float xOffset, float yOffset, float* coord, float* v)
    {
        // wow coords: x, y, height
        // coord is mirroed about the horizontal axes
        coord[0] = (xOffset + index%(V9_SIZE)*GRID_PART_SIZE) * -1.f;
        coord[1] = (yOffset + (int)(index/(V9_SIZE))*GRID_PART_SIZE) * -1.f;
        coord[2] = v[index2];
    }

    /**************************************************************************/
    bool TerrainBuilder::isHole(int square, uint8 const holes[16][16][8])
    {
        int row = square / 128;
        int col = square % 128;
        int cellRow = row / 8;     // 8 squares per cell
        int cellCol = col / 8;
        int holeRow = row % 8;
        int holeCol = (square - (row * 128 + cellCol * 8));

        return (holes[cellRow][cellCol][holeRow] & (1 << holeCol)) != 0;
    }

    /**************************************************************************/
    uint8 TerrainBuilder::getLiquidType(int square, const uint8 liquid_type[16][16])
    {
        int row = square / 128;
        int col = square % 128;
        int cellRow = row / 8;     // 8 squares per cell
        int cellCol = col / 8;

        return liquid_type[cellRow][cellCol];
    }

    /**************************************************************************/
    bool TerrainBuilder::loadVMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData)
    {
        VMapManager2* vmapManager = static_cast<VMapManager2*>(VMapFactory::createOrGetVMapManager());
        int result = vmapManager->loadSingleMap(mapID, "vmaps", tileX, tileY);
        bool retval = false;

        do
        {
            if (result == VMAP_LOAD_RESULT_ERROR)
                break;

            InstanceTreeMap instanceTrees;
            vmapManager->getInstanceMapTree(instanceTrees);

            if (!instanceTrees[mapID])
                break;

            ModelInstance* models = NULL;
            uint32 count = 0;
            instanceTrees[mapID]->getModelInstances(models, count);

            if (!models)
                break;

            for (uint32 i = 0; i < count; ++i)
            {
                ModelInstance instance = models[i];

                // model instances exist in tree even though there are instances of that model in this tile
                WorldModel* worldModel = instance.getWorldModel();
                if (!worldModel)
                    continue;

                // now we have a model to add to the meshdata
                retval = true;

                std::vector<GroupModel> groupModels;
                worldModel->getGroupModels(groupModels);

                // all M2s need to have triangle indices reversed
                bool isM2 = (instance.flags & MOD_M2) != 0;

                // transform data
                float scale = instance.iScale;
                G3D::Matrix3 rotation = G3D::Matrix3::fromEulerAnglesXYZ(G3D::pi()*instance.iRot.z/-180.f, G3D::pi()*instance.iRot.x/-180.f, G3D::pi()*instance.iRot.y/-180.f);
                G3D::Vector3 position = instance.iPos;
                position.x -= 32*GRID_SIZE;
                position.y -= 32*GRID_SIZE;

                for (std::vector<GroupModel>::iterator it = groupModels.begin(); it != groupModels.end(); ++it)
                {
                    std::vector<G3D::Vector3> tempVertices;
                    std::vector<G3D::Vector3> transformedVertices;
                    std::vector<MeshTriangle> tempTriangles;
                    WmoLiquid* liquid = NULL;

                    it->getMeshData(tempVertices, tempTriangles, liquid);

                    // first handle collision mesh
                    transform(tempVertices, transformedVertices, scale, rotation, position);

                    int offset = meshData.solidVerts.size() / 3;

                    copyVertices(transformedVertices, meshData.solidVerts);
                    copyIndices(tempTriangles, meshData.solidTris, offset, isM2);

                    // now handle liquid data
                    if (liquid && liquid->GetFlagsStorage())
                    {
                        std::vector<G3D::Vector3> liqVerts;
                        std::vector<int> liqTris;
                        uint32 tilesX, tilesY, vertsX, vertsY;
                        G3D::Vector3 corner;
                        liquid->getPosInfo(tilesX, tilesY, corner);
                        vertsX = tilesX + 1;
                        vertsY = tilesY + 1;
                        uint8* flags = liquid->GetFlagsStorage();
                        float* data = liquid->GetHeightStorage();
                        uint8 type = NAV_AREA_EMPTY;

                        // convert liquid type to NavTerrain
                        uint32 liquidFlags = vmapManager->GetLiquidFlagsPtr(liquid->GetType());
                        if ((liquidFlags & (MAP_LIQUID_TYPE_WATER | MAP_LIQUID_TYPE_OCEAN)) != 0)
                            type = NAV_AREA_WATER;
                        else if ((liquidFlags & (MAP_LIQUID_TYPE_MAGMA | MAP_LIQUID_TYPE_SLIME)) != 0)
                            type = NAV_AREA_MAGMA_SLIME;

                        // indexing is weird...
                        // after a lot of trial and error, this is what works:
                        // vertex = y*vertsX+x
                        // tile   = x*tilesY+y
                        // flag   = y*tilesY+x

                        G3D::Vector3 vert;
                        for (uint32 x = 0; x < vertsX; ++x)
                        {
                            for (uint32 y = 0; y < vertsY; ++y)
                            {
                                vert = G3D::Vector3(corner.x + x * GRID_PART_SIZE, corner.y + y * GRID_PART_SIZE, data[y * vertsX + x]);
                                vert = vert * rotation * scale + position;
                                vert.x *= -1.f;
                                vert.y *= -1.f;
                                liqVerts.push_back(vert);
                            }
                        }

                        int idx1, idx2, idx3, idx4;
                        uint32 square;
                        for (uint32 x = 0; x < tilesX; ++x)
                        {
                            for (uint32 y = 0; y < tilesY; ++y)
                            {
                                if ((flags[x + y * tilesX] & 0x0f) != 0x0f)
                                {
                                    square = x * tilesY + y;
                                    idx1 = square + x;
                                    idx2 = square + 1 + x;
                                    idx3 = square + tilesY + 1 + 1 + x;
                                    idx4 = square + tilesY + 1 + x;

                                    // top triangle
                                    liqTris.push_back(idx3);
                                    liqTris.push_back(idx2);
                                    liqTris.push_back(idx1);
                                    // bottom triangle
                                    liqTris.push_back(idx4);
                                    liqTris.push_back(idx3);
                                    liqTris.push_back(idx1);
                                }
                            }
                        }

                        uint32 liqOffset = meshData.liquidVerts.size() / 3;
                        for (uint32 i = 0; i < liqVerts.size(); ++i)
                            meshData.liquidVerts.append(liqVerts[i].y, liqVerts[i].z, liqVerts[i].x);

                        for (uint32 i = 0; i < liqTris.size() / 3; ++i)
                        {
                            meshData.liquidTris.append(liqTris[i * 3 + 1] + liqOffset, liqTris[i * 3 + 2] + liqOffset, liqTris[i * 3] + liqOffset);
                            meshData.liquidType.append(type);
                        }
                    }
                }
            }
        }
        while (false);

        vmapManager->unloadSingleMap(mapID, tileX, tileY);

        return retval;
    }

    /**************************************************************************/
    void TerrainBuilder::transform(std::vector<G3D::Vector3> &source, std::vector<G3D::Vector3> &transformedVertices, float scale, G3D::Matrix3 &rotation, G3D::Vector3 &position)
    {
        for (std::vector<G3D::Vector3>::iterator it = source.begin(); it != source.end(); ++it)
        {
            // apply tranform, then mirror along the horizontal axes
            G3D::Vector3 v((*it) * rotation * scale + position);
            v.x *= -1.f;
            v.y *= -1.f;
            transformedVertices.push_back(v);
        }
    }

    /**************************************************************************/
    void TerrainBuilder::copyVertices(std::vector<G3D::Vector3> &source, G3D::Array<float> &dest)
    {
        for (std::vector<G3D::Vector3>::iterator it = source.begin(); it != source.end(); ++it)
        {
            dest.push_back((*it).y);
            dest.push_back((*it).z);
            dest.push_back((*it).x);
        }
    }

    /**************************************************************************/
    void TerrainBuilder::copyIndices(std::vector<MeshTriangle> &source, G3D::Array<int> &dest, int offset, bool flip)
    {
        if (flip)
        {
            for (std::vector<MeshTriangle>::iterator it = source.begin(); it != source.end(); ++it)
            {
                dest.push_back((*it).idx2+offset);
                dest.push_back((*it).idx1+offset);
                dest.push_back((*it).idx0+offset);
            }
        }
        else
        {
            for (std::vector<MeshTriangle>::iterator it = source.begin(); it != source.end(); ++it)
            {
                dest.push_back((*it).idx0+offset);
                dest.push_back((*it).idx1+offset);
                dest.push_back((*it).idx2+offset);
            }
        }
    }

    /**************************************************************************/
    void TerrainBuilder::copyIndices(G3D::Array<int> &source, G3D::Array<int> &dest, int offset)
    {
        int* src = source.getCArray();
        for (int32 i = 0; i < source.size(); ++i)
            dest.append(src[i] + offset);
    }

    /**************************************************************************/
    void TerrainBuilder::cleanVertices(G3D::Array<float> &verts, G3D::Array<int> &tris)
    {
        std::map<int, int> vertMap;

        int* t = tris.getCArray();
        float* v = verts.getCArray();

        G3D::Array<float> cleanVerts;
        int index, count = 0;
        // collect all the vertex indices from triangle
        for (int i = 0; i < tris.size(); ++i)
        {
            if (vertMap.find(t[i]) != vertMap.end())
                continue;
            std::pair<int, int> val;
            val.first = t[i];

            index = val.first;
            val.second = count;

            vertMap.insert(val);
            cleanVerts.append(v[index * 3], v[index * 3 + 1], v[index * 3 + 2]);
            count++;
        }

        verts.fastClear();
        verts.append(cleanVerts);
        cleanVerts.clear();

        // update triangles to use new indices
        for (int i = 0; i < tris.size(); ++i)
        {
            std::map<int, int>::iterator it;
            if ((it = vertMap.find(t[i])) == vertMap.end())
                continue;

            t[i] = (*it).second;
        }

        vertMap.clear();
    }

    /**************************************************************************/
    void TerrainBuilder::loadOffMeshConnections(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData, const char* offMeshFilePath)
    {
        // no meshfile input given?
        if (offMeshFilePath == NULL)
            return;

        FILE* fp = fopen(offMeshFilePath, "rb");
        if (!fp)
        {
            printf(" loadOffMeshConnections:: input file %s not found!\n", offMeshFilePath);
            return;
        }

        // pretty silly thing, as we parse entire file and load only the tile we need
        // but we don't expect this file to be too large
        char* buf = new char[512];
        while(fgets(buf, 512, fp))
        {
            float p0[3], p1[3];
            uint32 mid, tx, ty;
            float size;
            if (sscanf(buf, "%u %u,%u (%f %f %f) (%f %f %f) %f", &mid, &tx, &ty,
                &p0[0], &p0[1], &p0[2], &p1[0], &p1[1], &p1[2], &size) != 10)
                continue;

            if (mapID == mid && tileX == tx && tileY == ty)
            {
                meshData.offMeshConnections.append(p0[1]);
                meshData.offMeshConnections.append(p0[2]);
                meshData.offMeshConnections.append(p0[0]);

                meshData.offMeshConnections.append(p1[1]);
                meshData.offMeshConnections.append(p1[2]);
                meshData.offMeshConnections.append(p1[0]);

                meshData.offMeshConnectionDirs.append(1);          // 1 - both direction, 0 - one sided
                meshData.offMeshConnectionRads.append(size);       // agent size equivalent
                // can be used same way as polygon flags
                meshData.offMeshConnectionsAreas.append((unsigned char)0xFF);
                meshData.offMeshConnectionsFlags.append((unsigned short)0xFF);  // all movement masks can make this path
            }

        }

        delete [] buf;
        fclose(fp);
    }
}
