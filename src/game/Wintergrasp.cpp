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

#include "Wintergrasp.h"
#include "SpellAuras.h"
#include "Vehicle.h"
//#include "GameEventMgr.h"
#include "ObjectMgr.h"
#include "World.h"

typedef uint32 TeamPair[2];

enum CreatureEntry
{
    CRE_ENG_A = 30499,
    CRE_ENG_H = 30400,
};

const TeamPair CreatureEntryPair[] =
{
    {32307, 32308}, // Guards
    {30739, 30740}, // Champions
    //{30400, 30499}, // Engineers
    {30870, 30869}, // Flight Masters
    {31101, 31051}, // Hoodoo Master & Sorceress
    {31102, 31052}, // Vieron Blazefeather & Bowyer
    {32296, 32294}, // Quartermaster
    {31107, 31109}, // Lieutenant & Senior Demolitionist
    {31151, 31153}, // Tactical Officer
    {31106, 31108}, // Siegesmith & Siege Master
    {31053, 31054}, // Primalist & Anchorite
    {31091, 31036}, // Commander
    {32615, 32626}, // Warbringer & Brigadier General
    //{31841, 31842), // Spirit Guide
    {0,0}
};

const TeamPair GODisplayPair[] =
{
    {5651, 5652},
    {8256, 8257},
    {0,0}
};

void LoadTeamPair(TeamPairMap &pairMap, const TeamPair *pair)
{
    while((*pair)[0])
    {
        pairMap[(*pair)[0]] = (*pair)[1];
        pairMap[(*pair)[1]] = (*pair)[0];
        ++pair;
    }
}

#define REMOVE_RANK_AURAS(p) (p)->RemoveAura(SPELL_RECRUIT);\
    (p)->RemoveAura(SPELL_CORPORAL);(p)->RemoveAura(SPELL_LIEUTENANT)

typedef std::list<const AreaPOIEntry *> AreaPOIList;

SiegeWorkshop::SiegeWorkshop(OPvPWintergrasp *opvp, BuildingState *state)
: OPvPCapturePoint(opvp), m_buildingState(state), m_wintergrasp(opvp)
, m_engineer(NULL), m_engGuid(0)
{
}

void SiegeWorkshop::SetStateByBuildingState()
{
    if(m_buildingState->team == TEAM_ALLIANCE)
    {
        m_value = m_maxValue;
        m_State = OBJECTIVESTATE_ALLIANCE;
    }
    else if(m_buildingState->team == TEAM_HORDE)
    {
        m_value = -m_maxValue;
        m_State = OBJECTIVESTATE_HORDE;
    }
    else
    {
        m_value = 0;
        m_State = OBJECTIVESTATE_NEUTRAL;
    }

    ChangeState();
    SendChangePhase();
}

void SiegeWorkshop::ChangeState()
{
    uint32 entry = 0;
    if(m_State == OBJECTIVESTATE_ALLIANCE) // to do m_buildingState->team == TEAM_ALLIANCE;
    {
        m_buildingState->team = TEAM_ALLIANCE;
        entry = CRE_ENG_A;
    }
    else if(m_State == OBJECTIVESTATE_HORDE)
    {
        m_buildingState->team = TEAM_HORDE;
        entry = CRE_ENG_H;
    }
    else
        return;

    *m_engEntry = entry;

    // TODO: this may be sent twice
    m_wintergrasp->BroadcastStateChange(m_buildingState);

    // does not work, entry may change
    /*Creature *creature = ObjectAccessor::GetObjectInWorld(m_Creatures[0], (Creature*)NULL);
    if(!creature)
    {
        sLog.outError("SiegeWorkshop::ChangeState cannot find creature " I64FMT " !", m_Creatures[0]);
        return;
    }*/

    if(m_engineer)
    {
        m_engineer->SetOriginalEntry(entry);
        if(entry != m_engineer->GetEntry() || !m_engineer->isAlive())
        {
            m_engineer->Respawn(true);
            DespawnAllVehicles();
        }
    }

    sLog.outDebug("Wintergrasp workshop now belongs to %u.", (uint32)m_buildingState->team);
}

void SiegeWorkshop::DespawnAllVehicles()
{
    while(!m_vehicles.empty())
        (*m_vehicles.begin())->Dismiss();
}

bool OPvPWintergrasp::SetupOutdoorPvP()
{
    m_defender = TeamId(rand()%2);

    // Load buildings
    AreaPOIList areaPOIs;
    float minX = 9999, minY = 9999, maxX = -9999, maxY = -9999;
    for(uint32 i = 0; i < sAreaPOIStore.GetNumRows(); ++i)
    {
        const AreaPOIEntry * poiInfo = sAreaPOIStore.LookupEntry(i);
        if(poiInfo && poiInfo->zoneId == ZONE_WINTERGRASP)
        {
            areaPOIs.push_back(poiInfo);
            if(minX > poiInfo->x) minX = poiInfo->x;
            if(minY > poiInfo->y) minY = poiInfo->y;
            if(maxX < poiInfo->x) maxX = poiInfo->x;
            if(maxY < poiInfo->y) maxY = poiInfo->y;
        }
    }
    minX -= 20; minY -= 20; maxX += 20; maxY += 20;

    QueryResult *result = WorldDatabase.PQuery("SELECT `guid` FROM `gameobject`,`gameobject_template`"
        " WHERE `gameobject`.`map`=571"
        " AND `gameobject`.`position_x`>%f AND `gameobject`.`position_y`>%f"
        " AND `gameobject`.`position_x`<%f AND `gameobject`.`position_y`<%f"
        " AND `gameobject_template`.`type`=33"
        " AND `gameobject`.`id`=`gameobject_template`.`entry`",
        minX, minY, maxX, maxY);
    if(!result)
        return false;

    do
    {
        Field *fields = result->Fetch();
        
        uint32 guid = fields[0].GetUInt32();
        GameObjectData const * goData = objmgr.GetGOData(guid);
        if(!goData) // this should not happen
            continue;

        float x = goData->posX, y = goData->posY;
        float minDist = 100;
        AreaPOIList::iterator poi = areaPOIs.end();
        for(AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end(); ++itr)
        {
            if(!(*itr)->icon[1]) // note: may for other use
                continue;

            float dist = (abs((*itr)->x - x) + abs((*itr)->y - y));
            if(minDist > dist)
            {
                minDist = dist;
                poi = itr;
            }
        }

        if(poi == areaPOIs.end())
            continue;

        // add building to the list
        TeamId teamId = x > POS_X_CENTER ? m_defender : OTHER_TEAM(m_defender);
        m_buildingStates[guid] = new BuildingState((*poi)->worldState, teamId, m_defender != TEAM_ALLIANCE);
        areaPOIs.erase(poi);

        //disable for now
        //continue;

        // add capture point
        uint32 capturePointEntry = 0;

        //192028 192029
        //192030 192031
        //192032 192033

        //190475 190487 not sure
        //192626 192627
        //194959 194960

        switch(goData->id)
        {
            case 192028: capturePointEntry = 190475; break;
            case 192029: capturePointEntry = 190487; break;
            case 192030: capturePointEntry = 190475; break;
            case 192031: capturePointEntry = 190487; break;
            case 192032: capturePointEntry = 190475; break;
            case 192033: capturePointEntry = 190487; break;
        }
        if(capturePointEntry)
        {
            uint32 engGuid = 0;

            QueryResult *result = WorldDatabase.PQuery("SELECT `guid` FROM `creature`"
                " WHERE `creature`.`map`=571"
                " AND `creature`.`id` IN (%u, %u);", CRE_ENG_A, CRE_ENG_H);

            if(!result)
            {
                sLog.outError("Cannot find siege workshop master in creature!"); 
                continue;
            }

            float minDist = 100;
            do
            {
                Field *fields = result->Fetch();
                uint32 guid = fields[0].GetUInt32();
                const CreatureData *creData = objmgr.GetCreatureData(guid);
                if(!creData)
                    continue;

                float dist = (abs(creData->posX - x) + abs(creData->posY - y));
                if(minDist > dist)
                {
                    minDist = dist;
                    engGuid = guid;
                }
            }while(result->NextRow());
            delete result;

            if(!engGuid)
            {
                sLog.outError("Cannot find nearby siege workshop master!");
                continue;
            }

            SiegeWorkshop *workshop = new SiegeWorkshop(this, m_buildingStates[guid]);
            if(!workshop->SetCapturePointData(capturePointEntry, goData->mapid, goData->posX, goData->posY, goData->posZ))
            {
                delete workshop;
                sLog.outError("Cannot add capture point!");
                continue;
            }
            const CreatureData *creData = objmgr.GetCreatureData(engGuid);
            if(!creData)
                continue;

            workshop->m_engEntry = const_cast<uint32*>(&creData->id);
            const_cast<CreatureData*>(creData)->displayid = 0;
            workshop->m_workshopGuid = guid;
            workshop->m_engGuid = engGuid;
            //workshop->AddGO(0, guid, goData->id);
            //workshop->AddCre(0, engGuid, creData->id);
            //sLog.outDebug("Demolisher Engineerer lowguid %u is linked to workshop lowguid %u.", engGuid, guid);
            AddCapturePoint(workshop);
            m_buildingStates[guid]->type = BUILDING_WORKSHOP;
            workshop->SetStateByBuildingState();
        }
    }while(result->NextRow());
    delete result;

    //for(AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end(); ++itr)
    //    sLog.outError("not assigned %u %f %f", (*itr)->id, (*itr)->x, (*itr)->y);

    //gameeventmgr.StartInternalEvent(GameEventWintergraspDefender[m_defender]);

    //Titan Relic eventid = 19982
    objmgr.AddGOData(192829, 571, 5440, 2840.8, 420.43, 0);

    LoadTeamPair(m_goDisplayPair, GODisplayPair);
    LoadTeamPair(m_creEntryPair, CreatureEntryPair);

    m_wartime = false;
    m_timer = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_START_TIME) * MINUTE * IN_MILISECONDS;

    RegisterZone(ZONE_WINTERGRASP);
    return true;
}

void OPvPWintergrasp::ProcessEvent(GameObject *obj, uint32 eventId)
{
    if(eventId == 19982)
    {
        if(m_wartime)
            ChangeDefender();
    }
    else if(obj->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        BuildingStateMap::const_iterator itr = m_buildingStates.find(obj->GetDBTableGUIDLow());
        if(itr != m_buildingStates.end())
        {
            if(obj->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED))
                itr->second->damageState = DAMAGE_DAMAGED;
            else
                itr->second->damageState = DAMAGE_DESTROYED;
            BroadcastStateChange(itr->second);

            if(itr->second->type == BUILDING_WORKSHOP)
                if(SiegeWorkshop *workshop = GetWorkshop(obj->GetDBTableGUIDLow()))
                    workshop->DespawnAllVehicles();
        }
    }
}

uint32 OPvPWintergrasp::GetCreatureEntry(uint32 guidlow, const CreatureData *data)
{
    if(m_defender == TEAM_ALLIANCE)
    {
        TeamPairMap::const_iterator itr = m_creEntryPair.find(data->id);
        if(itr != m_creEntryPair.end())
        {
            const_cast<CreatureData*>(data)->displayid = 0;
            return itr->second;
        }
    }
    return data->id;
}

void OPvPWintergrasp::OnCreatureCreate(Creature *creature, bool add)
{
    uint32 entry = creature->GetEntry();
    if(creature->isVehicle()) // vehicles
    {
        TeamId team;
        if(creature->getFaction() == WintergraspFaction[TEAM_ALLIANCE])
            team = TEAM_ALLIANCE;
        else if(creature->getFaction() == WintergraspFaction[TEAM_HORDE])
            team = TEAM_HORDE;
        else
            return;

        switch(entry)
        {
            case 27881:
            case 28094:
            case 28312:
            case 32627:
                if(uint32 engLowguid = GUID_LOPART(creature->GetOwnerGUID()))
                {
                    if(SiegeWorkshop *workshop = GetWorkshopByEngGuid(engLowguid))
                    {
                        if(add)
                        {
                            if(m_wartime && workshop->m_vehicles.size() < MAX_VEHICLE_PER_WORKSHOP)
                                workshop->m_vehicles.insert((Vehicle*)creature);
                            else
                            {
                                creature->setDeathState(DEAD);
                                creature->SetRespawnTime(DAY);
                                return;
                            }                            
                        }
                        // TODO: now you have to wait until the corpse of vehicle disappear to build a new one
                        else if(!workshop->m_vehicles.erase((Vehicle*)creature))
                            sLog.outError("OPvPWintergrasp::OnCreatureCreate: a vehicle is removed but it does not have record in workshop!");
                    }
                }
            //case 28366: tower
                if(add)
                {
                    m_vehicles[team].insert((Vehicle*)creature);
                    if(m_tenacityStack > 0)
                    {
                        if(team == TEAM_ALLIANCE)
                            creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, m_tenacityStack);
                    }
                    else if(m_tenacityStack < 0)
                    {
                        if(team == TEAM_HORDE)
                            creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, -m_tenacityStack);
                    }
                }
                else
                    m_vehicles[team].erase((Vehicle*)creature);                
                break;
        }
    }
    else if(m_creEntryPair.find(entry) != m_creEntryPair.end()) // guards and npc
    {
        if(add) m_creatures.insert(creature);
        else m_creatures.erase(creature);
    }
    else if(entry == CRE_ENG_A || entry == CRE_ENG_H) // demolisher engineers
    {
        for(OutdoorPvP::OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
            if(SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
                if(workshop->m_engGuid == creature->GetDBTableGUIDLow())
                {
                    workshop->m_engineer = add ? creature : NULL;
                    break;
                }
    }
}

void OPvPWintergrasp::OnGameObjectCreate(GameObject *go, bool add)
{
    OutdoorPvP::OnGameObjectCreate(go, add);

    if(UpdateGameObjectInfo(go))
    {
        if(add) m_gobjects.insert(go);
        else m_gobjects.erase(go);
    }
    //do we need to store building?
    else if(go->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        BuildingStateMap::const_iterator itr = m_buildingStates.find(go->GetDBTableGUIDLow());
        if(itr != m_buildingStates.end())
        {
            itr->second->building = add ? go : NULL;
            if(!add || itr->second->damageState == DAMAGE_INTACT && !itr->second->health)
                itr->second->health = go->GetGOValue()->building.health;
            else
            {
                go->GetGOValue()->building.health = itr->second->health;
                if(itr->second->damageState == DAMAGE_DAMAGED)
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                else if(itr->second->damageState == DAMAGE_DESTROYED)
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
            }
        }
    }
}

void OPvPWintergrasp::UpdateAllWorldObject()
{
    // update cre and go factions
    for(GameObjectSet::iterator itr = m_gobjects.begin(); itr != m_gobjects.end(); ++itr)
        UpdateGameObjectInfo(*itr);
    for(CreatureSet::iterator itr = m_creatures.begin(); itr != m_creatures.end(); ++itr)
        UpdateCreatureInfo(*itr);

    // rebuild and update building states
    RebuildAllBuildings();

    // update capture points
    for(OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
            workshop->SetStateByBuildingState();

    SendInitWorldStatesTo();
}

void OPvPWintergrasp::RebuildAllBuildings()
{
    for(BuildingStateMap::iterator itr = m_buildingStates.begin(); itr != m_buildingStates.end(); ++itr)
    {
        if(itr->second->building)
        {
            itr->second->building->Rebuild();
            itr->second->health = itr->second->building->GetGOValue()->building.health;
        }
        else
            itr->second->health = 0;

        itr->second->damageState = DAMAGE_INTACT;
        itr->second->team = m_defender == TEAM_ALLIANCE ? OTHER_TEAM(itr->second->defaultTeam) : itr->second->defaultTeam;
    }
}

void OPvPWintergrasp::SendInitWorldStatesTo(Player *player)
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, (4+4+4+2+(m_buildingStates.size()*8)));
    data << uint32(571);
    data << uint32(ZONE_WINTERGRASP);
    data << uint32(0);
    data << uint16(m_buildingStates.size());
    for(BuildingStateMap::iterator itr = m_buildingStates.begin(); itr != m_buildingStates.end(); ++itr)
        itr->second->FillData(data);
    if(player)
        player->GetSession()->SendPacket(&data);
    else
        BroadcastPacket(data);
}

void OPvPWintergrasp::BroadcastStateChange(BuildingState *state)
{
    for(uint32 team = 0; team < 2; ++team)
        for(PlayerSet::iterator p_itr = m_players[team].begin(); p_itr != m_players[team].end(); ++p_itr)
            state->SendUpdate(*p_itr);
}

bool OPvPWintergrasp::UpdateCreatureInfo(Creature *creature)
{
    TeamPairMap::const_iterator itr = m_creEntryPair.find(creature->GetCreatureData()->id);
    if(itr != m_creEntryPair.end())
    {
        uint32 entry = m_defender == TEAM_ALLIANCE ? itr->second : itr->first;
        if(entry != creature->GetEntry())
        {
            creature->SetOriginalEntry(entry);
            creature->Respawn(true);
        }
        else if(!creature->isAlive())
            creature->Respawn(true);
    }

    return false;
}

bool OPvPWintergrasp::UpdateGameObjectInfo(GameObject *go)
{
    switch(go->GetEntry())
    {
        // Defender's Portal
        case 190763:
            go->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[m_defender]);
            return true;
    }

    // Note: this is only for test, still need db support
    TeamPairMap::const_iterator itr = m_goDisplayPair.find(go->GetGOInfo()->displayId);
    if(itr != m_goDisplayPair.end())
    {
        go->SetUInt32Value(GAMEOBJECT_DISPLAYID, m_defender == TEAM_ALLIANCE ?
            itr->second : itr->first);
        return true;
    }

    return false;
}

void OPvPWintergrasp::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    if(m_wartime && !plr->HasAura(SPELL_RECRUIT) && !plr->HasAura(SPELL_CORPORAL)
        && !plr->HasAura(SPELL_LIEUTENANT))
        plr->CastSpell(plr, SPELL_RECRUIT, true);

    SendInitWorldStatesTo(plr);

    OutdoorPvP::HandlePlayerEnterZone(plr, zone);
    UpdateTenacityStack();
}

void OPvPWintergrasp::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    if(!plr->GetSession()->PlayerLogout())
    {
        if(plr->m_Vehicle) // dismiss in change zone case
            plr->m_Vehicle->Dismiss();
        REMOVE_RANK_AURAS(plr);
    }
    plr->RemoveAura(SPELL_TENACITY);
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
    UpdateTenacityStack();
}

void OPvPWintergrasp::HandleKill(Player *killer, Unit *victim)
{
    if(victim->GetTypeId() == TYPEID_PLAYER)
    {
        // We handle promotion here because player should not get promotion if he has buff but do the kill outside the zone
        if(victim->getLevel() >= 70)
        {
            Aura *aur;
            if(aur = killer->GetAura(SPELL_RECRUIT))
            {
                if(aur->GetStackAmount() >= 5)
                {
                    killer->RemoveAura(SPELL_RECRUIT);
                    killer->CastSpell(killer, SPELL_CORPORAL, true);
                }
                else
                    killer->CastSpell(killer, SPELL_RECRUIT, true);
            }
            else if(aur = killer->GetAura(SPELL_CORPORAL))
            {
                if(aur->GetStackAmount() >= 5)
                {
                    killer->RemoveAura(SPELL_CORPORAL);
                    killer->CastSpell(killer, SPELL_LIEUTENANT, true);
                }
                else
                    killer->CastSpell(killer, SPELL_CORPORAL, true);
            }
            else if(killer->HasAura(SPELL_LIEUTENANT))
                killer->CastSpell(killer, SPELL_LIEUTENANT, true);
        }
    }
}

void OPvPWintergrasp::UpdateTenacityStack()
{
    uint32 allianceNum = m_players[TEAM_ALLIANCE].size();
    uint32 hordeNum = m_players[TEAM_HORDE].size();

    int32 newStack = 0;
    if(allianceNum && hordeNum)
    {
        if(allianceNum > hordeNum)
            newStack = allianceNum / hordeNum - 1;
        else if(allianceNum < hordeNum)
            newStack = 1 - int32(hordeNum / allianceNum);
    }

    if(newStack == m_tenacityStack)
        return;

    // Remove old buff
    if(m_tenacityStack > 0)
    {
        if(newStack <= 0)
        {
            TeamCastSpell(TEAM_ALLIANCE, -SPELL_TENACITY);
            VehicleCastSpell(TEAM_ALLIANCE, -SPELL_TENACITY_VEHICLE);
        }
    }
    else if(m_tenacityStack < 0)
    {
        if(newStack >= 0)
        {
            TeamCastSpell(TEAM_HORDE, -SPELL_TENACITY);
            VehicleCastSpell(TEAM_HORDE, -SPELL_TENACITY_VEHICLE);
        }
    }
    m_tenacityStack = newStack;

    // Apply new buff
    if(newStack)
    {
        TeamId team = newStack > 0 ? TEAM_HORDE : TEAM_ALLIANCE;
        if(newStack < 0) newStack = -newStack;
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            (*itr)->SetAuraStack(SPELL_TENACITY, *itr, newStack);
        for(VehicleSet::iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            (*itr)->SetAuraStack(SPELL_TENACITY_VEHICLE, *itr, newStack);
    }
}

void OPvPWintergrasp::VehicleCastSpell(TeamId team, int32 spellId)
{
    if(spellId > 0)
        for(VehicleSet::iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            (*itr)->CastSpell(*itr, (uint32)spellId, true);
    else
        for(VehicleSet::iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            (*itr)->RemoveAura((uint32)-spellId); // by stack?
}

bool OPvPWintergrasp::Update(uint32 diff)
{
    if(m_timer > diff)
    {
        m_timer -= diff;

        if(m_wartime)
            OutdoorPvP::Update(diff); // update capture points
    }
    else
    {
        if(m_wartime)
        {
            if(m_defender == TEAM_ALLIANCE)
                sWorld.SendZoneText(ZONE_WINTERGRASP, "Alliance has successfully defended the fortress!");
            else
                sWorld.SendZoneText(ZONE_WINTERGRASP, "Horde has successfully defended the fortress!");
            GiveReward();
            EndBattle();
        }
        else
        {
            sWorld.SendZoneText(ZONE_WINTERGRASP, "Battle begins!");
            UpdateAllWorldObject();
            StartBattle();
        }
    }
    return false;
}

void OPvPWintergrasp::ChangeDefender()
{
    m_defender = OTHER_TEAM(m_defender);
    if(m_defender == TEAM_ALLIANCE)
        sWorld.SendZoneText(ZONE_WINTERGRASP, "Alliance has taken over the fortress!");
    else
        sWorld.SendZoneText(ZONE_WINTERGRASP, "Horde has taken over the fortress!");
    UpdateAllWorldObject();

    GiveReward();
    EndBattle();
}

void OPvPWintergrasp::GiveReward()
{
    for(uint32 team = 0; team < 2; ++team)
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if((*itr)->HasAura(SPELL_LIEUTENANT))
                (*itr)->CastSpell(*itr, team == m_defender ? SPELL_VICTORY_REWARD : SPELL_DEFEAT_REWARD, true);
}

void OPvPWintergrasp::StartBattle()
{
    m_wartime = true;
    m_timer = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_BATTLE_TIME) * MINUTE * IN_MILISECONDS;

    for(uint32 team = 0; team < 2; ++team)
    {
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        {
            REMOVE_RANK_AURAS(*itr);
            (*itr)->CastSpell(*itr, SPELL_RECRUIT, true);
        }
    }
}

void OPvPWintergrasp::EndBattle()
{
    m_wartime = false;
    m_timer = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_INTERVAL) * MINUTE * IN_MILISECONDS;

    for(uint32 team = 0; team < 2; ++team)
    {
        VehicleCastSpell(TeamId(team), SPELL_SHUTDOWN_VEHICLE);

        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        {
            REMOVE_RANK_AURAS(*itr);
        }
    }
}

void OPvPWintergrasp::SetData(uint32 id, uint32 value)
{
    if(id == DATA_ENGINEER_DIE)
        if(SiegeWorkshop *workshop = GetWorkshopByEngGuid(value))
            workshop->DespawnAllVehicles();
}

uint32 OPvPWintergrasp::GetData(uint32 id)
{
    // if can build more vehicles
    if(SiegeWorkshop *workshop = GetWorkshopByEngGuid(id))
        return m_wartime && workshop->m_vehicles.size() < MAX_VEHICLE_PER_WORKSHOP ? 1 : 0;

    return 0;
}

SiegeWorkshop *OPvPWintergrasp::GetWorkshop(uint32 lowguid) const
{
    if(OPvPCapturePoint *cp = GetCapturePoint(lowguid))
        return dynamic_cast<SiegeWorkshop*>(cp);
    return NULL;
}

SiegeWorkshop *OPvPWintergrasp::GetWorkshopByEngGuid(uint32 lowguid) const
{
    for(OutdoorPvP::OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
            if(workshop->m_engGuid == lowguid)
                return workshop;
    return NULL;  
}

SiegeWorkshop *OPvPWintergrasp::GetWorkshopByGOGuid(uint32 lowguid) const
{
    for(OutdoorPvP::OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if(SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
            if(workshop->m_workshopGuid == lowguid)
                return workshop;
    return NULL;  
}
