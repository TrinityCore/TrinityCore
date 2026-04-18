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
 * Combat timers requires to be revisited, seems like emerge and spout timers are randomized
 * Everything related to emerge and submerge requires sniff verification
 * SPELL_LURKER_SPAWN_TRIGGER interrupts fishing, this closes loot window
 * Verify if Lurker should emerge if all nagas are killed
 */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "serpent_shrine.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum LurkerTexts
{
    SAY_AGGRO                               = 0,
    EMOTE_SPOUT                             = 0
};

enum LurkerSpells
{
    // Combat
    SPELL_GEYSER                            = 37478,
    SPELL_WHIRL                             = 37660,
    SPELL_SPOUT                             = 37431,
    SPELL_WATER_BOLT                        = 37138,

    // Submerge
    SPELL_CLEAR_ALL_DEBUFFS                 = 34098,
    SPELL_SUBMERGE_VISUAL                   = 28819,

    // World Trigger (Not Immune PC)
    SPELL_LURKER_SPAWN_TRIGGER              = 54587,

    // Coilfang Ambusher
    SPELL_SHOOT                             = 37770,
    SPELL_SPREAD_SHOT                       = 37790,

    // Coilfang Guardian
    SPELL_HAMSTRING                         = 9080,
    SPELL_ARCING_SMASH                      = 28168,

    // Scripts
    SPELL_SPOUT_LEFT                        = 37429,
    SPELL_SPOUT_RIGHT                       = 37430
};

enum LurkerEvents
{
    EVENT_AGGRO_DELAY                       = 1,
    EVENT_GEYSER,
    EVENT_WHIRL,
    EVENT_SPOUT,
    EVENT_SPOUT_END_1,
    EVENT_SPOUT_END_2,
    EVENT_WATER_BOLT,
    EVENT_SUBMERGE,
    EVENT_EMERGE,
    EVENT_EMERGE_2,
    EVENT_EMERGE_3
};

enum LurkerSpawnGroups
{
    SPAWN_GROUP_COILFANG_AMBUSHER_1         = 348,
    SPAWN_GROUP_COILFANG_AMBUSHER_2         = 349,
    SPAWN_GROUP_COILFANG_AMBUSHER_3         = 350,
    SPAWN_GROUP_COILFANG_AMBUSHER_4         = 351,
    SPAWN_GROUP_COILFANG_AMBUSHER_5         = 352,
    SPAWN_GROUP_COILFANG_AMBUSHER_6         = 353,
    SPAWN_GROUP_COILFANG_GUARDIAN_1         = 354,
    SPAWN_GROUP_COILFANG_GUARDIAN_2         = 355,
    SPAWN_GROUP_COILFANG_GUARDIAN_3         = 356
};

enum LurkerPaths
{
    PATH_COILFANG_AMBUSHER_1                = 1474520,
    PATH_COILFANG_AMBUSHER_2                = 1474530,
    PATH_COILFANG_AMBUSHER_3                = 1474540,
    PATH_COILFANG_AMBUSHER_4                = 1474550,
    PATH_COILFANG_AMBUSHER_5                = 1474560,
    PATH_COILFANG_AMBUSHER_6                = 1474570,
    PATH_COILFANG_GUARDIAN_1                = 1474580,
    PATH_COILFANG_GUARDIAN_2                = 1474590,
    PATH_COILFANG_GUARDIAN_3                = 1474600
};

enum LurkerMisc
{
    NPC_WORLD_TRIGGER_NOT_IMMUNE_PC         = 21252,
    ACTION_SPOUT_STARTED                    = 0
};

static Position const LurkerSpawnPosition = { 38.4567f, -417.324f, -18.9167f, 2.94961f };

static constexpr std::array<uint32, 9> CoilfangNagaSpawnGroupsData =
{
    SPAWN_GROUP_COILFANG_AMBUSHER_1,
    SPAWN_GROUP_COILFANG_AMBUSHER_2,
    SPAWN_GROUP_COILFANG_AMBUSHER_3,
    SPAWN_GROUP_COILFANG_AMBUSHER_4,
    SPAWN_GROUP_COILFANG_AMBUSHER_5,
    SPAWN_GROUP_COILFANG_AMBUSHER_6,
    SPAWN_GROUP_COILFANG_GUARDIAN_1,
    SPAWN_GROUP_COILFANG_GUARDIAN_2,
    SPAWN_GROUP_COILFANG_GUARDIAN_3
};

// 21217 - The Lurker Below
struct boss_the_lurker_below : public BossAI
{
    boss_the_lurker_below(Creature* creature) : BossAI(creature, BOSS_THE_LURKER_BELOW) { }

    void InitializeAI() override
    {
        BossAI::InitializeAI();
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        events.ScheduleEvent(EVENT_AGGRO_DELAY, 4s);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_GEYSER, 10s, 15s);
        events.ScheduleEvent(EVENT_WHIRL, 10s, 20s);
        events.ScheduleEvent(EVENT_SPOUT, 45s);
        events.ScheduleEvent(EVENT_WATER_BOLT, 1200ms);
        events.ScheduleEvent(EVENT_SUBMERGE, 90s);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        /// @todo: Move this to Spout spell script in Precast hook
        if (spellInfo->Id == SPELL_SPOUT)
        {
            me->SetReactState(REACT_PASSIVE);
            Talk(EMOTE_SPOUT);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SPOUT_STARTED)
            events.ScheduleEvent(EVENT_SPOUT_END_1, 16s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        for (uint32 group : CoilfangNagaSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);

        instance->SetBossState(BOSS_THE_LURKER_BELOW, FAIL);
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        for (uint32 group : CoilfangNagaSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);
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
                case EVENT_AGGRO_DELAY:
                    me->SetReactState(REACT_AGGRESSIVE);
                    break;
                case EVENT_GEYSER:
                    if (me->GetReactState() != REACT_PASSIVE)
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                            DoCast(target, SPELL_GEYSER);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_WHIRL:
                    if (me->GetReactState() != REACT_PASSIVE)
                        DoCastSelf(SPELL_WHIRL);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_SPOUT:
                    DoCastSelf(SPELL_SPOUT);
                    events.Repeat(55s);
                    break;
                case EVENT_SPOUT_END_1:
                    me->RemoveAurasDueToSpell(SPELL_SPOUT_LEFT);
                    me->RemoveAurasDueToSpell(SPELL_SPOUT_RIGHT);
                    events.ScheduleEvent(EVENT_SPOUT_END_2, 2400ms);
                    break;
                case EVENT_SPOUT_END_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.RescheduleEvent(EVENT_WHIRL, 0s);
                    break;
                case EVENT_WATER_BOLT:
                    if (me->GetReactState() != REACT_PASSIVE)
                        if (!me->IsWithinMeleeRange(me->GetVictim()))
                            DoCastVictim(SPELL_WATER_BOLT);
                    events.Repeat(1200ms);
                    break;
                case EVENT_SUBMERGE:
                    /// @todo: This should not be called. Clear All Debuffs should remove all debuffs. Does it work? Remove this
                    me->RemoveAllAuras();
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                    DoCastSelf(SPELL_SUBMERGE_VISUAL);

                    for (uint32 group : CoilfangNagaSpawnGroupsData)
                        me->GetMap()->SpawnGroupSpawn(group, true, true);

                    me->SetStandState(UNIT_STAND_STATE_SUBMERGED);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    me->SetReactState(REACT_PASSIVE);

                    events.CancelEvent(EVENT_GEYSER);
                    events.CancelEvent(EVENT_WHIRL);
                    events.CancelEvent(EVENT_SPOUT);
                    events.CancelEvent(EVENT_WATER_BOLT);
                    events.ScheduleEvent(EVENT_EMERGE, 60s);
                    break;
                case EVENT_EMERGE:
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE_VISUAL);
                    me->SetStandState(UNIT_STAND_STATE_STAND);
                    events.ScheduleEvent(EVENT_EMERGE_2, 2s);
                    break;
                case EVENT_EMERGE_2:
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    events.ScheduleEvent(EVENT_EMERGE_3, 1s);
                    break;
                case EVENT_EMERGE_3:
                    events.ScheduleEvent(EVENT_GEYSER, 10s, 15s);
                    events.ScheduleEvent(EVENT_WHIRL, 10s, 20s);
                    events.ScheduleEvent(EVENT_SPOUT, 1s);
                    events.ScheduleEvent(EVENT_WATER_BOLT, 1200ms);
                    events.ScheduleEvent(EVENT_SUBMERGE, 90s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 21865 - Coilfang Ambusher
struct npc_coilfang_ambusher : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(GetPathId(), false);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    uint32 GetPathId() const
    {
        if (me->HasStringId("CoilfangAmbusher1"))
            return PATH_COILFANG_AMBUSHER_1;
        else if (me->HasStringId("CoilfangAmbusher2"))
            return PATH_COILFANG_AMBUSHER_2;
        else if (me->HasStringId("CoilfangAmbusher3"))
            return PATH_COILFANG_AMBUSHER_3;
        else if (me->HasStringId("CoilfangAmbusher4"))
            return PATH_COILFANG_AMBUSHER_4;
        else if (me->HasStringId("CoilfangAmbusher5"))
            return PATH_COILFANG_AMBUSHER_5;
        else if (me->HasStringId("CoilfangAmbusher6"))
            return PATH_COILFANG_AMBUSHER_6;
        return 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (roll_chance_i(25))
            Talk(SAY_AGGRO);

        _scheduler
            .Schedule(0s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f))
                    DoCast(target, SPELL_SHOOT);
                task.Repeat(3600ms, 7200ms);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_SPREAD_SHOT, { SPELLVALUE_MAX_TARGETS, 3 });
                task.Repeat(10s, 20s);
            });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->SetImmuneToPC(false);
        SetCombatMovement(false);
        DoZoneInCombat();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 21873 - Coilfang Guardian
struct npc_coilfang_guardian : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void JustAppeared() override
    {
        me->GetMotionMaster()->MovePath(GetPathId(), false);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    uint32 GetPathId() const
    {
        if (me->HasStringId("CoilfangGuardian1"))
            return PATH_COILFANG_GUARDIAN_1;
        else if (me->HasStringId("CoilfangGuardian2"))
            return PATH_COILFANG_GUARDIAN_2;
        else if (me->HasStringId("CoilfangGuardian3"))
            return PATH_COILFANG_GUARDIAN_3;
        return 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (roll_chance_i(25))
            Talk(SAY_AGGRO);

        _scheduler
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_HAMSTRING);
                task.Repeat(15s, 20s);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_ARCING_SMASH);
                task.Repeat(10s, 15s);
            });
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        me->SetImmuneToPC(false);
        DoZoneInCombat();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff);

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 184956 - Strange Pool
struct go_strange_pool : public GameObjectAI
{
    using GameObjectAI::GameObjectAI;

    bool OnGossipHello(Player* player) override
    {
        if (roll_chance_i(25))
        {
            if (Creature* trigger = GetClosestCreatureWithEntry(me, NPC_WORLD_TRIGGER_NOT_IMMUNE_PC, 50.0f))
                trigger->CastSpell(player, SPELL_LURKER_SPAWN_TRIGGER);

            me->ActivateObject(GameObjectActions(GameObjectActions::Despawn));

            me->GetMap()->SummonCreature(NPC_THE_LURKER_BELOW, LurkerSpawnPosition);
            if (InstanceScript* instance = me->GetInstanceScript())
                instance->SetBossState(BOSS_THE_LURKER_BELOW, SPECIAL);
        }

        return false;
    }
};

// 37431 - Spout
class spell_the_lurker_below_spout : public SpellScript
{
    PrepareSpellScript(spell_the_lurker_below_spout);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPOUT_LEFT, SPELL_SPOUT_RIGHT });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetCaster()->ToCreature())
        {
            creature->CastSpell(creature, RAND(SPELL_SPOUT_LEFT, SPELL_SPOUT_RIGHT), true);
            creature->AI()->DoAction(ACTION_SPOUT_STARTED);
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_the_lurker_below_spout::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 37429 - Spout
// 37430 - Spout
class spell_the_lurker_below_spout_periodic : public AuraScript
{
    PrepareAuraScript(spell_the_lurker_below_spout_periodic);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();

        float orientation = target->GetOrientation();

        switch (GetId())
        {
            case SPELL_SPOUT_LEFT:
                orientation += 5 * float(M_PI) / 180;
                break;
            case SPELL_SPOUT_RIGHT:
                orientation -= 5 * float(M_PI) / 180;
                break;
            default:
                break;
        }

        target->SetFacingTo(orientation);

        target->CastSpell(target, aurEff->GetAmount(), true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_the_lurker_below_spout_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 37433 - Spout
class spell_the_lurker_below_spout_damage : public SpellScript
{
    PrepareSpellScript(spell_the_lurker_below_spout_damage);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target)
        {
            return !target->IsUnit() || target->ToUnit()->HasUnitMovementFlag(MOVEMENTFLAG_SWIMMING);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_the_lurker_below_spout_damage::FilterTargets, EFFECT_ALL, TARGET_UNIT_CONE_ENEMY_24);
    }
};

void AddSC_boss_the_lurker_below()
{
    RegisterSerpentshrineCavernCreatureAI(boss_the_lurker_below);
    RegisterSerpentshrineCavernCreatureAI(npc_coilfang_ambusher);
    RegisterSerpentshrineCavernCreatureAI(npc_coilfang_guardian);
    RegisterSerpentshrineCavernGameObjectAI(go_strange_pool);
    RegisterSpellScript(spell_the_lurker_below_spout);
    RegisterSpellScript(spell_the_lurker_below_spout_periodic);
    RegisterSpellScript(spell_the_lurker_below_spout_damage);
}
