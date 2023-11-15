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

#include "TransportMgr.h"
#include "Containers.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "MoveSplineInitArgs.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Spline.h"
#include "Transport.h"

TransportPathLeg::TransportPathLeg() = default;
TransportPathLeg::~TransportPathLeg() = default;
TransportPathLeg::TransportPathLeg(TransportPathLeg&&) noexcept = default;
TransportPathLeg& TransportPathLeg::operator=(TransportPathLeg&&) noexcept = default;

TransportTemplate::TransportTemplate() = default;
TransportTemplate::~TransportTemplate() = default;
TransportTemplate::TransportTemplate(TransportTemplate&&) noexcept = default;
TransportTemplate& TransportTemplate::operator=(TransportTemplate&&) noexcept = default;

Optional<Position> TransportTemplate::ComputePosition(uint32 time, TransportMovementState* moveState, size_t* legIndex) const
{
    time %= TotalPathTime;

    // find leg
    TransportPathLeg const* leg = GetLegForTime(time);
    if (!leg)
        return {};

    // find segment
    uint32 prevSegmentTime = leg->StartTimestamp;
    auto segmentItr = leg->Segments.begin();
    double distanceMoved = 0.0;
    bool isOnPause = false;
    for (; segmentItr != std::prev(leg->Segments.end()); ++segmentItr)
    {
        if (time < segmentItr->SegmentEndArrivalTimestamp)
            break;

        distanceMoved = segmentItr->DistanceFromLegStartAtEnd;
        if (time < segmentItr->SegmentEndArrivalTimestamp + segmentItr->Delay)
        {
            isOnPause = true;
            break;
        }

        prevSegmentTime = segmentItr->SegmentEndArrivalTimestamp + segmentItr->Delay;
    }

    if (!isOnPause)
        distanceMoved += CalculateDistanceMoved(
            double(time - prevSegmentTime) * 0.001,
            double(segmentItr->SegmentEndArrivalTimestamp - prevSegmentTime) * 0.001,
            segmentItr == leg->Segments.begin(),
            segmentItr == std::prev(leg->Segments.end()));

    Movement::SplineBase::index_type splineIndex;
    float splinePointProgress;
    leg->Spline->computeIndex(std::fmin(distanceMoved / leg->Spline->length(), 1.0), splineIndex, splinePointProgress);

    G3D::Vector3 pos, dir;
    leg->Spline->evaluate_percent(splineIndex, splinePointProgress, pos);
    leg->Spline->evaluate_derivative(splineIndex, splinePointProgress, dir);

    if (moveState)
        *moveState = isOnPause ? TransportMovementState::WaitingOnPauseWaypoint : TransportMovementState::Moving;

    if (legIndex)
        *legIndex = std::distance(PathLegs.data(), leg);

    return Position(pos.x, pos.y, pos.z, std::atan2(dir.y, dir.x) + float(M_PI));
}

TransportPathLeg const* TransportTemplate::GetLegForTime(uint32 time) const
{
    auto legItr = PathLegs.begin();
    while (legItr->StartTimestamp + legItr->Duration <= time)
    {
        ++legItr;

        if (legItr == PathLegs.end())
            return nullptr;
    }

    return &*legItr;
}

uint32 TransportTemplate::GetNextPauseWaypointTimestamp(uint32 time) const
{
    TransportPathLeg const* leg = GetLegForTime(time);
    if (!leg)
        return time;

    auto segmentItr = leg->Segments.begin();
    for (; segmentItr != std::prev(leg->Segments.end()); ++segmentItr)
        if (time < segmentItr->SegmentEndArrivalTimestamp + segmentItr->Delay)
            break;

    return segmentItr->SegmentEndArrivalTimestamp + segmentItr->Delay;
}

double TransportTemplate::CalculateDistanceMoved(double timePassedInSegment, double segmentDuration, bool isFirstSegment, bool isLastSegment) const
{
    if (isFirstSegment)
    {
        if (!isLastSegment)
        {
            double accelerationTime = std::fmin(AccelerationTime, segmentDuration);
            double segmentTimeAtFullSpeed = segmentDuration - accelerationTime;
            if (timePassedInSegment <= segmentTimeAtFullSpeed)
            {
                return timePassedInSegment * Speed;
            }
            else
            {
                double segmentAccelerationTime = timePassedInSegment - segmentTimeAtFullSpeed;
                double segmentAccelerationDistance = AccelerationRate * accelerationTime;
                double segmentDistanceAtFullSpeed = segmentTimeAtFullSpeed * Speed;
                return (2.0 * segmentAccelerationDistance - segmentAccelerationTime * AccelerationRate) * 0.5 * segmentAccelerationTime + segmentDistanceAtFullSpeed;
            }
        }

        return timePassedInSegment * Speed;
    }

    if (isLastSegment)
    {
        if (!isFirstSegment)
        {
            if (timePassedInSegment <= std::fmin(AccelerationTime, segmentDuration))
                return AccelerationRate * timePassedInSegment * 0.5 * timePassedInSegment;
            else
                return (timePassedInSegment - AccelerationTime) * Speed + AccelerationDistance;
        }

        return timePassedInSegment * Speed;
    }

    double accelerationTime = std::fmin(segmentDuration * 0.5, AccelerationTime);
    if (timePassedInSegment <= segmentDuration - accelerationTime)
    {
        if (timePassedInSegment <= accelerationTime)
            return AccelerationRate * timePassedInSegment * 0.5 * timePassedInSegment;
        else
            return (timePassedInSegment - AccelerationTime) * Speed + AccelerationDistance;
    }
    else
    {
        double segmentTimeSpentAccelerating = timePassedInSegment - (segmentDuration - accelerationTime);
        return (segmentDuration - 2 * accelerationTime) * Speed
            + AccelerationRate * accelerationTime * 0.5 * accelerationTime
            + (2.0 * AccelerationRate * accelerationTime - segmentTimeSpentAccelerating * AccelerationRate) * 0.5 * segmentTimeSpentAccelerating;
    }
}

TransportMgr::TransportMgr() = default;

TransportMgr::~TransportMgr() = default;

TransportMgr* TransportMgr::instance()
{
    static TransportMgr instance;
    return &instance;
}

void TransportMgr::Unload()
{
    _transportTemplates.clear();
}

void TransportMgr::LoadTransportTemplates()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT entry FROM gameobject_template WHERE type = 15 ORDER BY entry ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 transport templates. DB table `gameobject_template` has no transports!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 entry = fields[0].GetUInt32();
        GameObjectTemplate const* goInfo = sObjectMgr->GetGameObjectTemplate(entry);
        if (goInfo == nullptr)
        {
            TC_LOG_ERROR("sql.sql", "Transport {} has no associated GameObjectTemplate from `gameobject_template` , skipped.", entry);
            continue;
        }

        if (goInfo->moTransport.taxiPathID >= sTaxiPathNodesByPath.size())
        {
            TC_LOG_ERROR("sql.sql", "Transport {} (name: {}) has an invalid path specified in `gameobject_template`.`Data0` ({}) field, skipped.", entry, goInfo->name, goInfo->moTransport.taxiPathID);
            continue;
        }

        if (!goInfo->moTransport.taxiPathID)
            continue;

        if (!sTaxiPathStore.LookupEntry(goInfo->moTransport.taxiPathID))
        {
            TC_LOG_ERROR("sql.sql", "Transport {} (name: {}) has an invalid path specified in `gameobject_template`.`Data0` ({}) field, skipped.", entry, goInfo->name.c_str(), goInfo->moTransport.taxiPathID);
            continue;
        }

        bool hasValidMaps = true;
        for (uint32 mapId : _transportTemplates[entry].MapIds)
        {
            if (!sMapStore.LookupEntry(mapId))
            {
                hasValidMaps = false;
                break;
            }
        }

        if (!hasValidMaps)
        {
            TC_LOG_ERROR("sql.sql", "Transport {} (name: {}) is trying to spawn on a map which does not exist, skipped.", entry, goInfo->name.c_str());
            _transportTemplates.erase(entry);
            continue;
        }

        // paths are generated per template, saves us from generating it again in case of instanced transports
        TransportTemplate& transport = _transportTemplates[entry];

        GeneratePath(goInfo, &transport);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded {} transport templates in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void TransportMgr::LoadTransportAnimationAndRotation()
{
    for (TransportAnimationEntry const* anim : sTransportAnimationStore)
        AddPathNodeToTransport(anim->TransportID, anim->TimeIndex, anim);

    for (TransportRotationEntry const* rot : sTransportRotationStore)
        AddPathRotationToTransport(rot->GameObjectsID, rot->TimeIndex, rot);
}

void TransportMgr::LoadTransportSpawns()
{
    if (_transportTemplates.empty())
        return;

    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT guid, entry, phaseUseFlags, phaseid, phasegroup FROM transports");

    uint32 count = 0;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            ObjectGuid::LowType guid = fields[0].GetUInt64();
            uint32 entry = fields[1].GetUInt32();
            uint8 phaseUseFlags = fields[2].GetUInt8();
            uint32 phaseId = fields[3].GetUInt32();
            uint32 phaseGroupId = fields[4].GetUInt32();

            TransportTemplate const* transportTemplate = GetTransportTemplate(entry);
            if (!transportTemplate)
            {
                TC_LOG_ERROR("sql.sql", "Table `transports` have transport (GUID: {} Entry: {}) with unknown gameobject `entry` set, skipped.", guid, entry);
                continue;
            }

            if (phaseUseFlags & ~PHASE_USE_FLAGS_ALL)
            {
                TC_LOG_ERROR("sql.sql", "Table `transports` have transport (GUID: {} Entry: {}) with unknown `phaseUseFlags` set, removed unknown value.", guid, entry);
                phaseUseFlags &= PHASE_USE_FLAGS_ALL;
            }

            if (phaseUseFlags & PHASE_USE_FLAGS_ALWAYS_VISIBLE && phaseUseFlags & PHASE_USE_FLAGS_INVERSE)
            {
                TC_LOG_ERROR("sql.sql", "Table `transports` have transport (GUID: {} Entry: {}) has both `phaseUseFlags` PHASE_USE_FLAGS_ALWAYS_VISIBLE and PHASE_USE_FLAGS_INVERSE,"
                    " removing PHASE_USE_FLAGS_INVERSE.", guid, entry);
                phaseUseFlags &= ~PHASE_USE_FLAGS_INVERSE;
            }

            if (phaseGroupId && phaseId)
            {
                TC_LOG_ERROR("sql.sql", "Table `transports` have transport (GUID: {} Entry: {}) with both `phaseid` and `phasegroup` set, `phasegroup` set to 0", guid, entry);
                phaseGroupId = 0;
            }

            if (phaseId)
            {
                if (!sPhaseStore.LookupEntry(phaseId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `transports` have transport (GUID: {} Entry: {}) with `phaseid` {} does not exist, set to 0", guid, entry, phaseId);
                    phaseId = 0;
                }
            }

            if (phaseGroupId)
            {
                if (!sDB2Manager.GetPhasesForGroup(phaseGroupId))
                {
                    TC_LOG_ERROR("sql.sql", "Table `transports` have transport (GUID: {} Entry: {}) with `phaseGroup` {} does not exist, set to 0", guid, entry, phaseGroupId);
                    phaseGroupId = 0;
                }
            }

            TransportSpawn& spawn = _transportSpawns[guid];
            spawn.SpawnId = guid;
            spawn.TransportGameObjectId = entry;
            spawn.PhaseUseFlags = phaseUseFlags;
            spawn.PhaseId = phaseId;
            spawn.PhaseGroup = phaseGroupId;

            for (uint32 mapId : transportTemplate->MapIds)
                _transportsByMap[mapId].insert(&spawn);

        } while (result->NextRow());
    }

    TC_LOG_INFO("server.loading", ">> Spawned {} continent transports in {} ms", count, GetMSTimeDiffToNow(oldMSTime));
}

class SplineRawInitializer
{
public:
    SplineRawInitializer(Movement::PointsArray& points) : _points(points) { }

    void operator()(uint8& mode, bool& cyclic, Movement::PointsArray& points, int& lo, int& hi) const
    {
        mode = Movement::SplineBase::ModeCatmullrom;
        cyclic = false;
        points.assign(_points.begin(), _points.end());
        lo = 1;
        hi = points.size() - 2;
    }

    Movement::PointsArray& _points;
};

static void InitializeLeg(TransportPathLeg* leg, std::vector<TransportPathEvent>* outEvents, std::vector<TaxiPathNodeEntry const*> const& pathPoints, std::vector<TaxiPathNodeEntry const*> const& pauses,
    std::vector<TaxiPathNodeEntry const*> const& events, GameObjectTemplate const* goInfo, uint32& totalTime)
{
    Movement::PointsArray splinePath;
    std::transform(pathPoints.begin(), pathPoints.end(), std::back_inserter(splinePath), [](TaxiPathNodeEntry const* node) { return Movement::Vector3(node->Loc.X, node->Loc.Y, node->Loc.Z); });
    SplineRawInitializer initer(splinePath);
    leg->Spline = std::make_unique<TransportSpline>();
    leg->Spline->set_steps_per_segment(20);
    leg->Spline->init_spline_custom(initer);
    leg->Spline->initLengths();

    leg->Segments.resize(pauses.size() + 1);

    auto legTimeAccelDecel = [&](double dist)
    {
        double speed = double(goInfo->moTransport.moveSpeed);
        double accel = double(goInfo->moTransport.accelRate);
        double accelDist = 0.5 * speed * speed / accel;
        if (accelDist >= dist * 0.5)
            return uint32(std::sqrt(dist / accel) * 2000.0);
        else
            return uint32((dist - (accelDist + accelDist)) / speed * 1000.0 + speed / accel * 2000.0);
    };

    auto legTimeAccel = [&](double dist)
    {
        double speed = double(goInfo->moTransport.moveSpeed);
        double accel = double(goInfo->moTransport.accelRate);
        double accelDist = 0.5 * speed * speed / accel;
        if (accelDist >= dist)
            return uint32(std::sqrt((dist + dist) / accel) * 1000.0);
        else
            return uint32(((dist - accelDist) / speed + speed / accel) * 1000.0);
    };

    // Init segments
    size_t pauseItr = 0;
    size_t eventItr = 0;
    double splineLengthToPreviousNode = 0.0;
    uint32 delaySum = 0;
    if (!pauses.empty())
    {
        for (; pauseItr < pauses.size(); ++pauseItr)
        {
            auto pausePointItr = std::find(pathPoints.begin(), pathPoints.end(), pauses[pauseItr]);
            if (*pausePointItr == pathPoints.back()) // last point is a "fake" spline point, its position can never be reached so transport cannot stop there
                break;

            for (; eventItr < events.size(); ++eventItr)
            {
                auto eventPointItr = std::find(pathPoints.begin(), pathPoints.end(), events[eventItr]);
                if (eventPointItr > pausePointItr)
                    break;

                double length = leg->Spline->length(std::distance(pathPoints.begin(), eventPointItr)) - splineLengthToPreviousNode;

                uint32 splineTime = 0;
                if (pauseItr)
                    splineTime = legTimeAccelDecel(length);
                else
                    splineTime = legTimeAccel(length);

                if ((*eventPointItr)->ArrivalEventID)
                {
                    TransportPathEvent& event = outEvents->emplace_back();
                    event.Timestamp = totalTime + splineTime + leg->Duration;
                    event.EventId = (*eventPointItr)->ArrivalEventID;
                }

                if ((*eventPointItr)->DepartureEventID)
                {
                    TransportPathEvent& event = outEvents->emplace_back();
                    event.Timestamp = totalTime + splineTime + leg->Duration + (pausePointItr == eventPointItr ? (*eventPointItr)->Delay * IN_MILLISECONDS : 0);
                    event.EventId = (*eventPointItr)->DepartureEventID;
                }
            }

            double splineLengthToCurrentNode = leg->Spline->length(std::distance(pathPoints.begin(), pausePointItr));
            double length = splineLengthToCurrentNode - splineLengthToPreviousNode;
            uint32 movementTime = 0;
            if (pauseItr)
                movementTime = legTimeAccelDecel(length);
            else
                movementTime = legTimeAccel(length);

            leg->Duration += movementTime;
            leg->Segments[pauseItr].SegmentEndArrivalTimestamp = leg->Duration + delaySum;
            leg->Segments[pauseItr].Delay = (*pausePointItr)->Delay * IN_MILLISECONDS;
            leg->Segments[pauseItr].DistanceFromLegStartAtEnd = splineLengthToCurrentNode;
            delaySum += (*pausePointItr)->Delay * IN_MILLISECONDS;
            splineLengthToPreviousNode = splineLengthToCurrentNode;
        }
    }

    // Process events happening after last pause
    for (; eventItr < events.size(); ++eventItr)
    {
        auto eventPointItr = std::find(pathPoints.begin(), pathPoints.end(), events[eventItr]);
        if (*eventPointItr == pathPoints.back()) // last point is a "fake" spline node, events cannot happen there
            break;

        double length = leg->Spline->length(std::distance(pathPoints.begin(), eventPointItr)) - splineLengthToPreviousNode;
        uint32 splineTime = 0;
        if (pauseItr)
            splineTime = legTimeAccel(length);
        else
            splineTime = uint32(length / double(goInfo->moTransport.moveSpeed) * 1000.0);

        if ((*eventPointItr)->ArrivalEventID)
        {
            TransportPathEvent& event = outEvents->emplace_back();
            event.Timestamp = totalTime + splineTime + leg->Duration;
            event.EventId = (*eventPointItr)->ArrivalEventID;
        }

        if ((*eventPointItr)->DepartureEventID)
        {
            TransportPathEvent& event = outEvents->emplace_back();
            event.Timestamp = totalTime + splineTime + leg->Duration;
            event.EventId = (*eventPointItr)->DepartureEventID;
        }
    }

    // Add segment after last pause
    double length = leg->Spline->length() - splineLengthToPreviousNode;
    uint32 splineTime = 0;
    if (pauseItr)
        splineTime = legTimeAccel(length);
    else
        splineTime = uint32(length / double(goInfo->moTransport.moveSpeed) * 1000.0);

    leg->StartTimestamp = totalTime;
    leg->Duration += splineTime + delaySum;
    leg->Segments[pauseItr].SegmentEndArrivalTimestamp = leg->Duration;
    leg->Segments[pauseItr].Delay = 0;
    leg->Segments[pauseItr].DistanceFromLegStartAtEnd = leg->Spline->length();
    totalTime += leg->Segments[pauseItr].SegmentEndArrivalTimestamp + leg->Segments[pauseItr].Delay;

    for (TransportPathSegment& segment : leg->Segments)
        segment.SegmentEndArrivalTimestamp += leg->StartTimestamp;

    if (leg->Segments.size() > pauseItr + 1)
        leg->Segments.resize(pauseItr + 1);
}

void TransportMgr::GeneratePath(GameObjectTemplate const* goInfo, TransportTemplate* transport)
{
    uint32 pathId = goInfo->moTransport.taxiPathID;
    TaxiPathNodeList const& path = sTaxiPathNodesByPath[pathId];

    transport->Speed = double(goInfo->moTransport.moveSpeed);
    transport->AccelerationRate = double(goInfo->moTransport.accelRate);
    transport->AccelerationTime = transport->Speed / transport->AccelerationRate;
    transport->AccelerationDistance = 0.5 * transport->Speed * transport->Speed / transport->AccelerationRate;

    std::vector<TaxiPathNodeEntry const*> pathPoints;
    std::vector<TaxiPathNodeEntry const*> pauses;
    std::vector<TaxiPathNodeEntry const*> events;
    TransportPathLeg* leg = &transport->PathLegs.emplace_back();
    leg->MapId = path[0]->ContinentID;
    bool prevNodeWasTeleport = false;
    uint32 totalTime = 0;
    for (TaxiPathNodeEntry const* node : path)
    {
        if (node->ContinentID != leg->MapId || prevNodeWasTeleport)
        {
            InitializeLeg(leg, &transport->Events, pathPoints, pauses, events, goInfo, totalTime);

            leg = &transport->PathLegs.emplace_back();
            leg->MapId = node->ContinentID;
            pathPoints.clear();
            pauses.clear();
            events.clear();
        }

        prevNodeWasTeleport = (node->Flags & TAXI_PATH_NODE_FLAG_TELEPORT) != 0;
        pathPoints.push_back(node);
        if (node->Flags & TAXI_PATH_NODE_FLAG_STOP)
            pauses.push_back(node);

        if (node->ArrivalEventID || node->DepartureEventID)
            events.push_back(node);

        transport->MapIds.insert(node->ContinentID);
    }

    if (!leg->Spline)
        InitializeLeg(leg, &transport->Events, pathPoints, pauses, events, goInfo, totalTime);

    if (transport->MapIds.size() > 1)
        for (uint32 mapId : transport->MapIds)
            ASSERT(!sMapStore.LookupEntry(mapId)->Instanceable());

    transport->TotalPathTime = totalTime;
}

void TransportMgr::AddPathNodeToTransport(uint32 transportEntry, uint32 timeSeg, TransportAnimationEntry const* node)
{
    TransportAnimation& animNode = _transportAnimations[transportEntry];
    if (animNode.TotalTime < timeSeg)
        animNode.TotalTime = timeSeg;

    animNode.Path[timeSeg] = node;
}

void TransportMgr::AddPathRotationToTransport(uint32 transportEntry, uint32 timeSeg, TransportRotationEntry const* node)
{
    TransportAnimation& animNode = _transportAnimations[transportEntry];
    animNode.Rotations[timeSeg] = node;

    if (animNode.Path.empty() && animNode.TotalTime < timeSeg)
        animNode.TotalTime = timeSeg;
}

Transport* TransportMgr::CreateTransport(uint32 entry, Map* map, ObjectGuid::LowType guid /*= 0*/, uint8 phaseUseFlags /*= 0*/, uint32 phaseId /*= 0*/, uint32 phaseGroupId /*= 0*/)
{
    // SetZoneScript() is called after adding to map, so fetch the script using map
    if (InstanceMap* instanceMap = map->ToInstanceMap())
        if (InstanceScript* instance = instanceMap->GetInstanceScript())
            entry = instance->GetGameObjectEntry(0, entry);

    if (!entry)
        return nullptr;

    TransportTemplate const* tInfo = GetTransportTemplate(entry);
    if (!tInfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport {} will not be loaded, `transport_template` missing", entry);
        return nullptr;
    }

    if (tInfo->MapIds.find(map->GetId()) == tInfo->MapIds.end())
    {
        TC_LOG_ERROR("entities.transport", "Transport {} attempted creation on map it has no path for {}!", entry, map->GetId());
        return nullptr;
    }

    Optional<Position> startingPosition = tInfo->ComputePosition(0, nullptr, nullptr);
    if (!startingPosition)
    {
        TC_LOG_ERROR("sql.sql", "Transport {} will not be loaded, failed to compute starting position", entry);
        return nullptr;
    }

    // create transport...
    Transport* trans = new Transport();

    // ...at first waypoint
    float x = startingPosition->GetPositionX();
    float y = startingPosition->GetPositionY();
    float z = startingPosition->GetPositionZ();
    float o = startingPosition->GetOrientation();

    // initialize the gameobject base
    ObjectGuid::LowType guidLow = guid ? guid : map->GenerateLowGuid<HighGuid::Transport>();
    if (!trans->Create(guidLow, entry, x, y, z, o))
    {
        delete trans;
        return nullptr;
    }

    PhasingHandler::InitDbPhaseShift(trans->GetPhaseShift(), phaseUseFlags, phaseId, phaseGroupId);

    // use preset map for instances (need to know which instance)
    trans->SetMap(map);
    if (InstanceMap* instanceMap = map->ToInstanceMap())
        trans->m_zoneScript = instanceMap->GetInstanceScript();

    // Passengers will be loaded once a player is near
    map->AddToMap<Transport>(trans);
    return trans;
}

void TransportMgr::CreateTransportsForMap(Map* map)
{
    auto mapTransports = _transportsByMap.find(map->GetId());

    // no transports here
    if (mapTransports == _transportsByMap.end())
        return;

    // create transports
    for (TransportSpawn const* transport : mapTransports->second)
        CreateTransport(transport->TransportGameObjectId, map, transport->SpawnId, transport->PhaseUseFlags, transport->PhaseId, transport->PhaseGroup);
}

TransportTemplate const* TransportMgr::GetTransportTemplate(uint32 entry) const
{
    return Trinity::Containers::MapGetValuePtr(_transportTemplates, entry);
}

TransportAnimation const* TransportMgr::GetTransportAnimInfo(uint32 entry) const
{
    return Trinity::Containers::MapGetValuePtr(_transportAnimations, entry);
}

TransportSpawn const* TransportMgr::GetTransportSpawn(ObjectGuid::LowType spawnId) const
{
    return Trinity::Containers::MapGetValuePtr(_transportSpawns, spawnId);
}

TransportAnimationEntry const* TransportAnimation::GetPrevAnimNode(uint32 time) const
{
    if (Path.empty())
        return nullptr;

    auto itr = Path.lower_bound(time);
    if (itr != Path.begin())
        return std::prev(itr)->second;

    return Path.rbegin()->second;
}

TransportRotationEntry const* TransportAnimation::GetPrevAnimRotation(uint32 time) const
{
    if (Rotations.empty())
        return nullptr;

    auto itr = Rotations.lower_bound(time);
    if (itr != Rotations.begin())
        return std::prev(itr)->second;

    return Rotations.rbegin()->second;
}

TransportAnimationEntry const* TransportAnimation::GetNextAnimNode(uint32 time) const
{
    if (Path.empty())
        return nullptr;

    auto itr = Path.lower_bound(time);
    if (itr != Path.end())
        return itr->second;

    return Path.begin()->second;
}

TransportRotationEntry const* TransportAnimation::GetNextAnimRotation(uint32 time) const
{
    if (Rotations.empty())
        return nullptr;

    auto itr = Rotations.lower_bound(time);
    if (itr != Rotations.end())
        return itr->second;

    return Rotations.begin()->second;
}
