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
#include "Player.h"
#include "ObjectMgr.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "GameObjectAI.h"
#include "ObjectAccessor.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "WaypointManager.h"
#include "MotionMaster.h"
#include "PhasingHandler.h"
#include "SpellInfo.h"
#include "Log.h"
#include "Map.h"
#include "Transport.h"
#include "DBCEnums.h"
#include "LFGMgr.h"
#include "LFGQueue.h"
#include "LFGPackets.h"
#include "DynamicObject.h"
#include "CreatureTextMgr.h"
#include "MiscPackets.h"
#include "Creature.h"
#include "Vehicle.h"
#include "TemporarySummon.h"
#include "CombatAI.h"
#include "Unit.h"

#define GOSSIP_ACCEPT_DUEL "Let's duel"
#define EVENT_SPECIAL 20

void AddSC_azsuna()
{
    
}
