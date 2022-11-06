/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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


 /*
After close gossip, npc start a text:
X: 4572.638 Y: 4010.3723 Z: 83.78008 Position Crystal -> "Text: Prison guards, we are leaving! These adventurers are taking over! Go go go!"

After this, npc start move a waypoint to the door:

    (MovementMonsterSpline)(MovementSpline)[0] Points: X: 4564.37 Y: 4015.36 Z: 83.7801 --> Points behind the door
    (MovementMonsterSpline)(MovementSpline)[0] WayPoints:  X:  4568.254 Y : 4013.1162 Z : 84.03009
    (MovementMonsterSpline)(MovementSpline)[1] WayPoints : X : 4567.754 Y : 4013.3662 Z : 84.03009
    (MovementMonsterSpline)(MovementSpline)[2] WayPoints : X : 4566.004 Y : 4014.3662 Z : 84.03009
    (MovementMonsterSpline)(MovementSpline)[3] WayPoints : X : 4565.754 Y : 4014.6162 Z : 84.03009

    Behind the door, npc talks again to us, and closes the door.

    X: 4564.37 Y: 4015.36 Z: 83.7801 Position behind door -> "Text: I'm locking the door. Good luck, and thank you for doing this."

*/
//INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `point_comment`) VALUES
//(102278, 0, 4568.254, 4013.1162, 84.03009, NULL, 0, 'Lieutenant Sinclari'),
//(102278, 1, 4567.754, 4013.3662, 84.03009, NULL, 0, 'Lieutenant Sinclari'),
//(102278, 2, 4566.004, 4014.3662, 84.03009, NULL, 0, 'Lieutenant Sinclari'),
//(102278, 3, 4565.754, 4014.6162, 84.03009, NULL, 0, 'Lieutenant Sinclari');

//me->MovePosition(Position(float 4564.37, float 4015.36f, float 83.7801f, float 0.0f), 5, 0);

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "violet_hold_broken_isles.h"

enum CreatureText
{
    SAY_INTRO = 0, // "Text: Prison guards, we are leaving! These adventurers are taking over! Go go go!"
    SAY_BYE = 1, // "Text: I'm locking the door. Good luck, and thank you for doing this."
};

enum Events
{
    EVENT_INTRO = 1,
    EVENT_MOVE_DOOR = 2,
    EVENT_TALK_OUTRO = 3,
    EVENT_DESPAWN = 4
};

enum Actions
{
    ACTION_GO_DOOR = 1,
};

enum MovementPoints
{
    PATH_TO_DOOR = 102278
};

enum Menus
{
    OPTION_START_INTRO_EVENT_MID = 19230,
    OPTION_START_INTRO_EVENT_OID = 0
};

enum GameObjectId
{
    GO_PRISON_SEAL = 247002
};

class npc_lieutenantSinclari : public CreatureScript
{
public:
    npc_lieutenantSinclari() : CreatureScript("npc_lieutenantSinclari") { }

    struct npc_lieutenantSinclariAI : public ScriptedAI
    {
        npc_lieutenantSinclariAI(Creature* creature) : ScriptedAI(creature) { }

        bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
        {
            if (menuId == OPTION_START_INTRO_EVENT_MID && gossipListId == OPTION_START_INTRO_EVENT_OID)
            {
                CloseGossipMenuFor(player);
                me->RemoveNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                Talk(SAY_INTRO, player);
                _events.ScheduleEvent(EVENT_INTRO, 2s);
            }
            return false;
        }

        void Reset() override
        {
            _events.Reset();
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INTRO:
                    DoAction(ACTION_GO_DOOR);
                    _events.ScheduleEvent(EVENT_MOVE_DOOR, 2s);
                    break;
                case EVENT_MOVE_DOOR:
                    me->PauseMovement();
                    me->GetMotionMaster()->Clear();
                    me->SetSpeed(UnitMoveType::MOVE_RUN, 1.14286f);
                    me->GetMotionMaster()->MovePath(PATH_TO_DOOR, false);
                    _events.ScheduleEvent(EVENT_TALK_OUTRO, 6s);
                    break;
                case EVENT_TALK_OUTRO:
                    me->SetFacingTo(6.195918560028076171f, true);
                    Talk(SAY_BYE);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_USE_STANDING);
                    _events.ScheduleEvent(EVENT_DESPAWN, 8s);
                    break;
                case EVENT_DESPAWN:
                    //if (GameObject* table = ObjectAccessor::GetGameObject(*me, _instance->GetGuidData(GO_PRISON_SEAL)))
                    //    me->FindNearestGameObject(GO_PRISON_SEAL, 5, true);
                    //_instance->HandleGameObject(GetGUID(GO_PRISON_SEAL), false);
                    me->DespawnOrUnsummon();
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVioletHoldBrokenIslesAI<npc_lieutenantSinclariAI>(creature);
    }
};

void AddSC_viole_thold_broken_isles()
{
    new npc_lieutenantSinclari();
}
