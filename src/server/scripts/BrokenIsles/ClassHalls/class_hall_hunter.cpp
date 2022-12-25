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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "PhasingHandler.h"

enum
{
    ///Hunter Quest
    NPC_SNOWFEATHER_100786 = 100786,
    QUEST_NEEDS_OF_THE_HUNTERS = 40384,
    QUEST_THE_HUNTERS_CALL = 41415,
    QUEST_WEAPONS_OF_LEGEND = 40618,
    QUEST_ONE_MORE_LEGEND = 44043,
    QUEST_MORE_WEAPONS_OF_LEGEND = 44366,

    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 198430,
    PLAYER_CHOICE_HUNTER_SELECTION = 240,

    ACTION_RESPONSEID_1 = 504, //Beast Mastery
    ACTION_RESPONSEID_2 = 506, //Marksmanship
    ACTION_RESPONSEID_3 = 505, //Survival
    //Beast Mastery
    QUEST_A_BEASTLY_EXPEDITION = 41541,
    QUEST_STOLEN_THUNDER = 41574,
    QUEST_HUNTER_TO_HUNTER = 41009,
    QUEST_ON_EAGLES_WINGS = 40953,
    QUEST_THE_UNSEEN_PATH = 40954,
    QUEST_OATH_OF_SERVICE = 40955,
    //Marksmanship
    QUEST_RENDEZVOUS_WITH_THE_COURIER = 41540,
    QUEST_CALL_OF_THE_MARKSMAN = 40392,
    QUEST_CLANDESTINE_OPERATION = 40400,
    QUEST_RESCUE_MISSION = 40419,
    //Survival
    QUEST_PREPARATION_FOR_THE_HUNT = 41542,
    QUEST_THE_EAGLE_SPIRIT_S_BLESSING = 39427,
    QUEST_THE_SPEAR_IN_THE_SHADOW = 40385,
};

void AddSC_class_hall_hunter()
{
   
}
