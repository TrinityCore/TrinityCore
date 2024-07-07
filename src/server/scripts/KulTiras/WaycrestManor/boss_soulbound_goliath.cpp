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
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "waycrest_manor.h"

enum SoulboundGoliathSpells
{
    SPELL_CRUSH                         = 260508,
    SPELL_SOUL_HARVEST_PERIODIC         = 261580,
    SPELL_SOUL_HARVEST_DAMAGE           = 260512,
    SPELL_SOUL_THORNS_SELECTOR          = 260551,
    SPELL_SOUL_THORNS_STUN              = 267907
};

enum SoulboundGoliathTexts
{
};

enum SoulboundGoliathEvents
{
    // Matron Bryndle
    EVENT_CRUSH         = 1,
    EVENT_SOUL_THORNS,
    EVENT_JAGGED_NETTLE
};

enum SoulboundGoliathMisc
{
    ANIMKIT_NONE = 0,
    ANIMKIT_AWAKE = 6550
};

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

        //Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetBossState(DATA_SOULBOUND_GOLIATH, IN_PROGRESS);

        DoCastSelf(SPELL_SOUL_HARVEST_PERIODIC);

        events.ScheduleEvent(EVENT_CRUSH, 5100ms);
        events.ScheduleEvent(EVENT_SOUL_THORNS, 9100ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        //Talk(SAY_DEATH);
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
                    //Talk(SAY_SHADOW_STORM);
                    DoCast(SPELL_SOUL_THORNS_SELECTOR);
                    events.Repeat(22500ms);
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
        GetCaster()->CastSpell(GetCaster(), SPELL_SOUL_THORNS_STUN, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_soulbound_goliath_soul_thorns_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260541 - Burning Brush
class spell_soulbound_goliath_burning_brush : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitCreature()->AttackStop();
        GetHitCreature()->SetReactState(REACT_PASSIVE);
        GetHitCreature()->GetMotionMaster()->Clear();
        GetHitCreature()->GetMotionMaster()->MoveRandom(2.0f);
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
        return ValidateSpellInfo({ SPELL_SOUL_HARVEST_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (AuraEffect* aurEff = GetCaster()->GetAuraEffect(SPELL_SOUL_HARVEST_DAMAGE, EFFECT_0))
            aurEff->GetBase()->ModStackAmount(-7);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->ToCreature()->GetMotionMaster()->Clear();
        GetTarget()->ToCreature()->SetReactState(REACT_AGGRESSIVE);
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
    RegisterSpellAndAuraScriptPair(spell_soulbound_goliath_burning_brush, spell_soulbound_goliath_burning_brush_aura);
}
