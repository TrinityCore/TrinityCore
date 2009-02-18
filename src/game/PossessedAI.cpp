/*
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * Thanks to the original authors: MaNGOS <http://www.mangosproject.org/>
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

#include "PossessedAI.h"
#include "Creature.h"
#include "World.h"

void PossessedAI::AttackStart(Unit *u)
{
    if( !u || i_pet.GetCharmer()->HasAuraType(SPELL_AURA_MOD_PACIFY))
        return;

    if (i_pet.getVictim() && u != i_pet.getVictim())
        i_pet.AttackStop();

    if(i_pet.Attack(u, true))
        i_victimGuid = u->GetGUID();

    // Do not autochase our target, and also make sure our current movement generator
    // is removed since the motion master is reset before this function is called
    i_pet.GetMotionMaster()->Clear(false);
    i_pet.GetMotionMaster()->MoveIdle();
}

bool PossessedAI::_needToStop() const
{
    if(!i_pet.getVictim() || !i_pet.isAlive())
        return true;

    // This is needed for charmed creatures, as once their target was reset other effects can trigger threat
    if(i_pet.getVictim() == i_pet.GetCharmer())
        return true;

    return !i_pet.canAttack(i_pet.getVictim());
}

void PossessedAI::_stopAttack()
{
    if( !i_victimGuid )
        return;

    Unit* victim = Unit::GetUnit(i_pet, i_victimGuid );

    if ( !victim )
        return;

    assert(!i_pet.getVictim() || i_pet.getVictim() == victim);

    if( !i_pet.isAlive() )
    {
        i_pet.StopMoving();
        i_pet.GetMotionMaster()->Clear(false);
        i_pet.GetMotionMaster()->MoveIdle();
        i_victimGuid = 0;
        i_pet.CombatStop();
        i_pet.getHostilRefManager().deleteReferences();

        return;
    }

    i_pet.GetMotionMaster()->Clear(false);
    i_pet.GetMotionMaster()->MoveIdle();
    i_victimGuid = 0;
    i_pet.AttackStop();
}

void PossessedAI::UpdateAI(const uint32 diff)
{
    // update i_victimGuid if i_pet.getVictim() !=0 and changed
    if(i_pet.getVictim())
        i_victimGuid = i_pet.getVictim()->GetGUID();

    // i_pet.getVictim() can't be used for check in case stop fighting, i_pet.getVictim() clear at Unit death etc.
    if( i_victimGuid )
    {
        if( _needToStop() )
        {
            _stopAttack();                                  // i_victimGuid == 0 && i_pet.getVictim() == NULL now
            return;
        }
        else if(i_pet.IsWithinMeleeRange(i_pet.getVictim()) && i_pet.isAttackReady() && !i_pet.GetCharmer()->HasAuraType(SPELL_AURA_MOD_PACIFY))
        {
            i_pet.AttackerStateUpdate(i_pet.getVictim());

            i_pet.resetAttackTimer();

            if( _needToStop() )
                _stopAttack();
        }
    }
}

void PossessedAI::JustDied(Unit *u)
{
    // We died while possessed, disable our loot
    i_pet.RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
}

void PossessedAI::KilledUnit(Unit* victim)
{
    // We killed a creature, disable victim's loot
    if (victim->GetTypeId() == TYPEID_UNIT)
        victim->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
}

