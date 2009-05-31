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
    objmgr.AddGameObject(192829, 571, 5444.6, 2840.8, 420.43, 0);


    return true;
}

uint32 OPvPWintergrasp::GetCreatureEntry(uint32 guidlow, uint32 entry)
{
    if(m_defender == TEAM_ALLIANCE)
    {
        switch(entry)
        {
            case 30739: return 30740;
            case 30740: return 30739;
            case 30400: return 30499;
            case 30499: return 30400;
        }
    }
    return entry;
}

/*
uint32 OPvPWintergrasp::GetGameObjectEntry(uint32 guidlow, uint32 entry)
{
    if(m_defender == TEAM_ALLIANCE)
    {
        GameObjectInfo const* goInfo = objmgr.GetGameObjectInfo(entry);
        if(!goInfo)
            return 0;
        switch(goInfo->displayId)
        {
            case 5651: return 192289;
            case 5652: return 192288;
            case 8256: return 192502;
            case 8257: return 192501;
        }
    }
    return entry;
}
*/

void OPvPWintergrasp::OnGameObjectCreate(GameObject *go, bool add)
{
    OutdoorPvP::OnGameObjectCreate(go, add);
    if(m_defender == TEAM_ALLIANCE)
    {
        switch(go->GetEntry())
        {
            case 190763: go->SetUInt32Value(GAMEOBJECT_FACTION, WintergraspFaction[m_defender]); break;
        }

        // Note: this is only for test, still need db support
        switch(go->GetGOInfo()->displayId)
        {
            case 5651: go->SetUInt32Value(GAMEOBJECT_DISPLAYID, 5652); break;
            case 5652: go->SetUInt32Value(GAMEOBJECT_DISPLAYID, 5651); break;
            case 8256: go->SetUInt32Value(GAMEOBJECT_DISPLAYID, 8257); break;
            case 8257: go->SetUInt32Value(GAMEOBJECT_DISPLAYID, 8256); break;
        }
    }
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
