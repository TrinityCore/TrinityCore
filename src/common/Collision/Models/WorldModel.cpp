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

#include "WorldModel.h"
#include "VMapDefinitions.h"
#include "MapTree.h"
#include "ModelIgnoreFlags.h"
#include <array>

using G3D::Vector3;

template<> struct BoundsTrait<VMAP::GroupModel>
{
    static void getBounds(const VMAP::GroupModel& obj, G3D::AABox& out) { out = obj.GetBound(); }
};

namespace VMAP
{
    bool IntersectTriangle(MeshTriangle const& tri, std::vector<Vector3>::const_iterator points, G3D::Ray const& ray, float& distance)
    {
        static const float EPS = 1e-5f;

        // See RTR2 ch. 13.7 for the algorithm.

        const Vector3 e1 = points[tri.idx1] - points[tri.idx0];
        const Vector3 e2 = points[tri.idx2] - points[tri.idx0];
        const Vector3 p(ray.direction().cross(e2));
        const float a = e1.dot(p);

        if (std::fabs(a) < EPS) {
            // Determinant is ill-conditioned; abort early
            return false;
        }

        const float f = 1.0f / a;
        const Vector3 s(ray.origin() - points[tri.idx0]);
        const float u = f * s.dot(p);

        if ((u < 0.0f) || (u > 1.0f)) {
            // We hit the plane of the m_geometry, but outside the m_geometry
            return false;
        }

        const Vector3 q(s.cross(e1));
        const float v = f * ray.direction().dot(q);

        if ((v < 0.0f) || ((u + v) > 1.0f)) {
            // We hit the plane of the triangle, but outside the triangle
            return false;
        }

        const float t = f * e2.dot(q);

        if ((t > 0.0f) && (t < distance))
        {
            // This is a new hit, closer than the previous one
            distance = t;

            /* baryCoord[0] = 1.0 - u - v;
            baryCoord[1] = u;
            baryCoord[2] = v; */

            return true;
        }
        // This hit is after the previous hit, so ignore it
        return false;
    }

    class TriBoundFunc
    {
        public:
            TriBoundFunc(std::vector<Vector3>& vert): vertices(vert.begin()) { }
            void operator()(MeshTriangle const& tri, G3D::AABox& out) const
            {
                G3D::Vector3 lo = vertices[tri.idx0];
                G3D::Vector3 hi = lo;

                lo = (lo.min(vertices[tri.idx1])).min(vertices[tri.idx2]);
                hi = (hi.max(vertices[tri.idx1])).max(vertices[tri.idx2]);

                out = G3D::AABox(lo, hi);
            }
        protected:
            const std::vector<Vector3>::const_iterator vertices;
    };

    // ===================== WmoLiquid ==================================

    WmoLiquid::WmoLiquid(uint32 width, uint32 height, Vector3 const& corner, uint32 type) :
        iTilesX(width), iTilesY(height), iCorner(corner), iType(type)
    {
        if (width && height)
        {
            iHeight = new float[(width + 1) * (height + 1)];
            iFlags = new uint8[width * height];
        }
        else
        {
            iHeight = new float[1];
            iFlags = nullptr;
        }
    }

    WmoLiquid::WmoLiquid(WmoLiquid const& other) : iHeight(nullptr), iFlags(nullptr)
    {
        *this = other; // use assignment operator...
    }

    WmoLiquid::~WmoLiquid()
    {
        delete[] iHeight;
        delete[] iFlags;
    }

    WmoLiquid& WmoLiquid::operator=(WmoLiquid const& other)
    {
        if (this == &other)
            return *this;
        iTilesX = other.iTilesX;
        iTilesY = other.iTilesY;
        iCorner = other.iCorner;
        iType = other.iType;
        delete[] iHeight;
        delete[] iFlags;
        if (other.iHeight)
        {
            iHeight = new float[(iTilesX+1)*(iTilesY+1)];
            memcpy(iHeight, other.iHeight, (iTilesX+1)*(iTilesY+1)*sizeof(float));
        }
        else
            iHeight = nullptr;
        if (other.iFlags)
        {
            iFlags = new uint8[iTilesX * iTilesY];
            memcpy(iFlags, other.iFlags, iTilesX * iTilesY);
        }
        else
            iFlags = nullptr;
        return *this;
    }

    bool WmoLiquid::GetLiquidHeight(Vector3 const& pos, float& liqHeight) const
    {
        // simple case
        if (!iFlags)
        {
            liqHeight = iHeight[0];
            return true;
        }

        float tx_f = (pos.x - iCorner.x) / LIQUID_TILE_SIZE;
        uint32 tx = uint32(tx_f);
        if (tx_f < 0.0f || tx >= iTilesX)
            return false;
        float ty_f = (pos.y - iCorner.y) / LIQUID_TILE_SIZE;
        uint32 ty = uint32(ty_f);
        if (ty_f < 0.0f || ty >= iTilesY)
            return false;

        // check if tile shall be used for liquid level
        // checking for 0x08 *might* be enough, but disabled tiles always are 0x?F:
        if ((iFlags[tx + ty * iTilesX] & 0x0F) == 0x0F)
            return false;

        // (dx, dy) coordinates inside tile, in [0, 1]^2
        float dx = tx_f - (float)tx;
        float dy = ty_f - (float)ty;

        /* Tesselate tile to two triangles (not sure if client does it exactly like this)

            ^ dy
            |
          1 x---------x (1, 1)
            | (b)   / |
            |     /   |
            |   /     |
            | /   (a) |
            x---------x---> dx
          0           1
        */

        uint32 const rowOffset = iTilesX + 1;
        if (dx > dy) // case (a)
        {
            float sx = iHeight[tx+1 +  ty    * rowOffset] - iHeight[tx   + ty * rowOffset];
            float sy = iHeight[tx+1 + (ty+1) * rowOffset] - iHeight[tx+1 + ty * rowOffset];
            liqHeight = iHeight[tx + ty * rowOffset] + dx * sx + dy * sy;
        }
        else // case (b)
        {
            float sx = iHeight[tx+1 + (ty+1) * rowOffset] - iHeight[tx + (ty+1) * rowOffset];
            float sy = iHeight[tx   + (ty+1) * rowOffset] - iHeight[tx +  ty    * rowOffset];
            liqHeight = iHeight[tx + ty * rowOffset] + dx * sx + dy * sy;
        }
        return true;
    }

    uint32 WmoLiquid::GetFileSize()
    {
        return 2 * sizeof(uint32) +
                sizeof(Vector3) +
                sizeof(uint32) +
                (iFlags ? ((iTilesX + 1) * (iTilesY + 1) * sizeof(float) + iTilesX * iTilesY) : sizeof(float));
    }

    bool WmoLiquid::writeToFile(FILE* wf)
    {
        bool result = false;
        if (fwrite(&iTilesX, sizeof(uint32), 1, wf) == 1 &&
            fwrite(&iTilesY, sizeof(uint32), 1, wf) == 1 &&
            fwrite(&iCorner, sizeof(Vector3), 1, wf) == 1 &&
            fwrite(&iType, sizeof(uint32), 1, wf) == 1)
        {
            if (iTilesX && iTilesY)
            {
                uint32 size = (iTilesX + 1) * (iTilesY + 1);
                if (fwrite(iHeight, sizeof(float), size, wf) == size)
                {
                    size = iTilesX * iTilesY;
                    result = fwrite(iFlags, sizeof(uint8), size, wf) == size;
                }
            }
            else
                result = fwrite(iHeight, sizeof(float), 1, wf) == 1;
        }

        return result;
    }

    bool WmoLiquid::readFromFile(FILE* rf, WmoLiquid*& out)
    {
        bool result = false;
        WmoLiquid* liquid = new WmoLiquid();

        if (fread(&liquid->iTilesX, sizeof(uint32), 1, rf) == 1 &&
            fread(&liquid->iTilesY, sizeof(uint32), 1, rf) == 1 &&
            fread(&liquid->iCorner, sizeof(Vector3), 1, rf) == 1 &&
            fread(&liquid->iType, sizeof(uint32), 1, rf) == 1)
        {
            if (liquid->iTilesX && liquid->iTilesY)
            {
                uint32 size = (liquid->iTilesX + 1) * (liquid->iTilesY + 1);
                liquid->iHeight = new float[size];
                if (fread(liquid->iHeight, sizeof(float), size, rf) == size)
                {
                    size = liquid->iTilesX * liquid->iTilesY;
                    liquid->iFlags = new uint8[size];
                    result = fread(liquid->iFlags, sizeof(uint8), size, rf) == size;
                }
            }
            else
            {
                liquid->iHeight = new float[1];
                result = fread(liquid->iHeight, sizeof(float), 1, rf) == 1;
            }
        }

        if (!result)
            delete liquid;
        else
            out = liquid;

        return result;
    }

    void WmoLiquid::getPosInfo(uint32& tilesX, uint32& tilesY, G3D::Vector3& corner) const
    {
        tilesX = iTilesX;
        tilesY = iTilesY;
        corner = iCorner;
    }

    // ===================== GroupModel ==================================

    GroupModel::GroupModel(GroupModel const& other) :
        iBound(other.iBound), iMogpFlags(other.iMogpFlags), iGroupWMOID(other.iGroupWMOID),
        vertices(other.vertices), triangles(other.triangles), meshTree(other.meshTree), iLiquid(nullptr)
    {
        if (other.iLiquid)
            iLiquid = new WmoLiquid(*other.iLiquid);
    }

    void GroupModel::setMeshData(std::vector<Vector3>& vert, std::vector<MeshTriangle>& tri)
    {
        vertices.swap(vert);
        triangles.swap(tri);
        TriBoundFunc bFunc(vertices);
        meshTree.build(triangles, bFunc);
    }

    bool GroupModel::writeToFile(FILE* wf)
    {
        bool result = true;
        uint32 chunkSize, count;

        if (result && fwrite(&iBound, sizeof(G3D::AABox), 1, wf) != 1) result = false;
        if (result && fwrite(&iMogpFlags, sizeof(uint32), 1, wf) != 1) result = false;
        if (result && fwrite(&iGroupWMOID, sizeof(uint32), 1, wf) != 1) result = false;

        // write vertices
        if (result && fwrite("VERT", 1, 4, wf) != 4) result = false;
        count = vertices.size();
        chunkSize = sizeof(uint32) + sizeof(Vector3) * count;
        if (result && fwrite(&chunkSize, sizeof(uint32), 1, wf) != 1) result = false;
        if (result && fwrite(&count, sizeof(uint32), 1, wf) != 1) result = false;
        if (!count) // models without (collision) geometry end here, unsure if they are useful
            return result;
        if (result && fwrite(&vertices[0], sizeof(Vector3), count, wf) != count) result = false;

        // write triangle mesh
        if (result && fwrite("TRIM", 1, 4, wf) != 4) result = false;
        count = triangles.size();
        chunkSize = sizeof(uint32) + sizeof(MeshTriangle) * count;
        if (result && fwrite(&chunkSize, sizeof(uint32), 1, wf) != 1) result = false;
        if (result && fwrite(&count, sizeof(uint32), 1, wf) != 1) result = false;
        if (result && fwrite(&triangles[0], sizeof(MeshTriangle), count, wf) != count) result = false;

        // write mesh BIH
        if (result && fwrite("MBIH", 1, 4, wf) != 4) result = false;
        if (result) result = meshTree.writeToFile(wf);

        // write liquid data
        if (result && fwrite("LIQU", 1, 4, wf) != 4) result = false;
        if (!iLiquid)
        {
            chunkSize = 0;
            if (result && fwrite(&chunkSize, sizeof(uint32), 1, wf) != 1) result = false;
            return result;
        }
        chunkSize = iLiquid->GetFileSize();
        if (result && fwrite(&chunkSize, sizeof(uint32), 1, wf) != 1) result = false;
        if (result) result = iLiquid->writeToFile(wf);

        return result;
    }

    bool GroupModel::readFromFile(FILE* rf)
    {
        char chunk[8];
        bool result = true;
        uint32 chunkSize = 0;
        uint32 count = 0;
        triangles.clear();
        vertices.clear();
        delete iLiquid;
        iLiquid = nullptr;

        if (result && fread(&iBound, sizeof(G3D::AABox), 1, rf) != 1) result = false;
        if (result && fread(&iMogpFlags, sizeof(uint32), 1, rf) != 1) result = false;
        if (result && fread(&iGroupWMOID, sizeof(uint32), 1, rf) != 1) result = false;

        // read vertices
        if (result && !readChunk(rf, chunk, "VERT", 4)) result = false;
        if (result && fread(&chunkSize, sizeof(uint32), 1, rf) != 1) result = false;
        if (result && fread(&count, sizeof(uint32), 1, rf) != 1) result = false;
        if (!count) // models without (collision) geometry end here, unsure if they are useful
            return result;
        if (result) vertices.resize(count);
        if (result && fread(&vertices[0], sizeof(Vector3), count, rf) != count) result = false;

        // read triangle mesh
        if (result && !readChunk(rf, chunk, "TRIM", 4)) result = false;
        if (result && fread(&chunkSize, sizeof(uint32), 1, rf) != 1) result = false;
        if (result && fread(&count, sizeof(uint32), 1, rf) != 1) result = false;
        if (result) triangles.resize(count);
        if (result && fread(&triangles[0], sizeof(MeshTriangle), count, rf) != count) result = false;

        // read mesh BIH
        if (result && !readChunk(rf, chunk, "MBIH", 4)) result = false;
        if (result) result = meshTree.readFromFile(rf);

        // write liquid data
        if (result && !readChunk(rf, chunk, "LIQU", 4)) result = false;
        if (result && fread(&chunkSize, sizeof(uint32), 1, rf) != 1) result = false;
        if (result && chunkSize > 0)
            result = WmoLiquid::readFromFile(rf, iLiquid);
        return result;
    }

    struct GModelRayCallback
    {
        GModelRayCallback(std::vector<MeshTriangle> const& tris, const std::vector<Vector3> &vert):
            vertices(vert.begin()), triangles(tris.begin()), hit(false) { }
        bool operator()(G3D::Ray const& ray, uint32 entry, float& distance, bool /*pStopAtFirstHit*/)
        {
            hit = IntersectTriangle(triangles[entry], vertices, ray, distance) || hit;
            return hit;
        }
        std::vector<Vector3>::const_iterator vertices;
        std::vector<MeshTriangle>::const_iterator triangles;
        bool hit;
    };

    bool GroupModel::IntersectRay(G3D::Ray const& ray, float& distance, bool stopAtFirstHit) const
    {
        if (triangles.empty())
            return false;

        GModelRayCallback callback(triangles, vertices);
        meshTree.intersectRay(ray, callback, distance, stopAtFirstHit);
        return callback.hit;
    }

    inline bool IsInsideOrAboveBound(G3D::AABox const& bounds, const G3D::Point3& point)
    {
        return point.x >= bounds.low().x
            && point.y >= bounds.low().y
            && point.z >= bounds.low().z
            && point.x <= bounds.high().x
            && point.y <= bounds.high().y;
    }

    GroupModel::InsideResult GroupModel::IsInsideObject(G3D::Ray const& ray, float& z_dist) const
    {
        if (triangles.empty() || !IsInsideOrAboveBound(iBound, ray.origin()))
            return OUT_OF_BOUNDS;

        if (meshTree.bound().high().z >= ray.origin().z)
        {
            float dist = G3D::finf();
            if (IntersectRay(ray, dist, false))
            {
                z_dist = dist - 0.1f;
                return INSIDE;
            }
            if (meshTree.bound().contains(ray.origin()))
                return MAYBE_INSIDE;
        }
        else
        {
            // some group models don't have any floor to intersect with
            // so we should attempt to intersect with a model part below this group
            // then find back where we originated from (in WorldModel::GetLocationInfo)
            float dist = G3D::finf();
            float delta = ray.origin().z - meshTree.bound().high().z;
            if (IntersectRay(ray.bumpedRay(delta), dist, false))
            {
                z_dist = dist - 0.1f + delta;
                return ABOVE;
            }
        }

        return OUT_OF_BOUNDS;
    }

    bool GroupModel::GetLiquidLevel(Vector3 const& pos, float& liqHeight) const
    {
        if (iLiquid)
            return iLiquid->GetLiquidHeight(pos, liqHeight);
        return false;
    }

    uint32 GroupModel::GetLiquidType() const
    {
        if (iLiquid)
            return iLiquid->GetType();
        return 0;
    }

    // ===================== WorldModel ==================================

    void WorldModel::setGroupModels(std::vector<GroupModel>& models)
    {
        groupModels.swap(models);
        groupTree.build(groupModels, BoundsTrait<GroupModel>::getBounds, 1);
    }

    struct WModelRayCallBack
    {
        WModelRayCallBack(std::vector<GroupModel> const& mod): models(mod.begin()), hit(false) { }
        bool operator()(G3D::Ray const& ray, uint32 entry, float& distance, bool pStopAtFirstHit)
        {
            bool result = models[entry].IntersectRay(ray, distance, pStopAtFirstHit);
            if (result)
                hit = true;
            return hit;
        }
        std::vector<GroupModel>::const_iterator models;
        bool hit;
    };

    bool WorldModel::IntersectRay(G3D::Ray const& ray, float& distance, bool stopAtFirstHit, ModelIgnoreFlags ignoreFlags) const
    {
        // If the caller asked us to ignore certain objects we should check flags
        if ((ignoreFlags & ModelIgnoreFlags::M2) != ModelIgnoreFlags::Nothing)
        {
            // M2 models are not taken into account for LoS calculation if caller requested their ignoring.
            if (IsM2())
                return false;
        }

        // small M2 workaround, maybe better make separate class with virtual intersection funcs
        // in any case, there's no need to use a bound tree if we only have one submodel
        if (groupModels.size() == 1)
            return groupModels[0].IntersectRay(ray, distance, stopAtFirstHit);

        WModelRayCallBack isc(groupModels);
        groupTree.intersectRay(ray, isc, distance, stopAtFirstHit);
        return isc.hit;
    }

    class WModelAreaCallback
    {
    public:
        WModelAreaCallback(std::vector<GroupModel> const& vals) :
            prims(vals), hit() { }
        std::vector<GroupModel> const& prims;
        std::array<GroupModel const*, 3> hit;

        bool operator()(G3D::Ray const& ray, uint32 entry, float& distance, bool /*stopAtFirstHit*/)
        {
            float group_Z;
            if (GroupModel::InsideResult result = prims[entry].IsInsideObject(ray, group_Z); result != GroupModel::OUT_OF_BOUNDS)
            {
                if (result != GroupModel::MAYBE_INSIDE)
                {
                    if (group_Z < distance)
                    {
                        distance = group_Z;
                        hit[result] = &prims[entry];
                        return true;
                    }
                }
                else
                    hit[result] = &prims[entry];
            }
            return false;
        }
    };

    bool WorldModel::GetLocationInfo(const G3D::Vector3& p, const G3D::Vector3& down, float& dist, GroupLocationInfo& info) const
    {
        if (groupModels.empty())
            return false;

        WModelAreaCallback callback(groupModels);
        G3D::Ray r(p - down * 0.1f, down);
        float zDist = groupTree.bound().extent().length();
        groupTree.intersectRay(r, callback, zDist, false);
        if (callback.hit[GroupModel::INSIDE])
        {
            info.rootId = RootWMOID;
            info.hitModel = callback.hit[GroupModel::INSIDE];
            dist = zDist;
            return true;
        }

        // some group models don't have any floor to intersect with
        // so we should attempt to intersect with a model part below the group `p` is in (stored in GroupModel::ABOVE)
        // then find back where we originated from (GroupModel::MAYBE_INSIDE)
        if (callback.hit[GroupModel::MAYBE_INSIDE] && callback.hit[GroupModel::ABOVE])
        {
            info.rootId = RootWMOID;
            info.hitModel = callback.hit[GroupModel::MAYBE_INSIDE];
            dist = zDist;
            return true;
        }
        return false;
    }

    bool WorldModel::writeFile(const std::string& filename)
    {
        FILE* wf = fopen(filename.c_str(), "wb");
        if (!wf)
            return false;

        uint32 chunkSize, count;
        bool result = fwrite(VMAP_MAGIC, 1, 8, wf) == 8;
        if (result && fwrite("WMOD", 1, 4, wf) != 4) result = false;
        chunkSize = sizeof(uint32) + sizeof(uint32);
        if (result && fwrite(&chunkSize, sizeof(uint32), 1, wf) != 1) result = false;
        if (result)
        {
            uint32 flags = Flags.AsUnderlyingType();
            if (fwrite(&flags, sizeof(uint32), 1, wf) != 1) result = false;
        }
        if (result && fwrite(&RootWMOID, sizeof(uint32), 1, wf) != 1) result = false;

        // write group models
        count = groupModels.size();
        if (count)
        {
            if (result && fwrite("GMOD", 1, 4, wf) != 4) result = false;
            //chunkSize = sizeof(uint32)+ sizeof(GroupModel)*count;
            //if (result && fwrite(&chunkSize, sizeof(uint32), 1, wf) != 1) result = false;
            if (result && fwrite(&count, sizeof(uint32), 1, wf) != 1) result = false;
            for (uint32 i = 0; i < groupModels.size() && result; ++i)
                result = groupModels[i].writeToFile(wf);

            // write group BIH
            if (result && fwrite("GBIH", 1, 4, wf) != 4) result = false;
            if (result) result = groupTree.writeToFile(wf);
        }

        fclose(wf);
        return result;
    }

    bool WorldModel::readFile(const std::string& filename)
    {
        FILE* rf = fopen(filename.c_str(), "rb");
        if (!rf)
            return false;

        bool result = true;
        uint32 chunkSize = 0;
        uint32 count = 0;
        char chunk[8];                          // Ignore the added magic header
        if (!readChunk(rf, chunk, VMAP_MAGIC, 8)) result = false;

        if (result && !readChunk(rf, chunk, "WMOD", 4)) result = false;
        if (result && fread(&chunkSize, sizeof(uint32), 1, rf) != 1) result = false;
        if (result)
        {
            ModelFlags flags;
            if (fread(&flags, sizeof(flags), 1, rf) == 1)
                Flags = flags;
            else
                result = false;
        }
        if (result && fread(&RootWMOID, sizeof(uint32), 1, rf) != 1) result = false;

        // read group models
        if (result && readChunk(rf, chunk, "GMOD", 4))
        {
            //if (fread(&chunkSize, sizeof(uint32), 1, rf) != 1) result = false;

            if (result && fread(&count, sizeof(uint32), 1, rf) != 1) result = false;
            if (result) groupModels.resize(count);
            //if (result && fread(&groupModels[0], sizeof(GroupModel), count, rf) != count) result = false;
            for (uint32 i = 0; i < count && result; ++i)
                result = groupModels[i].readFromFile(rf);

            // read group BIH
            if (result && !readChunk(rf, chunk, "GBIH", 4)) result = false;
            if (result) result = groupTree.readFromFile(rf);
        }

        fclose(rf);
        return result;
    }
}
