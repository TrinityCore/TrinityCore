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

/* Script Data Start
   SDName: Boss Hadronox
   Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "../Northrend/AzjolNerub/AzjolNerub/azjol_nerub.h"
#include "Player.h"
#include "CreatureTextMgr.h"
#include "TemporarySummon.h"

enum Events
{
    // =========== HADRONOX ===========
    EVENT_ACID_CLOUD           = 1,
    EVENT_LEECH_POISON	       = 2,
    EVENT_PIERCE_ARMOR	       = 3,
    EVENT_WEB_GRAB	           = 4,
    EVENT_MOVE_IN_TUNNEL       = 5,
    EVENT_TIMED_ATTACKERS_A    = 6, // Used to control periodic attacking trash from distant front door.
    EVENT_TIMED_ATTACKERS_B    = 7, // Used to control periodic attacking trash from closer front door.

    // =========== ANUB`AR CRUSHER ===========
    EVENT_SMASH                = 2,

    // =========== ANUB`AR CHAMPION ===========
    EVENT_REND                 = 2,
    EVENT_PUMMEL               = 3,

    // =========== ANUB`AR NECROMANCER ===========
    EVENT_SHADOW_BOLT          = 2,
    EVENT_ANIMATED_BONNES      = 3,

    // =========== CRYPT FIEND ===========
    EVENT_INFECTED_WOUNDS      = 2,
    EVENT_CRUSHING_WEBS        = 3
};

enum Actions
{
    ACTION_RESET_EVENT,
    ACTION_HANDLE_EVENT_START
};

enum Movements
{
    POINT_FINALIZE_WPS       = 0, // Point ID used by each member of crusher's reinforcement group to finalize wps.

    WP_HADRONOX              = 289210 // DB waypoint tunnel path for Hadronox.
};

enum Spells
{
    // ============== HADRONOX ==============
    SPELL_ACID_CLOUD                             = 53400,
    SPELL_LEECH_POISON                           = 53030,
    SPELL_PIERCE_ARMOR                           = 53418,
    SPELL_TAUNT                                  = 53799,
    SPELL_WEB_GRAB_WITHOUT_PLAYER	             = 53406,
    SPELL_WEB_GRAB_WITH_PLAYER                   = 57731,
    SPELL_WEB_FRONT_DOORS                        = 53177,
    SPELL_WEB_SIDE_DOOR	                         = 53185,

    // ============== ANUB'AR CRUSHER ==============
    SPELL_SMASH                                  = 53318,
    SPELL_FRENZY                                 = 53801,

    // ============== ANUB'AR CHAMPION ==============
    SPELL_REND_N                                 = 53317,
    SPELL_REND_H                                 = 59343, // used as must not have aura from reference
    SPELL_PUMMEL                                 = 53394,

    // ============== ANUB'AR NECROMANCER ==============
    SPELL_ANIMATED_BONNES                        = 53334,
    SPELL_SHADOW_BOLT                            = 53333,

    // ============== ANUB'AR CRYPT FIEND ==============
    SPELL_INFECTED_WOUNDS_N                      = 53330,
    SPELL_INFECTED_WOUNDS_H                      = 59348, // used as must not have aura from reference
    SPELL_CRUSHING_WEBS                          = 53322,

    // ============== TRIGGERS ==============
    SPELL_SUMMON_ANUB_AR_CHAMPION_PERIODIC       = 53035,
    SPELL_SUMMON_ANUB_AR_NECROMANCER_PERIODIC    = 53036,
    SPELL_SUMMON_ANUB_AR_CRYPT_FIEND_PERIODIC    = 53037,
    SPELL_SUMMON_ANUB_AR_CHAMPION                = 53826, 
    SPELL_SUMMON_ANUB_AR_NECROMANCER             = 53827,
    SPELL_SUMMON_ANUB_AR_CRYPT_FIEND             = 53828
};

enum NPCs
{
    NPC_STATIC_CRUSHER               = 28922,
    NPC_STATIC_CHAMPION	             = 29117,
    NPC_STATIC_CRYPT_FIEND           = 29118,
    NPC_STATIC_NECROMANCER           = 29119,
    NPC_PERIODIC_ATTACKING_CHAMPION  = 28924,
    NPC_PERIODIC_ATTACKING_NECRO     = 28925,
    NPC_PERIODIC_ATTACKING_FIEND     = 29051,
    // Trash heading Hadronox's Lair
    NPC_ANUB_FIEND_FRONT_D           = 29063,
    NPC_ANUB_FIEND_SIDE_D            = 29097,
    NPC_ANUB_CHAMPION_FRONT_D        = 29062,
    NPC_ANUB_CHAMPION_SIDE_D         = 29096,
    NPC_ANUB_NECRO_FRONT_D           = 29064,
    NPC_ANUB_NECRO_SIDE_D            = 29098
};

enum Texts
{
    // Hadronox
    EMOTE_MOVE_IN_TUNNEL       = 0,

    // Anub'Ar Crusher
    YELL_BREACHED_GATE         = 0,
    EMOTE_FRENZY               = 1
};

enum HadronoxData
{
    DATA_HADRONOX_DENIED       = 0, // http://www.wowhead.com/achievement=1297
    DATA_EVENT_STATUS          = 1
};

enum CreatureGroups
{
    CREATURE_GROUP_CRUSHER_REINFORCEMENTS_A,
    CREATURE_GROUP_CRUSHER_REINFORCEMENTS_B
};

Position const DistantDoorCrusherFinalPoint  = { 520.802f, 565.729f, 733.940f, 0.0f };
Position const DistantDoorChampionFinalPoint = { 530.965f, 563.105f, 732.844f, 0.0f };
Position const DistantDoorNecroFinalPoint    = { 511.110f, 563.919f, 734.705f, 0.0f };
Position const CloserDoorCrusherFinalPoint   = { 550.440f, 554.986f, 730.924f, 0.0f };
Position const CloserDoorFiendFinalPoint     = { 556.433f, 548.888f, 730.546f, 0.0f };
Position const CloserDoorNecroFinalPoint     = { 541.198f, 562.136f, 731.626f, 0.0f };
Position const PeriodicAttackingTrashFinalWP = { 529.282f, 553.558f, 732.272f, 0.0f };

#define MAX_FIRST_CRUSHER_GROUP_WAYPOINTS       10
Position const FirstCrusherGroupWaypoints[MAX_FIRST_CRUSHER_GROUP_WAYPOINTS] =
{
    { 476.300f, 620.260f, 771.470f, 0.0f },
    { 476.335f, 619.261f, 771.470f, 0.0f },
    { 486.294f, 611.404f, 771.538f, 0.0f },
    { 489.380f, 607.940f, 767.092f, 0.0f },
    { 508.496f, 586.488f, 736.623f, 0.0f },
    { 509.294f, 585.593f, 736.477f, 0.0f },
    { 514.452f, 579.804f, 735.388f, 0.0f },
    { 519.133f, 574.550f, 734.407f, 0.0f },
    { 522.031f, 571.299f, 734.001f, 0.0f },
    { 522.031f, 571.299f, 734.001f, 0.0f }
};

#define MAX_SECOND_CRUSHER_GROUP_WAYPOINTS       10
Position const SecondCrusherGroupWaypoints[MAX_SECOND_CRUSHER_GROUP_WAYPOINTS] =
{
    { 584.819f, 618.615f, 771.452f, 0.0f },
    { 583.920f, 618.177f, 771.452f, 0.0f },
    { 575.431f, 610.356f, 771.547f, 0.0f },
    { 546.944f, 584.116f, 731.422f, 0.0f },
    { 545.553f, 582.835f, 730.991f, 0.0f },
    { 540.572f, 578.247f, 732.316f, 0.0f },
    { 538.427f, 576.271f, 732.534f, 0.0f },
    { 536.559f, 574.550f, 732.554f, 0.0f },
    { 533.973f, 572.168f, 732.778f, 0.0f },
    { 552.580f, 566.355f, 729.937f, 0.0f }
};

// Front distant door trash stair waypoints 
#define MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS       3
Position const FrontDoorAStairsWaypoints[MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS] =
{
    { 485.155f, 611.184f, 771.461f, 0.0f },
    { 512.667f, 588.594f, 736.528f, 0.0f },
    { 550.284f, 568.537f, 730.294f, 0.0f }
};

// Front closer door trash stair waypoints
#define MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS       3
Position const FrontDoorBStairsWaypoints[MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS] =
{
    { 576.419f, 612.233f, 771.434f, 0.0f },
    { 544.141f, 585.004f, 731.543f, 0.0f },
    { 550.284f, 568.538f, 730.294f, 0.0f }
};

// Side door trash stair waypoints
#define MAX_SIDE_DOOR_STAIRS_WAYPOINTS       7
Position const SideDoorStairsWaypoints[MAX_SIDE_DOOR_STAIRS_WAYPOINTS] =
{
    { 581.603f, 607.853f, 739.321f, 0.0f },
    { 581.447f, 608.840f, 739.321f, 0.0f },
    { 589.564f, 597.528f, 739.135f, 0.0f },
    { 596.733f, 587.538f, 727.170f, 0.0f },
    { 598.621f, 584.906f, 726.183f, 0.0f },
    { 598.621f, 584.906f, 726.183f, 0.0f },
    { 597.902f, 587.909f, 727.186f, 0.0f }
};

// Waypoints for trash heading tunnel and Hadronox's Lair
#define MAX_TRASH_HEADING_LAIR_WAYPOINTS       12
Position const TrashHeadingLairWaypoints[MAX_TRASH_HEADING_LAIR_WAYPOINTS] =
{
    { 602.912f, 579.12f, 724.11f, 0.0f },
    { 620.422f, 561.14f, 717.12f, 0.0f },
    { 623.675f, 536.21f, 704.56f, 0.0f },
    { 617.250f, 522.58f, 695.48f, 0.0f },
    { 602.654f, 511.14f, 694.73f, 0.0f },
    { 588.071f, 511.27f, 695.12f, 0.0f },
    { 584.711f, 509.85f, 696.99f, 0.0f },
    { 566.644f, 513.36f, 698.92f, 0.0f },
    { 554.092f, 520.61f, 690.14f, 0.0f },
    { 539.741f, 533.15f, 684.36f, 0.0f },
    { 530.406f, 539.70f, 678.07f, 0.0f },
    { 515.585f, 544.20f, 673.62f, 0.0f }
};

class HadronoxEventDespawner : public BasicEvent
{
    public:
        explicit HadronoxEventDespawner(Creature* creature) : _creature(creature)
        {
        }

        bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
        {
            Trinity::CreatureWorker<HadronoxEventDespawner> worker(_creature, *this);
            _creature->VisitNearbyGridObject(300.0f, worker);
            return true;
        }

        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_HADRONOX:
                    creature->SetRespawnDelay(30);
                    creature->AI()->DoAction(ACTION_RESET_EVENT);
                    break;
                case NPC_WORLD_TRIGGER_LARGE_AOI:
                case NPC_STATIC_CRUSHER:
                case NPC_STATIC_CHAMPION:
                case NPC_STATIC_CRYPT_FIEND:
                case NPC_STATIC_NECROMANCER:
                    break;
                default:
                    return;
            }

            uint32 corpseDelay = creature->GetCorpseDelay();
            uint32 respawnDelay = creature->GetRespawnDelay();
            creature->SetCorpseDelay(1);

            if (CreatureData const* data = creature->GetCreatureData())
                creature->NearTeleportTo(data->posX, data->posY, data->posZ, data->orientation);

            creature->DespawnOrUnsummon();
            creature->SetCorpseDelay(corpseDelay);
        }

    private:
        Creature* _creature;
};

class TW_boss_hadronox : public CreatureScript
{
    public:
        TW_boss_hadronox() : CreatureScript("TW_boss_hadronox") { }

        struct TW_boss_hadronoxAI : public BossAI
        {
            TW_boss_hadronoxAI(Creature* creature) : BossAI(creature, DATA_HADRONOX_EVENT)
            {
            }

            void Reset()
            {
                events.Reset();

                _attackersCounterA = 0;
                _attackersCounterB = 0;

                _clearedWPMovement = false;
                _allowedAttack = true;
                _hadronoxDenied = false;
                _eventStarted = false;
                _eventReseted = false;
                _emoted = false;
            }

            uint32 GetData(uint32 type) const
            {
                if (type == DATA_HADRONOX_DENIED)
                    return _hadronoxDenied;
                else if (type == DATA_EVENT_STATUS)
                    return _eventStarted;

                return 0;
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_RESET_EVENT:
                        if (!_eventReseted)
                        {
                            _eventReseted = true;
                            _eventStarted = false;
                            _hadronoxDenied = false;
                            events.Reset();
                            me->RemoveAllAuras();
                            me->CombatStop();
                            me->ResetLootMode();
                            instance->SetBossState(DATA_HADRONOX, NOT_STARTED);
                            me->m_Events.AddEvent(new HadronoxEventDespawner(me), me->m_Events.CalculateTime(1000));
                        }
                        break;
                    case ACTION_HANDLE_EVENT_START:
                        if (!_eventReseted)
                        {
                            if (Creature* distantFrontDoorTrigger = me->GetMap()->GetCreature(instance->GetData64(DATA_FRONT_DOOR_TRIGGER_A_GUID)))
                            {
                                std::list<TempSummon*> reinforcementgroupA;
                                distantFrontDoorTrigger->SummonCreatureGroup(CREATURE_GROUP_CRUSHER_REINFORCEMENTS_A, &reinforcementgroupA);
                                for (std::list<TempSummon*>::const_iterator itr = reinforcementgroupA.begin(); itr != reinforcementgroupA.end(); ++itr)
                                    (*itr)->GetAI()->DoAction(CREATURE_GROUP_CRUSHER_REINFORCEMENTS_A);

                                events.ScheduleEvent(EVENT_TIMED_ATTACKERS_A, 20*IN_MILLISECONDS);
                            }

                            if (Creature* closerFrontDoorTrigger = me->GetMap()->GetCreature(instance->GetData64(DATA_FRONT_DOOR_TRIGGER_B_GUID)))
                            {
                                std::list<TempSummon*> reinforcementgroupB;
                                closerFrontDoorTrigger->SummonCreatureGroup(CREATURE_GROUP_CRUSHER_REINFORCEMENTS_B, &reinforcementgroupB);
                                for (std::list<TempSummon*>::const_iterator itr = reinforcementgroupB.begin(); itr != reinforcementgroupB.end(); ++itr)
                                    (*itr)->GetAI()->DoAction(CREATURE_GROUP_CRUSHER_REINFORCEMENTS_B);
                            }

                            _eventStarted = true;
                            _allowedAttack = false;
                            me->AttackStop();
                            _hadronoxDenied = true;
                            me->GetMotionMaster()->MovePath(WP_HADRONOX, false);
                        }
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();

                events.ScheduleEvent(EVENT_ACID_CLOUD, urand(10, 14)*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_LEECH_POISON, urand(3, 9)*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_PIERCE_ARMOR, urand(1, 3)*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_WEB_GRAB, urand(15, 19)*IN_MILLISECONDS);
            }

            // When Hadronox kills any enemy (that includes a player) he will regain 10% of HP if the target had Leech Poison applied.
            void KilledUnit(Unit* Victim)
            {
                if (!Victim || !Victim->HasAura(SPELL_LEECH_POISON) || !me->IsAlive())
                    return;

                me->ModifyHealth(uint32(me->CountPctFromMaxHealth(10)));
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type = WAYPOINT_MOTION_TYPE)
                {
                    switch (id)
                    {
                        case 4:
                            _allowedAttack = true;
                            _hadronoxDenied = true;
                            events.ScheduleEvent(EVENT_MOVE_IN_TUNNEL, 25*IN_MILLISECONDS, 2);
                            break;
                        case 6:
                        case 8:
                        case 10:
                            _allowedAttack = true;
                            break;	
                        case 11:
                            me->CastSpell(me, SPELL_WEB_SIDE_DOOR);
                            _hadronoxDenied = false;
                            break;
                        case 12:
                            me->CastSpell(me, SPELL_WEB_FRONT_DOORS);
                            instance->SetData(DATA_HADRONOX_EVENT, DONE);
                            me->GetMotionMaster()->Clear();
                            break;
                        default:
                            break;
                    }
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER || who->IsControlledByPlayer())
                    return;

                if (!me->IsWithinDistInMap(who, 10.0f, false))
                    return;

                if (who->ToCreature() && who->ToCreature()->GetReactState() != REACT_DEFENSIVE)
                    return;

                if (who->ToCreature())
                    who->ToCreature()->SetReactState(REACT_AGGRESSIVE);

                DoCast(who, SPELL_TAUNT);
            } 

            void DamageTaken(Unit* attacker, uint32& /*damage*/)
            {
                if (!_clearedWPMovement && (attacker->GetTypeId() == TYPEID_PLAYER) && !_eventReseted)
                {
                    _clearedWPMovement = true;
                    events.CancelEventGroup(2);
                    me->GetMotionMaster()->MoveIdle();
                    me->GetMotionMaster()->Clear();
                }
            }

            void UpdateAI(uint32 diff)
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
                        case EVENT_TIMED_ATTACKERS_A:
                            if (Creature* distantFrontDoorTrigger = me->GetMap()->GetCreature(instance->GetData64(DATA_FRONT_DOOR_TRIGGER_A_GUID)))
                            {
                                switch (_attackersCounterA)
                                {
                                    case 0:
                                        distantFrontDoorTrigger->AI()->DoCastAOE(SPELL_SUMMON_ANUB_AR_NECROMANCER);
                                        ++_attackersCounterA;
                                        break;
                                    case 1: distantFrontDoorTrigger->AI()->DoCastAOE(SPELL_SUMMON_ANUB_AR_CHAMPION);
                                        ++_attackersCounterA;
                                        break;
                                    case 2: distantFrontDoorTrigger->AI()->DoCastAOE(SPELL_SUMMON_ANUB_AR_CRYPT_FIEND); break;
                                }

                                if (_attackersCounterA < 2)
                                    events.ScheduleEvent(EVENT_TIMED_ATTACKERS_A, 20*IN_MILLISECONDS);
                                else
                                    events.ScheduleEvent(EVENT_TIMED_ATTACKERS_B, 20*IN_MILLISECONDS);
                            }

                            break;
                        case EVENT_TIMED_ATTACKERS_B:
                            if (Creature* closerFrontDoorTrigger = me->GetMap()->GetCreature(instance->GetData64(DATA_FRONT_DOOR_TRIGGER_B_GUID)))
                            {
                                switch (_attackersCounterB)
                                {
                                    case 0:
                                        closerFrontDoorTrigger->AI()->DoCastAOE(SPELL_SUMMON_ANUB_AR_NECROMANCER);
                                        ++_attackersCounterB;
                                        break;
                                    case 1:
                                        closerFrontDoorTrigger->AI()->DoCastAOE(SPELL_SUMMON_ANUB_AR_CHAMPION);
                                        ++_attackersCounterB;
                                        break;
                                    case 2: closerFrontDoorTrigger->AI()->DoCastAOE(SPELL_SUMMON_ANUB_AR_CRYPT_FIEND); break;
                                }

                                if (_attackersCounterB < 2)
                                    events.ScheduleEvent(EVENT_TIMED_ATTACKERS_B, 20*IN_MILLISECONDS);
                            }

                            break;
                        case EVENT_ACID_CLOUD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                                DoCast(target, SPELL_ACID_CLOUD);

                            events.ScheduleEvent(EVENT_ACID_CLOUD, urand(20, 30)*IN_MILLISECONDS);
                            break;
                        case EVENT_LEECH_POISON:
                            DoCastAOE(SPELL_LEECH_POISON);
                            events.ScheduleEvent(EVENT_LEECH_POISON, urand(11, 14)*IN_MILLISECONDS);
                            break;
                        case EVENT_PIERCE_ARMOR:
                            DoCastVictim(SPELL_PIERCE_ARMOR);
                            events.ScheduleEvent(EVENT_PIERCE_ARMOR, 8*IN_MILLISECONDS);
                            break;
                        case EVENT_WEB_GRAB:
                            if (me->SelectNearestPlayer(60.0f))
                            {
                                DoCastAOE(SPELL_WEB_GRAB_WITHOUT_PLAYER);
                                events.ScheduleEvent(EVENT_WEB_GRAB, urand(15, 30)*IN_MILLISECONDS);
                            }
                            else
                            {
                                DoCastAOE(SPELL_WEB_GRAB_WITHOUT_PLAYER);
                                events.ScheduleEvent(EVENT_WEB_GRAB, urand(15, 30)*IN_MILLISECONDS);
                            }

                            break;
                        case EVENT_MOVE_IN_TUNNEL:
                            if (!_emoted)
                            {
                                _allowedAttack = false;
                                me->AttackStop();
                                sCreatureTextMgr->SendChat(me, EMOTE_MOVE_IN_TUNNEL, 0, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_MAP);
                                _emoted = true;
                            }
                            break;
                    }
                }

                if (_allowedAttack)
                    DoMeleeAttackIfReady();
            }

        private:
            uint8 _attackersCounterA;  // Keep the count of periodic summoned attacker from each front door trigger /maximum of 3 for each/.
            uint8 _attackersCounterB;  // -//-
            bool _disableResetChecker; // Can control reset checking mechanism with it.
            bool _allowedAttack;       // Controls if Hadronox will melee attack or not
            bool _hadronoxDenied;      // Contains data for achievement.
            bool _clearedWPMovement;   // Used to stop WP movement if player gets in Hadronox threat list.
            bool _eventReseted;        // Used to check if Hadronox already has received signal to break event.
            bool _eventStarted;        // Used to check if UpdateAI should return if no victim is found.
            bool _emoted;              // Don't know...
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_boss_hadronoxAI(creature);
        }
};

class TW_npc_anub_ar_crusher : public CreatureScript
{
    public:
        TW_npc_anub_ar_crusher() : CreatureScript("TW_npc_anub_ar_crusher") { }

        struct TW_npc_anub_ar_crusherAI : public npc_escortAI
        {
            TW_npc_anub_ar_crusherAI(Creature* creature) : npc_escortAI(creature)
            {
                _instance = creature->GetInstanceScript();
                SetDespawnAtEnd(false);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (Creature* hadronox = me->GetMap()->GetCreature(_instance->GetData64(DATA_HADRONOX)))
                {
                    if (hadronox->AI()->GetData(DATA_EVENT_STATUS) == NOT_STARTED)
                    {
                        Talk(YELL_BREACHED_GATE);
                        hadronox->AI()->DoAction(ACTION_HANDLE_EVENT_START);
                    }
                }

                _events.ScheduleEvent(EVENT_SMASH, DUNGEON_MODE(urand(4, 9)*IN_MILLISECONDS, urand(4, 7)*IN_MILLISECONDS));
            }

            void EnterEvadeMode()
            {
                if (Creature* hadronox = me->GetMap()->GetCreature(_instance->GetData64(DATA_HADRONOX)))
                    hadronox->AI()->DoAction(ACTION_RESET_EVENT);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case CREATURE_GROUP_CRUSHER_REINFORCEMENTS_A:
                        for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                            AddWaypoint(i, FirstCrusherGroupWaypoints[i].GetPositionX(), FirstCrusherGroupWaypoints[i].GetPositionY(),
                            FirstCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, DistantDoorCrusherFinalPoint.GetPositionX(), DistantDoorCrusherFinalPoint.GetPositionY(),
                            DistantDoorCrusherFinalPoint.GetPositionZ(), 1*IN_MILLISECONDS);
                        Start(true, true);
                        break;
                    case CREATURE_GROUP_CRUSHER_REINFORCEMENTS_B:
                        for (uint8 i = 0; i < MAX_SECOND_CRUSHER_GROUP_WAYPOINTS; i++)
                            AddWaypoint(i, SecondCrusherGroupWaypoints[i].GetPositionX(), SecondCrusherGroupWaypoints[i].GetPositionY(),
                            SecondCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, CloserDoorCrusherFinalPoint.GetPositionX(), CloserDoorCrusherFinalPoint.GetPositionY(),
                            CloserDoorCrusherFinalPoint.GetPositionZ(), 1*IN_MILLISECONDS);
                        Start(true, true);
                        break;
                }
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (!me->HasAura(SPELL_FRENZY) && HealthBelowPct(30))
                {
                    DoCast(me, SPELL_FRENZY);
                    Talk(EMOTE_FRENZY);
                }

                while (uint32 eventId = _events.ExecuteEvent())
                {                 
                    if (eventId == EVENT_SMASH)
                    {
                        DoCastVictim(SPELL_SMASH);
                        _events.ScheduleEvent(EVENT_SMASH, DUNGEON_MODE(urand(12, 18)*IN_MILLISECONDS, urand(8, 18)*IN_MILLISECONDS));
                    }
                }

                DoMeleeAttackIfReady();
            }

            void WaypointReached(uint32 waypointId)
            {
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_anub_ar_crusherAI(creature);
        }
};

class TW_npc_anub_ar_champion : public CreatureScript
{
    public:
        TW_npc_anub_ar_champion() : CreatureScript("TW_npc_anub_ar_champion") { }

        struct TW_npc_anub_ar_championAI : public npc_escortAI
        {
            TW_npc_anub_ar_championAI(Creature* creature) : npc_escortAI(creature)
            {
                SetDespawnAtEnd(false);
                _instance = creature->GetInstanceScript();
                _canSpellInterrupt = false;
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                switch (me->GetEntry())
                {
                    case NPC_STATIC_CHAMPION:
                        return;
                    case NPC_PERIODIC_ATTACKING_CHAMPION:
                        if (me->GetPositionX() < 500.0f)
                            for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                                AddWaypoint(i, FirstCrusherGroupWaypoints[i].GetPositionX(), FirstCrusherGroupWaypoints[i].GetPositionY(),
                                FirstCrusherGroupWaypoints[i].GetPositionZ());
                        else
                            for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                                AddWaypoint(i, SecondCrusherGroupWaypoints[i].GetPositionX(), SecondCrusherGroupWaypoints[i].GetPositionY(),
                                SecondCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, PeriodicAttackingTrashFinalWP.GetPositionX(), PeriodicAttackingTrashFinalWP.GetPositionY(),
                            PeriodicAttackingTrashFinalWP.GetPositionZ());
                        break;
                    case NPC_ANUB_CHAMPION_FRONT_D:
                        if (me->GetPositionX() < 500.0f)
                        {
                            for (uint8 i = 0; i < MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS; i++)
                                AddWaypoint(i, FrontDoorAStairsWaypoints[i].GetPositionX(), FrontDoorAStairsWaypoints[i].GetPositionY(),
                                FrontDoorAStairsWaypoints[i].GetPositionZ());

                            for (uint8 i = MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS); i++)
                                AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionX(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionY(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionZ());
                        }
                        else
                        {
                            for (uint8 i = 0; i < MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS; i++)
                                AddWaypoint(i, FrontDoorBStairsWaypoints[i].GetPositionX(), FrontDoorBStairsWaypoints[i].GetPositionY(),
                                FrontDoorBStairsWaypoints[i].GetPositionZ());

                            for (uint8 i = MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS); i++)
                                AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionX(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionY(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionZ());
                        }

                        me->SetReactState(REACT_DEFENSIVE);
                        break;
                    case NPC_ANUB_CHAMPION_SIDE_D:
                        for (uint8 i = 0; i < MAX_SIDE_DOOR_STAIRS_WAYPOINTS; i++)
                            AddWaypoint(i, SideDoorStairsWaypoints[i].GetPositionX(), SideDoorStairsWaypoints[i].GetPositionY(),
                            SideDoorStairsWaypoints[i].GetPositionZ());

                        for (uint8 i = MAX_SIDE_DOOR_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_SIDE_DOOR_STAIRS_WAYPOINTS); i++)
                            AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionX(),
                            TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionY(),
                            TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionZ());

                        me->SetReactState(REACT_DEFENSIVE);
                        break;
                }

                Start(true, true);
            }

            void DoAction(int32 action)
            {
                if (action == CREATURE_GROUP_CRUSHER_REINFORCEMENTS_A)
                {
                    for (uint8 i = 0; i < MAX_SECOND_CRUSHER_GROUP_WAYPOINTS; i++)
                        AddWaypoint(i, FirstCrusherGroupWaypoints[i].GetPositionX(), FirstCrusherGroupWaypoints[i].GetPositionY(),
                        FirstCrusherGroupWaypoints[i].GetPositionZ());

                    AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, DistantDoorChampionFinalPoint.GetPositionX(), DistantDoorChampionFinalPoint.GetPositionY(),
                        DistantDoorChampionFinalPoint.GetPositionZ(), 1*IN_MILLISECONDS);
                    Start(true, true);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.ScheduleEvent(EVENT_REND, DUNGEON_MODE(urand(6, 9)*IN_MILLISECONDS, urand(4, 7)*IN_MILLISECONDS));
                _events.ScheduleEvent(EVENT_PUMMEL, DUNGEON_MODE(urand(14, 17)*IN_MILLISECONDS, urand(9, 12)*IN_MILLISECONDS));
            }

            void EnterEvadeMode()
            {
            }

            void WaypointReached(uint32 waypointId)
            {
                if (waypointId == 10)
                    if (me->GetEntry() == NPC_PERIODIC_ATTACKING_CHAMPION)
                        if (Unit* victim = me->SelectNearestPlayer(100.0f))
                            me->Attack(victim, true);
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (_canSpellInterrupt && me->GetVictim() && me->GetVictim()->IsNonMeleeSpellCast(false, false, true))
                {
                    DoCastVictim(SPELL_PUMMEL);
                    _canSpellInterrupt = false;
                }

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_REND:
                            if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, false, -(DUNGEON_MODE(SPELL_REND_N, SPELL_REND_H))))
                                DoCast(victim, SPELL_REND_N);

                            _events.ScheduleEvent(EVENT_REND, DUNGEON_MODE(urand(17, 32)*IN_MILLISECONDS, urand(15, 18)*IN_MILLISECONDS));
                            break;
                        case EVENT_PUMMEL:
                            _canSpellInterrupt = true;
                            _events.ScheduleEvent(EVENT_PUMMEL, DUNGEON_MODE(urand(14, 17)*IN_MILLISECONDS, urand(9, 12)*IN_MILLISECONDS));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
            bool _canSpellInterrupt; // Used to control when the creature will be able to do next spell interrupt.
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_anub_ar_championAI(creature);
        }
};

class TW_npc_anub_ar_necromancer : public CreatureScript
{
    public:
        TW_npc_anub_ar_necromancer() : CreatureScript("TW_npc_anub_ar_necromancer") { }

        struct TW_npc_anub_ar_necromancerAI : public npc_escortAI
        {
            TW_npc_anub_ar_necromancerAI(Creature* creature) : npc_escortAI(creature)
            {
                SetDespawnAtEnd(false);
                _instance = creature->GetInstanceScript();
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                switch (me->GetEntry())
                {
                    case NPC_STATIC_NECROMANCER:
                        return;
                    case NPC_PERIODIC_ATTACKING_NECRO:
                        if (me->GetPositionX() < 500.0f)
                            for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                                AddWaypoint(i, FirstCrusherGroupWaypoints[i].GetPositionX(), FirstCrusherGroupWaypoints[i].GetPositionY(),
                                FirstCrusherGroupWaypoints[i].GetPositionZ());
                        else
                            for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                                AddWaypoint(i, SecondCrusherGroupWaypoints[i].GetPositionX(), SecondCrusherGroupWaypoints[i].GetPositionY(),
                                SecondCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, PeriodicAttackingTrashFinalWP.GetPositionX(), PeriodicAttackingTrashFinalWP.GetPositionY(),
                            PeriodicAttackingTrashFinalWP.GetPositionZ());
                        break;
                    case NPC_ANUB_NECRO_FRONT_D:
                        if (me->GetPositionX() < 500.0f)
                        {
                            for (uint8 i = 0; i < MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS; i++)
                                AddWaypoint(i, FrontDoorAStairsWaypoints[i].GetPositionX(), FrontDoorAStairsWaypoints[i].GetPositionY(),
                                FrontDoorAStairsWaypoints[i].GetPositionZ());

                            for (uint8 i = MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS); i++)
                                AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionX(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionY(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionZ());
                        }
                        else
                        {
                            for (uint8 i = 0; i < MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS; i++)
                                AddWaypoint(i, FrontDoorBStairsWaypoints[i].GetPositionX(), FrontDoorBStairsWaypoints[i].GetPositionY(),
                                FrontDoorBStairsWaypoints[i].GetPositionZ());

                            for (uint8 i = MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS); i++)
                                AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionX(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionY(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionZ());
                        }

                        me->SetReactState(REACT_DEFENSIVE);
                        break;
                    case NPC_ANUB_NECRO_SIDE_D:
                        for (uint8 i = 0; i < MAX_SIDE_DOOR_STAIRS_WAYPOINTS; i++)
                            AddWaypoint(i, SideDoorStairsWaypoints[i].GetPositionX(), SideDoorStairsWaypoints[i].GetPositionY(),
                            SideDoorStairsWaypoints[i].GetPositionZ());

                        for (uint8 i = MAX_SIDE_DOOR_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_SIDE_DOOR_STAIRS_WAYPOINTS); i++)
                            AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionX(),
                            TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionY(),
                            TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionZ());

                        me->SetReactState(REACT_DEFENSIVE);
                        break;
                }

                Start(true, true);
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case CREATURE_GROUP_CRUSHER_REINFORCEMENTS_A:
                        for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                            AddWaypoint(i, FirstCrusherGroupWaypoints[i].GetPositionX(), FirstCrusherGroupWaypoints[i].GetPositionY(),
                            FirstCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, DistantDoorNecroFinalPoint.GetPositionX(), DistantDoorNecroFinalPoint.GetPositionY(),
                            DistantDoorNecroFinalPoint.GetPositionZ(), 1*IN_MILLISECONDS);
                        Start(true, true);
                        break;
                    case CREATURE_GROUP_CRUSHER_REINFORCEMENTS_B:
                        for (uint8 i = 0; i < MAX_SECOND_CRUSHER_GROUP_WAYPOINTS; i++)
                            AddWaypoint(i, SecondCrusherGroupWaypoints[i].GetPositionX(), SecondCrusherGroupWaypoints[i].GetPositionY(),
                            SecondCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, CloserDoorNecroFinalPoint.GetPositionX(), CloserDoorNecroFinalPoint.GetPositionY(),
                            CloserDoorNecroFinalPoint.GetPositionZ(), 1*IN_MILLISECONDS);
                        Start(true, true);
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                DoCastVictim(SPELL_SHADOW_BOLT);
                _events.ScheduleEvent(EVENT_ANIMATED_BONNES, urand(14, 17)*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(4, 6)*IN_MILLISECONDS);
            }

            void EnterEvadeMode()
            {
            }

            void WaypointReached(uint32 waypointId)
            {
                if (waypointId == 10)
                    if (me->GetEntry() == NPC_PERIODIC_ATTACKING_NECRO)
                        if (Unit* victim = me->SelectNearestPlayer(100.0f))
                            me->Attack(victim, true);
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_BOLT:
                            DoCastVictim(SPELL_SHADOW_BOLT);
                            _events.ScheduleEvent(EVENT_SHADOW_BOLT, urand(4, 6)*IN_MILLISECONDS);
                            break;
                        case EVENT_ANIMATED_BONNES:
                            DoCast(me, SPELL_ANIMATED_BONNES);
                            _events.ScheduleEvent(EVENT_ANIMATED_BONNES, urand(24, 28)*IN_MILLISECONDS);
                            break;
                    }
                }

                if (((me->GetPower(POWER_MANA) * 100) / me->GetMaxPower(POWER_MANA)) < 5)
                    DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_anub_ar_necromancerAI(creature);
        }
};

class TW_npc_anub_ar_crypt_fiend : public CreatureScript
{
    public:
        TW_npc_anub_ar_crypt_fiend() : CreatureScript("TW_npc_anub_ar_crypt_fiend") { }

        struct TW_npc_anub_ar_crypt_fiendAI : public npc_escortAI
        {
            TW_npc_anub_ar_crypt_fiendAI(Creature* creature) : npc_escortAI(creature)
            {
                SetDespawnAtEnd(false);
                _instance = creature->GetInstanceScript();
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                switch (me->GetEntry())
                {
                    case NPC_STATIC_CRYPT_FIEND:
                        return;
                    case NPC_PERIODIC_ATTACKING_FIEND:
                        if (me->GetPositionX() < 500.0f)
                            for (uint8 i = 0; i < MAX_FIRST_CRUSHER_GROUP_WAYPOINTS; i++)
                                AddWaypoint(i, FirstCrusherGroupWaypoints[i].GetPositionX(), FirstCrusherGroupWaypoints[i].GetPositionY(),
                                FirstCrusherGroupWaypoints[i].GetPositionZ());
                        else
                            for (uint8 i = 0; i < MAX_SECOND_CRUSHER_GROUP_WAYPOINTS; i++)
                                AddWaypoint(i, SecondCrusherGroupWaypoints[i].GetPositionX(), SecondCrusherGroupWaypoints[i].GetPositionY(),
                                SecondCrusherGroupWaypoints[i].GetPositionZ());

                        AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, PeriodicAttackingTrashFinalWP.GetPositionX(), PeriodicAttackingTrashFinalWP.GetPositionY(),
                            PeriodicAttackingTrashFinalWP.GetPositionZ());
                        break;
                    case NPC_ANUB_FIEND_FRONT_D:
                        if (me->GetPositionX() < 500.0f)
                        {
                            for (uint8 i = 0; i < MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS; i++)
                                AddWaypoint(i, FrontDoorAStairsWaypoints[i].GetPositionX(), FrontDoorAStairsWaypoints[i].GetPositionY(),
                                FrontDoorAStairsWaypoints[i].GetPositionZ());

                            for (uint8 i = MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS); i++)
                                AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionX(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionY(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_A_STAIRS_WAYPOINTS].GetPositionZ());
                        }
                        else
                        {
                            for (uint8 i = 0; i < MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS; i++)
                                AddWaypoint(i, FrontDoorBStairsWaypoints[i].GetPositionX(), FrontDoorBStairsWaypoints[i].GetPositionY(),
                                FrontDoorBStairsWaypoints[i].GetPositionZ());

                            for (uint8 i = MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS); i++)
                                AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionX(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionY(),
                                TrashHeadingLairWaypoints[i - MAX_FRONT_DOOR_B_STAIRS_WAYPOINTS].GetPositionZ());
                        }

                        me->SetReactState(REACT_DEFENSIVE);
                        break;
                    case NPC_ANUB_FIEND_SIDE_D:
                        for (uint8 i = 0; i < MAX_SIDE_DOOR_STAIRS_WAYPOINTS; i++)
                            AddWaypoint(i, SideDoorStairsWaypoints[i].GetPositionX(), SideDoorStairsWaypoints[i].GetPositionY(),
                            SideDoorStairsWaypoints[i].GetPositionZ());

                        for (uint8 i = MAX_SIDE_DOOR_STAIRS_WAYPOINTS; i < (MAX_TRASH_HEADING_LAIR_WAYPOINTS + MAX_SIDE_DOOR_STAIRS_WAYPOINTS); i++)
                            AddWaypoint(i, TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionX(),
                            TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionY(),
                            TrashHeadingLairWaypoints[i - MAX_SIDE_DOOR_STAIRS_WAYPOINTS].GetPositionZ());

                        me->SetReactState(REACT_DEFENSIVE);
                        break;
                }

                Start(true, true);
            }

            void DoAction(int32 action)
            {
                if (action == CREATURE_GROUP_CRUSHER_REINFORCEMENTS_B)
                {
                    for (uint8 i = 0; i < MAX_SECOND_CRUSHER_GROUP_WAYPOINTS; i++)
                        AddWaypoint(i, SecondCrusherGroupWaypoints[i].GetPositionX(), SecondCrusherGroupWaypoints[i].GetPositionY(),
                        SecondCrusherGroupWaypoints[i].GetPositionZ());

                    AddWaypoint(MAX_FIRST_CRUSHER_GROUP_WAYPOINTS, CloserDoorFiendFinalPoint.GetPositionX(), CloserDoorFiendFinalPoint.GetPositionY(),
                        CloserDoorFiendFinalPoint.GetPositionZ(), 1*IN_MILLISECONDS);
                    Start(true, true);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _events.ScheduleEvent(EVENT_INFECTED_WOUNDS, urand(4, 7)*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_CRUSHING_WEBS, urand(9, 12)*IN_MILLISECONDS);
            }

            void EnterEvadeMode()
            {
            }

            void WaypointReached(uint32 waypointId)
            {
                if (waypointId == 10)
                    if (me->GetEntry() == NPC_PERIODIC_ATTACKING_FIEND)
                        if (Unit* victim = me->SelectNearestPlayer(100.0f))
                            me->Attack(victim, true);
            }

            void UpdateEscortAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INFECTED_WOUNDS:
                            if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, false, -(DUNGEON_MODE(SPELL_INFECTED_WOUNDS_N, SPELL_INFECTED_WOUNDS_H))))
                                DoCast(victim, SPELL_INFECTED_WOUNDS_N);

                            _events.ScheduleEvent(EVENT_INFECTED_WOUNDS, urand(9, 12)*IN_MILLISECONDS);
                            break;
                        case EVENT_CRUSHING_WEBS:
                            if (Unit* victim = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, false))
                                DoCast(victim, SPELL_CRUSHING_WEBS);

                            _events.ScheduleEvent(EVENT_CRUSHING_WEBS, DUNGEON_MODE(urand(10, 13)*IN_MILLISECONDS, urand(13, 17)*IN_MILLISECONDS));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_anub_ar_crypt_fiendAI(creature);
        }
};

// Spell: 53035 - Summon Anub'ar Champion Periodic
class TW_spell_trigger_large_aoi_summon_anubar_champion_periodic : public SpellScriptLoader
{
    public:
        TW_spell_trigger_large_aoi_summon_anubar_champion_periodic() : SpellScriptLoader("TW_spell_trigger_large_aoi_summon_anubar_champion_periodic") { }

        class TW_spell_trigger_large_aoi_summon_anubar_champion_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(TW_spell_trigger_large_aoi_summon_anubar_champion_periodic_AuraScript);

            bool Load()
            {
                _championsTickCounter = 1;
                _instance = GetCaster()->GetInstanceScript();
                return _instance != NULL;
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {	
                if (_instance->GetData(DATA_KRIKTHIR_THE_GATEWATCHER) != DONE || _instance->GetData(DATA_HADRONOX_EVENT) == DONE)
                    return;

                Creature* trigger = GetCaster()->ToCreature();
                // Left front door trigger
                if (trigger->GetPositionX() < 500.0f && trigger->GetPositionZ() > 770.0f)
                {
                    if (_championsTickCounter == 1)
                        PreventDefaultAction();
                    else if (_championsTickCounter == 2)
                        PreventDefaultAction();
                    else if (_championsTickCounter == 3)
                        trigger->AI()->DoCast(53064);
                }

                // Right front door trigger
                if (trigger->GetPositionX() > 500.0f && trigger->GetPositionZ() > 770.63f)
                {
                    if (_championsTickCounter == 1)
                        trigger->AI()->DoCast(53090);
                    else if (_championsTickCounter == 2)
                        PreventDefaultAction();
                    else if (_championsTickCounter == 3)
                        PreventDefaultAction();
                }

                // Side door trigger
                if (trigger->GetPositionZ() < 740.0f)
                {
                    if (_championsTickCounter == 1)
                        PreventDefaultAction();
                    else if (_championsTickCounter == 2)
                        trigger->AI()->DoCast(53064);
                    else if (_championsTickCounter == 3)
                        PreventDefaultAction();
                }

                if (_championsTickCounter == 3 || _championsTickCounter > 3)
                    _championsTickCounter = 1;
                else
                    ++_championsTickCounter;
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(TW_spell_trigger_large_aoi_summon_anubar_champion_periodic_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:
            InstanceScript* _instance;
            uint8 _championsTickCounter;
        };

        AuraScript* GetAuraScript() const
        {
            return new TW_spell_trigger_large_aoi_summon_anubar_champion_periodic_AuraScript();
        }
};

// Spell: 53037 - Summon Anub'ar Crypt Fiend Periodic
class TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic : public SpellScriptLoader
{
    public:
        TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic() : SpellScriptLoader("TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic") { }

        class TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic_AuraScript);

            bool Load()
            {
                _fiendTickCounter = 1;
                _instance = GetCaster()->GetInstanceScript();
                return _instance != NULL;
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {	
                if (_instance->GetData(DATA_KRIKTHIR_THE_GATEWATCHER) != DONE || _instance->GetData(DATA_HADRONOX_EVENT) == DONE)
                    return;

                // Left front door trigger
                Creature* trigger = GetCaster()->ToCreature();
                if (trigger->GetPositionX() < 500.0f && trigger->GetPositionZ() > 770.0f)
                {
                    if (_fiendTickCounter == 1)
                        trigger->AI()->DoCast(53065);
                    else if (_fiendTickCounter == 2)
                        PreventDefaultAction();
                    else if (_fiendTickCounter == 3)
                        PreventDefaultAction();
                }

                // Right front door trigger
                if (trigger->GetPositionX() > 500.0f && trigger->GetPositionZ() > 770.63f)
                {
                    if (_fiendTickCounter == 1)
                        PreventDefaultAction();
                    else if (_fiendTickCounter == 2)
                        trigger->AI()->DoCast(53091);
                    else if (_fiendTickCounter == 3)
                        PreventDefaultAction();
                }

                // Side door trigger
                if (trigger->GetPositionZ() < 740.0f)
                {
                    if (_fiendTickCounter == 1)
                        PreventDefaultAction();
                    else if (_fiendTickCounter == 2)
                        PreventDefaultAction();
                    else if (_fiendTickCounter == 3)
                        trigger->AI()->DoCast(53065);
                }

                if (_fiendTickCounter == 3 || _fiendTickCounter > 3)
                    _fiendTickCounter = 1;
                else
                    ++_fiendTickCounter;
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:
            InstanceScript* _instance;
            uint8 _fiendTickCounter;
        };

        AuraScript* GetAuraScript() const
        {
            return new TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic_AuraScript();
        }
};

// Spell: 53036 - Summon Anub'ar Necromancer Periodic
class TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic : public SpellScriptLoader
{
    public:
        TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic() : SpellScriptLoader("TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic") { }

        class TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic_AuraScript : public AuraScript
        {
            PrepareAuraScript(TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic_AuraScript);

            bool Load()
            {
                _necroTickCounter = 1;
                _instance = GetCaster()->GetInstanceScript();
                return _instance != NULL;
            }

            void PeriodicTick(AuraEffect const* aurEff)
            {	
                if (_instance->GetData(DATA_KRIKTHIR_THE_GATEWATCHER) != DONE || _instance->GetData(DATA_HADRONOX_EVENT) == DONE)
                    return;

                // Left front door trigger
                Creature* trigger = GetCaster()->ToCreature();
                if (trigger->GetPositionX() < 500.0f && trigger->GetPositionZ() > 770.0f)
                {
                    if (_necroTickCounter == 1)
                        PreventDefaultAction();
                    else if (_necroTickCounter == 2)
                        trigger->AI()->DoCast(53066);
                    else if (_necroTickCounter == 3)
                        PreventDefaultAction();
                }

                // Right front door trigger
                if (trigger->GetPositionX() > 500.0f && trigger->GetPositionZ() > 770.63f)
                {
                    if (_necroTickCounter == 1)
                        PreventDefaultAction();
                    else if (_necroTickCounter == 2)
                        PreventDefaultAction();
                    else if (_necroTickCounter == 3)
                        trigger->AI()->DoCast(53092);
                }

                // Side door trigger
                if (trigger->GetPositionZ() < 740.0f)
                {
                    if (_necroTickCounter == 1)
                        trigger->AI()->DoCast(53066);
                    else if (_necroTickCounter == 2)
                        PreventDefaultAction();
                    else if (_necroTickCounter == 3)
                        PreventDefaultAction();
                }

                if (_necroTickCounter == 3 || _necroTickCounter > 3)
                    _necroTickCounter = 1;
                else
                    ++_necroTickCounter;
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic_AuraScript::PeriodicTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }

        private:
            InstanceScript* _instance;
            uint8 _necroTickCounter;
        };

        AuraScript* GetAuraScript() const
        {
            return new TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic_AuraScript();
        }
};

class TriggerPositionCheck
{
    public:
        TriggerPositionCheck(bool higherCheck) : _higherCheck(higherCheck) { }

        bool operator()(WorldObject* obj) const
        {
            if (obj->GetPositionZ() > 770.63f)
                return _higherCheck; // At front door

            return !_higherCheck; // At side door
        }

    private:
        bool _higherCheck;
};

// Id: 53177
class TW_spell_hadronox_web_front_doors : public SpellScriptLoader
{
    public:
        TW_spell_hadronox_web_front_doors() : SpellScriptLoader("TW_spell_hadronox_web_front_doors") { }

        class TW_spell_hadronox_web_front_doors_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_hadronox_web_front_doors_SpellScript);

            bool Load()
            {
                _instance = GetCaster()->GetInstanceScript();
                return _instance != NULL;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // Remove side door trigger
                targets.remove_if(TriggerPositionCheck(false));
            }

            void HandleSendEvent(SpellEffIndex /*effIndex*/)
            {
                Creature* hadronox = GetCaster()->ToCreature();
                std::list<Creature*> triggersList;
                if (Creature* frontTriggerA = hadronox->GetMap()->GetCreature(_instance->GetData64(DATA_FRONT_DOOR_TRIGGER_A_GUID)))
                    triggersList.push_back(frontTriggerA);

                if (Creature* frontTriggerB = hadronox->GetMap()->GetCreature(_instance->GetData64(DATA_FRONT_DOOR_TRIGGER_B_GUID)))
                    triggersList.push_back(frontTriggerB);

                for (std::list<Creature*>::iterator itr = triggersList.begin(); itr != triggersList.end(); ++itr)
                {   
                    // There can be aura from being webbed so can't risk to remove all auras.
                    (*itr)->RemoveAurasDueToSpell(SPELL_SUMMON_ANUB_AR_CHAMPION_PERIODIC);
                    (*itr)->RemoveAurasDueToSpell(SPELL_SUMMON_ANUB_AR_NECROMANCER_PERIODIC);
                    (*itr)->RemoveAurasDueToSpell(SPELL_SUMMON_ANUB_AR_CRYPT_FIEND_PERIODIC);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_hadronox_web_front_doors_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHit += SpellEffectFn(TW_spell_hadronox_web_front_doors_SpellScript::HandleSendEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
            }

            InstanceScript* _instance;
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_hadronox_web_front_doors_SpellScript();
        }
};

// Id: 53177 - Web Side Doors
class TW_spell_hadronox_web_side_door : public SpellScriptLoader
{
    public:
        TW_spell_hadronox_web_side_door() : SpellScriptLoader("TW_spell_hadronox_web_side_door") { }

        class TW_spell_hadronox_web_side_door_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_hadronox_web_side_door_SpellScript);

            bool Load()
            {
                _instance = GetCaster()->GetInstanceScript();
                return _instance != NULL;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // Remove front doors triggers
                targets.remove_if(TriggerPositionCheck(true));
            }

            void HandleSendEvent(SpellEffIndex /*effIndex*/)
            {
                if (Creature* trigger = GetCaster()->GetMap()->GetCreature(_instance->GetData64(DATA_SIDE_DOOR_TRIGGER_GUID)))
                {
                    // There can be aura from being webbed so can't risk to remove all auras.
                    trigger->RemoveAurasDueToSpell(SPELL_SUMMON_ANUB_AR_CHAMPION_PERIODIC);
                    trigger->RemoveAurasDueToSpell(SPELL_SUMMON_ANUB_AR_NECROMANCER_PERIODIC);
                    trigger->RemoveAurasDueToSpell(SPELL_SUMMON_ANUB_AR_CRYPT_FIEND_PERIODIC);
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_hadronox_web_side_door_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnEffectHit += SpellEffectFn(TW_spell_hadronox_web_side_door_SpellScript::HandleSendEvent, EFFECT_1, SPELL_EFFECT_SEND_EVENT);
            }

            InstanceScript* _instance;

        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_hadronox_web_side_door_SpellScript();
        }
};

// Spell: 53255 - Check Reset
class TW_spell_hadronox_event_check_reset : public SpellScriptLoader
{
    public:
        TW_spell_hadronox_event_check_reset() : SpellScriptLoader("TW_spell_hadronox_event_check_reset") { }

        class TW_spell_hadronox_event_check_reset_AuraScript : public AuraScript
        {
            PrepareAuraScript(TW_spell_hadronox_event_check_reset_AuraScript);

            bool Load()
            {
                _instance = GetCaster()->GetInstanceScript();
                return _instance != NULL;
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Creature* creature = GetCaster()->ToCreature();
                if (!creature->SelectNearestPlayer(200.0f))
                    if (Creature* hadronox = creature->GetMap()->GetCreature(_instance->GetData64(DATA_HADRONOX)))
                        hadronox->AI()->DoAction(ACTION_RESET_EVENT);
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Creature* creature = GetCaster()->ToCreature();
                if (!creature->SelectNearestPlayer(200.0f))
                    if (Creature* hadronox = creature->GetMap()->GetCreature(_instance->GetData64(DATA_HADRONOX)))
                        hadronox->AI()->DoAction(ACTION_RESET_EVENT);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(TW_spell_hadronox_event_check_reset_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(TW_spell_hadronox_event_check_reset_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }

            InstanceScript* _instance;
        };

        AuraScript* GetAuraScript() const
        {
            return new TW_spell_hadronox_event_check_reset_AuraScript();
        }
};

class TW_achievement_hadronox_denied : public AchievementCriteriaScript
{
    public:
        TW_achievement_hadronox_denied() : AchievementCriteriaScript("TW_achievement_hadronox_denied") { }

        bool OnCheck(Player* /*player*/, Unit* target)
        {
            return target && target->GetAI()->GetData(DATA_HADRONOX_DENIED);
        }
};

void AddSC_TW_boss_hadronox()
{
    new TW_boss_hadronox();
    new TW_npc_anub_ar_crusher();
    new TW_npc_anub_ar_champion();
    new TW_npc_anub_ar_necromancer();
    new TW_npc_anub_ar_crypt_fiend();
    new TW_spell_trigger_large_aoi_summon_anubar_champion_periodic();
    new TW_spell_trigger_large_aoi_summon_anubar_crypt_fiend_periodic();
    new TW_spell_trigger_large_aoi_summon_anubar_necromancer_periodic();
    new TW_spell_hadronox_web_front_doors();
    new TW_spell_hadronox_web_side_door();
    new TW_spell_hadronox_event_check_reset();
    new TW_achievement_hadronox_denied();
}
