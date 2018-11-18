/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Transport.h"
#include "CellImpl.h"
#include "Common.h"
#include "DBCStores.h"
#include "GameObjectAI.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spline.h"
#include "Totem.h"
#include "UpdateData.h"
#include "Vehicle.h"
#include "ZoneScript.h"

Transport::Transport() : GameObject(),
    _passengerTeleportItr(_passengers.begin()), _currentTransportTime(0), _destinationStopFrameTime(0),
    _alignmentTransportTime(0), _lastStopFrameTime(0), _isDynamicTransport(false), _initialRelocate(false)
{
    m_updateFlag |= UPDATEFLAG_TRANSPORT;
}

Transport::~Transport()
{
    ASSERT(_passengers.empty());
    if (m_goInfo && m_goInfo->type == GAMEOBJECT_TYPE_TRANSPORT)
        delete m_goValue.Transport.StopFrames;
}

void Transport::CleanupsBeforeDelete(bool finalCleanup /*= true*/)
{
    while (!_passengers.empty())
    {
        WorldObject* obj = *_passengers.begin();
        RemovePassenger(obj);
    }

    GameObject::CleanupsBeforeDelete(finalCleanup);
}

void Transport::AddPassenger(WorldObject* passenger)
{
    if (!IsInWorld())
        return;

    if (_passengers.insert(passenger).second)
    {
        passenger->SetTransport(this);
        passenger->m_movementInfo.transport.guid = GetGUID();
        passenger->m_movementInfo.transport.time = GetPathProgress();
        TC_LOG_DEBUG("entities.transport", "Object %s boarded transport %s.", passenger->GetName().c_str(), GetName().c_str());

        if (Unit* unit = passenger->ToUnit())
        {
            if (Guardian* guardian = unit->GetGuardianPet())
            {
                if (!guardian->IsPet() || guardian->GetCharmInfo()->GetCommandState() == COMMAND_FOLLOW)
                {
                    if (Transport* oldTransport = guardian->GetTransport())
                        oldTransport->RemovePassenger(guardian);

                    AddPassenger(guardian);
                    /// @HACK - transport models are not added to map's dynamic LoS calculations
                    ///         because the current GameObjectModel cannot be moved without recreating
                    guardian->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                }
            }
        }

        if (Player* plr = passenger->ToPlayer())
        {
            sScriptMgr->OnAddPassenger(this, plr);

            if (GetGoType() == GAMEOBJECT_TYPE_TRANSPORT)
                plr->SetTransportSpawnID(GetSpawnId());
        }
    }
}

void Transport::RemovePassenger(WorldObject* passenger)
{
    bool erased = false;
    if (_passengerTeleportItr != _passengers.end())
    {
        PassengerSet::iterator itr = _passengers.find(passenger);
        if (itr != _passengers.end())
        {
            if (itr == _passengerTeleportItr)
                ++_passengerTeleportItr;

            _passengers.erase(itr);
            erased = true;
        }
    }
    else
        erased = _passengers.erase(passenger) > 0;

    if (erased)
    {
        passenger->SetTransport(nullptr);
        passenger->m_movementInfo.transport.Reset();
        TC_LOG_DEBUG("entities.transport", "Object %s removed from transport %s.", passenger->GetName().c_str(), GetName().c_str());

        if (Unit* unit = passenger->ToUnit())
        {
            if (Guardian* guardian = unit->GetGuardianPet())
                if (!guardian->IsPet() || guardian->GetCharmInfo()->GetCommandState() == COMMAND_FOLLOW)
                {
                    if (guardian->GetTransGUID() == GetGUID())
                    {
                        RemovePassenger(guardian);
                        /// @HACK - transport models are not added to map's dynamic LoS calculations
                        ///         because the current GameObjectModel cannot be moved without recreating
                        guardian->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
                    }
                }
        }

        if (Player* plr = passenger->ToPlayer())
        {
            sScriptMgr->OnRemovePassenger(this, plr);
            plr->SetTransportSpawnID(0);
        }
    }
}

bool Transport::Create(ObjectGuid::LowType guidlow, uint32 entry, Map* map, uint32 /*phaseMask*/, Position const& pos, QuaternionData const& rotation, uint32 animprogress, GOState go_state, uint32 artKit /*= 0*/, bool dynamic, ObjectGuid::LowType spawnid)
{
    ASSERT(map);
    SetMap(map);

    SetZoneScript();
    if (GetZoneScript())
    {
        entry = GetZoneScript()->GetGameObjectEntry(m_spawnId, entry);
        if (!entry)
            return false;
    }

    // Set if this object can handle dynamic spawns
    if (!dynamic)
        SetRespawnCompatibilityMode();

    if (!Transport::CreateTransport(guidlow, entry, map->GetId(), pos, animprogress))
        return false;

    if (m_goInfo->type != GAMEOBJECT_TYPE_TRANSPORT)
    {
        TC_LOG_ERROR("entities.transport", "Transport (Spawn id: %u Entry: %u) not created.", GetSpawnId(), entry);
        return false;
    }

    m_stationaryPosition.Relocate(pos);

    GameObjectAddon const* gameObjectAddon = sObjectMgr->GetGameObjectAddon(GetSpawnId());

    SetWorldRotation(rotation.x, rotation.y, rotation.z, rotation.w);

    // For most of gameobjects is (0, 0, 0, 1) quaternion, there are only some transports with not standard rotation
    QuaternionData parentRotation;
    if (gameObjectAddon)
        parentRotation = gameObjectAddon->ParentRotation;

    SetParentRotation(parentRotation);

    SetGoArtKit(artKit);

    m_goValue.Transport.AnimationInfo = sTransportMgr->GetTransportAnimInfo(entry);
    m_goValue.Transport.StopFrames = new std::vector<uint32>();

    if (m_goInfo->transport.Timeto2ndfloor > 0)
    {
        // If we have a stop frame we also need an additional one at 0ms
        m_goValue.Transport.StopFrames->push_back(0);
        m_goValue.Transport.StopFrames->push_back(m_goInfo->transport.Timeto2ndfloor);
    }
    if (m_goInfo->transport.Timeto3rdfloor > 0)
        m_goValue.Transport.StopFrames->push_back(m_goInfo->transport.Timeto3rdfloor);
    if (m_goInfo->transport.Timeto4thfloor > 0)
        m_goValue.Transport.StopFrames->push_back(m_goInfo->transport.Timeto4thfloor);
    if (m_goInfo->transport.Timeto5thfloor > 0)
        m_goValue.Transport.StopFrames->push_back(m_goInfo->transport.Timeto5thfloor);

    _isDynamicTransport = m_goValue.Transport.StopFrames->empty();

    uint32 pathProgress = getMSTime();
    if (m_goValue.Transport.AnimationInfo)
        pathProgress -= pathProgress % GetTransportPeriod();

    uint32 stopTimer = 0;
    if (m_goInfo->transport.startOpen)
    {
        SetGoState(GO_STATE_TRANSPORT_STOPPED);
        stopTimer = m_goValue.Transport.StopFrames->at(m_goInfo->transport.startOpen - 1);
        _initialRelocate = true;
    }
    else
        SetGoState(GO_STATE_TRANSPORT_ACTIVE);

    SetPathProgress(pathProgress + stopTimer);

    SetDestinationStopFrameTime(stopTimer);
    SetCurrentTransportTime(stopTimer);

    if (gameObjectAddon && gameObjectAddon->InvisibilityValue)
    {
        m_invisibility.AddFlag(gameObjectAddon->invisibilityType);
        m_invisibility.AddValue(gameObjectAddon->invisibilityType, gameObjectAddon->InvisibilityValue);
    }

    LastUsedScriptID = GetGOInfo()->ScriptId;
    AIM_Initialize();

    if (spawnid)
        m_spawnId = spawnid;

    return true;
}

bool Transport::CreateTransport(ObjectGuid::LowType guidlow, uint32 entry, uint32 mapid, Position const& pos, uint32 animprogress)
{
    Relocate(pos);

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "Transport (GUID: %u) not created. Suggested coordinates isn't valid %s",
            guidlow, pos.ToString().c_str());
        return false;
    }

    Object::_Create(guidlow, 0, HighGuid::Transport);

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport not created: entry in `gameobject_template` not found, guidlow: %u map: %u (Position: %s) ang: %f", guidlow, mapid, pos.ToString().c_str());
        return false;
    }

    m_goInfo = goinfo;
    m_goTemplateAddon = sObjectMgr->GetGameObjectTemplateAddon(entry);

    if (m_goTemplateAddon)
    {
        SetFaction(m_goTemplateAddon->faction);
        SetUInt32Value(GAMEOBJECT_FLAGS, m_goTemplateAddon->flags);
    }

    SetObjectScale(goinfo->size);
    SetEntry(goinfo->entry);
    SetDisplayId(goinfo->displayId);
    SetGoType(GameobjectTypes(goinfo->type));
    SetGoAnimProgress(animprogress);
    SetName(goinfo->name);

    m_model = CreateModel();
    return true;
}

void Transport::Update(uint32 diff)
{
    GameObject::Update(diff);

    if (!IsInWorld())
        return;

    if (!m_goValue.Transport.AnimationInfo)
        return;

    if (_initialRelocate)
    {
        RelocateToProgress(GetCurrentTransportTime());
        _initialRelocate = false;
    }

    if (IsDynamicTransport())
    {
        SetPathProgress(GetPathProgress() + diff);

        SetCurrentTransportTime(GetCurrentTransportTime() + diff);
        if (GetCurrentTransportTime() >= GetTransportPeriod())
            SetCurrentTransportTime(GetCurrentTransportTime() % GetTransportPeriod());
    }
    else
    {
        if (GetGoState() == GO_STATE_TRANSPORT_ACTIVE)
        {
            // waiting at it's destination for state change, do nothing
            if (GetCurrentTransportTime() == GetDestinationStopFrameTime())
                return;

            SetPathProgress(GetPathProgress() + diff);

            // GOState has changed before previous state was reached, move to new destination immediately
            if (GetCurrentTransportTime() < GetDestinationStopFrameTime())
                SetCurrentTransportTime(0);
            else if (GetCurrentTransportTime() + diff < GetTransportPeriod())
                SetCurrentTransportTime(GetCurrentTransportTime() + diff);
            else
                SetCurrentTransportTime(0);
        }
        else
        {
            // waiting at it's destination for state change, do nothing
            if (GetCurrentTransportTime() == GetDestinationStopFrameTime())
                return;

            int32 currentTime = GetCurrentTransportTime();
            int32 destinationTime = GetDestinationStopFrameTime();
            bool backwardsMovement = destinationTime < currentTime;

            SetPathProgress(GetPathProgress() + std::max(0, int32(backwardsMovement ? (diff * -1) : diff)));

            if (!backwardsMovement)
            {
                // GOState has changed before previous state was reached, move to new destination immediately
                if (currentTime > destinationTime)
                    SetCurrentTransportTime(destinationTime);
                else if (int32(currentTime + diff) < destinationTime)
                    SetCurrentTransportTime(currentTime + diff);
                else
                {
                    SetCurrentTransportTime(destinationTime);
                    SetAlignmentTransportTime(0);
                }
            }
            else
            {
                uint32 timeDiff = diff;
                // Skipping multiple stop frames while moving to frame 0. Align the steps to the travel time.
                if (uint32 alignmentTime = GetAlightmentTransportTime())
                {
                    float alignmentPercentage = (float)alignmentTime / GetLastStopFrameTime();
                    timeDiff += diff * alignmentPercentage;
                }

                // GOState has changed before previous state was reached, move to new destination immediately
                if (currentTime < destinationTime)
                    currentTime = destinationTime;
                else if (int32(currentTime - timeDiff) > destinationTime)
                    currentTime -= timeDiff;
                else
                {
                    currentTime = destinationTime;
                    SetAlignmentTransportTime(0);
                }

                SetCurrentTransportTime(currentTime);
            }
        }
    }

    RelocateToProgress(GetCurrentTransportTime());
}

void Transport::RelocateToProgress(uint32 progress)
{
    TransportAnimationEntry const* curr = nullptr;
    TransportAnimationEntry const* next = nullptr;
    float percPos = 0.0f;

    if (m_goValue.Transport.AnimationInfo->GetAnimNode(progress, curr, next, percPos))
    {
        // curr node offset
        G3D::Vector3 pos = G3D::Vector3(curr->X, curr->Y, curr->Z);

        // move by percentage of segment already passed
        pos += G3D::Vector3(percPos * (next->X - curr->X), percPos * (next->Y - curr->Y), percPos * (next->Z - curr->Z));

        // rotate path by PathRotation
        // PathRotation in db is only simple orientation rotation, so don't use sophisticated and not working code
        // reminder: WorldRotation only influences model rotation, not the path
        float sign = GetFloatValue(GAMEOBJECT_PARENTROTATION + 2) >= 0.0f ? 1.0f : -1.0f;
        float pathRotAngle = sign * 2.0f * acos(GetFloatValue(GAMEOBJECT_PARENTROTATION + 3));
        float cs = cos(pathRotAngle), sn = sin(pathRotAngle);
        float nx = pos.x * cs - pos.y * sn;
        float ny = pos.x * sn + pos.y * cs;

        pos.x = nx;
        pos.y = ny;

        // add stationary position to the calculated offset
        pos += G3D::Vector3(GetStationaryX(), GetStationaryY(), GetStationaryZ());

        // rotate by AnimRotation at current segment
        // AnimRotation in dbc is only simple orientation rotation, so don't use sophisticated and not working code
        QuaternionData currRot = QuaternionData();
        QuaternionData nextRot = QuaternionData();
        float percRot = 0.0f;

        m_goValue.Transport.AnimationInfo->GetAnimRotation(progress, currRot, nextRot, percRot);

        float signCurr = currRot.z >= 0.0f ? 1.0f : -1.0f;
        float oriRotAngleCurr = signCurr * 2.0f * acos(currRot.w);
        float signNext = nextRot.z >= 0.0f ? 1.0f : -1.0f;
        float oriRotAngleNext = signNext * 2.0f * acos(nextRot.w);
        float oriRotAngle = oriRotAngleCurr + percRot * (oriRotAngleNext - oriRotAngleCurr);

        // check if position is valid
        if (!Trinity::IsValidMapCoord(pos.x, pos.y, pos.z))
            return;

        GetMap()->GameObjectRelocation(this, pos.x, pos.y, pos.z, NormalizeOrientation(GetStationaryO() + oriRotAngle));

        UpdatePassengerPositions(_passengers);
    }
}

void Transport::UpdatePassengerPositions(PassengerSet& passengers)
{
    for (PassengerSet::iterator itr = passengers.begin(); itr != passengers.end(); ++itr)
    {
        WorldObject* passenger = *itr;
        // transport teleported but passenger not yet (can happen for players)
        if (passenger->GetMap() != GetMap())
            continue;

        // if passenger is on vehicle we have to assume the vehicle is also on transport
        // and its the vehicle that will be updating its passengers
        if (Unit* unit = passenger->ToUnit())
        {
            if (unit->GetVehicle())
                continue;

            // if spline enabled, position will be updated in Unit::UpdateSplinePosition
            if (unit->IsSplineEnabled())
                continue;
        }

        // Do not use Unit::UpdatePosition here, we don't want to remove auras
        // as if regular movement occurred
        float x, y, z, o;
        passenger->m_movementInfo.transport.pos.GetPosition(x, y, z, o);
        CalculatePassengerPosition(x, y, z, &o);
        switch (passenger->GetTypeId())
        {
            case TYPEID_UNIT:
            {
                Creature* creature = passenger->ToCreature();
                GetMap()->CreatureRelocation(creature, x, y, z, o, false);
                creature->GetTransportHomePosition(x, y, z, o);
                CalculatePassengerPosition(x, y, z, &o);
                creature->SetHomePosition(x, y, z, o);
                break;
            }
            case TYPEID_PLAYER:
                GetMap()->PlayerRelocation(passenger->ToPlayer(), x, y, z, o);
                break;
            case TYPEID_GAMEOBJECT:
                GetMap()->GameObjectRelocation(passenger->ToGameObject(), x, y, z, o, false);
                passenger->ToGameObject()->RelocateStationaryPosition(x, y, z, o);
                break;
            case TYPEID_DYNAMICOBJECT:
                GetMap()->DynamicObjectRelocation(passenger->ToDynObject(), x, y, z, o);
                break;
            default:
                break;
        }

        if (Unit* unit = passenger->ToUnit())
            if (Vehicle* vehicle = unit->GetVehicleKit())
                vehicle->RelocatePassengers();
    }
}

uint32 Transport::GetTransportPeriod() const
{
    ASSERT(m_goInfo->type == GAMEOBJECT_TYPE_TRANSPORT);
    if (m_goValue.Transport.AnimationInfo)
        return m_goValue.Transport.AnimationInfo->TotalTime;

    return 0;
}

void Transport::SetTransportState(GOState state, uint32 stopFrame /*= 0*/)
{
    // Do not change the transport state before reaching the last selected destination
    if (GetCurrentTransportTime() != GetDestinationStopFrameTime())
        return;

    ASSERT(m_goInfo->type == GAMEOBJECT_TYPE_TRANSPORT);

    uint32 stopTimer = 0;
    uint32 backwardsTimer = 0;

    if (state == GO_STATE_TRANSPORT_ACTIVE)
    {
        if (GetGoState() >= GO_STATE_TRANSPORT_STOPPED)
            stopTimer = m_goValue.Transport.StopFrames->at(GetGoState() - GO_STATE_TRANSPORT_STOPPED);

        SetUInt32Value(GAMEOBJECT_LEVEL, getMSTime() + stopTimer);
    }
    else
    {
        ASSERT(state < GOState(GO_STATE_TRANSPORT_STOPPED + MAX_GO_STATE_TRANSPORT_STOP_FRAMES));
        ASSERT(stopFrame < m_goValue.Transport.StopFrames->size());

        stopTimer = m_goValue.Transport.StopFrames->at(stopFrame);

        // Handling backwards movement. According to retail tests, a transport that returns to stop frame 0 is using the time between frame 0 and 1
        if (!stopTimer)
            backwardsTimer = m_goValue.Transport.StopFrames->at(stopFrame + 1);

        // forward movement. target frame time - current frame time
        if (GetCurrentTransportTime() < stopTimer)
            SetUInt32Value(GAMEOBJECT_LEVEL, getMSTime() + stopTimer - GetCurrentTransportTime());
        else if (backwardsTimer)
            SetUInt32Value(GAMEOBJECT_LEVEL, getMSTime() + backwardsTimer);
        else
            SetUInt32Value(GAMEOBJECT_LEVEL, getMSTime() + GetCurrentTransportTime() - stopTimer);

        state = GOState(GO_STATE_TRANSPORT_STOPPED + stopFrame);
    }

    uint32 pathProgress = getMSTime();
    if (m_goValue.Transport.AnimationInfo)
        pathProgress -= pathProgress % GetTransportPeriod();

    SetPathProgress(pathProgress + stopTimer + backwardsTimer);
    SetDestinationStopFrameTime(stopTimer);
    SetLastStopFrameTime(GetCurrentTransportTime());
    if (GetCurrentTransportTime() > backwardsTimer)
        SetAlignmentTransportTime(backwardsTimer);

    SetGoState(state);
}

MapTransport::MapTransport() : Transport(),
    _transportInfo(nullptr), _isMoving(true), _pendingStop(false),
    _triggeredArrivalEvent(false), _triggeredDepartureEvent(false),
    _delayedAddModel(false), _delayedTeleport(false)
{
}

MapTransport::~MapTransport()
{
    UnloadStaticPassengers();
}

bool MapTransport::CreateMapTransport(ObjectGuid::LowType guidlow, uint32 entry, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress)
{
    if (!Transport::CreateTransport(guidlow, entry, mapid, Position(x, y, z, ang), animprogress))
        return false;

    TransportTemplate const* tInfo = sTransportMgr->GetTransportTemplate(entry);
    if (!tInfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport %u (name: %s) will not be created, missing `transport_template` entry.", entry, m_goInfo->name.c_str());
        return false;
    }

    _transportInfo = tInfo;

    // initialize waypoints
    _nextFrame = tInfo->keyFrames.begin();
    _currentFrame = _nextFrame++;
    _triggeredArrivalEvent = false;
    _triggeredDepartureEvent = false;

    m_goValue.Transport.PathProgress = 0;
    SetPeriod(tInfo->pathTime);
    SetGoState(!m_goInfo->moTransport.canBeStopped ? GO_STATE_READY : GO_STATE_ACTIVE);
    SetWorldRotation(0.0f, 0.0f, 0.0f, 1.0f);
    SetParentRotation(QuaternionData());

    m_model = CreateModel();
    return true;
}

void MapTransport::CleanupsBeforeDelete(bool finalCleanup /*= true*/)
{
    UnloadStaticPassengers();

    Transport::CleanupsBeforeDelete(finalCleanup);
}

void MapTransport::Update(uint32 diff)
{
    uint32 const positionUpdateDelay = 200;

    if (AI())
        AI()->UpdateAI(diff);
    else if (!AIM_Initialize())
        TC_LOG_ERROR("entities.transport", "Could not initialize GameObjectAI for Transport");

    if (GetKeyFrames().size() <= 1)
        return;

    if (IsMoving() || !_pendingStop)
        m_goValue.Transport.PathProgress += diff;

    uint32 timer = m_goValue.Transport.PathProgress % GetTransportPeriod();
    bool justStopped = false;

    // Set current waypoint
    // Desired outcome: _currentFrame->DepartureTime < timer < _nextFrame->ArriveTime
    // ... arrive | ... delay ... | departure
    //      event /         event /
    for (;;)
    {
        if (timer >= _currentFrame->ArriveTime)
        {
            if (!_triggeredArrivalEvent)
            {
                DoEventIfAny(*_currentFrame, false);
                _triggeredArrivalEvent = true;
            }

            if (timer < _currentFrame->DepartureTime)
            {
                justStopped = IsMoving();
                SetMoving(false);
                if (_pendingStop && GetGoState() != GO_STATE_READY)
                {
                    SetGoState(GO_STATE_READY);
                    m_goValue.Transport.PathProgress = (m_goValue.Transport.PathProgress / GetTransportPeriod());
                    m_goValue.Transport.PathProgress *= GetTransportPeriod();
                    m_goValue.Transport.PathProgress += _currentFrame->ArriveTime;
                }
                break;  // its a stop frame and we are waiting
            }
        }

        if (timer >= _currentFrame->DepartureTime && !_triggeredDepartureEvent)
        {
            DoEventIfAny(*_currentFrame, true); // departure event
            _triggeredDepartureEvent = true;
        }

        // not waiting anymore
        SetMoving(true);

        // Enable movement
        if (GetGOInfo()->moTransport.canBeStopped)
            SetGoState(GO_STATE_ACTIVE);

        if (timer >= _currentFrame->DepartureTime && timer < _currentFrame->NextArriveTime)
            break;  // found current waypoint

        MoveToNextWaypoint();

        sScriptMgr->OnRelocate(this, _currentFrame->Node->NodeIndex, _currentFrame->Node->MapID, _currentFrame->Node->LocX, _currentFrame->Node->LocY, _currentFrame->Node->LocZ);

        TC_LOG_DEBUG("entities.transport", "Transport %u (%s) moved to node %u %u %f %f %f", GetEntry(), GetName().c_str(), _currentFrame->Node->NodeIndex, _currentFrame->Node->MapID, _currentFrame->Node->LocX, _currentFrame->Node->LocY, _currentFrame->Node->LocZ);

        // Departure event
        if (_currentFrame->IsTeleportFrame())
            if (TeleportTransport(_nextFrame->Node->MapID, _nextFrame->Node->LocX, _nextFrame->Node->LocY, _nextFrame->Node->LocZ, _nextFrame->InitialOrientation))
                return; // Update more in new map thread
    }

    // Add model to map after we are fully done with moving maps
    if (_delayedAddModel)
    {
        _delayedAddModel = false;
        if (m_model)
            GetMap()->InsertGameObjectModel(*m_model);
    }

    // Set position
    _positionChangeTimer.Update(diff);
    if (_positionChangeTimer.Passed())
    {
        _positionChangeTimer.Reset(positionUpdateDelay);
        if (IsMoving())
        {
            float t = !justStopped ? CalculateSegmentPos(float(timer) * 0.001f) : 1.0f;
            G3D::Vector3 pos, dir;
            _currentFrame->Spline->evaluate_percent(_currentFrame->Index, t, pos);
            _currentFrame->Spline->evaluate_derivative(_currentFrame->Index, t, dir);
            UpdatePosition(pos.x, pos.y, pos.z, std::atan2(dir.y, dir.x) + float(M_PI));
        }
        else if (justStopped)
            UpdatePosition(_currentFrame->Node->LocX, _currentFrame->Node->LocY, _currentFrame->Node->LocZ, _currentFrame->InitialOrientation);
        else
        {
            /* There are four possible scenarios that trigger loading/unloading passengers:
              1. transport moves from inactive to active grid
              2. the grid that transport is currently in becomes active
              3. transport moves from active to inactive grid
              4. the grid that transport is currently in unloads
            */
            bool gridActive = GetMap()->IsGridLoaded(GetPositionX(), GetPositionY());

            if (_staticPassengers.empty() && gridActive) // 2.
                LoadStaticPassengers();
            else if (!_staticPassengers.empty() && !gridActive)
                // 4. - if transports stopped on grid edge, some passengers can remain in active grids
                //      unload all static passengers otherwise passengers won't load correctly when the grid that transport is currently in becomes active
                UnloadStaticPassengers();
        }
    }

    sScriptMgr->OnTransportUpdate(this, diff);
}

void MapTransport::DelayedUpdate(uint32 /*diff*/)
{
    if (GetKeyFrames().size() <= 1)
        return;

    DelayedTeleportTransport();
}

void MapTransport::RemovePassenger(WorldObject* passenger)
{
    bool erased = false;
    if (_passengerTeleportItr != _passengers.end())
    {
        PassengerSet::iterator itr = _passengers.find(passenger);
        if (itr != _passengers.end())
        {
            if (itr == _passengerTeleportItr)
                ++_passengerTeleportItr;

            _passengers.erase(itr);
            erased = true;
        }
    }
    else
        erased = _passengers.erase(passenger) > 0;

    if (erased || _staticPassengers.erase(passenger)) // static passenger can remove itself in case of grid unload
    {
        passenger->SetTransport(nullptr);
        passenger->m_movementInfo.transport.Reset();
        TC_LOG_DEBUG("entities.transport", "Object %s removed from transport %s.", passenger->GetName().c_str(), GetName().c_str());

        if (Unit* unit = passenger->ToUnit())
            if (Guardian* guardian = unit->GetGuardianPet())
                if (!guardian->IsPet() || guardian->GetCharmInfo()->GetCommandState() == COMMAND_FOLLOW)
                    if (guardian->GetTransGUID() == GetGUID())
                        RemovePassenger(guardian);

        if (Player* plr = passenger->ToPlayer())
        {
            sScriptMgr->OnRemovePassenger(this, plr);
            plr->SetFallInformation(0, plr->GetPositionZ());
        }
    }
}

Creature* MapTransport::CreateNPCPassenger(ObjectGuid::LowType guid, CreatureData const* data)
{
    Map* map = GetMap();
    if (map->GetCreatureRespawnTime(guid))
        return nullptr;

    Creature* creature = new Creature();

    if (!creature->LoadFromDB(guid, map, false, false))
    {
        delete creature;
        return nullptr;
    }

    float x, y, z, o;
    data->spawnPoint.GetPosition(x, y, z, o);

    creature->SetTransport(this);
    creature->m_movementInfo.transport.guid = GetGUID();
    creature->m_movementInfo.transport.time = GetPathProgress();
    creature->m_movementInfo.transport.pos.Relocate(x, y, z, o);
    CalculatePassengerPosition(x, y, z, &o);
    creature->Relocate(x, y, z, o);
    creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());
    creature->SetTransportHomePosition(creature->m_movementInfo.transport.pos);

    /// @HACK - transport models are not added to map's dynamic LoS calculations
    ///         because the current GameObjectModel cannot be moved without recreating
    creature->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

    if (!creature->IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "Creature (guidlow %d, entry %d) not created. Suggested coordinates aren't valid (X: %f Y: %f)",creature->GetGUID().GetCounter(),creature->GetEntry(),creature->GetPositionX(),creature->GetPositionY());
        delete creature;
        return nullptr;
    }

    PhasingHandler::InitDbPhaseShift(creature->GetPhaseShift(), data->phaseUseFlags, data->phaseId, data->phaseGroup);
    PhasingHandler::InitDbVisibleMapId(creature->GetPhaseShift(), data->terrainSwapMap);

    if (!map->AddToMap(creature))
    {
        delete creature;
        return nullptr;
    }

    _staticPassengers.insert(creature);
    sScriptMgr->OnAddCreaturePassenger(this, creature);
    return creature;
}

GameObject* MapTransport::CreateGOPassenger(ObjectGuid::LowType guid, GameObjectData const* data)
{
    ASSERT(data);

    Map* map = GetMap();
    if (map->GetGORespawnTime(guid))
        return nullptr;

    GameObject* go = nullptr;
    if (sObjectMgr->GetGameObjectTypeByEntry(data->id) == GAMEOBJECT_TYPE_TRANSPORT)
        go = new Transport();
    else
        go = new GameObject();

    if (!go->LoadFromDB(guid, map, false))
    {
        delete go;
        return nullptr;
    }

    ASSERT(data);

    float x, y, z, o;
    data->spawnPoint.GetPosition(x, y, z, o);

    go->SetTransport(this);
    go->m_movementInfo.transport.guid = GetGUID();
    go->m_movementInfo.transport.time = GetPathProgress();
    go->m_movementInfo.transport.pos.Relocate(x, y, z, o);
    CalculatePassengerPosition(x, y, z, &o);
    go->Relocate(x, y, z, o);
    go->RelocateStationaryPosition(x, y, z, o);

    if (!go->IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "GameObject (guidlow %d, entry %d) not created. Suggested coordinates aren't valid (X: %f Y: %f)", go->GetGUID().GetCounter(), go->GetEntry(), go->GetPositionX(), go->GetPositionY());
        delete go;
        return nullptr;
    }

    PhasingHandler::InitDbPhaseShift(go->GetPhaseShift(), data->phaseUseFlags, data->phaseId, data->phaseGroup);
    PhasingHandler::InitDbVisibleMapId(go->GetPhaseShift(), data->terrainSwapMap);

    if (!map->AddToMap(go))
    {
        delete go;
        return nullptr;
    }

    _staticPassengers.insert(go);
    return go;
}

TempSummon* MapTransport::SummonPassenger(uint32 entry, Position const& pos, TempSummonType summonType, SummonPropertiesEntry const* properties /*= nullptr*/, uint32 duration /*= 0*/, Unit* summoner /*= nullptr*/, uint32 spellId /*= 0*/, uint32 vehId /*= 0*/)
{
    Map* map = FindMap();
    if (!map)
        return nullptr;

    uint32 mask = UNIT_MASK_SUMMON;
    if (properties)
    {
        switch (properties->Category)
        {
            case SUMMON_CATEGORY_PET:
                mask = UNIT_MASK_GUARDIAN;
                break;
            case SUMMON_CATEGORY_PUPPET:
                mask = UNIT_MASK_PUPPET;
                break;
            case SUMMON_CATEGORY_VEHICLE:
                mask = UNIT_MASK_MINION;
                break;
            case SUMMON_CATEGORY_WILD:
            case SUMMON_CATEGORY_ALLY:
            case SUMMON_CATEGORY_UNK:
            {
                switch (properties->Type)
                {
                    case SUMMON_TYPE_MINION:
                    case SUMMON_TYPE_GUARDIAN:
                    case SUMMON_TYPE_GUARDIAN2:
                        mask = UNIT_MASK_GUARDIAN;
                        break;
                    case SUMMON_TYPE_TOTEM:
                    case SUMMON_TYPE_LIGHTWELL:
                        mask = UNIT_MASK_TOTEM;
                        break;
                    case SUMMON_TYPE_VEHICLE:
                    case SUMMON_TYPE_VEHICLE2:
                        mask = UNIT_MASK_SUMMON;
                        break;
                    case SUMMON_TYPE_MINIPET:
                        mask = UNIT_MASK_MINION;
                        break;
                    default:
                        break;
                }
                break;
            }
            default:
                return nullptr;
        }
    }

    TempSummon* summon = nullptr;
    switch (mask)
    {
        case UNIT_MASK_SUMMON:
            summon = new TempSummon(properties, summoner, false);
            break;
        case UNIT_MASK_GUARDIAN:
            summon = new Guardian(properties, summoner, false);
            break;
        case UNIT_MASK_PUPPET:
            summon = new Puppet(properties, summoner);
            break;
        case UNIT_MASK_TOTEM:
            summon = new Totem(properties, summoner);
            break;
        case UNIT_MASK_MINION:
            summon = new Minion(properties, summoner, false);
            break;
    }

    float x, y, z, o;
    pos.GetPosition(x, y, z, o);
    CalculatePassengerPosition(x, y, z, &o);

    if (!summon->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, 0, entry, { x, y, z, o }, nullptr, vehId))
    {
        delete summon;
        return nullptr;
    }

    PhasingHandler::InheritPhaseShift(summon, summoner ? static_cast<WorldObject*>(summoner) : static_cast<WorldObject*>(this));

    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, spellId);

    summon->SetTransport(this);
    summon->m_movementInfo.transport.guid = GetGUID();
    summon->m_movementInfo.transport.pos.Relocate(pos);
    summon->m_movementInfo.transport.time = GetPathProgress();
    summon->Relocate(x, y, z, o);
    summon->SetHomePosition(x, y, z, o);
    summon->SetTransportHomePosition(pos);

    /// @HACK - transport models are not added to map's dynamic LoS calculations
    ///         because the current GameObjectModel cannot be moved without recreating
    summon->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

    summon->InitStats(duration);

    if (!map->AddToMap<Creature>(summon))
    {
        delete summon;
        return nullptr;
    }

    _staticPassengers.insert(summon);

    summon->InitSummon();
    summon->SetTempSummonType(summonType);

    return summon;
}

void MapTransport::UpdatePosition(float x, float y, float z, float o)
{
    bool newActive = GetMap()->IsGridLoaded(x, y);
    Cell oldCell(GetPositionX(), GetPositionY());

    Relocate(x, y, z, o);
    m_stationaryPosition.SetOrientation(o);
    UpdateModelPosition();

    UpdatePassengerPositions(_passengers);

    /* There are four possible scenarios that trigger loading/unloading passengers:
      1. transport moves from inactive to active grid
      2. the grid that transport is currently in becomes active
      3. transport moves from active to inactive grid
      4. the grid that transport is currently in unloads
    */
    if (_staticPassengers.empty() && newActive) // 1.
        LoadStaticPassengers();
    else if (!_staticPassengers.empty() && !newActive && oldCell.DiffGrid(Cell(GetPositionX(), GetPositionY()))) // 3.
        UnloadStaticPassengers();
    else
        UpdatePassengerPositions(_staticPassengers);
    // 4. is handed by grid unload
}

void MapTransport::LoadStaticPassengers()
{
    if (uint32 mapId = GetGOInfo()->moTransport.mapID)
    {
        CellObjectGuidsMap const& cells = sObjectMgr->GetMapObjectGuids(mapId, GetMap()->GetSpawnMode());
        CellGuidSet::const_iterator guidEnd;
        for (CellObjectGuidsMap::const_iterator cellItr = cells.begin(); cellItr != cells.end(); ++cellItr)
        {
            // Creatures on transport
            guidEnd = cellItr->second.creatures.end();
            for (CellGuidSet::const_iterator guidItr = cellItr->second.creatures.begin(); guidItr != guidEnd; ++guidItr)
                CreateNPCPassenger(*guidItr, sObjectMgr->GetCreatureData(*guidItr));

            // GameObjects on transport
            guidEnd = cellItr->second.gameobjects.end();
            for (CellGuidSet::const_iterator guidItr = cellItr->second.gameobjects.begin(); guidItr != guidEnd; ++guidItr)
                CreateGOPassenger(*guidItr, sObjectMgr->GetGameObjectData(*guidItr));
        }
    }
}

void MapTransport::UnloadStaticPassengers()
{
    while (!_staticPassengers.empty())
    {
        WorldObject* obj = *_staticPassengers.begin();
        obj->AddObjectToRemoveList();   // also removes from _staticPassengers
    }
}

void MapTransport::EnableMovement(bool enabled)
{
    if (!GetGOInfo()->moTransport.canBeStopped)
        return;

    _pendingStop = !enabled;
}

void MapTransport::MoveToNextWaypoint()
{
    // Clear events flagging
    _triggeredArrivalEvent = false;
    _triggeredDepartureEvent = false;

    // Set frames
    _currentFrame = _nextFrame++;
    if (_nextFrame == GetKeyFrames().end())
        _nextFrame = GetKeyFrames().begin();
}

float MapTransport::CalculateSegmentPos(float now)
{
    KeyFrame const& frame = *_currentFrame;
    const float speed = float(m_goInfo->moTransport.moveSpeed);
    const float accel = float(m_goInfo->moTransport.accelRate);
    float timeSinceStop = frame.TimeFrom + (now - (1.0f/IN_MILLISECONDS) * frame.DepartureTime);
    float timeUntilStop = frame.TimeTo - (now - (1.0f/IN_MILLISECONDS) * frame.DepartureTime);
    float segmentPos, dist;
    float accelTime = _transportInfo->accelTime;
    float accelDist = _transportInfo->accelDist;
    // calculate from nearest stop, less confusing calculation...
    if (timeSinceStop < timeUntilStop)
    {
        if (timeSinceStop < accelTime)
            dist = 0.5f * accel * timeSinceStop * timeSinceStop;
        else
            dist = accelDist + (timeSinceStop - accelTime) * speed;
        segmentPos = dist - frame.DistSinceStop;
    }
    else
    {
        if (timeUntilStop < _transportInfo->accelTime)
            dist = 0.5f * accel * timeUntilStop * timeUntilStop;
        else
            dist = accelDist + (timeUntilStop - accelTime) * speed;
        segmentPos = frame.DistUntilStop - dist;
    }

    return segmentPos / frame.NextDistFromPrev;
}

bool MapTransport::TeleportTransport(uint32 newMapid, float x, float y, float z, float o)
{
    Map const* oldMap = GetMap();

    if (oldMap->GetId() != newMapid)
    {
        _delayedTeleport = true;
        UnloadStaticPassengers();
        return true;
    }
    else
    {
        UpdatePosition(x, y, z, o);

        // Teleport players, they need to know it
        for (PassengerSet::iterator itr = _passengers.begin(); itr != _passengers.end(); ++itr)
        {
            if ((*itr)->GetTypeId() == TYPEID_PLAYER)
            {
                // will be relocated in UpdatePosition of the vehicle
                if (Unit* veh = (*itr)->ToUnit()->GetVehicleBase())
                    if (veh->GetTransport() == this)
                        continue;

                float destX, destY, destZ, destO;
                (*itr)->m_movementInfo.transport.pos.GetPosition(destX, destY, destZ, destO);
                TransportBase::CalculatePassengerPosition(destX, destY, destZ, &destO, x, y, z, o);

                (*itr)->ToUnit()->NearTeleportTo(destX, destY, destZ, destO);
            }
        }

        return false;
    }
}

void MapTransport::DelayedTeleportTransport()
{
    if (!_delayedTeleport)
        return;

    _delayedTeleport = false;
    Map* newMap = sMapMgr->CreateBaseMap(_nextFrame->Node->MapID);
    GetMap()->RemoveFromMap<MapTransport>(this, false);
    SetMap(newMap);

    float x = _nextFrame->Node->LocX,
          y = _nextFrame->Node->LocY,
          z = _nextFrame->Node->LocZ,
          o =_nextFrame->InitialOrientation;

    for (_passengerTeleportItr = _passengers.begin(); _passengerTeleportItr != _passengers.end();)
    {
        WorldObject* obj = (*_passengerTeleportItr++);

        float destX, destY, destZ, destO;
        obj->m_movementInfo.transport.pos.GetPosition(destX, destY, destZ, destO);
        TransportBase::CalculatePassengerPosition(destX, destY, destZ, &destO, x, y, z, o);

        switch (obj->GetTypeId())
        {
            case TYPEID_PLAYER:
                if (!obj->ToPlayer()->TeleportTo(_nextFrame->Node->MapID, destX, destY, destZ, destO, TELE_TO_NOT_LEAVE_TRANSPORT))
                    RemovePassenger(obj);
                break;
            case TYPEID_DYNAMICOBJECT:
                obj->AddObjectToRemoveList();
                break;
            default:
                RemovePassenger(obj);
                break;
        }
    }

    Relocate(x, y, z, o);
    GetMap()->AddToMap<MapTransport>(this);
}

void MapTransport::DoEventIfAny(KeyFrame const& node, bool departure)
{
    if (uint32 eventid = departure ? node.Node->DepartureEventID : node.Node->ArrivalEventID)
    {
        TC_LOG_DEBUG("maps.script", "Taxi %s event %u of node %u of %s path", departure ? "departure" : "arrival", eventid, node.Node->NodeIndex, GetName().c_str());
        GetMap()->ScriptsStart(sEventScripts, eventid, this, this);
        EventInform(eventid);
    }
}

void MapTransport::BuildUpdate(UpdateDataMapType& data_map)
{
    Map::PlayerList const& players = GetMap()->GetPlayers();
    if (players.isEmpty())
        return;

    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        BuildFieldsUpdate(itr->GetSource(), data_map);

    ClearUpdateMask(true);
}
