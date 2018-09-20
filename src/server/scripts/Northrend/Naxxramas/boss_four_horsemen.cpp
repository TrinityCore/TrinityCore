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
#include "GameTime.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "naxxramas.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Horseman
{
    THANE   = DATA_THANE,
    LADY    = DATA_LADY,
    BARON   = DATA_BARON,
    SIR     = DATA_SIR,
};
static const std::vector<Horseman> horsemen = { THANE, LADY, BARON, SIR };  // for iterating

enum Spells
{
    /* all */
    SPELL_MARK_DAMAGE      = 28836,
    SPELL_BERSERK          = 26662,
    SPELL_ENCOUNTER_CREDIT = 59450,

    /* baron */
    SPELL_BARON_MARK       = 28834,
    SPELL_UNHOLY_SHADOW    = 28882,

    /* thane */
    SPELL_THANE_MARK       = 28832,
    SPELL_METEOR           = 28884,

    /* lady */
    SPELL_SHADOW_BOLT      = 57374,
    SPELL_LADY_MARK        = 28833,
    SPELL_VOID_ZONE        = 28863,
    SPELL_UNYIELDING_PAIN  = 57381,

    /* sir */
    SPELL_HOLY_BOLT        = 57376,
    SPELL_SIR_MARK         = 28835,
    SPELL_HOLY_WRATH       = 28883,
    SPELL_CONDEMNATION     = 57377
};

enum Actions
{
    ACTION_BEGIN_MOVEMENT = 1,
    ACTION_BEGIN_FIGHTING
};

enum HorsemenData
{
    DATA_HORSEMEN_IS_TIMED_KILL = NAXData::DATA_HORSEMEN_CHECK_ACHIEVEMENT_CREDIT, // inherit from naxxramas.h - this needs to be the first entry to ensure that there are no conflicts
    DATA_MOVEMENT_FINISHED,
    DATA_DEATH_TIME
};

enum Events
{
    /* all */
    EVENT_BERSERK = 1,
    EVENT_MARK,

    /* rivendare */
    EVENT_UNHOLYSHADOW,

    /* thane */
    EVENT_METEOR,

    /* lady */
    EVENT_VOIDZONE,

    /* sir */
    EVENT_HOLYWRATH
};

enum Yells
{
    SAY_AGGRO       = 0,
    SAY_SPECIAL     = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4,

    EMOTE_RAGECAST  = 7
};

static const Position baronPath[3] = { { 2552.427f, -2969.737f, 241.3021f },{ 2566.759f, -2972.535f, 241.3217f },{ 2584.32f, -2971.96f, 241.3489f } };
static const Position thanePath[3] = { { 2540.095f, -2983.192f, 241.3344f },{ 2546.005f, -2999.826f, 241.3665f },{ 2542.697f, -3014.055f, 241.3371f } };
static const Position ladyPath[3] = { { 2507.94f, -2961.444f, 242.4557f },{ 2488.763f, -2960.007f, 241.2757f },{ 2468.26f, -2947.499f, 241.2753f } };
static const Position sirPath[3] = { { 2533.141f, -2922.14f, 241.2764f },{ 2525.254f, -2905.907f, 241.2761f },{ 2517.636f, -2897.253f, 241.2758f } };

struct boss_four_horsemen_baseAI : public BossAI
{
    public:
        Creature* getHorsemanHandle(Horseman who) const
        {
            if (_which == who)
                return me;
            else
                return ObjectAccessor::GetCreature(*me, instance->GetGuidData(who));
        }
        boss_four_horsemen_baseAI(Creature* creature, Horseman which, Position const* initialPath) :
            BossAI(creature, BOSS_HORSEMEN), _which(which), _initialPath(initialPath), _myMovementFinished(false), _nextMovement(0), _timeDied(0), _ourMovementFinished(false)
        {
            if (!me->IsAlive() && instance->GetBossState(BOSS_HORSEMEN) != DONE)
                me->SetRespawnTime(10);
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_MOVEMENT_FINISHED:
                    return _myMovementFinished ? 1 : 0;
                case DATA_DEATH_TIME:
                    return _timeDied;
                case DATA_HORSEMEN_IS_TIMED_KILL:
                {
                    uint32 minTime = 0, maxTime = 0;
                    for (Horseman boss : horsemen)
                        if (Creature* cBoss = getHorsemanHandle(boss))
                        {
                            uint32 deathTime = cBoss->AI()->GetData(DATA_DEATH_TIME);
                            if (!deathTime)
                            {
                                TC_LOG_WARN("scripts", "FourHorsemenAI: Checking for achievement credit but horseman %s is reporting not dead", cBoss->GetName().c_str());
                                return 0;
                            }
                            if (!minTime || deathTime < minTime)
                                minTime = deathTime;
                            if (!maxTime || deathTime > maxTime)
                                maxTime = deathTime;
                        }
                        else
                        {
                            TC_LOG_WARN("scripts", "FourHorsemenAI: Checking for achievement credit but horseman with id %u is not present", uint32(boss));
                            return 0;
                        }
                    return (getMSTimeDiff(minTime, maxTime) <= 15 * IN_MILLISECONDS) ? 1 : 0;
                }
                default:
                    return 0;
            }
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_BEGIN_MOVEMENT:
                    me->GetMotionMaster()->MovePoint(1, _initialPath[0], true);
                    break;
                case ACTION_BEGIN_FIGHTING:
                    if (_ourMovementFinished)
                        break;
                    me->SetCombatPulseDelay(5);
                    BeginFighting();
                    _ourMovementFinished = true;
                    break;
            }
        }

        void CheckIsMovementFinished()
        {
            for (Horseman boss : horsemen)
            {
                if (Creature* cBoss = getHorsemanHandle(boss))
                {
                    if (cBoss->IsAlive() && !cBoss->AI()->GetData(DATA_MOVEMENT_FINISHED))
                        return;
                }
                else
                {
                    TC_LOG_WARN("scripts", "FourHorsemenAI: Checking if movement is finished but horseman with id %u is not present", uint32(boss));
                    ResetEncounter();
                    return;
                }
            }

            for (Horseman boss : horsemen)
                if (Creature* cBoss = getHorsemanHandle(boss))
                    cBoss->AI()->DoAction(ACTION_BEGIN_FIGHTING);
        }

        void BeginEncounter()
        {
            if (instance->GetBossState(BOSS_HORSEMEN) == IN_PROGRESS)
                return;
            if (!instance->CheckRequiredBosses(BOSS_HORSEMEN))
            {
                ResetEncounter();
                return;
            }
            instance->SetBossState(BOSS_HORSEMEN, IN_PROGRESS);
            Map::PlayerList const& players = me->GetMap()->GetPlayers();
            if (players.isEmpty()) // sanity check
                ResetEncounter();

            for (Horseman boss : horsemen)
            {
                if (Creature* cBoss = getHorsemanHandle(boss))
                {
                    if (!cBoss->IsAlive())
                    {
                        ResetEncounter();
                        return;
                    }
                    cBoss->SetReactState(REACT_PASSIVE);
                    cBoss->AttackStop(); // clear initial target that was set on enter combat
                    cBoss->setActive(true);
                    cBoss->SetFarVisible(true);

                    for (Map::PlayerList::const_iterator it = players.begin(); it != players.end(); ++it)
                    {
                        if (Player* player = it->GetSource())
                        {
                            if (player->IsGameMaster())
                                continue;

                            if (player->IsAlive())
                                AddThreat(player, 0.0f, cBoss);
                        }
                    }

                    /* Why do the Four Horsemen run to opposite corners of the room when engaged?          *
                    * They saw all the mobs leading up to them being AoE'd down and made a judgment call. */
                    cBoss->AI()->DoAction(ACTION_BEGIN_MOVEMENT);
                }
                else
                {
                    TC_LOG_WARN("scripts", "FourHorsemenAI: Encounter starting but horseman with id %u is not present", uint32(boss));
                    ResetEncounter();
                    return;
                }
            }
        }

        void ResetEncounter()
        {
            if (instance->GetBossState(BOSS_HORSEMEN) == NOT_STARTED || instance->GetBossState(BOSS_HORSEMEN) == DONE)
                return;
            instance->SetBossState(BOSS_HORSEMEN, NOT_STARTED);
            for (Horseman boss : horsemen)
            {
                if (Creature* cBoss = getHorsemanHandle(boss))
                    cBoss->DespawnOrUnsummon(0, Seconds(15));
                else
                    TC_LOG_WARN("scripts", "FourHorsemenAI: Encounter resetting but horseman with id %u is not present", uint32(boss));
            }
        }

        void EncounterCleared()
        {
            if (instance->GetBossState(BOSS_HORSEMEN) == DONE)
                return;
            instance->SetBossState(BOSS_HORSEMEN, DONE);
            //instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ENCOUNTER_CREDIT);
            DoCastAOE(SPELL_ENCOUNTER_CREDIT, true);
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            if (instance->GetBossState(BOSS_HORSEMEN) == IN_PROGRESS || instance->GetBossState(BOSS_HORSEMEN) == DONE) // another horseman already did it
                return;
            Talk(SAY_AGGRO);
            BeginEncounter();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            ResetEncounter();
        }

        void Reset() override
        {
            if (!me->IsAlive())
                return;
            _myMovementFinished = false;
            _nextMovement = 0;
            _timeDied = 0;
            _ourMovementFinished = false;
            me->SetReactState(REACT_AGGRESSIVE);
            SetCombatMovement(false);
            me->SetCombatPulseDelay(0);
            me->ResetLootMode();
            events.Reset();
            summons.DespawnAll();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY, victim);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance->GetBossState(BOSS_HORSEMEN) != IN_PROGRESS) // necessary in case a horseman gets one-shot
            {
                BeginEncounter();
                return;
            }

            Talk(SAY_DEATH);
            _timeDied = GameTime::GetGameTimeMS();
            for (Horseman boss : horsemen)
            {
                if (Creature* cBoss = getHorsemanHandle(boss))
                {
                    if (cBoss->IsAlive())
                    {
                        // in case a horseman dies while moving (unlikely but possible especially in non-335 branch)
                        CheckIsMovementFinished();
                        return;
                    }
                }
                else
                {
                    TC_LOG_WARN("scripts", "FourHorsemenAI: %s died but horseman with id %u is not present", me->GetName().c_str(), uint32(boss));
                    ResetEncounter();
                }
            }

            EncounterCleared();
        }

        void MovementInform(uint32 type, uint32 i) override
        {
            if (type != POINT_MOTION_TYPE)
                return;
            if (i < 3)
                _nextMovement = i; // delay to next updateai to prevent it from instantly expiring
            else
            {
                _myMovementFinished = true;
                CheckIsMovementFinished();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (_nextMovement)
            {
                me->GetMotionMaster()->MovePoint(_nextMovement + 1, _initialPath[_nextMovement], true);
                _nextMovement = 0;
            }
            _UpdateAI(diff);
        }

        virtual void BeginFighting() = 0;
        virtual void _UpdateAI(uint32 /*diff*/) = 0;

    private:
        const Horseman _which;
        Position const* _initialPath;
        bool _myMovementFinished;
        uint8 _nextMovement;
        uint32 _timeDied;
    protected:
        bool _ourMovementFinished;
};

class boss_four_horsemen_baron : public CreatureScript
{
    public:
        boss_four_horsemen_baron() : CreatureScript("boss_four_horsemen_baron") { }

        struct boss_four_horsemen_baronAI : public boss_four_horsemen_baseAI
        {
            boss_four_horsemen_baronAI(Creature* creature) : boss_four_horsemen_baseAI(creature, BARON, baronPath) { }
            void BeginFighting() override
            {
                SetCombatMovement(true);
                me->SetReactState(REACT_AGGRESSIVE);
                ThreatManager& threat = me->GetThreatManager();
                if (threat.IsThreatListEmpty())
                {
                    if (Unit* nearest = me->SelectNearestPlayer(5000.0f))
                    {
                        AddThreat(nearest, 1.0f);
                        AttackStart(nearest);
                    }
                    else
                        ResetEncounter();
                }
                else
                    AttackStart(threat.GetCurrentVictim());

                events.ScheduleEvent(EVENT_BERSERK, 10min);
                events.ScheduleEvent(EVENT_MARK, 24s);
                events.ScheduleEvent(EVENT_UNHOLYSHADOW, randtime(Seconds(3), Seconds(7)));
            }

            void _UpdateAI(uint32 diff) override
            {
                if (!_ourMovementFinished || !UpdateVictim())
                    return;
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCastAOE(SPELL_BERSERK, true);
                            break;
                        case EVENT_MARK:
                            DoCastAOE(SPELL_BARON_MARK, true);
                            events.Repeat(Seconds(12));
                            break;
                        case EVENT_UNHOLYSHADOW:
                            DoCastVictim(SPELL_UNHOLY_SHADOW);
                            events.Repeat(randtime(Seconds(10), Seconds(30)));
                            break;
                    }
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                DoMeleeAttackIfReady();
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_UNHOLY_SHADOW)
                    Talk(SAY_SPECIAL);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<boss_four_horsemen_baronAI>(creature);
        }
};

class boss_four_horsemen_thane : public CreatureScript
{
    public:
        boss_four_horsemen_thane() : CreatureScript("boss_four_horsemen_thane") { }

        struct boss_four_horsemen_thaneAI : public boss_four_horsemen_baseAI
        {
            boss_four_horsemen_thaneAI(Creature* creature) : boss_four_horsemen_baseAI(creature, THANE, thanePath), _shouldSay(true) { }
            void BeginFighting() override
            {
                SetCombatMovement(true);
                me->SetReactState(REACT_AGGRESSIVE);
                ThreatManager& threat = me->GetThreatManager();
                if (threat.IsThreatListEmpty())
                {
                    if (Unit* nearest = me->SelectNearestPlayer(5000.0f))
                    {
                        AddThreat(nearest, 1.0f);
                        AttackStart(nearest);
                    }
                    else
                        ResetEncounter();
                }
                else
                    AttackStart(threat.GetCurrentVictim());

                events.ScheduleEvent(EVENT_BERSERK, 10min);
                events.ScheduleEvent(EVENT_MARK, 24s);
                events.ScheduleEvent(EVENT_METEOR, randtime(Seconds(10), Seconds(25)));
            }
            void _UpdateAI(uint32 diff) override
            {
                if (!_ourMovementFinished || !UpdateVictim())
                    return;
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCastAOE(SPELL_BERSERK, true);
                            break;
                        case EVENT_MARK:
                            DoCastAOE(SPELL_THANE_MARK, true);
                            events.Repeat(Seconds(12));
                            break;
                        case EVENT_METEOR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                            {
                                DoCast(target, SPELL_METEOR);
                                _shouldSay = true;
                            }
                            events.Repeat(randtime(Seconds(13), Seconds(17)));
                            break;
                    }
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
                DoMeleeAttackIfReady();
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
            {
                if (_shouldSay && spell->Id == SPELL_METEOR)
                {
                    Talk(SAY_SPECIAL);
                    _shouldSay = false;
                }
            }

            private:
                bool _shouldSay; // throttle to make sure we only talk on first target hit by meteor
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<boss_four_horsemen_thaneAI>(creature);
        }
};

class boss_four_horsemen_lady : public CreatureScript
{
    public:
        boss_four_horsemen_lady() : CreatureScript("boss_four_horsemen_lady") { }

        struct boss_four_horsemen_ladyAI : public boss_four_horsemen_baseAI
        {
            boss_four_horsemen_ladyAI(Creature* creature) : boss_four_horsemen_baseAI(creature, LADY, ladyPath) { }
            void BeginFighting() override
            {
                events.ScheduleEvent(EVENT_BERSERK, 10min);
                events.ScheduleEvent(EVENT_MARK, 24s);
                events.ScheduleEvent(EVENT_VOIDZONE, randtime(Seconds(5), Seconds(10)));
            }

            void _UpdateAI(uint32 diff) override
            {
                if (!me->IsInCombat())
                    return;
                if (!_ourMovementFinished)
                    return;
                if (me->GetThreatManager().IsThreatListEmpty())
                {
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    return;
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCastAOE(SPELL_BERSERK, true);
                            break;
                        case EVENT_MARK:
                            DoCastAOE(SPELL_LADY_MARK, true);
                            events.Repeat(Seconds(15));
                            break;
                        case EVENT_VOIDZONE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 45.0f, true))
                            {
                                DoCast(target, SPELL_VOID_ZONE, true);
                                Talk(SAY_SPECIAL);
                            }
                            events.Repeat(randtime(Seconds(12), Seconds(18)));
                            break;
                    }
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 45.0f, true))
                    DoCast(target, SPELL_SHADOW_BOLT);
                else
                {
                    DoCastAOE(SPELL_UNYIELDING_PAIN);
                    Talk(EMOTE_RAGECAST);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<boss_four_horsemen_ladyAI>(creature);
        }
};

class boss_four_horsemen_sir : public CreatureScript
{
    public:
        boss_four_horsemen_sir() : CreatureScript("boss_four_horsemen_sir") { }

        struct boss_four_horsemen_sirAI : public boss_four_horsemen_baseAI
        {
            boss_four_horsemen_sirAI(Creature* creature) : boss_four_horsemen_baseAI(creature, SIR, sirPath), _shouldSay(true) { }
            void BeginFighting() override
            {
                events.ScheduleEvent(EVENT_BERSERK, 10min);
                events.ScheduleEvent(EVENT_MARK, 24s);
                events.ScheduleEvent(EVENT_HOLYWRATH, randtime(Seconds(13), Seconds(18)));
            }

            void _UpdateAI(uint32 diff) override
            {
                if (!me->IsInCombat())
                    return;
                if (!_ourMovementFinished)
                    return;
                if (me->GetThreatManager().IsThreatListEmpty())
                {
                    EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                    return;
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BERSERK:
                            DoCastAOE(SPELL_BERSERK, true);
                            break;
                        case EVENT_MARK:
                            DoCastAOE(SPELL_SIR_MARK, true);
                            events.Repeat(Seconds(15));
                            break;
                        case EVENT_HOLYWRATH:
                            if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 45.0f, true))
                            {
                                DoCast(target, SPELL_HOLY_WRATH, true);
                                _shouldSay = true;
                            }
                            events.Repeat(randtime(Seconds(10), Seconds(18)));
                            break;
                    }
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (Unit* target = SelectTarget(SELECT_TARGET_MINDISTANCE, 0, 45.0f, true))
                    DoCast(target, SPELL_HOLY_BOLT);
                else
                {
                    DoCastAOE(SPELL_CONDEMNATION);
                    Talk(EMOTE_RAGECAST);
                }
            }

            void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
            {
                if (_shouldSay && spell->Id == SPELL_HOLY_WRATH)
                {
                    Talk(SAY_SPECIAL);
                    _shouldSay = false;
                }
            }

            private:
                bool _shouldSay; // throttle to make sure we only talk on first target hit by holy wrath
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetNaxxramasAI<boss_four_horsemen_sirAI>(creature);
        }
};

class spell_four_horsemen_mark : public SpellScriptLoader
{
    public:
        spell_four_horsemen_mark() : SpellScriptLoader("spell_four_horsemen_mark") { }

        class spell_four_horsemen_mark_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_four_horsemen_mark_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 damage;
                    switch (GetStackAmount())
                    {
                        case 1:
                            damage = 0;
                            break;
                        case 2:
                            damage = 500;
                            break;
                        case 3:
                            damage = 1000;
                            break;
                        case 4:
                            damage = 1500;
                            break;
                        case 5:
                            damage = 4000;
                            break;
                        case 6:
                            damage = 12000;
                            break;
                        default:
                            damage = 20000 + 1000 * (GetStackAmount() - 7);
                            break;
                    }
                    if (damage)
                    {
                        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                        args.AddSpellBP0(damage);
                        caster->CastSpell(GetTarget(), SPELL_MARK_DAMAGE, args);
                    }
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_four_horsemen_mark_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_four_horsemen_mark_AuraScript();
        }
};

void AddSC_boss_four_horsemen()
{
    new boss_four_horsemen_baron();
    new boss_four_horsemen_thane();
    new boss_four_horsemen_lady();
    new boss_four_horsemen_sir();
    new spell_four_horsemen_mark();
}
