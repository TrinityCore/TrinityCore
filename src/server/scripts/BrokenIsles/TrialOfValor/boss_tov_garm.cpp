/*
 * Copyright 2023 AzgathCore
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

#include "trial_of_valor.h"
#include "AreaTriggerAI.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"

namespace
{
    enum Says
    {
        SAY_RAID_CAST = 5,
        SAY_BERSERK
    };

    enum Spells
    {
        SpellBerserkCharge = 232173,
        SpellBrineyVolatileFoam = 228810,
        SpellBrineyVolatileFoam2 = 228811,
        SpellFlamingVolatileFoam = 228744,
        SpellFlamingVolatileFoam2 = 228794,
        SpellFlashingFangs = 227514,
        SpellGuardiansBreath = 228187,
        SpellHeadlongCharge = 227816,
        SpellHeadlongChargeAT = 227833,
        SpellHelyatosis = 231561,
        SpellOffTheLeash = 228201,
        SpellRoaringLeap = 227883,
        SpellRoaringLeapJump = 229350,
        SpellShadowyVolatileFoam = 228818,
        SpellShadowyVolatileFoam2 = 228819,
        SpellVolatileFoam = 228824,
        SpellMultyHeaded = 227642,
        SpellMultyHeadedTooltip = 227512,
        SpellHelyatosis_AddPower = 235130,
        SpellGuardiansBreath_1 = 227666,
        SpellGuardiansBreath_2 = 227669,
        SpellGuardiansBreath_3 = 227673,
        SpellClearAllDebuffs = 34098,
        SpellFlameLick = 228226,
        SpellFrostLick = 228246,
        SpellShadowLick = 228250,
        SpellFieryPhlegm = 228758,
        SpellDarkDischarge = 228769,
        SpellSaltySpittle = 228768,
        SpellBerserk = 64238,
        SpellShadowLickAura = 228253,
        SpellHeadlongChargeDmg = 229480,
        SpellFrothingRage = 228174,
        SpellFieryPhlegmAOE = 227539,
        SpellDarkDischargeAOE = 227570,
        SpellSaltySpittleAOE = 227566
    };

    enum Events
    {
        EVENT_OFF_THE_LEASH = 1,
        EVENT_HEADLONG_CHARGE = 2,
        EVENT_HEADLONG_CHARGE_WP = 3,
        EVENT_ROARING_LEAP = 4,
        EVENT_ROARING_LEAP_JUMP = 5,

        EVENT_FLAME_LICK = 6,
        EVENT_FROST_LICK = 7,
        EVENT_SHADOW_LICK = 8,

        EVENT_POINT_2 = 9,
        EVENT_POINT_3 = 10,
        EVENT_POINT_COMPLETE = 11,

        //MYTHIC
        EVENT_FLAMING_VOLATILE_FOAM = 12,
        EVENT_BRINEY_VOLATILE_FOAM = 13,
        EVENT_SHADOWY_VOLATILE_FOAM = 14
    };

    enum Phase
    {
        PHASE_1 = 1,
        PHASE_2
    };
}

enum Misc
{
    ACTION_1 = 1,
    ACTION_2,
    ACTION_3,
};

uint32 RandSpellGuardiansBreath[3] =
{
    SpellGuardiansBreath_1,
    SpellGuardiansBreath_2,
    SpellGuardiansBreath_3
};

Position const WPphaseTwo[3] =
{
    { 451.0492f,    545.6583f, 3.07493f, 0.0f },
    { 476.35119f,   551.8374f, 2.42583f, 0.0f },
    { 482.3681f,    450.1896f, 5.06133f, 0.0f }
};

struct boss_garm : BossAI
{
    explicit boss_garm(Creature* creature) : BossAI(creature, Data::BossIDs::GarmID) {}

    uint32 passengerData[3][2] =
    {
        { Data::Creatures::GuarmPassenger1, 0 },
        { Data::Creatures::GuarmPassenger2, 1 },
        { Data::Creatures::GuarmPassenger3, 2 }
    };

    uint32 berserk;
    uint8 eventPhase;
    uint32 countTarget;
    bool berserkcharge = {};
    bool frothingRage = {};

    void Reset() override
    {
        _Reset();
        berserkcharge = false;
        frothingRage = false;
        berserk = 0;
        eventPhase = 0;
        countTarget = 0;
        DespawnAllSummons();
        RemoveDebaffsOnPlayer();

        me->SetUnitFlags(UNIT_FLAG_UNK_6);
        me->SetUnitFlags(UNIT_FLAG_UNK_15);
        me->SetUnitFlags2(UNIT_FLAG2_UNK5);
        me->SetPower(POWER_ENERGY, 0);
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetControlled(0, UNIT_STATE_ROOT);
        me->RemoveAllAuras();
        for (auto x = 0; x < std::extent<decltype(passengerData)>::value; x++)
        {
            if (auto passenger = me->SummonCreature(passengerData[x][0], me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()))
            {
                passenger->EnterVehicle(me, passengerData[x][1]);
                passenger->SetReactState(REACT_PASSIVE);
            }
            else
                BossAI::EnterEvadeMode();
        }

        DoCast(SpellMultyHeadedTooltip);
    }

    void RemoveDebaffsOnPlayer()
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFlameLick);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFrostLick);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellShadowLick);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFieryPhlegm);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellDarkDischarge);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellSaltySpittle);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellShadowLickAura);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellShadowyVolatileFoam);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellBrineyVolatileFoam);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFlamingVolatileFoam);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellShadowyVolatileFoam2);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellBrineyVolatileFoam2);
        instance->DoRemoveAurasDueToSpellOnPlayers(SpellFlamingVolatileFoam2);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, Data::Creatures::GuarmPassenger1, 50.0f);
        me->GetCreatureListWithEntryInGrid(list, Data::Creatures::GuarmPassenger2, 50.0f);
        me->GetCreatureListWithEntryInGrid(list, Data::Creatures::GuarmPassenger3, 50.0f);
        if (!list.empty())
            for (auto& sum : list)
                sum->DespawnOrUnsummon();
    }

    void EnterEvadeMode(EvadeReason w) 
    {
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _JustEngagedWith();
        StartEvents(PHASE_1);
        DoCast(SpellHelyatosis_AddPower);

        if (IsHeroicRaid() || IsNormalRaid())
            berserk = 300000;
        else if (IsMythicRaid())
            berserk = 240000;
        else if (IsLFR())
            berserk = 420000;
    }

    void SetPower(Powers power, int32 value)
    {
        if (power != POWER_ENERGY || !me->IsInCombat())
            return;

        if (value == 0)
        {
            if (!me->HasAura(SpellHelyatosis))
                DoCast(SpellHelyatosis);
        }

        if (value == 100)
        {
            frothingRage = false;
            countTarget = 0;
            ZoneTalk(SAY_RAID_CAST, nullptr);
            me->RemoveAura(SpellHelyatosis);
            me->SetPower(POWER_ENERGY, 0);
            DoCast(RandSpellGuardiansBreath[urand(0, 2)]);
            me->SetFacingToObject(me->GetVictim());
        }

        if (value == 53 || value == 70)
            DoCast(SpellFlashingFangs);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_COMPLETE_DUNGEON_ENCOUNTER, 1962);
        RemoveDebaffsOnPlayer();
    }

    void DoAction(int32 const action) override
    {
        switch (action)
        {
        case ACTION_1:
            DoCast(SpellMultyHeaded);
            break;
        case ACTION_2:
        {
            frothingRage = true;
            countTarget++;
            if (countTarget == 0)
                return;

            uint32 targets = 0;
            uint32 StackAuras = 0;
            uint32 diffRaid = IsMythicRaid() ? 20 : 30;
            auto threatlist = me->GetThreatManager().GetUnsortedThreatList();
            {
            /*if (!threatlist.empty())  ( not used ? )
            {
                targets = threatlist.size();*/
                StackAuras = (targets - countTarget);

                if (StackAuras >= 1 && StackAuras <= diffRaid)
                {
                    if (StackAuras > targets)
                        return;

                    if (Aura* aura = me->AddAura(SpellFrothingRage, me))
                        aura->SetStackAmount(StackAuras);
                }
                else if (targets == 1 && countTarget < 1)
                    me->AddAura(SpellFrothingRage, me);
                else if (StackAuras < 0)
                    me->AddAura(SpellFrothingRage, me);
            }
            break;
        }
       case ACTION_3:
        {
            if (!frothingRage)    
            {
                uint32 targets = 0;

                auto threatlist = me->GetThreatManager().GetThreat(me);
                //if (!threatlist.empty())
                {
                  //  targets = threatlist.size();
                    me->AddAura(SpellFrothingRage, me);
                }
            }
            break;
        }
        default:
            break;
        }
    }

    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SpellHeadlongCharge:
            me->GetMotionMaster()->MoveCharge(456.3476f, 449.91302f, 4.778366f, 30.0f);
            events.RescheduleEvent(EVENT_HEADLONG_CHARGE_WP, 2000);
            break;
        case SpellGuardiansBreath_1:
        case SpellGuardiansBreath_2:
        case SpellGuardiansBreath_3:
            DoCast(me, SpellFieryPhlegmAOE, true);
            DoCast(me, SpellDarkDischargeAOE, true);
            DoCast(me, SpellSaltySpittleAOE, true);
            break;
        }
    }

    void StartEvents(uint8 phase)
    {
        events.Reset();
        eventPhase = phase;

        switch (phase)
        {
        case PHASE_1:
            DoCast(SpellHelyatosis);
            events.RescheduleEvent(EVENT_OFF_THE_LEASH, 30000);
            events.RescheduleEvent(EVENT_FLAME_LICK, 12000);
            events.RescheduleEvent(EVENT_FROST_LICK, 24000);
            events.RescheduleEvent(EVENT_SHADOW_LICK, 27000);

            if (IsMythicRaid())
            {
                events.RescheduleEvent(EVENT_FLAMING_VOLATILE_FOAM, 10000);
                events.RescheduleEvent(EVENT_BRINEY_VOLATILE_FOAM, 10000);
                events.RescheduleEvent(EVENT_SHADOWY_VOLATILE_FOAM, 10000);
            }
            break;
        case PHASE_2:
            me->RemoveAura(SpellHelyatosis);
            me->AttackStop();

            DoCast(SpellClearAllDebuffs);
            DoCast(SpellOffTheLeash);

            events.RescheduleEvent(EVENT_ROARING_LEAP, 2000);
            events.RescheduleEvent(EVENT_HEADLONG_CHARGE, 7000);
            break;
        }
    }

    void MovementInform(uint32 type, uint32 data) override
    {
        if (type == POINT_MOTION_TYPE)
        {
            switch (data)
            {
            case 1:
                events.RescheduleEvent(EVENT_POINT_2, 100);
                break;
            case 2:
                events.RescheduleEvent(EVENT_POINT_3, 100);
                break;
            case 3:
                events.RescheduleEvent(EVENT_POINT_COMPLETE, 100);
                break;
            }
        }
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == Data::BossIDs::GarmID)
            return eventPhase;
        return 0;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_OFF_THE_LEASH:
                StartEvents(PHASE_2);
                break;
            case EVENT_HEADLONG_CHARGE:
                me->SetControlled(1, UNIT_STATE_ROOT);
                DoCast(SpellHeadlongCharge);
                break;
            case EVENT_HEADLONG_CHARGE_WP:
                if (!berserkcharge)
                    DoCast(SpellHeadlongChargeAT);
                else
                    DoCast(SpellBerserkCharge);

                DoCast(SpellHeadlongChargeDmg);

                me->SetControlled(0, UNIT_STATE_ROOT);
                me->AttackStop();
                me->GetMotionMaster()->MovePoint(1, WPphaseTwo[0]);
                break;
            case EVENT_ROARING_LEAP:
                me->SetControlled(1, UNIT_STATE_ROOT);
                DoCast(SpellRoaringLeap);
                events.RescheduleEvent(EVENT_ROARING_LEAP_JUMP, 2000);
                break;
            case EVENT_ROARING_LEAP_JUMP:
                me->SetControlled(0, UNIT_STATE_ROOT);

                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 15.0f, true))
                    DoCast(target, SpellRoaringLeapJump);
                break;
            case EVENT_FLAME_LICK:
                if (eventPhase != PHASE_2)
                {
                    DoCast(SpellFlameLick);
                    events.RescheduleEvent(EVENT_FLAME_LICK, 13000);
                }
                break;
            case EVENT_FROST_LICK:
                if (eventPhase != PHASE_2)
                {
                    DoCast(SpellFrostLick);
                    events.RescheduleEvent(EVENT_FROST_LICK, 24000);
                }
                break;
            case EVENT_SHADOW_LICK:
                if (eventPhase == PHASE_2)
                    return;

                DoCast(SpellShadowLick);
                events.RescheduleEvent(EVENT_SHADOW_LICK, 27000);
                break;
            case EVENT_POINT_2:
                me->AttackStop();
                me->GetMotionMaster()->MovePoint(2, WPphaseTwo[1]);
                break;
            case EVENT_POINT_3:
                me->AttackStop();
                me->GetMotionMaster()->MovePoint(3, WPphaseTwo[2]);
                break;
            case EVENT_POINT_COMPLETE:
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetControlled(0, UNIT_STATE_ROOT);
                me->RemoveAura(SpellHeadlongChargeAT);
                me->RemoveAura(SpellOffTheLeash);
                StartEvents(PHASE_1);
                break;
            case EVENT_FLAMING_VOLATILE_FOAM:
                if (eventPhase != PHASE_2)
                {
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        if (!target->HasAura(SpellFlamingVolatileFoam) && !target->HasAura(SpellBrineyVolatileFoam) && !target->HasAura(SpellShadowyVolatileFoam))
                            me->AddAura(SpellFlamingVolatileFoam, target);

                    events.RescheduleEvent(EVENT_FLAMING_VOLATILE_FOAM, 30000);
                }
                break;
            case EVENT_BRINEY_VOLATILE_FOAM:
                if (eventPhase != PHASE_2)
                {
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        if (!target->HasAura(SpellFlamingVolatileFoam) && !target->HasAura(SpellBrineyVolatileFoam) && !target->HasAura(SpellShadowyVolatileFoam))
                            me->AddAura(SpellBrineyVolatileFoam, target);

                    events.RescheduleEvent(EVENT_BRINEY_VOLATILE_FOAM, 30000);
                }
                break;
            case EVENT_SHADOWY_VOLATILE_FOAM:
                if (eventPhase != PHASE_2)
                {
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        if (!target->HasAura(SpellFlamingVolatileFoam) && !target->HasAura(SpellBrineyVolatileFoam) && !target->HasAura(SpellShadowyVolatileFoam))
                            me->AddAura(SpellShadowyVolatileFoam, target);

                    events.RescheduleEvent(EVENT_SHADOWY_VOLATILE_FOAM, 30000);
                }
                break;
            }
        }

        if (berserk)
        {
            if (berserk <= diff)
            {
                berserk = 0;
                DoCast(me, SpellBerserk, true);
                Talk(SAY_BERSERK);
                berserkcharge = true;
            }
            else
                berserk -= diff;
        }
        DoMeleeAttackIfReady();
    }
};

//227512
class spell_multi_headed_aura : public AuraScript
{
    PrepareAuraScript(spell_multi_headed_aura);

    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (auto Guarm = instance->instance->GetCreature(instance->GetGuidData(Data::Creatures::Guarm)))
            Guarm->GetAI()->DoAction(ACTION_1);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_multi_headed_aura::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

//227642
class spell_multi_headed : public SpellScript
{
    PrepareSpellScript(spell_multi_headed);

    uint8 targetsCount = 0;
    ObjectGuid m_target;

    bool Load() override
    {
        m_target.Clear();
        return true;
    }

    void HandleBeforeCast()
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (auto target = caster->GetVictim())
            m_target = target->GetGUID();
    }

    void CorrectTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        targets.remove_if([caster](WorldObject* object) -> bool
        {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if (!unit->isInFront(caster, 3.14f / 2))
                return true;

            return false;
        });

        targetsCount = targets.size();

        if (targets.size() > 1)
        {
            targets.remove_if([this](WorldObject* object) -> bool
            {
                return !object || object->GetGUID() == m_target;
            });

            if (targets.size() > 1)
            {
                targets.sort(Trinity::ObjectDistanceOrderPred(caster));
                WorldObject* object = targets.front();
                targets.clear();
                targets.push_back(object);
            }
        }
        else
        {
            targets.clear();

            if (Unit* target = ObjectAccessor::GetUnit(*caster, m_target))
                targets.push_back(target);
        }
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount < 2)
            SetHitDamage(GetHitDamage() * 2);
    }

    void Register() override
    {
        BeforeCast += SpellCastFn(spell_multi_headed::HandleBeforeCast);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_multi_headed::CorrectTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_multi_headed::HandleDamage, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
    }
};

class spell_mixed_elements : public SpellScript
{
    PrepareSpellScript(spell_mixed_elements);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object)
        {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if ((unit->HasAura(SpellFieryPhlegm) && unit->HasAura(SpellDarkDischarge)) || (unit->HasAura(SpellFieryPhlegm) && unit->HasAura(SpellSaltySpittle)) || (unit->HasAura(SpellSaltySpittle) && unit->HasAura(SpellDarkDischarge)))
                return false;
            else
                return true;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_mixed_elements::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//228794
class spell_flaming_volatile_foam : public SpellScript
{
    PrepareSpellScript(spell_flaming_volatile_foam);

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->AddAura(SpellFlamingVolatileFoam2, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_flaming_volatile_foam::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//228811
class spell_briney_volatile_foam : public SpellScript
{
    PrepareSpellScript(spell_briney_volatile_foam);

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->AddAura(SpellBrineyVolatileFoam2, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_briney_volatile_foam::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//228819
class spell_shadowy_volatile_foam : public SpellScript
{
    PrepareSpellScript(spell_shadowy_volatile_foam);

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->AddAura(SpellShadowyVolatileFoam2, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_shadowy_volatile_foam::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//228744
class spell_flaming_volatile_foam_dispell : public AuraScript
{
    PrepareAuraScript(spell_flaming_volatile_foam_dispell);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            target->CastSpell(target, SpellFlamingVolatileFoam2, true);
        else
            target->AddAura(SpellFieryPhlegm, target);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_flaming_volatile_foam_dispell::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//228810
class spell_briney_volatile_foam_dispell : public AuraScript
{
    PrepareAuraScript(spell_briney_volatile_foam_dispell);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            target->CastSpell(target, SpellBrineyVolatileFoam2, true);
        else
            target->AddAura(SpellSaltySpittle, target);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_briney_volatile_foam_dispell::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//228818
class spell_shadowy_volatile_foam_dispell : public AuraScript
{
    PrepareAuraScript(spell_shadowy_volatile_foam_dispell);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
            target->CastSpell(target, SpellShadowyVolatileFoam2, true);
        else
            target->AddAura(SpellDarkDischarge, target);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_shadowy_volatile_foam_dispell::OnRemove, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
    }
};

//227566
class spell_salty_spittle : public SpellScript
{
    PrepareSpellScript(spell_salty_spittle);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object)
        {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if (unit->HasAura(SpellSaltySpittle))
                return false;
            else
                return true;
        });

        targetsCount = targets.size();
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_salty_spittle::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_salty_spittle::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_24);
        OnEffectHitTarget += SpellEffectFn(spell_salty_spittle::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//227570
class spell_dark_discharge : public SpellScript
{
    PrepareSpellScript(spell_dark_discharge);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object)
        {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if (unit->HasAura(SpellDarkDischarge))
                return false;
            else
                return true;
        });

        targetsCount = targets.size();
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dark_discharge::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dark_discharge::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_24);
        OnEffectHitTarget += SpellEffectFn(spell_dark_discharge::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//227539
class spell_fiery_phlegm : public SpellScript
{
    PrepareSpellScript(spell_fiery_phlegm);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object)
        {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if (unit->HasAura(SpellFieryPhlegm))
                return false;
            else
                return true;
        });

        targetsCount = targets.size();
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fiery_phlegm::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fiery_phlegm::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_24);
        OnEffectHitTarget += SpellEffectFn(spell_fiery_phlegm::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

struct at_guardians_breath : AreaTriggerAI
{
    explicit at_guardians_breath(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    uint32 targetCounts{};

    void OnCreate() override
    {
        targetCounts = 0;
    }

    void OnRemove() override
    {
        auto caster = at->GetCaster()->ToCreature();
        if (!caster)
            return;

        if (targetCounts == 0)
            caster->GetAI()->DoAction(ACTION_3);
    }

    void BeforeRemove(Unit* target)
    {
        Unit* caster = at->GetCaster()->ToCreature();
        if (!caster || !target)
            return;

        if (target->IsPlayer())
        {
            targetCounts++;

            if (targetCounts >= 1)
                for (uint8 i = 0; i < targetCounts; ++i)
                    caster->GetAI()->DoAction(ACTION_2);
        }
    }
};

void AddSC_boss_garm()
{
    RegisterCreatureAI(boss_garm);
    RegisterAuraScript(spell_multi_headed_aura);
    RegisterSpellScript(spell_multi_headed);
    RegisterSpellScript(spell_flaming_volatile_foam);
    RegisterSpellScript(spell_briney_volatile_foam);
    RegisterSpellScript(spell_shadowy_volatile_foam);
    RegisterSpellScript(spell_mixed_elements);
    RegisterSpellScript(spell_salty_spittle);
    RegisterSpellScript(spell_dark_discharge);
    RegisterSpellScript(spell_fiery_phlegm);
    RegisterAuraScript(spell_flaming_volatile_foam_dispell);
    RegisterAuraScript(spell_briney_volatile_foam_dispell);
    RegisterAuraScript(spell_shadowy_volatile_foam_dispell);
    RegisterAreaTriggerAI(at_guardians_breath);
}
