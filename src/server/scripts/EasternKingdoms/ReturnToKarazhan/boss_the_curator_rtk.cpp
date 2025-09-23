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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "return_to_karazhan.h"

enum TheCuratorRTKSpells
{
    SPELL_COSMETIC_MANA_DRAIN             = 228840,
    SPELL_SUMMON_VOLATILE_ENERGY          = 227267,
    SPELL_SUMMON_VOLATILE_ENERGY_SELECTOR = 234416,
    SPELL_POWER_DISCHARGE                 = 227279,
    SPELL_POWER_DISCHARGE_AREATRIGGER     = 227289,
    SPELL_POWER_DISCHARGE_DAMAGE          = 227465,
    SPELL_POWER_DISCHARGE_SELECTOR        = 227278,
    SPELL_EVOCATION                       = 227254,
    SPELL_OVERLOAD                        = 227256,
    SPELL_OVERLOAD_DAMAGE                 = 227257,
    SPELL_ARC_LIGHTNING_DAMAGE            = 227270,
    SPELL_STATIC_CHARGE                   = 228736
};

enum TheCuratorRTKEvents
{
    EVENT_VOLATILE_ENERGY = 1,
    EVENT_POWER_DISCHARGE,
    EVENT_CHECK_MANA,
};

enum TheCuratorRTKTexts
{
    SAY_AGGRO                   = 0,
    SAY_VOLATILE_ENERGY         = 1,
    SAY_EVOCATION               = 2,
    SAY_SLAY                    = 3,
    SAY_DEAD                    = 4
};

enum TheCuratorRTKMisc
{
    SUMMON_GROUP_MEDIVH_SCENE = 0
};

// 114247 - The Curator
struct boss_the_curator_rtk : public BossAI
{
    boss_the_curator_rtk(Creature* creature) : BossAI(creature, DATA_THE_CURATOR_RTK) { }

    void RemoveAreaTriggers() const
    {
        for (AreaTrigger* powerDischarge : me->GetAreaTriggers(SPELL_POWER_DISCHARGE_AREATRIGGER))
            powerDischarge->Remove();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
        Talk(SAY_DEAD);
        RemoveAreaTriggers();

        me->SummonCreatureGroup(SUMMON_GROUP_MEDIVH_SCENE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        RemoveAreaTriggers();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        DoCastSelf(SPELL_COSMETIC_MANA_DRAIN);

        events.ScheduleEvent(EVENT_VOLATILE_ENERGY, 5s);
        events.ScheduleEvent(EVENT_POWER_DISCHARGE, 12s);
        events.ScheduleEvent(EVENT_CHECK_MANA, 500ms);
    }

    void OnChannelFinished(SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_EVOCATION)
            return;

        DoCastSelf(SPELL_OVERLOAD);
        DoCastSelf(SPELL_COSMETIC_MANA_DRAIN);
        events.ScheduleEvent(EVENT_VOLATILE_ENERGY, 9200ms);
        events.ScheduleEvent(EVENT_POWER_DISCHARGE, 12s);
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
                case EVENT_VOLATILE_ENERGY:
                {
                    Talk(SAY_VOLATILE_ENERGY);
                    DoCastSelf(SPELL_SUMMON_VOLATILE_ENERGY_SELECTOR);
                    events.Repeat(9700ms);
                    break;
                }
                case EVENT_POWER_DISCHARGE:
                {
                    DoCastSelf(SPELL_POWER_DISCHARGE_SELECTOR);
                    events.Repeat(12s);
                    break;
                }
                case EVENT_CHECK_MANA:
                {
                    if (me->GetPower(POWER_MANA) <= 0)
                    {
                        Talk(SAY_EVOCATION);
                        me->RemoveAurasDueToSpell(SPELL_COSMETIC_MANA_DRAIN);
                        DoCastSelf(SPELL_EVOCATION);
                        me->SetReactState(REACT_PASSIVE);
                        events.CancelEvent(EVENT_VOLATILE_ENERGY);
                        events.CancelEvent(EVENT_POWER_DISCHARGE);
                    }
                    events.Repeat(500ms);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 234416 - Summon Volatile Energy
class spell_the_curator_rtk_summon_volatile_energy_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SUMMON_VOLATILE_ENERGY });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SUMMON_VOLATILE_ENERGY, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_curator_rtk_summon_volatile_energy_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 227278 - Power Discharge
class spell_the_curator_rtk_power_discharge_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_POWER_DISCHARGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_POWER_DISCHARGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_curator_rtk_power_discharge_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 227269 - Arc Lightning
class spell_the_curator_rtk_arc_lightning_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ARC_LIGHTNING_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_ARC_LIGHTNING_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_curator_rtk_arc_lightning_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 228735 - Static Charge
class spell_the_curator_rtk_static_charge_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STATIC_CHARGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_STATIC_CHARGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_curator_rtk_static_charge_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 227256 - Overload
class spell_the_curator_rtk_overload : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_OVERLOAD_DAMAGE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        Creature* creatureCaster = GetCaster()->ToCreature();
        if (!creatureCaster)
            return;

        creatureCaster->CastSpell(GetHitUnit(), SPELL_OVERLOAD_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
        creatureCaster->SetReactState(REACT_AGGRESSIVE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_the_curator_rtk_overload::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 227289 Power Discharge
struct at_the_curator_rtk_power_discharge : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_POWER_DISCHARGE_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_POWER_DISCHARGE_DAMAGE, at->GetCasterGuid());
    }
};

void AddSC_boss_the_curator_rtk()
{
    RegisterReturnToKarazhanCreatureAI(boss_the_curator_rtk);

    RegisterSpellScript(spell_the_curator_rtk_summon_volatile_energy_selector);
    RegisterSpellScript(spell_the_curator_rtk_power_discharge_selector);
    RegisterSpellScript(spell_the_curator_rtk_arc_lightning_selector);
    RegisterSpellScript(spell_the_curator_rtk_static_charge_selector);
    RegisterSpellScript(spell_the_curator_rtk_overload);

    RegisterAreaTriggerAI(at_the_curator_rtk_power_discharge);
}
