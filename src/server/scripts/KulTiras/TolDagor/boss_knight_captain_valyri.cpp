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
#include <iostream>
using namespace std;

enum Spells {
    SPELL_CINDER_FLAME = 256955,
    SPELL_FUSELIGHTER = 257028,
    //Ignition
    SPELL_IGNITION = 256970,
    SPELL_IGNITION_AREAEFFECT = 256973,

    SPELL_ARMAMENT = 262327,
    SPELL_ARMAMENT_TEST = 263052,

    SPELL_BURNING_ARSENAL = 256710,

    SPELL_PICKING_UP = 265610,
    SPELL_CARRYING_MUNITIONS = 256496,
};

enum Events {
    EVENTS_CINDER_FLAME = 1,
    EVENTS_FUSELIGHTER = 2,
    EVENTS_IGNITION = 3,

    EVENT_DESPAWN = 5,
};

enum Actions {
    ACTION_THROW_BOMB = 0,
};

//todo correct
Position BarrelPositions[]{
    { 60.00f, -2962.62f, 60.92f },
    { 67.81f, -2674.87f, 60.92f },
    { 62.545f, -2682.86f, 60.92f },
    { 71.17f, -2690.06f, 60.83f },
};

//127490
struct boss_knight_captain_valyri : public BossAI
{
    boss_knight_captain_valyri(Creature* creature) : BossAI(creature, DATA_KNIGHT_CAPTAIN_VALYRI) { }

    void EnterCombat(Unit* who) override
    {
        events.ScheduleEvent(EVENTS_IGNITION, 6100);
        events.ScheduleEvent(EVENTS_FUSELIGHTER, 14200);
        events.ScheduleEvent(EVENTS_CINDER_FLAME, 18200);
        BossAI::EnterCombat(who);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_CINDER_FLAME || spell->Id == SPELL_IGNITION_AREAEFFECT)
        {
            if (target->HasAura(SPELL_CARRYING_MUNITIONS))
            {
               // target->CastSpell(nullptr,  256578);
                target->RemoveAura(SPELL_CARRYING_MUNITIONS);

                if (Unit* barrel = me->SummonCreature(NPC_MUNITIONS_BARREL, target->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN, 60000))
                    barrel->CastSpell(nullptr,  SPELL_BURNING_ARSENAL);
            }
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
            switch (eventId)
            {
            case EVENTS_CINDER_FLAME:
                DoCastVictim(SPELL_CINDER_FLAME);
                events.ScheduleEvent(EVENTS_CINDER_FLAME, 20500);
                break;
            case EVENTS_FUSELIGHTER:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                    me->CastSpell(target, SPELL_FUSELIGHTER);
                events.ScheduleEvent(EVENTS_FUSELIGHTER, 14700);
                break;
            case EVENTS_IGNITION:
                maxIgnitionTargets = 0;
                DoCastVictim(SPELL_IGNITION);
                events.ScheduleEvent(EVENTS_IGNITION, 32700);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    int maxIgnitionTargets = 0;

};
//131856
struct npc_tol_dagor_ashavane_quartermaster : public ScriptedAI
{
    npc_tol_dagor_ashavane_quartermaster(Creature* pCreature) : ScriptedAI(pCreature) { }


    void InitializeAI() override
    {
    }

    void Reset() override
    {
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_THROW_BOMB:
                Talk(0);
                //if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true)) fix add correct target
                //if (Unit* target = me->FindNearestCreature(NPC_KNIGHT_CAPTAIN_VALYRI, 50.0f, true))
                    //me->CastSpell(target, SPELL_ARMAMENT);
                me->CastSpell(BarrelPositions[urand(0, 3)], SPELL_ARMAMENT);
                break;
            default:
                break;
        }
    }
};

//129437
struct npc_tol_dagor_munitions_barrel : public ScriptedAI
{
    npc_tol_dagor_munitions_barrel(Creature* pCreature) : ScriptedAI(pCreature) { }

    void Reset() override
    {
        events.Reset();
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == 256963 || spell->Id == 256978 || spell->Id == 256931 || spell->Id == 256931) //256931?
        {
            if (hit == false)
            {
                me->CastSpell(me, SPELL_BURNING_ARSENAL);
                events.ScheduleEvent(EVENT_DESPAWN, 6000);
                hit = true;
            }
        }
        if (spell->Id == SPELL_PICKING_UP)
        {
            if (!me->HasUnitState(UNIT_STATE_CASTING))
            {
                if (!caster->HasAura(SPELL_CARRYING_MUNITIONS))
                {
                    if (me->IsAlive())
                    {
                        me->ForcedDespawn();
                    }
                    caster->CastSpell(nullptr, SPELL_CARRYING_MUNITIONS);
                }
            }
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (Unit* quartermaster = me->FindNearestCreature(NPC_ASHAVANE_QUATERMASTER, 100))
            quartermaster->GetAI()->DoAction(ACTION_THROW_BOMB);
    }

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        hit = false;
        ScriptedAI::InitializeAI();
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);
        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_DESPAWN:
                me->KillSelf();
                me->ForcedDespawn();
            }
        }
    }
private:
    bool hit = false;
};

//256970
class spell_ignition : public SpellScript
{
    PrepareSpellScript(spell_ignition);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_IGNITION_AREAEFFECT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_ignition::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//257028 todo fix
class bfa_spell_fuselighter : public AuraScript
{
    PrepareAuraScript(bfa_spell_fuselighter);

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster || !target)
            return;


    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(bfa_spell_fuselighter::AfterApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_knight_captain_valyri()
{
    RegisterCreatureAI(boss_knight_captain_valyri);
    RegisterCreatureAI(npc_tol_dagor_ashavane_quartermaster);
    RegisterCreatureAI(npc_tol_dagor_munitions_barrel);
    RegisterSpellScript(spell_ignition);
    RegisterAuraScript(bfa_spell_fuselighter);
}
