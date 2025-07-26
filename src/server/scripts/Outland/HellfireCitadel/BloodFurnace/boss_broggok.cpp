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

#include "ScriptMgr.h"
#include "blood_furnace.h"
#include "Containers.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum BroggokTexts
{
    SAY_INTRO                        = 0,
    SAY_AGGRO                        = 1
};

enum BroggokSpells
{
    SPELL_SLIME_SPRAY                = 30913,
    SPELL_POISON_BOLT                = 30917,
    SPELL_POISON_CLOUD               = 30916,

    SPELL_SUMMON_INCOMBAT_TRIGGER    = 26837,
    SPELL_DESPAWN_INCOMBAT_TRIGGER   = 26838,

    // Cloud
    SPELL_POISON_CLOUD_PASSIVE       = 30914,

    // Prisioners
    SPELL_STOMP                      = 31900,
    SPELL_CONCUSSION_BLOW            = 22427,
    SPELL_FRENZY                     = 8269,
    SPELL_CHARGE                     = 22120
};

enum BroggokEvents
{
    EVENT_SLIME_SPRAY                = 1,
    EVENT_POISON_BOLT,
    EVENT_POISON_CLOUD,

    EVENT_INTRO_1,
    EVENT_INTRO_2,

    EVENT_ACTIVATE_1,
    EVENT_ACTIVATE_2
};

enum BroggokMisc
{
    PATH_ROOM                        = 1381150,
    NPC_BROGGOK_POISON_CLOUD         = 17662,
    NPC_INCOMBAT_TRIGGER             = 16006
};

// 17380 - Broggok
struct boss_broggok : public BossAI
{
    boss_broggok(Creature* creature) : BossAI(creature, DATA_BROGGOK) { }

    void Reset() override
    {
        _Reset();
        DoAction(ACTION_RESET_BROGGOK);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        DoCastSelf(SPELL_DESPAWN_INCOMBAT_TRIGGER);

        events.ScheduleEvent(EVENT_SLIME_SPRAY, 8s, 12s);
        events.ScheduleEvent(EVENT_POISON_BOLT, 2s, 10s);
        events.ScheduleEvent(EVENT_POISON_CLOUD, 5s, 10s);
    }

    void JustSummoned(Creature* summoned) override
    {
        if (summoned->GetEntry() == NPC_BROGGOK_POISON_CLOUD)
        {
            summoned->SetReactState(REACT_PASSIVE);
            summoned->CastSpell(summoned, SPELL_POISON_CLOUD_PASSIVE, true);
            summons.Summon(summoned);
        }
        else if (summoned->GetEntry() == NPC_INCOMBAT_TRIGGER)
        {
            summoned->SetReactState(REACT_PASSIVE);
            DoZoneInCombat(summoned);
            summons.Summon(summoned);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnEntry(NPC_BROGGOK_POISON_CLOUD);
        DoCastSelf(SPELL_DESPAWN_INCOMBAT_TRIGGER, true);
        instance->SetBossState(DATA_BROGGOK, NOT_STARTED);
        _DespawnAtEvade();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PREPARE_BROGGOK:
                events.ScheduleEvent(EVENT_INTRO_1, 0s);
                break;
            case ACTION_ACTIVATE_BROGGOK:
                events.ScheduleEvent(EVENT_ACTIVATE_1, 0s);
                break;
            case ACTION_RESET_BROGGOK:
                me->SetReactState(REACT_PASSIVE);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                summons.DespawnEntry(NPC_BROGGOK_POISON_CLOUD);
                DoCastSelf(SPELL_DESPAWN_INCOMBAT_TRIGGER);
                instance->SetBossState(DATA_BROGGOK, NOT_STARTED);
                if (GameObject * lever = instance->GetGameObject(DATA_BROGGOK_LEVER))
                {
                    lever->RemoveFlag(GO_FLAG_NOT_SELECTABLE | GO_FLAG_IN_USE);
                    lever->SetGoState(GO_STATE_READY);
                }
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            UpdateOutOfCombatEvents(diff);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SLIME_SPRAY:
                    DoCastSelf(SPELL_SLIME_SPRAY);
                    events.Repeat(4s, 12s);
                    break;
                case EVENT_POISON_BOLT:
                    DoCastSelf(SPELL_POISON_BOLT);
                    events.Repeat(4s, 12s);
                    break;
                case EVENT_POISON_CLOUD:
                    DoCastSelf(SPELL_POISON_CLOUD);
                    events.Repeat(20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void UpdateOutOfCombatEvents(uint32 diff)
    {
        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    DoCastSelf(SPELL_SUMMON_INCOMBAT_TRIGGER);
                    events.ScheduleEvent(EVENT_INTRO_2, 2s);
                    break;
                case EVENT_INTRO_2:
                    Talk(SAY_INTRO);
                    break;
                case EVENT_ACTIVATE_1:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    events.ScheduleEvent(EVENT_ACTIVATE_2, 4s);
                    break;
                case EVENT_ACTIVATE_2:
                    Talk(SAY_AGGRO);
                    me->GetMotionMaster()->MovePath(PATH_ROOM, false);
                    break;
                default:
                    break;
            }
        }
    }
};

static Emote const PrisionersEmotes[] =
{
    EMOTE_ONESHOT_ROAR,
    EMOTE_ONESHOT_SHOUT,
    EMOTE_ONESHOT_BATTLE_ROAR
};

struct BroggokPrisionersAI : public ScriptedAI
{
    BroggokPrisionersAI(Creature* creature) : ScriptedAI(creature), instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        scheduler.CancelAll();
        scheduler.Schedule(1s, 5s, [this](TaskContext task)
        {
            me->HandleEmoteCommand(Trinity::Containers::SelectRandomContainerElement(PrisionersEmotes));
            task.Repeat(6s, 9s);
        });
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        scheduler.CancelAll();
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustReachedHome() override
    {
        if (instance->GetBossState(DATA_BROGGOK) == IN_PROGRESS)
        {
            if (Creature* broggok = instance->GetCreature(DATA_BROGGOK))
                broggok->AI()->DoAction(ACTION_RESET_BROGGOK);
        }

        ScriptedAI::JustReachedHome();
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

protected:
    InstanceScript* instance;
    TaskScheduler scheduler;
};

// 17398 - Nascent Fel Orc
struct npc_nascent_fel_orc : public BroggokPrisionersAI
{
    npc_nascent_fel_orc(Creature* creature) : BroggokPrisionersAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_CONCUSSION_BLOW);
                task.Repeat(8s, 11s);
            })
            .Schedule(7s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_STOMP);
                task.Repeat(16s, 21s);
            });
    }
};

// 17429 - Fel Orc Neophyte
struct npc_fel_orc_neophyte : public BroggokPrisionersAI
{
    npc_fel_orc_neophyte(Creature* creature) : BroggokPrisionersAI(creature) { }

    void ScheduleEvents() override
    {
        scheduler
            .Schedule(5s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_CHARGE);
                task.Repeat(20s);
            })
            .Schedule(1s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_FRENZY);
                task.Repeat(12s, 13s);
            });
    }
};

// 181982 - Cell Door Lever
struct go_broggok_lever : public GameObjectAI
{
    go_broggok_lever(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

    InstanceScript* instance;

    bool OnGossipHello(Player* /*player*/) override
    {
        if (instance->GetBossState(DATA_BROGGOK) != DONE && instance->GetBossState(DATA_BROGGOK) != IN_PROGRESS)
        {
            instance->SetBossState(DATA_BROGGOK, IN_PROGRESS);
            if (Creature* broggok = instance->GetCreature(DATA_BROGGOK))
                broggok->AI()->DoAction(ACTION_PREPARE_BROGGOK);
        }

        me->SetFlag(GO_FLAG_NOT_SELECTABLE | GO_FLAG_IN_USE);
        me->SetGoState(GO_STATE_ACTIVE);

        return true;
    }
};

// 30914, 38462 - Poison
class spell_broggok_poison_cloud : public AuraScript
{
    PrepareAuraScript(spell_broggok_poison_cloud);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void PeriodicTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (!aurEff->GetTotalTicks())
            return;

        uint32 triggerSpell = aurEff->GetSpellEffectInfo().TriggerSpell;
        int32 mod = int32(((float(aurEff->GetTickNumber()) / aurEff->GetTotalTicks()) * 0.9f + 0.1f) * 10000 * 2 / 3);
        GetTarget()->CastSpell(nullptr, triggerSpell, CastSpellExtraArgs(aurEff).AddSpellMod(SPELLVALUE_RADIUS_MOD, mod));
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_broggok_poison_cloud::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

void AddSC_boss_broggok()
{
    RegisterBloodFurnaceCreatureAI(boss_broggok);
    RegisterBloodFurnaceCreatureAI(npc_nascent_fel_orc);
    RegisterBloodFurnaceCreatureAI(npc_fel_orc_neophyte);
    RegisterBloodFurnaceGameObjectAI(go_broggok_lever);
    RegisterSpellScript(spell_broggok_poison_cloud);
}
