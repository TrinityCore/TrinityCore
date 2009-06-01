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
: m_PvP(pvp), m_ShiftPhase(0), m_ShiftMaxPhase(0), m_OldPhase(0),
m_State(0), m_OldState(0), m_CapturePointGUID(0), m_NeutralValue(0),
m_ShiftMaxCaptureSpeed(0), m_capturePoint(NULL)
{
}

bool OPvPCapturePoint::HandlePlayerEnter(Player * plr)
{
    return m_activePlayers[plr->GetTeamId()].insert(plr).second;
}

void OPvPCapturePoint::HandlePlayerLeave(Player * plr)
{
    m_activePlayers[plr->GetTeamId()].erase(plr);
}

bool OPvPCapturePoint::AddObject(uint32 type, uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3)
{
    uint32 guid = objmgr.AddGameObject(entry, map, x, y, z, o, 0, rotation0, rotation1, rotation2, rotation3);
    if(!guid)
        return false;

    // 2 way registering
    m_Objects[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_GAMEOBJECT);
    m_ObjectTypes[m_Objects[type]]=type;

    return true;
}

bool OPvPCapturePoint::AddCreature(uint32 type, uint32 entry, uint32 team, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay)
{
    uint32 guid = objmgr.AddCreature(entry, team, map, x, y, z, o, spawntimedelay);
    if(!guid)
        return false;

    m_Creatures[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_UNIT);
    m_CreatureTypes[m_Creatures[type]] = type;
    return true;
}

bool OPvPCapturePoint::AddCapturePoint(uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3)
{
    sLog.outDebug("Creating capture point %u", entry);

    // check info existence
    GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(entry);
    if(!goinfo || goinfo->type != GAMEOBJECT_TYPE_CAPTURE_POINT)
    {
        sLog.outError("OutdoorPvP: GO %u is not capture point!", goinfo->id);
        return false;
    }

    m_CapturePointGUID = objmgr.AddGameObject(entry, map, x, y, z, o, 0, rotation0, rotation1, rotation2, rotation3);
    if(!m_CapturePointGUID)
        return false;

    // get the needed values from goinfo
    m_ShiftMaxPhase = goinfo->capturePoint.maxTime;
    m_ShiftMaxCaptureSpeed = m_ShiftMaxPhase / float(goinfo->capturePoint.minTime);
    m_NeutralValue = goinfo->capturePoint.neutralPercent;

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
    cr->CleanupsBeforeDelete();
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
    objmgr.DeleteGOData(m_CapturePointGUID);
    m_CapturePointGUID = 0;

    if(m_capturePoint)
    {
        m_capturePoint->SetRespawnTime(0);                                 // not save respawn time
        m_capturePoint->Delete();
    }

    return true;
}

void OPvPCapturePoint::DeleteSpawns()
{
    for(std::map<uint32,uint64>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
        DelObject(i->first);
    for(std::map<uint32,uint64>::iterator i = m_Creatures.begin(); i != m_Creatures.end(); ++i)
        DelCreature(i->first);
    DelCapturePoint();
}

void OutdoorPvP::DeleteSpawns()
{
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        (*itr)->DeleteSpawns();
}

OutdoorPvP::OutdoorPvP()
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
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        (*itr)->HandlePlayerLeave(plr);
    // remove the world state information from the player (we can't keep everyone up to date, so leave out those who are not in the concerning zones)
    if(!plr->GetSession()->PlayerLogout())
        SendRemoveWorldStates(plr);
    m_players[plr->GetTeamId()].erase(plr);
    sLog.outDebug("Player %s left an outdoorpvp zone", plr->GetName());
}

bool OutdoorPvP::Update(uint32 diff)
{
    bool objective_changed = false;
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        objective_changed |= (*itr)->Update(diff);
    return objective_changed;
}

bool OPvPCapturePoint::Update(uint32 diff)
{
    if(!m_capturePoint)
        return false;

    float radius = m_capturePoint->GetGOInfo()->capturePoint.radius;

    for(uint32 team = 0; team < 2; ++team)
    {
        for(PlayerSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end();)
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

    for(std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
    {
        if((*itr)->IsOutdoorPvPActive())
        {
            if(m_activePlayers[(*itr)->GetTeamId()].insert(*itr).second)
                HandlePlayerEnter(*itr);
        }
    }

    // get the difference of numbers
    float fact_diff = (float)m_activePlayers[0].size() - (float)m_activePlayers[1].size();
    if(!fact_diff)
        return false;

    uint32 Challenger = 0;

    if(fact_diff < 0)
    {
        // horde is in majority, but it's already horde-controlled -> no change
        if(m_State == OBJECTIVESTATE_HORDE && m_ShiftPhase <= -m_ShiftMaxPhase)
            return false;

        if(fact_diff < - m_ShiftMaxCaptureSpeed)
            fact_diff = - m_ShiftMaxCaptureSpeed;

        Challenger = HORDE;
    }
    else
    {
        // ally is in majority, but it's already ally-controlled -> no change
        if(m_State == OBJECTIVESTATE_ALLIANCE && m_ShiftPhase >= m_ShiftMaxPhase)
            return false;

        if(fact_diff > m_ShiftMaxCaptureSpeed)
            fact_diff = m_ShiftMaxCaptureSpeed;

        Challenger = ALLIANCE;
    }

    m_OldPhase = m_ShiftPhase;

    m_OldState = m_State;

    m_ShiftPhase += fact_diff;

    // check limits, these are over the grey part
    if(m_ShiftPhase <= -m_ShiftMaxPhase * (float)(m_NeutralValue) / 100.0f)
    {
        if(m_ShiftPhase <= -m_ShiftMaxPhase)
            m_ShiftPhase = -m_ShiftMaxPhase;
        m_State = OBJECTIVESTATE_HORDE;
        return true;
    }
    else if(m_ShiftPhase >= m_ShiftMaxPhase * (float)(m_NeutralValue) / 100.0f)
    {
        if(m_ShiftPhase >= m_ShiftMaxPhase)
            m_ShiftPhase = m_ShiftMaxPhase;
        m_State = OBJECTIVESTATE_ALLIANCE;
        return true;
    }

    if(m_OldPhase*m_ShiftPhase <=0)
    {
        // gone through neutral
        // if challenger is ally, then n->a challenge
        if(Challenger == ALLIANCE)
            m_State = OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE;
        // if challenger is horde, then n->h challenge
        else if(Challenger == HORDE)
            m_State = OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE;
    }
    else
    {
        // old phase and current are on the same side, so one team challenges the other
        if(Challenger == ALLIANCE && (m_OldState == OBJECTIVESTATE_HORDE || m_OldState == OBJECTIVESTATE_NEUTRAL_HORDE_CHALLENGE))
            m_State = OBJECTIVESTATE_HORDE_ALLIANCE_CHALLENGE;
        else if(Challenger == HORDE && (m_OldState == OBJECTIVESTATE_ALLIANCE || m_OldState == OBJECTIVESTATE_NEUTRAL_ALLIANCE_CHALLENGE))
            m_State = OBJECTIVESTATE_ALLIANCE_HORDE_CHALLENGE;
    }

    return true;
}

void OutdoorPvP::SendUpdateWorldState(uint32 field, uint32 value)
{
    // send to both factions
    for(int i = 0; i < 2; ++i)
    {
        // send to all players present in the area
        for(PlayerSet::iterator itr = m_players[i].begin(); itr != m_players[i].end(); ++itr)
            (*itr)->SendUpdateWorldState(field,value);
    }
}

void OPvPCapturePoint::SendUpdateWorldState(uint32 field, uint32 value)
{
    for(uint32 team = 0; team < 2; ++team)
    {
        // send to all players present in the area
        for(PlayerSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)
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
    for(PlayerSet::iterator itr = m_activePlayers[team].begin(); itr != m_activePlayers[team].end(); ++itr)
        (*itr)->KilledMonster(id, guid);
}

void OutdoorPvP::HandleKill(Player *killer, Unit * killed)
{
    if(Group * pGroup = killer->GetGroup())
    {
        for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
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
    for(OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if((*itr)->IsInsideObjective(plr))
            return true;

    return false;
}

bool OPvPCapturePoint::IsInsideObjective(Player *plr) const
{
    return m_activePlayers[plr->GetTeamId()].find(plr) != m_activePlayers[plr->GetTeamId()].end();
}

bool OutdoorPvP::HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go)
{
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        if((*itr)->HandleCustomSpell(plr,spellId,go))
            return true;
    }
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
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        if((*itr)->HandleOpenGo(plr,guid) >= 0)
            return true;
    }
    return false;
}

bool OutdoorPvP::HandleGossipOption(Player * plr, uint64 guid, uint32 id)
{
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        if((*itr)->HandleGossipOption(plr, guid, id))
            return true;
    }
    return false;
}

bool OutdoorPvP::CanTalkTo(Player * plr, Creature * c, GossipOption &gso)
{
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        if((*itr)->CanTalkTo(plr, c, gso))
            return true;
    }
    return false;
}

bool OutdoorPvP::HandleDropFlag(Player * plr, uint32 id)
{
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
    {
        if((*itr)->HandleDropFlag(plr, id))
            return true;
    }
    return false;
}

bool OPvPCapturePoint::HandleGossipOption(Player * plr, uint64 guid, uint32 id)
{
    return false;
}

bool OPvPCapturePoint::CanTalkTo(Player * plr, Creature * c, GossipOption &gso)
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

void OutdoorPvP::BroadcastPacket(WorldPacket &data)
{
    // This is faster than sWorld.SendZoneMessage
    for(uint32 team = 0; team < 2; ++team)
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
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
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            (*itr)->CastSpell(*itr, (uint32)spellId, true);
    else
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
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

    for(OutdoorPvP::OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if((*itr)->m_CapturePointGUID == go->GetDBTableGUIDLow())
            (*itr)->m_capturePoint = add ? go : NULL;
}
