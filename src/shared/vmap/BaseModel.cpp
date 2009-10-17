/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */
#include "BaseModel.h"
#include "VMapTools.h"
using namespace G3D;
namespace VMAP
{
    //==========================================================
    void BaseModel::getMember(Array<TriangleBox>& pMembers)
    {
        for(unsigned int i=0; i<iNTriangles; i++)
        {
            pMembers.append(iTriangles[i]);
        }
    }
    //==========================================================
    BaseModel::BaseModel(unsigned int pNNodes, unsigned int  pNTriangles)
    {
        init(pNNodes, pNTriangles);
    };
    //==========================================================
    void BaseModel::init(unsigned int pNNodes, unsigned int  pNTriangles)
    {
        iNNodes = pNNodes;
        iNTriangles = pNTriangles;
        iTriangles = 0;
        iTreeNodes = 0;
        if(iNNodes >0) iTreeNodes = new TreeNode[iNNodes];
        if(iNTriangles >0) iTriangles = new TriangleBox[iNTriangles];
    }
    //==========================================================
    void BaseModel::free()
    {
        if(getTriangles() != 0) delete [] getTriangles(); setNTriangles(0);
        if(getTreeNodes() != 0) delete [] getTreeNodes(); setNNodes(0);
    }
    //==========================================================
    void BaseModel::intersect(const G3D::AABox& pBox, const G3D::Ray& pRay, float& pMaxDist, G3D::Vector3& pOutLocation, G3D::Vector3& /*pOutNormal*/) const
    {
        bool isInside = false;
        float d = MyCollisionDetection::collisionLocationForMovingPointFixedAABox(
            pRay.origin, pRay.direction,
            pBox,
            pOutLocation, isInside);
        if (!isInside && ((d > 0) && (d < pMaxDist)))
        {
            pMaxDist = d;
        }
    }
    //==========================================================
    bool BaseModel::intersect(const G3D::AABox& pBox, const G3D::Ray& pRay, float& pMaxDist) const
    {
        // See if the ray will ever hit this node or its children
        Vector3 location;
        bool alreadyInsideBounds = false;
        bool rayWillHitBounds =
            MyCollisionDetection::collisionLocationForMovingPointFixedAABox(
            pRay.origin, pRay.direction, pBox, location, alreadyInsideBounds);
        bool canHitThisNode = (alreadyInsideBounds ||
            (rayWillHitBounds && ((location - pRay.origin).squaredLength() < (pMaxDist * pMaxDist))));
        return canHitThisNode;
    }
}                                                           // VMAP

