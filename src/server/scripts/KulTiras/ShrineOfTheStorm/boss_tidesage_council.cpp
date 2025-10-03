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
#include "Creature.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "shrine_of_the_storm.h"

enum TidesageCouncilSpells
{
    // Brother Ironhull
    SPELL_BLESSING_OF_IRONSIDES                = 267901,
    SPELL_HINDERING_CLEAVE                     = 267899,
    SPELL_REINFORCING_WARD_AREATRIGGER         = 267905,
    SPELL_REINFORCING_WARD_DAMAGE_TAKEN_PLAYER = 267904, // Pets can get buff too
    SPELL_REINFORCING_WARD_DAMAGE_TAKEN_BOSS   = 268186,
    SPELL_REINFORCING_WARD_DISPEL_BOSS         = 272001,
    SPELL_REINFORCING_WARD_DISPEL_PLAYER       = 272002,
    SPELL_REINFORCING_WARD_SELECTOR            = 267903,
    SPELL_COSMETIC_REINFORCING_WARD            = 274690,
    SPELL_BROTHER_IRONHULL_GAIN_ENERGY         = 267916, // Serverside

    // Galecaller Faye
    SPELL_BLESSING_OF_THE_TEMPEST              = 267830,
    SPELL_SLICING_BLAST                        = 267818,
    SPELL_BLOWBACK_MISSILE                     = 267842,
    SPELL_BLOWBACK_DAMAGE                      = 267838,
    SPELL_BLOWBACK_AREATRIGGER                 = 267836,
    SPELL_SWIFTNESS_WARD_SELECTOR              = 267902,
    SPELL_SWIFTNESS_WARD_AREATRIGGER           = 267891,
    SPELL_SWIFTNESS_WARD_HASTE_BOSS            = 267890,
    SPELL_SWIFTNESS_WARD_HASTE_PLAYER          = 267888,  // Pets can get buff too
    SPELL_COSMETIC_SWIFTNESS_WARD              = 274689,
    SPELL_GALECALLER_FAYE_GAIN_ENERGY          = 267894 // Serverside
};

enum TidesageCouncilEvents
{
    EVENT_BLESSING_OF_IRONSIDES = 1,
    EVENT_HINDERING_CLEAVE,
    EVENT_REINFORCING_WARD,

    EVENT_BLESSING_OF_THE_TEMPEST,
    EVENT_SLICING_BLAST,
    EVENT_SWIFTNESS_WARD,

    EVENT_CHECK_MANA
};

enum TidesageCouncilTexts
{
    SAY_AGGRO                    = 0,
    SAY_SLAY                     = 3,
    SAY_WIPE                     = 4,
    SAY_DEAD                     = 5,

    // Galecaller Faye
    SAY_SWIFTING_WARD_WARNING    = 1,
    SAY_SWIFTING_WARD            = 2,
    SAY_BLESSING_OF_THE_TEMPEST  = 6,
    SAY_BROTHER_DIES             = 7,

    // Brother Ironhull
    SAY_REINFORCING_WARD         = 1,
    SAY_REINFORCING_WARD_WARNING = 2,
    SAY_FAYE_DIES                = 6
};

uint32 const TidesageData[2] =
{
    DATA_BROTHER_IRONHULL,
    DATA_GALECALLER_FAYE
};

namespace
{
void DespawnTidesageCouncil(InstanceScript* instance, EvadeReason why)
{
    if (instance->GetBossState(DATA_TIDESAGE_COUNCIL) == FAIL)
        return;

    instance->SetBossState(DATA_TIDESAGE_COUNCIL, FAIL);

    for (uint32 bossesData : TidesageData)
    {
        if (Creature* council = instance->GetCreature(bossesData))
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, council);
            council->AI()->EnterEvadeMode(why);
        }
    }
}

void TidesageCouncilEncounterDone(InstanceScript* instance)
{
    if (instance->GetBossState(DATA_TIDESAGE_COUNCIL) == DONE)
        return;

    for (uint32 bossesData : TidesageData)
    {
        if (Creature* council = instance->GetCreature(bossesData))
        {
            if (council->IsAlive())
                return;
        }
    }

    instance->SetBossState(DATA_TIDESAGE_COUNCIL, DONE);
}
}

struct TidesageCouncilSharedAI : public BossAI
{
    TidesageCouncilSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId)
    {
        SetBoundary(instance->GetBossBoundary(DATA_TIDESAGE_COUNCIL));
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        DespawnTidesageCouncil(instance, why);

        Talk(SAY_WIPE);

        events.Reset();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        for (uint32 bossesData : TidesageData)
        {
            if (Creature* council = instance->GetCreature(bossesData))
            {
                if (!council->IsAlive() || council->IsInCombat())
                    continue;

                council->AI()->DoZoneInCombat();
            }
        }

        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        Talk(SAY_AGGRO);

        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        Talk(SAY_DEAD);

        TidesageCouncilEncounterDone(instance);
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_SLAY);
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
            ExecuteEvent(eventId);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }
};

// 134063 - Brother Ironhull <Master of the Hull>
struct boss_brother_ironhull : public TidesageCouncilSharedAI
{
    boss_brother_ironhull(Creature* creature) : TidesageCouncilSharedAI(creature, DATA_BROTHER_IRONHULL) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_COSMETIC_REINFORCING_WARD);
        me->SetPowerType(POWER_MANA);
        me->SetPower(POWER_MANA, 0);
    }

    void JustDied(Unit* killer) override
    {
        TidesageCouncilSharedAI::JustDied(killer);

        if (Creature* faye = instance->GetCreature(DATA_GALECALLER_FAYE))
            faye->AI()->Talk(SAY_BROTHER_DIES);
    }

    void JustEngagedWith(Unit* who) override
    {
        TidesageCouncilSharedAI::JustEngagedWith(who);
        DoCastSelf(SPELL_BROTHER_IRONHULL_GAIN_ENERGY);
    }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_HINDERING_CLEAVE, 8500ms);
        events.ScheduleEvent(EVENT_CHECK_MANA, 500ms);

        if (IsHeroicOrHigher())
            events.ScheduleEvent(EVENT_BLESSING_OF_IRONSIDES, 6100ms);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BLESSING_OF_IRONSIDES:
            {
                DoCastSelf(SPELL_BLESSING_OF_IRONSIDES);
                events.Repeat(33s);
                break;
            }
            case EVENT_HINDERING_CLEAVE:
            {
                DoCastVictim(SPELL_HINDERING_CLEAVE);
                events.Repeat(17s);
                break;
            }
            case EVENT_CHECK_MANA:
            {
                if (me->GetPowerPct(POWER_MANA) >= 100)
                {
                    Talk(SAY_REINFORCING_WARD);
                    Talk(SAY_REINFORCING_WARD_WARNING);
                    DoCastSelf(SPELL_REINFORCING_WARD_SELECTOR, TRIGGERED_IGNORE_POWER_COST | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                }
                events.Repeat(500ms);
                break;
            }
            default:
                break;
        }
    }
};

// 134058 - Galecaller Faye <Master of the Tempest>
struct boss_galecaller_faye : public TidesageCouncilSharedAI
{
    boss_galecaller_faye(Creature* creature) : TidesageCouncilSharedAI(creature, DATA_GALECALLER_FAYE) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_COSMETIC_SWIFTNESS_WARD);
        me->SetPowerType(POWER_MANA);
        me->SetPower(POWER_MANA, me->GetMaxPower(POWER_MANA) / 2);
    }

    void JustDied(Unit* killer) override
    {
        TidesageCouncilSharedAI::JustDied(killer);

        if (Creature* brother = instance->GetCreature(DATA_BROTHER_IRONHULL))
            brother->AI()->Talk(SAY_FAYE_DIES);
    }

    void JustEngagedWith(Unit* who) override
    {
        TidesageCouncilSharedAI::JustEngagedWith(who);
        DoCastSelf(SPELL_GALECALLER_FAYE_GAIN_ENERGY);
    }

    void ScheduleEvents() override
    {
        events.ScheduleEvent(EVENT_SLICING_BLAST, 1s);
        events.ScheduleEvent(EVENT_CHECK_MANA, 500ms);

        if (IsHeroicOrHigher())
            events.ScheduleEvent(EVENT_BLESSING_OF_THE_TEMPEST, 26700ms);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_BLESSING_OF_THE_TEMPEST:
            {
                Talk(SAY_BLESSING_OF_THE_TEMPEST);
                DoCastSelf(SPELL_BLESSING_OF_THE_TEMPEST);
                events.Repeat(20s);
                break;
            }
            case EVENT_SLICING_BLAST:
            {
                DoCastVictim(SPELL_SLICING_BLAST);
                events.Repeat(2500ms);
                break;
            }
            case EVENT_CHECK_MANA:
            {
                if (me->GetPowerPct(POWER_MANA) >= 100)
                {
                    Talk(SAY_SWIFTING_WARD_WARNING);
                    Talk(SAY_SWIFTING_WARD);
                    DoCastSelf(SPELL_SWIFTNESS_WARD_SELECTOR, TRIGGERED_IGNORE_POWER_COST | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                }
                events.Repeat(500ms);
                break;
            }
            default:
                break;
        }
    }
};

// 267902 - Swiftness Ward
// 267903 - Reinforcing Ward
class spell_tidesage_council_ward_selector : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ static_cast<uint32>(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit()->GetPosition(), GetEffectValue(), CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleAfterCast() const
    {
        GetCaster()->SetPower(POWER_MANA, 0);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_tidesage_council_ward_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_tidesage_council_ward_selector::HandleAfterCast);
    }
};

// 267830 - Blessing of the Tempest
class spell_tidesage_council_blessing_of_the_tempest : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLOWBACK_MISSILE });
    }

    void HandleProc(ProcEventInfo const& /*eventInfo*/) const
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_BLOWBACK_MISSILE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnProc += AuraProcFn(spell_tidesage_council_blessing_of_the_tempest::HandleProc);
    }
};

// 267905 - Reinforcing Ward
struct at_tidesage_council_reinforcing_ward : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetEntry() == BOSS_BROTHER_IRONHULL || unit->GetEntry() == BOSS_GALECALLER_FAYE)
        {
            unit->CastSpell(unit, SPELL_REINFORCING_WARD_DAMAGE_TAKEN_BOSS, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            unit->CastSpell(unit, SPELL_REINFORCING_WARD_DISPEL_BOSS, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
        else
        {
            unit->CastSpell(unit, SPELL_REINFORCING_WARD_DAMAGE_TAKEN_PLAYER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            unit->CastSpell(unit, SPELL_REINFORCING_WARD_DISPEL_PLAYER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        }
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_REINFORCING_WARD_DAMAGE_TAKEN_BOSS);
        unit->RemoveAurasDueToSpell(SPELL_REINFORCING_WARD_DAMAGE_TAKEN_PLAYER);
    }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(1s, [this](TaskContext task)
        {
            for (ObjectGuid const& guid : at->GetInsideUnits())
            {
                Unit* unit = ObjectAccessor::GetUnit(*at, guid);
                if (!unit)
                    continue;

                if (unit->isDead())
                    continue;

                if (unit->GetEntry() == BOSS_BROTHER_IRONHULL || unit->GetEntry() == BOSS_GALECALLER_FAYE)
                    unit->CastSpell(unit, SPELL_REINFORCING_WARD_DISPEL_BOSS, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                else
                    unit->CastSpell(unit, SPELL_REINFORCING_WARD_DISPEL_PLAYER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            }
            task.Repeat(1s);
        });
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 267891 - Swiftness Ward
// Id - 13154
struct at_tidesage_council_swiftness_ward_boss : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetEntry() != BOSS_BROTHER_IRONHULL && unit->GetEntry() != BOSS_GALECALLER_FAYE)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_SWIFTNESS_WARD_HASTE_BOSS, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_SWIFTNESS_WARD_HASTE_BOSS);
    }
};

// 267891 - Swiftness Ward
// Id - 13157
struct at_tidesage_council_swiftness_ward_player : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetEntry() == BOSS_BROTHER_IRONHULL || unit->GetEntry() == BOSS_GALECALLER_FAYE)
            return;

        unit->CastSpell(unit, SPELL_SWIFTNESS_WARD_HASTE_PLAYER, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_SWIFTNESS_WARD_HASTE_PLAYER);
    }
};

// 267836 - Blowback
struct at_tidesage_council_blowback : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_BLOWBACK_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

void AddSC_boss_tidesage_council()
{
    RegisterShrineOfTheStormCreatureAI(boss_brother_ironhull);
    RegisterShrineOfTheStormCreatureAI(boss_galecaller_faye);

    RegisterSpellScript(spell_tidesage_council_ward_selector);
    RegisterSpellScript(spell_tidesage_council_blessing_of_the_tempest);

    RegisterAreaTriggerAI(at_tidesage_council_reinforcing_ward);
    RegisterAreaTriggerAI(at_tidesage_council_swiftness_ward_boss);
    RegisterAreaTriggerAI(at_tidesage_council_swiftness_ward_player);
    RegisterAreaTriggerAI(at_tidesage_council_blowback);
}
