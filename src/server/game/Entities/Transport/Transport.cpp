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
#include "Cell.h"
#include "CellImpl.h"
#include "Common.h"
#include "DBCStores.h"
#include "GameObjectAI.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Spline.h"
#include "Player.h"
#include "Totem.h"
#include "UpdateData.h"
#include "Vehicle.h"
#include <G3D/Vector3.h>

Transport::Transport() : GameObject(),
    _transportInfo(nullptr), _isMoving(true), _pendingStop(false),
    _triggeredArrivalEvent(false), _triggeredDepartureEvent(false),
    _passengerTeleportItr(_passengers.begin()), _delayedAddModel(false), _delayedTeleport(false)
{
    m_updateFlag = UPDATEFLAG_TRANSPORT | UPDATEFLAG_LOWGUID | UPDATEFLAG_STATIONARY_POSITION | UPDATEFLAG_ROTATION;
}

Transport::~Transport()
{
    ASSERT(_passengers.empty());
    UnloadStaticPassengers();
}

bool Transport::Create(ObjectGuid::LowType guidlow, uint32 entry, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress)
{
    Relocate(x, y, z, ang);

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "Transport (GUID: %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)",
            guidlow, x, y);
        return false;
    }

    Object::_Create(guidlow, 0, HighGuid::Mo_Transport);

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport not created: entry in `gameobject_template` not found, guidlow: %u map: %u  (X: %f Y: %f Z: %f) ang: %f", guidlow, mapid, x, y, z, ang);
        return false;
    }

    m_goInfo = goinfo;
    m_goTemplateAddon = sObjectMgr->GetGameObjectTemplateAddon(entry);

    TransportTemplate const* tInfo = sTransportMgr->GetTransportTemplate(entry);
    if (!tInfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport %u (name: %s) will not be created, missing `transport_template` entry.", entry, goinfo->name.c_str());
        return false;
    }

    _transportInfo = tInfo;

    // initialize waypoints
    _nextFrame = tInfo->keyFrames.begin();
    _currentFrame = _nextFrame++;
    _triggeredArrivalEvent = false;
    _triggeredDepartureEvent = false;

    if (m_goTemplateAddon)
    {
        SetFaction(m_goTemplateAddon->faction);
        SetUInt32Value(GAMEOBJECT_FLAGS, m_goTemplateAddon->flags);
    }

    m_goValue.Transport.PathProgress = 0;
    SetObjectScale(goinfo->size);
    SetPeriod(tInfo->pathTime);
    SetEntry(goinfo->entry);
    SetDisplayId(goinfo->displayId);
    SetGoState(!goinfo->moTransport.canBeStopped ? GO_STATE_READY : GO_STATE_ACTIVE);
    SetGoType(GAMEOBJECT_TYPE_MO_TRANSPORT);
    SetGoAnimProgress(animprogress);
    SetName(goinfo->name);
    SetWorldRotation(0.0f, 0.0f, 0.0f, 1.0f);
    SetParentRotation(QuaternionData());

    m_model = CreateModel();
    return true;
}

void Transport::CleanupsBeforeDelete(bool finalCleanup /*= true*/)
{
    UnloadStaticPassengers();
    while (!_passengers.empty())
    {
        WorldObject* obj = *_passengers.begin();
        RemovePassenger(obj);
    }

    GameObject::CleanupsBeforeDelete(finalCleanup);
}

void Transport::Update(uint32 diff)
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

void Transport::DelayedUpdate(uint32 /*diff*/)
{
    if (GetKeyFrames().size() <= 1)
        return;

    DelayedTeleportTransport();
}

void Transport::AddPassenger(WorldObject* passenger)
{
    if (!IsInWorld())
        return;

    if (_passengers.insert(passenger).second)
    {
        passenger->SetTransport(this);
        passenger->m_movementInfo.AddMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        passenger->m_movementInfo.transport.guid = GetGUID();
        TC_LOG_DEBUG("entities.transport", "Object %s boarded transport %s.", passenger->GetName().c_str(), GetName().c_str());

        if (Player* plr = passenger->ToPlayer())
            sScriptMgr->OnAddPassenger(this, plr);
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

    if (erased || _staticPassengers.erase(passenger)) // static passenger can remove itself in case of grid unload
    {
        passenger->SetTransport(nullptr);
        passenger->m_movementInfo.RemoveMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
        passenger->m_movementInfo.transport.Reset();
        TC_LOG_DEBUG("entities.transport", "Object %s removed from transport %s.", passenger->GetName().c_str(), GetName().c_str());

        if (Player* plr = passenger->ToPlayer())
        {
            sScriptMgr->OnRemovePassenger(this, plr);
            plr->SetFallInformation(0, plr->GetPositionZ());
        }
    }
}

Creature* Transport::CreateNPCPassenger(ObjectGuid::LowType guid, CreatureData const* data)
{
    Map* map = GetMap();
    Creature* creature = new Creature();

    if (!creature->LoadFromDB(guid, map, false, true))
    {
        delete creature;
        return nullptr;
    }

    float x, y, z, o;
    data->spawnPoint.GetPosition(x, y, z, o);

    creature->SetTransport(this);
    creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    creature->m_movementInfo.transport.guid = GetGUID();
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

    if (!map->AddToMap(creature))
    {
        delete creature;
        return nullptr;
    }

    _staticPassengers.insert(creature);
    sScriptMgr->OnAddCreaturePassenger(this, creature);
    return creature;
}

GameObject* Transport::CreateGOPassenger(ObjectGuid::LowType guid, GameObjectData const* data)
{
    Map* map = GetMap();
    GameObject* go = new GameObject();

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

    if (!map->AddToMap(go))
    {
        delete go;
        return nullptr;
    }

    _staticPassengers.insert(go);
    return go;
}

TempSummon* Transport::SummonPassenger(uint32 entry, Position const& pos, TempSummonType summonType, SummonPropertiesEntry const* properties /*= nullptr*/, uint32 duration /*= 0*/, Unit* summoner /*= nullptr*/, uint32 spellId /*= 0*/, uint32 vehId /*= 0*/)
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
                        if (properties->Flags & 512) // Mirror Image, Summon Gargoyle
                            mask = UNIT_MASK_GUARDIAN;
                        break;
                }
                break;
            }
            default:
                return nullptr;
        }
    }

    uint32 phase = PHASEMASK_NORMAL;
    if (summoner)
        phase = summoner->GetPhaseMask();

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

    if (!summon->Create(map->GenerateLowGuid<HighGuid::Unit>(), map, phase, entry, { x, y, z, o }, nullptr, vehId))
    {
        delete summon;
        return nullptr;
    }

    summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, spellId);

    summon->SetTransport(this);
    summon->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    summon->m_movementInfo.transport.guid = GetGUID();
    summon->m_movementInfo.transport.pos.Relocate(pos);
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

void Transport::UpdatePosition(float x, float y, float z, float o)
{
    bool newActive = GetMap()->IsGridLoaded(x, y);
    Cell oldCell(GetPositionX(), GetPositionY());

    Relocate(x, y, z, o);
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

void Transport::LoadStaticPassengers()
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

void Transport::UnloadStaticPassengers()
{
    while (!_staticPassengers.empty())
    {
        WorldObject* obj = *_staticPassengers.begin();
        obj->AddObjectToRemoveList();   // also removes from _staticPassengers
    }
}

void Transport::EnableMovement(bool enabled)
{
    if (!GetGOInfo()->moTransport.canBeStopped)
        return;

    _pendingStop = !enabled;
}

void Transport::MoveToNextWaypoint()
{
    // Clear events flagging
    _triggeredArrivalEvent = false;
    _triggeredDepartureEvent = false;

    // Set frames
    _currentFrame = _nextFrame++;
    if (_nextFrame == GetKeyFrames().end())
        _nextFrame = GetKeyFrames().begin();
}

float Transport::CalculateSegmentPos(float now)
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

bool Transport::TeleportTransport(uint32 newMapid, float x, float y, float z, float o)
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

                (*itr)->ToPlayer()->TeleportTo(newMapid, destX, destY, destZ, destO,
                    TELE_TO_NOT_LEAVE_TRANSPORT | TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET | TELE_TO_TRANSPORT_TELEPORT);
            }
        }

        UpdatePosition(x, y, z, o);
        return false;
    }
}

void Transport::DelayedTeleportTransport()
{
    if (!_delayedTeleport)
        return;

    _delayedTeleport = false;
    Map* newMap = sMapMgr->CreateBaseMap(_nextFrame->Node->MapID);
    GetMap()->RemoveFromMap<Transport>(this, false);
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
    GetMap()->AddToMap<Transport>(this);
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
            if (unit->GetVehicle())
                continue;

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
                //relocate only passengers in world and skip any player that might be still logging in/teleporting
                if (passenger->IsInWorld() && !passenger->ToPlayer()->IsBeingTeleported())
                {
                    GetMap()->PlayerRelocation(passenger->ToPlayer(), x, y, z, o);
                    passenger->ToPlayer()->SetFallInformation(0, passenger->GetPositionZ());
                }
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

void Transport::DoEventIfAny(KeyFrame const& node, bool departure)
{
    if (uint32 eventid = departure ? node.Node->DepartureEventID : node.Node->ArrivalEventID)
    {
        TC_LOG_DEBUG("maps.script", "Taxi %s event %u of node %u of %s path", departure ? "departure" : "arrival", eventid, node.Node->NodeIndex, GetName().c_str());
        GetMap()->ScriptsStart(sEventScripts, eventid, this, this);
        EventInform(eventid);
    }
}

void Transport::BuildUpdate(UpdateDataMapType& data_map)
{
    Map::PlayerList const& players = GetMap()->GetPlayers();
    if (players.isEmpty())
        return;

    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
        BuildFieldsUpdate(itr->GetSource(), data_map);

    ClearUpdateMask(true);
}
