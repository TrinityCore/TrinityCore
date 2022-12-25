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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "LFGMgr.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "InstanceScript.h"
#include "CriteriaHandler.h"
#include "SceneMgr.h"
#include "Creature.h"
#include "GameObject.h"
#include "PhasingHandler.h"
#include "Log.h"
#include "Object.h"

enum SPELLS
{
    QUEST_MASQUERADE = 42079,
    QUEST_A_Way_Back_In = 40401,
    LEARN_MASQUERADE = 211086,
    SPELL_MASQUERADE = 211135,
};

void AddSC_suramar()
{
    
}
