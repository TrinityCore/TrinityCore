/*
 * Copyright 2021 
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
#include "PhasingHandler.h"

enum Spells
{
    SPELL_FELFIRE_MISSILES = 241498,
    SPELL_FELFIRE_MISSILES_TRIGGER = 241507,
    SPELL_QUAKE = 241458,
    SPELL_SEAR = 241518,
};

enum Events
{
    EVENT_FELFIRE_MISSILES = 1,
    EVENT_QUAKE = 2,
    EVENT_SEAR = 3,
};

//121124
class boss_apocron : public CreatureScript
{
public:
    boss_apocron() : CreatureScript("boss_apocron") { }

    struct boss_apocronAI : public WorldBossAI
    {
        boss_apocronAI(Creature* creature) : WorldBossAI(creature) { }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->GetMotionMaster()->MoveTargetedHome();

            events.Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            if (!who)
                return;
            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
            events.Reset();

            events.ScheduleEvent(EVENT_FELFIRE_MISSILES, 10s);
            events.ScheduleEvent(EVENT_QUAKE, 22s);
            events.ScheduleEvent(EVENT_SEAR, 11s);
            //me->AI()->Talk(88247); //On aggro text
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            WorldBossAI::EnterEvadeMode(why);
            Reset();
            DoStopAttack();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (events.Empty())
            {
                events.ScheduleEvent(EVENT_FELFIRE_MISSILES, 10s);
                events.ScheduleEvent(EVENT_QUAKE, 22s);
                events.ScheduleEvent(EVENT_SEAR, 11s);
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FELFIRE_MISSILES:
                {
                    DoCastRandom(SPELL_FELFIRE_MISSILES, true);
                    events.Repeat(10s, 15s);
                    break;
                }
                case EVENT_QUAKE:
                {
                    DoCastVictim(SPELL_QUAKE, true);
                    events.Repeat(22s, 26s);
                    break;
                }
                case EVENT_SEAR:
                {
                    DoCastVictim(SPELL_SEAR, true);
                    events.Repeat(11s);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_apocronAI(creature);
    }
};

//241498
class spell_apocron_felfir_missiles : public SpellScriptLoader
{
public:
    spell_apocron_felfir_missiles() : SpellScriptLoader("spell_apocron_felfir_missiles")
    {}

    class spell_apocron_felfir_missiles_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_apocron_felfir_missiles_SpellScript);

        void HandleDummy(SpellEffIndex)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetCaster()->CastSpell(GetHitUnit(), SPELL_FELFIRE_MISSILES_TRIGGER, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_apocron_felfir_missiles_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SUMMON);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_apocron_felfir_missiles_SpellScript();
    }
};
void AddSC_boss_apocron()
{
    new boss_apocron();
    new spell_apocron_felfir_missiles();
}
