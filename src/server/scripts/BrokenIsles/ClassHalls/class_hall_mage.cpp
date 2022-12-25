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

#include "Conversation.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "Log.h"

enum
{
    PLAYER_CHOICE_MAGE_SELECTION = 265,

    NPC_MERYL_FELSTORM_102700 = 102700,
    NPC_ALODI_102846 = 102846,

    QUEST_FELSTORMS_PLEA = 41035, /// after quest 44184 In the Blink of an Eye complete
    QUEST_THE_DREADLORDS_PRIZE = 41036,
    QUEST_A_MAGES_WEAPON = 41085,
    QUEST_FINDING_BONCHILL = 42452,
    PHASE_2 = 5985,
    PHASE_3 = 6543,

    CONVERSATION_FELSTORMS_PLEA = 1264,
    CONVERSATION_THE_DREADLORDS_PRIZE = 3364,
    CONVERSATION_THE_DREADLORDS_PRIZE_THIRD = 1281,
    PATH_THE_DREADLORDS_PRIZE = 4471540,
    MOVE_TO_POSITION = 15,
    SPELL_TELE_TO_THE_DREADLORDS_PRIZE = 203241, ///ID - 203241 TELEPORT_TO_LFG_DUNGEON EffectMiscValueA = 1276 EffectMiscValueB = 1187 Location: X: 1276.16 Y: -263.27 Z: 44.36 Orientation: 6.275331 MapID: 1494

    EVENT_TALK_1 = 1,
    EVENET_TELE_TO_LFG_DUNGENON = 2,
    EVENT_BACK_HOME_1 = 3,
    EVENT_THE_DREADLORDS_PRIZE_LAST_TALK = 4,

    ACTION_RESPONSEID_1 = 584, //Arcane
    ACTION_RESPONSEID_2 = 585, //Fire
    ACTION_RESPONSEID_3 = 586, //Frost
};

void AddSC_class_hall_mage()
{
 
}
