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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "CreatureAI.h"
#include "Creature.h"
#include "Player.h"
#include "Pet.h"
#include "SpellAuras.h"

void UnitAI::AttackStart(Unit *victim)
{
    if(!victim)
        return;

    if(me->Attack(victim, true))
    {
        //DEBUG_LOG("Creature %s tagged a victim to kill [guid=%u]", me->GetName(), victim->GetGUIDLow());
        me->GetMotionMaster()->MoveChase(victim);
    }
}

void CreatureAI::MoveInLineOfSight(Unit *who)
{
    if(!me->getVictim() && me->canStartAttack(who))
        AttackStart(who);

    if (who->isInCombat() && who->getVictim() && me->GetCreatureType()==CREATURE_TYPE_HUMANOID && me->IsFriendlyTo(who))
        {
        if (me->GetDistanceZ(who) <= 2 && me->IsWithinLOSInMap(who))
            {
            float attackRadius = (me->GetAttackDistance(who) *0.5);
            if (me->IsWithinDistInMap(who, attackRadius))
                {
                Unit* target = NULL;
                target = who->getVictim();
                AttackStart(target);
                }
            }
        }
}

bool CreatureAI::UpdateVictim()
{
    if(!me->isInCombat())
        return false;
    if(Unit *victim = me->SelectVictim())
        AttackStart(victim);
    return me->getVictim();
}

void CreatureAI::EnterEvadeMode()
{
    me->RemoveAllAuras();
    me->DeleteThreatList();
    me->CombatStop();
    me->LoadCreaturesAddon();
    me->SetLootRecipient(NULL);

    if(me->isAlive())
        me->GetMotionMaster()->MoveTargetedHome();
}

void SimpleCharmedAI::UpdateAI(const uint32 /*diff*/)
{
    Creature *charmer = (Creature*)me->GetCharmer();

    //kill self if charm aura has infinite duration
    if(charmer->IsInEvadeMode())
    {
        Unit::AuraList const& auras = me->GetAurasByType(SPELL_AURA_MOD_CHARM);
        for(Unit::AuraList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
            if((*iter)->GetCasterGUID() == charmer->GetGUID() && (*iter)->IsPermanent())
            {
                charmer->Kill(me);
                return;
            }
    }

    if(!charmer->isInCombat())
        me->GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

    Unit *target = me->getVictim();
    if(!target || !charmer->canAttack(target))
        AttackStart(charmer->SelectNearestTarget());
}
