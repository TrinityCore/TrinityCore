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

#include "PhasingHandler.h"
#include "ScriptedGossip.h"
#include "InstanceScenario.h"
#include "GameObject.h"
#include "SceneMgr.h"
#include "Log.h"
#include "Spell.h"

enum
{
    DATA_ROF = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_STAGE_8 = 8,
    DATA_MAX_ENCOUNTERS = 9,
    NORMAL_PHASE = 169,
    QUEST_1 = 1,
    DRUID_FERAL_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1631,
    DRUID_FERAL_ACQUISTION_ARTIFACT_SECOND_DOOR_SCENE = 1736,
    DRUID_FERAL_ACQUISTION_ARTIFACT_3_SCENE = 1646,
};

enum
{
    ScenarioID = 1108,
    NPC_VERSTOK_DARKBOUGH = 108003,
    NPC_WEBBED_VICTIM_108028 = 108028,
    NPC_VERSTOK_DARKBOUGH2 = 108053,
    GO_DOOR_1 = 25064,
    GO_LEGION_GATE = 249494,
    GO_RUNIED_SWITCH = 250638,
    GO_PLATFORM = 250824,
};

void AddSC_scenario_artifact_ruins_of_falanaar()
{
   
}
