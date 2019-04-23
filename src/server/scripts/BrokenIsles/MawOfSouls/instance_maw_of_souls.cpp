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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "Player.h"
#include "GameObject.h"
#include "PassiveAI.h"
#include "maw_of_souls.h"

struct instance_maw_of_souls : public InstanceScript
{
    instance_maw_of_souls(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    bool SetBossState(uint32 type, EncounterState state) override
    {
        if(!InstanceScript::SetBossState(type, state))
        {
            return false;
        }

        switch (type)
        {
            case DATA_YMIRON_MAW:
            {
                if (state == DONE)
                {
                    // Add code for horn GO
                }
                break;
            }
            case DATA_HELYA_MAW:
            {
                if (state == FAIL)
                {
                    // Repair ship
                }
                else if (state == DONE)
                {
                    // Spawn Loot Chest
                }
                break;
            }
        }

        return true;
    }
};

void AddSC_instance_maw_of_souls()
{
    RegisterInstanceScript(instance_maw_of_souls, 1492);
}
