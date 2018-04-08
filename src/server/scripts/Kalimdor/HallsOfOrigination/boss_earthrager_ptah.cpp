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

// To-do:
// - Script "Sand Vortex", heroic mode ability.

#include "halls_of_origination.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "Weather.h"

enum Texts
{
    SAY_DEATH                       = 0,
    SAY_AGGRO                       = 1,
    SAY_PLAYER_KILL                 = 2,
    SAY_SPECIAL                     = 3
};

enum Events
{
    // Earthrager Ptah
    EVENT_RAGING_SMASH = 1,
    EVENT_FLAME_BOLT,
    EVENT_EARTH_SPIKE,
    EVENT_PTAH_EXPLODE,
    EVENT_QUICKSAND,

    // Beetle Stalker
    EVENT_SUMMON_JEWELED_SCARAB
};

enum Spells
{
    // Fight
    SPELL_RAGING_SMASH              = 83650,
    SPELL_FLAME_BOLT                = 77370,
    SPELL_EARTH_SPIKE_WARN          = 94974,

    // Disperse
    SPELL_SANDSTORM                 = 75491,
//  SPELL_TUMULTUOUS_EARTHSTORM     = 75517, // Server-side spell
    SPELL_PTAH_EXPLOSION            = 75519,
    SPELL_SUMMON_QUICKSAND          = 75550, // Server-side spell + hidden client-side flag!

    // Beetle Stalker
    SPELL_BEETLE_BURROW             = 75463, // Visual
    SPELL_SUMMON_JEWELED_SCARAB     = 75462,
    SPELL_SUMMON_DUSTBONE_HORROR    = 75521
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
            _summonsMaxCount = 0;
            _summonsDeadCount = 0;
        }

        void Reset() override
        {
            Initialize();
            Cleanup();
            _Reset();
            events.SetPhase(PHASE_FIGHT);
            ScheduleEvents();
        }

        void DoAction(int32 action) override
        {
            if (action != ACTION_PTAH_ADD_DIED)
                return;

            // Increase _summonsDeadCount and check if max reached.
            if (++_summonsDeadCount == _summonsMaxCount)
                ExitDispersePhase();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            Talk(SAY_AGGRO);
            _JustEngagedWith();
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
            Cleanup();
        }

        void JustReachedHome() override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustReachedHome();
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
                        break;
                    case EVENT_QUICKSAND:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_SUMMON_QUICKSAND);
                        events.Repeat(Seconds(21)); //Seconds(10)
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            if (!events.IsInPhase(PHASE_EARTHSTORM)) // Do not melee in the disperse phase
                DoMeleeAttackIfReady();
        }

    private:
        void ScheduleEvents()
        {
            events.Reset();
            events.ScheduleEvent(EVENT_RAGING_SMASH, Seconds(7), 0, PHASE_FIGHT); // Seconds(12)
            events.ScheduleEvent(EVENT_FLAME_BOLT, Seconds(8), 0, PHASE_FIGHT);
            events.ScheduleEvent(EVENT_EARTH_SPIKE, Seconds(15), 0, PHASE_FIGHT); // Seconds(21)
        }

        void EnterDispersePhase()
        {
            events.SetPhase(PHASE_EARTHSTORM);
            _hasDispersed = true;

            me->SetReactState(REACT_PASSIVE);
            me->InterruptNonMeleeSpells(true);
            me->AttackStop();
            me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_LIGHT_SANDSTORM, 1.0f);
            DoCast(me, SPELL_SANDSTORM);

            std::list<Creature*> stalkers;
            GetCreatureListWithEntryInGrid(stalkers, me, NPC_BEETLE_STALKER, 100.0f);
            for (std::list<Creature*>::iterator itr = stalkers.begin(); itr != stalkers.end(); ++itr)
            {
                ++_summonsMaxCount;
                if (-400.f < (*itr)->GetPositionY() && (*itr)->GetPositionY() < -390.f) // 2 stalkers in the middle
                    (*itr)->CastSpell((*itr), SPELL_SUMMON_DUSTBONE_HORROR);
                else
                    (*itr)->CastSpell((*itr), SPELL_BEETLE_BURROW);
            }
            
            events.ScheduleEvent(EVENT_PTAH_EXPLODE, Seconds(6), 0, PHASE_EARTHSTORM);
            events.ScheduleEvent(EVENT_QUICKSAND, Seconds(10), 0, PHASE_EARTHSTORM);
        }
        
        void ExitDispersePhase()
        {
            me->RemoveAurasDueToSpell(SPELL_PTAH_EXPLOSION);
            me->GetMap()->SetZoneWeather(AREA_TOMB_OF_THE_EARTHRAGER, WEATHER_STATE_FOG, 0.0f);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 2);
            events.SetPhase(PHASE_FIGHT);
            ScheduleEvents();
        }

        void Cleanup()
        {
            std::list<Creature*> units;

            GetCreatureListWithEntryInGrid(units, me, NPC_BEETLE_STALKER, 100.0f);
            for (std::list<Creature*>::iterator itr = units.begin(); itr != units.end(); ++itr)
            {
                ++_summonsMaxCount;
                if (-400.f < (*itr)->GetPositionY() && (*itr)->GetPositionY() < -390.f) // 2 stalkers in the middle
                    (*itr)->RemoveAurasDueToSpell(SPELL_SUMMON_DUSTBONE_HORROR);
                else
                    (*itr)->RemoveAurasDueToSpell(SPELL_BEETLE_BURROW);
            }

            units.clear();
            GetCreatureListWithEntryInGrid(units, me, NPC_DUSTBONE_HORROR, 100.0f);
            for (std::list<Creature*>::iterator itr = units.begin(); itr != units.end(); ++itr)
                (*itr)->DespawnOrUnsummon();

            units.clear();
            GetCreatureListWithEntryInGrid(units, me, NPC_JEWELED_SCARAB, 100.0f);
            for (std::list<Creature*>::iterator itr = units.begin(); itr != units.end(); ++itr)
                (*itr)->DespawnOrUnsummon();
        }

        bool _hasDispersed;
        uint8 _summonsMaxCount;
        uint8 _summonsDeadCount;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<boss_earthrager_ptahAI>(creature);
    }
};

// 15989 (criteria ID) Straw That Broke the Camel's Back
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

// 40459 Beetle Stalker
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
                events.ScheduleEvent(EVENT_SUMMON_JEWELED_SCARAB, Seconds(5), Seconds(6));
        }

        void UpdateAI(uint32 diff) override
        {
            if (events.Empty())
                return;

            events.Update(diff);

            if (events.ExecuteEvent() == EVENT_SUMMON_JEWELED_SCARAB)
            {
                DoCastAOE(SPELL_SUMMON_JEWELED_SCARAB);
                me->RemoveAurasDueToSpell(SPELL_BEETLE_BURROW);
            }
                
        }

    private:
        EventMap events;

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_ptah_beetle_stalkerAI>(creature);
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

// 75491 Sandstorm spell_earthrager_ptah_sandstorm
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

void AddSC_boss_earthrager_ptah()
{
    new boss_earthrager_ptah();
    new achievement_straw_broke_camels_back();
    new npc_ptah_beetle_stalker();
    new spell_earthrager_ptah_flame_bolt();
    new spell_earthrager_ptah_sandstorm();
    new spell_earthrager_ptah_explosion();
}
