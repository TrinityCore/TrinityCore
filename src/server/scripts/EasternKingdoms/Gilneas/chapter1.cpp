/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "gilneas.h"
#include "ScriptMgr.h"
#include "CreatureTextMgr.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "Vehicle.h"

/*######
## Quest 14098 - Evacuate the Merchant Square
######*/

enum FrightenedCitizen
{
    SAY_FRIGHTENED_CITIZEN_RESCUE   = 0,

    NPC_EVACUATION_STALKER_FIRST    = 35830,
    NPC_EVACUATION_STALKER_NEAR     = 35010,
    NPC_EVACUATION_STALKER_FAR      = 35011,
    NPC_RAMPAGING_WORGEN            = 35660,
    NPC_DARK_RANGER_THYALA          = 36312,
    NPC_GENERIC_TRIGGER_LAB_MP      = 35374, // target on ship
    NPC_KRENNAN_ARANAS_36331        = 36331,
    NPC_KING_GENN_GREYMANE_36332    = 36332,
    NPC_LORD_GODFREY_36330          = 36330,
    NPC_DARK_SCOUT                  = 37953,
    NPC_LORNA_CROWLEY               = 36457,
    NPC_LORNA_CRAWLEY               = 51409,
    NPC_HARNESS_38755               = 38755,
    NPC_HARNESS_43336               = 43336,
    NPC_CARRIAGE_43337              = 43337,
    NPC_ENSLAVED_VILLAGER           = 37694,
    NPC_SWIFT_MOUNTAIN_HORSE        = 36741,
    NPC_DROWNING_WATCHMANN_CREDIT   = 36450,
    NPC_PRINCE_LIAM_GREYMANE        = 36451,
    //NPC_ASHLEY_CREDIT               = 36289, handled with smartai
    NPC_LUCIUS                      = 36461,
    //NPC_CYNTIA_CREDIT               = 36287, handled with smartai
    GO_BALL_AND_CHAIN               = 201775,
    NPC_FORSAKEN_MACHINIST          = 36292,
    NPC_QUEST_14348_KILL_CREDIT     = 36233,
    //NPC_JAMES_CREDIT                = 36288, handled with smartai
    NPC_LORD_GODFREY                = 37875,
    NPC_TRIGGER                     = 36198,
    NPC_MASTIFF                     = 36405,
    NPC_KOROTH                      = 37808,
    NPC_LORD_DARIUS_CROWLEY         = 37195,
    NPC_GENERIC_TRIGGER_LAB_AOI     = 36286, // target on land
    NPC_HORRID_ABOMINATION          = 36231,

    CREDIT_35830                    = 35830,

    POINT_STALKER_FIRST             = 1,
    POINT_STALKER_NEAR              = 2,
    POINT_STALKER_FAR               = 3,

    EVENT_TALK_FRIGHTENED           = 1,
    EVENT_MOVE_TO_NEAR_STALKER      = 2,
    EVENT_MOVE_TO_FAR_STALKER       = 3,
    EVENT_DESPAWN                   = 4,

    QUEST_INVASION                = 14321,
    QUEST_LAST_CHANCE_AT_HUMANITY = 14375,
    QUEST_LAST_STAND              = 14222,
    QUEST_KILL_OR_BE_KILLED       = 14336,
    QUEST_YOU_CANT_TAKE_EM_ALONE  = 14348,
    QUEST_SAVE_THE_CHILDREN       = 14368,
    QUEST_LEADER_OF_THE_PACK      = 14386,
    QUEST_GASPING_FOR_BREATH      = 14395,
    QUEST_AS_THE_LAND_SHATTERS    = 14396,
    QUEST_GRANDMAS_CAT            = 14401,
    QUEST_TO_GREYMANE_MANOR       = 14465,
    QUEST_THE_KINGS_OBSERVATORY   = 14466,
    QUEST_ALAS_GILNEAS            = 14467,
    QUEST_EXODUS                  = 24438,
    QUEST_INTRODUCTIONS_ARE_IN_ORDER = 24472,
    QUEST_STORMGLEN               = 24483,
    QUEST_LIBERATION_DAY          = 24575,
    QUEST_BETRAYAL_AT_TEMPESTS_REACH = 24592,
    QUEST_LOSING_YOUR_TAIL        = 24616,
    QUEST_AT_OUR_DOORSTEP         = 24627,
    QUEST_PUSH_THEM_OUT           = 24676,
    QUEST_FLANK_THE_FORSAKEN      = 24677,
    QUEST_THE_HUNGRY_ETTIN        = 54416,
    QUEST_THE_BATTLE_FOR_GILNEAS_CITY = 24904,
    QUEST_ENDGAME = 26706,

    SPELL_RANDOM_POINT_POISON = 42266,
    SPELL_RANDOM_POINT_BONE = 42267,
    SPELL_RANDOM_POINT_BONE_2 = 42274,
    SPELL_SELF_ROOT = 42716,
    SPELL_CORPSE_EXPLOSION = 43999,
    SPELL_PARACHUTE = 45472,
    SPELL_DANS_EJECT_ALL_PASSENGERS = 51254,
    SPELL_FORCE_REACTION_1 = 61899,
    SPELL_LAUNCH3 = 66227,
    SPELL_LAUNCH2 = 66251,
    SPELL_FORCECAST_SUMMON_FORSAKEN_ASSASSIN = 68492,
    SPELL_BARREL_KEG_PLACED = 68555,
    SPELL_ABOMINATION_KILL_ME = 68558,
    SPELL_FIERY_BOULDER = 68591,
    SPELL_HORRID_ABOMINATION_EXPLOSION = 68560,
    SPELL_LAUNCH1 = 68659,
    SPELL_RESCUE_DROWNING_WATCHMANN = 68735,
    SPELL_SAVE_DROWNING_MILITIA_EFFECT = 68737,
    SPELL_EXIT_VEHICLE = 68741,
    SPELL_ROUND_UP_HORSE = 68903,
    SPELL_ROPE_IN_HORSE = 68908,
    SPELL_MOUNTAIN_HORSE_CREDIT = 68917,
    SPELL_ROPE_CHANNEL = 68940,
    SPELL_CATACLYSM_1 = 68953,
    SPELL_FORCECAST_CATACLYSM_I = 69027,
    SPELL_BARREL_KEG = 69094,
    SPELL_IN_STOCKS = 69169,
    SPELL_FORCECAST_SUMMON_SWIFT_MOUNTAIN_HORSE = 69256,
    SPELL_FORCECAST_GILNEAS_TELESCOPE = 69258,
    SPELL_STEALTH_70456 = 70456,
    SPELL_FREEZING_TRAP_EFFECT = 70794,
    SPELL_AIMED_SHOOT = 70796,
    SPELL_RIDE_VEHICLE_72764 = 72764,
    SPELL_SUMMON_CARRIAGE = 72767,
    SPELL_THROW_BOULDER = 72768,
    SPELL_LAST_STAND_COMPLETE = 72799,
    SPELL_CATACLYSM_3 = 80133,
    SPELL_CATACLYSM_2 = 80134,
    SPELL_UPDATE_BIND_TO_GREYMANE_MANOR = 82892,
    SPELL_GENERIC_QUEST_INVISIBLE_DETECTION_10 = 84481,
    SPELL_UPDATE_ZONE_AURAS = 89180,
    SPELL_FADE_BACK = 94053,
    SPELL_RIDE_VEHICLE = 94654,
    SPELL_FORCECAST_UPDATE_ZONE_AURAS = 94828,
    SPELL_LAUNCH4 = 96185,

    SPELL_PHASE_QUEST_ZONE_SPECIFIC_06 = 68481, // 181
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_07 = 68482, // 182
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_08 = 68483, // 183
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_09 = 69077, // 184
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_10 = 69078, // 185
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_11 = 69484, // 186
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_12 = 69485, // 187
    SPELL_PHASE_QUEST_ZONE_SPECIFIC_19 = 74096, // 194
};

class npc_frightened_citizen : public CreatureScript
{
    public:
        npc_frightened_citizen() : CreatureScript("npc_frightened_citizen") { }

        struct npc_frightened_citizenAI : public PassiveAI
        {
            npc_frightened_citizenAI(Creature* creature) : PassiveAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
        {
            if (Creature* stalkerNear = me->FindNearestCreature(NPC_EVACUATION_STALKER_FIRST, 20.0f))
                me->GetMotionMaster()->MovePoint(POINT_STALKER_FIRST, stalkerNear->GetPosition(), true);
        }

            void MovementInform(uint32 type, uint32 id) override
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                case POINT_STALKER_FIRST:
                    _events.ScheduleEvent(EVENT_TALK_FRIGHTENED, Seconds(1));
                    break;
                case POINT_STALKER_NEAR:
                    _events.ScheduleEvent(EVENT_MOVE_TO_FAR_STALKER, Milliseconds(1));
                    break;
                case POINT_STALKER_FAR:
                    _events.ScheduleEvent(EVENT_DESPAWN, Milliseconds(1));
                    break;
                default:
                    break;
            }
        }

            void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TALK_FRIGHTENED:
                        if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                        {
                            if (Player* player = summoner->ToPlayer())
                            {
                                player->KilledMonsterCredit(CREDIT_35830);
                                Talk(SAY_FRIGHTENED_CITIZEN_RESCUE, summoner);
                            }
                        }
                        _events.ScheduleEvent(EVENT_MOVE_TO_NEAR_STALKER, Seconds(2));
                        break;
                    case EVENT_MOVE_TO_NEAR_STALKER:
                        if (Creature* stalker = me->FindNearestCreature(NPC_EVACUATION_STALKER_FAR, 50.0f))
                            me->GetMotionMaster()->MovePoint(POINT_STALKER_FAR, stalker->GetPosition(), true);
                        else if (Creature* stalker = me->FindNearestCreature(NPC_EVACUATION_STALKER_NEAR, 100.0f))
                            me->GetMotionMaster()->MovePoint(POINT_STALKER_NEAR, stalker->GetPosition(), true);
                        break;
                    case EVENT_MOVE_TO_FAR_STALKER:
                        if (Creature* stalker = me->FindNearestCreature(NPC_EVACUATION_STALKER_FAR, 500.0f))
                            me->GetMotionMaster()->MovePoint(POINT_STALKER_FAR, stalker->GetPosition(), true);
                        break;
                    case EVENT_DESPAWN:
                        me->DespawnOrUnsummon();
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
            return new npc_frightened_citizenAI(creature);
        }
};

/*######
## Quest 14154 - By the Skin of his Teeth
######*/

enum WorgenRunt
{
    EVENT_JUMP_TO_PRISON            = 1,
    EVENT_AGGRO_PLAYER              = 2,
    EVENT_FORCE_DESPAWN             = 3,

    PHASE_ROOF                      = 0,
    PHASE_COMBAT                    = 1,

    WORGEN_ID_ROOF_1                = 0,
    WORGEN_ID_ROOF_2                = 1,
    WORGEN_ID_ROOF_3                = 2,
    WORGEN_ID_ROOF_4                = 3,
    WORGEN_ID_ROOF_5                = 4,
    WORGEN_ID_ROOF_6                = 5,
    WORGEN_ID_ROOF_7                = 6,

    WORGEN_ID_CATHEDRAL_1           = 7,
    WORGEN_ID_CATHEDRAL_2           = 8,
    WORGEN_ID_CATHEDRAL_3           = 9,
    WORGEN_ID_CATHEDRAL_4           = 10,
    WORGEN_ID_CATHEDRAL_5           = 11,
    WORGEN_ID_CATHEDRAL_6           = 12,
    WORGEN_ID_CATHEDRAL_7           = 13,
    WORGEN_ID_CATHEDRAL_8           = 14,
    WORGEN_ID_CATHEDRAL_9           = 15,

    NPC_WORGEN_RUNT_SPELL           = 35188,
};

Position const runtSpellSummonJumpPos = { -1671.915f, 1446.734f, 52.28712f };

class npc_worgen_runt : public CreatureScript
{
    public:
        npc_worgen_runt() :  CreatureScript("npc_worgen_runt") { }

        struct npc_worgen_runtAI : public ScriptedAI
        {
            npc_worgen_runtAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _worgenID = 0;
                _wayPointCounter = 0;
                _jumped = false;
                _playerGuid = ObjectGuid::Empty;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _events.SetPhase(PHASE_COMBAT);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                me->setActive(true); // we are in a phased and cut off map so we're fine to use that here
                _events.SetPhase(PHASE_ROOF);
                _events.ScheduleEvent(EVENT_FORCE_DESPAWN, Seconds(70), 0, PHASE_ROOF);
                _playerGuid = summoner->GetGUID();
                if (me->GetEntry() == NPC_WORGEN_RUNT_SPELL)
                    me->GetMotionMaster()->MoveJump(runtSpellSummonJumpPos, 16.0f, 4.371286f);
            }

            void DoAction(int32 action) override
            {
                _worgenID = action;
                switch (_worgenID) // ugly as fuck but needed for individual controls
                {
                    // House roof cases
                    case WORGEN_ID_ROOF_1:
                        _wayPointCounter = runtHousePathSize1;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize1, worgenRuntHousePath1, runtHousePathSize1);
                        break;
                    case WORGEN_ID_ROOF_2:
                        _wayPointCounter = runtHousePathSize2;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize2, worgenRuntHousePath2, runtHousePathSize2);
                        break;
                    case WORGEN_ID_ROOF_3:
                        _wayPointCounter = runtHousePathSize3;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize3, worgenRuntHousePath3, runtHousePathSize3);
                        break;
                    case WORGEN_ID_ROOF_4:
                        _wayPointCounter = runtHousePathSize4;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize4, worgenRuntHousePath4, runtHousePathSize4);
                        break;
                    case WORGEN_ID_ROOF_5:
                        _wayPointCounter = runtHousePathSize5;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize5, worgenRuntHousePath5, runtHousePathSize5);
                        break;
                    case WORGEN_ID_ROOF_6:
                        _wayPointCounter = runtHousePathSize6;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize6, worgenRuntHousePath6, runtHousePathSize6);
                        break;
                    case WORGEN_ID_ROOF_7:
                        _wayPointCounter = runtHousePathSize7;
                        me->GetMotionMaster()->MoveSmoothPath(runtHousePathSize7, worgenRuntHousePath7, runtHousePathSize7);
                        break;
                    // Cathedral cases
                    case WORGEN_ID_CATHEDRAL_1:
                        _wayPointCounter = runtCathedralPathSize1;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize1, worgenRuntCathedralPath1, runtCathedralPathSize1);
                        break;
                    case WORGEN_ID_CATHEDRAL_2:
                        _wayPointCounter = runtCathedralPathSize2;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize2, worgenRuntCathedralPath1, runtCathedralPathSize2);
                        break;
                    case WORGEN_ID_CATHEDRAL_3:
                        _wayPointCounter = runtCathedralPathSize3;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize3, worgenRuntCathedralPath1, runtCathedralPathSize3);
                        break;
                    case WORGEN_ID_CATHEDRAL_4:
                        _wayPointCounter = runtCathedralPathSize4;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize4, worgenRuntCathedralPath1, runtCathedralPathSize4);
                        break;
                    case WORGEN_ID_CATHEDRAL_5:
                        _wayPointCounter = runtCathedralPathSize5;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize5, worgenRuntCathedralPath1, runtCathedralPathSize5);
                        break;
                    case WORGEN_ID_CATHEDRAL_6:
                        _wayPointCounter = runtCathedralPathSize6;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize6, worgenRuntCathedralPath1, runtCathedralPathSize6);
                        break;
                    case WORGEN_ID_CATHEDRAL_7:
                        _wayPointCounter = runtCathedralPathSize7;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize7, worgenRuntCathedralPath1, runtCathedralPathSize7);
                        break;
                    case WORGEN_ID_CATHEDRAL_8:
                        _wayPointCounter = runtCathedralPathSize8;
                        me->GetMotionMaster()->MoveSmoothPath(runtCathedralPathSize8, worgenRuntCathedralPath1, runtCathedralPathSize8);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(Seconds(5));
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == EFFECT_MOTION_TYPE && pointId == _wayPointCounter && !_jumped)
                {
                    _jumped = true;
                    _events.ScheduleEvent(EVENT_JUMP_TO_PRISON, Milliseconds(1));
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() && !_events.IsInPhase(PHASE_ROOF))
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_FORCE_DESPAWN:
                            me->DespawnOrUnsummon();
                            break;
                        case EVENT_JUMP_TO_PRISON:
                            me->GetMotionMaster()->MoveJump(worgenRuntJumpPos[_worgenID], 16.0f, _worgenID < WORGEN_ID_CATHEDRAL_1 ? 19.2911f : frand(3.945607f, 4.852813f));
                            me->SetHomePosition(worgenRuntJumpPos[_worgenID]);
                            _events.ScheduleEvent(EVENT_AGGRO_PLAYER, Seconds(2));
                            break;
                        case EVENT_AGGRO_PLAYER:
                            if (Unit* player = ObjectAccessor::GetPlayer(*me, _playerGuid))
                                if (me->IsAIEnabled && me->GetHomePosition().IsInDist(player, 100.0f))
                                    me->AI()->AttackStart(player);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        private:
            uint32 _worgenID;
            uint32 _wayPointCounter;
            bool _jumped;
            ObjectGuid _playerGuid;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_worgen_runtAI(creature);
        }
};

/*######
## Quest 14159 - The Rebel Lord's Arsenal
######*/

enum TheRebelLordsArsena
{
    PHASE_ID_SUMMON         = 170,
    PHASE_ID_WOUND          = 171,
    NPC_GENERIC_TRIGGER_LAB = 35374,

    SPELL_SHOOT_INSTAKILL   = 67593,
    SPELL_COSMETIC_ATTACK   = 42880,
    SPELL_PULL_TO           = 67357,

    EVENT_COSMETIC_ATTACK   = 1,
    EVENT_JUMP_TO_PLAYER,
    EVENT_SHOOT_JOSIAH
};

Position const josiahJumpPos = { -1796.63f, 1427.73f, 12.4624f };

class npc_josiah_avery : public CreatureScript
{
    public:
        npc_josiah_avery() :  CreatureScript("npc_josiah_avery") { }

        struct npc_josiah_averyAI : public PassiveAI
        {
            npc_josiah_averyAI(Creature* creature) : PassiveAI(creature) { }

            void IsSummonedBy(Unit* summoner) override
            {
                PhasingHandler::AddPhase(me, PHASE_ID_SUMMON, true);
                PhasingHandler::AddPhase(me, PHASE_ID_WOUND, true);
                _playerGuid = summoner->GetGUID();
                _events.ScheduleEvent(EVENT_COSMETIC_ATTACK, Milliseconds(500));
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(Seconds(5));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                        case EVENT_COSMETIC_ATTACK:
                            if (Player* player = ObjectAccessor::GetPlayer(*me, _playerGuid))
                            {
                                DoCast(player, SPELL_COSMETIC_ATTACK);
                                if (Creature* lorna = me->FindNearestCreature(NPC_LORNA_CROWLEY, 30.0f, true))
                                    if (Creature* labTrigger = lorna->FindNearestCreature(NPC_GENERIC_TRIGGER_LAB, 5.0f, true))
                                        labTrigger->CastSpell(player, SPELL_PULL_TO);

                                _events.ScheduleEvent(EVENT_JUMP_TO_PLAYER, Seconds(1));
                            }
                            break;
                        case EVENT_JUMP_TO_PLAYER:
                            me->GetMotionMaster()->MoveJump(josiahJumpPos, 10.0f, 14.18636f);
                            _events.ScheduleEvent(EVENT_SHOOT_JOSIAH, Milliseconds(500));
                            break;
                        case EVENT_SHOOT_JOSIAH:
                            if (Creature* lorna = me->FindNearestCreature(NPC_LORNA_CROWLEY, 30.0f, true))
                                lorna->CastSpell(me, SPELL_SHOOT_INSTAKILL, true);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            ObjectGuid _playerGuid;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_josiah_averyAI(creature);
        }
};

/*######
## Quest 14293 - Save Krennan Aranas
######*/

Position const greymanesHorseJumpPos = { -1676.16f, 1346.19f, 15.1349f };

enum GreymanesHorse
{
    EVENT_START_PATH_1      = 1,
    EVENT_START_PATH_2,
    EVENT_JUMP_TO_KRENNAN,
    EVENT_ANNOUNCE_RESCUE,

    NPC_RESCUED_KRENNAN     = 35907,
    NPC_TRAPPED_KRENNAN     = 35753,
};

class npc_greymanes_horse : public CreatureScript
{
    public:
        npc_greymanes_horse() : CreatureScript("npc_greymanes_horse") { }

        struct npc_greymanes_horseAI : public VehicleAI
        {
            npc_greymanes_horseAI(Creature* creature) : VehicleAI(creature){}

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
                {
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    _events.ScheduleEvent(EVENT_START_PATH_1, Seconds(1));
                }
                else if (apply && passenger->GetEntry() == NPC_RESCUED_KRENNAN)
                    _events.ScheduleEvent(EVENT_START_PATH_2, Seconds(1));
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == EFFECT_MOTION_TYPE && pointId == pathSize1)
                    _events.ScheduleEvent(EVENT_JUMP_TO_KRENNAN, Milliseconds(1));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_PATH_1:
                            me->SetControlled(false, UNIT_STATE_ROOT);
                            me->GetMotionMaster()->MoveSmoothPath(pathSize1, greymanesHorsePath1, pathSize1);
                            break;
                        case EVENT_JUMP_TO_KRENNAN:
                            me->GetMotionMaster()->MoveJump(greymanesHorseJumpPos, 16.0f, 14.00968f);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_RESCUE, Seconds(2));
                            break;
                        case EVENT_ANNOUNCE_RESCUE:
                            me->SetControlled(true, UNIT_STATE_ROOT);
                            break;
                        case EVENT_START_PATH_2:
                            me->SetControlled(true, UNIT_STATE_ROOT);
                            me->GetMotionMaster()->MoveSmoothPath(pathSize2, greymanesHorsePath2, pathSize2);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            uint32 _currentPath;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_greymanes_horseAI(creature);
        }
};

/*######
## Quest 14212 - Sacrifices
######*/

enum CrowleysHorse
{
    EVENT_JUMP_OVER_BARRICADES_1 = 1,
    EVENT_JUMP_OVER_BARRICADES_2,
    EVENT_MOVE_PATH_MAIN_1,
    EVENT_MOVE_PATH_MAIN_2,
    EVENT_MOVE_OFF_PATH = 6,
    EVENT_DISMOUNT_PLAYER,

    PATH_ID_CROWLEYS_HORSE_1    = 352310,
    PATH_ID_CROWLEYS_HORSE_2    = 352311,
    PATH_ID_CROWLEYS_HORSE_3    = 444280,

    SPELL_THROW_TORCH           = 67063,
    NPC_CROWLEYS_HORSE_2        = 44428,
};

Position const crowleysHorseJumpPos = { -1714.762f, 1673.16f, 20.49182f };
Position const crowleysHorseJumpPos2 = { -1566.71f, 1708.04f, 20.4849f };

class npc_crowleys_horse : public CreatureScript
{
    public:
        npc_crowleys_horse() : CreatureScript("npc_crowleys_horse") { }

        struct npc_crowleys_horseAI : public VehicleAI
        {
            npc_crowleys_horseAI(Creature* creature) : VehicleAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _currentPath = 0;
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (apply && passenger->GetTypeId() == TYPEID_PLAYER && me->GetEntry() != NPC_CROWLEYS_HORSE_2)
                {
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    _events.ScheduleEvent(EVENT_JUMP_OVER_BARRICADES_1, Seconds(2));
                }
                else if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
                {
                    me->SetControlled(true, UNIT_STATE_ROOT);
                    _events.ScheduleEvent(EVENT_MOVE_OFF_PATH, Seconds(2));
                }
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == WAYPOINT_MOTION_TYPE && pointId == 14 && _currentPath == PATH_ID_CROWLEYS_HORSE_1)
                    _events.ScheduleEvent(EVENT_JUMP_OVER_BARRICADES_2, Seconds(1));
                else if (type == WAYPOINT_MOTION_TYPE && pointId ==  15 && _currentPath == PATH_ID_CROWLEYS_HORSE_2)
                    _events.ScheduleEvent(EVENT_DISMOUNT_PLAYER, Milliseconds(1));
                else if (type == WAYPOINT_MOTION_TYPE && pointId == 16 && _currentPath == PATH_ID_CROWLEYS_HORSE_3)
                    _events.ScheduleEvent(EVENT_DISMOUNT_PLAYER, Milliseconds(1));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_JUMP_OVER_BARRICADES_1:
                            me->SetControlled(false, UNIT_STATE_ROOT);
                            me->GetMotionMaster()->MoveJump(crowleysHorseJumpPos, 16.0f, 18.56182f);
                            _events.ScheduleEvent(EVENT_MOVE_PATH_MAIN_1, Seconds(2));
                            break;
                        case EVENT_MOVE_PATH_MAIN_1:
                            me->GetMotionMaster()->MovePath(PATH_ID_CROWLEYS_HORSE_1, false);
                            _currentPath = PATH_ID_CROWLEYS_HORSE_1;
                            break;
                        case EVENT_JUMP_OVER_BARRICADES_2:
                            me->GetMotionMaster()->MoveJump(crowleysHorseJumpPos2, 16.0f, 18.56182f);
                            _events.ScheduleEvent(EVENT_MOVE_PATH_MAIN_2, Seconds(2));
                            break;
                        case EVENT_MOVE_PATH_MAIN_2:
                            _currentPath = PATH_ID_CROWLEYS_HORSE_2;
                            me->GetMotionMaster()->MovePath(PATH_ID_CROWLEYS_HORSE_2, false);
                            break;
                        case EVENT_DISMOUNT_PLAYER:
                        {
                            std::vector<Unit*> storedAttackers;

                            for (Unit* attacker : me->getAttackers())
                                storedAttackers.push_back(attacker);

                            for (Unit* attacker : storedAttackers)
                            {
                                if (Creature* creature = attacker->ToCreature())
                                    if (creature->IsAIEnabled)
                                        creature->AI()->EnterEvadeMode();
                            }

                            me->RemoveAurasDueToSpell(VEHICLE_SPELL_RIDE_HARDCODED);
                            me->DespawnOrUnsummon(Seconds(5));
                            break;
                        }
                        case EVENT_MOVE_OFF_PATH:
                            me->SetControlled(false, UNIT_STATE_ROOT);
                            _currentPath = PATH_ID_CROWLEYS_HORSE_3;
                            me->GetMotionMaster()->MovePath(PATH_ID_CROWLEYS_HORSE_3, false);
                            break;
                        default:
                            break;
                    }
                }
            }
        private:
            EventMap _events;
            uint32 _currentPath;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_crowleys_horseAI(creature);
        }
};

const uint32 WorgenOrCitizen[] =
{
    34981, 35660, 35836
};

/// 195327
class go_merchant_square_door : public GameObjectScript
{
public:
    go_merchant_square_door() : GameObjectScript("go_merchant_square_door") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        int Random = rand32() % (sizeof(WorgenOrCitizen) / sizeof(uint32));

        if (go->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        {
            if (go->GetGoState() == GO_STATE_READY)
            {
                go->SetGoState(GO_STATE_ACTIVE);
                player->SummonCreature(WorgenOrCitizen[Random], go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), go->GetAngle(player), TEMPSUMMON_TIMED_DESPAWN, 30000);
            }
        }
		
        return true;
    }
};

// 37953
class npc_dark_scout_37953 : public CreatureScript
{
public:
    npc_dark_scout_37953() : CreatureScript("npc_dark_scout_37953") { }

    enum eNpc
    {
        TALK_EASY = 0,
        TALK_DO = 2,
        TALK_HOW = 1,
    };

    struct npc_dark_scout_37953AI : public ScriptedAI
    {
        npc_dark_scout_37953AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;

        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
            {
                m_playerGUID = player->GetGUID();
                me->GetMotionMaster()->Clear();
                me->SetFacingToObject(player);
                me->AI()->Talk(TALK_EASY);
                m_events.ScheduleEvent(EVENT_TALK_START, 5000);
                m_events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (player->GetQuestStatus(QUEST_LOSING_YOUR_TAIL) == QUEST_STATUS_INCOMPLETE)
                            if (player->GetDistance2d(me) < 30.0f)
                            {
                                if (!me->IsInCombat())
                                    m_events.ScheduleEvent(EVENT_MELEE_ATTACK, 500);
                                m_events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                                break;
                            }
                    me->DespawnOrUnsummon(100);
                    break;
                }
                case EVENT_TALK_START:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(TALK_DO, player);
                    m_events.ScheduleEvent(EVENT_SHOOT, 7500);
                    m_events.ScheduleEvent(EVENT_CHECK_AURA, 250);
                    break;
                }
                case EVENT_SHOOT:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        m_events.CancelEvent(EVENT_CHECK_AURA);
                        me->CastSpell(player, SPELL_AIMED_SHOOT);
                        me->GetMotionMaster()->Clear();
                        me->SetWalk(true);
                        me->SetSpeed(MOVE_WALK, 1.0f);
                        me->GetMotionMaster()->MoveChase(player);
                        me->Attack(player, true);
                    }
                    break;
                }
                case EVENT_CHECK_AURA:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (player->HasAura(SPELL_FREEZING_TRAP_EFFECT))
                        {
                            m_events.ScheduleEvent(EVENT_CHECK_AURA, 250);
                            break;
                        }
                    m_events.CancelEvent(EVENT_SHOOT);
                    Talk(TALK_HOW);
                    m_events.ScheduleEvent(EVENT_MELEE_ATTACK, 1500);
                    break;
                }
                case EVENT_MELEE_ATTACK:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (!player->IsInCombat())
                            if (player->GetDistance2d(me) < 30.0f)
                            {
                                me->GetMotionMaster()->Clear();
                                me->SetWalk(true);
                                me->SetSpeed(MOVE_WALK, 1.0f);
                                me->GetMotionMaster()->MoveChase(player);
                                me->Attack(player, true);
                            }
                    m_events.ScheduleEvent(EVENT_MELEE_ATTACK, 1500);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_dark_scout_37953AI(creature);
    }
};

// 36405
class npc_mastiff_36405 : public CreatureScript
{
public:
    npc_mastiff_36405() : CreatureScript("npc_mastiff_36405") { }

    struct npc_mastiff_36405AI : public ScriptedAI
    {
        npc_mastiff_36405AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_thyalaGUID;
        ObjectGuid  m_player_GUID;

        void Reset() override
        {
            me->SetWalk(true);
            me->SetSpeed(MOVE_RUN, true);
            me->SetReactState(REACT_AGGRESSIVE);
            m_events.Reset();
            m_thyalaGUID = ObjectGuid::Empty;
            m_player_GUID = ObjectGuid::Empty;
            m_events.RescheduleEvent(EVENT_CHECK_ATTACK, 1000);
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
            case PLAYER_GUID:
            {
                m_player_GUID = guid;
                break;
            }
            case NPC_DARK_RANGER_THYALA:
            {
                m_thyalaGUID = guid;
                break;
            }
            }
        }

        void EnterEvadeMode(EvadeReason /*reason*/) override
        {
            StartAttackThyala();
            m_events.RescheduleEvent(EVENT_CHECK_ATTACK, 1000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ATTACK:
                {
                    StartAttackThyala();
                    m_events.ScheduleEvent(EVENT_CHECK_ATTACK, 1000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }

        void StartAttackThyala()
        {
            Creature* thyala = ObjectAccessor::GetCreature(*me, m_thyalaGUID);
            if (!thyala)
                return;

            if (!thyala->IsAlive() || !thyala->IsInWorld())
            {
                me->DespawnOrUnsummon(1);
                return;
            }

            if (me->IsInCombat())
                if (Unit* npc = me->GetVictim())
                    if (npc->GetEntry() == NPC_DARK_RANGER_THYALA)
                        return;

            me->SetReactState(REACT_AGGRESSIVE);
            me->GetMotionMaster()->MoveChase(thyala, 3.0f, frand(0.0f, 6.28f));
            me->Attack(thyala, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mastiff_36405AI(creature);
    }
};

// 36290
class npc_lord_godfrey_36290 : public CreatureScript
{
public:
    npc_lord_godfrey_36290() : CreatureScript("npc_lord_godfrey_36290") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == 14396)
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_06);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_07);
            player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08, player);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_10);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_11);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_12);
        }

        return true;
    }
};

// 68659 trigger 96114
class spell_launch_68659 : public SpellScriptLoader
{
public:
    spell_launch_68659() : SpellScriptLoader("spell_launch_68659") { }

    class spell_launch_68659_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_launch_68659_SpellScript);

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if([](WorldObject* object)
            {
                return object->GetEntry() == NPC_GENERIC_TRIGGER_LAB_MP;
            });

            if (targets.size() > 0)
                if (WorldObject* wo = targets.front())
                    if (Creature* target = wo->ToCreature())
                    {
                        Position t = target->GetPosition();
                        if (Unit* unit = GetCaster())
                            if (Vehicle* car = unit->GetVehicleKit())
                                if (Unit* pas = car->GetPassenger(0))
                                    if (Player* player = pas->ToPlayer())
                                    {
                                        player->NearTeleportTo(t.GetPositionX(), t.GetPositionY(), t.GetPositionZ(), player->GetOrientation());
                                        return;
                                    }
                    }

            targets.clear();
            this->FinishCast(SPELL_CAST_OK);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_launch_68659_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_launch_68659_SpellScript();
    }
};

// 36331
class npc_krennan_aranas_36331 : public CreatureScript
{
public:
    npc_krennan_aranas_36331() : CreatureScript("npc_krennan_aranas_36331") { }

    struct npc_krennan_aranas_36331AI : public ScriptedAI
    {
        npc_krennan_aranas_36331AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        bool        m_videoStarted = false;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_kingGUID;
        ObjectGuid  m_godfreyGUID;
        std::set<ObjectGuid> pList;

        void Reset() override
        {
            m_kingGUID = ObjectGuid::Empty;
            m_godfreyGUID = ObjectGuid::Empty;
            m_events.RescheduleEvent(EVENT_CHECK_ARRIVEL_PLAYER, 1000);
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ARRIVEL_PLAYER:
                {
                    CheckVideoMember();
                    if (!m_videoStarted)
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        {
                            player->CastSpell(player, SPELL_IN_STOCKS, true);
                            player->CastSpell(player, SPELL_SELF_ROOT, true);
                            player->AddUnitFlag2(UNIT_FLAG2_DISABLE_TURN);
                            m_videoStarted = true;

                            m_events.ScheduleEvent(EVENT_TALK_PART_00, 4000);
                            return;
                        }

                    m_videoStarted = false;
                    m_playerGUID = ObjectGuid::Empty;
                    m_events.ScheduleEvent(EVENT_CHECK_ARRIVEL_PLAYER, 1000);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(0, player);
                    if (Creature* king = ObjectAccessor::GetCreature(*me, m_kingGUID))
                        king->RemoveNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);

                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 14000);
                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* lord = ObjectAccessor::GetCreature(*me, m_godfreyGUID))
                        {
                            player->CastSpell(player, SPELL_CATACLYSM_1);
                            lord->AI()->Talk(0, player);
                        }
                    m_events.ScheduleEvent(EVENT_TALK_PART_02, 8000);
                    break;
                }
                case EVENT_TALK_PART_02:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* king = ObjectAccessor::GetCreature(*me, m_kingGUID))
                        {
                            player->CastSpell(player, SPELL_CATACLYSM_2);
                            king->AI()->Talk(0, player);
                        }
                    m_events.ScheduleEvent(EVENT_TALK_PART_03, 9000);
                    break;
                }
                case EVENT_TALK_PART_03:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* king = ObjectAccessor::GetCreature(*me, m_kingGUID))
                        {
                            player->CastSpell(player, SPELL_CATACLYSM_3);
                            king->AI()->Talk(1, player);
                        }
                    m_events.ScheduleEvent(EVENT_TALK_PART_04, 8000);
                    break;
                }
                case EVENT_TALK_PART_04:
                {
                    if (ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        //player->CastSpell(player, SPELL_LAST_STAND_COMPLETE_2);
                        AddPlayer();
                    }
                    if (Creature* king = ObjectAccessor::GetCreature(*me, m_kingGUID))
                        king->AddNpcFlag(UNIT_NPC_FLAG_QUESTGIVER);

                    m_videoStarted = false;
                    m_playerGUID = ObjectGuid::Empty;
                    m_events.ScheduleEvent(EVENT_CHECK_ARRIVEL_PLAYER, 1000);
                    break;
                }
                }
            }
        }

        void CheckVideoMember()
        {
            if (!m_kingGUID)
                if (Creature* king = me->FindNearestCreature(NPC_KING_GENN_GREYMANE_36332, 25.0f))
                    m_kingGUID = king->GetGUID();
            if (!m_godfreyGUID)
                if (Creature* lord = me->FindNearestCreature(NPC_LORD_GODFREY_36330, 25.0f))
                    m_godfreyGUID = lord->GetGUID();

            if (m_videoStarted)
                return;

            if (Player* player = me->SelectNearestPlayer(10.0f))
                if (!HasPlayer(player->GetGUID()))
                    if (player->GetQuestStatus(QUEST_LAST_STAND) == QUEST_STATUS_REWARDED && player->GetQuestStatus(QUEST_LAST_CHANCE_AT_HUMANITY) == QUEST_STATUS_NONE)
                        if (player->GetAreaId() == AREA_GILNEAS_DUSKHAVEN)
                        {
                            m_playerGUID = player->GetGUID();
                            return;
                        }

            m_playerGUID = ObjectGuid::Empty;
        }

        void AddPlayer()
        {
            if (!HasPlayer(m_playerGUID))
                pList.insert(m_playerGUID);
        }

        bool HasPlayer(ObjectGuid guid)
        {
            return (pList.find(guid) != pList.end());
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_krennan_aranas_36331AI(creature);
    }
};

// 6687
class at_the_blackwald_6687 : public AreaTriggerScript
{
public:
    at_the_blackwald_6687() : AreaTriggerScript("at_the_blackwald_6687") { }

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/, bool /*enter*/) override
    {
        if (player->GetQuestStatus(QUEST_LOSING_YOUR_TAIL) == QUEST_STATUS_INCOMPLETE)
            if (!player->FindNearestCreature(NPC_DARK_SCOUT, 50.0f))
                player->CastSpell(player, SPELL_FREEZING_TRAP_EFFECT, true);
        return false;
    }
};

// 37783
class npc_lorna_crowley_37783 : public CreatureScript
{
public:
    npc_lorna_crowley_37783() : CreatureScript("npc_lorna_crowley_37783") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_BATTLE_FOR_GILNEAS_CITY)
        {
            player->ForceCompleteQuest(QUEST_THE_BATTLE_FOR_GILNEAS_CITY);
            player->TeleportTo(654, -1668.160f, 1664.280f, 20.573f, 4.555f);
        }
        return false;
    }

    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_PUSH_THEM_OUT)
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_11);
            player->CastSpell(player, SPELL_PHASE_QUEST_ZONE_SPECIFIC_12, true);
        }
        return false;
    }
};

// 36332
class npc_king_genn_greymane_36332 : public CreatureScript
{
public:
    npc_king_genn_greymane_36332() : CreatureScript("npc_king_genn_greymane_36332") { }

    bool OnQuestReward(Player* player, Creature* /*creature*/, const Quest* quest, uint32) override
    {
        if (quest->GetQuestId() == QUEST_LAST_CHANCE_AT_HUMANITY)
        {
            player->CastSpell(player, SPELL_PHASE_QUEST_ZONE_SPECIFIC_06, true);
            player->SetUnitFlags2(UNIT_FLAG2_REGENERATE_POWER);
            player->RemoveAura(42716);
            player->RemoveAura(50220);
            player->RemoveAura(58284);
            player->RemoveAura(68630);
            return true;
        }
        return false;
    }
};

// 201594
class go_koroths_banner_201594 : public GameObjectScript
{
public:
    go_koroths_banner_201594() : GameObjectScript("go_koroths_banner_201594") {}

    struct go_koroths_banner_201594AI : public GameObjectAI
    {
        go_koroths_banner_201594AI(GameObject* go) : GameObjectAI(go) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_korothGUID;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            m_korothGUID = ObjectGuid::Empty;
        }

        void OnStateChanged(uint32 /*state*/, Unit* unit) override
        {
            if (unit)
                if (Creature* koroth = go->FindNearestCreature(36294, 50.0f))
                    if (Player* player = unit->ToPlayer())
                    {
                        m_playerGUID = player->GetGUID();
                        m_korothGUID = koroth->GetGUID();
                        m_events.RescheduleEvent(EVENT_TALK_PART_00, 1000);
                    }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK_PART_00:
                {
                    if (Creature* koroth = ObjectAccessor::GetCreature(*go, m_korothGUID))
                        if (Player* player = ObjectAccessor::GetPlayer(*go, m_playerGUID))
                            koroth->AI()->Talk(0, player);
                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 6000);
                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    if (Creature* koroth = ObjectAccessor::GetCreature(*go, m_korothGUID))
                        if (Player* player = ObjectAccessor::GetPlayer(*go, m_playerGUID))
                            koroth->AI()->Talk(1, player);
                    break;
                }
                }
            }
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_koroths_banner_201594AI(go);
    }
};

// 34571
class npc_gwen_armstead_34571 : public CreatureScript
{
public:
    npc_gwen_armstead_34571() : CreatureScript("npc_gwen_armstead_34571") {}

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_KILL_OR_BE_KILLED)
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_06);
            player->CastSpell(player, SPELL_PHASE_QUEST_ZONE_SPECIFIC_07);
            return true;
        }
        return false;
    }
};

// 68903
class spell_round_up_horse_68903 : public SpellScriptLoader
{
public:
    spell_round_up_horse_68903() : SpellScriptLoader("spell_round_up_horse_68903") { }

    class spell_round_up_horse_68903_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_round_up_horse_68903_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ 68903 });
        }

        void HandleEffectDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit()->GetTypeId() != TYPEID_UNIT || GetCaster()->GetTypeId() != TYPEID_PLAYER || GetCaster()->ToPlayer()->GetQuestStatus(14416) != QUEST_STATUS_INCOMPLETE)
                return;
            GetHitUnit()->ToCreature()->DespawnOrUnsummon();
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_round_up_horse_68903_SpellScript::HandleEffectDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_round_up_horse_68903_SpellScript();
    }
};

// 68735
class spell_rescue_drowning_watchman_68735 : public SpellScriptLoader
{
public:
    spell_rescue_drowning_watchman_68735() : SpellScriptLoader("spell_rescue_drowning_watchman_68735") { }

    class spell_rescue_drowning_watchman_68735_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_rescue_drowning_watchman_68735_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ 68735 });
        }

        void HandleEffectDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER || GetHitUnit()->GetTypeId() != TYPEID_UNIT || GetCaster()->GetVehicleKit() == NULL)
                return;
            if (GetCaster()->ToPlayer()->GetQuestStatus(14395) != QUEST_STATUS_INCOMPLETE)
            {
                GetCaster()->RemoveAurasDueToSpell(68735);
                return;
            }
            if (GetCaster()->IsInWater())
                GetHitUnit()->CastCustomSpell(VEHICLE_SPELL_RIDE_HARDCODED, SPELLVALUE_BASE_POINT0, 1, GetCaster(), false);
            else if (GetHitUnit()->GetVehicle())
            {
                GetCaster()->GetVehicleKit()->RemoveAllPassengers();
                GetHitUnit()->RemoveAurasDueToSpell(68730);
                GetHitUnit()->CastSpell(GetHitUnit(), 68442, true);
                GetCaster()->ToPlayer()->KilledMonsterCredit(36440);
                GetCaster()->RemoveAurasDueToSpell(68735);
                GetHitUnit()->ToCreature()->DespawnOrUnsummon(5000);
                GetHitUnit()->ToCreature()->AI()->Talk(0);
            }
            else
                GetCaster()->RemoveAurasDueToSpell(68735);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_rescue_drowning_watchman_68735_SpellScript::HandleEffectDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_rescue_drowning_watchman_68735_SpellScript();
    }
};

// 49944
class item_belysras_talisman_49944 : public ItemScript
{
public:
    item_belysras_talisman_49944() : ItemScript("item_belysras_talisman_49944") { }

    bool OnUse(Player* player, Item* /*item*/, SpellCastTargets const& /*targets*/, ObjectGuid /*castId*/) override
    {
        if (player->GetQuestStatus(QUEST_LOSING_YOUR_TAIL) == QUEST_STATUS_INCOMPLETE)
            if (player->HasAura(SPELL_FREEZING_TRAP_EFFECT))
                player->RemoveAura(SPELL_FREEZING_TRAP_EFFECT);

        return false;
    }
};

// 36606
class npc_queen_mia_greymane_36606 : public CreatureScript
{
public:
    npc_queen_mia_greymane_36606() : CreatureScript("npc_queen_mia_greymane_36606") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_KINGS_OBSERVATORY)
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_06);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_07);
            player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08, player);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_10);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_11);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_12);
        }

        return true;
    }

    bool OnQuestReward(Player* player, Creature* /*creature*/, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_TO_GREYMANE_MANOR)
            player->CastSpell(player, SPELL_UPDATE_BIND_TO_GREYMANE_MANOR);

        return false;
    }
};

// 43337
class npc_stagecoach_carriage_43337 : public CreatureScript
{
public:
    npc_stagecoach_carriage_43337() : CreatureScript("npc_stagecoach_carriage_43337") { }

    struct npc_stagecoach_carriage_43337AI : public ScriptedAI
    {
        npc_stagecoach_carriage_43337AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_lornaGUID;
        ObjectGuid  m_harnessGUID;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            m_lornaGUID = ObjectGuid::Empty;
            m_harnessGUID = ObjectGuid::Empty;
            me->setActive(true);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Creature* car = summoner->ToCreature())
                m_harnessGUID = car->GetGUID();
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
            case NPC_LORNA_CRAWLEY:
                m_lornaGUID = summon->GetGUID();
                break;
            }
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (passenger->ToPlayer())
                    if (Creature* car = ObjectAccessor::GetCreature(*me, m_harnessGUID))
                        car->AI()->DoAction(EVENT_START_MOVEMENT);
            }
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
            case PLAYER_GUID:
                m_playerGUID = guid;
                break;
            case NPC_HARNESS_43336:
                m_harnessGUID = guid;
                break;
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
            case EVENT_SAY_ATTACK:
                if (Creature* lorna = ObjectAccessor::GetCreature(*me, m_lornaGUID))
                    lorna->AI()->Talk(0);
                break;
            case EVENT_DESPAWN_PART_00:
                me->DespawnOrUnsummon(1000);
                break;
            case EVENT_EXIT_VEHICLE:
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    player->ExitVehicle();
                break;
            case EVENT_ENTER_VEHICLE:
                if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    if (me->GetVehicleKit())
                        player->CastSpell(me, SPELL_RIDE_VEHICLE_72764, true);
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_stagecoach_carriage_43337AI(creature);
    }
};

// 38764
class npc_lord_hewell_38764 : public CreatureScript
{
public:
    npc_lord_hewell_38764() : CreatureScript("npc_lord_hewell_38764") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 /*action*/) override
    {
        if (player->GetQuestStatus(QUEST_FLANK_THE_FORSAKEN) == QUEST_STATUS_COMPLETE)
        {
            player->CastSpell(player, 72773);
        }

        return false;
    }
};

// 36452
class npc_gwen_armstead_36452 : public CreatureScript
{
public:
    npc_gwen_armstead_36452() : CreatureScript("npc_gwen_armstead_36452") {}

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_TO_GREYMANE_MANOR)
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_06);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_07);
            player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08, player);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_10);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_11);
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_12);
            player->CastSpell(player, SPELL_FORCECAST_SUMMON_SWIFT_MOUNTAIN_HORSE);
        }
        return true;
    }
};

// 201775
class go_ball_and_chain_201775 : public GameObjectScript
{
public:
    go_ball_and_chain_201775() : GameObjectScript("go_ball_and_chain_201775") {}

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit) override
    {
        if (state == 2 && unit)
            if (Player* player = unit->ToPlayer())
                if (player->GetQuestStatus(QUEST_LIBERATION_DAY) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_LIBERATION_DAY) == QUEST_STATUS_COMPLETE)
                    if (Creature* villager = go->FindNearestCreature(NPC_ENSLAVED_VILLAGER, 5.0f))
                    {
                        villager->AI()->SetGUID(go->GetGUID(), go->GetEntry());
                        villager->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
                        villager->AI()->DoAction(EVENT_START_ANIM);
                    }
    }
};

// 196399
class go_gate_196399 : public GameObjectScript
{
public:
    go_gate_196399() : GameObjectScript("go_gate_196399") {}

    struct go_gate_196399AI : public GameObjectAI
    {
        go_gate_196399AI(GameObject* go) : GameObjectAI(go) { }

        EventMap m_events;
        std::list<ObjectGuid> cList;
        bool m_isUsed;

        void Reset() override
        {
            m_events.RescheduleEvent(EVENT_CHECK_PLAYER_NEAR, 1000);
            m_isUsed = false;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER_NEAR:
                {
                    cList.clear();
                    std::list<Creature*> c1;
                    go->GetCreatureListWithEntryInGrid(c1, NPC_SWIFT_MOUNTAIN_HORSE, 20.0f);
                    for (auto horse : c1)
                        if (Unit* p1 = horse->GetOwner())
                            if (Player* player = p1->ToPlayer())
                                if (player->GetQuestStatus(QUEST_TO_GREYMANE_MANOR) == QUEST_STATUS_INCOMPLETE)
                                    cList.push_back(horse->GetGUID());

                    m_events.RescheduleEvent(EVENT_CHECK_PLAYER_NEAR, 1000);
                    break;
                }
                case EVENT_COOLDOWN_00:
                {
                    m_isUsed = false;
                    cList.clear();
                    go->ResetDoorOrButton();
                    break;
                }
                }
            }

            if (!m_isUsed)
                for (auto guid : cList)
                    if (Creature* horse = ObjectAccessor::GetCreature(*go, guid))
                        if (horse->GetDistance(go) < 10.0f)
                        {
                            go->UseDoorOrButton(5000);
                            m_isUsed = true;
                            m_events.ScheduleEvent(EVENT_COOLDOWN_00, 5000);
                        }
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_gate_196399AI(go);
    }
};

// Phase 183 (16384)

// 196401
class go_gate_196401 : public GameObjectScript
{
public:
    go_gate_196401() : GameObjectScript("go_gate_196401") {}

    struct go_gate_196401AI : public GameObjectAI
    {
        go_gate_196401AI(GameObject* go) : GameObjectAI(go) { }

        EventMap m_events;
        std::list<ObjectGuid> cList;
        bool m_isUsed;

        void Reset() override
        {
            m_events.RescheduleEvent(EVENT_CHECK_PLAYER_NEAR, 1000);
            m_isUsed = false;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER_NEAR:
                {
                    cList.clear();
                    std::list<Creature*> c1 = FindHorseNear();
                    for (auto mount : c1)
                        if (Player* player = GetPlayer(mount))
                            if (player->GetQuestStatus(QUEST_TO_GREYMANE_MANOR) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_EXODUS) == QUEST_STATUS_COMPLETE)
                                cList.push_back(mount->GetGUID());

                    m_events.RescheduleEvent(EVENT_CHECK_PLAYER_NEAR, 1000);
                    break;
                }
                case EVENT_COOLDOWN_00:
                {
                    m_isUsed = false;
                    go->ResetDoorOrButton();
                    break;
                }
                }
            }

            if (!m_isUsed)
                for (auto guid : cList)
                    if (Creature* horse = ObjectAccessor::GetCreature(*go, guid))
                        if (horse->GetDistance(go) < 14.0f)
                        {
                            go->UseDoorOrButton(5000);
                            m_isUsed = true;
                            m_events.ScheduleEvent(EVENT_COOLDOWN_00, 6000);
                        }
        }

        std::list<Creature*> FindHorseNear()
        {
            std::list<Creature*> cList;
            GetCreatureListWithEntryInGrid(cList, go, NPC_SWIFT_MOUNTAIN_HORSE, 20.0f);
            GetCreatureListWithEntryInGrid(cList, go, NPC_HARNESS_43336, 20.0f);
            return cList;
        }

        Player* GetPlayer(Unit* mount)
        {
            if (Unit* unit = mount->GetCharmerOrOwner())
                if (Player* player = unit->ToPlayer())
                    return player;
            if (Player* player = ObjectAccessor::GetPlayer(*go, mount->GetAI()->GetGUID(PLAYER_GUID)))
                return player;

            return nullptr;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_gate_196401AI(go);
    }
};

// 196412
class go_kings_gate_196412 : public GameObjectScript
{
public:
    go_kings_gate_196412() : GameObjectScript("go_kings_gate_196412") {}

    struct go_kings_gate_196412AI : public GameObjectAI
    {
        go_kings_gate_196412AI(GameObject* go) : GameObjectAI(go) { }

        EventMap m_events;
        std::list<ObjectGuid> cList;
        bool m_isUsed;

        void Reset() override
        {
            m_events.RescheduleEvent(EVENT_CHECK_PLAYER_NEAR, 1000);
            m_isUsed = false;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER_NEAR:
                {
                    cList.clear();
                    std::list<Creature*> c1 = FindHorseNear();
                    for (auto mount : c1)
                        if (Player* player = GetPlayer(mount))
                            if (player->GetQuestStatus(QUEST_EXODUS) == QUEST_STATUS_COMPLETE)
                                cList.push_back(mount->GetGUID());

                    m_events.RescheduleEvent(EVENT_CHECK_PLAYER_NEAR, 1000);
                    break;
                }
                case EVENT_COOLDOWN_00:
                {
                    m_isUsed = false;
                    go->ResetDoorOrButton();
                    break;
                }
                }
            }

            if (!m_isUsed)
                for (auto guid : cList)
                    if (Creature* horse = ObjectAccessor::GetCreature(*go, guid))
                        if (horse->GetDistance(go) < 14.0f)
                        {
                            go->UseDoorOrButton(5000);
                            m_isUsed = true;
                            m_events.ScheduleEvent(EVENT_COOLDOWN_00, 6000);
                        }
        }

        std::list<Creature*> FindHorseNear()
        {
            std::list<Creature*> cList;
            GetCreatureListWithEntryInGrid(cList, go, NPC_HARNESS_43336, 20.0f);
            return cList;
        }

        Player* GetPlayer(Unit* mount)
        {
            if (Unit* unit = mount->GetCharmerOrOwner())
                if (Player* player = unit->ToPlayer())
                    return player;
            if (Player* player = ObjectAccessor::GetPlayer(*go, mount->GetAI()->GetGUID(PLAYER_GUID)))
                return player;

            return nullptr;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_kings_gate_196412AI(go);
    }
};

// 36440
class npc_drowning_watchman_36440 : public CreatureScript
{
public:
    npc_drowning_watchman_36440() : CreatureScript("npc_drowning_watchman_36440") { }

    struct npc_drowning_watchman_36440AI : public ScriptedAI
    {
        npc_drowning_watchman_36440AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* clicker, bool& result)
        {
            if (Player* player = clicker->ToPlayer())
                if (player->GetQuestStatus(QUEST_GASPING_FOR_BREATH) == QUEST_STATUS_INCOMPLETE)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    player->KilledMonsterCredit(NPC_DROWNING_WATCHMANN_CREDIT);
                    me->ForcedDespawn(0, 15s);
                }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_drowning_watchman_36440AI(creature);
    }
};

// 196394
class go_mandragore_196394 : public GameObjectScript
{
public:
    go_mandragore_196394() : GameObjectScript("go_mandragore_196394") {}

    bool OnQuestReward(Player* player, GameObject* /*gameObject*/, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == 14320)
        {
            player->SendCinematicStart(168);
            player->PlayDirectSound(23676);
            return true;
        }

        return false;
    }
};

// 36289 lets handle it with SmartAI to make it smoother and also decrease performance taken by the core
//class npc_ashley_36269 : public CreatureScript
//{
//public:
//    npc_ashley_36269() : CreatureScript("npc_ashley_36269") {}
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        if (player->GetQuestStatus(QUEST_SAVE_THE_CHILDREN) == QUEST_STATUS_INCOMPLETE)
//        {
//            sCreatureTextMgr->SendChat(creature, 0, NULL, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
//            creature->AI()->Talk(1);
//            player->KilledMonsterCredit(NPC_ASHLEY_CREDIT);
//            return true;
//        }
//        return false;
//    }
//};

// 36440
class npc_chance_36459 : public CreatureScript
{
public:
    npc_chance_36459() : CreatureScript("npc_chance_36459") { }

    enum eNpc
    {
        EVENT_CREATE_LUCIUS = 901
    };

    struct npc_chance_36459AI : public ScriptedAI
    {
        npc_chance_36459AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_luciusGUID;
        ObjectGuid  m_playerGUID;
        bool        m_isLucisKilled;

        void Reset() override
        {
            m_events.Reset();
            m_events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
            m_luciusGUID = ObjectGuid::Empty;
            m_playerGUID = ObjectGuid::Empty;
            m_isLucisKilled = false;
        }

        void JustSummoned(Creature* summon) override
        {
            if (summon->GetEntry() == NPC_LUCIUS)
                summon->AI()->Talk(1);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
            m_isLucisKilled = true;
            m_luciusGUID = ObjectGuid::Empty;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER:
                {
                    if (!m_playerGUID)
                    {
                        if (Player* player = me->SelectNearestPlayer(10.0f))
                            if (player->GetQuestStatus(QUEST_GRANDMAS_CAT) == QUEST_STATUS_INCOMPLETE)
                            {
                                m_playerGUID = player->GetGUID();
                                m_events.ScheduleEvent(EVENT_MASTER_RESET, 180000);
                                me->SummonCreature(NPC_LUCIUS, -2109.36f, 2330.28f, 7.36667f, 0.151307f, TEMPSUMMON_TIMED_DESPAWN, 180000);
                            }
                    }
                    else if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        if (player->GetQuestStatus(QUEST_GRANDMAS_CAT) == QUEST_STATUS_COMPLETE)
                        {
                            me->DespawnOrUnsummon(10);
                            Reset();
                        }
                    }
                    else if (m_isLucisKilled)
                        Reset();

                    m_events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                    break;
                }
                case EVENT_MASTER_RESET:
                {
                    Reset();
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_chance_36459AI(creature);
    }
};

// 37078
class npc_swamp_crocolisk_37078 : public CreatureScript
{
public:
    npc_swamp_crocolisk_37078() : CreatureScript("npc_swamp_crocolisk_37078") { }

    struct npc_swamp_crocolisk_37078AI : public ScriptedAI
    {
        npc_swamp_crocolisk_37078AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
        }

        void AttackStart(Unit* target) override
        {
            if (target->GetEntry() == 37067)
                AttackStartNoMove(target);
            else if (me->Attack(target, true))
                me->GetMotionMaster()->MoveChase(target);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (attacker->GetEntry() == 37067)
                damage = 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_swamp_crocolisk_37078AI(creature);
    }
};

// 36488
class npc_forsaken_castaway_36488 : public CreatureScript
{
public:
    npc_forsaken_castaway_36488() : CreatureScript("npc_forsaken_castaway_36488") { }

    struct npc_forsaken_castaway_36488AI : public ScriptedAI
    {
        npc_forsaken_castaway_36488AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;
        ObjectGuid   m_luciusGUID;
        ObjectGuid   m_playerGUID;
        bool     m_isLucisKilled;

        void DamageDealt(Unit* victim, uint32& damage, DamageEffectType /*damageType*/) override
        {
            uint8 rol = urand(0, 100);
            if (victim->GetEntry() == 36454 || victim->GetEntry() == 36455 || victim->GetEntry() == 36492 || victim->GetEntry() == 36456)
            {
                if (rol < 70 || victim->GetHealthPct() < 70.0f)
                    damage = 0;
                else
                    damage = 1;
            }
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            uint8 rol = urand(0, 100);
            if (attacker->GetEntry() == 36454 || attacker->GetEntry() == 36455 || attacker->GetEntry() == 36492 || attacker->GetEntry() == 36456)
            {
                if (rol < 70)
                    damage = 0;
                else
                    damage = 1;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_forsaken_castaway_36488AI(creature);
    }
};

// 37067
class npc_crash_survivor_37067 : public CreatureScript
{
public:
    npc_crash_survivor_37067() : CreatureScript("npc_crash_survivor_37067") { }

    struct npc_crash_survivor_37067AI : public ScriptedAI
    {
        npc_crash_survivor_37067AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
            m_events.RescheduleEvent(EVENT_CHECK_FOR_CREATURE, 1000);
        }

        void AttackStart(Unit* target) override
        {
            AttackStartNoMove(target);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (attacker->GetEntry() == 37078)
                damage = 0;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_FOR_CREATURE:
                {
                    if (!me->IsInCombat())
                        if (Creature* croc = me->FindNearestCreature(37078, 4.0f))
                        {
                            me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);
                            me->SetFacingToObject(croc);
                            me->Attack(croc, true);
                        }

                    m_events.ScheduleEvent(EVENT_CHECK_FOR_CREATURE, 1000);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_crash_survivor_37067AI(creature);
    }
};

// 36287  // Quest save the children 14368 lets handle it with SmartAI to make it smoother and also decrease performance taken by the core
//class npc_cynthia_36267 : public CreatureScript
//{
//public:
//    npc_cynthia_36267() : CreatureScript("npc_cynthia_36267") {}
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        if (player->GetQuestStatus(QUEST_SAVE_THE_CHILDREN) == QUEST_STATUS_INCOMPLETE)
//        {
//            sCreatureTextMgr->SendChat(creature, 0, NULL, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
//            creature->AI()->Talk(1);
//            player->KilledMonsterCredit(NPC_CYNTIA_CREDIT);
//            return true;
//        }
//        return false;
//    }
//};

// 37694
class npc_enslaved_villager_37694 : public CreatureScript
{
public:
    npc_enslaved_villager_37694() : CreatureScript("npc_enslaved_villager_37694") { }

    struct npc_enslaved_villager_37694AI : public ScriptedAI
    {
        npc_enslaved_villager_37694AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_ballGUID;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
            m_ballGUID = ObjectGuid::Empty;
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
            case PLAYER_GUID:
                m_playerGUID = guid;
                break;
            case GO_BALL_AND_CHAIN:
                m_ballGUID = guid;
                break;
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
            case EVENT_START_ANIM:
            {
                if (GameObject* ball = ObjectAccessor::GetGameObject(*me, m_ballGUID))
                    ball->DestroyForNearbyPlayers();

                m_events.ScheduleEvent(EVENT_START_ANIM, 1000);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_ANIM:
                {
                    me->HandleEmoteCommand(EMOTE_STATE_NONE);
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        me->SetFacingToObject(player);
                        Talk(0, player);
                    }

                    m_events.ScheduleEvent(EVENT_TALK_PART_00, 3000);
                    break;
                }
                case EVENT_TALK_PART_00:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        me->GetMotionMaster()->MoveFleeing(player, 7000);

                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 6000);
                    break;
                }
                case EVENT_TALK_PART_01:
                    me->DespawnOrUnsummon(10);
                    break;
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_enslaved_villager_37694AI(creature);
    }
};

// 36283 quest 14382 Two by Sea (enter the ship)
class npc_forsaken_catapult_36283 : public CreatureScript
{
public:
    npc_forsaken_catapult_36283() : CreatureScript("npc_forsaken_catapult_36283") { }

    struct npc_forsaken_catapult_36283AI : public ScriptedAI
    {
        npc_forsaken_catapult_36283AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID; // guid only set if mounted
        ObjectGuid  m_forsakenGUID; // guid only set if mounted

        void Reset() override
        {
            me->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
        }

        void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) override
        {
            if (apply)
            {
                if (Player* player = passenger->ToPlayer())
                {
                    m_playerGUID = player->GetGUID();
                    if (seatId == 1)
                        m_events.ScheduleEvent(EVENT_PLAYER_LAUNCH, 2000);
                }
                else if (Creature* npc = passenger->ToCreature())
                {
                    m_forsakenGUID = npc->GetGUID();
                    npc->AddUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    m_events.ScheduleEvent(EVENT_CAST_BOULDER, urand(100, 5000));
                    m_events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                }
            }
            else
            {
                if (passenger->ToPlayer())
                {
                    if (seatId == 0)
                        m_playerGUID = ObjectGuid::Empty;
                }
                else if (Creature* npc = passenger->ToCreature())
                {
                    m_forsakenGUID = ObjectGuid::Empty;
                    npc->RemoveUnitFlag(UnitFlags(UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC));
                    m_events.CancelEvent(EVENT_CAST_BOULDER);
                    m_events.CancelEvent(EVENT_CHECK_PLAYER);
                    m_events.ScheduleEvent(EVENT_MASTER_RESET, 180000);
                    me->SetFaction(35);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_NONE);

                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_PLAYER:
                {
                    if (Creature* target = ObjectAccessor::GetCreature(*me, m_forsakenGUID))
                        if (me->SelectNearestPlayer(7.0f))
                        {
                            target->ExitVehicle();
                            break;
                        }

                    m_events.ScheduleEvent(EVENT_CHECK_PLAYER, 1000);
                    break;
                }
                case EVENT_MASTER_RESET:
                {
                    if (!m_forsakenGUID.IsEmpty() || !m_playerGUID.IsEmpty())
                        m_events.ScheduleEvent(EVENT_MASTER_RESET, 180000);
                    else
                    {
                        if (TempSummon* npc = me->SummonCreature(NPC_FORSAKEN_MACHINIST, me->GetPosition()))
                            npc->EnterVehicle(me, 0);

                        Reset();
                    }
                    break;
                }
                case EVENT_PLAYER_LAUNCH:
                {
                    if (ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        me->CastSpell(me, 96185, true); // trigger spell 66251 (Aura Id 144 (SPELL_AURA_SAFE_FALL)
                    }

                    m_events.ScheduleEvent(EVENT_PLAYER_LANDING, 5000);
                    break;
                }
                case EVENT_PLAYER_LANDING:
                {

                    m_events.RescheduleEvent(EVENT_MASTER_RESET, 10000);
                    m_playerGUID = ObjectGuid::Empty;

                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_forsaken_catapult_36283AI(creature);
    }
};

// 38762
class npc_ogre_ambusher_38762 : public CreatureScript
{
public:
    npc_ogre_ambusher_38762() : CreatureScript("npc_ogre_ambusher_38762") { }

    struct npc_ogre_ambusher_38762AI : public ScriptedAI
    {
        npc_ogre_ambusher_38762AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap m_events;
        bool m_cast_cooldown;

        void Reset() override
        {
            m_cast_cooldown = false;
            me->SetReactState(REACT_PASSIVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!m_cast_cooldown)
                if (who->ToPlayer() || who->getFaction() == 2203 || who->getFaction() == 2163)
                    if (me->GetDistance(who) < 60.0f)
                    {
                        me->SetFacingToObject(who);
                        if (urand(0, 100) < 30)
                        {
                            me->CastSpell(who, SPELL_THROW_BOULDER, true);
                            m_cast_cooldown = true;
                            m_events.ScheduleEvent(EVENT_COOLDOWN_00, urand(2500, 3500));
                        }
                    }
        }

        void AttackStart(Unit* who) override
        {
            DoStartNoMovement(who);
        }

        void EnterCombat(Unit* /*victim*/) override { }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_COOLDOWN_00:
                {
                    m_cast_cooldown = false;
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_ogre_ambusher_38762AI(creature);
    }
};

// 43336
class npc_harness_43336 : public CreatureScript
{
public:
    npc_harness_43336() : CreatureScript("npc_harness_43336") { }

    enum eNpc
    {
        WAYPOINT_ID = 4492801,
    };

    struct npc_harness_43336AI : public ScriptedAI
    {
        npc_harness_43336AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_carriageGUID;

        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
            m_carriageGUID = ObjectGuid::Empty;
            me->setActive(true);
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
            case EVENT_START_MOVEMENT:
                m_events.RescheduleEvent(EVENT_START_MOVEMENT, 3000);
                break;
            }
        }

        ObjectGuid GetGUID(int32 id) const override
        {
            switch (id)
            {
            case PLAYER_GUID:
                return m_playerGUID;
            }
            return ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
            {
                m_playerGUID = player->GetGUID();
                if (Creature* car = ObjectAccessor::GetCreature(*me, m_carriageGUID))
                {
                    car->AI()->SetGUID(m_playerGUID, PLAYER_GUID);
                    car->AI()->DoAction(EVENT_ENTER_VEHICLE);
                }
            }
        }

        void JustSummoned(Creature* summon) override
        {
            switch (summon->GetEntry())
            {
            case NPC_CARRIAGE_43337:
                m_carriageGUID = summon->GetGUID();
                summon->AI()->SetGUID(me->GetGUID(), me->GetEntry());
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
                switch (id)
                {
                case 28:
                {
                    // attack from orc...
                    if (Creature* car = ObjectAccessor::GetCreature(*me, m_carriageGUID))
                        car->GetAI()->DoAction(EVENT_SAY_ATTACK);
                    break;
                }
                case 33:
                {
                    if (Creature* car = ObjectAccessor::GetCreature(*me, m_carriageGUID))
                        car->GetAI()->DoAction(EVENT_EXIT_VEHICLE);
                    break;
                }
                case 44:
                {
                    me->DespawnOrUnsummon(1000);
                    if (Creature* car = ObjectAccessor::GetCreature(*me, m_carriageGUID))
                        car->GetAI()->DoAction(EVENT_DESPAWN_PART_00);
                    break;
                }
                }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_MOVEMENT:
                {
                    me->GetMotionMaster()->MovePath(WAYPOINT_ID, false);
                    break;
                }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_harness_43336AI(creature);
    }
};

// 36231  // Quest - You Can't Take 'Em Alone - 14348
class npc_horrid_abomination_36231 : public CreatureScript
{
public:
    npc_horrid_abomination_36231() : CreatureScript("npc_horrid_abomination_36231") { }

    enum eHorrid
    {
        SAY_BARREL = 0,
        EVENT_KEG_PLACED = 101,
        EVENT_KEG_CREDIT,
    };

    struct npc_horrid_abomination_36231AI : public ScriptedAI
    {
        npc_horrid_abomination_36231AI(Creature* creature) : ScriptedAI(creature) {}

        bool m_creditGiven;

        void Reset() override
        {
            me->ClearUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
            m_creditGiven = false;
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (Player* player = caster->ToPlayer())
            {
                if (spell->Id == SPELL_BARREL_KEG_PLACED)
                {
                    Talk(SAY_BARREL);
                    me->AddUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED);
                }
                if (!m_creditGiven && player->GetQuestStatus(QUEST_YOU_CANT_TAKE_EM_ALONE) == QUEST_STATUS_INCOMPLETE)
                {
                    player->KilledMonsterCredit(NPC_QUEST_14348_KILL_CREDIT);
                    m_creditGiven = true;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_horrid_abomination_36231AI(creature);
    }
};

// 36288 lets handle it with SmartAI to make it smoother and also decrease performance taken by the core
//class npc_james_36268 : public CreatureScript
//{
//public:
//    npc_james_36268() : CreatureScript("npc_james_36268") {}
//
//    bool OnGossipHello(Player* player, Creature* creature) override
//    {
//        if (player->GetQuestStatus(QUEST_SAVE_THE_CHILDREN) == QUEST_STATUS_INCOMPLETE)
//        {
//            sCreatureTextMgr->SendChat(creature, 0, NULL, CHAT_MSG_ADDON, LANG_ADDON, TEXT_RANGE_NORMAL, 0, TEAM_OTHER, false, player);
//            creature->AI()->Talk(1);
//            player->KilledMonsterCredit(NPC_JAMES_CREDIT);
//            return true;
//        }
//        return false;
//    }
//};

// 36743
class npc_king_genn_greymane_36743 : public CreatureScript
{
public:
    npc_king_genn_greymane_36743() : CreatureScript("npc_king_genn_greymane_36743") { }

    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
    {
        switch (quest->GetQuestId())
        {
        case QUEST_THE_KINGS_OBSERVATORY:
        {
            creature->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
            creature->AI()->DoAction(EVENT_CHANGE_PHASE);
            break;
        }
        case QUEST_ALAS_GILNEAS:
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08);
            player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_11, player);
            creature->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
            creature->AI()->DoAction(EVENT_START_VIDEO);
            break;
        }
        }
        return false;
    }

    struct npc_king_genn_greymane_36743AI : public ScriptedAI
    {
        npc_king_genn_greymane_36743AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;

        void Reset() override
        {
            m_playerGUID = ObjectGuid::Empty;
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
            case PLAYER_GUID:
            {
                m_playerGUID = guid;
                break;
            }
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
            case EVENT_CHANGE_PHASE:
            {
                m_events.RescheduleEvent(EVENT_CHANGE_PHASE, 4000);
                break;
            }
            case EVENT_START_VIDEO:
            {
                m_events.RescheduleEvent(EVENT_START_VIDEO, 1000);
                break;
            }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_VIDEO:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        player->SendCinematicStart(167);
                        player->PlayDirectSound(23539);
                    }
                    break;
                }
                case 1:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08);
                        player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_11, player);
                    }
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_king_genn_greymane_36743AI(creature);
    }
};

// 37876
class npc_king_genn_greymane_37876 : public CreatureScript
{
public:
    npc_king_genn_greymane_37876() : CreatureScript("npc_king_genn_greymane_37876") { }

    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
    {
        if (quest->GetQuestId() == QUEST_BETRAYAL_AT_TEMPESTS_REACH)
        {
            player->CastSpell(player, SPELL_FORCE_REACTION_1);
            player->RemoveAura(SPELL_STEALTH_70456);
            creature->AI()->DoAction(1);
        }

        return false;
    }

    struct npc_king_genn_greymane_37876AI : public ScriptedAI
    {
        npc_king_genn_greymane_37876AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_godfreyGUID;

        void Reset() override
        {
            m_events.Reset();
            m_godfreyGUID = ObjectGuid::Empty;
            if (Creature* godfrey = me->FindNearestCreature(NPC_LORD_GODFREY, 20.0f))
                m_godfreyGUID = godfrey->GetGUID();
        }

        void DoAction(int32 /*param*/) override
        {
            if (!m_godfreyGUID)
                if (Creature* godfrey = me->FindNearestCreature(NPC_LORD_GODFREY, 20.0f))
                    m_godfreyGUID = godfrey->GetGUID();

            m_events.ScheduleEvent(EVENT_START_ANIM, 100);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                switch (id)
                {
                case 4:
                {
                    if (Creature* godfrey = ObjectAccessor::GetCreature(*me, m_godfreyGUID))
                    {
                        godfrey->SetDisableGravity(false);
                        godfrey->DespawnOrUnsummon(5000);
                    }
                    break;
                }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_ANIM:
                {
                    if (ObjectAccessor::GetCreature(*me, m_godfreyGUID))
                        m_events.ScheduleEvent(EVENT_START_ANIM + 1, 100);
                    break;
                }
                case EVENT_START_ANIM + 1:
                {
                    Talk(0);
                    m_events.ScheduleEvent(EVENT_START_ANIM + 2, 5000);
                    break;
                }
                case EVENT_START_ANIM + 2:
                {
                    if (Creature* godfrey = ObjectAccessor::GetCreature(*me, m_godfreyGUID))
                        godfrey->AI()->Talk(0);
                    m_events.ScheduleEvent(EVENT_START_ANIM + 3, 3000);
                    break;
                }
                case EVENT_START_ANIM + 3:
                {
                    if (Creature* godfrey = ObjectAccessor::GetCreature(*me, m_godfreyGUID))
                    {
                        godfrey->GetMotionMaster()->MovePath(godfrey->GetSpawnId(), false);
                        godfrey->SetDisableGravity(true);
                    }

                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_king_genn_greymane_37876AI(creature);
    }
};

// 96185 trigger 66251
class spell_launch_96185 : public SpellScriptLoader
{
public:
    spell_launch_96185() : SpellScriptLoader("spell_launch_96185") { }

    class spell_launch_96185_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_launch_96185_SpellScript);

        ObjectGuid m_playerGUID;
        Position pos = Position();

        void CheckTarget(WorldObject*& target)
        {
            if (Vehicle* cat = GetCaster()->GetVehicleKit())
                if (Unit* pas = cat->GetPassenger(1))
                    if (Player* player = pas->ToPlayer())
                        target = player;
        }

        void Register() override
        {
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_launch_96185_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_CASTER);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_launch_96185_SpellScript();
    }
};

// 36409
class npc_mastiff_36409 : public CreatureScript
{
public:
    npc_mastiff_36409() : CreatureScript("npc_mastiff_36409") { }

    enum eNPC
    {
        EVENT_SEND_MORE_MASTIFF = 901
    };

    struct npc_mastiff_36409AI : public ScriptedAI
    {
        npc_mastiff_36409AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_thyalaGUID;
        ObjectGuid  m_player_GUID;
        uint32      m_mastiff_counter;

        void Reset() override
        {
            m_thyalaGUID = ObjectGuid::Empty;
            m_player_GUID = ObjectGuid::Empty;
            m_mastiff_counter = 0;
            m_events.Reset();
            m_events.ScheduleEvent(EVENT_CHECK_ATTACK, 500);
            m_events.ScheduleEvent(EVENT_SEND_MORE_MASTIFF, 250);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
                m_player_GUID = player->GetGUID();
            if (Creature* thyala = me->FindNearestCreature(NPC_DARK_RANGER_THYALA, 100.0f))
            {
                m_thyalaGUID = thyala->GetGUID();
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->MoveChase(thyala, 3.0f, 0.0f);
            }
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage) override
        {
            damage = 0;
        }

        void JustSummoned(Creature* summon) override
        {
            m_mastiff_counter += 1;
            summon->GetAI()->SetGUID(m_player_GUID, PLAYER_GUID);
            summon->GetAI()->SetGUID(m_thyalaGUID, NPC_DARK_RANGER_THYALA);
        }

        void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override
        {
            m_mastiff_counter -= 1;
        }

        void SummonedCreatureDespawn(Creature* /*summon*/) override
        {
            m_mastiff_counter -= 1;
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_ATTACK:
                {
                    if (Creature* thyala = ObjectAccessor::GetCreature(*me, m_thyalaGUID))
                    {
                        if (!thyala->IsAlive() || !thyala->IsInWorld())
                        {
                            if (Player* player = ObjectAccessor::GetPlayer(*me, m_player_GUID))
                                player->KilledMonsterCredit(NPC_DARK_RANGER_THYALA);

                            me->DespawnOrUnsummon(1000);
                        }

                        if (me->GetDistance2d(thyala) < 20.0f)
                        {
                            me->SetWalk(false);
                            me->GetMotionMaster()->MoveIdle();
                        }
                    }
                    m_events.ScheduleEvent(EVENT_CHECK_ATTACK, 1000);
                    break;
                }
                case EVENT_SEND_MORE_MASTIFF:
                {
                    if (ObjectAccessor::GetCreature(*me, m_thyalaGUID))
                        if (m_mastiff_counter < 50)
                        {
                            std::list<Creature*>trigger;
                            GetCreatureListWithEntryInGrid(trigger, me, NPC_TRIGGER, 100.0f);

                            for (std::list<Creature*>::const_iterator itr = trigger.begin(); itr != trigger.end(); ++itr)
                                me->SummonCreature(NPC_MASTIFF, (*itr)->GetNearPosition(5.0f, frand(0.0f, 6.28f)), TEMPSUMMON_TIMED_DESPAWN, urand(30000, 60000));
                        }

                    m_events.ScheduleEvent(EVENT_SEND_MORE_MASTIFF, 250);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mastiff_36409AI(creature);
    }
};

// 36540
class npc_mountain_horse_36540 : public CreatureScript
{
public:
    npc_mountain_horse_36540() : CreatureScript("npc_mountain_horse_36540") { }

    enum eNpc
    {
        EVENT_CHECK_HEALTH_AND_LORNA = 901,
    };

    struct npc_mountain_horse_36540AI : public ScriptedAI
    {
        npc_mountain_horse_36540AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_lornaGUID;
        float       m_dist;
        float       m_angle;
        float       m_size;
        Position    m_oldPosition;
        bool        m_lornaIsNear;

        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
            m_lornaGUID = ObjectGuid::Empty;
            m_lornaIsNear = false;
            me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
            me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }

        void OnSpellClick(Unit* clicker, bool& result) override
        {
            if (Player* player = clicker->ToPlayer())
                if (player->GetQuestStatus(QUEST_THE_HUNGRY_ETTIN) == QUEST_STATUS_INCOMPLETE)
                {
                    me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                    player->KilledMonsterCredit(36560);
                    me->ForcedDespawn(0, 15s);
                }
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (Player* player = passenger->ToPlayer())
                {
                    m_playerGUID = player->GetGUID();
                    me->SetMaxHealth(250);
                }
                m_events.ScheduleEvent(EVENT_CHECK_HEALTH_AND_LORNA, 1000);
            }
            else if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
            {
                if (m_lornaIsNear)
                {
                    player->KilledMonsterCredit(36560);
                    me->DespawnOrUnsummon(1000);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_CHECK_HEALTH_AND_LORNA:
                    me->SetHealth(me->GetMaxHealth());

                    if (!m_lornaGUID)
                        if (Creature* lorna = me->FindNearestCreature(NPC_LORNA_CROWLEY, 100.0f))
                            m_lornaGUID = lorna->GetGUID();

                    if (Creature* lorna = ObjectAccessor::GetCreature(*me, m_lornaGUID))
                        if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        {
                            m_lornaIsNear = player->GetDistance(lorna) < 7.0f;

                            if (m_lornaIsNear)
                                player->ExitVehicle();
                        }

                    m_events.ScheduleEvent(EVENT_CHECK_HEALTH_AND_LORNA, 1000);
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mountain_horse_36540AI(creature);
    }
};

// 36555
class npc_mountain_horse_36555 : public CreatureScript
{
public:
    npc_mountain_horse_36555() : CreatureScript("npc_mountain_horse_36555") { }

    struct npc_mountain_horse_36555AI : public ScriptedAI
    {
        npc_mountain_horse_36555AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_lornaGUID;
        float       m_dist;
        float       m_angle;
        float       m_size;
        Position    m_oldPosition;
        bool        m_isLornaNear;
        bool        m_isPlayerMounted;
        bool        m_hasPlayerRope;


        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
            m_lornaGUID = ObjectGuid::Empty;
            m_isLornaNear = false;
            m_isPlayerMounted = false;
            m_hasPlayerRope = false;
            me->SetWalk(false);
            me->SetSpeed(MOVE_RUN, 1.4f);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Player* player = summoner->ToPlayer())
            {
                m_playerGUID = summoner->GetGUID();
                me->CastSpell(player, SPELL_ROPE_CHANNEL, true);
                m_dist = frand(3.0f, 5.0f);
                m_angle = frand(2.59f, 3.53f);
                m_size = me->GetObjectSize();
                m_oldPosition = player->GetPosition();
                m_events.ScheduleEvent(EVENT_START_FOLLOWING, 100);
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!m_lornaGUID)
                if (Creature* lorna = who->ToCreature())
                    if (lorna->GetEntry() == NPC_LORNA_CROWLEY)
                        m_lornaGUID = lorna->GetGUID();
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_FOLLOWING:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        CheckLornaRelated(player);
                        if (m_oldPosition.GetExactDist(player) > 0.5f)
                        {
                            Position pos;
                            player->GetNearPoint(player, pos.m_positionX, pos.m_positionY, pos.m_positionZ, m_size, m_dist, m_angle);
                            me->GetMotionMaster()->MovePoint(0, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ());
                            m_oldPosition = player->GetPosition();
                        }
                        if (!m_isPlayerMounted && m_hasPlayerRope)
                        {
                            if (m_isLornaNear)
                                me->CastSpell(player, SPELL_MOUNTAIN_HORSE_CREDIT);
                            me->DespawnOrUnsummon();
                        }
                    }
                    m_events.ScheduleEvent(EVENT_START_FOLLOWING, 100);
                    break;
                }
                }
            }
        }

        void CheckLornaRelated(Player* player)
        {
            if (!player)
                return;

            m_isPlayerMounted = player->HasAura(SPELL_RIDE_VEHICLE);
            m_hasPlayerRope = player->HasAura(SPELL_ROPE_CHANNEL);
            if (!m_lornaGUID.IsEmpty())
                if (Creature* lorna = ObjectAccessor::GetCreature(*me, m_lornaGUID))
                    m_isLornaNear = (player->GetDistance(lorna) < 10.0f);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mountain_horse_36555AI(creature);
    }
};

// 37065
class npc_prince_liam_greymane_37065 : public CreatureScript
{
public:
    npc_prince_liam_greymane_37065() : CreatureScript("npc_prince_liam_greymane_37065") { }

    enum eNpc
    {
        MOVEMENT_KOROTH = 2515531,
    };

    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 /*opt*/) override
    {
        switch (quest->GetQuestId())
        {
        case QUEST_EXODUS:
        {
            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_19);
            break;
        }
        case QUEST_INTRODUCTIONS_ARE_IN_ORDER:
        {
            if (Creature* koroth = creature->FindNearestCreature(NPC_KOROTH, 50.0f))
            {
                player->AddAura(SPELL_GENERIC_QUEST_INVISIBLE_DETECTION_10, player);
                koroth->SetSpeed(MOVE_RUN, 1.3f);
                koroth->SetReactState(REACT_AGGRESSIVE);
                koroth->GetMotionMaster()->MovePath(MOVEMENT_KOROTH, false);
                creature->AI()->SetGUID(player->GetGUID(), PLAYER_GUID);
                creature->AI()->SetGUID(koroth->GetGUID(), koroth->GetEntry());
                creature->AI()->DoAction(1);
            }
            break;
        }
        }

        return false;
    }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_STORMGLEN)
        {
            player->RemoveAura(SPELL_GENERIC_QUEST_INVISIBLE_DETECTION_10);
        }
        return true;
    }

    struct npc_prince_liam_greymane_37065AI : public ScriptedAI
    {
        npc_prince_liam_greymane_37065AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;
        ObjectGuid  m_korothGUID;

        void Reset() override
        {
            m_korothGUID = ObjectGuid::Empty;
            m_playerGUID = ObjectGuid::Empty;
        }

        void SetGUID(ObjectGuid guid, int32 id) override
        {
            switch (id)
            {
            case PLAYER_GUID:
                m_playerGUID = guid;
                break;
            case NPC_KOROTH:
                m_korothGUID = guid;
                break;
            }
        }

        void DoAction(int32 param) override
        {
            switch (param)
            {
            case 1:
                m_events.ScheduleEvent(EVENT_TALK_PART_00, 2000);
                break;
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
                switch (id)
                {
                case 1020:
                {
                    m_events.ScheduleEvent(EVENT_TALK_PART_01, 1000);
                    break;
                }
                }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TALK_PART_00:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* koroth = ObjectAccessor::GetCreature(*me, m_korothGUID))
                        {
                            koroth->AI()->Talk(0, player);
                            Talk(0, player);
                        }

                    me->GetMotionMaster()->MovePoint(1020, -2192.868f, 1808.405f, 12.55306f);

                    break;
                }
                case EVENT_TALK_PART_01:
                {
                    me->CastSpell(me, 70511, true);
                    m_events.ScheduleEvent(EVENT_TALK_PART_02, 1000);
                    break;
                }
                case EVENT_TALK_PART_02:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        Talk(1, player);
                    m_events.ScheduleEvent(EVENT_TALK_PART_03, 3000);
                    break;
                }
                case EVENT_TALK_PART_03:
                {
                    me->GetMotionMaster()->MoveTargetedHome();
                    m_events.ScheduleEvent(EVENT_TALK_PART_04, 10000);
                    break;
                }
                case EVENT_TALK_PART_04:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        if (Creature* asther = me->FindNearestCreature(37806, 50.0f))
                            asther->AI()->Talk(0, player);
                    m_events.ScheduleEvent(EVENT_TALK_PART_05, 5000);
                    break;
                }
                case EVENT_TALK_PART_05:
                {
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                        player->RemoveAura(SPELL_GENERIC_QUEST_INVISIBLE_DETECTION_10);
                    if (Creature* koroth = ObjectAccessor::GetCreature(*me, m_korothGUID))
                        koroth->GetMotionMaster()->MoveTargetedHome();
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_prince_liam_greymane_37065AI(creature);
    }
};

// 36205
class npc_slain_watchman_36205 : public CreatureScript
{
public:
    npc_slain_watchman_36205() : CreatureScript("npc_slain_watchman_36205") {}

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_INVASION)
        {
            creature->CastSpell(player, SPELL_FORCECAST_SUMMON_FORSAKEN_ASSASSIN, true);
            return true;
        }
        return false;
    }
};

// 44928
class npc_stagecoach_carriage_44928 : public CreatureScript
{
public:
    npc_stagecoach_carriage_44928() : CreatureScript("npc_stagecoach_carriage_44928") { }

    /* the spell SPELL_SUMMON_CARRIAGE has failure. player mount not as passenger on carriage, but as horse in harness */
    bool OnGossipHello(Player* player, Creature* creature) override
    {
        if (player->GetQuestStatus(QUEST_EXODUS) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, SPELL_PHASE_QUEST_ZONE_SPECIFIC_19);
            player->ForceCompleteQuest(QUEST_EXODUS);
            player->TeleportTo(654, -2210.704f, 1817.451f, 13.123f, 3.133f);
            //player->SummonCreature(NPC_HARNESS_43336, creature->GetPosition(), TEMPSUMMON_MANUAL_DESPAWN);
        }

        return true;
    }
};

// 38765
class npc_stout_mountain_horse_38765 : public CreatureScript
{
public:
    npc_stout_mountain_horse_38765() : CreatureScript("npc_stout_mountain_horse_38765") { }

    enum eNpc
    {
        PATH_ID = 3876500,
    };

    struct npc_stout_mountain_horse_38765AI : public ScriptedAI
    {
        npc_stout_mountain_horse_38765AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;

        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->IsPlayer())
            {
                m_playerGUID = summoner->GetGUID();
                m_events.ScheduleEvent(EVENT_START_WAYPOINTS, 1500);
            }
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
            {
                switch (id)
                {
                case 41:
                {
                    m_events.ScheduleEvent(EVENT_STOP_WAYPOINTS, 1000);
                    break;
                }
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_WAYPOINTS:
                {
                    me->GetMotionMaster()->MovePath(PATH_ID, false);
                    break;
                }
                case EVENT_STOP_WAYPOINTS:
                {
                    me->CastSpell(me, SPELL_DANS_EJECT_ALL_PASSENGERS);
                    me->DespawnOrUnsummon(3000);
                    if (Player* player = ObjectAccessor::GetPlayer(*me, m_playerGUID))
                    {
                        if (player->HasAura(SPELL_FORCE_REACTION_1))
                            player->RemoveAura(SPELL_FORCE_REACTION_1);
                        if (player->HasAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09))
                            player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09);
                    }
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_stout_mountain_horse_38765AI(creature);
    }
};

// 36741
class npc_swift_mountain_horse_36741 : public CreatureScript
{
public:
    npc_swift_mountain_horse_36741() : CreatureScript("npc_swift_mountain_horse_36741") { }

    enum eNpc
    {
        WAYPOINT_ID = 3674101,
    };

    struct npc_swift_mountain_horse_36741AI : public ScriptedAI
    {
        npc_swift_mountain_horse_36741AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_playerGUID;

        void Reset() override
        {
            m_events.Reset();
            m_playerGUID = ObjectGuid::Empty;
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == WAYPOINT_MOTION_TYPE)
                if (id == 11)
                    me->GetVehicleKit()->RemoveAllPassengers();
        }

        void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
        {
            if (apply)
            {
                if (Player* player = passenger->ToPlayer())
                {
                    m_playerGUID = player->GetGUID();
                    player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08, player);
                    player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09, player);
                    me->CastSpell(player, SPELL_FORCECAST_UPDATE_ZONE_AURAS, true);
                    me->GetMotionMaster()->MovePath(WAYPOINT_ID, false);
                }
            }
            else
            {
                if (Player* player = passenger->ToPlayer())
                {
                    player->RemoveAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_08);
                    player->AddAura(SPELL_PHASE_QUEST_ZONE_SPECIFIC_09, player);
                    player->AreaExploredOrEventHappens(QUEST_TO_GREYMANE_MANOR);
                }

                me->DespawnOrUnsummon(1000);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_swift_mountain_horse_36741AI(creature);
    }
};

// 38195
class npc_tobias_mistmantle_38051 : public CreatureScript
{
public:
    npc_tobias_mistmantle_38051() : CreatureScript("npc_tobias_mistmantle_38051") { }

    struct npc_tobias_mistmantle_38051AI : public ScriptedAI
    {
        npc_tobias_mistmantle_38051AI(Creature* creature) : ScriptedAI(creature) { }

        EventMap    m_events;
        ObjectGuid  m_dariusGUID;

        void Reset() override
        {
            m_events.Reset();
            m_dariusGUID = ObjectGuid::Empty;
            if (Creature* darius = me->FindNearestCreature(NPC_LORD_DARIUS_CROWLEY, 50.0f))
                m_dariusGUID = darius->GetGUID();
            m_events.ScheduleEvent(EVENT_START_ANIM, 250);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type == POINT_MOTION_TYPE)
            {
                if (id == 1001)
                {
                    me->HandleEmoteCommand(EMOTE_ONESHOT_KNEEL);
                    m_events.ScheduleEvent(EVENT_START_TALK, 250);
                }
                else if (id == 1002)
                    me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            m_events.Update(diff);

            while (uint32 eventId = m_events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_START_ANIM:
                {
                    me->GetMotionMaster()->MovePoint(1001, -2068.833252f, 1277.579468f, -85.201454f, true);
                    break;
                }
                case EVENT_START_TALK:
                {
                    Talk(0);
                    if (Creature* darius = ObjectAccessor::GetCreature(*me, m_dariusGUID))
                        darius->SetFacingToObject(me);
                    m_events.ScheduleEvent(EVENT_START_TALK + 1, 5000);
                    break;
                }
                case EVENT_START_TALK + 1:
                {
                    if (Creature* darius = ObjectAccessor::GetCreature(*me, m_dariusGUID))
                        darius->AI()->Talk(1);
                    m_events.ScheduleEvent(EVENT_START_TALK + 2, 5000);
                    break;
                }
                case EVENT_START_TALK + 2:
                {
                    Talk(1);
                    m_events.ScheduleEvent(EVENT_START_TALK + 3, 5000);
                    break;
                }
                case EVENT_START_TALK + 3:
                {
                    me->HandleEmoteCommand(EMOTE_STATE_NONE);
                    me->GetMotionMaster()->MovePoint(1002, -2069.574951f, 1305.952393f, -83.195412f, true);
                    break;
                }
                }
            }

            if (!UpdateVictim())
                return;
            else
                DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_tobias_mistmantle_38051AI(creature);
    }
};

// quest_24616
class npc_trigger_quest_24616 : public CreatureScript
{
public:
    npc_trigger_quest_24616() : CreatureScript("npc_trigger_quest_24616") { }

    struct npc_trigger_quest_24616AI : public ScriptedAI
    {
        npc_trigger_quest_24616AI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            mui_timerAllowSummon = urand(3000, 5000);
            allowSummon = false;
            playerGUID = ObjectGuid::Empty;
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;
            if (who->ToPlayer()->GetQuestStatus(24616) != QUEST_STATUS_INCOMPLETE || me->FindNearestCreature(37953, 100, false) != NULL)
                return;
            if (me->IsWithinDistInMap(who, 20.0f))
            {
                allowSummon = true;
                playerGUID = who->GetGUID();
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!allowSummon)
                return;
            if (mui_timerAllowSummon <= diff)
            {
                if (Player *player = ObjectAccessor::GetPlayer(*me, playerGUID))
                    if (me->FindNearestCreature(37953, 100) == NULL)
                        me->CastSpell(player, 70794, true);
                allowSummon = false;
                playerGUID = ObjectGuid::Empty;
                mui_timerAllowSummon = urand(3000, 5000);
            }
            else mui_timerAllowSummon -= diff;
        }

    private:
        uint32 mui_timerAllowSummon;
        bool allowSummon;
        ObjectGuid playerGUID;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_trigger_quest_24616AI(creature);
    }
};

// 69094
class spell_cast_keg_69094 : public SpellScriptLoader
{
public:
    spell_cast_keg_69094() : SpellScriptLoader("spell_cast_keg_69094") { }

    class spell_cast_keg_69094_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_cast_keg_69094_SpellScript);

        void CheckTarget(WorldObject*& target)
        {
            if (target->GetEntry() != NPC_HORRID_ABOMINATION)
                target = target->FindNearestCreature(NPC_HORRID_ABOMINATION, 25.0f);
        }

        void Register() override
        {
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_cast_keg_69094_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_TARGET_ANY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_cast_keg_69094_SpellScript();
    }
};

// 68591
class spell_fire_boulder_68591 : public SpellScriptLoader
{
public:
    spell_fire_boulder_68591() : SpellScriptLoader("spell_fire_boulder_68591") { }

    class IsNotEntryButPlayer
    {
    public:
        explicit IsNotEntryButPlayer(Unit const* caster, uint32 entry) : _caster(caster), _entry(entry) { }

        bool operator()(WorldObject* obj) const
        {
            if (_caster->GetExactDist2d(obj) < 5.0f || _caster->GetExactDist2d(obj) > 80.0f)
                return true;
            if (Player* player = obj->ToPlayer())
                return player->IsMounted();
            else if (Creature* target = obj->ToCreature())
                return target->GetEntry() != _entry;

            return true;
        }

    private:
        const Unit* _caster;
        uint32 _entry;
    };

    class spell_fire_boulder_68591_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_fire_boulder_68591_SpellScript);

        void CheckTargets(std::list<WorldObject*>& targets)
        {
            targets.remove_if(IsNotEntryButPlayer(GetCaster(), NPC_GENERIC_TRIGGER_LAB_AOI));
            WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
            if (!target)
                this->FinishCast(SPELL_CAST_OK);
            else
            {
                std::list<WorldObject*>::iterator itr = targets.begin();
                GetCaster()->SetFacingToObject(*itr);
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fire_boulder_68591_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_fire_boulder_68591_SpellScript();
    }
};

class gilneas_phases : public PlayerScript
{
public:
    gilneas_phases() : PlayerScript("gilneas_phases") { }

    //If someone will report another broken phases in Gilneas, handle it here, thanks
    void OnUpdateZone(Player* player, uint32 /*newZone*/, uint32 /*oldZone*/, uint32 /*newArea*/) override
    {
        if (player->GetMapId() == 654)
            PhasingHandler::AddPhase(player, 170, true);
    }
};

class npc_lorna_crowley_43727 : public CreatureScript
{
public:
    npc_lorna_crowley_43727() : CreatureScript("npc_lorna_crowley_43727") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_ENDGAME)
            player->ForceCompleteQuest(26706);
        return false;
    }
};

struct npc_lorna_crowley_36457 : public ScriptedAI
{
    npc_lorna_crowley_36457(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who)
            return;

        Vehicle* pVehicle = who->GetVehicleKit();
        if (!pVehicle)
            return;

        if (!me->IsWithinDistInMap(who, 5.0f))
            return;

        Unit* rider = pVehicle->GetPassenger(0);
        if (!rider)
            return;

        if (Player* player = rider->ToPlayer())
        {
            player->KilledMonsterCredit(36560, ObjectGuid::Empty);
            player->ExitVehicle();
            who->ToCreature()->ForcedDespawn(100);
        }
    }
};

struct npc_dark_ranger_thyala_36312 : public ScriptedAI
{
    npc_dark_ranger_thyala_36312(Creature* c) : ScriptedAI(c) { }

    void JustDied(Unit* target) override
    {
        std::list<Player*> playerList;
        me->GetPlayerListInGrid(playerList, 50.0f);
        for (Player* player : playerList)
        {
            if (player->GetQuestStatus(QUEST_LEADER_OF_THE_PACK) == QUEST_STATUS_INCOMPLETE)
                player->KilledMonsterCredit(me->GetEntry());
        }
    }
};

void AddSC_gilneas_c1()
{
    new npc_frightened_citizen();
    new npc_worgen_runt();
    new npc_josiah_avery();
    new npc_dark_scout_37953();
    new npc_greymanes_horse();
    new npc_crowleys_horse();
    new npc_mastiff_36405();
    new npc_lord_godfrey_36290();
    new npc_krennan_aranas_36331();
    new npc_lorna_crowley_37783();
    new npc_king_genn_greymane_36332();
    new npc_gwen_armstead_34571();
    new npc_queen_mia_greymane_36606();
    new npc_stagecoach_carriage_43337();
    new npc_lord_hewell_38764();
    new npc_gwen_armstead_36452();
    new npc_drowning_watchman_36440();
   // new npc_ashley_36269();
    new npc_chance_36459();
    new npc_forsaken_castaway_36488();
    new npc_swamp_crocolisk_37078();
    new npc_crash_survivor_37067();
    //new npc_cynthia_36267();
    new npc_enslaved_villager_37694();
    new npc_forsaken_catapult_36283();
    new npc_ogre_ambusher_38762();
    new npc_harness_43336();
    new npc_horrid_abomination_36231();
    //new npc_james_36268();
    new npc_king_genn_greymane_36743();
    new npc_king_genn_greymane_37876();
    new npc_mastiff_36409();
    new npc_mountain_horse_36540();
    new npc_mountain_horse_36555();
    new npc_prince_liam_greymane_37065();
    new npc_slain_watchman_36205();
    new npc_stagecoach_carriage_44928();
    new npc_stout_mountain_horse_38765();
    new npc_swift_mountain_horse_36741();
    new npc_tobias_mistmantle_38051();
    new npc_trigger_quest_24616();
    new spell_launch_68659();
    new spell_round_up_horse_68903();
    new spell_rescue_drowning_watchman_68735();
    new spell_launch_96185();
    new spell_cast_keg_69094();
    new spell_fire_boulder_68591();
    new at_the_blackwald_6687();
    new go_merchant_square_door();
    new go_koroths_banner_201594();
    new go_ball_and_chain_201775();
    new go_gate_196399();
    new go_gate_196401();
    new go_kings_gate_196412();
    new go_mandragore_196394();
    new item_belysras_talisman_49944();
    RegisterPlayerScript(gilneas_phases);
    new npc_lorna_crowley_43727();
    RegisterCreatureAI(npc_lorna_crowley_36457);
    RegisterCreatureAI(npc_dark_ranger_thyala_36312);
}
