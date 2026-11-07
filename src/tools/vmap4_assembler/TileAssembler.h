/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ModelInstance.h"
#include "WorldModel.h"
#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <boost/filesystem/path.hpp>
#include <deque>
#include <map>
#include <set>

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

    struct MapSpawns
    {
        uint32 MapId = 0;
        std::map<uint32, ModelSpawn> UniqueEntries;
        std::set<std::string> SpawnedModelFiles;
        std::map<uint32 /*packedTileId*/, std::set<uint32 /*Id*/>> TileEntries;
        std::map<uint32 /*packedTileId*/, std::set<uint32 /*Id*/>> ParentTileEntries;
    };

    typedef std::deque<MapSpawns> MapData;
    //===============================================

    struct GroupModel_Raw
    {
        uint32 mogpflags;
        uint32 GroupWMOID;

        G3D::AABox bounds;
        uint32 liquidflags;
        std::vector<MeshTriangle> triangles;
        std::vector<G3D::Vector3> vertexArray;
        std::unique_ptr<WmoLiquid> liquid;

        GroupModel_Raw() : mogpflags(0), GroupWMOID(0), liquidflags(0),
            liquid(nullptr) { }

        bool Read(FILE* f);
    };

    struct WorldModel_Raw
    {
        ModelFlags Flags;
        uint32 RootWMOID;
        std::vector<GroupModel_Raw> groupsArray;

        bool Read(boost::filesystem::path const& path);
    };

    class TileAssembler
    {
        private:
            boost::filesystem::path iSrcDir;
            boost::filesystem::path iDestDir;
            uint32 iThreads;
            std::set<std::string> spawnedModelFiles;

        public:
            TileAssembler(std::string const& srcDirName, std::string const& destDirName, uint32 threads);

            bool convertWorld2();
            bool convertMap(MapSpawns& data) const;
            static bool readMapSpawns(FILE* dirf, MapSpawns* data);
            bool calculateTransformedBound(ModelSpawn &spawn) const;
            void exportGameobjectModels();

            bool convertRawFile(const std::string& pModelFilename) const;
    };

}                                                           // VMAP
#endif                                                      /*_TILEASSEMBLER_H_*/
