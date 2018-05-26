/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "GridNotifiers.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum Spells
{
    SPELL_TAIL_LASH                     = 212836,
    //Electrical Storm
    SPELL_ELECTRICAL_STORM_AT           = 212885,
    SPELL_ELECTRICAL_STORM_DAMAGE       = 212884,
    SPELL_ELECTRICAL_STORM_VISUAL       = 198900,
    SPELL_ELECTRICAL_STORM_TARGET       = 212867,
    //Static Charge
    //What to use to summon static orb : caster->SummonCreature(entry, pos, summonType, despawnTime);
    SPELL_STATIC_CHARGE_SUMMON          = 212889,
    SPELL_STATIC_CHARGE_TARGETED        = 212943, //Lightning rod, means you're a target
    SPELL_STATIC_CHARGE_EXPLOSION       = 212948,
    SPELL_STATIC_CHARGE                 = 212887,
    //Crackling jolt
    SPELL_CRACKLING_JOLT_TARGET_PICKER  = 212837,
    SPELL_CRACKLING_JOLT_MISSILE        = 212838,
    SPELL_CRACKLING_JOLT_DAMAGE         = 212841,

    SPELL_STORM_BREATH                  = 212852
};

enum NPCs
{
    NPC_STATIC_ORB = 107353
};

enum Phases
{
    PHASE_NORMAL    = 0,//When the combat starts
    PHASE_80PCT     = 1, //When Nithogg is under 80
    PHASE_60PCT     = 2, //blabla 60
    PHASE_40PCT     = 3, //blabla 40
    PHASE_20PCT     = 4 //blabla 20
};

enum Events
{
    EVENT_CRACKLING_JOLT    = 1,  //This event must be called every 20 percent hp
    EVENT_TAIL_LASH         = 2,  //Watched a video where people were always behind it : used every 7-8 sec
    EVENT_ELECTRICAL_STORM  = 3,  //About every 30 seconds
    EVENT_STATIC_CHARGE     = 4,  //Same as before
    EVENT_STORM_BREATH      = 5,   //Found on video : First at 10sec, then it's every 20 to 25 sec
};

struct boss_nithogg : public WorldBossAI
{
    boss_nithogg(Creature* creature) : WorldBossAI(creature) { }

    void Reset() override
    {
        _Reset();
        me->SetFullHealth();
        me->GetMotionMaster()->MoveTargetedHome();
        events.SetPhase(PHASE_NORMAL);
        events.Reset();
    }

    void EnterCombat(Unit* who) override
    {
        if (!who)
            return;
        me->setActive(true);
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_TAIL_LASH, 7 * IN_MILLISECONDS);
        events.ScheduleEvent(EVENT_CRACKLING_JOLT, 12000);
        events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 20000);
        events.ScheduleEvent(EVENT_STATIC_CHARGE, 15000);
        events.ScheduleEvent(EVENT_STORM_BREATH, 7000);

        me->SetFullHealth();
        events.SetPhase(PHASE_NORMAL);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Reset();
    }

    void DamageTaken(Unit* /*unit*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(80, damage))
        {
            events.SetPhase(PHASE_80PCT);
            //events.ScheduleEvent(EVENT_CRACKLING_JOLT, 1000);
        }
        else if (me->HealthBelowPctDamaged(60, damage))
        {
            events.SetPhase(PHASE_60PCT);
            DoCast(me, SPELL_CRACKLING_JOLT_TARGET_PICKER);
        }
        else if (me->HealthBelowPctDamaged(40, damage))
        {
            events.SetPhase(PHASE_40PCT);
            DoCast(me, SPELL_CRACKLING_JOLT_TARGET_PICKER);
        }
        else if (me->HealthBelowPctDamaged(20, damage))
        {
            events.SetPhase(PHASE_20PCT);
            DoCast(me, SPELL_CRACKLING_JOLT_TARGET_PICKER);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        //This is a safecheck. If Nithogg ever happens to not plan any attack, his cycle starts.
        if(me->IsInCombat() && events.Empty())
        {
            events.ScheduleEvent(EVENT_TAIL_LASH, 7 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_CRACKLING_JOLT, 12000);
            events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 20000);
            events.ScheduleEvent(EVENT_STATIC_CHARGE, 15000);
            events.ScheduleEvent(EVENT_STORM_BREATH, 7000);
        }

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TAIL_LASH:
                {
                    for (auto itr : me->getThreatManager().getThreatList())
                    {
                        if (!itr->getTarget())
                            continue;

                        if (me->isInBack(itr->getTarget(), float(M_PI) / 6))
                        {
                            DoCastAOE(SPELL_TAIL_LASH);
                            break;
                        }
                    }
                    events.ScheduleEvent(EVENT_TAIL_LASH, urand(7, 8) * IN_MILLISECONDS);
                    break;
                }
                case EVENT_CRACKLING_JOLT:
                {
                    //DoCast(me, SPELL_CRACKLING_JOLT_TARGET_PICKER);
                    //What I do here is make the cast happen from higher up, making the missiles travel more than they do at the moment.
                    if (Creature* tempSumm = me->SummonCreature(WORLD_TRIGGER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 14, 0, TEMPSUMMON_TIMED_DESPAWN, 10000))
                    {
                        tempSumm->setFaction(me->getFaction());
                        tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, me->GetGUID());
                        PhasingHandler::InheritPhaseShift(tempSumm, me);
                        tempSumm->SetLevel(me->getLevel());
                        tempSumm->SetName(me->GetName());
                        tempSumm->CastSpell(tempSumm, SPELL_CRACKLING_JOLT_TARGET_PICKER, true, nullptr, nullptr, me->GetGUID()); //If any of you knows how to make the game think Nithogg launched the spell, please tell me
                    }
                    events.ScheduleEvent(EVENT_CRACKLING_JOLT, urand(10000, 15000));
                    break;
                }
                case EVENT_ELECTRICAL_STORM:
                {
                    DoCastAOE(SPELL_ELECTRICAL_STORM_TARGET);
                    events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 30500);
                    break;
                }
                case EVENT_STORM_BREATH:
                {
                    DoCastVictim(SPELL_STORM_BREATH);
                    events.ScheduleEvent(EVENT_STORM_BREATH, 23100);
                    break;
                }
                case EVENT_STATIC_CHARGE:
                {
                    Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                    DoCast(target, SPELL_STATIC_CHARGE);
                    events.ScheduleEvent(EVENT_STATIC_CHARGE, 40200);
                    break;
                }
            }
        }

        DoMeleeAttackIfReady();
    }
};

//212867
class spell_nithogg_electrical_storm_target : public SpellScriptLoader
{
public:
    spell_nithogg_electrical_storm_target() : SpellScriptLoader("spell_nithogg_electrical_storm_target") { }

    class spell_nithogg_electrical_storm_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nithogg_electrical_storm_target_SpellScript);

        bool Validate(SpellInfo const* info) override
        {
            if (!sSpellMgr->GetSpellInfo(info->GetEffect(EFFECT_0)->BasePoints))
                return false;
            return true;
        }

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            Unit* target = GetHitUnit();
            Unit* caster = GetCaster();
            if (!target || !caster)
                return;

            caster->CastSpell(target, GetSpellInfo()->GetEffect(effIndex)->BasePoints, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_nithogg_electrical_storm_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nithogg_electrical_storm_target_SpellScript();
    }
};

//NPC ID : 107338
//Summoned by : 212877
class npc_nithogg_electrical_storm : public CreatureScript
{
public:
    npc_nithogg_electrical_storm() : CreatureScript("npc_nithogg_electrical_storm") {}

    struct npc_nithogg_electrical_storm_AI : public ScriptedAI
    {
        npc_nithogg_electrical_storm_AI(Creature* creature) : ScriptedAI(creature) {}

        uint32 visualTimer = 0;
        uint32 visualTick = 200;

        enum SpellData
        {
            SPELL_TO_CAST = SPELL_ELECTRICAL_STORM_AT
        };

        void Reset() override
        {
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL); //TODO : Change this to a spline once those work/I know how to use them.
            ApplyBuff();
        }

        void UpdateAI(uint32 uiDiff) override
        {
            visualTimer += uiDiff;
            if (visualTimer < visualTick)
                return;


            me->CastSpell(me, SPELL_ELECTRICAL_STORM_VISUAL, true);
            visualTimer = 0;
            visualTick = urand(250, 550);
        }

        void ApplyBuff()
        {
            if (!me)
                return;

            me->CastSpell(me, SPELL_TO_CAST, true); //Applies AreaTrigger aura
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nithogg_electrical_storm_AI(creature);
    }
};

// AT    ID : 7053
// Spell ID : 212885
class at_nithogg_electrical_storm : public AreaTriggerEntityScript
{
public:
    at_nithogg_electrical_storm() : AreaTriggerEntityScript("at_nithogg_electrical_storm") { }

    struct at_nithogg_electrical_stormAI : AreaTriggerAI
    {
        int32 timeInterval;
        at_nithogg_electrical_stormAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 0;
        }

        void OnUpdate(uint32 diff) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            timeInterval += diff;
            if (timeInterval < 2000)
                return;

            caster->RemoveAura(SPELL_ELECTRICAL_STORM_DAMAGE);
            caster->CastSpell(caster, SPELL_ELECTRICAL_STORM_DAMAGE, true);

            timeInterval -= 2000;
        }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster(); //Caster should be the electrical storm NPC

            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_ELECTRICAL_STORM_DAMAGE, true); //Applies an aura that damages everything
        }

        void OnUnitExit(Unit* unit) override
        {
            if (!unit)
                return;

            if (unit->HasAura(SPELL_ELECTRICAL_STORM_DAMAGE))
                unit->RemoveAura(SPELL_ELECTRICAL_STORM_DAMAGE);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!at || !caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->HasAura(SPELL_ELECTRICAL_STORM_DAMAGE))
                        unit->RemoveAura(SPELL_ELECTRICAL_STORM_DAMAGE);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_nithogg_electrical_stormAI(areatrigger);
    }
};

//212889 - Static Charge
class spell_nithogg_static_charge_summon : public SpellScriptLoader
{
public:
    spell_nithogg_static_charge_summon() : SpellScriptLoader("spell_nithogg_static_charge_summon") { }

    class spell_nithogg_static_charge_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nithogg_static_charge_summon_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            Unit* summoned = caster->SummonCreature(NPC_STATIC_ORB, *caster, TEMPSUMMON_TIMED_DESPAWN, 12 * IN_MILLISECONDS);
            summoned->SetTarget(target->GetGUID());
            summoned->CastSpell(target, SPELL_STATIC_CHARGE_TARGETED, true);
            summoned->AddUnitState(UNIT_STATE_FOLLOW);
            summoned->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_nithogg_static_charge_summon_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nithogg_static_charge_summon_SpellScript();
    }
};

//212837
class spell_nithogg_crackling_jolt_target : public SpellScriptLoader
{
public:
    spell_nithogg_crackling_jolt_target() : SpellScriptLoader("spell_nithogg_crackling_jolt_target") { }

    class spell_nithogg_crackling_jolt_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nithogg_crackling_jolt_target_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            if (!target)
                return;

            if (Unit* caster = GetCaster())
                caster->CastSpell(target, SPELL_CRACKLING_JOLT_MISSILE, false);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_nithogg_crackling_jolt_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nithogg_crackling_jolt_target_SpellScript();
    }
};

//212841
class spell_nithogg_crackling_jolt_damage : public SpellScriptLoader
{
public:
    spell_nithogg_crackling_jolt_damage() : SpellScriptLoader("spell_nithogg_crackling_jolt_damage") { }

    class spell_nithogg_crackling_jolt_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nithogg_crackling_jolt_damage_SpellScript);

        void HandleLaunch(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();
            if(!caster || !target)
                return;

            if(GetTriggeringSpell() == sSpellMgr->GetSpellInfo(SPELL_CRACKLING_JOLT_MISSILE))
            {
                PreventHitEffect(effIndex);
                ObjectGuid targetGuid = target->GetGUID();
                caster->GetScheduler().Schedule(2500ms, [targetGuid](TaskContext context)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*GetContextUnit(), targetGuid))
                        GetContextUnit()->CastSpell(target, SPELL_CRACKLING_JOLT_DAMAGE, false);
                });
            }
        }

        void Register() override
        {
            //OnEffectLaunchTarget += SpellEffectFn(spell_nithogg_crackling_jolt_damage_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nithogg_crackling_jolt_damage_SpellScript();
    }
};

//107353
class npc_nithogg_static_orb : public CreatureScript
{
public:
    npc_nithogg_static_orb() : CreatureScript("npc_nithogg_static_orb") {}

    struct npc_nithogg_static_orb_AI : public ScriptedAI
    {
        uint32 timer;

        npc_nithogg_static_orb_AI(Creature* creature) : ScriptedAI(creature)
        {
            timer = 0;
        }

        void Reset() override
        {
            me->SetSpeedRate(MOVE_RUN, 0.7f);
            me->SetSpeedRate(MOVE_WALK, 0.7f);
            me->SetReactState(REACT_PASSIVE);
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);  flags are now in db
        }

        void UpdateAI(uint32 uiDiff) override
        {
            timer += uiDiff;

            if (!me)
                return;

            if (!me->GetTarget())
                return;

            if (timer < 300)
                return;

            Unit* unit = ObjectAccessor::GetUnit(*me, me->GetTarget());
            if (!unit)
                return;

            if (me->IsInDist(unit, 4.0f))
            {
                me->SetReactState(REACT_AGGRESSIVE);
                //me->CastSpell(unit, SPELL_STATIC_CHARGE_EXPLOSION, true);
                DoCastAOE(SPELL_STATIC_CHARGE_EXPLOSION);
                unit->RemoveAura(SPELL_STATIC_CHARGE_TARGETED);
                me->KillSelf();
            }

            timer = 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_nithogg_static_orb_AI(creature);
    }
};

//212836
class spell_nithogg_tail_lash : public SpellScriptLoader
{
public:
    spell_nithogg_tail_lash() : SpellScriptLoader("spell_nithogg_tail_lash") { }

    class spell_nithogg_tail_lash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_nithogg_tail_lash_SpellScript);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            if (Unit* caster = GetCaster())
            {
                p_Targets.clear();

                std::list<Unit*> targets;
                caster->GetAttackableUnitListInRange(targets, 30.0f);
                for (auto itr : targets)
                {
                    if (caster->IsValidAttackTarget(itr))
                        if (caster->isInBack(itr, float(M_PI) / 6))
                            p_Targets.push_back(itr);
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nithogg_tail_lash_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nithogg_tail_lash_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_24);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_nithogg_tail_lash_SpellScript();
    }
};

void AddSC_boss_nithogg()
{
    //ATs
    new at_nithogg_electrical_storm();

    //NPCs
    RegisterCreatureAI(boss_nithogg);
    new npc_nithogg_electrical_storm();
    new npc_nithogg_static_orb();

    //Spells
    new spell_nithogg_static_charge_summon();
    new spell_nithogg_crackling_jolt_target();
    new spell_nithogg_crackling_jolt_damage();
    new spell_nithogg_electrical_storm_target();
    new spell_nithogg_tail_lash();
}
