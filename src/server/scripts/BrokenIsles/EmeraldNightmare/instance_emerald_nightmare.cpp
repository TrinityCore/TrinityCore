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

#include "Creature.h"
#include "emerald_nightmare.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"

/*DoorData const doorData[] =
{
};*/

struct instance_emerald_nightmare : public InstanceScript
{
    instance_emerald_nightmare(Map* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        //LoadDoorData(doorData);
    }
};

void AddSC_instance_emerald_nightmare()
{
    RegisterInstanceScript(instance_emerald_nightmare, 1520);
}
