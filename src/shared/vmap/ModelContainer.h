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

#ifndef _MODELCONTAINER_H
#define _MODELCONTAINER_H

// load our modified version first !!
#include "AABSPTree.h"

#include <G3D/AABox.h>
#include <G3D/Vector3.h>
#include <G3D/Ray.h>

#include "ShortBox.h"
#include "TreeNode.h"
#include "VMapTools.h"
#include "SubModel.h"
#include "BaseModel.h"

namespace VMAP
{
    /**
    The ModelContainer is a balanced BSP-Tree of SubModels.
    We store a map tile or an instance in one ModelContainer.
    The ModelContainer manages the memory used for the tree nodes, the SubModels and its triangles in static arrays.
    The tree nodes are used for the BSP-Tree of SubModels as well as for the BSP-Tree of triangles within one SubModel.
    The references are done by indexes within these static arrays.
    Therefore we are able to just load a binary block and do not need to mess around with memory allocation and pointers.
    */

    //=====================================================

    class ModelContainer : public BaseModel
    {
        private:
            unsigned int iNSubModel;
            SubModel *iSubModel;
            G3D::AABox iBox;

            ModelContainer (const ModelContainer& c): BaseModel(c) {}
            ModelContainer& operator=(const ModelContainer& ) {}

        public:
            ModelContainer() : BaseModel() { iNSubModel =0; iSubModel = 0; };

            // for the mainnode
            ModelContainer(unsigned int pNTriangles, unsigned int pNNodes, unsigned int pNSubModel);

            ModelContainer(G3D::AABSPTree<SubModel *> *pTree);

            ~ModelContainer(void);

            inline const void setSubModel(const SubModel& pSubModel, int pPos) { iSubModel[pPos] = pSubModel; }

            inline const SubModel& getSubModel(int pPos) const { return iSubModel[pPos]; }

            inline unsigned int getNSubModel() const { return(iNSubModel); }

            void countSubModelsAndNodesAndTriangles(G3D::AABSPTree<SubModel *>::Node& pNode, int& nSubModels, int& nNodes, int& nTriangles);

            void fillContainer(const G3D::AABSPTree<SubModel *>::Node& pNode, int &pSubModelPos, int &pTreeNodePos, int &pTrianglePos, G3D::Vector3& pLo, G3D::Vector3& pHi, G3D::Vector3& pFinalLo, G3D::Vector3& pFinalHi);

            bool readRawFile(const char *name);

            inline const G3D::AABox& getAABoxBounds() const { return(iBox); }

            inline void setBounds(const G3D::Vector3& lo, const G3D::Vector3& hi) { iBox.set(lo,hi); }

            bool writeFile(const char *filename);

            bool readFile(const char *filename);

            size_t getMemUsage();
            size_t hashCode() { return (getBasePosition() * getNTriangles()).hashCode(); }

            void intersect(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit, G3D::Vector3& pOutLocation, G3D::Vector3& pOutNormal) const;
            bool intersect(const G3D::Ray& pRay, float& pMaxDist) const;

            template<typename RayCallback>
            void intersectRay(const G3D::Ray& ray, RayCallback& intersectCallback, float& distance, bool pStopAtFirstHit, bool intersectCallbackIsFast = false);

            bool operator==(const ModelContainer& pMc2) const;
    };

    //=====================================================

    //=====================================================

    size_t hashCode(const ModelContainer& pMc);
    void getBounds(const ModelContainer& pMc, G3D::AABox& pAABox);
    void getBounds(const ModelContainer* pMc, G3D::AABox& pAABox);
}
#endif

