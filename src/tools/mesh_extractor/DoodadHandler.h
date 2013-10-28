/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef DOOADHNDL_H
#define DOOADHNDL_H
#include "ObjectDataHandler.h"
#include "Utils.h"
#include "Chunk.h"
#include "Model.h"
#include <set>
#include <vector>

class DoodadDefinition : public IDefinition
{
public:
    uint32 MmidIndex;
    uint32 UniqueId;
    uint16 DecimalScale;
    uint16 Flags;

    virtual float Scale() const { return DecimalScale / 1024.0f; }

    Vector3 FixCoords(Vector3& vec)
    {
        return Vector3(vec.z, vec.x, vec.y);
    }

    void Read(FILE* stream)
    {
        int count = 0;

        count += fread(&MmidIndex, sizeof(uint32), 1, stream);
        count += fread(&UniqueId, sizeof(uint32), 1, stream);
        Position = (Vector3::Read(stream));
        Rotation = Vector3::Read(stream);
        count += fread(&DecimalScale, sizeof(uint16), 1, stream);
        count += fread(&Flags, sizeof(uint16), 1, stream);
        if (count != 4)
            printf("DoodadDefinition::Read: Failed to read some data expected 4, read %d\n", count);
    }
};

class DoodadHandler : public ObjectDataHandler
{
public:
    DoodadHandler(ADT* adt);
    ~DoodadHandler();

    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    bool IsSane() { return _definitions && _paths; }


protected:
    void ProcessInternal(MapChunk* chunk);

private:
    void ReadDoodadDefinitions(Chunk* chunk);
    void ReadDoodadPaths(Chunk* id, Chunk* data);
    void InsertModelGeometry(const DoodadDefinition& def, Model* model);
    std::set<uint32> _drawn;
    std::vector<DoodadDefinition>* _definitions;
    std::vector<std::string>* _paths;
};
#endif
