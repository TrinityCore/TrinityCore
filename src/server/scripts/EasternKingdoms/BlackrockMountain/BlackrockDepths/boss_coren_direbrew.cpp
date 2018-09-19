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
#include "blackrock_depths.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "InstanceScript.h"
#include "LFGMgr.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum DirebrewSays
{
    SAY_INTRO                 = 0,
    SAY_INTRO1                = 1,
    SAY_INTRO2                = 2,
    SAY_INSULT                = 3,
    SAY_ANTAGONIST_1          = 0,
    SAY_ANTAGONIST_2          = 1,
    SAY_ANTAGONIST_COMBAT     = 2
};

enum DirebrewActions
{
    ACTION_START_FIGHT        = -1,
    ACTION_ANTAGONIST_SAY_1   = -2,
    ACTION_ANTAGONIST_SAY_2   = -3,
    ACTION_ANTAGONIST_HOSTILE = -4
};

enum DirebrewNpcs
{
    NPC_ILSA_DIREBREW         = 26764,
    NPC_URSULA_DIREBREW       = 26822,
    NPC_ANTAGONIST            = 23795
};

enum DirebrewSpells
{
    SPELL_MOLE_MACHINE_EMERGE          = 50313,
    SPELL_DIREBREW_DISARM_PRE_CAST     = 47407,
    SPELL_MOLE_MACHINE_TARGET_PICKER   = 47691,
    SPELL_MOLE_MACHINE_MINION_SUMMONER = 47690,
    SPELL_DIREBREW_DISARM_GROW         = 47409,
    SPELL_DIREBREW_DISARM              = 47310,
    SPELL_CHUCK_MUG                    = 50276,
    SPELL_PORT_TO_COREN                = 52850,
    SPELL_SEND_MUG_CONTROL_AURA        = 47369,
    SPELL_SEND_MUG_TARGET_PICKER       = 47370,
    SPELL_SEND_FIRST_MUG               = 47333,
    SPELL_SEND_SECOND_MUG              = 47339,
    SPELL_REQUEST_SECOND_MUG           = 47344,
    SPELL_HAS_DARK_BREWMAIDENS_BREW    = 47331,
    SPELL_BARRELED_CONTROL_AURA        = 50278,
    SPELL_BARRELED                     = 47442
};

enum DirebrewPhases
{
    PHASE_ALL = 1,
    PHASE_INTRO,
    PHASE_ONE,
    PHASE_TWO,
    PHASE_THREE
};

enum DirebrewEvents
{
    EVENT_INTRO_1 = 1,
    EVENT_INTRO_2,
    EVENT_INTRO_3,
    EVENT_DIREBREW_DISARM,
    EVENT_SUMMON_MOLE_MACHINE,
    EVENT_RESPAWN_ILSA,
    EVENT_RESPAWN_URSULA
};

enum DirebrewMisc
{
    GOSSIP_ID                      = 11388,
    GO_MOLE_MACHINE_TRAP           = 188509,
    GOSSIP_OPTION_FIGHT            = 0,
    GOSSIP_OPTION_APOLOGIZE        = 1,
    DATA_TARGET_GUID               = 1,
    MAX_ANTAGONISTS                = 3
};

Position const AntagonistPos[3] =
{
    { 895.3782f, -132.1722f, -49.66423f, 2.6529f   },
    { 893.9837f, -133.2879f, -49.66541f, 2.583087f },
    { 896.2667f, -130.483f,  -49.66249f, 2.600541f }
};

struct boss_coren_direbrew : public BossAI
{
    boss_coren_direbrew(Creature* creature) : BossAI(creature, DATA_COREN) { }

    bool GossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        if (menuId != GOSSIP_ID)
            return false;

        if (gossipListId == GOSSIP_OPTION_FIGHT)
        {
            Talk(SAY_INSULT, player);
            DoAction(ACTION_START_FIGHT);
        }
        else if (gossipListId == GOSSIP_OPTION_APOLOGIZE)
            CloseGossipMenuFor(player);

        return false;
    }

    void Reset() override
    {
        _Reset();
        me->SetImmuneToPC(true);
        me->SetFaction(FACTION_FRIENDLY);
        events.SetPhase(PHASE_ALL);

        for (uint8 i = 0; i < MAX_ANTAGONISTS; ++i)
            me->SummonCreature(NPC_ANTAGONIST, AntagonistPos[i], TEMPSUMMON_DEAD_DESPAWN);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        _DespawnAtEvade(Seconds(10));
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!events.IsInPhase(PHASE_ALL) || who->GetTypeId() != TYPEID_PLAYER)
            return;

        events.SetPhase(PHASE_INTRO);
        events.ScheduleEvent(EVENT_INTRO_1, Seconds(6), 0, PHASE_INTRO);
        Talk(SAY_INTRO);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_FIGHT)
        {
            events.SetPhase(PHASE_ONE);
            me->SetImmuneToPC(false);
            me->SetFaction(FACTION_GOBLIN_DARK_IRON_BAR_PATRON);
            DoZoneInCombat();

            EntryCheckPredicate pred(NPC_ANTAGONIST);
            summons.DoAction(ACTION_ANTAGONIST_HOSTILE, pred);

            events.ScheduleEvent(EVENT_SUMMON_MOLE_MACHINE, 15s);
            events.ScheduleEvent(EVENT_DIREBREW_DISARM, 20s);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(66, damage) && events.IsInPhase(PHASE_ONE))
        {
            events.SetPhase(PHASE_TWO);
            SummonSister(NPC_ILSA_DIREBREW);
        }
        else if (me->HealthBelowPctDamaged(33, damage) && events.IsInPhase(PHASE_TWO))
        {
            events.SetPhase(PHASE_THREE);
            SummonSister(NPC_URSULA_DIREBREW);
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_ILSA_DIREBREW)
            events.ScheduleEvent(EVENT_RESPAWN_ILSA, 1s);
        else if (summon->GetEntry() == NPC_URSULA_DIREBREW)
            events.ScheduleEvent(EVENT_RESPAWN_URSULA, 1s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        if (!players.isEmpty())
        {
            if (Group* group = players.begin()->GetSource()->GetGroup())
                if (group->isLFGGroup())
                    sLFGMgr->FinishDungeon(group->GetGUID(), 287, me->GetMap());
        }
    }

    void SummonSister(uint32 entry)
    {
        if (Creature* sister = me->SummonCreature(entry, me->GetPosition(), TEMPSUMMON_DEAD_DESPAWN))
            DoZoneInCombat(sister);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO_1:
                    Talk(SAY_INTRO1);
                    events.ScheduleEvent(EVENT_INTRO_2, Seconds(4), 0, PHASE_INTRO);
                    break;
                case EVENT_INTRO_2:
                {
                    EntryCheckPredicate pred(NPC_ANTAGONIST);
                    summons.DoAction(ACTION_ANTAGONIST_SAY_1, pred);
                    events.ScheduleEvent(EVENT_INTRO_3, Seconds(3), 0, PHASE_INTRO);
                    break;
                }
                case EVENT_INTRO_3:
                {
                    Talk(SAY_INTRO2);
                    EntryCheckPredicate pred(NPC_ANTAGONIST);
                    summons.DoAction(ACTION_ANTAGONIST_SAY_2, pred);
                    break;
                }
                case EVENT_RESPAWN_ILSA:
                    SummonSister(NPC_ILSA_DIREBREW);
                    break;
                case EVENT_RESPAWN_URSULA:
                    SummonSister(NPC_URSULA_DIREBREW);
                    break;
                case EVENT_SUMMON_MOLE_MACHINE:
                {
                    CastSpellExtraArgs args;
                    args.TriggerFlags = TRIGGERED_FULL_MASK;
                    args.AddSpellMod(SPELLVALUE_MAX_TARGETS, 1);
                    me->CastSpell(nullptr, SPELL_MOLE_MACHINE_TARGET_PICKER, args);
                    events.Repeat(Seconds(15));
                    break;
                }
                case EVENT_DIREBREW_DISARM:
                    DoCastSelf(SPELL_DIREBREW_DISARM_PRE_CAST, true);
                    events.Repeat(Seconds(20));
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

struct npc_coren_direbrew_sisters : public ScriptedAI
{
    npc_coren_direbrew_sisters(Creature* creature) : ScriptedAI(creature) { }

    void SetGUID(ObjectGuid const& guid, int32 id) override
    {
        if (id == DATA_TARGET_GUID)
            _targetGUID = guid;
    }

    ObjectGuid GetGUID(int32 data) const override
    {
        if (data == DATA_TARGET_GUID)
            return _targetGUID;

        return ObjectGuid::Empty;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        DoCastSelf(SPELL_PORT_TO_COREN);

        if (me->GetEntry() == NPC_URSULA_DIREBREW)
            DoCastSelf(SPELL_BARRELED_CONTROL_AURA);
        else
            DoCastSelf(SPELL_SEND_MUG_CONTROL_AURA);

        _scheduler
            .SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        })
            .Schedule(Seconds(2), [this](TaskContext mugChuck)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, false, true, -SPELL_HAS_DARK_BREWMAIDENS_BREW))
                DoCast(target, SPELL_CHUCK_MUG);
            mugChuck.Repeat(Seconds(4));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff, [this]
        {
            DoMeleeAttackIfReady();
        });
    }

private:
    ObjectGuid _targetGUID;
    TaskScheduler _scheduler;
};

struct npc_direbrew_minion : public ScriptedAI
{
    npc_direbrew_minion(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetFaction(FACTION_GOBLIN_DARK_IRON_BAR_PATRON);
        DoZoneInCombat();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* coren = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(DATA_COREN)))
            coren->AI()->JustSummoned(me);
    }

private:
    InstanceScript* _instance;
};

struct npc_direbrew_antagonist : public ScriptedAI
{
    npc_direbrew_antagonist(Creature* creature) : ScriptedAI(creature) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_ANTAGONIST_SAY_1:
                Talk(SAY_ANTAGONIST_1);
                break;
            case ACTION_ANTAGONIST_SAY_2:
                Talk(SAY_ANTAGONIST_2);
                break;
            case ACTION_ANTAGONIST_HOSTILE:
                me->SetImmuneToPC(false);
                me->SetFaction(FACTION_GOBLIN_DARK_IRON_BAR_PATRON);
                DoZoneInCombat();
                break;
            default:
                break;
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_ANTAGONIST_COMBAT, who);
        ScriptedAI::JustEngagedWith(who);
    }
};

class go_direbrew_mole_machine : public GameObjectScript
{
public:
    go_direbrew_mole_machine() : GameObjectScript("go_direbrew_mole_machine") { }

    struct go_direbrew_mole_machineAI : public GameObjectAI
    {
        go_direbrew_mole_machineAI(GameObject* go) : GameObjectAI(go) { }

        void Reset() override
        {
            me->SetLootState(GO_READY);
            _scheduler
                .Schedule(Seconds(1), [this](TaskContext /*context*/)
                {
                    me->UseDoorOrButton(10000);
                    me->CastSpell(nullptr, SPELL_MOLE_MACHINE_EMERGE, true);
                })
                .Schedule(Seconds(4), [this](TaskContext /*context*/)
                {
                    if (GameObject* trap = me->GetLinkedTrap())
                    {
                        trap->SetLootState(GO_ACTIVATED);
                        trap->UseDoorOrButton();
                    }
                });
        }

        void UpdateAI(uint32 diff) override
        {
            _scheduler.Update(diff);
        }

    private:
        TaskScheduler _scheduler;
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return GetBlackrockDepthsAI<go_direbrew_mole_machineAI>(go);
    }
};

// 47691 - Summon Mole Machine Target Picker
class spell_direbrew_summon_mole_machine_target_picker : public SpellScript
{
    PrepareSpellScript(spell_direbrew_summon_mole_machine_target_picker);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MOLE_MACHINE_MINION_SUMMONER });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MOLE_MACHINE_MINION_SUMMONER, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_direbrew_summon_mole_machine_target_picker::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 47370 - Send Mug Target Picker
class spell_send_mug_target_picker : public SpellScript
{
    PrepareSpellScript(spell_send_mug_target_picker);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();

        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HAS_DARK_BREWMAIDENS_BREW));

        if (targets.size() > 1)
            targets.remove_if([caster](WorldObject* obj)
        {
            if (obj->GetGUID() == caster->GetAI()->GetGUID(DATA_TARGET_GUID))
                return true;
            return false;
        });

        if (targets.empty())
            return;

        WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
        targets.clear();
        targets.push_back(target);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->GetAI()->SetGUID(GetHitUnit()->GetGUID(), DATA_TARGET_GUID);
        caster->CastSpell(GetHitUnit(), SPELL_SEND_FIRST_MUG, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_send_mug_target_picker::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_send_mug_target_picker::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 47344 - Request Second Mug
class spell_request_second_mug : public SpellScript
{
    PrepareSpellScript(spell_request_second_mug);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SEND_SECOND_MUG });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), SPELL_SEND_SECOND_MUG, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_request_second_mug::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 47369 - Send Mug Control Aura
class spell_send_mug_control_aura : public AuraScript
{
    PrepareAuraScript(spell_send_mug_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SEND_MUG_TARGET_PICKER });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_SEND_MUG_TARGET_PICKER, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_send_mug_control_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 50278 - Barreled Control Aura
class spell_barreled_control_aura : public AuraScript
{
    PrepareAuraScript(spell_barreled_control_aura);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(nullptr, SPELL_BARRELED, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_barreled_control_aura::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// 47407 - Direbrew's Disarm (precast)
class spell_direbrew_disarm : public AuraScript
{
    PrepareAuraScript(spell_direbrew_disarm);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DIREBREW_DISARM, SPELL_DIREBREW_DISARM_GROW });
    }

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (Aura* aura = GetTarget()->GetAura(SPELL_DIREBREW_DISARM_GROW))
        {
            aura->SetStackAmount(aura->GetStackAmount() + 1);
            aura->SetDuration(aura->GetDuration() - 1500);
        }
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_DIREBREW_DISARM_GROW, true);
        GetTarget()->CastSpell(GetTarget(), SPELL_DIREBREW_DISARM);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_direbrew_disarm::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectApply += AuraEffectRemoveFn(spell_direbrew_disarm::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_coren_direbrew()
{
    RegisterBlackrockDepthsCreatureAI(boss_coren_direbrew);
    RegisterBlackrockDepthsCreatureAI(npc_coren_direbrew_sisters);
    RegisterBlackrockDepthsCreatureAI(npc_direbrew_minion);
    RegisterBlackrockDepthsCreatureAI(npc_direbrew_antagonist);
    new go_direbrew_mole_machine();
    RegisterSpellScript(spell_direbrew_summon_mole_machine_target_picker);
    RegisterSpellScript(spell_send_mug_target_picker);
    RegisterSpellScript(spell_request_second_mug);
    RegisterAuraScript(spell_send_mug_control_aura);
    RegisterAuraScript(spell_barreled_control_aura);
    RegisterAuraScript(spell_direbrew_disarm);
}
