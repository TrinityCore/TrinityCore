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
TODO List:
- This whole rewinding process is one big mess at the moment. Need to check for more serverside spells to clean this up.
- Distortion Bomb timers are quite inconsistent after two and more rewinds in sniffs. Need clearer data.
*/

#include "end_time.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MapRefManager.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum Spells
{
    // Murozond
    SPELL_SANDS_OF_THE_HOURGLASS                = 102668,
    SPELL_TEMPORAL_SNAPSHOT                     = 101592,
    SPELL_TEMPORAL_BLAST                        = 102381,
    SPELL_DISTORTION_BOMB_1                     = 101983,
    SPELL_DISTORTION_BOMB_2                     = 102516,
    SPELL_TAIL_SWEEP                            = 108589,
    SPELL_DISTORTION_BOMB_REWIND_TIME           = 102652, // Casted when rewinding time.
    SPELL_BLESSING_OF_THE_BRONZE_DRAGON_FLIGHT  = 102364,
    SPELL_INFINITE_BREATH                       = 102569,
    SPELL_ACHIEVEMENT_CREDIT                    = 110158, // Serverside Spell
    SPELL_FADING                                = 107550,

    // Mirror Image
    SPELL_CLONE_ME                              = 45204,
    SPELL_TRACK_MASTER_HELPFUL_AURAS            = 102541,
    SPELL_CLONE_MASTER_HEALTH                   = 102571,
    SPELL_COPY_OFFHAND_WEAPON                   = 45206,
    SPELL_COPY_WEAPON                           = 41055,
    SPELL_TELEPORT_TO_TARGET                    = 102818,
    SPELL_MARK_MASTER_AS_SUMMONED               = 80927, // Todo: research
    SPELL_MARK_MASTER_AS_DESUMMONED             = 80929, // Todo: research and when exactly to use.
    SPELL_TEMPORAL_DISPLACEMENT                 = 80354,
    SPELL_EXHAUSTION                            = 57723,
    SPELL_SATED                                 = 57724
};

enum Events
{
    // Murozond
    EVENT_LAND = 1,
    EVENT_TEMPORAL_SNAPSHOT,
    EVENT_TEMPORAL_BLAST,
    EVENT_INFINITE_BREATH,
    EVENT_REENGAGE_PLAYERS,
    EVENT_DESPAWN,

    // Mirror Image
    EVENT_UNROOT_SUMMONER,
    EVENT_MOVE_SUMMONER_BACK,
    EVENT_TELEPORT_SUMMONER
};

enum Actions
{
    // Murozond and Mirror Image
    ACTION_REWIND_TIME      = 1,

    // Nozdormu
    ACTION_ENCOUNTER_INTRO  = 1,
    ACTION_ENCOUNTER_OUTRO  = 2
};

enum Texts
{
    // Murozond
    SAY_INTRO_1             = 0,
    SAY_INTRO_2             = 1,
    SAY_AGGRO               = 2,
    SAY_REWIND_TIME         = 3, // offset until group Id 7
    SAY_DEATH               = 8
};

enum MovePoints
{
    // Murozond
    POINT_ARENA = 1,
    POINT_LAND  = 2
};

enum Misc
{
    AI_ANIM_KIT_MIRROR_IMAGE            = 1552,
    AI_ANIM_KIT_MUROZOND_DEATH          = 1034
};

Position const ArenaFlightPosition                  = { 4181.117f, -420.21933f, 138.38057f };
Position const ArenaLandPosition                    = { 4181.117f, -420.21933f, 119.77462f };
constexpr float FlightPreFightOrientation           = 3.1066861f;

std::array<Milliseconds, 4> DistortionBombIntervals =
{
    6s,
    2s,
    1s + 500ms,
    1s + 500ms
};

struct boss_murozond : public BossAI
{
    boss_murozond(Creature* creature) : BossAI(creature, DATA_MUROZOND), _rewindTimeCount(0), _defeated(false) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisableGravity(true);
        me->SetHover(true);
    }

    void JustAppeared() override
    {
        if (instance->GetBossState(DATA_MUROZOND) == FAIL)
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        _Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith(who);
        instance->DoCastSpellOnPlayers(SPELL_SANDS_OF_THE_HOURGLASS);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        Talk(SAY_AGGRO);
        DoCastAOE(SPELL_TEMPORAL_SNAPSHOT);
        events.ScheduleEvent(EVENT_LAND, 3s + 500ms);

        if (Creature* nozdormu = instance->GetCreature(DATA_NOZDORMU_BRONZE_DRAGON_SHRINE))
            if (nozdormu->IsAIEnabled)
                nozdormu->AI()->DoAction(ACTION_ENCOUNTER_INTRO);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        if (GameObject* hourglass = instance->GetGameObject(DATA_HOURGLASS_OF_TIME))
            hourglass->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SANDS_OF_THE_HOURGLASS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TEMPORAL_BLAST);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_MUROZOND, FAIL);
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_ARENA:
                me->setActive(false);
                me->SetFacingTo(FlightPreFightOrientation);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                break;
            case POINT_LAND:
                me->SetDisableGravity(false);
                me->SetHover(false);
                me->SetReactState(REACT_AGGRESSIVE);
                events.ScheduleEvent(EVENT_TEMPORAL_BLAST, 5s);
                events.ScheduleEvent(EVENT_INFINITE_BREATH, 8s + 500ms);

                if (GameObject* hourglass = instance->GetGameObject(DATA_HOURGLASS_OF_TIME))
                    hourglass->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                // Distortion bombs are being executed independently from events
                scheduler.Schedule(1ms, [this](TaskContext task)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true))
                        me->CastSpell(target, SPELL_DISTORTION_BOMB_1, true); // No DoCast here because we have to bypass the casting state check.

                    task.Repeat(6s);
                });
                break;
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case DATA_MUROZOND_INTRO:
                if (data == IN_PROGRESS)
                    Talk(SAY_INTRO_1);
                else if (data == DONE)
                {
                    Talk(SAY_INTRO_2);
                    me->setActive(true);
                    me->GetMotionMaster()->MovePoint(POINT_ARENA, ArenaFlightPosition, false);
                }
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_REWIND_TIME: // This whole action is triggered by a serverside spell so we have creative freedom here.
                Talk(SAY_REWIND_TIME + _rewindTimeCount);
                ++_rewindTimeCount;

                if (_rewindTimeCount == 5)
                    if (GameObject* hourglass = instance->GetGameObject(DATA_HOURGLASS_OF_TIME))
                        hourglass->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                me->InterruptNonMeleeSpells(true);
                me->AttackStop();
                me->StopMoving();
                me->SetReactState(REACT_PASSIVE);
                me->CancelSpellMissiles(SPELL_DISTORTION_BOMB_1, true);
                me->CancelSpellMissiles(SPELL_DISTORTION_BOMB_2, true);
                me->RemoveAllDynObjects();

                for (auto& itr : instance->instance->GetPlayers())
                {
                    if (Player* player = itr.GetSource())
                    {
                        if (player->HasAura(SPELL_SANDS_OF_THE_HOURGLASS))
                        {
                            if (player->isDead())
                                player->ResurrectPlayer(100.f);

                            player->SetPower(POWER_ALTERNATE_POWER, player->GetMaxPower(POWER_ALTERNATE_POWER) - _rewindTimeCount);
                            player->GetSpellHistory()->ResetAllCooldowns(); // Todo: does this really reset ALL of them or just class specific spells? (thinking about profession cooldowns)
                        }
                    }
                }

                instance->DoCastSpellOnPlayers(SPELL_BLESSING_OF_THE_BRONZE_DRAGON_FLIGHT);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TEMPORAL_BLAST);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_EXHAUSTION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SATED);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TEMPORAL_DISPLACEMENT);

                scheduler.CancelAll();
                events.Reset();
                events.ScheduleEvent(EVENT_REENGAGE_PLAYERS, 7s);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (damage >= me->GetHealth())
        {
            damage = me->GetHealth() - 1;

            if (!_defeated)
            {
                _defeated = true;
                _JustDied();
                me->InterruptNonMeleeSpells(true);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->SetAIAnimKitId(AI_ANIM_KIT_MUROZOND_DEATH);
                me->CancelSpellMissiles(SPELL_DISTORTION_BOMB_1, true);
                me->CancelSpellMissiles(SPELL_DISTORTION_BOMB_2, true);
                me->RemoveAllDynObjects();
                DoCastSelf(SPELL_FADING);
                DoCastAOE(SPELL_ACHIEVEMENT_CREDIT);
                Talk(SAY_DEATH);

                if (GameObject* hourglass = instance->GetGameObject(DATA_HOURGLASS_OF_TIME))
                    hourglass->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                if (Creature* nozdormu = instance->GetCreature(DATA_NOZDORMU_BRONZE_DRAGON_SHRINE))
                    if (nozdormu->IsAIEnabled)
                        nozdormu->AI()->DoAction(ACTION_ENCOUNTER_OUTRO);

                events.ScheduleEvent(EVENT_DESPAWN, 7s);
                instance->instance->PermBindAllPlayers();
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SANDS_OF_THE_HOURGLASS);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TEMPORAL_BLAST);
                if (Player* player = me->GetLootRecipient())
                    player->RewardPlayerAndGroupAtKill(me, false);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);
        scheduler.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LAND:
                    me->GetMotionMaster()->MoveLand(POINT_LAND, ArenaLandPosition, 10.f);
                    break;
                case EVENT_TEMPORAL_SNAPSHOT:
                    DoCastAOE(SPELL_TEMPORAL_SNAPSHOT);
                    break;
                case EVENT_TEMPORAL_BLAST:
                    DoCastVictim(SPELL_TEMPORAL_BLAST);
                    events.Repeat(12s);
                    break;
                case EVENT_INFINITE_BREATH:
                    DoCastVictim(SPELL_INFINITE_BREATH);
                    events.Repeat(23s);
                    break;
                case EVENT_REENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_TEMPORAL_BLAST, 1s);
                    events.ScheduleEvent(EVENT_INFINITE_BREATH, 10s);

                    scheduler
                        .Schedule(4s, [this](TaskContext task)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true))
                                me->CastSpell(target, SPELL_DISTORTION_BOMB_1, true);

                            
                            task.Repeat(6s);
                        })
                        .Schedule(7s, [this](TaskContext task)
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.f, true))
                                me->CastSpell(target, SPELL_DISTORTION_BOMB_2, true);

                            task.Repeat(DistortionBombIntervals[_rewindTimeCount - 1]);
                        });
                    break;
                case EVENT_DESPAWN:
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon();
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    uint8 _rewindTimeCount;
    bool _defeated;
};

struct npc_murozond_mirror_image : public NullCreatureAI
{
    npc_murozond_mirror_image(Creature* creature) : NullCreatureAI(creature), _summon(me->ToTempSummon()) { }

    void IsSummonedBy(Unit* summoner) override
    {
        if (InstanceScript* instance = me->GetInstanceScript())
            if (Creature* murozond = instance->GetCreature(DATA_MUROZOND))
                if (murozond->IsAIEnabled)
                    murozond->AI()->JustSummoned(me);

        summoner->CastSpell(me, SPELL_CLONE_ME, true);
        DoCastAOE(SPELL_TRACK_MASTER_HELPFUL_AURAS);
        DoCastAOE(SPELL_CLONE_MASTER_HEALTH);
        DoCastAOE(SPELL_MARK_MASTER_AS_SUMMONED);
        me->SetAIAnimKitId(AI_ANIM_KIT_MIRROR_IMAGE);
        DoCast(summoner, SPELL_COPY_OFFHAND_WEAPON, true);
        DoCast(summoner, SPELL_COPY_WEAPON, true);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_REWIND_TIME:
            {
                if (!_summon)
                    break;

                Unit* summoner = _summon->GetSummoner();
                if (!summoner)
                    break;

                summoner->SetControlled(true, UNIT_STATE_ROOT);
                _events.ScheduleEvent(EVENT_UNROOT_SUMMONER, 1s + 500ms);
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_UNROOT_SUMMONER:
                    if (Unit* summoner = _summon->GetSummoner())
                    {
                        summoner->SetControlled(false, UNIT_STATE_ROOT);
                        _events.ScheduleEvent(EVENT_MOVE_SUMMONER_BACK, 1s);
                    }
                    break;
                case EVENT_MOVE_SUMMONER_BACK:
                    if (Unit* summoner = _summon->GetSummoner())
                    {
                        Movement::MoveSplineInit init(summoner);
                        init.MoveTo(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
                        init.SetBackward();
                        init.SetVelocity(40.f);
                        _events.ScheduleEvent(EVENT_TELEPORT_SUMMONER, init.Launch());
                    }
                    break;
                case EVENT_TELEPORT_SUMMONER:
                    if (Unit* summoner = _summon->GetSummoner())
                        summoner->CastSpell(me, SPELL_TELEPORT_TO_TARGET);
                    break;
                default:
                    break;
            }
        }
    }

private:
    TempSummon* _summon;
    EventMap _events;
};

// 101590 - Rewind Time
class spell_murozond_rewind_time_forcecast : public SpellScript
{
    void HandleSummon(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        Unit* target = GetHitUnit();
        target->CastSpell(target, GetSpellInfo()->Effects[effIndex].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_murozond_rewind_time_forcecast::HandleSummon, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

// 108026 - (Serverside/Non-DB2) Rewind Time
class spell_murozond_rewind_time : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        if (target->IsAIEnabled)
            target->AI()->DoAction(ACTION_REWIND_TIME);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_murozond_rewind_time::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 102571 - Clone Master Health
class spell_murozond_clone_master_health : public SpellScript
{
    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsSummon())
            return;

        TempSummon* summon = caster->ToTempSummon();
        if (Unit* summoner = summon->GetSummoner())
        {
            summon->SetMaxHealth(summoner->GetHealth());
            summon->SetFullHealth();
        }
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_murozond_clone_master_health::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_murozond()
{
    RegisterEndTimeCreatureAI(boss_murozond);
    RegisterEndTimeCreatureAI(npc_murozond_mirror_image);
    RegisterSpellScript(spell_murozond_rewind_time_forcecast);
    RegisterSpellScript(spell_murozond_rewind_time);
    RegisterSpellScript(spell_murozond_clone_master_health);
}
