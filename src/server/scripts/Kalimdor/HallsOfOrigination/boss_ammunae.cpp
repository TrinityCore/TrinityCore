/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "halls_of_origination.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum Spells
{
    //  Ammunae
    SPELL_ZERO_ENERGY                   = 72242,
    SPELL_WITHER                        = 76043,
    SPELL_CONSUME_LIFE_ENERGY           = 75725,
    SPELL_RAMPANT_GROWTH                = 75790,
    SPELL_SUMMON_SEEDLING_POD           = 75621, // summons 40550 (normal) or 51329 (heroic)
    SPELL_SUMMON_SPORE                  = 75695, // summons 40585
    
    // Consume Life Energy spell
    SPELL_CONSUME_LIFE_ENERGY_LEECH     = 79768,
    SPELL_CONSUME_LIFE_ENERGY_ENERGIZE  = 75665,

    // Seedling Pod npc
    SPELL_SEEDLING_POD_ENERGIZE         = 75708,
    SPELL_FORCECAST_SUMMON_BLOSSOM      = 75774, // forces Seedling Pods to cast 75771
    SPELL_SUMMON_BLOODPETAL_BLOSSOM     = 75771  // summons 40620
};

enum Texts
{
    SAY_DEATH               = 0,
    SAY_AGGRO               = 1,
    SAY_SPECIAL             = 2,
    SAY_PLAYER_KILL         = 3
};


enum Events
{
    // Ammunae
    EVENT_WITHER = 1,
    EVENT_APPLY_IMMUNITY,
    EVENT_CONSUME_LIFE_ENERGY,
    EVENT_SEEDLING_POD,
    EVENT_SUMMON_BLOODPETAL_BLOSSOM,
    EVENT_SUMMON_SPORE,

    // Blossom
    EVENT_TRANSFORM,
    EVENT_EMERGE,
    EVENT_THORN_SLASH
};

// 39731 Ammunae <Construct of Life>
class boss_ammunae : public CreatureScript
{
    public:
        boss_ammunae() : CreatureScript("boss_ammunae") { }

        struct boss_ammunaeAI : public BossAI
        {
            boss_ammunaeAI(Creature* creature) : BossAI(creature, DATA_AMMUNAE) { }

            void Reset() override
            {
                _Reset();
                me->MakeInterruptable(false);
                me->AddAura(SPELL_ZERO_ENERGY, me);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                events.ScheduleEvent(EVENT_WITHER, !IsHeroic() ? Seconds(7) : Seconds(5));
                events.ScheduleEvent(EVENT_SEEDLING_POD, Seconds(7));
                events.ScheduleEvent(EVENT_CONSUME_LIFE_ENERGY, Seconds(20));
                events.ScheduleEvent(EVENT_SUMMON_SPORE, Seconds(47));
            }

            void JustReachedHome() override
            {
                me->AddAura(SPELL_ZERO_ENERGY, me);
                me->SetPower(POWER_ENERGY, 0);
                instance->SetBossState(DATA_AMMUNAE, NOT_STARTED);
                _JustReachedHome();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                instance->SetBossState(DATA_AMMUNAE, FAIL);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->MakeInterruptable(false);
                events.Reset();
                _EnterEvadeMode();
            }

            void JustDied(Unit* /*who*/) override
            {
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while(uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WITHER:
                            me->MakeInterruptable(true);
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_WITHER);                            
                            events.ScheduleEvent(EVENT_APPLY_IMMUNITY, 1500);
                            events.Repeat(Seconds(20));
                            break;
                        case EVENT_APPLY_IMMUNITY:
                            me->MakeInterruptable(false);
                            break;
                        case EVENT_SEEDLING_POD:
                            // If 100 energy, cast Rampant Growth
                            if (me->GetPower(POWER_ENERGY) >= 100)
                            {
                                Talk(SAY_SPECIAL);
                                me->SetPower(POWER_ENERGY, 0);
                                DoCast(SPELL_RAMPANT_GROWTH);
                            }
                            DoCast(SPELL_SUMMON_SEEDLING_POD);
                            events.Repeat(Seconds(7));
                            break;
                        case EVENT_CONSUME_LIFE_ENERGY:
                            DoCast(SPELL_CONSUME_LIFE_ENERGY);
                            events.Repeat(Seconds(15));
                            break;
                        case EVENT_SUMMON_SPORE:
                            DoCast(SPELL_SUMMON_SPORE);
                            events.Repeat(Seconds(47));
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

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_ammunaeAI(creature);
        }
};

// 75725 Consume Life Energy
class spell_ammunae_consume_life_energy : public SpellScriptLoader
{
public:
    spell_ammunae_consume_life_energy() : SpellScriptLoader("spell_ammunae_consume_life_energy") { }

    class spell_ammunae_consume_life_energy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_ammunae_consume_life_energy_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_CONSUME_LIFE_ENERGY_LEECH, SPELL_CONSUME_LIFE_ENERGY_ENERGIZE });
        }
        
        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_CONSUME_LIFE_ENERGY_LEECH);
            GetCaster()->CastSpell(GetCaster(), SPELL_CONSUME_LIFE_ENERGY_ENERGIZE);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ammunae_consume_life_energy_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_ammunae_consume_life_energy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_ammunae_consume_life_energy_SpellScript();
    }
};

void AddSC_boss_ammunae()
{
    new boss_ammunae();
    new spell_ammunae_consume_life_energy();
}
