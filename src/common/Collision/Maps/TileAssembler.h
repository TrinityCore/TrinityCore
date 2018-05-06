/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include <deque>
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

    class TC_COMMON_API ModelPosition
    {
        private:
            G3D::Matrix3 iRotation;
        public:
            ModelPosition(): iScale(0.0f) { }
            G3D::Vector3 iPos;
            G3D::Vector3 iDir;
            float iScale;
            void init()
            {
                iRotation = G3D::Matrix3::fromEulerAnglesZYX(G3D::pif()*iDir.y/180.f, G3D::pif()*iDir.x/180.f, G3D::pif()*iDir.z/180.f);
            }
            G3D::Vector3 transform(const G3D::Vector3& pIn) const;
            void moveToBasePos(const G3D::Vector3& pBasePos) { iPos -= pBasePos; }
    };

    struct TileSpawn
    {
        TileSpawn() : Id(0), Flags(0) { }
        TileSpawn(uint32 id, uint32 flags) : Id(id), Flags(flags) { }

        uint32 Id;
        uint32 Flags;

        bool operator<(TileSpawn const& right) const { return Id < right.Id; }
    };

    struct TC_COMMON_API MapSpawns
    {
        MapSpawns() { }

        uint32 MapId;
        std::map<uint32, ModelSpawn> UniqueEntries;
        std::map<uint32 /*packedTileId*/, std::set<TileSpawn>> TileEntries;
        std::map<uint32 /*packedTileId*/, std::set<TileSpawn>> ParentTileEntries;
    };

    typedef std::deque<MapSpawns> MapData;
    //===============================================

    struct TC_COMMON_API GroupModel_Raw
    {
        uint32 mogpflags;
        uint32 GroupWMOID;

        G3D::AABox bounds;
        uint32 liquidflags;
        std::vector<MeshTriangle> triangles;
        std::vector<G3D::Vector3> vertexArray;
        class WmoLiquid* liquid;

        GroupModel_Raw() : mogpflags(0), GroupWMOID(0), liquidflags(0),
            liquid(NULL) { }
        ~GroupModel_Raw();

        bool Read(FILE* f);
    };

    struct TC_COMMON_API WorldModel_Raw
    {
        uint32 RootWMOID;
        std::vector<GroupModel_Raw> groupsArray;

        bool Read(const char * path);
    };

    class TC_COMMON_API TileAssembler
    {
        private:
            std::string iDestDir;
            std::string iSrcDir;
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
    };

}                                                           // VMAP
#endif                                                      /*_TILEASSEMBLER_H_*/
