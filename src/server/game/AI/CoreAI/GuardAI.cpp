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
    if (Unit const* unit = obj->ToUnit())
        if (unit->IsControlledByPlayer() && me->IsEngagedBy(unit))
            return true;
    return false;
}

void GuardAI::EnterEvadeMode(EvadeReason /*why*/)
{
    if (!me->IsAlive())
    {
        me->GetMotionMaster()->MoveIdle();
        me->CombatStop(true);
        EngagementOver();
        return;
    }

    TC_LOG_TRACE("scripts.ai", "GuardAI::EnterEvadeMode: %s enters evade mode.", me->GetGUID().ToString().c_str());

    me->RemoveAllAuras();
    me->CombatStop(true);
    EngagementOver();

    me->GetMotionMaster()->MoveTargetedHome();
}

void GuardAI::JustDied(Unit* killer)
{
    if (killer)
        if (Player* player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
            me->SendZoneUnderAttackMessage(player);
}
