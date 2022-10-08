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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "atal_dazar.h"

enum PriestessAlunzaSpells : uint32
{
    SPELL_PRE_RITUAL = 258386,

    SPELL_ENERGY_REGEN = 258681,
    SPELL_GILDED_CLAWS = 255579,
    SPELL_GILDED_CLAWS_TRIGGER_SPELL = 255581,
    SPELL_TRANSFUSION = 260666,
    SPELL_TRANSFUSION_PERIODIC_DUMMY = 255577,
    SPELL_TRANSFUSION_DAMAGE = 255836,
    SPELL_TRANSFUSION_DAMAGE_MYTHIC = 260667,
    SPELL_TRANSFUSION_HEAL = 255835,
    SPELL_TRANSFUSION_HEAL_MYTHIC = 260668,
    SPELL_TAINTED_BLOOD_DOT = 255558,
    SPELL_TAINTED_BLOOD_TARGET_CAULDRON = 255592,
    SPELL_TAINTED_BLOOD_MISSILE_BUBBLE = 260660, // TARGET_DEST_DEST
    SPELL_TAINTED_BLOOD_CREATE_AT = 260670,//AT
    SPELL_TAINTED_BLOOD_DAMAGE = 255842,
    SPELL_TAINTED_BLOOD_SPAWN = 255619,

    SPELL_MOLTEN_GOLD_POOL_PRE_SELECTOR = 255615,
    SPELL_MOLTEN_GOLD_POOL_SELECTOR = 255591,
    SPELL_MOLTEN_GOLD_TARGET_SELECT = 255584,
    SPELL_MOLTEN_GOLD_MISSILE = 255583,
    SPELL_MOLTEN_GOLD_DOT = 255582,

    SPELL_CORRUPTED_GOLD_TOUCH = 258709,
    SPELL_CORRUPTED_GOLD_AT = 258703,

    SPELL_SUMMON_SPIRIT_OF_GOLD = 259205,
};

enum PriestessAlunzaTalks : uint8
{
    TALK_AGGRO = 0,
    TALK_GILDED_CLAWS_EMOTE = 1,
    TALK_GILDED_CLAWS = 2,
    TALK_TRANSFUSION_EMOTE = 3,
    TALK_TRANSFUSION = 4,
    TALK_MOLTEN_GOLD = 5,
    TALK_DEATH = 6
};

enum PriestessAlunzaEvents : uint8
{
    EVENT_GILDED_CLAWS = 1,
    EVENT_TRANSFUSION,
    EVENT_MOLTEN_GOLD,
    EVENT_TAINTED_BLOOD_CAST,
    EVENT_TAINTED_BLOOD,
    EVENT_SPAWN_CORRUPTED_GOLD,
    EVENT_SPIRIT_OF_GOLD,
};

enum PriestessAlunzaNPCs : uint32
{
    NPC_BLOOD_TAINTED_CAULDRON = 128956,
    NPC_CORRUPTED_GOLD = 130738,
    NPC_SPIRIT_OF_GOLD = 131009,
};

enum Actions
{
    ACTION_SPIRIT_DIED = 0,
    ACTION_TAINTED_BLOOD,
};

enum PriestessMisc : uint32
{
    OUT_OF_COMBAT_ANIM_ID = 1346
};

enum conversationalunza
{
    CONVERSATION_ALUNZA_DEATH = 6323,
};

// 122967 - Priestess Alunza
struct boss_priestess_alunza : public BossAI
{
    boss_priestess_alunza(Creature* creature) : BossAI(creature, DATA_PRIESTESS_ALUNZA) { }

    void InitializeAI() override
    {
        me->SetMaxPower(POWER_MANA, 100);
        me->SetPower(POWER_MANA, 0);
        scheduler.ClearValidator();
        taintedCounter = 0;
        BossAI::InitializeAI();
    }

    void Reset() override
    {
        AreaTriggerList areatriggers = me->SelectNearestAreaTriggers(SPELL_TAINTED_BLOOD_CREATE_AT, 100.f);
        for (AreaTrigger* at : areatriggers)
            at->Remove();

        taintedCounter = 0;

        events.Reset();
        scheduler.CancelAll();
        summons.DespawnAll();

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->SetPower(POWER_MANA, 0);
        DoCastSelf(SPELL_PRE_RITUAL);
        BossAI::Reset();
    }

    void EnterCombat(Unit* who) override
    {
        Talk(TALK_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_GILDED_CLAWS, 10500);
        events.ScheduleEvent(EVENT_MOLTEN_GOLD, 16500);
        events.ScheduleEvent(EVENT_TAINTED_BLOOD, 18000);

        if (IsMythic() || IsHeroic())
        {
            events.ScheduleEvent(EVENT_SPAWN_CORRUPTED_GOLD, 2000);
            // Last event to add: Spawn add
        }
        taintedCounter = 0;
        me->RemoveAurasDueToSpell(SPELL_PRE_RITUAL);
        me->AddAura(SPELL_ENERGY_REGEN, me);

        BossAI::EnterCombat(who);
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SPIRIT_DIED)
            goldfever = true;
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _DespawnAtEvade();
        BossAI::EnterEvadeMode(why);
    }

    void JustDied(Unit* killer) override
    {
        Talk(TALK_DEATH);
        _JustDied();
        instance->SetBossState(DATA_PRIESTESS_ALUNZA, DONE);

        if (goldfever)
            instance->DoCompleteAchievement(AtalDazarAchievements::ACHIEVEMENT_GOLD_FEVER);

        for (auto creature : me->FindNearestCreatures(NPC_CORRUPTED_GOLD, 100.0f))
        {
            creature->DespawnOrUnsummon();
        }
        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 100.0f);
        for (auto player : playerList)
        {
            Conversation::CreateConversation(CONVERSATION_ALUNZA_DEATH, player, player->GetPosition(), { player->GetGUID() });
            if (player->HasAura(SPELL_UNSTABLE_HEX))
            {
                int cont = instance->GetData(DATA_ACHIEVEMENT_COUNT);
                instance->SetData(DATA_ACHIEVEMENT_COUNT, cont++);
                break;
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

        if (me->GetPower(POWER_MANA) >= 100 && !events.HasEvent(EVENT_TRANSFUSION))
            events.ScheduleEvent(EVENT_TRANSFUSION, 5000);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_GILDED_CLAWS:
                Talk(TALK_GILDED_CLAWS);
                Talk(TALK_GILDED_CLAWS_EMOTE);
                DoCastSelf(SPELL_GILDED_CLAWS);
                events.ScheduleEvent(EVENT_GILDED_CLAWS, 34000);
                break;
            case EVENT_MOLTEN_GOLD:
                Talk(TALK_MOLTEN_GOLD);
                DoCastSelf(SPELL_MOLTEN_GOLD_POOL_PRE_SELECTOR, true);
                events.ScheduleEvent(EVENT_MOLTEN_GOLD, 34000);
                break;
            case EVENT_TRANSFUSION:
                Talk(TALK_TRANSFUSION);
                Talk(TALK_TRANSFUSION_EMOTE);
                DoCast(SPELL_TRANSFUSION);
                taintedCounter = 0;
                break;
            case EVENT_TAINTED_BLOOD:
                events.DelayEvents(11000);
                events.ScheduleEvent(EVENT_TAINTED_BLOOD_CAST, 1000);
                events.ScheduleEvent(EVENT_TAINTED_BLOOD, 44000);
                break;
            case EVENT_TAINTED_BLOOD_CAST:
                DoCastSelf(SPELL_TAINTED_BLOOD_TARGET_CAULDRON);
                ++taintedCounter;
                if (taintedCounter < 5)
                    events.ScheduleEvent(EVENT_TAINTED_BLOOD_CAST, 2000);
                else
                {
                    if (IsHeroic() || IsMythic())
                        events.ScheduleEvent(EVENT_SPIRIT_OF_GOLD, 8500);
                    events.ScheduleEvent(EVENT_TRANSFUSION, 13000);
                }
                break;
            case EVENT_SPAWN_CORRUPTED_GOLD:
            {
                scheduler.Schedule(0s, [this](TaskContext context)
                {
                    if (Creature* cauldron = me->FindNearestCreature(NPC_BLOOD_TAINTED_CAULDRON, 100.f))
                    {
                        cauldron = DoSummon(NPC_CORRUPTED_GOLD, cauldron->GetPosition(), 40000, TEMPSUMMON_TIMED_DESPAWN);
                    }
                    context.Repeat(3500ms);
                });
                break;
            }
            case EVENT_SPIRIT_OF_GOLD:
            {
                me->CastSpell(me, SPELL_SUMMON_SPIRIT_OF_GOLD);
                break;
            }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler scheduler;
    int8 taintedCounter;
    bool goldfever;
};

enum CauldronSpells : uint32
{
    SPELL_TAINTED_BLOOD_CAULDRON_AURA = 255619,
    SPELL_TAINTED_BLOOD_CAULDRON_PURIFY = 260658
};

// 128956 - Blood Tainted Cauldron
struct npc_blood_tainted_cauldron : public ScriptedAI
{
    npc_blood_tainted_cauldron(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        DoCastSelf(SPELL_TAINTED_BLOOD_CAULDRON_AURA);
        ScriptedAI::Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        // Do nothing
        ScriptedAI::UpdateAI(diff);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_MOLTEN_GOLD_POOL_SELECTOR)
            DoCastSelf(SPELL_TAINTED_BLOOD_CAULDRON_PURIFY);
    }
};

// 130738 - Corrupted Gold
struct npc_corrupted_gold : public ScriptedAI
{
    npc_corrupted_gold(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        touched = false;
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        touched = false;
        DoCastSelf(SPELL_CORRUPTED_GOLD_AT);
        MoveForward(70.0f);
        ScriptedAI::Reset();
    }

    void MoveForward(float distance)
    {
        Position movePos;
        float ori = float(M_PI_2) + float(M_PI) + frand(0.0f, float(M_PI));
        float x = me->GetPositionX() + distance * cos(ori);
        float y = me->GetPositionY() + distance * sin(ori);
        float z = me->GetPositionZ();
        me->GetNearPoint2D(x, y, distance, ori);
        movePos = { x, y, z, ori };
        me->GetMotionMaster()->MovePoint(0, movePos, false);
    }

    void UpdateAI(uint32 diff) override
    {
        ScriptedAI::UpdateAI(diff);
        if (Player* player = me->SelectNearestPlayer(1.5f))
            if (!touched)
            {
                touched = true;
                me->GetMotionMaster()->Clear();
                me->CastSpell(player, SPELL_CORRUPTED_GOLD_TOUCH);
            }

    }
private:
    bool touched;
};

//259205
struct npc_spirit_of_gold : public ScriptedAI
{
    npc_spirit_of_gold(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        taintedblood = 0;
        ScriptedAI::InitializeAI();
    }

    void Reset() override
    {
        taintedblood = 0;
        ScriptedAI::Reset();
    }

    void JustDied(Unit* killer) override
    {
        if (taintedblood >= 8)
        {
            Creature* boss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_PRIESTESS_ALUNZA));
            boss->AI()->DoAction(ACTION_SPIRIT_DIED);
        }
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_TAINTED_BLOOD)
            taintedblood++;
    }

    void UpdateAI(uint32 diff) override
    {
        ScriptedAI::UpdateAI(diff);
        if (AreaTrigger* at = me->SelectNearestAreaTrigger(SPELL_TAINTED_BLOOD_CREATE_AT, 100.0f))
        {
            me->getThreatManager().resetAllAggro();
            me->GetMotionMaster()->MovePoint(0, at->GetPosition());
        }
        else
            if (Player* player = me->SelectNearestPlayer(100.0f))
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->getThreatManager().addThreat(player, 1000000.0f);
                me->GetMotionMaster()->MoveChase(player);
                me->Attack(player, true);
            }

    }
private:
    int taintedblood;
};

//260665
class spell_priestess_transfusion_cast : public SpellScript
{
    PrepareSpellScript(spell_priestess_transfusion_cast);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            caster->AddAura(SPELL_TRANSFUSION_PERIODIC_DUMMY, caster);
    }

    void Register() override
    {
        OnEffectLaunch += SpellEffectFn(spell_priestess_transfusion_cast::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 255575 - Tranfusion Damage
class spell_priestess_tranfusion_damage : public SpellScript
{
    PrepareSpellScript(spell_priestess_tranfusion_damage);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
        {
            if (hitUnit->HasAura(SPELL_TAINTED_BLOOD_DOT))
                GetCaster()->CastSpell(hitUnit, SPELL_TRANSFUSION_DAMAGE, true);
            else
                GetCaster()->CastSpell(hitUnit, SPELL_TRANSFUSION_HEAL, true);
        }
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object) -> bool
        {
            if (!object->ToPlayer())
                return true;

            return false;
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_tranfusion_damage::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_priestess_tranfusion_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_priestess_transfusion_heal : public SpellScript
{
    PrepareSpellScript(spell_priestess_transfusion_heal);

    void HandleHeal(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        if (Unit* caster = GetCaster())
        {
            float percent = 50 / 100;
            if (caster->GetInstanceScript()->instance->IsHeroic())
                percent = 1;
            if (caster->GetInstanceScript()->instance->IsMythic())
                percent = 2;
            SetHitHeal((int32)((percent / 100) * caster->GetMaxHealth()));
        }

    }
    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_transfusion_heal::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL_PCT);
    }
};

// 255577 - Transfusion
class spell_priestess_transfusion : public AuraScript
{
    PrepareAuraScript(spell_priestess_transfusion);

    void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetTarget())
            target->SetPower(POWER_MANA, 0);
    }
    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_priestess_transfusion::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// 258681 - Boss Energy Regen
class spell_priestess_energy_regen : public AuraScript
{
    PrepareAuraScript(spell_priestess_energy_regen);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* target = GetTarget())
        {
            /* int32 cant = target->GetPower(POWER_MANA) + aurEff->GetAmount() / 10;
             if (cant > 100)
                 cant = 100;*/
            target->ModifyPower(POWER_MANA, aurEff->GetAmount() / 10);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_priestess_energy_regen::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 260658 - Cauldron Purify
class spell_npc_cauldron_purify : public AuraScript
{
    PrepareAuraScript(spell_npc_cauldron_purify);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* target = GetTarget())
            target->CastSpell(target, SPELL_MOLTEN_GOLD_TARGET_SELECT, true);
        GetAura()->Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_npc_cauldron_purify::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 255592 - Pool Pre Tainted Selector
class spell_priestess_pool_tainted_selector : public SpellScript
{
    PrepareSpellScript(spell_priestess_pool_tainted_selector);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return obj->GetEntry() != NPC_BLOOD_TAINTED_CAULDRON; });
        Trinity::Containers::RandomResize(targets, 1);
    }

    void DoEffectHitTarget(SpellEffIndex effIndex)
    {
        if (Unit* hitUnit = GetHitUnit())
            if (UnitAI* ai = GetCaster()->GetAI()) //@HACK TODO
                if (Unit* target = ai->SelectTarget(SELECT_TARGET_RANDOM, 0))
                    hitUnit->CastSpell(target, SPELL_TAINTED_BLOOD_MISSILE_BUBBLE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_pool_tainted_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_priestess_pool_tainted_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 255615 - Pool Pre Selector
class spell_priestess_pool_pre_selector : public SpellScript
{
    PrepareSpellScript(spell_priestess_pool_pre_selector);

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
            GetCaster()->CastSpell(hitUnit, SPELL_MOLTEN_GOLD_POOL_SELECTOR);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj) { return obj->GetEntry() != NPC_BLOOD_TAINTED_CAULDRON; });
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_pool_pre_selector::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_priestess_pool_pre_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 255584 - Molten Gold Target Selector
class spell_priestess_alunza_molten_gold : public SpellScript
{
    PrepareSpellScript(spell_priestess_alunza_molten_gold);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        std::list<WorldObject*> originalTargets = targets;
        targets.remove_if([](WorldObject* object) -> bool
        {
            if (object->ToUnit()->HasAura(SPELL_MOLTEN_GOLD_DOT))
                return true;

            return false;
        });
        if (targets.empty())
            targets = originalTargets;
    }

    void DoEffectHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (Unit* hitUnit = GetHitUnit())
            if (InstanceScript* atalDazarScript = GetCaster()->GetInstanceScript())
                GetCaster()->CastSpell(hitUnit, SPELL_MOLTEN_GOLD_MISSILE, true, nullptr, nullptr, atalDazarScript->GetGuidData(DATA_PRIESTESS_ALUNZA));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_priestess_alunza_molten_gold::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_priestess_alunza_molten_gold::DoEffectHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Tainted Blood - 260670
// at 12369
struct at_priestess_alunza_tainted_blood : AreaTriggerAI
{
    at_priestess_alunza_tainted_blood(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (caster->IsValidAttackTarget(unit))
            {
                caster->CastSpell(unit, SPELL_TAINTED_BLOOD_DOT, true);
                at->Remove();
            }
        if (unit->GetEntry() == NPC_SPIRIT_OF_GOLD)
        {
            unit->ToCreature()->AI()->DoAction(ACTION_TAINTED_BLOOD);
            at->Remove();

        }
    }
};

void AddSC_boss_priestess_alunza()
{
    RegisterAreaTriggerAI(at_priestess_alunza_tainted_blood);

    RegisterCreatureAI(npc_corrupted_gold);
    RegisterCreatureAI(boss_priestess_alunza);
    RegisterCreatureAI(npc_blood_tainted_cauldron);
    RegisterCreatureAI(npc_spirit_of_gold);

    RegisterSpellScript(spell_priestess_alunza_molten_gold);
    RegisterAuraScript(spell_npc_cauldron_purify);
    RegisterAuraScript(spell_priestess_energy_regen);
    RegisterAuraScript(spell_priestess_transfusion);
    RegisterSpellScript(spell_priestess_tranfusion_damage);
    RegisterSpellScript(spell_priestess_pool_pre_selector);
    RegisterSpellScript(spell_priestess_pool_tainted_selector);
    RegisterSpellScript(spell_priestess_transfusion_cast);
    RegisterSpellScript(spell_priestess_transfusion_heal);
}
