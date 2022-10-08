/*
* Copyright (C) 2021 BfaCore Reforged
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

enum Spells
{
    SPELL_CRASHING_EMBERS = 233516, //233519,
    SPELL_METEOR_SLASH = 233484,
    SPELL_RUPTURE = 233566,
    SPELL_RUPTURE_TRIGGER = 234389,
};

enum Events
{
    EVENT_CRASHING_EMBERS = 1,
    EVENT_METEOR_SLASH = 2,
    EVENT_RUPTURE = 3,
};

enum NPCs
{

};

enum Phases
{
    PHASE_ASLEEP = 0,
    PHASE_COMBAT = 1
};
//117239
class boss_world_brutallus : public CreatureScript
{
public:
    boss_world_brutallus() : CreatureScript("boss_world_brutallus") { }

    struct boss_world_brutallusAI : public WorldBossAI
    {
        boss_world_brutallusAI(Creature* creature) : WorldBossAI(creature) {  }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->GetMotionMaster()->MoveTargetedHome();
            events.SetPhase(PHASE_ASLEEP);
            events.Reset();
        }

        void EnterCombat(Unit* who) 
        {
            if (!who)
                return;
            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
            events.Reset();
            events.SetPhase(PHASE_COMBAT);
            events.ScheduleEvent(EVENT_CRASHING_EMBERS, 17s);
            events.ScheduleEvent(EVENT_METEOR_SLASH, 18s, 19s);
            events.ScheduleEvent(EVENT_RUPTURE, 17s, 18s);
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
                events.ScheduleEvent(EVENT_CRASHING_EMBERS, 17s);
                events.ScheduleEvent(EVENT_METEOR_SLASH, 18s, 19s);
                events.ScheduleEvent(EVENT_RUPTURE, 17s, 18s);
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CRASHING_EMBERS:
                {
                    DoCastRandom(SPELL_CRASHING_EMBERS, false);
                    events.Repeat(17s);
                    break;
                }
                case EVENT_METEOR_SLASH:
                {
                    DoCastVictim(SPELL_METEOR_SLASH, false);
                    events.Repeat(18s, 19s);
                    break;
                }
                case EVENT_RUPTURE:
                {
                    DoCastVictim(SPELL_RUPTURE, false);
                    events.Repeat(17s, 18s);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_world_brutallusAI(creature);
    }
};

//233484 meteor-slash
class spell_brutallus_meteor_slash : public SpellScriptLoader
{
public:
    spell_brutallus_meteor_slash() : SpellScriptLoader("spell_brutallus_meteor_slash") {}

    class spell_brutallus_meteor_slash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_brutallus_meteor_slash_SpellScript);

        uint8 targetCount = 0;

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.size() > 1)
                targetCount = targets.size();
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster() || !GetHitUnit() || targetCount == 0)
                return;

            SetHitDamage(GetHitDamage() / targetCount);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_brutallus_meteor_slash_SpellScript::FilterTargets, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_brutallus_meteor_slash_SpellScript::FilterTargets, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            OnEffectHitTarget += SpellEffectFn(spell_brutallus_meteor_slash_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_brutallus_meteor_slash_SpellScript();
    }
};

// 233566   
class spell_brutallus_rupture : public SpellScriptLoader
{
public:
    spell_brutallus_rupture() : SpellScriptLoader("spell_brutallus_rupture")
    {}

    class spell_brutallus_rupture_SpellScript : public SpellScript
    {
    public:
        PrepareSpellScript(spell_brutallus_rupture_SpellScript);

        void HandleDummy(SpellEffIndex)
        {
            if (!GetCaster() || !GetHitUnit())
                return;

            GetCaster()->CastSpell(GetHitUnit(), SPELL_RUPTURE_TRIGGER, true);
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_brutallus_rupture_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_brutallus_rupture_SpellScript();
    }
};

void AddSC_boss_world_brutallus()
{
    new boss_world_brutallus();
    new spell_brutallus_meteor_slash();
    new spell_brutallus_rupture(); 
}
