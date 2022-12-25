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

#include "Log.h"
#include "Scenario.h"
#include "GameObject.h"
#include "InstanceScenario.h"
#include "PhasingHandler.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"

enum DataTypes
{
    DATA_CLAWS_OF_URSOC = 0,
    DATA_MAX_ENCOUNTERS = 1,

    SCENARIO_ID = 990,
    DATA_STEP_1 = 2029,
    DATA_STEP_2 = 2327,
    DATA_STEP_3 = 2030,
    DATA_STEP_4 = 2033,
    DATA_STEP_5 = 2034,
    DATA_STEP_6 = 2035,
    DATA_STEP_7 = 2040,
    DATA_STEP_8 = 2041,

    EVENT_STEP_1 = 1,
    EVENT_STEP_2 = 2,
    EVENT_STEP_3 = 3,
    EVENT_STEP_4 = 4,
    EVENT_STEP_5 = 5,
    EVENT_STEP_6 = 6,
    EVENT_STEP_7 = 7,
    EVENT_STEP_8 = 8,

    NPC_MYLUNE_101393 = 101393,
    NPC_SHADE_OF_XAVIUS_101403 = 101403,
    NPC_LEA_STONEPAW_101742 = 101742,
    NPC_VERDANT_WARDER_101754 = 101754,
    NPC_LEA_STONEPAW_101743 = 101743,
 
    NPC_LEA_STONEPAW_105243 = 105243,
    NPC_CLAWS_OF_URSOC_105331 = 105331,

    NPC_SPIRIT_OF_URSOC_101362 = 101362,
    NPC_BLIGHTBORN_SLUDGE_101384 = 101384,
    NPC_ROTHOOF_DEFILER_101386 = 101386,
    NPC_ROTHOOF_SHADOWSTALKER_101388 = 101388,
    NPC_CORRUPTED_DEFENDER_101389 = 101389,
    NPC_ARCH_DESECRATOR_MALITHAR_101390 = 101390,
    NPC_ROTHOOF_SHADOWSTALKER_105294 = 105294,


    QUEST_WHEN_DREAMS_BECOME_NIGHTMARES = 40647,
    SCENE_PLAYER_ENTER = 1177,
    GO_CYLINDER_COLLISION = 248827,
    DRUID_GUARDIA_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1605,
  
    TEST_EVENT = 9999,
};

void AddSC_scenario_artifact_ursocslair()
{
    
}
