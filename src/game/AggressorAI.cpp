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
            me->CastSpell(who, *i, true);
        else if(AISpellInfo[*i].condition == AICOND_COMBAT)
            events.ScheduleEvent(*i, AISpellInfo[*i].cooldown + rand()%AISpellInfo[*i].cooldown);
    }
    i_creature.ResetDamageByPlayers();
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
        Unit *target = NULL;
        //sLog.outError("aggre %u %u", spellId, (uint32)AISpellInfo[spellId].target);
        switch(AISpellInfo[spellId].target)
        {
            default:
            case AITARGET_SELF:     target = me; break;
            case AITARGET_VICTIM:   target = me->getVictim(); break;
            case AITARGET_ENEMY:    target = SelectTarget(SELECT_TARGET_RANDOM); break;
            case AITARGET_ALLY:     target = me; break;
            case AITARGET_BUFF:     target = me; break;
            case AITARGET_DEBUFF:
            {
                const SpellEntry * spellInfo = GetSpellStore()->LookupEntry(spellId);
                bool playerOnly = spellInfo->AttributesEx3 & SPELL_ATTR_EX3_PLAYERS_ONLY;
                float range = GetSpellMaxRange(spellInfo, false);
                target = SelectTarget(SELECT_TARGET_RANDOM, 0, range, playerOnly, -(int32)spellId);
                break;
            }
        }
        if(target) me->CastSpell(target, spellId, false);
        events.ScheduleEvent(spellId, AISpellInfo[spellId].cooldown + rand()%AISpellInfo[spellId].cooldown);
    }
    else
        DoMeleeAttackIfReady();
}
