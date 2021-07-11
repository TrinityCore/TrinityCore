/*
* Copyright (C) 2017-2018 Light's Hope <https://lightshope.org>
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

#include "PetEventAI.h"
#include "Pet.h"
#include "Player.h"

PetEventAI::PetEventAI(Creature* pCreature) : CreatureEventAI(pCreature)
{}

int PetEventAI::Permissible(Creature const* creature)
{
    if ((creature->GetAIName() == "PetEventAI") || (creature->IsPet() && (creature->GetAIName() == "EventAI")))
        return PERMIT_BASE_SPECIAL;

    return PERMIT_BASE_NO;
}

void PetEventAI::MoveInLineOfSight(Unit* pWho)
{
    if (!pWho)
        return;

    if (m_creature->GetVictim())
        return;

    //Check for OOC LOS Event
    if (!m_bEmptyList)
        UpdateEventsOn_MoveInLineOfSight(pWho);

    if (!m_creature->HasReactState(REACT_AGGRESSIVE))
        return;

    if (m_creature->GetCharmInfo() && m_creature->GetCharmInfo()->IsReturning())
        return;

    if (m_creature->GetDistanceZ(pWho) > CREATURE_Z_ATTACK_RANGE)
        return;

    // World of Warcraft Client Patch 1.8.0 (2005-10-11)
    // - Guardians and pets in aggressive mode no longer attack civilians.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
    if (m_creature->IsPet() && pWho->IsCreature() && static_cast<Creature*>(pWho)->IsCivilian())
        return;
#endif

    if (m_creature->CanInitiateAttack() && pWho->IsTargetable(true, m_creature->IsCharmerOrOwnerPlayerOrPlayerItself()))
    {
        float const attackRadius = m_creature->GetAttackDistance(pWho);
        if (m_creature->IsWithinDistInMap(pWho, attackRadius, true, false) && m_creature->IsHostileTo(pWho) &&
            pWho->IsInAccessablePlaceFor(m_creature) && m_creature->IsWithinLOSInMap(pWho))
            AttackStart(pWho);
    }
}

void PetEventAI::AttackStart(Unit* pWho)
{
    if (!pWho)
        return;

    if (m_creature->IsPet() && !static_cast<Pet*>(m_creature)->IsEnabled())
        return;

    if (pWho == m_creature->GetCharmerOrOwner())
        return;

    if (m_creature->HasReactState(REACT_PASSIVE) && m_creature->GetCharmInfo() && !m_creature->GetCharmInfo()->IsCommandAttack())
        return;

    if (pWho->HasAuraPetShouldAvoidBreaking() && m_creature->GetCharmerOrOwner() && m_creature->GetCharmerOrOwner()->IsAlive())
        return;

    if (m_creature->Attack(pWho, m_bMeleeAttack))
    {
        m_creature->AddThreat(pWho);
        m_creature->SetInCombatWith(pWho);
        pWho->SetInCombatWith(m_creature);

        if (Player* pOwner = ToPlayer(m_creature->GetCharmerOrOwner()))
        {
            if (!pOwner->IsInCombat())
            {
                if (m_creature->HasReactState(REACT_AGGRESSIVE))
                    m_creature->SendPetAIReaction();

                pOwner->SetInCombatWith(pWho);
                pWho->SetInCombatWith(pOwner);
            }
            
            if (!pOwner->IsPvP())
                pOwner->TogglePlayerPvPFlagOnAttackVictim(pWho);
        }

        if (m_bCombatMovement)
        {
            if (m_creature->GetCharmInfo())
                m_creature->GetCharmInfo()->SetIsReturning(false);
            m_creature->GetMotionMaster()->MoveChase(pWho);
        }   
    } 
}

void PetEventAI::AttackedBy(Unit* pAttacker)
{
    if (!m_creature->GetVictim())
        AttackStart(pAttacker);

    if (Creature* pOwner = ToCreature(m_creature->GetCharmerOrOwner()))
    {
        pOwner->AddThreat(pAttacker);
        pOwner->SetInCombatWith(pAttacker);
    }
}

bool PetEventAI::FindTargetForAttack()
{
    if (Unit* pTaunter = m_creature->GetTauntTarget())
    {
        AttackStart(pTaunter);
        return true;
    }

    // Check if any of the Pet's attackers are valid targets.
    Unit::AttackerSet attackers = m_creature->GetAttackers();
    for (const auto& itr : attackers)
    {
        if (itr->IsInMap(m_creature) && m_creature->IsValidAttackTarget(itr) && !itr->HasAuraPetShouldAvoidBreaking())
        {
            AttackStart(itr);
            return true;
        }
    }

    Unit const* pOwner = m_creature->GetCharmerOrOwner();

    if (!pOwner)
        return false;

    // Pet has no attackers, check for anyone attacking Owner.
    if (Unit* const pTarget = pOwner->GetAttackerForHelper())
    {
        // Prevent pets from breaking CC effects
        if (!pTarget->HasAuraPetShouldAvoidBreaking())
        {
            AttackStart(pTarget);
            return true;
        } 
        else
        {
            // Main target is CC-ed, so pick another attacker.
            Unit::AttackerSet owner_attackers = pOwner->GetAttackers();
            for (const auto& itr : owner_attackers)
            {
                if (itr->IsInMap(m_creature) && m_creature->IsValidAttackTarget(itr) && !itr->HasAuraPetShouldAvoidBreaking())
                {
                    AttackStart(itr);
                    return true;
                }
            }
        }
    }
    return false;
}

void PetEventAI::UpdateAI(uint32 const uiDiff)
{
    //Must return if creature isn't alive. Normally select hostile target and get victim prevent this
    if (!m_creature->IsAlive())
        return;

    Unit const* pOwner = m_creature->GetCharmerOrOwner();
    bool const hasAliveOwner = pOwner && pOwner->IsAlive() && m_creature->GetCharmInfo();
    bool bHasVictim = m_creature->GetVictim();

    if (!bHasVictim && (m_creature->IsInCombat() || (hasAliveOwner && pOwner->IsInCombat())))
    {
        if (FindTargetForAttack())
            bHasVictim = m_creature->GetVictim();
    }

    if (!m_bEmptyList)
        UpdateEventsOn_UpdateAI(uiDiff, bHasVictim);

    if (bHasVictim)
    {
        if (!m_CreatureSpells.empty())
            UpdateSpellsList(uiDiff);

        DoMeleeAttackIfReady();
    }
    else
    {
        if (m_creature->IsInCombat() && !(hasAliveOwner && pOwner->IsInCombat()))
            m_creature->OnLeaveCombat();

        if (hasAliveOwner && m_creature->GetCharmInfo()->HasCommandState(COMMAND_FOLLOW) && !m_creature->HasUnitState(UNIT_STAT_FOLLOW))
        {
            m_creature->GetMotionMaster()->MoveFollow(m_creature->GetCharmerOrOwner(), PET_FOLLOW_DIST,
                                                      m_creature->IsPet() && static_cast<Pet*>(m_creature)->getPetType() == MINI_PET ? MINI_PET_FOLLOW_ANGLE : PET_FOLLOW_ANGLE);
            if (m_creature->GetCharmInfo())
                m_creature->GetCharmInfo()->SetIsReturning(true);
        }     
    }
}

void PetEventAI::OwnerAttackedBy(Unit* pAttacker)
{
    // Called when owner takes damage. This function helps keep pets from running off
    //  simply due to owner gaining aggro.
    if (!pAttacker)
        return;

    // Prevent pet from disengaging from current target
    if (m_creature->GetVictim() && m_creature->GetVictim()->IsAlive())
        return;

    // If owner attacked by fire, attacker=owner. Don't attack our owner !
    if (!m_creature->IsValidAttackTarget(pAttacker))
        return;

    // Continue to evaluate and attack if necessary
    AttackStart(pAttacker);
}

void PetEventAI::OwnerAttacked(Unit* pTarget)
{
    // Called when owner attacks something. Allows defensive pets to know
    //  that they need to assist

    // Target might be nullptr if called from spell with invalid cast targets
    if (!pTarget)
        return;

    // Prevent pet from disengaging from current target
    if (m_creature->GetVictim() && m_creature->GetVictim()->IsAlive())
        return;

    if (!m_creature->IsValidAttackTarget(pTarget))
        return;

    // Continue to evaluate and attack if necessary
    AttackStart(pTarget);
}

void PetEventAI::MovementInform(uint32 moveType, uint32 data)
{
    CreatureEventAI::MovementInform(moveType, data);

    if (!m_creature->GetCharmInfo() || !m_creature->GetCharmerOrOwner())
        return;

    // Receives notification when pet reaches owner
    if (moveType == FOLLOW_MOTION_TYPE)
    {
        // If data is owner's GUIDLow then we've reached follow point,
        // otherwise we're probably chasing a creature.
        if ((data == m_creature->GetCharmerOrOwner()->GetGUIDLow()) && m_creature->GetCharmInfo()->IsReturning())
        {
            m_creature->GetCharmInfo()->SetIsReturning(false);
        }
    }
}