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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "lost_city_of_the_tolvir.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

enum Spells
{
    // General Husam
    SPELL_HAMMER_FIST                       = 83654,
    SPELL_SHOCKWAVE                         = 83445,
    SPELL_SHOCKWAVE_VISUAL                  = 83130,
    SPELL_SUMMON_SHOCKWAVE_TARGET_N         = 83131,
    SPELL_SUMMON_SHOCKWAVE_TARGET_S         = 83132,
    SPELL_SUMMON_SHOCKWAVE_TARGET_E         = 83133,
    SPELL_SUMMON_SHOCKWAVE_TARGET_W         = 83134,
    SPELL_MYSTIC_TRAP                       = 83644,
    SPELL_THROW_LAND_MINES                  = 83122,
    SPELL_DETONE_TRAPS                      = 91263,
    SPELL_BAD_INTENTIONS                    = 83113,
    SPELL_HURL                              = 83236,
    SPELL_THROW_VISUAL                      = 83371,

    // Shockwave Stalker
    SPELL_SHOCKWAVE_SUMMON_EFFECT           = 83128,

    // Tol'Vir Land Mine
    SPELL_TOLVIR_LAND_MINE_VISUAL           = 83110,
    SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER   = 83111,
    SPELL_LAND_MINE_PLAYER_SEARCH_EFFECT    = 83112,
    SPELL_LAND_MINE_PERIODIC                = 85523,
    SPELL_MYSTIC_TRAP_DAMAGE                = 83171
};

enum Events
{
    // General Husam
    EVENT_HAMMER_FIST = 1,
    EVENT_SHOCKWAVE,
    EVENT_MYSTIC_TRAP,
    EVENT_DETONATE_TRAPS,
    EVENT_BAD_INTENTIONS,
    EVENT_THROW_PLAYER,

    // Tol'Vir Land Mine
    EVENT_READY_MINE,
    EVENT_START_COUNTDOWN,
    EVENT_CLEAR_AURAS
};

enum Actions
{
    ACTION_DETONATE_MINE = 1
};

enum Texts
{
    SAY_AGGRO               = 0,
    SAY_SLAY                = 1,
    SAY_SHOCKWAVE           = 2,
    SAY_ANNOUNCE_SHOCKWAVE  = 3,
    SAY_DETONATE_MINES      = 4,
    SAY_DEATH               = 5
};

enum Seats
{
    SEAT_PLAYER = 0
};

class boss_general_husam : public CreatureScript
{
public:
    boss_general_husam() : CreatureScript("boss_general_husam") { }

    struct boss_general_husamAI : public BossAI
    {
        boss_general_husamAI(Creature* creature) : BossAI(creature, DATA_GENERAL_HUSAM) { }

        void Reset() override
        {
            _Reset();
            _shockwaveStalkerCount = 0;
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            Talk(SAY_AGGRO);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            events.ScheduleEvent(EVENT_HAMMER_FIST, Seconds(10));
            events.ScheduleEvent(EVENT_SHOCKWAVE, Seconds(18));
            events.ScheduleEvent(EVENT_MYSTIC_TRAP, Seconds(7) + Milliseconds(500));
            events.ScheduleEvent(EVENT_BAD_INTENTIONS, Seconds(13));
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(SAY_DEATH);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            _EnterEvadeMode();
            summons.DespawnAll();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _DespawnAtEvade();
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);

            if (summon->GetEntry() == NPC_SHOCKWAVE_STALKER)
            {
                _shockwaveStalkerCount++;
                float x = summon->GetPositionX();
                float y = summon->GetPositionY();
                float z = summon->GetPositionZ();
                float orientation = summon->GetAngle(me->GetPosition()) + float(M_PI);
                summon->SetSpeed(MOVE_FLIGHT, 4.5f);
                summon->GetMotionMaster()->MovePoint(0, x + cos(orientation) * 300, y + sin(orientation) * 300, z, false);

                if (_shockwaveStalkerCount == 4)
                {
                    DoCastSelf(SPELL_SHOCKWAVE);
                    _shockwaveStalkerCount = 0;
                }
            }
        }

        void PassengerBoarded(Unit* /*who*/, int8 seatId, bool apply) override
        {
            if (!me->GetVehicleKit())
                return;

            if (apply && seatId == SEAT_PLAYER)
            {
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_THROW_PLAYER, Seconds(1));
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
                    case EVENT_HAMMER_FIST:
                        DoCastSelf(SPELL_HAMMER_FIST, true);
                        events.Repeat(Seconds(20));
                        break;
                    case EVENT_SHOCKWAVE:
                        Talk(SAY_ANNOUNCE_SHOCKWAVE);
                        Talk(SAY_SHOCKWAVE);
                        DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_N, true);
                        DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_S, true);
                        DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_E, true);
                        DoCastSelf(SPELL_SUMMON_SHOCKWAVE_TARGET_W, true);
                        events.Repeat(Seconds(39));
                        if (IsHeroic())
                            events.ScheduleEvent(EVENT_DETONATE_TRAPS, Seconds(6));
                        break;
                    case EVENT_MYSTIC_TRAP:
                        DoCastSelf(SPELL_MYSTIC_TRAP, true);
                        events.Repeat(Seconds(16) + Milliseconds(500));
                        break;
                    case EVENT_DETONATE_TRAPS:
                        Talk(SAY_DETONATE_MINES);
                        DoCastSelf(SPELL_DETONE_TRAPS);
                        break;
                    case EVENT_BAD_INTENTIONS:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                            DoCast(target, SPELL_BAD_INTENTIONS);
                        events.Repeat(Seconds(25));
                        break;
                    case EVENT_THROW_PLAYER:
                        DoCastSelf(SPELL_HURL, true);
                        DoCastSelf(SPELL_THROW_VISUAL, true);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    default:
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        uint8 _shockwaveStalkerCount;
    };

    CreatureAI* GetAI(Creature *creature) const override
    {
        return GetLostCityOfTheTolvirAI<boss_general_husamAI>(creature);
    }
};

class npc_husam_tolvir_land_mine : public CreatureScript
{
public:
    npc_husam_tolvir_land_mine() : CreatureScript("npc_husam_tolvir_land_mine") { }

    struct npc_husam_tolvir_land_mineAI : public ScriptedAI
    {
        npc_husam_tolvir_land_mineAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            if (Creature* husam = _instance->GetCreature(DATA_GENERAL_HUSAM))
                husam->AI()->JustSummoned(me);

            _events.ScheduleEvent(EVENT_READY_MINE, Seconds(2));
        }

        void SpellHitTarget(Unit* target, SpellInfo const* spell) override
        {
            if (spell->Id == SPELL_LAND_MINE_PLAYER_SEARCH_EFFECT && target->GetTypeId() == TYPEID_PLAYER && !target->GetVehicle())
            {
                DoCastSelf(SPELL_MYSTIC_TRAP_DAMAGE, true);
                me->RemoveAurasDueToSpell(SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER);
                me->RemoveAurasDueToSpell(SPELL_TOLVIR_LAND_MINE_VISUAL);
                me->RemoveAurasDueToSpell(SPELL_LAND_MINE_PERIODIC);
                me->DespawnOrUnsummon(3000);
            }
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_DETONATE_MINE)
            {
                _events.CancelEvent(EVENT_START_COUNTDOWN);
                _events.ScheduleEvent(EVENT_START_COUNTDOWN, 1);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_READY_MINE:
                        DoCastSelf(SPELL_TOLVIR_LAND_MINE_VISUAL, true);
                        DoCastSelf(SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER, true);
                        _events.ScheduleEvent(EVENT_START_COUNTDOWN, Seconds(20));
                        break;
                    case EVENT_START_COUNTDOWN:
                        DoCastSelf(SPELL_LAND_MINE_PERIODIC, true);
                        _events.ScheduleEvent(EVENT_CLEAR_AURAS, Seconds(5));
                        break;
                    case EVENT_CLEAR_AURAS:
                        me->RemoveAurasDueToSpell(SPELL_TOLVIR_LAND_MINE_VISUAL);
                        me->RemoveAurasDueToSpell(SPELL_LAND_MINE_PLAYER_SEARCH_TRIGGER);
                        me->DespawnOrUnsummon(3000);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_husam_tolvir_land_mineAI>(creature);
    }
};

class npc_husam_tolvir_land_mine_trigger : public CreatureScript
{
public:
    npc_husam_tolvir_land_mine_trigger() : CreatureScript("npc_husam_tolvir_land_mine_trigger") { }

    struct npc_husam_tolvir_land_mine_triggerAI : public ScriptedAI
    {
        npc_husam_tolvir_land_mine_triggerAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (Creature* husam = _instance->GetCreature(DATA_GENERAL_HUSAM))
                husam->CastSpell(me, SPELL_THROW_LAND_MINES, true);
        }

    private:
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_husam_tolvir_land_mine_triggerAI>(creature);
    }
};

class npc_husam_tolvir_land_mine_vehicle : public CreatureScript
{
public:
    npc_husam_tolvir_land_mine_vehicle() : CreatureScript("npc_husam_tolvir_land_mine_vehicle") { }

    struct npc_husam_tolvir_land_mine_vehicleAI : public ScriptedAI
    {
        npc_husam_tolvir_land_mine_vehicleAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (Creature* mine = me->SummonCreature(NPC_TOLVIR_LAND_MINE, me->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 30000))
                mine->CastSpell(me, VEHICLE_SPELL_RIDE_HARDCODED, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetLostCityOfTheTolvirAI<npc_husam_tolvir_land_mine_vehicleAI>(creature);
    }
};

class spell_husam_hammer_fist : public SpellScriptLoader
{
public:
    spell_husam_hammer_fist() : SpellScriptLoader("spell_husam_hammer_fist") { }

    class spell_husam_hammer_fist_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_husam_hammer_fist_AuraScript);

        void HandleTick(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            if (Unit* caster = GetCaster())
                if (caster->GetVictim())
                    caster->CastSpell(GetCaster()->GetVictim(), GetSpellInfo()->Effects[EFFECT_0].TriggerSpell, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_husam_hammer_fist_AuraScript::HandleTick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_husam_hammer_fist_AuraScript();
    }
};

class spell_husam_shockwave : public SpellScriptLoader
{
public:
    spell_husam_shockwave() : SpellScriptLoader("spell_husam_shockwave") { }

    class spell_husam_shockwave_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_husam_shockwave_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHOCKWAVE_VISUAL });
        }

        void EffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_SHOCKWAVE_VISUAL, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_husam_shockwave_SpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_husam_shockwave_SpellScript();
    }
};

class spell_husam_shockwave_summon_search : public SpellScriptLoader
{
public:
    spell_husam_shockwave_summon_search() : SpellScriptLoader("spell_husam_shockwave_summon_search") { }

    class spell_husam_shockwave_summon_search_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_husam_shockwave_summon_search_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHOCKWAVE_SUMMON_EFFECT });
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                GetCaster()->CastSpell(GetCaster(), SPELL_SHOCKWAVE_SUMMON_EFFECT, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_husam_shockwave_summon_search_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_husam_shockwave_summon_search_SpellScript();
    }
};

class spell_husam_mystic_trap : public SpellScriptLoader
{
public:
    spell_husam_mystic_trap() : SpellScriptLoader("spell_husam_mystic_trap") { }

    class spell_husam_mystic_trap_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_husam_mystic_trap_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            Trinity::Containers::RandomResize(targets, 3);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_husam_mystic_trap_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_husam_mystic_trap_SpellScript();
    }
};

class spell_husam_detonate_traps : public SpellScriptLoader
{
public:
    spell_husam_detonate_traps() : SpellScriptLoader("spell_husam_detonate_traps") { }

    class spell_husam_detonate_traps_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_husam_detonate_traps_SpellScript);

        void EffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Creature* target = GetHitCreature())
                target->AI()->DoAction(ACTION_DETONATE_MINE);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_husam_detonate_traps_SpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_husam_detonate_traps_SpellScript();
    }
};

class spell_husam_bad_intentions : public SpellScriptLoader
{
public:
    spell_husam_bad_intentions() : SpellScriptLoader("spell_husam_bad_intentions") { }

    class spell_husam_bad_intentions_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_husam_bad_intentions_SpellScript);

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastStop();
            GetHitUnit()->CastSpell(GetCaster(), GetSpellInfo()->Effects[EFFECT_1].BasePoints, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_husam_bad_intentions_SpellScript::HandleScriptEffect, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_husam_bad_intentions_SpellScript();
    }
};

class spell_husam_hurl : public SpellScriptLoader
{
public:
    spell_husam_hurl() : SpellScriptLoader("spell_husam_hurl") { }

    class spell_husam_hurl_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_husam_hurl_SpellScript);

        void EffectScriptEffect(SpellEffIndex /*effIndex*/)
        {
            if (Vehicle* vehicle = GetCaster()->GetVehicleKit())
            {
                if (Unit* passenger = vehicle->GetPassenger(SEAT_PLAYER))
                {
                    passenger->ExitVehicle();
                    if (Creature* intentionsTarget = GetCaster()->FindNearestCreature(NPC_BAD_INTENTIONS_TARGET, 100.0f, true))
                        passenger->CastSpell(intentionsTarget, GetSpellInfo()->Effects[EFFECT_0].BasePoints, true);
                }
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_husam_hurl_SpellScript::EffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_husam_hurl_SpellScript();
    }
};

void AddSC_boss_general_husam()
{
    new boss_general_husam();
    new npc_husam_tolvir_land_mine();
    new npc_husam_tolvir_land_mine_trigger();
    new npc_husam_tolvir_land_mine_vehicle();
    new spell_husam_hammer_fist();
    new spell_husam_shockwave();
    new spell_husam_shockwave_summon_search();
    new spell_husam_mystic_trap();
    new spell_husam_detonate_traps();
    new spell_husam_bad_intentions();
    new spell_husam_hurl();
}
