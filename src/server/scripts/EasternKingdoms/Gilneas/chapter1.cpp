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
            if (Creature* stalkerNear = me->FindNearestCreature(NPC_EVACUATION_STALKER_FIRST, 25.0f))
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

void AddSC_gilneas_c1()
{
    new npc_frightened_citizen();
}
