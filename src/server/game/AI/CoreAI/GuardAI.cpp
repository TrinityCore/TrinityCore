/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "GuardAI.h"
#include "Creature.h"
#include "Errors.h"
#include "Log.h"
#include "MotionMaster.h"
#include "Player.h"

GuardAI::GuardAI(Creature* creature) : ScriptedAI(creature)
{
}

int32 GuardAI::Permissible(Creature const* creature)
{
    if (creature->IsGuard())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

void GuardAI::UpdateAI(uint32 /*diff*/)
{
    if (!UpdateVictim())
        return;

    DoMeleeAttackIfReady();
}

bool GuardAI::CanSeeAlways(WorldObject const* obj)
{
    if (!obj->isType(TYPEMASK_UNIT))
        return false;

    ThreatContainer::StorageType threatList = me->getThreatManager().getThreatList();
    for (ThreatContainer::StorageType::const_iterator itr = threatList.begin(); itr != threatList.end(); ++itr)
        if ((*itr)->getUnitGuid() == obj->GetGUID())
            return true;

    return false;
}

void GuardAI::EnterEvadeMode(EvadeReason /*why*/)
{
    if (!me->IsAlive())
    {
        me->GetMotionMaster()->MoveIdle();
        me->CombatStop(true);
        me->DeleteThreatList();
        return;
    }

    TC_LOG_DEBUG("entities.unit", "Guard entry: %u enters evade mode.", me->GetEntry());

    me->RemoveAllAuras();
    me->DeleteThreatList();
    me->CombatStop(true);

    // Remove ChaseMovementGenerator from MotionMaster stack list, and add HomeMovementGenerator instead
    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHASE_MOTION_TYPE)
        me->GetMotionMaster()->MoveTargetedHome();
}

void GuardAI::JustDied(Unit* killer)
{
    if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
        me->SendZoneUnderAttackMessage(player);
}
