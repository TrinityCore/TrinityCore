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

    /* Paladin */
    PASSIVE_ILLUMINATION    = 20215,

    /* Priest */
    SPELL_SOUL_WARDING      = 63574,
    SPELL_SPIRIT_REDEMPTION = 20711,
    SPELL_SHADOWFORM        = 15473,

    /* Shaman */
    SPELL_TIDAL_FORCE       = 582,
    SPELL_MANA_TIDE_TOTEM   = 590,
    SPELL_SHA_NATURE_SWIFT  = 591,
    SPELL_STORMSTRIKE       = 17364,

    /* Druid */
    SPELL_MOONKIN_FORM      = 24858,
    SPELL_SWIFTMEND         = 18562,
    SPELL_DRU_NATURE_SWIFT  = 17116,
    SPELL_TREE_OF_LIFE      = 33891
};

bool PlayerAI::IsPlayerHealer(Player const* who)
{
    switch (who->getClass())
    {
        case CLASS_WARRIOR:
        case CLASS_HUNTER:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        case CLASS_MAGE:
        case CLASS_WARLOCK:
        default:
            return false;
        case CLASS_PALADIN:
            return who->HasSpell(PASSIVE_ILLUMINATION);
        case CLASS_PRIEST:
            return who->HasSpell(SPELL_SOUL_WARDING) || who->HasSpell(SPELL_SPIRIT_REDEMPTION);
        case CLASS_SHAMAN:
            return who->HasSpell(SPELL_MANA_TIDE_TOTEM) || who->HasSpell(SPELL_SHA_NATURE_SWIFT) || who->HasSpell(SPELL_TIDAL_FORCE);
        case CLASS_DRUID:
            return who->HasSpell(SPELL_SWIFTMEND) || who->HasSpell(SPELL_DRU_NATURE_SWIFT) || who->HasSpell(SPELL_TREE_OF_LIFE);
    }
}

bool PlayerAI::IsPlayerRangedAttacker(Player const* who)
{
    switch (who->getClass())
    {
        case CLASS_WARRIOR:
        case CLASS_PALADIN:
        case CLASS_ROGUE:
        case CLASS_DEATH_KNIGHT:
        default:
            return false;
        case CLASS_MAGE:
        case CLASS_WARLOCK:
            return true;
        case CLASS_HUNTER:
        {
            // check if we have a ranged weapon equipped
            Item const* rangedSlot = who->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
            if (ItemTemplate const* rangedTemplate = rangedSlot ? rangedSlot->GetTemplate() : nullptr)
                if ((1 << rangedTemplate->SubClass) & ITEM_SUBCLASS_MASK_WEAPON_RANGED)
                    return true;
            return false;
        }
        case CLASS_PRIEST:
            return who->HasSpell(SPELL_SHADOWFORM);
        case CLASS_SHAMAN:
            return !who->HasSpell(SPELL_STORMSTRIKE);
        case CLASS_DRUID:
            return who->HasSpell(SPELL_MOONKIN_FORM);
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
        switch (rangedTemplate->SubClass)
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

struct UncontrolledTargetSelectPredicate : public std::unary_function<Unit*, bool>
{
    bool operator()(Unit const* target) const
    {
        return !target->HasBreakableByDamageCrowdControlAura();
    }
};
Unit* SimpleCharmedPlayerAI::SelectAttackTarget() const
{
    if (Unit* charmer = me->GetCharmer())
        return charmer->IsAIEnabled ? charmer->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, UncontrolledTargetSelectPredicate()) : charmer->GetVictim();
    return nullptr;
}

void SimpleCharmedPlayerAI::UpdateAI(const uint32 /*diff*/)
{
    Creature* charmer = me->GetCharmer() ? me->GetCharmer()->ToCreature() : nullptr;
    if (!charmer)
        return;

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
        if (!target || !charmer->IsValidAttackTarget(target) || target->HasBreakableByDamageCrowdControlAura())
        {
            target = SelectAttackTarget();
            if (!target)
                return;

            if (IsRangedAttacker())
                AttackStartCaster(target, 28.0f);
            else
                AttackStart(target);
        }
        DoAutoAttackIfReady();
    }
    else
    {
        me->AttackStop();
        me->CastStop();
        me->StopMoving();
        me->GetMotionMaster()->Clear();
        me->GetMotionMaster()->MoveFollow(charmer, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
    }
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
