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
#include "MapManager.h"
#include "ruby_sanctum.h"

/*
DELETE FROM `spell_dbc` WHERE `id`=70507;
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`AttributesEx`,`AttributesEx2`,`CastingTimeIndex`,`ProcChance`,`DurationIndex`,`RangeIndex`,`StackAmount`,`Effect1`,`EffectBasePoints1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`DmgMultiplier1`,`Comment`) VALUES
(70507,0x00000100,0x00000400,0x0,1,101,21,1,100,6,2,1,61,1, 'Halion - Combustion & Consumption Scale Aura');

UPDATE `creature` SET `spawntimesecs`=604800 WHERE `id` IN (39751,39746,39747);
UPDATE `gameobject` SET `phaseMask`=`phaseMask`|0x20 WHERE `id`=203007; -- Ruby Sanctum Halion Flame Ring

UPDATE `creature_template` SET `scale`=1,`exp`=2,`baseattacktime`=2000,`unit_flags`=33554432,`ScriptName`= 'npc_consumption' WHERE `entry`=40135; -- Consumption
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`ScriptName`= 'npc_combustion' WHERE `entry`=40001; -- Combustion
UPDATE `creature_model_info` SET `bounding_radius`=3.8,`combat_reach`=7.6,`gender`=2 WHERE `modelid`=16946;
UPDATE `creature_template` SET `ScriptName`= 'boss_halion' WHERE `entry`=39863;
UPDATE `creature_template` SET `ScriptName`= 'boss_twilight_halion' WHERE `entry`=40142;
UPDATE `creature_template` SET `ScriptName`= 'npc_halion_controller' WHERE `entry`=40146;
UPDATE `creature_template` SET `ScriptName`= 'npc_shadow_orb' WHERE `entry` IN (40083,40100,40468,40469);
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike_initial',`flags_extra`=130 WHERE `entry`=40029; -- Meteor Strike Initial
UPDATE `creature_template` SET `ScriptName`= 'npc_meteor_strike',`flags_extra`=130 WHERE `entry` IN (40041,40042,40043,40044); -- Meteor Strike
UPDATE `creature_template` SET `flags_extra`=130 WHERE `entry`=40055; -- Meteor Strike

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_meteor_strike_marker';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_fiery_combustion';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_soul_consumption';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_mark_of_combustion';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_mark_of_consumption';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_combustion_consumption_summon';
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_halion_combustion_consumption_damage_periodic_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(74641, 'spell_halion_meteor_strike_marker'),
(74562, 'spell_halion_fiery_combustion'),
(74792, 'spell_halion_soul_consumption'),
(74567, 'spell_halion_mark_of_combustion'),
(74795, 'spell_halion_mark_of_consumption'),
(74610, 'spell_halion_combustion_consumption_summon'),
(74800, 'spell_halion_combustion_consumption_summon'),
(74630, 'spell_halion_combustion_consumption_damage_periodic_aura'),
(74802, 'spell_halion_combustion_consumption_damage_periodic_aura');

DELETE FROM `creature` WHERE `id`=40146;
DELETE FROM `creature_text` WHERE `entry`=39863; 
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES 
(39863,0,0, 'Meddlesome insects! You are too late. The Ruby Sanctum is lost!',14,0,100,1,0,17499, 'Halion'),
(39863,1,0, 'Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!',14,0,100,0,0,17500, 'Halion'),
(39863,2,0, 'The heavens burn!',14,0,100,0,0,17505, 'Halion'),
(39863,3,0, 'You will find only suffering within the realm of twilight! Enter if you dare!',14,0,100,0,0,17507, 'Halion'),
(39863,4,0, 'Relish this victory, mortals, for it will be your last! This world will burn with the master''s return!',14,0,100,0,0,17503, 'Halion'),
(39863,5,0, 'Another "hero" falls.',14,0,100,0,0,17501, 'Halion'),
(40146,0,0, 'Beware the shadow!',14,0,100,0,0,17506, 'Halion'),
(40146,1,0, 'I am the light and the darkness! Cower, mortals, before the herald of Deathwing!',14,0,100,0,0,17502, 'Halion'), -- SoundID guessed
(40146,2,0, 'Not good enough.',14,0,100,0,0,17504, 'Halion');
*/

enum Texts
{
    SAY_INTRO                        = 0, // Meddlesome insects! You are too late. The Ruby Sanctum is lost!
    SAY_AGGRO                        = 1, // Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!
    SAY_METEOR_STRIKE                = 2, // The heavens burn!
    SAY_PHASE_TWO                    = 3, // You will find only suffering within the realm of twilight! Enter if you dare!
    SAY_DEATH                        = 4, // Relish this victory, mortals, for it will be your last! This world will burn with the master's return!
    SAY_KILL                         = 5, // Another "hero" falls.

    SAY_SPHERE_PULSE                 = 0, // Beware the shadow!
    SAY_PHASE_THREE                  = 1, // I am the light and the darkness! Cower, mortals, before the herald of Deathwing!
    SAY_KILL_TWO                     = 2, // Not good enough. 17504
};

enum Spells
{
    // Halion
    SPELL_FLAME_BREATH                  = 74525,
    SPELL_CLEAVE                        = 74524,
    SPELL_METEOR_STRIKE                 = 74637,

    SPELL_COMBUSTION                    = 74562,    // Will each tick, apart from the damage, also add a stack to 74567
    SPELL_MARK_OF_COMBUSTION            = 74567,    // If 74562 or 74567 is removed; this will trigger an explosion (74607) based on stackamount.
    SPELL_FIERY_COMBUSTION_EXPLOSION    = 74607,
    SPELL_FIERY_COMBUSTION_SUMMON       = 74610,
    SPELL_COMBUSTION_DAMAGE_AURA        = 74629,

    SPELL_COMBUSTION_CONSUMPTION_SCALE_AURA = 70507, // Aura created in spell_dbc since missing in client dbc. Value based on 74567 & 74795 stackamount.

    // Twilight Halion
    SPELL_DARK_BREATH                   = 74806,

    SPELL_CONSUMPTION                   = 74792,
    SPELL_MARK_OF_CONSUMPTION           = 74795,
    SPELL_SOUL_CONSUMPTION              = 74792,
    SPELL_SOUL_CONSUMPTION_EXPLOSION    = 74799,
    SPELL_SOUL_CONSUMPTION_SUMMON       = 74800,
    SPELL_CONSUMPTION_DAMAGE_AURA       = 74803,

    // Misc
    SPELL_TWILIGHT_DIVISION             = 75063,    // Phase spell from phase 2 to phase 3
    SPELL_TWILIGHT_SHIFT                = 57620,    // Phase spell from phase 1 to phase 2
    SPELL_TWILIGHT_REALM                = 74807,
    SPELL_LEAVE_TWILIGHT_REALM          = 74812,
    SPELL_TWILIGHT_PHASING              = 74808,    // Phase spell from phase 1 to phase 2
    SPELL_SUMMON_TWILIGHT_PORTAL        = 74809,    // Summons go 202794
    
    // Shadow Orb
    SPELL_TWILIGHT_PULSE_PERIODIC       = 78861,

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
};

enum Events
{
    // Halion
    EVENT_ACTIVATE_FIREWALL     = 1,
    EVENT_CLEAVE                = 2, // Used by Twilight Halion too
    EVENT_FLAME_BREATH          = 3,
    EVENT_METEOR_STRIKE         = 4,
    EVENT_FIERY_COMBUSTION      = 5,

    // Halion Controller
    EVENT_START_INTRO           = 6,
    EVENT_INTRO_PROGRESS_1      = 7,
    EVENT_INTRO_PROGRESS_2      = 8,
    EVENT_INTRO_PROGRESS_3      = 9,
    EVENT_CHECK_CORPOREALITY    = 10,
    EVENT_SHADOW_PULSARS_SHOOT  = 11,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME    = 12,

    // Twilight Halion
    EVENT_DARK_BREATH           = 13,
    EVENT_SOUL_CONSUMPTION      = 14,
};

enum Actions
{
    ACTION_METEOR_STRIKE_BURN   = 1, // Meteor Strike
    ACTION_METEOR_STRIKE_AOE    = 2,

    ACTION_PHASE_TWO            = 3, // Halion Controller
    ACTION_PHASE_THREE          = 4,
    ACTION_SHADOW_PULSARS_SHOOT = 5,
    ACTION_DESPAWN_ADDS         = 6,
};

enum Phases
{
    PHASE_ALL       = 0,
    PHASE_ONE       = 1,
    PHASE_TWO       = 2,
    PHASE_THREE     = 3,

    PHASE_ONE_MASK = 1 << PHASE_ONE,
    PHASE_TWO_MASK = 1 << PHASE_TWO,
    PHASE_THREE_MASK = 1 << PHASE_THREE,
};

enum Misc
{
    MARK_STACKAMOUNT        = 1,
    TWILIGHT_DAMAGE_TAKEN   = 2,
    MATERIAL_DAMAGE_TAKEN   = 3,
};

Position const HalionSpawnPos   = {3156.67f,  533.8108f, 72.98822f, 3.159046f};

Position const ShadowOrbsSpawnPos[4] =
{
    {3196.67f, 533.8108f, 73.24f, 3.160787f}, // North - On Heroic
    {3116.67f, 533.8108f, 72.91f, 6.264683f}, // South - On Heroic
    {3156.67f, 493.8108f, 72.58f, 1.593135f}, // East
    {3156.67f, 573.8108f, 72.89f, 4.659930f} //  West
};

class boss_halion : public CreatureScript
{
    public:
        boss_halion() : CreatureScript("boss_halion") { }

        struct boss_halionAI : public BossAI
        {
            boss_halionAI(Creature* creature) : BossAI(creature, DATA_HALION) 
            {
                instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth());
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD, me);
                instance->SetBossState(DATA_HALION, IN_PROGRESS);
                
                events.Reset();
                events.SetPhase(PHASE_ONE);
                events.ScheduleEvent(EVENT_ACTIVATE_FIREWALL, 10000);
                events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                events.ScheduleEvent(EVENT_FLAME_BREATH, urand(10000, 12000));
                events.ScheduleEvent(EVENT_METEOR_STRIKE, urand(20000, 25000));
                events.ScheduleEvent(EVENT_FIERY_COMBUSTION, urand(15000, 18000));
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                Talk(SAY_DEATH);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
                instance->SetBossState(DATA_HALION, DONE);

                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_DESPAWN_ADDS);
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
                instance->SetBossState(DATA_HALION, FAIL);
                instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth());
                
                if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->DoAction(ACTION_DESPAWN_ADDS);
            }

            Position const* GetMeteorStrikePosition() const { return &_meteorStrikePos; }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (me->GetHealth() - damage > 0)
                    instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth() - damage);

                if (me->HealthBelowPctDamaged(75, damage) && (events.GetPhaseMask() & PHASE_ONE_MASK))
                {
                    me->CastStop();
                    events.SetPhase(PHASE_TWO);
                    events.Reset();
                    DoCast(me, SPELL_TWILIGHT_PHASING);
                    Talk(SAY_PHASE_TWO);

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->DoAction(ACTION_PHASE_TWO);
                }

                if (events.GetPhaseMask() & PHASE_THREE_MASK)
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(MATERIAL_DAMAGE_TAKEN, damage);
            }

            void UpdateAI(uint32 const diff)
            {
                if (events.GetPhaseMask() & (PHASE_TWO_MASK | PHASE_THREE_MASK) && instance)
                    me->SetHealth(instance->GetData(DATA_HALION_SHARED_HEALTH));

                if ((events.GetPhaseMask() & (PHASE_ONE_MASK | PHASE_THREE_MASK)) && !UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;
                    
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ACTIVATE_FIREWALL:
                            // Firewall is activated 10 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                            if (GameObject* firewall = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FLAME_RING)))
                                instance->HandleGameObject(instance->GetData64(DATA_FLAME_RING), false, firewall);
                            break;
                        case EVENT_FLAME_BREATH:
                            DoCast(me, SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, 25000);
                            break;
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                            break;
                        case EVENT_METEOR_STRIKE:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
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
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_COMBUSTION);
                            if (!target) target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_COMBUSTION);
                            if (target)  DoCast(target, SPELL_COMBUSTION);
                            events.ScheduleEvent(EVENT_FIERY_COMBUSTION, 25000);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void setEventsPhase(uint32 p) { events.SetPhase(p); events.Reset(); me->CastStop(); }

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
                events.SetPhase(PHASE_TWO);
            }

            void EnterCombat(Unit* /*who*/) { events.Reset(); }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);

                victim->RemoveAurasDueToSpell(TWILIGHT_REALM_AURA); // Victims should not be in the Twilight Realm
            }

            void JustDied(Unit* killer)
            {
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    // Ensure looting
                    if (me->IsDamageEnoughForLootingAndReward())
                        halion->LowerPlayerDamageReq(halion->GetMaxHealth());

                    killer->Kill(halion); // Will trigger HalionAI::JustDied.
                }
                
                _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TWILIGHT_REALM);
            }

            void JustReachedHome()
            {
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, halion);

                events.Reset();

                // Let Halion Controller kill Twilight Halion
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                {
                    controller->Kill(me);
                    controller->AI()->DoAction(ACTION_DESPAWN_ADDS);
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if ((me->GetHealth() - damage) > 0)
                    _instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth() - damage);

                if (me->HealthBelowPctDamaged(50, damage) && (events.GetPhaseMask() & PHASE_TWO_MASK))
                {
                    events.SetPhase(PHASE_THREE);
                    events.Reset();
                    me->CastStop();
                    DoCast(me, SPELL_TWILIGHT_DIVISION);
                    Talk(SAY_PHASE_THREE);

                    if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->DoAction(ACTION_PHASE_THREE);

                    if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                    {
                        // Is this the best or the commented SpellHitTarget ?
                        // Leave this line for now
                        halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
                        if (HalionAI* halionAI = CAST_AI(HalionAI, halion->AI()))
                           halionAI->setEventsPhase(PHASE_THREE);
                    }
                }

                if (events.GetPhaseMask() & PHASE_THREE_MASK)
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->SetData(TWILIGHT_DAMAGE_TAKEN, damage);
            }

            // void SpellHitTarget(Unit* who, const SpellEntry* spell)
            // {
            //     if (spell->Id == SPELL_TWILIGHT_DIVISION)
            //         if (me->GetGUIDLow() == who->GetGUIDLow() && who == me)
            //             if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
            //                 halion->RemoveAurasDueToSpell(SPELL_TWILIGHT_PHASING);
            // }

            void UpdateAI(uint32 const diff)
            {
                if ((events.GetPhaseMask() & PHASE_THREE_MASK) && _instance)
                    me->SetHealth(_instance->GetData(DATA_HALION_SHARED_HEALTH));

                if ((events.GetPhaseMask() & (PHASE_TWO_MASK | PHASE_THREE_MASK)) && !UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DARK_BREATH:
                            DoCast(me, SPELL_DARK_BREATH);
                            events.ScheduleEvent(EVENT_DARK_BREATH, urand(10000, 15000));
                            break;
                        case EVENT_SOUL_CONSUMPTION:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true, -SPELL_SOUL_CONSUMPTION);
                            if (!target)  target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true, -SPELL_SOUL_CONSUMPTION);
                            if (target)   DoCast(target, SPELL_SOUL_CONSUMPTION);
                            events.ScheduleEvent(EVENT_SOUL_CONSUMPTION, 20000);
                            break;
                        }
                        case EVENT_CLEAVE:
                            DoCastVictim(SPELL_CLEAVE);
                            events.ScheduleEvent(EVENT_CLEAVE, urand(8000, 10000));
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void setEventsPhase(uint32 p) { events.SetPhase(p); events.Reset(); }

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

            // Let him count as summoner for various NPCs, making them dissapear at encounter failure or success.
            // Counting as summoner for:
            // - Combustion
            // - Consumption
            // - Shadow Orb
            // - Meteor Strike Initial
            // - Meteor Strike (N, S, E, W)
            void JustSummoned(Creature* who) { _summons.Summon(who); }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_INTRO_HALION:
                    {
                        me->setActive(true);
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_START_INTRO, 2000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_1, 6000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_2, 10000);
                        _events.ScheduleEvent(EVENT_INTRO_PROGRESS_3, 14000);
                        break;
                    }
                    case ACTION_PHASE_TWO:
                    {
                        me->setActive(true);
                        _events.Reset();
                        me->GetMap()->SummonCreature(NPC_TWILIGHT_HALION, HalionSpawnPos);
                        uint8 begin = 0;
                        if (me->GetMap()->IsHeroic())
                            begin = 2;
                        for (uint8 i = begin; i < 4; i++)
                        {
                            uint32 npcId;
                            switch (i)
                            {
                                default:
                                case 1: npcId = NPC_SHADOW_ORB_N; break;
                                case 2: npcId = NPC_SHADOW_ORB_S; break;
                                case 3: npcId = NPC_SHADOW_ORB_E; break;
                                case 4: npcId = NPC_SHADOW_ORB_W; break;
                            }
                            me->SummonCreature(npcId, ShadowOrbsSpawnPos[i]);
                        }
                        me->SummonCreature(NPC_ORB_ROTATION_FOCUS, HalionSpawnPos);
                        break;
                    }
                    case ACTION_PHASE_THREE:
                    {
                        me->setActive(true);
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 30000);
                        _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 5000);
                        TwilightDamageTaken = 0;
                        MaterialDamageTaken = 0;
                        TwilightCorporealityValue = 50;
                        MaterialCorporealityValue = 50;
                        break;
                    }
                    case ACTION_DESPAWN_ADDS:
                    {
                        _summons.DespawnAll();
                        me->setActive(false);
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
                            for (uint8 i = 2; i < 4; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(DATA_BURNING_TREE_1 + i)))
                                    _instance->HandleGameObject(_instance->GetData64(DATA_BURNING_TREE_1 + i), true, tree);
                            break;
                        case EVENT_INTRO_PROGRESS_2:
                            for (uint8 i = 0; i < 2; ++i)
                                if (GameObject* tree = ObjectAccessor::GetGameObject(*me, _instance->GetData64(DATA_BURNING_TREE_1 + i)))
                                    _instance->HandleGameObject(_instance->GetData64(DATA_BURNING_TREE_1 + i), true, tree);
                            break;
                        case EVENT_INTRO_PROGRESS_3:
                            DoCast(me, SPELL_FIERY_EXPLOSION);
                            if (Creature* halion = me->GetMap()->SummonCreature(NPC_HALION, HalionSpawnPos))
                                halion->AI()->Talk(SAY_INTRO);
                            me->setActive(false);
                            break;
                        case EVENT_SHADOW_PULSARS_SHOOT:
                            _events.ScheduleEvent(EVENT_SHADOW_PULSARS_SHOOT, 30000);
                            break;
                        case EVENT_CHECK_CORPOREALITY:
                            if (MaterialDamageTaken * 1.02f > TwilightDamageTaken)
                            {
                                TwilightDamageTaken = 0;
                                MaterialDamageTaken = 0;
                                TwilightCorporealityValue += 10;
                                MaterialCorporealityValue -= 10;
                            }
                            else if (TwilightDamageTaken * 1.02f > MaterialDamageTaken)
                            {
                                TwilightDamageTaken = 0;
                                MaterialDamageTaken = 0;
                                TwilightCorporealityValue -= 10;
                                MaterialCorporealityValue += 10;
                            }
                            if (TwilightCorporealityValue > 100) TwilightCorporealityValue = 100;
                            if (TwilightCorporealityValue < 0)   TwilightCorporealityValue = 0;
                            if (MaterialCorporealityValue > 100) MaterialCorporealityValue = 100;
                            if (MaterialCorporealityValue < 0)   MaterialCorporealityValue = 0;
                            // Todo: List buffs accordingly, then cast them on both Halion
                            _events.ScheduleEvent(EVENT_CHECK_CORPOREALITY, 15000);
                        default:
                            break;
                    }
                }
            }

            void SetData(uint32 id, uint32 value)
            {
                switch (id)
                {
                    case MATERIAL_DAMAGE_TAKEN:
                        MaterialDamageTaken += value;
                        break;
                    case TWILIGHT_DAMAGE_TAKEN:
                        TwilightDamageTaken += value;
                        break;
                }
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            SummonList _summons;
            uint32 TwilightDamageTaken;
            uint32 MaterialDamageTaken;
            uint32 TwilightCorporealityValue;
            uint32 MaterialCorporealityValue;
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
                    Position newpos;
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
                        me->GetNearPosition(newpos, 10.0f, 0.0f); // Exact distance
                        if (Creature* meteor = me->SummonCreature(NPC_METEOR_STRIKE_NORTH + i, newpos, TEMPSUMMON_TIMED_DESPAWN, 30000))
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
                        _spawnCount++;
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

class npc_combustion : public CreatureScript
{
    public:
        npc_combustion() : CreatureScript("npc_combustion") { }

        struct npc_combustionAI : public Scripted_NoMovementAI
        {
            npc_combustionAI(Creature* creature) : Scripted_NoMovementAI(creature),
                _instance(creature->GetInstanceScript())
            {
                me->SetPhaseMask(0x1, true);
                if (me->GetMap()->IsHeroic())
                    me->SetPhaseMask(creature->GetPhaseMask() | 0x20, true);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == MARK_STACKAMOUNT)
                {
                    int32 damage = 1200 + (data * 1290); // Hardcoded values from guessing. Need some more research.
                    me->CastCustomSpell(SPELL_FIERY_COMBUSTION_EXPLOSION, SPELLVALUE_BASE_POINT0, damage, me, true);

                    me->CastCustomSpell(SPELL_COMBUSTION_CONSUMPTION_SCALE_AURA, SPELLVALUE_AURA_STACK, data, me, false);
                    DoCast(me, SPELL_COMBUSTION_DAMAGE_AURA);

                    _scale = data;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case MARK_STACKAMOUNT:
                        return _scale;
                    default:
                        return 0;
                }
            }

            void UpdateAI(uint32 const /*diff*/) { }

        private:
            InstanceScript* _instance;
            uint32 _scale;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_combustionAI>(creature);
        }
};

class npc_consumption : public CreatureScript
{
    public:
        npc_consumption() : CreatureScript("npc_consumption") { }

        struct npc_consumptionAI : public Scripted_NoMovementAI
        {
            npc_consumptionAI(Creature* creature) : Scripted_NoMovementAI(creature),
                   _instance(creature->GetInstanceScript())
            {
                me->SetPhaseMask(0x20, true);
                if (me->GetMap()->IsHeroic())
                    me->SetPhaseMask(creature->GetPhaseMask() | 0x1, true);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == MARK_STACKAMOUNT)
                {
                    //if (Unit* owner = me->GetSummoner())
                    int32 damage = 1200 + (data * 1290); // Hardcoded values from guessing. Need some more research.
                    me->CastCustomSpell(SPELL_SOUL_CONSUMPTION_EXPLOSION, SPELLVALUE_BASE_POINT0, damage, me, true);

                    me->CastCustomSpell(SPELL_COMBUSTION_CONSUMPTION_SCALE_AURA, SPELLVALUE_AURA_STACK, data, me, false);
                    DoCast(me, SPELL_CONSUMPTION_DAMAGE_AURA); // This one's radius should scale.

                    _scale = data;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case MARK_STACKAMOUNT:
                        return _scale;
                    default:
                        return 0;
                }
            }

            void UpdateAI(uint32 const /*diff*/) { }

        private:
            InstanceScript* _instance;
            uint32 _scale;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_consumptionAI>(creature);
        }
};

class npc_shadow_orb : public CreatureScript
{
    public:
        npc_shadow_orb() : CreatureScript("npc_shadow_orb") { }

        struct npc_shadow_orbAI : public ScriptedAI
        {
            npc_shadow_orbAI(Creature* creature) : ScriptedAI(creature), 
                _instance(creature->GetInstanceScript())
            {
                _angle = 0.0f;
                me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                MovementInform(POINT_MOTION_TYPE, 0); // Start movement
                me->SetPhaseMask(0x20, true);
            }
            
            void IsSummonedBy(Unit* /*summoner*/)
            {
                // Let Halion Controller count as summoner
                if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                    controller->AI()->JustSummoned(me);
            }

            void UpdateAI(uint32 const /*diff*/) { }

            void MovementInform(uint32 type, uint32 /*id*/)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                float destinationX = HalionSpawnPos.GetPositionX() + 40 * cos(_angle);
                float destinationY = HalionSpawnPos.GetPositionY() + 40 * sin(_angle);
                me->GetMotionMaster()->MovePoint(1, destinationX, destinationY, 73.24f); // Find the correct Z coordinate
                _angle = (_angle >= 2 * M_PI) ? 0 : _angle + M_PI / 32;
            }

        private:
            InstanceScript* _instance;
            EventMap _events;
            float _angle;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_shadow_orbAI>(creature);
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
                {
                    if (Creature* creCaster = GetCaster()->ToCreature())
                        creCaster->AI()->DoAction(ACTION_METEOR_STRIKE_AOE);
                }
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
                if (!GetTarget())
                    return;

                if (GetTarget()->HasAura(SPELL_MARK_OF_COMBUSTION))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_COMBUSTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                // Todo: Move this to spell_linked_spell ?
                if (!GetTarget())
                    return;

                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_COMBUSTION, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                if (!GetTarget())
                    return;

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
                if (!GetTarget())
                    return;

                if (GetTarget()->HasAura(SPELL_MARK_OF_CONSUMPTION))
                    GetTarget()->RemoveAurasDueToSpell(SPELL_MARK_OF_CONSUMPTION, 0, 0, AURA_REMOVE_BY_ENEMY_SPELL);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                // Todo: Move this to spell_linked_spell ?
                if (!GetTarget())
                    return;

                GetTarget()->CastSpell(GetTarget(), SPELL_MARK_OF_CONSUMPTION, true);
            }

            void AddMarkStack(AuraEffect const* /*aurEff*/)
            {
                if (!GetTarget())
                    return;

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
                if (!GetTarget())
                    return;

                GetTarget()->CastCustomSpell(SPELL_FIERY_COMBUSTION_SUMMON, SPELLVALUE_BASE_POINT0, aurEff->GetBase()->GetStackAmount(), GetTarget(), true);
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
                if (!GetTarget())
                    return;

                GetTarget()->CastCustomSpell(SPELL_SOUL_CONSUMPTION_SUMMON, SPELLVALUE_BASE_POINT0, aurEff->GetBase()->GetStackAmount(), GetTarget(), true);
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

                Position pos;
                caster->GetPosition(&pos);
                if (TempSummon* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
                    summon->AI()->SetData(MARK_STACKAMOUNT, uint32(GetSpellInfo()->Effects[effIndex].BasePoints));
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_halion_combustion_consumption_summon_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_combustion_consumption_summon_SpellScript();
        }
};

class CombustionConsumptionDamageSelector
{
    public:
        explicit CombustionConsumptionDamageSelector(Creature* owner) : _owner(owner) { }

        bool operator()(Unit* unit)
        {
            if (uint32 scale = _owner->AI()->GetData(MARK_STACKAMOUNT))
                if (unit->GetTypeId() == TYPEID_PLAYER)
                    if (unit->IsWithinDistInMap(_owner, float(12 * (1 + scale / 10)))) // Guessing
                        return false;
            return true;
        }

    private:
        Creature* _owner;
};

class spell_halion_combustion_consumption_damage_periodic_aura : public SpellScriptLoader
{
    public:
        spell_halion_combustion_consumption_damage_periodic_aura() : SpellScriptLoader("spell_halion_combustion_consumption_damage_periodic_aura") { }

        class spell_halion_combustion_consumption_damage_periodic_aura_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_halion_combustion_consumption_damage_periodic_aura_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                if (Unit* caster = GetCaster())
                    if (Creature* creCaster = caster->ToCreature())
                        unitList.remove_if(CombustionConsumptionDamageSelector(creCaster));
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_halion_combustion_consumption_damage_periodic_aura_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_halion_combustion_consumption_damage_periodic_aura_SpellScript();
        }
};

void AddSC_boss_halion()
{
    new boss_halion();
    new boss_twilight_halion();

    new npc_halion_controller();
    new npc_meteor_strike_initial();
    new npc_meteor_strike();
    new npc_combustion();
    new npc_consumption();
    new npc_shadow_orb();

    new spell_halion_meteor_strike_marker();
    new spell_halion_combustion_consumption_summon();
    new spell_halion_mark_of_combustion();
    new spell_halion_mark_of_consumption();
    new spell_halion_fiery_combustion();
    new spell_halion_soul_consumption();
    new spell_halion_combustion_consumption_damage_periodic_aura();
}
