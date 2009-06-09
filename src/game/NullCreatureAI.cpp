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

#include "NullCreatureAI.h"
#include "Creature.h"
#include "TemporarySummon.h"

void PassiveAI::UpdateAI(const uint32)
{
    if(me->isInCombat() && me->getAttackers().empty())
        EnterEvadeMode();
}

void PossessedAI::AttackStart(Unit *target)
{
    me->Attack(target, true);
}

void PossessedAI::UpdateAI(const uint32 diff)
{
    if(me->getVictim())
    {
        if(!me->canAttack(me->getVictim()))
            me->AttackStop();
        else
            DoMeleeAttackIfReady();
    }
}

void PossessedAI::JustDied(Unit *u)
{
    // We died while possessed, disable our loot
    me->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
}

void PossessedAI::KilledUnit(Unit* victim)
{
    // We killed a creature, disable victim's loot
    if (victim->GetTypeId() == TYPEID_UNIT)
        victim->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
}

void CritterAI::DamageTaken(Unit *done_by, uint32 &)
{
    if(!me->hasUnitState(UNIT_STAT_FLEEING))
        me->SetControlled(true, UNIT_STAT_FLEEING);
}

void CritterAI::EnterEvadeMode()
{
    if(me->hasUnitState(UNIT_STAT_FLEEING))
        me->SetControlled(false, UNIT_STAT_FLEEING);
    CreatureAI::EnterEvadeMode();
}

void TriggerAI::UpdateAI(const uint32 diff)
{
    if(!casted)
    {
        casted = true;
        if(me->m_spells[0] && me->isSummon())
            me->CastSpell(me, me->m_spells[0], false, 0, 0, ((TempSummon*)me)->GetSummonerGUID());
    }
}
