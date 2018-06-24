/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "GameObject.h"
#include "halls_of_valor.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"

DoorData const doorData[] =
{
    { GOB_DOOR_HYMDALL_ENTRANCE,    DATA_HYMDALL,           DOOR_TYPE_ROOM      },
    { GOB_DOOR_HYMDALL_EXIT,        DATA_HYMDALL,           DOOR_TYPE_PASSAGE   },

    { GOB_DOOR_HYRJA_ROOM,          DATA_HYRJA,             DOOR_TYPE_ROOM      },

    { GOB_DOOR_ODYN_PASSAGE,        DATA_HYRJA,             DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ODYN_BRIDGE,         DATA_HYRJA,             DOOR_TYPE_PASSAGE   },

    { GOB_DOOR_ODYN_ROOM,           DATA_GODKING_SKOVALD,   DOOR_TYPE_ROOM      },
    { GOB_DOOR_ODYN_ROOM,           DATA_ODYN,              DOOR_TYPE_ROOM      },
};

struct instance_halls_of_valor : public InstanceScript
{
    instance_halls_of_valor(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);
    }

    void OnGameObjectCreate(GameObject* gob) override
    {
        InstanceScript::OnGameObjectCreate(gob);

        switch (gob->GetEntry())
        {
            case GOB_DOOR_ODYN_BRIDGE:
                gob->setActive(true);
                break;
            default:
                break;
        }
    }
};

void AddSC_instance_halls_of_valor()
{
    RegisterInstanceScript(instance_halls_of_valor, 1477);
}
