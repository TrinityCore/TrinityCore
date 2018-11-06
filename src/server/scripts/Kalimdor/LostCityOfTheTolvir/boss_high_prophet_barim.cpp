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

#include "ScriptMgr.h"
#include "lost_city_of_the_tolvir.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{
    // High Prophet Barim
    SPELL_FIFTY_LASHINGS                = 82506,
    SPELL_PLAGUE_OF_AGES                = 82622,
    SPELL_HEAVENS_FURY                  = 81939,
    SPELL_REPENTANCE                    = 82320,
    SPELL_REPENTANCE_PULL               = 82168,
    SPELL_REPENTANCE_STUN               = 81947,
    SPELL_REPENTANCE_KNOCKBACK          = 82012,
    SPELL_REPENTANCE_SCREEN_EFFECT      = 82139,
    SPELL_WAIL_OF_DARKNESS_DUMMY        = 82195,
    SPELL_BLAZE_OF_THE_HEAVENS          = 91181,

    // Repentance
    SPELL_REPENTANCE_SCRIPT_1           = 82009,
    SPELL_REPENTANCE_SCRIPT_2           = 81960,
    SPELL_REPENTANCE_PULL_BACK          = 82430,

    // Harbinger of Darkness
    SPELL_BIRTH                         = 26586,
    SPELL_WAIL_OF_DARKNESS              = 82533,
    SPELL_SOUL_SEVER                    = 82255,
    SPELL_WAIL_OF_DARKNESS_END          = 82425,

    // Blaze of the Heavens
    SPELL_BLAZE_OF_THE_HEAVENS_TRIGGER  = 95248,
    SPELL_BLAZE_OF_THE_HEAVENS_FLAME    = 91189,
    SPELL_TRANSFORM                     = 95276,

    // Soul Fragment
    SPELL_SOUL_SEVER_SCRIPT             = 82220,
    SPELL_SOUL_FRAGMENT_DUMMY           = 82224,
    SPELL_MERGED_SOULS                  = 82263,
};

enum Events
{
    // High Prophet Barim
    EVENT_FIFTY_LASHINGS = 1,
    EVENT_PLAGUE_OF_AGES,
    EVENT_HEAVENS_FURY,
    EVENT_REPENTANCE_PULL,
    EVENT_REPENTANCE_STUN,
    EVENT_REPENTANCE_KNOCKBACK,
    EVENT_BLAZE_OF_THE_HEAVENS,
    EVENT_COUNT_PLAYERS,

    // Repentance
    EVENT_COPY_WEAPON,

    // Harbinger of Darkness
    EVENT_MAKE_AGGRESSIVE,
    EVENT_WAIL_OF_DARKNESS,
    EVENT_SOUL_SEVER,

    // Blaze of the Heavens
    EVENT_TRIGGER_BLAZE,
    EVENT_SUMMON_BLAZE_FLAME,
    EVENT_CHECK_HEALTH,
    EVENT_TRANSFORMED,

    // Soul Fragment
    EVENT_MOVE_TO_HARBINGER,
    EVENT_CHECK_DISTANCE
};

enum Actions
{
    ACTION_PULL_BACK = 1,
    ACTION_MAKE_PASSIVE,
    ACTION_ATTACK_PLAYERS,
    ACTION_BLAZE_DIED
};

enum Texts
{
    // High Prophet Barim
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_REPENTEANCE         = 2,
    SAY_DEATH               = 3,

    // Soul Fragment
    SAY_ANNOUNCE_MERGE_SOUL = 0
};

enum PhaseMisc
{
    PHASE_ID_REPENTANCE     = 173,
    PHASE_GROUP_ENCOUNTER_1 = 391
};

class boss_high_prophet_barim : public CreatureScript
{
public:
    boss_high_prophet_barim() : CreatureScript("boss_high_prophet_barim") { }

    struct boss_high_prophet_barimAI : public BossAI
    {
        boss_high_prophet_barimAI(Creature* creature) : BossAI(creature, DATA_HIGH_PROPHET_BARIM)
        {
            Initialize();
        }

        void Initialize()
        {
            _repentanceStarted = false;
        }

        void Reset() override
        {
            _Reset();
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_FIFTY_LASHINGS, Seconds(9));
            events.ScheduleEvent(EVENT_PLAGUE_OF_AGES, Seconds(7) + Milliseconds(500));
            events.ScheduleEvent(EVENT_HEAVENS_FURY, Seconds(7) + Milliseconds(500));
            if (IsHeroic())
                events.ScheduleEvent(EVENT_BLAZE_OF_THE_HEAVENS, Seconds(10));
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, blaze);
                blaze->DespawnOrUnsummon(Milliseconds(100));
            }
            Talk(SAY_DEATH);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_SEVER);
            if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
            {
                blaze->AI()->EnterEvadeMode();
                blaze->DespawnOrUnsummon(Milliseconds(700));
            }
            _DespawnAtEvade();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/) override
        {
            if (me->HealthBelowPct(50) && !_repentanceStarted)
            {
                events.Reset();
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->StopMoving();
                DoCastSelf(SPELL_REPENTANCE);
                events.ScheduleEvent(EVENT_REPENTANCE_PULL, Seconds(1));
                _repentanceStarted = true;
            }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_PULL_BACK:
                {
                    instance->SetData(DATA_REPENTEANCE_ENDED, DONE);
                    me->RemoveAurasDueToSpell(SPELL_REPENTANCE);
                    me->SetReactState(REACT_AGGRESSIVE);

                    summons.DespawnEntry(NPC_SOUL_FRAGMENT);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_SEVER);

                    if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
                        blaze->AI()->DoAction(ACTION_ATTACK_PLAYERS);

                    events.ScheduleEvent(EVENT_FIFTY_LASHINGS, Seconds(2));
                    events.ScheduleEvent(EVENT_PLAGUE_OF_AGES, Seconds(2));
                    events.ScheduleEvent(EVENT_HEAVENS_FURY, Seconds(3) + Milliseconds(500));
                    break;
                }
                case ACTION_BLAZE_DIED:
                    events.ScheduleEvent(EVENT_BLAZE_OF_THE_HEAVENS, Seconds(3));
                    break;
                default:
                    break;
            }
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
                    case EVENT_FIFTY_LASHINGS:
                        DoCastSelf(SPELL_FIFTY_LASHINGS);
                        events.Repeat(Seconds(40));
                        break;
                    case EVENT_PLAGUE_OF_AGES:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_PLAGUE_OF_AGES);
                        events.Repeat(Seconds(25));
                        break;
                    case EVENT_HEAVENS_FURY:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_HEAVENS_FURY);
                        events.Repeat(Seconds(22));
                        break;
                    case EVENT_REPENTANCE_PULL:
                        Talk(SAY_REPENTEANCE);
                        DoCastSelf(SPELL_REPENTANCE_PULL);
                        events.ScheduleEvent(EVENT_REPENTANCE_STUN, Seconds(1) + Milliseconds(300));

                        if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
                            blaze->AI()->DoAction(ACTION_MAKE_PASSIVE);
                        break;
                    case EVENT_REPENTANCE_STUN:
                        DoCastAOE(SPELL_REPENTANCE_STUN, true);
                        events.ScheduleEvent(EVENT_REPENTANCE_KNOCKBACK, Seconds(6));
                        break;
                    case EVENT_REPENTANCE_KNOCKBACK:
                        if (Creature* blaze = instance->GetCreature(DATA_BLAZE_OF_THE_HEAVENS))
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, blaze);

                        DoCastAOE(SPELL_REPENTANCE_KNOCKBACK);
                        DoCastAOE(SPELL_REPENTANCE_SCREEN_EFFECT, true);
                        DoCastSelf(SPELL_WAIL_OF_DARKNESS_DUMMY, true);
                        break;
                    case EVENT_BLAZE_OF_THE_HEAVENS:
                        DoCastSelf(SPELL_BLAZE_OF_THE_HEAVENS, true);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    private:
        bool _repentanceStarted;
    };

    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetLostCityOfTheTolvirAI<boss_high_prophet_barimAI>(creature);
    }
};

class npc_barim_repentance : public CreatureScript
{
public:
    npc_barim_repentance() : CreatureScript("npc_barim_repentance") { }

    struct npc_barim_repentanceAI : public PassiveAI
    {
        npc_barim_repentanceAI(Creature* creature) : PassiveAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
                barim->AI()->JustSummoned(me);

            PhasingHandler::AddPhaseGroup(me, PHASE_GROUP_ENCOUNTER_1, true);

            DoCastSelf(SPELL_REPENTANCE_SCRIPT_1, true);
            _events.ScheduleEvent(EVENT_COPY_WEAPON, Seconds(2));

            if (Aura* aura = summoner->GetAura(SPELL_REPENTANCE_STUN))
                if (AuraEffect* aurEff = aura->GetEffect(EFFECT_1))
                    aurEff->SetPeriodic(false);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_PULL_BACK)
            {
                DoCastAOE(SPELL_REPENTANCE_PULL_BACK, true);
                me->DespawnOrUnsummon(Seconds(1) + Milliseconds(500));
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_COPY_WEAPON:
                        DoCastSelf(SPELL_REPENTANCE_SCRIPT_2, true);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_barim_repentanceAI>(creature);
    }
};

class npc_barim_harbinger_of_darkness : public CreatureScript
{
public:
    npc_barim_harbinger_of_darkness() : CreatureScript("npc_barim_harbinger_of_darkness") { }

    struct npc_barim_harbinger_of_darknessAI : public ScriptedAI
    {
        npc_barim_harbinger_of_darknessAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            DoZoneInCombat();
            DoCastSelf(SPELL_BIRTH, true);
            _events.ScheduleEvent(EVENT_WAIL_OF_DARKNESS, Seconds(6));
            _events.ScheduleEvent(EVENT_SOUL_SEVER, Seconds(11));
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            _events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(1) + Milliseconds(500));
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DoCastAOE(SPELL_WAIL_OF_DARKNESS_END, true);
            me->DespawnOrUnsummon(Milliseconds(700));

            if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
                barim->AI()->DoAction(ACTION_PULL_BACK);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(Milliseconds(700));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MAKE_AGGRESSIVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Player* victim = me->SelectNearestPlayer(100.0f))
                            me->AI()->AttackStart(victim);
                        break;
                    case EVENT_WAIL_OF_DARKNESS:
                        DoCastAOE(SPELL_WAIL_OF_DARKNESS);
                        _events.Repeat(Seconds(2) + Milliseconds(500));
                        break;
                    case EVENT_SOUL_SEVER:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, 0))
                            DoCast(target, SPELL_SOUL_SEVER);
                        _events.Repeat(Seconds(11));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_barim_harbinger_of_darknessAI>(creature);
    }
};

class npc_barim_blaze_of_the_heavens : public CreatureScript
{
public:
    npc_barim_blaze_of_the_heavens() : CreatureScript("npc_barim_blaze_of_the_heavens") { }

    struct npc_barim_blaze_of_the_heavensAI : public ScriptedAI
    {
        npc_barim_blaze_of_the_heavensAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
        {
            Initialize();
        }

        void Initialize()
        {
            _isInEgg = false;
            _isTransforming = false;
        }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            PhasingHandler::ResetPhaseShift(me);
            DoZoneInCombat();
            DoCastSelf(SPELL_BIRTH, true);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            _events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(1) + Milliseconds(500));
            _events.ScheduleEvent(EVENT_TRIGGER_BLAZE, Seconds(3));
            _events.ScheduleEvent(EVENT_SUMMON_BLAZE_FLAME, Seconds(4));
        }

        void JustSummoned(Creature* summon) override
        {
            if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
                barim->AI()->JustSummoned(summon);

            PhasingHandler::AddPhaseGroup(summon, PHASE_GROUP_ENCOUNTER_1, true);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->DespawnOrUnsummon(Seconds(4));
            if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
                barim->AI()->DoAction(ACTION_BLAZE_DIED);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _events.Reset();
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_ATTACK_PLAYERS:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    if (!_isInEgg)
                    {
                        _events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(1) + Milliseconds(500));
                        _events.ScheduleEvent(EVENT_TRIGGER_BLAZE, Seconds(3));
                        _events.ScheduleEvent(EVENT_SUMMON_BLAZE_FLAME, Seconds(4));
                    }
                    else
                        _events.ScheduleEvent(EVENT_CHECK_HEALTH, Seconds(1));
                    break;
                case ACTION_MAKE_PASSIVE:
                    _events.Reset();
                    me->AttackStop();
                    me->StopMoving();
                    me->RemoveAurasDueToSpell(SPELL_BLAZE_OF_THE_HEAVENS_TRIGGER);
                    me->SetReactState(REACT_PASSIVE);
                    break;
                default:
                    break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            if (me->HealthBelowPct(1) && !_isTransforming)
            {
                _events.Reset();
                _isTransforming = true;
                _events.ScheduleEvent(EVENT_TRANSFORMED, Seconds(2) + Milliseconds(300));
                me->RemoveAllAuras();
                DoCastSelf(SPELL_TRANSFORM);
            }

            if (damage >= me->GetHealth() && !_isInEgg)
                damage = me->GetHealth() - 1;
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MAKE_AGGRESSIVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Player* victim = me->SelectNearestPlayer(100.0f))
                            me->AI()->AttackStart(victim);
                        break;
                    case EVENT_TRIGGER_BLAZE:
                        DoCastSelf(SPELL_BLAZE_OF_THE_HEAVENS_TRIGGER, true);
                        break;
                    case EVENT_SUMMON_BLAZE_FLAME:
                        if (!me->FindNearestCreature(NPC_BLAZE_OF_THE_HEAVENS_FIRE, 5.0f, true))
                            DoCastSelf(SPELL_BLAZE_OF_THE_HEAVENS_FLAME, true);
                        _events.Repeat(Seconds(1));
                        break;
                    case EVENT_TRANSFORMED:
                        _isInEgg = true;
                        _events.ScheduleEvent(EVENT_CHECK_HEALTH, Seconds(1));
                        break;
                    case EVENT_CHECK_HEALTH:
                        if (me->GetHealthPct() == 100.0f && me->GetReactState() == REACT_PASSIVE)
                        {
                            me->RemoveAurasDueToSpell(SPELL_TRANSFORM);
                            DoCastSelf(SPELL_BIRTH, true);
                            DoZoneInCombat();
                            _events.ScheduleEvent(EVENT_MAKE_AGGRESSIVE, Seconds(1) + Milliseconds(500));
                            _events.ScheduleEvent(EVENT_TRIGGER_BLAZE, Seconds(3));
                            _events.ScheduleEvent(EVENT_SUMMON_BLAZE_FLAME, Seconds(4));
                            _isInEgg = false;
                            _isTransforming = false;
                        }
                        else
                            _events.Repeat(Seconds(1));
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
        bool _isInEgg;
        bool _isTransforming;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_barim_blaze_of_the_heavensAI>(creature);
    }
};

class npc_barim_soul_fragment : public CreatureScript
{
public:
    npc_barim_soul_fragment() : CreatureScript("npc_barim_soul_fragment") { }

    struct npc_barim_soul_fragmentAI : public PassiveAI
    {
        npc_barim_soul_fragmentAI(Creature* creature) : PassiveAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetWalk(true);
            DoCastSelf(SPELL_SOUL_SEVER_SCRIPT, true);
            DoCastSelf(SPELL_REPENTANCE_SCRIPT_2, true);
            DoCastAOE(SPELL_SOUL_FRAGMENT_DUMMY, true);

            if (Creature* barim = _instance->GetCreature(DATA_HIGH_PROPHET_BARIM))
                barim->AI()->JustSummoned(me);

            _events.ScheduleEvent(EVENT_MOVE_TO_HARBINGER, Seconds(5));
        }

        void JustDied(Unit* /*killer*/) override
        {
            me->DespawnOrUnsummon(Seconds(1));
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_MOVE_TO_HARBINGER:
                        if (Creature* harbinger = _instance->GetCreature(DATA_HARBINGER_OF_DARKNESS))
                        {
                            me->GetMotionMaster()->MovePoint(0, harbinger->GetPosition(), true);
                            _events.ScheduleEvent(EVENT_CHECK_DISTANCE, Milliseconds(500));
                        }
                        break;
                    case EVENT_CHECK_DISTANCE:
                        if (Creature* harbinger = me->FindNearestCreature(NPC_HARBINGER_OF_DARKNESS, 0.3f, true))
                        {
                            Talk(SAY_ANNOUNCE_MERGE_SOUL);
                            me->CastStop();
                            DoCastAOE(SPELL_MERGED_SOULS, true);
                            me->DespawnOrUnsummon(Seconds(1));
                        }
                        else
                        {
                            if (Creature* harbinger = _instance->GetCreature(DATA_HARBINGER_OF_DARKNESS))
                                me->GetMotionMaster()->MovePoint(0, harbinger->GetPosition(), true);
                            _events.Repeat(Milliseconds(500));
                        }
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_barim_soul_fragmentAI>(creature);
    }
};

class spell_barim_plague_of_ages_first : public SpellScriptLoader
{
public:
    spell_barim_plague_of_ages_first() : SpellScriptLoader("spell_barim_plague_of_ages_first") { }

    class spell_barim_plague_of_ages_first_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_barim_plague_of_ages_first_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_barim_plague_of_ages_first_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_barim_plague_of_ages_first_SpellScript();
    }
};

class spell_barim_plague_of_ages_second : public SpellScriptLoader
{
public:
    spell_barim_plague_of_ages_second() : SpellScriptLoader("spell_barim_plague_of_ages_second") { }

    class spell_barim_plague_of_ages_second_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_barim_plague_of_ages_second_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_barim_plague_of_ages_second_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_barim_plague_of_ages_second_SpellScript();
    }
};

class spell_barim_repentance_script : public SpellScriptLoader
{
public:
    spell_barim_repentance_script() : SpellScriptLoader("spell_barim_repentance_script") { }

    class spell_barim_repentance_script_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_barim_repentance_script_SpellScript);

        void EffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Unit* playerTarget = GetHitPlayer())
                playerTarget->CastSpell(GetCaster(), GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_barim_repentance_script_SpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_barim_repentance_script_SpellScript();
    }
};

class spell_barim_repentance_pull : public SpellScriptLoader
{
public:
    spell_barim_repentance_pull() : SpellScriptLoader("spell_barim_repentance_pull") { }

    class spell_barim_repentance_pull_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_barim_repentance_pull_SpellScript);

        void HandPullEffect(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);
            if (Unit* playerTarget = GetHitPlayer())
            {
                if (Unit* barim = GetCaster()) // unneeded, but we use it for readability instead of tons of GetCaster() calls
                {
                    // Calculate our own destination since players should land in front of Barim instead of inside him
                    Position pos;
                    float angle = barim->GetAngle(playerTarget);
                    float distance = barim->GetCombatReach() * 2;
                    pos.m_positionX = barim->GetPositionX() + cos(angle) * distance;
                    pos.m_positionY = barim->GetPositionY() + sin(angle) * distance;
                    pos.m_positionZ = barim->GetPositionZ();

                    float speedXY = float(GetSpellInfo()->Effects[EFFECT_0].MiscValue) * 0.1f;
                    float speedZ = playerTarget->GetDistance(pos) / speedXY * 0.5f * Movement::gravity;
                    playerTarget->GetMotionMaster()->MoveJump(pos, speedXY, speedZ);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_barim_repentance_pull_SpellScript::HandPullEffect, EFFECT_0, SPELL_EFFECT_PULL_TOWARDS);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_barim_repentance_pull_SpellScript();
    }
};

void AddSC_boss_high_prophet_barim()
{
    new boss_high_prophet_barim();
    new npc_barim_repentance();
    new npc_barim_harbinger_of_darkness();
    new npc_barim_blaze_of_the_heavens();
    new npc_barim_soul_fragment();
    new spell_barim_plague_of_ages_first();
    new spell_barim_plague_of_ages_second();
    new spell_barim_repentance_script();
    new spell_barim_repentance_pull();
}
