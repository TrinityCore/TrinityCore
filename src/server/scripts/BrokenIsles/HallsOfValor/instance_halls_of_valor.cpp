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

#include "Group.h"
#include "halls_of_valor.h"
#include "WorldPacket.h"
#include "InstancePackets.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_HYMDALL_ENTER_DOOR,         DATA_HYMDALL,         DOOR_TYPE_ROOM},
    {GO_HYMDALL_EXIT_DOOR,          DATA_HYMDALL,         DOOR_TYPE_PASSAGE},
    {GO_HYRJA_DOOR,                 DATA_HYRJA,           DOOR_TYPE_ROOM},
    {GO_GATES_OF_GLORY_DOOR,        DATA_HYRJA,           DOOR_TYPE_PASSAGE},
    {GO_GATES_OF_GLORY_DOOR,        DATA_FENRYR,          DOOR_TYPE_PASSAGE},
    {GO_ODYN_AND_SKOVALD_DOOR,      DATA_SKOVALD,         DOOR_TYPE_ROOM},
    {GO_ODYN_AND_SKOVALD_DOOR,      DATA_ODYN,            DOOR_TYPE_ROOM},
};

void AddSC_instance_halls_of_valor()
{
    
}
