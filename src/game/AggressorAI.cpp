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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "AggressorAI.h"
#include "Errors.h"
#include "Creature.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "VMapFactory.h"
#include "World.h"

#include <list>

int
AggressorAI::Permissible(const Creature *creature)
{
    // have some hostile factions, it will be selected by IsHostileTo check at MoveInLineOfSight
    if( !creature->isCivilian() && !creature->IsNeutralToAll() )
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

AggressorAI::AggressorAI(Creature &c) : i_creature(c), i_victimGuid(0), i_state(STATE_NORMAL), i_tracker(TIME_INTERVAL_LOOK)
{
}

void
AggressorAI::MoveInLineOfSight(Unit *u)
{
    // Ignore Z for flying creatures
    if( !i_creature.canFly() && i_creature.GetDistanceZ(u) > CREATURE_Z_ATTACK_RANGE )
        return;
    
    if( !i_creature.getVictim() && !i_creature.hasUnitState(UNIT_STAT_STUNNED) && i_creature.canAttack(u) &&
        ( i_creature.IsHostileTo( u ) /*|| u->getVictim() && i_creature.IsFriendlyTo( u->getVictim() )*/ ) &&
        u->isInAccessiblePlaceFor(&i_creature) )
    {
        float attackRadius = i_creature.GetAttackDistance(u);
        if(i_creature.IsWithinDistInMap(u, attackRadius) && i_creature.IsWithinLOSInMap(u) )
        {
            AttackStart(u);
            u->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH);
        }
    }
}

void AggressorAI::EnterEvadeMode()
{
    if( !i_creature.isAlive() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his dead [guid=%u]", i_creature.GetGUIDLow());
        i_victimGuid = 0;
        i_creature.CombatStop();
        i_creature.DeleteThreatList();
        return;
    }

    Unit* victim = ObjectAccessor::GetUnit(i_creature, i_victimGuid );

    if( !victim  )
    {
        DEBUG_LOG("Creature stopped attacking because victim is non exist [guid=%u]", i_creature.GetGUIDLow());
    }
    else if( !victim->isAlive() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his victim is dead [guid=%u]", i_creature.GetGUIDLow());
    }
    else if( victim->HasStealthAura() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his victim is stealth [guid=%u]", i_creature.GetGUIDLow());
    }
    else if( victim->isInFlight() )
    {
        DEBUG_LOG("Creature stopped attacking cuz his victim is fly away [guid=%u]", i_creature.GetGUIDLow());
    }
    else
    {
        DEBUG_LOG("Creature stopped attacking due to target out run him [guid=%u]", i_creature.GetGUIDLow());
        //i_state = STATE_LOOK_AT_VICTIM;
        //i_tracker.Reset(TIME_INTERVAL_LOOK);
    }

    if(!i_creature.GetCharmerOrOwner())
    {
        i_creature.RemoveAllAuras();

        // Remove TargetedMovementGenerator from MotionMaster stack list, and add HomeMovementGenerator instead
        if( i_creature.GetMotionMaster()->GetCurrentMovementGeneratorType() == TARGETED_MOTION_TYPE )
            i_creature.GetMotionMaster()->MoveTargetedHome();
    }
    else if (i_creature.GetOwner() && i_creature.GetOwner()->isAlive())
        i_creature.GetMotionMaster()->MoveFollow(owner,PET_FOLLOW_DIST,PET_FOLLOW_ANGLE);

    i_creature.DeleteThreatList();
    i_victimGuid = 0;
    i_creature.CombatStop();
    i_creature.SetLootRecipient(NULL);
}

void
AggressorAI::UpdateAI(const uint32 /*diff*/)
{
    // update i_victimGuid if i_creature.getVictim() !=0 and changed
    if(!i_creature.SelectHostilTarget() || !i_creature.getVictim())
        return;

    i_victimGuid = i_creature.getVictim()->GetGUID();

    if( i_creature.isAttackReady() )
    {
        if( i_creature.IsWithinCombatDist(i_creature.getVictim(), ATTACK_DISTANCE))
        {
            i_creature.AttackerStateUpdate(i_creature.getVictim());
            i_creature.resetAttackTimer();
        }
    }
}

bool
AggressorAI::IsVisible(Unit *pl) const
{
    return i_creature.GetDistance(pl) < sWorld.getConfig(CONFIG_SIGHT_MONSTER)
        && pl->isVisibleForOrDetect(&i_creature,true);
}

void
AggressorAI::AttackStart(Unit *u)
{
    if( !u )
        return;

    if(i_creature.Attack(u,true))
    {
        i_creature.SetInCombatWith(u);
        u->SetInCombatWith(&i_creature);

        i_creature.AddThreat(u, 0.0f);
        //    DEBUG_LOG("Creature %s tagged a victim to kill [guid=%u]", i_creature.GetName(), u->GetGUIDLow());
        i_victimGuid = u->GetGUID();

        i_creature.GetMotionMaster()->MoveChase(u);
    }
}
