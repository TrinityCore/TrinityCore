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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Vehicle.h"
#include "ObjectMgr.h"
#include "ScriptedEscortAI.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Player.h"
#include "SpellInfo.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "GameObjectAI.h"

/*######
##Quest 14098 - Evacuate the Merchant Place
######*/

enum FrightenedCitizen
{
    SAY_FRIGHTENED_CITIZEN_RESCUE   = 0,

    NPC_EVACUATION_STALKER_FIRST    = 35830,
    NPC_EVACUATION_STALKER_NEAR     = 35010,
    NPC_EVACUATION_STALKER_FAR      = 35011,
    NPC_RAMPAGING_WORGEN            = 35660,

    CREDIT_35830                    = 35830,

    POINT_STALKER_FIRST             = 1,
    POINT_STALKER_NEAR              = 2,
    POINT_STALKER_FAR               = 3,

    EVENT_TALK_FRIGHTENED           = 1,
    EVENT_MOVE_TO_NEAR_STALKER      = 2,
    EVENT_MOVE_TO_FAR_STALKER       = 3,
    EVENT_DESPAWN                   = 4
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
##Quest 14293 - Save Krennan Aranas
######*/

uint32 const pathSize1 = 7;
G3D::Vector3 const greymanesHorsePath1[pathSize1] =
{
    { -1797.425f, 1396.941f, 20.07336f },
    { -1788.675f, 1378.441f, 20.07336f },
    { -1780.925f, 1368.941f, 20.07336f },
    { -1767.425f, 1358.191f, 19.82336f },
    { -1746.425f, 1358.691f, 20.07336f },
    { -1726.175f, 1354.191f, 19.82336f },
    { -1709.064f, 1348.535f, 19.78232f }
};

uint32 const pathSize2 = 13;
G3D::Vector3 const greymanesHorsePath2[] =
{
    { -1664.807f, 1345.011f, 15.48499f },
    { -1662.807f, 1354.511f, 15.48499f },
    { -1667.307f, 1362.511f, 15.48499f },
    { -1674.307f, 1363.761f, 15.48499f },
    { -1686.057f, 1355.011f, 15.48499f },
    { -1691.057f, 1347.261f, 15.48499f },
    { -1705.807f, 1350.011f, 19.98499f },
    { -1731.307f, 1360.011f, 19.98499f },
    { -1744.807f, 1370.511f, 20.23499f },
    { -1758.807f, 1389.511f, 19.98499f },
    { -1768.307f, 1410.011f, 19.98499f },
    { -1771.557f, 1423.011f, 19.98499f },
    { -1770.955f, 1430.332f, 19.83506f }
};

Position const greymanesHorseJumpPos = { -1676.16f, 1346.19f, 15.1349f };

enum GreymanesHorse
{
    SAY_ANNOUNCE_RESCUE     = 0,
    SAY_RESCUED             = 0,

    PATH_KRENNAN_TREE       = 0,
    PATH_KRENNAN_BACK       = 1,

    EVENT_START_PATH_1      = 1,
    EVENT_START_PATH_2,
    EVENT_JUMP_TO_KRENNAN,
    EVENT_ANNOUNCE_RESCUE,
    EVENT_DISMOUNT_PLAYER,

    NPC_RESCUED_KRENNAN     = 35907
};

class npc_greymanes_horse : public CreatureScript
{
    public:
        npc_greymanes_horse() : CreatureScript("npc_greymanes_horse") { }

        struct npc_greymanes_horseAI : public VehicleAI
        {
            npc_greymanes_horseAI(Creature* creature) : VehicleAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _currentPath = PATH_KRENNAN_TREE;
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (apply && passenger->GetTypeId() == TYPEID_PLAYER)
                {
                    passenger->ToPlayer()->SetMover(me);
                    _events.ScheduleEvent(EVENT_START_PATH_1, Seconds(1));
                }
                else if (apply && passenger->GetEntry() == NPC_RESCUED_KRENNAN)
                    _events.ScheduleEvent(EVENT_START_PATH_2, Seconds(1));
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type == EFFECT_MOTION_TYPE && pointId == pathSize1 && _currentPath == PATH_KRENNAN_TREE)
                    _events.ScheduleEvent(EVENT_JUMP_TO_KRENNAN, Milliseconds(1));
                else if (type == EFFECT_MOTION_TYPE && pointId == pathSize2 && _currentPath == PATH_KRENNAN_BACK)
                    _events.ScheduleEvent(EVENT_DISMOUNT_PLAYER, Milliseconds(1));
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
                            _currentPath = PATH_KRENNAN_TREE;
                            me->GetMotionMaster()->MoveSmoothPath(pathSize1, greymanesHorsePath1, pathSize1);
                            break;
                        case EVENT_JUMP_TO_KRENNAN:
                            me->GetMotionMaster()->MoveJump(greymanesHorseJumpPos, 16.0f, 14.00968f);
                            _events.ScheduleEvent(EVENT_ANNOUNCE_RESCUE, Seconds(2));
                            break;
                        case EVENT_ANNOUNCE_RESCUE:
                            if (Unit* passenger = me->GetVehicleKit()->GetPassenger(0))
                                Talk(SAY_ANNOUNCE_RESCUE, passenger);
                            break;
                        case EVENT_START_PATH_2:
                            _currentPath = PATH_KRENNAN_BACK;
                            me->GetMotionMaster()->MoveSmoothPath(pathSize2, greymanesHorsePath2, pathSize2);
                            break;
                        case EVENT_DISMOUNT_PLAYER:
                            if (Unit* passenger = me->GetVehicleKit()->GetPassenger(1))
                                if (Unit* player = me->GetVehicleKit()->GetPassenger(0))
                                    if (Creature* krennan = passenger->ToCreature())
                                    {
                                        me->ClearInCombat();
                                        player->ClearInCombat();
                                        krennan->ClearInCombat();
                                        player->ExitVehicle();
                                        krennan->ExitVehicle();
                                        krennan->AI()->Talk(SAY_RESCUED, me);
                                        krennan->DespawnOrUnsummon(Seconds(7));
                                    }
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

void AddSC_gilneas_c1()
{
    new npc_frightened_citizen();
    new npc_greymanes_horse();
}
