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
#include "PathGenerator.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "return_to_karazhan.h"

enum ManaDevourerSpells
{
    SPELL_ABSORB_LOOSE_MANA               = 227466,
    SPELL_ARCANE_BOMB                     = 227618,
    SPELL_COALESCE_POWER                  = 227297,
    SPELL_DECIMATING_ESSENCE              = 227507,
    SPELL_ENERGY_DISCHARGE                = 227457,
    SPELL_ENERGY_VOID                     = 227523,
    SPELL_ENERGY_VOID_DAMAGE              = 227524,
    SPELL_ENERGY_VOID_DRAIN_POWER         = 227528,
    SPELL_ENGULFING_POWER                 = 228577,
    SPELL_LOOSE_MANA_MISSILE              = 228066,
    SPELL_LOOSE_MANA_AREATRIGGER          = 227296,
    SPELL_MANA_DEVOURER_ENERGIZE_PERIODIC = 227451,
    SPELL_MANA_DEVOURER_ENERGIZE          = 232066,
    SPELL_TELEPORT                        = 231500,
    SPELL_UNSTABLE_MANA                   = 227502
};

enum ManaDevourerEvents
{
    EVENT_ARCANE_BOMB = 1,
    EVENT_ENERGY_VOID,
    EVENT_ENERGY_DISCHARGE,
    EVENT_COALESCE_POWER,
    EVENT_CHECK_POWER
};

// 114252 - Mana Devourer
struct boss_mana_devourer : public BossAI
{
    boss_mana_devourer(Creature* creature) : BossAI(creature, DATA_MANA_DEVOURER) { }

    void JustAppeared() override
    {
        me->SetPower(POWER_ENERGY, 0);
    }

    void RemoveAreaTriggers() const
    {
        for (AreaTrigger* energyVoid : me->GetAreaTriggers(SPELL_ENERGY_VOID))
            energyVoid->Remove();

        for (AreaTrigger* looseMana : me->GetAreaTriggers(SPELL_LOOSE_MANA_AREATRIGGER))
            looseMana->Remove();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
        RemoveAreaTriggers();
        DoCast(SPELL_TELEPORT);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        RemoveAreaTriggers();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        DoCastSelf(SPELL_MANA_DEVOURER_ENERGIZE_PERIODIC);

        events.ScheduleEvent(EVENT_ARCANE_BOMB, 7s);
        events.ScheduleEvent(EVENT_ENERGY_VOID, 14500ms);
        events.ScheduleEvent(EVENT_ENERGY_DISCHARGE, 21s);
        events.ScheduleEvent(EVENT_COALESCE_POWER, 30600ms);
        events.ScheduleEvent(EVENT_CHECK_POWER, 500ms);
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
                case EVENT_ARCANE_BOMB:
                {
                    DoCastSelf(SPELL_ARCANE_BOMB);
                    events.Repeat(13700ms);
                    break;
                }
                case EVENT_ENERGY_VOID:
                {
                    DoCastSelf(SPELL_ENERGY_VOID);
                    events.Repeat(20600ms);
                    break;
                }
                case EVENT_ENERGY_DISCHARGE:
                {
                    DoCastSelf(SPELL_ENERGY_DISCHARGE);
                    events.Repeat(27900ms);
                    break;
                }
                case EVENT_COALESCE_POWER:
                {
                    DoCastSelf(SPELL_COALESCE_POWER);
                    events.Repeat(30300ms);
                    break;
                }
                case EVENT_CHECK_POWER:
                {
                    if (me->GetPower(POWER_ENERGY) >= 100)
                        DoCast(SPELL_DECIMATING_ESSENCE);
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

// 227297 - Coalesce Power
class spell_mana_devourer_coalesce_power : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LOOSE_MANA_MISSILE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_LOOSE_MANA_MISSILE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_devourer_coalesce_power::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 227451 - Mana Devourer Energize
class spell_mana_devourer_energize : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MANA_DEVOURER_ENERGIZE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_MANA_DEVOURER_ENERGIZE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_devourer_energize::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 227457 - Energy Discharge
class spell_mana_devourer_energy_discharge : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ENGULFING_POWER });
    }

    void HandleCast()
    {
        for (uint8 i = 0; i < 40; ++i)
        {
            float randomAngle = frand(0.0f, 2.0f * float(M_PI));
            float randomDist = frand(GetSpellInfo()->GetMinRange(), GetSpellInfo()->GetMaxRange());

            Position pos(*GetCaster());
            GetCaster()->MovePosition(pos, randomDist, randomAngle);
            GetCaster()->CastSpell(pos, SPELL_ENGULFING_POWER, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_mana_devourer_energy_discharge::HandleCast);
    }
};

// 227524 - Energy Void
class spell_mana_devourer_energy_void : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_MANA, SPELL_ENERGY_VOID_DRAIN_POWER });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Aura* unstableMana = target->GetAura(SPELL_UNSTABLE_MANA))
            unstableMana->ModStackAmount(-1);
        else
            target->CastSpell(target, SPELL_ENERGY_VOID_DRAIN_POWER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_mana_devourer_energy_void::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 227296 - Loose Mana
// Id - 8754
struct at_mana_devourer_loose_mana : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
        {
            at->SetOrientation(caster->GetOrientation());

            Position destPos = caster->GetPosition();
            PathGenerator path(at);
            path.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);

            at->InitSplines(path.GetPath());
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
            unit->CastSpell(unit, SPELL_UNSTABLE_MANA, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        else if (unit->GetEntry() == BOSS_MANA_DEVOURER)
            unit->CastSpell(unit, SPELL_ABSORB_LOOSE_MANA, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        at->Remove();
    }
};

// 227523 - Energy Void
// Id - 8791
struct at_mana_devourer_energy_void : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_ENERGY_VOID_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_ENERGY_VOID_DAMAGE);
    }
};

void AddSC_boss_mana_devourer()
{
    RegisterReturnToKarazhanCreatureAI(boss_mana_devourer);

    RegisterSpellScript(spell_mana_devourer_coalesce_power);
    RegisterSpellScript(spell_mana_devourer_energize);
    RegisterSpellScript(spell_mana_devourer_energy_discharge);
    RegisterSpellScript(spell_mana_devourer_energy_void);

    RegisterAreaTriggerAI(at_mana_devourer_loose_mana);
    RegisterAreaTriggerAI(at_mana_devourer_energy_void);
}
