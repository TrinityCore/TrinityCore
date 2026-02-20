/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

/*
 * Timers requires to be revisited
 * Spells SPELL_ROOT_SELF and SPELL_PACIFY_SELF are guessed, based on effects received in packets
 * Everything related to Sporebats requires sniff verification
 * After looting Tainted Core, spell SPELL_PARALYZE should be casted by player
 * Is SPELL_REMOVE_TAINTED_CORES used in correct place?
 * Creature 15384 at position X: 29.875898 Y: -923.3916 Z: 42.985214 is spawned when second phase
   starts. Despawns when second phase is finished. Currently spawned permanently
 * Critical bug: SPELL_SURGE doesn't get applied because of SPELL_MAGIC_BARRIER immunity
 * Critical bug: SPELL_MAGIC_BARRIER doesn't stack because of immunity, only one channel is active,
   it is enough to deactivate generator with channeled spell to kill boss, skipping phase 3 entirely
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum VashjTexts
{
    SAY_INTRO                            = 0,
    SAY_AGGRO                            = 1,
    SAY_BOWSHOT                          = 2,
    SAY_PHASE_2                          = 3,
    SAY_PHASE_3                          = 4,
    SAY_SLAY                             = 5,
    SAY_DEATH                            = 6
};

enum VashjSpells
{
    // Phase 1 & 3
    SPELL_SHOOT                          = 38295,
    SPELL_MULTI_SHOT                     = 38310,
    SPELL_STATIC_CHARGE                  = 38280,
    SPELL_ENTANGLE                       = 38316,
    SPELL_SHOCK_BLAST                    = 38509,

    // Transition
    SPELL_ROOT_SELF                      = 23973,
    SPELL_PACIFY_SELF                    = 19951,

    // Phase 2
    SPELL_FORKED_LIGHTNING               = 38145,

    SPELL_WAVE_A_1_PERIODIC              = 38018,
    SPELL_WAVE_A_2_PERIODIC              = 38036,
    SPELL_WAVE_A_3_PERIODIC              = 38040,
    SPELL_WAVE_A_4_PERIODIC              = 38041,

    SPELL_SUMMON_WAVE_B_MOB_TRIGGER      = 38248,
    SPELL_SUMMON_WAVE_C_MOB_TRIGGER      = 38241,
    SPELL_SUMMON_WAVE_D_MOB_TRIGGER      = 38140,

    // Phase 3
    SPELL_SUMMON_WAVE_E_MOB_TRIGGER      = 38494,

    // World Trigger (Tiny)
    SPELL_MAGIC_BARRIER                  = 38112,

    // Enchanted Elemental
    SPELL_SURGE                          = 38044,

    // Tainted Elemental
    SPELL_POISON_BOLT                    = 38253,

    // Toxic Sporebat
    SPELL_SPORE_DROP                     = 38571,

    // Scripts
    SPELL_SUMMON_WAVE_A_MOB_TRIGGER_1    = 38017,
    SPELL_SUMMON_WAVE_A_MOB_TRIGGER_2    = 38037,
    SPELL_SUMMON_WAVE_A_MOB_TRIGGER_3    = 38038,
    SPELL_SUMMON_WAVE_A_MOB_TRIGGER_4    = 38039,

    SPELL_SUMMON_WAVE_A_MOB              = 38019,
    SPELL_SUMMON_WAVE_B_MOB              = 38247,
    SPELL_SUMMON_WAVE_C_MOB              = 38242,
    SPELL_SUMMON_WAVE_D_MOB              = 38244,

    SPELL_SUMMON_WAVE_E_MOB_1            = 38489,
    SPELL_SUMMON_WAVE_E_MOB_2            = 38492,
    SPELL_SUMMON_WAVE_E_MOB_3            = 38493,

    SPELL_TOXIC_SPORES                   = 38574,

    SPELL_REMOVE_TAINTED_CORES_EFFECT    = 39496,

    // Misc
    SPELL_PARALYZE                       = 38132,
    SPELL_REMOVE_TAINTED_CORES           = 39495
};

enum VashjEvents
{
    // Intro
    EVENT_INTRO                          = 1,

    // Phase 1 & 3
    EVENT_SHOOT,
    EVENT_MULTI_SHOT,
    EVENT_STATIC_CHARGE,
    EVENT_ENTANGLE,
    EVENT_SHOCK_BLAST,

    // Transition
    EVENT_TRANSITION_1,
    EVENT_TRANSITION_2,

    // Phase 2
    EVENT_FORKED_LIGHTNING,
    EVENT_SUMMON_TAINTED_ELEMENTAL,
    EVENT_SUMMON_COILFANG_ELITE,
    EVENT_SUMMON_COILFANG_STRIDER,

    // Phase 3
    EVENT_SUMMON_SPOREBAT
};

enum VashjActions
{
    ACTION_INTRO_EVENT_TRIGGERED         = 0,
    ACTION_TAINTED_ELEMENTAL_DESPAWNED   = 1,
    ACTION_TAINTED_ELEMENTAL_DIES        = 2,
    ACTION_SHIELD_GENERATOR_DEACTIVATED  = 3
};

enum VashjCreatures
{
    NPC_WORLD_TRIGGER_TINY               = 21987,
    NPC_ENCHANTED_ELEMENTAL              = 21958,
    NPC_TAINTED_ELEMENTAL                = 22009,
    NPC_COILFANG_ELITE                   = 22055,
    NPC_COILFANG_STRIDER                 = 22056,
    NPC_TOXIC_SPOREBAT                   = 22140,
    NPC_SPORE_DROP_TRIGGER               = 22207
};

enum VashjPaths
{
    PATH_SPOREBAT_INTRO_1                = 17712002,
    PATH_SPOREBAT_INTRO_2                = 17712010,
    PATH_SPOREBAT_INTRO_3                = 17712018,
    PATH_SPOREBAT_LOOP_1                 = 17712026,
    PATH_SPOREBAT_LOOP_2                 = 17712034,
    PATH_SPOREBAT_LOOP_3                 = 17712042
};

enum VashjMisc
{
    POINT_CENTER                         = 0,
    MAX_DEACTIVATED_GENERATORS           = 4,
    SPELL_VISUAL_KIT                     = 6445,
    ITEM_TAINTED_CORE                    = 31088
};

Position const CenterPos = { 29.8326f, -923.274f, 42.901886f, 0.0f };

static constexpr std::array<uint32, 4> ShieldGeneratorData =
{
    DATA_SHIELD_GENERATOR_1,
    DATA_SHIELD_GENERATOR_2,
    DATA_SHIELD_GENERATOR_3,
    DATA_SHIELD_GENERATOR_4
};

// 21212 - Lady Vashj
struct boss_lady_vashj : public BossAI
{
    boss_lady_vashj(Creature* creature) : BossAI(creature, BOSS_LADY_VASHJ),
        _introIsTriggered(false), _isSecondPhaseStarted(false), _isSecondPhaseInProgress(false),
        _generatorsDeactivatedCount(0), _summonSporebatStaticTimer(30000) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SHOOT, 0s);
        events.ScheduleEvent(EVENT_MULTI_SHOT, 10s, 20s);
        events.ScheduleEvent(EVENT_STATIC_CHARGE, 5s, 15s);
        events.ScheduleEvent(EVENT_ENTANGLE, 20s, 45s);
        events.ScheduleEvent(EVENT_SHOCK_BLAST, 10s, 30s);

        DoCastSelf(SPELL_REMOVE_TAINTED_CORES);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 40.0f);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!_isSecondPhaseStarted && me->HealthBelowPctDamaged(70, damage))
        {
            _isSecondPhaseStarted = true;
            events.ScheduleEvent(EVENT_TRANSITION_1, 0s);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == POINT_MOTION_TYPE && pointId == POINT_CENTER)
            events.ScheduleEvent(EVENT_TRANSITION_2, 1s);
    }

    void DoDespawnSummons()
    {
        std::vector<Creature*> spawns;

        GetCreatureListWithEntryInGrid(spawns, me, NPC_ENCHANTED_ELEMENTAL, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_TAINTED_ELEMENTAL, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_COILFANG_ELITE, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_COILFANG_STRIDER, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_TOXIC_SPOREBAT, 500.0f);
        GetCreatureListWithEntryInGrid(spawns, me, NPC_SPORE_DROP_TRIGGER, 500.0f);

        for (Creature* spawn : spawns)
            spawn->DespawnOrUnsummon();
    }

    void DoCleanupTriggers()
    {
        if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA1" }))
            trigger->RemoveAurasDueToSpell(SPELL_WAVE_A_1_PERIODIC);

        if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA2" }))
            trigger->RemoveAurasDueToSpell(SPELL_WAVE_A_2_PERIODIC);

        if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA3" }))
            trigger->RemoveAurasDueToSpell(SPELL_WAVE_A_3_PERIODIC);

        if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA4" }))
            trigger->RemoveAurasDueToSpell(SPELL_WAVE_A_4_PERIODIC);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        for (uint32 data : ShieldGeneratorData)
            if (GameObject* generator = instance->GetGameObject(data))
                generator->ActivateObject(GameObjectActions(GameObjectActions::MakeInert));

        DoDespawnSummons();
        DoCleanupTriggers();

        _DespawnAtEvade();
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SHOOT:
                if (roll_chance_i(10))
                    Talk(SAY_BOWSHOT);
                break;
            case SPELL_MULTI_SHOT:
                if (roll_chance_i(50))
                    Talk(SAY_BOWSHOT);
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (!me->IsAlive())
            return;

        switch (action)
        {
            case ACTION_INTRO_EVENT_TRIGGERED:
                if (!_introIsTriggered)
                {
                    events.ScheduleEvent(EVENT_INTRO, 25s);
                    _introIsTriggered = true;
                }
                break;
            case ACTION_TAINTED_ELEMENTAL_DESPAWNED:
                if (_isSecondPhaseInProgress)
                    events.ScheduleEvent(EVENT_SUMMON_TAINTED_ELEMENTAL, 0s, 15s);
                break;
            case ACTION_TAINTED_ELEMENTAL_DIES:
                if (_isSecondPhaseInProgress)
                    events.ScheduleEvent(EVENT_SUMMON_TAINTED_ELEMENTAL, 50s, 60s);
                break;
            case ACTION_SHIELD_GENERATOR_DEACTIVATED:
            {
                _generatorsDeactivatedCount++;

                if (me->HealthAbovePct(5))
                    me->SetHealth(me->GetHealth() - me->CountPctFromMaxHealth(5));
                else
                    me->SetHealth(1);

                me->SendPlaySpellVisualKit(SPELL_VISUAL_KIT, 0);

                if (_generatorsDeactivatedCount == MAX_DEACTIVATED_GENERATORS)
                {
                    me->RemoveAurasDueToSpell(SPELL_ROOT_SELF);
                    me->RemoveAurasDueToSpell(SPELL_PACIFY_SELF);

                    Talk(SAY_PHASE_3);

                    ResetThreatList();

                    DoCleanupTriggers();

                    _isSecondPhaseInProgress = false;

                    events.CancelEvent(EVENT_FORKED_LIGHTNING);
                    events.CancelEvent(EVENT_SUMMON_TAINTED_ELEMENTAL);
                    events.CancelEvent(EVENT_SUMMON_COILFANG_ELITE);
                    events.CancelEvent(EVENT_SUMMON_COILFANG_STRIDER);

                    events.ScheduleEvent(EVENT_SHOOT, 0s);
                    events.ScheduleEvent(EVENT_MULTI_SHOT, 10s, 20s);
                    events.ScheduleEvent(EVENT_STATIC_CHARGE, 5s, 15s);
                    events.ScheduleEvent(EVENT_ENTANGLE, 20s, 45s);
                    events.ScheduleEvent(EVENT_SHOCK_BLAST, 10s, 30s);
                    events.ScheduleEvent(EVENT_SUMMON_SPOREBAT, 35s);
                }
                break;
            }
            default:
                break;
        }
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        DoDespawnSummons();
        DoCleanupTriggers();
        _JustDied();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO:
                        Talk(SAY_INTRO);
                        break;
                    default:
                        break;
                }
            }
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                // Phase 1 & 3
                case EVENT_SHOOT:
                    DoCastVictim(SPELL_SHOOT);
                    events.Repeat(2s, 4s);
                    break;
                case EVENT_MULTI_SHOT:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_MULTI_SHOT);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_STATIC_CHARGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true, true, -SPELL_STATIC_CHARGE))
                        DoCast(target, SPELL_STATIC_CHARGE);
                    events.Repeat(5s, 25s);
                    break;
                case EVENT_ENTANGLE:
                    DoCastSelf(SPELL_ENTANGLE);
                    events.Repeat(15s, 35s);
                    break;
                case EVENT_SHOCK_BLAST:
                    DoCastVictim(SPELL_SHOCK_BLAST);
                    events.Repeat(10s, 30s);
                    break;

                // Transition
                case EVENT_TRANSITION_1:
                    _isSecondPhaseInProgress = true;

                    events.CancelEvent(EVENT_SHOOT);
                    events.CancelEvent(EVENT_MULTI_SHOT);
                    events.CancelEvent(EVENT_STATIC_CHARGE);
                    events.CancelEvent(EVENT_ENTANGLE);
                    events.CancelEvent(EVENT_SHOCK_BLAST);

                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_CENTER, CenterPos);
                    break;
                case EVENT_TRANSITION_2:
                {
                    DoCastSelf(SPELL_ROOT_SELF);
                    DoCastSelf(SPELL_PACIFY_SELF);

                    Talk(SAY_PHASE_2);

                    std::vector<Creature*> triggers;
                    GetCreatureListWithEntryInGrid(triggers, me, NPC_WORLD_TRIGGER_TINY, 50.0f);
                    for (Creature* trigger : triggers)
                        trigger->CastSpell(trigger, SPELL_MAGIC_BARRIER);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA1" }))
                        trigger->CastSpell(trigger, SPELL_WAVE_A_1_PERIODIC);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA2" }))
                        trigger->CastSpell(trigger, SPELL_WAVE_A_2_PERIODIC);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA3" }))
                        trigger->CastSpell(trigger, SPELL_WAVE_A_3_PERIODIC);

                    if (Creature* trigger = me->FindNearestCreatureWithOptions(100.0f, { .StringId = "LadyVashjTriggerWaveA4" }))
                        trigger->CastSpell(trigger, SPELL_WAVE_A_4_PERIODIC);

                    for (uint32 data : ShieldGeneratorData)
                        if (GameObject* generator = instance->GetGameObject(data))
                            generator->ActivateObject(GameObjectActions(GameObjectActions::MakeActive));

                    me->SetReactState(REACT_AGGRESSIVE);

                    events.ScheduleEvent(EVENT_FORKED_LIGHTNING, 0s);
                    events.ScheduleEvent(EVENT_SUMMON_TAINTED_ELEMENTAL, 50s, 60s);
                    events.ScheduleEvent(EVENT_SUMMON_COILFANG_ELITE, 45s, 50s);
                    events.ScheduleEvent(EVENT_SUMMON_COILFANG_STRIDER, 60s);
                    break;
                }

                // Phase 2
                case EVENT_FORKED_LIGHTNING:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FORKED_LIGHTNING);
                    events.Repeat(2s, 10s);
                    break;
                case EVENT_SUMMON_TAINTED_ELEMENTAL:
                    DoCastSelf(SPELL_SUMMON_WAVE_D_MOB_TRIGGER);
                    break;
                case EVENT_SUMMON_COILFANG_ELITE:
                    DoCastSelf(SPELL_SUMMON_WAVE_B_MOB_TRIGGER);
                    events.Repeat(40s, 50s);
                    break;
                case EVENT_SUMMON_COILFANG_STRIDER:
                    DoCastSelf(SPELL_SUMMON_WAVE_C_MOB_TRIGGER);
                    events.Repeat(60s, 65s);
                    break;

                // Phase 3
                case EVENT_SUMMON_SPOREBAT:
                    DoCastSelf(SPELL_SUMMON_WAVE_E_MOB_TRIGGER);

                    if (_summonSporebatStaticTimer > 5000ms)
                        _summonSporebatStaticTimer -= 2000ms;
                    else
                        _summonSporebatStaticTimer = 5000ms;

                    events.Repeat(_summonSporebatStaticTimer);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    bool _introIsTriggered;
    bool _isSecondPhaseStarted;
    bool _isSecondPhaseInProgress;
    uint8 _generatorsDeactivatedCount;
    Milliseconds _summonSporebatStaticTimer;
};

// 21958 - Enchanted Elemental
struct npc_enchanted_elemental : public ScriptedAI
{
    npc_enchanted_elemental(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCorpseDelay(4, true);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        ///! HACK: This creature should walk but it runs, reducing run speed
        me->SetSpeedRate(MOVE_RUN, 0.5f);

        /// @todo: Angle should be closest position to Vashj, not to the left or right of Vashj
        if (Creature* vashj = _instance->GetCreature(BOSS_LADY_VASHJ))
            me->GetMotionMaster()->MoveFollow(vashj, 5.0f, 0.0f);

        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            if (Creature* vashj = _instance->GetCreature(BOSS_LADY_VASHJ))
            {
                /// @todo: This should ignore combat reach calculation (boss grows in size but elementals still move to 5 yards from boss)
                if (me->IsWithinDistInMap(vashj, 6.0f))
                    DoCastSelf(SPELL_SURGE);
            }
            task.Repeat();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 22009 - Tainted Elemental
struct npc_tainted_elemental : public ScriptedAI
{
    npc_tainted_elemental(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_POISON_BOLT);
                task.Repeat(2s);
            })
            .Schedule(15s, 20s, [this](TaskContext /*task*/)
            {
                if (Creature* vashj = _instance->GetCreature(BOSS_LADY_VASHJ))
                    vashj->AI()->DoAction(ACTION_TAINTED_ELEMENTAL_DESPAWNED);

                me->DespawnOrUnsummon();
            });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* vashj = _instance->GetCreature(BOSS_LADY_VASHJ))
            vashj->AI()->DoAction(ACTION_TAINTED_ELEMENTAL_DIES);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 22140 - Toxic Sporebat
struct npc_toxic_sporebat : public ScriptedAI
{
    npc_toxic_sporebat(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SPORE_DROP);

        switch (me->GetUInt32Value(UNIT_CREATED_BY_SPELL))
        {
            case SPELL_SUMMON_WAVE_E_MOB_1:
                me->GetMotionMaster()->MovePath(PATH_SPOREBAT_INTRO_1, false);
                break;
            case SPELL_SUMMON_WAVE_E_MOB_2:
                me->GetMotionMaster()->MovePath(PATH_SPOREBAT_INTRO_2, false);
                break;
            case SPELL_SUMMON_WAVE_E_MOB_3:
                me->GetMotionMaster()->MovePath(PATH_SPOREBAT_INTRO_3, false);
                break;
            default:
                break;
        }
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->GetMotionMaster()->MovePath(RAND(PATH_SPOREBAT_LOOP_1, PATH_SPOREBAT_LOOP_2, PATH_SPOREBAT_LOOP_3), true);
    }
};

// 184568 - Lady Vashj Bridge Console
struct go_bridge_console : public GameObjectAI
{
    go_bridge_console(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        if (GameObject* bridge = _instance->GetGameObject(DATA_BRIDGE_PART_1))
            _instance->HandleGameObject(ObjectGuid::Empty, true, bridge);

        if (GameObject* bridge = _instance->GetGameObject(DATA_BRIDGE_PART_2))
            _instance->HandleGameObject(ObjectGuid::Empty, true, bridge);

        if (GameObject* bridge = _instance->GetGameObject(DATA_BRIDGE_PART_3))
            _instance->HandleGameObject(ObjectGuid::Empty, true, bridge);

        if (Creature* vashj = _instance->GetCreature(BOSS_LADY_VASHJ))
            vashj->AI()->DoAction(ACTION_INTRO_EVENT_TRIGGERED);

        return false;
    }

private:
    InstanceScript* _instance;
};

// 185051, 185052, 185053, 185054 - Shield Generator
struct go_shield_generator : public GameObjectAI
{
    go_shield_generator(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        if (Creature* trigger = GetClosestCreatureWithEntry(me, NPC_WORLD_TRIGGER_TINY, 10.0f))
            trigger->InterruptNonMeleeSpells(false);

        if (Creature* vashj = _instance->GetCreature(BOSS_LADY_VASHJ))
            vashj->AI()->DoAction(ACTION_SHIELD_GENERATOR_DEACTIVATED);

        me->ActivateObject(GameObjectActions(GameObjectActions::MakeInert));

        return false;
    }

private:
    InstanceScript* _instance;
};

/* 38017 - Wave A - 1
   38037 - Wave A - 2
   38038 - Wave A - 3
   38039 - Wave A - 4
   38248 - Summon Wave B Mob Trigger
   38241 - Summon Wave C Mob Trigger
   38140 - Summon Wave D Mob Trigger */
class spell_lady_vashj_summon_wave_mob_trigger : public SpellScript
{
    PrepareSpellScript(spell_lady_vashj_summon_wave_mob_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_WAVE_A_MOB,
            SPELL_SUMMON_WAVE_B_MOB,
            SPELL_SUMMON_WAVE_C_MOB,
            SPELL_SUMMON_WAVE_D_MOB
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        switch (GetSpellInfo()->Id)
        {
            case SPELL_SUMMON_WAVE_A_MOB_TRIGGER_1:
            case SPELL_SUMMON_WAVE_A_MOB_TRIGGER_2:
            case SPELL_SUMMON_WAVE_A_MOB_TRIGGER_3:
            case SPELL_SUMMON_WAVE_A_MOB_TRIGGER_4:
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_WAVE_A_MOB);
                break;
            case SPELL_SUMMON_WAVE_B_MOB_TRIGGER:
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_WAVE_B_MOB);
                break;
            case SPELL_SUMMON_WAVE_C_MOB_TRIGGER:
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_WAVE_C_MOB);
                break;
            case SPELL_SUMMON_WAVE_D_MOB_TRIGGER:
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_WAVE_D_MOB);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lady_vashj_summon_wave_mob_trigger::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_lady_vashj_summon_wave_mob_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 38494 - Summon Wave E Mob
class spell_lady_vashj_summon_wave_e_mob_trigger : public SpellScript
{
    PrepareSpellScript(spell_lady_vashj_summon_wave_e_mob_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_WAVE_E_MOB_1,
            SPELL_SUMMON_WAVE_E_MOB_2,
            SPELL_SUMMON_WAVE_E_MOB_3
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), RAND(SPELL_SUMMON_WAVE_E_MOB_1, SPELL_SUMMON_WAVE_E_MOB_2, SPELL_SUMMON_WAVE_E_MOB_3), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_lady_vashj_summon_wave_e_mob_trigger::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 38573 - Spore Drop Effect
class spell_lady_vashj_spore_drop_effect : public SpellScript
{
    PrepareSpellScript(spell_lady_vashj_spore_drop_effect);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TOXIC_SPORES });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TOXIC_SPORES, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lady_vashj_spore_drop_effect::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_lady_vashj_spore_drop_effect::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 39495 - Remove Tainted Cores
class spell_lady_vashj_remove_tainted_cores : public SpellScript
{
    PrepareSpellScript(spell_lady_vashj_remove_tainted_cores);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_REMOVE_TAINTED_CORES_EFFECT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_REMOVE_TAINTED_CORES_EFFECT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_lady_vashj_remove_tainted_cores::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 39496 - Remove Tainted Cores
class spell_lady_vashj_remove_tainted_cores_effect : public SpellScript
{
    PrepareSpellScript(spell_lady_vashj_remove_tainted_cores_effect);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return sObjectMgr->GetItemTemplate(ITEM_TAINTED_CORE);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            caster->DestroyItemCount(ITEM_TAINTED_CORE, 1, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_lady_vashj_remove_tainted_cores_effect::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

class item_tainted_core : public ItemScript
{
public:
    item_tainted_core() : ItemScript("item_tainted_core") { }

    bool OnRemove(Player* player, Item* /*item*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_PARALYZE);
        return false;
    }
};

void AddSC_boss_lady_vashj()
{
    RegisterSerpentshrineCavernCreatureAI(boss_lady_vashj);
    RegisterSerpentshrineCavernCreatureAI(npc_enchanted_elemental);
    RegisterSerpentshrineCavernCreatureAI(npc_tainted_elemental);
    RegisterSerpentshrineCavernCreatureAI(npc_toxic_sporebat);
    RegisterSerpentshrineCavernGameObjectAI(go_bridge_console);
    RegisterSerpentshrineCavernGameObjectAI(go_shield_generator);
    RegisterSpellScript(spell_lady_vashj_summon_wave_mob_trigger);
    RegisterSpellScript(spell_lady_vashj_summon_wave_e_mob_trigger);
    RegisterSpellScript(spell_lady_vashj_spore_drop_effect);
    RegisterSpellScript(spell_lady_vashj_remove_tainted_cores);
    RegisterSpellScript(spell_lady_vashj_remove_tainted_cores_effect);
    new item_tainted_core();
}
