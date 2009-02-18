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

#include <G3D/Vector3.h>
#include <G3D/Triangle.h>

#include "TileAssembler.h"
#include "CoordModelMapping.h"
#include "ModelContainer.h"

#include <limits.h>
#include <string.h>

#ifdef _ASSEMBLER_DEBUG
FILE *g_df = NULL;
#endif

using namespace G3D;

namespace VMAP
{
    //=================================================================

    Vector3 ModelPosition::transform(const Vector3& pIn) const
    {
        //return(pIn);
        Vector3 out = pIn * iScale;
        out = izMatrix * out;
        out = ixMatrix * out;
        out = iyMatrix * out;
        return(out);

    }
    //=================================================================

    TileAssembler::TileAssembler(const std::string& pSrcDirName, const std::string& pDestDirName)
    {
        iCurrentUniqueNameId = 0;
        iFilterMethod = NULL;
        iSrcDir = pSrcDirName;
        iDestDir = pDestDirName;
        //mkdir(iDestDir);
        init();
    }

    //=================================================================

    TileAssembler::~TileAssembler()
    {
        delete iCoordModelMapping;
    }

    //=================================================================

    void TileAssembler::init()
    {
        iCoordModelMapping = new CoordModelMapping();
        addWorldAreaMapId(0);                               //Azeroth
        addWorldAreaMapId(1);                               //Kalimdor
        addWorldAreaMapId(530);                             //Expansion01
        addWorldAreaMapId(571);                             //Expansion02
    }
    //=================================================================

    std::string getModNameFromModPosName(const std::string& pModPosName)
    {
        size_t spos = pModPosName.find_first_of('#');
        std::string modelFileName = pModPosName.substr(0,spos);
        return(modelFileName);
    }

    //=================================================================

    unsigned int TileAssembler::getUniqueNameId(const std::string pName)
    {
        unsigned int result;

        if(!iUniqueNameIds.containsKey(pName))
        {
            ++iCurrentUniqueNameId;
            iUniqueNameIds.set(pName, iCurrentUniqueNameId);
        }
        result = iUniqueNameIds.get(pName);
        return result;
    }

    //=================================================================

    std::string TileAssembler::getDirEntryNameFromModName(unsigned int pMapId, const std::string& pModPosName)
    {
        size_t spos;
        char buffer[20];

        std::string modelFileName = getModNameFromModPosName(pModPosName);
        //std::string fext = pModPosName.substr(modelFileName.length(),pModPosName.length());
        unsigned int fextId = getUniqueNameId(pModPosName);
        sprintf(buffer, "_%07d",fextId);
        std::string fext(buffer);
        spos = modelFileName.find_last_of('/');
        std::string fname = modelFileName.substr(spos+1, modelFileName.length());
        spos = fname.find_last_of('.');
        fname = fname.substr(0,spos);
        sprintf(buffer, "%03u", pMapId);
        std::string dirEntry(buffer);
        dirEntry.append("_");
        dirEntry.append(fname);
        dirEntry.append(fext);
        dirEntry.append(".vmap");
        return(dirEntry);
    }

    //=================================================================

    void emptyArray(Array<ModelContainer*>& mc)
    {
        int no=mc.size();
        while(no > 0)
        {
            --no;
            delete mc[no];
            mc.remove(no);
        }
    }

    //=================================================================
    bool TileAssembler::convertWorld()
    {
        #ifdef _ASSEMBLER_DEBUG
        #   ifdef _DEBUG
        ::g_df = fopen("../TileAssembler_debug.txt", "wb");
        #   else
        ::g_df = fopen("../TileAssembler_release.txt", "wb");
        #   endif
        #endif

        bool result = true;
        std::string fname = iSrcDir;
        fname.append("/");
        fname.append("dir");
        iCoordModelMapping->setModelNameFilterMethod(iFilterMethod);
        iCoordModelMapping->readCoordinateMapping(fname);

        Array<unsigned int> mapIds = iCoordModelMapping->getMaps();
        if(mapIds.size() == 0)
        {
            result = false;
        }
        for(int i=0; i<mapIds.size() && result; ++i)
        {
            unsigned int mapId = mapIds[i];

            #ifdef _ASSEMBLER_DEBUG
            if(mapId == 0)                                  // "Azeroth" just for debug
            {
                for(int x=28; x<29 && result; ++x)          //debug
                {
                    for(int y=28; y<29 && result; ++y)
                    {
                        #else
                        // ignore DeeprunTram (369) it is too large for short vector and not important
                        // ignore test (13), Test (29) , development (451)
                        if(mapId != 369 && mapId != 13 && mapId != 29 && mapId != 451)
                        {
                            for(int x=0; x<66 && result; ++x)
                            {
                                for(int y=0; y<66 && result; ++y)
                                {
                                    #endif
                                    Array<ModelContainer*> mc;
                                    std::string dirname;
                                    char buffer[100];
                                    if(iCoordModelMapping->isWorldAreaMap(mapId) && x<65 && y<65)
                                    {
                                        sprintf(buffer, "%03u_%d_%d",mapId,y,x); // Let's flip x and y here
                                        dirname = std::string(buffer);
                                    }
                                    else
                                    {
                                        sprintf(buffer, "%03u",mapId);
                                        dirname = std::string(buffer);
                                    }
                                    result = fillModelContainerArray(dirname, mapId, x, y, mc);
                                    emptyArray(mc);
                                }
                            }
                        }
                    }
                    #ifdef _ASSEMBLER_DEBUG
                    if(::g_df) fclose(::g_df);
                    #endif

                    return result;
                }

                //=================================================================

                bool TileAssembler::fillModelContainerArray(const std::string& pDirFileName, unsigned int pMapId, int pXPos, int pYPos, Array<ModelContainer*>& pMC)
                {
                    bool result = true;
                    ModelContainer* modelContainer;

                    NameCollection nameCollection = iCoordModelMapping->getFilenamesForCoordinate(pMapId, pXPos, pYPos);
                    if(nameCollection.size() > 0)
                    {
                        result = false;
                        char dirfilename[500];
                        sprintf(dirfilename,"%s/%s.vmdir",iDestDir.c_str(),pDirFileName.c_str());
                        FILE *dirfile = fopen(dirfilename, "ab");
                        if(dirfile)
                        {
                            result = true;
                            char destnamebuffer[500];
                            char fullnamedestnamebuffer[500];
                            if(nameCollection.iMainFiles.size() >0)
                            {
                                sprintf(destnamebuffer,"%03u_%i_%i.vmap",pMapId, pYPos, pXPos); // flip it here too
                                std::string checkDoubleStr = std::string(dirfilename);
                                checkDoubleStr.append("##");
                                checkDoubleStr.append(std::string(destnamebuffer));
                                // Check, if same file already is in the same dir file
                                if(!iCoordModelMapping->isAlreadyProcessedSingleFile(checkDoubleStr))
                                {
                                    iCoordModelMapping->addAlreadyProcessedSingleFile(checkDoubleStr);
                                    fprintf(dirfile, "%s\n",destnamebuffer);
                                    sprintf(fullnamedestnamebuffer,"%s/%s",iDestDir.c_str(),destnamebuffer);
                                    modelContainer = processNames(nameCollection.iMainFiles, fullnamedestnamebuffer);
                                    if(modelContainer)
                                    {
                                        pMC.append(modelContainer);
                                    }
                                    else
                                    {
                                        result = false;
                                    }
                                }
                            }
                            // process the large singe files
                            int pos = 0;
                            while(result && (pos < nameCollection.iSingeFiles.size()))
                            {
                                std::string destFileName = iDestDir;
                                destFileName.append("/");
                                std::string dirEntryName = getDirEntryNameFromModName(pMapId,nameCollection.iSingeFiles[pos]);
                                std::string checkDoubleStr = std::string(dirfilename);
                                checkDoubleStr.append("##");
                                checkDoubleStr.append(nameCollection.iSingeFiles[pos]);
                                // Check, if same file already is in the same dir file
                                if(!iCoordModelMapping->isAlreadyProcessedSingleFile(checkDoubleStr))
                                {
                                    iCoordModelMapping->addAlreadyProcessedSingleFile(checkDoubleStr);
                                    fprintf(dirfile, "%s\n",dirEntryName.c_str());
                                    destFileName.append(dirEntryName);

                                    Array<std::string> positionarray;
                                    positionarray.append(nameCollection.iSingeFiles[pos]);

                                    if(!iCoordModelMapping->isAlreadyProcessedSingleFile(nameCollection.iSingeFiles[pos]))
                                    {
                                        modelContainer = processNames(positionarray, destFileName.c_str());
                                        iCoordModelMapping->addAlreadyProcessedSingleFile(nameCollection.iSingeFiles[pos]);
                                        if(modelContainer)
                                        {
                                            pMC.append(modelContainer);
                                        }
                                        else
                                        {
                                            result = false;
                                        }
                                    }
                                }
                                ++pos;
                            }
                            fclose(dirfile);
                        }
                    }
                    return(result);
                }

                //=================================================================

                void removeEntriesFromTree(AABSPTree<SubModel *>* pTree)
                {
                    Array<SubModel *> submodelArray;
                    pTree->getMembers(submodelArray);
                    int no = submodelArray.size();
                    while(no > 0)
                    {
                        --no;
                        delete submodelArray[no];
                    }
                }

                //=================================================================

                ModelContainer* TileAssembler::processNames(const Array<std::string>& pPositions, const char* pDestFileName)
                {
                    ModelContainer *modelContainer = 0;

                    Vector3 basepos = Vector3(0,0,0);
                    AABSPTree<SubModel *>* mainTree = new AABSPTree<SubModel *>();

                    int pos = 0;

                    bool result = true;
                    while(result && (pos < pPositions.size()))
                    {
                        std::string modelPosString = pPositions[pos];
                        std::string modelFileName = getModNameFromModPosName(modelPosString);

                        if(!fillModelIntoTree(mainTree, basepos, modelPosString, modelFileName))
                        {
                            result = false;
                            break;
                        }
                        ++pos;
                    }
                    if(result && mainTree->size() > 0)
                    {
                        mainTree->balance();
                        modelContainer = new ModelContainer(mainTree);
                        modelContainer->writeFile(pDestFileName);
                    }
                    removeEntriesFromTree(mainTree);

                    delete mainTree;

                    return(modelContainer);
                }

                //=================================================================
                bool TileAssembler::readRawFile(std::string& pModelFilename,  ModelPosition& pModelPosition, AABSPTree<SubModel *> *pMainTree)
                {
                    bool result = false;

                    std::string filename = iSrcDir;
                    if(filename.length() >0)
                        filename.append("/");
                    filename.append(pModelFilename);
                    FILE *rf = fopen(filename.c_str(), "rb");
                    if(!rf)
                    {
                        // depending on the extractor version, the data could be located in the root dir
                        std::string baseModelFilename = pModelFilename.substr((pModelFilename.find_first_of("/")+1),pModelFilename.length());
                        filename = iSrcDir;
                        if(filename.length() >0)
                            filename.append("/");
                        filename.append(baseModelFilename);
                        rf = fopen(filename.c_str(), "rb");
                    }
                    char ident[8];

                    int trianglecount =0;

                    #ifdef _ASSEMBLER_DEBUG
                    int startgroup = 0;                     //2;
                    int endgroup = INT_MAX;                 //2;
                    fprintf(::g_df,"-------------------------------------------------\n");
                    fprintf(::g_df,"%s\n", pModelFilename.c_str());
                    fprintf(::g_df,"-------------------------------------------------\n");
                    #else
                    int startgroup = 0;
                    int endgroup = INT_MAX;
                    #endif

                    if(rf)
                    {
                        if(fread(&ident, 8, 1, rf) != 1) { fclose(rf); return(false); }
                        if(strcmp(ident, "VMAP001") == 0)
                        {
                            // OK, do nothing
                        }
                        else if(strcmp(ident, "VMAP002") == 0)
                        {
                            // we have to read one int. This is needed during the export and we have to skip it here
                            int tempNVectors;
                            if(fread(&tempNVectors, sizeof(int), 1, rf) != 1) { fclose(rf); return(false); }

                        }
                        else
                        {
                            // wrong version
                            fclose(rf);
                            return(false);
                        }
                        G3D::uint32 groups;
                        char blockId[5];
                        blockId[4] = 0;
                        int blocksize;

                        if(fread(&groups, sizeof(G3D::uint32), 1, rf) != 1) { fclose(rf); return(false); }

                        for(int g=0;g<(int)groups;g++)
                        {
                            // group MUST NOT have more then 65536 indexes !! Array will have a problem with that !! (strange ...)
                            Array<int> tempIndexArray;
                            Array<Vector3> tempVertexArray;

                            AABSPTree<Triangle> *gtree = new AABSPTree<Triangle>();

                            G3D::uint32 flags;
                            if(fread(&flags, sizeof(G3D::uint32), 1, rf) != 1) { fclose(rf); return(false); }

                            G3D::uint32 branches;
                            if(fread(&blockId, 4, 1, rf) != 1) { fclose(rf); return(false); }
                            if(strcmp(blockId, "GRP ") != 0) { fclose(rf); return(false); }
                            if(fread(&blocksize, sizeof(int), 1, rf) != 1) { fclose(rf); return(false); }
                            if(fread(&branches, sizeof(G3D::uint32), 1, rf) != 1) { fclose(rf); return(false); }
                            for(int b=0;b<(int)branches; b++)
                            {
                                G3D::uint32 indexes;
                                // indexes for each branch (not used jet)
                                if(fread(&indexes, sizeof(G3D::uint32), 1, rf) != 1) { fclose(rf); return(false); }
                            }

                            // ---- indexes
                            if(fread(&blockId, 4, 1, rf) != 1) { fclose(rf); return(false); }
                            if(strcmp(blockId, "INDX") != 0) { fclose(rf); return(false); }
                            if(fread(&blocksize, sizeof(int), 1, rf) != 1) { fclose(rf); return(false); }
                            unsigned int nindexes;
                            if(fread(&nindexes, sizeof(G3D::uint32), 1, rf) != 1) { fclose(rf); return(false); }
                            if(nindexes >0)
                            {
                                unsigned short *indexarray = new unsigned short[nindexes*sizeof(unsigned short)];
                                if(fread(indexarray, sizeof(unsigned short), nindexes, rf) != nindexes) { fclose(rf); return(false); }
                                for(int i=0;i<(int)nindexes; i++)
                                {
                                    unsigned short val = indexarray[i];
                                    tempIndexArray.append(val);
                                }
                                delete indexarray;
                            }

                            // ---- vectors
                            if(fread(&blockId, 4, 1, rf) != 1) {fclose(rf); return(false); }
                            if(strcmp(blockId, "VERT") != 0) { fclose(rf); return(false); }
                            if(fread(&blocksize, sizeof(int), 1, rf) != 1) { fclose(rf); return(false); }
                            unsigned int nvectors;
                            if(fread(&nvectors, sizeof(int), 1, rf) != 1) { fclose(rf); return(false); }
                            float *vectorarray = 0;
                            if(nvectors >0)
                            {
                                vectorarray = new float[nvectors*sizeof(float)*3];
                                if(fread(vectorarray, sizeof(float)*3, nvectors, rf) != nvectors) { fclose(rf); return(false); }
                            }
                            // ----- liquit
                            if(flags & 1)
                            {
                                // we have liquit -> not handled yet ... skip
                                if(fread(&blockId, 4, 1, rf) != 1) { fclose(rf); return(false); }
                                if(strcmp(blockId, "LIQU") != 0) { fclose(rf); return(false); }
                                if(fread(&blocksize, sizeof(int), 1, rf) != 1) { fclose(rf); return(false); }
                                fseek(rf, blocksize, SEEK_CUR);
                            }

                            for(unsigned int i=0, indexNo=0; indexNo<nvectors; indexNo++)
                            {
                                Vector3 v = Vector3(vectorarray[i+2], vectorarray[i+1], vectorarray[i+0]);
                                i+=3;
                                v = pModelPosition.transform(v);

                                float swapy = v.y;
                                v.y = v.x;
                                v.x = swapy;

                                tempVertexArray.append(v);
                            }

                            // ---- calculate triangles
                            int rest = nindexes%3;
                            if(rest != 0)
                            {
                                nindexes -= rest;
                            }

                            for(unsigned int i=0;i<(nindexes);)
                            {
                                Triangle t = Triangle(tempVertexArray[tempIndexArray[i+2]], tempVertexArray[tempIndexArray[i+1]], tempVertexArray[tempIndexArray[i+0]] );
                                i+=3;
                                ++trianglecount;
                                if(g>= startgroup && g <= endgroup)
                                {
                                    gtree->insert(t);
                                }
                            }

                            if(vectorarray != 0)
                            {
                                delete vectorarray;
                            }

                            if(gtree->size() >0)
                            {
                                gtree->balance();
                                SubModel *sm = new SubModel(gtree);
                                #ifdef _ASSEMBLER_DEBUG
                                if(::g_df) fprintf(::g_df,"group trianglies: %d, Tris: %d, Nodes: %d, gtree.triangles: %d\n", g, sm->getNTriangles(), sm->getNNodes(), gtree->memberTable.size());
                                if(sm->getNTriangles() !=  gtree->memberTable.size())
                                {
                                    if(::g_df) fprintf(::g_df,"ERROR !!!! group trianglies: %d, Tris: %d, Nodes: %d, gtree.triangles: %d\n", g, sm->getNTriangles(), sm->getNNodes(), gtree->memberTable.size());
                                }
                                #endif
                                sm->setBasePosition(pModelPosition.iPos);
                                pMainTree->insert(sm);
                            }
                            delete gtree;
                        }
                        fclose(rf);
                        result = true;
                    }
                    return(result);
                }

                //=================================================================

                bool TileAssembler::fillModelIntoTree(AABSPTree<SubModel *> *pMainTree, const Vector3& pBasePos, std::string& pPos, std::string& pModelFilename)
                {
                    bool result = false;
                    ModelPosition modelPosition;
                    getModelPosition(pPos, modelPosition);
                    // all should be relative to object base position
                    modelPosition.moveToBasePos(pBasePos);

                    modelPosition.init();

                    if(readRawFile(pModelFilename,  modelPosition, pMainTree))
                    {
                        result = true;
                    }

                    return result;
                }

                //=================================================================
                void TileAssembler::getModelPosition(std::string& pPosString, ModelPosition& pModelPosition)
                {
                    float vposarray[3];
                    float vdirarray[3];
                    float scale;

                    size_t spos = pPosString.find_first_of('#');
                    std::string stripedPosString = pPosString.substr(spos+1,pPosString.length());

                    sscanf(stripedPosString.c_str(), "%f,%f,%f_%f,%f,%f_%f",
                        &vposarray[0],&vposarray[1],&vposarray[2],
                        &vdirarray[0],&vdirarray[1],&vdirarray[2],
                        &scale);

                    pModelPosition.iPos = Vector3(vposarray[0], vposarray[1], vposarray[2]);
                    pModelPosition.iDir = Vector3(vdirarray[0], vdirarray[1], vdirarray[2]);
                    pModelPosition.iScale = scale;

                }
                //==========================================

            }                                               // VMAP

