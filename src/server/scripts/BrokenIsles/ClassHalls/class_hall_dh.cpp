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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "CombatAI.h"
#include "Item.h"
#include "ObjectMgr.h"
#include "GridNotifiersImpl.h"

enum ClassHallDH
{
    /// DH Quests
    QUEST_CALL_OF_THE_ILLIDARI_39261 = 39261,
    QUEST_CALL_OF_THE_ILLIDARI_39047 = 39047,

    QUEST_WEAPONS_OF_LEGEND_1 = 40816,
    QUEST_WEAPONS_OF_LEGEND_2 = 40814,
    QUEST_ONE_MORE_LEGEND = 44043,

    // Havoc
    QUEST_MAKING_ARRANGEMENTS_1 = 40819,
    QUEST_BY_ANY_MEANS_1 = 39051,
    QUEST_THE_HUNT_1 = 39247,

    QUEST_MAKING_ARRANGEMENTS_2 = 41120,
    QUEST_BY_ANY_MEANS_2 = 41121,
    QUEST_THE_HUNT_2 = 41119,

    // Vengeance
    QUEST_VENGEANCE_WILL_BE_OURS_1 = 40249,
    QUEST_VENGEANCE_WILL_BE_OURS_2 = 41863,

    /// Texts
    KORVAS_BLOODTHORN_TEXT_00 = 0,
    KORVAS_BLOODTHORN_TEXT_01 = 1,

    /// Spells
    SPELL_WEAPONS_OF_LEGEND_PLAYER_CHOICE = 201092,
    SPELL_CALL_OF_THE_WARBLADES = 208464,
    SPELL_FELLSOUL_SLAM = 216164,
    SPELL_SIGIL_OF_POWER = 216228,
    SPELL_SOUL_CARVER = 216188,

    /// Events
    EVENT_CALL_OF_THE_WARBLADES = 1,
    EVENT_FELLSOUL_SLAM = 2,
    EVENT_SIGIL_OF_POWER = 3,
    EVENT_SOUL_CARVER = 4,

    /// Misc
    PLAYER_CHOICE_DH_SELECTION = 255,

    ACTION_RESPONSEID_1 = 600, // Havoc
    ACTION_RESPONSEID_2 = 601, // Vengeance
    QUEST_THE_POWER_TO_SURVIVE = 40816,
    SPELL_PLAYERCHOICE = 201092,
    PLAYER_CHOICE_DH_ARTIFACT_SELECTION = 255,
    PLAYER_CHOICE_DH_HAVOC = 641,
    PLAYER_CHOICE_DH_VENGEANCE = 640,
    SPELL_DH_SPEC_HAVOK = 201093,
    SPELL_DH_SPEC_VENGEANCE = 201094,
    QUEST_ALDRACHI_WARBLADES_CHOSEN = 40818,
    QUEST_TWINBLADES_OFTHE_DECEIVER_CHOSEN = 40817,
    KILL_CREDIT_DH_ARTIFACT_CHOSEN = 105177,
};

enum DataTypes
{
    DATA_STAGE_7 = 7
};

void AddSC_class_hall_dh()
{
    
}
