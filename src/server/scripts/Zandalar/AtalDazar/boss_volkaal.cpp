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

#include "Creature.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "atal_dazar.h"

enum spell
{
    //Totems
    SPELL_REANIMATION_TOTEM_HEAL                = 259531,
    SPELL_BAD_VODOO                             = 250192, //Npc heals if totmes are alive, Each totem is supposed to add 1 stack of this to the boss
    //Toxic Leap
    SPELL_TOXIC_LEAP_DUMMY                      = 250708, //Targes
    SPELL_TOXIC_LEAP                            = 250258, //Jumps to the position of the player (phase 1)
    SPELL_TOXIC_LEAP_LANDING                    = 250259, //Cast after landing

    SPELL_NOXIOUS_STENCH                        = 259572, //Chanelled and adds a debuff to the whole party
    SPELL_NOXIOUS_STENCH_DMG                    = 250368,
    SPELL_LINGERING_NAUSEA                      = 250372, //aura added
    //Rapid Decay
    SPELL_RAPID_DECAY_BOSS_AURA                 = 250241, //Added to the boss after the totems get destroyed
    SPELL_RAPID_DECAY_AREATRIGGER               = 250696, //also creates an areatrigger
    SPELL_RAPID_DECAY_AREATRIGGER_MISSLE        = 250697, //creates an areatrigger random
    SPELL_RAPID_DECAY_AREATRIGGER_MISSLE2       = 250694, // creates an areatrigger at target

    SPELL_CREATE_TOXI_POOL_AREATRIGGER          = 263922, //Creates the areatrigger for the toxic pool

    SPELL_TOXIC_POOLS_AURA                      = 263927  //Gets applied while you're standing in a toxic pool

    // sniffs uses 259114? 250694, 250697,
    // areatrigger used from spell 250696
    // 250696 11243
};

enum Actions
{
    ACTION_TOTEM_DIED = 0,
    ACTION_TOTEM_HEALED,
};

enum NPCs
{
    NPC_REANIMATION_TOTEM = 125977
};

enum Events : uint32
{
    EVENT_REANIMATION_TOTEM_HEAL = 0,
    EVENT_BAD_VODOO,
    EVENT_TOXIC_LEAP,
    EVENT_NOXIOUS_STENCH,
    EVENT_RAPID_DECAY,
    EVENT_TOXIC_POOLS_AURA,
    EVENT_JUMP_DAMAGE,
    EVENT_TOXIC_POOL,
    EVENT_CLOSE_DOOR,
};

enum Talks
{
    TALK_AGGRO = 0,
    TALK_PHASE_TWO,
    TALK_DEATH,
};

enum Areatriggers
{
    AREATRIGGER_TOXIC_POOL = 16029,
};

Position totemSpawns[] =
{
    { -636.18f, 2316.12f, 709.963f },
    { -591.24f, 2292.44f, 709.968f },
    { -636.028f, 2269.22f, 709.974f }
};

void OpenBossGate(InstanceScript* instance)
{
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_005)))
        go->SetGoState(GO_STATE_ACTIVE);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_006)))
        go->SetGoState(GO_STATE_ACTIVE);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_007)))
        go->SetGoState(GO_STATE_ACTIVE);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_008)))
        go->SetGoState(GO_STATE_ACTIVE);
};
void CloseBossGate(InstanceScript* instance)
{
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_005)))
        go->SetGoState(GO_STATE_READY);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_006)))
        go->SetGoState(GO_STATE_READY);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_007)))
        go->SetGoState(GO_STATE_READY);
    if (GameObject* go = instance->instance->GetGameObject(instance->GetGuidData(GO_GATE_008)))
        go->SetGoState(GO_STATE_READY);
};

struct boss_ataldazar_volkaal : public BossAI
{
    boss_ataldazar_volkaal(Creature* creature) : BossAI(creature, DATA_VOLKAAL) { }

    void InitializeAI() override
    {
        totemsDead = 0;
        BossAI::InitializeAI();
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_TOXIC_LEAP_DUMMY)
            me->CastSpell(target, SPELL_TOXIC_LEAP);
        if (spell->Id == SPELL_NOXIOUS_STENCH_DMG)
            me->CastSpell(target, SPELL_LINGERING_NAUSEA, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
    }

    void Reset() override
    {
        phase = 1;

        events.Reset();
        summons.DespawnAll();
        OpenBossGate(instance);
        totemsDead = 0;

        if (me->HasAura(SPELL_BAD_VODOO))
            me->RemoveAura(SPELL_BAD_VODOO);

        for (Position point : totemSpawns)
            me->SummonCreature(NPC_REANIMATION_TOTEM, point, TEMPSUMMON_MANUAL_DESPAWN);

        AreaTriggerList triggers;
        me->GetAreatriggerListInRange(triggers, 50.0f);
        for (AreaTrigger* trigger : triggers)
        {
            if (trigger->GetEntry() == AREATRIGGER_TOXIC_POOL)
            {
                trigger->Remove();
            }
        }
    }

    void EnterCombat(Unit* who) override
    {
        Talk(TALK_AGGRO);
        // Events
        events.ScheduleEvent(EVENT_CLOSE_DOOR, 1800);
        events.ScheduleEvent(EVENT_TOXIC_LEAP, 2000);
        events.ScheduleEvent(EVENT_NOXIOUS_STENCH, 6000);

        BossAI::EnterCombat(who);
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
            case EVENT_JUMP_DAMAGE:
            {
                me->CastSpell(me, SPELL_TOXIC_LEAP_LANDING, true);
                break;
            }
            case EVENT_NOXIOUS_STENCH:
            {
                me->CastSpell(me->GetVictim(), SPELL_NOXIOUS_STENCH);
                //Noxious Stench adds a delay on toxic leap
                if (phase == 1)
                {
                    events.DelayEvent(EVENT_TOXIC_LEAP, 2000);
                    events.ScheduleEvent(EVENT_NOXIOUS_STENCH, 18200);
                }
                if (phase == 2)
                {
                    events.ScheduleEvent(EVENT_NOXIOUS_STENCH, 20600);
                }
                break;
            }
            case EVENT_TOXIC_LEAP:
            {
                me->CastSpell(me, SPELL_TOXIC_LEAP_DUMMY);
                events.ScheduleEvent(EVENT_JUMP_DAMAGE, 3500);
                events.ScheduleEvent(EVENT_TOXIC_LEAP, 6000);
                break;
            }
            case EVENT_TOXIC_POOL:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(target, SPELL_RAPID_DECAY_AREATRIGGER_MISSLE2, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
                me->CastSpell(me, SPELL_RAPID_DECAY_AREATRIGGER_MISSLE, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
                events.ScheduleEvent(EVENT_TOXIC_POOL, 1000);
                break;
            }
            case EVENT_CLOSE_DOOR:
                CloseBossGate(instance);
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_TOTEM_DIED:
        {
            if (totemsDead < 3)
            {
                totemsDead++;

                if (me->HasAura(SPELL_BAD_VODOO))
                    me->RemoveAuraFromStack(SPELL_BAD_VODOO);
            }
            if (totemsDead == 3)
            {
                Talk(TALK_PHASE_TWO);

                phase = 2;

                me->AddAura(SPELL_RAPID_DECAY_BOSS_AURA);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    me->InterruptNonMeleeSpells(0);

                summons.DespawnAll();

                events.CancelEvent(EVENT_TOXIC_LEAP);
                events.CancelEvent(EVENT_TOXIC_POOL);
                events.ScheduleEvent(EVENT_TOXIC_POOL, 800);
            }
            break;
        }
        case ACTION_TOTEM_HEALED:
        {
            totemsDead--;
            break;
        }
        default:
            break;
        }
    }

    void JustDied(Unit* killer) override
    {
        Talk(TALK_DEATH);
        _JustDied();
        instance->SetBossState(DATA_VOLKAAL, DONE);
        OpenBossGate(instance);
        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 100.0f);
        for (auto player : playerList)
        {
            if (player->HasAura(SPELL_UNSTABLE_HEX))
            {
                int cont = instance->GetData(DATA_ACHIEVEMENT_COUNT);
                instance->SetData(DATA_ACHIEVEMENT_COUNT, cont++);
                break;
            }
        }
        //DoPlayConversation();
    }

private:
    uint8 totemsDead;
    uint8 phase;
};

struct npc_ataldazar_reanimation_totem : public ScriptedAI
{
    npc_ataldazar_reanimation_totem(Creature* pCreature) : ScriptedAI(pCreature) { }

    void Reset() override
    {
        events.Reset();
        me->setActive(false);

        if (Creature* volkaal = me->FindNearestCreature(NPC_VOLKAAL, 100))
            volkaal->AddAura(SPELL_BAD_VODOO);
    }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        ScriptedAI::InitializeAI();
    }

    void DamageTaken(Unit* /*who*/, uint32& damage) override
    {
        if (damage >= me->GetHealth())
        {
            if (IsHeroic() || IsMythic())
            {
                damage = me->GetHealth() - 1;
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                {
                    me->CastSpell(me, SPELL_REANIMATION_TOTEM_HEAL);
                    if (Creature* boss = me->FindNearestCreature(NPC_VOLKAAL, 100.f))
                        boss->AI()->DoAction(ACTION_TOTEM_DIED);
                }
            }
            if (!IsHeroic() && !IsMythic())
            {
                if (Creature* boss = me->FindNearestCreature(NPC_VOLKAAL, 100.f))
                    boss->AI()->DoAction(ACTION_TOTEM_DIED);
                me->DespawnOrUnsummon();
            }
        }
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* /*spell*/) override
    {
        if (Creature* boss = me->FindNearestCreature(NPC_VOLKAAL, 100.f))
            boss->AI()->DoAction(ACTION_TOTEM_HEALED);
    }

    void EnterCombat(Unit* attacker) override
    {
        if (Unit* boss = me->FindNearestCreature(NPC_VOLKAAL, 50, true))
        {
            if (!boss->IsInCombat())
            {
                me->CallAssistance();
                boss->SetInCombatWith(attacker);
                attacker->SetInCombatWith(boss);
                boss->AddThreat(attacker, 0.1f);
                boss->Attack(attacker, true);
            }
        }
    }

    void UpdateAI(uint32 /*diff*/) override
    {
    }
};


void AddSC_boss_volkaal()
{
    RegisterCreatureAI(boss_ataldazar_volkaal);
    RegisterCreatureAI(npc_ataldazar_reanimation_totem);
}
