/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

#include "SubModel.h"

#ifdef _ASSEMBLER_DEBUG
extern FILE *::g_df;
#endif

using namespace G3D;

namespace VMAP
{

    //==========================================================
    /**
    Functions to use ModelContainer with a AABSPTree
    */
    unsigned int hashCode(const SubModel& pSm)
    {
        return pSm.getNTriangles();
    }

    void getBounds(const SubModel& pSm, G3D::AABox& pAABox)
    {
        ShortBox box = pSm.getReletiveBounds();
        pAABox.set(box.getLo().getVector3()+pSm.getBasePosition(), box.getHi().getVector3()+pSm.getBasePosition());
    }

    void getBounds(const SubModel* pSm, G3D::AABox& pAABox)
    {
        ShortBox box = pSm->getReletiveBounds();
        pAABox.set(box.getLo().getVector3()+pSm->getBasePosition(), box.getHi().getVector3()+pSm->getBasePosition());
    }

    //==========================================================
    //==========================================================
    //==========================================================
    //==========================================================
    SubModel::SubModel(unsigned int pNTriangles, TriangleBox *pTriangles, unsigned int pTrianglesPos, unsigned int pNNodes, TreeNode *pTreeNodes, unsigned int pNodesPos) :
    BaseModel(pNNodes, pTreeNodes, pNTriangles, pTriangles)
    {
        iTrianglesPos = pTrianglesPos;
        iNodesPos = pNodesPos;
        iHasInternalMemAlloc = false;
    }

    //==========================================================

    SubModel::~SubModel(void)
    {
        if(iHasInternalMemAlloc)
        {
            free();
        }
    }

    //==========================================================

    bool SubModel::operator==(const SubModel& pSm2) const
    {
        bool result = false;

        if(getNNodes() == pSm2.getNNodes() &&
            getNTriangles() == pSm2.getNTriangles() &&
            getBasePosition() == pSm2.getBasePosition() &&
            getNodesPos() == pSm2.getNodesPos() &&
            getTrianglesPos() == pSm2.getTrianglesPos())
        {
            result = true;
        }
        return result;
    }
    //==========================================================

    enum BIN_POSITIONS
    {
        BP_iNTriangles=8,
        BP_iNNodes=12,
        BP_iBasePosition=16,
        BP_iNodesPos=28,
        BP_iTrianglesPos=32,
        BP_iHasInternalMemAlloc=36,
        BP_iBox=38,
    };
    /**
    This is ugly, but due to compatibility and 64 bit support we have to do that ... sorry
    */
    void SubModel::initFromBinBlock(void *pBinBlock)
    {
        iNTriangles =  *((unsigned int *)(((char *) pBinBlock) + BP_iNTriangles));
        iNNodes =  *((unsigned int *) (((char *) pBinBlock) + BP_iNNodes));
        iBasePosition =  *((Vector3 *) (((char *) pBinBlock) + BP_iBasePosition));
        iNodesPos =  *((unsigned int *) (((char *) pBinBlock) + BP_iNodesPos));
        iTrianglesPos =  *((unsigned int *) (((char *) pBinBlock) + BP_iTrianglesPos));
        iHasInternalMemAlloc = *((bool *) (((char *) pBinBlock) + BP_iHasInternalMemAlloc));
        iBox =  *((ShortBox *) (((char *) pBinBlock) + BP_iBox));
    }

    //==========================================================

    void SubModel::countNodesAndTriangles(AABSPTree<Triangle>::Node& pNode, int &pNNodes, int &pNTriabgles)
    {
        ++pNNodes;
        pNTriabgles += pNode.valueArray.size();

        #ifdef _ASSEMBLER_DEBUG
        fprintf(::g_df, "Nodes: %d, Tris: %d\n",pNNodes, pNTriabgles);
        #endif

        if(pNode.child[0] != 0)
        {
            countNodesAndTriangles(*pNode.child[0], pNNodes, pNTriabgles);
        }
        if(pNode.child[1] != 0)
        {
            countNodesAndTriangles(*pNode.child[1], pNNodes, pNTriabgles);
        }
    }

    //==========================================================

    void SubModel::fillContainer(const AABSPTree<Triangle>::Node& pNode, int &pTreeNodePos, int &pTrianglePos, Vector3& pLo, Vector3& pHi)
    {
        TreeNode treeNode = TreeNode(pNode.valueArray.size(), pTrianglePos);
        treeNode.setSplitAxis(pNode.splitAxis);
        treeNode.setSplitLocation(pNode.splitLocation);

        int currentTreeNodePos = pTreeNodePos++;

        Vector3 lo = Vector3(inf(),inf(),inf());
        Vector3 hi = Vector3(-inf(),-inf(),-inf());

        for (int i=0; i<pNode.valueArray.size(); i++)
        {
            G3D::_AABSPTree::Handle<Triangle>* h= pNode.valueArray[i];
            Triangle t = h->value;
            TriangleBox triangleBox = TriangleBox(t.vertex(0),t.vertex(1), t.vertex(2));
            lo = lo.min(triangleBox.getBounds().getLo().getVector3());
            hi = hi.max(triangleBox.getBounds().getHi().getVector3());

            getTriangles()[pTrianglePos++] = triangleBox;
        }

        if(pNode.child[0] != 0)
        {
            treeNode.setChildPos(0, pTreeNodePos);
            fillContainer(*pNode.child[0], pTreeNodePos, pTrianglePos, lo, hi);
        }
        if(pNode.child[1] != 0)
        {
            treeNode.setChildPos(1, pTreeNodePos);
            fillContainer(*pNode.child[1], pTreeNodePos, pTrianglePos, lo, hi);
        }

        treeNode.setBounds(lo,hi);

        // get absolute bounds
        pLo = pLo.min(lo);
        pHi = pHi.max(hi);

        getTreeNodes()[currentTreeNodePos] = treeNode;
    }

    //==========================================================

    SubModel::SubModel(AABSPTree<Triangle> *pTree)
    {
        int nNodes, nTriangles;
        nNodes = nTriangles = 0;
        countNodesAndTriangles(*pTree->root, nNodes, nTriangles);

        init(nNodes, nTriangles);

        iTrianglesPos = 0;                                  // this is the global array
        iNodesPos = 0;                                      // this is the global array
        iHasInternalMemAlloc = true;
        int treeNodePos, trianglePos;
        treeNodePos = trianglePos = 0;

        Vector3 lo = Vector3(inf(),inf(),inf());
        Vector3 hi = Vector3(-inf(),-inf(),-inf());

        fillContainer(*pTree->root, treeNodePos, trianglePos, lo, hi);
        setReletiveBounds(lo, hi);
    }

    //==========================================================
#ifdef _DEBUG_VMAPS
#ifndef gBoxArray
    extern Vector3 p1,p2,p3,p4,p5,p6,p7;
    extern Array<AABox>gBoxArray;
    extern Array<G3D::Triangle>gTriArray;
    extern int gCount1, gCount2, gCount3, gCount4;
    extern bool myfound;
#endif
#endif

    //==========================================================
    void SubModel::intersect(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit, G3D::Vector3& /*pOutLocation*/, G3D::Vector3& /*pOutNormal*/) const
    {
            NodeValueAccess<TreeNode, TriangleBox> vna = NodeValueAccess<TreeNode, TriangleBox>(getTreeNodes(), getTriangles());
            IntersectionCallBack<TriangleBox> intersectCallback;
            Ray relativeRay = Ray::fromOriginAndDirection(pRay.origin - getBasePosition(), pRay.direction);
#ifdef _DEBUG_VMAPS
            //p6=getBasePosition();
            //gBoxArray.push_back(getAABoxBounds());
#endif
            getTreeNode(0).intersectRay(relativeRay, intersectCallback, pMaxDist, vna, pStopAtFirstHit, false);
    }

    //==========================================================

    bool SubModel::intersect(const G3D::Ray& pRay, float& pMaxDist) const
    {
        return BaseModel::intersect(getAABoxBounds(), pRay, pMaxDist);
    }

    //==========================================================

    template<typename RayCallback>
    void SubModel::intersectRay(const Ray& pRay, RayCallback& pIntersectCallback, float& pMaxDist, bool pStopAtFirstHit, bool intersectCallbackIsFast)
    {
        if(intersect(pRay, pMaxDist))
        {
            NodeValueAccess<TreeNode, TriangleBox> vna = NodeValueAccess<TreeNode, TriangleBox>(getTreeNodes(), getTriangles());
            IntersectionCallBack<TriangleBox> intersectCallback;
             getTreeNode(0).intersectRay(pRay, intersectCallback, pMaxDist, vna, pStopAtFirstHit, false);
        }
    }
    //==========================================================

}

