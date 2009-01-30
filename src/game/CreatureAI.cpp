/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#include "Pet.h"
#include "SpellAuras.h"

CreatureAI::~CreatureAI()
{
}

void CreatureAI::EnterEvadeMode()
{
    if(!me) return;

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
    {
        target = charmer->SelectNearestTarget();
        if(!target)
            return;

        me->GetMotionMaster()->MoveChase(target);
        me->Attack(target, true);
    }
}
