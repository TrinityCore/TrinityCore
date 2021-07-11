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

#include "Policies/SingletonImp.h"
#include "TransportMgr.h"
#include "Transport.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "MoveMap.h"
#include "World.h"

INSTANTIATE_SINGLETON_1(TransportMgr);

void TransportMgr::LoadTransportAnimationAndRotation()
{
    for (uint32 i = 0; i < sTransportAnimationStore.GetNumRows(); ++i)
        if (TransportAnimationEntry const* anim = sTransportAnimationStore.LookupEntry(i))
            AddPathNodeToTransport(anim->TransportEntry, anim->TimeSeg, anim);
}

TransportTemplate* TransportMgr::GetTransportTemplate(uint32 entry)
{
    auto itr = m_transportTemplates.find(entry);
    if (itr != m_transportTemplates.end())
        return &(*itr).second;

    return nullptr;
}

void TransportMgr::LoadTransportTemplates()
{
    for (uint32 entry = 1; entry <= sGOStorage.GetMaxEntry(); ++entry)
    {
        auto data = sGOStorage.LookupEntry<GameObjectInfo>(entry);
        if (data && data->type == GAMEOBJECT_TYPE_MO_TRANSPORT)
        {
            TransportTemplate& transportTemplate = m_transportTemplates[entry];
            transportTemplate.entry = entry;
            if (!GenerateWaypoints(data, transportTemplate))
                m_transportTemplates.erase(entry);
        }
    }
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

bool TransportMgr::GenerateWaypoints(GameObjectInfo const* goinfo, TransportTemplate& transportTemplate)
{
    uint32 pathid = goinfo->moTransport.taxiPathId;
    if (pathid >= sTaxiPathNodesByPath.size())
        return false;

    uint32 pathId = goinfo->moTransport.taxiPathId;
    TaxiPathNodeList const& path = sTaxiPathNodesByPath[pathId];
    std::vector<KeyFrame>& keyFrames = transportTemplate.keyFrames;
    Movement::PointsArray splinePath, allPoints;
    bool mapChange = false;
    for (size_t i = 0; i < path.size(); ++i)
        allPoints.push_back(G3D::Vector3(path[i].x, path[i].y, path[i].z));

    // Add extra points to allow derivative calculations for all path nodes
    allPoints.insert(allPoints.begin(), allPoints.front().lerp(allPoints[1], -0.2f));
    allPoints.push_back(allPoints.back().lerp(allPoints[allPoints.size() - 2], -0.2f));
    allPoints.push_back(allPoints.back().lerp(allPoints[allPoints.size() - 2], -1.0f));

    SplineRawInitializer initer(allPoints);
    TransportSpline orientationSpline;
    orientationSpline.init_spline_custom(initer);
    orientationSpline.initLengths();

    for (size_t i = 1; i < path.size() - 1; ++i)
    {
        if (!mapChange)
        {
            TaxiPathNodeEntry const& node_i = path[i];
            if (i != path.size() - 1 && (node_i.actionFlag & 1 || node_i.mapid != path[i + 1].mapid))
            {
                keyFrames.back().Teleport = true;
                mapChange = true;
            }
            else
            {
                KeyFrame k(node_i);
                G3D::Vector3 h;
                orientationSpline.evaluate_derivative(i + 1, 0.0f, h);
                k.InitialOrientation = MapManager::NormalizeOrientation(atan2(h.y, h.x) + M_PI);

                keyFrames.push_back(k);
                splinePath.push_back(G3D::Vector3(node_i.x, node_i.y, node_i.z));
                transportTemplate.mapsUsed.insert(k.Node->mapid);
            }
        }
        else
            mapChange = false;
    }

    MANGOS_ASSERT(!keyFrames.empty());

    if (transportTemplate.mapsUsed.size() > 1)
    {
        for (const auto itr : transportTemplate.mapsUsed)
            MANGOS_ASSERT(!sMapStorage.LookupEntry<MapEntry>(itr)->Instanceable());

        transportTemplate.inInstance = false;
    }
    else
        transportTemplate.inInstance = sMapStorage.LookupEntry<MapEntry>(*transportTemplate.mapsUsed.begin())->Instanceable();

    // last to first is always "teleport", even for closed paths
    keyFrames.back().Teleport = true;

    float const speed = float(goinfo->moTransport.moveSpeed);
    float const accel = float(goinfo->moTransport.accelRate);
    float const accel_dist = 0.5f * speed * speed / accel;

    transportTemplate.accelTime = speed / accel;
    transportTemplate.accelDist = accel_dist;

    int32 firstStop = -1;
    int32 lastStop = -1;

    // first cell is arrived at by teleportation :S
    keyFrames[0].DistFromPrev = 0;
    keyFrames[0].Index = 1;
    if (keyFrames[0].IsStopFrame())
    {
        firstStop = 0;
        lastStop = 0;
    }

    // find the rest of the distances between key points
    // Every path segment has its own spline
    size_t start = 0;
    for (size_t i = 1; i < keyFrames.size(); ++i)
    {
        if (keyFrames[i - 1].Teleport || i + 1 == keyFrames.size())
        {
            size_t extra = !keyFrames[i - 1].Teleport ? 1 : 0;
            TransportSpline* spline = new TransportSpline();
            spline->init_spline(&splinePath[start], i - start + extra, Movement::SplineBase::ModeCatmullrom);
            spline->initLengths();
            for (size_t j = start; j < i + extra; ++j)
            {
                keyFrames[j].Index = j - start + 1;
                keyFrames[j].DistFromPrev = spline->length(j - start, j + 1 - start);
                if (j > 0)
                    keyFrames[j - 1].NextDistFromPrev = keyFrames[j].DistFromPrev;
                keyFrames[j].Spline = spline;
            }

            if (keyFrames[i - 1].Teleport)
            {
                keyFrames[i].Index = i - start + 1;
                keyFrames[i].DistFromPrev = 0.0f;
                keyFrames[i - 1].NextDistFromPrev = 0.0f;
                keyFrames[i].Spline = spline;
            }

            start = i;
        }

        if (keyFrames[i].IsStopFrame())
        {
            // remember first stop frame
            if (firstStop == -1)
                firstStop = i;
            lastStop = i;
        }
    }

    keyFrames.back().NextDistFromPrev = keyFrames.front().DistFromPrev;

    if (firstStop == -1 || lastStop == -1)
        firstStop = lastStop = 0;

    // at stopping keyframes, we define distSinceStop == 0,
    // and distUntilStop is to the next stopping keyframe.
    // this is required to properly handle cases of two stopping frames in a row (yes they do exist)
    float tmpDist = 0.0f;
    for (size_t i = 0; i < keyFrames.size(); ++i)
    {
        int32 j = (i + lastStop) % keyFrames.size();
        if (keyFrames[j].IsStopFrame() || j == lastStop)
            tmpDist = 0.0f;
        else
            tmpDist += keyFrames[j].DistFromPrev;
        keyFrames[j].DistSinceStop = tmpDist;
    }

    tmpDist = 0.0f;
    for (int32 i = int32(keyFrames.size()) - 1; i >= 0; i--)
    {
        int32 j = (i + firstStop) % keyFrames.size();
        tmpDist += keyFrames[(j + 1) % keyFrames.size()].DistFromPrev;
        keyFrames[j].DistUntilStop = tmpDist;
        if (keyFrames[j].IsStopFrame() || j == firstStop)
            tmpDist = 0.0f;
    }

    for (auto& keyFrame : keyFrames)
    {
        float total_dist = keyFrame.DistSinceStop + keyFrame.DistUntilStop;
        if (total_dist < 2 * accel_dist) // won't reach full speed
        {
            if (keyFrame.DistSinceStop < keyFrame.DistUntilStop) // is still accelerating
            {
                // calculate accel+brake time for this short segment
                float segment_time = 2.0f * sqrt((keyFrame.DistUntilStop + keyFrame.DistSinceStop) / accel);
                // substract acceleration time
                keyFrame.TimeTo = segment_time - sqrt(2 * keyFrame.DistSinceStop / accel);
            }
            else // slowing down
                keyFrame.TimeTo = sqrt(2 * keyFrame.DistUntilStop / accel);
        }
        else if (keyFrame.DistSinceStop < accel_dist) // still accelerating (but will reach full speed)
        {
            // calculate accel + cruise + brake time for this long segment
            float segment_time = (keyFrame.DistUntilStop + keyFrame.DistSinceStop) / speed + (speed / accel);
            // substract acceleration time
            keyFrame.TimeTo = segment_time - sqrt(2 * keyFrame.DistSinceStop / accel);
        }
        else if (keyFrame.DistUntilStop < accel_dist) // already slowing down (but reached full speed)
            keyFrame.TimeTo = sqrt(2 * keyFrame.DistUntilStop / accel);
        else // at full speed
            keyFrame.TimeTo = (keyFrame.DistUntilStop / speed) + (0.5f * speed / accel);
    }

    // calculate tFrom times from tTo times
    float segmentTime = 0.0f;
    for (size_t i = 0; i < keyFrames.size(); ++i)
    {
        int32 j = (i + lastStop) % keyFrames.size();
        if (keyFrames[j].IsStopFrame() || j == lastStop)
            segmentTime = keyFrames[j].TimeTo;
        keyFrames[j].TimeFrom = segmentTime - keyFrames[j].TimeTo;
    }

    // calculate path times
    keyFrames[0].ArriveTime = 0;
    float curPathTime = 0.0f;
    if (keyFrames[0].IsStopFrame())
    {
        curPathTime = float(keyFrames[0].Node->delay);
        keyFrames[0].DepartureTime = uint32(curPathTime * IN_MILLISECONDS);
    }

    for (size_t i = 1; i < keyFrames.size(); ++i)
    {
        curPathTime += keyFrames[i - 1].TimeTo;
        if (keyFrames[i].IsStopFrame())
        {
            keyFrames[i].ArriveTime = uint32(curPathTime * IN_MILLISECONDS);
            keyFrames[i - 1].NextArriveTime = keyFrames[i].ArriveTime;
            curPathTime += float(keyFrames[i].Node->delay);
            keyFrames[i].DepartureTime = uint32(curPathTime * IN_MILLISECONDS);
        }
        else
        {
            curPathTime -= keyFrames[i].TimeTo;
            keyFrames[i].ArriveTime = uint32(curPathTime * IN_MILLISECONDS);
            keyFrames[i - 1].NextArriveTime = keyFrames[i].ArriveTime;
            keyFrames[i].DepartureTime = keyFrames[i].ArriveTime;
        }
    }

    keyFrames.back().NextArriveTime = keyFrames.back().DepartureTime;
    // the client destroys a transport by itself after a while, refresh is needed mid course
    // Feathermoon 303 & Teldrassil 293 ferries
    if (pathId == 303 || pathId == 293)
        keyFrames[12].Update = true;
    transportTemplate.pathTime = keyFrames.back().DepartureTime;

    return true;
}

void TransportMgr::AddPathNodeToTransport(uint32 transportEntry, uint32 timeSeg, TransportAnimationEntry const* node)
{
    TransportAnimation& animNode = m_transportAnimations[transportEntry];
    if (animNode.TotalTime < timeSeg)
        animNode.TotalTime = timeSeg;

    animNode.Path[timeSeg] = node;
}

TransportAnimationEntry const* TransportAnimation::GetPrevAnimNode(uint32 time) const
{
    auto itr = Path.lower_bound(time);
    if (itr != Path.end() && itr != Path.begin())
    {
        --itr;
        return itr->second;
    }

    return nullptr;
}

TransportAnimationEntry const* TransportAnimation::GetNextAnimNode(uint32 time) const
{
    auto itr = Path.lower_bound(time);
    if (itr != Path.end())
        return itr->second;

    return nullptr;
}

Transport* TransportMgr::CreateTransport(uint32 entry, Map* map /*= nullptr*/)
{
    // instance case, execute GetGameObjectEntry hook
    if (map && !entry)
        return nullptr;

    TransportTemplate const* tInfo = GetTransportTemplate(entry);
    if (!tInfo)
    {
        sLog.outErrorDb("Transport %u will not be loaded, transport template is missing", entry);
        return nullptr;
    }

    // create transport...
    Transport* trans = new Transport(*tInfo);

    // ...at first waypoint
    TaxiPathNodeEntry const* startNode = tInfo->keyFrames.begin()->Node;
    uint32 mapId = startNode->mapid;
    float x = startNode->x;
    float y = startNode->y;
    float z = startNode->z;
    float o = tInfo->keyFrames.begin()->InitialOrientation;

    // creates the Gameobject
    if (!trans->Create(entry, mapId, x, y, z, o, GO_ANIMPROGRESS_DEFAULT))
    {
        delete trans;
        return nullptr;
    }

    if (MapEntry const* mapEntry = sMapStorage.LookupEntry<MapEntry>(mapId))
    {
        if (mapEntry->Instanceable() != tInfo->inInstance)
        {
            sLog.outError("Transport %u (name: %s) attempted creation in instance map (id: %u) but it is not an instanced transport!", entry, trans->GetName(), mapId);
            delete trans;
            return nullptr;
        }
    }

    // use preset map for instances (need to know which instance)
    trans->SetLocationInstanceId(sMapMgr.GetContinentInstanceId(mapId, x, y));
    trans->SetMap(map ? map : sMapMgr.CreateMap(mapId, trans));

    // Passengers will be loaded once a player is near
    trans->GetMap()->Add<Transport>(trans);
    return trans;
}

void TransportMgr::SpawnContinentTransports()
{
    if (m_transportAnimations.empty())
        return;

    uint32 oldMSTime = WorldTimer::getMSTime();

    QueryResult* result = WorldDatabase.Query("SELECT `entry`, `period` FROM `transports`");

    uint32 count = 0;
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            uint32 entry = fields[0].GetUInt32();
            uint32 period = fields[1].GetUInt32();

            if (TransportTemplate* tInfo = GetTransportTemplate(entry))
            {
                if (period)
                {
                    // Override calculated period with more accurate db value.
                    tInfo->pathTime = period;
                    tInfo->keyFrames.back().DepartureTime = period;
                }
                
                if (!tInfo->inInstance)
                    if (CreateTransport(entry))
                        ++count;
            }

        } while (result->NextRow());
        delete result;
    }

    sLog.outString(">> Spawned %u continent transports in %u ms", count, WorldTimer::getMSTimeDiffToNow(oldMSTime));
}
