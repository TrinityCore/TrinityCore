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
#include "InstanceScript.h"
#include "Scenario.h"
#include "SceneMgr.h"
#include "Log.h"
#include "Player.h"
#include "Creature.h"
#include "Spell.h"

enum
{
    DATA_Stormheim     = 0,
    DATA_STAGE_1 = 1,
    DATA_STAGE_2 = 2,
    DATA_STAGE_3 = 3,
    DATA_STAGE_4 = 4,
    DATA_STAGE_5 = 5,
    DATA_STAGE_6 = 6,
    DATA_MAX_ENCOUNTERS = 7,
    NORMAL_PHASE = 169,
};

enum CriteriaTrees
{
    //CLASS_PALADIN
    CRITERIA_TREE_YOU_VE_ARRIVED_AT_SHIELD_S_REST_MEET_UP_WITH_ORIK_AND_PREPARE_TO_ENTER_THE_TOMB = 47433,
    CRITERIA_TREE_INSIDE_THE_TOMB_LIES_THE_SHRINE_OF_THE_TRUTHGUARD_OVERCOME_ANY_DEFENSES_AND_FIND_THE_SHRINE = 47435,
    CRITERIA_TREE_THE_DOOR_TO_THE_SHRINE_IS_THE_FIRST_TRIAL_SURVIVE_ITS_TEST = 47505,
    CRITERIA_TREE_THE_WAY_IS_OPEN_AND_THE_SHRINE_AWAITS_THE_SHIELD_IS_BELOW_SOMEWHERE_FIND_IT = 47521,
    CRITERIA_TREE_YRGRIM_WIELDER_OF_THE_TRUTHGUARD_HAS_CHALLENGED_YOU_TO_A_TRIAL_BY_COMBAT_COMPLETE_THE_TRIAL_TO_EARN_HIS_RESPECT = 47523,
    CRITERIA_TREE_THE_TRIAL_IS_OVER_TAKE_UP_THE_TRUTHGUARD = 47525,
    //CLASS_HUNTER
    CRITERIA_TREE_SPEAK_WITH_GRIF_AND_MEET_HIS_VRYKUL_GUIDE_PRUSTAGA = 47167,
    CRITERIA_TREE_FIND_THE_ENTRANCE_TO_THE_TOMB_OF_WARLORD_VOLUND_INSIDE_THE_TOMB_OF_ANCIENT_KINGS = 47215,
    CRITERIA_TREE_ASSIST_PRUSTAGA_IN_OPENING_THE_DOOR_TO_VOLUND_S_TOMB = 47217,
    CRITERIA_TREE_SCOUR_VOLUND_S_HOARD_FOR_A_SIGN_OF_TITANSTRIKE = 47178,
    CRITERIA_TREE_WARLORD_VOLUND_SEEKS_TO_STOP_YOU_FROM_CLAIMING_TITANSTRIKE = 47556,
    CRITERIA_TREE_USE_THE_TELEPORTATION_PAD_TO_JOIN_MIMIRON_IN_ULDUAR = 47558,
    //CLASS_WARRIOR
    CRITERIA_TREE_FIND_MAGNAR_S_TOMB_WITH_HRUTHNIR = 45335,
    CRITERIA_TREE_DEFEAT_THE_LEGION_FORCES = 45337,
    CRITERIA_TREE_FIND_MAGNAR_S_RESTING_PLACE_WITHIN_THE_TOMB = 44568,
    CRITERIA_TREE_DEFEND_HRUTHNIR_FROM_MAGNAR_S_FORCES = 44570,
    CRITERIA_TREE_DEFEAT_MAGNAR_ICEBREAKER = 45762,
    CRITERIA_TREE_THE_SWORD_AND_SHIELD_ARE_YOURS_CLAIM_THEM = 44572,
};

enum
{
    ScenarioID = 1108,
};

void AddSC_scenario_artifact_truthguard()
{
    
}
