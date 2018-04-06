/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "black_rook_hold.h"

DoorData const doorData[] =
{
    { GOB_DOOR_AMALGAME_ENTER_1,        DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ENTER_2,        DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_1,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_2,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_3,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_4,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_EXIT,           DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ILLYSANNA_PORTCULLIS_1,  DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_ROOM      },
    { GOB_DOOR_ILLYSANNA_PORTCULLIS_2,  DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_ROOM      },
    { GOB_DOOR_ILLYSANNA_ENTER,         DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_ROOM      },
    { GOB_DOOR_ILLYSANNA_EXIT_1,        DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ILLYSANNA_EXIT_2,        DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_SMASHSPITE_ROOM,         DATA_SMASHSPITE,            DOOR_TYPE_ROOM      },
    { GOB_DOOR_RAVENCREST_PASSAGE,      DATA_SMASHSPITE,            DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_RAVENCREST_ROOM,         DATA_LORD_RAVENCREST,       DOOR_TYPE_ROOM      },
};

struct instance_black_rook_hold : public InstanceScript
{
    instance_black_rook_hold(Map* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);
    }
};

void AddSC_instance_black_rook_hold()
{
    RegisterInstanceScript(instance_black_rook_hold, 1501);
}
