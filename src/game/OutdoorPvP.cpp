/*
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "OutdoorPvP.h"
#include "OutdoorPvPImpl.h"
#include "OutdoorPvPMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Map.h"
#include "MapManager.h"
#include "Group.h"
#include "WorldPacket.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

OPvPCapturePoint::OPvPCapturePoint(OutdoorPvP * pvp)
: m_PvP(pvp), m_value(0), m_maxValue(0), m_team(TEAM_NEUTRAL),
m_State(OBJECTIVESTATE_NEUTRAL), m_OldState(OBJECTIVESTATE_NEUTRAL), m_capturePointGUID(0), m_neutralValuePct(0),
m_maxSpeed(0), m_capturePoint(NULL)
{
}

bool OPvPCapturePoint::HandlePlayerEnter(Player * plr)
{
    if(m_capturePoint)
    {
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldState1, 1);
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate2, (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f));
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate3, m_neutralValuePct);
    }
    return m_activePlayers[plr->GetTeamId()].insert(plr).second;
}

void OPvPCapturePoint::HandlePlayerLeave(Player * plr)
{
    if(m_capturePoint)
        plr->SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldState1, 0);
    m_activePlayers[plr->GetTeamId()].erase(plr);
}

void OPvPCapturePoint::SendChangePhase()
{
    if(!m_capturePoint)
        return;

    // send this too, sometimes the slider disappears, dunno why :(
    SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldState1, 1);
    // send these updates to only the ones in this objective
    SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate2, (uint32)ceil((m_value + m_maxValue) / (2 * m_maxValue) * 100.0f));
    // send this too, sometimes it resets :S
    SendUpdateWorldState(m_capturePoint->GetGOInfo()->capturePoint.worldstate3, m_neutralValuePct);
}

void OPvPCapturePoint::AddGO(uint32 type, uint32 guid, uint32 entry)
{
    if(!entry)
    {
        const GameObjectData *data = objmgr.GetGOData(guid);
        if(!data)
            return;
        entry = data->id;
    }
    m_Objects[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_GAMEOBJECT);
    m_ObjectTypes[m_Objects[type]]=type;
}

void OPvPCapturePoint::AddCre(uint32 type, uint32 guid, uint32 entry)
{
    if(!entry)
    {
        const CreatureData *data = objmgr.GetCreatureData(guid);
        if(!data)
            return;
        entry = data->id;
    }
    m_Creatures[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_UNIT);
    m_CreatureTypes[m_Creatures[type]] = type;
}

bool OPvPCapturePoint::AddObject(uint32 type, uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3)
{
    if(uint32 guid = objmgr.AddGOData(entry, map, x, y, z, o, 0, rotation0, rotation1, rotation2, rotation3))
    {
        AddGO(type, guid, entry);
        return true;
    }

    return false;
}

bool OPvPCapturePoint::AddCreature(uint32 type, uint32 entry, uint32 team, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay)
{
    if(uint32 guid = objmgr.AddCreData(entry, team, map, x, y, z, o, spawntimedelay))
    {
        AddCre(type, guid, entry);
        return true;
    }

    return false;
}

bool OPvPCapturePoint::SetCapturePointData(uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3)
{
    sLog.outDebug("Creating capture point %u", entry);

    // check info existence
    GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(entry);
    if(!goinfo || goinfo->type != GAMEOBJECT_TYPE_CAPTURE_POINT)
    {
        sLog.outError("OutdoorPvP: GO %u is not capture point!", entry);
        return false;
    }

    m_capturePointGUID = objmgr.AddGOData(entry, map, x, y, z, o, 0, rotation0, rotation1, rotation2, rotation3);
    if(!m_capturePointGUID)
        return false;

    // get the needed values from goinfo
    m_maxValue = goinfo->capturePoint.maxTime;
    m_maxSpeed = m_maxValue / (goinfo->capturePoint.minTime ? goinfo->capturePoint.minTime : 60);
    m_neutralValuePct = goinfo->capturePoint.neutralPercent;
    m_minValue = m_maxValue * goinfo->capturePoint.neutralPercent / 100;

    return true;
}

bool OPvPCapturePoint::DelCreature(uint32 type)
{
    if(!m_Creatures[type])
    {
        sLog.outDebug("opvp creature type %u was already deleted",type);
        return false;
    }

    Creature *cr = HashMapHolder<Creature>::Find(m_Creatures[type]);
    if(!cr)
    {
        // can happen when closing the core
        m_Creatures[type] = 0;
        return false;
    }
    sLog.outDebug("deleting opvp creature type %u",type);
    uint32 guid = cr->GetDBTableGUIDLow();
    // Don't save respawn time
    cr->SetRespawnTime(0);
    cr->RemoveCorpse();
    // explicit removal from map
    // beats me why this is needed, but with the recent removal "cleanup" some creatures stay in the map if "properly" deleted
    // so this is a big fat workaround, if AddObjectToRemoveList and DoDelayedMovesAndRemoves worked correctly, this wouldn't be needed
    //if(Map * map = MapManager::Instance().FindMap(cr->GetMapId()))
    //    map->Remove(cr,false);
    // delete respawn time for this creature
    WorldDatabase.PExecute("DELETE FROM creature_respawn WHERE guid = '%u'", guid);
    cr->AddObjectToRemoveList();
    objmgr.DeleteCreatureData(guid);
    m_CreatureTypes[m_Creatures[type]] = 0;
    m_Creatures[type] = 0;
    return true;
}

bool OPvPCapturePoint::DelObject(uint32 type)
{
    if(!m_Objects[type])
        return false;

    GameObject *obj = HashMapHolder<GameObject>::Find(m_Objects[type]);
    if(!obj)
    {
        m_Objects[type] = 0;
        return false;
    }
    uint32 guid = obj->GetDBTableGUIDLow();
    obj->SetRespawnTime(0);                                 // not save respawn time
    obj->Delete();
    objmgr.DeleteGOData(guid);
    m_ObjectTypes[m_Objects[type]] = 0;
    m_Objects[type] = 0;
    return true;
}

bool OPvPCapturePoint::DelCapturePoint()
{
    objmgr.DeleteGOData(m_capturePointGUID);
    m_capturePointGUID = 0;

    if(m_capturePoint)
    {
        m_capturePoint->SetRespawnTime(0);                                 // not save respawn time
        m_capturePoint->Delete();
    }

    return true;
}

void OPvPCapturePoint::DeleteSpawns()
{
    for (std::map<uint32,uint64>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
        DelObject(i->first);
    for (std::map<uint32,uint64>::iterator i = m_Creatures.begin(); i != m_Creatures.end(); ++i)
        DelCreature(i->first);
    DelCapturePoint();
}

void OutdoorPvP::DeleteSpawns()
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->DeleteSpawns();
}

OutdoorPvP::OutdoorPvP() : m_sendUpdate(true)
{
}

OutdoorPvP::~OutdoorPvP()
{
    DeleteSpawns();
}

void OutdoorPvP::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    m_players[plr->GetTeamId()].insert(plr);
}

void OutdoorPvP::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    // inform the objectives of the leaving
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        itr->second->HandlePlayerLeave(plr);
    // remove the world state information from the player (we can't keep everyone up to date, so leave out those who are not in the concerning zones)
    if(!plr->GetSession()->PlayerLogout())
        SendRemoveWorldStates(plr);
    m_players[plr->GetTeamId()].erase(plr);
    sLog.outDebug("Player %s left an outdoorpvp zone", plr->GetName());
}

void OutdoorPvP::HandlePlayerResurrects(Player * plr, uint32 zone)
{
}

bool OutdoorPvP::Update(uint32 diff)
{
    bool objective_changed = false;
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        if(itr->second->Update(diff))
            objective_changed = true;
    }
    return objective_changed;
}

bool OPvPCapturePoint::Update(uint32 diff)
{
    if(!m_capturePoint)
        return false;

    float radius = m_capturePoint->GetGOInfo()->capturePoint.radius;

    for (uint32 team = 0; team < 2; ++team)
    {
        for (PlayerSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end();)
        {
            Player *player = *itr;
            ++itr;
            if(!m_capturePoint->IsWithinDistInMap(player, radius) || !player->IsOutdoorPvPActive())
                HandlePlayerLeave(player);
        }
    }

    std::list<Player*> players;
    Trinity::AnyPlayerInObjectRangeCheck checker(m_capturePoint, radius);
    Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(m_capturePoint, players, checker);
    m_capturePoint->VisitNearbyWorldObject(radius, searcher);

    for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
    {
        if((*itr)->IsOutdoorPvPActive())
        {
            if(m_activePlayers[(*itr)->GetTeamId()].insert(*itr).second)
                HandlePlayerEnter(*itr);
        }
    }

    // get the difference of numbers
    float fact_diff = ((float)m_activePlayers[0].size() - (float)m_activePlayers[1].size()) * diff / OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL;
    if(!fact_diff)
        return false;

    uint32 Challenger = 0;
    float maxDiff = m_maxSpeed * diff;

    if(fact_diff < 0)
    {
        // horde is in majority, but it's already horde-controlled -> no change
        if(m_State == OBJECTIVESTATE_HORDE && m_value <= -m_maxValue)
            return false;

        if(fact_diff < -maxDiff)
            fact_diff = -maxDiff;

        Challenger = HORDE;
    }
    else
    {
        // ally is in majority, but it's already ally-controlled -> no change
        if(m_State == OBJECTIVESTATE_ALLIANCE && m_value >= m_maxValue)
            return false;

        if(fact_diff > maxDiff)
            fact_diff = maxDiff;

        Challenger = ALLIANCE;
    }

    float oldValue = m_value;
    TeamId oldTeam = m_team;

    m_OldState = m_State;

    m_value += fact_diff;

    if(m_value < -m_minValue) // red
    {
        if(m_value < -m_maxValue)
            m_value = -m_maxValue;
        m_State = OBJECTIVESTATE_HORDE;
        m_team = TEAM_HORDE;
    }
    else if(m_value > m_minValue) // blue
    {
        if(m_value > m_maxValue)
            m_value = m_maxValue;
        m_State = OBJECTIVESTATE_ALLIANCE;
        m_team = TEAM_ALLIANCE;
    }
    else if(oldValue * m_value <= 0) // grey, go through mid point
    {
        // if challenger is ally, then n->a challenge
        if(Challenger == ALLIANCE)
            m_State = OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE;
        // if challenger is horde, then n->h challenge
        else if(Challenger == HORDE)
            m_State = OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE;
        m_team = TEAM_NEUTRAL;
    }
    else // grey, did not go through mid point
    {
        // old phase and current are on the same side, so one team challenges the other
        if(Challenger == ALLIANCE && (m_OldState == OBJECTIVESTATE_HORDE || m_OldState == OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE))
            m_State = OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE;
        else if(Challenger == HORDE && (m_OldState == OBJECTIVESTATE_ALLIANCE || m_OldState == OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE))
            m_State = OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE;
        m_team = TEAM_NEUTRAL;
    }

    if(m_value != oldValue)
        SendChangePhase();

    if(m_OldState != m_State)
    {
        //sLog.outError("%u->%u", m_OldState, m_State);
        if(oldTeam != m_team)
            ChangeTeam(oldTeam);
        ChangeState();
        return true;
    }

    return false;
}

void OutdoorPvP::SendUpdateWorldState(uint32 field, uint32 value)
{
    if(m_sendUpdate)
        for (int i = 0; i < 2; ++i)
            for (PlayerSet::iterator itr = m_players[i].begin(); itr != m_players[i].end(); ++itr)
                (*itr)->SendUpdateWorldState(field, value);
}

void OPvPCapturePoint::SendUpdateWorldState(uint32 field, uint32 value)
{
    for (uint32 team = 0; team < 2; ++team)
    {
        // send to all players present in the area
        for (PlayerSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)
        {
            (*itr)->SendUpdateWorldState(field,value);
        }
    }
}

void OPvPCapturePoint::SendObjectiveComplete(uint32 id,uint64 guid)
{
    uint32 team;
    switch(m_State)
    {
    case OBJECTIVESTATE_ALLIANCE:
        team = 0;
        break;
    case OBJECTIVESTATE_HORDE:
        team = 1;
        break;
    default:
        return;
    }

    // send to all players present in the area
    for (PlayerSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)
        (*itr)->KilledMonsterCredit(id, guid);
}

void OutdoorPvP::HandleKill(Player *killer, Unit * killed)
{
    if(Group * pGroup = killer->GetGroup())
    {
        for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
        {
            Player *pGroupGuy = itr->getSource();

            if(!pGroupGuy)
                continue;

            // skip if too far away
            if(!pGroupGuy->IsAtGroupRewardDistance(killed))
                continue;

            // creature kills must be notified, even if not inside objective / not outdoor pvp active
            // player kills only count if active and inside objective
            if(( pGroupGuy->IsOutdoorPvPActive() && IsInsideObjective(pGroupGuy) ) || killed->GetTypeId() == TYPEID_UNIT)
            {
                HandleKillImpl(pGroupGuy, killed);
            }
        }
    }
    else
    {
        // creature kills must be notified, even if not inside objective / not outdoor pvp active
        if(killer && (( killer->IsOutdoorPvPActive() && IsInsideObjective(killer) ) || killed->GetTypeId() == TYPEID_UNIT))
        {
            HandleKillImpl(killer, killed);
        }
    }
}

bool OutdoorPvP::IsInsideObjective(Player *plr) const
{
    for (OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(itr->second->IsInsideObjective(plr))
            return true;

    return false;
}

bool OPvPCapturePoint::IsInsideObjective(Player *plr) const
{
    return m_activePlayers[plr->GetTeamId()].find(plr) != m_activePlayers[plr->GetTeamId()].end();
}

bool OutdoorPvP::HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(itr->second->HandleCustomSpell(plr,spellId,go))
            return true;

    return false;
}

bool OPvPCapturePoint::HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go)
{
    if(!plr->IsOutdoorPvPActive())
        return false;
    return false;
}

bool OutdoorPvP::HandleOpenGo(Player *plr, uint64 guid)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(itr->second->HandleOpenGo(plr,guid) >= 0)
            return true;

    return false;
}

bool OutdoorPvP::HandleGossipOption(Player * plr, uint64 guid, uint32 id)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(itr->second->HandleGossipOption(plr, guid, id))
            return true;

    return false;
}

bool OutdoorPvP::CanTalkTo(Player * plr, Creature * c, GossipMenuItems gso)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(itr->second->CanTalkTo(plr, c, gso))
            return true;

    return false;
}

bool OutdoorPvP::HandleDropFlag(Player * plr, uint32 id)
{
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(itr->second->HandleDropFlag(plr, id))
            return true;

    return false;
}

bool OPvPCapturePoint::HandleGossipOption(Player * plr, uint64 guid, uint32 id)
{
    return false;
}

bool OPvPCapturePoint::CanTalkTo(Player * plr, Creature * c, GossipMenuItems gso)
{
    return false;
}

bool OPvPCapturePoint::HandleDropFlag(Player * plr, uint32 id)
{
    return false;
}

int32 OPvPCapturePoint::HandleOpenGo(Player *plr, uint64 guid)
{
    std::map<uint64,uint32>::iterator itr = m_ObjectTypes.find(guid);
    if(itr != m_ObjectTypes.end())
    {
        return itr->second;
    }
    return -1;
}

bool OutdoorPvP::HandleAreaTrigger(Player *plr, uint32 trigger)
{
    return false;
}

void OutdoorPvP::BroadcastPacket(WorldPacket &data) const
{
    // This is faster than sWorld.SendZoneMessage
    for (uint32 team = 0; team < 2; ++team)
        for (PlayerSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            (*itr)->GetSession()->SendPacket(&data);
}

void OutdoorPvP::RegisterZone(uint32 zoneId)
{
    sOutdoorPvPMgr.AddZone(zoneId, this);
}

bool OutdoorPvP::HasPlayer(Player *plr) const
{
    return m_players[plr->GetTeamId()].find(plr) != m_players[plr->GetTeamId()].end();
}

void OutdoorPvP::TeamCastSpell(TeamId team, int32 spellId)
{
    if(spellId > 0)
        for (PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            (*itr)->CastSpell(*itr, (uint32)spellId, true);
    else
        for (PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            (*itr)->RemoveAura((uint32)-spellId); // by stack?
}

void OutdoorPvP::TeamApplyBuff(TeamId team, uint32 spellId, uint32 spellId2)
{
    TeamCastSpell(team, spellId);
    TeamCastSpell(OTHER_TEAM(team), spellId2 ? -(int32)spellId2 : -(int32)spellId);
}

void OutdoorPvP::OnGameObjectCreate(GameObject *go, bool add)
{
    if(go->GetGoType() != GAMEOBJECT_TYPE_CAPTURE_POINT)
        return;

    if(OPvPCapturePoint *cp = GetCapturePoint(go->GetDBTableGUIDLow()))
        cp->m_capturePoint = add ? go : NULL;
}
