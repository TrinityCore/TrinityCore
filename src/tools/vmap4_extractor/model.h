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

#ifndef MODEL_H
#define MODEL_H

#include "vec3d.h"
#include "modelheaders.h"
#include <vector>

class CASCFile;
struct ADTOutputCache;
struct WMODoodadData;
namespace ADT { struct MDDF; struct MODF; }

Vec3D fixCoordSystem(Vec3D const& v);

class Model
{
private:
    void _unload()
    {
        delete[] vertices;
        delete[] indices;
        vertices = NULL;
        indices = NULL;
    }
    std::string filename;
public:
    ModelHeader header;
    Vec3D* vertices;
    uint16* indices;
    AaBox3D bounds;

    bool open();
    bool ConvertToVMAPModel(char const* outfilename);

    Model(std::string& filename);
    ~Model() { _unload(); }
};

namespace Doodad
{
    void Extract(ADT::MDDF const& doodadDef, char const* ModelInstName, uint32 mapID, uint32 originalMapId,
        FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache);

    void ExtractSet(WMODoodadData const& doodadData, ADT::MODF const& wmo, bool isGlobalWmo, uint32 mapID, uint32 originalMapId,
        FILE* pDirfile, std::vector<ADTOutputCache>* dirfileCache);
}

#endif
