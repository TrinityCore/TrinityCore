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
#include "world_bosses_zuldazar.h"

enum Spells {
    SPELL_CRUSHING_SLAM            = 262004,
    SPELL_COALESCED_ESSENCE        = 261600,
    SPELL_COALESCED_ESSENCE_DAMAGE = 261597,
    SPELL_COALESCED_ESSENCE_VISUAL = 261575,
    SPELL_CONSUMING_SPIRITS        = 261605,

    SPELL_TERROR_WALL             = 261552,
    SPELL_TERROR_WALL_VISUAL      = 261560,
    SPELL_TERROR_WALL_VISUAL_BACK = 261718,
};

enum Events {
    EVENT_CRUSHING_SLAM     = 1,
    EVENT_COALSECED_ESSENCE = 2,
    EVENT_CONSUMING_SPIRITS = 3,
    EVENT_TERROR_WALL       = 4,
};

struct boss_tzane : public BossAI
{
    boss_tzane(Creature* creature) : BossAI(creature, DATA_TZANE) { }

    void Reset() override
    {
        summons.DespawnAll();
        BossAI::Reset();
    }

    void EnterCombat(Unit* who) override
    {
        events.ScheduleEvent(EVENT_CRUSHING_SLAM, 22000);
        events.ScheduleEvent(EVENT_TERROR_WALL, 11000);
        events.ScheduleEvent(EVENT_COALSECED_ESSENCE, 8500);
        events.ScheduleEvent(EVENT_CONSUMING_SPIRITS, 19000);
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
            case EVENT_CRUSHING_SLAM:
                DoCastVictim(SPELL_CRUSHING_SLAM);
                events.ScheduleEvent(EVENT_CRUSHING_SLAM, 23000);
                break;
            case EVENT_TERROR_WALL:
                DoCastVictim(SPELL_TERROR_WALL);
                events.ScheduleEvent(EVENT_TERROR_WALL, 23000);
                break;
            case EVENT_COALSECED_ESSENCE:
                DoCast(SPELL_COALESCED_ESSENCE);
                events.ScheduleEvent(EVENT_COALSECED_ESSENCE, 24000);
                break;
            case EVENT_CONSUMING_SPIRITS:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                {
                    me->CastSpell(target, SPELL_CONSUMING_SPIRITS, TRIGGERED_CAN_CAST_WHILE_CASTING_MASK);
                }
                events.ScheduleEvent(EVENT_CONSUMING_SPIRITS, 21000);
                break;
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//261600 SPELL_COALESCED_ESSENCE
class spell_coalseced_essence : public SpellScript
{
    PrepareSpellScript(spell_coalseced_essence);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        if (Unit* orb = caster->SummonCreature(NPC_ORB_OF_SWIRLING, target->GetPosition()))
        {
            orb->AddAura(SPELL_COALESCED_ESSENCE_VISUAL);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_coalseced_essence::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};
//261552
class spell_terror_wall : public SpellScript
{
    PrepareSpellScript(spell_terror_wall);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_TERROR_WALL_VISUAL);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_terror_wall::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};
//261560
class spell_terror_wall_visual : public SpellScript
{
    PrepareSpellScript(spell_terror_wall_visual);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        caster->CastSpell(target, SPELL_TERROR_WALL_VISUAL_BACK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_terror_wall_visual::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};
//261718
class spell_terror_wall_visual_back : public SpellScript
{
    PrepareSpellScript(spell_terror_wall_visual_back);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster || !target)
            return;

        //no idea what to do
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_terror_wall_visual_back::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

struct npc_orb_of_swirling : public ScriptedAI
{
    npc_orb_of_swirling(Creature* pCreature) : ScriptedAI(pCreature) { }

    int time = 2000;

    void InitializeAI() override
    {
        me->SetReactState(REACT_PASSIVE);
        SetCombatMovement(false);
        ScriptedAI::InitializeAI();
    }

    void UpdateAI(uint32 diff) override
    {
        if (time > 0)
        {
            time = time - diff;
            return;
        }

        if (Player* closestplayer = me->SelectNearestPlayer(50))
            if (me->GetDistance(closestplayer) < 1)
            {
                me->CastSpell(me, SPELL_COALESCED_ESSENCE_DAMAGE);
                me->ForcedDespawn(0);
            }
    }
};

void AddSC_boss_tzane()
{
    RegisterCreatureAI(boss_tzane);
    RegisterSpellScript(spell_coalseced_essence);
    RegisterSpellScript(spell_terror_wall);
    RegisterSpellScript(spell_terror_wall_visual);
    RegisterSpellScript(spell_terror_wall_visual_back);
    RegisterCreatureAI(npc_orb_of_swirling);
}
