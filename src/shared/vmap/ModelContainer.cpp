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

#include <iostream>
#include <fstream>

#include <string.h>

#include "ModelContainer.h"
#include "VMapDefinitions.h"

using namespace G3D;

namespace VMAP
{
    //==========================================================
    /**
    Functions to use ModelContainer with a AABSPTree
    */
    size_t hashCode(const ModelContainer& pMc)
    {
        return (pMc.getBasePosition() * pMc.getNTriangles()).hashCode();
    }
    //==========================================================

    ModelContainer::ModelContainer(unsigned int pNTriangles, unsigned int pNNodes, unsigned int pNSubModel) :
    BaseModel(pNNodes, pNTriangles)
    {

        iNSubModel = pNSubModel;
        iSubModel = 0;
        if(pNSubModel > 0) iSubModel = new SubModel[iNSubModel];
    }

    //==========================================================

    bool ModelContainer::operator==(const ModelContainer& pMc2) const
    {
        if (this->iNSubModel == 0 && pMc2.iNSubModel == 0 && this->iSubModel == 0 && pMc2.iSubModel == 0)
            return true;
        return this == &pMc2;
    }

    //==========================================================

    void ModelContainer::countSubModelsAndNodesAndTriangles(AABSPTree<SubModel *>::Node& pNode, int& nSubModels, int& nNodes, int& nTriangles)
    {
        // For this node we will need a TreeNode as well as for the internal nodes
        ++nNodes;

        nSubModels += pNode.valueArray.size();
        for (int i=0; i<pNode.valueArray.size(); i++)
        {
        G3D::_AABSPTree::Handle<SubModel*>* h= pNode.valueArray[i];
            SubModel *m = h->value;
            // add the internal nodes as well
            nNodes += m->getNNodes();
            nTriangles += m->getNTriangles();
        }

        if(pNode.child[0] != 0)
        {
            countSubModelsAndNodesAndTriangles(*pNode.child[0], nSubModels, nNodes, nTriangles);
        }
        if(pNode.child[1] != 0)
        {
            countSubModelsAndNodesAndTriangles(*pNode.child[1],  nSubModels, nNodes, nTriangles);
        }
    }
    //==========================================================

    void ModelContainer::fillContainer(const AABSPTree<SubModel *>::Node& pNode, int &pSubModelPos, int &pTreeNodePos, int &pTrianglePos, Vector3& pLo, Vector3& pHi, Vector3& pFinalLo, Vector3& pFinalHi)
    {
        // TreeNode for the SubModel
        TreeNode treeNode = TreeNode(pNode.valueArray.size(), pSubModelPos);
        treeNode.setSplitAxis(pNode.splitAxis);
        treeNode.setSplitLocation(pNode.splitLocation);
        int currentTreeNodePos = pTreeNodePos++;

        Vector3 lo = Vector3(inf(),inf(),inf());
        Vector3 hi = Vector3(-inf(),-inf(),-inf());

        for (int i=0; i<pNode.valueArray.size(); i++)
        {
            G3D::_AABSPTree::Handle<SubModel*>* h= pNode.valueArray[i];
            SubModel *m = h->value;

            memcpy(&getTreeNodes()[pTreeNodePos], &m->getTreeNode(0), sizeof(TreeNode) * m->getNNodes());
            memcpy(&getTriangles()[pTrianglePos], &m->getTriangle(0), sizeof(TriangleBox) * m->getNTriangles());

            SubModel newModel = SubModel(m->getNTriangles(), getTriangles(), pTrianglePos, m->getNNodes(), getTreeNodes(), pTreeNodePos);
            newModel.setReletiveBounds(m->getReletiveBounds().getLo(), m->getReletiveBounds().getHi());
            newModel.setBasePosition(m->getBasePosition());
            iSubModel[pSubModelPos++] = newModel;

            pTreeNodePos += m->getNNodes();
            pTrianglePos += m->getNTriangles();

            AABox box = m->getAABoxBounds();
            lo = lo.min(box.low());
            hi = hi.max(box.high());
            pFinalLo = pFinalLo.min(lo);
            pFinalHi = pFinalHi.max(hi);
        }
        /*
        if(pNode.valueArray.size() == 0) {
        int xxx = 0; // just for the breakpoint
        }
        */
        // get absolute bounds

        if(pNode.child[0] != 0)
        {
            treeNode.setChildPos(0, pTreeNodePos);
            fillContainer(*pNode.child[0], pSubModelPos, pTreeNodePos, pTrianglePos, lo, hi,pFinalLo,pFinalHi);
        }
        if(pNode.child[1] != 0)
        {
            treeNode.setChildPos(1, pTreeNodePos);
            fillContainer(*pNode.child[1], pSubModelPos, pTreeNodePos, pTrianglePos, lo, hi,pFinalLo,pFinalHi);
        }

        pLo = pLo.min(lo);
        pHi = pHi.max(hi);

        treeNode.setBounds(lo,hi);

        setTreeNode(treeNode, currentTreeNodePos);

    }

    //==========================================================
    /**
    Create the structure out of a AABSPTree
    */

    ModelContainer::ModelContainer(AABSPTree<SubModel *> *pTree)
    {

        int nSubModels, nNodes, nTriangles;
        nSubModels = nNodes = nTriangles = 0;
        countSubModelsAndNodesAndTriangles(*pTree->root, nSubModels, nNodes, nTriangles);

        init(nNodes, nTriangles);

        iNSubModel = nSubModels;

        iSubModel = new SubModel[iNSubModel];

        int subModelPos,treeNodePos, trianglePos;
        subModelPos = treeNodePos = trianglePos = 0;

        Vector3 lo = Vector3(inf(),inf(),inf());
        Vector3 hi = Vector3(-inf(),-inf(),-inf());
        Vector3 finalLo, finalHi;
        finalLo = lo;
        finalHi = hi;

        fillContainer(*pTree->root, subModelPos, treeNodePos, trianglePos, lo, hi, finalLo, finalHi);
        setBounds(finalLo, finalHi);
    }

    //==========================================================

    ModelContainer::~ModelContainer(void)
    {
        free();
        if(iSubModel != 0) delete [] iSubModel;
    }
    //==========================================================

    bool ModelContainer::writeFile(const char *filename)
    {
        bool result = false;
        unsigned int flags=0;
        unsigned int size;

        FILE *wf =fopen(filename,"wb");
        if(wf)
        {
            fwrite(VMAP_MAGIC,1,8,wf);
            result = true;
            if(result && fwrite("CTREE01",8,1,wf) != 1) result = false;
            if(result && fwrite(&flags,sizeof(unsigned int),1,wf) != 1) result = false;

            if(result && fwrite("POS ",4,1,wf) != 1) result = false;
            size = sizeof(float)*3;
            if(result && fwrite(&size,4,1,wf) != 1) result = false;
            Vector3 basePos = getBasePosition();
            if(result && fwrite(&basePos,sizeof(float),3,wf) != 3) result = false;

            if(result && fwrite("BOX ",4,1,wf) != 1) result = false;
            size = sizeof(float)*6;
            if(result && fwrite(&size,4,1,wf) != 1) result = false;
            Vector3 low = iBox.low();
            if(result && fwrite(&low,sizeof(float),3,wf) != 3) result = false;
            Vector3 high = iBox.high();
            if(result && fwrite(&high,sizeof(float),3,wf) != 3) result = false;

            if(result && fwrite("NODE",4,1,wf) != 1) result = false;
            size = sizeof(unsigned int)+ sizeof(TreeNode)*getNNodes();
            if(result && fwrite(&size,4,1,wf) != 1) result = false;
            unsigned int val = getNNodes();
            if(result && fwrite(&val,sizeof(unsigned int),1,wf) != 1) result = false;
            if(result && fwrite(getTreeNodes(),sizeof(TreeNode),getNNodes(),wf) != getNNodes()) result = false;

            if(result && fwrite("TRIB",4,1,wf) != 1) result = false;
            size = sizeof(unsigned int)+ sizeof(TriangleBox)*getNTriangles();
            if(result && fwrite(&size,4,1,wf) != 1) result = false;
            val = getNTriangles();
            if(result && fwrite(&val,sizeof(unsigned int),1,wf) != 1) result = false;
            if(result && fwrite(getTriangles(),sizeof(TriangleBox),getNTriangles(),wf) != getNTriangles()) result = false;

            if(result && fwrite("SUBM",4,1,wf) != 1) result = false;
            size = sizeof(unsigned int)+ sizeof(SubModel)*iNSubModel;
            if(result && fwrite(&size,4,1,wf) != 1) result = false;
            if(result && fwrite(&iNSubModel,sizeof(unsigned int),1,wf) != 1) result = false;
            if(result && fwrite(iSubModel,sizeof(SubModel),iNSubModel,wf) != iNSubModel) result = false;

            fclose(wf);
        }

        return(result);
    }

    //===============================================================

    bool ModelContainer::readFile(const char *filename)
    {
        bool result = false;
        unsigned int flags;
        unsigned int size;
        char ident[8];
        char chunk[4];
        unsigned int ival;
        FILE *rf = fopen(filename, "rb");
        if(rf)
        {
            free();

            result = true;
            char magic[8];                          // Ignore the added magic header
            fread(magic,1,8,rf);
            if(strncmp(VMAP_MAGIC,magic,8)) result = false;
            if(result && fread(ident,8,1,rf) != 1) result = false;
            if(result && fread(&flags,sizeof(unsigned int),1,rf) != 1) result = false;
            //POS
            if(result && fread(chunk,4,1,rf) != 1) result = false;
            if(result && fread(&size,4,1,rf) != 1) result = false;
            Vector3 basePos;
            if(result && fread(&basePos,sizeof(float),3,rf) != 3) result = false;
            setBasePosition(basePos);

            //---- Box
            if(result && fread(chunk,4,1,rf) != 1) result = false;
            if(result && fread(&size,4,1,rf) != 1) result = false;
            Vector3 low,high;
            if(result && fread(&low,sizeof(float),3,rf) != 3) result = false;
            if(result && fread(&high,sizeof(float),3,rf) != 3) result = false;
            setBounds(low, high);

            //---- TreeNodes
            if(result && fread(chunk,4,1,rf) != 1) result = false;
            if(result && fread(&size,4,1,rf) != 1) result = false;

            if(result && fread(&ival,sizeof(unsigned int),1,rf) != 1) result = false;
            if(result) setNNodes(ival);
            if(result) setTreeNodeArray(new TreeNode[getNNodes()]);
            if(result && fread(getTreeNodes(),sizeof(TreeNode),getNNodes(),rf) != getNNodes()) result = false;

            //---- TriangleBoxes
            if(result && fread(chunk,4,1,rf) != 1) result = false;
            if(result && fread(&size,4,1,rf) != 1) result = false;

            if(result && fread(&ival,sizeof(unsigned int),1,rf) != 1) result = false;
            setNTriangles(ival);
            if(result) setTriangleArray(new TriangleBox[getNTriangles()]);
            if(result && fread(getTriangles(),sizeof(TriangleBox),getNTriangles(),rf) != getNTriangles()) result = false;

            //---- SubModel
            if(result && fread(chunk,4,1,rf) != 1) result = false;
            if(result && fread(&size,4,1,rf) != 1) result = false;

            if(result && fread(&iNSubModel,sizeof(unsigned int),1,rf) != 1) result = false;
            if(result) iSubModel = new SubModel[iNSubModel];

            if(result)
            {
                for (unsigned int i=0; i<iNSubModel && result; ++i)
                {
                    unsigned char readBuffer[52];           // this is the size of SubModel on 32 bit systems
                    if(fread(readBuffer,sizeof(readBuffer),1,rf) != 1) result = false;
                    iSubModel[i].initFromBinBlock(readBuffer);
                    iSubModel[i].setTriangleArray(getTriangles());
                    iSubModel[i].setTreeNodeArray(getTreeNodes());
                }
            }
            fclose(rf);
        }
        return result;
    }

    //=================================================================

    size_t ModelContainer::getMemUsage()
    {
                                                            // BaseModel is included in ModelContainer
        return(iNSubModel * sizeof(SubModel) + BaseModel::getMemUsage() + sizeof(ModelContainer) - sizeof(BaseModel));
    }

    //=================================================================
#ifdef _DEBUG_VMAPS
#ifndef gBoxArray
    extern Vector3 p1,p2,p3,p4,p5,p6,p7;
    extern Array<AABox>gBoxArray;
    extern int gCount1, gCount2, gCount3, gCount4;
    extern bool myfound;
#endif
#endif

    void ModelContainer::intersect(const G3D::Ray& pRay, float& pMaxDist, bool pStopAtFirstHit, G3D::Vector3& /*pOutLocation*/, G3D::Vector3& /*pOutNormal*/) const
    {
        IntersectionCallBack<SubModel> intersectCallback;
        NodeValueAccess<TreeNode, SubModel> vna = NodeValueAccess<TreeNode, SubModel>(getTreeNodes(), iSubModel);
        Ray relativeRay = Ray::fromOriginAndDirection(pRay.origin - getBasePosition(), pRay.direction);
        iTreeNodes[0].intersectRay(pRay, intersectCallback, pMaxDist, vna, pStopAtFirstHit, false);
    }

    //==========================================================

    bool ModelContainer::intersect(const G3D::Ray& pRay, float& pMaxDist) const
    {
        return BaseModel::intersect(getAABoxBounds(), pRay, pMaxDist);
    }

    //=================================================================

    template<typename RayCallback>
    void ModelContainer::intersectRay(const G3D::Ray& pRay, RayCallback& intersectCallback, float& pMaxDist, bool pStopAtFirstHit, bool intersectCallbackIsFast)
    {
        if(intersect(pRay, pMaxDist))
        {
            NodeValueAccess<TreeNode, SubModel> vna = NodeValueAccess<TreeNode, SubModel>(getTreeNodes(), iSubModel);
            iTreeNodes[0].intersectRay(pRay, intersectCallback, distance, vna, pStopAtFirstHit, true);
        }
    }
    //=================================================================
    void getBounds(const ModelContainer& pMc, G3D::AABox& pAABox)
    {
        pAABox = pMc.getAABoxBounds();
    }

    //=================================================================

    void getBounds(const ModelContainer* pMc, G3D::AABox& pAABox)
    {
        pAABox = pMc->getAABoxBounds();
    }
    //=================================================================
}                                                           // VMAP

