/*
* Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Spell.h"
#include "Vehicle.h"
#include "MapManager.h"
#include "ruby_sanctum.h"

enum Texts
{
    SAY_INTRO           = 0, // Meddlesome insects! You are too late. The Ruby Sanctum is lost!
    SAY_AGGRO           = 1, // Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!
    SAY_METEOR_STRIKE   = 2, // The heavens burn!
    SAY_PHASE_TWO       = 3, // You will find only suffering within the realm of twilight! Enter if you dare!
    SAY_DEATH           = 4, // Relish this victory, mortals, for it will be your last! This world will burn with the master's return!
    SAY_KILL            = 5, // Another "hero" falls.
    SAY_BERSERK         = 6, // Not good enough.

    SAY_SPHERE_PULSE    = 0, // Beware the shadow!
    SAY_PHASE_THREE     = 1, // I am the light and the darkness! Cower, mortals, before the herald of Deathwing!

    EMOTE_TWILIGHT_OUT_TWILIGHT     = 0, // Your companion's efforts have forced Halion further out of the Twilight realm!
    EMOTE_TWILIGHT_IN_TWILIGHT      = 1, // Your efforts have forced Halion further into the Twilight realm!
    EMOTE_PHYSICAL_OUT_PHYSICAL     = 2, // Your companion's efforts have forced Halion further out of the Physical realm!
    EMOTE_PHYSICAL_IN_PHYSICAL      = 3, // Your efforts have forced Halion further into the Physical realm!
    EMOTE_REGENERATE                = 4, // Without pressure in both realms, Halion begins to regenerate.
    EMOTE_WARN_LASER                = 5, // The orbiting spheres pulse with dark energy!
};

enum Spells
{
    // Halion
    SPELL_FLAME_BREATH                  = 74525,
    SPELL_CLEAVE                        = 74524,
    SPELL_METEOR_STRIKE                 = 74637,
    SPELL_TAIL_LASH                     = 74531,

    SPELL_FIERY_COMBUSTION              = 74562,
    SPELL_MARK_OF_COMBUSTION            = 74567,
    SPELL_FIERY_COMBUSTION_EXPLOSION    = 74607,
    SPELL_FIERY_COMBUSTION_SUMMON       = 74610,
    SPELL_COMBUSTION_DAMAGE_AURA        = 74629,

    SPELL_SCALE_AURA                    = 70507, // Aura created in spell_dbc.

    // Twilight Halion
    SPELL_DARK_BREATH                   = 74806,

    SPELL_MARK_OF_CONSUMPTION           = 74795,
    SPELL_SOUL_CONSUMPTION              = 74792,
    SPELL_SOUL_CONSUMPTION_EXPLOSION    = 74799,
    SPELL_SOUL_CONSUMPTION_SUMMON       = 74800,
    SPELL_CONSUMPTION_DAMAGE_AURA       = 74803,

    // Misc
    SPELL_TWILIGHT_DIVISION             = 75063, // Phase spell from phase 2 to phase 3
    SPELL_LEAVE_TWILIGHT_REALM          = 74812,
    SPELL_TWILIGHT_PHASING              = 74808, // Phase spell from phase 1 to phase 2
    SPELL_SUMMON_TWILIGHT_PORTAL        = 74809, // Summons go 202794
    SPELL_TWILIGHT_MENDING              = 75509,

    // Living Inferno
    SPELL_BLAZING_AURA                  = 75885,

    // Halion Controller
    SPELL_COSMETIC_FIRE_PILLAR          = 76006,
    SPELL_FIERY_EXPLOSION               = 76010,

    // Meteor Strike
    SPELL_METEOR_STRIKE_COUNTDOWN       = 74641,
    SPELL_METEOR_STRIKE_AOE_DAMAGE      = 74648,
    SPELL_METEOR_STRIKE_FIRE_AURA_1     = 74713,
    SPELL_METEOR_STRIKE_FIRE_AURA_2     = 74718,
    SPELL_BIRTH_NO_VISUAL               = 40031,

    // Shadow Orb
    SPELL_TWILIGHT_CUTTER               = 74768, // Unknown dummy effect (EFFECT_0)
    SPELL_TWILIGHT_CUTTER_TRIGGERED     = 74769,
    SPELL_TWILIGHT_PULSE_PERIODIC       = 78861,
    SPELL_TRACK_ROTATION                = 74758, // NPC_ORB_CARRIER -> NPC_ORB_ROTATION_FOCUS

};

enum Events
{
    // Halion
    EVENT_ACTIVATE_FIREWALL             = 1,
    EVENT_CLEAVE                        = 2, // Used by Twilight Halion too
    EVENT_FLAME_BREATH                  = 3,
    EVENT_METEOR_STRIKE                 = 4,
    EVENT_FIERY_COMBUSTION              = 5,
    EVENT_TAIL_LASH                     = 6,

    // Halion Controller
    EVENT_START_INTRO                   = 7,
    EVENT_INTRO_PROGRESS_1              = 8,
    EVENT_INTRO_PROGRESS_2              = 9,
    EVENT_INTRO_PROGRESS_3              = 10,
    EVENT_CHECK_CORPOREALITY            = 11,
    EVENT_SHADOW_PULSARS_SHOOT          = 12,
    EVENT_WARN_LASERS                   = 13,
    EVENT_BERSERK                       = 14,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME            = 15,

    // Twilight Halion
    EVENT_DARK_BREATH                   = 16,
    EVENT_SOUL_CONSUMPTION              = 17,
};

enum Actions
{
    ACTION_METEOR_STRIKE_BURN           = 1, // Meteor Strike
    ACTION_METEOR_STRIKE_AOE            = 2,

    ACTION_BERSERK                      = 3, // Also used by both Halions
    ACTION_PHASE_TWO                    = 4, // Halion Controller
    ACTION_PHASE_THREE                  = 5,
    ACTION_CLEANUP                      = 6,

    ACTION_BEGIN_ROTATION               = 7, // Orb Rotation Focus

    ACTION_SHOOT                        = 8, // Orb Carrier
};

enum Phases
{
    PHASE_ALL           = 0,
    PHASE_ONE           = 1,
    PHASE_TWO           = 2,
    PHASE_THREE         = 3,

    PHASE_ONE_MASK      = 1 << PHASE_ONE,
    PHASE_TWO_MASK      = 1 << PHASE_TWO,
    PHASE_THREE_MASK    = 1 << PHASE_THREE,
};

enum Misc
{
    DATA_TWILIGHT_DAMAGE_TAKEN      = 1,
    DATA_MATERIAL_DAMAGE_TAKEN      = 2,
    DATA_STACKS_DISPELLED           = 3,
    DATA_FIGHT_PHASE                = 4,
};

enum OrbCarrierSeats
{
    SEAT_NORTH      = 0,
    SEAT_SOUTH      = 1,
    SEAT_EAST       = 2, // Heroic
    SEAT_WEST       = 3, // Heroic
};

Position const HalionSpawnPos = {3156.67f, 533.8108f, 72.98822f, 3.159046f};

struct CorporealityData
{
    uint8 materialPercentage;
    uint32 materialRealmSpell;
    uint32 twilightRealmSpell;
    // uint8 twilightPercentage; // Unneeded
};

uint8 const MAX_CORPOREALITY_STATE = 11;

CorporealityData const corporealityReference[MAX_CORPOREALITY_STATE] =
{
    { 0, 74836, 74831}, //, 100},
    { 10, 74835, 74830}, //, 90},
    { 20, 74834, 74829}, //, 80},
    { 30, 74833, 74828}, //, 70},
    { 40, 74832, 74827}, //, 60},
    { 50, 74826, 74826}, //, 50},
    { 60, 74827, 74832}, //, 40},
    { 70, 74828, 74833}, //, 30},
    { 80, 74829, 74834}, //, 20},
    { 90, 74830, 74835}, //, 10},
    {100, 74831, 74836}, //, 0},
};

class boss_halion : public CreatureScript
{
    public:
        boss_halion() : CreatureScript("boss_halion") { }

        struct boss_halionAI : public BossAI
        {
            boss_halionAI(Creature* creature) : BossAI(creature, DATA_HALION) { }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                instance->SetBossState(DATA_HALION, IN_PROGRESS);

                events.Reset();
                events.SetPhase(PHASE_ONE);

                // Schedule events without taking care of phases, since EventMap will not be updated under phase 2.
                events.ScheduleEvent(EVENT_ACTIVATE_FIREWALL, 10000);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 12000));
                events.ScheduleEvent(EVENT_METEOR_STRIKE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_FIERY_COMBUSTION, urand(15000, 18000));
                events.ScheduleEvent(EVENT_TAIL_LASH, 10000);

                // Due to Halion's EventMap not being updated under phase two, Berserk will be triggered by the Controller
                // so that the timer still ticks in phase two.
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_BERSERK);
            }

            void Reset()
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetMaxHealth());
                _Reset();
            }

            void JustDied(Unit* killer)
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_HALION, DONE);

                instance->DoCastSpellOnPlayers(SPELL_LEAVE_TWILIGHT_REALM);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FIERY_COMBUSTION);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SOUL_CONSUMPTION);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_CLEANUP);

                if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_TWILIGHT_HALION)))
                    if (twilightHalion->isAlive())
                        twilightHalion->Kill(twilightHalion);
            }

            void JustReachedHome()
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_HALION, FAIL);
                instance->DoCastSpellOnPlayers(SPELL_LEAVE_TWILIGHT_REALM);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_CLEANUP);

                if (Creature* halion = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_TWILIGHT_HALION)))
                    halion->DespawnOrUnsummon();
            }

            Position const* GetMeteorStrikePosition() const { return &_meteorStrikePos; }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if ((me->GetHealth() - damage) > 0 && (events.GetPhaseMask() & (PHASE_ONE_MASK | PHASE_THREE_MASK)))
                    instance->SetData(DATA_HALION_SHARED_HEALTH, (me->GetHealth() - damage));

                if (me->HealthBelowPctDamaged(75, damage) && (events.GetPhaseMask() & PHASE_ONE_MASK))
                {
                    events.SetPhase(PHASE_TWO);
                    events.DelayEvents(2600); // 2.5 sec + 0.1 sec lag

                    Talk(SAY_PHASE_TWO);

                    me->CastStop();
                    DoCast(me, SPELL_TWILIGHT_PHASING);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->DoAction(ACTION_PHASE_TWO);
                }

                if (events.GetPhaseMask() & PHASE_THREE_MASK)
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_MATERIAL_DAMAGE_TAKEN, damage);
            }

            bool CanAIAttack(const Unit* victim)
            {
                return !victim->HasAura(SPELL_TWILIGHT_REALM);
            }

            void UpdateAI(uint32 const diff)
            {
                if (!(events.GetPhaseMask() & PHASE_ONE_MASK))
                    me->SetHealth(instance->GetData(DATA_HALION_SHARED_HEALTH));

                if ((!UpdateVictim() && (events.GetPhaseMask() & (PHASE_ONE_MASK | PHASE_THREE_MASK))) || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                // Events won't be updated under phase two.
                if (!(events.GetPhaseMask() & PHASE_TWO_MASK))
                    events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ACTIVATE_FIREWALL:
                        {
                            // Firewall is activated 10 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                            if (GameObject* firewall = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FLAME_RING)))
                                instance->HandleGameObject(instance->GetData64(DATA_FLAME_RING), false, firewall);
                            if (GameObject* firewall = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_TWILIGHT_FLAME_RING)))
                                instance->HandleGameObject(instance->GetData64(DATA_TWILIGHT_FLAME_RING), false, firewall);
                            break;
                        }
                        case EVENT_FLAME_BREATH:
                            DoCast(me, SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, 25000);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                            break;
                        case EVENT_TAIL_LASH:
                            DoCastAOE(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                            break;
                        case EVENT_METEOR_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM))
                            {
                                target->GetPosition(&_meteorStrikePos);
                                me->CastSpell(_meteorStrikePos.GetPositionX(), _meteorStrikePos.GetPositionY(), _meteorStrikePos.GetPositionZ(), SPELL_METEOR_STRIKE, true, NULL, NULL, me->GetGUID());
                                Talk(SAY_METEOR_STRIKE);
                            }
                            events.ScheduleEvent(EVENT_METEOR_STRIKE, 40000);
                            break;
                        }
                        case EVENT_FIERY_COMBUSTION:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_TWILIGHT_REALM);
                            if (!target)
                                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_TWILIGHT_REALM);
                            if (target)
                                    DoCast(target, SPELL_FIERY_COMBUSTION);
                            events.ScheduleEvent(EVENT_FIERY_COMBUSTION, 25000);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void SetData(uint32 index, uint32 value)
            {
                if (index == DATA_FIGHT_PHASE)
                    events.SetPhase(value);
            }

            void DoAction(int32 const action)
            {
                if (action != ACTION_BERSERK)
                    return;

                Talk(SAY_BERSERK);
                DoCast(me, SPELL_BERSERK);
            }

        private:
            Position _meteorStrikePos;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_halionAI>(creature);
        }
};

typedef boss_halion::boss_halionAI HalionAI;

class boss_twilight_halion : public CreatureScript
{
    public:
        boss_twilight_halion() : CreatureScript("boss_twilight_halion") { }

        struct boss_twilight_halionAI : public ScriptedAI
        {
            boss_twilight_halionAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript())
            {
                me->SetPhaseMask(0x20, true); // Should not be visible with phasemask 0x21, so only 0x20
                me->SetHealth(_instance->GetData(DATA_HALION_SHARED_HEALTH)); // Should be 75%
                me->SetReactState(REACT_AGGRESSIVE); // NFI if needed
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.Reset();
                events.SetPhase(PHASE_TWO);
                //! All of Twilight Halion's abilities are not phase dependant as he is never on Phase One.
                //! However, phasemasks are "needed" so that we know on which phase we are when Halion
                //! takes damage, causing corporeality not to tick in phase two.
                events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);

                // Victims should not be in the Twilight Realm
                me->CastSpell(victim, SPELL_LEAVE_TWILIGHT_REALM, true);
            }

            void JustDied(Unit* killer)
            {
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    // Ensure looting
                    if (me->IsDamageEnoughForLootingAndReward())
                        halion->LowerPlayerDamageReq(halion->GetMaxHealth());

                    if (halion->isAlive())
                        killer->Kill(halion);
                }

                _instance->DoCastSpellOnPlayers(SPELL_LEAVE_TWILIGHT_REALM);
            }

            void JustReachedHome()
            {
                // If the Twilight Halion enters evade mode on phase 2, the players in the Physical realm should enter the Twilight Realm to end the fight (i.e. wipe)
                // As a consequence, the Twilight Halion entering evade mode does not end the encounter.
                if (events.GetPhaseMask() & PHASE_TWO_MASK)
                    return;

                ScriptedAI::JustReachedHome();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (me->GetHealth() - damage > 0)
                    _instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth() - damage);

                if (me->HealthBelowPctDamaged(50, damage) && (events.GetPhaseMask() & PHASE_TWO_MASK))
                {
                    events.SetPhase(PHASE_THREE);
                    events.DelayEvents(2600); // 2.5 sec + 0.1sec lag

                    me->CastStop();
                    DoCast(me, SPELL_TWILIGHT_DIVISION);
                    Talk(SAY_PHASE_THREE);
                }

                if (events.GetPhaseMask() & PHASE_THREE_MASK)
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(DATA_TWILIGHT_DAMAGE_TAKEN, damage);
            }

            void SpellHitTarget(Unit* /*who*/, const SpellInfo* spell)
            {
                if (spell->Id != SPELL_TWILIGHT_DIVISION)
                    return;

                DoCast(me, 74826); // 50% corporeality
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    halion->CastSpell(halion, 74826, false); // 50% corporeality
                    halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                    halion->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    halion->AI()->SetData(DATA_FIGHT_PHASE, PHASE_THREE);
                }

                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_PHASE_THREE);
            }

            bool CanAIAttack(const Unit* victim)
            {
                return victim->HasAura(SPELL_TWILIGHT_REALM);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_BERSERK)
                    DoCast(me, SPELL_BERSERK);
            }

            void UpdateAI(uint32 const diff)
            {
                me->SetHealth(_instance->GetData(DATA_HALION_SHARED_HEALTH));

                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DARK_BREATH:
                        {
                            DoCast(me, SPELL_DARK_BREATH);
                            events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                            break;
                        }
                        case EVENT_SOUL_CONSUMPTION:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, SPELL_TWILIGHT_REALM);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, SPELL_TWILIGHT_REALM);
                            if (target)
                                DoCast(target, SPELL_SOUL_CONSUMPTION);
                            events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                            break;
                        }
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                            break;
                        case EVENT_TAIL_LASH:
                            DoCastAOE(SPELL_TAIL_LASH);
                            events.ScheduleEvent(EVENT_TAIL_LASH, 10000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            EventMap events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_twilight_halionAI>(creature);
        }
};

typedef boss_twilight_halion::boss_twilight_halionAI twilightHalionAI;

class npc_halion_controller : public CreatureScript
{
    public:
        npc_halion_controller() : CreatureScript("npc_halion_controller") { }

        struct npc_halion_controllerAI : public ScriptedAI
        {
            npc_halion_controllerAI(Creature* creature) : ScriptedAI(creature),
                _instance(creature->GetInstanceScript()), _summons(me)
            {
                me->SetPhaseMask(me->GetPhaseMask() | 0x20, true);
            }

            void Reset() { me->SetReactState(REACT_PASSIVE); }

            void JustSummoned(Creature* who)
            {
                _summons.Summon(who);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_INTRO_HALION:
                    {
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_START_INTRO, 2000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_1, 6000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_2, 10000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_3, 14000);
                        break;
                    }
                    case ACTION_PHASE_TWO:
                    {
                        _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 10000); // Fix the timer

                        me->SummonCreature(NPC_TWILIGHT_HALION, HalionSpawnPos);

                        if (Creature* rotationFocus = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORB_ROTATION_FOCUS)))
                            rotationFocus->AI()->DoAction(ACTION_BEGIN_ROTATION);

                        if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                            halion->CastSpell(halion->GetPositionX(), halion->GetPositionY(), halion->GetPositionZ(), SPELL_SUMMON_TWILIGHT_PORTAL, true);
                        break;
                    }
                    case ACTION_PHASE_THREE:
                    {
                        _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 20000);

                        TwilightDamageTaken = 0;
                        MaterialDamageTaken = 0;
                        materialCorporealityValue = 50;
                        _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TOGGLE, 1);

                        break;
                    }
                    case ACTION_CLEANUP:
                    {
                        _summons.DespawnAll();
                        _events.Reset();
                        if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                            halion->RemoveGameObject(SPELL_SUMMON_TWILIGHT_PORTAL, true);
                        break;
                    }
                    case ACTION_BERSERK:
                    {
                        _events.ScheduleEvent(EVENT_BERSERK, 8 * MINUTE * IN_MILLISECONDS);
                        break;
                    }
                }
            }

            void UpdateAI(uint32 const diff)
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_INTRO:
                            DoCast(me, SPELL_COSMETIC_FIRE_PILLAR, true);
                            break;
                        case EVENT_INTRO_PROGRESS_1:
                            for (uint8 i = DATA_BURNING_TREE_3; i < DATA_BURNING_TREE_4; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(i)))
                                    _instance->HandleGameObject(_instance->GetData64(i), true, tree);
                            break;
                        case EVENT_INTRO_PROGRESS_2:
                            for (uint8 i = DATA_BURNING_TREE_1; i < DATA_BURNING_TREE_2; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(i)))
                                    _instance->HandleGameObject(_instance->GetData64(i), true, tree);
                            break;
                        case EVENT_INTRO_PROGRESS_3:
                            DoCast(me, SPELL_FIERY_EXPLOSION);
                            if (Creature* halion = me->GetMap()->SummonCreature(NPC_HALION, HalionSpawnPos))
                                halion->AI()->Talk(SAY_INTRO);
                            break;
                        case EVENT_SHADOW_PULSARS_SHOOT:
                        {
                            if (Creature* twilightHalion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_TWILIGHT_HALION)))
                                twilightHalion->AI()->Talk(SAY_SPHERE_PULSE);

                            if (Creature* orbCarrier = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_ORB_CARRIER)))
                                orbCarrier->AI()->DoAction(ACTION_SHOOT);

                            _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 30000);
                            _events.ScheduleEvent(EVENT_WARN_LASERS, 25000);
                            break;
                        }
                        case EVENT_WARN_LASERS:
                        {
                            Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
                            for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                                if (Player* player = i->getSource())
                                    if (player->HasAura(SPELL_TWILIGHT_REALM))
                                        Talk(EMOTE_WARN_LASER, player->GetGUID());
                            break;
                        }
                        case EVENT_CHECK_CORPOREALITY:
                        {
                            bool canUpdate = false;
                            if (MaterialDamageTaken != 0 && TwilightDamageTaken != 0)
                            {
                                // Moar research needed.
                                if (MaterialDamageTaken >= 1.02f * TwilightDamageTaken)
                                {
                                    TwilightDamageTaken = 0;
                                    MaterialDamageTaken = 0;
                                    canUpdate = (materialCorporealityValue != 0);
                                    if (canUpdate)
                                        materialCorporealityValue -= 10;
                                }
                                else if (TwilightDamageTaken >= 1.02f * MaterialDamageTaken)
                                {
                                    TwilightDamageTaken = 0;
                                    MaterialDamageTaken = 0;
                                    canUpdate = (materialCorporealityValue != 100);
                                    if (canUpdate)
                                        materialCorporealityValue += 10;
                                }
                            }
                            else
                            {
                                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                                {
                                    Map::PlayerList const &PlList = me->GetMap()->GetPlayers();
                                    for (Map::PlayerList::const_iterator i = PlList.begin(); i != PlList.end(); ++i)
                                        if (Player* player = i->getSource())
                                            Talk(EMOTE_REGENERATE, player->GetGUID());

                                    DoCast(halion, SPELL_TWILIGHT_MENDING);
                                }
                                _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 15000);
                                break;
                            }

                            if (canUpdate)
                            {
                                uint32 twilightSpell, physicalSpell;

                                for (uint8 i = 0; i < MAX_CORPOREALITY_STATE; i++)
                                {
                                    // Testing the material value is enough.
                                    if (corporealityReference[i].materialPercentage == materialCorporealityValue)
                                    {
                                        twilightSpell = corporealityReference[i].twilightRealmSpell;
                                        physicalSpell = corporealityReference[i].materialRealmSpell;
                                        break; // stop here
                                    }
                                }

                                for (uint8 i = DATA_HALION; i <= DATA_TWILIGHT_HALION; i++)
                                {
                                    if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(i)))
                                    {
                                        RemoveAnyCorporealityBuff(halion);
                                        halion->CastSpell(halion, (i == DATA_HALION ? physicalSpell : twilightSpell), true);
                                    }
                                }

                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_MATERIAL, materialCorporealityValue);
                                _instance->DoUpdateWorldState(WORLDSTATE_CORPOREALITY_TWILIGHT, (100 - materialCorporealityValue));

                                Map::PlayerList const &playersList = me->GetMap()->GetPlayers();
                                for (Map::PlayerList::const_iterator i = playersList.begin(); i != playersList.end(); ++i)
                                {
                                    if (Player* player = i->getSource())
                                    {
                                        if (materialCorporealityValue > 50) // Range is 0 ... 100
                                        {
                                            if (player->HasAura(SPELL_TWILIGHT_REALM))
                                                Talk(EMOTE_TWILIGHT_OUT_TWILIGHT, player->GetGUID());
                                            else
                                                Talk(EMOTE_PHYSICAL_IN_PHYSICAL, player->GetGUID());
                                        }
                                        else
                                        {
                                            if (player->HasAura(SPELL_TWILIGHT_REALM))
                                                Talk(EMOTE_TWILIGHT_IN_TWILIGHT, player->GetGUID());
                                            else
                                                Talk(EMOTE_PHYSICAL_OUT_PHYSICAL, player->GetGUID());
                                        }
                                    }
                                }
                            }
                            _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 15000);
                            break;
                        }
                        case EVENT_BERSERK:
                        {
                            for (uint8 i = DATA_HALION; i <= DATA_TWILIGHT_HALION; i++)
                                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(i)))
                                    halion->AI()->DoAction(ACTION_BERSERK);
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void SetData(uint32 id, uint32 value)
            {
                switch (id)
                {
                    case DATA_MATERIAL_DAMAGE_TAKEN:
                        MaterialDamageTaken += value;
                        break;
                    case DATA_TWILIGHT_DAMAGE_TAKEN:
                        TwilightDamageTaken += value;
                        break;
                }
            }

            // Move to spell_linked_spell, for God's sake.
            void RemoveAnyCorporealityBuff(Creature* who)
            {
                for (uint8 i = 0; i < MAX_CORPOREALITY_STATE; i++)
                {
                    if (who->HasAura(74826 + i))
                    {
                        who->RemoveAurasDueToSpell(74826 + i);
                        break;
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
            uint32 TwilightDamageTaken;
            uint32 MaterialDamageTaken;
            uint8 materialCorporealityValue;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_halion_controllerAI>(creature);
        }
};

typedef npc_halion_controller::npc_halion_controllerAI controllerAI;

class npc_meteor_strike_initial : public CreatureScript
{
    public:
        npc_meteor_strike_initial() : CreatureScript("npc_meteor_strike_initial") { }

        struct npc_meteor_strike_initialAI : public Scripted_NoMovementAI
        {
            npc_meteor_strike_initialAI(Creature* creature) : Scripted_NoMovementAI(creature),
                _instance(creature->GetInstanceScript())
            { }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_METEOR_STRIKE_AOE:
                        DoCast(me, SPELL_METEOR_STRIKE_AOE_DAMAGE, true);
                        DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_1, true);
                        for (std::list<Creature*>::iterator itr = _meteorList.begin(); itr != _meteorList.end(); ++itr)
                            (*itr)->AI()->DoAction(ACTION_METEOR_STRIKE_BURN);
                        break;
                }
            }

            void IsSummonedBy(Unit* summoner)
            {
                _owner = summoner->ToCreature();

                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);

                if (!_owner)
                    return;

                DoCast(me, SPELL_METEOR_STRIKE_COUNTDOWN);
                DoCast(me, SPELL_BIRTH_NO_VISUAL); // Unknown purpose

                if (HalionAI* halionAI = CAST_AI(HalionAI, _owner->AI()))
                {
                    Position const* ownerPos = halionAI->GetMeteorStrikePosition();
                    Position newPos;
                    float angle[4];
                    angle[0] = me->GetAngle(ownerPos);
                    angle[1] = me->GetAngle(ownerPos) - static_cast<float>(M_PI/2);
                    angle[2] = me->GetAngle(ownerPos) - static_cast<float>(-M_PI/2);
                    angle[3] = me->GetAngle(ownerPos) - static_cast<float>(M_PI);

                    _meteorList.clear();
                    for (uint8 i = 0; i < 4; i++)
                    {
                        MapManager::NormalizeOrientation(angle[i]);
                        me->SetOrientation(angle[i]);
                        me->GetNearPosition(newPos, 10.0f, 0.0f); // Exact distance
                        if (Creature* meteor = me->SummonCreature(NPC_METEOR_STRIKE_NORTH + i, newPos, TEMPSUMMON_TIMED_DESPAWN, 30000))
                            _meteorList.push_back(meteor);
                    }
                }
            }

            void UpdateAI(uint32 const /*diff*/) { }
            void EnterEvadeMode() { }

        private:
            InstanceScript* _instance;
            Creature* _owner;
            std::list<Creature*> _meteorList;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_meteor_strike_initialAI>(creature);
        }
};

class npc_meteor_strike : public CreatureScript
{
    public:
        npc_meteor_strike() : CreatureScript("npc_meteor_strike") { }

        struct npc_meteor_strikeAI : public Scripted_NoMovementAI
        {
            npc_meteor_strikeAI(Creature* creature) : Scripted_NoMovementAI(creature),
                _instance(creature->GetInstanceScript())
            {
                _range = 5.0f;
                _spawnCount = 0;
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_METEOR_STRIKE_BURN)
                {
                    DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                    me->setActive(true);
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 500);
                }
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                // Let Halion Controller count as summoner.
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);
            }

            void UpdateAI(uint32 const diff)
            {
                if (_spawnCount > 5)
                    return;

                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_SPAWN_METEOR_FLAME)
                {
                    Position pos;
                    me->GetNearPosition(pos, _range, 0.0f);

                    if (Creature* flame = me->SummonCreature(NPC_METEOR_STRIKE_FLAME, pos, TEMPSUMMON_TIMED_DESPAWN, 25000))
                    {
                        if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                            controller->AI()->JustSummoned(flame);

                        flame->CastSpell(flame, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                        ++_spawnCount;
                    }
                    _range += 5.0f;
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 800);
                }
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            float _range;
            uint8 _spawnCount;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_meteor_strikeAI>(creature);
        }
};

class npc_combustion_consumption : public CreatureScript
{
    public:
        npc_combustion_consumption() : CreatureScript("npc_combustion_consumption") { }

        struct npc_combustion_consumptionAI : public Scripted_NoMovementAI
        {
            npc_combustion_consumptionAI(Creature* creature) : Scripted_NoMovementAI(creature),
                   _instance(creature->GetInstanceScript())
            {
                switch (me->GetEntry())
                {
                    case NPC_COMBUSTION:
                        _explosionSpell = SPELL_FIERY_COMBUSTION_EXPLOSION;
                        _damageSpell = SPELL_COMBUSTION_DAMAGE_AURA;
                        me->SetPhaseMask(0x20, true);
                        if (IsHeroic())
                            me->SetPhaseMask(me->GetPhaseMask() | 0x1, true);
                        break;
                    case NPC_CONSUMPTION:
                        _explosionSpell = SPELL_SOUL_CONSUMPTION_EXPLOSION;
                        _damageSpell = SPELL_CONSUMPTION_DAMAGE_AURA;
                        if (IsHeroic())
                            me->SetPhaseMask(me->GetPhaseMask() | 0x20, true);
                        break;
                    default: // Should never happen
                        _explosionSpell = 0;
                        _damageSpell = 0;
                        break;
                }
            }

            void IsSummonedBy(Unit* summoner)
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);

                _summoner = summoner;
            }

            void SetData(uint32 type, uint32 value)
            {
                if (type != DATA_STACKS_DISPELLED || !_damageSpell || !_explosionSpell || !_summoner)
                    return;

                me->CastCustomSpell(SPELL_SCALE_AURA, SPELLVALUE_AURA_STACK, value, me);
                DoCast(me, _damageSpell);
                
                int32 damage = 1200 + (value * 1290); // Needs moar research.
                // Target is TARGET_UNIT_AREA_ALLY_SRC (TARGET_SRC_CASTER)
                _summoner->CastCustomSpell(_explosionSpell, SPELLVALUE_BASE_POINT0, damage, _summoner);
            }

            void UpdateAI(const uint32 /*diff*/) { }

        private:
            InstanceScript* _instance;
            uint32 _explosionSpell;
            uint32 _damageSpell;

            Unit* _summoner;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_combustion_consumptionAI>(creature);
        }
};

class npc_orb_carrier : public CreatureScript
{
    public:
        npc_orb_carrier() : CreatureScript("npc_orb_carrier") { }

        struct npc_orb_carrierAI : public ScriptedAI
        {
            npc_orb_carrierAI(Creature* creature) : ScriptedAI(creature)
            {
                ASSERT(creature->GetVehicleKit());
            }

            void UpdateAI(uint32 const diff)
            {
                //! According to sniffs this spell is cast every 1 or 2 seconds.
                //! However, refreshing it looks bad, so just cast the spell if
                //! we are not channeling it. Targeting will be handled by
                //! conditions.
                if (!me->HasUnitState(UNIT_STATE_CASTING))
                    DoCast(me, SPELL_TRACK_ROTATION, false);
            }

            void DoAction(int32 const action)
            {
                if (action == ACTION_SHOOT)
                {
                    Vehicle* vehicle = me->GetVehicleKit();

                    if (Unit* southOrb = vehicle->GetPassenger(SEAT_SOUTH))
                        if (Unit* northOrb = vehicle->GetPassenger(SEAT_NORTH))
                            northOrb->CastSpell(southOrb, SPELL_TWILIGHT_CUTTER);

                    // Doublecheck which one casts on which here (Need moar sniffz)
                    if (IsHeroic())
                        if (Unit* eastOrb = vehicle->GetPassenger(SEAT_EAST))
                            if (Unit* westOrb = vehicle->GetPassenger(SEAT_WEST))
                                eastOrb->CastSpell(westOrb, SPELL_TWILIGHT_CUTTER);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_orb_carrierAI>(creature);
        }
};

class npc_living_inferno : public CreatureScript
{
    public:
        npc_living_inferno() : CreatureScript("npc_living_inferno") { }

        struct npc_living_infernoAI : public ScriptedAI
        {
            npc_living_infernoAI(Creature* creature) : ScriptedAI(creature) { }

            void JustSummoned(Creature* /*summoner*/)
            {
                me->SetInCombatWithZone();
                DoCast(me, SPELL_BLAZING_AURA);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_living_infernoAI>(creature);
        }
};

//! Need sniff data
class npc_living_ember : public CreatureScript
{
    public:
        npc_living_ember() : CreatureScript("npc_living_ember") { }

        struct npc_living_emberAI : public ScriptedAI
        {
            npc_living_emberAI(Creature* creature) : ScriptedAI(creature) { }

            void JustSummoned(Creature /*summoner*/)
            {
                _berserkingTimer = 2 * MINUTE * IN_MILLISECONDS;
                me->SetInCombatWithZone();
            }

            void UpdateAI(uint32 const diff)
            {
                if (_berserkingTimer < diff)
                    DoCast(me, SPELL_BERSERK);
                else _berserkingTimer -= diff;
            }

        private:
            uint32 _berserkingTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_living_emberAI>(creature);
        }
};

class spell_halion_meteor_strike_marker : public SpellScriptLoader
{
    public:
        spell_halion_meteor_strike_marker() : SpellScriptLoader("spell_halion_meteor_strike_marker") { }

        class spell_halion_meteor_strike_marker_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_meteor_strike_marker_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    if (Creature* creCaster = GetCaster()->ToCreature())
                        creCaster->AI()->DoAction(ACTION_METEOR_STRIKE_AOE);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_meteor_strike_marker_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_meteor_strike_marker_AuraScript();
        }
};

class spell_halion_fiery_combustion : public SpellScriptLoader
{
    public:
        spell_halion_fiery_combustion() : SpellScriptLoader("spell_halion_fiery_combustion") { }

        class spell_halion_fiery_combustion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_fiery_combustion_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_COMBUSTION))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->HasAura(SPELL_MARK_OF_COMBUSTION))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_COMBUSTION, 0, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_COMBUSTION, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_COMBUSTION, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_fiery_combustion_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_fiery_combustion_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_fiery_combustion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_fiery_combustion_AuraScript();
        }
};

class spell_halion_soul_consumption : public SpellScriptLoader
{
    public:
        spell_halion_soul_consumption() : SpellScriptLoader("spell_halion_soul_consumption") { }

        class spell_halion_soul_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_soul_consumption_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_CONSUMPTION))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget()->HasAura(SPELL_MARK_OF_CONSUMPTION))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_CONSUMPTION, 0, 0, AURA_REMOVE_BY_EXPIRE);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_CONSUMPTION, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_CONSUMPTION, true);
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_halion_soul_consumption_AuraScript::AddMarkStack, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                AfterEffectApply += AuraEffectApplyFn(spell_halion_soul_consumption_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_soul_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_soul_consumption_AuraScript();
        }
};

class spell_halion_mark_of_combustion : public SpellScriptLoader
{
    public:
        spell_halion_mark_of_combustion() : SpellScriptLoader("spell_halion_mark_of_combustion") { }

        class spell_halion_mark_of_combustion_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_mark_of_combustion_AuraScript);

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FIERY_COMBUSTION_SUMMON))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_FIERY_COMBUSTION_EXPLOSION))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL) // Purged
                    target->RemoveAurasDueToSpell(SPELL_FIERY_COMBUSTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);

                //! Don't process if the aura is not considered expired.
                //! The hook will still be called upon dispelling Soul Consumption because
                //! it causes Mark of Combustion to be considered removed by expire.
                //! It will also be called upon purging the mark, but purging it will
                //! trigger Fiery Conbustion's dispel.
                //! Note: This is really fubarish, we need something simpler.
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                InstanceScript* instance = target->GetInstanceScript();
                if (!instance)
                    return;

                uint8 stacks = aurEff->GetBase()->GetStackAmount();

                // Keep track of stacks when dispelling, there's only one effect in the spell.
                CustomSpellValues values;
                values.AddSpellMod(SPELLVALUE_BASE_POINT1, stacks);

                target->CastCustomSpell(SPELL_FIERY_COMBUSTION_SUMMON, values, target, true, NULL, NULL, GetCasterGUID());
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_mark_of_combustion_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_mark_of_combustion_AuraScript();
        }
};

class spell_halion_mark_of_consumption : public SpellScriptLoader
{
    public:
        spell_halion_mark_of_consumption() : SpellScriptLoader("spell_halion_mark_of_consumption") { }

        class spell_halion_mark_of_consumption_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_halion_mark_of_consumption_AuraScript);

            bool Validate(SpellInfo const* /*spell*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SOUL_CONSUMPTION_SUMMON))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SOUL_CONSUMPTION_EXPLOSION))
                    return false;
                return true;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL) // Purged
                    target->RemoveAurasDueToSpell(SPELL_SOUL_CONSUMPTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);

                //! Don't process if the aura is not considered expired.
                //! The hook will still be called upon dispelling Soul Consumption because
                //! it causes Mark of Consumption to be considered removed by expire.
                //! It will also be called upon purging the mark, but purging it will
                //! trigger Soul Consumption's dispel.
                //! Note: This is really fubarish, we need something simpler.
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
                    return;

                InstanceScript* instance = target->GetInstanceScript();
                if (!instance)
                    return;

                uint8 stacks = aurEff->GetBase()->GetStackAmount();

                // Keep track of stacks when dispelling, there's only one effect in the spell.
                CustomSpellValues values;
                values.AddSpellMod(SPELLVALUE_BASE_POINT1, stacks);

                target->CastCustomSpell(SPELL_SOUL_CONSUMPTION_SUMMON, values, target, true, NULL, NULL, GetCasterGUID());
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_mark_of_consumption_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_mark_of_consumption_AuraScript();
        }
};

class spell_halion_combustion_consumption_summon : public SpellScriptLoader
{
    public:
        spell_halion_combustion_consumption_summon() : SpellScriptLoader("spell_halion_combustion_consumption_summon") { }

        class spell_halion_combustion_consumption_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_combustion_consumption_summon_SpellScript);

            void HandleSummon(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                uint32 entry = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->Effects[effIndex].MiscValueB));
                uint32 duration = uint32(GetSpellInfo()->GetDuration());

                InstanceScript* instance = caster->GetInstanceScript();
                if (!instance)
                    return;

                Position pos;
                caster->GetPosition(&pos);
                if (Creature* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
                    if (summon->IsAIEnabled)
                        summon->AI()->SetData(DATA_STACKS_DISPELLED, GetSpellValue()->EffectBasePoints[EFFECT_1]);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_halion_combustion_consumption_summon_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_combustion_consumption_summon_SpellScript();
        }
};

class spell_halion_leave_twilight_realm : public SpellScriptLoader
{
    public:
        spell_halion_leave_twilight_realm() : SpellScriptLoader("spell_halion_leave_twilight_realm") { }

        class spell_halion_leave_twilight_realm_AuraScript: public AuraScript
        {
            PrepareAuraScript(spell_halion_leave_twilight_realm_AuraScript);

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*handle*/)
            {
                GetTarget()->RemoveAurasDueToSpell(SPELL_TWILIGHT_REALM);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_halion_leave_twilight_realm_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        class spell_halion_leave_twilight_realm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_leave_twilight_realm_SpellScript);

            void HandleBeforeHit()
            {
                if (Player* player = GetHitPlayer())
                    player->RemoveAurasDueToSpell(SPELL_SOUL_CONSUMPTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void FilterTargets(std::list<Unit*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_TWILIGHT_REALM));
                //! Wat about dis ?
                //! targets.clear();
                //! if (GetTargetUnit() && GetTargetUnit()->HasAura(SPELL_TWILIGHT_REALM))
                //! targets.push_back(GetTargetUnit());
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_halion_leave_twilight_realm_SpellScript::HandleBeforeHit);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_halion_leave_twilight_realm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_TARGET_ANY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_leave_twilight_realm_SpellScript();
        }

        AuraScript* GetAuraScript() const
        {
            return new spell_halion_leave_twilight_realm_AuraScript();
        }
};

class spell_halion_enter_twilight_realm : public SpellScriptLoader
{
    public:
        spell_halion_enter_twilight_realm() : SpellScriptLoader("spell_halion_enter_twilight_realm") { }

        class spell_halion_enter_twilight_realm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_enter_twilight_realm_SpellScript);

            void HandleBeforeHit()
            {
                if (Player* player = GetHitPlayer())
                    player->RemoveAurasDueToSpell(SPELL_FIERY_COMBUSTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_halion_enter_twilight_realm_SpellScript::HandleBeforeHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_enter_twilight_realm_SpellScript();
        }
};

class TwilightCutterSelector
{
    public:
        TwilightCutterSelector(Unit* caster, Unit* cutterCaster) : _caster(caster), _cutterCaster(cutterCaster) {}

        bool operator()(Unit* unit)
        {
            if (unit->IsInBetween(_caster, _cutterCaster, 4.0f))
                return false;

            sLog->outError("%s is inbetween, do damage!", unit->GetName());
            return true;
        }

    private:
        Unit* _caster;
        Unit* _cutterCaster;
};

class spell_halion_twilight_cutter : public SpellScriptLoader
{
    public:
        spell_halion_twilight_cutter() : SpellScriptLoader("spell_halion_twilight_cutter") { }

        class spell_halion_twilight_cutter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_twilight_cutter_SpellScript);

            void RemoveNotBetween(std::list<Unit*>& targets)
            {
                Unit* caster = GetCaster();
                if (Aura* cutter = caster->GetAura(SPELL_TWILIGHT_CUTTER))
                {
                    if (Unit* cutterCaster = cutter->GetCaster())
                        targets.remove_if(TwilightCutterSelector(caster, cutterCaster));
                    else
                        sLog->outError("No cutterCaster");
                }
                else
                    sLog->outError("No cutter");
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_halion_twilight_cutter_SpellScript::RemoveNotBetween, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_twilight_cutter_SpellScript();
        }
};

void AddSC_boss_halion()
{
    new boss_halion();
    new boss_twilight_halion();

    new npc_halion_controller();
    new npc_meteor_strike_initial();
    new npc_meteor_strike();
    new npc_combustion_consumption();
    new npc_orb_carrier();
    new npc_living_inferno();
    new npc_living_ember();

    new spell_halion_meteor_strike_marker();
    new spell_halion_combustion_consumption_summon();
    new spell_halion_mark_of_combustion();
    new spell_halion_mark_of_consumption();
    new spell_halion_fiery_combustion();
    new spell_halion_soul_consumption();
    new spell_halion_leave_twilight_realm();
    new spell_halion_enter_twilight_realm();
    new spell_halion_twilight_cutter();
}