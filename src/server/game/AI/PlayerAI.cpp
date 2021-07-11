/*
 * Copyright (C) 2005-2010 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2010 MaNGOSZero <http://github.com/mangoszero/mangoszero/>
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

#include "PlayerAI.h"
#include "Player.h"
#include "DBCStores.h"
#include "SpellMgr.h"
#include "MotionMaster.h"
#include "Spell.h"

// Misc spells we dont want players to cast
static std::vector<uint32> priestSkipSpells =
{
    453,8123,8192,8193,10953,10954,  // mind soothe
    1150,2096,2097,10909,10910,      // mind vision
    1265,9580,9581,9593,10943,10944, // fade
};
static std::vector<uint32> hunterSkipSpells =
{
    75, // auto shot
};

void PlayerAI::Remove()
{
    me->SetAI(nullptr);
    delete this;
}

PlayerAI::~PlayerAI()
{
}

bool PlayerAI::CanCastSpell(Unit* pTarget, SpellEntry const* pSpell, bool isTriggered, bool checkControlled)
{
    if (!pTarget)
        return false;

    // If not triggered, we check
    if (!isTriggered)
    {
        // State does not allow
        if (me->HasUnitState(checkControlled ? UNIT_STAT_CAN_NOT_REACT_OR_LOST_CONTROL : UNIT_STAT_CAN_NOT_REACT))
            return false;

        if (pSpell->PreventionType == SPELL_PREVENTION_TYPE_SILENCE && me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED))
            return false;

        if (pSpell->PreventionType == SPELL_PREVENTION_TYPE_PACIFY && me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED))
            return false;

        // Check for power (also done by Spell::CheckCast())
        if (me->GetPower((Powers)pSpell->powerType) < pSpell->manaCost)
            return false;
    }

    if (SpellRangeEntry const* pSpellRange = sSpellRangeStore.LookupEntry(pSpell->rangeIndex))
    {
        if (pTarget != me)
        {
            // pTarget is out of range of this spell (also done by Spell::CheckCast())
            float fDistance = me->GetCombatDistance(pTarget);

            if (fDistance > pSpellRange->maxRange)
                return false;

            float fMinRange = pSpellRange->minRange;

            if (fMinRange && fDistance < fMinRange)
                return false;
        }
        return true;
    }
    
    return false;
}

void PlayerAI::UpdateAI(uint32 const /*diff*/)
{
}

PlayerControlledAI::PlayerControlledAI(Player* pPlayer, Unit* caster) : PlayerAI(pPlayer), controllerGuid(caster ? caster->GetObjectGuid() : ObjectGuid()), uiGlobalCD(0)
{
    ASSERT(pPlayer);
    switch (pPlayer->GetClass())
    {
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
            bIsMelee = true;
            isHealer = false;
            break;
        case CLASS_PALADIN:
        case CLASS_DRUID:
            bIsMelee = true;
            isHealer = true;
            break;
        case CLASS_PRIEST:
        case CLASS_SHAMAN:
            isHealer = true;
            bIsMelee = false;
            break;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        case CLASS_HUNTER:
            isHealer = false;
            bIsMelee = false;
            break;
    }
    PlayerSpellMap spells = me->GetSpellMap();
    usableSpells.clear();
    for (const auto& spell : spells)
    {
        if (spell.second.state == PLAYERSPELL_REMOVED || spell.second.disabled)
            continue;
        SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell.first);
        if (spellInfo->SpellFamilyName == SPELLFAMILY_GENERIC)
            continue;
        if (spellInfo->Attributes & (SPELL_ATTR_PASSIVE | 0x80))
            continue;
        if (spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_DAMAGE)
            continue;
        if (Spells::IsPositiveSpell(spell.first) && !enablePositiveSpells)
            continue;
        switch (pPlayer->GetClass())
        {
        case CLASS_WARRIOR:
        case CLASS_ROGUE:
        case CLASS_PALADIN:
        case CLASS_DRUID:
        case CLASS_SHAMAN:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            break;
        case CLASS_HUNTER:
            if (std::find(hunterSkipSpells.begin(), hunterSkipSpells.end(), spell.first) != hunterSkipSpells.end())
                continue;
            break;
        case CLASS_PRIEST:
            if (std::find(priestSkipSpells.begin(), priestSkipSpells.end(), spell.first) != priestSkipSpells.end())
                continue;
            break;
        }
        usableSpells.push_back(spell.first);
    }
    // Suppression des sorts dont on a deja des rangs superieurs
    for (std::vector<uint32>::iterator it = usableSpells.begin(); it != usableSpells.end();)
    {
        bool foundSupRank = false;
        SpellEntry const* pCurrSpell_1 = sSpellMgr.GetSpellEntry(*(it));
        for (const auto& usableSpell : usableSpells)
        {
            SpellEntry const* pCurrSpell_2 = sSpellMgr.GetSpellEntry(usableSpell);
            if (pCurrSpell_2->SpellFamilyName == pCurrSpell_1->SpellFamilyName && pCurrSpell_2->SpellIconID == pCurrSpell_1->SpellIconID && pCurrSpell_2->SpellVisual == pCurrSpell_1->SpellVisual) // Meme sort, rangs differents
            {
                if (Spells::CompareAuraRanks(pCurrSpell_1->Id, pCurrSpell_2->Id) < 0) // pCurrSpell_1 < pCurrSpell_2
                {
                    // Donc on supprime pCurrSpell_1
                    foundSupRank = true;
                    break;
                }
            }
        }
        if (foundSupRank)
        {
            usableSpells.erase(it);
            it = usableSpells.begin();
        }
        else
            ++it;
    }
    
    me->GetMotionMaster()->Clear();
    
    if (caster && caster->ToCreature())
        if (Unit* victim = caster->ToCreature()->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            UpdateTarget(victim);

}

Unit* PlayerControlledAI::FindController()
{
    return me->GetMap()->GetUnit(controllerGuid);
}

void PlayerControlledAI::UpdateTarget(Unit* victim)
{
    if ((victim->IsCharmed() && victim->GetCharmerGuid() == me->GetCharmerGuid()) || me->IsFeared() || me->IsPolymorphed())
    {
        me->AttackStop();
        me->CastStop();
        return;
    }

    Unit* controller = FindController();

    bool isNewVictim = me->GetVictim() != victim;

    if (isNewVictim)
        me->Attack(victim, true);

    // Mode combat
    if (controller && controller->GetTypeId() == TYPEID_PLAYER)
    {
        me->SetInCombatWith(victim);
        controller->SetInCombatWith(victim);

        if (!me->GetMotionMaster()->empty() && me->GetMotionMaster()->GetCurrentMovementGeneratorType() != IDLE_MOTION_TYPE)
            return;
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveChase(victim);
    }
    else
    {
        me->SetInCombatWith(victim);
        victim->SetInCombatWith(me);
        if (controller)
        {
            controller->SetInCombatWith(victim);
            victim->SetInCombatWith(controller);
        }

        if (!bIsMelee)
            me->SetCasterChaseDistance(25.0f);

        if (isNewVictim)
        {
            me->GetMotionMaster()->Clear();
            me->GetMotionMaster()->MoveChase(victim);
            return;
        }
        else
        {
            bool inMeleeRange = me->CanReachWithMeleeAutoAttack(victim);
            if ((bIsMelee && inMeleeRange) || (!bIsMelee && !me->IsMoving() && me->IsWithinDist(victim, 30.0f)))
            {
                me->GetMotionMaster()->Clear();
                if (bIsMelee && !me->HasInArc(victim, 0.2f))
                {
                    me->SetFacingToObject(victim);
                }
                else if (!me->HasInArc(victim, 0.5f))
                {
                    me->SetFacingToObject(victim);
                }
            }
            else
            {
                // melee not in melee range or nonmoving caster not in caster range
                if (!me->IsInRoots() && !me->IsMoving())
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveChase(victim);
                }
            }
        }
    }
}

PlayerControlledAI::~PlayerControlledAI()
{
}

void PlayerControlledAI::UpdateAI(uint32 const uiDiff)
{
    if (me->IsDeleted() || !me->IsInWorld() || !me->IsAlive())
    {
        me->RemoveAI();
        return;
    }

    Unit* victim = nullptr;
    CharmInfo* charmInfo = me->GetCharmInfo();
    Unit* controller = FindController();

    // If controller is a player
    if (controller && controller->GetTypeId() == TYPEID_PLAYER)
    {
        Player* Pcontroller = ((Player*)controller);

        if (!Pcontroller->IsAlive())
        {
            me->RemoveCharmAuras();
            // Note that we CANNOT continue after this point since this object has been deleted
            // Pcontroller is a local var on the stack, not a member object, so it is safe to use
            Pcontroller->RemoveCharmAuras();
            return;
        }

        if (charmInfo)
        {
            if (charmInfo->HasReactState(REACT_PASSIVE))
                victim = me->GetVictim();
            else if (charmInfo->HasReactState(REACT_DEFENSIVE) || charmInfo->HasReactState(REACT_AGGRESSIVE))
            {
                victim = me->GetVictim();
                if (!victim || (victim == Pcontroller))
                    victim = Pcontroller->GetVictim();
            }
        }
        else
        {
            victim = me->GetVictim();
            if (!victim || (victim == Pcontroller))
                victim = Pcontroller->GetVictim();
        }

        if (!victim || (victim == me))
            return;

        UpdateTarget(victim);
    }
    else // If controller is a creature
    {
        Creature* Ccontroller = controller ? controller->ToCreature() : nullptr;

        // Unit* victim = controller-> getVictim ();
        // Ivina <Nostalrius>: chooses the target randomly and not always the target of the controller.
        victim = Ccontroller ? Ccontroller->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0) : me->SelectNearestTarget(50.0f);
        if (Unit* v2 = me->GetVictim())
            if (me->CanAttack(v2, false))
                victim = v2;

        if (Ccontroller && (!Ccontroller->IsAlive() || !Ccontroller->IsInCombat()))
        {
            me->RemoveCharmAuras();
            // Note that we CANNOT continue after this point since this object has been deleted
            // Ccontroller is a local var on the stack, not a member object, so it is safe to use
            Ccontroller->RemoveCharmAuras();
            return;
        }

        if (!victim || (victim == me)) // Ivina <Nostalrius>: avoid being targeted
            return;

        // Need a valid target
        if (!me->IsHostileTo(victim))
            return;

        UpdateTarget(victim);


        if (uiGlobalCD < uiDiff)
        {
            if (me->GetClass() == CLASS_HUNTER)
            {
                float dist = me->GetDistance(victim);
                if (dist > 10.0f)
                {
                    if (Spell* pSpell = me->GetCurrentSpell(CURRENT_AUTOREPEAT_SPELL))
                    {
                        if (pSpell->m_spellInfo && pSpell->m_spellInfo->Id != 75) // auto shoot
                            me->CastSpell(victim, 75, true);
                    }
                }
            }

            if (me->IsNonMeleeSpellCasted(true))
                uiGlobalCD = 200;
            else
            {
                // Since we are going to do something usableSpells [0, urand (0, usableSpells.size () - 1)], we must have at least one element.
                if (usableSpells.empty())
                    return;

                uint32 spellId = usableSpells[urand(0, usableSpells.size() - 1)];
                SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);
                
                // If its a positive spell we prioritize controller, if he's out of range,
                // ourself, otherwise it will probably not be cast.
                Unit* spellTarget = victim;
                if (controller && spellInfo->IsPositiveSpell(me, controller))
                    spellTarget = controller;
                else if (spellInfo->IsPositiveSpell(me, me))
                    spellTarget = me;

                if (spellInfo)
                {
                    if (CanCastSpell(spellTarget, spellInfo, false, false))
                    {
                        me->CastSpell(spellTarget, spellId, false);
                        uiGlobalCD = 1500;
                        if (!bIsMelee)
                            me->SetCasterChaseDistance(25.0f);
                    }
                    else
                    {
                        if (!bIsMelee)
                            me->SetCasterChaseDistance(0.0f);
                    }
                }
            }
        }
        else
            uiGlobalCD -= uiDiff;
    }
}
