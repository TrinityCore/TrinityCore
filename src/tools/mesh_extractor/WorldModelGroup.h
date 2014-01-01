/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef WMOGROUP_H
#define WMOGROUP_H
#include "ChunkedData.h"
#include "Utils.h"

class WorldModelGroup
{
public:
    WorldModelGroup(std::string path, int groupIndex);
    WorldModelGroup(Stream* stream, std::string path, int groupIndex);
    ~WorldModelGroup();
    void Load(std::string& path);

    ChunkedData* Data;
    ChunkedData* SubData;
    int GroupIndex;
    std::string Name;
    WMOGroupHeader Header;

    std::vector<uint8> TriangleFlags;
    std::vector<uint8> TriangleMaterials;
    std::vector<Triangle<uint16> > Triangles;
    std::vector<Vector3> Vertices;
    std::vector<Vector3> Normals;
    // @ToDo: Research.
    uint16* MOBA;
    uint32 MOBALength;

    bool HasLiquidData;
    bool IsBad;
    LiquidHeader LiquidDataHeader;
    LiquidData LiquidDataGeometry;
private:
    void ReadNormals();
    void ReadLiquid();
    void ReadVertices();
    void ReadTriangles();
    void ReadMaterials();
    void ReadHeader();
    void ReadBatches();
};
#endif