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

#ifndef TRANSPORTMGR_H
#define TRANSPORTMGR_H

#include "ObjectGuid.h"
#include <map>
#include <memory>
#include <unordered_map>

struct KeyFrame;
struct GameObjectTemplate;
struct TaxiPathNodeEntry;
struct TransportAnimationEntry;
struct TransportRotationEntry;
struct TransportTemplate;
class Transport;
class Map;

namespace Movement
{
    template <typename length_type> class Spline;
}

using TransportSpline = Movement::Spline<double>;
using KeyFrameVec = std::vector<KeyFrame>;

struct KeyFrame
{
    explicit KeyFrame(TaxiPathNodeEntry const* node) : Index(0), Node(node), InitialOrientation(0.0f),
        DistSinceStop(-1.0f), DistUntilStop(-1.0f), DistFromPrev(-1.0f), TimeFrom(0.0f), TimeTo(0.0f),
        Teleport(false), ArriveTime(0), DepartureTime(0), Spline(nullptr), NextDistFromPrev(0.0f), NextArriveTime(0)
    {
    }

    uint32 Index;
    TaxiPathNodeEntry const* Node;
    float InitialOrientation;
    float DistSinceStop;
    float DistUntilStop;
    float DistFromPrev;
    float TimeFrom;
    float TimeTo;
    bool Teleport;
    uint32 ArriveTime;
    uint32 DepartureTime;
    std::shared_ptr<TransportSpline> Spline;

    // Data needed for next frame
    float NextDistFromPrev;
    uint32 NextArriveTime;

    bool IsTeleportFrame() const { return Teleport; }
    bool IsStopFrame() const;
};

struct TransportTemplate
{
    TransportTemplate() : inInstance(false), pathTime(0), accelTime(0.0f), accelDist(0.0f), entry(0) { }
    ~TransportTemplate();

    std::set<uint32> mapsUsed;
    bool inInstance;
    uint32 pathTime;
    KeyFrameVec keyFrames;
    float accelTime;
    float accelDist;
    uint32 entry;
};

struct TC_GAME_API TransportAnimation
{
    TransportAnimation() : TotalTime(0) { }

    std::map<uint32, TransportAnimationEntry const*> Path;
    std::map<uint32, TransportRotationEntry const*> Rotations;
    uint32 TotalTime;

    TransportAnimationEntry const* GetAnimNode(uint32 time) const;
    TransportRotationEntry const* GetAnimRotation(uint32 time) const;
};

struct TransportSpawn
{
    ObjectGuid::LowType SpawnId = UI64LIT(0);
    uint32 TransportGameObjectId = 0; // entry in respective _template table
    uint8 PhaseUseFlags = 0;
    uint32 PhaseId = 0;
    uint32 PhaseGroup = 0;
};

class TC_GAME_API TransportMgr
{
    public:
        static TransportMgr* instance();

        void Unload();

        void LoadTransportTemplates();

        void LoadTransportAnimationAndRotation();

        void LoadTransportSpawns();

        // Creates a transport using given GameObject template entry
        Transport* CreateTransport(uint32 entry, ObjectGuid::LowType guid = UI64LIT(0), Map* map = nullptr, uint8 phaseUseFlags = 0, uint32 phaseId = 0, uint32 phaseGroupId = 0);

        // Spawns all continent transports, used at core startup
        void SpawnContinentTransports();

        // creates all transports for instance
        void CreateInstanceTransports(Map* map);

        TransportTemplate const* GetTransportTemplate(uint32 entry) const;

        TransportAnimation const* GetTransportAnimInfo(uint32 entry) const;

        TransportSpawn const* GetTransportSpawn(ObjectGuid::LowType spawnId) const;

    private:
        TransportMgr();
        ~TransportMgr();
        TransportMgr(TransportMgr const&) = delete;
        TransportMgr& operator=(TransportMgr const&) = delete;

        // Generates and precaches a path for transport to avoid generation each time transport instance is created
        void GeneratePath(GameObjectTemplate const* goInfo, TransportTemplate* transport);

        void AddPathNodeToTransport(uint32 transportEntry, uint32 timeSeg, TransportAnimationEntry const* node);

        void AddPathRotationToTransport(uint32 transportEntry, uint32 timeSeg, TransportRotationEntry const* node)
        {
            _transportAnimations[transportEntry].Rotations[timeSeg] = node;
        }

        // Container storing transport templates
        std::unordered_map<uint32, TransportTemplate> _transportTemplates;

        // Container storing transport entries to create for instanced maps
        std::unordered_map<uint32, std::set<uint32>> _instanceTransports;

        std::map<uint32, TransportAnimation> _transportAnimations;

        std::unordered_map<ObjectGuid::LowType, TransportSpawn> _transportSpawns;
};

#define sTransportMgr TransportMgr::instance()

#endif // TRANSPORTMGR_H
