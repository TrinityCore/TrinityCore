/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "baradin_hold.h"
#include "Containers.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

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
            boss_occutharAI(Creature* creature) : BossAI(creature, BOSS_OCCUTHAR),
                _vehicle(me->GetVehicleKit())
            {
                ASSERT(_vehicle);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                events.ScheduleEvent(EVENT_SEARING_SHADOWS, 8s);
                events.ScheduleEvent(EVENT_FOCUSED_FIRE, 15s);
                events.ScheduleEvent(EVENT_EYES_OF_OCCUTHAR, 30s);
                events.ScheduleEvent(EVENT_BERSERK, 5min);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                BossAI::EnterEvadeMode(why);
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
                            events.ScheduleEvent(EVENT_SEARING_SHADOWS, 25s);
                            break;
                        case EVENT_FOCUSED_FIRE:
                            DoCastAOE(SPELL_FOCUSED_FIRE_TRIGGER, true);
                            events.ScheduleEvent(EVENT_FOCUSED_FIRE, 15s);
                            break;
                        case EVENT_EYES_OF_OCCUTHAR:
                            DoCastAOE(SPELL_EYES_OF_OCCUTHAR);
                            events.RescheduleEvent(EVENT_FOCUSED_FIRE, 15s);
                            events.ScheduleEvent(EVENT_EYES_OF_OCCUTHAR, 60s);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                        default:
                            break;
                    }
                }
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

            void IsSummonedBy(WorldObject* /*summoner*/) override
            {
                // player is the spellcaster so register summon manually
                if (Creature* occuthar =  _instance->GetCreature(BOSS_OCCUTHAR))
                    occuthar->AI()->JustSummoned(me);
            }

            void Reset() override
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_FOCUSED_FIRE_FIRST_DAMAGE, 0s);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_FOCUSED_FIRE_FIRST_DAMAGE)
                {
                    DoCastAOE(SPELL_FOCUSED_FIRE_FIRST_DAMAGE);
                    if (++_damageCount < 2)
                        _events.ScheduleEvent(EVENT_FOCUSED_FIRE_FIRST_DAMAGE, 1s);
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override { } // Never evade

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

// 96872 - Focused Fire
class spell_occuthar_focused_fire : public SpellScriptLoader
{
    public:
        spell_occuthar_focused_fire() : SpellScriptLoader("spell_occuthar_focused_fire") { }

        class spell_occuthar_focused_fire_SpellScript : public SpellScript
        {
            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() < 2)
                    return;

                targets.remove_if([&](WorldObject const* target)
                {
                    return GetCaster()->GetVictim() == target;
                });

                if (targets.size() >= 2)
                    Trinity::Containers::RandomResize(targets, 1);
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
            bool Validate(SpellInfo const* spellInfo) override
            {
                return ValidateSpellEffect({ { spellInfo->Id, EFFECT_0 } }) && ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
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
            bool Load() override
            {
                return InstanceHasScript(GetCaster(), BHScriptName);
            }

            void HandleScript()
            {
                Position pos = GetHitUnit()->GetPosition();

                if (Creature* occuthar = GetCaster()->GetInstanceScript()->GetCreature(BOSS_OCCUTHAR))
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
            bool Load() override
            {
                return GetCaster() && GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    if (IsExpired())
                        caster->CastSpell(nullptr, SPELL_OCCUTHARS_DESTUCTION, aurEff);

                    caster->ToCreature()->DespawnOrUnsummon(500ms);
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
