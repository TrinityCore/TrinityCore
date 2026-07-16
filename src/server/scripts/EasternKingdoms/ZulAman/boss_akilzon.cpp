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
#include "GridNotifiers.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "Weather.h"
#include "zulaman.h"

enum AkilzonTexts
{
    SAY_AGGRO                   = 0,
    SAY_SUMMON                  = 1,
    SAY_BERSERK                 = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,
    SAY_EVENT                   = 5,
    EMOTE_STORM                 = 6
};

enum AkilzonSpells
{
    // Akil'zon
    SPELL_GUST_OF_WIND          = 43621,
    SPELL_STATIC_DISRUPTION     = 43622,
    SPELL_CALL_LIGHTNING        = 43661,
    SPELL_ELECTRICAL_STORM      = 44735,
    SPELL_BERSERK               = 45078,

    // Soaring Eagle
    SPELL_EAGLE_SWOOP           = 44733,

    // Scripts
    SPELL_ELECTRICAL_STORM_AURA = 44007,
    SPELL_TELEPORT_SELF         = 44006,
    SPELL_ELECTRICAL_ARC_1      = 43653,
    SPELL_ELECTRICAL_ARC_2      = 43654,
    SPELL_ELECTRICAL_ARC_3      = 43655,
    SPELL_ELECTRICAL_ARC_4      = 43656,
    SPELL_ELECTRICAL_ARC_5      = 43659
};

enum AkilzonEvents
{
    EVENT_GUST_OF_WIND          = 1,
    EVENT_STATIC_DISRUPTION,
    EVENT_CALL_LIGHTNING,
    EVENT_SUMMON_EAGLES,
    EVENT_SET_WEATHER,
    EVENT_SET_WEATHER_2,
    EVENT_ELECTRICAL_STORM,
    EVENT_BERSERK
};

enum AkilzonMisc
{
    SPAWN_GROUP_EAGLE_1         = 381,
    SPAWN_GROUP_EAGLE_2         = 382,
    SPAWN_GROUP_EAGLE_3         = 383,
    SPAWN_GROUP_EAGLE_4         = 384,
    AREA_ZULAMAN                = 3805,
    SOUND_EAGLE                 = 12196
};

static constexpr std::array<uint32, 4> EagleSpawnGroupsData =
{
    SPAWN_GROUP_EAGLE_1,
    SPAWN_GROUP_EAGLE_2,
    SPAWN_GROUP_EAGLE_3,
    SPAWN_GROUP_EAGLE_4
};

// 23574 - Akil'zon
struct boss_akilzon : public BossAI
{
    boss_akilzon(Creature* creature) : BossAI(creature, BOSS_AKILZON) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_GUST_OF_WIND, 10s, 20s);
        events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 6s, 12s);
        events.ScheduleEvent(EVENT_CALL_LIGHTNING, 5s, 15s);
        events.ScheduleEvent(EVENT_SUMMON_EAGLES, 1min);
        events.ScheduleEvent(EVENT_SET_WEATHER, 40s);
        events.ScheduleEvent(EVENT_BERSERK, 10min);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BERSERK)
            Talk(SAY_BERSERK);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        for (uint32 group : EagleSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);

        // Guessed. What should we do?
        me->GetMap()->SetZoneWeather(AREA_ZULAMAN, WEATHER_STATE_FINE, 0.0f);

        _DespawnAtEvade();
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        for (uint32 group : EagleSpawnGroupsData)
            me->GetMap()->SpawnGroupDespawn(group);
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
                case EVENT_GUST_OF_WIND:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 1, 80.0f, true))
                        DoCast(target, SPELL_GUST_OF_WIND);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_STATIC_DISRUPTION:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                        DoCast(target, SPELL_STATIC_DISRUPTION);
                    events.Repeat(6s, 12s);
                    break;
                case EVENT_CALL_LIGHTNING:
                    DoCastVictim(SPELL_CALL_LIGHTNING);
                    events.Repeat(5s, 25s);
                    break;
                case EVENT_SUMMON_EAGLES:
                    Talk(SAY_SUMMON);
                    for (uint32 group : EagleSpawnGroupsData)
                        me->GetMap()->SpawnGroupSpawn(group, true);
                    events.Repeat(1min);
                    break;
                case EVENT_SET_WEATHER:
                    me->GetMap()->SetZoneWeather(AREA_ZULAMAN, WEATHER_STATE_MEDIUM_RAIN, 0.75f);
                    events.Repeat(1min);
                    events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 8500ms);
                    events.ScheduleEvent(EVENT_SET_WEATHER_2, 17s);
                    break;
                case EVENT_SET_WEATHER_2:
                    me->GetMap()->SetZoneWeather(AREA_ZULAMAN, WEATHER_STATE_FOG, 0.0f);
                    break;
                case EVENT_ELECTRICAL_STORM:
                    DoCastSelf(SPELL_ELECTRICAL_STORM);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_BERSERK);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

// 24858 - Soaring Eagle
struct npc_soaring_eagle : public ScriptedAI
{
    using ScriptedAI::ScriptedAI;

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetCorpseDelay(15, true);
        ScriptedAI::InitializeAI();
    }

    void JustAppeared() override
    {
        _scheduler.Schedule(0s, 10s, [this](TaskContext task)
        {
            DoPlaySoundToSet(me, SOUND_EAGLE);
            DoCastSelf(SPELL_EAGLE_SWOOP);
            task.Repeat(1s, 15s);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (UpdateVictim())
            DoMeleeAttackIfReady();
    }

private:
    TaskScheduler _scheduler;
};

// 44733 - Eagle Swoop Primer
class spell_akilzon_eagle_swoop_primer : public SpellScript
{
    PrepareSpellScript(spell_akilzon_eagle_swoop_primer);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_akilzon_eagle_swoop_primer::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_akilzon_eagle_swoop_primer::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 44735 - Electrical Overload Primer
class spell_akilzon_electrical_overload_primer : public SpellScript
{
    PrepareSpellScript(spell_akilzon_electrical_overload_primer);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_akilzon_electrical_overload_primer::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_akilzon_electrical_overload_primer::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 43658 - Electrical Overload Graphic Pulse
class spell_akilzon_electrical_overload : public SpellScript
{
    PrepareSpellScript(spell_akilzon_electrical_overload);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            SPELL_ELECTRICAL_ARC_1,
            SPELL_ELECTRICAL_ARC_2,
            SPELL_ELECTRICAL_ARC_3,
            SPELL_ELECTRICAL_ARC_4,
            SPELL_ELECTRICAL_ARC_5
        }) && ValidateSpellInfo({ spellInfo->GetEffect(EFFECT_1).TriggerSpell });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(nullptr, SPELL_ELECTRICAL_ARC_1, true);
        caster->CastSpell(nullptr, SPELL_ELECTRICAL_ARC_2, true);
        caster->CastSpell(nullptr, SPELL_ELECTRICAL_ARC_3, true);
        caster->CastSpell(nullptr, SPELL_ELECTRICAL_ARC_4, true);
        caster->CastSpell(nullptr, SPELL_ELECTRICAL_ARC_5, true);
    }

    void HandleEffect(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);

        SpellInfo const* damageSpellSpellInfo = sSpellMgr->AssertSpellInfo(GetEffectInfo().TriggerSpell);

        if (SpellInfo const* triggeringSpellSpellInfo = GetTriggeringSpell())
            if (AuraEffect const* eff = GetCaster()->GetAuraEffect(triggeringSpellSpellInfo->Id, EFFECT_1))
                GetCaster()->CastSpell(nullptr, uint32(GetEffectInfo().TriggerSpell), CastSpellExtraArgs()
                    .SetTriggerFlags(TRIGGERED_FULL_MASK)
                    .AddSpellMod(SPELLVALUE_BASE_POINT0, int32(eff->GetTickNumber() * damageSpellSpellInfo->GetEffect(EFFECT_0).CalcValue())));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_akilzon_electrical_overload::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectLaunch += SpellEffectFn(spell_akilzon_electrical_overload::HandleEffect, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
    }
};

// 43648 - Electrical Storm
class spell_akilzon_electrical_storm : public SpellScript
{
    PrepareSpellScript(spell_akilzon_electrical_storm);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ELECTRICAL_STORM_AURA, SPELL_TELEPORT_SELF });
    }

    void HandleAfterHit()
    {
        Unit* target = GetHitUnit();

        if (Creature* caster = GetCaster()->ToCreature())
            caster->AI()->Talk(EMOTE_STORM, target);

        // this is a hack to ensure that DynamicObject granting SPELL_ELECTRICAL_STORM_AURA is only removed after damaging periodic fades
        target->m_Events.AddEventAtOffset([target]
        {
            target->CastSpell(nullptr, SPELL_ELECTRICAL_STORM_AURA, true);
            target->CastSpell(nullptr, SPELL_TELEPORT_SELF, true);
        }, 100ms);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_akilzon_electrical_storm::HandleAfterHit);
    }
};

// 43657 - Electrical Storm
class spell_akilzon_electrical_storm_damage : public SpellScript
{
    PrepareSpellScript(spell_akilzon_electrical_storm_damage);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ELECTRICAL_STORM_AURA });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_ELECTRICAL_STORM_AURA));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_akilzon_electrical_storm_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// 44006 - Teleport Self
class spell_akilzon_teleport_self : public SpellScript
{
    PrepareSpellScript(spell_akilzon_teleport_self);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 10.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_akilzon_teleport_self::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

void AddSC_boss_akilzon()
{
    RegisterZulAmanCreatureAI(boss_akilzon);
    RegisterZulAmanCreatureAI(npc_soaring_eagle);
    RegisterSpellScript(spell_akilzon_eagle_swoop_primer);
    RegisterSpellScript(spell_akilzon_electrical_overload_primer);
    RegisterSpellScript(spell_akilzon_electrical_overload);
    RegisterSpellScript(spell_akilzon_electrical_storm);
    RegisterSpellScript(spell_akilzon_electrical_storm_damage);
    RegisterSpellScript(spell_akilzon_teleport_self);
}
