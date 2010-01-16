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

#include "VMapManager.h"
#include "VMapDefinitions.h"

using namespace G3D;

namespace VMAP
{

    //=========================================================

    VMapManager::VMapManager()
    {
#ifdef _VMAP_LOG_DEBUG
        iCommandLogger.setFileName("vmapcmd.log");
        iCommandLogger.setResetFile();
#endif
    }

    //=========================================================

    VMapManager::~VMapManager(void)
    {
        Array<unsigned int > keyArray = iInstanceMapTrees.getKeys();
        for (int i=0; i<keyArray.size(); ++i)
        {
            delete iInstanceMapTrees.get(keyArray[i]);
            iInstanceMapTrees.remove(keyArray[i]);
        }
    }

    //=========================================================

    Vector3 VMapManager::convertPositionToInternalRep(float x, float y, float z) const
    {
        float pos[3];
        pos[0] = y;
        pos[1] = z;
        pos[2] = x;
        double full = 64.0*533.33333333;
        double mid = full/2.0;
        pos[0] = full- (pos[0] + mid);
        pos[2] = full- (pos[2] + mid);

        return(Vector3(pos));
    }

    //=========================================================

    Vector3 VMapManager::convertPositionToTrinityRep(float x, float y, float z) const
    {
        float pos[3];
        pos[0] = z;
        pos[1] = x;
        pos[2] = y;
        double full = 64.0*533.33333333;
        double mid = full/2.0;
        pos[0] = -((mid+pos[0])-full);
        pos[1] = -((mid+pos[1])-full);

        return(Vector3(pos));
    }
    //=========================================================

    std::string VMapManager::getDirFileName(unsigned int pMapId, int x, int y) const
    {
        char name[FILENAMEBUFFER_SIZE];

        sprintf(name, "%03u_%d_%d%s",pMapId, x, y, DIR_FILENAME_EXTENSION);
        return(std::string(name));
    }

    //=========================================================
    std::string VMapManager::getDirFileName(unsigned int pMapId) const
    {
        char name[FILENAMEBUFFER_SIZE];

        sprintf(name, "%03d%s",pMapId, DIR_FILENAME_EXTENSION);
        return(std::string(name));
    }
    //=========================================================
    // remote last return or LF
    void chomp(std::string& str)
    {
        while(str.length() >0)
        {
            char lc = str[str.length()-1];
            if(lc == '\r' || lc == '\n')
            {
                str = str.substr(0,str.length()-1);
            }
            else
            {
                break;
            }
        }
    }
    //=========================================================

    void chompAndTrim(std::string& str)
    {
        while(str.length() >0)
        {
            char lc = str[str.length()-1];
            if(lc == '\r' || lc == '\n' || lc == ' ' || lc == '"' || lc == '\'')
            {
                str = str.substr(0,str.length()-1);
            }
            else
            {
                break;
            }
        }
        while(str.length() >0)
        {
            char lc = str[0];
            if(lc == ' ' || lc == '"' || lc == '\'')
            {
                str = str.substr(1,str.length()-1);
            }
            else
            {
                break;
            }
        }
    }

    //=========================================================
    // result false, if no more id are found

    bool getNextMapId(const std::string& pString, unsigned int& pStartPos, unsigned int& pId)
    {
        bool result = false;
        unsigned int i;
        for (i=pStartPos; i<pString.size(); ++i)
        {
            if(pString[i] == ',')
            {
                break;
            }
        }
        if(i>pStartPos)
        {
            std::string idString = pString.substr(pStartPos, i-pStartPos);
            pStartPos = i+1;
            chompAndTrim(idString);
            pId = atoi(idString.c_str());
            result = true;
        }
        return(result);
    }

    //=========================================================
    /**
    Block maps from being used.
    parameter: String of map ids. Delimiter = ","
    e.g.: "0,1,590"
    */

    void VMapManager::preventMapsFromBeingUsed(const char* pMapIdString)
    {
        if(pMapIdString != NULL)
        {
            unsigned int pos =0;
            unsigned int id;
            std::string confString(pMapIdString);
            chompAndTrim(confString);
            while(getNextMapId(confString, pos, id))
            {
                iIgnoreMapIds.set(id, true);
            }
        }
    }

    //=========================================================

    int VMapManager::loadMap(const char* pBasePath, unsigned int pMapId, int x, int y)
    {
        int result = VMAP_LOAD_RESULT_IGNORED;
        if(isMapLoadingEnabled() && !iIgnoreMapIds.containsKey(pMapId))
        {
            bool loaded = _loadMap(pBasePath, pMapId, x, y, false);
            if(!loaded)
            {
                // if we can't load the map it might be splitted into tiles. Try that one and store the result
                loaded = _loadMap(pBasePath, pMapId, x, y, true);
                if(loaded)
                {
                    iMapsSplitIntoTiles.set(pMapId, true);
                }
            }
            if(loaded)
            {
                result = VMAP_LOAD_RESULT_OK;
                // just for debugging
#ifdef _VMAP_LOG_DEBUG
                Command c = Command();
                c.fillLoadTileCmd(x, y, pMapId);
                iCommandLogger.appendCmd(c);
#endif
            }
            else
            {
                result = VMAP_LOAD_RESULT_ERROR;
            }
        }
        return result;
    }

    //=========================================================
    // load one tile (internal use only)

    bool VMapManager::_loadMap(const char* pBasePath, unsigned int pMapId, int x, int y, bool pForceTileLoad)
    {
        bool result = false;
        std::string dirFileName;
        if(pForceTileLoad || iMapsSplitIntoTiles.containsKey(pMapId))
        {
            dirFileName = getDirFileName(pMapId,x,y);
        }
        else
        {
            dirFileName = getDirFileName(pMapId);
        }
        MapTree* instanceTree;
        if(!iInstanceMapTrees.containsKey(pMapId))
        {
            instanceTree = new MapTree(pBasePath);
            iInstanceMapTrees.set(pMapId, instanceTree);
        }
        else
            instanceTree = iInstanceMapTrees.get(pMapId);

        unsigned int mapTileIdent = MAP_TILE_IDENT(x,y);
        result = instanceTree->loadMap(dirFileName, mapTileIdent);
        if(!result)                                         // remove on fail
        {
            if(instanceTree->size() == 0)
            {
                iInstanceMapTrees.remove(pMapId);
                delete instanceTree;
            }
        }
        return(result);
    }

    //=========================================================

    bool VMapManager::_existsMap(const std::string& pBasePath, unsigned int pMapId, int x, int y, bool pForceTileLoad)
    {
        bool result = false;
        std::string dirFileName;
        if(pForceTileLoad || iMapsSplitIntoTiles.containsKey(pMapId))
        {
            dirFileName = getDirFileName(pMapId,x,y);
        }
        else
        {
            dirFileName = getDirFileName(pMapId);
        }
        std::string fb = pBasePath + dirFileName;
        FILE* df = fopen(fb.c_str(), "rb");
        if(df)
        {
            char lineBuffer[FILENAMEBUFFER_SIZE];
            if (fgets(lineBuffer, FILENAMEBUFFER_SIZE-1, df) != 0)
            {
                std::string name = std::string(lineBuffer);
                chomp(name);
                if(name.length() >1)
                {
                    std::string fb2 = pBasePath + name;
                    FILE* df2 = fopen(fb2.c_str(), "rb");
                    if(df2)
                    {
                        char magic[8];
                        fread(magic,1,8,df2);
                        if(!strncmp(VMAP_MAGIC,magic,8))
                            result = true;
                        fclose(df2);
                    }
                }
            }
            fclose(df);
        }
        return result;
    }

    //=========================================================

    bool VMapManager::existsMap(const char* pBasePath, unsigned int pMapId, int x, int y)
    {
        std::string basePath = std::string(pBasePath);
        if(basePath.length() > 0 && (basePath[basePath.length()-1] != '/' || basePath[basePath.length()-1] != '\\'))
        {
            basePath.append("/");
        }
        bool found = _existsMap(basePath, pMapId, x, y, false);
        if(!found)
        {
            // if we can't load the map it might be splitted into tiles. Try that one and store the result
            found = _existsMap(basePath, pMapId, x, y, true);
            if(found)
            {
                iMapsSplitIntoTiles.set(pMapId, true);
            }
        }
        return found;
    }

    //=========================================================

    void VMapManager::unloadMap(unsigned int pMapId, int x, int y)
    {
        _unloadMap(pMapId, x, y);

#ifdef _VMAP_LOG_DEBUG
        Command c = Command();
        c.fillUnloadTileCmd(pMapId, x,y);
        iCommandLogger.appendCmd(c);
#endif
    }

    //=========================================================

    void VMapManager::_unloadMap(unsigned int  pMapId, int x, int y)
    {
        if(iInstanceMapTrees.containsKey(pMapId))
        {
            MapTree* instanceTree = iInstanceMapTrees.get(pMapId);
            std::string dirFileName;
            if(iMapsSplitIntoTiles.containsKey(pMapId))
            {
                dirFileName = getDirFileName(pMapId,x,y);
            }
            else
            {
                dirFileName = getDirFileName(pMapId);
            }
            unsigned int mapTileIdent = MAP_TILE_IDENT(x,y);
            instanceTree->unloadMap(dirFileName, mapTileIdent);
            if(instanceTree->size() == 0)
            {
                iInstanceMapTrees.remove(pMapId);
                delete instanceTree;
            }
        }
    }

    //=========================================================

    void VMapManager::unloadMap(unsigned int pMapId)
    {
        if(iInstanceMapTrees.containsKey(pMapId))
        {
            MapTree* instanceTree = iInstanceMapTrees.get(pMapId);
            std::string dirFileName = getDirFileName(pMapId);
            instanceTree->unloadMap(dirFileName, 0, true);
            if(instanceTree->size() == 0)
            {
                iInstanceMapTrees.remove(pMapId);
                delete instanceTree;
            }
#ifdef _VMAP_LOG_DEBUG
            Command c = Command();
            c.fillUnloadTileCmd(pMapId);
            iCommandLogger.appendCmd(c);
#endif
        }
    }
    //==========================================================

    bool VMapManager::isInLineOfSight(unsigned int pMapId, float x1, float y1, float z1, float x2, float y2, float z2)
    {
        bool result = true;
        if(isLineOfSightCalcEnabled() && iInstanceMapTrees.containsKey(pMapId))
        {
            Vector3 pos1 = convertPositionToInternalRep(x1,y1,z1);
            Vector3 pos2 = convertPositionToInternalRep(x2,y2,z2);
            if(pos1 != pos2)
            {
                MapTree* mapTree = iInstanceMapTrees.get(pMapId);
                result = mapTree->isInLineOfSight(pos1, pos2);
#ifdef _VMAP_LOG_DEBUG
                Command c = Command();
                                                            // save the orig vectors
                c.fillTestVisCmd(pMapId,Vector3(x1,y1,z1),Vector3(x2,y2,z2),result);
                iCommandLogger.appendCmd(c);
#endif
            }
        }
        return(result);
    }
    //=========================================================
    /**
    get the hit position and return true if we hit something
    otherwise the result pos will be the dest pos
    */
    bool VMapManager::getObjectHitPos(unsigned int pMapId, float x1, float y1, float z1, float x2, float y2, float z2, float& rx, float &ry, float& rz, float pModifyDist)
    {
        bool result = false;
        rx=x2;
        ry=y2;
        rz=z2;
        if(isLineOfSightCalcEnabled())
        {
            if(iInstanceMapTrees.containsKey(pMapId))
            {
                Vector3 pos1 = convertPositionToInternalRep(x1,y1,z1);
                Vector3 pos2 = convertPositionToInternalRep(x2,y2,z2);
                Vector3 resultPos;
                MapTree* mapTree = iInstanceMapTrees.get(pMapId);
                result = mapTree->getObjectHitPos(pos1, pos2, resultPos, pModifyDist);
                resultPos = convertPositionToTrinityRep(resultPos.x,resultPos.y,resultPos.z);
                rx = resultPos.x;
                ry = resultPos.y;
                rz = resultPos.z;
#ifdef _VMAP_LOG_DEBUG
                Command c = Command();
                c.fillTestObjectHitCmd(pMapId, pos1, pos2, resultPos, result);
                iCommandLogger.appendCmd(c);
#endif
            }
        }
        return result;
    }

    //=========================================================
    /**
    get height or INVALID_HEIGHT if to height was calculated
    */

    //int gGetHeightCounter = 0;
    float VMapManager::getHeight(unsigned int pMapId, float x, float y, float z, float ray_lenght)
    {
        float height = VMAP_INVALID_HEIGHT_VALUE;           //no height
        if(isHeightCalcEnabled() && iInstanceMapTrees.containsKey(pMapId))
        {
            Vector3 pos = convertPositionToInternalRep(x,y,z);
            MapTree* mapTree = iInstanceMapTrees.get(pMapId);
            height = mapTree->getHeight(pos, ray_lenght);
            if(!(height < inf()))
            {
                height = VMAP_INVALID_HEIGHT_VALUE;         //no height
            }
#ifdef _VMAP_LOG_DEBUG
            Command c = Command();
            c.fillTestHeightCmd(pMapId,Vector3(x,y,z),height);
            iCommandLogger.appendCmd(c);
#endif
        }
        return(height);
    }

    //=========================================================
    /**
    used for debugging
    */
    bool VMapManager::processCommand(char *pCommand)
    {
        bool result = false;
        std::string cmd = std::string(pCommand);
        if(cmd == "startlog")
        {
#ifdef _VMAP_LOG_DEBUG

            iCommandLogger.enableWriting(true);
#endif
            result = true;
        }
        else if(cmd == "stoplog")
        {
#ifdef _VMAP_LOG_DEBUG
            iCommandLogger.appendCmd(Command());            // Write stop command
            iCommandLogger.enableWriting(false);
#endif
            result = true;
        }
        else if(cmd.find_first_of("pos ") == 0)
        {
            float x,y,z;
            sscanf(pCommand, "pos %f,%f,%f",&x,&y,&z);
#ifdef _VMAP_LOG_DEBUG
            Command c = Command();
            c.fillSetPosCmd(convertPositionToInternalRep(x,y,z));
            iCommandLogger.appendCmd(c);
            iCommandLogger.enableWriting(false);
#endif
            result = true;
        }
        return result;
    }

    //=========================================================
    //=========================================================
    //=========================================================

    MapTree::MapTree(const char* pBaseDir)
    {
        iBasePath = std::string(pBaseDir);
        if(iBasePath.length() > 0 && (iBasePath[iBasePath.length()-1] != '/' || iBasePath[iBasePath.length()-1] != '\\'))
        {
            iBasePath.append("/");
        }
        iTree = new AABSPTree<ModelContainer *>();
    }

    //=========================================================
    MapTree::~MapTree()
    {
        Array<ModelContainer *> mcArray;
        iTree->getMembers(mcArray);
        int no = mcArray.size();
        while(no >0)
        {
            --no;
            delete mcArray[no];
        }
        delete iTree;
    }
    //=========================================================

    // just for visual debugging with an external debug class
    #ifdef _DEBUG_VMAPS
    #ifndef gBoxArray
    extern Vector3 p1,p2,p3,p4,p5,p6,p7;
    extern Array<AABox>gBoxArray;
    extern int gCount1, gCount2, gCount3, gCount4;
    extern bool myfound;
    #endif
    #endif

    //=========================================================
    /**
    return dist to hit or inf() if no hit
    */

    float MapTree::getIntersectionTime(const Ray& pRay, float pMaxDist, bool pStopAtFirstHit)
    {
        float firstDistance = inf();
        IntersectionCallBack<ModelContainer> intersectionCallBack;
        float t = pMaxDist;
        iTree->intersectRay(pRay, intersectionCallBack, t, pStopAtFirstHit, false);
#ifdef _DEBUG_VMAPS
        {
            if(t < pMaxDist)
            {
                myfound = true;
                p4 = pRay.origin + pRay.direction*t;
            }
        }
#endif
        if(t > 0 && t < inf() && pMaxDist > t)
        {
            firstDistance = t;
        }
        return firstDistance;
    }
    //=========================================================

    bool MapTree::isInLineOfSight(const Vector3& pos1, const Vector3& pos2)
    {
        bool result = true;
        float maxDist = abs((pos2 - pos1).magnitude());
                                                            // direction with length of 1
        Ray ray = Ray::fromOriginAndDirection(pos1, (pos2 - pos1)/maxDist);
        float resultDist = getIntersectionTime(ray, maxDist, true);
        if(resultDist < maxDist)
        {
            result = false;
        }
        return result;
    }
    //=========================================================
    /**
    When moving from pos1 to pos2 check if we hit an object. Return true and the position if we hit one
    Return the hit pos or the original dest pos
    */

    bool MapTree::getObjectHitPos(const Vector3& pPos1, const Vector3& pPos2, Vector3& pResultHitPos, float pModifyDist)
    {
        bool result;
        float maxDist = abs((pPos2 - pPos1).magnitude());
        Vector3 dir = (pPos2 - pPos1)/maxDist;              // direction with length of 1
        Ray ray = Ray::fromOriginAndDirection(pPos1, dir);
        float dist = getIntersectionTime(ray, maxDist, false);
        if(dist < maxDist)
        {
            pResultHitPos = pPos1 + dir * dist;
            if(pModifyDist < 0)
            {
                if(abs((pResultHitPos - pPos1).magnitude()) > -pModifyDist)
                {
                    pResultHitPos = pResultHitPos + dir*pModifyDist;
                }
                else
                {
                    pResultHitPos = pPos1;
                }
            }
            else
            {
                pResultHitPos = pResultHitPos + dir*pModifyDist;
            }
            result = true;
        }
        else
        {
            pResultHitPos = pPos2;
            result = false;
        }
        return result;
    }

    //=========================================================

    float MapTree::getHeight(const Vector3& pPos, float ray_lenght)
    {
        float height = inf();
        Vector3 dir = Vector3(0,-1,0);
        Ray ray = Ray::fromOriginAndDirection(pPos, dir);   // direction with length of 1
        float dist = getIntersectionTime(ray, ray_lenght, false);
        if(dist < inf())
        {
            height = (pPos + dir * dist).y;
        }
        return(height);
    }

    //=========================================================

    bool MapTree::PrepareTree()
    {
        iTree->balance();
        return true;
    }

    bool MapTree::loadMap(const std::string& pDirFileName, unsigned int pMapTileIdent)
    {
        bool result = true;
        if(!hasDirFile(pDirFileName))
        {
            FilesInDir filesInDir;
            result = false;
            std::string fb = iBasePath + pDirFileName;
            FILE* df = fopen(fb.c_str(), "rb");
            if(df)
            {
                char lineBuffer[FILENAMEBUFFER_SIZE];
                result = true;
                bool newModelLoaded = false;
                while(result && (fgets(lineBuffer, FILENAMEBUFFER_SIZE-1, df) != 0))
                {
                    std::string name = std::string(lineBuffer);
                    chomp(name);
                    if(name.length() >1)
                    {
                        filesInDir.append(name);
                        ManagedModelContainer *mc;
                        if(!isAlreadyLoaded(name))
                        {
                            std::string fname = iBasePath;
                            fname.append(name);
                            mc = new ManagedModelContainer();
                            result = mc->readFile(fname.c_str());
                            if(result)
                            {
                                addModelContainer(name, mc);
                                newModelLoaded = true;
                            }
                        }
                        else
                        {
                            mc = getModelContainer(name);
                        }
                        mc->incRefCount();
                    }
                }
                if(result && newModelLoaded)
                {
                    iTree->balance();
                }
                if(result && ferror(df) != 0)
                {
                    result = false;
                }
                fclose(df);
                if(result)
                {
                    filesInDir.incRefCount();
                    addDirFile(pDirFileName, filesInDir);
                    setLoadedMapTile(pMapTileIdent);
                }
            }
        }
        else
        {
            // Already loaded, so just inc. the ref count if mapTileIdent is new
            if(!containsLoadedMapTile(pMapTileIdent))
            {
                setLoadedMapTile(pMapTileIdent);
                FilesInDir& filesInDir = getDirFiles(pDirFileName);
                filesInDir.incRefCount();
            }
        }
        return (result);
    }

    //=========================================================

    void MapTree::unloadMap(const std::string& dirFileName, unsigned int pMapTileIdent, bool pForce)
    {
        if(hasDirFile(dirFileName) && (pForce || containsLoadedMapTile(pMapTileIdent)))
        {
            if(containsLoadedMapTile(pMapTileIdent))
                removeLoadedMapTile(pMapTileIdent);
            FilesInDir& filesInDir = getDirFiles(dirFileName);
            filesInDir.decRefCount();
            if(filesInDir.getRefCount() <= 0)
            {
                Array<std::string> fileNames = filesInDir.getFiles();
                bool treeChanged = false;
                for (int i=0; i<fileNames.size(); ++i)
                {
                    std::string name = fileNames[i];
                    ManagedModelContainer* mc = getModelContainer(name);
                    mc->decRefCount();
                    if(mc->getRefCount() <= 0)
                    {
                        iLoadedModelContainer.remove(name);
                        iTree->remove(mc);
                        delete mc;
                        treeChanged = true;
                    }
                }
                iLoadedDirFiles.remove(dirFileName);
                if(treeChanged)
                {
                    iTree->balance();
                }
            }
        }
    }

    //=========================================================
    //=========================================================

    void MapTree::addModelContainer(const std::string& pName, ManagedModelContainer *pMc)
    {
        iLoadedModelContainer.set(pName, pMc);
        iTree->insert(pMc);
    }
    //=========================================================
    //=========================================================
    //=========================================================
}

