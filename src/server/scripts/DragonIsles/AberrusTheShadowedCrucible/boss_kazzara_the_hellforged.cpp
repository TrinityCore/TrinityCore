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
#include "GameObject.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "aberrus_the_shadowed_crucible.h"

enum KazzaraSpells
{
    // Intro
    SPELL_DREAD_LANDING                         = 411872,
    SPELL_FEAR                                  = 220540,
    SPELL_KAZZARA_INTRO                         = 410541,

    // Kazzara
    SPELL_DREAD_RIFTS                           = 407196,
    SPELL_DREAD_RIFT_AURA                       = 406525,
    SPELL_DREAD_RIFT_SUMMON                     = 406526,
    SPELL_DREAD_RIFTS_3_TARGETS                 = 406516,
    SPELL_DREAD_RIFTS_4_TARGETS                 = 407198,
    SPELL_DREAD_RIFTS_5_TARGETS                 = 407199,
    SPELL_DREAD_RIFTS_6_TARGETS                 = 407200,
    SPELL_DREAD_RIFT_MARKER                     = 411926,
    SPELL_HELLBEAM                              = 400430,
    SPELL_HELLSTEEL_CARNAGE_40_PCT              = 401319,
    SPELL_HELLSTEEL_CARNAGE_60_PCT              = 401318,
    SPELL_HELLSTEEL_CARNAGE_80_PCT              = 401316,
    SPELL_HELLSTEEL_CARNAGE_TRANSFORM_40_PCT    = 401335,
    SPELL_HELLSTEEL_CARNAGE_TRANSFORM_60_PCT    = 401331,
    SPELL_HELLSTEEL_CARNAGE_TRANSFORM_80_PCT    = 401328,
    SPELL_HELLSTEEL_FRAGMENTS_40_PCT            = 404595,
    SPELL_HELLSTEEL_FRAGMENTS_60_PCT            = 404593,
    SPELL_HELLSTEEL_FRAGMENTS_80_PCT            = 404553,
    SPELL_INFERNAL_FUSION                       = 408147,
    SPELL_INFERNAL_HEART_40_PCT                 = 408373,
    SPELL_INFERNAL_HEART_60_PCT                 = 408372,
    SPELL_INFERNAL_HEART_80_PCT                 = 408367,
    SPELL_MOLTEN_SCAR_AREATRIGGER               = 402421,
    SPELL_MOLTEN_SCAR_AREATRIGGER_RIFT          = 407517,
    SPELL_MOLTEN_SCAR_DAMAGE                    = 402420,
    SPELL_OVERRIDE_POWER_DISPLAY                = 402550,
    SPELL_PERIODIC_ENERGIZE                     = 402538,
    SPELL_RAY_OF_ANGUISH_AREA                   = 402260,
    SPELL_RAY_OF_ANGUISH_AREATRIGGER            = 402219,
    SPELL_RAY_OF_ANGUISH_DAMAGE                 = 402207,
    SPELL_RAY_OF_ANGUISH_FIXATE_SELECTOR        = 407218,
    SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS        = 409256,
    SPELL_RAY_OF_ANGUISH_AURA_MARKER            = 411925,
    SPELL_RAY_OF_ANGUISH_DECREASE_SPEED         = 402299,
    SPELL_RAY_OF_ANGUISH_FIXATE                 = 402253,
    SPELL_RAY_OF_ANGUISH_MISSILE                = 402187,
    SPELL_RAYS_OF_ANGUISH                       = 407069,
    SPELL_RELENTLESS_TORMENT                    = 410511,
    SPELL_REVENANTS_BLOOD_80_PCT                = 404407,
    SPELL_REVENANTS_BLOOD_60_PCT                = 404784,
    SPELL_REVENANTS_BLOOD_40_PCT                = 407488,
    SPELL_RIFTBURN                              = 406530,
    SPELL_TERROR_CLAWS                          = 404744,
    SPELL_TERROR_CLAWS_DAMAGE                   = 406597,
    SPELL_TERROR_CLAWS_PERIODIC_AURA            = 404743,
    SPELL_TERROR_CLAWS_PERIODIC_DAMAGE          = 401898,
    SPELL_TERROR_CLAWS_SHADOWFLAME_DAMAGE       = 406601,
    SPELL_WINGS_OF_EXTINCTION                   = 403326
};

enum KazzaraTexts
{
    SAY_AGGRO                   = 0,
    SAY_WINGS_OF_EXTINCTION     = 1,
    SAY_ARMOR_80_PCT            = 2,
    SAY_RAYS_OF_ANGUISH         = 3,
    SAY_HELLBEAM                = 4,
    SAY_HELLBEAM_ALERT          = 5,
    SAY_TERROR_CLAWS            = 6,
    SAY_ARMOR_60_PCT            = 7,
    SAY_ARMOR_40_PCT            = 8,
    SAY_KILL                    = 9,
    SAY_DIED                    = 10,
    SAY_WIPE                    = 11,

    // Ray of Anguish
    SAY_FIXATE                  = 0
};

enum KazzaraEvents
{
    EVENT_RAYS_OF_ANGUISH = 1,
    EVENT_TERROR_CLAWS,
    EVENT_WINGS_OF_EXTINCTION,
    EVENT_DREAD_RIFT,
    EVENT_CHECK_ENERGY,

    // Ray of Anguish
    EVENT_MOLTEN_SCAR,
    EVENT_RELENTLESS_TORMENT
};

enum KazzaraActions
{
    ACTION_HEALTH_BELOW_80_PCT = 1,
    ACTION_HEALTH_BELOW_60_PCT = 2,
    ACTION_HEALTH_BELOW_40_PCT = 3
};

enum KazzaraMisc
{
    NPC_RAY_OF_ANGUISH = 202167
};

// 201261 - Kazzara the Hellforged
struct boss_kazzara_the_hellforged : public BossAI
{
    boss_kazzara_the_hellforged(Creature* creature) : BossAI(creature, DATA_KAZZARA_THE_HELLFORGED), _hellsteelCarnageCast(0), _terrorClawsCount(1) { }

    void Reset() override
    {
        _Reset();
        _hellsteelCarnageCast = 0;
        _terrorClawsCount = 1;
        _pendingCarnages.clear();
        _energizeScheduler.CancelAll();
    }

    void KilledUnit(Unit* victim) override
    {
        if (!victim->IsPlayer())
            return;

        Talk(SAY_KILL);
    }

    void JustAppeared() override
    {
        if (instance->GetData(DATA_KAZZARA_INTRO_STATE) != DONE)
        {
            me->SetUninteractible(true);
            me->SetImmuneToAll(true);
            me->SetVisible(false);
        }

        me->SetPower(me->GetPowerType(), 0);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_DIED);
        _JustDied();
        _energizeScheduler.CancelAll();
        me->RemoveAllAreaTriggers();
        summons.DespawnAll();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        Talk(SAY_WIPE);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        DoCastSelf(SPELL_PERIODIC_ENERGIZE);
        DoCastSelf(SPELL_OVERRIDE_POWER_DISPLAY);

        events.ScheduleEvent(EVENT_TERROR_CLAWS, 4s);
        events.ScheduleEvent(EVENT_DREAD_RIFT, 7s);
        events.ScheduleEvent(EVENT_WINGS_OF_EXTINCTION, 14500ms);
        events.ScheduleEvent(EVENT_RAYS_OF_ANGUISH, 24s);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
    }

    void OnSpellStart(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_WINGS_OF_EXTINCTION:
                Talk(SAY_WINGS_OF_EXTINCTION);
                break;
            case SPELL_TERROR_CLAWS:
                Talk(SAY_TERROR_CLAWS);
                break;
            case SPELL_RAYS_OF_ANGUISH:
                Talk(SAY_RAYS_OF_ANGUISH);
                break;
            case SPELL_HELLBEAM:
                Talk(SAY_HELLBEAM);
                Talk(SAY_HELLBEAM_ALERT);
                ScheduleEnergize(7300ms);
                break;
            case SPELL_HELLSTEEL_CARNAGE_80_PCT:
                Talk(SAY_ARMOR_80_PCT);
                me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGIZE);
                ScheduleEnergize(9000ms);
                break;
            case SPELL_HELLSTEEL_CARNAGE_60_PCT:
                Talk(SAY_ARMOR_60_PCT);
                me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGIZE);
                ScheduleEnergize(9000ms);
                break;
            case SPELL_HELLSTEEL_CARNAGE_40_PCT:
                Talk(SAY_ARMOR_40_PCT);
                me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGIZE);
                ScheduleEnergize(9000ms);
                break;
            default:
                break;
        }
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_HELLSTEEL_CARNAGE_80_PCT:
                DoCastSelf(SPELL_INFERNAL_HEART_80_PCT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                break;
            case SPELL_HELLSTEEL_CARNAGE_60_PCT:
                me->RemoveAurasDueToSpell(SPELL_INFERNAL_HEART_80_PCT);
                DoCastSelf(SPELL_INFERNAL_HEART_60_PCT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                break;
            case SPELL_HELLSTEEL_CARNAGE_40_PCT:
                me->RemoveAurasDueToSpell(SPELL_INFERNAL_HEART_60_PCT);
                DoCastSelf(SPELL_INFERNAL_HEART_40_PCT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_HELLSTEEL_CARNAGE_40_PCT, DIFFICULTY_NONE);
        if (!spellInfo)
            return;

        if (me->HealthBelowPctDamaged(spellInfo->GetEffect(EFFECT_2).CalcValue(me), damage) && _hellsteelCarnageCast < 1)
            DoAction(ACTION_HEALTH_BELOW_80_PCT);
        else if (me->HealthBelowPctDamaged(spellInfo->GetEffect(EFFECT_3).CalcValue(me), damage) && _hellsteelCarnageCast < 2)
            DoAction(ACTION_HEALTH_BELOW_60_PCT);
        else if (me->HealthBelowPctDamaged(spellInfo->GetEffect(EFFECT_4).CalcValue(me), damage) && _hellsteelCarnageCast < 3)
            DoAction(ACTION_HEALTH_BELOW_40_PCT);
    }

    void DoAction(int32 actionId) override
    {
        switch (actionId)
        {
            case ACTION_START_KAZZARA_INTRO:
            {
                if (GameObject* gate = instance->GetGameObject(DATA_KAZZARA_GATE))
                {
                    gate->SetFlag(GO_FLAG_IN_USE);
                    gate->SetGoState(GO_STATE_READY);
                }

                me->SetVisible(true);
                DoCast(SPELL_DREAD_LANDING);
                DoCast(SPELL_KAZZARA_INTRO);

                scheduler.Schedule(1s + 500ms, [this](TaskContext const& /*context*/)
                {
                    std::vector<Creature*> sunderedMobs;
                    GetCreatureListWithOptionsInGrid(sunderedMobs, me, 70.0f, { .StringId = "sundered_mob" });
                    for (Creature* sunderedMob : sunderedMobs)
                    {
                        if (!sunderedMob->IsAlive() || sunderedMob->IsInCombat())
                            continue;

                        sunderedMob->CastSpell(nullptr, SPELL_FEAR, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
                    }
                });

                scheduler.Schedule(12s, [this](TaskContext const& /*context*/)
                {
                    me->SetUninteractible(false);
                    me->SetImmuneToAll(false);
                });
                break;
            }
            case ACTION_HEALTH_BELOW_80_PCT:
                _pendingCarnages.push_back(SPELL_HELLSTEEL_CARNAGE_80_PCT);
                ++_hellsteelCarnageCast;
                break;
            case ACTION_HEALTH_BELOW_60_PCT:
                _pendingCarnages.push_back(SPELL_HELLSTEEL_CARNAGE_60_PCT);
                ++_hellsteelCarnageCast;
                break;
            case ACTION_HEALTH_BELOW_40_PCT:
                _pendingCarnages.push_back(SPELL_HELLSTEEL_CARNAGE_40_PCT);
                ++_hellsteelCarnageCast;
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
        _energizeScheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (!_pendingCarnages.empty())
        {
            if (DoCastSelf(_pendingCarnages.front()) == SPELL_CAST_OK)
                _pendingCarnages.pop_front();
            return;
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RAYS_OF_ANGUISH:
                    DoCastSelf(SPELL_RAYS_OF_ANGUISH);
                    events.Repeat(34100ms);
                    break;
                case EVENT_TERROR_CLAWS:
                {
                    DoCastVictim(SPELL_TERROR_CLAWS);
                    _terrorClawsCount++;
                    events.Repeat(_terrorClawsCount % 2 == 0 ? 15800ms : 20700ms);
                    break;
                }
                case EVENT_WINGS_OF_EXTINCTION:
                    DoCastSelf(SPELL_WINGS_OF_EXTINCTION);
                    events.Repeat(35s);
                    break;
                case EVENT_DREAD_RIFT:
                    DoCastSelf(SPELL_DREAD_RIFTS);
                    events.Repeat(35s);
                    break;
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(me->GetPowerType()) >= 100)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 70.0f, true))
                        {
                            me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGIZE);
                            DoCast(target, SPELL_HELLBEAM);
                        }
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

private:
    void ScheduleEnergize(Milliseconds delay)
    {
        // own scheduler without BossAI's casting validator: retail's Energize comes 9.0 s after every Carnage start and
        // 7.3 s after a Hellbeam start, also when the boss is casting then (scheduler held it until the cast ended)
        _energizeScheduler.CancelAll();
        _energizeScheduler.Schedule(delay, [this](TaskContext const& /*context*/)
        {
            DoCastSelf(SPELL_PERIODIC_ENERGIZE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        });
    }

    uint8 _hellsteelCarnageCast;
    uint32 _terrorClawsCount;
    std::deque<uint32> _pendingCarnages;
    TaskScheduler _energizeScheduler;
};

// 202167 - Ray of Anguish
struct npc_kazzara_ray_of_anguish : public ScriptedAI
{
    npc_kazzara_ray_of_anguish(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_RAY_OF_ANGUISH_AREATRIGGER);
        DoCastSelf(SPELL_RAY_OF_ANGUISH_DECREASE_SPEED);
        DoCastSelf(SPELL_RAY_OF_ANGUISH_FIXATE_SELECTOR);

        if (IsLFR() || IsNormal())
            me->DespawnOrUnsummon(17500ms);

        _events.ScheduleEvent(EVENT_MOLTEN_SCAR, 400ms);

        if (IsHeroicOrHigher())
            _events.ScheduleEvent(EVENT_RELENTLESS_TORMENT, 32600ms, 41700ms);
    }

    void SpellHitTarget(WorldObject* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_RAY_OF_ANGUISH_FIXATE)
            Talk(SAY_FIXATE, target);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOLTEN_SCAR:
                    DoCastSelf(SPELL_MOLTEN_SCAR_AREATRIGGER);
                    _events.Repeat(400ms);
                    break;
                case EVENT_RELENTLESS_TORMENT:
                    DoCastSelf(SPELL_RELENTLESS_TORMENT);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 406525 - Dread Rift
class spell_kazzara_dread_rift : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget()->GetPosition(), SPELL_DREAD_RIFT_SUMMON, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_kazzara_dread_rift::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 406517 - Dread Rift (periodic selector)
class spell_kazzara_dread_rift_player_select : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DREAD_RIFT_MARKER,
            SPELL_DREAD_RIFT_AURA
        });
    }

    void HandleDreadRift(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DREAD_RIFT_AURA, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleDreadRiftSelector(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DREAD_RIFT_MARKER, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_dread_rift_player_select::HandleDreadRift, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_dread_rift_player_select::HandleDreadRiftSelector, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 407196 - Dread Rifts
class spell_kazzara_dread_rifts : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DREAD_RIFTS_3_TARGETS,
            SPELL_DREAD_RIFTS_4_TARGETS,
            SPELL_DREAD_RIFTS_5_TARGETS,
            SPELL_DREAD_RIFTS_6_TARGETS,
            SPELL_INFERNAL_HEART_40_PCT,
            SPELL_INFERNAL_HEART_60_PCT,
            SPELL_INFERNAL_HEART_80_PCT
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        uint32 spellId = SPELL_DREAD_RIFTS_3_TARGETS;
        Unit* caster = GetCaster();

        if (caster->HasAura(SPELL_INFERNAL_HEART_80_PCT))
            spellId = SPELL_DREAD_RIFTS_4_TARGETS;
        else if (caster->HasAura(SPELL_INFERNAL_HEART_60_PCT))
            spellId = SPELL_DREAD_RIFTS_5_TARGETS;
        else if (caster->HasAura(SPELL_INFERNAL_HEART_40_PCT))
            spellId = SPELL_DREAD_RIFTS_6_TARGETS;

        caster->CastSpell(caster, spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_dread_rifts::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 402538 - Energize
class spell_kazzara_energize : public AuraScript
{
    static constexpr std::array<uint8, 29> KazzaraEnergizeCycle = { 3, 4, 3, 4, 3, 4, 4, 3, 4, 3, 4, 3, 4, 4, 3, 4, 3, 4, 3, 4, 3, 4, 4, 3, 4, 3, 4, 3, 1 };

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        Unit* target = GetTarget();
        uint32 cycleIdx = std::min<uint32>(aurEff->GetTickNumber() - 1, KazzaraEnergizeCycle.size() - 1);
        target->ModifyPower(target->GetPowerType(), KazzaraEnergizeCycle[cycleIdx]);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kazzara_energize::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 402547 - Hellbeam
class spell_kazzara_hellbeam_consume_energy : public SpellScript
{
    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* target = GetHitUnit();
        target->SetPower(target->GetPowerType(), target->GetPower(target->GetPowerType()) - 10);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_hellbeam_consume_energy::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 401328 - Hellsteel Carnage
// 401331 - Hellsteel Carnage
// 401335 - Hellsteel Carnage
class spell_kazzara_hellsteel_carnage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_HELLSTEEL_CARNAGE_TRANSFORM_80_PCT,
            SPELL_HELLSTEEL_FRAGMENTS_80_PCT,
            SPELL_HELLSTEEL_CARNAGE_TRANSFORM_60_PCT,
            SPELL_HELLSTEEL_FRAGMENTS_60_PCT,
            SPELL_HELLSTEEL_CARNAGE_TRANSFORM_40_PCT,
            SPELL_HELLSTEEL_FRAGMENTS_40_PCT
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        uint32 spellId = GetSpellInfo()->Id;
        switch (spellId)
        {
            case SPELL_HELLSTEEL_CARNAGE_TRANSFORM_80_PCT:
                spellId = SPELL_HELLSTEEL_FRAGMENTS_80_PCT;
                break;
            case SPELL_HELLSTEEL_CARNAGE_TRANSFORM_60_PCT:
                spellId = SPELL_HELLSTEEL_FRAGMENTS_60_PCT;
                break;
            case SPELL_HELLSTEEL_CARNAGE_TRANSFORM_40_PCT:
                spellId = SPELL_HELLSTEEL_FRAGMENTS_40_PCT;
                break;
            default:
                break;
        }

        GetCaster()->CastSpell(GetCaster(), spellId, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_hellsteel_carnage::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 407069 - Rays of Anguish
class spell_kazzara_rays_of_anguish : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RAY_OF_ANGUISH_AREA });
    }

    void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& isPeriodic, int32& amplitude) const
    {
        if (_riftGuids.empty())
            return;

        isPeriodic = true;
        amplitude = GetDuration() / _riftGuids.size();
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        if (_riftGuids.empty())
            return;

        ObjectGuid guid = _riftGuids.front();
        _riftGuids.pop_front();

        if (WorldObject* target = ObjectAccessor::GetWorldObject(*GetTarget(), guid))
            target->CastSpell(target, SPELL_RAY_OF_ANGUISH_AREA,
                TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_kazzara_rays_of_anguish::CalcPeriodic, EFFECT_1, SPELL_AURA_DUMMY);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kazzara_rays_of_anguish::HandleDummyTick, EFFECT_1, SPELL_AURA_DUMMY);
    }

public:
    void SetRifts(std::list<WorldObject*> const& targets)
    {
        _riftGuids.clear();
        for (WorldObject* obj : targets)
            _riftGuids.push_back(obj->GetGUID());
    }

private:
    std::deque<ObjectGuid> _riftGuids;
};

// 407068 - Rays of Anguish
class spell_kazzara_rays_of_anguish_rift_selector : public SpellScript
{
    void CountTargets(std::list<WorldObject*>& targets)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* kazzara = instance->GetCreature(DATA_KAZZARA_THE_HELLFORGED);
        if (!kazzara)
            return;

        if (Aura* aura = kazzara->GetAura(SPELL_RAYS_OF_ANGUISH))
        {
            if (spell_kazzara_rays_of_anguish* script = aura->GetScript<spell_kazzara_rays_of_anguish>())
                script->SetRifts(targets);

            if (AuraEffect* aurEff = aura->GetEffect(EFFECT_1))
                aurEff->CalculatePeriodic(kazzara, true);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kazzara_rays_of_anguish_rift_selector::CountTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 407218 - Ray of Anguish
class spell_kazzara_ray_of_anguish_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS, SPELL_RAY_OF_ANGUISH_FIXATE });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        Unit* caster = GetCaster();
        targets.remove_if([](WorldObject const* target)
        {
            Player const* player = target->ToPlayer();
            return !player || !player->HasAura(SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS);
        });

        if (targets.empty())
            return;

        auto itr = std::ranges::min_element(targets, {}, [caster](WorldObject const* target)
        {
            return std::pair(target->ToUnit()->HasAura(SPELL_RAY_OF_ANGUISH_FIXATE), caster->GetExactDistSq(target));
        });

        WorldObject* selected = *itr;
        targets.clear();
        targets.push_back(selected);
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* creatureCaster = GetCaster()->ToCreature())
        {
            Unit* target = GetHitUnit();
            creatureCaster->CastSpell(target, SPELL_RAY_OF_ANGUISH_FIXATE, CastSpellExtraArgsInit{
                .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
                .TriggeringSpell = GetSpell()
            });
            creatureCaster->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kazzara_ray_of_anguish_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 402260 - Ray of Anguish
class spell_kazzara_ray_of_anguish_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_RAY_OF_ANGUISH_AURA_MARKER,
            SPELL_RAY_OF_ANGUISH_MISSILE,
            SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_RAY_OF_ANGUISH_AURA_MARKER));
    }

    void HandleHitAura(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleHitMissile(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAY_OF_ANGUISH_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void HandleHitAura2(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAY_OF_ANGUISH_AURA_MARKER, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kazzara_ray_of_anguish_trigger::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_trigger::HandleHitAura, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_trigger::HandleHitMissile, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_trigger::HandleHitAura2, EFFECT_2, SPELL_EFFECT_DUMMY);
    }
};

// 404553 - Hellsteel Fragments
// 404593 - Hellsteel Fragments
// 404595 - Hellsteel Fragments
class spell_kazzara_revenants_blood : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_REVENANTS_BLOOD_80_PCT,
            SPELL_HELLSTEEL_FRAGMENTS_80_PCT,
            SPELL_REVENANTS_BLOOD_60_PCT,
            SPELL_HELLSTEEL_FRAGMENTS_60_PCT,
            SPELL_REVENANTS_BLOOD_40_PCT,
            SPELL_HELLSTEEL_FRAGMENTS_40_PCT
        });
    }

    void HandleRevenantsBlood() const
    {
        uint32 spellId = GetSpellInfo()->Id;
        switch (spellId)
        {
            case SPELL_HELLSTEEL_FRAGMENTS_80_PCT:
                spellId = SPELL_REVENANTS_BLOOD_80_PCT;
                break;
            case SPELL_HELLSTEEL_FRAGMENTS_60_PCT:
                spellId = SPELL_REVENANTS_BLOOD_60_PCT;
                break;
            case SPELL_HELLSTEEL_FRAGMENTS_40_PCT:
                spellId = SPELL_REVENANTS_BLOOD_40_PCT;
                break;
            default:
                break;
        }

        GetCaster()->CastSpell(GetCaster(), spellId, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_kazzara_revenants_blood::HandleRevenantsBlood);
    }
};

// 404744 - Terror Claws
class spell_kazzara_terror_claws : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TERROR_CLAWS_DAMAGE,
            SPELL_TERROR_CLAWS_SHADOWFLAME_DAMAGE,
            SPELL_TERROR_CLAWS_PERIODIC_AURA
        });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        caster->CastSpell(target, SPELL_TERROR_CLAWS_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        caster->CastSpell(target, SPELL_TERROR_CLAWS_SHADOWFLAME_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
        caster->CastSpell(target, SPELL_TERROR_CLAWS_PERIODIC_AURA, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_terror_claws::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 404743 - Terror Claws (periodic)
class spell_kazzara_terror_claws_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TERROR_CLAWS_PERIODIC_DAMAGE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_TERROR_CLAWS_PERIODIC_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kazzara_terror_claws_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 407046 - Dread Rift
struct at_kazzara_dread_rift : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (unit->GetMap()->IsHeroicOrHigher() && unit->GetEntry() == NPC_RAY_OF_ANGUISH)
        {
            unit->ToCreature()->DespawnOrUnsummon();
            caster->CastSpell(at->GetPosition(), SPELL_MOLTEN_SCAR_AREATRIGGER_RIFT, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            at->Remove();
        }

        if (unit->IsPlayer())
        {
            caster->CastSpell(unit, SPELL_RIFTBURN, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
            unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -0.5f, MovementForceType::Gravity);
        }
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_RIFTBURN);
        unit->RemoveMovementForce(at->GetGUID());
    }
};

// 402421 - Molten Scar
// 407517 - Molten Scar
struct at_kazzara_molten_scar : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_MOLTEN_SCAR_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_MOLTEN_SCAR_DAMAGE);
    }
};

// 402421 - Molten Scar
struct at_kazzara_molten_scar_mythic : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (unit->GetEntry() == NPC_RAY_OF_ANGUISH)
            unit->CastSpell(at->GetPosition(), SPELL_INFERNAL_FUSION, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);

        if (unit->IsPlayer())
            caster->CastSpell(unit, SPELL_MOLTEN_SCAR_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_MOLTEN_SCAR_DAMAGE);
    }
};

// 402219 - Ray of Anguish
struct at_kazzara_ray_of_anguish : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_RAY_OF_ANGUISH_DAMAGE, TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveAurasDueToSpell(SPELL_RAY_OF_ANGUISH_DAMAGE);
    }
};

// 403326 - Wings of Extinction
struct at_kazzara_wings_of_extinction : AreaTriggerAI
{
    using AreaTriggerAI::AreaTriggerAI;

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -20.0f, MovementForceType::Gravity);
    }

    void OnUnitExit(Unit* unit, AreaTriggerExitReason /*reason*/) override
    {
        unit->RemoveMovementForce(at->GetGUID());
    }
};

void AddSC_boss_kazzara_the_hellforged()
{
    RegisterAberrusTheShadowedCrucibleCreatureAI(boss_kazzara_the_hellforged);
    RegisterAberrusTheShadowedCrucibleCreatureAI(npc_kazzara_ray_of_anguish);

    RegisterSpellScript(spell_kazzara_dread_rift);
    RegisterSpellScript(spell_kazzara_dread_rift_player_select);
    RegisterSpellScript(spell_kazzara_dread_rifts);
    RegisterSpellScript(spell_kazzara_energize);
    RegisterSpellScript(spell_kazzara_hellbeam_consume_energy);
    RegisterSpellScript(spell_kazzara_hellsteel_carnage);
    RegisterSpellScript(spell_kazzara_rays_of_anguish);
    RegisterSpellScript(spell_kazzara_rays_of_anguish_rift_selector);
    RegisterSpellScript(spell_kazzara_ray_of_anguish_selector);
    RegisterSpellScript(spell_kazzara_ray_of_anguish_trigger);
    RegisterSpellScript(spell_kazzara_revenants_blood);
    RegisterSpellScript(spell_kazzara_terror_claws);
    RegisterSpellScript(spell_kazzara_terror_claws_periodic);

    RegisterAreaTriggerAI(at_kazzara_dread_rift);
    RegisterAreaTriggerAI(at_kazzara_molten_scar);
    RegisterAreaTriggerAI(at_kazzara_molten_scar_mythic);
    RegisterAreaTriggerAI(at_kazzara_ray_of_anguish);
    RegisterAreaTriggerAI(at_kazzara_wings_of_extinction);
}
