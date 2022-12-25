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

#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectMgr.h"

//TODO: DB work

enum
{
	QUEST_DESCENT_ALLIANCE = 54969,
	QUEST_DESCENT_HORDE = 54018,
    QUEST_FORTUNATE_SOULS_ALLIANCE = 56640,
    QUEST_FORTUNATE_SOULS_HORDE = 54012,
    GO_GLIMMERING_CHEST = 322413,
    QUEST_SCRYING_STONES_HORDE = 56210,
    QUEST_SCRYING_STONES_ALLIANCE = 56210,
    QUEST_UP_AGAINST_IT_HORDE = 56429,
    QUEST_UP_AGAINST_IT_ALLIANCE = 56644,
    SCENE_SEEING_THE_ARMY = 2619,
    QUEST_SCOUTING_THE_PALACE_HORDE = 55481,
    QUEST_SCOUTING_THE_PALACE_ALLIANCE = 56350,
    SCENE_SCOUTING_THE_TIDESTONE = 2625,
    QUEST_DISRUPTION_OF_POWER_ALLIANCE = 56641,
    QUEST_DISRUPTION_OF_POWER_HORDE = 55092,
    QUEST_DARK_TIDES_HORDE = 56063,
    QUEST_DARK_TIDES_ALLIANCE = 56642,
    QUEST_WHERE_THE_ROAD_LEADS_ALLIANCE = 55175,
    QUEST_STAY_FAST_STAY_LOW_HORDE = 55094,
    SCENE_MEETING_AZSHARA_ALLIANCE = 2671,
    SCENE_MEETING_AZSHARA_HORDE = 2672,
    QUEST_A_WAY_HOME_ALLIANCE = 54972,
    QUEST_A_BOLT_HOLE_ALLIANCE = 55558,
    QUEST_WHAT_REMAINS_OF_ZIN_ASHARI_ALLIANCE = 55561,
    QUEST_SECRETS_IN_THE_RUINS = 55570,
    QUEST_HELP_THEM_SEE_THE_TRUTH = 55571,
};

void AddSC_nazjatar()
{
    
}
