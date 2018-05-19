/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "eye_of_azshara.h"

enum Spells
{
    SPELL_CRASHING_WAVE                     = 191900,
    SPELL_THROW_SPEAR                       = 192131,

    SPELL_IMPALING_SPEAR_CAST               = 191946,
    SPELL_IMPALING_SPEAR_EFFECT             = 191977,
    SPELL_IMPALING_SPEAR_TARGET             = 192094,

    SPELL_CALL_REINFORCEMENTS_SHELLBREAKER  = 192072,
    SPELL_SHELLBREAKER_BELLOWING_ROAR       = 192135,

    SPELL_CALL_REINFORCEMENTS_CRESTRIDER    = 192073,
    SPELL_CRESTRIDER_LIGHTNING_STRIKE       = 192138,

    SPELL_ENRAGE                            = 197064,
};

// 91784
struct boss_warlord_parjesh : public BossAI
{
    boss_warlord_parjesh(Creature* creature) : BossAI(creature, DATA_WARLORD_PARJESH) { }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(SPELL_CRASHING_WAVE, 20000, 24000);
        events.ScheduleEvent(SPELL_IMPALING_SPEAR_CAST, 28000, 32000);
        events.ScheduleEvent(SPELL_THROW_SPEAR, 8000, 12000);
        events.ScheduleEvent(SPELL_CALL_REINFORCEMENTS_SHELLBREAKER, 3000);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case SPELL_CRASHING_WAVE:
                me->CastSpell(me, SPELL_CRASHING_WAVE, false);
                events.Repeat(20000, 24000);
                break;
            case SPELL_IMPALING_SPEAR_CAST:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                {
                    me->CastSpell(target, SPELL_IMPALING_SPEAR_CAST, false);
                    me->CastSpell(target, SPELL_IMPALING_SPEAR_TARGET, true);
                }
                events.Repeat(28000, 32000);
                break;
            case SPELL_THROW_SPEAR:
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    me->CastSpell(target, SPELL_THROW_SPEAR, false);
                events.Repeat(8000, 12000);
                break;
            case SPELL_CALL_REINFORCEMENTS_SHELLBREAKER:
                me->CastSpell(me, RAND(SPELL_CALL_REINFORCEMENTS_SHELLBREAKER, SPELL_CALL_REINFORCEMENTS_CRESTRIDER), false);
                events.Repeat(28000, 32000);
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(30, damage))
            me->CastSpell(me, SPELL_ENRAGE, false);
    }
};

//191946
class spell_warlord_parjesh_impaling_spear : public SpellScript
{
    PrepareSpellScript(spell_warlord_parjesh_impaling_spear);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster || !target)
            return;

        Unit* finalTarget = target;
        float minimalDistance = caster->GetDistance(target);

        std::list<Unit*> attackableUnitList;
        caster->GetAttackableUnitListInRange(attackableUnitList, minimalDistance);

        for (Unit* unit : attackableUnitList)
        {
            if (unit->IsInBetween(*caster, *target) && caster->GetDistance(unit) < minimalDistance)
            {
                minimalDistance = caster->GetDistance(unit);
                finalTarget = unit;
            }
        }

        caster->CastSpell(finalTarget, SPELL_IMPALING_SPEAR_EFFECT, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warlord_parjesh_impaling_spear::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 97264
struct npc_hatecoil_shellbreaker : public ScriptedAI
{
    npc_hatecoil_shellbreaker(Creature* creature) : ScriptedAI(creature) { }

    void EnterCombat(Unit* /*who*/) override
    {
        me->GetScheduler().Schedule(Seconds(1), Seconds(1), [](TaskContext context)
        {
            GetContextUnit()->CastSpell(nullptr, SPELL_CRESTRIDER_LIGHTNING_STRIKE, false);
            context.Repeat();
        });
    }
};
// 97269
struct npc_hatecoil_crestrider : public ScriptedAI
{
    npc_hatecoil_crestrider(Creature* creature) : ScriptedAI(creature) { }

    void EnterCombat(Unit* /*who*/) override
    {
        me->GetScheduler().Schedule(Seconds(1), Seconds(1), [this](TaskContext context)
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                GetContextUnit()->CastSpell(nullptr, SPELL_SHELLBREAKER_BELLOWING_ROAR, false);

            context.Repeat();
        });
    }
};

void AddSC_boss_warlord_parjesh()
{
    RegisterCreatureAI(boss_warlord_parjesh);

    RegisterSpellScript(spell_warlord_parjesh_impaling_spear);

    RegisterCreatureAI(npc_hatecoil_shellbreaker);
    RegisterCreatureAI(npc_hatecoil_crestrider);
}
