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
 * Combat timers requires to be revisited, especially Romulo and Julianne
 * Romulo and Julianne encounter requires additional checks, maybe something is missing or implemented wrongly
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "karazhan.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

/*
 * Wizard of Oz Event
 */

enum WizardOfOzTexts
{
    SAY_DOROTHEE_DEATH          = 0,
    SAY_DOROTHEE_SUMMON         = 1,
    SAY_DOROTHEE_TITO_DEATH     = 2,
    SAY_DOROTHEE_AGGRO          = 3,

    SAY_ROAR_AGGRO              = 0,
    SAY_ROAR_DEATH              = 1,
    SAY_ROAR_SLAY               = 2,

    SAY_STRAWMAN_AGGRO          = 0,
    SAY_STRAWMAN_DEATH          = 1,
    SAY_STRAWMAN_SLAY           = 2,

    SAY_TINHEAD_AGGRO           = 0,
    SAY_TINHEAD_DEATH           = 1,
    SAY_TINHEAD_SLAY            = 2,
    EMOTE_RUST                  = 3,

    SAY_CRONE_AGGRO             = 0,
    SAY_CRONE_DEATH             = 1,
    SAY_CRONE_SLAY              = 2
};

enum WizardOfOzSpells
{
    // Dorothee
    SPELL_WATER_BOLT            = 31012,
    SPELL_FRIGHTENED_SCREAM     = 31013,
    SPELL_SUMMON_TITO           = 31014,

    // Strawman
    SPELL_BRAIN_BASH            = 31046,
    SPELL_BRAIN_WIPE            = 31069,

    // Tinhead
    SPELL_CLEAVE                = 31043,
    SPELL_RUST                  = 31086,

    // Roar
    SPELL_MANGLE                = 31041,
    SPELL_SHRED                 = 31042,

    // Crone
    SPELL_CHAIN_LIGHTNING       = 32337,

    // Tito
    SPELL_ANNOYING_YIPPING      = 31015,

    // Cyclone
    SPELL_CYCLONE_VISUAL        = 32332,
    SPELL_CYCLONE_1             = 32334,
    SPELL_CYCLONE_2             = 32335      // Shown in sniffs but makes cyclone overpowered, just like Karathress' cyclone
};

enum WizardOfOzMisc
{
    ACTION_TITO_DIES            = 0,
    EQUIP_ID_BROOM              = 3362,
    SPAWN_GROUP_CYCLONE         = 385,
    SPAWN_GROUP_CRONE           = 394
};

void SummonCroneIfReady(InstanceScript* _instance, Creature* creature)
{
    _instance->SetData(DATA_OPERA_OZ_DEATH_COUNT, SPECIAL);

    if (_instance->GetData(DATA_OPERA_OZ_DEATH_COUNT) == 4)
        creature->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_CRONE, true);
}

// 17535 - Dorothee
struct boss_dorothee : public ScriptedAI
{
    boss_dorothee(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(6s, [this](TaskContext task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    Talk(SAY_DOROTHEE_AGGRO);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                    task.Repeat(5s);
                    break;
                case 1:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_TALK);
                    task.Repeat(5s);
                    break;
                case 2:
                    me->SetImmuneToPC(false);
                    DoZoneInCombat();
                    break;
                default:
                    break;
            }
        });

        _instance->HandleGameObject(ObjectGuid::Empty, false, _instance->GetGameObject(DATA_GO_STAGE_DOOR_LEFT));
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(0s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_WATER_BOLT);
                task.Repeat(2400ms);
            })
            .Schedule(10s, 20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_FRIGHTENED_SCREAM);
                task.Repeat(20s, 25s);
            })
            .Schedule(35s, [this](TaskContext /*task*/)
            {
                Talk(SAY_DOROTHEE_SUMMON);
                DoCastSelf(SPELL_SUMMON_TITO);
            });
    }

    void DoAction(int32 action) override
    {
        if (me->IsAlive())
            if (action == ACTION_TITO_DIES)
                Talk(SAY_DOROTHEE_TITO_DEATH);
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        _instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DOROTHEE_DEATH);

        SummonCroneIfReady(_instance, me);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 17543 - Strawman
struct boss_strawman : public ScriptedAI
{
    boss_strawman(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(27s, [this](TaskContext /*task*/)
        {
            me->SetImmuneToPC(false);
            DoZoneInCombat();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_STRAWMAN_AGGRO);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_BRAIN_BASH);
                task.Repeat(13s, 18s);
            })
            .Schedule(10s, 15s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f, true))
                    DoCast(target, SPELL_BRAIN_WIPE);
                task.Repeat(15s, 20s);
            });
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        _instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_STRAWMAN_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_STRAWMAN_DEATH);

        SummonCroneIfReady(_instance, me);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 17547 - Tinhead
struct boss_tinhead : public ScriptedAI
{
    boss_tinhead(Creature* creature) : ScriptedAI(creature), _isFirstRust(true), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(35s, [this](TaskContext /*task*/)
        {
            me->SetImmuneToPC(false);
            DoZoneInCombat();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_TINHEAD_AGGRO);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_CLEAVE);
                task.Repeat(5s, 10s);
            })
            .Schedule(6s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_RUST);
                task.Repeat(6s);
            });
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (_isFirstRust && spellInfo->Id == SPELL_RUST)
        {
            _isFirstRust = false;
            Talk(EMOTE_RUST);
        }
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        _instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_TINHEAD_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_TINHEAD_DEATH);

        SummonCroneIfReady(_instance, me);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    bool _isFirstRust;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 17546 - Roar
struct boss_roar : public ScriptedAI
{
    boss_roar(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(18s, [this](TaskContext /*task*/)
        {
            me->SetImmuneToPC(false);
            DoZoneInCombat();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        Talk(SAY_ROAR_AGGRO);

        _scheduler
            .SetValidator([this]
            {
                return !me->HasUnitState(UNIT_STATE_CASTING);
            })
            .Schedule(8s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_MANGLE);
                task.Repeat(10s);
            })
            .Schedule(15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_SHRED);
                task.Repeat(10s, 20s);
            });
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        _instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_ROAR_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_ROAR_DEATH);

        SummonCroneIfReady(_instance, me);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 18168 - The Crone
struct boss_crone : public BossAI
{
    boss_crone(Creature* creature) : BossAI(creature, DATA_OPERA_PERFORMANCE) { }

    void JustAppeared() override
    {
        me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_CYCLONE, true);

        scheduler.Schedule(2400ms, [this](TaskContext task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_POINT);
                    Talk(SAY_CRONE_AGGRO);
                    task.Repeat(6s);
                    break;
                case 1:
                    me->SetImmuneToPC(false);
                    DoZoneInCombat();
                    SetEquipmentSlots(false, EQUIP_ID_BROOM);
                    break;
                default:
                    break;
            }
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        scheduler.Schedule(5s, 20s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_CHAIN_LIGHTNING);
            task.Repeat(10s, 15s);
        });
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();

        me->GetMap()->SpawnGroupDespawn(SPAWN_GROUP_CYCLONE);

        instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_CRONE_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_CRONE_DEATH);

        me->GetMap()->SpawnGroupDespawn(SPAWN_GROUP_CYCLONE);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }
};

// 17548 - Tito
struct npc_tito : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetCorpseDelay(3, true);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler.Schedule(10s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_ANNOYING_YIPPING);
            task.Repeat(10s);
        });
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* summoner = summon->GetSummonerUnit())
                if (Creature* creature = summoner->ToCreature())
                    creature->AI()->DoAction(ACTION_TITO_DIES);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    TaskScheduler _scheduler;
};

// 18412 - Cyclone (The Crone)
struct npc_cyclone : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_CYCLONE_VISUAL);
        DoCastSelf(SPELL_CYCLONE_1);
    }
};

/*
 * Red Riding Hood Event
 */

enum BigBadWolfTexts
{
    SAY_WOLF_AGGRO                  = 0,
    SAY_WOLF_SLAY                   = 1,
    SAY_WOLF_HOOD                   = 2
};

enum BigBadWolfSpells
{
    // Combat
    SPELL_TERRIFYING_HOWL           = 30752,
    SPELL_WIDE_SWIPE                = 30761,
    SPELL_PICK_RED_RIDING_HOOD      = 30769,

    // Scripts
    SPELL_LITTLE_RED_RIDING_HOOD    = 30768,
    SPELL_PICNIC_BASKET_SMELL       = 30755
};

enum BigBadWolfMisc
{
    GOSSIP_MENU_GRANDMOTHER         = 7443,
    SOUND_WOLF_DEATH                = 9275,
    SPAWN_GROUP_BIG_BAD_WOLF        = 393
};

// 17603 - Grandmother
struct npc_grandmother : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 /*gossipListId*/) override
    {
        if (menuId == GOSSIP_MENU_GRANDMOTHER)
        {
            CloseGossipMenuFor(player);

            me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_BIG_BAD_WOLF, true);
            me->DespawnOrUnsummon();
        }
        return false;
    }
};

// 17521 - The Big Bad Wolf
struct boss_big_bad_wolf : public BossAI
{
    boss_big_bad_wolf(Creature* creature) : BossAI(creature, DATA_OPERA_PERFORMANCE) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);

        scheduler.Schedule(3s, [this](TaskContext /*task*/)
        {
            me->SetReactState(REACT_AGGRESSIVE);
        });

        instance->HandleGameObject(ObjectGuid::Empty, false, instance->GetGameObject(DATA_GO_STAGE_DOOR_LEFT));
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_WOLF_AGGRO);

        scheduler
            .Schedule(5s, 20s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_TERRIFYING_HOWL);
                task.Repeat(25s, 35s);
            })
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_WIDE_SWIPE);
                task.Repeat(25s, 30s);
            })
            .Schedule(3s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_PICK_RED_RIDING_HOOD);
                task.Repeat(30s);
            });
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_PICK_RED_RIDING_HOOD)
            Talk(SAY_WOLF_HOOD);
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_WOLF_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        DoPlaySoundToSet(me, SOUND_WOLF_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }
};

// 30769 - Pick Red Riding Hood
class spell_opera_pick_red_riding_hood : public SpellScript
{
    PrepareSpellScript(spell_opera_pick_red_riding_hood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LITTLE_RED_RIDING_HOOD });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        if (Creature* caster = GetCaster()->ToCreature())
        {
            caster->GetThreatManager().AddThreat(target, 1000000.0f, nullptr, true, true);
            caster->CastSpell(target, SPELL_LITTLE_RED_RIDING_HOOD, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_opera_pick_red_riding_hood::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_opera_pick_red_riding_hood::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30768 - Little Red Riding Hood
class spell_opera_little_red_riding_hood : public SpellScript
{
    PrepareSpellScript(spell_opera_little_red_riding_hood);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_PICNIC_BASKET_SMELL });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_PICNIC_BASKET_SMELL, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_opera_little_red_riding_hood::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 30755 - Picnic Basket Smell
class spell_opera_picnic_basket_smell : public AuraScript
{
    PrepareAuraScript(spell_opera_picnic_basket_smell);

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            if (Creature* target = GetTarget()->ToCreature())
                if (Unit* caster = GetCaster())
                    target->GetThreatManager().AddThreat(caster, -1000000.0f, nullptr, true, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_opera_picnic_basket_smell::AfterRemove, EFFECT_0, SPELL_AURA_MOD_TAUNT, AURA_EFFECT_HANDLE_REAL);
    }
};

/*
 * Romeo and Juliet Event
 */

enum JulianneRomuloTexts
{
    SAY_JULIANNE_AGGRO              = 0,
    SAY_JULIANNE_DEATH_1            = 1,
    SAY_JULIANNE_DEATH_2            = 2,
    SAY_JULIANNE_RESURRECT          = 3,
    SAY_JULIANNE_SLAY               = 4,

    SAY_ROMULO_AGGRO                = 0,
    SAY_ROMULO_DEATH                = 1,
    SAY_ROMULO_RESURRECT            = 2,
    SAY_ROMULO_SLAY                 = 3
};

enum JulianneRomuloSpells
{
    // Julianne
    SPELL_BLINDING_PASSION          = 30890,
    SPELL_DEVOTION                  = 30887,
    SPELL_ETERNAL_AFFECTION         = 30878,
    SPELL_POWERFUL_ATTRACTION       = 30889,

    // Romulo
    SPELL_BACKWARD_LUNGE            = 30815,
    SPELL_DEADLY_SWATHE             = 30817,
    SPELL_POISONED_THRUST           = 30822,
    SPELL_DARING                    = 30841,

    // Misc
    SPELL_DRINK_POISON              = 30907,
    SPELL_PERMANENT_FEIGN_DEATH     = 29266,
    SPELL_UNDYING_LOVE              = 30951,
    SPELL_CLEAR_ALL_DEBUFFS         = 34098,
    SPELL_FULL_HEAL                 = 43979,
    SPELL_SUICIDE_WHILE_DEAD        = 30966
};

enum JulianneRomuloEvents
{
    // Julianne - Intro
    EVENT_INTRO                     = 1,

    // Julianne - Combat
    EVENT_BLINDING_PASSION,
    EVENT_DEVOTION,
    EVENT_ETERNAL_AFFECTION,
    EVENT_POWERFUL_ATTRACTION,

    // Julianne - Transition
    EVENT_JULIANNE_TRANSITION_1_1,
    EVENT_JULIANNE_TRANSITION_1_2,
    EVENT_JULIANNE_TRANSITION_1_3,
    EVENT_JULIANNE_TRANSITION_2_1,

    // Romulo - Combat
    EVENT_BACKWARD_LUNGE,
    EVENT_DEADLY_SWATHE,
    EVENT_POISONED_THRUST,
    EVENT_DARING,

    // Romulo - Transition
    EVENT_ROMULO_TRANSITION,

    // Shared
    EVENT_FEIGN_DEATH,
    EVENT_REVIVE_OR_DIE,
    EVENT_REVIVE_SELF
};

enum JulianneRomuloMisc
{
    SPAWN_GROUP_ROMULO              = 395,
    ACTION_FINISH_TRANSITION        = 0,
    DATA_OTHER_IS_DEAD              = 0
};

enum JulianneRomuloPhases
{
    PHASE_SINGLE                    = 1,
    PHASE_DEATH                     = 2,
    PHASE_BOTH                      = 3
};

// 17534 - Julianne
struct boss_julianne : public BossAI
{
    boss_julianne(Creature* creature) : BossAI(creature, DATA_OPERA_PERFORMANCE) { }

    void JustAppeared() override
    {
        instance->HandleGameObject(ObjectGuid::Empty, false, instance->GetGameObject(DATA_GO_STAGE_DOOR_LEFT));

        events.SetPhase(PHASE_SINGLE);
        events.ScheduleEvent(EVENT_INTRO, 5s);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_JULIANNE_AGGRO);

        events.ScheduleEvent(EVENT_BLINDING_PASSION, 1ms);
        events.ScheduleEvent(EVENT_DEVOTION, 10s, 15s);
        events.ScheduleEvent(EVENT_ETERNAL_AFFECTION, 15s, 20s);
        events.ScheduleEvent(EVENT_POWERFUL_ATTRACTION, 10s, 20s);
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && who != me)
        {
            damage = me->GetHealth() -1;

            if (events.IsInPhase(PHASE_DEATH))
                return;

            if (events.IsInPhase(PHASE_SINGLE))
            {
                events.SetPhase(PHASE_DEATH);
                events.ScheduleEvent(EVENT_JULIANNE_TRANSITION_1_1, 0s);
            }
            else if (events.IsInPhase(PHASE_BOTH))
            {
                events.SetPhase(PHASE_DEATH);
                events.ScheduleEvent(EVENT_FEIGN_DEATH, 0s);
            }
        }
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_OTHER_IS_DEAD)
            return events.IsInPhase(PHASE_DEATH) ? 1 : 0;

        return 0;
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_FINISH_TRANSITION)
            events.ScheduleEvent(EVENT_JULIANNE_TRANSITION_2_1, 6s);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim != me)
            Talk(SAY_JULIANNE_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        instance->SetBossState(DATA_OPERA_PERFORMANCE, DONE);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_INTRO)
                {
                    me->SetImmuneToPC(false);
                    DoZoneInCombat();
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
                // Combat
                case EVENT_BLINDING_PASSION:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f, true))
                            DoCast(target, SPELL_BLINDING_PASSION);
                    events.Repeat(2s, 4s);
                    break;
                case EVENT_DEVOTION:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        DoCastSelf(SPELL_DEVOTION);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_ETERNAL_AFFECTION:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        if (Unit* target = DoSelectLowestHpFriendly(100.0f))
                            DoCast(target, SPELL_ETERNAL_AFFECTION);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_POWERFUL_ATTRACTION:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f, true))
                            DoCast(target, SPELL_POWERFUL_ATTRACTION);
                    events.Repeat(25s, 35s);
                    break;

                // Transition
                case EVENT_JULIANNE_TRANSITION_1_1:
                    Talk(SAY_JULIANNE_DEATH_1);
                    DoCastSelf(SPELL_DRINK_POISON);
                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_JULIANNE_TRANSITION_1_2, 2s);
                    break;
                case EVENT_JULIANNE_TRANSITION_1_2:
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    events.ScheduleEvent(EVENT_JULIANNE_TRANSITION_1_3, 6s);
                    break;
                case EVENT_JULIANNE_TRANSITION_1_3:
                    me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ROMULO, true);
                    break;

                case EVENT_JULIANNE_TRANSITION_2_1:
                    me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                    DoCastSelf(SPELL_FULL_HEAL);
                    Talk(SAY_JULIANNE_RESURRECT);
                    DoCastSelf(SPELL_UNDYING_LOVE);
                    ResetThreatList();
                    events.SetPhase(PHASE_BOTH);
                    break;

                // Misc
                case EVENT_FEIGN_DEATH:
                    Talk(SAY_JULIANNE_DEATH_2);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    events.ScheduleEvent(EVENT_REVIVE_OR_DIE, 10s);
                    break;
                case EVENT_REVIVE_OR_DIE:
                    if (Creature* romulo = instance->GetCreature(DATA_ROMULO))
                    {
                        if (romulo->AI()->GetData(DATA_OTHER_IS_DEAD))
                            DoCastSelf(SPELL_SUICIDE_WHILE_DEAD, true);
                        else
                            events.ScheduleEvent(EVENT_REVIVE_SELF, 0s);
                    }
                    break;
                case EVENT_REVIVE_SELF:
                    me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                    DoCastSelf(SPELL_FULL_HEAL);
                    ResetThreatList();
                    events.SetPhase(PHASE_BOTH);
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

// 17533 - Romulo
struct boss_romulo : public BossAI
{
    boss_romulo(Creature* creature) : BossAI(creature, DATA_OPERA_PERFORMANCE) { }

    void JustAppeared() override
    {
        DoZoneInCombat();
        events.SetPhase(PHASE_SINGLE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_ROMULO_AGGRO);

        events.ScheduleEvent(EVENT_BACKWARD_LUNGE, 10s, 20s);
        events.ScheduleEvent(EVENT_DEADLY_SWATHE, 5s, 15s);
        events.ScheduleEvent(EVENT_POISONED_THRUST, 15s, 20s);
        events.ScheduleEvent(EVENT_DARING, 20s, 25s);
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (damage >= me->GetHealth() && who != me)
        {
            damage = me->GetHealth() -1;

            if (events.IsInPhase(PHASE_DEATH))
                return;

            if (events.IsInPhase(PHASE_SINGLE))
            {
                events.SetPhase(PHASE_DEATH);
                events.ScheduleEvent(EVENT_ROMULO_TRANSITION, 0s);
            }
            else if (events.IsInPhase(PHASE_BOTH))
            {
                events.SetPhase(PHASE_DEATH);
                events.ScheduleEvent(EVENT_FEIGN_DEATH, 0s);
            }
        }
    }

    uint32 GetData(uint32 data) const override
    {
        if (data == DATA_OTHER_IS_DEAD)
            return events.IsInPhase(PHASE_DEATH) ? 1 : 0;

        return 0;
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_UNDYING_LOVE)
            events.ScheduleEvent(EVENT_REVIVE_SELF, 0s);
    }

    void JustReachedHome() override
    {
        me->DespawnOrUnsummon();
        instance->SetBossState(DATA_OPERA_PERFORMANCE, FAIL);
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim != me)
            Talk(SAY_ROMULO_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        instance->SetBossState(DATA_OPERA_PERFORMANCE, DONE);
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
                // Combat
                case EVENT_BACKWARD_LUNGE:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        DoCastSelf(SPELL_BACKWARD_LUNGE);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_DEADLY_SWATHE:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        DoCastVictim(SPELL_DEADLY_SWATHE);
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_POISONED_THRUST:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        DoCastVictim(SPELL_POISONED_THRUST);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_DARING:
                    if (!me->HasAura(SPELL_PERMANENT_FEIGN_DEATH))
                        DoCastSelf(SPELL_DARING);
                    events.Repeat(20s, 40s);
                    break;

                // Misc
                case EVENT_ROMULO_TRANSITION:
                    me->SetReactState(REACT_PASSIVE);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    Talk(SAY_ROMULO_DEATH);
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    if (Creature* julianne = instance->GetCreature(DATA_JULIANNE))
                        julianne->AI()->DoAction(ACTION_FINISH_TRANSITION);
                    break;
                case EVENT_FEIGN_DEATH:
                    me->SetReactState(REACT_PASSIVE);
                    me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                    events.ScheduleEvent(EVENT_REVIVE_OR_DIE, 10s);
                    break;
                case EVENT_REVIVE_OR_DIE:
                    if (Creature* julianne = instance->GetCreature(DATA_JULIANNE))
                    {
                        if (julianne->AI()->GetData(DATA_OTHER_IS_DEAD))
                            DoCastSelf(SPELL_SUICIDE_WHILE_DEAD, true);
                        else
                        {
                            Talk(SAY_ROMULO_RESURRECT);
                            events.ScheduleEvent(EVENT_REVIVE_SELF, 0s);
                        }
                    }
                    break;
                case EVENT_REVIVE_SELF:
                    me->RemoveAurasDueToSpell(SPELL_PERMANENT_FEIGN_DEATH);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    DoCastSelf(SPELL_CLEAR_ALL_DEBUFFS);
                    DoCastSelf(SPELL_FULL_HEAL);
                    ResetThreatList();
                    events.SetPhase(PHASE_BOTH);
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

void AddSC_bosses_opera()
{
    RegisterKarazhanCreatureAI(boss_dorothee);
    RegisterKarazhanCreatureAI(boss_strawman);
    RegisterKarazhanCreatureAI(boss_tinhead);
    RegisterKarazhanCreatureAI(boss_roar);
    RegisterKarazhanCreatureAI(boss_crone);
    RegisterKarazhanCreatureAI(npc_tito);
    RegisterKarazhanCreatureAI(npc_cyclone);
    RegisterKarazhanCreatureAI(npc_grandmother);
    RegisterKarazhanCreatureAI(boss_big_bad_wolf);
    RegisterSpellScript(spell_opera_pick_red_riding_hood);
    RegisterSpellScript(spell_opera_little_red_riding_hood);
    RegisterSpellScript(spell_opera_picnic_basket_smell);
    RegisterKarazhanCreatureAI(boss_julianne);
    RegisterKarazhanCreatureAI(boss_romulo);
}
