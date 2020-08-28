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

#include "halls_of_origination.h"
#include "CreatureAIImpl.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "InstanceScript.h"

enum Spells
{
    //  Ammunae
    SPELL_ZERO_ENERGY_ZERO_REGEN                = 72242,
    SPELL_WITHER                                = 76043,
    SPELL_CONSUME_LIFE_ENERGY                   = 75725,
    SPELL_CONSUME_LIFE_ENERGY_ENERGIZE          = 75665,
    SPELL_CONSUME_LIFE_ENERGY_BURN_MANA         = 75718,
    SPELL_CONSUME_LIFE_ENERGY_BURN_RUNIC_POWER  = 79768,
    SPELL_CONSUME_LIFE_ENERGY_BURN_ENERGY       = 79766,
    SPELL_CONSUME_LIFE_ENERGY_BURN_RAGE         = 79767,
    SPELL_CONSUME_LIFE_ENERGY_BURN_FOCUS        = 80968,
    SPELL_RAMPANT_GROWTH                        = 75790,
    SPELL_SUMMON_BLOODPETAL_BLOSSOM             = 75774,
    SPELL_SUMMON_SEEDLING_POD                   = 75621,
    SPELL_SUMMON_SPORE                          = 75695,

    // Seedling Pod
    SPELL_ENERGIZE                              = 75657,
    SPELL_ENERGIZING_GROWTH                     = 75624,
    SPELL_SEEDLING_POD_VISUAL                   = 75687,
    SPELL_SUMMON_SEEDLING_POD_2                 = 75688,

    // Bloodpetal Blossom
    SPELL_SHRINK                                = 59632,
    SPELL_SUBMERGE                              = 76486,
    SPELL_BLOODPETAL_BLOSSOM                    = 75768,
    SPELL_EMERGE                                = 76485,
    SPELL_THORN_SLASH                           = 76044,

    // Blootpetal Sprout
    SPELL_SUMMON_BLOODPETAL_SPROUT              = 75795,
    SPELL_SUMMON_BLOODPETAL_BLOSOM_VISUAL       = 75769,
    SPELL_SUMMON_BLOODPETAL_BLOOM_STATE         = 75770,
    SPELL_FIXATE                                = 73686,

    // Spore
    SPELL_SPORE_CLOUD                           = 75701
};

enum Texts
{
    // Ammunae
    SAY_AGGRO               = 0,
    SAY_RAMPANT_GROWTH      = 1,
    SAY_DEATH               = 2,
    SAY_SLAY                = 3
};

enum Events
{
    // Ammunae
    EVENT_WITHER = 1,
    EVENT_CONSUME_LIFE_ENERGY,
    EVENT_RAMPANT_GROWTH,
    EVENT_SUMMON_SEEDLING_POD,
    EVENT_SUMMON_BLOODPETAL_BLOSSOM,
    EVENT_SUMMON_SPORE,

    // Bloodpetal Blossom
    EVENT_ENGAGE_PLAYERS,
    EVENT_TRANSFORM,
    EVENT_REMOVE_SHRINK_AURA,
    EVENT_EMERGE,
    EVENT_THORN_SLASH,

    // Bloodpetal Sprout
    EVENT_FIXATE
};

struct boss_ammunae : public BossAI
{
    boss_ammunae(Creature* creature) : BossAI(creature, DATA_AMMUNAE), _firstDrainLifeEnergyCycle(true) { }

    void JustAppeared() override
    {
        me->MakeInterruptable(false);
        me->AddAura(SPELL_ZERO_ENERGY_ZERO_REGEN, me);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_SUMMON_SEEDLING_POD, 7s);
        events.ScheduleEvent(EVENT_SUMMON_SEEDLING_POD, 14s, 15s);
        events.ScheduleEvent(EVENT_WITHER, 7s, 9s);
        events.ScheduleEvent(EVENT_CONSUME_LIFE_ENERGY, 21s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*who*/) override
    {
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->IsPlayer())
            Talk(SAY_SLAY, victim);
    }

    void OnSpellCastFinished(SpellInfo const* spell, SpellFinishReason /*reason*/) override
    {
        if (spell->Id == SPELL_WITHER)
            me->MakeInterruptable(false);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.RemoveNotExisting();
        summons.Summon(summon);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || !CheckInRoom())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_WITHER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.f, true))
                    {
                        me->MakeInterruptable(true);
                        DoCast(target, SPELL_WITHER);
                    }
                    break;
                case EVENT_CONSUME_LIFE_ENERGY:
                    DoCastAOE(SPELL_CONSUME_LIFE_ENERGY);
                    events.Repeat(20s);
                    events.ScheduleEvent(EVENT_SUMMON_SEEDLING_POD, 6s);
                    events.ScheduleEvent(EVENT_RAMPANT_GROWTH, 6s);

                    if (_firstDrainLifeEnergyCycle)
                    {
                        events.ScheduleEvent(EVENT_SUMMON_BLOODPETAL_BLOSSOM, 6s);
                        _firstDrainLifeEnergyCycle = false;
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_SUMMON_SPORE, 7s);
                        _firstDrainLifeEnergyCycle = true;
                    }

                    events.ScheduleEvent(EVENT_SUMMON_SEEDLING_POD, 14s, 15s);
                    events.ScheduleEvent(EVENT_WITHER, 7s, 8s);

                    break;
                case EVENT_RAMPANT_GROWTH:
                    if (me->GetPower(POWER_ENERGY) == me->GetMaxPower(POWER_ENERGY))
                    {
                        Talk(SAY_RAMPANT_GROWTH);
                        DoCastAOE(SPELL_RAMPANT_GROWTH);
                        events.RescheduleEvent(EVENT_SUMMON_SEEDLING_POD, 11s);
                        events.RescheduleEvent(EVENT_WITHER, 3s);
                    }
                    break;
                case EVENT_SUMMON_SEEDLING_POD:
                    DoCastSelf(SPELL_SUMMON_SEEDLING_POD);
                    break;
                case EVENT_SUMMON_BLOODPETAL_BLOSSOM:
                    DoCastAOE(SPELL_SUMMON_BLOODPETAL_BLOSSOM);
                    break;
                case EVENT_SUMMON_SPORE:
                    DoCastSelf(SPELL_SUMMON_SPORE);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
 private:
     bool _firstDrainLifeEnergyCycle;
};

struct npc_ammunae_seedling_pod : public NullCreatureAI
{
    npc_ammunae_seedling_pod(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SUMMON_SEEDLING_POD_2);
        DoCastSelf(SPELL_ENERGIZING_GROWTH);
        DoCastSelf(SPELL_ENERGIZE);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_UNK_6);
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_SEEDLING_POD_VISUAL:
                summon->CastSpell(summon, SPELL_SEEDLING_POD_VISUAL);
                summon->DespawnOrUnsummon(2s + 600ms);
                break;
            case NPC_BLOODPETAL_BLOSSOM:
            case NPC_BLOODPETAL_SPROUT:
                if (InstanceScript* instance = me->GetInstanceScript())
                    if (Creature* ammunae = instance->GetCreature(DATA_AMMUNAE))
                        if (ammunae->IsAIEnabled)
                            ammunae->AI()->JustSummoned(summon);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(1s + 200ms);
    }
};

struct npc_ammunae_bloodpetal_blossom : public ScriptedAI
{
    npc_ammunae_bloodpetal_blossom(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SHRINK);
        DoCastSelf(SPELL_SUBMERGE);
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(2s);
    }

    void JustSummoned(Creature* summon) override
    {
        summon->CastSpell(summon, SPELL_SUMMON_BLOODPETAL_BLOOM_STATE);
        summon->DespawnOrUnsummon(2s + 600ms);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    DoZoneInCombat();
                    _events.ScheduleEvent(EVENT_TRANSFORM, 1s);
                    break;
                case EVENT_TRANSFORM:
                    DoCastSelf(SPELL_BLOODPETAL_BLOSSOM);
                    DoCastSelf(SPELL_SUMMON_BLOODPETAL_BLOSOM_VISUAL, true);
                    _events.ScheduleEvent(EVENT_REMOVE_SHRINK_AURA, 1s + 500ms);
                    break;
                case EVENT_REMOVE_SHRINK_AURA:
                    me->RemoveAurasDueToSpell(SPELL_SHRINK);
                    _events.ScheduleEvent(EVENT_EMERGE, 3s + 400ms);
                    break;
                case EVENT_EMERGE:
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                    DoCastSelf(SPELL_EMERGE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    _events.ScheduleEvent(SPELL_THORN_SLASH, 3s);
                    break;
                case SPELL_THORN_SLASH:
                    DoCastVictim(SPELL_THORN_SLASH);
                    _events.Repeat(8s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_ammunae_bloodpetal_sprout : public ScriptedAI
{
    npc_ammunae_bloodpetal_sprout(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SUBMERGE);
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 400ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->DespawnOrUnsummon(2s);
    }

    void JustSummoned(Creature* summon) override
    {
        summon->CastSpell(summon, SPELL_SUMMON_BLOODPETAL_BLOOM_STATE);
        summon->DespawnOrUnsummon(2s + 600ms);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    DoZoneInCombat();
                    _events.ScheduleEvent(EVENT_TRANSFORM, 1s + 200ms);
                    break;
                case EVENT_TRANSFORM:
                    DoCastSelf(SPELL_SUMMON_BLOODPETAL_SPROUT);
                    DoCastSelf(SPELL_SUMMON_BLOODPETAL_BLOSOM_VISUAL, true);
                    _events.ScheduleEvent(EVENT_EMERGE, 5s);
                    break;
                case EVENT_EMERGE:
                    me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 35.f, true))
                        DoCast(target, SPELL_FIXATE);
                    DoCastSelf(SPELL_EMERGE);
                    _events.ScheduleEvent(EVENT_FIXATE, 5s);
                    break;
                case EVENT_FIXATE:
                    DoCastVictim(SPELL_FIXATE);
                    _events.Repeat(5s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

struct npc_ammunae_spore : public ScriptedAI
{
    npc_ammunae_spore(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _events.ScheduleEvent(EVENT_ENGAGE_PLAYERS, 1s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->CastSpell(me, SPELL_SPORE_CLOUD);

        me->m_Events.AddEventAtOffset([this]()
            {
                me->RemoveAllAuras();
                me->DespawnOrUnsummon(1s + 500ms);
            }, 29s);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ENGAGE_PLAYERS:
                    me->SetReactState(REACT_AGGRESSIVE);
                    DoZoneInCombat();
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    EventMap _events;
};

class spell_ammunae_consume_life_energy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_CONSUME_LIFE_ENERGY_BURN_MANA,
                SPELL_CONSUME_LIFE_ENERGY_BURN_RAGE,
                SPELL_CONSUME_LIFE_ENERGY_BURN_RUNIC_POWER,
                SPELL_CONSUME_LIFE_ENERGY_BURN_FOCUS,
                SPELL_CONSUME_LIFE_ENERGY_BURN_ENERGY,
                SPELL_CONSUME_LIFE_ENERGY_ENERGIZE
            });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_CONSUME_LIFE_ENERGY_ENERGIZE);

        Player* player = GetHitPlayer();
        if (!player)
            return;

        uint32 spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_MANA;
        switch (player->getClass())
        {
            case CLASS_WARRIOR:
                spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_RAGE;
                break;
            case CLASS_HUNTER:
                spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_FOCUS;
                break;
            case CLASS_DEATH_KNIGHT:
                spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_RUNIC_POWER;
                break;
            case CLASS_ROGUE:
                spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_ENERGY;
                break;
            case CLASS_DRUID:
                if (player->GetShapeshiftForm() == FORM_CAT)
                    spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_ENERGY;
                else if (player->GetShapeshiftForm() == FORM_BEAR)
                    spellId = SPELL_CONSUME_LIFE_ENERGY_BURN_RAGE;
                break;
            default:
                break;
        }

        caster->CastSpell(GetHitUnit(), spellId);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_ammunae_consume_life_energy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget.Register(&spell_ammunae_consume_life_energy::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ammunae_summon_bloodpetal_blossom : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDespawn(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            target->DespawnOrUnsummon(1s + 200ms);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_ammunae_summon_bloodpetal_blossom::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        OnEffectHitTarget.Register(&spell_ammunae_summon_bloodpetal_blossom::HandleDespawn, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_ammunae_rampant_growth : public SpellScript
{
    void HandleDespawn(SpellEffIndex /*effIndex*/)
    {
        if (Creature* target = GetHitCreature())
            target->DespawnOrUnsummon(1s + 600ms);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ammunae_rampant_growth::HandleDespawn, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
    }
};

class spell_ammunae_fixate : public SpellScript
{
    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, GetEffectValue(), true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ammunae_fixate::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_ammunae()
{
    RegisterHallsOfOriginationCreatureAI(boss_ammunae);
    RegisterHallsOfOriginationCreatureAI(npc_ammunae_seedling_pod);
    RegisterHallsOfOriginationCreatureAI(npc_ammunae_bloodpetal_blossom);
    RegisterHallsOfOriginationCreatureAI(npc_ammunae_bloodpetal_sprout);
    RegisterHallsOfOriginationCreatureAI(npc_ammunae_spore);
    RegisterSpellScript(spell_ammunae_consume_life_energy);
    RegisterSpellScript(spell_ammunae_summon_bloodpetal_blossom);
    RegisterSpellScript(spell_ammunae_rampant_growth);
    RegisterSpellScript(spell_ammunae_fixate);
}
