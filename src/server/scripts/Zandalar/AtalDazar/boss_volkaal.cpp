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
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "atal_dazar.h"

enum VolkaalSpells
{
    SPELL_SOUL_ANCHOR         = 259537,
    SPELL_BAD_VOODOO          = 250192,
    SPELL_RAPID_DECAY         = 250241,
    SPELL_RAPID_DECAY_TARGET  = 250694,
    SPELL_RAPID_DECAY_RANDOM  = 250697,
    SPELL_TOXIC_POOL          = 250585,
    SPELL_REANIMATE           = 259531,
    SPELL_TOXIC_LEAP_SELECTOR = 250708,
    SPELL_TOXIC_LEAP          = 250258,
    SPELL_TOXIC_LEAP_DAMAGE   = 250259,
    SPELL_NOXIOUS_STENCH      = 259572,
    SPELL_LINGERING_NAUSEA    = 250372
};

enum VolkaalEvents
{
    EVENT_TOXIC_LEAP = 1,
    EVENT_NOXIOUS_STENCH,
};

enum VolkaalActions
{
    ACTION_TOTEMS_DIED = 1
};

enum VolkaalSummonGroups
{
    SUMMON_GROUP_VOLKAAL_TOTEMS = 0
};

enum VolkaalTexts
{
    SAY_AGGRO = 0,
    SAY_DECAY = 1,
    SAY_DIED  = 2,
    SAY_SLAY  = 3,
    SAY_WIPE  = 4
};

// 122965 - Vol'kaal
struct boss_volkaal : public BossAI
{
    boss_volkaal(Creature* creature) : BossAI(creature, DATA_VOLKAAL) { }

    void Reset() override
    {
        _Reset();
    }

    void JustAppeared() override
    {
        me->SummonCreatureGroup(SUMMON_GROUP_VOLKAAL_TOTEMS);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_WIPE);

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();

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
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

        std::list<Creature*> totems;
        me->GetCreatureListWithEntryInGrid(totems, NPC_REANIMATION_TOTEM);
        for (Creature* totem : totems)
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, totem);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_TOXIC_LEAP, 2200ms);
        events.ScheduleEvent(EVENT_NOXIOUS_STENCH, 5800ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DIED);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_RAPID_DECAY)
        {
            Talk(SAY_DECAY);
            events.CancelEvent(EVENT_TOXIC_LEAP);
        }
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == EVENT_JUMP)
            DoCastSelf(SPELL_TOXIC_LEAP_DAMAGE);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_TOXIC_LEAP:
            {
                DoCast(SPELL_TOXIC_LEAP_SELECTOR);
                events.Repeat(6s);
                break;
            }
            case EVENT_NOXIOUS_STENCH:
            {
                DoCast(SPELL_NOXIOUS_STENCH);
                events.Repeat(19400ms);
                events.RescheduleEvent(EVENT_TOXIC_LEAP, 8500ms);
                break;
            }
            default:
                break;
        }
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

// 125977 - Reanimation Totem
struct npc_volkaal_reanimation_totem : public ScriptedAI
{
    npc_volkaal_reanimation_totem(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        if (IsHeroicOrHigher())
            me->SetUnkillable(true);
    }

    void DamageTaken(Unit* /*who*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (IsHeroicOrHigher())
        {
            if (me->GetHealth() <= damage)
            {
                DoCastSelf(SPELL_SOUL_ANCHOR);
                DoCastSelf(SPELL_REANIMATE);
            }
        }

        InstanceScript* instance = me->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* volkaal = instance->GetCreature(DATA_VOLKAAL))
            volkaal->AI()->DoZoneInCombat();
    }

    void DoAction(int32 action) override
    {
        if (action == ACTION_TOTEMS_DIED)
        {
            std::list<Creature*> totems;
            me->GetCreatureListWithEntryInGrid(totems, me->GetEntry());
            for (Creature* totem : totems)
            {
                totem->SetUnkillable(false);
                totem->KillSelf();
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        InstanceScript* instance = me->GetInstanceScript();
        if (!instance)
            return;

        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }
};

// 250372 - Lingering Nausea
class spell_volkaal_lingering_nausea : public AuraScript
{
    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        GetCaster()->CastSpell(target, aurEff->GetAmount(), CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_volkaal_lingering_nausea::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 250368 - Noxious Stench
class spell_volkaal_noxious_stench : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_LINGERING_NAUSEA });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_LINGERING_NAUSEA, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_volkaal_noxious_stench::HandleDummy, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 250708 - Toxic Leap
class spell_volkaal_toxic_leap_selector : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_volkaal_toxic_leap_selector::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 250229 - Soul Anchor
class spell_volkaal_soul_anchor : public SpellScript
{
    void SelectTotem(std::list<WorldObject*>& targets) const
    {
        if (targets.empty())
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            if (Creature* totem = instance->GetCreature(DATA_VOLKAAL_TOTEM))
                if (npc_volkaal_reanimation_totem* totemAI = CAST_AI(npc_volkaal_reanimation_totem, totem->GetAI()))
                    totemAI->DoAction(ACTION_TOTEMS_DIED);

            Unit* caster = GetCaster();
            caster->RemoveAurasDueToSpell(SPELL_BAD_VOODOO);
            caster->CastSpell(caster, SPELL_RAPID_DECAY, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_volkaal_soul_anchor::SelectTotem, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 259531 - Reanimate
class spell_volkaal_reanimate : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->RemoveAurasDueToSpell(SPELL_SOUL_ANCHOR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_volkaal_reanimate::HandleScript, EFFECT_0, SPELL_EFFECT_HEAL_PCT);
    }
};

// 250241 - Rapid Decay
class spell_volkaal_rapid_decay : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo ({ SPELL_RAPID_DECAY_TARGET, SPELL_RAPID_DECAY_RANDOM });
    }

    void HandleToxicPool(AuraEffect const* aurEff) const
    {
        Unit* caster = GetCaster();

        float range = 100.0f;
        Player* player = nullptr;
        Trinity::AnyPlayerInObjectRangeCheck check(caster, range);
        Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(caster, player, check);
        Cell::VisitWorldObjects(caster, searcher, range);

        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR;
        args.TriggeringAura = aurEff;
        caster->CastSpell(player->GetPosition(), SPELL_RAPID_DECAY_TARGET, args);
        caster->CastSpell(caster, SPELL_RAPID_DECAY_RANDOM, args);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_volkaal_rapid_decay::HandleToxicPool, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

// 250696 - Rapid Decay
// ID - 11243
struct at_volkaal_rapid_decay : AreaTriggerAI
{
    at_volkaal_rapid_decay(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_TOXIC_POOL, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_TOXIC_POOL);
    }

    void OnRemove() override
    {
        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Unit* unit = ObjectAccessor::GetUnit(*at, guid);
            if (!unit)
                continue;

            OnUnitExit(unit);
        }
    }
};

void AddSC_boss_volkaal()
{
    RegisterAtalDazarCreatureAI(boss_volkaal);
    RegisterAtalDazarCreatureAI(npc_volkaal_reanimation_totem);

    RegisterSpellScript(spell_volkaal_lingering_nausea);
    RegisterSpellScript(spell_volkaal_noxious_stench);
    RegisterSpellScript(spell_volkaal_toxic_leap_selector);
    RegisterSpellScript(spell_volkaal_soul_anchor);
    RegisterSpellScript(spell_volkaal_reanimate);
    RegisterSpellScript(spell_volkaal_rapid_decay);

    RegisterAreaTriggerAI(at_volkaal_rapid_decay);
}
