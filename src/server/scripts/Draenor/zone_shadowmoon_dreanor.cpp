/*
* Copyright 2023 AzgathCore
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Creature.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Garrison.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum
{
    QUEST_FINDING_A_FOOTHOLD                = 34582,
    QUEST_FOR_THE_ALLIANCE                  = 34583,

    QUEST_ESTABLISH_YOUR_GARRISON           = 34586,
};

enum
{
    NPC_VELEN_FOLLOWER_MARAAD               = 79218,
    NPC_VELEN_FOLLOWER_YREL                 = 79219,

    NPC_FINDING_A_FOOTHOLD_KILL_CREDIT      = 79697,
    NPC_FOR_THE_ALLIANCE_PORTAL_KILL_CREDIT = 79433,
    NPC_ESTABLISH_YOUR_GARRISON_KILL_CREDIT = 79757,
};

void AddSC_shadowmoon_draenor()
{
  
}
