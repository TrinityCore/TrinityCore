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
#include "Player.h"
#include "InstanceScript.h"
#include "battle_of_dazaralor.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Conversation.h"
#include "PhasingHandler.h"

DoorData const doorData[] =
{
	{ GO_FRIDA_WALL_OF_SPEARS, DATA_FRIDA_IRONBELLOWS, DOOR_TYPE_ROOM },
	{ GO_WALL_OF_SPEARS_GRONG, DATA_GRONG, DOOR_TYPE_ROOM },
	{ GO_MEKKATORQUE_WALL_OF_SPEARS_ENTRANCE, DATA_HIGH_TINKER_MEKKATORQUE, DOOR_TYPE_ROOM },
	{ GO_MEKKATORQUE_WALL_OF_SPEARS_EXIT, DATA_HIGH_TINKER_MEKKATORQUE, DOOR_TYPE_PASSAGE },
	{ GO_RAWANI_WALL_OF_SPEARS, DATA_RAWANI_KANAE, DOOR_TYPE_ROOM },
	{ GO_JADEFIRE_MASTERS_ALLIANCE_ENTRANCE, DATA_JADEFIRE_MASTERS, DOOR_TYPE_ROOM },
	{ GO_JADEFIRE_MASTERS_ALLIANCE_EXIT, DATA_JADEFIRE_MASTERS, DOOR_TYPE_PASSAGE },
	{ GO_JADEFIRE_MASTERS_ALLIANCE_COLLISION, DATA_JADEFIRE_MASTERS, DOOR_TYPE_PASSAGE },
};

void AddSC_instance_battle_of_dazaralor()
{
	
}
