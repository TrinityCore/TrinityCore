/*
 * This file is part of the CMaNGOS Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef TRANSPORTMGR_H
#define TRANSPORTMGR_H

#include <G3D/Quat.h>
#include "spline.h"
#include "DBCStores.h"
#include <map>

class Map;
class Transport;
struct GameObjectInfo;

typedef std::map<uint32, TransportAnimationEntry const*> TransportPathContainer;
// typedef std::map<uint32, TransportRotationEntry const*> TransportPathRotationContainer;

struct TransportAnimation
{
    TransportAnimation() : TotalTime(0) { }

    TransportPathContainer Path;
    // TransportPathRotationContainer Rotations;
    uint32 TotalTime;

    TransportAnimationEntry const* GetPrevAnimNode(uint32 time) const;
    TransportAnimationEntry const* GetNextAnimNode(uint32 time) const;
    // TransportRotationEntry const* GetAnimRotation(uint32 time) const; - wotlk onwards
};

typedef std::map<uint32, TransportAnimation> TransportAnimationContainer;

typedef Movement::Spline<double>                 TransportSpline;

struct KeyFrame
{
    explicit KeyFrame(TaxiPathNodeEntry const& _node) : Index(0), Node(&_node), InitialOrientation(0.0f),
        DistSinceStop(-1.0f), DistUntilStop(-1.0f), DistFromPrev(-1.0f), TimeFrom(0.0f), TimeTo(0.0f),
        Teleport(false), Update(false), ArriveTime(0), DepartureTime(0), Spline(nullptr), NextDistFromPrev(0.0f), NextArriveTime(0)
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
    bool Update;
    uint32 ArriveTime;
    uint32 DepartureTime;
    TransportSpline* Spline;

    // Data needed for next frame
    float NextDistFromPrev;
    uint32 NextArriveTime;

    bool IsTeleportFrame() const { return Teleport; }
    bool IsUpdateFrame() const { return Update; }
    bool IsStopFrame() const { return Node->actionFlag == 2; }
};

typedef std::vector<KeyFrame>  KeyFrameVec;

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

typedef std::multimap<uint32 /*mapId*/, uint32 /*guidLow*/> ElevatorTransportMap;
typedef std::pair<ElevatorTransportMap::const_iterator, ElevatorTransportMap::const_iterator> ElevatorTransportMapBounds;

class TransportMgr
{
public:

    void LoadTransportAnimationAndRotation();

    TransportAnimation const* GetTransportAnimInfo(uint32 entry) const
    {
        auto itr = m_transportAnimations.find(entry);
        if (itr != m_transportAnimations.end())
            return &itr->second;

        return nullptr;
    }

    TransportTemplate* GetTransportTemplate(uint32 entry);

    void LoadTransportTemplates();
    void SpawnContinentTransports();
    Transport* CreateTransport(uint32 entry, Map* map = nullptr);

    // elevator transports
    ElevatorTransportMapBounds GetElevatorTransportsForMap(uint32 mapId) const
    {
        return m_elevatorTransportsByMap.equal_range(mapId);
    }
    void AddElevatorTransportForMap(uint32 mapId, uint32 guidLow)
    {
        for (auto itr : m_elevatorTransportsByMap)
        {
            if (itr.first == mapId && itr.second == guidLow)
                return;
        }
        m_elevatorTransportsByMap.insert(std::make_pair(mapId, guidLow));
    }

private:
    void AddPathNodeToTransport(uint32 transportEntry, uint32 timeSeg, TransportAnimationEntry const* node);
    bool GenerateWaypoints(GameObjectInfo const* goinfo, TransportTemplate& transportTemplate);

    TransportAnimationContainer m_transportAnimations;
    std::unordered_map<uint32, TransportTemplate> m_transportTemplates;
    ElevatorTransportMap m_elevatorTransportsByMap;
};

#define sTransportMgr MaNGOS::Singleton<TransportMgr>::Instance()

#endif // TRANSPORTMGR_H
