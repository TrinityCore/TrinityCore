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

const TeamPair CreatureEntryPair[] =
{
    {30739, 30740},
    {30400, 30499},
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

bool OPvPWintergrasp::SetupOutdoorPvP()
{
    RegisterZone(ZONE_WINTERGRASP);

    for(uint32 i = 0; i < sAreaPOIStore.GetNumRows(); ++i)
    {
        const AreaPOIEntry * poiInfo = sAreaPOIStore.LookupEntry(i);
        if(poiInfo && poiInfo->zoneId == ZONE_WINTERGRASP)
            areaPOIs.push_back(poiInfo);
    }

    m_defender = TeamId(rand()%2);
    //m_defender = TEAM_ALLIANCE;
    //gameeventmgr.StartInternalEvent(GameEventWintergraspDefender[m_defender]);

    //Titan Relic eventid = 19982
    objmgr.AddGameObject(192829, 571, 5440, 2840.8, 420.43, 0);

    LoadTeamPair(m_goDisplayPair, GODisplayPair);
    LoadTeamPair(m_creEntryPair, CreatureEntryPair);

    return true;
}

void OPvPWintergrasp::ProcessEvent(WorldObject *obj, uint32 eventId)
{
    if(eventId == 19982)
        ChangeDefender();
}

void OPvPWintergrasp::ChangeDefender()
{
    m_defender = OTHER_TEAM(m_defender);
    if(m_defender == TEAM_ALLIANCE)
        sWorld.SendZoneText(ZONE_WINTERGRASP, "Alliance has taken over the fortress!");
    else
        sWorld.SendZoneText(ZONE_WINTERGRASP, "Horde has taken over the fortress!");
    UpdateAllWorldObject();
}

uint32 OPvPWintergrasp::GetCreatureEntry(uint32 guidlow, uint32 entry)
{
    if(m_defender == TEAM_ALLIANCE)
    {
        TeamPairMap::const_iterator itr = m_creEntryPair.find(entry);
        if(itr != m_creEntryPair.end())
            return itr->second;
    }
    return entry;
}

void OPvPWintergrasp::OnCreatureCreate(Creature *creature, bool add)
{
    if(m_creEntryPair.find(creature->GetEntry()) != m_creEntryPair.end())
    {
        if(add) m_creatures.insert(creature);
        else m_creatures.erase(creature);
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
}

void OPvPWintergrasp::UpdateAllWorldObject()
{
    for(GameObjectSet::iterator itr = m_gobjects.begin(); itr != m_gobjects.end(); ++itr)
        UpdateGameObjectInfo(*itr);
    for(CreatureSet::iterator itr = m_creatures.begin(); itr != m_creatures.end(); ++itr)
        UpdateCreatureInfo(*itr);
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
            creature->setDeathState(DEAD);
            creature->Respawn();
        }
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
    if(!plr->HasAura(SPELL_RECRUIT) && !plr->HasAura(SPELL_CORPORAL)
        && !plr->HasAura(SPELL_LIEUTENANT))
        plr->CastSpell(plr, SPELL_RECRUIT, true);

    for(AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end(); ++itr)
    {
        TeamId team = ((*itr)->x > POS_X_CENTER ? m_defender : OTHER_TEAM(m_defender));
        plr->SendUpdateWorldState((*itr)->worldState, AreaPOIIconId[team][DAMAGE_INTACT]);
    }

    OutdoorPvP::HandlePlayerEnterZone(plr, zone);
    UpdateTenacityStack();
}

void OPvPWintergrasp::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    if(!plr->GetSession()->PlayerLogout() && plr->m_Vehicle) // dismiss in change zone case
        plr->m_Vehicle->Dismiss();
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
            if(Aura *aur = killer->GetAura(SPELL_RECRUIT))
            {
                if(aur->GetStackAmount() >= 5)
                {
                    killer->RemoveAura(SPELL_RECRUIT);
                    killer->CastSpell(killer, SPELL_CORPORAL, true);
                }
                else
                    killer->CastSpell(killer, SPELL_RECRUIT, true);
            }
            else if(Aura *aur = killer->GetAura(SPELL_CORPORAL))
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
            TeamCastSpell(TEAM_ALLIANCE, -SPELL_TENACITY);
    }
    else if(m_tenacityStack < 0)
    {
        if(newStack >= 0)
            TeamCastSpell(TEAM_HORDE, -SPELL_TENACITY);
    }
    m_tenacityStack = newStack;

    // Apply new buff
    if(newStack)
    {
        TeamId team = newStack > 0 ? TEAM_ALLIANCE : TEAM_HORDE;
        for(PlayerSet::iterator itr = m_players[team].begin(); itr != m_players[team].end(); ++itr)
            (*itr)->SetAuraStack(SPELL_TENACITY, *itr, newStack);
    }
}
