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
    SPELL_DREAD_LANDING                     = 411872,
    SPELL_FEAR                              = 220540,
    SPELL_KAZZARA_INTRO                     = 410541,

    // Kazzara
    SPELL_DREAD_RIFTS                       = 407196,
    SPELL_DREAD_RIFT_AREATRIGGER            = 407046,
    SPELL_DREAD_RIFT_AURA                   = 406525,
    SPELL_DREAD_RIFT_SUMMON                 = 406526,
    SPELL_DREAD_RIFTS_3_TARGETS             = 406516,
    SPELL_DREAD_RIFTS_4_TARGETS             = 407198,
    SPELL_DREAD_RIFTS_5_TARGETS             = 407199,
    SPELL_DREAD_RIFTS_6_TARGETS             = 407200,
    SPELL_DREAD_RIFT_SELECTOR               = 411926,
    SPELL_HELLBEAM                          = 400430,
    SPELL_HELLSTEEL_CARNAGE_40_PCT          = 401319,
    SPELL_HELLSTEEL_CARNAGE_60_PCT          = 401318,
    SPELL_HELLSTEEL_CARNAGE_80_PCT          = 401316,
    SPELL_HELLSTEEL_CARNAGE_TRANSFORM_40_PCT = 401335,
    SPELL_HELLSTEEL_CARNAGE_TRANSFORM_60_PCT = 401331,
    SPELL_HELLSTEEL_CARNAGE_TRANSFORM_80_PCT = 401328,
    SPELL_HELLSTEEL_FRAGMENTS_40_PCT        = 404595,
    SPELL_HELLSTEEL_FRAGMENTS_60_PCT        = 404593,
    SPELL_HELLSTEEL_FRAGMENTS_80_PCT        = 404553,
    SPELL_INFERNAL_HEART_40_PCT             = 408373,
    SPELL_INFERNAL_HEART_60_PCT             = 408372,
    SPELL_INFERNAL_HEART_80_PCT             = 408367,
    SPELL_MOLTEN_SCAR_AREATRIGGER           = 402421,
    SPELL_MOLTEN_SCAR_DAMAGE                = 402420,
    SPELL_OVERRIDE_POWER_DISPLAY            = 402550,
    SPELL_PERIODIC_ENERGIZE                 = 402538,
    SPELL_RAY_OF_ANGUISH_AREA               = 402260,
    SPELL_RAY_OF_ANGUISH_AREATRIGGER        = 402219,
    SPELL_RAY_OF_ANGUISH_DAMAGE             = 402207,
    SPELL_RAY_OF_ANGUISH_DAMAGE_AREA        = 407218,
    SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS    = 409256,
    SPELL_RAY_OF_ANGUISH_AURA_45_SECONDS    = 411925,
    SPELL_RAY_OF_ANGUISH_DECREASE_SPEED     = 402299,
    SPELL_RAY_OF_ANGUISH_FIXATE             = 402253,
    SPELL_RAY_OF_ANGUISH_MISSILE            = 402187,
    SPELL_RAYS_OF_ANGUISH                   = 407069,
    SPELL_RAYS_OF_ANGUISH_RIFTS_CHECK       = 407068,
    SPELL_RIFTBURN                          = 406530,
    SPELL_TERROR_CLAWS_DAMAGE               = 406597,
    SPELL_TERROR_CLAWS_PERIODIC_AURA        = 404743,
    SPELL_TERROR_CLAWS_PERIODIC_DAMAGE      = 401898,
    SPELL_TERROR_CLAWS_SELECTOR             = 404744,
    SPELL_TERROR_CLAWS_SHADOWFLAME_DAMAGE   = 406601,
    SPELL_WINGS_OF_EXTINCTION               = 403326
};

enum KazzaraTexts
{
    SAY_AGGRO                               = 0,
    SAY_WINGS_OF_EXTINCTION                 = 1,
    SAY_ARMOR_80_PCT                        = 2,
    SAY_RAYS_OF_ANGUISH                     = 3,
    SAY_HELLBEAM                            = 4,
    SAY_HELLBEAM_ALERT                      = 5,
    SAY_TERROR_CLAWS                        = 6,
    SAY_ARMOR_60_PCT                        = 7,
    SAY_ARMOR_40_PCT                        = 8,
    SAY_KILL                                = 9,
    SAY_DIED                                = 10,

    // Ray of Anguish
    SAY_FIXATE                              = 0
};

enum KazzaraEvents
{
    EVENT_RAYS_OF_ANGUISH                   = 1,
    EVENT_TERROR_CLAWS                      = 2,
    EVENT_WINGS_OF_EXTINCTION               = 3,
    EVENT_ENERGIZE                          = 4,
    EVENT_DREAD_RIFT                        = 5,
    EVENT_CHECK_ENERGY                      = 6,

    // Ray of Anguish
    EVENT_MOLTEN_SCAR                       = 7
};

enum KazzaraActions
{
    ACTION_HEALTH_BELOW_80_PCT              = 1,
    ACTION_HEALTH_BELOW_60_PCT              = 2,
    ACTION_HEALTH_BELOW_40_PCT              = 3
};

// 201261 - Kazzara the Hellforged
struct boss_kazzara_the_hellforged : public BossAI
{
    boss_kazzara_the_hellforged(Creature* creature) : BossAI(creature, DATA_KAZZARA_THE_HELLFORGED), _hellsteelCarnageCast(0) { }

    void Reset() override
    {
        events.Reset();
        _hellsteelCarnageCast = 0;
        me->SetPower(POWER_ENERGY, 0);
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
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DIED);
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->RemoveAurasDueToSpell(SPELL_OVERRIDE_POWER_DISPLAY);
        me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGIZE);

        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        DoCastSelf(SPELL_OVERRIDE_POWER_DISPLAY, true);
        DoCastSelf(SPELL_PERIODIC_ENERGIZE);
        events.ScheduleEvent(EVENT_RAYS_OF_ANGUISH, 24s);
        events.ScheduleEvent(EVENT_TERROR_CLAWS, 5s);
        events.ScheduleEvent(EVENT_WINGS_OF_EXTINCTION, 14s);
        events.ScheduleEvent(EVENT_DREAD_RIFT, 12s);
        events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
    }

    void DamageTaken(Unit* /*killer*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_HELLSTEEL_CARNAGE_40_PCT, DIFFICULTY_NONE);

        if (!spellInfo)
            return;

        if (me->HealthBelowPctDamaged(spellInfo->GetEffect(EFFECT_2).CalcValue(me), damage) && _hellsteelCarnageCast < 1)
        {
            Talk(SAY_ARMOR_80_PCT);
            DoAction(ACTION_HEALTH_BELOW_80_PCT);
        }
        else if (me->HealthBelowPctDamaged(spellInfo->GetEffect(EFFECT_3).CalcValue(me), damage) && _hellsteelCarnageCast < 2)
        {
            Talk(SAY_ARMOR_60_PCT);
            DoAction(ACTION_HEALTH_BELOW_60_PCT);
        }
        else if (me->HealthBelowPctDamaged(spellInfo->GetEffect(EFFECT_4).CalcValue(me), damage) && _hellsteelCarnageCast < 3)
        {
            Talk(SAY_ARMOR_40_PCT);
            DoAction(ACTION_HEALTH_BELOW_40_PCT);
        }
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

                scheduler.Schedule(1s + 500ms, [this](TaskContext /*context*/)
                {
                    std::vector<Creature*> sunderedMobs;
                    GetCreatureListWithOptionsInGrid(sunderedMobs, me, 70.0f, { .StringId = "sundered_mob" });
                    for (Creature* sunderedMob : sunderedMobs)
                    {
                        if (!sunderedMob->IsAlive() || sunderedMob->IsInCombat())
                            continue;

                        sunderedMob->CastSpell(nullptr, SPELL_FEAR, false);
                    }
                });

                scheduler.Schedule(12s, [this](TaskContext /*context*/)
                {
                    me->SetUninteractible(false);
                    me->SetImmuneToAll(false);
                });
                break;
            }
            case ACTION_HEALTH_BELOW_80_PCT:
            {
                DoCastSelf(SPELL_HELLSTEEL_CARNAGE_80_PCT);
                DoCastSelf(SPELL_INFERNAL_HEART_80_PCT);
                ++_hellsteelCarnageCast;
                break;
            }
            case ACTION_HEALTH_BELOW_60_PCT:
            {
                DoCastSelf(SPELL_HELLSTEEL_CARNAGE_60_PCT);
                me->RemoveAurasDueToSpell(SPELL_INFERNAL_HEART_80_PCT);
                DoCastSelf(SPELL_INFERNAL_HEART_60_PCT);
                ++_hellsteelCarnageCast;
                break;
            }
            case ACTION_HEALTH_BELOW_40_PCT:
            {
                DoCastSelf(SPELL_HELLSTEEL_CARNAGE_40_PCT);
                me->RemoveAurasDueToSpell(SPELL_INFERNAL_HEART_60_PCT);
                DoCastSelf(SPELL_INFERNAL_HEART_40_PCT);
                ++_hellsteelCarnageCast;
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_RAYS_OF_ANGUISH:
                    Talk(SAY_RAYS_OF_ANGUISH);
                    DoCastSelf(SPELL_RAYS_OF_ANGUISH);
                    events.ScheduleEvent(EVENT_RAYS_OF_ANGUISH, 34s);
                    break;
                case EVENT_TERROR_CLAWS:
                    Talk(SAY_TERROR_CLAWS);
                    DoCastVictim(SPELL_TERROR_CLAWS_SELECTOR);
                    events.ScheduleEvent(EVENT_TERROR_CLAWS, 15s);
                    break;
                case EVENT_WINGS_OF_EXTINCTION:
                    Talk(SAY_WINGS_OF_EXTINCTION);
                    DoCastSelf(SPELL_WINGS_OF_EXTINCTION);
                    events.ScheduleEvent(EVENT_WINGS_OF_EXTINCTION, 34s);
                    break;
                case EVENT_ENERGIZE:
                    DoCastSelf(SPELL_PERIODIC_ENERGIZE);
                    break;
                case EVENT_DREAD_RIFT:
                    DoCastSelf(SPELL_DREAD_RIFTS);
                    events.ScheduleEvent(EVENT_DREAD_RIFT, 34s);
                    break;
                case EVENT_CHECK_ENERGY:
                {
                    if (me->GetPower(me->GetPowerType()) == 100 && !me->HasUnitState(UNIT_STATE_CASTING))
                    {
                        me->RemoveAurasDueToSpell(SPELL_PERIODIC_ENERGIZE);
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 70.0f, true))
                        {
                            Talk(SAY_HELLBEAM);
                            Talk(SAY_HELLBEAM_ALERT);
                            DoCast(target, SPELL_HELLBEAM);
                            events.ScheduleEvent(EVENT_ENERGIZE, 1s);
                        }
                    }
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, 500ms);
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
    uint8 _hellsteelCarnageCast;
};

// 203832 - Dread Rift
struct npc_dread_rift : public ScriptedAI
{
    npc_dread_rift(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        Creature* kazzara = me->GetInstanceScript()->GetCreature(DATA_KAZZARA_THE_HELLFORGED);
        if (!kazzara)
            return;

        DoCastSelf(SPELL_DREAD_RIFT_AREATRIGGER);
    }
};

// 202167 - Ray of Anguish
struct npc_ray_of_anguish : public ScriptedAI
{
    npc_ray_of_anguish(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        Creature* kazzara = me->GetInstanceScript()->GetCreature(DATA_KAZZARA_THE_HELLFORGED);
        if (!kazzara)
            return;

        DoCastSelf(SPELL_RAY_OF_ANGUISH_AREATRIGGER);
        DoCastSelf(SPELL_MOLTEN_SCAR_AREATRIGGER);
        DoCastSelf(SPELL_RAY_OF_ANGUISH_DECREASE_SPEED);
        _events.ScheduleEvent(EVENT_RAYS_OF_ANGUISH, 100ms, 400ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOLTEN_SCAR:
                    DoCastSelf(SPELL_MOLTEN_SCAR_AREATRIGGER);
                    _events.ScheduleEvent(EVENT_RAYS_OF_ANGUISH, 100ms, 400ms);
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
        GetTarget()->CastSpell(GetTarget()->GetPosition(), SPELL_DREAD_RIFT_SUMMON, true);
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
            SPELL_DREAD_RIFT_SELECTOR,
            SPELL_DREAD_RIFT_AURA
        });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        // @TODO: remove tank unless alive players < x
        targets.remove_if([](WorldObject* target) -> bool
        {
            Player* player = target->ToPlayer();

            if (!player)
                return true;

            if (player->HasAura(SPELL_DREAD_RIFT_SELECTOR))
                return true;

            return false;
        });
    }

    void HandleDreadRift(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DREAD_RIFT_AURA, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void HandleDreadRiftSelector(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DREAD_RIFT_SELECTOR, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kazzara_dread_rift_player_select::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
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

        Unit::AuraApplicationMap const& appliedAuras = GetCaster()->GetAppliedAuras();
        for (auto const& itr : appliedAuras)
        {
            Aura const* aura = itr.second->GetBase();
            if (aura->GetId() == SPELL_INFERNAL_HEART_40_PCT)
            {
                spellId = SPELL_DREAD_RIFTS_6_TARGETS;
                break;
            }
            else if (aura->GetId() == SPELL_INFERNAL_HEART_60_PCT)
            {
                spellId = SPELL_DREAD_RIFTS_5_TARGETS;
                break;
            }
            else if (aura->GetId() == SPELL_INFERNAL_HEART_80_PCT)
            {
                spellId = SPELL_DREAD_RIFTS_4_TARGETS;
                break;
            }
        }

        GetCaster()->CastSpell(GetCaster(), spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
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
    static constexpr std::array<uint8, 30> KazzaraEnergizeCycle = { 0, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 3, 4, 4, 4, 4, 3, 4, 3, 4, 3, 3, 4, 4, 3, 4, 3, 4, 3, 1 };

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_HELLSTEEL_CARNAGE_80_PCT,
            SPELL_HELLSTEEL_CARNAGE_60_PCT,
            SPELL_HELLSTEEL_CARNAGE_40_PCT
        });
    }

    void PeriodicTick(AuraEffect const* aurEff) const
    {
        Spell* currentChanneledSpell = GetTarget()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);

        if (!currentChanneledSpell)
            return;

        if (currentChanneledSpell && (currentChanneledSpell->GetSpellInfo()->Id == SPELL_HELLSTEEL_CARNAGE_80_PCT
            || currentChanneledSpell->GetSpellInfo()->Id == SPELL_HELLSTEEL_CARNAGE_60_PCT
            || currentChanneledSpell->GetSpellInfo()->Id == SPELL_HELLSTEEL_CARNAGE_40_PCT))
            return;

        if (GetTarget())
            GetTarget()->SetPower(POWER_ENERGY, GetTarget()->GetPower(POWER_ENERGY) + KazzaraEnergizeCycle[std::min(aurEff->GetTickNumber(), aurEff->GetTickNumber())]);
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
        if (GetHitUnit())
            GetHitUnit()->SetPower(POWER_ENERGY, GetHitUnit()->GetPower(POWER_ENERGY) - 10);
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
            {
                spellId = SPELL_HELLSTEEL_FRAGMENTS_80_PCT;
                break;
            }
            case SPELL_HELLSTEEL_CARNAGE_TRANSFORM_60_PCT:
            {
                spellId = SPELL_HELLSTEEL_FRAGMENTS_60_PCT;
                break;
            }
            case SPELL_HELLSTEEL_CARNAGE_TRANSFORM_40_PCT:
            {
                spellId = SPELL_HELLSTEEL_FRAGMENTS_40_PCT;
                break;
            }
            default:
                break;
        }

        GetCaster()->CastSpell(GetCaster(), spellId, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_hellsteel_carnage::HandleHit, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

// 402260 - Ray of Anguish
class spell_kazzara_ray_of_anguish_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_RAY_OF_ANGUISH_AURA_45_SECONDS,
            SPELL_RAY_OF_ANGUISH_MISSILE,
            SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS
        });
    }

    void HandleHitAura(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAY_OF_ANGUISH_AURA_10_SECONDS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void HandleHitMissile(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAY_OF_ANGUISH_MISSILE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void HandleHitAura2(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RAY_OF_ANGUISH_AURA_45_SECONDS, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell(),
            .OriginalCastId = GetSpell()->m_castId
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_trigger::HandleHitAura, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_trigger::HandleHitMissile, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_kazzara_ray_of_anguish_trigger::HandleHitAura2, EFFECT_2, SPELL_EFFECT_DUMMY);
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

        caster->CastSpell(target, SPELL_TERROR_CLAWS_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
        caster->CastSpell(target, SPELL_TERROR_CLAWS_SHADOWFLAME_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
        caster->CastSpell(target, SPELL_TERROR_CLAWS_PERIODIC_AURA, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringSpell = GetSpell()
        });
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

    void HandlePeriodic(AuraEffect const* aurEff) const
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_TERROR_CLAWS_PERIODIC_DAMAGE, CastSpellExtraArgsInit{
            .TriggerFlags = TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_DONT_REPORT_CAST_ERROR,
            .TriggeringAura = aurEff
        });
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_kazzara_terror_claws_periodic::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 407046 - Dread Rift
struct at_kazzara_dread_rift : AreaTriggerAI
{
    at_kazzara_dread_rift(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_RIFTBURN, true);
        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -0.5f, MovementForceType::Gravity);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveAura(SPELL_RIFTBURN);
        unit->RemoveMovementForce(at->GetGUID());
    }
};

// 402421 - Molten Scar
struct at_kazzara_molten_scar : AreaTriggerAI
{
    at_kazzara_molten_scar(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_MOLTEN_SCAR_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveAura(SPELL_MOLTEN_SCAR_DAMAGE);
    }
};

// 402219 - Ray of Anguish
struct at_kazzara_ray_of_anguish : AreaTriggerAI
{
    at_kazzara_ray_of_anguish(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->CastSpell(unit, SPELL_RAY_OF_ANGUISH_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveAura(SPELL_RAY_OF_ANGUISH_DAMAGE);
    }
};

// 403326 - Wings of Extinction
struct at_kazzara_wings_of_extinction : AreaTriggerAI
{
    at_kazzara_wings_of_extinction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -20.0f, MovementForceType::Gravity);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        unit->RemoveMovementForce(at->GetGUID());
    }
};

void AddSC_boss_kazzara_the_hellforged()
{
    RegisterAberrusTheShadowedCrucibleCreatureAI(boss_kazzara_the_hellforged);
    RegisterAberrusTheShadowedCrucibleCreatureAI(npc_dread_rift);
    RegisterAberrusTheShadowedCrucibleCreatureAI(npc_ray_of_anguish);

    RegisterSpellScript(spell_kazzara_dread_rift);
    RegisterSpellScript(spell_kazzara_dread_rift_player_select);
    RegisterSpellScript(spell_kazzara_dread_rifts);
    RegisterSpellScript(spell_kazzara_energize);
    RegisterSpellScript(spell_kazzara_hellbeam_consume_energy);
    RegisterSpellScript(spell_kazzara_hellsteel_carnage);
    RegisterSpellScript(spell_kazzara_ray_of_anguish_trigger);
    RegisterSpellScript(spell_kazzara_terror_claws);
    RegisterSpellScript(spell_kazzara_terror_claws_periodic);

    RegisterAreaTriggerAI(at_kazzara_dread_rift);
    RegisterAreaTriggerAI(at_kazzara_molten_scar);
    RegisterAreaTriggerAI(at_kazzara_ray_of_anguish);
    RegisterAreaTriggerAI(at_kazzara_wings_of_extinction);
}
