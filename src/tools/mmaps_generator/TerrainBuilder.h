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

#include "PathCommon.h"
#include "WorldModel.h"

#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>

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

    struct MeshData
    {
        G3D::Array<float> solidVerts;
        G3D::Array<int> solidTris;

        G3D::Array<float> liquidVerts;
        G3D::Array<int> liquidTris;
        G3D::Array<uint8> liquidType;

        // offmesh connection data
        G3D::Array<float> offMeshConnections;   // [p0y,p0z,p0x,p1y,p1z,p1x] - per connection
        G3D::Array<float> offMeshConnectionRads;
        G3D::Array<unsigned char> offMeshConnectionDirs;
        G3D::Array<unsigned char> offMeshConnectionsAreas;
        G3D::Array<unsigned short> offMeshConnectionsFlags;
    };

    class TerrainBuilder
    {
        public:
            TerrainBuilder(bool skipLiquid);
            ~TerrainBuilder();

            void loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData);
            bool loadVMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData);
            void loadOffMeshConnections(uint32 mapID, uint32 tileX, uint32 tileY, MeshData& meshData, char const* offMeshFilePath);

            bool usesLiquids() const { return !m_skipLiquid; }

            // vert and triangle methods
            static void transform(std::vector<G3D::Vector3> &original, std::vector<G3D::Vector3> &transformed,
                float scale, G3D::Matrix3 &rotation, G3D::Vector3 &position);
            static void copyVertices(std::vector<G3D::Vector3> &source, G3D::Array<float> &dest);
            static void copyIndices(std::vector<VMAP::MeshTriangle> &source, G3D::Array<int> &dest, int offest, bool flip);
            static void copyIndices(G3D::Array<int> &src, G3D::Array<int> &dest, int offset);
            static void cleanVertices(G3D::Array<float> &verts, G3D::Array<int> &tris);
        private:
            /// Loads a portion of a map's terrain
            bool loadMap(uint32 mapID, uint32 tileX, uint32 tileY, MeshData &meshData, Spot portion);

            /// Sets loop variables for selecting only certain parts of a map's terrain
            void getLoopVars(Spot portion, int &loopStart, int &loopEnd, int &loopInc);

            /// Controls whether liquids are loaded
            bool m_skipLiquid;

            /// Load the map terrain from file
            bool loadHeightMap(uint32 mapID, uint32 tileX, uint32 tileY, G3D::Array<float> &vertices, G3D::Array<int> &triangles, Spot portion);

            /// Get the vector coordinate for a specific position
            void getHeightCoord(int index, Grid grid, float xOffset, float yOffset, float* coord, float* v);

            /// Get the triangle's vector indices for a specific position
            void getHeightTriangle(int square, Spot triangle, int* indices, bool liquid = false);

            /// Determines if the specific position's triangles should be rendered
            bool isHole(int square, uint8 const holes[16][16][8]);

            /// Get the liquid vector coordinate for a specific position
            void getLiquidCoord(int index, int index2, float xOffset, float yOffset, float* coord, float* v);

            /// Get the liquid type for a specific position
            uint8 getLiquidType(int square, const uint8 liquid_type[16][16]);

            // hide parameterless and copy constructor
            TerrainBuilder() = delete;
            TerrainBuilder(TerrainBuilder const& tb) = delete;
    };
}

#endif
