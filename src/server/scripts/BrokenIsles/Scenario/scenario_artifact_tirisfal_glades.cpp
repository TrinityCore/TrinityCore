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

enum DataTypes
{
    DATA_ARTIFACT_TIRISFAL_GLADES = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_MAX_ENCOUNTERS = 8,

    SCENARIO_ID_PALADIN = 775,
    PHASE_PALADIN = 5171,

    PHASE_WARRIOR = 6815,
    QUEST__RETURN_TO_THE_BROKEN_SHORE = 38904,
    DATA_STEP_1 = 1939,
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

    SPELL_SCENE_MALGALOR_ARRIVES = 197593,
};

void AddSC_scenario_artifact_tirisfal_glades()
{

}
