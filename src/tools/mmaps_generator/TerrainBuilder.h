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

#ifndef _MMAP_TERRAIN_BUILDER_H
#define _MMAP_TERRAIN_BUILDER_H

#include "WorldModel.h"
#include <G3D/Vector3.h>

namespace VMAP
{
class VMapManager;
}

enum class map_liquidHeaderTypeFlags : uint8;

namespace MMAP
{
    enum Spot
    {
        TOP     = 1,
        RIGHT   = 2,
        LEFT    = 3,
        BOTTOM  = 4,
        ENTIRE  = 5
    };

    enum Grid
    {
        GRID_V8,
        GRID_V9
    };

    static const int V9_SIZE = 129;
    static const int V9_SIZE_SQ = V9_SIZE*V9_SIZE;
    static const int V8_SIZE = 128;
    static const int V8_SIZE_SQ = V8_SIZE*V8_SIZE;
    static const float GRID_SIZE = 533.3333f;
    static const float GRID_PART_SIZE = GRID_SIZE/V8_SIZE;

    // see contrib/extractor/system.cpp, CONF_use_minHeight
    static const float INVALID_MAP_LIQ_HEIGHT = -2000.f;
    static const float INVALID_MAP_LIQ_HEIGHT_MAX = 5000.0f;

    // see following files:
    // contrib/extractor/system.cpp
    // src/game/Map.cpp

    struct OffMeshData
    {
        uint32 MapId;
        uint32 TileX;
        uint32 TileY;
        float From[3];
        float To[3];
        bool Bidirectional;
        float Radius;
        uint8 AreaId;
        uint16 Flags;
    };

    struct MeshData
    {
        std::vector<float> solidVerts;
        std::vector<int> solidTris;

        std::vector<float> liquidVerts;
        std::vector<int> liquidTris;
        std::vector<uint8> liquidType;

        // offmesh connection data
        std::vector<float> offMeshConnections;  // [p0y,p0z,p0x,p1y,p1z,p1x] - per connection
        std::vector<float> offMeshConnectionRads;
        std::vector<unsigned char> offMeshConnectionDirs;
        std::vector<unsigned char> offMeshConnectionsAreas;
        std::vector<unsigned short> offMeshConnectionsFlags;
    };

    class TerrainBuilder
    {
        public:
            explicit TerrainBuilder(bool skipLiquid);

            void loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, VMAP::VMapManager* vmapManager);
            bool loadVMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, VMAP::VMapManager* vmapManager);
            void loadOffMeshConnections(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, std::vector<OffMeshData> const& offMeshConnections);

            bool usesLiquids() const { return !m_skipLiquid; }

            // vert and triangle methods
            static void transformVertices(std::vector<G3D::Vector3> const& source, std::vector<float>& dest,
                float scale, G3D::Matrix3 const& rotation, G3D::Vector3 const& position);
            static void copyIndices(std::vector<VMAP::MeshTriangle> const& source, std::vector<int>& dest, int offset, bool flip);
            static void copyIndices(std::vector<int> const& source, std::vector<int>& dest, int offset);
            static void cleanVertices(std::vector<float>& verts, std::vector<int>& tris);
        private:
            /// Loads a portion of a map's terrain
            bool loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, VMAP::VMapManager* vmapManager, Spot portion);

            /// Sets loop variables for selecting only certain parts of a map's terrain
            static void getLoopVars(Spot portion, int& loopStart, int& loopEnd, int& loopInc);

            /// Controls whether liquids are loaded
            bool m_skipLiquid;

            /// Get the vector coordinate for a specific position
            static void getHeightCoord(int index, Grid grid, float xOffset, float yOffset, float* coord, float* v);

            /// Get the triangle's vector indices for a specific position
            static void getHeightTriangle(int square, Spot triangle, int* indices, int offset, bool liquid = false);

            /// Determines if the specific position's triangles should be rendered
            static bool isHole(int square, uint8 const (&holes)[16][16][8]);

            /// Get the liquid vector coordinate for a specific position
            static void getLiquidCoord(int index, int index2, float xOffset, float yOffset, float* coord, float* v);

            /// Get the liquid type for a specific position
            static map_liquidHeaderTypeFlags getLiquidType(int square, map_liquidHeaderTypeFlags const (&liquid_type)[16][16]);
    };
}

#endif
