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

#ifndef _BASEMODEL_H_
#define _BASEMODEL_H_

#include <G3D/AABox.h>
#include <G3D/Vector3.h>

#include "ShortVector.h"
#include "ShortBox.h"
#include "TreeNode.h"

/**
A model is based on triangles. To be able to check intersection we need a BSP-Tree.
This Class holds the array of triangles as well as the management information for the BSP-Tree.
Both are stored in static array and index information is used instead of pointers.
Therefore we can load the whole object as a binary block.

The vectors are relative to a base position.
*/

namespace VMAP
{

    class BaseModel
    {
        protected:
            TriangleBox *iTriangles;
            TreeNode *iTreeNodes;
            unsigned int iNTriangles;
            unsigned int iNNodes;
            G3D::Vector3 iBasePosition;
        public:
            BaseModel() { iNTriangles = 0; iNNodes = 0; iTriangles = 0; iTreeNodes = 0;};
            BaseModel(unsigned int pNNodes  , TreeNode* pTreeNode, unsigned int  pNTriangles, TriangleBox* pTriangleBox)
            {
                iNNodes = pNNodes; iNTriangles = pNTriangles; iTriangles = pTriangleBox; iTreeNodes = pTreeNode;
            };
            BaseModel(unsigned int pNNodes, unsigned int  pNTriangles);

            // destructor does nothing ! The subclass controles the array memory and knows when to free it
            ~BaseModel() {}

            void free();
            void init(unsigned int pNNodes, unsigned int  pNTriangles);

            void getMember(G3D::Array<TriangleBox>& pMembers);

            inline const TriangleBox& getTriangle(int pPos) const { return(iTriangles[pPos]); }
            inline       TriangleBox& getTriangle(int pPos)       { return(iTriangles[pPos]); }

            inline void setTriangle(const TriangleBox& pTriangleBox, int pPos) { iTriangles[pPos] = pTriangleBox; }

            inline const TreeNode& getTreeNode(int pPos) const { return(getTreeNodes()[pPos]); }
            inline       TreeNode& getTreeNode(int pPos)       { return(getTreeNodes()[pPos]); }

            inline void setTreeNode(const TreeNode& pTreeNode, int pPos) { getTreeNodes()[pPos] = pTreeNode; }

            inline void setBasePosition(const G3D::Vector3& pBasePosition) { iBasePosition = pBasePosition; }

            inline const G3D::Vector3& getBasePosition() const { return(iBasePosition); }

            inline unsigned int getNNodes() const { return(iNNodes); }
            inline unsigned int getNTriangles() const { return(iNTriangles); }

            inline void setNNodes(unsigned int pNNodes)  { iNNodes = pNNodes; }
            inline void setNTriangles(unsigned int  pNTriangles)  { iNTriangles = pNTriangles; }

            inline void setTriangleArray(TriangleBox *pGlobalTriangleArray ) { iTriangles = pGlobalTriangleArray ; }
            inline void setTreeNodeArray(TreeNode *pGlobalTreeNodeArray ) { iTreeNodes = pGlobalTreeNodeArray ; }

            inline TriangleBox* getTriangles() const { return(iTriangles); }

            inline TreeNode* getTreeNodes() const{ return(iTreeNodes); }

            inline size_t getMemUsage() { return(iNTriangles * sizeof(TriangleBox) + iNNodes * sizeof(TreeNode) + sizeof(BaseModel)); }

            void intersect(const G3D::AABox& pBox, const G3D::Ray& pRay, float& pMaxDist, G3D::Vector3& pOutLocation, G3D::Vector3& pOutNormal) const;
            bool intersect(const G3D::AABox& pBox, const G3D::Ray& pRay, float& pMaxDist) const;
    };

}
#endif                                                      /*BASEMODEL_H_*/

