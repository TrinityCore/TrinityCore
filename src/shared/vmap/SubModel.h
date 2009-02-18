/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#ifndef _SUBMODEL_H
#define _SUBMODEL_H

// load our modified version first !!
#include "AABSPTree.h"

#include "ShortVector.h"
#include "ShortBox.h"
#include "TreeNode.h"
#include "VMapTools.h"
#include "BaseModel.h"

namespace VMAP
{
    /**
    This is a balanced static BSP-Tree of triangles.
    The memory for the tree nodes and the triangles are managed by the ModelContainer.
    The exception to this is during the conversion of raw data info balanced BSP-Trees.
    During this conversion the memory management is done internally.
    */
    class SubModel : public BaseModel
    {
        private:
            unsigned int iNodesPos;
            unsigned int iTrianglesPos;
            bool iHasInternalMemAlloc;
            ShortBox iBox;
        #ifdef _DEBUG_VIEW
            G3D::Array<TriangleBox *> iDrawBox;
        #endif
        public:
            SubModel() : BaseModel(){ };

            SubModel(unsigned int pNTriangles, TriangleBox *pTriangles, unsigned int pTrianglesPos, unsigned int pNNodes, TreeNode *pTreeNodes, unsigned int pNodesPos);
            SubModel(G3D::AABSPTree<G3D::Triangle> *pTree);
            ~SubModel(void);
            //Gets a 50 byte binary block
            void initFromBinBlock(void *pBinBlock);

            void fillRenderArray(G3D::Array<TriangleBox> &pArray, const TreeNode* pTreeNode);

            void countNodesAndTriangles(G3D::AABSPTree<G3D::Triangle>::Node& pNode, int &pNNodes, int &pNTriabgles);

            void fillContainer(const G3D::AABSPTree<G3D::Triangle>::Node& pNode, int &pTreeNodePos, int &pTrianglePos, G3D::Vector3& pLo, G3D::Vector3& pHi);

            inline const ShortBox& getReletiveBounds() const { return(iBox); }

            inline void setReletiveBounds(const ShortVector& lo, const ShortVector& hi) { iBox.setLo(lo); iBox.setHi(hi); }

            inline const G3D::AABox getAABoxBounds() const { return(G3D::AABox(iBox.getLo().getVector3() + getBasePosition(), iBox.getHi().getVector3()+ getBasePosition())); }

            // get start pos bases on the global array
            inline TriangleBox const* getTriangles() const { return &BaseModel::getTriangle(iTrianglesPos); }
            inline TriangleBox      * getTriangles()       { return &BaseModel::getTriangle(iTrianglesPos); }

            // get start pos bases on the global array
            inline TreeNode const* getTreeNodes() const { return &BaseModel::getTreeNode(iNodesPos); }
            inline TreeNode      * getTreeNodes()       { return &BaseModel::getTreeNode(iNodesPos); }

            // internal method usign internal offset
            inline const TreeNode& getTreeNode(int pPos) const { return(SubModel::getTreeNodes()[pPos]); }

            // internal method usign internal offset
            inline const TriangleBox& getTriangle(int pPos) const { return(SubModel::getTriangles()[pPos]); }

            inline unsigned int getNodesPos() const { return(iNodesPos); }
            inline unsigned int getTrianglesPos() const { return(iTrianglesPos); }

            //unsigned int hashCode() { return (getBasePosition() * getNTriangles()).hashCode(); }

            void intersect(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit, G3D::Vector3& pOutLocation, G3D::Vector3& pOutNormal) const;
            bool intersect(const G3D::Ray& pRay, float& pMaxDist) const;
            template<typename RayCallback>
            void intersectRay(const G3D::Ray& ray, RayCallback& intersectCallback, float& distance, bool pStopAtFirstHit, bool intersectCallbackIsFast = false);
            bool operator==(const SubModel& pSm2) const;
            unsigned int hashCode() const { return BaseModel::getNTriangles(); }
    };

    unsigned int hashCode(const SubModel& pSm);
    void getBounds(const SubModel& pSm, G3D::AABox& pAABox);
    void getBounds(const SubModel* pSm, G3D::AABox& pAABox);
    //====================================
}                                                           // VMAP
#endif

