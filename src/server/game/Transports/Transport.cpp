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

#include "Common.h"
#include "Transport.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Path.h"
#include "WorldPacket.h"
#include "World.h"
#include "GameObjectAI.h"
#include "MapReference.h"
#include "Player.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameObjectModel.h"
#include "ObjectAccessor.h"

#include <G3D/Quat.h>

Transport::Transport(TransportTemplate const& transportTemplate) : GenericTransport(), m_transportTemplate(transportTemplate), m_isMoving(true), m_pendingStop(false)
{
    m_updateFlag = UPDATEFLAG_TRANSPORT;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    m_updateFlag |= UPDATEFLAG_ALL | UPDATEFLAG_HAS_POSITION;
#endif

    SetPeriod(transportTemplate.pathTime);
}

bool Transport::Create(uint32 guidlow, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress)
{
    Relocate(x, y, z, ang);

    if (!IsPositionValid())
    {
        sLog.outError("Transport (GUID: %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)",
                      guidlow, x, y);
        return false;
    }

    Object::_Create(guidlow, 0, HIGHGUID_MO_TRANSPORT);

    GameObjectInfo const* goinfo = ObjectMgr::GetGameObjectInfo(guidlow);

    if (!goinfo)
    {
        sLog.outErrorDb("Transport not created: entry in `gameobject_template` not found, guidlow: %u map: %u  (X: %f Y: %f Z: %f) ang: %f", guidlow, mapid, x, y, z, ang);
        return false;
    }

    m_goInfo = goinfo;

    // initialize waypoints
    m_nextFrame = GetKeyFrames().begin();
    m_currentFrame = m_nextFrame++;

    m_pathProgress = sWorld.GetCurrentMSTime();

    SetObjectScale(goinfo->size);

    SetUInt32Value(GAMEOBJECT_FACTION, goinfo->faction);
    SetUInt32Value(GAMEOBJECT_FLAGS, goinfo->flags);

    SetEntry(goinfo->id);

    SetDisplayId(goinfo->displayId);
    SetUInt32Value(GAMEOBJECT_DISPLAYID, goinfo->displayId);

    SetGoState(GO_STATE_READY);
    SetGoType(GameobjectTypes(goinfo->type));

    SetGoAnimProgress(animprogress);

    SetName(goinfo->name);

    sObjectAccessor.AddObject(this);
    return true;
}

void GenericTransport::CleanupsBeforeDelete()
{
    while (!m_passengers.empty())
    {
        Unit* obj = *m_passengers.begin();
        RemovePassenger(obj);
    }

    GameObject::CleanupsBeforeDelete();
}

void Transport::MoveToNextWayPoint()
{
    m_currentFrame = m_nextFrame++;
    if (m_nextFrame == GetKeyFrames().end())
        m_nextFrame = GetKeyFrames().begin();
}

bool Transport::TeleportTransport(uint32 newMapid, float x, float y, float z, float o)
{
    Map const* oldMap = GetMap();

    uint32 newInstanceId = sMapMgr.GetContinentInstanceId(newMapid, x, y);
    SetLocationInstanceId(newInstanceId);
    Map* newMap = sMapMgr.CreateMap(newMapid, this);
    GetMap()->Remove<Transport>(this, false);
    SetMap(newMap);

    for (m_passengerTeleportItr = m_passengers.begin(); m_passengerTeleportItr != m_passengers.end();)
    {
        Unit* passenger = (*m_passengerTeleportItr++);

        float destX, destY, destZ, destO;
        destX = passenger->GetTransOffsetX();
        destY = passenger->GetTransOffsetY();
        destZ = passenger->GetTransOffsetZ();
        destO = passenger->GetTransOffsetO();
        CalculatePassengerPosition(destX, destY, destZ, &destO, x, y, z, o);

        switch (passenger->GetTypeId())
        {
            case TYPEID_UNIT:
            {
                // Units teleport on transport not implemented.
                Creature* creature = static_cast<Creature*>(passenger);
                RemovePassenger(creature);

                Player* pOwner = ::ToPlayer(creature->GetOwner());
                if (!pOwner || pOwner->GetTransport() != this)
                {
                    if (creature->IsInCombat())
                        creature->OnLeaveCombat();
                    else
                    {
                        float x, y, z, o = 0.0f;
                        if (pOwner)
                            pOwner->GetPosition(x, y, z);
                        else
                            creature->GetRespawnCoord(x, y, z, &o);
                        creature->NearTeleportTo(x, y, z, o);
                    }
                }
                
                break;
            }
            case TYPEID_PLAYER:
            {
                // Remove some auras to prevent undermap
                Player* player = static_cast<Player*>(passenger);
                if (!player->IsInWorld())
                {
                    RemovePassenger(player);
                    break;
                }

                if (!player->IsAlive())
                    player->ResurrectPlayer(1.0f);

                player->RemoveSpellsCausingAura(SPELL_AURA_MOD_CONFUSE);
                player->RemoveSpellsCausingAura(SPELL_AURA_MOD_FEAR);
                player->CombatStopWithPets(true);

                // No need for teleport packet if no map change
                // The client still shows the correct loading screen when one is needed (Grom'Gol-Undercity)
                if (newMapid == player->GetMapId())
                {
                    player->TeleportPositionRelocation(destX, destY, destZ, destO);
                    if (newInstanceId != player->GetInstanceId())
                        sMapMgr.ScheduleInstanceSwitch(player, newInstanceId);
                }
                else
                    player->TeleportTo(newMapid, destX, destY, destZ, destO,
                        TELE_TO_NOT_LEAVE_TRANSPORT);

                break;
            }
            default:
                break;
        }
    }

    Relocate(x, y, z, o);
    GetMap()->Add<Transport>(this);

    return newMap != oldMap;
}

void GenericTransport::AddPassenger(Unit* passenger, bool adjustCoords)
{
    if (m_passengers.insert(passenger).second)
    {
        DETAIL_LOG("Unit %s boarded transport %s.", passenger->GetName(), GetName());
        passenger->SetTransport(this);
        passenger->m_movementInfo.AddMovementFlag(MOVEFLAG_ONTRANSPORT);
        bool changedTransports = passenger->m_movementInfo.t_guid != GetObjectGuid();
        passenger->m_movementInfo.t_guid = GetObjectGuid();
        passenger->m_movementInfo.t_time = GetPathProgress();
        if (changedTransports && adjustCoords)
        {
            passenger->m_movementInfo.t_pos.x = passenger->GetPositionX();
            passenger->m_movementInfo.t_pos.y = passenger->GetPositionY();
            passenger->m_movementInfo.t_pos.z = passenger->GetPositionZ();
            passenger->m_movementInfo.t_pos.o = passenger->GetOrientation();
            CalculatePassengerOffset(passenger->m_movementInfo.t_pos.x, passenger->m_movementInfo.t_pos.y, passenger->m_movementInfo.t_pos.z, &passenger->m_movementInfo.t_pos.o);
        }
    }
}

void GenericTransport::RemovePassenger(Unit* passenger)
{
    bool erased = false;
    if (m_passengerTeleportItr != m_passengers.end())
    {
        PassengerSet::iterator itr = m_passengers.find(passenger);
        if (itr != m_passengers.end())
        {
            if (itr == m_passengerTeleportItr)
                ++m_passengerTeleportItr;

            m_passengers.erase(itr);
            erased = true;
        }
    }
    else
        erased = m_passengers.erase(passenger) > 0;

    if (erased)
    {
        DETAIL_LOG("Unit %s removed from transport %s.", passenger->GetName(), GetName());
        passenger->SetTransport(nullptr);
        passenger->m_movementInfo.ClearTransportData();
    }
}

void GenericTransport::AddFollowerToTransport(Unit* passenger, Unit* follower)
{
    AddPassenger(follower);
    follower->m_movementInfo.SetTransportData(GetObjectGuid(), passenger->m_movementInfo.t_pos.x, passenger->m_movementInfo.t_pos.y, passenger->m_movementInfo.t_pos.z, passenger->m_movementInfo.t_pos.o, GetPathProgress());
    if (follower->IsCreature())
        follower->NearTeleportTo(passenger->m_movementInfo.pos.x, passenger->m_movementInfo.pos.y, passenger->m_movementInfo.pos.z, passenger->m_movementInfo.pos.o);
    else
    {
        follower->Relocate(passenger->m_movementInfo.pos.x, passenger->m_movementInfo.pos.y, passenger->m_movementInfo.pos.z, passenger->m_movementInfo.pos.o);
        follower->SendHeartBeat();
    }
}

void GenericTransport::RemoveFollowerFromTransport(Unit* passenger, Unit* follower)
{
    RemovePassenger(follower);
    if (follower->IsCreature())
        follower->NearTeleportTo(passenger->m_movementInfo.pos.x, passenger->m_movementInfo.pos.y, passenger->m_movementInfo.pos.z, passenger->m_movementInfo.pos.o);
    else
    {
        follower->Relocate(passenger->m_movementInfo.pos.x, passenger->m_movementInfo.pos.y, passenger->m_movementInfo.pos.z, passenger->m_movementInfo.pos.o);
        follower->SendHeartBeat();
    }
}

void Transport::Update(uint32 /*update_diff*/, uint32 /*time_diff*/)
{
    uint32 const positionUpdateDelay = 50;

    if (GetKeyFrames().size() <= 1)
        return;

    uint32 currentMsTime = sWorld.GetCurrentMSTime();
    if (m_pathProgress >= currentMsTime) // map transition and update happened in same tick due to MT
        return;

    const uint32 diff = currentMsTime - m_pathProgress;

    if (IsMoving() || !m_pendingStop)
        m_pathProgress = currentMsTime;

    uint32 pathProgress = m_pathProgress % GetPeriod();
    while (true)
    {
        if (pathProgress >= m_currentFrame->ArriveTime && pathProgress < m_currentFrame->DepartureTime)
        {
            SetMoving(false);
            break;  // its a stop frame and we are waiting
        }

        // not waiting anymore
        SetMoving(true);

        if (pathProgress >= m_currentFrame->DepartureTime && pathProgress < m_currentFrame->NextArriveTime)
            break;  // found current waypoint

        MoveToNextWayPoint();

        // first check help in case client-server transport coordinates de-synchronization
        if (m_currentFrame->Node->mapid != GetMapId() || m_currentFrame->IsTeleportFrame())
        {
            TeleportTransport(m_nextFrame->Node->mapid, m_nextFrame->Node->x, m_nextFrame->Node->y, m_nextFrame->Node->z, m_nextFrame->InitialOrientation);
            return;
        }
        else if (m_currentFrame->IsUpdateFrame())
        {
            SendOutOfRangeUpdateToMap();
            SendCreateUpdateToMap();
        }

        if (m_currentFrame == GetKeyFrames().begin())
            DETAIL_FILTER_LOG(LOG_FILTER_TRANSPORT_MOVES, " ************ BEGIN ************** %s", GetName());

        DETAIL_FILTER_LOG(LOG_FILTER_TRANSPORT_MOVES, "%s moved to %f %f %f %d", GetName(), m_currentFrame->Node->x, m_currentFrame->Node->y, m_currentFrame->Node->z, m_currentFrame->Node->mapid);
    }

    // Set position
    m_positionChangeTimer.Update(diff);
    if (m_positionChangeTimer.Passed())
    {
        m_positionChangeTimer.Reset(positionUpdateDelay);
        if (IsMoving() && pathProgress)
        {
            float t = CalculateSegmentPos(float(pathProgress) * 0.001f);
            G3D::Vector3 pos, dir;
            m_currentFrame->Spline->evaluate_percent(m_currentFrame->Index, t, pos);
            m_currentFrame->Spline->evaluate_derivative(m_currentFrame->Index, t, dir);
            UpdatePosition(pos.x, pos.y, pos.z, atan2(dir.y, dir.x) + M_PI);
        }
    }
}

float Transport::CalculateSegmentPos(float now)
{
    KeyFrame const& frame = *m_currentFrame;
    float const speed = float(m_goInfo->moTransport.moveSpeed);
    float const accel = float(m_goInfo->moTransport.accelRate);
    float timeSinceStop = frame.TimeFrom + (now - (1.0f / IN_MILLISECONDS) * frame.DepartureTime);
    float timeUntilStop = frame.TimeTo - (now - (1.0f / IN_MILLISECONDS) * frame.DepartureTime);
    float segmentPos, dist;
    float accelTime = m_transportTemplate.accelTime;
    float accelDist = m_transportTemplate.accelDist;
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
        if (timeUntilStop < m_transportTemplate.accelTime)
            dist = 0.5f * accel * timeUntilStop * timeUntilStop;
        else
            dist = accelDist + (timeUntilStop - accelTime) * speed;
        segmentPos = frame.DistUntilStop - dist;
    }

    return segmentPos / frame.NextDistFromPrev;
}

bool ElevatorTransport::Create(uint32 guidlow, uint32 name_id, Map* map, float x, float y, float z, float ang, float rotation0, float rotation1, float rotation2, float rotation3, uint32 animprogress, GOState go_state)
{
    if (GenericTransport::Create(guidlow, name_id, map, x, y, z, ang, rotation0, rotation1, rotation2, rotation3, animprogress, go_state))
    {
        m_animationInfo = sTransportMgr.GetTransportAnimInfo(GetGOInfo()->id);
        m_pathProgress = m_animationInfo ? (sWorld.GetCurrentMSTime() % m_animationInfo->TotalTime) : 0;
        m_currentSeg = 0;
        return true;
    }
    return false;
}

void ElevatorTransport::Update(uint32 /*update_diff*/, uint32 /*time_diff*/)
{
    if (!m_animationInfo)
        return;

    m_pathProgress = sWorld.GetCurrentMSTime() % m_animationInfo->TotalTime;
    TransportAnimationEntry const* nodeNext = m_animationInfo->GetNextAnimNode(m_pathProgress);
    TransportAnimationEntry const* nodePrev = m_animationInfo->GetPrevAnimNode(m_pathProgress);
    if (nodeNext && nodePrev)
    {
        m_currentSeg = nodePrev->TimeSeg;
        G3D::Vector3 posPrev = G3D::Vector3(nodePrev->X, nodePrev->Y, nodePrev->Z);
        G3D::Vector3 posNext = G3D::Vector3(nodeNext->X, nodeNext->Y, nodeNext->Z);
        G3D::Vector3 currentPos;
        if (posPrev == posNext)
            currentPos = posPrev;
        else
        {
            uint32 timeElapsed = m_pathProgress - nodePrev->TimeSeg;
            uint32 timeDiff = nodeNext->TimeSeg - nodePrev->TimeSeg;
            G3D::Vector3 segmentDiff = posNext - posPrev;
            float velocityX = float(segmentDiff.x) / timeDiff, velocityY = float(segmentDiff.y) / timeDiff, velocityZ = float(segmentDiff.z) / timeDiff;

            currentPos = G3D::Vector3(timeElapsed * velocityX, timeElapsed * velocityY, timeElapsed * velocityZ);
            currentPos += posPrev;
        }

        auto data = GetLocalRotation();
        G3D::Quat rotation(data.x, data.y, data.z, data.w);
        currentPos = currentPos * rotation;
        currentPos.y = -currentPos.y; // magical sign flip but it works - vanilla/tbc only
        currentPos += G3D::Vector3(m_stationaryPosition.x, m_stationaryPosition.y, m_stationaryPosition.z);

        Relocate(currentPos.x, currentPos.y, currentPos.z, GetOrientation());
        UpdateModelPosition();
        UpdatePassengerPositions(GetPassengers());

        //SummonCreature(1, currentPos.x, currentPos.y, currentPos.z, GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 1000);
    }
}

void GenericTransport::UpdatePosition(float x, float y, float z, float o)
{
    Relocate(x, y, z, o);
    UpdateModelPosition();

    UpdatePassengerPositions(m_passengers);
}

void GenericTransport::UpdatePassengerPositions(PassengerSet& passengers)
{
    for (const auto passenger : passengers)
        UpdatePassengerPosition(passenger);
}

void GenericTransport::UpdatePassengerPosition(Unit* passenger)
{
    // transport teleported but passenger not yet (can happen for players)
    if (passenger->FindMap() != GetMap())
        return;

    // Do not use Unit::UpdatePosition here, we don't want to remove auras
    // as if regular movement occurred
    float x, y, z, o;
    x = passenger->GetTransOffsetX();
    y = passenger->GetTransOffsetY();
    z = passenger->GetTransOffsetZ();
    o = passenger->GetTransOffsetO();
    CalculatePassengerPosition(x, y, z, &o);
    if (!MaNGOS::IsValidMapCoord(x, y, z))
    {
        sLog.outError("[TRANSPORTS] Object %s [guid %u] has invalid position on transport.", passenger->GetName(), passenger->GetGUIDLow());
        return;
    }

    switch (passenger->GetTypeId())
    {
        case TYPEID_UNIT:
        {
            Creature* creature = static_cast<Creature*>(passenger);
            if (passenger->IsInWorld())
                GetMap()->CreatureRelocation(creature, x, y, z, o);
            else
                passenger->Relocate(x, y, z, o);
            creature->m_movementInfo.t_time = GetPathProgress();
            break;
        }
        case TYPEID_PLAYER:
            //relocate only passengers in world and skip any player that might be still logging in/teleporting
            if (passenger->IsInWorld())
                GetMap()->PlayerRelocation(static_cast<Player*>(passenger), x, y, z, o);
            else
            {
                passenger->Relocate(x, y, z, o);
                static_cast<Player*>(passenger)->m_movementInfo.t_guid = GetObjectGuid();
            }
            static_cast<Player*>(passenger)->m_movementInfo.t_time = GetPathProgress();
            break;
        default:
            break;
    }
}

void GenericTransport::CalculatePassengerOrientation(float& o) const
{
    o = MapManager::NormalizeOrientation(GetOrientation() + o);
}

void GenericTransport::CalculatePassengerPosition(float& x, float& y, float& z, float* o, float transX, float transY, float transZ, float transO)
{
    float inx = x, iny = y, inz = z;
    if (o)
        *o = MapManager::NormalizeOrientation(transO + *o);

    x = transX + inx * std::cos(transO) - iny * std::sin(transO);
    y = transY + iny * std::cos(transO) + inx * std::sin(transO);
    z = transZ + inz;
}

void GenericTransport::CalculatePassengerOffset(float& x, float& y, float& z, float* o, float transX, float transY, float transZ, float transO)
{
    if (o)
        *o = MapManager::NormalizeOrientation(*o - transO);

    z -= transZ;
    y -= transY;    // y = searchedY * std::cos(o) + searchedX * std::sin(o)
    x -= transX;    // x = searchedX * std::cos(o) + searchedY * std::sin(o + pi)
    float inx = x, iny = y;
    y = (iny - inx * std::tan(transO)) / (std::cos(transO) + std::sin(transO) * std::tan(transO));
    x = (inx + iny * std::tan(transO)) / (std::cos(transO) + std::sin(transO) * std::tan(transO));
}

void GenericTransport::SendOutOfRangeUpdateToMap()
{
    Map::PlayerList const& players = GetMap()->GetPlayers();
    if (!players.isEmpty())
    {
        UpdateData data;
        BuildOutOfRangeUpdateBlock(data);
        WorldPacket packet;
        data.BuildPacket(&packet);
        for (const auto& player : players)
            if (player.getSource()->GetTransport() != this)
                player.getSource()->SendDirectMessage(&packet);
    }
}

void GenericTransport::SendCreateUpdateToMap()
{
    Map::PlayerList const& players = GetMap()->GetPlayers();
    if (!players.isEmpty())
    {
        for (const auto& player : players)
            if (player.getSource()->GetTransport() != this)
            {
                UpdateData data;
                BuildCreateUpdateBlockForPlayer(data, player.getSource());
                data.Send(player.getSource()->GetSession());
            }
    }
}

TransportTemplate::~TransportTemplate()
{
    // Collect shared pointers into a set to avoid deleting the same memory more than once
    std::set<TransportSpline*> splines;
    for (const auto& keyFrame : keyFrames)
        splines.insert(keyFrame.Spline);

    for (const auto& spline : splines)
        delete spline;
}
