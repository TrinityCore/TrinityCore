/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "mechanar.h"
#include "Player.h"

enum Spells
{
    SPELL_HEADCRACK                 = 35161,
    SPELL_REFLECTIVE_MAGIC_SHIELD   = 35158,
    SPELL_REFLECTIVE_DAMAGE_SHIELD  = 35159,
    SPELL_POLARITY_SHIFT            = 39096,
    SPELL_BERSERK                   = 26662,
    SPELL_NETHER_CHARGE_TIMER       = 37670,
    SPELL_NETHER_CHARGE_PASSIVE     = 37670,

    SPELL_POSITIVE_POLARITY         = 39088,
    SPELL_POSITIVE_CHARGE_STACK     = 39089,
    SPELL_POSITIVE_CHARGE           = 39090,

    SPELL_NEGATIVE_POLARITY         = 39091,
    SPELL_NEGATIVE_CHARGE_STACK     = 39092,
    SPELL_NEGATIVE_CHARGE           = 39093
};

enum Yells
{
    YELL_AGGRO                      = 0,
    YELL_REFLECTIVE_MAGIC_SHIELD    = 1,
    YELL_REFLECTIVE_DAMAGE_SHIELD   = 2,
    YELL_KILL                       = 3,
    YELL_DEATH                      = 4
};

enum Creatures
{
    NPC_NETHER_CHARGE               = 20405
};

enum Events
{
    EVENT_NONE                      = 0,

    EVENT_HEADCRACK                 = 1,
    EVENT_REFLECTIVE_DAMAGE_SHIELD  = 2,
    EVENT_REFLECTIVE_MAGIE_SHIELD   = 3,
    EVENT_POSITIVE_SHIFT            = 4,
    EVENT_SUMMON_NETHER_CHARGE      = 5,
    EVENT_BERSERK                   = 6
};

class boss_mechano_lord_capacitus : public CreatureScript
{
    public:
        boss_mechano_lord_capacitus() : CreatureScript("boss_mechano_lord_capacitus") { }

        struct boss_mechano_lord_capacitusAI : public BossAI
        {
            boss_mechano_lord_capacitusAI(Creature* creature) : BossAI(creature, DATA_MECHANOLORD_CAPACITUS) { }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                Talk(YELL_AGGRO);
                events.ScheduleEvent(EVENT_HEADCRACK, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_REFLECTIVE_DAMAGE_SHIELD, 15 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON_NETHER_CHARGE, 10 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 3 * MINUTE * IN_MILLISECONDS);

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_POSITIVE_SHIFT, 15 * IN_MILLISECONDS);
            }

            void KilledUnit(Unit* /*victim*/) OVERRIDE
            {
                Talk(YELL_KILL);
            }

            void JustDied(Unit* /*victim*/) OVERRIDE
            {
                _JustDied();
                Talk(YELL_DEATH);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                        case EVENT_HEADCRACK:
                            DoCastVictim(SPELL_HEADCRACK);
                            events.ScheduleEvent(EVENT_HEADCRACK, 10 * IN_MILLISECONDS);
                            break;
                        case EVENT_REFLECTIVE_DAMAGE_SHIELD:
                            Talk(YELL_REFLECTIVE_DAMAGE_SHIELD);
                            DoCast(me, SPELL_REFLECTIVE_DAMAGE_SHIELD);
                            events.ScheduleEvent(EVENT_REFLECTIVE_MAGIE_SHIELD, 30 * IN_MILLISECONDS);
                            break;
                        case EVENT_REFLECTIVE_MAGIE_SHIELD:
                            Talk(YELL_REFLECTIVE_MAGIC_SHIELD);
                            DoCast(me, SPELL_REFLECTIVE_MAGIC_SHIELD);
                            events.ScheduleEvent(EVENT_REFLECTIVE_DAMAGE_SHIELD, 30 * IN_MILLISECONDS);
                            break;
                        case EVENT_POSITIVE_SHIFT:
                            DoCastAOE(SPELL_POLARITY_SHIFT);
                            events.ScheduleEvent(EVENT_POSITIVE_SHIFT, urand(45, 60) * IN_MILLISECONDS);
                            break;
                        case EVENT_SUMMON_NETHER_CHARGE:
                        {
                            Position pos;
                            me->GetRandomNearPosition(pos, 5.0f);
                            me->SummonCreature(NPC_NETHER_CHARGE, pos, TEMPSUMMON_TIMED_DESPAWN, 18000);
                            events.ScheduleEvent(EVENT_SUMMON_NETHER_CHARGE, 10 * IN_MILLISECONDS);
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new boss_mechano_lord_capacitusAI(creature);
        }
};

class spell_capacitus_polarity_charge : public SpellScriptLoader
{
    public:
        spell_capacitus_polarity_charge() : SpellScriptLoader("spell_capacitus_polarity_charge") { }

        class spell_capacitus_polarity_charge_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_capacitus_polarity_charge_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_CHARGE_STACK))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_CHARGE_STACK))
                    return false;
                return true;
            }

            void HandleTargets(std::list<WorldObject*>& targetList)
            {
                uint8 count = 0;
                for (std::list<WorldObject*>::iterator ihit = targetList.begin(); ihit != targetList.end(); ++ihit)
                    if ((*ihit)->GetGUID() != GetCaster()->GetGUID())
                        if (Player* target = (*ihit)->ToPlayer())
                            if (target->HasAura(GetTriggeringSpell()->Id))
                                ++count;

                if (count)
                {
                    uint32 spellId = 0;

                    if (GetSpellInfo()->Id == SPELL_POSITIVE_CHARGE)
                        spellId = SPELL_POSITIVE_CHARGE_STACK;
                    else // if (GetSpellInfo()->Id == SPELL_NEGATIVE_CHARGE)
                        spellId = SPELL_NEGATIVE_CHARGE_STACK;

                    GetCaster()->SetAuraStack(spellId, GetCaster(), count);
                }
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                if (!GetTriggeringSpell())
                    return;

                Unit* target = GetHitUnit();

                if (target->HasAura(GetTriggeringSpell()->Id))
                    SetHitDamage(0);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_capacitus_polarity_charge_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_capacitus_polarity_charge_SpellScript::HandleTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_capacitus_polarity_charge_SpellScript();
        }
};

class spell_capacitus_polarity_shift : public SpellScriptLoader
{
    public:
        spell_capacitus_polarity_shift() : SpellScriptLoader("spell_capacitus_polarity_shift") { }

        class spell_capacitus_polarity_shift_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_capacitus_polarity_shift_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_POSITIVE_POLARITY) || !sSpellMgr->GetSpellInfo(SPELL_NEGATIVE_POLARITY))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* target = GetHitUnit();
                Unit* caster = GetCaster();

                target->CastSpell(target, roll_chance_i(50) ? SPELL_POSITIVE_POLARITY : SPELL_NEGATIVE_POLARITY, true, NULL, NULL, caster->GetGUID());
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_capacitus_polarity_shift_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_capacitus_polarity_shift_SpellScript();
        }
};

void AddSC_boss_mechano_lord_capacitus()
{
    new boss_mechano_lord_capacitus();
    new spell_capacitus_polarity_charge();
    new spell_capacitus_polarity_shift();
}
