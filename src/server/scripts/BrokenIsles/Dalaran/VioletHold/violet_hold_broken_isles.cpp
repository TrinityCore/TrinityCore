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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "violet_hold_broken_isles.h"

enum Texts
{
    TEXT_1 = 0, // "Text: Prison guards, we are leaving! These adventurers are taking over! Go go go!"
    TEXT_2 = 1, // "Text: I'm locking the door. Good luck, and thank you for doing this."
};

enum Menus
{
    OPTION_START_INSTANCE_EVENT = 19230
};

enum Spells
{

};

enum Events
{

};

enum Phase
{

};

enum MovementPoints
{

};

struct npc_lieutenantSinclariAI : public ScriptedAI
{
    npc_lieutenantSinclariAI(Creature* creature) : ScriptedAI(creature) { }

    bool OnGossipSelect(Player* player, uint32 menuId, uint32 gossipListId) override
    {
        if (menuId == OPTION_START_INSTANCE_EVENT && gossipListId == 0)
        {
            CloseGossipMenuFor(player);
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
            //me->Say()
            //me->GetWaypointPath()
        }
        return false;
    }
};

// TO-DO:
// - Millhouse Manastorm should face and cast SPELL_TIGULE_AND_FORORS_SPECIAL_BLEND, but he won't. :(

void AddSC_viole_thold_broken_isles()
{

}
