/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "Transport.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Path.h"
#include "ScriptMgr.h"
#include "WorldPacket.h"
#include "DBCStores.h"
#include "World.h"
#include "GameObjectAI.h"
#include "Player.h"

void MapManager::LoadTransports()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = WorldDatabase.Query("SELECT guid, entry, name, period, ScriptName FROM transports");

    if (!result)
    {
        sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 transports. DB table `transports` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {

        Field* fields = result->Fetch();
        uint32 lowguid = fields[0].GetUInt32();
        uint32 entry = fields[1].GetUInt32();
        std::string name = fields[2].GetString();
        uint32 period = fields[3].GetUInt32();
        uint32 scriptId = sObjectMgr->GetScriptId(fields[4].GetCString());

        GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);

        if (!goinfo)
        {
            sLog->outError(LOG_FILTER_SQL, "Transport ID:%u, Name: %s, will not be loaded, gameobject_template missing", entry, name.c_str());
            continue;
        }

        if (goinfo->type != GAMEOBJECT_TYPE_MO_TRANSPORT)
        {
            sLog->outError(LOG_FILTER_SQL, "Transport ID:%u, Name: %s, will not be loaded, gameobject_template type wrong", entry, name.c_str());
            continue;
        }

        // sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Loading transport %d between %s, %s", entry, name.c_str(), goinfo->name);

        std::set<uint32> mapsUsed;

        Transport* t = new Transport(period, scriptId);
        if (!t->GenerateWaypoints(goinfo->moTransport.taxiPathId, mapsUsed))
            // skip transports with empty waypoints list
        {
            sLog->outError(LOG_FILTER_SQL, "Transport (path id %u) path size = 0. Transport ignored, check DBC files or transport GO data0 field.", goinfo->moTransport.taxiPathId);
            delete t;
            continue;
        }

        float x = t->m_WayPoints[0].x;
        float y = t->m_WayPoints[0].y;
        float z = t->m_WayPoints[0].z;
        uint32 mapid = t->m_WayPoints[0].mapid;
        float o = 1.0f;

         // creates the Gameobject
        if (!t->Create(lowguid, entry, mapid, x, y, z, o, 255, 0))
        {
            delete t;
            continue;
        }

        m_Transports.insert(t);

        for (std::set<uint32>::const_iterator i = mapsUsed.begin(); i != mapsUsed.end(); ++i)
            m_TransportsByMap[*i].insert(t);

        //If we someday decide to use the grid to track transports, here:
        t->SetMap(sMapMgr->CreateBaseMap(mapid));
        t->AddToWorld();

        ++count;
    }
    while (result->NextRow());

    // check transport data DB integrity
    result = WorldDatabase.Query("SELECT gameobject.guid, gameobject.id, transports.name FROM gameobject, transports WHERE gameobject.id = transports.entry");
    if (result)                                              // wrong data found
    {
        do
        {
            Field* fields = result->Fetch();

            uint32 guid  = fields[0].GetUInt32();
            uint32 entry = fields[1].GetUInt32();
            std::string name = fields[2].GetString();
            sLog->outError(LOG_FILTER_SQL, "Transport %u '%s' have record (GUID: %u) in `gameobject`. Transports must not have any records in `gameobject` or its behavior will be unpredictable/bugged.", entry, name.c_str(), guid);
        }
        while (result->NextRow());
    }

    sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u transports in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

void MapManager::LoadTransportNPCs()
{
    uint32 oldMSTime = getMSTime();

    //                                                 0       1            2                3             4             5             6        7
    QueryResult result = WorldDatabase.Query("SELECT guid, npc_entry, transport_entry, TransOffsetX, TransOffsetY, TransOffsetZ, TransOffsetO, emote FROM creature_transport");

    if (!result)
    {
        sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded 0 transport NPCs. DB table `creature_transport` is empty!");
        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 guid = fields[0].GetInt32();
        uint32 entry = fields[1].GetInt32();
        uint32 transportEntry = fields[2].GetInt32();
        float tX = fields[3].GetFloat();
        float tY = fields[4].GetFloat();
        float tZ = fields[5].GetFloat();
        float tO = fields[6].GetFloat();
        uint32 anim = fields[7].GetInt32();

        for (MapManager::TransportSet::iterator itr = m_Transports.begin(); itr != m_Transports.end(); ++itr)
        {
            if ((*itr)->GetEntry() == transportEntry)
            {
                (*itr)->AddNPCPassenger(guid, entry, tX, tY, tZ, tO, anim);
                break;
            }
        }

        ++count;
    }
    while (result->NextRow());

    sLog->outInfo(LOG_FILTER_SERVER_LOADING, ">> Loaded %u transport npcs in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

Transport::Transport(uint32 period, uint32 script) : GameObject(), m_pathTime(0), m_timer(0),
currenttguid(0), m_period(period), ScriptId(script), m_nextNodeTime(0)
{
    m_updateFlag = (UPDATEFLAG_TRANSPORT | UPDATEFLAG_LOWGUID | UPDATEFLAG_STATIONARY_POSITION | UPDATEFLAG_ROTATION);
}

Transport::~Transport()
{
    for (CreatureSet::iterator itr = m_NPCPassengerSet.begin(); itr != m_NPCPassengerSet.end(); ++itr)
    {
        (*itr)->SetTransport(NULL);
        GetMap()->AddObjectToRemoveList(*itr);
    }

    m_NPCPassengerSet.clear();

    m_WayPoints.clear();
    m_passengers.clear();
}

bool Transport::Create(uint32 guidlow, uint32 entry, uint32 mapid, float x, float y, float z, float ang, uint32 animprogress, uint32 dynflags)
{
    Relocate(x, y, z, ang);
    // instance id and phaseMask isn't set to values different from std.

    if (!IsPositionValid())
    {
        sLog->outError(LOG_FILTER_TRANSPORTS, "Transport (GUID: %u) not created. Suggested coordinates isn't valid (X: %f Y: %f)",
            guidlow, x, y);
        return false;
    }

    Object::_Create(guidlow, 0, HIGHGUID_MO_TRANSPORT);

    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(entry);

    if (!goinfo)
    {
        sLog->outError(LOG_FILTER_SQL, "Transport not created: entry in `gameobject_template` not found, guidlow: %u map: %u  (X: %f Y: %f Z: %f) ang: %f", guidlow, mapid, x, y, z, ang);
        return false;
    }

    m_goInfo = goinfo;

    SetObjectScale(goinfo->size);

    SetUInt32Value(GAMEOBJECT_FACTION, goinfo->faction);
    SetUInt32Value(GAMEOBJECT_FLAGS, goinfo->flags);
    SetUInt32Value(GAMEOBJECT_LEVEL, m_period);
    SetEntry(goinfo->entry);

    SetDisplayId(goinfo->displayId);

    SetGoState(GO_STATE_READY);
    SetGoType(GameobjectTypes(goinfo->type));

    SetGoAnimProgress(animprogress);
    if (dynflags)
        SetUInt32Value(GAMEOBJECT_DYNAMIC, MAKE_PAIR32(0, dynflags));

    SetName(goinfo->name);

    SetZoneScript();

    return true;
}

struct keyFrame
{
    explicit keyFrame(TaxiPathNodeEntry const& _node) : node(&_node),
        distSinceStop(-1.0f), distUntilStop(-1.0f), distFromPrev(-1.0f), tFrom(0.0f), tTo(0.0f)
        {
        }

    TaxiPathNodeEntry const* node;

    float distSinceStop;
    float distUntilStop;
    float distFromPrev;
    float tFrom, tTo;
};

bool Transport::GenerateWaypoints(uint32 pathid, std::set<uint32> &mapids)
{
    if (pathid >= sTaxiPathNodesByPath.size())
        return false;

    TaxiPathNodeList const& path = sTaxiPathNodesByPath[pathid];

    std::vector<keyFrame> keyFrames;
    int mapChange = 0;
    mapids.clear();
    for (size_t i = 1; i < path.size() - 1; ++i)
    {
        if (mapChange == 0)
        {
            TaxiPathNodeEntry const& node_i = path[i];
            if (node_i.mapid == path[i+1].mapid)
            {
                keyFrame k(node_i);
                keyFrames.push_back(k);
                mapids.insert(k.node->mapid);
            }
            else
            {
                mapChange = 1;
            }
        }
        else
        {
            --mapChange;
        }
    }

    int lastStop = -1;
    int firstStop = -1;

    // first cell is arrived at by teleportation :S
    keyFrames[0].distFromPrev = 0;
    if (keyFrames[0].node->actionFlag == 2)
    {
        lastStop = 0;
    }

    // find the rest of the distances between key points
    for (size_t i = 1; i < keyFrames.size(); ++i)
    {
        if ((keyFrames[i].node->actionFlag == 1) || (keyFrames[i].node->mapid != keyFrames[i-1].node->mapid))
        {
            keyFrames[i].distFromPrev = 0;
        }
        else
        {
            keyFrames[i].distFromPrev =
                sqrt(pow(keyFrames[i].node->x - keyFrames[i - 1].node->x, 2) +
                    pow(keyFrames[i].node->y - keyFrames[i - 1].node->y, 2) +
                    pow(keyFrames[i].node->z - keyFrames[i - 1].node->z, 2));
        }
        if (keyFrames[i].node->actionFlag == 2)
        {
            // remember first stop frame
            if (firstStop == -1)
                firstStop = i;
            lastStop = i;
        }
    }

    float tmpDist = 0;
    for (size_t i = 0; i < keyFrames.size(); ++i)
    {
        int j = (i + lastStop) % keyFrames.size();
        if (keyFrames[j].node->actionFlag == 2)
            tmpDist = 0;
        else
            tmpDist += keyFrames[j].distFromPrev;
        keyFrames[j].distSinceStop = tmpDist;
    }

    for (int i = int(keyFrames.size()) - 1; i >= 0; i--)
    {
        int j = (i + (firstStop+1)) % keyFrames.size();
        tmpDist += keyFrames[(j + 1) % keyFrames.size()].distFromPrev;
        keyFrames[j].distUntilStop = tmpDist;
        if (keyFrames[j].node->actionFlag == 2)
            tmpDist = 0;
    }

    for (size_t i = 0; i < keyFrames.size(); ++i)
    {
        if (keyFrames[i].distSinceStop < (30 * 30 * 0.5f))
            keyFrames[i].tFrom = sqrt(2 * keyFrames[i].distSinceStop);
        else
            keyFrames[i].tFrom = ((keyFrames[i].distSinceStop - (30 * 30 * 0.5f)) / 30) + 30;

        if (keyFrames[i].distUntilStop < (30 * 30 * 0.5f))
            keyFrames[i].tTo = sqrt(2 * keyFrames[i].distUntilStop);
        else
            keyFrames[i].tTo = ((keyFrames[i].distUntilStop - (30 * 30 * 0.5f)) / 30) + 30;

        keyFrames[i].tFrom *= 1000;
        keyFrames[i].tTo *= 1000;
    }

    //    for (int i = 0; i < keyFrames.size(); ++i) {
    //        sLog->outInfo(LOG_FILTER_TRANSPORTS, "%f, %f, %f, %f, %f, %f, %f", keyFrames[i].x, keyFrames[i].y, keyFrames[i].distUntilStop, keyFrames[i].distSinceStop, keyFrames[i].distFromPrev, keyFrames[i].tFrom, keyFrames[i].tTo);
    //    }

    // Now we're completely set up; we can move along the length of each waypoint at 100 ms intervals
    // speed = max(30, t) (remember x = 0.5s^2, and when accelerating, a = 1 unit/s^2
    int t = 0;
    bool teleport = false;
    if (keyFrames[keyFrames.size() - 1].node->mapid != keyFrames[0].node->mapid)
        teleport = true;

    m_WayPoints[0] = WayPoint(keyFrames[0].node->mapid, keyFrames[0].node->x, keyFrames[0].node->y, keyFrames[0].node->z, teleport, 0,
        keyFrames[0].node->arrivalEventID, keyFrames[0].node->departureEventID);

    t += keyFrames[0].node->delay * 1000;

    uint32 cM = keyFrames[0].node->mapid;
    for (size_t i = 0; i < keyFrames.size() - 1; ++i)
    {
        float d = 0;
        float tFrom = keyFrames[i].tFrom;
        float tTo = keyFrames[i].tTo;

        // keep the generation of all these points; we use only a few now, but may need the others later
        if (((d < keyFrames[i + 1].distFromPrev) && (tTo > 0)))
        {
            while ((d < keyFrames[i + 1].distFromPrev) && (tTo > 0))
            {
                tFrom += 100;
                tTo -= 100;

                if (d > 0)
                {
                    float newX = keyFrames[i].node->x + (keyFrames[i + 1].node->x - keyFrames[i].node->x) * d / keyFrames[i + 1].distFromPrev;
                    float newY = keyFrames[i].node->y + (keyFrames[i + 1].node->y - keyFrames[i].node->y) * d / keyFrames[i + 1].distFromPrev;
                    float newZ = keyFrames[i].node->z + (keyFrames[i + 1].node->z - keyFrames[i].node->z) * d / keyFrames[i + 1].distFromPrev;

                    teleport = false;
                    if (keyFrames[i].node->mapid != cM)
                    {
                        teleport = true;
                        cM = keyFrames[i].node->mapid;
                    }

                    //                    sLog->outInfo(LOG_FILTER_TRANSPORTS, "T: %d, D: %f, x: %f, y: %f, z: %f", t, d, newX, newY, newZ);
                    if (teleport)
                        m_WayPoints[t] = WayPoint(keyFrames[i].node->mapid, newX, newY, newZ, teleport, 0);
                }

                if (tFrom < tTo)                            // caught in tFrom dock's "gravitational pull"
                {
                    if (tFrom <= 30000)
                    {
                        d = 0.5f * (tFrom / 1000) * (tFrom / 1000);
                    }
                    else
                    {
                        d = 0.5f * 30 * 30 + 30 * ((tFrom - 30000) / 1000);
                    }
                    d = d - keyFrames[i].distSinceStop;
                }
                else
                {
                    if (tTo <= 30000)
                    {
                        d = 0.5f * (tTo / 1000) * (tTo / 1000);
                    }
                    else
                    {
                        d = 0.5f * 30 * 30 + 30 * ((tTo - 30000) / 1000);
                    }
                    d = keyFrames[i].distUntilStop - d;
                }
                t += 100;
            }
            t -= 100;
        }

        if (keyFrames[i + 1].tFrom > keyFrames[i + 1].tTo)
            t += 100 - ((long)keyFrames[i + 1].tTo % 100);
        else
            t += (long)keyFrames[i + 1].tTo % 100;

        teleport = false;
        if ((keyFrames[i + 1].node->actionFlag == 1) || (keyFrames[i + 1].node->mapid != keyFrames[i].node->mapid))
        {
            teleport = true;
            cM = keyFrames[i + 1].node->mapid;
        }

        m_WayPoints[t] = WayPoint(keyFrames[i + 1].node->mapid, keyFrames[i + 1].node->x, keyFrames[i + 1].node->y, keyFrames[i + 1].node->z, teleport,
            0, keyFrames[i + 1].node->arrivalEventID, keyFrames[i + 1].node->departureEventID);
        //        sLog->outInfo(LOG_FILTER_TRANSPORTS, "T: %d, x: %f, y: %f, z: %f, t:%d", t, pos.x, pos.y, pos.z, teleport);

        t += keyFrames[i + 1].node->delay * 1000;
    }

    uint32 timer = t;

    //    sLog->outInfo(LOG_FILTER_TRANSPORTS, "    Generated %lu waypoints, total time %u.", (unsigned long)m_WayPoints.size(), timer);

    m_curr = m_WayPoints.begin();
    m_next = GetNextWayPoint();
    m_pathTime = timer;

    m_nextNodeTime = m_curr->first;

    return true;
}

Transport::WayPointMap::const_iterator Transport::GetNextWayPoint()
{
    WayPointMap::const_iterator iter = m_curr;
    ++iter;
    if (iter == m_WayPoints.end())
        iter = m_WayPoints.begin();
    return iter;
}

void Transport::TeleportTransport(uint32 newMapid, float x, float y, float z)
{
    Map const* oldMap = GetMap();
    Relocate(x, y, z);

    for (PlayerSet::const_iterator itr = m_passengers.begin(); itr != m_passengers.end();)
    {
        Player* player = *itr;
        ++itr;

        if (player->isDead() && !player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            player->ResurrectPlayer(1.0f);

        player->TeleportTo(newMapid, x, y, z, GetOrientation(), TELE_TO_NOT_LEAVE_TRANSPORT);
    }

    //we need to create and save new Map object with 'newMapid' because if not done -> lead to invalid Map object reference...
    //player far teleport would try to create same instance, but we need it NOW for transport...

    RemoveFromWorld();
    ResetMap();
    Map* newMap = sMapMgr->CreateBaseMap(newMapid);
    SetMap(newMap);
    ASSERT(GetMap());
    AddToWorld();

    if (oldMap != newMap)
    {
        UpdateForMap(oldMap);
        UpdateForMap(newMap);
    }

    for (CreatureSet::iterator itr = m_NPCPassengerSet.begin(); itr != m_NPCPassengerSet.end(); ++itr)
        (*itr)->FarTeleportTo(newMap, x, y, z, (*itr)->GetOrientation());
}

bool Transport::AddPassenger(Player* passenger)
{
    if (m_passengers.insert(passenger).second)
        sLog->outInfo(LOG_FILTER_TRANSPORTS, "Player %s boarded transport %s.", passenger->GetName().c_str(), GetName().c_str());

    sScriptMgr->OnAddPassenger(this, passenger);
    return true;
}

bool Transport::RemovePassenger(Player* passenger)
{
    if (m_passengers.erase(passenger))
        sLog->outInfo(LOG_FILTER_TRANSPORTS, "Player %s removed from transport %s.", passenger->GetName().c_str(), GetName().c_str());

    sScriptMgr->OnRemovePassenger(this, passenger);
    return true;
}

void Transport::Update(uint32 p_diff)
{
    if (!AI())
    {
        if (!AIM_Initialize())
            sLog->outError(LOG_FILTER_TRANSPORTS, "Could not initialize GameObjectAI for Transport");
    } else
        AI()->UpdateAI(p_diff);

    if (m_WayPoints.size() <= 1)
        return;

    m_timer = getMSTime() % m_period;
    while (((m_timer - m_curr->first) % m_pathTime) > ((m_next->first - m_curr->first) % m_pathTime))
    {
        DoEventIfAny(*m_curr, true);

        m_curr = GetNextWayPoint();
        m_next = GetNextWayPoint();

        DoEventIfAny(*m_curr, false);

        // first check help in case client-server transport coordinates de-synchronization
        if (m_curr->second.mapid != GetMapId() || m_curr->second.teleport)
        {
            TeleportTransport(m_curr->second.mapid, m_curr->second.x, m_curr->second.y, m_curr->second.z);
        }
        else
        {
            Relocate(m_curr->second.x, m_curr->second.y, m_curr->second.z, GetAngle(m_next->second.x, m_next->second.y) + float(M_PI));
            UpdateNPCPositions(); // COME BACK MARKER
        }

        sScriptMgr->OnRelocate(this, m_curr->first, m_curr->second.mapid, m_curr->second.x, m_curr->second.y, m_curr->second.z);

        m_nextNodeTime = m_curr->first;

        if (m_curr == m_WayPoints.begin())
            sLog->outDebug(LOG_FILTER_TRANSPORTS, " ************ BEGIN ************** %s", m_name.c_str());

        sLog->outDebug(LOG_FILTER_TRANSPORTS, "%s moved to %d %f %f %f %d", m_name.c_str(), m_curr->second.id, m_curr->second.x, m_curr->second.y, m_curr->second.z, m_curr->second.mapid);
    }

    sScriptMgr->OnTransportUpdate(this, p_diff);
}

void Transport::UpdateForMap(Map const* targetMap)
{
    Map::PlayerList const& player = targetMap->GetPlayers();
    if (player.isEmpty())
        return;

    if (GetMapId() == targetMap->GetId())
    {
        for (Map::PlayerList::const_iterator itr = player.begin(); itr != player.end(); ++itr)
        {
            if (this != itr->getSource()->GetTransport())
            {
                UpdateData transData;
                BuildCreateUpdateBlockForPlayer(&transData, itr->getSource());
                WorldPacket packet;
                transData.BuildPacket(&packet);
                itr->getSource()->SendDirectMessage(&packet);
            }
        }
    }
    else
    {
        UpdateData transData;
        BuildOutOfRangeUpdateBlock(&transData);
        WorldPacket out_packet;
        transData.BuildPacket(&out_packet);

        for (Map::PlayerList::const_iterator itr = player.begin(); itr != player.end(); ++itr)
            if (this != itr->getSource()->GetTransport())
                itr->getSource()->SendDirectMessage(&out_packet);
    }
}

void Transport::DoEventIfAny(WayPointMap::value_type const& node, bool departure)
{
    if (uint32 eventid = departure ? node.second.departureEventID : node.second.arrivalEventID)
    {
        sLog->outDebug(LOG_FILTER_MAPSCRIPTS, "Taxi %s event %u of node %u of %s path", departure ? "departure" : "arrival", eventid, node.first, GetName().c_str());
        GetMap()->ScriptsStart(sEventScripts, eventid, this, this);
        EventInform(eventid);
    }
}

void Transport::BuildStartMovePacket(Map const* targetMap)
{
    SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    SetGoState(GO_STATE_ACTIVE);
    UpdateForMap(targetMap);
}

void Transport::BuildStopMovePacket(Map const* targetMap)
{
    RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
    SetGoState(GO_STATE_READY);
    UpdateForMap(targetMap);
}

uint32 Transport::AddNPCPassenger(uint32 tguid, uint32 entry, float x, float y, float z, float o, uint32 anim)
{
    Map* map = GetMap();
    //make it world object so it will not be unloaded with grid
    Creature* creature = new Creature(true);

    if (!creature->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), map, GetPhaseMask(), entry, 0, GetGOInfo()->faction, 0, 0, 0, 0))
    {
        delete creature;
        return 0;
    }

    creature->SetTransport(this);
    creature->AddUnitMovementFlag(MOVEMENTFLAG_ONTRANSPORT);
    creature->m_movementInfo.guid = GetGUID();
    creature->m_movementInfo.t_pos.Relocate(x, y, z, o);

    if (anim)
        creature->SetUInt32Value(UNIT_NPC_EMOTESTATE, anim);

    creature->Relocate(
        GetPositionX() + (x * std::cos(GetOrientation()) + y * std::sin(GetOrientation() + float(M_PI))),
        GetPositionY() + (y * std::cos(GetOrientation()) + x * std::sin(GetOrientation())),
        z + GetPositionZ(),
        o + GetOrientation());

    creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());
    creature->SetTransportHomePosition(creature->m_movementInfo.t_pos);

    if (!creature->IsPositionValid())
    {
        sLog->outError(LOG_FILTER_TRANSPORTS, "Creature (guidlow %d, entry %d) not created. Suggested coordinates isn't valid (X: %f Y: %f)", creature->GetGUIDLow(), creature->GetEntry(), creature->GetPositionX(), creature->GetPositionY());
        delete creature;
        return 0;
    }

    map->AddToMap(creature);
    m_NPCPassengerSet.insert(creature);

    if (tguid == 0)
    {
        ++currenttguid;
        tguid = currenttguid;
    }
    else
        currenttguid = std::max(tguid, currenttguid);

    creature->SetGUIDTransport(tguid);
    sScriptMgr->OnAddCreaturePassenger(this, creature);
    return tguid;
}

void Transport::UpdatePosition(MovementInfo* mi)
{
    float transport_o = mi->pos.GetOrientation() - mi->t_pos.GetOrientation();
    float transport_x = mi->pos.m_positionX - (mi->t_pos.m_positionX * std::cos(transport_o) - mi->t_pos.m_positionY * std::sin(transport_o));
    float transport_y = mi->pos.m_positionY - (mi->t_pos.m_positionY * std::cos(transport_o) + mi->t_pos.m_positionX * std::sin(transport_o));
    float transport_z = mi->pos.m_positionZ - mi->t_pos.m_positionZ;

    Relocate(transport_x, transport_y, transport_z, transport_o);
    UpdateNPCPositions();
}

void Transport::UpdateNPCPositions()
{
    for (CreatureSet::iterator itr = m_NPCPassengerSet.begin(); itr != m_NPCPassengerSet.end(); ++itr)
    {
        Creature* npc = *itr;

        float x, y, z, o;
        npc->m_movementInfo.t_pos.GetPosition(x, y, z, o);
        CalculatePassengerPosition(x, y, z, o);
        GetMap()->CreatureRelocation(npc, x, y, z, o, false);
        npc->GetTransportHomePosition(x, y, z, o);
        CalculatePassengerPosition(x, y, z, o);
        npc->SetHomePosition(x, y, z, o);
    }
}

void Transport::CalculatePassengerPosition(float& x, float& y, float& z, float& o)
{
    float inx = x, iny = y, inz = z, ino = o;
    o = GetOrientation() + ino;
    x = GetPositionX() + inx * std::cos(GetOrientation()) - iny * std::sin(GetOrientation());
    y = GetPositionY() + iny * std::cos(GetOrientation()) + inx * std::sin(GetOrientation());
    z = GetPositionZ() + inz;
}

void Transport::CalculatePassengerOffset(float& x, float& y, float& z, float& o)
{
    o -= GetOrientation();
    z -= GetPositionZ();
    y -= GetPositionY();    // y = searchedY * std::cos(o) + searchedX * std::sin(o)
    x -= GetPositionX();    // x = searchedX * std::cos(o) + searchedY * std::sin(o + pi)
    float inx = x, iny = y;
    y = (iny - inx * tan(GetOrientation())) / (cos(GetOrientation()) + std::sin(GetOrientation()) * tan(GetOrientation()));
    x = (inx + iny * tan(GetOrientation())) / (cos(GetOrientation()) + std::sin(GetOrientation()) * tan(GetOrientation()));
}
