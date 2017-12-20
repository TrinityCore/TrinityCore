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
    //Nightfall
    SPELL_NIGHTFALL_MISSILE = 198401,
    SPELL_NIGHTFALL_AT      = 198402,
    SPELL_NIGHTFALL_DAMAGE  = 198408,

    //Grievous Leap
    SPELL_GL_TARGET         = 196346, //Targets a non tank player (Healers/casters preferably)
    SPELL_GL_LEAP_1         = 196348,
    SPELL_GL_DAMAGE_1       = 196354,
    SPELL_GL_LEAP_2         = 198095,
    SPELL_GL_DAMAGE_2       = 198269,

    SPELL_GL_DOT            = 196376,  //Applied at each damaging spell.

    //Primal Rampage
    SPELL_PR_DAMAGE_1       = 198376,
    SPELL_PR_CHARGE         = 198379,
    SPELL_PR_CHARGE_DAMAGE  = 198386,
    SPELL_PR_MORPH          = 198360,
    SPELL_PR_END            = 198387,

    SPELL_CAT_FORM          = 212276,
    SPELL_RAY_PRESERVATION  = 197642,
    SPELL_SUICIDE           = 203620,
    SPELL_GREEN_SHIELD      = 203257,
};

enum Talks
{
    SAY_EVENT       = 0,
    SAY_PULL        = 1,
    SAY_65PCT       = 2,
    SAY_45PCT       = 3,
    SAY_DIE         = 4,

    SAY_DRUID       = 0,
};

enum Events
{
    // Intro
    EVENT_INTRO_GLAIDALIS_1     = 1,
    EVENT_INTRO_GLAIDALIS_2     = 2,
    EVENT_INTRO_GLAIDALIS_3     = 3,
    EVENT_INTRO_GLAIDALIS_4     = 4,
    EVENT_INTRO_GLAIDALIS_5     = 5,
    EVENT_INTRO_GLAIDALIS_6     = 6,
    EVENT_INTRO_GLAIDALIS_7     = 7,
    EVENT_INTRO_GLAIDALIS_8     = 8,
    EVENT_INTRO_GLAIDALIS_9     = 9,

    // Boss
    EVENT_NIGHTFALL             = 10,
    EVENT_GL_LEAP_1             = 11,
    EVENT_GL_LEAP_BACK          = 12,
    EVENT_PR                    = 13
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

Position const SummonPositions[8] =
{
    // Druidic Preserver
    { 2886.29f, 1949.78f, 189.938f, 3.68708f },
    { 2874.54f, 1970.38f, 189.809f, 2.80743f },
    { 2905.18f, 1984.34f, 189.992f, 0.87014f },
    { 2913.47f, 1968.30f, 189.707f, 0.06511f },

    // Perserver Ray Trigger
    { 2877.31f, 1940.80f, 191.888f, 4.40373f },
    { 2864.09f, 1971.48f, 190.289f, 4.56393f },
    { 2915.67f, 1994.29f, 189.907f, 5.55120f },
    { 2929.72f, 1967.43f, 189.693f, 1.61005f },
};

#define GOSSIP_GLAIDALIS_INTRO "Intro pls biatch !"

class boss_archdruid_glaidalis : public CreatureScript
{
public:
    boss_archdruid_glaidalis() : CreatureScript("boss_archdruid_glaidalis") { }

    struct boss_archdruid_glaidalisAI : public BossAI
    {
        boss_archdruid_glaidalisAI(Creature* creature) : BossAI(creature, DATA_ARCHDRUID_GLAIDALIS)
        {
            hp65 = false;
            hp45 = false;
        }

        Phases phase;

        void Initialize()
        {
            phase = PHASE_NORMAL;
        }

        void Reset() override
        {
            _Reset();
            events.ScheduleEvent(EVENT_NIGHTFALL, 15000);
            events.ScheduleEvent(EVENT_PR, urand(12800, 14100));
            events.ScheduleEvent(EVENT_GL_LEAP_1, urand(20000, 22200));

            phase = PHASE_NORMAL;
            hp65 = false;
            hp45 = false;
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            instance->SetBossState(DATA_ARCHDRUID_GLAIDALIS, FAIL);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->setActive(true);
            DoZoneInCombat();

            events.ScheduleEvent(EVENT_NIGHTFALL, 15000);
            events.ScheduleEvent(EVENT_PR, urand(12800, 14100));
            events.ScheduleEvent(EVENT_GL_LEAP_1, urand(21000, 23200));

            Talk(SAY_PULL);
            instance->SetBossState(DATA_ARCHDRUID_GLAIDALIS, IN_PROGRESS);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();

            Talk(SAY_DIE);

            instance->SetBossState(DATA_ARCHDRUID_GLAIDALIS, DONE);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_GLAIDALIS_INTRO)
            {
                phase = PHASE_INTRO;
                instance->SetBossState(DATA_ARCHDRUID_GLAIDALIS, SPECIAL);
                events.Reset();
                events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_1, 5000);
            }
        }

        void MovementInform(uint32 type, uint32 pointId) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (pointId == 0)
            {
                me->SetFacingTo(0.441398f);
                events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_2, 1000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (phase == PHASE_INTRO)
            {
                events.Update(diff);

                switch (events.ExecuteEvent())
                {
                    case EVENT_INTRO_GLAIDALIS_1:
                        if (Creature* druidSum1 = me->SummonCreature(NPC_DRUIDIC_PRESERVER, SummonPositions[0], TEMPSUMMON_TIMED_DESPAWN, 25000))
                            druidGUID1 = druidSum1->GetGUID();
                        if (Creature* druidSum2 = me->SummonCreature(NPC_DRUIDIC_PRESERVER, SummonPositions[1], TEMPSUMMON_TIMED_DESPAWN, 25000))
                            druidGUID2 = druidSum2->GetGUID();
                        if (Creature* druidSum3 = me->SummonCreature(NPC_DRUIDIC_PRESERVER, SummonPositions[2], TEMPSUMMON_TIMED_DESPAWN, 25000))
                            druidGUID3 = druidSum3->GetGUID();
                        if (Creature* druidSum4 = me->SummonCreature(NPC_DRUIDIC_PRESERVER, SummonPositions[3], TEMPSUMMON_TIMED_DESPAWN, 25000))
                            druidGUID4 = druidSum4->GetGUID();
                        me->GetMotionMaster()->MovePoint(0, 2876.5976f, 1958.9278f, 189.7037f);
                        break;

                    case EVENT_INTRO_GLAIDALIS_2:
                        Talk(SAY_EVENT);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_3, 1000);
                        break;

                    case EVENT_INTRO_GLAIDALIS_3:
                        if (Creature* druid1 = ObjectAccessor::GetCreature(*me, druidGUID1))
                            if (Creature* triggerSum1 = me->SummonCreature(NPC_TRIGGER_PERSERVER, SummonPositions[4], TEMPSUMMON_TIMED_DESPAWN, 25000))
                                druid1->CastSpell(triggerSum1, SPELL_RAY_PRESERVATION, false);
                        if (Creature* druid2 = ObjectAccessor::GetCreature(*me, druidGUID2))
                            if (Creature* triggerSum2 = me->SummonCreature(NPC_TRIGGER_PERSERVER, SummonPositions[5], TEMPSUMMON_TIMED_DESPAWN, 25000))
                                druid2->CastSpell(triggerSum2, SPELL_RAY_PRESERVATION, false);
                        if (Creature* druid3 = ObjectAccessor::GetCreature(*me, druidGUID3))
                            if (Creature* triggerSum3 = me->SummonCreature(NPC_TRIGGER_PERSERVER, SummonPositions[6], TEMPSUMMON_TIMED_DESPAWN, 25000))
                                druid3->CastSpell(triggerSum3, SPELL_RAY_PRESERVATION, false);
                        if (Creature* druid4 = ObjectAccessor::GetCreature(*me, druidGUID4))
                            if (Creature* triggerSum4 = me->SummonCreature(NPC_TRIGGER_PERSERVER, SummonPositions[7], TEMPSUMMON_TIMED_DESPAWN, 25000))
                            {
                                druid4->CastSpell(triggerSum4, SPELL_RAY_PRESERVATION, false);
                                druid4->AI()->Talk(SAY_DRUID);
                            }
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_4, 5000);
                        break;

                    case EVENT_INTRO_GLAIDALIS_4:
                        me->CastSpell(me, SPELL_CAT_FORM, false);
                        me->SetObjectScale(1.8f);
                        if (Creature* druid1 = ObjectAccessor::GetCreature(*me, druidGUID1))
                        {
                            me->GetMotionMaster()->MoveJump(druid1->GetPositionX(), druid1->GetPositionY(), druid1->GetPositionZ(), druid1->GetOrientation(), 20.0f, 10.0f);
                            druid1->CastSpell(druid1, SPELL_SUICIDE, true);
                        }
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_5, 1500);
                        break;

                    case EVENT_INTRO_GLAIDALIS_5:
                        if (Creature* druid2 = ObjectAccessor::GetCreature(*me, druidGUID2))
                        {
                            me->GetMotionMaster()->MoveJump(druid2->GetPositionX(), druid2->GetPositionY(), druid2->GetPositionZ(), druid2->GetOrientation(), 20.0f, 10.0f);
                            druid2->CastSpell(druid2, SPELL_SUICIDE, true);
                        }
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_6, 1800);
                        break;

                    case EVENT_INTRO_GLAIDALIS_6:
                        if (Creature* druid3 = ObjectAccessor::GetCreature(*me, druidGUID3))
                        {
                            me->GetMotionMaster()->MoveJump(druid3->GetPositionX(), druid3->GetPositionY(), druid3->GetPositionZ(), druid3->GetOrientation(), 20.0f, 10.0f);
                            druid3->CastSpell(druid3, SPELL_SUICIDE, true);
                        }
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_7, 1800);
                        break;

                    case EVENT_INTRO_GLAIDALIS_7:
                        if (Creature* druid4 = ObjectAccessor::GetCreature(*me, druidGUID4))
                        {
                            me->GetMotionMaster()->MoveJump(druid4->GetPositionX(), druid4->GetPositionY(), druid4->GetPositionZ(), druid4->GetOrientation(), 20.0f, 10.0f);
                            druid4->CastSpell(druid4, SPELL_SUICIDE, true);
                        }
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_8, 1800);
                        break;

                    case EVENT_INTRO_GLAIDALIS_8:
                        if (Creature* triggerShield = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_SHIELD_TRIGGER)))
                            triggerShield->RemoveAurasDueToSpell(SPELL_GREEN_SHIELD);
                        if (GameObject* collisionEvent = me->GetMap()->GetGameObject(instance->GetGuidData(GO_EVENT_GLAIDALIS)))
                            collisionEvent->SetGoState(GO_STATE_ACTIVE);
                        me->GetMotionMaster()->MoveJump(2876.5976f, 1958.9278f, 189.7037f, 0.441398f, 20.0f, 20.0f);
                        events.ScheduleEvent(EVENT_INTRO_GLAIDALIS_9, 2000);
                        break;

                    case EVENT_INTRO_GLAIDALIS_9:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                        me->RemoveAurasDueToSpell(SPELL_CAT_FORM);
                        me->SetObjectScale(1.0f);
                        me->SetHomePosition(2876.5976f, 1958.9278f, 189.7037f, 0.441398f);
                        me->SetFacingTo(0.441398f);
                        phase = PHASE_NORMAL;
                        break;
                }
            }

            if (phase == PHASE_NORMAL)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (!hp65 && HealthBelowPct(65))
                {
                    Talk(SAY_65PCT);
                    hp65 = true;
                }

                if (!hp45 && HealthBelowPct(45))
                {
                    Talk(SAY_45PCT);
                    hp45 = true;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_NIGHTFALL:
                        {
                            events.ScheduleEvent(EVENT_NIGHTFALL, urand(14500, 17500));
                            Unit* target1 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true);
                            Unit* target2 = SelectTarget(SELECT_TARGET_RANDOM, 0.0, 0.0, true);
                            if (!target1)
                                return;

                            me->CastSpell(target1, SPELL_NIGHTFALL_MISSILE, false);

                            if (!target2)
                                return;

                            me->CastSpell(target2, SPELL_NIGHTFALL_MISSILE, false);

                            break;
                        }
                        case EVENT_GL_LEAP_1:
                        {
                            events.ScheduleEvent(EVENT_GL_LEAP_1, urand(20200, 22200));
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me));
                            if (!target)
                                return;

                            me->CastSpell(target, SPELL_GL_LEAP_1);
                            break;
                        }
                        case EVENT_PR:
                        {
                            me->CastSpell(me, SPELL_PR_MORPH, true);
                            DoCastAOE(SPELL_PR_DAMAGE_1);
                            me->CastSpell(me, SPELL_PR_CHARGE, false);
                            events.ScheduleEvent(EVENT_PR, urand(15800, 20100));
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
        }

        private:
            ObjectGuid druidGUID1;
            ObjectGuid druidGUID2;
            ObjectGuid druidGUID3;
            ObjectGuid druidGUID4;
            bool hp65;
            bool hp45;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_archdruid_glaidalisAI(creature);
    }
};

//At : 5445
//Spell : 198402
class at_archdruid_glaidalis_nightfall : public AreaTriggerEntityScript
{
public:
    at_archdruid_glaidalis_nightfall() : AreaTriggerEntityScript("at_archdruid_glaidalis_nightfall") { }

    struct at_archdruid_glaidalis_nightfallAI : AreaTriggerAI
    {
        at_archdruid_glaidalis_nightfallAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            at->SetUInt32Value(AREATRIGGER_DECAL_PROPERTIES_ID, 34);

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        unit->CastSpell(unit, SPELL_NIGHTFALL_DAMAGE, true);
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (unit->GetTypeId() == TYPEID_PLAYER)
                unit->CastSpell(unit, SPELL_NIGHTFALL_DAMAGE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (unit->HasAura(SPELL_NIGHTFALL_DAMAGE))
                unit->RemoveAura(SPELL_NIGHTFALL_DAMAGE);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->HasAura(SPELL_NIGHTFALL_DAMAGE))
                        unit->RemoveAura(SPELL_NIGHTFALL_DAMAGE);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_archdruid_glaidalis_nightfallAI(areatrigger);
    }
};

/*

Grevious leap

*/

//196346
class spell_archdruid_glaidalis_grevious_leap_target : public SpellScriptLoader
{
public:
    spell_archdruid_glaidalis_grevious_leap_target() : SpellScriptLoader("spell_archdruid_glaidalis_grevious_leap_target") { }

    class spell_archdruid_glaidalis_grevious_leap_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_archdruid_glaidalis_grevious_leap_target_SpellScript);

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, GetSpellInfo()->GetEffect(effIndex)->BasePoints, false);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_archdruid_glaidalis_grevious_leap_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_archdruid_glaidalis_grevious_leap_target_SpellScript();
    }
};

//196348
class spell_archdruid_glaidalis_grevious_leap_first : public SpellScriptLoader
{
public:
    spell_archdruid_glaidalis_grevious_leap_first() : SpellScriptLoader("spell_archdruid_glaidalis_grevious_leap_first") { }

    class spell_archdruid_glaidalis_grevious_leap_first_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_archdruid_glaidalis_grevious_leap_first_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (!caster || !caster->GetAI())
                return;

            Unit* target = caster->GetAI()->SelectTarget(SELECT_TARGET_TOPAGGRO);
            if (!target)
                return;

            caster->CastSpell(target, SPELL_GL_LEAP_2, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_archdruid_glaidalis_grevious_leap_first_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_archdruid_glaidalis_grevious_leap_first_SpellScript();
    }
};

//196354
class spell_archdruid_glaidalis_grevious_leap_damage : public SpellScriptLoader
{
public:
    spell_archdruid_glaidalis_grevious_leap_damage() : SpellScriptLoader("spell_archdruid_glaidalis_grevious_leap_damage") { }

    class spell_archdruid_glaidalis_grevious_leap_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_archdruid_glaidalis_grevious_leap_damage_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_GL_DOT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_archdruid_glaidalis_grevious_leap_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_archdruid_glaidalis_grevious_leap_damage_SpellScript();
    }
};

/*

Primordial Rage

*/

//198379
class spell_archdruid_glaidalis_primal_rage_charge : public SpellScriptLoader
{
public:
    spell_archdruid_glaidalis_primal_rage_charge() : SpellScriptLoader("spell_archdruid_glaidalis_primal_rage_charge") { }

    class spell_archdruid_glaidalis_primal_rage_charge_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_archdruid_glaidalis_primal_rage_charge_AuraScript);

        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_PR_END, true);
        }

        void Register() override
        {
            OnEffectRemove += AuraEffectRemoveFn(spell_archdruid_glaidalis_primal_rage_charge_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_archdruid_glaidalis_primal_rage_charge_AuraScript();
    }
};

//AT : 5443
//Spell : 198379
class at_archdruid_glaidalis_primal_rage : public AreaTriggerEntityScript
{
public:
    at_archdruid_glaidalis_primal_rage() : AreaTriggerEntityScript("at_archdruid_glaidalis_primal_rage") { }

    struct at_archdruid_glaidalis_primal_rageAI : AreaTriggerAI
    {
        at_archdruid_glaidalis_primal_rageAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            caster->CastSpell(unit, SPELL_PR_DAMAGE_1, true);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_archdruid_glaidalis_primal_rageAI(areatrigger);
    }
};

class at_archdruid_glaidalis_event : public AreaTriggerScript
{
public:
    at_archdruid_glaidalis_event() : AreaTriggerScript("at_archdruid_glaidalis_event") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool /*entered*/) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return false;

        if (instance->GetBossState(DATA_ARCHDRUID_GLAIDALIS) != SPECIAL && instance->GetBossState(DATA_ARCHDRUID_GLAIDALIS) != DONE && instance->GetBossState(DATA_ARCHDRUID_GLAIDALIS) != FAIL && instance->GetBossState(DATA_ARCHDRUID_GLAIDALIS) != IN_PROGRESS)
            if (Creature* archdruidGlaidalis = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_ARCHDRUID_GLAIDALIS)))
            {
                archdruidGlaidalis->AI()->DoAction(ACTION_GLAIDALIS_INTRO);
                return true;
            }

        return false;
    }
};

void AddSC_boss_archdruid_glaidalis()
{
    new at_archdruid_glaidalis_nightfall();
    new at_archdruid_glaidalis_primal_rage();
    new at_archdruid_glaidalis_event();

    new boss_archdruid_glaidalis();

    new spell_archdruid_glaidalis_grevious_leap_damage();
    new spell_archdruid_glaidalis_grevious_leap_first();
    new spell_archdruid_glaidalis_grevious_leap_target();
    new spell_archdruid_glaidalis_primal_rage_charge();
}
