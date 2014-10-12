/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "molten_core.h"

enum Spells
{
    SPELL_ARCANE_EXPLOSION      = 19712,
    SPELL_SHAZZRAH_CURSE        = 19713,
    SPELL_MAGIC_GROUNDING       = 19714,
    SPELL_COUNTERSPELL          = 19715,
    SPELL_SHAZZRAH_GATE_DUMMY   = 23138, // Teleports to and attacks a random target.
    SPELL_SHAZZRAH_GATE         = 23139,
};

enum Events
{
    EVENT_ARCANE_EXPLOSION              = 1,
    EVENT_ARCANE_EXPLOSION_TRIGGERED    = 2,
    EVENT_SHAZZRAH_CURSE                = 3,
    EVENT_MAGIC_GROUNDING               = 4,
    EVENT_COUNTERSPELL                  = 5,
    EVENT_SHAZZRAH_GATE                 = 6,
};

class boss_shazzrah : public CreatureScript
{
    public:
        boss_shazzrah() : CreatureScript("boss_shazzrah") { }

        struct boss_shazzrahAI : public BossAI
        {
            boss_shazzrahAI(Creature* creature) : BossAI(creature, BOSS_SHAZZRAH)
            {
            }

            void EnterCombat(Unit* target) override
            {
                BossAI::EnterCombat(target);
                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, 6000);
                events.ScheduleEvent(EVENT_SHAZZRAH_CURSE, 10000);
                events.ScheduleEvent(EVENT_MAGIC_GROUNDING, 24000);
                events.ScheduleEvent(EVENT_COUNTERSPELL, 15000);
                events.ScheduleEvent(EVENT_SHAZZRAH_GATE, 45000);
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
                        case EVENT_ARCANE_EXPLOSION:
                            DoCastVictim(SPELL_ARCANE_EXPLOSION);
                            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, urand(4000, 7000));
                            break;
                        // Triggered subsequent to using "Gate of Shazzrah".
                        case EVENT_ARCANE_EXPLOSION_TRIGGERED:
                            DoCastVictim(SPELL_ARCANE_EXPLOSION);
                            break;
                        case EVENT_SHAZZRAH_CURSE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_SHAZZRAH_CURSE))
                                DoCast(target, SPELL_SHAZZRAH_CURSE);
                            events.ScheduleEvent(EVENT_SHAZZRAH_CURSE, urand(25000, 30000));
                            break;
                        case EVENT_MAGIC_GROUNDING:
                            DoCast(me, SPELL_MAGIC_GROUNDING);
                            events.ScheduleEvent(EVENT_MAGIC_GROUNDING, 35000);
                            break;
                        case EVENT_COUNTERSPELL:
                            DoCastVictim(SPELL_COUNTERSPELL);
                            events.ScheduleEvent(EVENT_COUNTERSPELL, urand(16000, 20000));
                            break;
                        case EVENT_SHAZZRAH_GATE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                DoResetThreat();
                                AttackStart(target); // Attack the target which caster will teleport to.
                                DoCast(me, SPELL_SHAZZRAH_GATE_DUMMY);
                                events.ScheduleEvent(EVENT_ARCANE_EXPLOSION_TRIGGERED, 2000);
                                events.RescheduleEvent(EVENT_ARCANE_EXPLOSION, urand(3000, 6000));
                            }
                            events.ScheduleEvent(EVENT_SHAZZRAH_GATE, 45000);
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
            return new boss_shazzrahAI(creature);
        }
};

class spell_shazzrah_gate_dummy : public SpellScriptLoader
{
    public:
        spell_shazzrah_gate_dummy() : SpellScriptLoader("spell_shazzrah_gate_dummy") { }

        class spell_shazzrah_gate_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_shazzrah_gate_dummy_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAZZRAH_GATE))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                if (GetCaster() && GetHitUnit())
                    GetHitUnit()->CastSpell(GetCaster(), SPELL_SHAZZRAH_GATE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_shazzrah_gate_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shazzrah_gate_dummy_SpellScript();
        }
};

void AddSC_boss_shazzrah()
{
    new boss_shazzrah();
    new spell_shazzrah_gate_dummy();
}
