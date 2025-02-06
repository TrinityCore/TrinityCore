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
#include "CellImpl.h"
#include "Containers.h"
#include "Creature.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "atal_dazar.h"

enum PriestessAlunzaSpells
{
    SPELL_RITUAL                 = 258386,
    SPELL_ENERGY_REGEN           = 258681,
    SPELL_GILDED_CLAWS           = 255579,
    SPELL_AGITATE                = 255615,
    SPELL_MOLTEN_GOLD_MISSILE    = 255583,
    SPELL_TRANSFUSION            = 255577,
    SPELL_TRANSFUSION_HEAL       = 255835,
    SPELL_TRANSFUSION_DAMAGE     = 255836,
    SPELL_TAINTED_BLOOD_SELECTOR = 255592,
    SPELL_TAINTED_BLOOD_MISSILE  = 255565,
    SPELL_TAINTED_BLOOD_DAMAGE   = 255558,
    SPELL_TAINTED_BLOOD_AT       = 255559,
    SPELL_SPIRIT_OF_GOLD         = 259205,
    SPELL_CORRUPTED_GOLD         = 258703,
    SPELL_CORRUPTED_GOLD_DAMAGE  = 258709,

    SPELL_SPAWN                  = 259018,
    SPELL_TIKI_MASK              = 277065,
    SPELL_CORRUPT                = 259032,
    SPELL_FATALLY_CORRUPTED      = 259123
};

enum PriestessAlunzaEvents
{
    EVENT_GILDED_CLAWS = 1,
    EVENT_TAINTED_BLOOD,
    EVENT_MOLTEN_GOLD,
    EVENT_CHECK_ENERGY,
    EVENT_CORRUPTED_GOLD,
    EVENT_SPIRIT_OF_GOLD,

    EVENT_CHECK_TAINTED_BLOOD
};

enum PriestessAlunzaTexts
{
    SAY_AGGRO                = 0,
    SAY_GILDED_CLAWS_WARNING = 1,
    SAY_GILDED_CLAWS         = 2,
    SAY_TRANSFUSION_WARNING  = 3,
    SAY_TRANSFUSION          = 4,
    SAY_SLAY                 = 5,
    SAY_WIPE                 = 6,
    SAY_DIED                 = 7
};

enum PriestessAlunzaMisc
{
    NPC_CORRUPTED_GOLD        = 130738,
    NPC_SPIRIT_OF_GOLD        = 131009,

    POINT_DESPAWN             = 0,
    POINT_POOL                = 1,

    AREATRIGGER_TAINTED_BLOOD = 16553,

    SUMMON_GROUP_CAULDRONS      = 0,
};

constexpr Position RitualPosition[5] =
{
    { -1124.4688f, 2294.139f,  747.2801f  },
    { -1126.8889f, 2307.7466f, 743.11414f },
    { -1124.342f,  2292.5173f, 747.76434f },
    { -1131.6841f, 2304.0347f, 743.94354f },
    { -1131.2916f, 2282.3438f, 743.99896f }
};

constexpr Position TaintedBloodPosition[11] =
{
    { -1084.0f, 2276.5f, 740.784f   },
    { -1084.0f, 2292.5f, 740.784f   },
    { -1096.0f, 2316.5f, 740.78394f },
    { -1088.0f, 2268.5f, 740.784f   },
    { -1100.0f, 2276.5f, 740.78406f },
    { -1096.0f, 2268.5f, 740.784f   },
    { -1080.0f, 2316.5f, 740.78394f },
    { -1088.0f, 2284.5f, 740.784f   },
    { -1088.0f, 2316.5f, 740.604f   },
    { -1080.0f, 2300.5f, 740.603f   },
    { -1100.0f, 2308.5f, 740.604f   }
};

constexpr Position CorruptedGoldSpawnPosition[2] =
{
    { -1110.4965f, 2259.4306f, 741.8436f, 0.261799f },
    { -1110.5451f, 2325.2829f, 741.8436f, 0.785398f }
};

constexpr Position SpiritOfGoldSpawnPosition = { -1119.8f, 2292.46f, 745.114f };

// 122967 - Priestess Alun'za
struct boss_priestess_alun_za : public BossAI
{
    boss_priestess_alun_za(Creature* creature) : BossAI(creature, DATA_PRIESTESS_ALUNZA) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_RITUAL);
        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 0);

        me->SummonCreatureGroup(SUMMON_GROUP_CAULDRONS);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();

        Talk(SAY_WIPE);

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

        Talk(SAY_AGGRO);

        DoCastSelf(SPELL_ENERGY_REGEN);

        events.ScheduleEvent(EVENT_GILDED_CLAWS, 10500ms);
        events.ScheduleEvent(EVENT_TAINTED_BLOOD, 2s, 4s);
        events.ScheduleEvent(EVENT_MOLTEN_GOLD, 16500ms);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);

        if (IsHeroicOrHigher() || IsMythicPlus())
        {
            events.ScheduleEvent(EVENT_SPIRIT_OF_GOLD, 9100ms);
            events.ScheduleEvent(EVENT_CORRUPTED_GOLD, 3s);
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_DIED);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_GILDED_CLAWS:
            {
                Talk(SAY_GILDED_CLAWS_WARNING, me);
                Talk(SAY_GILDED_CLAWS);
                DoCastSelf(SPELL_GILDED_CLAWS);
                events.Repeat(33500ms);
                break;
            }
            case EVENT_TAINTED_BLOOD:
            {
                DoCast(SPELL_TAINTED_BLOOD_SELECTOR);
                events.Repeat(2s, 4s);
                break;
            }
            case EVENT_MOLTEN_GOLD:
            {
                DoCast(SPELL_AGITATE);
                events.Repeat(16500ms);
                break;
            }
            case EVENT_CHECK_ENERGY:
            {
                if (me->GetPower(POWER_ENERGY) >= 100)
                {
                    Talk(SAY_TRANSFUSION_WARNING);
                    Talk(SAY_TRANSFUSION);
                    DoCast(SPELL_TRANSFUSION);
                }
                events.Repeat(500ms);
                break;
            }
            case EVENT_CORRUPTED_GOLD:
            {
                me->SummonCreature(NPC_CORRUPTED_GOLD, CorruptedGoldSpawnPosition[0], TEMPSUMMON_MANUAL_DESPAWN);
                me->SummonCreature(NPC_CORRUPTED_GOLD, CorruptedGoldSpawnPosition[1], TEMPSUMMON_MANUAL_DESPAWN);
                events.Repeat(3s);
                break;
            }
            case EVENT_SPIRIT_OF_GOLD:
            {
                DoCast(SPELL_SPIRIT_OF_GOLD);
                events.Repeat(35s);
                break;
            }
            default:
                break;
        }
    }
};

// 130738 - Corrupted Gold
struct npc_priestess_alun_za_corrupted_gold : public ScriptedAI
{
    npc_priestess_alun_za_corrupted_gold(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_CORRUPTED_GOLD);

        static constexpr float MIN_DISTANCE = 25.0f;
        static constexpr float MAX_DISTANCE = 116.0f;
        static constexpr float RAYCAST_Z = 742.5f;

        float randomAngle = frand(me->GetOrientation() - float(M_PI) / 2.0f, me->GetOrientation() + float(M_PI) / 2.0f);
        Position despawnPos;

        do
        {
            despawnPos = Position(me->GetPositionX(), me->GetPositionY(), RAYCAST_Z);
            me->MovePositionToFirstCollision(despawnPos, MAX_DISTANCE, randomAngle);

            // in case we hit the nearest wall we try to get a different position
            randomAngle += frand(float(M_PI) / 4, float(M_PI) / 2);
        } while (me->GetDistance(despawnPos) < MIN_DISTANCE);
        me->GetMotionMaster()->MovePoint(POINT_DESPAWN, despawnPos, true, {}, 2.0f);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_DESPAWN)
            me->DespawnOrUnsummon();
    }

private:
    TaskScheduler _scheduler;
};

// 131009 - Spirit of Gold
struct npc_priestess_alun_za_spirit_of_gold : public ScriptedAI
{
    npc_priestess_alun_za_spirit_of_gold(Creature* creature) : ScriptedAI(creature) { }

    AreaTrigger* GetClosestTaintedBloodAreaTrigger() const
    {
        static constexpr float SELECT_RANGE_TAINTED_BLOOD = 300.0f;

        AreaTrigger* at = nullptr;
        Trinity::NearestAreaTriggerEntryInObjectRangeCheck check(*me, AREATRIGGER_TAINTED_BLOOD, SELECT_RANGE_TAINTED_BLOOD);
        Trinity::AreaTriggerLastSearcher<Trinity::NearestAreaTriggerEntryInObjectRangeCheck> checker(me, at, check);
        Cell::VisitGridObjects(me, checker, SELECT_RANGE_TAINTED_BLOOD);
        return at;
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_SPAWN);
        DoCastSelf(SPELL_TIKI_MASK);

        _events.ScheduleEvent(EVENT_CHECK_TAINTED_BLOOD, 500ms);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId != POINT_POOL)
            return;

        if (me->HasAura(SPELL_FATALLY_CORRUPTED))
            return;

        AreaTrigger* closestAt = GetClosestTaintedBloodAreaTrigger();
        if (closestAt && me->GetDistance(closestAt) <= 1.0f)
            DoCastSelf(SPELL_CORRUPT);

        _events.ScheduleEvent(EVENT_CHECK_TAINTED_BLOOD, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CHECK_TAINTED_BLOOD:
                {
                    if (me->HasAura(SPELL_FATALLY_CORRUPTED))
                        break;

                    if (AreaTrigger* at = GetClosestTaintedBloodAreaTrigger())
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MovePoint(POINT_POOL, at ->GetPosition());
                    }
                    else
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        _events.Repeat(500ms);
                    }
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
    EventMap _events;
};

// 258388 - Ritual
class spell_priestess_alun_za_ritual : public SpellScript
{
    static void SetDest(SpellDestination& dest)
    {
        dest.Relocate(Trinity::Containers::SelectRandomContainerElement(RitualPosition));
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_priestess_alun_za_ritual::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 258681 - Energy Regen
class spell_priestess_alun_za_energy_regen : public AuraScript
{
    void OnPeriodic(AuraEffect const* aurEff) const
    {
        GetTarget()->ModifyPower(POWER_ENERGY, aurEff->GetAmount() / 10);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_priestess_alun_za_energy_regen::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 255615 - Agitate
class spell_priestess_alun_za_agitate : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectValue(), CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
        });
    }

    static void SelectTarget(std::list<WorldObject*>& targets)
    {
        targets.resize(1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_alun_za_agitate::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_priestess_alun_za_agitate::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 255591 - Molten Gold
class spell_priestess_alun_za_molten_gold : public AuraScript
{
    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, aurEff->GetAmount(), CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_priestess_alun_za_molten_gold::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 255584 - Molten Gold
class spell_priestess_alun_za_molten_gold_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_MOLTEN_GOLD_MISSILE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_MOLTEN_GOLD_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_alun_za_molten_gold_selector::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 255566 - Bubble
class spell_priestess_alun_za_bubble : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TAINTED_BLOOD_MISSILE });
    }

    void HandleScript(SpellEffIndex /*effIndex*/) const
    {
        GetHitUnit()->CastSpell(*GetHitDest(), SPELL_TAINTED_BLOOD_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_alun_za_bubble::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 255565 - Bubble
class spell_priestess_alun_za_tainted_blood : public SpellScript
{
    static void SetDest(SpellDestination& dest)
    {
        dest.Relocate(Trinity::Containers::SelectRandomContainerElement(TaintedBloodPosition));
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_priestess_alun_za_tainted_blood::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 255577 - Transfusion
class spell_priestess_alun_za_transfusion_cast : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ENERGY_REGEN });
    }

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_ENERGY_REGEN, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_priestess_alun_za_transfusion_cast::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 255575 - transfusion Damage
class spell_priestess_alun_za_transfusion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TAINTED_BLOOD_DAMAGE, SPELL_TRANSFUSION_DAMAGE, SPELL_TRANSFUSION_HEAL });
    }

    void HandleTransfusion(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        CastSpellExtraArgs args;
        args.SetTriggerFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        args.SetTriggeringSpell(GetSpell());

        if (target->HasAura(SPELL_TAINTED_BLOOD_DAMAGE))
            caster->CastSpell(target, SPELL_TRANSFUSION_DAMAGE, args);
        else
            caster->CastSpell(target, SPELL_TRANSFUSION_HEAL, args);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_alun_za_transfusion::HandleTransfusion, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 255835 - Transfusion
// 255836 - Transfusion
class spell_priestess_alun_za_transfusion_heal_and_damage : public SpellScript
{
    void HandleValue(SpellEffIndex /*effIndex*/)
    {
        SetEffectValue(GetEffectValue() / 100);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_priestess_alun_za_transfusion_heal_and_damage::HandleValue, EFFECT_0, SPELL_EFFECT_HEAL_PCT);
    }
};

// 259205 - Spirit of Gold
// 259209 - Summon Spirit of Gold
class spell_priestess_alun_za_spirit_of_gold : public SpellScript
{
    static void SetDest(SpellDestination& dest)
    {
        dest.Relocate(SpiritOfGoldSpawnPosition);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_priestess_alun_za_spirit_of_gold::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 259032 - Corrupt
class spell_priestess_alun_za_corrupt : public AuraScript
{
    void OnStackChange(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/) const
    {
        if (GetStackAmount() == 8)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_FATALLY_CORRUPTED, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringAura = aurEff
            });

            Creature* creature = GetTarget()->ToCreature();
            if (!creature)
                return;

            creature->SetReactState(REACT_AGGRESSIVE);
            creature->AI()->DoZoneInCombat();
        }
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_priestess_alun_za_corrupt::OnStackChange, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAPPLY);
    }
};

// 255559 - Tainted Blood
// ID - 11867
struct at_priestess_alun_za_tainted_blood : AreaTriggerAI
{
    at_priestess_alun_za_tainted_blood(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->IsPlayer())
        {
            unit->CastSpell(unit, SPELL_TAINTED_BLOOD_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            at->Remove();
        }
        else if (unit->GetEntry() == NPC_SPIRIT_OF_GOLD && !unit->HasAura(SPELL_FATALLY_CORRUPTED))
        {
            _scheduler.Schedule(3s, [this](TaskContext /*task*/)
            {
                at->Remove();
            });
        }
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 258703 - Corrupted Gold
// ID - 12159
struct at_priestess_alun_za_corrupted_gold : AreaTriggerAI
{
    at_priestess_alun_za_corrupted_gold(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_CORRUPTED_GOLD_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }
};

void AddSC_boss_priestess_alun_za()
{
    RegisterAtalDazarCreatureAI(boss_priestess_alun_za);
    RegisterAtalDazarCreatureAI(npc_priestess_alun_za_corrupted_gold);
    RegisterAtalDazarCreatureAI(npc_priestess_alun_za_spirit_of_gold);

    RegisterSpellScript(spell_priestess_alun_za_ritual);
    RegisterSpellScript(spell_priestess_alun_za_energy_regen);
    RegisterSpellScript(spell_priestess_alun_za_agitate);
    RegisterSpellScript(spell_priestess_alun_za_molten_gold);
    RegisterSpellScript(spell_priestess_alun_za_molten_gold_selector);
    RegisterSpellScript(spell_priestess_alun_za_bubble);
    RegisterSpellScript(spell_priestess_alun_za_tainted_blood);
    RegisterSpellScript(spell_priestess_alun_za_transfusion_cast);
    RegisterSpellScript(spell_priestess_alun_za_transfusion);
    RegisterSpellScript(spell_priestess_alun_za_transfusion_heal_and_damage);
    RegisterSpellScript(spell_priestess_alun_za_spirit_of_gold);
    RegisterSpellScript(spell_priestess_alun_za_corrupt);

    RegisterAreaTriggerAI(at_priestess_alun_za_tainted_blood);
    RegisterAreaTriggerAI(at_priestess_alun_za_corrupted_gold);
}
