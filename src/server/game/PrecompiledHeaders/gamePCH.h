/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

//add here most rarely modified headers to speed up debug build compilation

#include "CellImpl.h"
#include "DB2Stores.h"
#include "DatabaseEnv.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "World.h"
#include "WorldSession.h"

// less commonly included headers but still giving compile time benefit
#include "Group.h"
#include "CriteriaHandler.h"
#include "MotionMaster.h"
#include "Battleground.h"
#include "MiscPackets.h"
#include "Guild.h"
#include "MoveSpline.h"
#include "CollectionMgr.h"
#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "SpellAuras.h"
#include "Chat.h"
#include "StringConvert.h"
#include "SpellPackets.h"
#include "InstanceScript.h"
#include "BattlegroundMgr.h"
#include "ObjectAccessor.h"
#include "MapManager.h"
#include "AuthenticationPackets.h"
#include "BattlePetMgr.h"
#include "Pet.h"
#include "AccountMgr.h"
