/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
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

#include "AggressorAI.h"
#include "SpellMgr.h"

int AggressorAI::Permissible(const Creature *creature)
{
    // have some hostile factions, it will be selected by IsHostileTo check at MoveInLineOfSight
    if( !creature->isCivilian() && !creature->IsNeutralToAll() )
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

void AggressorAI::UpdateAI(const uint32 /*diff*/)
{
    if(!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

int SpellAI::Permissible(const Creature *creature)
{
    return PERMIT_BASE_NO;
}

void SpellAI::InitializeAI()
{
    for(uint32 i = 0; i < CREATURE_MAX_SPELLS; ++i)
        if(me->m_spells[i] && GetSpellStore()->LookupEntry(me->m_spells[i]))
            spells.push_back(me->m_spells[i]);

    CreatureAI::InitializeAI();
}

void SpellAI::Reset()
{
    events.Reset();
}

void SpellAI::JustDied(Unit *killer)
{
    for(SpellVct::iterator i = spells.begin(); i != spells.end(); ++i)
        if(AISpellInfo[*i].condition == AICOND_DIE)
            me->CastSpell(killer, *i, true);
}

void SpellAI::EnterCombat(Unit *who)
{
    for(SpellVct::iterator i = spells.begin(); i != spells.end(); ++i)
    {
        if(AISpellInfo[*i].condition == AICOND_AGGRO)
            me->CastSpell(who, *i, false);
        else if(AISpellInfo[*i].condition == AICOND_COMBAT)
            events.ScheduleEvent(*i, AISpellInfo[*i].cooldown + rand()%AISpellInfo[*i].cooldown);
    }
}

void SpellAI::UpdateAI(const uint32 diff)
{
    if(!UpdateVictim())
        return;

    events.Update(diff);

    if(me->hasUnitState(UNIT_STAT_CASTING))
        return;

    if(uint32 spellId = events.ExecuteEvent())
    {
        DoCast(spellId);
        events.ScheduleEvent(spellId, AISpellInfo[spellId].cooldown + rand()%AISpellInfo[spellId].cooldown);
    }
    else
        DoMeleeAttackIfReady();
}

void SpellCasterAI::InitializeAI()
{
    SpellAI::InitializeAI();
    float m_attackDist = 30.0f;
    for(SpellVct::iterator itr = spells.begin(); itr != spells.end(); ++itr)
    {
        if (AISpellInfo[*itr].condition == AICOND_COMBAT && m_attackDist > GetAISpellInfo(*itr)->maxRange)
            m_attackDist = GetAISpellInfo(*itr)->maxRange;
    }
    if (m_attackDist == 30.0f)
        m_attackDist = MELEE_RANGE;
}

void SpellCasterAI::EnterCombat(Unit *who)
{
    if (spells.empty())
        return;

    uint32 spell = rand() % spells.size();
    uint32 count = 0;
    for(SpellVct::iterator itr = spells.begin(); itr != spells.end(); ++itr, ++count)
    {
        if(AISpellInfo[*itr].condition == AICOND_AGGRO)
            me->CastSpell(who, *itr, false);
        else if (AISpellInfo[*itr].condition == AICOND_COMBAT)
        {
            uint32 cooldown = GetAISpellInfo(*itr)->realCooldown;
            if (count == spell)
            {
                DoCast(spells[spell]);
                cooldown += me->GetCurrentSpellCastTime(*itr);
            }
            events.ScheduleEvent(*itr, cooldown);
        }
    }
}

void SpellCasterAI::UpdateAI(const uint32 diff)
{
    if(!UpdateVictim())
        return;

    events.Update(diff);

    if(me->hasUnitState(UNIT_STAT_CASTING))
        return;

    if(uint32 spellId = events.ExecuteEvent())
    {
        DoCast(spellId);
        uint32 casttime = me->GetCurrentSpellCastTime(spellId);
        events.ScheduleEvent(spellId, (casttime ? casttime : 500) + GetAISpellInfo(spellId)->realCooldown);
    }
}
