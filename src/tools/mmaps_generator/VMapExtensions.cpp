/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include <vector>
#include "MapTree.h"
#include "VMapManager2.h"
#include "WorldModel.h"
#include "ModelInstance.h"

namespace VMAP
{
    // Need direct access to encapsulated VMAP data, so we add functions for MMAP generator
    // maybe add MapBuilder as friend to all of the below classes would be better?

    // declared in src/shared/vmap/MapTree.h
    void StaticMapTree::getModelInstances(ModelInstance* &models, uint32 &count)
    {
        models = iTreeValues;
        count = iNTreeValues;
    }

    // declared in src/shared/vmap/VMapManager2.h
    void VMapManager2::getInstanceMapTree(InstanceTreeMap &instanceMapTree)
    {
        instanceMapTree = iInstanceMapTrees;
    }

    // declared in src/shared/vmap/WorldModel.h
    void WorldModel::getGroupModels(std::vector<GroupModel> &groupModels)
    {
        groupModels = this->groupModels;
    }

    // declared in src/shared/vmap/WorldModel.h
    void GroupModel::getMeshData(std::vector<G3D::Vector3> &vertices, std::vector<MeshTriangle> &triangles, WmoLiquid* &liquid)
    {
        vertices = this->vertices;
        triangles = this->triangles;
        liquid = iLiquid;
    }

    // declared in src/shared/vmap/ModelInstance.h
    WorldModel* ModelInstance::getWorldModel()
    {
        return iModel;
    }

    // declared in src/shared/vmap/WorldModel.h
    void WmoLiquid::getPosInfo(uint32 &tilesX, uint32 &tilesY, G3D::Vector3 &corner) const
    {
        tilesX = iTilesX;
        tilesY = iTilesY;
        corner = iCorner;
    }
}
