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
#include "MapManager.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Log.h"
#include "World.h"
#include "WorldSession.h"
#include "ScriptedGossip.h"
#include "SceneHelper.h"
#include "Spell.h"

enum
{
    QUEST_THE_LEGION_RETURNS_A = 40519,
    QUEST_THE_FALLEN_LION = 40517,

    QUEST_THE_LEGION_RETURNS_H = 43926,
    QUEST_FATE_OF_THE_HORDE = 40522,

    PHASE_DALARAN_KARAZHAN = 5829,
    QUEST_BLINK_OF_AN_EYE = 44663,
    QUEST_KHADGARS_DISCOVERY = 44555,
    SPELL_LEGION_LAUNCH_PATCH_QUEST_LAUNCH = 258792,
    SPELL_LEGION_7_2_PATCH_QUEST_LAUNCH = 239624,
    SPELL_WHISPERS_OF_A_FRIGHTENED_WORLD_PUSH = 240549,

    PHASE_STORMHEIM_HORDE = 5277,
    PHASE_STORMHEIM_ALLIANCE = 7048,
};

void AddSC_dalaran_legion()
{
    
}
