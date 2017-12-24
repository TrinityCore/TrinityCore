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
#include "GridNotifiers.h"
#include "halls_of_origination.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    ANRAPHET_SAY_INTRO              = 0,
    ANRAPHET_SAY_AGGRO              = 1,
    ANRAPHET_SAY_OMEGA_STANCE       = 2,
    ANRAPHET_SAY_KILL               = 3,
    ANRAPHET_SAY_DEATH              = 4,

    BRANN_SAY_DOOR_INTRO            = 0,  // Right, let's go! Just need to input the final entry sequence into the door mechanism... and...
    BRANN_SAY_UNLOCK_DOOR           = 1,  // That did the trick! The control room should be right behind this... oh... wow...
    BRANN_SAY_TROGGS                = 2,  // What? This isn't the control room! There's another entire defense mechanism in place, and the blasted Rock Troggs broke into here somehow. Troggs. Why did it have to be Troggs!
    BRANN_SAY_THINK                 = 3,  // Ok, let me think a moment.
    BRANN_SAY_MIRRORS               = 4,  // Mirrors pointing all over the place.
    BRANN_SAY_ELEMENTALS            = 5,  // Four platforms with huge elementals.
    BRANN_SAY_GET_IT                = 6,  // I got it! I saw a tablet that mentioned this chamber. This is the Vault of Lights! Ok, simple enough. I need you adventurers to take out each of the four elementals to trigger the opening sequence for the far door!
    BRANN_1_ELEMENTAL_DEAD          = 7,  // One down!
    BRANN_2_ELEMENTAL_DEAD          = 8,  // Another one down! Just look at those light beams! They seem to be connecting to the far door!
    BRANN_3_ELEMENTAL_DEAD          = 9,  // One more elemental to go! The door is almost open!
    BRANN_4_ELEMENTAL_DEAD          = 10, // That''s it, you''ve done it! The vault door is opening! Now we can... oh, no!
    BRANN_SAY_ANRAPHET_DIED         = 11, // We''ve done it! The control room is breached!
    BRANN_SAY_MOMENT                = 12, // Here we go! Now this should only take a moment...
    BRANN_SAY_BLASTED_TITANS        = 13, // Blasted titans... Why do they use a different set of mechanisms at each of their installations?
    BRANN_SAY_THIS_SYMBOL           = 14  // This symbol, I think I've seen this before...
};

enum Gossip
{
    GOSSIP_MENU_NO_TIME_TO_WASTE    = 11339, // Great, ye found yer way here!$b$bNo time to waste. Ye ready?
    GOSSIP_OPTION_WE_ARE_READY      = 0,     //   We're ready! Go, Brann!
    GOSSIP_MENU_DESTROY_ELEMENTAL   = 11348, // Yep, destroy the four elementals, then the door will open. ...
    GOSSIP_MENU_OCH_ITS_NOT_EASY    = 12512  // Och!$b$bWhy can''t it just be easy fer once?!
};

enum Events
{
    EVENT_BRANN_IDLE_EMOTE             = 1,
    EVENT_BRANN_START_INTRO            = 2,
    EVENT_BRANN_UNLOCK_DOOR            = 3,
    EVENT_BRANN_MOVE_INTRO             = 4,
    EVENT_BRANN_THINK                  = 5,
    EVENT_BRANN_LOOK_RIGHT             = 6,
    EVENT_BRANN_LOOK_LEFT              = 7,
    EVENT_BRANN_SAY_ELEMENTALS         = 8,
    EVENT_BRANN_SAY_GET_IT             = 9,
    EVENT_BRANN_SET_FLAG_GOSSIP        = 10,
    EVENT_BRANN_ACTIVATE_LASERBEAMS    = 11,
    EVENT_BRANN_SAY_ALL_ELEMENTAL_DEAD = 12,
    EVENT_BRANN_MOVE_OUTRO             = 13,
    EVENT_BRANN_MOVE_FINAL             = 14,
    EVENT_BRANN_TURN_BACK              = 15,
    EVENT_ANRAPHET_APPEAR              = 16,
    EVENT_ANRAPHET_ACTIVATE            = 17,
    EVENT_ANRAPHET_DESTRUCTION         = 18,
    EVENT_ANRAPHET_READY               = 19,
    EVENT_ANRAPHET_NEMESIS_STRIKE      = 20,
    EVENT_ANRAPHET_ALPHA_BEAMS         = 21,
    EVENT_ANRAPHET_OMEGA_STANCE        = 22,
    EVENT_ANRAPHET_CRUMBLING_RUIN      = 23,
    EVENT_ANRAPHET_ACTIVATE_OMEGA      = 24
};

enum Spells
{
    SPELL_DESTRUCTION_PROTOCOL          = 77437,

    SPELL_ALPHA_BEAMS                   = 76184,
    SPELL_ALPHA_BEAMS_BACK_CAST         = 76912,

    SPELL_CRUMBLING_RUIN                = 75609,


    SPELL_NEMESIS_STRIKE                = 75604,

    SPELL_OMEGA_STANCE_SUMMON           = 77106,
    SPELL_OMEGA_STANCE                  = 75622,
    SPELL_OMEGA_STANCE_SPIDER_TRIGGER   = 77121
};

enum Phases
{
    PHASE_INTRO         = 1,
    PHASE_COMBAT        = 2
};

enum Points
{
    POINT_ANRAPHET_ACTIVATE,
    POINT_BRANN_SAY_TROGGS, 
    POINT_BRANN_SAY_MOMENT,
    POINT_BRANN_TURN_BACK
};

// Anraphet's intro
Position const AnraphetActivatePos = { -193.656f, 366.689f, 75.91001f, 3.138207f };

uint32 const AnraphetPathSize = 6;
Position const AnraphetPath[AnraphetPathSize] =
{
    { -125.4643f, 366.5138f, 89.88697f },
    { -132.7143f, 366.5138f, 89.88697f },
    { -143.9643f, 366.5138f, 89.88697f },
    { -159.2143f, 366.5138f, 85.38697f },
    { -188.2143f, 366.7638f, 76.38697f },
    { -193.656f,  366.689f,  75.91001f }
};

// Brann's intro
Position const BrannBossHomePos = { -429.583f, 367.019f, 89.79282f, 0.01745329f };

// Brann's outro
uint32 const BrannOutroPathSize = 13;
Position const BrannOutroPath[BrannOutroPathSize] =
{
    { -409.9531f, 367.0469f, 89.81111f, 0.0f },
    { -397.8246f, 366.967f,  86.37722f, 0.0f },
    { -383.7813f, 366.8229f, 82.07919f, 0.0f },
    { -368.2604f, 366.7448f, 77.0984f,  0.0f },
    { -353.6458f, 366.4896f, 75.92504f, 0.0f },
    { -309.0608f, 366.7205f, 75.91345f, 0.0f },
    { -276.3303f, 367.0f,    75.92413f, 0.0f },
    { -246.5104f, 366.6389f, 75.87791f, 0.0f },
    { -202.0417f, 366.7517f, 75.92508f, 0.0f },
    { -187.6024f, 366.7656f, 76.23077f, 0.0f },
    { -155.0938f, 366.783f,  86.45834f, 0.0f },
    { -143.5694f, 366.8177f, 89.73354f, 0.0f },
    { -128.5608f, 366.8629f, 89.74199f, 0.0f }
};

Position const BrannFinalHomePos = { -35.04861f, 366.6563f, 89.77447f, 3.141593f };

uint32 const BrannFinalPathSize = 3;
Position const BrannFinalPath[BrannFinalPathSize] =
{
    { -103.559f,  366.5938f, 89.79725f, 0.0f },
    { -71.58507f, 367.0278f, 89.77069f, 0.0f },
    { -35.04861f, 366.6563f, 89.77447f, 0.0f }
};

class boss_anraphet : public CreatureScript
{
public:
    boss_anraphet() : CreatureScript("boss_anraphet") { }

    struct boss_anraphetAI : public BossAI
    {
        boss_anraphetAI(Creature* creature) : BossAI(creature, DATA_ANRAPHET) { }

        void Reset() override
        {
            _Reset();

            // Vault of Lights not yet done?
            if (instance->GetData(DATA_DEAD_ELEMENTALS) < 4)
                return;
 
            me->SetHomePosition(AnraphetActivatePos);
            me->GetMotionMaster()->MoveTargetedHome();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            events.SetPhase(PHASE_COMBAT);
            ScheduleCombatEvents();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
            Talk(ANRAPHET_SAY_AGGRO);
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            Talk(ANRAPHET_SAY_DEATH);

            if (Creature* brann = instance->GetCreature(DATA_BRANN_0))
                brann->AI()->DoAction(ACTION_ANRAPHET_DIED);

            _JustDied();
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(ANRAPHET_SAY_KILL);
        }

        void JustReachedHome() override
        {
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            _JustReachedHome();
            instance->SetBossState(DATA_ANRAPHET, FAIL);
        }

        void DoAction(int32 action) override
        {
            if (action != ACTION_ANRAPHET_INTRO)
                return;
            
            // Intro
            events.SetPhase(PHASE_INTRO);
            events.ScheduleEvent(EVENT_ANRAPHET_APPEAR, Seconds(6), 0, PHASE_INTRO); // Note: 5800 ms
        }

        void MovementInform(uint32 type, uint32 point) override
        {
            if (type != EFFECT_MOTION_TYPE || point != POINT_ANRAPHET_ACTIVATE)
                return;

            // Activate point
            me->SetHomePosition(AnraphetActivatePos);
            events.ScheduleEvent(EVENT_ANRAPHET_ACTIVATE, Seconds(1), 0, PHASE_INTRO);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!events.IsInPhase(PHASE_INTRO) && (!UpdateVictim() || !CheckInRoom()))
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_ANRAPHET_APPEAR:
                        me->GetMotionMaster()->MoveSmoothPath(POINT_ANRAPHET_ACTIVATE, AnraphetPath, AnraphetPathSize);
                        break;
                    case EVENT_ANRAPHET_ACTIVATE:
                        Talk(ANRAPHET_SAY_INTRO);
                        events.ScheduleEvent(EVENT_ANRAPHET_DESTRUCTION, Seconds(10), 0, PHASE_INTRO); // Note: 10800 ms
                        break;
                    case EVENT_ANRAPHET_DESTRUCTION:
                        DoCastAOE(SPELL_DESTRUCTION_PROTOCOL);
                        events.ScheduleEvent(EVENT_ANRAPHET_READY, Seconds(6), 0, PHASE_INTRO); // Note: 6400 ms
                        break;
                    case EVENT_ANRAPHET_READY:
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        events.SetPhase(PHASE_COMBAT);
                        ScheduleCombatEvents();
                        break;
                    case EVENT_ANRAPHET_NEMESIS_STRIKE:
                        DoCastVictim(SPELL_NEMESIS_STRIKE);
                        events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, Seconds(21), 0, PHASE_COMBAT);
                        break;
                    case EVENT_ANRAPHET_ALPHA_BEAMS:
                        DoCastSelf(SPELL_ALPHA_BEAMS);
                        events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, Seconds(12), 0, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, Seconds(40), Seconds(45), 0, PHASE_COMBAT);
                        break;
                    case EVENT_ANRAPHET_OMEGA_STANCE:
                        DoCastSelf(SPELL_OMEGA_STANCE_SUMMON);
                        DoCastSelf(SPELL_OMEGA_STANCE);
                        Talk(ANRAPHET_SAY_OMEGA_STANCE);
                        events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, Seconds(45), Seconds(50), 0, PHASE_COMBAT);
                        events.ScheduleEvent(EVENT_ANRAPHET_CRUMBLING_RUIN, Seconds(13), 0, PHASE_COMBAT);
                        break;
                    case EVENT_ANRAPHET_CRUMBLING_RUIN:
                        DoCastSelf(SPELL_CRUMBLING_RUIN);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            if (UpdateVictim())
                DoMeleeAttackIfReady();
        }

    private:
        void ScheduleCombatEvents()
        {
            events.ScheduleEvent(EVENT_ANRAPHET_NEMESIS_STRIKE, Seconds(8), 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_ANRAPHET_ALPHA_BEAMS, Seconds(10), 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_ANRAPHET_OMEGA_STANCE, Seconds(35), 0, PHASE_COMBAT);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfOriginationAI<boss_anraphetAI>(creature);
    }
};

class npc_omega_stance : public CreatureScript
{
    public:
        npc_omega_stance() : CreatureScript("npc_omega_stance") { }

        struct npc_omega_stanceAI : public ScriptedAI
        {
            npc_omega_stanceAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*who*/) override
            {
                DoCastSelf(SPELL_OMEGA_STANCE_SPIDER_TRIGGER, true);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfOriginationAI<npc_omega_stanceAI>(creature);
        }
};

class npc_alpha_beam : public CreatureScript
{
    public:
        npc_alpha_beam() : CreatureScript("npc_alpha_beam") { }

        struct npc_alpha_beamAI : public ScriptedAI
        {
            npc_alpha_beamAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                if (Creature* anraphet = _instance->GetCreature(DATA_ANRAPHET))
                    anraphet->CastSpell(me, SPELL_ALPHA_BEAMS_BACK_CAST);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override { } // Never evade

            private:
                InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfOriginationAI<npc_alpha_beamAI>(creature);
        }
};

class npc_brann_bronzebeard_anraphet : public CreatureScript
{
    public:
        npc_brann_bronzebeard_anraphet() : CreatureScript("npc_brann_bronzebeard_anraphet") { }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;
    
            // What gossip menu shall we send?
            uint32 gossipMenuId = GOSSIP_MENU_NO_TIME_TO_WASTE;

            if (instance->GetBossState(DATA_VAULT_OF_LIGHTS) != DONE) // gossipMenuId already set, only add gossip option
                AddGossipItemFor(player, gossipMenuId, GOSSIP_OPTION_WE_ARE_READY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
            else if (instance->GetBossState(DATA_ANRAPHET) != DONE)
                gossipMenuId = GOSSIP_MENU_DESTROY_ELEMENTAL;
            else
                gossipMenuId = GOSSIP_MENU_OCH_ITS_NOT_EASY;
            
            SendGossipMenuFor(player, player->GetGossipTextId(gossipMenuId, creature), creature->GetGUID());
            return true;
        }

        struct npc_brann_bronzebeard_anraphetAI : public CreatureAI
        {
            npc_brann_bronzebeard_anraphetAI(Creature* creature) : CreatureAI(creature), _instance(creature->GetInstanceScript()) { }

            void Reset() override
            {
                if (_instance->GetBossState(DATA_VAULT_OF_LIGHTS) != DONE) // Vault of Lights not yet started?
                    events.ScheduleEvent(EVENT_BRANN_IDLE_EMOTE, Seconds(45));
                else if (_instance->GetBossState(DATA_ANRAPHET) != DONE) // Anraphet not yet killed?
                    me->SetHomePosition(BrannBossHomePos);
                else
                    me->SetHomePosition(BrannFinalHomePos);

                me->GetMotionMaster()->MoveTargetedHome();
            }

            void sGossipSelect(Player* /*player*/, uint32 /*menuId*/, uint32 /*gossipListId*/) override
            {
                if (_instance->GetBossState(DATA_VAULT_OF_LIGHTS) == DONE)
                    return;

                _instance->SetBossState(DATA_VAULT_OF_LIGHTS, IN_PROGRESS);
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                events.Reset(); // Removes EVENT_BRANN_IDLE_EMOTE.
                events.ScheduleEvent(EVENT_BRANN_START_INTRO, Seconds(1));
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_ELEMENTAL_DIED:
                    {
                        uint32 dead = _instance->GetData(DATA_DEAD_ELEMENTALS);
                        if (dead < 4) // Say that an elemental has died.
                            Talk(BRANN_1_ELEMENTAL_DEAD + dead - 1);
                        else // Cast achievement credit rightaway.
                            _instance->DoCastSpellOnPlayers(SPELL_VAULT_OF_LIGHTS_CREDIT);
                        events.RescheduleEvent(EVENT_BRANN_ACTIVATE_LASERBEAMS, Seconds(9));
                        break;
                    }
                    case ACTION_ANRAPHET_DIED:
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        events.ScheduleEvent(EVENT_BRANN_MOVE_OUTRO, Seconds(5));
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BRANN_IDLE_EMOTE:
                            Talk(urand(0, 1) ? BRANN_SAY_BLASTED_TITANS : BRANN_SAY_THIS_SYMBOL);
                            events.Repeat(Seconds(45));
                            break;
                        case EVENT_BRANN_START_INTRO:
                            Talk(BRANN_SAY_DOOR_INTRO);
                            events.ScheduleEvent(EVENT_BRANN_UNLOCK_DOOR, Seconds(7));
                            break;
                        case EVENT_BRANN_UNLOCK_DOOR:
                            Talk(BRANN_SAY_UNLOCK_DOOR);
                            _instance->SetBossState(DATA_VAULT_OF_LIGHTS, DONE);
                            _instance->DoStartCriteriaTimer(CRITERIA_TIMED_TYPE_EVENT, ACHIEV_VAULT_OF_LIGHTS_EVENT);
                            events.ScheduleEvent(EVENT_BRANN_MOVE_INTRO, Seconds(3));
                            break;
                        case EVENT_BRANN_MOVE_INTRO:
                            //me->GetMotionMaster()->MoveSmoothPath(POINT_BRANN_SAY_TROGGS, BrannIntroPath, BrannIntroPathSize, true);
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(POINT_BRANN_SAY_TROGGS, BrannBossHomePos, true);
                            break;
                        case EVENT_BRANN_THINK:
                            Talk(BRANN_SAY_THINK);
                            events.ScheduleEvent(EVENT_BRANN_LOOK_RIGHT, Seconds(6));
                            break;
                        case EVENT_BRANN_LOOK_RIGHT:
                            me->SetFacingTo(DegToRad(312.0f)); // Sniff: o = 5.445427f
                            Talk(BRANN_SAY_MIRRORS);
                            events.ScheduleEvent(EVENT_BRANN_LOOK_LEFT, Seconds(1));
                            break;
                        case EVENT_BRANN_LOOK_LEFT:
                            me->SetFacingTo(DegToRad(36.0f)); // Sniff: o = 0.6283185f
                            events.ScheduleEvent(EVENT_BRANN_SAY_ELEMENTALS, Seconds(3));
                            break;
                        case EVENT_BRANN_SAY_ELEMENTALS:
                            me->SetFacingTo(DegToRad(1.0f)); // Sniff: o = 0.01745329f
                            Talk(BRANN_SAY_ELEMENTALS);
                            events.ScheduleEvent(EVENT_BRANN_SAY_GET_IT, Seconds(4));
                            break;
                        case EVENT_BRANN_SAY_GET_IT:
                            Talk(BRANN_SAY_GET_IT);
                            events.ScheduleEvent(EVENT_BRANN_SET_FLAG_GOSSIP, Seconds(16));
                            break;
                        case EVENT_BRANN_SET_FLAG_GOSSIP:
                            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            break;
                        case EVENT_BRANN_ACTIVATE_LASERBEAMS:
                        {
                            // Activate laserbeams
                            if (_instance->GetBossState(DATA_EARTH_WARDEN) == DONE)
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_LASERBEAMS_EARTH_WARDEN));
                            if (_instance->GetBossState(DATA_WATER_WARDEN) == DONE)
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_LASERBEAMS_WATER_WARDEN));
                            if (_instance->GetBossState(DATA_AIR_WARDEN) == DONE)
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_LASERBEAMS_AIR_WARDEN));
                            if (_instance->GetBossState(DATA_FIRE_WARDEN) == DONE)
                                _instance->HandleGameObject(ObjectGuid::Empty, true, _instance->GetGameObject(DATA_LASERBEAMS_FIRE_WARDEN));

                            uint32 dead = _instance->GetData(DATA_DEAD_ELEMENTALS);
                            if (dead == 4) {
                                // Note: In some old sniff file Sun Mirror gets activated every time an elemental dies (for 10 seconds).
                                // Needs to be checked on live. It makes sense that it is only activated after all four beams are active.
                                if (GameObject* mirror = _instance->GetGameObject(DATA_ANRAPHET_SUN_MIRROR))
                                    mirror->SetGoState(GO_STATE_ACTIVE);
                                if (GameObject* door = _instance->GetGameObject(DATA_ANRAPHET_DOOR))
                                    door->SetGoState(GO_STATE_ACTIVE);
                                events.ScheduleEvent(EVENT_BRANN_SAY_ALL_ELEMENTAL_DEAD, Seconds(4)); // Note: 4600 ms
                            }
                            break;
                        }
                        case EVENT_BRANN_SAY_ALL_ELEMENTAL_DEAD:
                            Talk(BRANN_4_ELEMENTAL_DEAD);
                            if (Creature* anraphet = _instance->GetCreature(DATA_ANRAPHET))
                                anraphet->AI()->DoAction(ACTION_ANRAPHET_INTRO);
                            break;
                        case EVENT_BRANN_MOVE_OUTRO:
                            Talk(BRANN_SAY_ANRAPHET_DIED);
                            me->GetMotionMaster()->MoveSmoothPath(POINT_BRANN_SAY_MOMENT, BrannOutroPath, BrannOutroPathSize, false);
                            break;
                        case EVENT_BRANN_MOVE_FINAL:
                            me->GetMotionMaster()->MoveSmoothPath(POINT_BRANN_TURN_BACK, BrannFinalPath, BrannFinalPathSize, false);
                            break;
                        case EVENT_BRANN_TURN_BACK:
                            me->SetFacingTo(DegToRad(180.0f)); // Sniff: 3.141593f
                            me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                            break;
                    }
                }
            }

            void MovementInform(uint32 movementType, uint32 pointId) override
            {
                if (movementType != POINT_MOTION_TYPE && movementType != EFFECT_MOTION_TYPE)
                    return;

                switch (pointId)
                {
                    case POINT_BRANN_SAY_TROGGS:
                        me->SetWalk(false);
                        Talk(BRANN_SAY_TROGGS);
                        events.ScheduleEvent(EVENT_BRANN_THINK, Seconds(15));
                        break;
                    case POINT_BRANN_SAY_MOMENT:
                        Talk(BRANN_SAY_MOMENT);
                        events.ScheduleEvent(EVENT_BRANN_MOVE_FINAL, Seconds(2));
                        break;
                    case POINT_BRANN_TURN_BACK:
                        events.ScheduleEvent(EVENT_BRANN_TURN_BACK, Seconds(6));
                        break;
                    default:
                        break;
                }
            }

        protected:
            EventMap events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfOriginationAI<npc_brann_bronzebeard_anraphetAI>(creature);
        } 
};

class spell_anraphet_alpha_beams : public SpellScriptLoader
{
public:
    spell_anraphet_alpha_beams() : SpellScriptLoader("spell_anraphet_alpha_beams") { }

    class spell_anraphet_alpha_beams_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_anraphet_alpha_beams_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            if (targets.empty())
                return;

            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            targets.clear();
            targets.push_back(target);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anraphet_alpha_beams_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_anraphet_alpha_beams_SpellScript();
    }
};

// 77106 - Omega Stance (Summon)
class spell_anraphet_omega_stance_summon : public SpellScriptLoader
{
public:
    spell_anraphet_omega_stance_summon() : SpellScriptLoader("spell_anraphet_omega_stance_summon") { }

    class spell_anraphet_omega_stance_summon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_anraphet_omega_stance_summon_SpellScript);

        void SetDest(SpellDestination& dest)
        {
            dest.RelocateOffset({ 0.0f, 0.0f, 30.0f, 0.0f });
        }

        void Register() override
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_anraphet_omega_stance_summon_SpellScript::SetDest, EFFECT_0, TARGET_DEST_DEST);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_anraphet_omega_stance_summon_SpellScript();
    }
};

// 77127 Omega Stance Spider Effect
class spell_anraphet_omega_stance_spider_effect : public SpellScriptLoader
{
public:
    spell_anraphet_omega_stance_spider_effect() : SpellScriptLoader("spell_anraphet_omega_stance_spider_effect") { }

    class spell_anraphet_omega_stance_spider_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_anraphet_omega_stance_spider_effect_SpellScript);

        void SetDest(SpellDestination& dest)
        {
            // Do our own calculations for the destination position.
            /// TODO: Remove this once we find a general rule for WorldObject::MovePosition (this spell shouldn't take the Z change into consideration)
            Unit* caster = GetCaster();
            float angle = float(rand_norm()) * static_cast<float>(2 * M_PI);
            uint32 dist = caster->GetObjectSize() + GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius(caster) * (float)rand_norm();

            float x = caster->GetPositionX() + dist * std::cos(angle);
            float y = caster->GetPositionY() + dist * std::sin(angle);
            float z = caster->GetMap()->GetHeight(caster->GetPhaseShift(), x, y, caster->GetPositionZ());
            float o = dest._position.GetOrientation();

            dest.Relocate({ x, y, z, o });
        }

        void Register() override
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_anraphet_omega_stance_spider_effect_SpellScript::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_anraphet_omega_stance_spider_effect_SpellScript();
    }
};

void AddSC_boss_anraphet()
{
    new boss_anraphet();
    new spell_anraphet_alpha_beams();
    new npc_brann_bronzebeard_anraphet();
    new npc_alpha_beam();
    new spell_anraphet_omega_stance_summon();
    new spell_anraphet_omega_stance_spider_effect();
    new npc_omega_stance();
}
