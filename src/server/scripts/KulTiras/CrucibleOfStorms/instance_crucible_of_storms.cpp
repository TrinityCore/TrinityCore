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
#include "crucible_of_storms.h"

class instance_crucible_of_storms : public InstanceMapScript
{
public:
    instance_crucible_of_storms() : InstanceMapScript("instance_crucible_of_storms", 2096) { }


    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_crucible_of_storms_InstanceScript(map);
    }
     // later to do, PH atm #Rageless
    struct instance_crucible_of_storms_InstanceScript : public InstanceScript
    {
        instance_crucible_of_storms_InstanceScript(InstanceMap* map) : InstanceScript(map)
        {
        }
    };
};

void AddSC_instance_crucible_of_storms()
{
    new instance_crucible_of_storms();
}