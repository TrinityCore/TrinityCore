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

#include "GameObject.h"
#include "ScriptMgr.h"
#include "violet_hold_assault.h"

class instance_violet_hold_legion : public InstanceMapScript
{
public:
    instance_violet_hold_legion() : InstanceMapScript("instance_violet_hold_legion", 1544) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_violet_hold_legion_InstanceMapScript(map);
    }

    struct instance_violet_hold_legion_InstanceMapScript : public InstanceScript
    {
        instance_violet_hold_legion_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
        }
    };
};

void AddSC_instance_violet_hold_assault()
{
    new instance_violet_hold_legion();
}
