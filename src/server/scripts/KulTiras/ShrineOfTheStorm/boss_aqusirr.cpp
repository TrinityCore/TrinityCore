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

enum AqusirrSpells
{
    // Lord Stormsong
    SPELL_WATER_RITUAL                   = 274341,
    SPELL_REQUIEM_OF_THE_ABYSS_PERIODIC  = 274364,
    SPELL_REQUIEM_OF_THE_ABYSS           = 274359,
    SPELL_REQUIEM_OF_THE_ABYSS_KNOCKBACK = 274367,
    SPELL_SPLASHING_WATERS               = 241680,

    // Aqu'sirr
    SPELL_EMERGE_VISUAL                  = 274948,
    SPELL_UNDERTOW                       = 264144,
    SPELL_SEA_BLAST                      = 265001,
    SPELL_SURGING_RUSH_DAMAGE            = 264155,
    SPELL_SURGING_RUSH                   = 264101,
    SPELL_ERUPTING_WATERS_SPLIT          = 264903,
    SPELL_ERUPTING_WATERS_DAMAGE         = 264941,
    SPELL_ERUPTING_WATERS_AQUALING       = 265030,
    SPELL_CHOKING_BRINE                  = 264560,
    SPELL_CHOKING_BRINE_MISSILE          = 264714,
    SPELL_CHOKING_BRINE_MISSILE_2        = 264703,
    SPELL_GRASP_FROM_THE_DEPTHS_SELECTOR = 264477,
    SPELL_GRASP_FROM_THE_DEPTHS_SUMMON   = 264522,
    SPELL_GRASP_FROM_THE_DEPTHS_DAMAGE   = 264526,

    SPELL_CONVERSATION_HORDE             = 274669,
    SPELL_CONVERSATION_ALLIANCE          = 274668
};

enum AqusirrEvents
{
    EVENT_SURGING_RUSH = 1,
    EVENT_CHOKING_BRINE,
    EVENT_SEA_BLAST,
    EVENT_UNDERTOW,
    EVENT_GRASP_FROM_THE_DEPTHS
};

enum AqusirrActions
{
    ACTION_START_INTRO = 1
};

enum AqusirrTexts
{
    SAY_AQUSIRR_INTRO_1 = 0,
    SAY_AQUSIRR_INTRO_2 = 1
};

enum AqusirrMisc
{
    SPAWN_GROUP_ID_AQUSIRR = 9999, // TODO: change when merge
    ANIM_KIT_SURGING_RUSH  = 11428
};

constexpr Position RequiemOfTheAbyssPosition = { 3932.82f, -1243.81f, 128.368f };
constexpr Position EruptingWatersSummonPosition1 = { 3917.31f, -1234.08f, 128.130f };
constexpr Position EruptingWatersSummonPosition2 = { 3924.02f, -1259.52f, 128.141f };
constexpr Position EruptingWatersSummonPosition3 = { 3950.80f, -1238.47f, 127.831f };

struct AqusirrSharedAI : public BossAI
{
    AqusirrSharedAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId)
    {
        SetBoundary(instance->GetBossBoundary(DATA_AQUSIRR));
    }

    virtual void ScheduleEvents()
    {
        events.ScheduleEvent(EVENT_SURGING_RUSH, 17s);
        events.ScheduleEvent(EVENT_CHOKING_BRINE, 8900ms);
        events.ScheduleEvent(EVENT_UNDERTOW, 36800ms);
        events.ScheduleEvent(EVENT_SEA_BLAST, 1s);

        if (IsHeroicOrHigher())
            events.ScheduleEvent(EVENT_GRASP_FROM_THE_DEPTHS, 14300ms);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        ScheduleEvents();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SEA_BLAST:
            {
                if (!me->GetCurrentSpell(CURRENT_CHANNELED_SPELL) && !me->IsWithinMeleeRange(me->GetVictim()))
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        DoCast(target, SPELL_SEA_BLAST);
                    events.Repeat(2400ms);
                }
                events.Repeat(1s);
                break;
            }
            case EVENT_CHOKING_BRINE:
            {
                if (me->GetMap()->GetPlayersCountExceptGMs() > 1) // This event doesn't happen if you go alone
                {
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                        DoCast(target, SPELL_CHOKING_BRINE);
                }
                events.Repeat(34s, 39s);
                break;
            }
            case EVENT_SURGING_RUSH:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                    DoCast(target, SPELL_SURGING_RUSH);
                events.RescheduleEvent(EVENT_SEA_BLAST, 10s);
                events.Repeat(31500ms, 39300ms);
                break;
            }
            case EVENT_UNDERTOW:
            {
                if (Unit* target = SelectTarget(SelectTargetMethod::Random))
                    DoCast(target, SPELL_UNDERTOW);
                events.Repeat(32400ms, 34s);
                break;
            }
            case EVENT_GRASP_FROM_THE_DEPTHS:
            {
                DoCast(SPELL_GRASP_FROM_THE_DEPTHS_SELECTOR);
                events.Repeat(38s);
                break;
            }
            default:
                break;
        }
    }
};

// 134056 - Aqu'sirr
struct boss_aqusirr : public AqusirrSharedAI
{
    boss_aqusirr(Creature* creature) : AqusirrSharedAI(creature, DATA_AQUSIRR), _triggered(false), _aqualingDefeatedCount(0) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_EMERGE_VISUAL);
    }

    void JustEngagedWith(Unit* who) override
    {
        AqusirrSharedAI::JustEngagedWith(who);
        instance->SetBossState(DATA_AQUSIRR, IN_PROGRESS);
    }

    void Reset() override
    {
        events.Reset();
        _triggered = false;
        _aqualingDefeatedCount = 0;
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_AQUSIRR, FAIL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_GRASP_FROM_THE_DEPTHS_DAMAGE);

        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_AQUSIRR, DONE);

        Creature* shrineDummy = GetClosestCreatureWithOptions(me, 50.0f, { .CreatureId = NPC_SHRINE_OF_THE_STORM_DUMMY, .IgnorePhases = true });
        if (!shrineDummy)
            return;

        shrineDummy->CastSpell(shrineDummy, instance->instance->GetTeamInInstance() == HORDE ? SPELL_CONVERSATION_HORDE : SPELL_CONVERSATION_ALLIANCE, true);

    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !_triggered)
        {
            _triggered = true;
            me->SetUnkillable(true);
            DoCastSelf(SPELL_ERUPTING_WATERS_SPLIT);
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_ERUPTING_WATERS_AQUALING)
        {
            if (_aqualingDefeatedCount <= 1)
            {
                DoCastSelf(SPELL_ERUPTING_WATERS_DAMAGE);
                _aqualingDefeatedCount++;
            }
            else if (_aqualingDefeatedCount == 2)
            {
                DoCastSelf(SPELL_ERUPTING_WATERS_DAMAGE);
                me->RemoveAurasDueToSpell(SPELL_ERUPTING_WATERS_SPLIT);
                me->SetUnkillable(false);
            }
        }
    }

private:
    bool _triggered;
    uint8 _aqualingDefeatedCount;
};

// 134828 - Aqualing
struct boss_aqusirr_aqualing : public AqusirrSharedAI
{
    boss_aqusirr_aqualing(Creature* creature) : AqusirrSharedAI(creature, DATA_AQUALING) { }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        DoZoneInCombat();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DoCast(SPELL_ERUPTING_WATERS_AQUALING);
    }

    void JustEngagedWith(Unit* who) override
    {
        AqusirrSharedAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
        ScheduleEvents();
    }
};

// 139737 - Lord Stormsong
struct npc_aqusirr_intro_lord_stormsong : public CreatureAI
{
    npc_aqusirr_intro_lord_stormsong(Creature* creature) : CreatureAI(creature) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_START_INTRO)
        {
            me->RemoveAurasDueToSpell(SPELL_WATER_RITUAL);

            Seconds delay = 1s;

            _scheduler.Schedule(delay, [this](TaskContext)
            {
                me->SetFacingTo(0.1939797f);
            });

            delay += 3s;

            _scheduler.Schedule(delay, [this](TaskContext)
            {
                Talk(SAY_AQUSIRR_INTRO_1);
            });

            delay += 6s;

            _scheduler.Schedule(delay, [this](TaskContext)
            {
                Talk(SAY_AQUSIRR_INTRO_2);
            });

            delay += 6s;

            _scheduler.Schedule(delay, [this](TaskContext)
            {
                DoCastSelf(SPELL_REQUIEM_OF_THE_ABYSS);
            });

            delay += 1s;

            _scheduler.Schedule(1s, [this](TaskContext)
            {
                DoCastSelf(SPELL_REQUIEM_OF_THE_ABYSS_PERIODIC, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
            });

            delay += 6s;

            _scheduler.Schedule(delay, [this](TaskContext)
            {
                me->GetMap()->SpawnGroupSpawn(SPAWN_GROUP_ID_AQUSIRR);
            });

            delay += 3s;

            _scheduler.Schedule(delay + 800ms, [this](TaskContext)
            {
                DoCastSelf(SPELL_SPLASHING_WATERS);
            });
        }
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_SPLASHING_WATERS)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 274365 - Requiem of the Abyss (Visual)
// 274367 - Requiem of the Abyss (Knockback)
class spell_aqusirr_requiem_of_the_abyss : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(RequiemOfTheAbyssPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_aqusirr_requiem_of_the_abyss::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 274364 - Requiem of the Abyss
class spell_aqusirr_requiem_of_the_abyss_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_REQUIEM_OF_THE_ABYSS_KNOCKBACK });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* creature = GetTarget()->ToCreature();
        if (!creature)
            return;

        creature->CastSpell(nullptr, SPELL_REQUIEM_OF_THE_ABYSS_KNOCKBACK, false);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_aqusirr_requiem_of_the_abyss_periodic::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 264911 - Erupting Waters
class spell_aqusirr_erupting_waters_split_1 : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(EruptingWatersSummonPosition1);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_aqusirr_erupting_waters_split_1::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 264912 - Erupting Waters
class spell_aqusirr_erupting_waters_split_2 : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(EruptingWatersSummonPosition2);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_aqusirr_erupting_waters_split_2::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 264913 - Erupting Waters
class spell_aqusirr_erupting_waters_split_3 : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(EruptingWatersSummonPosition3);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_aqusirr_erupting_waters_split_3::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 264560 - Choking Brine
class spell_aqusirr_choking_brine : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CHOKING_BRINE_MISSILE, SPELL_CHOKING_BRINE_MISSILE_2 });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_CHOKING_BRINE_MISSILE, TRIGGERED_IGNORE_CAST_IN_PROGRESS);

        for (uint8 i = 0; i < 5; ++i)
            target->CastSpell(target, SPELL_CHOKING_BRINE_MISSILE_2, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_aqusirr_choking_brine::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 274260 - Surging Rush
class spell_aqusirr_surging_rush : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* creatureTarget = GetHitCreature();
        if (!creatureTarget)
            return;

        creatureTarget->SetDisableGravity(true);
        creatureTarget->AddUnitState(UNIT_STATE_ROOT);
        creatureTarget->PlayOneShotAnimKitId(ANIM_KIT_SURGING_RUSH);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_aqusirr_surging_rush::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_ACTION_SET);
    }
};

// 264102 - Surging Rush
class spell_aqusirr_surging_rush_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SURGING_RUSH });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SURGING_RUSH, true);
    }

    void HandleActionSet(SpellEffIndex /*effIndex*/)
    {
        Creature* creatureTarget = GetHitCreature();
        if (!creatureTarget)
            return;

        creatureTarget->SetDisableGravity(false);
        creatureTarget->ClearUnitState(UNIT_STATE_ROOT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_aqusirr_surging_rush_selector::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_aqusirr_surging_rush_selector::HandleActionSet, EFFECT_2, SPELL_EFFECT_TRIGGER_ACTION_SET);
    }
};

// 264941 - Erupting Waters
class spell_aqusirr_erupting_waters : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        caster->SetHealth(caster->GetHealth() - caster->CountPctFromMaxHealth(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_aqusirr_erupting_waters::HandleDamage, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 264477 - Grasp from the Depths
class spell_aqusirr_grasp_from_the_depths_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GRASP_FROM_THE_DEPTHS_SUMMON });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GRASP_FROM_THE_DEPTHS_SUMMON, TRIGGERED_IGNORE_CAST_IN_PROGRESS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_aqusirr_grasp_from_the_depths_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// XXXX - Areatrigger (TODO: Set on merge)
struct at_aqusirr_intro : AreaTriggerAI
{
    at_aqusirr_intro(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player)
            return;

        Creature* lordSongstorm = unit->FindNearestCreature(NPC_LORD_SONGSTORM_AQUSIRR, 50.0f);
        if (!lordSongstorm)
            return;

        lordSongstorm->AI()->DoAction(ACTION_START_INTRO);
        at->Remove();
    }
};

// 264144 - Undertow
struct at_aqusirr_undertow : AreaTriggerAI
{
    at_aqusirr_undertow(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -5.0f, MovementForceType::Gravity);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveMovementForce(at->GetGUID());
    }
};

// 264101 - Surging Rush
struct at_aqusirr_surging_rush : AreaTriggerAI
{
    at_aqusirr_surging_rush(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_SURGING_RUSH_DAMAGE, false);
    }
};

void AddSC_boss_aqusirr()
{
    RegisterShrineOfTheStormCreatureAI(boss_aqusirr);
    RegisterShrineOfTheStormCreatureAI(boss_aqusirr_aqualing);
    RegisterShrineOfTheStormCreatureAI(npc_aqusirr_intro_lord_stormsong);

    RegisterSpellScript(spell_aqusirr_requiem_of_the_abyss);
    RegisterSpellScript(spell_aqusirr_requiem_of_the_abyss_periodic);
    RegisterSpellScript(spell_aqusirr_erupting_waters_split_1);
    RegisterSpellScript(spell_aqusirr_erupting_waters_split_2);
    RegisterSpellScript(spell_aqusirr_erupting_waters_split_3);
    RegisterSpellScript(spell_aqusirr_choking_brine);
    RegisterSpellScript(spell_aqusirr_surging_rush);
    RegisterSpellScript(spell_aqusirr_surging_rush_selector);
    RegisterSpellScript(spell_aqusirr_erupting_waters);
    RegisterSpellScript(spell_aqusirr_grasp_from_the_depths_selector);

    RegisterAreaTriggerAI(at_aqusirr_intro);
    RegisterAreaTriggerAI(at_aqusirr_undertow);
    RegisterAreaTriggerAI(at_aqusirr_surging_rush);
}
