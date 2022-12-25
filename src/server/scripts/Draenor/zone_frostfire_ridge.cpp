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
#include "CreatureTextMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Garrison.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"

enum
{
    QUEST_THE_HOME_OF_THE_FROSTWOLFES   = 33868,
    QUEST_A_SONG_OF_FROST_AND_FIRE      = 33815,
    QUEST_OF_WOLFES_AND_WARRIORS        = 34402,

    QUEST_ESTABLISH_YOUR_GARRISON       = 34378,
};

enum
{
    SpellEarthrendingSlam = 165907,
    SpellRampage          = 148852
};

enum
{
    EventEarthrendingSlam = 1,
    EventRampage          = 2,
    TEXT_GENERIC_2        = 3,
    TEXT_GENERIC_1        
};

enum
{
    NPC_DUROTAN_BEGIN                       = 78272,
    NPC_OF_WOLFES_AND_WARRIOR_KILL_CREDIT   = 78407,
    NPC_ESTABLISH_YOUR_GARRISON_KILL_CREDIT = 79757,
};

enum
{
    SCENE_LANDING_TO_TOP_OF_HILL    = 771,
    SCENE_TOP_OF_HILL_TO_GARRISON   = 778,
    SCENE_PORTAL_OPENING            = 789,
    SCENE_DUROTAN_DEPARTS           = 798,
};

void AddSC_frostfire_ridge()
{
   
}
