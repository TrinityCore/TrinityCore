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

#include "maw_of_souls.h"
#include "WorldPacket.h"
#include "InstancePackets.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_HARBARON_DOOR,      DATA_HARBARON,       DOOR_TYPE_PASSAGE},
    {GO_HARBARON_DOOR_2,    DATA_HARBARON,       DOOR_TYPE_ROOM},
    {GO_SKJAL_INVIS_DOOR,   DATA_SKJAL,          DOOR_TYPE_PASSAGE},
    {GO_SKJAL_DOOR_1,       DATA_SKJAL,          DOOR_TYPE_PASSAGE},
    {GO_SKJAL_DOOR_2,       DATA_SKJAL,          DOOR_TYPE_PASSAGE},
};

void AddSC_instance_maw_of_souls()
{
    
}
