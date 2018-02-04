/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "grim_batol.h"

enum Spells
{
    // Erudax
    SPELL_BINDING_SHADOWS                       = 79466,
    SPELL_ENFEEBLING_BLOW                       = 75789,
    SPELL_SHADOW_GALE_TRIGGER                   = 75656,
    SPELL_SHADOW_GALE                           = 75664,

    // Shadow Gale Controller
    SPELL_SUMMON_SHADOW_GALE_STALKER            = 75655,

    // Shadow Gale Stalker
    SPELL_SHADOW_GALE_TRIGGER_RUN_SPEED_TRIGGER = 92296,
};

enum Texts
{
    SAY_AGGRO                           = 0,
    SAY_ANNOUNCE_SHADOW_GALE            = 1,
    SAY_SHADOW_GALE                     = 2,
    SAY_FACELESS_CORRUPTORS             = 3,
    SAY_ANNOUNCE_GUARDIANS              = 4,
    SAY_ANNOUNCE_SHIELD_OF_NIGHTMARES   = 5,
    SAY_SLAY                            = 6,
    SAY_DEATH                           = 7
};

enum Events
{
    // Erudax
    EVENT_BINDING_SHADOWS = 1,
    EVENT_ENFEEBLING_BLOW,
    EVENT_SHADOW_GALE,
    EVENT_CHASE_VICTIM,
};

class boss_erudax : public CreatureScript
{
    public:
        boss_erudax() : CreatureScript("boss_erudax") { }

        struct boss_erudaxAI : public BossAI
        {
            boss_erudaxAI(Creature* creature) : BossAI(creature, DATA_ERUDAX) { }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_BINDING_SHADOWS, Seconds(10) + Milliseconds(500));
                events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, Seconds(19));
                events.ScheduleEvent(EVENT_SHADOW_GALE, Seconds(21) + Milliseconds(500));
            }

            void KilledUnit(Unit* killed) override
            {
                if (killed->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
                _DespawnAtEvade();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_SHADOW_GALE_STALKER)
                {
                    Talk(SAY_SHADOW_GALE);
                    Talk(SAY_ANNOUNCE_SHADOW_GALE);
                    summon->CastSpell(summon, SPELL_SHADOW_GALE_TRIGGER_RUN_SPEED_TRIGGER);
                    DoCastAOE(SPELL_SHADOW_GALE);
                    events.ScheduleEvent(EVENT_BINDING_SHADOWS, Seconds(21));
                    events.ScheduleEvent(EVENT_ENFEEBLING_BLOW, Seconds(20));
                    events.ScheduleEvent(EVENT_SHADOW_GALE, Seconds(55));
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
                        case EVENT_BINDING_SHADOWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, true, 0, 0))
                                DoCast(target, SPELL_BINDING_SHADOWS);
                            break;
                        case EVENT_ENFEEBLING_BLOW:
                            DoCastVictim(SPELL_ENFEEBLING_BLOW);
                            break;
                        case EVENT_SHADOW_GALE:
                            DoCastSelf(SPELL_SHADOW_GALE_TRIGGER, true);
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetGrimBatolAI<boss_erudaxAI>(creature);
        }
};

class spell_erudax_shadow_gale_trigger : public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale_trigger() : SpellScriptLoader("spell_erudax_shadow_gale_trigger") { }

        class spell_erudax_shadow_gale_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_SUMMON_SHADOW_GALE_STALKER });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_SUMMON_SHADOW_GALE_STALKER, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_erudax_shadow_gale_trigger_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_shadow_gale_trigger_SpellScript();
        }
};

class ShadowGaleDistanceCheck
{
    public:
        ShadowGaleDistanceCheck(Position pos) : _pos(pos) { }

        bool operator()(WorldObject* object)
        {
            return (object->GetDistance2d(_pos.GetPositionX(), _pos.GetPositionY()) <= 3.0f);
        }
    private:
        Position _pos;
};

class spell_erudax_shadow_gale : public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale() : SpellScriptLoader("spell_erudax_shadow_gale") { }

        class spell_erudax_shadow_gale_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(ShadowGaleDistanceCheck(GetExplTargetDest()->GetPosition()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_shadow_gale_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_shadow_gale_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_shadow_gale_SpellScript();
        }
};

class spell_erudax_shadow_gale_aura : public SpellScriptLoader
{
    public:
        spell_erudax_shadow_gale_aura() : SpellScriptLoader("spell_erudax_shadow_gale_aura") { }

        class spell_erudax_shadow_gale_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_erudax_shadow_gale_aura_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(ShadowGaleDistanceCheck(GetCaster()->GetPosition()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_erudax_shadow_gale_aura_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_erudax_shadow_gale_aura_SpellScript();
        }
};

void AddSC_boss_erudax()
{
    new boss_erudax();
    new spell_erudax_shadow_gale_trigger();
    new spell_erudax_shadow_gale();
    new spell_erudax_shadow_gale_aura();
}
