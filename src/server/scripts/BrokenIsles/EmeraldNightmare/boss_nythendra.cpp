/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "emerald_nightmare.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Spells
{
    // Stage One
    SPELL_INFESTED                  = 204504,
    SPELL_INFESTED_TARGET           = 220189,
    SPELL_INFESTED_DAMAGE           = 204506,
    SPELL_INFESTED_MIND             = 205043,
    SPELL_SPREAD_INFESTATION        = 205070,
    SPELL_INFESTED_GROUND           = 203044,
    SPELL_INFESTED_GROUND_DAMAGE    = 203045,
    SPELL_INFESTED_BREATH           = 202977,
    SPELL_INFESTED_BREATH_DAMAGE    = 202978,
    SPELL_ROT                       = 203096,
    SPELL_VOLATILE_ROT              = 204463,
    SPELL_TAIL_LASH                 = 203024,

    // Stage Two
    SPELL_HEART_OF_THE_SWARM        = 203552,
    SPELL_BURST_OF_CORRUPTION       = 203646,

    SPELL_ENRAGE                    = 47008
};

class EntryCheckWithPlayerNearPredicate
{
public:
    EntryCheckWithPlayerNearPredicate(Unit* owner, uint32 entry, float distance) : _owner(owner), _entry(entry), _distance(distance) { }
    bool operator()(ObjectGuid const& guid) const
    {
        if (guid.GetEntry() != _entry)
            return false;

        Creature* summon = ObjectAccessor::GetCreature(*_owner, guid);
        return summon && summon->SelectNearestPlayer(_distance);
    }

private:
    Unit* _owner;
    uint32 _entry;
    uint32 _distance;
};

struct boss_nythendra : public BossAI
{
    boss_nythendra(Creature* creature) : BossAI(creature, DATA_NYTHENDRA) { }

    enum EventGroups
    {
        EVENTS_PHASE_1 = 1,
        EVENTS_PHASE_2 = 2,
    };

    void Reset() override
    {
        _Reset();

        RemoveAllAreaTriggers();

        me->SetPowerType(POWER_ENERGY);
        me->SetPower(POWER_ENERGY, 100);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFESTED);
        instance->DoKillPlayersWithAura(SPELL_INFESTED_MIND);
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_ROT,             10s,    EVENTS_PHASE_1);
        events.ScheduleEvent(SPELL_VOLATILE_ROT,    30s,    EVENTS_PHASE_1);
        events.ScheduleEvent(SPELL_INFESTED_BREATH, 60s,    EVENTS_PHASE_1);
        events.ScheduleEvent(SPELL_TAIL_LASH,       20s,    EVENTS_PHASE_1);

        if (IsHeroic())
        {
            me->GetScheduler().Schedule(8min, [this](TaskContext /*context*/)
            {
                me->CastSpell(me, SPELL_ENRAGE, true);
            });
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();

        me->RemoveAllAreaTriggers();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFESTED);
    }

    void DamageDealt(Unit* victim, uint32& /*damage*/, DamageEffectType damageType, SpellInfo const* spellInfo) override
    {
        if (spellInfo && spellInfo->Id != SPELL_INFESTED_DAMAGE && damageType != DIRECT_DAMAGE && IsHeroic())
        {
            me->AddAura(SPELL_INFESTED_TARGET, victim);
            me->CastSpell(victim, SPELL_INFESTED, true);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId != SPELL_BURST_OF_CORRUPTION && me->HasUnitState(UNIT_STATE_CASTING))
                return;

            ExecuteEvent(eventId);
        }

        if (!me->HasUnitState(UNIT_STATE_CASTING))
            DoMeleeAttackIfReady();
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_ROT:
            {
                for (uint8 i = 0; i < 2; ++i)
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                        me->CastSpell(target, SPELL_ROT, true);

                events.Repeat(10s);
                break;
            }
            case SPELL_VOLATILE_ROT:
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    me->CastSpell(target, SPELL_VOLATILE_ROT, true);

                events.Repeat(25s);
                break;
            }
            case SPELL_INFESTED_BREATH:
            {
                me->CastSpell(nullptr, SPELL_INFESTED_BREATH, false);
                events.Repeat(60s);

                me->ModifyPower(POWER_ENERGY, -50);

                // If no more energy, start phase 2
                if (me->GetPower(POWER_ENERGY) <= 0)
                    SwitchPhase2();

                break;
            }
            case SPELL_TAIL_LASH:
            {
                DoCast(SPELL_TAIL_LASH);
                events.Repeat(20s);
                break;
            }
            case SPELL_BURST_OF_CORRUPTION:
            {
                EntryCheckWithPlayerNearPredicate pred(me, NPC_CORRUPTED_VERMIN, 3.f);
                summons.DoAction(0, pred, 1);
                events.Repeat(2s);
                break;
            }
            default:
                break;
        }
    }

private:
    void SwitchPhase2()
    {
        events.DelayEvents(31s);

        me->GetScheduler()
            .Schedule(10s, [this](TaskContext /*context*/)
            {
                me->CastSpell(me, SPELL_HEART_OF_THE_SWARM, false);
                me->SummonCreatureGroup(0);
                events.ScheduleEvent(SPELL_BURST_OF_CORRUPTION, 2s);
            })
            .Schedule(14s, [this](TaskContext /*context*/)
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFESTED);

                std::list<AreaTrigger*> ats;
                me->GetAreaTriggerListWithSpellIDInRange(ats, SPELL_INFESTED_GROUND, 500.f);
                for (AreaTrigger* at : ats)
                    at->SetDestination(me->GetPosition(), 5000);
            })
            .Schedule(31s, [this](TaskContext /*context*/)
            {
                summons.DespawnEntry(NPC_CORRUPTED_VERMIN);
                events.CancelEvent(SPELL_BURST_OF_CORRUPTION);
            });
    }

    // Some AT are spawned by players, force remove them
    void RemoveAllAreaTriggers()
    {
        me->RemoveAllAreaTriggers();

        std::list<AreaTrigger*> ats;
        me->GetAreaTriggerListWithSpellIDInRange(ats, SPELL_INFESTED_GROUND, 500.f);
        for (AreaTrigger* at : ats)
            at->SetDuration(0);
    }
};

// 102998
struct npc_nythendra_corrupted_vermin : public ScriptedAI
{
    npc_nythendra_corrupted_vermin(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        me->SetObjectScale(0.2f);
    }

    void DoAction(int32 /*action*/) override
    {
        me->SetObjectScale(1.f);
        me->GetScheduler().Schedule(2s, [](TaskContext context)
        {
            GetContextUnit()->CastSpell(GetContextUnit(), SPELL_BURST_OF_CORRUPTION, false);

            if (context.GetRepeatCounter() < 3)
                context.Repeat(2s);
        });
    }
};

//204504
class aura_nythendra_infested : public AuraScript
{
    PrepareAuraScript(aura_nythendra_infested);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();

        if (!caster)
            return;

        // Periodic is 250ms, we want to damage only every 2s
        if (aurEff->GetTickNumber() % 8 == 0)
            caster->CastCustomSpell(SPELL_INFESTED_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, TRIGGERED_FULL_MASK);

        if (caster->GetMap() && caster->GetMap()->IsMythic())
        {
            if (GetAura()->GetStackAmount() >= 10)
            {
                if (!target->HasAura(SPELL_INFESTED_MIND))
                {
                    caster->AddAura(SPELL_INFESTED_TARGET, target);
                    caster->CastSpell(target, SPELL_INFESTED_MIND, true);
                }
            }
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_INFESTED_TARGET);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_nythendra_infested ::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(aura_nythendra_infested::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//205043
class aura_nythendra_infested_mind : public AuraScript
{
    PrepareAuraScript(aura_nythendra_infested_mind);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        GetTarget()->CastSpell(nullptr, SPELL_SPREAD_INFESTATION, false);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_nythendra_infested_mind::OnPeriodic, EFFECT_8, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//202977
class aura_nythendra_infested_breath : public AuraScript
{
    PrepareAuraScript(aura_nythendra_infested_breath);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        // Deal damage every 2 ticks
        if (aurEff->GetTickNumber() % 2 == 0)
            if (Unit* caster = GetCaster())
                caster->CastSpell(nullptr, SPELL_INFESTED_BREATH_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_nythendra_infested_breath::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

//203096
class aura_nythendra_rot : public AuraScript
{
    PrepareAuraScript(aura_nythendra_rot);

    void AfterRemove(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_INFESTED_GROUND, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(aura_nythendra_rot::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

//204463
class aura_nythendra_volatile_rot : public AuraScript
{
    PrepareAuraScript(aura_nythendra_volatile_rot);

    void AfterRemove(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
        {
            for (uint8 i = 0; i < 3; ++i)
            {
                Position castPos;
                GetRandPosFromCenterInDist(GetTarget(), 10.0f, castPos);
                caster->CastSpell(castPos, SPELL_INFESTED_GROUND, true);
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(aura_nythendra_volatile_rot::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

//204470
class spell_nythendra_volatile_rot_damage : public SpellScript
{
    PrepareSpellScript(spell_nythendra_volatile_rot_damage);

    void CalcDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetExplTargetUnit();

        if (!target)
            return;

        float castertoTargetDist = GetCaster()->GetDistance2d(target);

        int32 damage = GetHitDamage();
        SetHitDamage(damage * (1 / castertoTargetDist));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_nythendra_volatile_rot_damage::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//Spell : 203044
//AT : 10594
struct at_nythendra_infested_ground : AreaTriggerAI
{
    at_nythendra_infested_ground(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
            if (InstanceScript* instance = caster->GetInstanceScript())
                if (Creature* nythendra = instance->GetCreature(NPC_NYTHENDRA))
                    if (nythendra->IsValidAttackTarget(unit))
                        nythendra->CastSpell(unit, SPELL_INFESTED_GROUND_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_INFESTED_GROUND_DAMAGE);
    }

    void OnDestinationReached() override
    {
        at->Remove();
    }
};

void AddSC_nythendra()
{
    RegisterCreatureAI(boss_nythendra);
    RegisterCreatureAI(npc_nythendra_corrupted_vermin);

    RegisterAuraScript(aura_nythendra_infested);
    RegisterAuraScript(aura_nythendra_infested_mind);
    RegisterAuraScript(aura_nythendra_infested_breath);
    RegisterAuraScript(aura_nythendra_rot);
    RegisterAuraScript(aura_nythendra_volatile_rot);
    RegisterSpellScript(spell_nythendra_volatile_rot_damage);

    RegisterAreaTriggerAI(at_nythendra_infested_ground);
}
