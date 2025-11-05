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
#include "Log.h"
#include "MapDefines.h"
#include "MapTree.h"
#include "MMapDefines.h"
#include "Memory.h"
#include "ModelInstance.h"
#include "StringFormat.h"
#include "Util.h"
#include "VMapManager.h"
#include <unordered_map>

namespace MMAP
{
    TerrainBuilder::TerrainBuilder(boost::filesystem::path const& inputDirectory, bool skipLiquid) :
        m_inputDirectory(inputDirectory),
        m_skipLiquid (skipLiquid)
    {
    }

    /**************************************************************************/
    void TerrainBuilder::getLoopVars(Spot portion, int& loopStart, int& loopEnd, int& loopInc)
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
    void TerrainBuilder::loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, VMAP::VMapManager* vmapManager)
    {
        if (loadMap(mapID, tileX, tileY, meshData, vmapManager, ENTIRE))
        {
            loadMap(mapID, tileX, tileY+1, meshData, vmapManager, LEFT);
            loadMap(mapID, tileX, tileY-1, meshData, vmapManager, RIGHT);
            loadMap(mapID, tileX+1, tileY, meshData, vmapManager, TOP);
            loadMap(mapID, tileX-1, tileY, meshData, vmapManager, BOTTOM);
        }
    }

    /**************************************************************************/
    bool TerrainBuilder::loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, VMAP::VMapManager* vmapManager, Spot portion)
    {
        std::string mapFileName = Trinity::StringFormat("{}/maps/{:04}_{:02}_{:02}.map", m_inputDirectory.generic_string(), mapID, tileX, tileY);

        auto mapFile = Trinity::make_unique_ptr_with_deleter<&::fclose>(fopen(mapFileName.c_str(), "rb"));
        if (!mapFile)
        {
            int32 parentMapId = vmapManager->getParentMapId(mapID);
            while (!mapFile && parentMapId != -1)
            {
                mapFileName = Trinity::StringFormat("{}/maps/{:04}_{:02}_{:02}.map", m_inputDirectory.generic_string(), parentMapId, tileX, tileY);
                mapFile.reset(fopen(mapFileName.c_str(), "rb"));
                parentMapId = vmapManager->getParentMapId(parentMapId);
            }
        }

        if (!mapFile)
            return false;

        map_fileheader fheader;
        if (fread(&fheader, sizeof(map_fileheader), 1, mapFile.get()) != 1 ||
            fheader.versionMagic != MapVersionMagic)
        {
            TC_LOG_ERROR("maps.mmapgen", "{} is the wrong version, please extract new .map files", mapFileName);
            return false;
        }

        map_heightHeader hheader;
        fseek(mapFile.get(), fheader.heightMapOffset, SEEK_SET);

        bool haveTerrain = false;
        bool haveLiquid = false;
        if (fread(&hheader, sizeof(map_heightHeader), 1, mapFile.get()) == 1)
        {
            haveTerrain = !hheader.flags.HasFlag(map_heightHeaderFlags::NoHeight);
            haveLiquid = fheader.liquidMapOffset && !m_skipLiquid;
        }

        // no data in this map file
        if (!haveTerrain && !haveLiquid)
            return false;

        // data used later
        uint8 holes[16][16][8] = { };
        uint16 liquid_entry[16][16] = { };
        map_liquidHeaderTypeFlags liquid_flags[16][16] = { };
        std::vector<int> ltriangles;
        std::vector<int> ttriangles;

        // terrain data
        if (haveTerrain)
        {
            float heightMultiplier;
            float V9[V9_SIZE_SQ], V8[V8_SIZE_SQ];
            size_t expected = V9_SIZE_SQ + V8_SIZE_SQ;

            if (hheader.flags.HasFlag(map_heightHeaderFlags::HeightAsInt8))
            {
                uint8 v9[V9_SIZE_SQ];
                uint8 v8[V8_SIZE_SQ];
                size_t count = 0;
                count += fread(v9, sizeof(uint8), V9_SIZE_SQ, mapFile.get());
                count += fread(v8, sizeof(uint8), V8_SIZE_SQ, mapFile.get());
                if (count != expected)
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} height data expected {}, read {}", mapFileName, expected, count);

                heightMultiplier = (hheader.gridMaxHeight - hheader.gridHeight) / 255;

                for (int i = 0; i < V9_SIZE_SQ; ++i)
                    V9[i] = (float)v9[i]*heightMultiplier + hheader.gridHeight;

                for (int i = 0; i < V8_SIZE_SQ; ++i)
                    V8[i] = (float)v8[i]*heightMultiplier + hheader.gridHeight;
            }
            else if (hheader.flags.HasFlag(map_heightHeaderFlags::HeightAsInt16))
            {
                uint16 v9[V9_SIZE_SQ];
                uint16 v8[V8_SIZE_SQ];
                size_t count = 0;
                count += fread(v9, sizeof(uint16), V9_SIZE_SQ, mapFile.get());
                count += fread(v8, sizeof(uint16), V8_SIZE_SQ, mapFile.get());
                if (count != expected)
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} height data expected {}, read {}", mapFileName, expected, count);

                heightMultiplier = (hheader.gridMaxHeight - hheader.gridHeight) / 65535;

                for (int i = 0; i < V9_SIZE_SQ; ++i)
                    V9[i] = (float)v9[i]*heightMultiplier + hheader.gridHeight;

                for (int i = 0; i < V8_SIZE_SQ; ++i)
                    V8[i] = (float)v8[i]*heightMultiplier + hheader.gridHeight;
            }
            else
            {
                size_t count = 0;
                count += fread(V9, sizeof(float), V9_SIZE_SQ, mapFile.get());
                count += fread(V8, sizeof(float), V8_SIZE_SQ, mapFile.get());
                if (count != expected)
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} height data expected {}, read {}", mapFileName, expected, count);
            }

            // hole data
            if (fheader.holesSize != 0)
            {
                memset(holes, 0, fheader.holesSize);
                fseek(mapFile.get(), fheader.holesOffset, SEEK_SET);
                if (fread(holes, fheader.holesSize, 1, mapFile.get()) != 1)
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} holes data expected {}, read {}", mapFileName, 1, 0);
            }

            int count = meshData.solidVerts.size() / 3;
            meshData.solidVerts.resize(meshData.solidVerts.size() + (V9_SIZE_SQ + V8_SIZE_SQ) * 3);
            float* solidVerts = meshData.solidVerts.data() + count * 3;

            float xoffset = (float(tileX)-32)*GRID_SIZE;
            float yoffset = (float(tileY)-32)*GRID_SIZE;

            for (int i = 0; i < V9_SIZE_SQ; ++i)
            {
                getHeightCoord(i, GRID_V9, xoffset, yoffset, solidVerts, V9);
                solidVerts += 3;
            }

            for (int i = 0; i < V8_SIZE_SQ; ++i)
            {
                getHeightCoord(i, GRID_V8, xoffset, yoffset, solidVerts, V8);
                solidVerts += 3;
            }

            int loopStart = 0, loopEnd = 0, loopInc = 0;
            getLoopVars(portion, loopStart, loopEnd, loopInc);
            for (int i = loopStart; i < loopEnd; i+=loopInc)
            {
                std::size_t trianglesOffset = ttriangles.size();
                ttriangles.resize(ttriangles.size() + 12);
                getHeightTriangle(i, TOP, ttriangles.data() + trianglesOffset + 0, count);
                getHeightTriangle(i, RIGHT, ttriangles.data() + trianglesOffset + 3, count);
                getHeightTriangle(i, LEFT, ttriangles.data() + trianglesOffset + 6, count);
                getHeightTriangle(i, BOTTOM, ttriangles.data() + trianglesOffset + 9, count);
            }
        }

        // liquid data
        if (haveLiquid)
        {
            map_liquidHeader lheader;
            fseek(mapFile.get(), fheader.liquidMapOffset, SEEK_SET);
            if (fread(&lheader, sizeof(map_liquidHeader), 1, mapFile.get()) != 1)
                TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} liquid header expected {}, read {}", mapFileName, 1, 0);

            std::unique_ptr<float[]> liquid_map;

            if (!lheader.flags.HasFlag(map_liquidHeaderFlags::NoType))
            {
                if (fread(liquid_entry, sizeof(liquid_entry), 1, mapFile.get()) != 1)
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} liquid id expected {}, read {}", mapFileName, 1, 0);
                if (fread(liquid_flags, sizeof(liquid_flags), 1, mapFile.get()) != 1)
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} liquid flags expected {}, read {}", mapFileName, 1, 0);
            }
            else
            {
                std::fill_n(&liquid_entry[0][0], 16 * 16, lheader.liquidType);
                std::fill_n(&liquid_flags[0][0], 16 * 16, lheader.liquidFlags);
            }

            if (!lheader.flags.HasFlag(map_liquidHeaderFlags::NoHeight))
            {
                uint32 toRead = lheader.width * lheader.height;
                liquid_map = std::make_unique<float[]>(toRead);
                if (fread(liquid_map.get(), sizeof(float), toRead, mapFile.get()) != toRead)
                {
                    TC_LOG_ERROR("maps.mmapgen", "TerrainBuilder::loadMap: Failed to read {} liquid header expected {}, read {}", mapFileName, toRead, 0);
                    liquid_map = nullptr;
                }
            }

            int count = meshData.liquidVerts.size() / 3;
            meshData.liquidVerts.resize(meshData.liquidVerts.size() + V9_SIZE_SQ * 3);
            float* liquidVerts = meshData.liquidVerts.data();
            float xoffset = (float(tileX)-32)*GRID_SIZE;
            float yoffset = (float(tileY)-32)*GRID_SIZE;

            int row, col;

            // generate coordinates
            if (!lheader.flags.HasFlag(map_liquidHeaderFlags::NoHeight))
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
                        liquidVerts[(count + i) * 3 + 0] = (yoffset + col * GRID_PART_SIZE) * -1;
                        liquidVerts[(count + i) * 3 + 1] = INVALID_MAP_LIQ_HEIGHT;
                        liquidVerts[(count + i) * 3 + 2] = (xoffset + row * GRID_PART_SIZE) * -1;
                        continue;
                    }

                    getLiquidCoord(i, j, xoffset, yoffset, &liquidVerts[(count + i) * 3], liquid_map.get());
                    j++;
                }
            }
            else
            {
                for (int i = 0; i < V9_SIZE_SQ; ++i)
                {
                    row = i / V9_SIZE;
                    col = i % V9_SIZE;
                    liquidVerts[(count + i) * 3 + 0] = (yoffset + col * GRID_PART_SIZE) * -1;
                    liquidVerts[(count + i) * 3 + 1] = lheader.liquidLevel;
                    liquidVerts[(count + i) * 3 + 2] = (xoffset + row * GRID_PART_SIZE) * -1;
                }
            }

            int loopStart = 0, loopEnd = 0, loopInc = 0;
            getLoopVars(portion, loopStart, loopEnd, loopInc);

            // generate triangles
            for (int i = loopStart; i < loopEnd; i += loopInc)
            {
                std::size_t trianglesOffset = ltriangles.size();
                ltriangles.resize(ltriangles.size() + 6);
                getHeightTriangle(i, TOP, ltriangles.data() + trianglesOffset + 0, count, true);
                getHeightTriangle(i, BOTTOM, ltriangles.data() + trianglesOffset + 3, count, true);
            }
        }

        // now that we have gathered the data, we can figure out which parts to keep:
        // liquid above ground, ground above liquid
        int loopStart = 0, loopEnd = 0, loopInc = 0, tTriCount = 4;
        bool useTerrain, useLiquid;

        float* lverts = meshData.liquidVerts.data();
        int* ltris = ltriangles.data();

        float* tverts = meshData.solidVerts.data();
        int* ttris = ttriangles.data();

        if ((ltriangles.size() + ttriangles.size()) == 0)
            return false;

        // make a copy of liquid vertices
        // used to pad right-bottom frame due to lost vertex data at extraction
        std::unique_ptr<float[]> lverts_copy;
        if (!meshData.liquidVerts.empty())
        {
            lverts_copy = std::make_unique<float[]>(meshData.liquidVerts.size());
            memcpy(lverts_copy.get(), lverts, sizeof(float)* meshData.liquidVerts.size());
        }

        getLoopVars(portion, loopStart, loopEnd, loopInc);
        for (int i = loopStart; i < loopEnd; i+=loopInc)
        {
            for (int j = 0; j < 2; ++j)
            {
                // default is true, will change to false if needed
                useTerrain = true;
                useLiquid = true;
                EnumFlag<map_liquidHeaderTypeFlags> liquidType = map_liquidHeaderTypeFlags::NoWater;
                uint8 navLiquidType = NAV_AREA_EMPTY;

                // if there is no liquid, don't use liquid
                if (meshData.liquidVerts.empty() || ltriangles.empty())
                    useLiquid = false;
                else
                {
                    liquidType = getLiquidType(i, liquid_flags);
                    if (liquidType.HasFlag(map_liquidHeaderTypeFlags::DarkWater))
                    {
                        // players should not be here, so logically neither should creatures
                        useTerrain = false;
                        useLiquid = false;
                    }
                    else if (liquidType.HasFlag(map_liquidHeaderTypeFlags::Water | map_liquidHeaderTypeFlags::Ocean))
                        navLiquidType = NAV_AREA_WATER;
                    else if (liquidType.HasFlag(map_liquidHeaderTypeFlags::Magma | map_liquidHeaderTypeFlags::Slime))
                        navLiquidType = NAV_AREA_MAGMA_SLIME;
                    else
                        useLiquid = false;
                }

                // if there is no terrain, don't use terrain
                if (ttriangles.empty())
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
                    meshData.liquidTris.insert(meshData.liquidTris.end(), &ltris[0], &ltris[3]);
                    meshData.liquidType.push_back(navLiquidType);
                }

                if (useTerrain)
                    meshData.solidTris.insert(meshData.solidTris.end(), &ttris[0], &ttris[3 * tTriCount / 2]);

                // advance to next set of triangles
                ltris += 3;
                ttris += 3*tTriCount/2;
            }
        }

        return !meshData.solidTris.empty() || !meshData.liquidTris.empty();
    }

    /**************************************************************************/
    inline void TerrainBuilder::getHeightCoord(int index, Grid grid, float xOffset, float yOffset, float* coord, float* v)
    {
        // wow coords: x, y, height
        // coord is mirroed about the horizontal axes
        switch (grid)
        {
        case GRID_V9:
            coord[0] = (yOffset + (int)(index % V9_SIZE) * GRID_PART_SIZE) * -1.f;
            coord[1] = v[index];
            coord[2] = (xOffset + (int)(index / (V9_SIZE)) * GRID_PART_SIZE) * -1.f;
            break;
        case GRID_V8:
            coord[0] = (yOffset + (int)(index % V8_SIZE) * GRID_PART_SIZE + GRID_PART_SIZE / 2.f) * -1.f;
            coord[1] = v[index];
            coord[2] = (xOffset + (int)(index / (V8_SIZE)) * GRID_PART_SIZE + GRID_PART_SIZE / 2.f) * -1.f;
            break;
        }
    }

    /**************************************************************************/
    inline void TerrainBuilder::getHeightTriangle(int square, Spot triangle, int* indices, int offset, bool liquid/* = false*/)
    {
        int rowOffset = square/V8_SIZE;
        if (!liquid)
            switch (triangle)
        {
            case TOP:
                indices[0] = V9_SIZE_SQ + square + offset;              //           0-----1 .... 128
                indices[1] = square + 1 + rowOffset + offset;           //           |\ T /|
                indices[2] = square + rowOffset + offset;               //           | \ / |
                break;                                                  //           |L 0 R| .. 127
            case LEFT:                                                  //           | / \ |
                indices[0] = square + V9_SIZE + rowOffset + offset;     //           |/ B \|
                indices[1] = V9_SIZE_SQ + square + offset;              //          129---130 ... 386
                indices[2] = square + rowOffset + offset;               //           |\   /|
                break;                                                  //           | \ / |
            case RIGHT:                                                 //           | 128 | .. 255
                indices[0] = V9_SIZE_SQ + square + offset;              //           | / \ |
                indices[1] = square + V9_SIZE + 1 + rowOffset + offset; //           |/   \|
                indices[2] = square + 1 + rowOffset + offset;           //          258---259 ... 515
                break;
            case BOTTOM:
                indices[0] = square + V9_SIZE + rowOffset + offset;
                indices[1] = square + V9_SIZE + 1 + rowOffset + offset;
                indices[2] = V9_SIZE_SQ + square + offset;
                break;
            default: break;
        }
        else
            switch (triangle)
        {                                                               //           0-----1 .... 128
            case TOP:                                                   //           |\    |
                indices[0] = square + V9_SIZE + 1 + rowOffset + offset; //           | \ T |
                indices[1] = square + 1 + rowOffset + offset;           //           |  \  |
                indices[2] = square + rowOffset + offset;               //           | B \ |
                break;                                                  //           |    \|
            case BOTTOM:                                                //          129---130 ... 386
                indices[0] = square + V9_SIZE + rowOffset + offset;     //           |\    |
                indices[1] = square + V9_SIZE + 1 + rowOffset + offset; //           | \   |
                indices[2] = square + rowOffset + offset;               //           |  \  |
                break;                                                  //           |   \ |
            default: break;                                             //           |    \|
        }                                                               //          258---259 ... 515

    }

    /**************************************************************************/
    inline void TerrainBuilder::getLiquidCoord(int index, int index2, float xOffset, float yOffset, float* coord, float* v)
    {
        // wow coords: x, y, height
        // coord is mirroed about the horizontal axes
        coord[0] = (yOffset + (int)(index % V9_SIZE) * GRID_PART_SIZE) * -1.f;
        coord[1] = v[index2];
        coord[2] = (xOffset + (int)(index / (V9_SIZE)) * GRID_PART_SIZE) * -1.f;
    }

    /**************************************************************************/
    inline bool TerrainBuilder::isHole(int square, uint8 const (&holes)[16][16][8])
    {
        int row = square / 128;
        int col = square % 128;
        int cellRow = row / 8;     // 8 squares per cell
        int cellCol = col / 8;
        int holeRow = row % 8;
        int holeCol = col % 8;

        return (holes[cellRow][cellCol][holeRow] & (1 << holeCol)) != 0;
    }

    /**************************************************************************/
    inline map_liquidHeaderTypeFlags TerrainBuilder::getLiquidType(int square, map_liquidHeaderTypeFlags const (&liquid_type)[16][16])
    {
        int row = square / 128;
        int col = square % 128;
        int cellRow = row / 8;     // 8 squares per cell
        int cellCol = col / 8;

        return liquid_type[cellRow][cellCol];
    }

    /**************************************************************************/
    bool TerrainBuilder::loadVMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, VMAP::VMapManager* vmapManager)
    {
        VMAP::LoadResult result = vmapManager->loadMap((m_inputDirectory / "vmaps").string(), mapID, tileX, tileY);
        if (result != VMAP::LoadResult::Success)
            return false;

        auto vmapTile = Trinity::make_unique_ptr_with_deleter(vmapManager, [=](VMAP::VMapManager* mgr)
        {
            mgr->unloadMap(mapID, tileX, tileY);
        });

        std::span<VMAP::ModelInstance const> models = vmapManager->getModelsOnMap(mapID);
        if (models.empty())
            return false;

        bool retval = false;

        for (VMAP::ModelInstance const& instance : models)
        {
            // model instances exist in tree even though there are instances of that model in this tile
            VMAP::WorldModel const* worldModel = instance.getWorldModel();
            if (!worldModel)
                continue;

            // now we have a model to add to the meshdata
            retval = true;

            G3D::Vector3 position = instance.iPos;
            position.x -= 32 * GRID_SIZE;
            position.y -= 32 * GRID_SIZE;
            loadVMapModel(worldModel, position, instance.GetInvRot(), instance.iScale, meshData, vmapManager);
        }

        return retval;
    }

    void TerrainBuilder::loadVMapModel(VMAP::WorldModel const* worldModel, G3D::Vector3 const& position, G3D::Matrix3 const& rotation, float scale,
        MeshData& meshData, VMAP::VMapManager* vmapManager)
    {
        std::vector<VMAP::GroupModel> const& groupModels = worldModel->getGroupModels();

        // all M2s need to have triangle indices reversed
        bool isM2 = worldModel->IsM2();

        // transform data
        for (std::vector<VMAP::GroupModel>::const_iterator it = groupModels.begin(); it != groupModels.end(); ++it)
        {
            // first handle collision mesh
            int offset = meshData.solidVerts.size() / 3;
            transformVertices(it->GetVertices(), meshData.solidVerts, scale, rotation, position);
            copyIndices(it->GetTriangles(), meshData.solidTris, offset, isM2);

            // now handle liquid data
            VMAP::WmoLiquid const* liquid = it->GetLiquid();
            if (liquid && liquid->GetFlagsStorage())
            {
                uint32 tilesX, tilesY;
                G3D::Vector3 corner;
                liquid->getPosInfo(tilesX, tilesY, corner);
                uint32 vertsX = tilesX + 1;
                uint32 vertsY = tilesY + 1;
                uint8 const* flags = liquid->GetFlagsStorage();
                float const* data = liquid->GetHeightStorage();
                uint8 type = NAV_AREA_EMPTY;

                // convert liquid type to NavTerrain
                EnumFlag<map_liquidHeaderTypeFlags> liquidFlags = map_liquidHeaderTypeFlags(vmapManager->GetLiquidFlagsPtr(liquid->GetType()));
                if (liquidFlags.HasFlag(map_liquidHeaderTypeFlags::Water | map_liquidHeaderTypeFlags::Ocean))
                    type = NAV_AREA_WATER;
                else if (liquidFlags.HasFlag(map_liquidHeaderTypeFlags::Magma | map_liquidHeaderTypeFlags::Slime))
                    type = NAV_AREA_MAGMA_SLIME;

                // indexing is weird...
                // after a lot of trial and error, this is what works:
                // vertex = y*vertsX+x
                // tile   = x*tilesY+y
                // flag   = y*tilesY+x

                uint32 liqOffset = meshData.liquidVerts.size() / 3;
                meshData.liquidVerts.resize(meshData.liquidVerts.size() + vertsX * vertsY * 3);
                float* liquidVerts = meshData.liquidVerts.data();
                for (uint32 x = 0; x < vertsX; ++x)
                {
                    for (uint32 y = 0; y < vertsY; ++y)
                    {
                        G3D::Vector3 vert = G3D::Vector3(corner.x + x * GRID_PART_SIZE, corner.y + y * GRID_PART_SIZE, data[y * vertsX + x]);
                        vert = vert * rotation * scale + position;
                        vert.x *= -1.f;
                        vert.y *= -1.f;
                        liquidVerts[(liqOffset + x * vertsY + y) * 3 + 0] = vert.y;
                        liquidVerts[(liqOffset + x * vertsY + y) * 3 + 1] = vert.z;
                        liquidVerts[(liqOffset + x * vertsY + y) * 3 + 2] = vert.x;
                    }
                }

                std::size_t liquidSquares = 0;
                for (uint32 x = 0; x < tilesX; ++x)
                {
                    for (uint32 y = 0; y < tilesY; ++y)
                    {
                        if ((flags[x + y * tilesX] & 0x0f) != 0x0f)
                        {
                            uint32 square = x * tilesY + y;
                            int idx1 = square + x;
                            int idx2 = square + 1 + x;
                            int idx3 = square + tilesY + 1 + 1 + x;
                            int idx4 = square + tilesY + 1 + x;

                            std::size_t liquidTriOffset = meshData.liquidTris.size();
                            meshData.liquidTris.resize(liquidTriOffset + 6);
                            int* liquidTris = meshData.liquidTris.data() + liquidTriOffset;

                            // top triangle
                            liquidTris[0] = idx2 + liqOffset;
                            liquidTris[1] = idx1 + liqOffset;
                            liquidTris[2] = idx3 + liqOffset;

                            // bottom triangle
                            liquidTris[3] = idx3 + liqOffset;
                            liquidTris[4] = idx1 + liqOffset;
                            liquidTris[5] = idx4 + liqOffset;

                            ++liquidSquares;
                        }
                    }
                }

                meshData.liquidType.resize(meshData.liquidType.size() + liquidSquares * 2, type);
            }
        }
    }

    /**************************************************************************/
    void TerrainBuilder::transformVertices(std::vector<G3D::Vector3> const& source, std::vector<float>& dest, float scale, G3D::Matrix3 const& rotation, G3D::Vector3 const& position)
    {
        std::size_t offset = dest.size();
        dest.resize(dest.size() + source.size() * 3);
        float* d = dest.data();
        for (std::size_t i = 0; i < source.size(); ++i)
        {
            // apply tranform, then mirror along the horizontal axes
            G3D::Vector3 v(source[i] * rotation * scale + position);
            v.x *= -1.f;
            v.y *= -1.f;
            d[offset + i * 3 + 0] = v.y;
            d[offset + i * 3 + 1] = v.z;
            d[offset + i * 3 + 2] = v.x;
        }
    }

    /**************************************************************************/
    void TerrainBuilder::copyIndices(std::vector<VMAP::MeshTriangle> const& source, std::vector<int>& dest, int offset, bool flip)
    {
        std::size_t destOffset = dest.size();
        dest.resize(dest.size() + source.size() * 3);
        int* d = dest.data();
        if (flip)
        {
            for (VMAP::MeshTriangle const& triangle : source)
            {
                d[destOffset++] = triangle.idx2 + offset;
                d[destOffset++] = triangle.idx1 + offset;
                d[destOffset++] = triangle.idx0 + offset;
            }
        }
        else
        {
            static_assert(sizeof(VMAP::MeshTriangle) == 3 * sizeof(uint32));
            std::ranges::transform(reinterpret_cast<uint32 const*>(source.data()), reinterpret_cast<uint32 const*>(source.data() + source.size()),
                dest.data() + destOffset, [&](int src) { return src + offset; });
        }
    }

    /**************************************************************************/
    void TerrainBuilder::copyIndices(std::vector<int> const& source, std::vector<int>& dest, int offset)
    {
        std::size_t destOffset = dest.size();
        dest.resize(destOffset + source.size());
        std::ranges::transform(source, dest.data() + destOffset, [&](int src) { return src + offset; });
    }

    /**************************************************************************/
    void TerrainBuilder::cleanVertices(std::vector<float>& verts, std::vector<int>& tris)
    {
        std::unordered_map<int, int> vertMap;
        vertMap.reserve(tris.size());

        int* t = tris.data();
        float* v = verts.data();

        std::vector<float> cleanVerts;
        cleanVerts.reserve(verts.size());
        int count = 0;
        // collect all the vertex indices from triangle
        for (std::size_t i = 0; i < tris.size(); ++i)
        {
            auto [vertItr, isNew] = vertMap.try_emplace(t[i], count);
            if (!isNew)
                continue;

            std::ptrdiff_t index = t[i];

            cleanVerts.insert(cleanVerts.end(), &v[index * 3], &v[index * 3 + 3]);
            count++;
        }

        verts = std::move(cleanVerts);

        // update triangles to use new indices
        for (std::size_t i = 0; i < tris.size(); ++i)
        {
            auto it = vertMap.find(t[i]);
            if (it == vertMap.end())
                continue;

            t[i] = it->second;
        }
    }

    /**************************************************************************/
    void TerrainBuilder::loadOffMeshConnections(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData, std::vector<OffMeshData> const& offMeshConnections)
    {
        for (OffMeshData const& offMeshConnection : offMeshConnections)
        {
            if (mapID != offMeshConnection.MapId || tileX != offMeshConnection.TileX || tileY != offMeshConnection.TileY)
                continue;

            meshData.offMeshConnections.push_back(offMeshConnection.From[1]);
            meshData.offMeshConnections.push_back(offMeshConnection.From[2]);
            meshData.offMeshConnections.push_back(offMeshConnection.From[0]);

            meshData.offMeshConnections.push_back(offMeshConnection.To[1]);
            meshData.offMeshConnections.push_back(offMeshConnection.To[2]);
            meshData.offMeshConnections.push_back(offMeshConnection.To[0]);

            meshData.offMeshConnectionDirs.push_back(offMeshConnection.ConnectionFlags & OFFMESH_CONNECTION_FLAG_BIDIRECTIONAL);
            meshData.offMeshConnectionRads.push_back(offMeshConnection.Radius);    // agent size equivalent
            // can be used same way as polygon flags
            meshData.offMeshConnectionsAreas.push_back(offMeshConnection.AreaId);
            meshData.offMeshConnectionsFlags.push_back(offMeshConnection.Flags);
        }
    }
}
