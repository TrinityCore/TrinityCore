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

DoorData const doorData[] =
{
    { GOB_NYTHENDRA_ENTRANCE_1,     DATA_NYTHENDRA,     DOOR_TYPE_ROOM  },
    { GOB_NYTHENDRA_ENTRANCE_2,     DATA_NYTHENDRA,     DOOR_TYPE_ROOM  },
};

struct instance_emerald_nightmare : public InstanceScript
{
    instance_emerald_nightmare(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        if (instance->IsHeroic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 2.f);
        if (instance->IsMythic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 1.33f);
    }
};

void AddSC_instance_emerald_nightmare()
{
    RegisterInstanceScript(instance_emerald_nightmare, 1520);
}
