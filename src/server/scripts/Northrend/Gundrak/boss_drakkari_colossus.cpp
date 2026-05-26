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
 * Comment: The event with the Living Mojos is not implemented, just is done that when one of the mojos around the boss take damage will make the boss enter in combat!
 */

#include "gundrak.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "SpellScript.h"

enum DrakkariColossusTexts
{
    // Drakkari Elemental
    EMOTE_MOJO                                    = 0,
    EMOTE_ACTIVATE_ALTAR                          = 1
};

enum DrakkariColossusSpells
{
    SPELL_EMERGE                                  = 54850,
    SPELL_ELEMENTAL_SPAWN_EFFECT                  = 54888,
    SPELL_MOJO_VOLLEY                             = 54849,
    SPELL_SURGE_VISUAL                            = 54827,
    SPELL_MERGE                                   = 54878,
    SPELL_MIGHTY_BLOW                             = 54719,
    SPELL_SURGE                                   = 54801,
    SPELL_FREEZE_ANIM                             = 16245,
    SPELL_MOJO_PUDDLE                             = 55627,
    SPELL_MOJO_WAVE                               = 55626,
};

enum DrakkariColossusEvents
{
    EVENT_MIGHTY_BLOW   = 1,
    EVENT_SURGE,
    EVENT_SURGE_FINISH
};

enum DrakkariColossusActions
{
    ACTION_UNFREEZE_COLOSSUS = 1,
};

enum DrakkariColossusPhases
{
    COLOSSUS_PHASE_NORMAL,
    COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON,
    COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON
};

enum DrakkariColossusData
{
    DATA_COLOSSUS_PHASE = 1
};

enum DrakkariColossusPoints
{
    POINT_COLOSSUS = 1
};

enum DrakkariColossusSpawnGroups
{
    SPAWN_GROUP_MOJO = 328
};

struct boss_drakkari_colossus : public BossAI
{
    boss_drakkari_colossus(Creature* creature) : BossAI(creature, DATA_DRAKKARI_COLOSSUS)
    {
    }

    void Reset() override
    {
        _Reset();

        instance->instance->SpawnGroupSpawn(SPAWN_GROUP_MOJO, true);
        me->SetReactState(REACT_PASSIVE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        _JustEngagedWith(who);
        events.ScheduleEvent(EVENT_MIGHTY_BLOW, 10s, 30s);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_UNFREEZE_COLOSSUS:
                if (me->GetReactState() == REACT_AGGRESSIVE)
                    return;

                me->SetImmuneToPC(false);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAura(SPELL_FREEZE_ANIM);
                events.RescheduleEvent(EVENT_MIGHTY_BLOW, 10s, 30s);
                if (me->IsEngaged())
                {
                    if (Unit* victim = me->SelectVictim())
                        AttackStart(victim);
                }
                else
                    DoZoneInCombat();
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->IsImmuneToPC())
        {
            damage = 0;
            return;
        }

        if (!events.IsInPhase(COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON))
        {
            if (me->HealthBelowPctDamaged(events.IsInPhase(COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON) ? 5 : 50, damage))
            {
                if ((int64(me->GetHealth()) - int64(damage)) <= 0)
                    damage = me->GetHealth() - 1;
                events.SetPhase((events.IsInPhase(COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON) ? COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON : COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON));

                // Freeze Colossus
                me->SetReactState(REACT_PASSIVE);
                DoStopAttack();
                me->DoNotReacquireSpellFocusTarget();
                me->SetImmuneToPC(true);
                me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);

                DoCastSelf(SPELL_FREEZE_ANIM);
                DoCast(SPELL_EMERGE);
            }
        }
    }

    uint32 GetData(uint32 data) const override
    {
       if (data == DATA_COLOSSUS_PHASE)
           return events.GetPhaseMask();

       return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MIGHTY_BLOW:
                    DoCastVictim(SPELL_MIGHTY_BLOW);
                    events.ScheduleEvent(EVENT_MIGHTY_BLOW, 5s, 15s);
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* summon) override
    {
        if (summon->GetEntry() == NPC_DRAKKARI_ELEMENTAL && events.IsInPhase(COLOSSUS_PHASE_SECOND_ELEMENTAL_SUMMON))
        {
            summon->SetHealth(summon->GetMaxHealth() / 2);
            summon->LowerPlayerDamageReq(1);
            DoZoneInCombat(summon);
        }
        else
            BossAI::JustSummoned(summon);
    }
};

struct boss_drakkari_elemental : public ScriptedAI
{
    boss_drakkari_elemental(Creature* creature) : ScriptedAI(creature)
    {
        instance = creature->GetInstanceScript();
    }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        ScriptedAI::InitializeAI();
        DoCastSelf(SPELL_ELEMENTAL_SPAWN_EFFECT);
        SetAggressiveStateAfter(2s);
    }

    void Reset() override
    {
        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->AddAura(SPELL_MOJO_VOLLEY, me);
        events.ScheduleEvent(EVENT_SURGE, 5s, 15s);
    }

    void JustDied(Unit* killer) override
    {
        Talk(EMOTE_ACTIVATE_ALTAR);

        if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
            Unit::Kill(killer, colossus);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SURGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 0.0f, true))
                    {
                        DoStopAttack();
                        if (DoCast(target, SPELL_SURGE) == SpellCastResult::SPELL_CAST_OK)
                            events.ScheduleEvent(EVENT_SURGE_FINISH, 5s);
                        else
                            events.ScheduleEvent(EVENT_SURGE_FINISH, 0s);
                    }
                    events.ScheduleEvent(EVENT_SURGE, 5s, 15s);
                    break;
                case EVENT_SURGE_FINISH:
                    if (Unit* victim = me->SelectVictim())
                        AttackStart(victim);
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage))
        {
            if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
            {
                if (colossus->AI()->GetData(DATA_COLOSSUS_PHASE) == COLOSSUS_PHASE_FIRST_ELEMENTAL_SUMMON)
                {
                    damage = 0;

                    // to prevent spell spaming
                    if (me->HasUnitState(UNIT_STATE_CHARGING))
                        return;

                    // not sure about this, the idea of this code is to prevent bug the elemental
                    // if it is not in a acceptable distance to cast the charge spell.
                    /*if (me->GetDistance(colossus) > 80.0f)
                    {
                        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                            return;

                        me->GetMotionMaster()->MovePoint(0, colossus->GetPositionX(), colossus->GetPositionY(), colossus->GetPositionZ());
                        return;
                    }*/
                    Talk(EMOTE_MOJO);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->Clear(MOTION_PRIORITY_NORMAL);
                    DoStopAttack();
                    me->DoNotReacquireSpellFocusTarget();
                    DoCast(SPELL_SURGE_VISUAL);
                    if (Creature* colossus = instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
                        // what if the elemental is more than 80 yards from drakkari colossus ?
                        DoCast(colossus, SPELL_MERGE, true);
                }
            }
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_MERGE)
        {
            if (Creature* colossus = target->ToCreature())
            {
                colossus->AI()->DoAction(ACTION_UNFREEZE_COLOSSUS);
                me->DespawnOrUnsummon();
            }
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == EVENT_CHARGE && events.HasEventScheduled(EVENT_SURGE_FINISH))
            events.RescheduleEvent(EVENT_SURGE_FINISH, 0s);
    }

private:
    EventMap events;
    InstanceScript* instance;
};

struct npc_living_mojo : public ScriptedAI
{
    npc_living_mojo(Creature* creature) : ScriptedAI(creature)
    {
        _instance = creature->GetInstanceScript();
        if (SpawnMetadata const* data = sObjectMgr->GetSpawnMetadata(SpawnObjectType::SPAWN_TYPE_CREATURE, me->GetSpawnId()))
            if (data->spawnGroupData && data->spawnGroupData->groupId == SPAWN_GROUP_MOJO)
                me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (me->HasReactState(REACT_PASSIVE))
        {
            if (Creature* colossus = _instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
            {
                for (auto& pair : sObjectMgr->GetSpawnMetadataForGroup(SPAWN_GROUP_MOJO))
                    if (Creature* mojo = _instance->instance->GetCreatureBySpawnId(pair.second->spawnId))
                        if (mojo->GetMotionMaster()->GetCurrentMovementGeneratorType() == MovementGeneratorType::IDLE_MOTION_TYPE)
                            mojo->GetMotionMaster()->MovePoint(POINT_COLOSSUS, colossus->GetHomePosition());
                return;
            }
            else
                me->SetReactState(REACT_AGGRESSIVE);
        }

        _scheduler.Schedule(2s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MOJO_WAVE);
            task.Repeat(15s);
        })
        .Schedule(7s, [this](TaskContext task)
        {
            DoCastVictim(SPELL_MOJO_PUDDLE);
            task.Repeat(18s);
        });
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_COLOSSUS)
        {
            if (Creature* colossus = _instance->GetCreature(DATA_DRAKKARI_COLOSSUS))
                colossus->AI()->DoAction(ACTION_UNFREEZE_COLOSSUS);

            me->DespawnOrUnsummon();
        }
    }

    void UpdateAI(uint32 diff) override
    {
        //Return since we have no target
        if (!UpdateVictim())
            return;

        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 54801 - Surge
class spell_drakkari_colossus_surge : public SpellScript
{
    PrepareSpellScript(spell_drakkari_colossus_surge);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_SURGE_VISUAL });
    }

    void HandleVisual(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_SURGE_VISUAL, true);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_drakkari_colossus_surge::HandleVisual, EFFECT_1, SPELL_EFFECT_CHARGE_DEST);
    }
};

void AddSC_boss_drakkari_colossus()
{
    RegisterGundrakCreatureAI(boss_drakkari_colossus);
    RegisterGundrakCreatureAI(boss_drakkari_elemental);
    RegisterGundrakCreatureAI(npc_living_mojo);
    RegisterSpellScript(spell_drakkari_colossus_surge);
}
