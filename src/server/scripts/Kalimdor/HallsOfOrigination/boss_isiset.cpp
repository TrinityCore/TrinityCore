/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "ObjectAccessor.h"
#include "GridNotifiers.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "halls_of_origination.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_SUPERNOVA                         = 74136,
    SPELL_SUPERNOVA_EFFECT                  = 74137,

    // Startfall / Astral Rain ability
    SPELL_ASTRAL_RAIN_CONTROLLER            = 74381,
    SPELL_ASTRAL_RAIN_1                     = 74134,
    SPELL_ASTRAL_RAIN_2                     = 74365,
    SPELL_ASTRAL_RAIN_3                     = 74371,

    // Adds / Celestial Call ability
    SPELL_ASTRAL_FAMILIAR_CONTROLLER        = 74383,
    SPELL_CELESTIAL_CALL_1                  = 74362,
    SPELL_CELESTIAL_CALL_2                  = 74355,
    SPELL_CELESTIAL_CALL_3                  = 74364,

    // Mana shield / Veil of Sky ability
    SPELL_MANA_SHIELD_CONTROLLER            = 74382,
    SPELL_VEIL_OF_SKY_1                     = 74133,
    SPELL_VEIL_OF_SKY_2                     = 74372,
    SPELL_VEIL_OF_SKY_3                     = 74373,
    SPELL_VEIL_OF_SKY_DAMAGE                = 79370,

    // Mirror Images (at 66% and 33%)
    SPELL_MIRROR_IMAGE_STARRY_SKY_SPAWNER   = 69941,
    SPELL_MIRROR_IMAGE_STARRY_SKY_N         = 69936,
    SPELL_MIRROR_IMAGE_STARRY_SKY_E         = 69939,
    SPELL_MIRROR_IMAGE_STARRY_SKY_W         = 69940,
    SPELL_ASTRAL_SHIFT                      = 74312,
    SPELL_ASTRAL_SHIFT_EXPLOSION            = 74333,
    SPELL_MIRROR_IMAGE_SPAWNER              = 74264,
    SPELL_MIRROR_IMAGE_N                    = 74263,
    SPELL_MIRROR_IMAGE_E                    = 74262,
    SPELL_MIRROR_IMAGE_W                    = 74261,
    SPELL_ADDS_STATE_VISUAL                 = 74289,
    SPELL_STARFALL_STATE_VISUAL             = 74265,
    SPELL_MANA_SHIELD_STATE_VISUAL          = 74266,
    SPELL_IMAGE_EXPLOSION                   = 74301,

    // Celestial Familiar npc
    SPELL_ORB_VISUAL                        = 74356, 
    SPELL_ARCANE_BARRAGE                    = 74374,

    // Starry Sky npc
    SPELL_STARRY_SKY_VISUAL                 = 74149,

    // Astral Shift Explosion Visual npc
    SPELL_ASTRAL_SHIFT_EXPLOSION_VISUAL     = 74331,

    // Spatial Flux & Energy Flux (heroic only)
    SPELL_CALL_OF_SKY                       = 90750, // Summons Spatial Flux
    SPELL_SPAWN_ENERGY_FLUX_ISISET          = 90735, // Makes random player cast Summon Energy Flux
    SPELL_ENERGY_FLUX_BEAM_ISISET           = 90741, // Makes nearby Spatial Flux cast visual beam
    SPELL_ENERGY_FLUX_PERIODIC              = 74044,
};

enum NPCs
{
    NPC_CELESTIAL_FAMILIAR                  = 39795,
    NPC_ASTRAL_RAIN                         = 39720, // N
    NPC_CELESTIAL_CALL                      = 39721, // E
    NPC_VEIL_OF_SKY                         = 39722, // W
    NPC_ISISET_SPATIAL_FLUX                 = 48707, // heroic only
};

enum Texts
{
    SAY_AGGRO                               = 0,
    SAY_SUPERNOVA                           = 1,
    SAY_SUPERNOVA_WARNING                   = 2,
    SAY_PLAYER_KILL                         = 3,
    SAY_DEATH                               = 4,
};

enum Events
{
    EVENT_NONE,
    EVENT_SUPERNOVA,
    EVENT_ASTRAL_RAIN,
    EVENT_ASTRAL_FAMILIAR,
    EVENT_VEIL_OF_SKY,
    EVENT_IMAGES_ATTACK,
    EVENT_DESPAWN_IMAGES,

    EVENT_ORB_ADD_VISUAL,
    EVENT_ORB_SET_AGGRESSIVE,
    EVENT_ORB_ARCANE_BARRAGE,

    EVENT_IMAGE_ASTRAL_RAIN_ABILITY,
    EVENT_IMAGE_ARCANE_BARRAGE_ABILITY,
    EVENT_IMAGE_VEIL_OF_SKY_ABILITY,

    EVENT_STARRY_SKY_ADD_VISUAL,

    // Spatial Flux
    EVENT_DUMMY_NUKE,
    EVENT_SPAWN_ENERGY_FLUX,

    // Energy Flux
    EVENT_FOLLOW_SUMMONER,
};

enum Actions
{
    ACTION_NONE,
    ACTION_IMAGES_SET_AGGRESSIVE,
    ACTION_MIRROR_IMAGE_DIED,
    ACTION_IMAGES_SET_PASSIVE,
    ACTION_IMAGES_DESPAWN,
};

class boss_isiset : public CreatureScript
{
public:
    boss_isiset() : CreatureScript("boss_isiset") { }

    struct boss_isisetAI : public BossAI
    {
        boss_isisetAI(Creature* creature) : BossAI(creature, DATA_ISISET) { }

        void Reset() override
        {
            _Reset();

            me->SetReactState(REACT_AGGRESSIVE);

            transitionPhase = false;
            instance->SetData(DATA_ISISET_PHASE, 1);
            instance->SetData(DATA_ISISET_ASTRAL_RAIN_ALIVE, 1);
            instance->SetData(DATA_ISISET_CELESTIAL_CALL_ALIVE, 1);
            instance->SetData(DATA_ISISET_VEIL_OF_SKY_ALIVE, 1);
        }

        void EnterCombat(Unit* /*victim*/) override
        {
            Talk(SAY_AGGRO);
            if (IsHeroic())
                DoCastSelf(SPELL_CALL_OF_SKY);
            RescheduleEvents();
            _EnterCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT, 0);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (transitionPhase)
                return;

            // Second transition
            if (instance->GetData(DATA_ISISET_PHASE) == 2 && me->HealthBelowPctDamaged(33, damage))
                MirrorImage();

            // First transition
            if (instance->GetData(DATA_ISISET_PHASE) == 1 && me->HealthBelowPctDamaged(66, damage))
                MirrorImage();
        }

        void DoAction(int32 action) override
        {
            // We only accept action from the first dying image
            if (mirrorImageDied || action != ACTION_MIRROR_IMAGE_DIED)
                return;

            mirrorImageDied = true;
            
            // Handle despawning
            DummyEntryCheckPredicate pred;
            summons.DoAction(ACTION_IMAGES_SET_PASSIVE, pred);
            events.ScheduleEvent(EVENT_DESPAWN_IMAGES, 2400);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                Talk(SAY_PLAYER_KILL);
        }

        void JustDied(Unit* /*killer*/) override
        {
            //instance->SendEncounterUnit(ENCOUNTER_FRAME_SET_COMBAT_RES_LIMIT, ?me?, 1);
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me, 0);
            _JustDied();
            Talk(SAY_DEATH);
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
                    case EVENT_ASTRAL_RAIN:
                        DoCastSelf(SPELL_ASTRAL_RAIN_CONTROLLER);
                        events.Repeat(Seconds(15), Seconds(19));
                        break;
                    case EVENT_ASTRAL_FAMILIAR:
                        DoCastSelf(SPELL_ASTRAL_FAMILIAR_CONTROLLER);
                        events.Repeat(Seconds(26), Seconds(30));
                        break;
                    case EVENT_VEIL_OF_SKY:
                        DoCastSelf(SPELL_MANA_SHIELD_CONTROLLER);
                        events.Repeat(Seconds(20), Seconds(25));
                        break;
                    case EVENT_SUPERNOVA:
                        DoCastSelf(SPELL_SUPERNOVA);
                        Talk(SAY_SUPERNOVA);
                        Talk(SAY_SUPERNOVA_WARNING);
                        events.Repeat(Seconds(45), Seconds(50));
                        break;
                    case EVENT_IMAGES_ATTACK:
                    {
                        DummyEntryCheckPredicate pred;
                        summons.DoAction(ACTION_IMAGES_SET_AGGRESSIVE, pred);
                        break;
                    }
                    case EVENT_DESPAWN_IMAGES:
                    {
                        DummyEntryCheckPredicate pred;
                        summons.DoAction(ACTION_IMAGES_DESPAWN, pred);
                        instance->SetData(DATA_ISISET_PHASE, instance->GetData(DATA_ISISET_PHASE) + 1);
                        transitionPhase = false;
                        me->RemoveAurasDueToSpell(SPELL_ASTRAL_SHIFT);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 1);
                        RescheduleEvents();
                        break;
                    }
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        void RescheduleEvents()
        {
            events.Reset();
            if (instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE) == 1)
                events.ScheduleEvent(EVENT_ASTRAL_RAIN, Seconds(4), Seconds(6));
            if (instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE) == 1)
                events.ScheduleEvent(EVENT_ASTRAL_FAMILIAR, Seconds(7));
            if (instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE) == 1)
                events.ScheduleEvent(EVENT_VEIL_OF_SKY, Seconds(8), Seconds(10));
            events.ScheduleEvent(EVENT_SUPERNOVA, Seconds(12), Seconds(17));
        }

        // Mirror Image transition phase
        void MirrorImage()
        {
            transitionPhase = true;

            events.Reset();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_UPDATE_PRIORITY, me, 0);
            mirrorImageDied = false;

            DoCastSelf(SPELL_ASTRAL_SHIFT);
            DoCastSelf(SPELL_ASTRAL_SHIFT_EXPLOSION);
            DoCastSelf(SPELL_MIRROR_IMAGE_STARRY_SKY_SPAWNER);
            DoCastSelf(SPELL_MIRROR_IMAGE_SPAWNER);

            events.ScheduleEvent(EVENT_IMAGES_ATTACK, Seconds(2));
        }

        bool transitionPhase;
        bool mirrorImageDied;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<boss_isisetAI>(creature);
    }
};

// 39795 - Celestial Familiar
class npc_celestial_familiar : public CreatureScript
{
public:
    npc_celestial_familiar() : CreatureScript("npc_celestial_familiar") { }

    struct npc_celestial_familiarAI : public ScriptedAI
    {
        npc_celestial_familiarAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetInCombatWithZone();
            events.ScheduleEvent(EVENT_ORB_ADD_VISUAL, 1200);
            events.ScheduleEvent(EVENT_ORB_SET_AGGRESSIVE, 2400);
            events.ScheduleEvent(EVENT_ORB_ARCANE_BARRAGE, Seconds(urand(4,6)));
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
                    case EVENT_ORB_ADD_VISUAL:
                        DoCastSelf(SPELL_ORB_VISUAL);
                        break;
                    case EVENT_ORB_SET_AGGRESSIVE:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_ORB_ARCANE_BARRAGE:
                        DoCastSelf(SPELL_ARCANE_BARRAGE);
                        events.Repeat(Seconds(6), Seconds(7));
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_celestial_familiarAI>(creature);
    }
};

// 39787 - Astral Shift Explosion Visual
class npc_astral_shift_explosion_visual : public CreatureScript
{
public:
    npc_astral_shift_explosion_visual() : CreatureScript("npc_astral_shift_explosion_visual") { }

    struct npc_astral_shift_explosion_visualAI : public ScriptedAI
    {
        npc_astral_shift_explosion_visualAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCastSelf(SPELL_ASTRAL_SHIFT_EXPLOSION_VISUAL);
            me->DespawnOrUnsummon(21300);
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_astral_shift_explosion_visualAI>(creature);
    }
};

// 39681 - Starry Sky
class npc_starry_sky : public CreatureScript
{
public:
    npc_starry_sky() : CreatureScript("npc_starry_sky") { }

    struct npc_starry_skyAI : public ScriptedAI
    {
        npc_starry_skyAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            events.ScheduleEvent(EVENT_STARRY_SKY_ADD_VISUAL, 800); // Sniffed timers
            me->DespawnOrUnsummon(3600);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STARRY_SKY_ADD_VISUAL:
                        DoCastSelf(SPELL_STARRY_SKY_VISUAL);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_starry_skyAI>(creature);
    }
};

// 39720 - Astral Rain
// 39721 - Celestial Call
// 39722 - Veil of Sky
class npc_isiset_mirror_image : public CreatureScript
{
public:
    npc_isiset_mirror_image() : CreatureScript("npc_isiset_mirror_image") { }

    struct npc_isiset_mirror_imageAI : public ScriptedAI
    {
        npc_isiset_mirror_imageAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
        {
            me->SetReactState(REACT_PASSIVE);
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

            switch (me->GetEntry()) {
                case NPC_ASTRAL_RAIN:
                    _events.ScheduleEvent(EVENT_IMAGE_ASTRAL_RAIN_ABILITY, Seconds(3), Seconds(5));
                    DoCastSelf(SPELL_STARFALL_STATE_VISUAL);
                    break;
                case NPC_CELESTIAL_CALL:
                    _events.ScheduleEvent(EVENT_IMAGE_ARCANE_BARRAGE_ABILITY, Seconds(6));
                    DoCastSelf(SPELL_ADDS_STATE_VISUAL);
                    break;
                case NPC_VEIL_OF_SKY:
                    _events.ScheduleEvent(EVENT_IMAGE_VEIL_OF_SKY_ABILITY, Seconds(8), Seconds(9));
                    //DoCastSelf(SPELL_MANA_SHIELD_STATE_VISUAL); // Disabled in sniffs/on retail, too shiny. 
                    break;
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            // Because only one image explodes, others become passive
            if (me->GetReactState() != REACT_AGGRESSIVE || me->GetHealth() > damage)
                return;

            me->SetReactState(REACT_PASSIVE);
            damage = me->GetHealth() - 1;
            DoCastSelf(SPELL_IMAGE_EXPLOSION);
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_IMAGES_SET_AGGRESSIVE:
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetInCombatWithZone();
                    AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
                    break;
                case ACTION_IMAGES_SET_PASSIVE:
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    break;
                case ACTION_IMAGES_DESPAWN:
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    me->DespawnOrUnsummon();
                    break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            _events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_IMAGE_ASTRAL_RAIN_ABILITY:
                        DoCastSelf(SPELL_ASTRAL_RAIN_CONTROLLER);
                        _events.Repeat(Seconds(16), Seconds(19));
                        break;
                    case EVENT_IMAGE_ARCANE_BARRAGE_ABILITY:
                        DoCastSelf(SPELL_ARCANE_BARRAGE);
                        _events.Repeat(Seconds(8), Seconds(10));
                        break;
                    case EVENT_IMAGE_VEIL_OF_SKY_ABILITY:
                        DoCastSelf(SPELL_VEIL_OF_SKY_1); // Veil of Sky npc does not cast controller spell!
                        //_events.Repeat(Seconds(20), Seconds(25)); // It does probably not repeat.
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap _events;
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_isiset_mirror_imageAI>(creature);
    }
};

// 48707 - Spatial Flux (Isiset)
class npc_isiset_spatial_flux : public CreatureScript
{
public:
    npc_isiset_spatial_flux() : CreatureScript("npc_isiset_spatial_flux") { }

    struct npc_isiset_spatial_fluxAI : public ScriptedAI
    {
        npc_isiset_spatial_fluxAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetInCombatWithZone();
            events.Reset();
            events.ScheduleEvent(EVENT_DUMMY_NUKE, Seconds(0));
            events.ScheduleEvent(EVENT_SPAWN_ENERGY_FLUX, Seconds(3));
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
                    case EVENT_DUMMY_NUKE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                            DoCast(target, SPELL_DUMMY_NUKE);
                        events.Repeat(Seconds(1));
                        break;
                    case EVENT_SPAWN_ENERGY_FLUX:
                        DoCastSelf(SPELL_SPAWN_ENERGY_FLUX_ISISET);
                        events.Repeat(Seconds(12));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_isiset_spatial_fluxAI>(creature);
    }
};

// 48709 - Energy flux (Isiset)
class npc_isiset_energy_flux : public CreatureScript
{
public:
    npc_isiset_energy_flux() : CreatureScript("npc_isiset_energy_flux") { }

    struct npc_isiset_energy_fluxAI : public ScriptedAI
    {
        npc_isiset_energy_fluxAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetReactState(REACT_PASSIVE);
            target = nullptr;
        }

        void Reset() override
        {
            DoCastSelf(SPELL_ENERGY_FLUX_BEAM_ISISET);
            DoCastSelf(SPELL_ENERGY_FLUX_PERIODIC);
            me->SetWalk(true);
            events.ScheduleEvent(EVENT_FOLLOW_SUMMONER, Seconds(1));
            me->DespawnOrUnsummon(Seconds(6));
        }

        void IsSummonedBy(Unit* summoner) override
        {
            target = summoner;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!target)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FOLLOW_SUMMONER:
                        me->GetMotionMaster()->MovePoint(0, target->GetPosition(), true);
                        events.Repeat(Seconds(1));
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
        Unit* target;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<npc_isiset_energy_fluxAI>(creature);
    }
};

// 74381 - Astral Rain Controller Spell 
class spell_isiset_astral_rain_controller : public SpellScriptLoader
{
public:
    spell_isiset_astral_rain_controller() : SpellScriptLoader("spell_isiset_astral_rain_controller") { }

    class spell_isiset_astral_rain_controller_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_astral_rain_controller_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_ASTRAL_RAIN_1, SPELL_ASTRAL_RAIN_2, SPELL_ASTRAL_RAIN_3 });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance || instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE) == 0)
                return;

            uint32 phase = instance->GetData(DATA_ISISET_PHASE);
            if (phase == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_ASTRAL_RAIN_1, true);
            else if (phase == 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_ASTRAL_RAIN_2, true);
            else if (phase == 3)
                GetCaster()->CastSpell(GetCaster(), SPELL_ASTRAL_RAIN_3, true);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_isiset_astral_rain_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_astral_rain_controller_SpellScript();
    }
};

// 74382 - Mana Shield Controller Spell
class spell_isiset_mana_shield_controller : public SpellScriptLoader
{
public:
    spell_isiset_mana_shield_controller() : SpellScriptLoader("spell_isiset_mana_shield_controller") { }

    class spell_isiset_mana_shield_controller_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_mana_shield_controller_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_VEIL_OF_SKY_1, SPELL_VEIL_OF_SKY_2, SPELL_VEIL_OF_SKY_3 });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance || instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE) == 0)
                return;

            uint32 phase = instance->GetData(DATA_ISISET_PHASE);
            if (phase == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_SKY_1, false);
            else if (phase == 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_SKY_2, false);
            else if (phase == 3)
                GetCaster()->CastSpell(GetCaster(), SPELL_VEIL_OF_SKY_3, false);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_isiset_mana_shield_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_mana_shield_controller_SpellScript();
    }
};

// 74383 - Astral Familiar Controller Spell 
class spell_isiset_astral_familiar_controller : public SpellScriptLoader
{
public:
    spell_isiset_astral_familiar_controller() : SpellScriptLoader("spell_isiset_astral_familiar_controller") { }

    class spell_isiset_astral_familiar_controller_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_astral_familiar_controller_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_CELESTIAL_CALL_1, SPELL_CELESTIAL_CALL_2, SPELL_CELESTIAL_CALL_3 });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance || instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE) == 0)
                return;

            uint32 phase = instance->GetData(DATA_ISISET_PHASE);
            if (phase == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_CELESTIAL_CALL_1, true);
            else if (phase == 2)
                GetCaster()->CastSpell(GetCaster(), SPELL_CELESTIAL_CALL_2, true);
            else if (phase == 3)
                GetCaster()->CastSpell(GetCaster(), SPELL_CELESTIAL_CALL_3, true);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_isiset_astral_familiar_controller_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_astral_familiar_controller_SpellScript();
    }
};

// 74133, 74372, 74373 - Veil of Sky (mana shield)
class spell_isiset_veil_of_sky : public SpellScriptLoader
{
public:
    spell_isiset_veil_of_sky() : SpellScriptLoader("spell_isiset_veil_of_sky") { }

    class spell_isiset_veil_of_sky_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_isiset_veil_of_sky_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_VEIL_OF_SKY_DAMAGE });
        }

        bool Load() override
        {
            reflectPct = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
            return true;
        }

        void Trigger(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            if (dmgInfo.GetDamageType() != SPELL_DIRECT_DAMAGE)
                return;

            int32 damage = CalculatePct(absorbAmount, reflectPct);
            GetCaster()->CastCustomSpell(SPELL_VEIL_OF_SKY_DAMAGE, SPELLVALUE_BASE_POINT0, damage, dmgInfo.GetAttacker(), true);
        }

        void Register() override
        {
            AfterEffectManaShield += AuraEffectManaShieldFn(spell_isiset_veil_of_sky_AuraScript::Trigger, EFFECT_0);
        }

    private:
        int32 reflectPct;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_isiset_veil_of_sky_AuraScript();
    }
};

// 74137 - Supernova (disorient + triggers 76670) (are pets also affected?)
// 76670 - Supernova (damage)
class spell_isiset_supernova_filter : public SpellScriptLoader
{
public:
    spell_isiset_supernova_filter() : SpellScriptLoader("spell_isiset_supernova_filter") { }

    class spell_isiset_supernova_filter_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_supernova_filter_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Unit* caster = GetCaster();
            targets.remove_if([caster](WorldObject* object) { return !object->ToUnit() || !object->ToUnit()->IsCharmedOwnedByPlayerOrPlayer() || !object->isInFront(caster, 2.5f); });
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_isiset_supernova_filter_SpellScript::FilterTargets, m_scriptSpellId == SPELL_SUPERNOVA_EFFECT ? EFFECT_1 : EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_supernova_filter_SpellScript();
    }
};

// 69941 - Mirror Image
class spell_isiset_mirror_image_starry_sky_spawner : public SpellScriptLoader
{
public:
    spell_isiset_mirror_image_starry_sky_spawner() : SpellScriptLoader("spell_isiset_mirror_image_starry_sky_spawner") { }

    class spell_isiset_mirror_image_starry_sky_spawner_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_mirror_image_starry_sky_spawner_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MIRROR_IMAGE_STARRY_SKY_N, SPELL_MIRROR_IMAGE_STARRY_SKY_E, SPELL_MIRROR_IMAGE_STARRY_SKY_W });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            if (instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE) == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_STARRY_SKY_N, true);
            if (instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE) == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_STARRY_SKY_E, true);
            if (instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE) == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_STARRY_SKY_W, true);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_isiset_mirror_image_starry_sky_spawner_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_mirror_image_starry_sky_spawner_SpellScript();
    }
};

// 74264 - Mirror Image
class spell_isiset_mirror_image_spawner : public SpellScriptLoader
{
public:
    spell_isiset_mirror_image_spawner() : SpellScriptLoader("spell_isiset_mirror_image_spawner") { }

    class spell_isiset_mirror_image_spawner_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_mirror_image_spawner_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MIRROR_IMAGE_N, SPELL_MIRROR_IMAGE_E, SPELL_MIRROR_IMAGE_W });
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* const instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            if (instance->GetData(DATA_ISISET_CELESTIAL_CALL_ALIVE) == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_N, true);
            if (instance->GetData(DATA_ISISET_ASTRAL_RAIN_ALIVE) == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_E, true);
            if (instance->GetData(DATA_ISISET_VEIL_OF_SKY_ALIVE) == 1)
                GetCaster()->CastSpell(GetCaster(), SPELL_MIRROR_IMAGE_W, true);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_isiset_mirror_image_spawner_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }

    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_mirror_image_spawner_SpellScript();
    }
};

// 74301 - Image Explosion
class spell_isiset_image_explosion : public SpellScriptLoader
{
public:
    spell_isiset_image_explosion() : SpellScriptLoader("spell_isiset_image_explosion") { }

    class spell_isiset_image_explosion_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_image_explosion_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            InstanceScript* const instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            switch (GetCaster()->GetEntry())
            {
                case NPC_ASTRAL_RAIN:
                    instance->SetData(DATA_ISISET_ASTRAL_RAIN_ALIVE, 0);
                    break;
                case NPC_CELESTIAL_CALL:
                    instance->SetData(DATA_ISISET_CELESTIAL_CALL_ALIVE, 0);
                    break;
                case NPC_VEIL_OF_SKY:
                    instance->SetData(DATA_ISISET_VEIL_OF_SKY_ALIVE, 0);
                    break;
            }

            if (Creature* Isiset = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_ISISET)))
                Isiset->AI()->DoAction(ACTION_MIRROR_IMAGE_DIED);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_isiset_image_explosion_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_image_explosion_SpellScript();
    }
};

// 90750 - Call of Sky (heroic only)
class spell_isiset_call_of_sky : public SpellScriptLoader
{
public:
    spell_isiset_call_of_sky() : SpellScriptLoader("spell_isiset_call_of_sky") { }

    class spell_isiset_call_of_sky_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_call_of_sky_SpellScript);

        void OnMissleHit(SpellEffIndex /*effIndex*/)
        {
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* Isiset = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_ISISET)))
                    Isiset->SummonCreature(NPC_ISISET_SPATIAL_FLUX, GetHitDest()->GetPositionX(), GetHitDest()->GetPositionY(), GetHitDest()->GetPositionZ(), 2.775074f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT);
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_isiset_call_of_sky_SpellScript::OnMissleHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_call_of_sky_SpellScript();
    }
};

// 90735 - Energy Flux (Isiset's Spatial Flux)
class spell_isiset_energy_flux_target_selector : public SpellScriptLoader
{
public:
    spell_isiset_energy_flux_target_selector() : SpellScriptLoader("spell_isiset_energy_flux_target_selector") { }

    class spell_isiset_energy_flux_target_selector_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_isiset_energy_flux_target_selector_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            // Remove tank
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* Isiset = ObjectAccessor::GetCreature(*GetCaster(), instance->GetGuidData(DATA_ISISET)))
                    if (WorldObject* tank = Isiset->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                        targets.remove(tank);

            targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));
            if (targets.empty())
                return;

            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_isiset_energy_flux_target_selector_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_isiset_energy_flux_target_selector_SpellScript();
    }
};

void AddSC_boss_isiset()
{
    new boss_isiset();
    new npc_celestial_familiar();
    new npc_astral_shift_explosion_visual();
    new npc_starry_sky();
    new npc_isiset_mirror_image();
    new npc_isiset_spatial_flux();
    new npc_isiset_energy_flux();
    new spell_isiset_astral_rain_controller();
    new spell_isiset_mana_shield_controller();
    new spell_isiset_astral_familiar_controller();
    new spell_isiset_veil_of_sky();
    new spell_isiset_supernova_filter();
    new spell_isiset_mirror_image_starry_sky_spawner();
    new spell_isiset_mirror_image_spawner();
    new spell_isiset_image_explosion();
    new spell_isiset_call_of_sky();
    new spell_isiset_energy_flux_target_selector();
}
