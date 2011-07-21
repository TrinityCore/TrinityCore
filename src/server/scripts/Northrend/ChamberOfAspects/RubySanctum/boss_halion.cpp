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
(70507,0x00000100,0x00000400,0x0,1,101,21,1,100,6,2,1,61,1, 'Halion - Combustion & Consumption Scale Aura'),

UPDATE `creature` SET `spawntimesecs`=604800 WHERE `id` IN (39751,39746,39747);
UPDATE `gameobject` SET `phaseMask`=`phaseMask`|0x20 WHERE `id`=203007; -- Ruby Sanctum Halion Flame Ring

UPDATE `creature_template` SET `scale`=1,`exp`=2,`baseattacktime`=2000,`unit_flags`=33554432 WHERE `entry`=40135; -- Consumption
UPDATE `creature_template` SET `scale`=1,`flags_extra`=130,`ScriptName`= 'npc_combustion' WHERE `entry`=40001; -- Combustion
UPDATE `creature_model_info` SET `bounding_radius`=3.8,`combat_reach`=7.6,`gender`=2 WHERE `modelid`=16946;
UPDATE `creature_template` SET `ScriptName`= 'boss_halion' WHERE `entry`=39863;
UPDATE `creature_template` SET `ScriptName`= 'boss_twilight_halion' WHERE `entry`=40142;
UPDATE `creature_template` SET `ScriptName`= 'npc_halion_controller' WHERE `entry`=40146;
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
(39863,3,0, 'You will find only suffering within the realm of twilight! Enter if you dare!',14,0,100,0,0,17507, 'Halion');
*/

enum Texts
{
    SAY_INTRO                        = 0, // Meddlesome insects! You are too late. The Ruby Sanctum is lost!
    SAY_AGGRO                        = 1, // Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!
    SAY_METEOR_STRIKE                = 2, // The heavens burn!
    SAY_PHASE_TWO                    = 3, // You will find only suffering within the realm of twilight! Enter if you dare!
    SAY_DEATH                        = 4, // Relish this victory, mortals, for it will be your last! This world will burn with the master's return! (17503)
    // Beware the shadow! (17506)
    // I am the light and the darkness! Cower, mortals, before the herald of Deathwing!
    // Not good enough. 17504
    // Another "hero" falls. 17501
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
    
    SPELL_CONSUMPTION                   = 74792,
    SPELL_MARK_OF_CONSUMPTION           = 74795,
    SPELL_SOUL_CONSUMPTION              = 74792,
    SPELL_SOUL_CONSUMPTION_EXPLOSION    = 74799,
    SPELL_SOUL_CONSUMPTION_SUMMON       = 74800,
    SPELL_CONSUMPTION_DAMAGE_AURA       = 74803,

    // Misc
    SPELL_TWILIGHT_DIVISION             = 75063,    // Phase spell from phase 1 to phase 2
    SPELL_TWILIGHT_SHIFT                = 57620,    // Phase spell to go on phase 3 - So why 2 NPCs ?
    SPELL_TWILIGHT_REALM                = 74807,
    SPELL_TWILIGHT_PHASING              = 74808, // Same visual ad 75063, plus immunity and morphing
    SPELL_SUMMON_TWILIGHT_PORTAL        = 74809, // Summons go 202794
    
    // Unknwon purpose for now
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
    EVENT_CLEAVE                = 2,
    EVENT_FLAME_BREATH          = 3,
    EVENT_METEOR_STRIKE         = 4,
    EVENT_FIERY_COMBUSTION      = 5,

    // Halion Controller
    EVENT_START_INTRO           = 6,
    EVENT_INTRO_PROGRESS_1      = 7,
    EVENT_INTRO_PROGRESS_2      = 8,
    EVENT_INTRO_PROGRESS_3      = 9,

    // Meteor Strike
    EVENT_SPAWN_METEOR_FLAME    = 10,

    // Twilight Halion
    EVENT_CLEAVE                = 11,
    EVENT_DARK_BREATH           = 12,
    EVENT_SOUL_CONSUMPTION      = 13,
};

enum Actions
{
    ACTION_METEOR_STRIKE_BURN   = 1, // Meteor Strike
    ACTION_METEOR_STRIKE_AOE    = 2, // Meteor Strike

    ACTION_PHASE_TWO            = 3, // Halion Controller
    ACTION_PHASE_THREE          = 4,
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
};

Position const HalionSpawnPos   = {3156.67f,  533.8108f, 72.98822f, 3.159046f};

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
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ADD, me);
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
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, me);
                instance->SetBossState(DATA_HALION, FAIL);
            }

            Position const* GetMeteorStrikePosition() const
            {
                return &_meteorStrikePos;
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (me->GetHealth() - damage > 0)
                    instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth() - damage);

                if (me->HealthBelowPctDamaged(75, damage) && (events.GetPhaseMask() & PHASE_ONE_MASK))
                {
                    DoCast(me, SPELL_TWILIGHT_SHIFT);
                    Talk(SAY_PHASE_TWO);
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->DoAction(ACTION_PHASE_TWO);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if ((events.GetPhaseMask() & (PHASE_ONE_MASK | PHASE_THREE_MASK)) && !UpdateVictim())
                    return;

                me->SetHealth(instance->GetData(DATA_HALION_SHARED_HEALTH));

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ACTIVATE_FIREWALL:
                            // Firewall is activated 10 seconds after starting encounter, DOOR_TYPE_ROOM is only instant.
                            if (GameObject* firewall = ObjectAccessor::GetGameObject(*me, instance->GetData64(DATA_FLAME_RING)))
                                instance->HandleGameObject(instance->GetData64(DATA_FLAME_RING), false, firewall);
                            // Todo :find the twilight firewall or modify its spawnmask.
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
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                            if (target)
                                DoCast(target, SPELL_COMBUSTION);
                            events.ScheduleEvent(EVENT_FIERY_COMBUSTION, 25000);
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
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
            boss_twilight_halionAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetPhaseMask(me->GetPhaseMask() | 0x20, true);
                _instance = creature->GetInstanceScript();
                events.SetPhase(PHASE_TWO);
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.Reset();
            }

            void JustDied(Unit* killer)
            {
                Talk(SAY_DEATH);
                
                if (Creature* halion = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION)))
                {
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_REMOVE, halion);
                    // Ensure looting
                    if (me->IsDamageEnoughForLootingAndReward())
                        halion->LowerPlayerDamageReq(halion->GetMaxHealth());
                        
                    killer->Kill(halion);
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
                    controller->Kill(me);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (me->GetHealth() - damage > 0)
                    _instance->SetData(DATA_HALION_SHARED_HEALTH, me->GetHealth() - damage);

                if (me->HealthBelowPctDamaged(50, damage) && (events.GetPhaseMask() & PHASE_TWO_MASK))
                {
                    events.SetPhase(PHASE_THREE);
                    DoCast(me, SPELL_TWILIGHT_DIVISION);
                    if (Creature* controller = ObjectAccessor::GetCreature(*me, _instance->GetData64(DATA_HALION_CONTROLLER)))
                        controller->AI()->DoAction(ACTION_PHASE_THREE);
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if ((events.GetPhaseMask() & (PHASE_TWO_MASK | PHASE_THREE_MASK)) && !UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
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
                _instance(creature->GetInstanceScript())
            {
                me->SetPhaseMask(me->GetPhaseMask() | 0x20, true);
            }

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
            }

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
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_halion_controllerAI>(creature);
        }
};

class npc_meteor_strike_initial : public CreatureScript
{
    public:
        npc_meteor_strike_initial() : CreatureScript("npc_meteor_strike_initial") { }

        struct npc_meteor_strike_initialAI : public Scripted_NoMovementAI
        {
            npc_meteor_strike_initialAI(Creature* creature) : Scripted_NoMovementAI(creature) { }

            void DoAction(int32 const action)
            {
                if (action == ACTION_METEOR_STRIKE_AOE)
                {
                    DoCast(me, SPELL_METEOR_STRIKE_AOE_DAMAGE, true);
                    DoCast(me, SPELL_METEOR_STRIKE_FIRE_AURA_1, true);
                    for (std::list<Creature*>::iterator itr = _meteorList.begin(); itr != _meteorList.end(); ++itr)
                        (*itr)->AI()->DoAction(ACTION_METEOR_STRIKE_BURN);
                }
            }

            void IsSummonedBy(Unit* summoner)
            {
                _owner = summoner->ToCreature();
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

            void UpdateAI(uint32 const /*diff*/) {}
            void EnterEvadeMode() {}

        private:
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
            npc_meteor_strikeAI(Creature* creature) : Scripted_NoMovementAI(creature)
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
                        flame->CastSpell(flame, SPELL_METEOR_STRIKE_FIRE_AURA_2, true);
                        _spawnCount++;
                    }
                    _range += 5.0f;
                    _events.ScheduleEvent(EVENT_SPAWN_METEOR_FLAME, 800);
                }
            }

        private:
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
            npc_combustionAI(Creature* creature) : Scripted_NoMovementAI(creature) { }

            void SetData(uint32 type, uint32 data)
            {
                if (type == MARK_STACKAMOUNT)
                {
                    int32 damage = 1200 + (data * 1290); // Hardcoded values from guessing. Need some more research.
                    me->CastCustomSpell(SPELL_FIERY_COMBUSTION_EXPLOSION, SPELLVALUE_BASE_POINT0, damage, me, true);
                    // Scaling aura
                    me->CastCustomSpell(SPELL_COMBUSTION_CONSUMPTION_SCALE_AURA, SPELLVALUE_AURA_STACK, data, me, false);
                    DoCast(me, SPELL_COMBUSTION_DAMAGE_AURA);
                    // Save scale for range selection
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
            npc_consumptionAI(Creature* creature) : Scripted_NoMovementAI(creature) { }

            void SetData(uint32 type, uint32 data)
            {
                if (type == MARK_STACKAMOUNT)
                {
                    //if (Unit* owner = me->GetSummoner())
                    int32 damage = 1200 + (data * 1290); // Hardcoded values from guessing. Need some more research.
                    me->CastCustomSpell(SPELL_SOUL_CONSUMPTION_EXPLOSION, SPELLVALUE_BASE_POINT0, damage, me, true);
                    // Scaling aura
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
            uint32 _scale;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<npc_consumptionAI>(creature);
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
                if (!sSpellStore.LookupEntry(SPELL_MARK_OF_COMBUSTION))
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
                if (!sSpellStore.LookupEntry(SPELL_MARK_OF_CONSUMPTION))
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
                if (!sSpellStore.LookupEntry(SPELL_FIERY_COMBUSTION_SUMMON))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_FIERY_COMBUSTION_EXPLOSION))
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

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_SOUL_CONSUMPTION_SUMMON))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_SOUL_CONSUMPTION_EXPLOSION))
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
                uint32 entry = uint32(GetSpellInfo()->EffectMiscValue[effIndex]);
                SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(uint32(GetSpellInfo()->EffectMiscValueB[effIndex]));
                uint32 duration = uint32(GetSpellDuration(GetSpellInfo()));

                Position pos;
                caster->GetPosition(&pos);
                if (TempSummon* summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, caster, GetSpellInfo()->Id))
                    summon->AI()->SetData(MARK_STACKAMOUNT, uint32(GetSpellInfo()->EffectBasePoints[effIndex]));
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

class CombustionConsumptionPeriodicDamageSelector
{
    public:
        explicit CombustionConsumptionPeriodicDamageSelector(Creature* owner) : _owner(owner) { }

        bool operator()(Unit* unit)
        {
            if (uint32 scale = _owner->AI()->GetData(MARK_STACKAMOUNT))
                if (unit->GetTypeId() == TYPEID_PLAYER)
                    if (unit->IsWithinDistInMap(_owner, float(12 * (1 + scale / 10))))
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
                        unitList.remove_if(CombustionConsumptionPeriodicDamageSelector(creCaster));
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

    new spell_halion_meteor_strike_marker();
    new spell_halion_combustion_consumption_summon();
    new spell_halion_mark_of_combustion();
    new spell_halion_mark_of_consumption();
    new spell_halion_fiery_combustion();
    new spell_halion_soul_consumption();
    new spell_halion_combustion_consumption_damage_periodic_aura();
}

