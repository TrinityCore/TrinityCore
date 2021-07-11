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

#include "ReactorAI.h"
#include "Creature.h"
#include "Player.h"
#include "GuardMgr.h"

ReactorAI::ReactorAI(Creature* c) : CreatureAI(c), m_bCanSummonGuards(c->CanSummonGuards())
{}

int ReactorAI::Permissible(Creature const* creature)
{
    if (creature->HasExtraFlag(CREATURE_FLAG_EXTRA_NO_AGGRO) || creature->IsNeutralToAll())
        return PERMIT_BASE_REACTIVE;

    return PERMIT_BASE_NO;
}

void ReactorAI::JustRespawned()
{
    m_bCanSummonGuards = m_creature->CanSummonGuards();
}

void ReactorAI::MoveInLineOfSight(Unit* pWho)
{
    if (!CanSummonGuards() || m_creature->IsInCombat())
        return;

    if (!pWho->IsPlayer())
        return;

    if (!m_creature->IsWithinDistInMap(pWho, m_creature->GetDetectionRange()))
        return;

    if (m_creature->IsHostileTo(pWho) && pWho->IsTargetable(true, false) && m_creature->IsWithinLOSInMap(pWho))
        m_bCanSummonGuards = !sGuardMgr.SummonGuard(m_creature, static_cast<Player*>(pWho));
}

void ReactorAI::AttackStart(Unit* p)
{
    if (!p)
        return;

    if (m_creature->Attack(p, true))
    {
        DEBUG_FILTER_LOG(LOG_FILTER_AI_AND_MOVEGENSS, "Tag unit GUID: %u (TypeId: %u) as a victim", p->GetGUIDLow(), p->GetTypeId());

        m_creature->AddThreat(p);

        m_creature->SetInCombatWith(p);
        p->SetInCombatWith(m_creature);

        if (m_bCombatMovement)
            m_creature->GetMotionMaster()->MoveChase(p);
    }
}

void ReactorAI::UpdateAI(uint32 const uiDiff)
{
    if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        return;

    if (!m_CreatureSpells.empty())
        UpdateSpellsList(uiDiff);

    DoMeleeAttackIfReady();
}
