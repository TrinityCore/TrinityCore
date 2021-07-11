/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
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

#include "AggressorAI.h"
#include "Creature.h"
#include "Map.h"

int AggressorAI::Permissible(Creature const* creature)
{
    // have some hostile factions, it will be selected by IsHostileTo check at MoveInLineOfSight
    if (!creature->HasExtraFlag(CREATURE_FLAG_EXTRA_NO_AGGRO) && !creature->IsNeutralToAll())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

void AggressorAI::MoveInLineOfSight(Unit* u)
{
    // Check this now to prevent calling expensive functions (IsInAccessablePlaceFor / IsWithinLOSInMap)
    if (m_creature->GetVictim() && !m_creature->GetMap()->IsDungeon())
        return;

    if (!m_creature->IsWithinDistInMap(u, m_creature->GetAttackDistance(u), true, false))
        return;

    if (m_creature->CanInitiateAttack() && u->IsTargetable(true, false) && m_creature->IsHostileTo(u) &&
        m_creature->IsWithinLOSInMap(u) && u->IsInAccessablePlaceFor(m_creature))
    {
        if (!m_creature->GetVictim())
            AttackStart(u);
        else if (m_creature->GetMap()->IsDungeon())
        {
            m_creature->AddThreat(u);
            u->SetInCombatWith(m_creature);
        }
    }
}


void AggressorAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        return;

    if (!m_CreatureSpells.empty())
        UpdateSpellsList(uiDiff);

    DoMeleeAttackIfReady();
}

void AggressorAI::AttackStart(Unit* u)
{
    if (!u)
        return;

    if (m_creature->Attack(u, true))
    {
        m_creature->AddThreat(u);
        m_creature->SetInCombatWith(u);
        u->SetInCombatWith(m_creature);

        if (m_bCombatMovement)
            m_creature->GetMotionMaster()->MoveChase(u);
    }
}
