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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "emerald_nightmare.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum Spells
{
    // Stage One
    SPELL_INFESTED                  = 204504,
    SPELL_INFESTED_MIND             = 205043,
    SPELL_SPREAD_INFESTATION        = 205070,
    SPELL_INFESTED_GROUND           = 203044,
    SPELL_INFESTED_GROUND_DAMAGE    = 203045,
    SPELL_INFESTED_BREATH           = 202977,
    SPELL_ROT                       = 203096,
    SPELL_VOLATILE_ROT              = 204463,
    SPELL_TAIL_LASH                 = 203024,

    // Stage Two
    SPELL_HEART_OF_THE_SWARM        = 203552,
    SPELL_BURST_OF_CORRUPTION       = 203646,
};

class boss_nythendra : public CreatureScript
{
public:
    boss_nythendra() : CreatureScript("boss_nythendra") { }

    enum Events
    {
        EVENT_ROT               = 1,
        EVENT_VOLATILE_ROT      = 2,
        EVENT_INFESTED_BREATH   = 3,
        EVENT_TAIL_LASH         = 4,
    };

    struct boss_nythendraAI : public BossAI
    {
        boss_nythendraAI(Creature* creature) : BossAI(creature, DATA_NYTHENDRA) { }

        void EnterCombat(Unit* /*attacker*/) override
        {
            events.ScheduleEvent(EVENT_ROT, Seconds(15));
            events.ScheduleEvent(EVENT_VOLATILE_ROT, Seconds(1));
            events.ScheduleEvent(EVENT_INFESTED_BREATH, Seconds(1));
            events.ScheduleEvent(EVENT_TAIL_LASH, Seconds(6));
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_ROT:
                {
                    for (uint8 i = 0; i < 2; ++i)
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2))
                            me->CastSpell(target, SPELL_ROT, true);

                    events.ScheduleEvent(EVENT_ROT, Seconds(15));
                    break;
                }
                case EVENT_VOLATILE_ROT:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                        me->CastSpell(target, SPELL_VOLATILE_ROT, true);

                    events.ScheduleEvent(EVENT_VOLATILE_ROT, Seconds(15));
                    break;
                }
                case EVENT_TAIL_LASH:
                {
                    DoCast(SPELL_TAIL_LASH);
                    events.ScheduleEvent(EVENT_TAIL_LASH, Seconds(6));
                    break;
                }
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_nythendraAI(creature);
    }
};

//203096
class spell_nythendra_rot : public AuraScript
{
    PrepareAuraScript(spell_nythendra_rot);

    void AfterRemove(AuraEffect const* /*eff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), SPELL_INFESTED_GROUND, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_nythendra_rot::AfterRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
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

    void HandleAfterCast()
    {
        for (uint8 i = 0; i < 3; ++i)
        {
            Position castPos;
            GetRandPosFromCenterInDist(GetCaster(), 5.0f, castPos);
            GetCaster()->CastSpell(castPos, SPELL_INFESTED_GROUND, true);
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_nythendra_volatile_rot_damage::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        AfterCast += SpellCastFn(spell_nythendra_volatile_rot_damage::HandleAfterCast);
    }
};

//Spell : 203044
class at_nythendra_infested_ground : public AreaTriggerEntityScript
{
public:
    at_nythendra_infested_ground() : AreaTriggerEntityScript("at_nythendra_infested_ground") { }

    struct at_nythendra_infested_groundAI : AreaTriggerAI
    {
        at_nythendra_infested_groundAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            if (caster && unit)
                if (caster->IsValidAttackTarget(unit))
                    caster->CastSpell(unit, SPELL_INFESTED_GROUND_DAMAGE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            unit->RemoveAurasDueToSpell(SPELL_INFESTED_GROUND_DAMAGE);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_nythendra_infested_groundAI(areatrigger);
    }
};

void AddSC_nythendra()
{
    new boss_nythendra();

    RegisterAuraScript(spell_nythendra_rot);
    RegisterSpellScript(spell_nythendra_volatile_rot_damage);

    new at_nythendra_infested_ground();
}
