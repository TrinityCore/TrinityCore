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
#include "ScriptMgr.h"
#include "seat_of_triumvirate.h"

enum Spells
{
    SPELL_VOID_CONTAINMENT = 246922,
    SPELL_VOID_PHASED = 246913,

    SPELL_NULL_PALM = 246134,
    SPELL_NULL_PALM_MISSILE = 246135,
    SPELL_NULL_PALM_DAMAGE = 246136,

    SPELL_DECIMATE = 244579,

    SPELL_COALESCED_VOID = 244602,
    SPELL_DARK_EXPULSION = 244599,
    SPELL_UMBRAL_EJECTION = 244731,
    SPELL_VOID_SLUDGE = 244588,
    SPELL_VOID_INFUSION = 244300,

    SPELL_UMBRA_SHIFT = 244433,
    SPELL_FIXATE = 244657,
    SPELL_MADDENED_FRENZY = 247038,

    SPELL_RELEASE_VOID_ENERGY = 244618,
    SPELL_VOID_TEAR = 244621,

    SPELL_PHYSICAL_REALM_COSMETIC = 244087,
};

enum Npcs
{
    NPC_COALESCED_VOID = 122716,
    NPC_DARK_ABERRATION = 122482
};

// 122313
struct boss_zuraal_the_ascended : public BossAI
{
    boss_zuraal_the_ascended(Creature* creature) : BossAI(creature, DATA_ZURAAL_THE_ASCENDED) { }

    void ScheduleTasks() override
    {
        me->RemoveAurasDueToSpell(SPELL_VOID_PHASED);
        me->RemoveAurasDueToSpell(SPELL_PHYSICAL_REALM_COSMETIC);
        me->setActive(true);
        DoZoneInCombat();
        events.ScheduleEvent(SPELL_NULL_PALM, 10s);
        events.ScheduleEvent(SPELL_DECIMATE, 10s);
        events.ScheduleEvent(SPELL_UMBRA_SHIFT, 10s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        if (HealthBelowPct(45))
        {
            DoCastSelf(SPELL_MADDENED_FRENZY, true);
        }

        switch (eventId)
        {
        case SPELL_NULL_PALM:
        {
            me->CastSpell(nullptr, SPELL_NULL_PALM, false);
            events.Repeat(10s);
            break;
        }
        case SPELL_DECIMATE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                me->CastSpell(target, SPELL_DECIMATE, false);

            events.Repeat(10s);
            break;
        }
        case SPELL_UMBRA_SHIFT:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                me->CastSpell(target, SPELL_UMBRA_SHIFT, false);

            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.f, true, -SPELL_UMBRA_SHIFT))
                me->CastSpell(target, SPELL_FIXATE, false);

            break;
        }
        }
    }
};

// 124171
class npc_shadowguard_subjugator : public ScriptedAI
{
public:
    npc_shadowguard_subjugator(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->CastSpell(me, SPELL_VOID_CONTAINMENT, false);
    }
};

// 122716
class npc_coalesced_void : public ScriptedAI
{
public:
    npc_coalesced_void(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        if (IsMythic())
            me->CastSpell(me, SPELL_UMBRAL_EJECTION, false);

        me->GetScheduler().Schedule(1s, [](TaskContext context)
        {
            if (TempSummon* tempSummon = GetContextCreature()->ToTempSummon())
            {
                if (tempSummon->IsWithinDist(tempSummon->GetSummoner(), 3.f))
                {
                    tempSummon->CastSpell(nullptr, SPELL_DARK_EXPULSION, false);
                    tempSummon->DespawnOrUnsummon();
                }
                else
                    context.Repeat(1s);
            }
        });
    }
};

// 246134
class spell_null_palm : public SpellScript
{
    PrepareSpellScript(spell_null_palm);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target->GetPosition(), SPELL_NULL_PALM_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_null_palm::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

// 246913
class aura_void_phased : public AuraScript
{
    PrepareAuraScript(aura_void_phased);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->SetHover(true);
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (!GetTarget()->HasAura(SPELL_VOID_CONTAINMENT))
            Remove();
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetHover(false);
        target->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(aura_void_phased::OnApply, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_void_phased::OnPeriodic, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY);
        OnEffectRemove += AuraEffectRemoveFn(aura_void_phased::OnRemove, EFFECT_0, SPELL_AURA_DAMAGE_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Spell 244732
// at : 15477
struct at_umbral_ejection : AreaTriggerAI
{
    at_umbral_ejection(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        at->SetPeriodicProcTimer(2000);
    }

    void OnPeriodicProc() override
    {
        if (Unit* caster = at->GetCaster())
        {
            for (ObjectGuid guid : at->GetInsideUnits())
            {
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                {
                    if (caster->IsValidAttackTarget(unit))
                    {
                        unit->CastSpell(unit, SPELL_VOID_SLUDGE, true);
                    }
                    else if (unit == caster)
                    {
                        unit->CastSpell(unit, SPELL_VOID_INFUSION, true);
                    }
                }
            }
        }
    }
};

void AddSC_boss_zuraal_the_ascended()
{
    RegisterCreatureAI(boss_zuraal_the_ascended);
    RegisterCreatureAI(npc_shadowguard_subjugator);
    RegisterCreatureAI(npc_coalesced_void);

    RegisterSpellScript(spell_null_palm);
    RegisterAuraScript(aura_void_phased);

    RegisterAreaTriggerAI(at_umbral_ejection);
}
