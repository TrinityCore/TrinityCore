/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Optional.h"
#include "Position.h"
#include <map>
#include <memory>
#include <unordered_map>

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

enum class TransportMovementState : uint8
{
    Moving,
    WaitingOnPauseWaypoint
};

// Represents a segment within path leg between stops
struct TransportPathSegment
{
    uint32 SegmentEndArrivalTimestamp = 0;
    uint32 Delay = 0;
    double DistanceFromLegStartAtEnd = 0.0;
};

struct TransportPathEvent
{
    uint32 Timestamp = 0;
    uint32 EventId = 0;
};

// Represents a contignuous part of transport path (without map changes or teleports)
struct TransportPathLeg
{
    TransportPathLeg();
    ~TransportPathLeg();

    TransportPathLeg(TransportPathLeg const&) = delete;
    TransportPathLeg(TransportPathLeg&&) noexcept;
    TransportPathLeg& operator=(TransportPathLeg const&) = delete;
    TransportPathLeg& operator=(TransportPathLeg&&) noexcept;

    uint32 MapId = 0;
    std::unique_ptr<TransportSpline> Spline;
    uint32 StartTimestamp = 0;
    uint32 Duration = 0;
    std::vector<TransportPathSegment> Segments;
};

struct TransportTemplate
{
    TransportTemplate();
    ~TransportTemplate();

    TransportTemplate(TransportTemplate const&) = delete;
    TransportTemplate(TransportTemplate&&) noexcept;
    TransportTemplate& operator=(TransportTemplate const&) = delete;
    TransportTemplate& operator=(TransportTemplate&&) noexcept;

    uint32 TotalPathTime = 0;
    double Speed = 0.0;
    double AccelerationRate = 0.0;
    double AccelerationTime = 0.0;
    double AccelerationDistance = 0.0;
    std::vector<TransportPathLeg> PathLegs;
    std::vector<TransportPathEvent> Events;

    Optional<Position> ComputePosition(uint32 time, TransportMovementState* moveState, size_t* legIndex) const;
    TransportPathLeg const* GetLegForTime(uint32 time) const;
    uint32 GetNextPauseWaypointTimestamp(uint32 time) const;

    double CalculateDistanceMoved(double timePassedInSegment, double segmentDuration, bool isFirstSegment, bool isLastSegment) const;

    std::set<uint32> MapIds;
    bool InInstance = false;
};

struct TC_GAME_API TransportAnimation
{
    TransportAnimation() : TotalTime(0) { }
    std::map<uint32, TransportAnimationEntry const*> Path;
    std::map<uint32, TransportRotationEntry const*> Rotations;
    uint32 TotalTime;

    TransportAnimationEntry const* GetPrevAnimNode(uint32 time) const;
    TransportRotationEntry const* GetPrevAnimRotation(uint32 time) const;

    TransportAnimationEntry const* GetNextAnimNode(uint32 time) const;
    TransportRotationEntry const* GetNextAnimRotation(uint32 time) const;
};


struct TransportSpawn
{
    ObjectGuid::LowType SpawnId = 0;
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
    Transport* CreateTransport(uint32 entry, Map* map, ObjectGuid::LowType guid = 0, uint8 phaseUseFlags = 0, uint32 phaseId = 0, uint32 phaseGroupId = 0);

    // creates all transports for map
    void CreateTransportsForMap(Map* map);

    TransportTemplate const* GetTransportTemplate(uint32 entry) const;

    TransportAnimation const* GetTransportAnimInfo(uint32 entry) const;

    TransportSpawn const* GetTransportSpawn(ObjectGuid::LowType spawnId) const;

private:
    TransportMgr();
    ~TransportMgr();
    TransportMgr(TransportMgr const&) = delete;
    TransportMgr(TransportMgr&&) = delete;
    TransportMgr& operator=(TransportMgr const&) = delete;
    TransportMgr& operator=(TransportMgr&&) = delete;

    // Generates and precaches a path for transport to avoid generation each time transport instance is created
    void GeneratePath(GameObjectTemplate const* goInfo, TransportTemplate* transport);

    void AddPathNodeToTransport(uint32 transportEntry, uint32 timeSeg, TransportAnimationEntry const* node);

    void AddPathRotationToTransport(uint32 transportEntry, uint32 timeSeg, TransportRotationEntry const* node);

    // Container storing transport templates
    std::unordered_map<uint32, TransportTemplate> _transportTemplates;

    // Container storing transport entries to create for instanced maps
    std::unordered_map<uint32, std::set<TransportSpawn*>> _transportsByMap;

    std::map<uint32, TransportAnimation> _transportAnimations;

    std::unordered_map<ObjectGuid::LowType, TransportSpawn> _transportSpawns;
};

#define sTransportMgr TransportMgr::instance()

#endif // TRANSPORTMGR_H
