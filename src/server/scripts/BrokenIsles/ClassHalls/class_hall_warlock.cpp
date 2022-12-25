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
#include "SceneHelper.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Log.h"
#include "Spell.h"

enum
{
    SPELL_PLAYER_CHOICE_WARLOCK = 199411,
    PLAYER_CHOICE_WARLOCK_AFFLICTION = 523,
    PLAYER_CHOICE_WARLOCK_DEMONOLOGY = 524,
    PLAYER_CHOICE_WARLOCK_DESTRUCTION = 525,
    PLAYER_CHOICE_WARLOCK_SELECTION = 245,

    QUEST_AFFLICTION_CHOSEN = 40686,
    QUEST_DESTRUCTION_CHOSEN = 40687,
    QUEST_DEMONOLOGY_CHOSEN = 40688,

    ///WARLOCK Quest 
    NPC_RITSSYN_FLAMESCOWL_103506 = 103506,
    QUEST_THE_SIXTH = 40716,
    QUEST_THE_NEW_BLOOD = 40729,

    QUEST_THE_TOME_OF_BLIGHTED_IMPLEMENTS = 40684,
    QUEST_THE_TOME_OPENS_AGAIN = 43984,
    QUEST_A_GREATER_ARSENAL = 44089,
    ///AFFLICTION
    QUEST_TRACKING_DOWN_UTHALESH = 42939,
    QUEST_ULTHALESH_THE_DEADWIND_HARVESTER = 40495,
    ///DEMONOLOGY
    QUEST_RITUAL_REAGENTS = 42128,
    QUEST_LOOKING_INTO_THE_DARKNESS = 42168,
    QUEST_DARK_WHISPERS = 42125,
    ///DESTRUCTION
    QUEST_FINDING_THE_SCEPTER = 43100,
    QUEST_AN_EYE_FOR_A_SCEPTER = 43153,
    QUEST_RITUAL_RUINATION = 43254,

    QUEST_THE_HEART_OF_THE_DREADSCAR = 40731,
    QUEST_REBUILDING_THE_COUNCIL = 40823,
};

void AddSC_class_hall_warlock()
{
    
}
