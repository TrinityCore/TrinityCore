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

#include "emerald_nightmare.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_NYTHENDRA_DOOR_1,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_NYTHENDRA_DOOR_2,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_NYTHENDRA_DOOR_3,       DATA_NYTHENDRA,         DOOR_TYPE_ROOM},
    {GO_NYTHENDRA_DOOR_4,       DATA_NYTHENDRA,         DOOR_TYPE_ROOM},
    {GO_NYTHENDRA_DOOR_5,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_NYTHENDRA_DOOR_6,       DATA_NYTHENDRA,         DOOR_TYPE_PASSAGE},
    {GO_RENFERAL_DOOR,          DATA_RENFERAL,          DOOR_TYPE_ROOM},
    {GO_ILGYNOTH_DOOR_1,        DATA_ILGYNOTH,          DOOR_TYPE_ROOM},
    {GO_ILGYNOTH_DOOR_2,        DATA_ILGYNOTH,          DOOR_TYPE_ROOM},
    {GO_ILGYNOTH_DOOR_3,        DATA_ILGYNOTH,          DOOR_TYPE_ROOM},
    {GO_URSOC_DOOR_1,           DATA_URSOC,             DOOR_TYPE_ROOM},
    {GO_URSOC_DOOR_2,           DATA_URSOC,             DOOR_TYPE_ROOM},
};

ObjectData const creatureData[] =
{
    {NPC_NYTHENDRA,         NPC_NYTHENDRA},
    {NPC_YSONDRE,           NPC_YSONDRE},
    {NPC_LETHON,            NPC_LETHON},
    {NPC_XAVIUS,            NPC_XAVIUS},
    {0,                     0} // END
};

ObjectData const gobjectData[] =
{
    {GO_CENARIUS_CHEST,     GO_CENARIUS_CHEST},
    {0,                     0 } // END
};

void AddSC_instance_emerald_nightmare()
{
   
}
