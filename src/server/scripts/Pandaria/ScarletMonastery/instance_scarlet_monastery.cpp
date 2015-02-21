/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
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
#include "scarlet_monastery.h"


class instance_scarlet_monastery : public InstanceMapScript
{
    public:
        instance_scarlet_monastery() : InstanceMapScript("instance_scarlet_monastery", 859) { }

        struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
        {
            instance_scarlet_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
			{}
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_scarlet_monastery_InstanceMapScript(map);
        }
};

void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}
