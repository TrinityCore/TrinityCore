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

#ifndef _WORLDMODEL_H
#define _WORLDMODEL_H

#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Ray.h>
#include "BoundingIntervalHierarchy.h"

#include "Define.h"
#include "EnumFlag.h"

namespace VMAP
{
    class TreeNode;
    struct AreaInfo;
    struct LocationInfo;
    struct GroupLocationInfo;
    enum class ModelIgnoreFlags : uint32;

    enum class ModelFlags : uint32
    {
        None    = 0x0,
        IsM2    = 0x1
    };

    DEFINE_ENUM_FLAG(ModelFlags);

    struct MeshTriangle
    {
        uint32 idx0;
        uint32 idx1;
        uint32 idx2;
    };

    class TC_COMMON_API WmoLiquid
    {
        public:
            WmoLiquid(uint32 width, uint32 height, G3D::Vector3 const& corner, uint32 type);
            WmoLiquid(WmoLiquid const& other);
            ~WmoLiquid();
            WmoLiquid& operator=(WmoLiquid const& other);
            bool GetLiquidHeight(G3D::Vector3 const& pos, float& liqHeight) const;
            uint32 GetType() const { return iType; }
            float *GetHeightStorage() { return iHeight; }
            uint8 *GetFlagsStorage() { return iFlags; }
            float const* GetHeightStorage() const { return iHeight; }
            uint8 const* GetFlagsStorage()  const { return iFlags; }
            uint32 GetFileSize();
            bool writeToFile(FILE* wf);
            static bool readFromFile(FILE* rf, WmoLiquid* &liquid);
            void getPosInfo(uint32 &tilesX, uint32 &tilesY, G3D::Vector3 &corner) const;
        private:
            WmoLiquid() : iTilesX(0), iTilesY(0), iCorner(), iType(0), iHeight(nullptr), iFlags(nullptr) { }
            uint32 iTilesX;       //!< number of tiles in x direction, each
            uint32 iTilesY;
            G3D::Vector3 iCorner; //!< the lower corner
            uint32 iType;         //!< liquid type
            float *iHeight;       //!< (tilesX + 1)*(tilesY + 1) height values
            uint8 *iFlags;        //!< info if liquid tile is used
    };

    /*! holding additional info for WMO group files */
    class TC_COMMON_API GroupModel
    {
        public:
            GroupModel() : iBound(), iMogpFlags(0), iGroupWMOID(0), iLiquid(nullptr) { }
            GroupModel(GroupModel const& other);
            GroupModel(uint32 mogpFlags, uint32 groupWMOID, G3D::AABox const& bound):
                        iBound(bound), iMogpFlags(mogpFlags), iGroupWMOID(groupWMOID), iLiquid(nullptr) { }
            ~GroupModel() { delete iLiquid; }

            //! pass mesh data to object and create BIH. Passed vectors get get swapped with old geometry!
            void setMeshData(std::vector<G3D::Vector3> &vert, std::vector<MeshTriangle> &tri);
            void setLiquidData(WmoLiquid*& liquid) { iLiquid = liquid; liquid = nullptr; }
            bool IntersectRay(const G3D::Ray &ray, float &distance, bool stopAtFirstHit) const;
            bool IsInsideObject(const G3D::Vector3 &pos, const G3D::Vector3 &down, float &z_dist) const;
            bool GetLiquidLevel(const G3D::Vector3 &pos, float &liqHeight) const;
            uint32 GetLiquidType() const;
            bool writeToFile(FILE* wf);
            bool readFromFile(FILE* rf);
            const G3D::AABox& GetBound() const { return iBound; }
            uint32 GetMogpFlags() const { return iMogpFlags; }
            uint32 GetWmoID() const { return iGroupWMOID; }
            std::vector<G3D::Vector3> const& GetVertices() const { return vertices; }
            std::vector<MeshTriangle> const& GetTriangles() const { return triangles; }
            WmoLiquid const* GetLiquid() const { return iLiquid; }
        protected:
            G3D::AABox iBound;
            uint32 iMogpFlags;// 0x8 outdor; 0x2000 indoor
            uint32 iGroupWMOID;
            std::vector<G3D::Vector3> vertices;
            std::vector<MeshTriangle> triangles;
            BIH meshTree;
            WmoLiquid* iLiquid;
    };

    /*! Holds a model (converted M2 or WMO) in its original coordinate space */
    class TC_COMMON_API WorldModel
    {
        public:
            WorldModel(): Flags(ModelFlags::None), RootWMOID(0) { }

            //! pass group models to WorldModel and create BIH. Passed vector is swapped with old geometry!
            void setGroupModels(std::vector<GroupModel> &models);
            void setFlags(ModelFlags flags) { Flags = flags; }
            void setRootWmoID(uint32 id) { RootWMOID = id; }
            bool IntersectRay(const G3D::Ray &ray, float &distance, bool stopAtFirstHit, ModelIgnoreFlags ignoreFlags) const;
            bool GetLocationInfo(const G3D::Vector3 &p, const G3D::Vector3 &down, float &dist, GroupLocationInfo& info) const;
            bool writeFile(const std::string &filename);
            bool readFile(const std::string &filename);
            bool IsM2() const { return Flags.HasFlag(ModelFlags::IsM2); }
            std::vector<GroupModel> const& getGroupModels() const { return groupModels; }
            std::string const& GetName() const { return name; }
            void SetName(std::string newName) { name = std::move(newName); }
        protected:
            EnumFlag<ModelFlags> Flags;
            uint32 RootWMOID;
            std::vector<GroupModel> groupModels;
            BIH groupTree;
            std::string name;
    };
} // namespace VMAP

#endif // _WORLDMODEL_H
