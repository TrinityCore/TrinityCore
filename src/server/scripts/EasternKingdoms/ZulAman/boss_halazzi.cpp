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
 * Combat timers requires to be revisited
 * SAY_EVENT is NYI
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "zulaman.h"

enum HalazziTexts
{
    SAY_AGGRO                   = 0,
    SAY_SPLIT                   = 1,
    SAY_MERGE                   = 2,
    SAY_MELEE                   = 3,
    SAY_BERSERK                 = 4,
    SAY_SLAY                    = 5,
    SAY_DEATH                   = 6,
    SAY_EVENT                   = 7
};

enum HalazziSpells
{
    // Halazzi - Combat - Lynx Phase & Last Phase
    SPELL_ENRAGE                = 43139,
    SPELL_SABER_LASH            = 43267,

    // Halazzi - Combat - Split
    SPELL_TRANSFIGURE           = 44054,
    SPELL_SUMMON_SPIRIT_LYNX    = 43143,

    // Halazzi - Combat - Merge
    SPELL_TRANSFORM_60_HEALTH   = 43145,
    SPELL_TRANSFORM_30_HEALTH   = 43271,
    SPELL_TRANSFORM_25_HEALTH   = 43272,

    // Halazzi - Combat - Spirit Phase & Last Phase
    SPELL_LIGHTNING_TOTEM       = 43302,
    SPELL_FLAME_SHOCK           = 43303,
    SPELL_EARTH_SHOCK           = 43305,

    // Halazzi - Combat - All Phases
    SPELL_BERSERK               = 45078,

    // Halazzi - Combat - Misc
    SPELL_TRANSFORM_MAX_HEALTH  = 43311,

    // Spirit of the Lynx
    SPELL_SPIRIT_CHANNEL        = 43615,
    SPELL_SPIRIT_EFFECT         = 42466,
    SPELL_SHRED_ARMOR           = 43243,
    SPELL_LYNX_FLURRY           = 43290,

    // Corrupted Lightning Totem
    SPELL_LIGHTNING             = 43301
};

enum HalazziEvents
{
    // Lynx Phase & Last Phase
    EVENT_ENRAGE                = 1,
    EVENT_SABER_LASH,

    // Split
    EVENT_SPLIT_1,
    EVENT_SPLIT_2,

    // Merge
    EVENT_MERGE_1,
    EVENT_MERGE_2,

    // Spirit Phase & Last Phase
    EVENT_LIGHTNING_TOTEM,
    EVENT_FLAME_SHOCK,
    EVENT_EARTH_SHOCK,

    // All Phases
    EVENT_BERSERK
};

enum HalazziPhases
{
    PHASE_LYNX                  = 1,
    PHASE_SPIRIT,
    PHASE_FINAL
};

enum HalazziMisc
{
    NPC_HALAZZI_LYNX            = 23577,
    NPC_HALAZZI_TROLL           = 24144,
    NPC_SPIRIT_LYNX             = 24143,
    ACTION_BEGIN_MERGE          = 0,
    ACTION_INFORM_LYNX          = 1
};

// 23577 - Halazzi
struct boss_halazzi : public BossAI
{
    boss_halazzi(Creature* creature) : BossAI(creature, BOSS_HALAZZI), _transformCount(2) { }

    void Reset() override
    {
        _Reset();

        _transformCount = 2;

        me->SetCanDualWield(true);
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetUnkillable(false);

        events.SetPhase(PHASE_LYNX);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_ENRAGE, 15s, 25s);
        events.ScheduleEvent(EVENT_SABER_LASH, 10s, 15s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void DamageTaken(Unit* /*done_by*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (events.IsInPhase(PHASE_LYNX) && me->HealthBelowPctDamaged(30 * _transformCount, damage))
        {
            me->SetUnkillable(true);
            events.SetPhase(PHASE_SPIRIT);
            events.ScheduleEvent(EVENT_SPLIT_1, 0s);
        }
    }

    void OnHealthDepleted(Unit* /*attacker*/, bool /*isKill*/) override
    {
        if (events.IsInPhase(PHASE_SPIRIT))
        {
            events.SetPhase(PHASE_LYNX);
            events.ScheduleEvent(EVENT_MERGE_1, 0s);
        }
    }

    void PerformAdditionalEvents()
    {
        switch (_transformCount)
        {
            case 2:
                DoCastSelf(SPELL_TRANSFORM_60_HEALTH);
                break;
            case 1:
                DoCastSelf(SPELL_TRANSFORM_30_HEALTH);
                break;
            default:
                break;
        }

        if (Creature* spirit = me->FindNearestCreature(NPC_SPIRIT_LYNX, 200.0f))
            spirit->AI()->DoAction(ACTION_INFORM_LYNX);

        --_transformCount;

        if (_transformCount)
        {
            events.CancelEvent(EVENT_LIGHTNING_TOTEM);
            events.CancelEvent(EVENT_FLAME_SHOCK);
            events.CancelEvent(EVENT_EARTH_SHOCK);
            events.ScheduleEvent(EVENT_ENRAGE, 15s, 25s);
            events.ScheduleEvent(EVENT_SABER_LASH, 10s, 15s);
        }
        else
        {
            events.SetPhase(PHASE_FINAL);
            events.ScheduleEvent(EVENT_ENRAGE, 15s, 25s);
            events.ScheduleEvent(EVENT_SABER_LASH, 10s, 15s);
            events.RescheduleEvent(EVENT_LIGHTNING_TOTEM, 10s, 15s);
            events.RescheduleEvent(EVENT_FLAME_SHOCK, 10s, 25s);
            events.RescheduleEvent(EVENT_EARTH_SHOCK, 10s, 20s);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_BEGIN_MERGE && events.IsInPhase(PHASE_SPIRIT))
        {
            events.SetPhase(PHASE_LYNX);
            events.ScheduleEvent(EVENT_MERGE_1, 0s);
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_SABER_LASH:
                Talk(SAY_MELEE);
                break;
            case SPELL_BERSERK:
                Talk(SAY_BERSERK);
                break;
            default:
                break;
        }
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DoCastSelf(SPELL_TRANSFORM_MAX_HEALTH);

        if (me->GetEntry() == NPC_HALAZZI_TROLL)
            me->UpdateEntry(NPC_HALAZZI_LYNX);

        BossAI::EnterEvadeMode(why);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
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
                // Lynx Phase & Last Phase
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_SABER_LASH:
                    DoCastVictim(SPELL_SABER_LASH);
                    events.Repeat(20s);
                    break;

                // Split
                case EVENT_SPLIT_1:
                    Talk(SAY_SPLIT);
                    DoCastSelf(SPELL_TRANSFIGURE);
                    me->SetReactState(REACT_PASSIVE);
                    events.CancelEvent(EVENT_ENRAGE);
                    events.CancelEvent(EVENT_SABER_LASH);
                    events.ScheduleEvent(EVENT_SPLIT_2, 3s);
                    break;
                case EVENT_SPLIT_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->UpdateEntry(NPC_HALAZZI_TROLL);
                    DoCastSelf(SPELL_SUMMON_SPIRIT_LYNX);
                    events.ScheduleEvent(EVENT_LIGHTNING_TOTEM, 10s, 15s);
                    events.ScheduleEvent(EVENT_FLAME_SHOCK, 10s, 25s);
                    events.ScheduleEvent(EVENT_EARTH_SHOCK, 10s, 20s);
                    break;

                // Merge
                case EVENT_MERGE_1:
                    me->UpdateEntry(NPC_HALAZZI_LYNX);
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_MERGE);
                    PerformAdditionalEvents();
                    events.ScheduleEvent(EVENT_MERGE_2, 5s);
                    break;
                case EVENT_MERGE_2:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetUnkillable(false);
                    break;

                // Spirit Phase & Last Phase
                case EVENT_LIGHTNING_TOTEM:
                    DoCastSelf(SPELL_LIGHTNING_TOTEM);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_FLAME_SHOCK:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FLAME_SHOCK);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_EARTH_SHOCK:
                {
                    std::vector<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 30.0f);
                    for (Player* player : playerList)
                    {
                        if (player->IsNonMeleeSpellCast(false))
                        {
                            DoCast(player, SPELL_EARTH_SHOCK);
                            break;
                        }
                    }
                    events.Repeat(10s, 20s);
                    break;
                }

                // All Phases
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    uint8 _transformCount;
};

// 24143 - Spirit of the Lynx
struct npc_spirit_of_the_lynx : public ScriptedAI
{
    npc_spirit_of_the_lynx(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.Schedule(0s, [this](TaskContext& task)
        {
            switch (task.GetRepeatCounter())
            {
                case 0:
                    DoZoneInCombat();
                    DoCastSelf(SPELL_SPIRIT_CHANNEL);
                    task.Repeat(1200ms);
                    break;
                case 1:
                    DoCastSelf(SPELL_SPIRIT_EFFECT, true);
                    break;
                default:
                    break;
            }
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _scheduler
            .Schedule(4s, [this](TaskContext& task)
            {
                DoCastVictim(SPELL_SHRED_ARMOR);
                task.Repeat(4s);
            })
            .Schedule(5s, 10s, [this](TaskContext& task)
            {
                DoCastSelf(SPELL_LYNX_FLURRY);
                task.Repeat(15s, 20s);
            });
    }

    void OnHealthDepleted(Unit* /*killer*/, bool /*isKill*/) override
    {
        if (Creature* halazzi = _instance->GetCreature(BOSS_HALAZZI))
            halazzi->AI()->DoAction(ACTION_BEGIN_MERGE);

        /// @todo: This part requires sniff verification. Basically copied from Halazzi's low health actions
        me->SetReactState(REACT_PASSIVE);
        me->DespawnOrUnsummon(3s);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_INFORM_LYNX)
        {
            me->SetReactState(REACT_PASSIVE);
            me->DespawnOrUnsummon(3s);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        UpdateVictim();
    }

private:
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};

// 24224 - Corrupted Lightning Totem
struct npc_corrupted_lightning_totem : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoZoneInCombat();

        _scheduler.Schedule(2400ms, [this](TaskContext& task)
        {
            std::vector<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 30.0f);

            Trinity::Containers::RandomResize(playerList, 1);

            for (Player* player : playerList)
                DoCast(player, SPELL_LIGHTNING);

            task.Repeat(2400ms);
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
    TaskScheduler _scheduler;
};

// 43536 - Set Health
// 43537 - Set Health
// 43538 - Set Health
class spell_halazzi_set_health : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->SetHealth(GetCaster()->CountPctFromMaxHealth(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_halazzi_set_health::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_halazzi()
{
    RegisterZulAmanCreatureAI(boss_halazzi);
    RegisterZulAmanCreatureAI(npc_spirit_of_the_lynx);
    RegisterZulAmanCreatureAI(npc_corrupted_lightning_totem);
    RegisterSpellScript(spell_halazzi_set_health);
}
