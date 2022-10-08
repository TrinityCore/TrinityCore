/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016-2019 MagicStorm
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

#include "trial_of_valor.h"

enum Spells
{
    SPELL_EXPEL_LIGHT_MARKER        = 228029,
    SPELL_EXPEL_LIGHT               = 228030,
    SPELL_SHIELD_OF_LIGHT           = 228162,
};

enum Events
{
    EVENT_EXPEL_LIGHT               = 1, // This ability seems to come in waves of 2 casts, the casts being 20 seconds apart and the waves 75 seconds apart.
    EVENT_SHIELD_OF_LIGHT, // every 35 seconds
};

enum Says
{
    SAY_COMBAT = 0,
    SAY_SHIELD = 1,
};

class boss_hyrja_tov : public CreatureScript
{
public:

    boss_hyrja_tov() : CreatureScript("boss_hyrja_tov") { }

    struct boss_hyrja_tovAI : public BossAI
    {
        boss_hyrja_tovAI(Creature* creature) : BossAI(creature, DATA_HYRJA)
        {
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));
            me->SetCanFly(false);

            if (instance)
                instance->SetBossState(DATA_HYRJA, NOT_STARTED);
        }

        Creature* hymdall = NULL;
        uint8 expelLightSwitch;

        void Reset() override
        {
            expelLightSwitch = 1;

            _Reset();
            if (instance)
                instance->SetBossState(DATA_HYRJA, FAIL);

            me->SetFaction(14);

            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();

            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                instance->SetBossState(DATA_HYRJA, IN_PROGRESS);
            }

            Talk(SAY_COMBAT);
            me->setActive(true);
            DoZoneInCombat();

            events.ScheduleEvent(EVENT_EXPEL_LIGHT, 20 * IN_MILLISECONDS);
            hymdall = me->FindNearestCreature(BOSS_HYRJA, 500.0f);
            hymdall->SetInCombatWithZone();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
                instance->SetBossState(DATA_HYRJA, DONE);
            }
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void JustReachedHome() override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustReachedHome();
                instance->SetBossState(DATA_HYRJA, FAIL);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->GetHealthPct() <= 25 && !(me->FindCurrentSpellBySpellId(SPELL_REVIVIFY)))
            {
                me->CastStop();
                me->CastSpell(me, SPELL_REVIVIFY, false);
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EXPEL_LIGHT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            me->CastSpell(target, SPELL_EXPEL_LIGHT_MARKER, false);

                        events.ScheduleEvent(EVENT_EXPEL_LIGHT, (expelLightSwitch <= 1) ? 20 : 75 * IN_MILLISECONDS);
                        expelLightSwitch = (expelLightSwitch <= 1) ? ++expelLightSwitch : 0;

                        break;
                    case EVENT_SHIELD_OF_LIGHT:
                        Talk(SAY_SHIELD);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            me->CastSpell(target, SPELL_SHIELD_OF_LIGHT, false);

                        events.ScheduleEvent(EVENT_SHIELD_OF_LIGHT, 35 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfValorAI<boss_hyrja_tovAI>(creature);
    }
};

// 228029 Expel Light
class spell_hyrja_expel_light_marker : public SpellScriptLoader
{
public:
    spell_hyrja_expel_light_marker() : SpellScriptLoader("spell_hyrja_expel_light_marker") { }

    class spell_hyrja_expel_light_marker_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hyrja_expel_light_marker_AuraScript);

        void OnTick(AuraEffect const*)
        {
            if (Unit* target = GetTarget())
                GetCaster()->CastSpell(target, SPELL_EXPEL_LIGHT, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_hyrja_expel_light_marker_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hyrja_expel_light_marker_AuraScript();
    }
};

void AddSC_boss_hyrja_tov()
{
    new boss_hyrja_tov();
    new spell_hyrja_expel_light_marker();
}
