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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "TemporarySummon.h"
#include "Vehicle.h"
#include "PhasingHandler.h"

enum eTiragardeQuests
{
    QUEST_DAUGHTER_OF_THE_SEA = 51341,

    QUEST_OUT_LIKE_FLYNN = 47098,
    KILL_CREDIT_GET_DRESSED = 138554,
    KILL_CREDIT_PULL_LEVER = 138553,
    KILL_CREDIT_CELL_BLOCK_DOOR = 137923,

    QUEST_GET_YOUR_BEARINGS = 47099,
    QUEST_THE_OLD_KNIGHT = 46729,
    QUEST_NATION_DIVIDED = 47189,
    QUEST_NATION_UNITED = 52151,
};

enum Intro
{
    SPELL_PROUDMOORE_KEEP_ESCORT        = 269772,
    SPELL_LADY_KATHERINE_MOVIE          = 241525,

    SPELL_TELEPORT_TO_TOL_DAGOR         = 241526,
    SPELL_PRISONER                      = 272512,
    SPELL_TOL_DAGOR_WAKE_UP             = 270081,

    SPELL_PUNCH_FLYNN                   = 264918,
    SPELL_FLYNN_KNOCKOUT_JAILER         = 246555,
    SPELL_SUMMON_FLYNN_ESCORT           = 246931,

    SPELL_SCENE_FLYNN_JAILBREAK         = 246821,
    SPELL_SCENE_GETAWAY_BOAT_TRIGGER    = 281331,
    SPELL_SCENE_NATION_DIVIDED          = 269191,

    SPELL_GETAWAY_CONVERSATION_1        = 247230,
    SPELL_GETAWAY_CONVERSATION_2        = 247275,

    SPELL_MAINTAIN_TAELIA_SUMMON        = 247532,
    SPELL_SCENE_OLD_KNIGHT              = 271234,

    NPC_FLYNN_BEGIN                     = 121239,
    NPC_FLYNN_ESCORT                    = 124311,
    NPC_FLYNN_ESCAPE                    = 124363,
    NPC_ASHVANE_JAILER_EVENT            = 124022,
    NPC_TAELIA                          = 124356,
    NPC_GETAWAY_BOAT_BOARDED            = 124030,
    NPC_TAELIA_GET_YOUR_BEARINGS        = 124630,
    NPC_CYRUS_CRESTFALL                 = 122370,

    GOB_PRISON_BARS                     = 281878,
    GOB_PRISON_GATE                     = 301088,
    GOB_CELL_BLOCK_GATE                 = 281902,

    MOVIE_LADY_KATHERINE                = 859,
};

void AddSC_zone_tiragarde_sound()
{
   
}
