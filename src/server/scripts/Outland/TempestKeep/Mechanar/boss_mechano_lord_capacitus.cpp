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

#include "ScriptMgr.h"
#include "Containers.h"
#include "mechanar.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum CapacitusTexts
{
    SAY_AGGRO                       = 0,
    SAY_SLAY                        = 1,
    SAY_DAMAGE_SHIELD               = 2,
    SAY_MAGIC_SHIELD                = 3,
    SAY_DEATH                       = 4
};

enum CapacitusSpells
{
    SPELL_HEAD_CRACK                = 35161,
    SPELL_MAGIC_SHIELD              = 35158,
    SPELL_DAMAGE_SHIELD             = 35159,
    SPELL_POLARITY_SHIFT            = 39096,
    SPELL_BERSERK                   = 26662,

    SPELL_SUMMON_NETHER_CHARGE_NE   = 35153,
    SPELL_SUMMON_NETHER_CHARGE_NW   = 35904,
    SPELL_SUMMON_NETHER_CHARGE_SE   = 35905,
    SPELL_SUMMON_NETHER_CHARGE_SW   = 35906,

    SPELL_TRIGGER_DAMAGE_SHIELD     = 35173,
    SPELL_TRIGGER_MAGIC_SHIELD      = 35174,

    SPELL_POSITIVE_CHARGE_PERIODIC  = 39088,
    SPELL_POSITIVE_CHARGE_STACK     = 39089,
    SPELL_POSITIVE_CHARGE_DAMAGE    = 39090,

    SPELL_NEGATIVE_CHARGE_PERIODIC  = 39091,
    SPELL_NEGATIVE_CHARGE_STACK     = 39092,
    SPELL_NEGATIVE_CHARGE_DAMAGE    = 39093
};

enum CapacitusEvents
{
    EVENT_HEAD_CRACK                = 1,
    EVENT_MAGIC_SHIELD,
    EVENT_DAMAGE_SHIELD,
    EVENT_POLARITY_SHIFT,
    EVENT_SUMMON_NETHER_CHARGE,
    EVENT_BERSERK
};

// 19219 - Mechano-Lord Capacitus
struct boss_mechano_lord_capacitus : public BossAI
{
    boss_mechano_lord_capacitus(Creature* creature) : BossAI(creature, DATA_MECHANOLORD_CAPACITUS) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_HEAD_CRACK, 10s, 20s);
        events.ScheduleEvent(EVENT_SUMMON_NETHER_CHARGE, 10s);

        if (!IsHeroic())
        {
            events.ScheduleEvent(EVENT_MAGIC_SHIELD, 35s);
            events.ScheduleEvent(EVENT_DAMAGE_SHIELD, 15s);
        }
        else
        {
            events.ScheduleEvent(EVENT_POLARITY_SHIFT, 25s, 30s);
            events.ScheduleEvent(EVENT_BERSERK, 3min);
        }
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DAMAGE_SHIELD:
                if (roll_chance_i(30))
                    Talk(SAY_DAMAGE_SHIELD);
                break;
            case SPELL_MAGIC_SHIELD:
                if (roll_chance_i(30))
                    Talk(SAY_MAGIC_SHIELD);
                break;
            default:
                break;
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_DAMAGE_SHIELD:
                if (!me->HasAura(SPELL_TRIGGER_DAMAGE_SHIELD))
                    DoCastSelf(SPELL_TRIGGER_DAMAGE_SHIELD, true);
                if (roll_chance_i(30))
                    Talk(SAY_DAMAGE_SHIELD);
                break;
            case SPELL_MAGIC_SHIELD:
                if (!me->HasAura(SPELL_TRIGGER_MAGIC_SHIELD))
                    DoCastSelf(SPELL_TRIGGER_MAGIC_SHIELD, true);
                if (roll_chance_i(30))
                    Talk(SAY_MAGIC_SHIELD);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEAD_CRACK:
                    DoCastVictim(SPELL_HEAD_CRACK);
                    events.Repeat(20s, 40s);
                    break;
                case EVENT_MAGIC_SHIELD:
                    DoCastSelf(SPELL_MAGIC_SHIELD);
                    break;
                case EVENT_DAMAGE_SHIELD:
                    DoCastSelf(SPELL_DAMAGE_SHIELD);
                    break;
                case EVENT_POLARITY_SHIFT:
                    DoCastAOE(SPELL_POLARITY_SHIFT);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_SUMMON_NETHER_CHARGE:
                    DoCastSelf(RAND(SPELL_SUMMON_NETHER_CHARGE_NE, SPELL_SUMMON_NETHER_CHARGE_NW, SPELL_SUMMON_NETHER_CHARGE_SE, SPELL_SUMMON_NETHER_CHARGE_SW));
                    events.Repeat(1s, 4s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 39096 - Polarity Shift
class spell_capacitus_polarity_shift : public SpellScript
{
    PrepareSpellScript(spell_capacitus_polarity_shift);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POSITIVE_CHARGE_PERIODIC, SPELL_NEGATIVE_CHARGE_PERIODIC, SPELL_POSITIVE_CHARGE_STACK, SPELL_NEGATIVE_CHARGE_STACK });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        std::vector<WorldObject*> shuffledTargets(targets.begin(), targets.end());
        Trinity::Containers::RandomShuffle(shuffledTargets);

        targets.clear();

        for (WorldObject* target : shuffledTargets)
            targets.push_back(target);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        target->RemoveAurasDueToSpell(SPELL_POSITIVE_CHARGE_PERIODIC);
        target->RemoveAurasDueToSpell(SPELL_NEGATIVE_CHARGE_PERIODIC);
        target->RemoveAurasDueToSpell(SPELL_POSITIVE_CHARGE_STACK);
        target->RemoveAurasDueToSpell(SPELL_NEGATIVE_CHARGE_STACK);

        // In sniffs two or even three targets in a row can receive same buff, so current handling is not entirely correct. Just a small detail
        target->CastSpell(nullptr, (_targetIndex % 2 == 0) ? SPELL_POSITIVE_CHARGE_PERIODIC : SPELL_NEGATIVE_CHARGE_PERIODIC, GetCaster()->GetGUID());

        ++_targetIndex;
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_capacitus_polarity_shift::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_capacitus_polarity_shift::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    uint32 _targetIndex = 0;
};

// 39088 - Positive Charge
// 39091 - Negative Charge
class spell_capacitus_polarity_charge_periodic : public AuraScript
{
    PrepareAuraScript(spell_capacitus_polarity_charge_periodic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POSITIVE_CHARGE_STACK, SPELL_NEGATIVE_CHARGE_STACK });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_POSITIVE_CHARGE_STACK);
        target->RemoveAurasDueToSpell(SPELL_NEGATIVE_CHARGE_STACK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_capacitus_polarity_charge_periodic::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 39090 - Positive Charge
// 39093 - Negative Charge
class spell_capacitus_polarity_charge_damage : public SpellScript
{
    PrepareSpellScript(spell_capacitus_polarity_charge_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_POSITIVE_CHARGE_DAMAGE,
            SPELL_POSITIVE_CHARGE_STACK,
            SPELL_NEGATIVE_CHARGE_DAMAGE,
            SPELL_NEGATIVE_CHARGE_STACK
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!GetTriggeringSpell())
            return;

        for (std::list<WorldObject*>::iterator itr = targets.begin(); itr != targets.end();)
        {
            if ((*itr)->IsPlayer() && (*itr)->ToPlayer()->HasAura(GetTriggeringSpell()->Id))
            {
                itr = targets.erase(itr);
                ++_targetCount;
            }
            else
                ++itr;
        }
    }

    void HandleAfterCast()
    {
        if (_targetCount)
        {
            uint32 spellId = 0;

            if (GetSpellInfo()->Id == SPELL_POSITIVE_CHARGE_DAMAGE)
                spellId = SPELL_POSITIVE_CHARGE_STACK;
            else if (GetSpellInfo()->Id == SPELL_NEGATIVE_CHARGE_DAMAGE)
                spellId = SPELL_NEGATIVE_CHARGE_STACK;

            if (!spellId)
                return;

            GetCaster()->RemoveAurasDueToSpell(spellId);

            GetCaster()->CastSpell(nullptr, spellId, CastSpellExtraArgs()
                .SetTriggerFlags(TRIGGERED_FULL_MASK)
                .AddSpellMod(SPELLVALUE_AURA_STACK, _targetCount));
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_capacitus_polarity_charge_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        AfterCast += SpellCastFn(spell_capacitus_polarity_charge_damage::HandleAfterCast);
    }

private:
    uint32 _targetCount = 0;
};

void AddSC_boss_mechano_lord_capacitus()
{
    RegisterMechanarCreatureAI(boss_mechano_lord_capacitus);
    RegisterSpellScript(spell_capacitus_polarity_shift);
    RegisterSpellScript(spell_capacitus_polarity_charge_periodic);
    RegisterSpellScript(spell_capacitus_polarity_charge_damage);
}
