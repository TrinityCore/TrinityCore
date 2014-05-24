/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "Vehicle.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "baradin_hold.h"

enum Spells
{
    SPELL_SEARING_SHADOWS               = 96913,
    SPELL_FOCUSED_FIRE_FIRST_DAMAGE     = 97212,
    SPELL_FOCUSED_FIRE_TRIGGER          = 96872,
    SPELL_FOCUSED_FIRE_VISUAL           = 96886,
    SPELL_FOCUSED_FIRE                  = 96884,
    SPELL_EYES_OF_OCCUTHAR              = 96920,
    SPELL_GAZE_OF_OCCUTHAR              = 96942,
    SPELL_OCCUTHARS_DESTUCTION          = 96968,
    SPELL_BERSERK                       = 47008
};

enum Events
{
    EVENT_SEARING_SHADOWS               = 1,
    EVENT_FOCUSED_FIRE                  = 2,
    EVENT_EYES_OF_OCCUTHAR              = 3,
    EVENT_BERSERK                       = 4,

    EVENT_FOCUSED_FIRE_FIRST_DAMAGE     = 1
};

enum Misc
{
    MAX_OCCUTHAR_VEHICLE_SEATS          = 7
};

class boss_occuthar : public CreatureScript
{
    public:
        boss_occuthar() : CreatureScript("boss_occuthar") { }

        struct boss_occutharAI : public BossAI
        {
            boss_occutharAI(Creature* creature) : BossAI(creature, DATA_OCCUTHAR),
                _vehicle(me->GetVehicleKit())
            {
                ASSERT(_vehicle);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_SEARING_SHADOWS, 8 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FOCUSED_FIRE, 15 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_EYES_OF_OCCUTHAR, 30 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BERSERK, 5 * MINUTE * IN_MILLISECONDS);
            }

            void EnterEvadeMode() override
            {
                BossAI::EnterEvadeMode();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _DespawnAtEvade();
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                if (summon->GetEntry() == NPC_FOCUS_FIRE_DUMMY)
                {
                    DoCast(summon, SPELL_FOCUSED_FIRE);

                    for (uint8 i = 0; i < MAX_OCCUTHAR_VEHICLE_SEATS; ++i)
                    {
                        if (Unit* vehicle = _vehicle->GetPassenger(i))
                            vehicle->CastSpell(summon, SPELL_FOCUSED_FIRE_VISUAL);
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
                        case EVENT_SEARING_SHADOWS:
                            DoCastAOE(SPELL_SEARING_SHADOWS);
                            events.ScheduleEvent(EVENT_SEARING_SHADOWS, 25 * IN_MILLISECONDS);
                            break;
                        case EVENT_FOCUSED_FIRE:
                            DoCastAOE(SPELL_FOCUSED_FIRE_TRIGGER, true);
                            events.ScheduleEvent(EVENT_FOCUSED_FIRE, 15 * IN_MILLISECONDS);
                            break;
                        case EVENT_EYES_OF_OCCUTHAR:
                            DoCastAOE(SPELL_EYES_OF_OCCUTHAR);
                            events.RescheduleEvent(EVENT_FOCUSED_FIRE, 15 * IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_EYES_OF_OCCUTHAR, 60 * IN_MILLISECONDS);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            Vehicle* _vehicle;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBaradinHoldAI<boss_occutharAI>(creature);
        }
};

class npc_eyestalk : public CreatureScript
{
    public:
        npc_eyestalk() : CreatureScript("npc_eyestalk") { }

        struct npc_eyestalkAI : public ScriptedAI
        {
            npc_eyestalkAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                _damageCount = 0;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                // player is the spellcaster so register summon manually
                if (Creature* occuthar = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_OCCUTHAR)))
                    occuthar->AI()->JustSummoned(me);
            }

            void Reset() override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_FOCUSED_FIRE_FIRST_DAMAGE, 0);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_FOCUSED_FIRE_FIRST_DAMAGE)
                {
                    DoCastAOE(SPELL_FOCUSED_FIRE_FIRST_DAMAGE);
                    if (++_damageCount < 2)
                        _events.ScheduleEvent(EVENT_FOCUSED_FIRE_FIRST_DAMAGE, 1 * IN_MILLISECONDS);
                }
            }

            void EnterEvadeMode() override { } // Never evade

        private:
            InstanceScript* _instance;
            EventMap _events;
            uint8 _damageCount;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetBaradinHoldAI<npc_eyestalkAI>(creature);
        }
};

class FocusedFireTargetSelector : public std::unary_function<Unit *, bool>
{
    public:
        FocusedFireTargetSelector(Creature* me, const Unit* victim) : _me(me), _victim(victim) { }

        bool operator() (WorldObject* target)
        {
            if (target == _victim && _me->getThreatManager().getThreatList().size() > 1)
                return true;

            if (target->GetTypeId() != TYPEID_PLAYER)
                return true;

            return false;
        }

        Creature* _me;
        Unit const* _victim;
};

// 96872 - Focused Fire
class spell_occuthar_focused_fire : public SpellScriptLoader
{
    public:
        spell_occuthar_focused_fire() : SpellScriptLoader("spell_occuthar_focused_fire") { }

        class spell_occuthar_focused_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_occuthar_focused_fire_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(FocusedFireTargetSelector(GetCaster()->ToCreature(), GetCaster()->GetVictim()));
                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_occuthar_focused_fire_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_occuthar_focused_fire_SpellScript();
        }
};

// ID - 96931 Eyes of Occu'thar
class spell_occuthar_eyes_of_occuthar : public SpellScriptLoader
{
    public:
        spell_occuthar_eyes_of_occuthar() : SpellScriptLoader("spell_occuthar_eyes_of_occuthar") { }

        class spell_occuthar_eyes_of_occuthar_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_occuthar_eyes_of_occuthar_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_0].CalcValue()))
                    return false;
                return true;
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetHitUnit()->CastSpell(GetCaster(), GetEffectValue(), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_occuthar_eyes_of_occuthar_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_occuthar_eyes_of_occuthar_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_occuthar_eyes_of_occuthar_SpellScript();
        }
};

// ID - 96932 Eyes of Occu'thar
class spell_occuthar_eyes_of_occuthar_vehicle : public SpellScriptLoader
{
    public:
        spell_occuthar_eyes_of_occuthar_vehicle() : SpellScriptLoader("spell_occuthar_eyes_of_occuthar_vehicle") { }

        class spell_occuthar_eyes_of_occuthar_vehicle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_occuthar_eyes_of_occuthar_vehicle_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetInstanceScript() != NULL;
            }

            void HandleScript()
            {
                Position pos = GetHitUnit()->GetPosition();

                if (Creature* occuthar = ObjectAccessor::GetCreature(*GetCaster(), GetCaster()->GetInstanceScript()->GetData64(DATA_OCCUTHAR)))
                {
                    if (Creature* creature = occuthar->SummonCreature(NPC_EYE_OF_OCCUTHAR, pos))
                        creature->CastSpell(GetHitUnit(), SPELL_GAZE_OF_OCCUTHAR, false);
                }
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_occuthar_eyes_of_occuthar_vehicle_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_occuthar_eyes_of_occuthar_vehicle_SpellScript();
        }
};

// 96942 / 101009 - Gaze of Occu'thar
class spell_occuthar_occuthars_destruction : public SpellScriptLoader
{
    public:
        spell_occuthar_occuthars_destruction() : SpellScriptLoader("spell_occuthar_occuthars_destruction") { }

        class spell_occuthar_occuthars_destruction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_occuthar_occuthars_destruction_AuraScript);

            bool Load() override
            {
                return GetCaster() && GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (IsExpired())
                        caster->CastSpell((Unit*)NULL, SPELL_OCCUTHARS_DESTUCTION, true, NULL, aurEff);

                    caster->ToCreature()->DespawnOrUnsummon(500);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_occuthar_occuthars_destruction_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_occuthar_occuthars_destruction_AuraScript();
        }
};

void AddSC_boss_occuthar()
{
    new boss_occuthar();
    new npc_eyestalk();
    new spell_occuthar_focused_fire();
    new spell_occuthar_eyes_of_occuthar();
    new spell_occuthar_eyes_of_occuthar_vehicle();
    new spell_occuthar_occuthars_destruction();
}
