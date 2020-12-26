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

#include "PassiveAI.h"
#include "Creature.h"

PassiveAI::PassiveAI(Creature* c) : CreatureAI(c) { me->SetReactState(REACT_PASSIVE); }
PossessedAI::PossessedAI(Creature* c) : CreatureAI(c) { me->SetReactState(REACT_PASSIVE); }
NullCreatureAI::NullCreatureAI(Creature* c) : CreatureAI(c) { me->SetReactState(REACT_PASSIVE); }

int32 NullCreatureAI::Permissible(Creature const* creature)
{
    if (creature->HasNpcFlag(UNIT_NPC_FLAG_SPELLCLICK))
        return PERMIT_BASE_PROACTIVE + 50;

    if (creature->IsTrigger())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_IDLE;
}

void PassiveAI::UpdateAI(uint32)
{
    if (me->IsInCombat() && me->getAttackers().empty())
        EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
}

void PossessedAI::AttackStart(Unit* target)
{
    me->Attack(target, true);
}

void PossessedAI::UpdateAI(uint32 /*diff*/)
{
    if (me->GetVictim())
    {
        if (!me->IsValidAttackTarget(me->GetVictim()))
            me->AttackStop();
        else
            DoMeleeAttackIfReady();
    }
}

void PossessedAI::JustDied(Unit* /*u*/)
{
    // We died while possessed, disable our loot
    me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
}

void PossessedAI::KilledUnit(Unit* victim)
{
    // We killed a creature, disable victim's loot
    if (victim->GetTypeId() == TYPEID_UNIT)
        me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
}

void PossessedAI::OnCharmed(bool /*apply*/)
{
    me->NeedChangeAI = true;
    me->IsAIEnabled = false;
}

void CritterAI::DamageTaken(Unit* /*done_by*/, uint32&)
{
    if (!me->HasUnitState(UNIT_STATE_FLEEING))
        me->SetControlled(true, UNIT_STATE_FLEEING);
}

void CritterAI::EnterEvadeMode(EvadeReason why)
{
    if (me->HasUnitState(UNIT_STATE_FLEEING))
        me->SetControlled(false, UNIT_STATE_FLEEING);
    CreatureAI::EnterEvadeMode(why);
}

int32 CritterAI::Permissible(Creature const* creature)
{
    if (creature->IsCritter() && !creature->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

void TriggerAI::IsSummonedBy(Unit* summoner)
{
    if (me->m_spells[0])
        me->CastSpell(me, me->m_spells[0], false, nullptr, nullptr, summoner->GetGUID());
}

int32 TriggerAI::Permissible(Creature const* creature)
{
    if (creature->IsTrigger() && creature->m_spells[0])
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}
