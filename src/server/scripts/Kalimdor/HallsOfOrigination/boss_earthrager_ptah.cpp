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

#include "halls_of_origination.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "Unit.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "PassiveAI.h"
#include "GridNotifiers.h"
#include "MoveSplineInit.h"
#include "MoveSpline.h"
#include "Weather.h"

enum Texts
{
    SAY_DEATH       = 0,
    SAY_AGGRO       = 1,
    SAY_PLAYER_KILL = 2,
    SAY_SPECIAL     = 3
};

enum Events
{
    // Earthrager Ptah
    EVENT_RAGING_SMASH = 1,
    EVENT_FLAME_BOLT,
    EVENT_EARTH_SPIKE,
    EVENT_PTAH_EXPLODE,
    EVENT_TUMULTUOUS_SAND_STORM,
    EVENT_QUICKSAND,

    // Beetle Stalker
    EVENT_SUMMON_JEWELED_SCARAB,

    // Tumultuous Earthstorm
    EVENT_START_MOVEMENT
};

enum Spells
{
    // Fight
    SPELL_RAGING_SMASH              = 83650,
    SPELL_FLAME_BOLT                = 77370,
    SPELL_EARTH_SPIKE_WARN          = 94974,

    // Disperse
    SPELL_SANDSTORM                 = 75491,
    SPELL_TUMULTUOUS_EARTHSTORM     = 75517, // Server-side spell
    SPELL_PTAH_EXPLOSION            = 75519,
    SPELL_SUMMON_QUICKSAND          = 75550,  // Server-side spell + hidden client-side flag!

    // Tumultuous Earthstorm
    SPELL_CONSUME                   = 89633,
    SPELL_CONSUME_DAMAGE            = 75369
};

enum Phases
{
    PHASE_FIGHT                     = 1,
    PHASE_EARTHSTORM                = 2
};

enum Sounds
{
    SOUND_PTAH_EARTHQUAKE           = 18908
};

enum Data
{
    DATA_LAST_CONSUME_TARGET = 0
};

// 39428 Earthrager Ptah
class boss_earthrager_ptah : public CreatureScript
{
    public:
        boss_earthrager_ptah() : CreatureScript("boss_earthrager_ptah") { }

        struct boss_earthrager_ptahAI : public BossAI
        {
            boss_earthrager_ptahAI(Creature* creature) : BossAI(creature, DATA_EARTHRAGER_PTAH)
            { 
                Initialize();
            }

            void Initialize()
            {
                _hasDispersed = false;
                _summonCount = 0;
                _summonsDeadCount = 0;
            }

            void Reset() override
            {
                Initialize();
                _Reset();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                Talk(SAY_AGGRO);
                _JustEngagedWith();
                events.SetPhase(PHASE_FIGHT);
                events.ScheduleEvent(EVENT_RAGING_SMASH, Seconds(7), 0, PHASE_FIGHT); // Seconds(12)
                events.ScheduleEvent(EVENT_FLAME_BOLT, Seconds(8), 0, PHASE_FIGHT);
                events.ScheduleEvent(EVENT_EARTH_SPIKE, Seconds(15), 0, PHASE_FIGHT); // Seconds(21)
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_PLAYER_KILL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                Talk(SAY_DEATH);
                _JustDied();
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                summons.DespawnAll();
                me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_FOG, 0.0f);
                _EnterEvadeMode();
                _DespawnAtEvade();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                // About to die? One-hit cases...
                if (int64(me->GetHealth()) - int64(damage) <= 0)
                    return;

                // Earthquake phase happens at 50% health remaining.
                if (me->HealthBelowPctDamaged(50, damage) && !_hasDispersed)
                    EnterDispersePhase();
            }

            void DoAction(int32 action) override
            {
                if (action != ACTION_PTAH_ADD_DIED)
                    return;

                _summonsDeadCount++;
                if (_summonsDeadCount == _summonCount)
                    ExitDispersePhase();
            }

            void JustSummoned(Creature* summon) override
            {
                switch (summon->GetEntry())
                {
                    case NPC_DUSTBONE_HORROR:
                    case NPC_JEWELED_SCARAB:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->SetInCombatWithZone();
                        _addGUIDs.push_back(summon->GetGUID());
                        _summonCount++;
                        break;
                    default:
                        break;
                }
                summons.Summon(summon);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RAGING_SMASH:
                            DoCastVictim(SPELL_RAGING_SMASH);
                            events.Repeat(Seconds(19));
                            break;
                        case EVENT_FLAME_BOLT:
                            DoCast(me, SPELL_FLAME_BOLT);
                            events.Repeat(Seconds(21));
                            break;
                        case EVENT_EARTH_SPIKE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_EARTH_SPIKE_WARN);
                            events.Repeat(Seconds(15));
                            break;
                        case EVENT_PTAH_EXPLODE:
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 0);
                            Talk(SAY_SPECIAL);
                            DoCast(me, SPELL_PTAH_EXPLOSION);

                            for (ObjectGuid guid : _addGUIDs)
                            {
                                if (Creature* add = ObjectAccessor::GetCreature(*me, guid))
                                {
                                    add->SetReactState(REACT_AGGRESSIVE);
                                    if (add->IsAIEnabled)
                                        add->AI()->DoZoneInCombat();
                                }
                            }

                            if (IsHeroic())
                                events.ScheduleEvent(EVENT_TUMULTUOUS_SAND_STORM, Seconds(2) + Milliseconds(500), 0, PHASE_EARTHSTORM);
                            break;
                        case EVENT_QUICKSAND:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_SUMMON_QUICKSAND, true);
                            events.Repeat(Seconds(21)); //Seconds(10)
                            break;
                        case EVENT_TUMULTUOUS_SAND_STORM:
                            DoCastSelf(SPELL_TUMULTUOUS_EARTHSTORM, true);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void EnterDispersePhase()
            {
                _hasDispersed = true;

                me->SetReactState(REACT_PASSIVE);
                me->CastStop();
                me->AttackStop();
                me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_LIGHT_SANDSTORM, 1.0f);
                DoCast(me, SPELL_SANDSTORM);
                instance->SetData(DATA_SUMMON_SANDSTORM_ADDS, IN_PROGRESS);

                events.SetPhase(PHASE_EARTHSTORM);
                events.ScheduleEvent(EVENT_PTAH_EXPLODE, Seconds(6), 0, PHASE_EARTHSTORM);
                events.ScheduleEvent(EVENT_QUICKSAND, Seconds(10), 0, PHASE_EARTHSTORM);
            }
        
            void ExitDispersePhase()
            {
                me->RemoveAurasDueToSpell(SPELL_PTAH_EXPLOSION);
                me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_FOG, 0.0f);
                me->SetReactState(REACT_AGGRESSIVE);

                instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 2);
                events.SetPhase(PHASE_FIGHT);
                events.ScheduleEvent(EVENT_RAGING_SMASH, Seconds(7), 0, PHASE_FIGHT); // Seconds(12)
                events.ScheduleEvent(EVENT_FLAME_BOLT, Seconds(8), 0, PHASE_FIGHT);
                events.ScheduleEvent(EVENT_EARTH_SPIKE, Seconds(15), 0, PHASE_FIGHT); // Seconds(21)
            }

            bool _hasDispersed;
            uint8 _summonCount;
            uint8 _summonsDeadCount;
            GuidVector _addGUIDs;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfOriginationAI<boss_earthrager_ptahAI>(creature);
        }
};

class npc_ptah_beetle_stalker : public CreatureScript
{
    public:
        npc_ptah_beetle_stalker() : CreatureScript("npc_ptah_beetle_stalker") { }

        struct npc_ptah_beetle_stalkerAI : public ScriptedAI
        {
            npc_ptah_beetle_stalkerAI(Creature* creature) : ScriptedAI(creature) { }

            void SpellHit(Unit* /*caster*/, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id == SPELL_BEETLE_BURROW)
                    _events.ScheduleEvent(EVENT_SUMMON_JEWELED_SCARAB, Seconds(5), Seconds(6));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_JEWELED_SCARAB:
                            if (me->HasAura(SPELL_BEETLE_BURROW))
                            {
                                DoCastAOE(SPELL_SUMMON_JEWELED_SCARAB);
                                me->RemoveAurasDueToSpell(SPELL_BEETLE_BURROW);
                            }
                            break;
                        default:
                            break;
                    }
                }        
            }
        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfOriginationAI<npc_ptah_beetle_stalkerAI>(creature);
        }
};

class npc_ptah_tumultuous_earthstorm : public CreatureScript
{
    public:
        npc_ptah_tumultuous_earthstorm() : CreatureScript("npc_ptah_tumultuous_earthstorm") { }

        struct npc_ptah_tumultuous_earthstormAI : public PassiveAI
        {
            npc_ptah_tumultuous_earthstormAI(Creature* creature) : PassiveAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _guid = ObjectGuid::Empty;
            }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                _events.ScheduleEvent(EVENT_START_MOVEMENT, Seconds(3) + Milliseconds(600));
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger && apply)
                    return;

                _guid = passenger->GetGUID();
            }

            ObjectGuid GetGUID(int32 type) const override
            {
                return (type == DATA_LAST_CONSUME_TARGET ? _guid : ObjectGuid::Empty);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_MOVEMENT:
                            DoCastSelf(SPELL_CONSUME, true);
                            me->GetMotionMaster()->MoveRandom(30.0f);
                            break;
                        default:
                            break;
                    }
                }
                
            }
        private:
            EventMap _events;
            ObjectGuid _guid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfOriginationAI<npc_ptah_tumultuous_earthstormAI>(creature);
        }
};

class spell_earthrager_ptah_flame_bolt : public SpellScriptLoader
{
    public:
        spell_earthrager_ptah_flame_bolt() : SpellScriptLoader("spell_earthrager_ptah_flame_bolt") { }

        class spell_earthrager_ptah_flame_bolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_earthrager_ptah_flame_bolt_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->IsHeroic() ? 3 : 2);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_earthrager_ptah_flame_bolt_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_earthrager_ptah_flame_bolt_SpellScript();
        }
};

class spell_earthrager_ptah_sandstorm : public SpellScriptLoader
{
    public:
        spell_earthrager_ptah_sandstorm() : SpellScriptLoader("spell_earthrager_ptah_sandstorm") { }

        class spell_earthrager_ptah_sandstorm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_earthrager_ptah_sandstorm_SpellScript);

            void PlaySound(SpellEffIndex /*effIndex*/)
            {
                if (Player* player = GetHitUnit()->ToPlayer())
                    GetCaster()->PlayDirectSound(SOUND_PTAH_EARTHQUAKE, player);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_earthrager_ptah_sandstorm_SpellScript::PlaySound, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_earthrager_ptah_sandstorm_SpellScript();
        }
};

class spell_earthrager_ptah_explosion : public SpellScriptLoader
{
    public:
        spell_earthrager_ptah_explosion() : SpellScriptLoader("spell_earthrager_ptah_explosion") { }

        class spell_earthrager_ptah_explosion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_earthrager_ptah_explosion_AuraScript);

            void SetFlags(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* ptah = GetCaster())
                {
                    ptah->SetFlag(UNIT_FIELD_FLAGS, uint32(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_29 | UNIT_FLAG_UNK_31));
                    ptah->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                }
            }

            void RemoveFlags(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* ptah = GetCaster())
                {
                    ptah->RemoveFlag(UNIT_FIELD_FLAGS, uint32(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_UNK_29 | UNIT_FLAG_UNK_31));
                    ptah->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH);
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_earthrager_ptah_explosion_AuraScript::SetFlags, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_earthrager_ptah_explosion_AuraScript::RemoveFlags, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_earthrager_ptah_explosion_AuraScript();
        }
};

class ConsumeEntryCheck
{
    public:
        ConsumeEntryCheck() { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return target->movespline->isParabolic() || target->HasAura(SPELL_CONSUME_DAMAGE);

            return false;
        }
};

class ConsumeKnockbackCheck
{
    public:
        ConsumeKnockbackCheck(Unit* caster) : _caster(caster) { }

        bool operator()(WorldObject* object)
        {
            Unit* target = object->ToUnit();
            if (!target)
                return true;

            Creature* caster = _caster->ToCreature();
            if (!caster)
                return true;

            if (caster->IsAIEnabled && target->GetTypeId() == TYPEID_PLAYER)
            {
                ObjectGuid guid = caster->AI()->GetGUID(DATA_LAST_CONSUME_TARGET);
                return target->GetGUID() != guid;
            }

            return false;
        }
    private:
        Unit * _caster;

};

class spell_earthrager_ptah_consume: public SpellScriptLoader
{
    public:
        spell_earthrager_ptah_consume() : SpellScriptLoader("spell_earthrager_ptah_consume") { }

        class spell_earthrager_ptah_consume_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_earthrager_ptah_consume_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(ConsumeEntryCheck());
            }

            void FilterTargetsKnockback(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                targets.remove_if(ConsumeKnockbackCheck(GetCaster()));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_earthrager_ptah_consume_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_earthrager_ptah_consume_SpellScript::FilterTargetsKnockback, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_earthrager_ptah_consume_SpellScript();
        }
};

class achievement_straw_broke_camels_back : public AchievementCriteriaScript
{
    public:
        achievement_straw_broke_camels_back() : AchievementCriteriaScript("achievement_straw_broke_camels_back") { }

        bool OnCheck(Player* player, Unit* /*target*/) override
        {
            if (Unit* vehicle = player->GetVehicleBase())
                return vehicle->GetEntry() == NPC_HOO_CAMEL;

            return false;
        }
};

void AddSC_boss_earthrager_ptah()
{
    new boss_earthrager_ptah();
    new npc_ptah_beetle_stalker();
    new npc_ptah_tumultuous_earthstorm();
    new spell_earthrager_ptah_flame_bolt();
    new spell_earthrager_ptah_sandstorm();
    new spell_earthrager_ptah_explosion();
    new spell_earthrager_ptah_consume();
    new achievement_straw_broke_camels_back();
}
