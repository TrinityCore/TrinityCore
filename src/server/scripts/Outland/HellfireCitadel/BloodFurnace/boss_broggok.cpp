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
 */

#include "ScriptMgr.h"
#include "blood_furnace.h"
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
    SAY_AGGRO                        = 1,

    SAY_PRISONER_AGGRO               = 0
};

enum BroggokSpells
{
    // Broggok - Combat
    SPELL_SLIME_SPRAY                = 30913,
    SPELL_POISON_BOLT                = 30917,
    SPELL_POISON_CLOUD               = 30916,

    // Broggok - Misc
    SPELL_SUMMON_INCOMBAT_TRIGGER    = 26837,
    SPELL_DESPAWN_INCOMBAT_TRIGGER   = 26838,

    // Nascent Fel Orc
    SPELL_CONCUSSION_BLOW            = 22427,
    SPELL_STOMP                      = 31900,

    // Fel Orc Neophyte
    SPELL_CHARGE                     = 22120,
    SPELL_FRENZY                     = 8269
};

enum BroggokEvents
{
    EVENT_SLIME_SPRAY                = 1,
    EVENT_POISON_BOLT,
    EVENT_POISON_CLOUD,

    EVENT_INTRO_1,
    EVENT_INTRO_2,

    EVENT_RELEASE_1,
    EVENT_RELEASE_2
};

enum BroggokMisc
{
    PATH_ROOM                        = 11049200
};

// 17380 - Broggok
struct boss_broggok : public BossAI
{
    boss_broggok(Creature* creature) : BossAI(creature, DATA_BROGGOK) { }

    void JustAppeared() override
    {
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        DoCastSelf(SPELL_DESPAWN_INCOMBAT_TRIGGER);

        events.ScheduleEvent(EVENT_SLIME_SPRAY, 5s, 15s);
        events.ScheduleEvent(EVENT_POISON_BOLT, 0s, 5s);
        events.ScheduleEvent(EVENT_POISON_CLOUD, 5s, 20s);
    }

    // Do nothing, don't store summons, don't despawn them in case of wipe or death - correct behavior
    void JustSummoned(Creature* /*summoned*/) override { }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 /*pathId*/) override
    {
        DoZoneInCombat();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_PERFORM_INTRO:
                events.ScheduleEvent(EVENT_INTRO_1, 0s);
                break;
            case ACTION_RELEASE_BROGGOK:
                events.ScheduleEvent(EVENT_RELEASE_1, 0s);
                break;
            case ACTION_DESPAWN_TRIGGER:
                DoCastSelf(SPELL_DESPAWN_INCOMBAT_TRIGGER);
                break;
            default:
                break;
        }
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

                case EVENT_RELEASE_1:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                    events.ScheduleEvent(EVENT_RELEASE_2, 5s);
                    break;
                case EVENT_RELEASE_2:
                    Talk(SAY_AGGRO);
                    me->GetMotionMaster()->MovePath(PATH_ROOM, false);
                    break;
                default:
                    break;
            }
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
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_POISON_BOLT:
                    DoCastSelf(SPELL_POISON_BOLT);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_POISON_CLOUD:
                    DoCastSelf(SPELL_POISON_CLOUD);
                    events.Repeat(10s, 25s);
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

struct BroggokPrisionerBaseAI : public ScriptedAI
{
    BroggokPrisionerBaseAI(Creature* creature) : ScriptedAI(creature), EmoteCounter(0), Instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        if (IsHighCellPrisoner())
        {
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_PASSIVE);
            me->SetImmuneToNPC(true);
        }
        else if (IsCellPrisoner())
        {
            me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_PASSIVE);
            DoStartEmotesTask();
        }
    }

    void Reset() override
    {
        Scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        if (IsCellPrisoner())
            Scheduler.CancelAll();

        ScheduleEvents();

        if (roll_chance_i(15))
            Talk(SAY_PRISONER_AGGRO);
    }

    bool IsHighCellPrisoner()
    {
        return me->HasStringId("BroggokPrisonerHighCell");
    }

    bool IsCellPrisoner()
    {
        return me->HasStringId("BroggokPrisonerCell1") || me->HasStringId("BroggokPrisonerCell2") || me->HasStringId("BroggokPrisonerCell3") || me->HasStringId("BroggokPrisonerCell4");
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_PRISONER_ENGAGE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_AGGRESSIVE);
            DoZoneInCombat();
        }
    }

    void DoStartEmotesTask()
    {
        // Timer is random but all prisoners from the same cell plays emote at the same time,
        // meaning they are in same spawn group and event is linked to all spawn group members.
        // We can't support that for now in an easy way
        EmoteCounter = 1;

        Scheduler.Schedule(6s, 12s, [this](TaskContext task)
        {
            switch (EmoteCounter)
            {
                case 1:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_SHOUT);
                    break;
                case 2:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                    break;
                case 3:
                    me->HandleEmoteCommand(EMOTE_ONESHOT_BATTLE_ROAR);
                    break;
                default:
                    break;
            }

            if (EmoteCounter >= 3)
                EmoteCounter = 1;
            else
                ++EmoteCounter;

            task.Repeat(6s, 12s);
        });
    }

    virtual void ScheduleEvents() = 0;

    void JustReachedHome() override
    {
        ScriptedAI::JustReachedHome();

        if (!IsCellPrisoner())
            return;

        Instance->SetData(DATA_PRISONERS_EVENT, FAIL);

        // This is not correct in case of wipe. Flags aren't set back. We do it for safety reasons
        me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
        me->SetReactState(REACT_PASSIVE);
        DoStartEmotesTask();
    }

    void UpdateAI(uint32 diff) override
    {
        Scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

protected:
    uint8 EmoteCounter;
    InstanceScript* Instance;
    TaskScheduler Scheduler;
};

// 17398 - Nascent Fel Orc
struct npc_nascent_fel_orc : public BroggokPrisionerBaseAI
{
    using BroggokPrisionerBaseAI::BroggokPrisionerBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 15s, [this](TaskContext task)
            {
                DoCastVictim(SPELL_CONCUSSION_BLOW);
                task.Repeat(20s, 30s);
            })
            .Schedule(0s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_STOMP);
                task.Repeat(10s, 20s);
            });
    }
};

// 17429 - Fel Orc Neophyte
struct npc_fel_orc_neophyte : public BroggokPrisionerBaseAI
{
    using BroggokPrisionerBaseAI::BroggokPrisionerBaseAI;

    void ScheduleEvents() override
    {
        Scheduler
            .Schedule(5s, 10s, [this](TaskContext task)
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                    DoCast(target, SPELL_CHARGE);
                task.Repeat(20s, 30s);
            })
            .Schedule(0s, 10s, [this](TaskContext task)
            {
                DoCastSelf(SPELL_FRENZY);
                task.Repeat(120s);
            });
    }
};

// 181982 - Cell Door Lever
struct go_broggok_lever : public GameObjectAI
{
    go_broggok_lever(GameObject* go) : GameObjectAI(go), _instance(go->GetInstanceScript()) { }

    bool OnGossipHello(Player* /*player*/) override
    {
        if (_instance->GetBossState(DATA_BROGGOK) != DONE)
            _instance->SetData(DATA_PRISONERS_EVENT, IN_PROGRESS);

        me->ActivateObject(GameObjectActions(GameObjectActions::MakeInert));

        return false;
    }

private:
    InstanceScript* _instance;
};

// 30914, 38462 - Poison
class spell_broggok_poison_cloud : public AuraScript
{
    PrepareAuraScript(spell_broggok_poison_cloud);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_0).TriggerSpell });
    }

    void OnPeriodic(AuraEffect const* aurEff)
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
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_broggok_poison_cloud::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
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
