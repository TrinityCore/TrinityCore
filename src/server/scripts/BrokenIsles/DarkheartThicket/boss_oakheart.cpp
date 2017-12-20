/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "darkheart_thicket.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Spells
{

    //Nightmare Breath
    SPELL_NIGHTMARE_BREATH_DAMAGE   = 204667,

    //Shattered Earth
    SPELL_SHATTERED_EARTH_DAMAGE    = 204666,

    //Strangling Roots
    SPELL_STRANGLING_ROOTS_TARGET   = 204574,
    SPELL_STRANGLING_ROOTS_MISSILE  = 199051,
    SPELL_STRANGLING_ROOTS_SUMMON   = 199060,
    SPELL_STRANGLING_ROOTS_AURA     = 199063,
    SPELL_STRANGLING_ROOTS_AT       = 199067,
    SPELL_STRANGLING_ROOTS_VISUAL   = 100991,

    //Crushing Grip
    SPELL_CRUSHING_GRIP_CAST        = 204611,
    SPELL_CRUSHING_GRIP_VEHICLE     = 204613,
    SPELL_CRUSHING_GRIP_THROW       = 204658
};

enum Events
{
    EVENT_SHATTERED_EARTH   = 1,
    EVENT_CRUSHING_GRIP     = 2,
    EVENT_STRANGLING_ROOTS  = 3,
    EVENT_NIGHTMARE_BREATH  = 4
};

enum Talks
{
    SAY_PULL        = 0,
    SAY_ROOT        = 1,
    SAY_BREATH      = 2,
    SAY_DIE         = 3,
};

class boss_oakheart : public CreatureScript
{
public:
    boss_oakheart() : CreatureScript("boss_oakheart") { }

    struct boss_oakheartAI : public BossAI
    {
        boss_oakheartAI(Creature* creature) : BossAI(creature, DATA_OAKHEART) { }

        void Reset() override
        {
            _Reset();
            events.ScheduleEvent(EVENT_STRANGLING_ROOTS, urand(16000, 18000));
            events.ScheduleEvent(EVENT_SHATTERED_EARTH, urand(4000, 6000));
            events.ScheduleEvent(EVENT_NIGHTMARE_BREATH, urand(10000, 12000));
            events.ScheduleEvent(EVENT_CRUSHING_GRIP, 20000);
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            instance->SetBossState(DATA_OAKHEART, FAIL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
            DoZoneInCombat();

            events.Reset();
            events.ScheduleEvent(EVENT_STRANGLING_ROOTS, urand(16000, 18000));
            events.ScheduleEvent(EVENT_SHATTERED_EARTH, urand(4000, 6000));
            events.ScheduleEvent(EVENT_NIGHTMARE_BREATH, urand(10000, 12000));
            events.ScheduleEvent(EVENT_CRUSHING_GRIP, 20000);

            Talk(SAY_PULL);
            instance->SetBossState(DATA_OAKHEART, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DIE);
            instance->SetBossState(DATA_OAKHEART, DONE);
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
                    case EVENT_SHATTERED_EARTH:
                    {
                        events.ScheduleEvent(EVENT_SHATTERED_EARTH, urand(35000, 40000));
                        me->CastSpell(me, SPELL_SHATTERED_EARTH_DAMAGE, false);
                        break;
                    }
                    case EVENT_CRUSHING_GRIP:
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO);
                        if (!target)
                            break;
                        me->CastSpell(target, SPELL_CRUSHING_GRIP_CAST, false);
                        events.ScheduleEvent(EVENT_CRUSHING_GRIP, urand(29000, 32000));
                        break;
                    }
                    case EVENT_STRANGLING_ROOTS:
                    {
                        events.ScheduleEvent(EVENT_STRANGLING_ROOTS, urand(23000, 31000));
                        me->CastSpell(me, SPELL_STRANGLING_ROOTS_TARGET, false);
                        Talk(SAY_ROOT);
                        break;
                    }
                    case EVENT_NIGHTMARE_BREATH:
                    {
                        events.ScheduleEvent(EVENT_NIGHTMARE_BREATH, urand(26000, 35000));
                        Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO);
                        if (!target)
                            break;
                        me->CastSpell(target, SPELL_NIGHTMARE_BREATH_DAMAGE, false);
                        Talk(SAY_BREATH);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_oakheartAI(creature);
    }
};

/*

    Strangling Roots

*/

//204574
class spell_oakheart_strangling_roots_target : public SpellScriptLoader
{
public:
    spell_oakheart_strangling_roots_target() : SpellScriptLoader("spell_oakheart_strangling_roots_target") { }

    class spell_oakheart_strangling_roots_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_oakheart_strangling_roots_target_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_STRANGLING_ROOTS_MISSILE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_oakheart_strangling_roots_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_oakheart_strangling_roots_target_SpellScript();
    }
};

//199060
class spell_oakheart_strangling_roots_summon : public SpellScriptLoader
{
public:
    spell_oakheart_strangling_roots_summon() : SpellScriptLoader("spell_oakheart_strangling_roots_summon") { }

    class spell_oakheart_strangling_roots_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_oakheart_strangling_roots_summon_SpellScript);

        void HandleSummon(Creature* /*creature*/)
        {
            Unit* caster = GetCaster();
            
            if (!caster)
                return;

            //creature->CastSpell(creature, SPELL_STRANGLING_ROOTS_AT, false);
        }

        void Register() override
        {
            OnEffectSummon += SpellOnEffectSummonFn(spell_oakheart_strangling_roots_summon_SpellScript::HandleSummon);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_oakheart_strangling_roots_summon_SpellScript();
    }
};

//AT ID : 6037
//Spell ID : 199067 - Effect 0
class at_oakheart_strangling_roots : public AreaTriggerEntityScript
{
public:
    at_oakheart_strangling_roots() : AreaTriggerEntityScript("at_oakheart_strangling_roots") { }

    struct at_oakheart_strangling_rootsAI : AreaTriggerAI
    {
        at_oakheart_strangling_rootsAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    caster->CastSpell(unit, SPELL_STRANGLING_ROOTS_AURA, false);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_oakheart_strangling_rootsAI(areatrigger);
    }
};

// Strangling Roots
// NPC ID - 100991
class npc_dt_strangling_roots : public CreatureScript
{
public:
    npc_dt_strangling_roots() : CreatureScript("npc_dt_strangling_roots") {}

    class npc_dt_strangling_rootsAI : public ScriptedAI
    {
    public:

        npc_dt_strangling_rootsAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->CastSpell(me, SPELL_STRANGLING_ROOTS_AT, false);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dt_strangling_rootsAI(creature);
    }
};

/*

    Crushing Grip

*/



void AddSC_boss_oakheart()
{
    new at_oakheart_strangling_roots();

    new boss_oakheart();

    new npc_dt_strangling_roots();

    new spell_oakheart_strangling_roots_target();
    new spell_oakheart_strangling_roots_summon();
}
