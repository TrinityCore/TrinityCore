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
    DATA_RESTOACQUSITON = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_STAGE_7 = 7,
    DATA_MAX_ENCOUNTERS = 8,
    NORMAL_PHASE = 6115,
    QUEST_CLEANSING_THE_MOTHER_TREE = 41689,
    DRUID_RESTO_ACQUISTION_ARTIFACT_LOOTED_SCENE = 1595,
};

enum
{
    NPC_SKYLORD_OMNURON_104620 = 104620,
    NPC_ZEN_TABRA_104658 = 104658,
    NPC_CELESTINE_OF_THE_HARVEST_104657 = 104657,
    NPC_ARCHDRUID_HAMUUL_RUNETOTEM_104659 = 104659,
    NPC_LYESSA_BLOOMWATCHER_104628 = 104628,
    NPC_DESTROMATH_104619 = 104619,
};

void AddSC_scenario_artifact_restoacqusition()
{
    
}
