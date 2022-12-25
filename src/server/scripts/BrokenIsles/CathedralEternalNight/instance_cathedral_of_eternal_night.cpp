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

#include "cathedral_of_eternal_night.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_AGRONOX_DOOR,           DATA_AGRONOX,       DOOR_TYPE_PASSAGE},
    {GO_THRASHBITE_DOOR,        DATA_THRASHBITE,    DOOR_TYPE_PASSAGE},
    {GO_THRASHBITE_DOOR_ENTER,  DATA_THRASHBITE,    DOOR_TYPE_ROOM},
    {GO_LAST_DOORS,             DATA_DOMATRAX,      DOOR_TYPE_ROOM},
    {GO_LAST_DOORS,             DATA_MEPHISTROTH,   DOOR_TYPE_ROOM},
};

void AddSC_instance_cathedral_of_eternal_night()
{
  
}
