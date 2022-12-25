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
#include "InstanceScript.h"
#include "VMapFactory.h"
#include "heart_of_fear.h"

DoorData const doorData[] =
{
    {GOB_ANTECHAMBER_DOOR_ENTRANCE, 0,              DOOR_TYPE_ROOM      },
    {GOB_ANTECHAMBER_DOOR_EXIT,     0,              DOOR_TYPE_ROOM      },
    {GOB_ORATIUM_DOOR_ENTRANCE,     DATA_ZORLOK,    DOOR_TYPE_ROOM      },
    {GOB_QUARTERS_DOOR_ENTRANCE,    DATA_ZORLOK,    DOOR_TYPE_PASSAGE   },
    {GOB_QUARTERS_DOOR_EXIT,        DATA_TAYAK,     DOOR_TYPE_PASSAGE   },
    {GOB_STAIRWAYS_DOOR_EXIT,       0,              DOOR_TYPE_ROOM      },
    {GOB_BALCONY_DOOR_EXIT,         DATA_MELJARAK,  DOOR_TYPE_PASSAGE   },
    {GOB_ATRIUM_DOOR_ENTRANCE,      0,              DOOR_TYPE_ROOM      },
    {GOB_ATRIUM_DOOR_EXIT,          0,              DOOR_TYPE_ROOM      },
    {GOB_SANCTUM_DOOR_ENTRANCE,     0,              DOOR_TYPE_ROOM      },
    {GOB_HEARTOFFEAR_DOOR_ENTRANCE, DATA_UNSOK,     DOOR_TYPE_PASSAGE   }
};

void AddSC_instance_heart_of_fear()
{
   
}
