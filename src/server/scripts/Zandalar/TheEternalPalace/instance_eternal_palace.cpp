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
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Conversation.h"
#include "ObjectMgr.h"
#include "eternal_palace.h"

DoorData const doorData[] =
{
    { GO_SIVARA_ENCOUNTER, DATA_COMMANDER_SIVARA, DOOR_TYPE_ROOM },
    { GO_SIVARA_LEFT, DATA_COMMANDER_SIVARA, DOOR_TYPE_PASSAGE },
    { GO_SIVARA_RIGHT, DATA_COMMANDER_SIVARA, DOOR_TYPE_PASSAGE },
    { GO_LADY_ASHVANE_ENCOUNTER, DATA_LADY_ASHVANE, DOOR_TYPE_ROOM },
};

void AddSC_instance_eternal_palace()
{
   
}
