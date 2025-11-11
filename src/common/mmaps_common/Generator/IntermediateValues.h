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

#ifndef _INTERMEDIATE_VALUES_H
#define _INTERMEDIATE_VALUES_H

#include "TerrainBuilder.h"
#include <Recast.h>
#include <utility>

namespace MMAP
{
    // this class gathers all debug info holding and output
    struct IntermediateValues
    {
        rcHeightfield* heightfield;
        rcCompactHeightfield* compactHeightfield;
        rcContourSet* contours;
        rcPolyMesh* polyMesh;
        rcPolyMeshDetail* polyMeshDetail;

        IntermediateValues() : heightfield(nullptr), compactHeightfield(nullptr),
                               contours(nullptr), polyMesh(nullptr), polyMeshDetail(nullptr) {}

        IntermediateValues(IntermediateValues const&) = delete;

        IntermediateValues(IntermediateValues&& other) noexcept :
            heightfield(std::exchange(other.heightfield, nullptr)),
            compactHeightfield(std::exchange(other.compactHeightfield, nullptr)),
            contours(std::exchange(other.contours, nullptr)),
            polyMesh(std::exchange(other.polyMesh, nullptr)),
            polyMeshDetail(std::exchange(other.polyMeshDetail, nullptr))
        {
        }

        ~IntermediateValues();

        IntermediateValues& operator=(IntermediateValues const&) = delete;

        IntermediateValues& operator=(IntermediateValues&& other) noexcept
        {
            if (this != std::addressof(other))
            {
                heightfield = std::exchange(other.heightfield, nullptr);
                compactHeightfield = std::exchange(other.compactHeightfield, nullptr);
                contours = std::exchange(other.contours, nullptr);
                polyMesh = std::exchange(other.polyMesh, nullptr);
                polyMeshDetail = std::exchange(other.polyMeshDetail, nullptr);
            }
            return *this;
        }

        void writeIV(boost::filesystem::path const& outputDirectory, std::string_view fileNameSuffix, uint32 mapID, uint32 tileX, uint32 tileY);

        static void debugWrite(FILE* file, rcHeightfield const* mesh);
        static void debugWrite(FILE* file, rcCompactHeightfield const* chf);
        static void debugWrite(FILE* file, rcContourSet const* cs);
        static void debugWrite(FILE* file, rcPolyMesh const* mesh);
        static void debugWrite(FILE* file, rcPolyMeshDetail const* mesh);

        void generateObjFile(boost::filesystem::path const& outputDirectory, std::string_view fileNameSuffix, uint32 mapID, uint32 tileX, uint32 tileY, MeshData const& meshData);
    };
}
#endif
