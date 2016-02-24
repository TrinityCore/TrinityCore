/*
* Copyright (C) 2016-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "PlayerAI.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum Spells
{
    /* Generic */
    SPELL_AUTO_SHOT         =    75,
    SPELL_SHOOT             =  3018,
    SPELL_THROW             =  2764,
    SPELL_SHOOT_WAND        =  5019,
};
PlayerAI::PlayerAI(Player* player) : UnitAI(static_cast<Unit*>(player)), me(player), _isRangedAttacker(false)
{
    switch (me->getClass())
    {
        case CLASS_WARRIOR:
            _isRangedAttacker = false;
            break;
        case CLASS_PALADIN:
            _isRangedAttacker = false;
            break;
        case CLASS_HUNTER:
        {
            // check if we have a ranged weapon equipped
            Item const* rangedSlot = me->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (ItemTemplate const* rangedTemplate = rangedSlot ? rangedSlot->GetTemplate() : nullptr)
                if ((1 << rangedTemplate->GetSubClass()) & ITEM_SUBCLASS_MASK_WEAPON_RANGED)
                {
                    _isRangedAttacker = true;
                    break;
                }
            _isRangedAttacker = false;
            break;
        }
        case CLASS_ROGUE:
            _isRangedAttacker = false;
            break;
        case CLASS_PRIEST:
            _isRangedAttacker = me->GetSpecId(me->GetActiveTalentGroup()) == TALENT_SPEC_PRIEST_SHADOW;
            break;
        case CLASS_DEATH_KNIGHT:
            _isRangedAttacker = false;
            break;
        case CLASS_SHAMAN:
            _isRangedAttacker = me->GetSpecId(me->GetActiveTalentGroup()) == TALENT_SPEC_SHAMAN_ELEMENTAL;
            break;
        case CLASS_MAGE:
            _isRangedAttacker = true;
            break;
        case CLASS_WARLOCK:
            _isRangedAttacker = true;
            break;
        case CLASS_DRUID:
            _isRangedAttacker = me->GetSpecId(me->GetActiveTalentGroup()) == TALENT_SPEC_DRUID_BALANCE;
            break;
        default:
            TC_LOG_WARN("entities.unit", "Possessed player %s (possessed by %s) does not have any recognized class (class = %u).", me->GetGUID().ToString().c_str(), me->GetCharmerGUID().ToString().c_str(), me->getClass());
            break;
    }
}

void PlayerAI::DoRangedAttackIfReady()
{
    if (me->HasUnitState(UNIT_STATE_CASTING))
        return;

    if (!me->isAttackReady(RANGED_ATTACK))
        return;

    Unit* victim = me->GetVictim();
    if (!victim)
        return;

    uint32 rangedAttackSpell = 0;

    Item const* rangedItem = me->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
    if (ItemTemplate const* rangedTemplate = rangedItem ? rangedItem->GetTemplate() : nullptr)
    {
        switch (rangedTemplate->GetSubClass())
        {
            case ITEM_SUBCLASS_WEAPON_BOW:
            case ITEM_SUBCLASS_WEAPON_GUN:
            case ITEM_SUBCLASS_WEAPON_CROSSBOW:
                rangedAttackSpell = SPELL_SHOOT;
                break;
            case ITEM_SUBCLASS_WEAPON_THROWN:
                rangedAttackSpell = SPELL_THROW;
                break;
            case ITEM_SUBCLASS_WEAPON_WAND:
                rangedAttackSpell = SPELL_SHOOT_WAND;
                break;
        }
    }

    if (!rangedAttackSpell)
        return;

    me->CastSpell(victim, rangedAttackSpell, TRIGGERED_CAST_DIRECTLY);
    me->resetAttackTimer(RANGED_ATTACK);
}

void PlayerAI::DoAutoAttackIfReady()
{
    if (IsRangedAttacker())
        DoRangedAttackIfReady();
    else
        DoMeleeAttackIfReady();
}

void SimpleCharmedPlayerAI::UpdateAI(const uint32 /*diff*/)
{
    Creature* charmer = me->GetCharmer()->ToCreature();

    //kill self if charm aura has infinite duration
    if (charmer->IsInEvadeMode())
    {
        Player::AuraEffectList const& auras = me->GetAuraEffectsByType(SPELL_AURA_MOD_CHARM);
        for (Player::AuraEffectList::const_iterator iter = auras.begin(); iter != auras.end(); ++iter)
            if ((*iter)->GetCasterGUID() == charmer->GetGUID() && (*iter)->GetBase()->IsPermanent())
            {
                me->Kill(me);
                return;
            }
    }

    if (charmer->IsInCombat())
    {
        Unit* target = me->GetVictim();
        if (!target || !charmer->IsValidAttackTarget(target))
        {
            target = charmer->SelectNearestTarget();
            if (!target)
                return;

            if (IsRangedAttacker())
                AttackStartCaster(target, 28.0f);
            else
                AttackStart(target);
        }
    }
    else
    {
        me->AttackStop();
        me->CastStop();
        me->GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }

    DoAutoAttackIfReady();
}

void SimpleCharmedPlayerAI::OnCharmed(bool apply)
{
    if (apply)
    {
        me->CastStop();
        me->AttackStop();
    }
    else
    {
        me->CastStop();
        me->AttackStop();
        // @todo only voluntary movement (don't cancel stuff like death grip or charge mid-animation)
        me->GetMotionMaster()->Clear();
        me->StopMoving();
    }
}
