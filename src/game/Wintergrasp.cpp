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
    //{30870, 30869}, // Flight Masters
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

#define REMOVE_WARTIME_AURAS(p) (p)->RemoveAura(SPELL_RECRUIT);\
    (p)->RemoveAura(SPELL_CORPORAL);(p)->RemoveAura(SPELL_LIEUTENANT)
#define REMOVE_TENACITY_AURA(p) CastTenacity(p, 0)

typedef std::list<const AreaPOIEntry *> AreaPOIList;

bool OPvPWintergrasp::SetupOutdoorPvP()
{
    if(!sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
        return false;

    m_defender = TeamId(rand()%2);
    m_changeDefender = false;

    m_workshopCount[TEAM_ALLIANCE] = 0;
    m_workshopCount[TEAM_HORDE] = 0;
    m_towerCount = 3;

    // Select POI
    AreaPOIList areaPOIs;
    float minX = 9999, minY = 9999, maxX = -9999, maxY = -9999;
    for (uint32 i = 0; i < sAreaPOIStore.GetNumRows(); ++i)
    {
        const AreaPOIEntry * poiInfo = sAreaPOIStore.LookupEntry(i);
        if (poiInfo && poiInfo->zoneId == ZONE_WINTERGRASP)
        {
            areaPOIs.push_back(poiInfo);
            if (minX > poiInfo->x) minX = poiInfo->x;
            if (minY > poiInfo->y) minY = poiInfo->y;
            if (maxX < poiInfo->x) maxX = poiInfo->x;
            if (maxY < poiInfo->y) maxY = poiInfo->y;
        }
    }
    minX -= 20; minY -= 20; maxX += 20; maxY += 20;

    QueryResult *result = WorldDatabase.PQuery("SELECT guid FROM gameobject,gameobject_template"
        " WHERE gameobject.map=571"
        " AND gameobject.position_x>%f AND gameobject.position_y>%f"
        " AND gameobject.position_x<%f AND gameobject.position_y<%f"
        " AND gameobject_template.type=33"
        " AND gameobject.id=gameobject_template.entry",
        minX, minY, maxX, maxY);
    if (!result)
        return false;

    do
    {
        Field *fields = result->Fetch();

        uint32 guid = fields[0].GetUInt32();
        GameObjectData const * goData = objmgr.GetGOData(guid);
        if (!goData) // this should not happen
            continue;

        float x = goData->posX, y = goData->posY;
        float minDist = 100;
        AreaPOIList::iterator poi = areaPOIs.end();
        for (AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end(); ++itr)
        {
            if (!(*itr)->icon[1]) // note: may for other use
                continue;

            float dist = (abs((*itr)->x - x) + abs((*itr)->y - y));
            if (minDist > dist)
            {
                minDist = dist;
                poi = itr;
            }
        }

        if (poi == areaPOIs.end())
            continue;

        // add building to the list
        TeamId teamId = x > POS_X_CENTER ? m_defender : OTHER_TEAM(m_defender);
        m_buildingStates[guid] = new BuildingState((*poi)->worldState, teamId, m_defender != TEAM_ALLIANCE);
        if ((*poi)->id == 2246)
        {
            m_gate = m_buildingStates[guid];
        }
        areaPOIs.erase(poi);

        // add capture point
        uint32 capturePointEntry = 0;

        switch(goData->id)
        {
            case 192028: capturePointEntry = 190475; break;
            case 192029: capturePointEntry = 190487; break; // not sure
            case 192030: capturePointEntry = 190475; break;
            case 192031: capturePointEntry = 190487; break;
            case 192032: capturePointEntry = 190475; break;
            case 192033: capturePointEntry = 190487; break;
        }
        if (capturePointEntry)
        {
            uint32 engGuid = 0;

            QueryResult *result = WorldDatabase.PQuery("SELECT guid FROM creature"
                " WHERE creature.map=571"
                " AND creature.id IN (%u, %u);", CRE_ENG_A, CRE_ENG_H);

            if (!result)
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
                if (!creData)
                    continue;

                float dist = (abs(creData->posX - x) + abs(creData->posY - y));
                if (minDist > dist)
                {
                    minDist = dist;
                    engGuid = guid;
                }
            }while(result->NextRow());
            delete result;

            if (!engGuid)
            {
                sLog.outError("Cannot find nearby siege workshop master!");
                continue;
            }

            SiegeWorkshop *workshop = new SiegeWorkshop(this, m_buildingStates[guid]);
            if (!workshop->SetCapturePointData(capturePointEntry, goData->mapid, goData->posX + 40 * cos(goData->orientation + M_PI / 2), goData->posY + 40 * sin(goData->orientation + M_PI / 2), goData->posZ))
            {
                delete workshop;
                sLog.outError("Cannot add capture point!");
                continue;
            }
            const CreatureData *creData = objmgr.GetCreatureData(engGuid);
            if (!creData)
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
            workshop->SetTeamByBuildingState();
        }
    }while(result->NextRow());
    delete result;

    if (!m_gate)
    {
        sLog.outError("Cannot find wintergrasp fortress gate!");
        return false;
    }

    // Load Graveyard
    GraveYardMap::const_iterator graveLow  = objmgr.mGraveYardMap.lower_bound(ZONE_WINTERGRASP);
    GraveYardMap::const_iterator graveUp   = objmgr.mGraveYardMap.upper_bound(ZONE_WINTERGRASP);
    for (AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end();)
    {
        if ((*itr)->icon[1] == 8)
        {
            // find or create grave yard
            const WorldSafeLocsEntry *loc = objmgr.GetClosestGraveYard((*itr)->x, (*itr)->y, (*itr)->z, (*itr)->mapId, 0);
            if (!loc)
            {
                ++itr;
                continue;
            }

            GraveYardMap::const_iterator graveItr;
            for (graveItr = graveLow; graveItr != graveUp; ++graveItr)
                if (graveItr->second.safeLocId == loc->ID)
                    break;
            if (graveItr == graveUp)
            {
                GraveYardData graveData;
                graveData.safeLocId = loc->ID;
                graveData.team = 0;
                graveItr = objmgr.mGraveYardMap.insert(std::make_pair(ZONE_WINTERGRASP, graveData));
            }

            for (BuildingStateMap::iterator stateItr = m_buildingStates.begin(); stateItr != m_buildingStates.end(); ++stateItr)
            {
                if (stateItr->second->worldState == (*itr)->worldState)
                {
                    stateItr->second->graveTeam = const_cast<uint32*>(&graveItr->second.team);
                    break;
                }
            }
            areaPOIs.erase(itr++);
        }
        else
            ++itr;
    }

    //for (AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end(); ++itr)
    //    sLog.outError("not assigned %u %f %f", (*itr)->id, (*itr)->x, (*itr)->y);

    //gameeventmgr.StartInternalEvent(GameEventWintergraspDefender[m_defender]);

    //Titan Relic eventid = 19982
    objmgr.AddGOData(192829, 571, 5440, 2840.8, 420.43 + 10, 0);

    LoadTeamPair(m_goDisplayPair, GODisplayPair);
    LoadTeamPair(m_creEntryPair, CreatureEntryPair);

    m_wartime = false;
    m_timer = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_START_TIME) * MINUTE * IN_MILISECONDS;

    // Load custom rewards
    if (sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR))
        for (int i = 0; i < WG_REWARD_EVENT_MAX; ++i)
            m_customHonorReward[i] = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR_0 + i);

    RemoveOfflinePlayerWGAuras();

    RegisterZone(ZONE_WINTERGRASP);
    return true;
}

void OPvPWintergrasp::ProcessEvent(GameObject *obj, uint32 eventId)
{
    if (eventId == 19982)
    {
        if (m_wartime && m_gate && m_gate->damageState == DAMAGE_DESTROYED)
        {
            m_changeDefender = true;
            m_timer = 0;
        }
    }
    else if (obj->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        BuildingStateMap::const_iterator itr = m_buildingStates.find(obj->GetDBTableGUIDLow());
        if (itr != m_buildingStates.end())
        {
            BuildingState *state = itr->second;
            if (eventId == obj->GetGOInfo()->building.damagedEvent)
            {
                state->damageState = DAMAGE_DAMAGED;

                if (state->type == BUILDING_TOWER)
                {
                    if (sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR))
                    {
                        for (PlayerSet::const_iterator itr = m_players[m_defender].begin(); itr != m_players[m_defender].end(); ++itr)
                            if ((*itr)->HasAura(SPELL_LIEUTENANT) && ((*itr)->getLevel() > 69))
                               (*itr)->ModifyHonorPoints(m_customHonorReward[DAMAGED_TOWER]);
                    }
                    else
                        LieutenantCastSpell(m_defender, SPELL_DAMAGED_TOWER);
                }
            }
            else if (eventId == obj->GetGOInfo()->building.destroyedEvent)
            {
                state->damageState = DAMAGE_DESTROYED;

                if (state->type == BUILDING_WORKSHOP)
                {
                    //if (SiegeWorkshop *workshop = GetWorkshop(obj->GetDBTableGUIDLow()))
                    //    workshop->DespawnAllVehicles();
                    ModifyWorkshopCount(state->GetTeam(), false);
                }
                else if (state->type == BUILDING_TOWER)
                {
                    if (!m_towerCount)
                        sLog.outError("OPvPWintergrasp::ProcessEvent: negative tower count!");
                    else
                    {
                        --m_towerCount;
                        if (sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR))
                        {
                            for (PlayerSet::const_iterator itr = m_players[m_defender].begin(); itr != m_players[m_defender].end(); ++itr)
                                if ((*itr)->HasAura(SPELL_LIEUTENANT) && ((*itr)->getLevel() > 69))
                                    (*itr)->ModifyHonorPoints(m_customHonorReward[DESTROYED_TOWER]);
                        }
                        else
                            LieutenantCastSpell(m_defender, SPELL_DESTROYED_TOWER);
                    }
                }
            }
            BroadcastStateChange(state);
        }
    }
}

void OPvPWintergrasp::RemoveOfflinePlayerWGAuras()
{
    // if server crashed while in battle there could be players with rank or tenacity
    CharacterDatabase.PExecute("DELETE FROM character_aura WHERE spell IN (%u,%u,%u, %u)",
        SPELL_RECRUIT, SPELL_CORPORAL, SPELL_LIEUTENANT, SPELL_TENACITY);
}

void OPvPWintergrasp::ModifyWorkshopCount(TeamId team, bool add)
{
    if (team == TEAM_NEUTRAL)
        return;

    if (add)
        ++m_workshopCount[team];
    else if (m_workshopCount[team])
        --m_workshopCount[team];
    else
        sLog.outError("OPvPWintergrasp::ModifyWorkshopCount: negative workshop count!");

    SendUpdateWorldState(MaxVehNumWorldState[team], m_workshopCount[team] * MAX_VEHICLE_PER_WORKSHOP);
}

uint32 OPvPWintergrasp::GetCreatureEntry(uint32 guidlow, const CreatureData *data)
{
    if (m_defender == TEAM_ALLIANCE)
    {
        TeamPairMap::const_iterator itr = m_creEntryPair.find(data->id);
        if (itr != m_creEntryPair.end())
        {
            const_cast<CreatureData*>(data)->displayid = 0;
            return itr->second;
        }
    }
    return data->id;
}

WintergraspCreType OPvPWintergrasp::GetCreatureType(uint32 entry) const
{
    switch(entry)
    {
        case 27881:
        case 28094:
        case 28312:
        case 32627:
            return CREATURE_SIEGE_VEHICLE;
        case 28366:
            return CREATURE_TURRET;
        case CRE_ENG_A:
        case CRE_ENG_H:
            return CREATURE_ENGINEER;
        case 30739:
        case 30740:
        case 32307:
        case 32308:
            return CREATURE_GUARD;
        default:
            return CREATURE_OTHER;
    }
}

void OPvPWintergrasp::OnCreatureCreate(Creature *creature, bool add)
{
    uint32 entry = creature->GetEntry();
    switch(GetCreatureType(entry))
    {
        case CREATURE_SIEGE_VEHICLE:
        {
            if (!creature->isSummon())
                return;

            TeamId team;
            if (add)
            {
                if (creature->getFaction() == WintergraspFaction[TEAM_ALLIANCE])
                    team = TEAM_ALLIANCE;
                else if (creature->getFaction() == WintergraspFaction[TEAM_HORDE])
                    team = TEAM_HORDE;
                else
                    return;

                if (uint32 engLowguid = GUID_LOPART(((TempSummon*)creature)->GetSummonerGUID()))
                {
                    if (SiegeWorkshop *workshop = GetWorkshopByEngGuid(engLowguid))
                    {
                        if (CanBuildVehicle(workshop))
                        {
                            m_vehicles[team].insert(creature);
                            //workshop->m_vehicles.insert(creature);
                        }
                        else
                        {
                            creature->setDeathState(DEAD);
                            creature->SetRespawnTime(DAY);
                            return;
                        }
                    }
                }

                if (m_tenacityStack > 0)
                {
                    if (team == TEAM_ALLIANCE)
                        creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, m_tenacityStack);
                }
                else if (m_tenacityStack < 0)
                {
                    if (team == TEAM_HORDE)
                        creature->SetAuraStack(SPELL_TENACITY_VEHICLE, creature, -m_tenacityStack);
                }
            }
            else // the faction may be changed in uncharm
            {
                // TODO: now you have to wait until the corpse of vehicle disappear to build a new one
                if (m_vehicles[TEAM_ALLIANCE].erase(creature))
                    team = TEAM_ALLIANCE;
                else if (m_vehicles[TEAM_HORDE].erase(creature))
                    team = TEAM_HORDE;
                else
                    return;
            }
            SendUpdateWorldState(VehNumWorldState[team], m_vehicles[team].size());
            break;
        }
        case CREATURE_ENGINEER:
            for (OutdoorPvP::OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
            {
                if (SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
                    if (workshop->m_engGuid == creature->GetDBTableGUIDLow())
                    {
                        workshop->m_engineer = add ? creature : NULL;
                        break;
                    }
            }
            break;
        default:
            if (m_creEntryPair.find(entry) != m_creEntryPair.end()) // guards and npc
            {
                if (add) m_creatures.insert(creature);
                else m_creatures.erase(creature);
            }
            break;
    }
}

void OPvPWintergrasp::OnGameObjectCreate(GameObject *go, bool add)
{
    OutdoorPvP::OnGameObjectCreate(go, add);

    if (UpdateGameObjectInfo(go))
    {
        if (add) m_gobjects.insert(go);
        else m_gobjects.erase(go);
    }
    //do we need to store building?
    else if (go->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        BuildingStateMap::const_iterator itr = m_buildingStates.find(go->GetDBTableGUIDLow());
        if (itr != m_buildingStates.end())
        {
            itr->second->building = add ? go : NULL;
            if (!add || itr->second->damageState == DAMAGE_INTACT && !itr->second->health)
                itr->second->health = go->GetGOValue()->building.health;
            else
            {
                go->GetGOValue()->building.health = itr->second->health;
                if (itr->second->damageState == DAMAGE_DAMAGED)
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                else if (itr->second->damageState == DAMAGE_DESTROYED)
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
            }
        }
    }
}

void OPvPWintergrasp::UpdateAllWorldObject()
{
    // update cre and go factions
    for (GameObjectSet::iterator itr = m_gobjects.begin(); itr != m_gobjects.end(); ++itr)
        UpdateGameObjectInfo(*itr);
    for (CreatureSet::iterator itr = m_creatures.begin(); itr != m_creatures.end(); ++itr)
        UpdateCreatureInfo(*itr);

    // rebuild and update building states
    RebuildAllBuildings();

    // update capture points
    for (OPvPCapturePointMap::iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
            workshop->SetTeamByBuildingState();
}

void OPvPWintergrasp::RebuildAllBuildings()
{
    for (BuildingStateMap::const_iterator itr = m_buildingStates.begin(); itr != m_buildingStates.end(); ++itr)
    {
        if (itr->second->building)
        {
            itr->second->building->Rebuild();
            itr->second->health = itr->second->building->GetGOValue()->building.health;
        }
        else
            itr->second->health = 0;

        if (itr->second->damageState == DAMAGE_DESTROYED)
        {
            if (itr->second->type == BUILDING_WORKSHOP)
                ModifyWorkshopCount(itr->second->GetTeam(), true);
        }

        itr->second->damageState = DAMAGE_INTACT;
        itr->second->SetTeam(m_defender == TEAM_ALLIANCE ? OTHER_TEAM(itr->second->defaultTeam) : itr->second->defaultTeam);
    }

    m_towerCount = 3;
}

void OPvPWintergrasp::SendInitWorldStatesTo(Player *player) const
{
    WorldPacket data(SMSG_INIT_WORLD_STATES, (4+4+4+2+(m_buildingStates.size()*8)));
    data << uint32(571);
    data << uint32(ZONE_WINTERGRASP);
    data << uint32(0);
    data << uint16(4+5+4+m_buildingStates.size());

    data << uint32(3803) << uint32(m_defender == TEAM_ALLIANCE ? 1 : 0);
    data << uint32(3802) << uint32(m_defender != TEAM_ALLIANCE ? 1 : 0);
    data << uint32(3801) << uint32(m_wartime ? 0 : 1);
    data << uint32(3710) << uint32(m_wartime ? 1 : 0);

    for (uint32 i = 0; i < 5; ++i)
        data << ClockWorldState[i] << m_clock[i];

    data << uint32(3490) << uint32(m_vehicles[TEAM_HORDE].size());
    data << uint32(3491) << m_workshopCount[TEAM_HORDE] * MAX_VEHICLE_PER_WORKSHOP;
    data << uint32(3680) << uint32(m_vehicles[TEAM_ALLIANCE].size());
    data << uint32(3681) << m_workshopCount[TEAM_ALLIANCE] * MAX_VEHICLE_PER_WORKSHOP;

    for (BuildingStateMap::const_iterator itr = m_buildingStates.begin(); itr != m_buildingStates.end(); ++itr)
        itr->second->FillData(data);

    if (player)
        player->GetSession()->SendPacket(&data);
    else
        BroadcastPacket(data);
}

void OPvPWintergrasp::BroadcastStateChange(BuildingState *state) const
{
    if (m_sendUpdate)
        for (uint32 team = 0; team < 2; ++team)
            for (PlayerSet::const_iterator p_itr = m_players[team].begin(); p_itr != m_players[team].end(); ++p_itr)
                state->SendUpdate(*p_itr);
}

bool OPvPWintergrasp::UpdateCreatureInfo(Creature *creature) const
{
    TeamPairMap::const_iterator itr = m_creEntryPair.find(creature->GetCreatureData()->id);
    if (itr != m_creEntryPair.end())
    {
        uint32 entry = m_defender == TEAM_ALLIANCE ? itr->second : itr->first;
        creature->SetOriginalEntry(entry);
        if (entry != creature->GetEntry() || !creature->isAlive())
            creature->Respawn(true);
    }

    return false;
}

bool OPvPWintergrasp::UpdateGameObjectInfo(GameObject *go) const
{
    switch(go->GetEntry())
    {
        // Defender's Portal
        case 190763:
            go->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[m_defender]);
            return true;
        // Titan relic
        case 192829:
            go->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[OTHER_TEAM(m_defender)]);
            return true;
    }

    // Note: this is only for test, still need db support
    TeamPairMap::const_iterator itr = m_goDisplayPair.find(go->GetGOInfo()->displayId);
    if (itr != m_goDisplayPair.end())
    {
        go->SetUInt32Value(GAMEOBJECT_DISPLAYID, m_defender == TEAM_ALLIANCE ?
            itr->second : itr->first);
        return true;
    }

    return false;
}

void OPvPWintergrasp::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    if (m_wartime && !plr->HasAura(SPELL_RECRUIT) && !plr->HasAura(SPELL_CORPORAL)
        && !plr->HasAura(SPELL_LIEUTENANT))
        plr->CastSpell(plr, SPELL_RECRUIT, true);

    SendInitWorldStatesTo(plr);
    OutdoorPvP::HandlePlayerEnterZone(plr, zone);
    UpdateTenacityStack();
}

void OPvPWintergrasp::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    if (!plr->GetSession()->PlayerLogout())
    {
        if (plr->GetVehicle()) // dismiss in change zone case
            plr->GetVehicle()->Dismiss();
        REMOVE_WARTIME_AURAS(plr);
    }
    REMOVE_TENACITY_AURA(plr);
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
    UpdateTenacityStack();
}

void OPvPWintergrasp::PromotePlayer(Player *killer) const
{
    Aura *aur;
    if (aur = killer->GetAura(SPELL_RECRUIT))
    {
        if (aur->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_RECRUIT);
            killer->CastSpell(killer, SPELL_CORPORAL, true);
        }
        else
            killer->CastSpell(killer, SPELL_RECRUIT, true);
    }
    else if (aur = killer->GetAura(SPELL_CORPORAL))
    {
        if (aur->GetStackAmount() >= 5)
        {
            killer->RemoveAura(SPELL_CORPORAL);
            killer->CastSpell(killer, SPELL_LIEUTENANT, true);
        }
        else
            killer->CastSpell(killer, SPELL_CORPORAL, true);
    }
    else if (killer->HasAura(SPELL_LIEUTENANT))
        killer->CastSpell(killer, SPELL_LIEUTENANT, true);
}

void OPvPWintergrasp::HandleKill(Player *killer, Unit *victim)
{
    bool ok = false;
    if (victim->GetTypeId() == TYPEID_PLAYER)
    {
        if (victim->getLevel() >= 70)
            ok = true;
    }
    else
    {
        switch(GetCreatureType(victim->GetEntry()))
        {
            case CREATURE_SIEGE_VEHICLE:
            case CREATURE_GUARD:
            case CREATURE_TURRET:
                ok = true;
                break;
        }
    }

    if (ok)
    {
        if (Group *pGroup = killer->GetGroup())
        {
            for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                if (itr->getSource()->IsAtGroupRewardDistance(killer) && itr->getSource()->getLevel() > 69)
                    PromotePlayer(itr->getSource());
        }
        else if (killer->getLevel() > 69)
            PromotePlayer(killer);
    }
}

// Cast or removes Tenacity. MaxHP Modified, HP keeps it's % ratio
void OPvPWintergrasp::CastTenacity(Unit *utr, int32 newStack)
{
    if (!utr)
        return;

    uint32 spellId = utr->GetTypeId() == TYPEID_PLAYER ? SPELL_TENACITY : SPELL_TENACITY_VEHICLE;
    float percent = (0.0f + utr->GetHealth()) / utr->GetMaxHealth();

    if (newStack)
        utr->SetAuraStack(spellId, utr, newStack);
    else
        utr->RemoveAura(spellId);
    utr->SetHealth(uint32(utr->GetMaxHealth()*percent));
}

// Recalculates Tenacity and applies it to Players / Vehicles
void OPvPWintergrasp::UpdateTenacityStack()
{
    if (!m_wartime)
        return;

    TeamId team = TEAM_NEUTRAL;
    uint32 allianceNum = m_players[TEAM_ALLIANCE].size();
    uint32 hordeNum = m_players[TEAM_HORDE].size();
    int32 newStack = 0;

    if (allianceNum && hordeNum)
    {
        if (allianceNum < hordeNum)
            newStack = (hordeNum / allianceNum - 1)*4; // positive, should cast on alliance
        else if (allianceNum > hordeNum)
            newStack = (1 - int32(allianceNum / hordeNum))*4; // negative, should cast on horde
    }

    if (newStack == m_tenacityStack)
        return;

    if (m_tenacityStack > 0 && newStack <= 0) // old buff was on alliance
        team = TEAM_ALLIANCE;
    else if (m_tenacityStack < 0 && newStack >= 0) // old buff was on horde
        team = TEAM_HORDE;

    m_tenacityStack = newStack;

    // Remove old buff
    if (team != TEAM_NEUTRAL)
    {
        for (PlayerSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if ((*itr)->getLevel() > 69)
                REMOVE_TENACITY_AURA((*itr));

        for (CreatureSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            REMOVE_TENACITY_AURA((*itr));
    }

    // Apply new buff
    if (newStack)
    {
        team = newStack > 0 ? TEAM_ALLIANCE : TEAM_HORDE;
        if (newStack < 0) newStack = -newStack;
        int32 auraStack = newStack > 20 ? 20 : newStack; // Dont let it be higher than 20

        for (PlayerSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            if ((*itr)->getLevel() > 69)
                CastTenacity((*itr), auraStack);

        for (CreatureSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            CastTenacity((*itr), auraStack);
    }
}

void OPvPWintergrasp::VehicleCastSpell(TeamId team, int32 spellId) const
{
    if (spellId > 0)
        for (CreatureSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            (*itr)->CastSpell(*itr, (uint32)spellId, true);
    else
        for (CreatureSet::const_iterator itr = m_vehicles[team].begin(); itr != m_vehicles[team].end(); ++itr)
            (*itr)->RemoveAura((uint32)-spellId); // by stack?
}

void OPvPWintergrasp::LieutenantCastSpell(TeamId team, int32 spellId) const
{
    for (PlayerSet::const_iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        if ((*itr)->HasAura(SPELL_LIEUTENANT) && ((*itr)->getLevel() > 69))
            (*itr)->CastSpell(*itr, (uint32)spellId, true);
}

void OPvPWintergrasp::UpdateClockDigit(uint32 &timer, uint32 digit, uint32 mod)
{
    uint32 value = timer%mod;
    timer /= mod;
    if (m_clock[digit] != value)
    {
        m_clock[digit] = value;
        SendUpdateWorldState(ClockWorldState[digit], value);
    }
}

void OPvPWintergrasp::UpdateClock()
{
    uint32 timer = m_timer / 1000;
    UpdateClockDigit(timer, 0, 10);
    UpdateClockDigit(timer, 1, 6);
    UpdateClockDigit(timer, 2, 10);
    UpdateClockDigit(timer, 3, 6);
    if (!m_wartime)
        UpdateClockDigit(timer, 4, 10);
}

bool OPvPWintergrasp::Update(uint32 diff)
{
    if(!sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
        return false;

    if (m_timer > diff)
    {
        m_timer -= diff;

        if (m_wartime)
            OutdoorPvP::Update(diff); // update capture points

        UpdateClock();
    }
    else
    {
        m_sendUpdate = false;

        if (m_wartime)
        {
            if (m_changeDefender)
            {
                m_changeDefender = false;
                m_defender = OTHER_TEAM(m_defender);
                if (m_defender == TEAM_ALLIANCE)
                    sWorld.SendZoneText(ZONE_WINTERGRASP, "Alliance has taken over the fortress!");
                else
                    sWorld.SendZoneText(ZONE_WINTERGRASP, "Horde has taken over the fortress!");
            }
            else
            {
                if (m_defender == TEAM_ALLIANCE)
                    sWorld.SendZoneText(ZONE_WINTERGRASP, "Alliance has successfully defended the fortress!");
                else
                    sWorld.SendZoneText(ZONE_WINTERGRASP, "Horde has successfully defended the fortress!");
            }

            EndBattle();
        }
        else
        {
            sWorld.SendZoneText(ZONE_WINTERGRASP, "Battle begins!");
            StartBattle();
        }

        UpdateAllWorldObject();
        UpdateClock();

        SendInitWorldStatesTo();
        m_sendUpdate = true;
    }

    return false;
}

void OPvPWintergrasp::StartBattle()
{
    m_wartime = true;
    m_timer = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_BATTLE_TIME) * MINUTE * IN_MILISECONDS;

    // Add recruit Aura, Add Tenacity
    TeamCastSpell(m_defender, SPELL_RECRUIT);
    TeamCastSpell(OTHER_TEAM(m_defender), SPELL_RECRUIT);
    UpdateTenacityStack();
}

void OPvPWintergrasp::EndBattle()
{
    m_wartime = false;
    m_timer = sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_INTERVAL) * MINUTE * IN_MILISECONDS;

    for (uint32 team = 0; team < 2; ++team)
    {
        // calculate rewards
        uint32 intactNum = 0;
        uint32 damagedNum = 0;
        for (OutdoorPvP::OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        {
            if (SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
                if (workshop->m_buildingState->GetTeam() == team)
                    if (workshop->m_buildingState->damageState == DAMAGE_DAMAGED)
                        ++damagedNum;
                    else if (workshop->m_buildingState->damageState == DAMAGE_INTACT)
                        ++intactNum;
        }

        // give rewards
        uint32 honor = ( team == m_defender ? m_customHonorReward[WIN_BATTLE] : m_customHonorReward[LOSE_BATTLE] );
        for (uint32 i = 0; i < intactNum; ++i)
            honor += m_customHonorReward[INTACT_BUILDING];
        for (uint32 i = 0; i < damagedNum; ++i)
            honor += m_customHonorReward[DAMAGED_BUILDING];

        for (PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
        {
            if ((*itr)->HasAura(SPELL_LIEUTENANT))
            {
                if (!sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR))
                {
                   (*itr)->CastSpell(*itr, team == m_defender ? SPELL_VICTORY_REWARD : SPELL_DEFEAT_REWARD, true);
                    for (uint32 i = 0; i < intactNum; ++i)
                        (*itr)->CastSpell(*itr, SPELL_INTACT_BUILDING, true);
                    for (uint32 i = 0; i < damagedNum; ++i)
                        (*itr)->CastSpell(*itr, SPELL_DAMAGED_BUILDING, true);
                }
                else if (sWorld.getConfig(CONFIG_OUTDOORPVP_WINTERGRASP_CUSTOM_HONOR))
                    (*itr)->ModifyHonorPoints(honor);
            }
            REMOVE_WARTIME_AURAS(*itr);
            REMOVE_TENACITY_AURA(*itr);
            (*itr)->CombatStop(true);
        }

        // destroyed all vehicles
        while(!m_vehicles[team].empty())
        {
            Creature *veh = *m_vehicles[team].begin();
            m_vehicles[team].erase(m_vehicles[team].begin());
            veh->CastSpell(veh, SPELL_SHUTDOWN_VEHICLE, true);
        }
    }

    //3.2.0: TeamCastSpell(OTHER_TEAM(m_defender), SPELL_TELEPORT_DALARAN);
    RemoveOfflinePlayerWGAuras();
}

void OPvPWintergrasp::SetData(uint32 id, uint32 value)
{
    //if (id == DATA_ENGINEER_DIE)
    //    if (SiegeWorkshop *workshop = GetWorkshopByEngGuid(value))
    //        workshop->DespawnAllVehicles();
}

bool OPvPWintergrasp::CanBuildVehicle(SiegeWorkshop *workshop) const
{
    TeamId team = workshop->m_buildingState->GetTeam();
    if (team == TEAM_NEUTRAL)
        return false;

    return m_wartime
        && workshop->m_buildingState->damageState != DAMAGE_DESTROYED
        && m_vehicles[team].size() < m_workshopCount[team] * MAX_VEHICLE_PER_WORKSHOP;
}

uint32 OPvPWintergrasp::GetData(uint32 id)
{
    // if can build more vehicles
    if (SiegeWorkshop *workshop = GetWorkshopByEngGuid(id))
        return CanBuildVehicle(workshop) ? 1 : 0;

    return 0;
}

SiegeWorkshop *OPvPWintergrasp::GetWorkshop(uint32 lowguid) const
{
    if (OPvPCapturePoint *cp = GetCapturePoint(lowguid))
        return dynamic_cast<SiegeWorkshop*>(cp);
    return NULL;
}

SiegeWorkshop *OPvPWintergrasp::GetWorkshopByEngGuid(uint32 lowguid) const
{
    for (OutdoorPvP::OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
            if (workshop->m_engGuid == lowguid)
                return workshop;
    return NULL;
}

SiegeWorkshop *OPvPWintergrasp::GetWorkshopByGOGuid(uint32 lowguid) const
{
    for (OutdoorPvP::OPvPCapturePointMap::const_iterator itr = m_capturePoints.begin(); itr != m_capturePoints.end(); ++itr)
        if (SiegeWorkshop *workshop = dynamic_cast<SiegeWorkshop*>(itr->second))
            if (workshop->m_workshopGuid == lowguid)
                return workshop;
    return NULL;
}

/*######
##SiegeWorkshop
######*/

SiegeWorkshop::SiegeWorkshop(OPvPWintergrasp *opvp, BuildingState *state)
: OPvPCapturePoint(opvp), m_buildingState(state), m_wintergrasp(opvp)
, m_engineer(NULL), m_engGuid(0)
{
}

void SiegeWorkshop::SetTeamByBuildingState()
{
    if (m_buildingState->GetTeam() == TEAM_ALLIANCE)
    {
        m_value = m_maxValue;
        m_State = OBJECTIVESTATE_ALLIANCE;
    }
    else if (m_buildingState->GetTeam() == TEAM_HORDE)
    {
        m_value = -m_maxValue;
        m_State = OBJECTIVESTATE_HORDE;
    }
    else
    {
        m_value = 0;
        m_State = OBJECTIVESTATE_NEUTRAL;
    }

    if (m_team != m_buildingState->GetTeam())
    {
        TeamId oldTeam = m_team;
        m_team = m_buildingState->GetTeam();
        ChangeTeam(oldTeam);
    }

    SendChangePhase();
}

void SiegeWorkshop::ChangeTeam(TeamId oldTeam)
{
    uint32 entry = 0;
    if (oldTeam != TEAM_NEUTRAL)
        m_wintergrasp->ModifyWorkshopCount(oldTeam, false);
    if (m_team != TEAM_NEUTRAL)
    {
        entry = m_team == TEAM_ALLIANCE ? CRE_ENG_A : CRE_ENG_H;
        m_wintergrasp->ModifyWorkshopCount(m_team, true);
    }

    GameObject::SetGoArtKit(CapturePointArtKit[m_team], m_capturePoint, m_capturePointGUID);

    m_buildingState->SetTeam(m_team);
    // TODO: this may be sent twice
    m_wintergrasp->BroadcastStateChange(m_buildingState);

    // does not work, entry may change
    /*Creature *creature = ObjectAccessor::GetObjectInWorld(m_Creatures[0], (Creature*)NULL);
    if (!creature)
    {
        sLog.outError("SiegeWorkshop::ChangeState cannot find creature " I64FMT " !", m_Creatures[0]);
        return;
    }*/

    if (entry)
    {
        *m_engEntry = entry;

        if (m_engineer)
        {
            m_engineer->SetOriginalEntry(entry);
            if (entry != m_engineer->GetEntry() || !m_engineer->isAlive())
            {
                m_engineer->Respawn(true);
                //DespawnAllVehicles();
            }
            m_engineer->SetVisibility(VISIBILITY_ON);
        }
    }
    else if (m_engineer)
        m_engineer->SetVisibility(VISIBILITY_OFF);

    sLog.outDebug("Wintergrasp workshop now belongs to %u.", (uint32)m_buildingState->GetTeam());
}
