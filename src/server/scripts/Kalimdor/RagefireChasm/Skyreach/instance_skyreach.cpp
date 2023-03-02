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

#include "instance_skyreach.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"

enum MaxEncounter
{
    Number = 4,
};

static const DoorData k_DoorData[] =
{
    { DOOR_RANJIT_ENTRANCE,             Data::Ranjit,           DOOR_TYPE_ROOM,      },
    { DOOR_RANJIT_EXIT,                 Data::Ranjit,           DOOR_TYPE_PASSAGE,   },
    { DOOR_ARAKNATH_ENTRANCE_1,         Data::Araknath,         DOOR_TYPE_ROOM,      },
    { DOOR_ARAKNATH_ENTRANCE_2,         Data::Araknath,         DOOR_TYPE_ROOM,      },
    { DOOR_ARAKNATH_EXIT_1,             Data::Araknath,         DOOR_TYPE_PASSAGE,   },
    { DOOR_ARAKNATH_EXIT_2,             Data::Araknath,         DOOR_TYPE_PASSAGE,   },
    { DOOR_RUKHRAN_ENTRANCE,            Data::Rukhran,          DOOR_TYPE_ROOM,      },
    { DOOR_RUKHRAN_EXIT,                Data::Rukhran,          DOOR_TYPE_PASSAGE,   },
    { DOOR_HIGH_SAVE_VIRYX_ENTRANCE,    Data::HighSageViryx,    DOOR_TYPE_ROOM,      },
    { 0,                                0,                      DOOR_TYPE_ROOM,      }  // EOF
};

void AddSC_instance_skyreach()
{
   
}
