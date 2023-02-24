/*
 * Copyright 2021 
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
#include "PhasingHandler.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells
{
    SPELL_INCITE_PANIC = 233570,
    SPELL_PESTILENCE = 233614,
    SPELL_PESTILENCE_AT = 233631,//AT 9466
    SPELL_PESTILENCE_DMG = 233850,
    SPELL_SHADOW_BARRAGE = 234452,
};

enum Events
{
    EVENT_INCITE_PANIC = 1,
    EVENT_PESTILENCE = 2,
    EVENT_SHADOW_BARRAGE = 3,
};

//117239
class boss_malificus : public CreatureScript
{
public:
    boss_malificus() : CreatureScript("boss_malificus") { }

    struct boss_malificusAI : public WorldBossAI
    {
        boss_malificusAI(Creature* creature) : WorldBossAI(creature)
        {
        }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
        }

        void JustEngagedWith(Unit* who) override
        {
            if (!who)
                return;
            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
            events.Reset();
            events.ScheduleEvent(EVENT_INCITE_PANIC, 14s, 15s);
            events.ScheduleEvent(EVENT_PESTILENCE, 14s);
            events.ScheduleEvent(EVENT_SHADOW_BARRAGE, 16s, 17s);
            //me->AI()->Talk(88247); //On aggro text
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            WorldBossAI::EnterEvadeMode(why);
            Reset();
            DoStopAttack();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (events.Empty())
            {
                events.ScheduleEvent(EVENT_INCITE_PANIC, 14s, 15s);
                events.ScheduleEvent(EVENT_PESTILENCE, 14s);
                events.ScheduleEvent(EVENT_SHADOW_BARRAGE, 16s, 17s);
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INCITE_PANIC:
                {
                    DoCastRandom(SPELL_INCITE_PANIC, false);
                    DoCastRandom(SPELL_INCITE_PANIC, false);
                    DoCastRandom(SPELL_INCITE_PANIC, false);
                    events.Repeat(14s, 15s);
                    break;
                }
                case EVENT_PESTILENCE:
                {
                    DoCastRandom(SPELL_PESTILENCE, false);
                    events.Repeat(14s);
                    break;
                }
                case EVENT_SHADOW_BARRAGE:
                {
                    DoCastRandom(SPELL_SHADOW_BARRAGE, false);
                    events.Repeat(16s, 17s);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_malificusAI(creature);
    }
};
//233614
class spell_malificus_pestilence : public SpellScriptLoader
{
public:
    spell_malificus_pestilence() : SpellScriptLoader("spell_malificus_pestilence")
    {}

    class spell_malificus_pestilence_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_malificus_pestilence_SpellScript);

        void HandleDummy(SpellEffIndex)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetCaster()->CastSpell(GetHitUnit(), SPELL_PESTILENCE_AT, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_malificus_pestilence_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_malificus_pestilence_SpellScript();
    }
};
// 233631,//AT 9466
struct at_malificus_pestilence : AreaTriggerAI
{
    at_malificus_pestilence(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        Unit* caster = at->GetCaster();

        if (!caster)
            return;

        for (auto guid : at->GetInsideUnits())
            if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                if (unit->GetTypeId() == TYPEID_PLAYER)
                    unit->CastSpell(unit, SPELL_PESTILENCE_DMG, true);
    }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();

        if (!caster)
            return;

        if (!unit)
            return;

        if (unit->GetTypeId() == TYPEID_PLAYER)
            unit->CastSpell(unit, SPELL_PESTILENCE_DMG, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit)
            return;

        if (unit->HasAura(SPELL_PESTILENCE_DMG))
            unit->RemoveAura(SPELL_PESTILENCE_DMG);
    }

    void OnRemove() override
    {
        Unit* caster = at->GetCaster();

        if (!caster)
            return;

        for (auto guid : at->GetInsideUnits())
            if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                if (unit->HasAura(SPELL_PESTILENCE_DMG))
                    unit->RemoveAura(SPELL_PESTILENCE_DMG);
    }
};
void AddSC_boss_malificus()
{
    new boss_malificus();
    new spell_malificus_pestilence();
    RegisterAreaTriggerAI(at_malificus_pestilence);
}
