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

#include "ScriptMgr.h"
#include "tol_dagor.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells {
    SPELL_SANDSTORM = 257495,

    SPELL_UPHEAVAL_TARGET_SELECTOR = 257612,
    SPELL_UPHEAVAL_CAST    = 257608,
    SPELL_UPHEAVAL_DAMAGE  = 257617,
    SPELL_UPHEAVAL_JUMP_TO_TARGET = 257615,

    //Sandtrap
    SPELL_SAND_TRAP = 257092,
    SPELL_SAND_TRAP_AREATRIGGER = 257093,
    SPELL_SAND_TRAP_DAMAGE = 257119,
};

enum Events{
    EVENT_SAND_TRAP = 1,
    EVENT_UPHEAVAL = 2,
    EVENT_SANDSTORM = 3,
    EVENT_UPHEAVAL_TARGET_SELECTION = 4,
    EVENT_UPHEAVAL_DAMAGE = 5,
};


// 127479 - Sand Queen
struct boss_sand_queen : public BossAI
{
    boss_sand_queen(Creature* creature) : BossAI(creature, DATA_THE_SAND_QUEEN) { }

    void EnterCombat(Unit* who) override
    {
        events.ScheduleEvent(EVENT_SAND_TRAP, 8500);
        events.ScheduleEvent(EVENT_UPHEAVAL, 20500);
        events.ScheduleEvent(EVENT_SANDSTORM, 30300);
        BossAI::EnterCombat(who);
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
            case EVENT_SAND_TRAP:
                DoCastVictim(SPELL_SAND_TRAP);
                events.ScheduleEvent(EVENT_SAND_TRAP, 14200);
                break;
            case EVENT_UPHEAVAL:
                me->CastSpell(me, SPELL_UPHEAVAL_CAST);
                events.ScheduleEvent(EVENT_UPHEAVAL, 43400);
                events.ScheduleEvent(EVENT_UPHEAVAL_TARGET_SELECTION, 2000);
                break;
            case EVENT_SANDSTORM:
                me->CastSpell(me, SPELL_SANDSTORM);
                events.ScheduleEvent(EVENT_SANDSTORM, 34000);
                break;
            case EVENT_UPHEAVAL_TARGET_SELECTION:
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                me->CastSpell(me, SPELL_UPHEAVAL_TARGET_SELECTOR);
                break;
            case EVENT_UPHEAVAL_DAMAGE:
                if (upheaval_target->IsAlive())
                {
                    me->CastSpell(upheaval_target, SPELL_UPHEAVAL_DAMAGE);
                }
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    Unit* upheaval_target;

};

struct areatrigger_sand_trap : AreaTriggerAI
{
    areatrigger_sand_trap(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnInitialize() override
    {
        _instance = at->GetInstanceScript();
    };
    InstanceScript * _instance;

    void OnUnitEnter(Unit* unit) override
    {
        unit->CastSpell(unit, SPELL_SAND_TRAP_DAMAGE);
        at->Remove();
    }
};

//257092
class bfa_spell_sand_trap : public SpellScript
{
    PrepareSpellScript(bfa_spell_sand_trap);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_SAND_TRAP_AREATRIGGER);
        caster->SummonCreature(NPC_BUZZING_DRONE, target->GetPosition(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 5000);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(bfa_spell_sand_trap::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//257612
class bfa_spell_upheaval_target_selector : public SpellScript
{
    PrepareSpellScript(bfa_spell_upheaval_target_selector);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_UPHEAVAL_JUMP_TO_TARGET);
        caster->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(bfa_spell_upheaval_target_selector::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//257608
class bfa_spell_upheaval_2 : public AuraScript
{
    PrepareAuraScript(bfa_spell_upheaval_2);

    void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        caster->CastSpell(caster, SPELL_UPHEAVAL_DAMAGE);

        if (Creature* sandqueen = caster->ToCreature())
            sandqueen->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_upheaval_2::HandleEffectRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_the_sand_queen()
{
    RegisterCreatureAI(boss_sand_queen);
    RegisterAreaTriggerAI(areatrigger_sand_trap);
    RegisterSpellScript(bfa_spell_sand_trap);
    RegisterSpellScript(bfa_spell_upheaval_target_selector);
    RegisterAuraScript(bfa_spell_upheaval_2);
}
