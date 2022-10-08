/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_SHADE_OF_XAVIUS_VISUAL = 31059,

    //Festering Rip
    SPELL_FR_TARGET         = 200182,  //Targets a random player within melee range

    //Feed on the Weak
    SPELL_FOTW_TARGET       = 200238,  //Target a random non-tank player
    //     214224  //Mythic+ ?
    //     214229  //Mythic+ ?

    //Nightmare Bolt
    SPELL_NB_TARGET         = 204808,  //Targets a random player
    SPELL_NB_DAMAGE         = 200185,
    //225899 ?

    //Waking Nightmare
    SPELL_WN_TARGET_AT      = 200243,  //Targets a random player
    //Growing Paranoia
    SPELL_GP_TARGET_AT      = 200289,  //Targets a random player
    //Overwhelming Terror
    SPELL_OT_TARGET         = 200329,  //Targets a random player
    //Induced Paranoia
    SPELL_IP_TARGET         = 200359,  //Targets a random player

    //Apocalyptic Nightmare
    SPELL_AN_TARGET         = 200050,  //Cast after reaching 50% health
    SPELL_AN_TRIGGERMISSILE = 200067,
    SPELL_AN_MISSILE        = 200111,
    SPELL_AN_DAMAGE         = 204502,
    SPELL_AN_TRIGGERMISSILE_1 = 221267, //ocd trigger much ?
    SPELL_AN_MISSILE_1      = 221268
};

enum Events
{
    EVENT_FESTERING_RIP     = 1,
    EVENT_FEED_ON_THE_WEAK  = 2,
    EVENT_NIGHTMARE_BOLT    = 3,
    EVENT_INDUCED_PARANOIA  = 4
};

enum Talks
{
    SAY_PULL        = 0,
    SAY_90PCT       = 1,
    SAY_15PCT       = 2,
    SAY_DIE         = 3,
};

class boss_shade_of_xavius : public CreatureScript
{
public:
    boss_shade_of_xavius() : CreatureScript("boss_shade_of_xavius") { }

    struct boss_shade_of_xaviusAI : public BossAI
    {
        boss_shade_of_xaviusAI(Creature* creature) : BossAI(creature, DATA_SHADE_OF_XAVIUS)
        {
            hp90 = false;
            hp15 = false;
        }

        void Reset() override
        {
            _Reset();
            events.ScheduleEvent(EVENT_NIGHTMARE_BOLT, urand(17000, 25000));
            events.ScheduleEvent(EVENT_FEED_ON_THE_WEAK, urand(15000, 20000));
            events.ScheduleEvent(EVENT_FESTERING_RIP, urand(17000, 21000));
            events.ScheduleEvent(EVENT_INDUCED_PARANOIA, urand(18000, 28000));

            me->CastSpell(me, SPELL_SHADE_OF_XAVIUS_VISUAL, true);

            hp90 = false;
            hp15 = false;
            hp50 = false;
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            instance->SetBossState(DATA_SHADE_OF_XAVIUS, FAIL);

            me->CastSpell(me, SPELL_SHADE_OF_XAVIUS_VISUAL, true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
            DoZoneInCombat();

            events.ScheduleEvent(EVENT_NIGHTMARE_BOLT, urand(17000, 25000));
            events.ScheduleEvent(EVENT_FEED_ON_THE_WEAK, urand(15000, 20000));
            events.ScheduleEvent(EVENT_FESTERING_RIP, urand(17000, 21000));
            events.ScheduleEvent(EVENT_INDUCED_PARANOIA, urand(18000, 28000));

            Talk(SAY_PULL);
            instance->SetBossState(DATA_SHADE_OF_XAVIUS, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            Talk(SAY_DIE);
            instance->SetBossState(DATA_SHADE_OF_XAVIUS, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (!hp90 && HealthBelowPct(90))
            {
                Talk(SAY_90PCT);
                hp90 = true;
            }

            if (!hp15 && HealthBelowPct(15))
            {
                Talk(SAY_15PCT);
                hp15 = true;
            }

            if (!hp50 && HealthBelowPct(50))
            {
                me->CastSpell(me, SPELL_AN_TARGET, false);
                hp50 = true;
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_NIGHTMARE_BOLT:
                    {
                        events.ScheduleEvent(EVENT_NIGHTMARE_BOLT, urand(17000, 25000));
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0, true);
                        if (!target)
                            break;

                        me->CastSpell(target, SPELL_NB_TARGET, false);
                        break;
                    }
                    case EVENT_INDUCED_PARANOIA:
                    {
                        events.ScheduleEvent(EVENT_INDUCED_PARANOIA, urand(18000, 28000));

                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0, true);
                        if (!target)
                            break;

                        me->CastSpell(target, SPELL_IP_TARGET, false);
                        break;
                    }
                    case EVENT_FESTERING_RIP:
                    {
                        events.ScheduleEvent(EVENT_FESTERING_RIP, urand(17000, 21000));
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0, true);
                        if (!target)
                            break;

                        me->CastSpell(target, SPELL_FR_TARGET, false);
                        break;
                    }
                    case EVENT_FEED_ON_THE_WEAK:
                    {
                        events.ScheduleEvent(EVENT_FEED_ON_THE_WEAK, urand(15000, 20000));
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0, true);
                        if (!target)
                            break;

                        me->CastSpell(target, SPELL_FOTW_TARGET, false);
                        break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }
        private:
            bool hp90;
            bool hp15;
            bool hp50;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_shade_of_xaviusAI(creature);
    }
};

/*
    Nightmare Bolt
*/

//204808
class spell_shade_of_xavius_nightmare_bolt_target : public SpellScriptLoader
{
public:
    spell_shade_of_xavius_nightmare_bolt_target() : SpellScriptLoader("spell_shade_of_xavius_nightmare_bolt_target") { }

    class spell_shade_of_xavius_nightmare_bolt_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shade_of_xavius_nightmare_bolt_target_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_NB_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shade_of_xavius_nightmare_bolt_target_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shade_of_xavius_nightmare_bolt_target_SpellScript();
    }
};

/*
    Induced Paranoia
*/

//200359
class spell_shade_of_xavius_induced_paranoia_target : public SpellScriptLoader
{
public:
    spell_shade_of_xavius_induced_paranoia_target() : SpellScriptLoader("spell_shade_of_xavius_induced_paranoia_target") { }

    class spell_shade_of_xavius_induced_paranoia_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shade_of_xavius_induced_paranoia_target_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            target->CastSpell(target, SPELL_GP_TARGET_AT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shade_of_xavius_induced_paranoia_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shade_of_xavius_induced_paranoia_target_SpellScript();
    }
};

//AT ID : 5631
//Spell ID : 200289
class at_shade_of_xavius_growing_paranoia : public AreaTriggerEntityScript
{
public:
    at_shade_of_xavius_growing_paranoia() : AreaTriggerEntityScript("at_shade_of_xavius_growing_paranoia") { }

    struct at_oakheart_strangling_rootsAI : AreaTriggerAI
    {
        int32 timeInterval;
        at_oakheart_strangling_rootsAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 200;
        }

        void OnUpdate(uint32 p_Time) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            timeInterval += p_Time;
            if (timeInterval < 200)
                return;

            for (ObjectGuid guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (caster->IsFriendlyTo(unit))
                        caster->CastSpell(caster, SPELL_OT_TARGET, true);

            timeInterval -= 200;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_oakheart_strangling_rootsAI(areatrigger);
    }
};

/*
    Apocalyptic Nightmare
*/

//200050
class spell_shade_of_xavius_apocalyptic_nightmare : public SpellScriptLoader
{
public:
    spell_shade_of_xavius_apocalyptic_nightmare() : SpellScriptLoader("spell_shade_of_xavius_apocalyptic_nightmare") { }

    class spell_shade_of_xavius_apocalyptic_nightmare_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_shade_of_xavius_apocalyptic_nightmare_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 deltaX = urand(0, 150);
            int32 deltaY = urand(0, 150);

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, caster->GetPositionX() + deltaX - 75, caster->GetPositionY() + deltaY - 75, caster->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 2000))
            {
                tempSumm->SetSummonerGUID(caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);
                tempSumm->SetName(caster->GetName());
                caster->CastSpell(tempSumm, SPELL_AN_TRIGGERMISSILE, false);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_shade_of_xavius_apocalyptic_nightmare_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_shade_of_xavius_apocalyptic_nightmare_AuraScript();
    }
};

void AddSC_boss_shade_of_xavius()
{
    new at_shade_of_xavius_growing_paranoia();

    new boss_shade_of_xavius();

    new spell_shade_of_xavius_apocalyptic_nightmare();
    new spell_shade_of_xavius_induced_paranoia_target();
    new spell_shade_of_xavius_nightmare_bolt_target();
}
