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

#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "TemporarySummon.h"
#include "waycrest_manor.h"

enum SoulboundGoliathSpells
{
    SPELL_BURNING_SOULS         = 268045,
    SPELL_CRUSH                 = 260508,
    SPELL_KILL_SOUL_THORN       = 278792,
    SPELL_SOUL_HARVEST_PERIODIC = 261580,
    SPELL_SOUL_HARVEST_DAMAGE   = 260512,
    SPELL_SOUL_THORNS_SELECTOR  = 260551,
    SPELL_SOUL_THORNS_STUN      = 267907
};

enum SoulboundGoliathTexts
{
    SAY_AGGRO           = 0,
    SAY_SLAY            = 1,
    SAY_THORNS          = 2,
    SAY_BURNING_BRUSH   = 3,
    SAY_DEATH           = 4,
    SAY_PLAYER_THORNS   = 5,
    SAY_SOUL_HARVEST    = 6
};

enum SoulboundGoliathEvents
{
    EVENT_CRUSH         = 1,
    EVENT_SOUL_THORNS,
    EVENT_SOUL_HARVEST_WARNING
};

enum SoulboundGoliathMisc
{
    ANIMKIT_NONE  = 0,
    ANIMKIT_AWAKE = 6550
};

// 131667 - Soulbound Goliath
struct boss_soulbound_goliath : public BossAI
{
    boss_soulbound_goliath(Creature* creature) : BossAI(creature, DATA_SOULBOUND_GOLIATH) { }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_SOULBOUND_GOLIATH_INTRO) == DONE)
        {
            me->SetAIAnimKitId(ANIMKIT_NONE);
            me->SetImmuneToPC(false);
            me->SetUninteractible(false);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_SOULBOUND_GOLIATH, FAIL);

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_SOULBOUND_GOLIATH, IN_PROGRESS);

        DoCastSelf(SPELL_SOUL_HARVEST_PERIODIC);

        events.ScheduleEvent(EVENT_CRUSH, 5800ms);
        events.ScheduleEvent(EVENT_SOUL_THORNS, 9800ms);
        events.ScheduleEvent(EVENT_SOUL_HARVEST_WARNING, 23s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_SOULBOUND_GOLIATH, DONE);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_SOULBOUND_GOLIATH_INTRO:
            {
                _scheduler.Schedule(1s + 500ms, [this](TaskContext /*task*/)
                {
                    me->SetAIAnimKitId(ANIMKIT_NONE);
                    me->PlayOneShotAnimKitId(ANIMKIT_AWAKE);
                    me->SetImmuneToPC(false);
                    me->SetUninteractible(false);
                });
                break;
            }
            default:
                break;
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BURNING_BRUSH)
            Talk(SAY_BURNING_BRUSH);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SOUL_THORNS_SELECTOR)
            Talk(SAY_PLAYER_THORNS, target);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CRUSH:
                {
                    DoCastVictim(SPELL_CRUSH);
                    events.Repeat(16200ms);
                    break;
                }
                case EVENT_SOUL_THORNS:
                {
                    Talk(SAY_THORNS);
                    DoCast(SPELL_SOUL_THORNS_SELECTOR);
                    events.Repeat(22500ms);
                    break;
                }
                case EVENT_SOUL_HARVEST_WARNING:
                {
                    Talk(SAY_SOUL_HARVEST);
                    events.Repeat(32s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    TaskScheduler _scheduler;
};

// 261580 - Soul Harvest
class spell_soulbound_goliath_soul_harvest : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_HARVEST_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        InstanceScript* instance = target->GetInstanceScript();
        if (!instance)
            return;

        if (instance->GetBossState(DATA_SOULBOUND_GOLIATH) != IN_PROGRESS)
            return;

        target->CastSpell(target, SPELL_SOUL_HARVEST_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_soulbound_goliath_soul_harvest::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 260551 - Soul Thorns
class spell_soulbound_goliath_soul_thorns_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_THORNS_STUN });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SOUL_THORNS_STUN, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_soulbound_goliath_soul_thorns_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 267907 - Soul Thorns
class spell_soulbound_goliath_soul_thorns_damage : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_KILL_SOUL_THORN });
    }

    void HandleDamage(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            return;

        GetTarget()->CastSpell(nullptr, SPELL_KILL_SOUL_THORN, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_soulbound_goliath_soul_thorns_damage::HandleDamage, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 267911 - Soul Thorns
class spell_soulbound_goliath_soul_thorns_remove_stun : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_THORNS_STUN });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (TempSummon* target = GetHitUnit()->ToTempSummon())
        {
            if (Unit* summoner = target->GetSummonerUnit())
                summoner->RemoveAurasDueToSpell(GetEffectValue());
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_soulbound_goliath_soul_thorns_remove_stun::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 260541 - Burning Brush
class spell_soulbound_goliath_burning_brush : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        target->AttackStop();
        target->SetReactState(REACT_PASSIVE);
        target->GetMotionMaster()->Clear();
        target->GetMotionMaster()->MoveRandom(2.0f);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_soulbound_goliath_burning_brush::HandleScript, EFFECT_1, SPELL_EFFECT_TRIGGER_ACTION_SET);
    }
};

class spell_soulbound_goliath_burning_brush_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_HARVEST_DAMAGE, SPELL_BURNING_SOULS });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();

        if (AuraEffect* aurEff = target->GetAuraEffect(SPELL_SOUL_HARVEST_DAMAGE, EFFECT_0))
            aurEff->GetBase()->ModStackAmount(-7);

        if (target->GetMap()->IsHeroicOrHigher())
            target->CastSpell(target, SPELL_BURNING_SOULS, false);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* creatureTarget = GetTarget()->ToCreature();
        if (!creatureTarget)
            return;

        creatureTarget->GetMotionMaster()->Clear();
        creatureTarget->SetReactState(REACT_AGGRESSIVE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_soulbound_goliath_burning_brush_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_soulbound_goliath_burning_brush_aura::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_soulbound_goliath()
{
    RegisterWaycrestManorCreatureAI(boss_soulbound_goliath);

    RegisterSpellScript(spell_soulbound_goliath_soul_harvest);
    RegisterSpellScript(spell_soulbound_goliath_soul_thorns_selector);
    RegisterSpellScript(spell_soulbound_goliath_soul_thorns_damage);
    RegisterSpellScript(spell_soulbound_goliath_soul_thorns_remove_stun);
    RegisterSpellAndAuraScriptPair(spell_soulbound_goliath_burning_brush, spell_soulbound_goliath_burning_brush_aura);
}
