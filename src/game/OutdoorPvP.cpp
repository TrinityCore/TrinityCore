#include "OutdoorPvP.h"
#include "OutdoorPvPMgr.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Map.h"
#include "MapManager.h"
#include "OutdoorPvPObjectiveAI.h"
#include "Group.h"
#include "WorldPacket.h"

OutdoorPvPObjective::OutdoorPvPObjective(OutdoorPvP * pvp) 
: m_PvP(pvp), m_AllianceActivePlayerCount(0), m_HordeActivePlayerCount(0),
m_ShiftTimer(0), m_ShiftPhase(0), m_ShiftMaxPhase(0), m_OldPhase(0),
m_State(0), m_OldState(0), m_CapturePoint(0), m_NeutralValue(0), m_ShiftMaxCaptureSpeed(0), m_CapturePointCreature(0)
{
}

bool OutdoorPvPObjective::HandlePlayerEnter(Player * plr)
{
    // only called if really entered, so no use in the return value anymore
    // player distance and activity state was checked already in the AI
    std::set<uint64>::iterator pitr = m_ActivePlayerGuids.find(plr->GetGUID());
    // if not already counted as active, add player
    if(pitr == m_ActivePlayerGuids.end())
    {
        if(plr->GetTeam() == ALLIANCE)
            ++m_AllianceActivePlayerCount;
        else
            ++m_HordeActivePlayerCount;
        m_ActivePlayerGuids.insert(plr->GetGUID());
        sLog.outDebug("player %u entered an outdoorpvpobjective", plr->GetGUIDLow());
        return true;
    }
    return true;
}

void OutdoorPvPObjective::HandlePlayerLeave(Player * plr)
{
    // only decrease the count if the player is in the active list
    if(m_ActivePlayerGuids.find(plr->GetGUID())!=m_ActivePlayerGuids.end())
    {
        if(plr->GetTeam() == ALLIANCE)
            --m_AllianceActivePlayerCount;
        else
            --m_HordeActivePlayerCount;
        m_ActivePlayerGuids.erase(plr->GetGUID());
    }
}

void OutdoorPvPObjective::HandlePlayerActivityChanged(Player * plr)
{
    if(m_CapturePointCreature)
        if(Creature * c = HashMapHolder<Creature>::Find(m_CapturePointCreature))
            if(c->AI())
                c->AI()->MoveInLineOfSight(plr);
}

bool OutdoorPvPObjective::AddObject(uint32 type, uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3)
{
    GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(entry);
    if (!goinfo)
        return false;

    uint32 guid = objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT);

    GameObjectData& data = objmgr.NewGOData(guid);

    data.id             = entry;
    data.mapid          = map;
    data.posX           = x;
    data.posY           = y;
    data.posZ           = z;
    data.orientation    = o;
    data.rotation0      = rotation0;
    data.rotation1      = rotation1;
    data.rotation2      = rotation2;
    data.rotation3      = rotation3;
    data.spawntimesecs  = 0;
    data.animprogress   = 100;
    data.spawnMask      = 1;
    data.go_state       = 1;

    objmgr.AddGameobjectToGrid(guid, &data);

    // 2 way registering
    m_Objects[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_GAMEOBJECT);
    m_ObjectTypes[m_Objects[type]]=type;

    Map * pMap = MapManager::Instance().FindMap(map);
    if(!pMap)
        return true;
    GameObject * go = new GameObject;
    if(!go->Create(guid,entry, pMap,x,y,z,o,rotation0,rotation1,rotation2,rotation3,100,1))
    {
        sLog.outError("Gameobject template %u not found in database.", entry);
        delete go;
        return true;
    }

    go->SetRespawnTime(0);
    objmgr.SaveGORespawnTime(go->GetDBTableGUIDLow(),0,0);
    pMap->Add(go);

    return true;
}

bool OutdoorPvPObjective::AddCreature(uint32 type, uint32 entry, uint32 teamval, uint32 map, float x, float y, float z, float o, uint32 spawntimedelay)
{
    CreatureInfo const *cinfo = objmgr.GetCreatureTemplate(entry);
    if(!cinfo)
    {
        return false;
    }

    uint32 displayId = objmgr.ChooseDisplayId(teamval, cinfo, NULL);
    CreatureModelInfo const *minfo = objmgr.GetCreatureModelRandomGender(displayId);
    if (!minfo)
    {
        return false;
    }
    else
        displayId = minfo->modelid;                        // it can be different (for another gender)

    uint32 guid = objmgr.GenerateLowGuid(HIGHGUID_UNIT);

    CreatureData& data = objmgr.NewOrExistCreatureData(guid);

    data.id = entry;
    data.mapid = map;
    data.displayid = displayId;
    data.equipmentId = cinfo->equipmentId;
    data.posX = x;
    data.posY = y;
    data.posZ = z;
    data.orientation = o;
    data.spawntimesecs = spawntimedelay;
    data.spawndist = 0;
    data.currentwaypoint = 0;
    data.curhealth = cinfo->maxhealth;
    data.curmana = cinfo->maxmana;
    data.is_dead = false;
    data.movementType = cinfo->MovementType;
    data.spawnMask = 1;

    objmgr.AddCreatureToGrid(guid, &data);

    m_Creatures[type] = MAKE_NEW_GUID(guid, entry, HIGHGUID_UNIT);
    m_CreatureTypes[m_Creatures[type]] = type;

    Map * pMap = MapManager::Instance().FindMap(map);
    if(!pMap)
        return true;
    Creature* pCreature = new Creature;
    if (!pCreature->Create(guid, pMap, entry, teamval))
    {
        sLog.outError("Can't create creature entry: %u",entry);
        delete pCreature;
        return true;
    }

    pCreature->AIM_Initialize();

    pCreature->Relocate(x, y, z, o);

    if(!pCreature->IsPositionValid())
    {
        sLog.outError("ERROR: Creature (guidlow %d, entry %d) not added to opvp. Suggested coordinates isn't valid (X: %f Y: %f)",pCreature->GetGUIDLow(),pCreature->GetEntry(),pCreature->GetPositionX(),pCreature->GetPositionY());
        return false;
    }

    if(spawntimedelay)
        pCreature->SetRespawnDelay(spawntimedelay);

    pMap->Add(pCreature);

    return true;
}

bool OutdoorPvPObjective::AddCapturePoint(uint32 entry, uint32 map, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3)
{
    sLog.outDebug("creating capture point %u and capture point creature",entry);

    // check info existence
    GameObjectInfo const* goinfo = objmgr.GetGameObjectInfo(entry);
    if (!goinfo)
        return false;

    CreatureInfo const *cinfo = objmgr.GetCreatureTemplate(OPVP_TRIGGER_CREATURE_ENTRY);
    if(!cinfo)
        return false;

    // create capture point creature
    uint32 displayId = objmgr.ChooseDisplayId(0, cinfo, NULL);

    uint32 creature_guid = objmgr.GenerateLowGuid(HIGHGUID_UNIT);

    CreatureData& cdata = objmgr.NewOrExistCreatureData(creature_guid);

    cdata.id = OPVP_TRIGGER_CREATURE_ENTRY;
    cdata.mapid = map;
    cdata.displayid = displayId;
    cdata.equipmentId = cinfo->equipmentId;
    cdata.posX = x;
    cdata.posY = y;
    cdata.posZ = z;
    cdata.orientation = o;
    cdata.spawntimesecs = 1;
    cdata.spawndist = 0;
    cdata.currentwaypoint = 0;
    cdata.curhealth = cinfo->maxhealth;
    cdata.curmana = cinfo->maxmana;
    cdata.is_dead = false;
    cdata.movementType = cinfo->MovementType;
    cdata.spawnMask = 1;

    objmgr.AddCreatureToGrid(creature_guid, &cdata);
    m_CapturePointCreature = MAKE_NEW_GUID(creature_guid, OPVP_TRIGGER_CREATURE_ENTRY, HIGHGUID_UNIT);

    // create capture point go
    uint32 guid = objmgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT);

    GameObjectData& data = objmgr.NewGOData(guid);

    data.id             = entry;
    data.mapid          = map;
    data.posX           = x;
    data.posY           = y;
    data.posZ           = z;
    data.orientation    = o;
    data.rotation0      = rotation0;
    data.rotation1      = rotation1;
    data.rotation2      = rotation2;
    data.rotation3      = rotation3;
    data.spawntimesecs  = 1;
    data.animprogress   = 100;
    data.spawnMask      = 1;
    data.go_state       = 1;

    objmgr.AddGameobjectToGrid(guid, &data);

    m_CapturePoint = MAKE_NEW_GUID(guid, entry, HIGHGUID_GAMEOBJECT);

    // get the needed values from goinfo
    m_ShiftMaxPhase = goinfo->raw.data[17];
    m_ShiftMaxCaptureSpeed = m_ShiftMaxPhase / float(goinfo->raw.data[16]);
    m_NeutralValue = goinfo->raw.data[12];

    // add to map if map is already loaded
    Map * pMap = MapManager::Instance().FindMap(map);
    if(!pMap)
        return true;
    // add GO...
    GameObject * go = new GameObject;
    if(!go->Create(guid,entry, pMap,x,y,z,o,rotation0,rotation1,rotation2,rotation3,100,1))
    {
        sLog.outError("Gameobject template %u not found in database.", entry);
        delete go;
    }
    else
    {
        go->SetRespawnTime(0);
        objmgr.SaveGORespawnTime(go->GetDBTableGUIDLow(), 0, 0);
        pMap->Add(go);
    }
    // add creature...
    Creature* pCreature = new Creature;
    if (!pCreature->Create(creature_guid, pMap, OPVP_TRIGGER_CREATURE_ENTRY, 0))
    {
        sLog.outError("Can't create creature entry: %u",entry);
        delete pCreature;
    }
    else
    {
        pCreature->AIM_Initialize();

        pCreature->Relocate(x, y, z, o);

        if(!pCreature->IsPositionValid())
        {
            sLog.outError("ERROR: Creature (guidlow %d, entry %d) not added to opvp. Suggested coordinates isn't valid (X: %f Y: %f)",pCreature->GetGUIDLow(),pCreature->GetEntry(),pCreature->GetPositionX(),pCreature->GetPositionY());
            return false;
        }

        pMap->Add(pCreature);
    }
    return true;
}

bool OutdoorPvPObjective::DelCreature(uint32 type)
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
    // dont save respawn time
    cr->SetRespawnTime(0);
    cr->RemoveCorpse();
    cr->CleanupsBeforeDelete();
    // explicit removal from map
    // beats me why this is needed, but with the recent removal "cleanup" some creatures stay in the map if "properly" deleted
    // so this is a big fat workaround, if AddObjectToRemoveList and DoDelayedMovesAndRemoves worked correctly, this wouldn't be needed
    if(Map * map = MapManager::Instance().FindMap(cr->GetMapId()))
        map->Remove(cr,false);
    // delete respawn time for this creature
    WorldDatabase.PExecute("DELETE FROM creature_respawn WHERE guid = '%u'", guid);
    cr->AddObjectToRemoveList();
    objmgr.DeleteCreatureData(guid);
    m_CreatureTypes[m_Creatures[type]] = 0;
    m_Creatures[type] = 0;
    return true;
}

bool OutdoorPvPObjective::DelObject(uint32 type)
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

bool OutdoorPvPObjective::DelCapturePoint()
{
    if(m_CapturePoint)
    {
        GameObject *obj = HashMapHolder<GameObject>::Find(m_CapturePoint);
        if(obj)
        {
            uint32 guid = obj->GetDBTableGUIDLow();
            obj->SetRespawnTime(0);                                 // not save respawn time
            obj->Delete();
            objmgr.DeleteGOData(guid);
        }
        m_CapturePoint = 0;
    }
    if(m_CapturePointCreature)
    {
        Creature *cr = HashMapHolder<Creature>::Find(m_CapturePointCreature);
        if(cr)
        {
            uint32 guid = cr->GetDBTableGUIDLow();
            // dont save respawn time
            cr->SetRespawnTime(0);
            cr->RemoveCorpse();
            cr->CleanupsBeforeDelete();
            // explicit removal from map
            // beats me why this is needed, but with the recent removal "cleanup" some creatures stay in the map if "properly" deleted
            // so this is a big fat workaround, if AddObjectToRemoveList and DoDelayedMovesAndRemoves worked correctly, this wouldn't be needed
            if(Map * map = MapManager::Instance().FindMap(cr->GetMapId()))
                map->Remove(cr,false);
            // delete respawn time for this creature
            WorldDatabase.PExecute("DELETE FROM creature_respawn WHERE guid = '%u'", guid);
            cr->AddObjectToRemoveList();
            objmgr.DeleteCreatureData(guid);
        }
        m_CapturePointCreature = 0;
    }
    return true;
}

void OutdoorPvPObjective::DeleteSpawns()
{
    for(std::map<uint32,uint64>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i)
        DelObject(i->first);
    for(std::map<uint32,uint64>::iterator i = m_Creatures.begin(); i != m_Creatures.end(); ++i)
        DelCreature(i->first);
    DelCapturePoint();
}

void OutdoorPvP::DeleteSpawns()
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
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
    if(plr->GetTeam()==ALLIANCE)
        m_PlayerGuids[0].insert(plr->GetGUID());
    else
        m_PlayerGuids[1].insert(plr->GetGUID());
}

void OutdoorPvP::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    // inform the objectives of the leaving
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
        (*itr)->HandlePlayerLeave(plr);
    // remove the world state information from the player (we can't keep everyone up to date, so leave out those who are not in the concerning zones)
    if(zone != plr->GetZoneId())
        SendRemoveWorldStates(plr);
    if(plr->GetTeam()==ALLIANCE)
        m_PlayerGuids[0].erase(plr->GetGUID());
    else
        m_PlayerGuids[1].erase(plr->GetGUID());
    sLog.outDebug("player left an outdoorpvp zone");
}

bool OutdoorPvP::Update(uint32 diff)
{
    bool objective_changed = false;
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
        objective_changed |= (*itr)->Update(diff);
    return objective_changed;
}

bool OutdoorPvPObjective::Update(uint32 diff)
{
    uint32 Challenger = 0;
    if(m_ShiftTimer<diff)
    {
        m_ShiftTimer = OUTDOORPVP_OBJECTIVE_UPDATE_INTERVAL;

        // get the difference of numbers
        float fact_diff = (m_AllianceActivePlayerCount - m_HordeActivePlayerCount);

        if(fact_diff<0)
        {
            if(fact_diff < - m_ShiftMaxCaptureSpeed)
                fact_diff = - m_ShiftMaxCaptureSpeed;
            Challenger = HORDE;
            // horde is in majority, but it's already horde-controlled -> no change
            if(m_State == OBJECTIVESTATE_HORDE && m_ShiftPhase == - m_ShiftMaxPhase)
                return false;
        }
        else if(fact_diff>0)
        {
            if(fact_diff > m_ShiftMaxCaptureSpeed)
                fact_diff = m_ShiftMaxCaptureSpeed;
            Challenger = ALLIANCE;
            // ally is in majority, but it's already ally-controlled -> no change
            if(m_State == OBJECTIVESTATE_ALLIANCE && m_ShiftPhase == m_ShiftMaxPhase)
                return false;
        }
        else /*if(fact_diff==0)*/ // no change
            return false;

        m_OldPhase = m_ShiftPhase;

        m_OldState = m_State;

        m_ShiftPhase += fact_diff;

        // check limits, these are over the grey part
        if(m_ShiftPhase <= - m_ShiftMaxPhase * (float)(m_NeutralValue) / 100.0f)
        {
            if(m_ShiftPhase <= - m_ShiftMaxPhase)
                m_ShiftPhase = - m_ShiftMaxPhase;
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
    } else m_ShiftTimer-=diff;

    return false;
}

bool OutdoorPvPObjective::HandleCaptureCreaturePlayerMoveInLos(Player * p, Creature * c)
{
    // check if guid matches
    if(c->GetGUID() != m_CapturePointCreature)
        return false;

    // check if capture point go is spawned
    GameObject * cp = HashMapHolder<GameObject>::Find(m_CapturePoint);
    if(!cp)
        return false;

    // check range and activity
    if(cp->IsWithinDistInMap(p,cp->GetGOInfo()->raw.data[0]) && p->IsOutdoorPvPActive())
    {
        // data[8] will be used for player enter
        return HandleCapturePointEvent(p, cp->GetGOInfo()->raw.data[8]); //i_objective->HandlePlayerEnter((Player*)u);
    }
    else
    {
        // data[9] will be used for player leave
        return HandleCapturePointEvent(p, cp->GetGOInfo()->raw.data[9]); //i_objective->HandlePlayerLeave((Player*)u);
    }
}

void OutdoorPvP::SendUpdateWorldState(uint32 field, uint32 value)
{
    // send to both factions
    for(int i = 0; i < 2; ++i)
    {
        // send to all players present in the area
        for(std::set<uint64>::iterator itr = m_PlayerGuids[i].begin(); itr != m_PlayerGuids[i].end(); ++itr)
        {
            Player * plr = objmgr.GetPlayer(*itr);
            if(plr)
            {
                plr->SendUpdateWorldState(field,value);
            }
        }
    }
}

void OutdoorPvPObjective::SendUpdateWorldState(uint32 field, uint32 value)
{
    // send to all players present in the area
    for(std::set<uint64>::iterator itr = m_ActivePlayerGuids.begin(); itr != m_ActivePlayerGuids.end(); ++itr)
    {
        Player * plr = objmgr.GetPlayer(*itr);
        if(plr)
        {
            plr->SendUpdateWorldState(field,value);
        }
    }
}

void OutdoorPvPObjective::SendObjectiveComplete(uint32 id,uint64 guid)
{
    uint32 controlling_faction;
    switch(m_State)
    {
    case OBJECTIVESTATE_ALLIANCE:
        controlling_faction = ALLIANCE;
        break;
    case OBJECTIVESTATE_HORDE:
        controlling_faction = HORDE;
        break;
    default:
        return;
        break;
    }

    // send to all players present in the area
    for(std::set<uint64>::iterator itr = m_ActivePlayerGuids.begin(); itr != m_ActivePlayerGuids.end(); ++itr)
    {
        Player * plr = objmgr.GetPlayer(*itr);
        if(plr && plr->GetTeam() == controlling_faction)
        {
            plr->KilledMonster(id,guid);
        }
    }
}

void OutdoorPvP::HandlePlayerActivityChanged(Player * plr)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
        (*itr)->HandlePlayerActivityChanged(plr);
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

bool OutdoorPvP::IsInsideObjective(Player *plr)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->IsInsideObjective(plr))
            return true;
    }
    return false;
}

bool OutdoorPvPObjective::IsInsideObjective(Player *plr)
{
    std::set<uint64>::iterator itr = m_ActivePlayerGuids.find(plr->GetGUID());
    return itr != m_ActivePlayerGuids.end();
}

bool OutdoorPvP::HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->HandleCustomSpell(plr,spellId,go))
            return true;
    }
    return false;
}

bool OutdoorPvPObjective::HandleCustomSpell(Player *plr, uint32 spellId, GameObject * go)
{
    if(!plr->IsOutdoorPvPActive())
        return false;
    return false;
}

bool OutdoorPvP::HandleOpenGo(Player *plr, uint64 guid)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->HandleOpenGo(plr,guid) >= 0)
            return true;
    }
    return false;
}

bool OutdoorPvP::HandleCaptureCreaturePlayerMoveInLos(Player * p, Creature * c)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->HandleCaptureCreaturePlayerMoveInLos(p, c))
            return true;
    }
    return false;
}

bool OutdoorPvP::HandleGossipOption(Player * plr, uint64 guid, uint32 id)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->HandleGossipOption(plr, guid, id))
            return true;
    }
    return false;
}

bool OutdoorPvP::CanTalkTo(Player * plr, Creature * c, GossipOption &gso)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->CanTalkTo(plr, c, gso))
            return true;
    }
    return false;
}

bool OutdoorPvP::HandleDropFlag(Player * plr, uint32 id)
{
    for(OutdoorPvPObjectiveSet::iterator itr = m_OutdoorPvPObjectives.begin(); itr != m_OutdoorPvPObjectives.end(); ++itr)
    {
        if((*itr)->HandleDropFlag(plr, id))
            return true;
    }
    return false;
}

bool OutdoorPvPObjective::HandleGossipOption(Player * plr, uint64 guid, uint32 id)
{
    return false;
}

bool OutdoorPvPObjective::CanTalkTo(Player * plr, Creature * c, GossipOption &gso)
{
    return false;
}

bool OutdoorPvPObjective::HandleDropFlag(Player * plr, uint32 id)
{
    return false;
}

int32 OutdoorPvPObjective::HandleOpenGo(Player *plr, uint64 guid)
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
