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
    m_attacker = (m_defender == TEAM_ALLIANCE ? TEAM_HORDE : TEAM_ALLIANCE);

    return true;
}

void OPvPWintergrasp::HandlePlayerEnterZone(Player * plr, uint32 zone)
{
    if(!plr->HasAura(SPELL_RECRUIT) && !plr->HasAura(SPELL_CORPORAL)
        && !plr->HasAura(SPELL_LIEUTENANT))
        plr->CastSpell(plr, SPELL_RECRUIT, true);

    for(AreaPOIList::iterator itr = areaPOIs.begin(); itr != areaPOIs.end(); ++itr)
    {
        TeamId team = ((*itr)->x > POS_X_CENTER ? m_defender : m_attacker);
        plr->SendUpdateWorldState((*itr)->worldState, AreaPOIIconId[team][DAMAGE_INTACT]);
    }

    OutdoorPvP::HandlePlayerEnterZone(plr, zone);
}

void OPvPWintergrasp::HandlePlayerLeaveZone(Player * plr, uint32 zone)
{
    if(!plr->GetSession()->PlayerLogout() && plr->m_Vehicle) // dismiss in change zone case
        plr->m_Vehicle->Dismiss();
    OutdoorPvP::HandlePlayerLeaveZone(plr, zone);
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
