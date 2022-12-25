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
#include "Player.h"
#include "Spell.h"
#include "Log.h"

enum
{
    ///MONK Quest
    NPC_INITIATE_DA_NEL = 98519,
    QUEST_DA_NEL = 12103,

    PLAYER_CHOICE_MONK_SELECTION = 294,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 226729,
    ACTION_RESPONSEID_1 = 602, //Brewmaster
    ACTION_RESPONSEID_2 = 603, //Mistweaver
    ACTION_RESPONSEID_3 = 604, //Windwalker

    QUEST_BREWMASTER_CHOSEN = 40640,
    QUEST_WINDWALKER_CHOSEN = 40638,
    QUEST_MISTWEAVER_CHOSEN = 40639,

    QUEST_WEAPONS_OF_LEGEND = 40636,
    QUEST_ONE_MORE_LEGEND = 43973,
    QUEST_MORE_WEAPONS_OF_LEGEND = 44424,
    QUEST_THE_DAWNING_LIGHT = 40236,
    //Brewmaster
    QUEST_THE_WANDERERS_COMPANION = 42762,

    QUEST_THE_RIDDLE_OF_THE_BARREL = 42766,
    QUEST_THE_RIDDLE_OF_THE_LAND = 42767,
    QUEST_THE_RIDDLE_OF_PURITY = 42768,

    QUEST_JOURNEY_TO_THE_EAST = 42957,
    QUEST_THE_MONKEY_KING_S_CHALLENGE = 42868,
    QUEST_THE_TRIAL_AT_THE_TEMPLE = 42765,
    //Mistweaver
    QUEST_THE_EMPERORS_GIFT = 41003,
    //Windwalker
    QUEST_THE_LEGEND_OF_THE_SANDS = 40569,
    QUEST_OFF_TO_ADVENTURE = 40633,
    QUEST_THUNDER_ON_THE_SANDS = 40634,
    QUEST_INTO_THE_HEAVENS = 40570,
};

void AddSC_class_hall_monk()
{
    
}
