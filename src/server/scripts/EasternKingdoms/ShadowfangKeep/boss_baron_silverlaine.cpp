/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "shadowfang_keep.h"
#include "SpellMgr.h"

enum Spells
{
   SPELL_SUMMON_WORGEN_SPIRIT      = 93857,
   SPELL_VEIL_OF_SHADOW            = 23224,
   SPELL_CURSED_VEIL_H             = 93956,
};

enum Events
{
   EVENT_SUMMON_WORGEN_SPIRIT      = 1,
   EVENT_VEIL_OF_SHADOW,
   EVENT_CURSED_VEIL,
};

enum Texts
{
   SAY_AGGRO                       = 0,
   SAY_DEATH                       = 1,
   SAY_KILLER_1                    = 2,
   SAY_KILLER_2                    = 3,
};

enum Summons
{
   RETHILGORE                      = 50835,
   ODO_THE_BLINDWATCHER            = 50857,
   LUPINE_SPECTRE                  = 50923,
   RAZORCLAW_THE_BUTCHER           = 50869,
   WOLF_MASTER_NANDOS              = 50851,
};

class boss_baron_silverlaine : public CreatureScript
{
    struct boss_baron_silverlaineAI : public BossAI
    {
        boss_baron_silverlaineAI(Creature * creature) : BossAI(creature, BOSS_BARON_SILVERLAINE)
        {
            instance = creature->GetInstanceScript();
        }

       InstanceScript* instance;

        void Reset() override
        {
            _Reset();

            if (instance)
            {
                instance->SetData(DATA_BARON_SILVERLAINE_EVENT, NOT_STARTED);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            if (instance)
            {
                instance->SetData(DATA_BARON_SILVERLAINE_EVENT, IN_PROGRESS);
            }

            events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, 20000);
            events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 15000);
            events.ScheduleEvent(EVENT_CURSED_VEIL, 10000);
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();

            if (instance)
            {
                instance->SetData(DATA_BARON_SILVERLAINE_EVENT, DONE);
            }
        }

        void KilledUnit(Unit* /*victim*/) override
        {
            Talk(RAND(SAY_KILLER_1, SAY_KILLER_2));
        }

        void UpdateAI(uint32 diff) override
        {
            if(!UpdateVictim())
                return;

            events.Update(diff);

            if(me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if(uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
               case EVENT_SUMMON_WORGEN_SPIRIT:
                    DoCast(SPELL_SUMMON_WORGEN_SPIRIT);
                    events.ScheduleEvent(EVENT_SUMMON_WORGEN_SPIRIT, urand(20000, 30000));
                    break;
               case EVENT_VEIL_OF_SHADOW:
                    DoCast(SPELL_VEIL_OF_SHADOW);
                    events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, 10000);
                    break;
               case EVENT_CURSED_VEIL:
                    DoCast(SPELL_CURSED_VEIL_H);
                    events.ScheduleEvent(EVENT_CURSED_VEIL, urand(20000, 40000));
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
public:
    boss_baron_silverlaine() : CreatureScript("boss_baron_silverlaine") {}

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_baron_silverlaineAI(creature);
    }
};

class spell_summon_worgen_spirits : public SpellScriptLoader
{
    public:
        spell_summon_worgen_spirits() : SpellScriptLoader("spell_summon_worgen_spirits") { }

        class spell_summon_worgen_spirits_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_summon_worgen_spirits_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_WORGEN_SPIRIT))
                    return false;
                return true;
            }

            void AfterCast(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->SummonCreature(RAND(WOLF_MASTER_NANDOS, RAZORCLAW_THE_BUTCHER, RETHILGORE, ODO_THE_BLINDWATCHER, LUPINE_SPECTRE),
                    caster->GetPositionX() + 2, caster->GetPositionY(), caster->GetPositionZ(), 0.0f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 10000);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_summon_worgen_spirits_SpellScript::AfterCast, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_summon_worgen_spirits_SpellScript();
        }
};

void AddSC_boss_baron_silverlaine()
{
    new boss_baron_silverlaine();
    new spell_summon_worgen_spirits();
}
