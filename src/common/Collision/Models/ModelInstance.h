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

#ifndef _MODELINSTANCE_H_
#define _MODELINSTANCE_H_

#include <G3D/Matrix3.h>
#include <G3D/Vector3.h>
#include <G3D/AABox.h>
#include <G3D/Ray.h>

#include "Define.h"

namespace VMAP
{
    class WorldModel;
    struct AreaInfo;
    struct LocationInfo;
    enum class ModelIgnoreFlags : uint32;

    enum ModelFlags
    {
        MOD_M2 = 1,
        MOD_HAS_BOUND = 1 << 1,
        MOD_PARENT_SPAWN = 1 << 2
    };

    struct ModelMinimalData
    {
            //Flags, ID, Pos, Rot, Scale, Bound_lo, Bound_hi
            uint8 flags;
            uint8 adtId;
            uint32 ID;
            G3D::Vector3 iPos;
            float iScale;
            G3D::AABox iBound;
#ifdef VMAP_DEBUG
            std::string name;
#endif

            bool operator==(ModelMinimalData const& other) const { return ID == other.ID; }
            G3D::AABox const& getBounds() const { return iBound; }
    };

    struct TC_COMMON_API ModelSpawn : public ModelMinimalData
    {
            G3D::Vector3 iRot;
#ifndef VMAP_DEBUG
            std::string name;
#endif

            static bool readFromFile(FILE* rf, ModelSpawn& spawn);
            static bool writeToFile(FILE* rw, ModelSpawn const& spawn);
    };

    class TC_COMMON_API ModelInstance : public ModelMinimalData
    {
        public:
            ModelInstance() : iInvScale(0.0f), iModel(nullptr) { }
            ModelInstance(ModelSpawn const& spawn, WorldModel* model);
            void setUnloaded() { iModel = nullptr; }
            bool intersectRay(G3D::Ray const& pRay, float& pMaxDist, bool pStopAtFirstHit, ModelIgnoreFlags ignoreFlags) const;
            void intersectPoint(G3D::Vector3 const& p, AreaInfo& info) const;
            bool GetLocationInfo(G3D::Vector3 const& p, LocationInfo& info) const;
            bool GetLiquidLevel(G3D::Vector3 const& p, LocationInfo& info, float& liqHeight) const;
            G3D::Matrix3 const& GetInvRot() const { return iInvRot; }
            WorldModel const* getWorldModel() const { return iModel; }
        protected:
            G3D::Matrix3 iInvRot;
            float iInvScale;
            WorldModel* iModel;
    };
} // namespace VMAP

#endif // _MODELINSTANCE
