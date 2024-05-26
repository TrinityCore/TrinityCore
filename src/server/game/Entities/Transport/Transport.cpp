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

#include "Transport.h"
#include "Cell.h"
#include "CellImpl.h"
#include "Common.h"
#include "DB2Stores.h"
#include "GameEventSender.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "Spline.h"
#include "Totem.h"
#include "UpdateData.h"
#include "Vehicle.h"
#include <boost/dynamic_bitset.hpp>
#include <G3D/Vector3.h>
#include <sstream>

void TransportBase::UpdatePassengerPosition(Map* map, WorldObject* passenger, float x, float y, float z, float o, bool setHomePosition)
{
    // transport teleported but passenger not yet (can happen for players)
    if (passenger->GetMap() != map)
        return;

    // Do not use Unit::UpdatePosition here, we don't want to remove auras
    // as if regular movement occurred
    switch (passenger->GetTypeId())
    {
        case TYPEID_UNIT:
        {
            Creature* creature = passenger->ToCreature();
            map->CreatureRelocation(creature, x, y, z, o, false);
            if (setHomePosition)
            {
                creature->GetTransportHomePosition(x, y, z, o);
                CalculatePassengerPosition(x, y, z, &o);
                creature->SetHomePosition(x, y, z, o);
            }
            break;
        }
        case TYPEID_PLAYER:
            //relocate only passengers in world and skip any player that might be still logging in/teleporting
            if (passenger->IsInWorld() && !passenger->ToPlayer()->IsBeingTeleported())
            {
                map->PlayerRelocation(passenger->ToPlayer(), x, y, z, o);
                passenger->ToPlayer()->SetFallInformation(0, passenger->GetPositionZ());
            }
            break;
        case TYPEID_GAMEOBJECT:
            map->GameObjectRelocation(passenger->ToGameObject(), x, y, z, o, false);
            passenger->ToGameObject()->RelocateStationaryPosition(x, y, z, o);
            break;
        case TYPEID_DYNAMICOBJECT:
            map->DynamicObjectRelocation(passenger->ToDynObject(), x, y, z, o);
            break;
        case TYPEID_AREATRIGGER:
            map->AreaTriggerRelocation(passenger->ToAreaTrigger(), x, y, z, o);
            break;
        default:
            break;
    }

    if (Unit* unit = passenger->ToUnit())
        if (Vehicle* vehicle = unit->GetVehicleKit())
            vehicle->RelocatePassengers();
}

Transport::Transport() : GameObject(),
    _transportInfo(nullptr), _movementState(TransportMovementState::Moving), _eventsToTrigger(std::make_unique<boost::dynamic_bitset<uint8>>()),
    _currentPathLeg(0), _pathProgress(0), _delayedAddModel(false)
{
    m_updateFlag.ServerTime = true;
    m_updateFlag.Stationary = true;
    m_updateFlag.Rotation = true;
}

Transport::~Transport()
{
    ASSERT(_passengers.empty());
    UnloadStaticPassengers();
}

bool Transport::Create(ObjectGuid::LowType guidlow, uint32 entry, float x, float y, float z, float ang)
{
    Relocate(x, y, z, ang);

    if (!IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "Transport (GUID: {}) not created. Suggested coordinates isn't valid (X: {} Y: {})",
            guidlow, x, y);
        return false;
    }

    Object::_Create(ObjectGuid::Create<HighGuid::Transport>(guidlow));

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);
    if (!goinfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport not created: entry in `gameobject_template` not found, entry: {}", entry);
        return false;
    }

    m_goInfo = goinfo;
    m_goTemplateAddon = sObjectMgr->GetGameObjectTemplateAddon(entry);

    TransportTemplate const* tInfo = sTransportMgr->GetTransportTemplate(entry);
    if (!tInfo)
    {
        TC_LOG_ERROR("sql.sql", "Transport {} (name: {}) will not be created, missing `transport_template` entry.", entry, goinfo->name);
        return false;
    }

    _transportInfo = tInfo;
    _eventsToTrigger->resize(tInfo->Events.size(), true);

    if (GameObjectOverride const* goOverride = GetGameObjectOverride())
    {
        SetFaction(goOverride->Faction);
        ReplaceAllFlags(GameObjectFlags(goOverride->Flags));
    }

    _pathProgress = !goinfo->moTransport.allowstopping ? getMSTime() /*might be called before world update loop begins, don't use GameTime*/ % tInfo->TotalPathTime : 0;
    SetPathProgressForClient(float(_pathProgress) / float(tInfo->TotalPathTime));
    SetObjectScale(goinfo->size);
    SetPeriod(tInfo->TotalPathTime);
    SetEntry(goinfo->entry);
    SetDisplayId(goinfo->displayId);
    SetGoState(!goinfo->moTransport.allowstopping ? GO_STATE_READY : GO_STATE_ACTIVE);
    SetGoType(GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT);
    SetGoAnimProgress(255);
    SetUpdateFieldValue(m_values.ModifyValue(&GameObject::m_gameObjectData).ModifyValue(&UF::GameObjectData::SpawnTrackingStateAnimID), sDB2Manager.GetEmptyAnimStateID());
    SetName(goinfo->name);
    SetLocalRotation(0.0f, 0.0f, 0.0f, 1.0f);
    SetParentRotation(QuaternionData());

    size_t legIndex;
    if (Optional<Position> position = _transportInfo->ComputePosition(_pathProgress, nullptr, &legIndex))
    {
        Relocate(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), position->GetOrientation());
        _currentPathLeg = legIndex;
    }

    CreateModel();
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
    constexpr Milliseconds positionUpdateDelay = 200ms;

    if (AI())
        AI()->UpdateAI(diff);
    else if (!AIM_Initialize())
        TC_LOG_ERROR("entities.transport", "Could not initialize GameObjectAI for Transport");

    sScriptMgr->OnTransportUpdate(this, diff);

    _positionChangeTimer.Update(diff);

    uint32 cycleId = _pathProgress / GetTransportPeriod();
    if (!GetGOInfo()->moTransport.allowstopping)
        _pathProgress = GameTime::GetGameTimeMS();
    else if (!_requestStopTimestamp || _requestStopTimestamp > _pathProgress + diff)
        _pathProgress += diff;
    else
        _pathProgress = *_requestStopTimestamp;

    if (_pathProgress / GetTransportPeriod() != cycleId)
    {
        // reset cycle
        _eventsToTrigger->set();
    }

    SetPathProgressForClient(float(_pathProgress) / float(GetTransportPeriod()));

    uint32 timer = _pathProgress % GetTransportPeriod();

    size_t eventToTriggerIndex = _eventsToTrigger->find_first();
    if (eventToTriggerIndex != boost::dynamic_bitset<uint8>::npos)
    {
        while (eventToTriggerIndex < _transportInfo->Events.size() && _transportInfo->Events[eventToTriggerIndex].Timestamp < timer)
        {
            if (TransportPathLeg const* leg = _transportInfo->GetLegForTime(_transportInfo->Events[eventToTriggerIndex].Timestamp))
                if (leg->MapId == GetMapId())
                    GameEvents::Trigger(_transportInfo->Events[eventToTriggerIndex].EventId, this, this);

            _eventsToTrigger->set(eventToTriggerIndex, false);
            ++eventToTriggerIndex;
        }
    }

    TransportMovementState moveState;
    size_t legIndex;
    if (Optional<Position> newPosition = _transportInfo->ComputePosition(timer, &moveState, &legIndex))
    {
        bool justStopped = _movementState == TransportMovementState::Moving && moveState != TransportMovementState::Moving;
        _movementState = moveState;

        if (justStopped)
        {
            if (_requestStopTimestamp && GetGoState() != GO_STATE_READY)
            {
                SetGoState(GO_STATE_READY);
                SetDynamicFlag(GO_DYNFLAG_LO_STOPPED);
            }
        }

        if (legIndex != _currentPathLeg)
        {
            uint32 oldMapId = _transportInfo->PathLegs[_currentPathLeg].MapId;
            _currentPathLeg = legIndex;
            TeleportTransport(oldMapId, _transportInfo->PathLegs[legIndex].MapId, newPosition->GetPositionX(), newPosition->GetPositionY(), newPosition->GetPositionZ(), newPosition->GetOrientation());
            return;
        }

        // set position
        if (_positionChangeTimer.Passed() && GetExpectedMapId() == GetMapId())
        {
            _positionChangeTimer.Reset(positionUpdateDelay);
            if (_movementState == TransportMovementState::Moving || justStopped)
                UpdatePosition(newPosition->GetPositionX(), newPosition->GetPositionY(), newPosition->GetPositionZ(), newPosition->GetOrientation());
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
    }

    // Add model to map after we are fully done with moving maps
    if (_delayedAddModel)
    {
        _delayedAddModel = false;
        if (m_model)
            GetMap()->InsertGameObjectModel(*m_model);
    }
}

void Transport::AddPassenger(WorldObject* passenger)
{
    if (!IsInWorld())
        return;

    if (_passengers.insert(passenger).second)
    {
        passenger->SetTransport(this);
        passenger->m_movementInfo.transport.guid = GetGUID();
        TC_LOG_DEBUG("entities.transport", "Object {} boarded transport {}.", passenger->GetName(), GetName());

        if (Player* plr = passenger->ToPlayer())
            sScriptMgr->OnAddPassenger(this, plr);
    }
}

Transport* Transport::RemovePassenger(WorldObject* passenger)
{
    if (_passengers.erase(passenger) || _staticPassengers.erase(passenger)) // static passenger can remove itself in case of grid unload
    {
        passenger->SetTransport(nullptr);
        passenger->m_movementInfo.transport.Reset();
        TC_LOG_DEBUG("entities.transport", "Object {} removed from transport {}.", passenger->GetName(), GetName());

        if (Player* plr = passenger->ToPlayer())
        {
            sScriptMgr->OnRemovePassenger(this, plr);
            plr->SetFallInformation(0, plr->GetPositionZ());
        }
    }

    return this;
}

Creature* Transport::CreateNPCPassenger(ObjectGuid::LowType guid, CreatureData const* data)
{
    Map* map = GetMap();
    if (map->GetCreatureRespawnTime(guid))
        return nullptr;

    Creature* creature = Creature::CreateCreatureFromDB(guid, map, false, true);
    if (!creature)
        return nullptr;

    ASSERT(data);

    float x, y, z, o;
    data->spawnPoint.GetPosition(x, y, z, o);

    creature->SetTransport(this);
    creature->m_movementInfo.transport.guid = GetGUID();
    creature->m_movementInfo.transport.pos.Relocate(x, y, z, o);
    creature->m_movementInfo.transport.seat = -1;
    CalculatePassengerPosition(x, y, z, &o);
    creature->Relocate(x, y, z, o);
    creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());
    creature->SetTransportHomePosition(creature->m_movementInfo.transport.pos);

    /// @HACK - transport models are not added to map's dynamic LoS calculations
    ///         because the current GameObjectModel cannot be moved without recreating
    creature->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

    if (!creature->IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "Passenger {} not created. Suggested coordinates aren't valid (X: {} Y: {})", creature->GetGUID().ToString(), creature->GetPositionX(), creature->GetPositionY());
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

GameObject* Transport::CreateGOPassenger(ObjectGuid::LowType guid, GameObjectData const* data)
{
    Map* map = GetMap();
    if (map->GetGORespawnTime(guid))
        return nullptr;

    GameObject* go = GameObject::CreateGameObjectFromDB(guid, map, false);
    if (!go)
        return nullptr;

    ASSERT(data);

    float x, y, z, o;
    data->spawnPoint.GetPosition(x, y, z, o);

    go->SetTransport(this);
    go->m_movementInfo.transport.guid = GetGUID();
    go->m_movementInfo.transport.pos.Relocate(x, y, z, o);
    go->m_movementInfo.transport.seat = -1;
    CalculatePassengerPosition(x, y, z, &o);
    go->Relocate(x, y, z, o);
    go->RelocateStationaryPosition(x, y, z, o);

    if (!go->IsPositionValid())
    {
        TC_LOG_ERROR("entities.transport", "Passenger {} not created. Suggested coordinates aren't valid (X: {} Y: {})", go->GetGUID().ToString(), go->GetPositionX(), go->GetPositionY());
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

TempSummon* Transport::SummonPassenger(uint32 entry, Position const& pos, TempSummonType summonType, SummonPropertiesEntry const* properties /*= nullptr*/, Milliseconds duration /*= 0ms*/, Unit* summoner /*= nullptr*/, uint32 spellId /*= 0*/, uint32 vehId /*= 0*/)
{
    Map* map = FindMap();
    if (!map)
        return nullptr;

    uint32 mask = UNIT_MASK_SUMMON;
    if (properties)
    {
        switch (properties->Control)
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
                switch (SummonTitle(properties->Title))
                {
                    case SummonTitle::Minion:
                    case SummonTitle::Guardian:
                    case SummonTitle::Runeblade:
                        mask = UNIT_MASK_GUARDIAN;
                        break;
                    case SummonTitle::Totem:
                    case SummonTitle::Lightwell:
                        mask = UNIT_MASK_TOTEM;
                        break;
                    case SummonTitle::Vehicle:
                    case SummonTitle::Mount:
                        mask = UNIT_MASK_SUMMON;
                        break;
                    case SummonTitle::Companion:
                        mask = UNIT_MASK_MINION;
                        break;
                    default:
                        if (properties->GetFlags().HasFlag(SummonPropertiesFlags::JoinSummonerSpawnGroup)) // Mirror Image, Summon Gargoyle
                            mask = UNIT_MASK_GUARDIAN;
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

    if (!summon->Create(map->GenerateLowGuid<HighGuid::Creature>(), map, entry, { x, y, z, o }, nullptr, vehId))
    {
        delete summon;
        return nullptr;
    }

    WorldObject* phaseShiftOwner = this;
    if (summoner && !(properties && properties->GetFlags().HasFlag(SummonPropertiesFlags::IgnoreSummonerPhase)))
        phaseShiftOwner = summoner;

    if (phaseShiftOwner)
        PhasingHandler::InheritPhaseShift(summon, phaseShiftOwner);

    summon->SetCreatedBySpell(spellId);

    summon->SetTransport(this);
    summon->m_movementInfo.transport.guid = GetGUID();
    summon->m_movementInfo.transport.pos.Relocate(pos);
    summon->Relocate(x, y, z, o);
    summon->SetHomePosition(x, y, z, o);
    summon->SetTransportHomePosition(pos);

    /// @HACK - transport models are not added to map's dynamic LoS calculations
    ///         because the current GameObjectModel cannot be moved without recreating
    summon->AddUnitState(UNIT_STATE_IGNORE_PATHFINDING);

    summon->InitStats(summoner, duration);

    if (!map->AddToMap<Creature>(summon))
    {
        delete summon;
        return nullptr;
    }

    _staticPassengers.insert(summon);

    summon->InitSummon(summoner);
    summon->SetTempSummonType(summonType);

    return summon;
}

int32 Transport::GetMapIdForSpawning() const
{
    return GetGOInfo()->moTransport.SpawnMap;
}

void Transport::UpdatePosition(float x, float y, float z, float o)
{
    sScriptMgr->OnRelocate(this, GetMapId(), x, y, z);

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

void Transport::LoadStaticPassengers()
{
    uint32 mapId = GetGOInfo()->moTransport.SpawnMap;
    if (!mapId)
        return;

    CellObjectGuidsMap const* cells = sObjectMgr->GetMapObjectGuids(mapId, GetMap()->GetDifficultyID());
    if (!cells)
        return;

    for (auto const& [cellId, guids] : *cells)
    {
        // GameObjects on transport
        for (ObjectGuid::LowType spawnId : guids.gameobjects)
            CreateGOPassenger(spawnId, sObjectMgr->GetGameObjectData(spawnId));

        // Creatures on transport
        for (ObjectGuid::LowType spawnId : guids.creatures)
            CreateNPCPassenger(spawnId, sObjectMgr->GetCreatureData(spawnId));
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
    if (!GetGOInfo()->moTransport.allowstopping)
        return;

    if (!enabled)
    {
        _requestStopTimestamp = (_pathProgress / GetTransportPeriod()) * GetTransportPeriod() + _transportInfo->GetNextPauseWaypointTimestamp(_pathProgress);
    }
    else
    {
        _requestStopTimestamp.reset();
        SetGoState(GO_STATE_ACTIVE);
        RemoveDynamicFlag(GO_DYNFLAG_LO_STOPPED);
    }
}

bool Transport::TeleportTransport(uint32 oldMapId, uint32 newMapId, float x, float y, float z, float o)
{
    if (oldMapId != newMapId)
    {
        UnloadStaticPassengers();
        TeleportPassengersAndHideTransport(newMapId);
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

void Transport::TeleportPassengersAndHideTransport(uint32 newMapid)
{
    if (newMapid == GetMapId())
    {
        AddToWorld();

        for (MapReference const& ref : GetMap()->GetPlayers())
        {
            if (ref.GetSource()->GetTransport() != this && ref.GetSource()->InSamePhase(this))
            {
                UpdateData data(GetMap()->GetId());
                BuildCreateUpdateBlockForPlayer(&data, ref.GetSource());
                ref.GetSource()->m_visibleTransports.insert(GetGUID());
                WorldPacket packet;
                data.BuildPacket(&packet);
                ref.GetSource()->SendDirectMessage(&packet);
            }
        }
    }
    else
    {
        UpdateData data(GetMap()->GetId());
        BuildOutOfRangeUpdateBlock(&data);

        WorldPacket packet;
        data.BuildPacket(&packet);
        for (MapReference const& ref : GetMap()->GetPlayers())
        {
            if (ref.GetSource()->GetTransport() != this && ref.GetSource()->m_visibleTransports.count(GetGUID()))
            {
                ref.GetSource()->SendDirectMessage(&packet);
                ref.GetSource()->m_visibleTransports.erase(GetGUID());
            }
        }

        RemoveFromWorld();
    }

    PassengerSet passengersToTeleport = _passengers;
    for (WorldObject* obj : passengersToTeleport)
    {
        float destX, destY, destZ, destO;
        obj->m_movementInfo.transport.pos.GetPosition(destX, destY, destZ, destO);

        switch (obj->GetTypeId())
        {
            case TYPEID_PLAYER:
                if (!obj->ToPlayer()->TeleportTo({ .Location = WorldLocation(newMapid, destX, destY, destZ, destO), .TransportGuid = GetTransportGUID() }, TELE_TO_NOT_LEAVE_TRANSPORT))
                    RemovePassenger(obj);
                break;
            case TYPEID_DYNAMICOBJECT:
            case TYPEID_AREATRIGGER:
                obj->AddObjectToRemoveList();
                break;
            default:
                RemovePassenger(obj);
                break;
        }
    }
}

void Transport::UpdatePassengerPositions(PassengerSet const& passengers)
{
    for (WorldObject* passenger : passengers)
    {
        float x, y, z, o;
        passenger->m_movementInfo.transport.pos.GetPosition(x, y, z, o);
        CalculatePassengerPosition(x, y, z, &o);
        UpdatePassengerPosition(GetMap(), passenger, x, y, z, o, true);
    }
}

void Transport::BuildUpdate(UpdateDataMapType& data_map)
{
    Map::PlayerList const& players = GetMap()->GetPlayers();
    if (players.isEmpty())
        return;

    for (MapReference const& playerReference : players)
        if (playerReference.GetSource()->InSamePhase(this))
            BuildFieldsUpdate(playerReference.GetSource(), data_map);

    ClearUpdateMask(true);
}

std::string Transport::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << GameObject::GetDebugInfo();
    return sstr.str();
}

uint32 Transport::GetExpectedMapId() const
{
    return _transportInfo->PathLegs[_currentPathLeg].MapId;
}
