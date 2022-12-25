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
#include "PhasingHandler.h"
#include "ScriptedGossip.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Spell.h"
#include "Log.h"
#include "LFGMgr.h"

enum
{
    PLAYER_CHOICE_PRIEST_HOLY = 532,
    PLAYER_CHOICE_PRIEST_SHADOW = 533,
    PLAYER_CHOICE_PRIEST_DISCIPLINE = 534,
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 199700,
    PLAYER_CHOICE_PRIEST_SELECTION = 248,

    QUEST_HOLY_CHOSEN = 40708,
    QUEST_SHADOW_CHOSEN = 40707,
    QUEST_DISCIPLINE_CHOSEN = 40709,

    QUEST_WEAPONS_OF_LEGEND = 40706,
    QUEST_ONE_MORE_LEGEND = 43935,
    QUEST_MORE_WEAPONS_OF_LEGEND = 44407,

    ///Priest Quest
    QUEST_PRIESTLY_MATTERS = 40705,

    //HOLY
    QUEST_THE_VINDICATORS_PLEA = 41957,
    QUEST_HOUSE_CALL = 41966,
    QUEST_OUT_OF_THE_DARKNESS = 41967,
    QUEST_SALVATION_FROM_ON_HIGH = 41993,
    QUEST_RETURN_OF_THE_LIGHT = 42074,
    LFG_DUNGEON_SCENARIO_RETURN_OF_THE_LIGHT = 1243,
    SPELL_SALVATION_FROM_ON_HIGH = 210016,
    //SHADOW
    QUEST_BLADE_IN_TWILIGHT = 40710,
    //DISCIPLINE
    QUEST_THE_LIGHTS_WRATH = 41625,
    QUEST_A_GIFT_OF_TIME = 41632,

    QUEST_THE_LIGHT_AND_THE_VOID = 40938,
};

void AddSC_class_hall_priest()
{
    
}
