/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
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

#ifndef _TILEASSEMBLER_H_
#define _TILEASSEMBLER_H_

#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include <map>
#include <set>

#include "ModelInstance.h"
#include "WorldModel.h"

namespace VMAP
{
    /**
    This Class is used to convert raw vector data into balanced BSP-Trees.
    To start the conversion call convertWorld().
    */
    //===============================================

    class ModelPosition
    {
        private:
            G3D::Matrix3 iRotation;
        public:
            G3D::Vector3 iPos;
            G3D::Vector3 iDir;
            float iScale;
            void init()
            {
                iRotation = G3D::Matrix3::fromEulerAnglesZYX(G3D::pi()*iDir.y/180.f, G3D::pi()*iDir.x/180.f, G3D::pi()*iDir.z/180.f);
            }
            G3D::Vector3 transform(const G3D::Vector3& pIn) const;
            void moveToBasePos(const G3D::Vector3& pBasePos) { iPos -= pBasePos; }
    };

    typedef std::map<uint32, ModelSpawn> UniqueEntryMap;
    typedef std::multimap<uint32, uint32> TileMap;

    struct MapSpawns
    {
        UniqueEntryMap UniqueEntries;
        TileMap TileEntries;
    };

    typedef std::map<uint32, MapSpawns*> MapData;
    //===============================================

    struct GroupModel_Raw
    {
        uint32 mogpflags;
        uint32 GroupWMOID;

        G3D::AABox bounds;
        uint32 liquidflags;
        std::vector<MeshTriangle> triangles;
        std::vector<G3D::Vector3> vertexArray;
        class WmoLiquid *liquid;

        GroupModel_Raw() : liquid(0) {}
        ~GroupModel_Raw();

        bool Read(FILE * f);
    };

    struct WorldModel_Raw
    {
        uint32 RootWMOID;
        std::vector<GroupModel_Raw> groupsArray;

        bool Read(const char * path);
    };

    class TileAssembler
    {
        private:
            std::string iDestDir;
            std::string iSrcDir;
            bool (*iFilterMethod)(char *pName);
            G3D::Table<std::string, unsigned int > iUniqueNameIds;
            unsigned int iCurrentUniqueNameId;
            MapData mapData;
            std::set<std::string> spawnedModelFiles;

        public:
            TileAssembler(const std::string& pSrcDirName, const std::string& pDestDirName);
            virtual ~TileAssembler();

            bool convertWorld2();
            bool readMapSpawns();
            bool calculateTransformedBound(ModelSpawn &spawn);
            void exportGameobjectModels();

            bool convertRawFile(const std::string& pModelFilename);
            void setModelNameFilterMethod(bool (*pFilterMethod)(char *pName)) { iFilterMethod = pFilterMethod; }
            std::string getDirEntryNameFromModName(unsigned int pMapId, const std::string& pModPosName);
    };

}                                                           // VMAP
#endif                                                      /*_TILEASSEMBLER_H_*/
