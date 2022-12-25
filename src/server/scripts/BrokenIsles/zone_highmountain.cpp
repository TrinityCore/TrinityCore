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
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "SceneHelper.h"

enum
{
    QUEST_THE_LONE_MOUNTAIN     = 39733,
    QUEST_KEEPERS_OF_THE_HAMMER = 38907,
    QUEST_THE_RIVERMANE_TRIBE   = 38911,
    QUEST_ORMGUL_THE_PESTILENT  = 39491,
    QUEST_THE_FLOW_OF_THE_RIVER = 39496,
    QUEST_TRAPPED_TAUREN        = 39316,

    QUEST_SECRETS_OF_HIGHMOUNTAIN = 38916,
    QUEST_THE_PATH_OF_HULN        = 39575,

    QUEST_THE_STORY_OF_HULN       = 40167,
    QUEST_TO_SEE_THE_PAST         = 40520,
    QUEST_HULNS_WAR_THE_ARRIVAL   = 39983,

    QUEST_GRASP_OF_THE_UNDERKING  = 39025,
    QUEST_BITESTONE_ENCLAVE       = 39043,
    QUEST_DARGRUL_AND_THE_HAMMER  = 39027,
    QUEST_GET_TO_HIGH_GROUND      = 38909,

    QUEST_THE_BLOODTOTEM_TRIBE    = 38912,
    QUEST_AN_AUDIENCE_WITH_TOROK  = 39374,
    QUEST_CAVE_OF_THE_BLOOD_TRIAL = 39455,
    QUEST_RITE_OF_BLOOD           = 39860,
    QUEST_ROCK_TROLL_IN_A_HARD_PLACE = 39381,
    QUEST_PET_ROCKS               = 39391,
    QUEST_STONEDARK_CRYSTAL       = 39425,
    QUEST_THEY_WILL_PAY_WITH_BLOOD = 39588,
    QUEST_BLOOD_DEBT              = 39426,
    QUEST_BREAK_WEAPON_RACKS      = 40243,
    QUEST_STEP_INTO_THE_DARK      = 40229,
    QUEST_UNEXPECTED_ALLIES       = 39456,

    QUEST_IN_DEFIANCE_OF_DEATHWING = 40219,
    QUEST_AN_ANCIENT_SECRET        = 39577,
    QUEST_EVACUATE_SNOWMANE        = 42088,
    QUEST_HIGHMOUNTAIN_STANDS      = 42512,
    QUEST_JUSTICE_RAINS_FROM_ABOVE = 40594,
    QUEST_THE_UNDERKING            = 39780,


    QUEST_THE_SKYHORN_TRIBE       = 38913,
    QUEST_NURSING_THE_WOUNDS      = 39318,
    QUEST_ROCS_VS_EAGLES          = 38910,
    QUEST_THE_THREE               = 39321,
    QUEST_THE_WITCHQUEEN          = 39322,
    QUEST_THE_SKIES_OF_HIGHMOUNTAIN = 39387,


    QUEST_CURSE_OF_THE_NECRODARK  = 41815,
    QUEST_THE_TAKEN               = 41839,
    QUEST_ICE_AND_SHADOW          = 41840,
    QUEST_WHISPERS_OF_THE_DARKNESS = 41882,
    QUEST_THE_FINAL_WARD         = 41841,
    QUEST_THE_DARKNESS           = 48403,
};

void AddSC_highmountain()
{
   
}
